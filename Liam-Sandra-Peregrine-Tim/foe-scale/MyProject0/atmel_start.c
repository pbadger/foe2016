/*
 * Code generated from Atmel Start.
 *
 * This file will be overwritten when reconfiguring your Atmel Start project.
 * Please copy examples or other code you want to keep to a separate file
 * to avoid losing it when reconfiguring.
 */

#include "atmel_start.h"
#include <utils.h>
#include <hal_init.h>
#include <hpl_irq.h>
#include <hpl_pm1_v201_base.h>
#include <hpl_gclk1_v210_base.h>
#include <peripheral_gclk_config.h>


// sampling frequency
#define freq 2940
// sampling time
#define t 1
// # of samples (note that we cannot sample for too long... when I tried to sample for 5 secs (14700 samples) I got an "ram overflow error"
#define numConvs 2940

// indicate if conversion is done
volatile bool done;
// count number of conversions
volatile uint8_t count = 0;


// index for data when shifting in
uint8_t data_index;

// data buffers
uint8_t data [16];
uint16_t value;

// holds all sample values
uint16_t data_buffer[numConvs];


#if CONF_DMAC_MAX_USED_DESC > 0
#    include <hpl_dma.h>

	COMPILER_ALIGNED(16)
	DmacDescriptor _descriptor_section[CONF_DMAC_MAX_USED_DESC]
	SECTION_DMAC_DESCRIPTOR;

	COMPILER_ALIGNED(16)
	DmacDescriptor _write_back_section[CONF_DMAC_MAX_USED_DESC]
	SECTION_DMAC_DESCRIPTOR;

	struct _dma_resource _resource[CONF_DMAC_MAX_USED_CH];

	uint32_t dmac_ch_used = CONF_DMAC_MAX_USED_CH;
	uint32_t dmac_resource_used = CONF_DMAC_MAX_USED_DESC;
#endif

extern struct _irq_descriptor *_irq_table[PERIPH_COUNT_IRQn];
extern void Default_Handler(void);

struct spi_m_sync_descriptor SPI_0;

struct timer_descriptor TIMER_0;
static struct timer_task TIMER_0_task1, TIMER_0_task2;

struct usart_sync_descriptor USART_0;

struct ac_sync_descriptor AC_0;

struct dac_sync_descriptor DAC_0;

struct wdt_descriptor WDT_0;

void SPI_0_PORT_init(void)
{
	// Set pin direction to output
	gpio_set_pin_direction(PA04, GPIO_DIRECTION_OUT);

	gpio_set_pin_level(PA04,
	        // <y> Initial level
	        // <id> pad_initial_level
	        // <false"> Low
	        // <true"> High
			false);

	gpio_set_pin_function(PA04, PINMUX_PA04D_SERCOM0_PAD0);

	// Set pin direction to output
	gpio_set_pin_direction(PA05, GPIO_DIRECTION_OUT);

	gpio_set_pin_level(PA05,
	        // <y> Initial level
	        // <id> pad_initial_level
	        // <false"> Low
	        // <true"> High
			false);

	gpio_set_pin_function(PA05, PINMUX_PA05D_SERCOM0_PAD1);

	// Set pin direction to input
	gpio_set_pin_direction(PA06, GPIO_DIRECTION_IN);

	gpio_set_pin_pull_mode(PA06,
	        // <y> Pull configuration
	        // <id> pad_pull_config
	        // <GPIO_PULL_OFF"> Off
	        // <GPIO_PULL_UP"> Pull-up
	        // <GPIO_PULL_DOWN"> Pull-down
			GPIO_PULL_OFF);

	gpio_set_pin_function(PA06, PINMUX_PA06D_SERCOM0_PAD2);
}
void SPI_0_CLOCK_init(void)
{
	_pm_enable_bus_clock(PM_BUS_APBC, SERCOM0);
	_gclk_enable_channel(SERCOM0_GCLK_ID_CORE, CONF_GCLK_SERCOM0_CORE_SRC);
	_gclk_enable_channel(SERCOM0_GCLK_ID_SLOW, CONF_GCLK_SERCOM0_SLOW_SRC);
}
void SPI_0_init(void)
{
	SPI_0_CLOCK_init();
	spi_m_sync_init(&SPI_0, SERCOM0);
	SPI_0_PORT_init();
}

void USART_0_PORT_init(void)
{
	gpio_set_pin_function(PA00, PINMUX_PA00D_SERCOM1_PAD0);

	gpio_set_pin_function(PA01, PINMUX_PA01D_SERCOM1_PAD1);
}

