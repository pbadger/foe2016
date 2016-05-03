/**
 * \file
 *
 * \brief Generic DMA v100 related functionality.
 *
 * Copyright (C) 2015-2016 Atmel Corporation. All rights reserved.
 *
 * \asf_license_start
 *
 * \page License
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice,
 *    this list of conditions and the following disclaimer.
 *
 * 2. Redistributions in binary form must reproduce the above copyright notice,
 *    this list of conditions and the following disclaimer in the documentation
 *    and/or other materials provided with the distribution.
 *
 * 3. The name of Atmel may not be used to endorse or promote products derived
 *    from this software without specific prior written permission.
 *
 * 4. This software may only be redistributed and used in connection with an
 *    Atmel microcontroller product.
 *
 * THIS SOFTWARE IS PROVIDED BY ATMEL "AS IS" AND ANY EXPRESS OR IMPLIED
 * WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT ARE
 * EXPRESSLY AND SPECIFICALLY DISCLAIMED. IN NO EVENT SHALL ATMEL BE LIABLE FOR
 * ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,
 * STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN
 * ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 *
 * \asf_license_stop
 *
 */

#include <hpl_dma.h>
#include <hpl_memory_dma.h>
#include "hpl_dmac_v100_base.h"
#include <utils_assert.h>
#include "hpl_dmac_v100_config.h"
#include <utils.h>
#include <hpl_irq.h>
#ifndef _UNIT_TEST_
#    include <hri_dmac_v100.h>
#else
#    include <hri_dmac_v100_mock.h>
#endif
/**
 * \brief Macro is used to fill memory with dma configuration structure
 *
 * \param[in] n The number of structures
 */
struct dma_configuration _memory_config[] = {
	{
		CONF_M2M_DMAC_0_CH_ENABLE,
		CONF_M2M_DMAC_0_LVL,
		CONF_M2M_DMAC_0_TRIGACT,
		CONF_M2M_DMAC_0_STEPSIZE,
		CONF_M2M_DMAC_0_STEPSEL,
		CONF_M2M_DMAC_0_SRCINC,
		CONF_M2M_DMAC_0_DSTINC,
		CONF_M2M_DMAC_0_STEPSIZE,
		CONF_M2M_DMAC_0_BLOCKACT,
	}
};

/**
 * \brief default initialized status
 */
static bool initialized = false;

/**
 * \brief default channel status: all channel unused
 */
static uint32_t channel_mask = 0;
static uint32_t memory_mask = 0;

/**
 * \brief DMAC descriptor section
 */
extern DmacDescriptor _descriptor_section[];

/**
 * \brief DMAC write-back section
 */
extern DmacDescriptor _write_back_section[];

/**
 * \brief DMAC instance
 */
static struct _dma_dev device;

/**
 * \brief DMAC resources
 */
extern struct _dma_resource _resource[];

extern uint32_t dmac_ch_used;
extern uint32_t dmac_resource_used;

static void _dma_handler(void *p);

/**
 * \brief Initialize DMAC
 */
int32_t _dma_init(struct _dma_dev * *dev)
{
	void *hw;
	ASSERT(dev);

	*dev = &device;

	if (!initialized) {
		initialized = true;
		device.hw = DMAC;
		device.irq.handler = _dma_handler;
		device.irq.parameter = (void *)( dev );
		hw = ( *dev )->hw;

		hri_dmac_clear_CTRL_DMAENABLE_bit(hw);
		hri_dmac_clear_CTRL_CRCENABLE_bit(hw);
		hri_dmac_set_CHCTRLA_SWRST_bit(hw);

		hri_dmac_write_BASEADDR_reg(hw, (uint32_t)_descriptor_section);
		hri_dmac_write_WRBADDR_reg(hw, (uint32_t)_write_back_section);

		hri_dmac_write_CTRL_reg(hw,
				( 0x1 << DMAC_CTRL_LVLEN0_Pos ) |
				( 0x1 << DMAC_CTRL_LVLEN1_Pos ) |
				( 0x1 << DMAC_CTRL_LVLEN2_Pos ) |
				( 0x1 << DMAC_CTRL_LVLEN3_Pos ));

		hri_dmac_write_DBGCTRL_reg(hw,
				0x1 << DMAC_DBGCTRL_DBGRUN_Pos);

		hri_dmac_write_PRICTRL0_reg(hw,
				( 0x0 << DMAC_PRICTRL0_RRLVLEN0_Pos ) |
				( 0x0 << DMAC_PRICTRL0_RRLVLEN1_Pos ) |
				( 0x0 << DMAC_PRICTRL0_RRLVLEN2_Pos ) |
				( 0x0 << DMAC_PRICTRL0_RRLVLEN3_Pos ));

		hri_dmac_set_CTRL_DMAENABLE_bit(hw);

		_irq_disable(DMAC_IRQn);
		_irq_clear(DMAC_IRQn);
		_irq_register(DMAC_IRQn, &( *dev )->irq);
		_irq_enable(DMAC_IRQn);
	}

	return ERR_NONE;
}

