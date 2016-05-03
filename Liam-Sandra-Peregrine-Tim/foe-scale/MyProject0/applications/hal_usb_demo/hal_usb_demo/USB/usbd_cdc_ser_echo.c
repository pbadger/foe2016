/**
 * \file
 *
 * \brief SAM USB CDC Serial Echo Demo
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

#include <hal_usb_device.h>
//#include <usb_protocol.h>

#include <stdio.h>
#include <string.h>

/** \name Device descriptor settings */
/*@{*/

/** USB device Vendor ID. */
#define VID 0x03eb

/** USB device Product ID. */
#define PID 0x2404
/*@}*/

/** \name Endpoint settings */
/*@{*/

/** Endpoint address of control endpoint. */
#define EP_CTRL      0x00

/** Endpoint size of control endpoint. */
#define EP_CTRL_SIZE 64

/** Endpoint size of bulk endpoint. */
#define EP_BULK_SIZE 64

/** Endpoint size of interrupt endpoint. */
#define EP_INT_SIZE  64

/** Endpoint address of bulk OUT endpoint. */
#define EP_BULK_O      0x01

/** Endpoint size of bulk OUT endpoint. */
#define EP_BULK_O_SIZE EP_BULK_SIZE

/** Endpoint address of bulk IN endpoint. */
#define EP_BULK_I      0x81

/** Endpoint size of bulk IN endpoint. */
#define EP_BULK_I_SIZE EP_BULK_SIZE

/** Endpoint address of interrupt IN endpoint. */
#define EP_INT_I          0x82

/** Endpoint size of interrupt IN endpoint. */
#define EP_INT_I_SIZE     EP_INT_SIZE

/** Endpoint interval of interrupt IN endpoint. */
#define EP_INT_I_INTERVAL 10
/*@}*/

/** Configuration descriptor total size. */
#define CONFIG_DESC_LENGTH 67

/** \name Macros to build USB standard descriptors */
/*@{*/

/** Build bytes for USB device descriptor. */
#define USB_DEV_DESC_BYTES(bcdUSB,\
		bDeviceClass, bDeviceSubClass, bDeviceProtocol,\
		bMaxPacketSize0,\
		idVendor, idProduct, bcdDevice,\
		iManufacturer, iProduct, iSerialNumber,\
		bNumConfigurations) \
		18, /* bLength */\
		0x01, /* bDescriptorType: DEVICE */\
		LE_BYTE0(bcdUSB), LE_BYTE1(bcdUSB),\
		(bDeviceClass), (bDeviceSubClass), (bDeviceProtocol),\
		(bMaxPacketSize0),\
		LE_BYTE0(idVendor), LE_BYTE1(idVendor),\
		LE_BYTE0(idProduct), LE_BYTE1(idProduct),\
		LE_BYTE0(bcdDevice), LE_BYTE1(bcdDevice),\
		(iManufacturer), (iProduct), (iSerialNumber),\
		(bNumConfigurations)

/** Build bytes for USB configuration descriptor. */
#define USB_CONFIG_DESC_BYTES(wTotalLength,\
		bNumInterfaces, bConfigurationValue, iConfiguration,\
		bmAttributes, bMaxPower) \
		9, /* bLength */\
		0x02, /* bDescriptorType: CONFIGURATION */\
		LE_BYTE0(wTotalLength), LE_BYTE1(wTotalLength),\
		(bNumInterfaces), (bConfigurationValue), (iConfiguration),\
		(bmAttributes), (bMaxPower)

/** Build bytes for USB interface descriptor. */
#define USB_IFACE_DESC_BYTES(bInterfaceNumber, bAlternateSetting,\
		bNumEndpoints,\
		bInterfaceClass, bInterfaceSubClass, bInterfaceProtocol,\
		iInterface) \
		9, /* bLength */\
		0x04, /* bDescriptorType: INTERFACE */\
		(bInterfaceNumber), (bAlternateSetting), (bNumEndpoints),\
		(bInterfaceClass), (bInterfaceSubClass), (bInterfaceProtocol),\
		(iInterface)