void USART_0_CLOCK_init(void)
{
	_pm_enable_bus_clock(PM_BUS_APBC, SERCOM1);
	_gclk_enable_channel(SERCOM1_GCLK_ID_CORE, CONF_GCLK_SERCOM1_CORE_SRC);
	_gclk_enable_channel(SERCOM1_GCLK_ID_SLOW, CONF_GCLK_SERCOM1_SLOW_SRC);
}

void USART_0_init(void)
{
	USART_0_CLOCK_init();
	usart_sync_init(&USART_0, SERCOM1);
	USART_0_PORT_init();
}

/**
 * Example of using USART_0 to write "Hello World" using the IO abstraction.
 */
void USART_0_example(void)
{
	struct io_descriptor *io;
	usart_sync_get_io_descriptor(&USART_0, &io);
	usart_sync_enable(&USART_0);

	io_write(io, (uint8_t *)"Hello World!", 12);
}

/**
 * \brief Timer initialization function
 *
 * Enables Timer peripheral, clocks and initializes Timer driver
 */
static void TIMER_0_init(void)
{
	_pm_enable_bus_clock(PM_BUS_APBC, TC3);
	_gclk_enable_channel(TC3_GCLK_ID, CONF_GCLK_TC3_SRC);
	timer_init(&TIMER_0, TC3, _tc_get_timer());
}


void EXTERNAL_IRQ_0_init(void)
{
	_gclk_enable_channel(EIC_GCLK_ID, CONF_GCLK_EIC_SRC);
	ext_irq_init();
}

void AC_0_PORT_init(void)
{
}

void AC_0_CLOCK_init(void)
{
	_pm_enable_bus_clock(PM_BUS_APBC, AC);
	_gclk_enable_channel(AC_GCLK_ID_DIG, CONF_GCLK_DIG_AC_SRC);
	_gclk_enable_channel(AC_GCLK_ID_ANA, CONF_GCLK_ANA_AC_SRC);
}

void AC_0_init(void)
{
	AC_0_CLOCK_init();
	ac_sync_init(&AC_0, AC);
	AC_0_PORT_init();
}

/**
 * Example of using AC_0 to generate waveform.
 */
void AC_0_example(void)
{
	ac_sync_enable(&AC_0);
	ac_sync_start_comparison(&AC_0, 0);

	while (true) {
		ac_sync_get_result(&AC_0, 0);
	}
}

void DAC_0_PORT_init(void)
{
}

void DAC_0_CLOCK_init(void)
{
	_pm_enable_bus_clock(PM_BUS_APBC, DAC);
	_gclk_enable_channel(DAC_GCLK_ID, CONF_GCLK_DAC_SRC);
}

void DAC_0_init(void)
{
	DAC_0_CLOCK_init();
	dac_sync_init(&DAC_0, DAC);
	DAC_0_PORT_init();
}

/**
 * Example of using DAC_0 to generate waveform.
 */
void DAC_0_example(void)
{
	uint16_t i = 0;

	dac_sync_enable_channel(&DAC_0, 0);

	for(;; ) {
		dac_sync_write(&DAC_0, 0, &i, 1);
		i = ( i+1 ) % 1024;
	}
}

void WDT_0_CLOCK_init(void)
{
	_pm_enable_bus_clock(PM_BUS_APBA, WDT);
	_gclk_enable_channel(WDT_GCLK_ID, CONF_GCLK_WDT_SRC);
}

void WDT_0_init(void)
{
	WDT_0_CLOCK_init();
	wdt_init(&WDT_0, WDT);
}

/**
 * Example of using WDT_0.
 */
void WDT_0_example(void)
{
	uint32_t clk_rate;
	uint16_t timeout_period;

	clk_rate = 1000;
	timeout_period = 4096;
	wdt_set_timeout_period(&WDT_0, clk_rate, timeout_period);
	wdt_enable(&WDT_0);
}

void DMA_0_CLOCK_init(void)
{
	_pm_enable_bus_clock(PM_BUS_AHB, DMAC);
	_pm_enable_bus_clock(PM_BUS_APBB, DMAC);
}

void DMA_0_init(void)
{
	DMA_0_CLOCK_init();
	dma_memory_init();
}

void DMA_0_example(void)
{
	uint32_t source_memory[10];
	uint32_t destination_memory[10];
	for (uint32_t i = 0; i < 10; i++) {
		source_memory[i] = i;
	}

	dma_memcpy(destination_memory, source_memory, 10);
}

