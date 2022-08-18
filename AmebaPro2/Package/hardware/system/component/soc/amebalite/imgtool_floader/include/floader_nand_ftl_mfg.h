/**
  ******************************************************************************
  * @file    floader_nand_ftl_mfg.h
  * @author  Realsil WLAN5 Team
  * @date    2021-01-27
  * @brief   This file is the header file for floader_nand_ftl_mfg.c
  ******************************************************************************
  * @attention
  *
  * This module is a confidential and proprietary property of RealTek and
  * possession or use of this module requires written permission of RealTek.
  *
  * Copyright(c) 2020, Realtek Semiconductor Corporation. All rights reserved.
  ******************************************************************************
  */

#ifndef _FLOADER_NAND_FTL_MFG_H
#define _FLOADER_NAND_FTL_MFG_H

/* Includes ------------------------------------------------------------------*/

#include "floader_nand_ftl.h"

/* Exported defines ----------------------------------------------------------*/

#define NAND_MFG_DOSILICON	0xE5U
#define NAND_MFG_GIGADEVICE	0xC8U
#define NAND_MFG_MACRONIX	0xC2U
#define NAND_MFG_MICRON		0x2CU
#define NAND_MFG_WINBOND	0xEFU

/* Exported types ------------------------------------------------------------*/

typedef struct {
	u8(* Init)(NAND_FTL_DeviceTypeDef *nand);
	u8(* SelectTarget)(NAND_FTL_DeviceTypeDef *nand, u8 target);
	u8(* GetEccStatus)(NAND_FTL_DeviceTypeDef *nand, u8 status);
	u8(* ReadParameterPage)(NAND_FTL_DeviceTypeDef *nand, u8 *data);
} NAND_FTL_MfgOpsTypeDef;

/* Exported variables --------------------------------------------------------*/

/* Exported functions --------------------------------------------------------*/

u8 NAND_FTL_MfgInit(NAND_FTL_DeviceTypeDef *nand, NAND_FTL_MfgOpsTypeDef *ops);

#endif // _FLOADER_NAND_FTL_MFG_H

