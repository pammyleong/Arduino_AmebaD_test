/**
  ******************************************************************************
  * @file    floader_flash_ftl.h
  * @author  Realsil WLAN5 Team
  * @date    2021-01-27
  * @brief   This file is the general definitions for Flash FTL
  ******************************************************************************
  * @attention
  *
  * This module is a confidential and proprietary property of RealTek and
  * possession or use of this module requires written permission of RealTek.
  *
  * Copyright(c) 2020, Realtek Semiconductor Corporation. All rights reserved.
  ******************************************************************************
  */

#ifndef _FLOADER_FLASH_FTL_H
#define _FLOADER_FLASH_FTL_H

/* Includes ------------------------------------------------------------------*/

#include "basic_types.h"
#include "ameba_soc.h"
#ifdef CONFIG_AMEBAD2
#include "usbd_errno.h"
#endif
/* Exported defines ----------------------------------------------------------*/

/* Exported macros -----------------------------------------------------------*/

#define FTL_MEMSET	_memset
#define FTL_MEMCPY	_memcpy

/* Exported types ------------------------------------------------------------*/

typedef struct {
	/* For both NOR and NAND */
	u8  MID;
	u8  DID;
	u8  ExtDID;

	/* For NAND only */
	u8	MFG[12];			/* Manufacture, ONFI parameter page 32-43 */
	u8	Model[20];			/* Device model, ONFI parameter page 44-63 */
	u32 PageSize;			/* Bytes per page, ONFI parameter page 80-83 */
	u16 OobSize;			/* OOB bytes per page, ONFI parameter page 84-85 */
	u32 PagesPerBlock;		/* Pages per erase block, ONFI parameter page 92-95 */
	u32 BlocksPerLun;		/* Blocks per logical unit, ONFI parameter page 96-99 */
	u8  LunsPerTarget;		/* Logical units per target, ONFI parameter page 100 */
	u16 MaxBadBlocksPerLun;	/* Max bad blocks per logical unit, ONFI parameter page 103-104 */
	u8  ReqHostEccLevel;	/* Required host ECC bits, ONFI parameter page 112 */

	u8  Targets;			/* Targets/dies */
	u32 Capacity;			/* Capacity */

	u8	Reserved[6];		/* Padding to 64 bytes */
} _PACKED_ Flash_InfoTypeDef;

/* Exported variables --------------------------------------------------------*/

/* Exported functions --------------------------------------------------------*/

#endif // _FLOADER_FLASH_FTL_H

