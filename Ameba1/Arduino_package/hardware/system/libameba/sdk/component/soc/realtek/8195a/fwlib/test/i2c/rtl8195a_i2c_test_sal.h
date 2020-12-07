/*
 *  Routines to access hardware
 *
 *  Copyright (c) 2013 Realtek Semiconductor Corp.
 *
 *  This module is a confidential and proprietary property of RealTek and
 *  possession or use of this module requires written permission of RealTek.
 */


#ifndef _RTL8195A_I2C_TEST_SAL_H_
#define _RTL8195A_I2C_TEST_SAL_H_

#include "osdep_api.h"
#include "mbed_i2c_sample.h"

#define I2C_VERI_DATA_LEN_SAL       1024
#define I2C_VERI_RXBUF_LEN_SAL      16
#define I2C_VERI_TXBUF_LEN_SAL      24

#define I2C_VERI_PANT_CNT_SAL       6

#define I2C_VERI_ACK_ADDR_SAL       0x68
#define I2C_VERI_USER_REG_ADDR_SAL  0x75


typedef enum _I2C_VERI_PROC_CMD_SAL_ {
        I2C_TEST_INIT_SAL       = 0,
        I2C_TEST_SWCH_SAL       = 1,
        I2C_TEST_DEINIT_SAL     = 2,
        I2C_TEST_GETCNT_SAL     = 3
}I2C_VERI_PROC_CMD_SAL, *PI2C_VERI_PROC_CMD_SAL;


typedef enum _I2C_VERI_ITEM_SAL_ {
        I2C_TEST_S_NINT_SAL     = 1,     //single rw without DMA without INT
        I2C_TEST_S_WINT_SAL     = 2,     //single rw without DMA with INT
        I2C_TEST_S_RINT_SAL     = 3,     //single rw without DMA with INT
        I2C_TEST_D_INT_SAL      = 4,     //single rw without DMA with INT
        I2C_TEST_DTR_INT_SAL    = 5,     //single rw using DMA with INT
#if TASK_SCHEDULER_DISABLED
        I2C_TEST_S_GCINT_SAL    = 7
#else
        I2C_TEST_S_GCINT_SAL    = 7,
        I2C_TEST_N_DEINT_SAL    = 10
#endif
#ifdef  MBED_I2C_VERIFICATION
        ,
        I2C_TEST_MBED_MTR_RD    = 0x80
#endif
}I2C_VERI_ITEM_SAL, *PI2C_VERI_ITEM_SAL;


typedef struct _I2C_VERI_PARA_SAL_ {
        u32         VeriProcCmd;
        u32         VeriItem;
        u32         VeriLoop;
        u32         VeriMaster;
        u32         VeriSlave;
        u32         MtrRW;
#if !TASK_SCHEDULER_DISABLED
        _Sema       VeriSema;
#else
        u32         VeriSema;
#endif  
#ifdef PLATFORM_FREERTOS
        xTaskHandle I2CTask;
#else
        u32         I2CTask;
#endif
        u8        *VeriPattern;
        void        *VeriDatSrc;
        void        *VeriDatDes;
        void        *VeriDatCmdSrcMtr;
        void        *VeriDatCmdSrcSlv;
        u8          SpdMod;
        u8          AddrMod;
#if !TASK_SCHEDULER_DISABLED        
        u8          VeriStop;
        u8          Revd;
#else
        u16          Revd;
#endif
}I2C_VERI_PARA_SAL,*PI2C_VERI_PARA_SAL;

#endif