/** Build bytes for USB endpoint descriptor. */
#define USB_ENDP_DESC_BYTES(bEndpointAddress,\
		bmAttributes, wMaxPacketSize, bInterval) \
		7, /* bLength */\
		0x05, /* bDescriptorType: ENDPOINT */\
		(bEndpointAddress), (bmAttributes),\
		LE_BYTE0(wMaxPacketSize), LE_BYTE1(wMaxPacketSize),\
		(bInterval)

/** Build bytes for USB CDC serial device descriptor. */
#define USB_CDC_SER_DEV_DESC_BYTES(bcdUSB,\
		bMaxPacketSize0,\
		idVendor, idProduct, bcdDevice,\
		iManufacturer, iProduct, iSerialNumber,\
		bNumConfigurations) \
		USB_DEV_DESC_BYTES((bcdUSB), 0x02, 0x00, 0x00, (bMaxPacketSize0),\
				(idVendor), (idProduct), (bcdDevice),\
				(iManufacturer), (iProduct), (iSerialNumber),\
				(bNumConfigurations))
/*@}*/

/** \name USB basic and CDC serial protocol */
/*@{*/

/**
 * \brief Standard USB requests (bRequest)
 */
enum usb_req_code {
	USB_REQ_GET_STATUS = 0,
	USB_REQ_CLEAR_FTR = 1,
	USB_REQ_SET_FTR = 3,
	USB_REQ_SET_ADDRESS = 5,
	USB_REQ_GET_DESC = 6,
	USB_REQ_SET_DESC = 7,
	USB_REQ_GET_CONFIG = 8,
	USB_REQ_SET_CONFIG = 9,
	USB_REQ_GET_INTERFACE = 10,
	USB_REQ_SET_INTERFACE = 11,
	USB_REQ_SYNCH_FRAME = 12,
	USB_REQ_SET_SEL = 48,
	USB_REQ_ISOCH_DELAY = 49
};

/**
 * \brief Standard USB descriptor types
 */
enum usb_descriptor_type {
	USB_DT_DEVICE = 1,
	USB_DT_CONFIG = 2,
	USB_DT_STRING = 3,
	USB_DT_INTERFACE = 4,
	USB_DT_ENDPOINT = 5,
	USB_DT_DEVICE_QUALIFIER = 6,
	USB_DT_OTHER_SPEED_CONFIG = 7,
	USB_DT_INTERFACE_POWER = 8,
	USB_DT_OTG = 9,
	USB_DT_DEBUG = 10,
	USB_DT_IAD = 11,
	USB_DT_BOS = 15,
	USB_DT_DEV_CAP = 16,
	USB_DT_SS_EP_COMPANION = 48
};

/**
 * \brief Standard USB endpoint transfer types
 */
enum usb_ep_type {
	USB_EP_TYPE_CONTROL = 0x00,
	USB_EP_TYPE_ISOCHRONOUS = 0x01,
	USB_EP_TYPE_BULK = 0x02,
	USB_EP_TYPE_INTERRUPT = 0x03,
	USB_EP_TYPE_MASK = 0x03u,
};

#define  USB_REQT_DIR_IN          (1<<7) /*!< USB Device to host request */

#define  USB_REQT_TYPE_STANDARD   (0<<5) /*!< USB Standard request */
#define  USB_REQT_TYPE_CLASS      (1<<5) /*!< USB Class-specific request */
#define  USB_REQT_TYPE_VENDOR     (2<<5) /*!< USB Vendor-specific request */
#define  USB_REQT_TYPE_MASK       (3<<5) /*!< USBMask */

