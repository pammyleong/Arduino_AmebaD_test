/*
 *  Routines to access hardware
 *
 *  Copyright (c) 2013 Realtek Semiconductor Corp.
 *
 *  This module is a confidential and proprietary property of RealTek and
 *  possession or use of this module requires written permission of RealTek.
 */

#ifndef _MBED_I2C_SAMPLE_H_
#define _MBED_I2C_SAMPLE_H_

#define MBED_I2C_VERIFICATION   1

//iPod CP I2C related parameter
#define IPOD_CP_I2C_ADDR        0x22

//iPod CP Register definition
#define REG_IPOD_CP_DEV_VER     0x00
#define REG_IPOD_CP_FW_VER      0x01
#define REG_IPOD_CP_AP_VER0     0x02
#define REG_IPOD_CP_AP_VER1     0x03
#define REG_IPOD_CP_DEV_ID      0x04
#define REG_IPOD_CP_AU_STS      0x10



//Function prototype
VOID MbedI2CMtrRD(IN  VOID    *I2CMtr);


#endif
