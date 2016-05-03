/**
 * \file
 *
 * \brief Memory with DMA functionality declaration.
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




/**
 * Note: this hal_memory_dma.h just will be used by memory to memory with DMA
 *
 */


#ifndef HAL_MEMORY_DMA_H_INCLUDED
#define HAL_MEMORY_DMA_H_INCLUDED

#include <hpl_dma.h>
#include <hpl_memory_dma.h>


#ifdef __cplusplus
extern "C" {
#endif

/**
 * \addtogroup hal_memory_dma Driver
 *
 * \section dma_rev Revision History
 * - v0.0.0.1 Initial Commit
 *
 *@{
 */

/**
 * \brief Memory with DMA descriptor
 *
 * The Memory with DMA descriptor forward declaration.
 */
struct memory_dma_descriptor;

/**
 * \brief memory with dma callback type
 */
typedef void (* memory_dma_cb_t)(
		struct memory_dma_descriptor *const descr);

 /**
 * \brief Memory with DMA callback types
 */
enum memory_dma_callback_type {
	HAL_MEMORY_DMA_COMPLETE_CB,
	HAL_MEMORY_DMA_ERROR_CB
};

/**
 * \brief Memory with DMA callbacks
 */
struct memory_dma_callbacks {
	memory_dma_cb_t complete;
	memory_dma_cb_t error;
};

/**
 * \brief Memory with DMA descriptor
 */
struct memory_dma_descriptor {
	struct _dma_dev *dev;
	struct _dma_resource *resource;
	struct memory_dma_callbacks memory_cb;
};

/**
 * \brief Initialize Memory with DMA 
 *
 * \return Initialization status.
 * \retval -1 Already initialized or allocation failure 
 * \retval 0 Init successfully
 */
int32_t dma_memory_init(void);

/**
 * \brief De-initialize Memory with DMA 
 *
 * \return De-initialization status.
 * \retval 0 Deinit successfully
 */
int32_t dma_memory_deinit(void);

/**
 * \brief Register Memory with DMA callback
 *
 * \param[in] type Callback type
 * \param[in] cb A callback function, passing NULL de-registers callback
 *
 * \return The status of callback assignment.
 * \retval -1 Passed parameters were invalid
 * \retval 0 A callback is registered successfully
 */
int32_t dma_memory_register_callback(const enum memory_dma_callback_type type,
		memory_dma_cb_t cb);

/**
 * \brief dma memory copy 
 *
 * \param[in] src The pointer to source address for transfer
 * \param[in] dst The pointer to destination address for transfer
 * \param[in] size The transfer size  
 *
 * \return the status of operation` 
 * \retval -1 Resource is busy 
 * \retval 0 Copy operation is executed
 */
int32_t dma_memcpy(void *dst, void *src, uint32_t size);

/**
 * \brief dma memory set 
 *
 * \param[in] dst The pointer to address to  fill
 * \param[in] ch The value to be filled
 * \param[in] size Number of bytes to set to the value 
 *
 * \return the status of operation
 * \retval -1 Resource is busy 
 * \retval 0 Set operation is executed
 */
int32_t dma_memset(void *dst, int32_t ch, uint32_t size);

/**
 * \brief Retrieve the current driver version
 *
 * \return Current driver version
 */
uint32_t memory_dma_get_version(void);
/**@}*/

#ifdef __cplusplus
}
#endif

#endif /* HAL_MEMORY_DMA_H_INCLUDED */
