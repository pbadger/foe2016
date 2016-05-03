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

/**
 * \brief Initialize DAC
 */
int32_t _dac_async_init(struct _dac_async_device *const device, void *const hw)
{
	int32_t init_status;

	ASSERT(device);

	init_status = _dac_init(hw);
	if (init_status) {
		return init_status;
	}
	device->hw = hw;

	device->irq.handler = _dac_interrupt_handler;
	device->irq.parameter = (void *)device;
	_irq_disable(DAC_IRQn);
	_irq_clear(DAC_IRQn);
	_irq_register(DAC_IRQn, &device->irq);
	_irq_enable(DAC_IRQn);

	return ERR_NONE;
}

/**
 * \brief De-initialize DAC
 */
void _dac_sync_deinit(struct _dac_sync_device *const device)
{
	_dac_deinit(device->hw);
}

/**
 * \brief De-initialize DAC
 */
void _dac_async_deinit(struct _dac_async_device *const device)
{
	_irq_disable(DAC_IRQn);

	_dac_deinit(device->hw);
}

/**
 * \brief Enable DAC Channel
 */
void _dac_sync_enable_channel(struct _dac_sync_device *const device,
		const uint8_t ch)
{
	(void)ch;
	hri_dac_set_CTRLA_ENABLE_bit(device->hw);
}

/**
 * \brief Enable DAC Channel
 */
void _dac_async_enable_channel(struct _dac_async_device *const device,
		const uint8_t ch)
{
	(void)ch;
	hri_dac_set_CTRLA_ENABLE_bit(device->hw);
}

/**
 * \brief Disable DAC Channel
 */
void _dac_sync_disable_channel(struct _dac_sync_device *const device,
		const uint8_t ch)
{
	(void)ch;
	hri_dac_clear_CTRLA_ENABLE_bit(device->hw);
}

/**
 * \brief Disable DAC Channel
 */
void _dac_async_disable_channel(struct _dac_async_device *const device,
		const uint8_t ch)
{
	(void)ch;
	hri_dac_clear_CTRLA_ENABLE_bit(device->hw);
}

bool _dac_sync_is_channel_enable(struct _dac_sync_device *const device,
		const uint8_t ch)
{
	(void)ch;
	return hri_dac_get_CTRLA_ENABLE_bit(device->hw);
}

bool _dac_async_is_channel_enable(struct _dac_async_device *const device,
		const uint8_t ch)
{
	(void)ch;
	return hri_dac_get_CTRLA_ENABLE_bit(device->hw);
}

/**
 * \brief write synchronous DAC data for output
 */
void _dac_sync_write_data(struct _dac_sync_device *const device, const uint16_t data,
		const uint8_t ch)
{
	(void)ch;
	hri_dac_write_DATA_reg(device->hw, data);
}

/**
 * \brief write DAC data for output
 */
void _dac_async_write_data(struct _dac_async_device *const device, const uint16_t data,
		const uint8_t ch)
{
	(void)ch;
	hri_dac_write_DATABUF_reg(device->hw, data);
}

/**
 * \brief Enable/disable DAC interrupt
 *
 * param[in] device The pointer to DAC device instance
 * param[in] type The type of interrupt to disable/enable if applicable
 * param[in] state Enable or disable
 */
void _dac_async_set_irq_state(struct _dac_async_device *const device,
		const enum _dac_callback_type type, const bool state)
{
	void *hw = device->hw;

	if (DAC_DEVICE_CONVERSION_DONE_CB == type) {
		hri_dac_write_INTEN_EMPTY_bit(hw, state);
	} else if (DAC_DEVICE_ERROR_CB == type) {
		hri_dac_write_INTEN_UNDERRUN_bit(hw, state);
	}
}

/** \endcond */
/**
 * \page hpl__dac__hw_module1__doc DAC HPL Implement
 *
 * \section hpl__dac__hw_module1__hw DAC Specific Information
 * DAC default configuration for dedicated device's peripheral can be changed
 * in hpl_dac1_v101_config.h. Refer to it for more information.
 * \section hpl__dac__hw_module1__errata DAC Errata Workarounds
 * There is no errata releated to DAC module.
 */

