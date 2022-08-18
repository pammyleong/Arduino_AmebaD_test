/**
  ******************************************************************************
  * @file    floader_nand_ftl.h
  * @author  Realsil WLAN5 Team
  * @date    2021-01-27
  * @brief   This file is the header file for floader_nand_ftl.c
  ******************************************************************************
  * @attention
  *
  * This module is a confidential and proprietary property of RealTek and
  * possession or use of this module requires written permission of RealTek.
  *
  * Copyright(c) 2020, Realtek Semiconductor Corporation. All rights reserved.
  ******************************************************************************
  */

#ifndef _FLOADER_NAND_FTL_H
#define _FLOADER_NAND_FTL_H

/* Includes ------------------------------------------------------------------*/

#include "floader_flash_ftl.h"

/* Exported defines ----------------------------------------------------------*/

#define NF_ENABLE_MARKBD			1

#define NF_BAD_BLOCK				0x00U
#define NF_GOOD_BLOCK				0xFFU

#define NF_SMALL_PAGE_SIZE			2048U
#define NF_BIG_PAGE_SIZE			4096U

/* Exported types ------------------------------------------------------------*/

typedef struct {
	Flash_InfoTypeDef MemInfo;
	__IO u8 CurTarget;
	__IO u8 Initialized;
	__IO u32 LastErasedBlockAddr;
} NAND_FTL_DeviceTypeDef;

/* Exported variables --------------------------------------------------------*/

/* Exported functions --------------------------------------------------------*/

u8 NAND_FTL_Init(void);
u8 NAND_FTL_Query(Flash_InfoTypeDef *info);
u8 NAND_FTL_ReadPage(u32 addr, u8 *buf);
u8 NAND_FTL_EraseBlock(u32 addr);
u8 NAND_FTL_WritePage(u32 addr, const u8 *buf, u8 do_erase);
u8 NAND_FTL_IsBad(u32 addr, u8 *value);
u8 NAND_FTL_MarkBad(u32 addr, u8 value);
u8 NAND_FTL_GetStatus(u8 cmd, u8 addr, u8 *value);
u8 NAND_FTL_SetStatus(u8 cmd, u8 addr, u8 value);

#endif // _FLOADER_NAND_FTL_H

