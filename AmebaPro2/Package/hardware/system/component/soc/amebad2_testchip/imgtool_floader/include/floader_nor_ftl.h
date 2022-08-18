/**
  ******************************************************************************
  * @file    floader_nor_ftl.h
  * @author  Realsil WLAN5 Team
  * @date    2021-01-27
  * @brief   This file is the header file for floader_nor_ftl.c
  ******************************************************************************
  * @attention
  *
  * This module is a confidential and proprietary property of RealTek and
  * possession or use of this module requires written permission of RealTek.
  *
  * Copyright(c) 2020, Realtek Semiconductor Corporation. All rights reserved.
  ******************************************************************************
  */

#ifndef _FLOADER_NOR_FTL_H
#define _FLOADER_NOR_FTL_H

/* Includes ------------------------------------------------------------------*/

#include "floader_flash_ftl.h"

/* Exported defines ----------------------------------------------------------*/

/* Exported types ------------------------------------------------------------*/

/* Exported variables --------------------------------------------------------*/

/* Exported functions --------------------------------------------------------*/

void NOR_FTL_Init(void);
void NOR_FTL_Query(Flash_InfoTypeDef *info);
void NOR_FTL_ReadPage(u32 addr, u8 *buf);
void NOR_FTL_EraseBlock(u32 addr, u32 size);
void NOR_FTL_WritePage(u32 addr, const u8 *buf);
u16 NOR_FTL_GetStatus(u8 cmd, u8 size);
void NOR_FTL_SetStatus(u8 cmd, u8 size, u8 *status);

#endif // _FLOADER_NOR_FTL_H