#define  USB_REQT_RECIP_DEVICE    (0<<0) /*!< USB Recipient device */
#define  USB_REQT_RECIP_INTERFACE (1<<0) /*!< USB Recipient interface */
#define  USB_REQT_RECIP_ENDPOINT  (2<<0) /*!< USB Recipient endpoint */
#define  USB_REQT_RECIP_MASK      (0x1F) /*!< USB recipient code Mask */


/** USB CDC SetLineCoding request. */
#define USB_REQ_CDC_SET_LINE_CODING        0x20

/** USB CDC GetLineCoding request. */
#define USB_REQ_CDC_GET_LINE_CODING        0x21

/** USB CDC SetControlLineState request. */
#define USB_REQ_CDC_SET_CONTROL_LINE_STATE 0x22

/** USB CDC ControlLineState carrier control or RS-232 RTS. */
#define CDC_CTRL_SIGNAL_ACTIVATE_CARRIER (1 << 1)

/** USB CDC ControlLineState DTE present or RS-232 DTR. */
#define CDC_CTRL_SIGNAL_DTE_PRESENT      (1 << 0)

COMPILER_PACK_SET(1);
/**
 * \brief A USB Device SETUP request
 *
 * The data payload of SETUP packets always follows this structure.
 */
typedef struct usb_req {
    uint8_t bmRequestType;
    uint8_t bRequest;
    uint16_t wValue;
    uint16_t wIndex;
    uint16_t wLength;
} usb_req_t;

/** USB CDC LineCoding struct. */
struct usb_cdc_line_coding {
	/** Data terminal rate, in bits per second. */
	uint32_t dwDTERate;
	/** Stop bits: 0-1 stop bit; 1-1.5 stop bits; 2-2 stop bits. */
	uint8_t bCharFormat;
	/** Parity: 0-none; 1-odd; 2-even; 3-mark; 4-space. */
	uint8_t bParityType;
	/** Data bits (5, 6, 7, 8 or 16). */
	uint8_t bDataBits;
};
COMPILER_PACK_RESET();
/*@}*/

/** Callback invoked when control request is received. */
static bool usb_device_cb_ctl_req(const uint8_t ep, struct usb_req *req);

/** Callback invoked when control transfer is done. */
static bool usb_device_cb_ctl_done(const uint8_t ep,
		const enum usb_xfer_code code,
		struct usb_req *req);

/** Callback invoked when bulk OUT data received. */
static bool usb_device_cb_bulk_out(const uint8_t ep,
		const enum usb_xfer_code rc, const uint32_t count);

/** USB descriptors for a CDC serial device. */
static uint8_t usb_cdc_ser_d_descriptors[] = {
	/* Device descriptor. */
	USB_CDC_SER_DEV_DESC_BYTES(0x0200, EP_CTRL_SIZE, VID, PID, 0x0100, 0, 0, 0, 1),

	/* Configuration descriptor & list. */
	USB_CONFIG_DESC_BYTES(CONFIG_DESC_LENGTH, 2, 1, 0, 0x80, 0x32),

	USB_IFACE_DESC_BYTES(0, 0, 1, 0x2, 0x2, 0x0, 0),
	/* Header Functional descriptor */
	5, /* bLength (bFunctionLength) */
	0x24, /* bDescriptorType: CS_INTERFACE */
	0x00, /* bDescriptorSubtype: Header Functional Descriptor */
	LE_BYTE0(0x1001), LE_BYTE1(0x1001) /* bcdCDC */
	,
	/* Call Management Functional descriptor */
	5, /* bLength (bFunctionLength) */
	0x24, /* bDescriptorType: CS_INTERFACE */
	0x01, /* bDescriptorSubtype: Call Management Functional Descriptor */
	0x01, /* bmCapabilities */
	0x00 /* bDataInterface */
	,
	/* Abstracted Control Management Functional */
	4, /* bLength (bFunctionLength) */
	0x24, /* bDescriptorType: CS_INTERFACE */
	0x02, /* bDescriptorSubtype: Abstracted Control Management Functional Descriptor */
	0x02 /* bmCapabilities */
	,
	/* Union Functional descriptor */
	5, /* bLength (bFunctionLength) */
	0x24, /* bDescriptorType: CS_INTERFACE */
	0x06, /* bDescriptorSubtype: Union Functional Descriptor */
	0x00, /* bControlInterface */
	0x01 /* bSubordinateInterface */
	,
	USB_ENDP_DESC_BYTES(EP_INT_I, 3, EP_INT_I_SIZE, EP_INT_I_INTERVAL),

	USB_IFACE_DESC_BYTES(1, 0, 2, 0xa, 0, 0, 0),
	USB_ENDP_DESC_BYTES(EP_BULK_O, 2, EP_BULK_O_SIZE, 0),
	USB_ENDP_DESC_BYTES(EP_BULK_I, 2, EP_BULK_I_SIZE, 0)
};