void USB_0_PORT_init(void)
{
	gpio_set_pin_direction(PA24,
	        // <y> Pin direction
	        // <id> pad_direction
	        // <GPIO_DIRECTION_OFF"> Off
	        // <GPIO_DIRECTION_IN"> In
	        // <GPIO_DIRECTION_OUT"> Out
			GPIO_DIRECTION_OUT);

	gpio_set_pin_level(PA24,
	        // <y> Initial level
	        // <id> pad_initial_level
	        // <false"> Low
	        // <true"> High
			false);

	gpio_set_pin_pull_mode(PA24,
	        // <y> Pull configuration
	        // <id> pad_pull_config
	        // <GPIO_PULL_OFF"> Off
	        // <GPIO_PULL_UP"> Pull-up
	        // <GPIO_PULL_DOWN"> Pull-down
			GPIO_PULL_OFF);

	gpio_set_pin_function(PA24, PINMUX_PA24G_USB_DM);

	gpio_set_pin_direction(PA25,
	        // <y> Pin direction
	        // <id> pad_direction
	        // <GPIO_DIRECTION_OFF"> Off
	        // <GPIO_DIRECTION_IN"> In
	        // <GPIO_DIRECTION_OUT"> Out
			GPIO_DIRECTION_OUT);

	gpio_set_pin_level(PA25,
	        // <y> Initial level
	        // <id> pad_initial_level
	        // <false"> Low
	        // <true"> High
			false);

	gpio_set_pin_pull_mode(PA25,
	        // <y> Pull configuration
	        // <id> pad_pull_config
	        // <GPIO_PULL_OFF"> Off
	        // <GPIO_PULL_UP"> Pull-up
	        // <GPIO_PULL_DOWN"> Pull-down
			GPIO_PULL_OFF);

	gpio_set_pin_function(PA25, PINMUX_PA25G_USB_DP);
}

/* The USB module requires a GCLK_USB of 48 MHz ~ 0.25% clock
 * for low speed and full speed operation. */
#if ( CONF_GCLK_USB_FREQUENCY > ( 48000000 + 48000000/400 )) ||	\
	( CONF_GCLK_USB_FREQUENCY < ( 48000000 - 48000000/400 ))
#    warning USB clock should be 48MHz ~ 0.25% clock, check your configuration!
#endif

void USB_0_CLOCK_init(void)
{
	_pm_enable_bus_clock(PM_BUS_APBB, USB);
	_pm_enable_bus_clock(PM_BUS_AHB, USB);
	_gclk_enable_channel(USB_GCLK_ID, CONF_GCLK_USB_SRC);
}

void USB_0_init(void)
{
	USB_0_CLOCK_init();
	usb_d_init();
	USB_0_PORT_init();
}

void USB_0_example(void)
{
	USB_0_CLOCK_init();
	usbd_cdc_ser_echo_init();
	USB_0_PORT_init();
	usbd_cdc_ser_echo_attach();
	while(1) {
		__WFI();
	}
}

void SERCOM0_Handler(void)
{
	if (_irq_table[ SERCOM0_IRQn + 0 ]) {
		_irq_table[ SERCOM0_IRQn + 0 ]->handler(
				_irq_table[ SERCOM0_IRQn + 0 ]->parameter);
	} else {
		Default_Handler();
	}
}
void SERCOM1_Handler(void)
{
	if (_irq_table[ SERCOM0_IRQn + 1 ]) {
		_irq_table[ SERCOM0_IRQn + 1 ]->handler(
				_irq_table[ SERCOM0_IRQn + 1 ]->parameter);
	} else {
		Default_Handler();
	}
}
void TC3_Handler(void)
{
	if (_irq_table[ TCC0_IRQn + 3 ]) {
		_irq_table[ TCC0_IRQn + 3 ]->handler(
				_irq_table[ TCC0_IRQn + 3 ]->parameter);
	} else {
		Default_Handler();
	}
}
void EIC_Handler(void)
{
	if (_irq_table[ EIC_IRQn + 0 ]) {
		_irq_table[ EIC_IRQn + 0 ]->handler(
				_irq_table[ EIC_IRQn + 0 ]->parameter);
	} else {
		Default_Handler();
	}
}
void AC_Handler(void)
{
	if (_irq_table[ AC_IRQn + 0 ]) {
		_irq_table[ AC_IRQn + 0 ]->handler(_irq_table[ AC_IRQn + 0 ]->parameter);
	} else {
		Default_Handler();
	}
}
void DAC_Handler(void)
{
	if (_irq_table[ DAC_IRQn + 0 ]) {
		_irq_table[ DAC_IRQn + 0 ]->handler(
				_irq_table[ DAC_IRQn + 0 ]->parameter);
	} else {
		Default_Handler();
	}
}
void WDT_Handler(void)
{
	if (_irq_table[ WDT_IRQn + 0 ]) {
		_irq_table[ WDT_IRQn + 0 ]->handler(
				_irq_table[ WDT_IRQn + 0 ]->parameter);
	} else {
		Default_Handler();
	}
}
void DMAC_Handler(void)
{
	if (_irq_table[ DMAC_IRQn + 0 ]) {
		_irq_table[ DMAC_IRQn + 0 ]->handler(
				_irq_table[ DMAC_IRQn + 0 ]->parameter);
	} else {
		Default_Handler();
	}
}
void SYSCTRL_Handler(void)
{
	if (_irq_table[ SYSCTRL_IRQn + 0 ]) {
		_irq_table[ SYSCTRL_IRQn + 0 ]->handler(
				_irq_table[ SYSCTRL_IRQn + 0 ]->parameter);
	} else {
		Default_Handler();
	}
}
void PM_Handler(void)
{
	if (_irq_table[ PM_IRQn + 0 ]) {
		_irq_table[ PM_IRQn + 0 ]->handler(_irq_table[ PM_IRQn + 0 ]->parameter);
	} else {
		Default_Handler();
	}
}
void USB_Handler(void)
{
	if (_irq_table[ USB_IRQn + 0 ]) {
		_irq_table[ USB_IRQn + 0 ]->handler(
				_irq_table[ USB_IRQn + 0 ]->parameter);
	} else {
		Default_Handler();
	}
}

