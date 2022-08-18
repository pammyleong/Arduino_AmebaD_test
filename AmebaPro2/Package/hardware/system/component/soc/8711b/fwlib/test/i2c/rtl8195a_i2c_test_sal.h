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

#define I2C_VERI_DATA_LEN_SAL       1024
#define I2C_VERI_DMA_LEN_SAL       256

#define I2C_VERI_RXBUF_LEN_SAL      32
#define I2C_VERI_TXBUF_LEN_SAL      32

#define I2C_VERI_PANT_CNT_SAL       6

#define I2C_VERI_ACK_ADDR_SAL       0x68
#define I2C_VERI_ACK_ADDR1_SAL       0x46

#define I2C_VERI_USER_REG_ADDR_SAL  0x75
//#define ONEMST_MULTISLV_TEST
//#define ONESLV_MULTIMST_TEST
//#define Open_Schmitt
#define I2C_OPEN_OSC8M



typedef enum _I2C_VERI_PROC_CMD_SAL_ {
        I2C_TEST_ITEMS_SAL       = 0,
	 I2C_TEST_ALL_SAL       = 1,
}I2C_VERI_PROC_CMD_SAL, *PI2C_VERI_PROC_CMD_SAL;


typedef enum _I2C_VERI_ITEM_SAL_ {
		I2C_TEST_M2S_POLL     = 1,
		I2C_TEST_M2S_INT     = 2,
		I2C_TEST_M2S_DMA      = 3,
		I2C_TEST_S2M_INT     = 4,
		I2C_TEST_S_GCINT_SAL    = 5,
		I2C_TEST_S2M_DMA    = 6,
		I2C_TEST_M_NULLDATA  = 7,
		I2C_TEST_RESTART = 8,
		I2C_TEST_ADDR_MATCH_WAKEUP  = 9,
		I2C_TEST_TO_STM32  = 10,
		I2C_TEST_MultiMrtInit = 11,
        I2C_TEST_ALL_CASE = 20
}I2C_VERI_ITEM_SAL, *PI2C_VERI_ITEM_SAL;


typedef struct _I2C_VERI_PARA_SAL_ {
        u32         VeriItem;
        u32         VeriLoop;
        u32         VeriMaster;
        u32         VeriSlave;
		u32         VeriDMA;  
        u8        *VeriPattern;
        void        *VeriDatSrc;
        void        *VeriDatDes;
        void        *VeriDatCmdSrcMtr;
        void        *VeriDatCmdSrcSlv;
        u8          SpdMod;
        u8          AddrMod;
}I2C_VERI_PARA_SAL,*PI2C_VERI_PARA_SAL;

#endif