/** The USB device is in configured state. */
volatile static bool usbd_is_configured = false;

/** Control data buffer used when process control IN request.
 *  Size is set to 8 bytes for configure value (1 byte), status (2 bytes) or
 *  CDC line coding value (7 bytes).
 */
static uint32_t usbd_ctrl_buf[2];

/** Current USB CDC line coding used. */
static struct usb_cdc_line_coding usbd_cdc_line_coding;

/** Current USB CDC control line state. */
static uint16_t usbd_cdc_line_state = 0;

/** Buffers to receive and echo the communication bytes. */
static uint32_t usbd_cdc_buffer[2][EP_BULK_SIZE/4];

/** Current receiving buffer index. */
static uint8_t usbd_cdc_rx_buf_i = 0;

/**
 * \brief Callback invoked on USB device events
 * \param[in] ev Event code.
 * \param[in] param Event parameter for event handling.
 */
static void usb_device_cb_event(const enum usb_event ev, const uint32_t param)
{
	(void)param;

	switch(ev) {
	case USB_EV_RESET:
		usbd_is_configured = false;
		usb_d_ep_deinit(EP_CTRL);
		usb_d_ep_deinit(EP_BULK_I);
		usb_d_ep_deinit(EP_BULK_O);
		usb_d_ep_deinit(EP_INT_I);
		usb_d_ep0_init(EP_CTRL_SIZE);
		usb_d_ep_register_callback(0, USB_D_EP_CB_SETUP,
				(FUNC_PTR)usb_device_cb_ctl_req);
		usb_d_ep_register_callback(0, USB_D_EP_CB_XFER,
				(FUNC_PTR)usb_device_cb_ctl_done);
		usb_d_ep_enable(0);
		break;
	default:
		break;
	}
}

/**
 * \brief Issue USB device transfer
 * \param[in] ep Endpoint number and direction on bit 8.
 * \param[in] buf Pointer to the buffer used for transfer.
 * \param[in] size Transfer size.
 * \param[in] zlp Auto send ZLP for IN and wait ZLP for OUT.
 */
static inline void usb_device_xfer(const uint8_t ep, const uint8_t *buf, const uint32_t size, const bool zlp)
{
	struct usb_d_transfer xfer = {
		(uint8_t*)buf, size, ep, zlp
	};
	usb_d_ep_transfer(&xfer);
}

/**
 * \brief Process the GetDescriptor request
 * \param[in] ep Endpoint address.
 * \param[in] req Pointer to the request.
 * \return Operation status.
 * \retval true Request is handled OK.
 * \retval false Request not supported.
 */
static inline bool usb_device_get_desc_req(const uint8_t ep, struct usb_req *req)
{
	uint8_t type = (uint8_t)(req->wValue >> 8);
	uint16_t length = req->wLength;
	bool need_zlp = !(length & (EP_CTRL_SIZE - 1));
	switch(type) {
	case USB_DT_DEVICE:
		if (length > 0x12) {
			length = 0x12;
		}
		usb_device_xfer(ep, usb_cdc_ser_d_descriptors, length, false);
		return true;
	case USB_DT_CONFIG:
		if (length <= CONFIG_DESC_LENGTH) {
			need_zlp = false;
		} else {
			length = CONFIG_DESC_LENGTH;
		}
		usb_device_xfer(ep, &usb_cdc_ser_d_descriptors[0x12], length, need_zlp);
		return true;
	default:
		break;
	}
	return false;
}

