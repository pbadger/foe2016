/**
 * \file
 *
 * \brief Memery with DMA functionality implementation.
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

#include "hal_memory_dma.h"
#include <utils_assert.h>
#include <utils.h>
#include <hal_atomic.h>

/**
 * \brief Driver version
 */
#define DRIVER_VERSION 0x00000001u

/**
 * \brief memory with dma intialized status
 */
static bool initialized = false;
/**
 * \brief memory with dma descriptor instance
 */
static struct memory_dma_descriptor descr;

/**
 * \internal Process transfer done interrupts
 *
 * \param[in] device The pointer to pointer to device sctructure
 * \param[in] resource The pointer to memory resource
 */
static void dma_transfer_done(struct _dma_dev * *dev,
		struct _dma_resource *const resource)
{
	struct memory_dma_descriptor *descr =
			CONTAINER_OF(dev, struct memory_dma_descriptor, dev);

	if(descr->memory_cb.complete) {
		descr->memory_cb.complete(descr);
	}
	(void)resource;
}

/**
 * \internal Process transfer error interrupts
 *
 * \param[in] device The pointer to pointer to device sctructure
 * \param[in] resource The pointer to memory resource
 */
static void dma_memory_error(struct _dma_dev * *dev,
		struct _dma_resource *const resource)
{
	struct memory_dma_descriptor *descr =
			CONTAINER_OF(dev, struct memory_dma_descriptor, dev);

	if(descr->memory_cb.error) {
		descr->memory_cb.error(descr);
	}
	(void)resource;
}

/**
 * \brief Initialize DMA
 */
int32_t dma_memory_init(void)
{
	int32_t ret;

	if(initialized == true) {
		return ERR_ALREADY_INITIALIZED;
	}

	initialized = true;

	_dma_init(&descr.dev);

	ret = _dma_allocate(descr.dev, &descr.resource, 1);

	if(ret < 0) {
		return ERR_NO_RESOURCE;
	}

	descr.resource->_dma_cb.transfer_done = dma_transfer_done;
	descr.resource->_dma_cb.error = dma_memory_error;

	_memory_fill_dma_pointer(&descr.resource->get_trigger_num);
	_memory_fill_dma_config_pointer(&descr.resource->config);

	_dma_config_resource(descr.dev, descr.resource, NULL, MEMORY_DMA_TX);

	return ERR_NONE;
}

/**
 * \brief De-initialize DMA
 */
int32_t dma_memory_deinit(void)
{
	_dma_disable(descr.dev, descr.resource);

	return ERR_NONE;
}

/**
 * \brief Register DMA callback
 */
int32_t dma_memory_register_callback(const enum memory_dma_callback_type type,
		memory_dma_cb_t cb)
{
	switch (type) {
	case HAL_MEMORY_DMA_COMPLETE_CB:
		descr.memory_cb.complete = cb;
		break;

	case HAL_MEMORY_DMA_ERROR_CB:
		descr.memory_cb.error = cb;
		break;

	default:
		return ERR_INVALID_ARG;
	}

	_dma_set_irq_state(descr.dev,
			descr.resource,
			(enum _dma_callback_type)type,
			( cb != NULL ));

	return ERR_NONE;
}

/**
 * \brief memory copy with dma
 */
int32_t dma_memcpy(void *dst, void *src, uint32_t size)
{
	if (descr.resource->status != ERR_NONE) {
		return ERR_NOT_READY;
	}

	_dma_config_transfer(descr.dev, descr.resource, src, dst, size);

	_dma_enable(descr.dev, descr.resource);

	_dma_software_trigger_set(descr.dev, descr.resource);

	return ERR_NONE;
}

/**
 * \brief memory set with dma
 */
int32_t dma_memset(void *dst, int32_t ch, uint32_t size)
{
	static int32_t tmp_ch;

	if (descr.resource->status != ERR_NONE) {
		return ERR_NOT_READY;
	}

	tmp_ch = ch;

	_dma_srcinc_enable(descr.dev, descr.resource, false);
	_dma_config_transfer(descr.dev, descr.resource, &tmp_ch, dst,
			size);

	_dma_enable(descr.dev, descr.resource);

	_dma_software_trigger_set(descr.dev, descr.resource);

	return ERR_NONE;
}

/**
 * \brief Retrieve the current driver version
 */
uint32_t memory_dma_get_version(void)
{
	return DRIVER_VERSION;
}


//@}
