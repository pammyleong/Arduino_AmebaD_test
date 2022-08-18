/*
 *  Routines to access hardware
 *
 *  Copyright (c) 2013 Realtek Semiconductor Corp.
 *
 *  This module is a confidential and proprietary property of RealTek and
 *  possession or use of this module requires written permission of RealTek.
 */


#ifndef _RTL8721D_DDR_TEST_SAL_H_
#define _RTL8721D_DDR_TEST_SAL_H_

// DDR debug output
#define DDR_PREFIX      "RTL8195A[psram]: "
#define DDR_PREFIX_LVL  "    [DDR_DBG]: "
#define DDR_DEBUG_GPIO		_PA_15
#define DDR_SIZE_BYTE		(128*1024*1024) // for 1Gbit


typedef struct _SAL_DDR_MNGT_ADPT_ {
	PCTL_InitTypeDef       	PCTL_InitStruct;           //Pointer to PCTL initial data
} SAL_DDR_MNGT_ADPT, *PSAL_DDR_MNGT_ADPT;

typedef enum _DDR_VERI_ITEM_SAL_ {
	DDR_INIT_TEST = 1,
	DDR_MEMORY_RW = 2,
	DDR_DMA_RW = 3,
	DDR_DPIN_WR = 4,
	DDR_CACHE_ENABLE = 5,
	DDR_CACHE_DISABLE = 6,
	DDR_POWER_TEST = 7,
	DDR_REG_TEST = 8,
	DDR_DEBUG_PORT = 9,
} DDR_VERI_ITEM_SAL, *PDDR_VERI_ITEM_SAL;


typedef struct _DDR_VERI_PARA_SAL_ {
	u32	VeriItem;
	u32	VeriLoop;
	u32	Verimode1;
	u32	Verimode2;
	u32	Verimode3;
} DDR_VERI_PARA_SAL, *PDDR_VERI_PARA_SAL;

#endif