/**
 * \brief Process the GetStatus request
 * \param[in] ep Endpoint address.
 * \param[in] req Pointer to the request.
 * \return Operation status.
 * \retval true Request is handled OK.
 * \retval false Request not supported.
 */
static bool _std_get_status_req(const uint8_t ep, const struct usb_req *req)
{
	int32_t st;
	(void)ep;
	switch (req->bmRequestType & USB_REQT_RECIP_MASK) {
	case USB_REQT_RECIP_DEVICE:
	case USB_REQT_RECIP_INTERFACE:
		st = 0;
		break;
	case USB_REQT_RECIP_ENDPOINT:
		st = usb_d_ep_halt(req->wIndex & 0xFF, USB_EP_HALT_GET);
		if (st < 0) {
			return false;
		}
		st = st & 0x1;
		break;
	default:
		return false;
	}
	memcpy(usbd_ctrl_buf, &st, 2);
	usb_device_xfer(ep, (const uint8_t *)usbd_ctrl_buf, 2, false);
	return true;
}

/**
 * \brief Process the standard Get request
 * \param[in] ep Endpoint address.
 * \param[in] req Pointer to the request.
 * \return Operation status.
 * \retval true Request is handled OK.
 * \retval false Request not supported.
 */
static bool _std_get_req(const uint8_t ep, struct usb_req *req)
{
	switch(req->bRequest) {
	case USB_REQ_GET_DESC:
		return usb_device_get_desc_req(ep, req);
	case USB_REQ_GET_CONFIG:
		*(uint8_t *)usbd_ctrl_buf = 1;
		usb_device_xfer(ep, (const uint8_t *)usbd_ctrl_buf, 1, false);
		return true;
	case USB_REQ_GET_STATUS:
		return _std_get_status_req(ep, req);
	case USB_REQ_GET_INTERFACE:
		default:
		return false;
	}
}

/**
 * \brief Process the standard ClearFeature request
 * \param[in] ep Endpoint address.
 * \param[in] req Pointer to the request.
 * \return Operation status.
 * \retval true Request is handled OK.
 * \retval false Request not supported.
 */
static bool _std_clear_ftr_req(const uint8_t ep, const struct usb_req *req)
{
	(void)ep;
	switch (req->bmRequestType & USB_REQT_RECIP_MASK) {
	case USB_REQT_RECIP_ENDPOINT:
		if (req->wIndex != 0) {
			return false;
		}
		usb_d_ep_halt(req->wIndex & 0xFF, USB_EP_HALT_CLR);
		return true;
	default:
		return false;
	}
}

/**
 * \brief Process the standard SetFeature request
 * \param[in] ep Endpoint address.
 * \param[in] req Pointer to the request.
 * \return Operation status.
 * \retval true Request is handled OK.
 * \retval false Request not supported.
 */
static bool _std_set_ftr_req(const uint8_t ep, const struct usb_req *req)
{
	(void)ep;
	switch (req->bmRequestType & USB_REQT_RECIP_MASK) {
	case USB_REQT_RECIP_ENDPOINT:
		if (req->wIndex != 0) {
			return false;
		}
		usb_d_ep_halt(req->wIndex & 0xFF, USB_EP_HALT_SET);
		return true;
	default:
		return false;
	}
}

/**
 * \brief Apply the configurations
 * \return Operation status.
 * \retval true Configuration application OK.
 * \retval false Configuration fail.
 */
