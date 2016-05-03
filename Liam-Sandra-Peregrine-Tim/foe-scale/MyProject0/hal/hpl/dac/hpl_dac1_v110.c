/**
* \file
*
* \brief SAM Digital to Analog Converter
*
* Copyright (C) 2015 Atmel Corporation. All rights reserved.
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
* DAMAGES (INCLUDING, BUT NOT LIMIT ED TO, PROCUREMENT OF SUBSTITUTE GOODS
* OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
* HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,
* STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN
* ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
* POSSIBILITY OF SUCH DAMAGE.
*
* \asf_license_stop
*
*/

#include <hpl_dac1_v110_config.h>
#include <hri_dac1_v110.h>
#include <utils_assert.h>
#include <hpl_dac_sync.h>
#include <hpl_dac_async.h>
#include <hpl_irq.h>

/** \conf INTERNAL */
static void _dac_interrupt_handler(void *p);
static int32_t _dac_init(void *const hw);
static inline void _dac_deinit(void *const hw);
/** \endcond */

/**
 * \brief DAC configuration type
 */
struct dac_configuration {
	hri_dac_ctrla_reg_t  ctrla;    /*!< Control A Register */
	hri_dac_ctrlb_reg_t  ctrlb;    /*!< Control B Register */
	hri_dac_evctrl_reg_t ev_ctrl;  /*!< Event Control Register */
};

/**
 * \brief Array of DAC configurations
 */
static struct dac_configuration _dac = {
	(CONF_DAC_RUNSTDBY << DAC_CTRLA_RUNSTDBY_Pos),\
	(CONF_DAC_REFSEL << DAC_CTRLB_REFSEL_Pos) | \
	(CONF_DAC_BDWP << DAC_CTRLB_BDWP_Pos) | \
	(CONF_DAC_VPD <<  DAC_CTRLB_VPD_Pos) | \
	(CONF_DAC_LEFTADJ << DAC_CTRLB_LEFTADJ_Pos) | \
	(CONF_DAC_IOEN << DAC_CTRLB_IOEN_Pos) | \
	(CONF_DAC_EOEN << DAC_CTRLB_EOEN_Pos), \
	(CONF_DAC_EMPTYEO << DAC_EVCTRL_EMPTYEO_Pos) |\
	(CONF_DAC_STARTEI << DAC_EVCTRL_STARTEI_Pos)
};

/**
 * \brief Initialize synchronous DAC
 */
int32_t _dac_sync_init(struct _dac_sync_device *const device, void *const hw)
{
	ASSERT(device);

	device->hw = hw;

	return _dac_init(device->hw);
 }

/** \cond INTERNAL */
/*
 * \brief DAC interrupt handler
 *
 * \param[in] p The pointer to interrupt parameter
 */
static void _dac_interrupt_handler(void *p)
{
	struct _dac_async_device *device = (struct _dac_async_device *)p;
	void *const hw = device->hw;

	if (hri_dac_get_interrupt_UNDERRUN_bit(hw)) {
		hri_dac_clear_interrupt_UNDERRUN_bit(hw);
		if(NULL != device->dac_cb.tx_error_cb) {
			device->dac_cb.tx_error_cb(device, 0);
		}
	} else if (hri_dac_get_interrupt_EMPTY_bit(hw)) {
		hri_dac_clear_interrupt_EMPTY_bit(hw);
		if(NULL != device->dac_cb.tx_ready_cb) {
			device->dac_cb.tx_ready_cb(device, 0);
		}
	} else if (hri_dac_get_interrupt_SYNCRDY_bit(hw)) {
		hri_dac_clear_interrupt_SYNCRDY_bit(hw);
	}
}

/**
 * \brief Initialize DAC
 *
 * param[in] hw The pointer to DAC hardware instance
 */
static int32_t _dac_init(void *const hw)
{
	ASSERT(hw == DAC);

	hri_dac_wait_for_sync(hw);
	if (hri_dac_get_CTRLA_ENABLE_bit(hw)) {
		return ERR_BUSY;
	}
	hri_dac_set_CTRLA_SWRST_bit(hw);
	hri_dac_wait_for_sync(hw);

	hri_dac_write_EVCTRL_reg(hw, _dac.ev_ctrl);
	hri_dac_write_CTRLB_reg(hw, _dac.ctrlb);
	hri_dac_write_CTRLA_reg(hw, _dac.ctrla);

	return ERR_NONE;
}

/**
 * \brief De-initialize DAC
 *
 * param[in] hw The pointer to DAC hardware instance
 */
static inline void _dac_deinit(void *const hw)
{
	hri_dac_clear_CTRLA_ENABLE_bit(hw);
	hri_dac_set_CTRLA_SWRST_bit(hw);
}

#include <hpl_dac1_v101_base.inc>

