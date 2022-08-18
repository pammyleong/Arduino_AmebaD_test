/*
 *  Routines to access hardware
 *
 *  Copyright (c) 2013 Realtek Semiconductor Corp.
 *
 *  This module is a confidential and proprietary property of RealTek and
 *  possession or use of this module requires written permission of RealTek.
 */

#ifndef _AMEBA_OTG_H_
#define _AMEBA_OTG_H_

#define DWC_EN_ISOC 1
#if defined(DWC_EN_ISOC)
#define USB_REQ_ISO_ASAP 1
#endif

//#define CONFIG_USB_OTG							1

#define HAL_OTG_READ32(addr)					HAL_READ32(USB_OTG_REG_BASE, (u32)addr)
#define HAL_OTG_WRITE32(addr, value)			HAL_WRITE32(USB_OTG_REG_BASE, (u32)addr, value)

#define HAL_OTG_MODIFY32(addr, clrmsk, setmsk)	HAL_WRITE32(USB_OTG_REG_BASE,(u32)addr,\
												((HAL_READ32(USB_OTG_REG_BASE, (u32)addr) & (~clrmsk)) | setmsk))

#define DWC_READ_REG32(_reg_)					HAL_OTG_READ32((u32)_reg_)
#define DWC_WRITE_REG32(_reg_, _val_)			HAL_OTG_WRITE32((u32)_reg_,_val_)
#define DWC_MODIFY_REG32(_reg_,_cmsk_,_smsk_)	HAL_OTG_MODIFY32((u32)_reg_,_cmsk_,_smsk_)

// USB OTG addon register
#define REG_OTG_PWCSEQ_IP_OFF		0x30004		//This is in OTG IP
#define REG_OTG_PS_INTR_STS			0x30008		//This is in OTG IP
#define REG_OTG_PS_INTR_MSK			0x3000C		//This is in OTG IP
#define REG_OTG_VND_STS_OUT			0x3001C		//This is in OTG IP

/* #define REG_OTG_PWCSEQ_IP_OFF	0x30004 */
#define BIT_PWR_SAV_EN				BIT(0)	/* R/W	0		1: Enable USB power save */
#define BIT_UPLL_CKRDY				BIT(5)	/* R/W	0		1: USB PHY clock ready */
#define BIT_USBOTG_EN				BIT(8)	/* R/W	0		1: Enable USB OTG */
#define BIT_USBPHY_EN				BIT(9)	/* R/W	0		1: Enable USB PHY */
#define BIT_PORETB_TOP				BIT(14)	/* R/W	0		1: Enable USB APHY */

/* USB PHY registers */
#define USB_PHY_E0						0xE0
#define USB_PHY_E1						0xE1
#define USB_PHY_E2						0xE2
#define USB_PHY_E4						0xE4
#define USB_PHY_E6						0xE6
#define USB_PHY_E7						0xE7
#define USB_PHY_F1						0xF1
#define USB_PHY_F4						0xF4
#define USB_PHY_F6						0xF6

/* USB_PHY_E0 PAGE0 bits */
#define USB_PHY_PAGE0_BIT_Z0_AUTO_K		((u8)0x01 << 6)
#define USB_PHY_PAGE0_MASK_Z0_ADJR		((u8)0x0F << 2)
#define USB_PHY_PAGE0_Z0_ADJR(x)		((u8)((x) & 0x0F) << 2)

/* USB_PHY_E1 PAGE1 bits */
#define USB_PHY_PAGE1_BIT_EN_OTG		((u8)0x01 << 7)
#define USB_PHY_PAGE1_MASK_SRC		((u8)0x07 << 4)
#define USB_PHY_PAGE1_SRC(x)		((u8)((x) & 0x07) << 4)

/* USB_PHY_E2 PAGE1 bits */
#define USB_PHY_PAGE1_BIT_SREN			((u8)0x01 << 6)
#define USB_PHY_PAGE1_MASK_SRVH		((u8)0x07 << 0)
#define USB_PHY_PAGE1_SRVH(x)		((u8)((x) & 0x07) << 0)
#define USB_PHY_PAGE1_MASK_SRM		((u8)0x07 << 3)
#define USB_PHY_PAGE1_SRM(x)		((u8)((x) & 0x07) << 3)

/* USB_PHY_E4 PAGE0 bits */
#define USB_PHY_PAGE0_MASK_SITX		((u8)0x0F << 0)
#define USB_PHY_PAGE0_SITX(x)		((u8)((x) & 0x0F) << 0)

/* USB_PHY_E6 PAGE0 bits */
#define USB_PHY_PAGE0_MASK_RX_BOOST		((u8)0x03 << 0)
#define USB_PHY_PAGE0_RX_BOOST(x)		((u8)((x) & 0x03) << 0)

/* USB_PHY_E7 PAGE2 bits */
#define USB_PHY_PAGE2_MASK_SEND_OBJ		((u8)0x0F << 0)
#define USB_PHY_PAGE2_SEND_OBJ(x)		((u8)((x) & 0x0F) << 0)
#define USB_PHY_PAGE2_MASK_SENH_OBJ		((u8)0x0F << 4)
#define USB_PHY_PAGE2_SENH_OBJ(x)		((u8)((x) & 0x0F) << 4)

/* USB_PHY_F1 PAGE0 bits */
#define USB_PHY_PAGE0_BIT_UTMI_POS_OUT		((u8)0x01 << 7)

/* USB_PHY_F4 bits */
#define USB_PHY_MASK_PAGE_SEL			((u8)0x03 << 5)
#define USB_PHY_PAGE_SEL(x)				((u8)((x) & 0x03) << 5)

/* USB_PHY_F6 PAGE1 bits */
#define USB_PHY_PAGE1_MASK_LATE_DLLEN		((u8)0x03 << 0)
#define USB_PHY_PAGE1_LATE_DLLEN(x)		((u8)((x) & 0x03) << 0)
#define USB_PHY_PAGE1_BIT_NSQ_VLD_SEL		((u8)0x01 << 2)
#define USB_PHY_PAGE1_BIT_DISABLE_EB_WAIT4IDLE		((u8)0x01 << 3)
#define USB_PHY_PAGE1_BIT_WATER_LEVEL_CLEAN_SEL		((u8)0x01 << 4)
#define USB_PHY_PAGE1_MASK_NSQ_DEL_SEL		((u8)0x03 << 5)
#define USB_PHY_PAGE1_NSQ_DEL_SEL(x)		((u8)((x) & 0x03) << 5)

/* USB PHY page definition */
#define USB_PHY_PAGE0				0
#define USB_PHY_PAGE1				1
#define USB_PHY_PAGE2				2
#define USB_PHY_PAGE3				3

#define PHY_HIGH_ADDR(x)			(((x) & 0xF0) >> 4)
#define PHY_LOW_ADDR(x)				((x) & 0x0F)
#define PHY_DATA_MASK				0xFF
#endif