static inline bool _set_config_exc(void)
{
	int32_t rc;
	rc = usb_d_ep_init(EP_BULK_I, USB_EP_TYPE_BULK, EP_BULK_I_SIZE);
	rc |= usb_d_ep_init(EP_BULK_O, USB_EP_TYPE_BULK, EP_BULK_O_SIZE);
	rc |= usb_d_ep_init(EP_INT_I, USB_EP_TYPE_INTERRUPT, EP_INT_I_SIZE);
	if (rc < 0) {
		return false;
	}
	usb_d_ep_register_callback(EP_BULK_O, USB_D_EP_CB_XFER,
			(FUNC_PTR)usb_device_cb_bulk_out);
	usb_d_ep_enable(EP_BULK_I);
	usb_d_ep_enable(EP_BULK_O);
	usb_d_ep_enable(EP_INT_I);
	return true;
}

/**
 * \brief Process the standard Set request
 * \param[in] ep Endpoint address.
 * \param[in] req Pointer to the request.
 * \return Operation status.
 * \retval true Request is handled OK.
 * \retval false Request not supported.
 */
static bool _std_set_req(const uint8_t ep, struct usb_req *req)
{
	switch(req->bRequest) {
	case USB_REQ_SET_ADDRESS:
		usb_device_xfer(ep, NULL, 0, true);
		return true;
	case USB_REQ_SET_CONFIG:
		if (_set_config_exc()) {
			usb_device_xfer(ep, NULL, 0, true);
		} else {
			return false;
		}
		return true;
	case USB_REQ_CLEAR_FTR:
		return _std_clear_ftr_req(ep, req);
	case USB_REQ_SET_FTR:
		return _std_set_ftr_req(ep, req);
	default:
		return false;
	}
}

/**
 * \brief Process the class Get request
 * \param[in] ep Endpoint address.
 * \param[in] req Pointer to the request.
 * \return Operation status.
 * \retval true Request is handled OK.
 * \retval false Request not supported.
 */
static bool _cls_get_req(const uint8_t ep, struct usb_req *req)
{
	uint16_t len = req->wLength;
	switch(req->bRequest) {
	case USB_REQ_CDC_GET_LINE_CODING:
		if (sizeof(struct usb_cdc_line_coding) != len) {
			return false;
		}
		usb_device_xfer(ep, (const uint8_t *)&usbd_cdc_line_coding, len, false);
		return true;
	default:
		return false;
	}
}

/**
 * \brief Callback invoked when bulk OUT data received
 * \param[in] ep Endpoint address.
 * \param[in] rc Transfer end up status code.
 * \param[in] count Number of bytes received.
 * \return \c true if there is error.
 */
static bool usb_device_cb_bulk_out(const uint8_t ep,
		const enum usb_xfer_code rc, const uint32_t count)
{
	/* Echo data. */
	usb_device_xfer(EP_BULK_I, (uint8_t *)usbd_cdc_buffer[usbd_cdc_rx_buf_i],
			count, true);

	/* Start RX on another buffer. */
	usbd_cdc_rx_buf_i = !usbd_cdc_rx_buf_i;
	usb_device_xfer(EP_BULK_O, (uint8_t *)usbd_cdc_buffer[usbd_cdc_rx_buf_i],
			EP_BULK_SIZE, false);

	/* No error. */
	return false;
}

/**
 * \brief Apply the CDC LineState
 * \param[in] line_state The line state to apply.
 * \return Operation status.
 * \retval true Configuration application OK.
 * \retval false Configuration fail.
 */
static inline void _set_line_state_exec(uint16_t line_state)
{
	usbd_cdc_line_state = line_state;
	usb_device_xfer(0, NULL, 0, 0);
	if (usbd_cdc_line_state & CDC_CTRL_SIGNAL_DTE_PRESENT) {
		/* Start RX. */
		usb_device_xfer(EP_BULK_O,
				(uint8_t *)usbd_cdc_buffer[usbd_cdc_rx_buf_i], EP_BULK_SIZE,
				false);
	} else {
		/* Stop transfer. */
		usb_d_ep_abort(EP_BULK_I);
		usb_d_ep_abort(EP_BULK_O);
	}
}

