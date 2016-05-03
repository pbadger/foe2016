/*
 * Code generated from Atmel Start.
 *
 * This file will be overwritten when reconfiguring your Atmel Start project.
 * Please copy examples or other code you want to keep to a separate file
 * to avoid losing it when reconfiguring.
 */
#ifndef ATMEL_START_H_INCLUDED
#define ATMEL_START_H_INCLUDED

#include "atmel_start_pins.h"

#ifdef __cplusplus
		extern "C" {
#endif

#include <hal_spi_m_sync.h>

#include <hal_usart_sync.h>
#include <hal_timer.h>
#include <hpl_tc1_v121.h>
#include <hal_ext_irq.h>

#include <hal_ac_sync.h>

#include <hal_dac_sync.h>

#include <hal_wdt.h>

#include <hal_memory_dma.h>
#include <hpl_dmac_v100_config.h>

#include "hal_usb_device.h"
#include "usbd_cdc_ser_echo.h"

	extern struct spi_m_sync_descriptor SPI_0;

	extern struct usart_sync_descriptor USART_0;
	extern struct timer_descriptor TIMER_0;

	extern struct ac_sync_descriptor AC_0;

	extern struct dac_sync_descriptor DAC_0;

	extern struct wdt_descriptor WDT_0;

	extern struct memory_dma_descriptor DMA_0;

	void SPI_0_PORT_init(void);
	void SPI_0_CLOCK_init(void);
	void SPI_0_init(void);
	void SPI_0_example(void);

	void USART_0_PORT_init(void);
	void USART_0_CLOCK_init(void);
	void USART_0_init(void);
	void USART_0_example(void);

	void AC_0_PORT_init(void);
	void AC_0_CLOCK_init(void);
	void AC_0_init(void);
	void AC_0_example(void);

	void DAC_0_PORT_init(void);
	void DAC_0_CLOCK_init(void);
	void DAC_0_init(void);
	void DAC_0_example(void);

	void WDT_0_CLOCK_init(void);
	void WDT_0_init(void);
	void WDT_0_example(void);

	void DMA_0_CLOCK_init(void);
	void DMA_0_init(void);
	void DMA_0_example(void);

	void USB_0_CLOCK_init(void);
	void USB_0_init(void);
	void USB_0_example(void);

#define CONF_DMAC_MAX_USED_DESC ( /*SERCOM0*/ 0 + /*SERCOM1*/ 0 + /*TC3*/ 0 + \
	        /*EIC*/ 0 + /*AC*/ 0 + /*DAC*/ 0 + /*WDT*/ 0 + /*GCLK*/ 0 +	\
	        /*DMAC*/ DMAC_transaction + /*SYSCTRL*/ 0 + /*PM*/ 0 + /*USB*/ 0 )

#define CONF_DMAC_MAX_USED_CH ( /*SERCOM0*/ 0 + /*SERCOM1*/ 0 + /*TC3*/ 0 +	\
	        /*EIC*/ 0 + /*AC*/ 0 + /*DAC*/ 0 + /*WDT*/ 0 + /*GCLK*/ 0 +	\
	        /*DMAC*/ DMAC_channel + /*SYSCTRL*/ 0 + /*PM*/ 0 + /*USB*/ 0 )

	/**
	 * \brief Perform system initialization, initialize pins and clocks for
	 * peripherals
	 */
	void system_init(void);

#ifdef __cplusplus
		}
#endif
#endif // ATMEL_START_H_INCLUDED
