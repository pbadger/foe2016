/**
 * \file
 *
 * \brief USART DMA related functionality declaration.
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

#ifndef _HPL_USART_DMA_H_INCLUDED
#define _HPL_USART_DMA_H_INCLUDED

/**
 * \addtogroup HPL USART DMA
 *
 * \section hpl_usart_dma_rev Revision History
 * - v1.0.0 Initial Release
 *
 *@{
 */

#include <hpl_usart_sync.h>
#include <hpl_dma.h>

#ifdef __cplusplus
extern "C" {
#endif

enum USART_DMA_TRIGGER {
	USART_DMA_TX,
	USART_DMA_RX
};

/**
 * \brief Retrieve pointers to dma related sercom functions
 *
 * \param[out] cbs The pointer to structure to fill with callbacks
 */
void _usart_fill_dma_pointer(dma_get_trigger_number_t *get_trigger_num);

/**
 * \brief Get the address of REG 
 *
 * \param[in] hw The pointer to hardware instance
 * \param[in] trigger The trigger type for USART 
 *
 * \return address of REG
 */
uint32_t _usart_get_addr_for_dma(const void *const dev, enum USART_DMA_TRIGGER trigger);

/**
 * \brief Retrieve pointers to memory dma configuration
 *
 * \param[in] hw The pointer to hardware instance
 * \param[out] config The pointer to pointer to the config
 * \param[in] trigger Usart trigger type(TX or RX)
 */
void _usart_fill_dma_config_pointer(void *const dev, void **config, uint32_t const trigger);

//@}

#ifdef __cplusplus
}
#endif
/**@}*/
#endif /* _HPL_USART_DMA_H_INCLUDED */