/**
 * \brief De-initialize DMAC
 */
int32_t _dma_deinit(struct _dma_dev *const dev)
{
	void *hw = dev->hw;

	ASSERT(dev && hw);

	hri_dmac_clear_CTRL_DMAENABLE_bit(hw);
	hri_dmac_clear_CTRL_CRCENABLE_bit(hw);
	hri_dmac_set_CTRL_SWRST_bit(hw);

	channel_mask = 0;
	memory_mask = 0;
	initialized = 0;

	_irq_disable(DMAC_IRQn);

	return ERR_NONE;
}

/**
 * \brief Allocate resource for DMAC
 */
int32_t _dma_allocate(struct _dma_dev *const dev,
		struct _dma_resource * *const resource,
		uint32_t num)
{
	uint8_t channel;
	uint8_t index = 0;
	DmacDescriptor *tmp_descriptor = NULL;

	ASSERT(dev);

	for (channel = 0; channel < dmac_ch_used; channel++) {
		if (!( channel_mask & ( 1 << channel ))) {
			*resource = &_resource[channel];
			(*resource)->id = channel;
			tmp_descriptor = &_descriptor_section[channel];
			channel_mask |= ( 1 << channel );
			break;
		}
	}

	if (num != 1)
	{
		for (;( index < ( num - 1 )) &&
				( index < ( dmac_resource_used - dmac_ch_used )); index++) {
			if (!( memory_mask & ( 1 << index ))) {
				tmp_descriptor->DESCADDR.reg =
						(uint32_t)&_resource[dmac_ch_used + index];
				tmp_descriptor = (DmacDescriptor *)tmp_descriptor->DESCADDR.reg;
				memory_mask |= ( 1 << index );
			}
		}
	}

	if (( channel == dmac_ch_used ) ||
			( index == ( dmac_resource_used - dmac_ch_used ))) {
		return ERR_NO_RESOURCE;
	}

	return ERR_NONE;
}

/**
 * \brief Enable DMAC
 */
int32_t _dma_enable(struct _dma_dev *const dev,
		struct _dma_resource *const resource)
{
	void *hw = dev->hw;
	uint8_t channel = resource->id;

	ASSERT(dev && hw);

	resource->status = ERR_BUSY;
	hri_dmac_write_CHID_reg(hw, channel);
	hri_dmac_set_CHCTRLA_ENABLE_bit(hw);

	return ERR_NONE;
}

/**
 * \brief Disable DMAC
 */
int32_t _dma_disable(struct _dma_dev *const dev,
		struct _dma_resource *const resource)
{
	void *hw = dev->hw;
	uint8_t channel = resource->id;

	ASSERT(dev && hw);

	resource->status = ERR_NONE;
	hri_dmac_write_CHID_reg(hw, channel);
	hri_dmac_clear_CHCTRLA_ENABLE_bit(hw);

	return ERR_NONE;
}

/**
 * \brief Config trigger source for DMA Resource if needed
 */
int32_t _dma_config_resource(struct _dma_dev *const dev,
		struct _dma_resource *const resource,
		void *const peripheral_dev,
		uint32_t const trigger)
{
	void *hw = dev->hw;
	struct dma_configuration *config;
	uint32_t channel = resource->id;
	struct _dma_resource *tmp_resource = &_resource[channel];

	ASSERT(dev);

	config = (struct dma_configuration *)resource->config;

	hri_dmac_write_CHID_reg(hw, channel);
	hri_dmac_clear_CHCTRLA_ENABLE_bit(hw);
	hri_dmac_set_CHCTRLA_SWRST_bit(hw);
	hri_dmac_clear_SWTRIGCTRL_reg(hw, 1 << channel);

	hri_dmac_write_CHCTRLB_LVL_bf(hw, config->lvl);
	hri_dmac_write_CHCTRLB_TRIGACT_bf(hw, config->trigact);

	hri_dmac_write_CHCTRLB_TRIGSRC_bf(hw,
			tmp_resource->get_trigger_num(peripheral_dev, trigger));

	return ERR_NONE;
}

/**
 * \brief  Set source/destination address and the size for transfer
 */
