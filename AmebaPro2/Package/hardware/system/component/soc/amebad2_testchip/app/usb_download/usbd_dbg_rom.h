/**
  ******************************************************************************
  * @file    usbd_dbg_rom.h
  * @author  Realsil WLAN5 Team
  * @version V1.0.0
  * @date    2020-11-23
  * @brief   This file provides the USB debug functions
  ******************************************************************************
  * @attention
  *
  * This module is a confidential and proprietary property of RealTek and
  * possession or use of this module requires written permission of RealTek.
  *
  * Copyright(c) 2020, Realtek Semiconductor Corporation. All rights reserved.
  ******************************************************************************
  */

#ifndef USBD_DBG_ROM_H
#define USBD_DBG_ROM_H

/* Includes ------------------------------------------------------------------*/

#include "ameba_soc.h"

/* Exported defines ----------------------------------------------------------*/

#ifndef USB_DEBUG_LEVEL
#define USB_DEBUG_LEVEL         0U
#endif

/* Exported macros -----------------------------------------------------------*/

#if (USB_DEBUG_LEVEL > 0U)
#define  USB_INFO(...)  		do { \
									DiagPrintf("[USBD] ") ;\
									DiagPrintf(__VA_ARGS__);\
									DiagPrintf("\n"); \
								} while(0)
#else
#define USB_INFO(...)
#endif

#if (USB_DEBUG_LEVEL > 1U)

#define  USB_ERROR(...)   		do { \
									DiagPrintf("[USBD][ERROR] ") ;\
									DiagPrintf(__VA_ARGS__);\
									DiagPrintf("\n"); \
								} while(0)
#else
#define USB_ERROR(...)
#endif

#if (USB_DEBUG_LEVEL > 2U)

#define  USB_WARN(...)  		do { \
									DiagPrintf("[USBD][WARN] ") ;\
									DiagPrintf(__VA_ARGS__);\
									DiagPrintf("\n"); \
								} while(0)
#else
#define USB_WARN(...)
#endif

#if (USB_DEBUG_LEVEL > 3U)
#define  USB_DEBUG(...)   		do { \
									DiagPrintf("[USBD][DEBUG] ") ;\
									DiagPrintf(__VA_ARGS__);\
									DiagPrintf("\n"); \
								} while(0)
#else
#define USB_DEBUG(...)
#endif

/* Exported variables --------------------------------------------------------*/

/* Exported functions --------------------------------------------------------*/

void USBD_DebugInit(void);
void USBD_Debug(u32 code, u32 delay);

#endif /* USBD_DBG_ROM_H */