/**
 * Example of using SPI_0 to write "Hello World" using the IO abstraction.
 */
static uint8_t example_SPI_0[12] = "Hello World!";

void SPI_0_example(void)
{
	struct io_descriptor *io;
	spi_m_sync_get_io_descriptor(&SPI_0, &io);

	spi_m_sync_enable(&SPI_0);
	io_write(io, example_SPI_0, 12);
}

/**
 * Example of using TIMER_0.
 */
// converts array to uint16_t
static void array_to_16bit(void)
{
	
	uint8_t MSbyte = 0;
	uint8_t LSbyte = 0;
	
	// previous value for MSbyte
	uint8_t prev1 = 0;
	// previous value for LSbyte
	uint8_t prev2 = 0;
	
	// convert first 8 bits of data to a byte
	for(int i = 0;i<8;i++)
	{
		MSbyte = prev1 + (data[7-i]<<i);
		prev1 = MSbyte;
	}
	// convert last 8 bits to a byte
	for(int i = 0;i<8;i++)
	{
		LSbyte = prev2 + (data[15-i]<<i);
		prev2 = LSbyte;
	}
	
	value = MSbyte;
	value = value << 8;
	value |= LSbyte;
	
}

static void TIMER_0_task1_cb(const struct timer_task *const timer_task)
{
	gpio_set_pin_level(CONV,true);
}

static void TIMER_0_task2_cb(const struct timer_task *const timer_task)
{
	gpio_set_pin_level(CONV,false);
	for(uint8_t i = 0; i < 16; i++)
	{
		gpio_set_pin_level(SCK,false);
		gpio_set_pin_level(SCK,true);
		
		// get pin level and put value into data array
		if(gpio_get_pin_level(SDI))
		{
			data[i] = 1;
		}
		else
		{
			data[i] = 0;
		}
	}
	array_to_16bit();
	
	if(count >= numConvs - 1)
	{
		data_buffer[count] = value;
		count = 0;
	}
	else
	{
		count++;
	}
	
	// sets the threshold value for where the LED turns on and off... it will turn on when signal exceeds threshold, and off when it goes below. 
	// Right now threshold is set at (2^16)/2 since 0 is min, and 2^16 is max. So 50% threshold.
	if (value > 32767)
	{
		gpio_set_pin_level(PA04,false);
	}
	else
	{
		gpio_set_pin_level(PA04,true);
	}
	
}


void TIMER_0_example(void)
{
	TIMER_0_task1.interval = 1;
	TIMER_0_task1.cb = TIMER_0_task1_cb;
	TIMER_0_task1.mode = TIMER_TASK_REPEAT;
	TIMER_0_task2.interval = 2;
	TIMER_0_task2.cb = TIMER_0_task2_cb;
	TIMER_0_task2.mode = TIMER_TASK_REPEAT;

	timer_add_task(&TIMER_0, &TIMER_0_task1);
	timer_add_task(&TIMER_0, &TIMER_0_task2);
	timer_set_clock_cycles_per_tick(&TIMER_0,1);
	timer_start(&TIMER_0);
}

/**
 * Example of using EXTERNAL_IRQ_0
 */
void EXTERNAL_IRQ_0_example(void)
{
}

void system_init(void)
{
	init_mcu();

	SPI_0_init();

	USART_0_init();

	TIMER_0_init();
	EXTERNAL_IRQ_0_init();

	AC_0_init();

	DAC_0_init();

	WDT_0_init();

	DMA_0_init();

	USB_0_init();
}