/**
 * \brief Process the class Set request
 * \param[in] ep Endpoint address.
 * \param[in] req Pointer to the request.
 * \return Operation status.
 * \retval true Request is handled OK.
 * \retval false Request not supported.
 */
static bool _cls_set_req(const uint8_t ep, struct usb_req *req)
{
	uint16_t len = req->wLength;
	switch(req->bRequest) {
	case USB_REQ_CDC_SET_LINE_CODING:
		if (sizeof(struct usb_cdc_line_coding) != len) {
			return false;
		}
		usb_device_xfer(ep, (const uint8_t *)usbd_ctrl_buf, len, false);
		return true;
	case USB_REQ_CDC_SET_CONTROL_LINE_STATE:
		_set_line_state_exec(req->wValue);
		return true;
	default:
		return false;
	}
}

/**
 * \brief Callback invoked when control request is received
 * \param[in] ep Endpoint address.
 * \param[in] req Pointer to the request.
 * \return Operation status.
 * \retval true Request is handled OK.
 * \retval false Request not supported.
 */
static bool usb_device_cb_ctl_req(const uint8_t ep, struct usb_req *req)
{
	switch(req->bmRequestType & (USB_REQT_TYPE_MASK|USB_REQT_DIR_IN)) {
	case USB_REQT_TYPE_STANDARD:
		return _std_set_req(ep, req);
	case (USB_REQT_TYPE_STANDARD|USB_REQT_DIR_IN):
		return _std_get_req(ep, req);
	case USB_REQT_TYPE_CLASS:
		return _cls_set_req(ep, req);
	case (USB_REQT_TYPE_CLASS|USB_REQT_DIR_IN):
		return _cls_get_req(ep, req);
	default:
		return false;
	}
}

/**
 * \brief When control data stage is end
 * \param[in] req Pointer to the request.
 */
static bool usb_device_ctrl_data_end(const struct usb_req *req)
{
	switch(req->bRequest) {
		case USB_REQ_CDC_SET_LINE_CODING:
		memcpy(&usbd_cdc_line_coding, usbd_ctrl_buf,
				sizeof(struct usb_cdc_line_coding));
		break;
	default:
		break;
	}
	return false;
}

/**
 * \brief Apply the USB device address
 */
static inline void _set_address_exc(uint8_t addr)
{
	usb_d_set_address(addr);
}

/**
 * \brief When control status stage is end
 * \param[in] req Pointer to the request.
 */
static void usb_device_ctrl_status_end(const struct usb_req *req)
{
	switch(req->bRequest) {
	case USB_REQ_SET_CONFIG:
		/* Set config done. */
		usbd_is_configured = true;
		break;
	case USB_REQ_SET_ADDRESS:
		_set_address_exc(req->wValue);
		break;
	default:
		break;
	}
}

/**
 * \brief Callback invoked when control data done or status done
 * \param[in] ep Endpoint number with direction on bit 8.
 * \param[in] code Status code.
 * \param[in] req Pointer to the control setup request.
 * \return Data has error or not.
 * \retval true There is data error, protocol error.
 * \retval false There is no data error.
 */
static bool usb_device_cb_ctl_done(const uint8_t ep,
		const enum usb_xfer_code code, struct usb_req *req)
{
	(void)ep;
	switch(code) {
	case USB_XFER_DONE:
		usb_device_ctrl_status_end(req);
		break;
	case USB_XFER_DATA:
		return usb_device_ctrl_data_end(req);
	default:
		break;
	}
	return false;
}

void usbd_cdc_ser_echo_init(void)
{
	usb_d_init();
	usb_d_register_callback(USB_D_CB_EVENT, (FUNC_PTR)usb_device_cb_event);
	usb_d_enable();
}

void usbd_cdc_ser_echo_attach(void)
{
	usb_d_attach();
}

