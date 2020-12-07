/*
 *  Routines to access hardware
 *
 *  Copyright (c) 2013 Realtek Semiconductor Corp.
 *
 *  This module is a confidential and proprietary property of RealTek and
 *  possession or use of this module requires written permission of RealTek.
 */

#ifndef _RTL8195A_ADC_TEST_H_
#define _RTL8195A_ADC_TEST_H_

#include "osdep_api.h"

#define ADC_VERI_DATA_LEN       2048
#define ADC_VERI_ENDLESS        0

typedef enum _ADC_VERI_PROC_CMD_ {
        ADC_TEST_INIT       = 0,
        ADC_TEST_SWCH       = 1,
        ADC_TEST_DEINIT     = 2,
        ADC_TEST_PAUSE      = 3,
        ADC_TEST_RESUME     = 4,
        ADC_TEST_DUMP       = 5,
}ADC_VERI_PROC_CMD, *PADC_VERI_PROC_CMD;

typedef enum _ADC_VERI_ITEM_ {
        ADC_TEST_S_NINT     = 1,     //single rw without DMA without INT
        ADC_TEST_S_RINT     = 2,     //single rw without DMA with INT
        ADC_TEST_D_INT      = 3,     //single rw without DMA with INT
        ADC_TEST_DTR_INT    = 4,     //single rw using DMA with INT
#if TASK_SCHEDULER_DISABLED
        ADC_TEST_S_GCINT    = 7
#else
        ADC_TEST_S_GCINT    = 7,
        ADC_TEST_N_DEINT    = 10
#endif
}ADC_VERI_ITEM, *PADC_VERI_ITEM;


typedef struct _ADC_VERI_PARA_ {
        u32         VeriProcCmd;
        u32         VeriItem;
        u32         VeriLoop;
        u32         VeriAdcIdx;
        void        *VeriDatDst;        
#if !TASK_SCHEDULER_DISABLED
        _Sema       VeriSema;
#else
        u32         VeriSema;
#endif  
#ifdef PLATFORM_FREERTOS
        xTaskHandle ADCTask;
#else
        u32         ADCTask;
#endif
        u8          SpdMod;
#if !TASK_SCHEDULER_DISABLED        
        u8          VeriStop;
        u8          Revd;
#else
        u16          Revd;
#endif
}ADC_VERI_PARA,*PADC_VERI_PARA;

#endif
