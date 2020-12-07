/*
 *  Routines to access hardware
 *
 *  Copyright (c) 2013 Realtek Semiconductor Corp.
 *
 *  This module is a confidential and proprietary property of RealTek and
 *  possession or use of this module requires written permission of RealTek.
 */

#ifndef __HAL_BTBX_TEST_H__
#define __HAL_BTBX_TEST_H__

#if CONFIG_BTBX_TEST
#define SETDATA BIT2
#define SETACK  BIT1
#define GETDATA BIT0

typedef struct _BTBX_ADAPTER_ {
    u8          Function;
    u8          TxdataFlag;
    //u8          RxdataFlag;
}BTBX_ADAPTER, *PBTBX_ADAPTER;
#endif
#endif
