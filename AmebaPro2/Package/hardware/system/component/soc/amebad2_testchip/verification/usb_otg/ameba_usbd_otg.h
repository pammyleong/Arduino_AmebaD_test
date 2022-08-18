#ifndef __AMEBA_USBD_OTG_H
#define __AMEBA_USBD_OTG_H
#include "usb_ch9.h"

#ifdef CONFIG_USB_OTG
/* USB_DT_OTG (from OTG 1.0a supplement) */
struct usb_otg_descriptor {
	u8  bLength;
	u8  bDescriptorType;

	u8  bmAttributes;	/* support for HNP, SRP, etc */
};
#define USB_DT_OTG_SIZE      3

/* USB_DT_OTG (from OTG 2.0 supplement) */
struct usb_otg20_descriptor {
	u8  bLength;
	u8  bDescriptorType;

	u8  bmAttributes;	/* support for HNP, SRP and ADP, etc */
	u16 bcdOTG;		/* OTG and EH supplement release number in binary-coded decimal(i.e. 2.0 is 0200H) */
};
#define USB_DT_OTG20_SIZE      5

/* from usb_otg_descriptor.bmAttributes */
#define USB_OTG_SRP		(1 << 0)
#define USB_OTG_HNP		(1 << 1)	/* swap host/device roles */
#define USB_OTG_ADP		(1 << 2)	/* support ADP */

#define OTG_STS_SELECTOR	0xF000		/* OTG status selector */

/** @defgroup OTG_DESCRIPTORS
  * @{
  */
struct usb_otg_descriptor verify_otg_descriptor = {
	.bLength				= USB_DT_OTG_SIZE,
	.bDescriptorType		= USB_DT_OTG,
	.bmAttributes			= (USB_OTG_SRP | USB_OTG_HNP),
};

struct usb_otg20_descriptor verify_otg20_descriptor = {
	.bLength				= USB_DT_OTG_SIZE,
	.bDescriptorType		= USB_DT_OTG,
	.bmAttributes			= (USB_OTG_SRP | USB_OTG_HNP),
	.bcdOTG				= 0x0200,
};

/**
  * @}
  */
#endif	//CONFIG_USB_OTG
#endif	//__AMEBA_USBD_OTG_H