int32_t _dma_config_transfer(struct _dma_dev *const dev,
		struct _dma_resource *const resource,
		void *src,
		void *dst,
		uint32_t size)
{
	uint8_t channel = resource->id;
	struct dma_configuration *config;
	DmacDescriptor *tmp_descriptor = &_descriptor_section[channel];

	ASSERT(dev);

	config = (struct dma_configuration *)resource->config;

	tmp_descriptor->BTCTRL.bit.VALID = true;
	tmp_descriptor->BTCTRL.bit.BLOCKACT = 0;
	tmp_descriptor->BTCTRL.bit.SRCINC = config->srcinc;
	tmp_descriptor->BTCTRL.bit.DSTINC = config->dstinc;
	tmp_descriptor->BTCTRL.bit.STEPSEL = config->stepsel;

	if(config->srcinc) {
		tmp_descriptor->SRCADDR.reg = (uint32_t)src + size;
	}
	else{
		tmp_descriptor->SRCADDR.reg = (uint32_t)src;
	}

	if(config->dstinc) {
		tmp_descriptor->DSTADDR.reg = (uint32_t)dst + size;
	}
	else{
		tmp_descriptor->DSTADDR.reg = (uint32_t)dst;
	}

	tmp_descriptor->BTCTRL.bit.BEATSIZE = config->beatsize;
	tmp_descriptor->BTCNT.reg = size >> config->beatsize;

	return ERR_NONE;
}

int32_t _dma_srcinc_enable(struct _dma_dev *const dev,
		struct _dma_resource *const resource,
		bool state)
{
	((struct dma_configuration *)resource->config )->srcinc = state;
	(void)dev;

	return ERR_NONE;
}
/**
 * \brief  Set software trigger command for transfer
 */
int32_t _dma_software_trigger_set(struct _dma_dev *const dev,
		struct _dma_resource *const resource)
{
	void *hw = dev->hw;
	uint32_t channel = resource->id;

	ASSERT(dev && hw);

	hri_dmac_write_SWTRIGCTRL_reg(hw, 1 << channel);

	return ERR_NONE;
}

/**
 * \brief Enable/disable DMA interrupt
 */
void _dma_set_irq_state(struct _dma_dev *const dev,
		struct _dma_resource *const resource,
		const enum _dma_callback_type type,
		const bool state)
{
	void *hw = dev->hw;
	uint8_t channel = resource->id;

	ASSERT(dev && hw);

	hri_dmac_write_CHID_reg(hw, channel);

	if (DMA_TRANSFER_COMPLETE_CB == type) {
		hri_dmac_write_CHINTEN_TCMPL_bit(hw, state);
	}
	else if (DMA_TRANSFER_ERROR_CB == type) {
		hri_dmac_write_CHINTEN_TERR_bit(hw, state);
	}
}

/**
 * \internal Sercom interrupt handler
 *
 * \param[in] p The pointer to interrupt parameter
 */
static void _dma_handler(void *p)
{
	struct _dma_dev * *dev = (struct _dma_dev * *)p;
	uint32_t write_size, total_size;

	uint8_t channel = hri_dmac_read_INTPEND_ID_bf(( *dev )->hw);

	struct _dma_resource *tmp_resource = &_resource[channel];

	total_size = _descriptor_section[channel].BTCNT.reg;
	write_size = _write_back_section[channel].BTCNT.reg;
	tmp_resource->transfered_size = total_size - write_size;

	hri_dmac_write_CHID_reg(( *dev )->hw, channel);

	if (hri_dmac_get_interrupt_TERR_bit(( *dev )->hw)) {
		tmp_resource->status = ERR_IO;
		hri_dmac_clear_interrupt_TERR_bit(( *dev )->hw);
		tmp_resource->_dma_cb.error(dev, tmp_resource);
	} else if (hri_dmac_get_interrupt_TCMPL_bit(( *dev )->hw)) {
		tmp_resource->status = ERR_NONE;
		hri_dmac_clear_interrupt_TCMPL_bit(( *dev )->hw);
		tmp_resource->_dma_cb.transfer_done(dev, tmp_resource);
	}
}
/**
 * \internal Retrieve software trigger number for DMA
 *
 * \return The trigger number
 */
static int32_t get_trigger_source(void *const dev, uint32_t const trigger)
{
	(void)dev;
	if (MEMORY_DMA_TX == trigger) {
		return 0;
	} else {
		return -1;
	}
}

/**
 * \brief fill function pointers for software triggher number retrieve
 */
void _memory_fill_dma_pointer(dma_get_trigger_number_t *get_trigger_num)
{
	*get_trigger_num = get_trigger_source;
}

/**
 * \brief Retrieve pointers to memory dma configuration
 */
void _memory_fill_dma_config_pointer(void * *config)
{
	*config = _memory_config;
}
