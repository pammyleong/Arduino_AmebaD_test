/*
 *  Routines to access hardware
 *
 *  Copyright (c) 2013 Realtek Semiconductor Corp.
 *
 *  This module is a confidential and proprietary property of RealTek and
 *  possession or use of this module requires written permission of RealTek.
 */

#ifndef _RTL8195A_DAC_TEST_H_
#define _RTL8195A_DAC_TEST_H_

#include "osdep_api.h"

//#define DAC_VERI_DATA_LEN_ARRAY         16384
#define DAC_VERI_DATA_LEN               16384
#define DAC_VERI_DATA_LEN_FIX           (DAC_VERI_DATA_LEN/4)

#define DAC_VERI_DATA_BLK_NUM   4

#define DAC_VERI_DATA_DMA_BLK_SIZE  (DAC_VERI_DATA_LEN/(DAC_VERI_DATA_BLK_NUM*2))


#define DAC_VERI_GDMA_LLP_NUM_BASE      4
#define DAC_VERI_GDMA_LLP_NUM_TOTAL     8192

//From GDMA_LLP_BUF
typedef struct _DAC_GDMA_BLK_BUF_ {
    u32  LliTest[DAC_VERI_DATA_DMA_BLK_SIZE];
}DAC_GDMA_BLK_BUF, *P_DAC_GDMA_BLK_BUF;


typedef enum _DAC_VERI_PROC_CMD_ {
        DAC_TEST_INIT       = 0,
        DAC_TEST_SWCH       = 1,
        DAC_TEST_DEINIT     = 2,
}DAC_VERI_PROC_CMD, *PDAC_VERI_PROC_CMD;

typedef enum _DAC_VERI_ITEM_ {
        DAC_TEST_S_NINT     = 1,     //single rw without DMA without INT
        DAC_TEST_S_RINT     = 2,     //single rw without DMA with INT
        DAC_TEST_D_INT      = 3,     //single rw without DMA with INT
        DAC_TEST_DTR_INT    = 4,     //single rw using DMA with INT
#if TASK_SCHEDULER_DISABLED
        DAC_TEST_S_GCINT    = 7
#else
        DAC_TEST_S_GCINT    = 7,
        DAC_TEST_N_DEINT    = 10
#endif
}DAC_VERI_ITEM, *PDAC_VERI_ITEM;


typedef struct _DAC_VERI_PARA_ {
        u32         VeriProcCmd;
        u32         VeriItem;
        u32         VeriLoop;
        u32         VeriDacIdx;
        void        *VeriDatSrc;        
#if !TASK_SCHEDULER_DISABLED
        _Sema       VeriSema;
#else
        u32         VeriSema;
#endif  
#ifdef PLATFORM_FREERTOS
        xTaskHandle DACTask;
#else
        u32         DACTask;
#endif
        u8          SpdMod;
#if !TASK_SCHEDULER_DISABLED        
        u8          VeriStop;
        u8          Revd;
#else
        u16          Revd;
#endif
}DAC_VERI_PARA,*PDAC_VERI_PARA;

//======================================================
// Function Prototypes
VOID DACTestSinWave(VOID    *DACVeriHnd, VOID    *DACVeriPara);

#endif
