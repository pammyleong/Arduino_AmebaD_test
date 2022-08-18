/**
  ******************************************************************************
  * @file    usbd_core_rom.h
  * @author  Realsil WLAN5 Team
  * @version V1.0.0
  * @date    2020-11-23
  * @brief   This file is the header file for usbd_core_rom.c
  ******************************************************************************
  * @attention
  *
  * This module is a confidential and proprietary property of RealTek and
  * possession or use of this module requires written permission of RealTek.
  *
  * Copyright(c) 2020, Realtek Semiconductor Corporation. All rights reserved.
  ******************************************************************************
  */

#ifndef __USBD_CORE_ROM_H
#define __USBD_CORE_ROM_H

/* Includes ------------------------------------------------------------------*/

#include "usbd_hal_rom.h"
#include "usbd_cdc_rom.h"

/* Exported defines ----------------------------------------------------------*/

/* Exported types ------------------------------------------------------------*/

/* Exported macros -----------------------------------------------------------*/

/* Exported variables --------------------------------------------------------*/

/* Exported functions --------------------------------------------------------*/

USBD_StatusTypeDef USBD_Core_Init(USBD_CDC_ItfTypeDef *fops, USBD_SpeedTypeDef speed);
USBD_StatusTypeDef USBD_Core_DeInit(void);
USBD_StatusTypeDef USBD_SetupStage(USBD_HandleTypeDef *pdev, uint8_t *psetup);
USBD_StatusTypeDef USBD_DataOutStage(USBD_HandleTypeDef *pdev, uint8_t epnum, uint8_t *pdata);
USBD_StatusTypeDef USBD_DataInStage(USBD_HandleTypeDef *pdev, uint8_t epnum, uint8_t *pdata);
USBD_StatusTypeDef USBD_Reset(USBD_HandleTypeDef  *pdev);
USBD_StatusTypeDef USBD_SetSpeed(USBD_HandleTypeDef  *pdev, USBD_SpeedTypeDef speed);
USBD_StatusTypeDef USBD_Suspend(USBD_HandleTypeDef  *pdev);
USBD_StatusTypeDef USBD_Resume(USBD_HandleTypeDef  *pdev);
USBD_StatusTypeDef USBD_SOF(USBD_HandleTypeDef  *pdev);
USBD_StatusTypeDef USBD_DevConnected(USBD_HandleTypeDef  *pdev);
USBD_StatusTypeDef USBD_DevDisconnected(USBD_HandleTypeDef  *pdev);
USBD_StatusTypeDef USBD_OpenEP(USBD_HandleTypeDef *pdev, uint8_t  ep_addr, uint8_t  ep_type, uint16_t ep_mps);
USBD_StatusTypeDef USBD_CloseEP(USBD_HandleTypeDef *pdev, uint8_t ep_addr);
USBD_StatusTypeDef USBD_Transmit(USBD_HandleTypeDef *pdev, uint8_t  ep_addr, uint8_t  *pbuf, uint16_t  size);
USBD_StatusTypeDef USBD_PrepareReceive(USBD_HandleTypeDef *pdev, uint8_t  ep_addr, uint8_t  *pbuf, uint16_t  size);
USBD_StatusTypeDef USBD_CtlSendData(USBD_HandleTypeDef *pdev, uint8_t *pbuf, uint16_t len);
USBD_StatusTypeDef USBD_CtlPrepareRx(USBD_HandleTypeDef  *pdev, uint8_t *pbuf, uint16_t len);
uint32_t USBD_GetRxDataSize(USBD_HandleTypeDef *pdev, uint8_t  ep_addr);
void USBD_CtlError(USBD_HandleTypeDef  *pdev, USBD_SetupReqTypedef *req);
void USBD_GetString(uint8_t *desc, uint8_t *unicode, uint16_t *len);
void USBD_IRQHandler(void);

#endif /* __USBD_CORE_ROM_H */

