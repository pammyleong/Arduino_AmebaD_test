/*
 *  Routines to access hardware
 *
 *  Copyright (c) 2020 Realtek Semiconductor Corp.
 *
 *  This module is a confidential and proprietary property of RealTek and
 *  possession or use of this module requires written permission of RealTek.
 */

#include "ameba_soc.h"

typedef struct {
	void *TxData;
	u32 TxLength;
	u32 Index;
	u32 Result;
} LEDC_OBJ, *PLEDC_OBJ;

#define LEDC_CLOCK_NS		25

#define LEDC_RESET_TIME_MIN_NS 20
#define LEDC_RESET_TIME_MAX_NS 327680 //20ns*2^14

#define LEDC_T1H_MIN_NS 0
#define LEDC_T1H_MAX_NS 5100

#define LEDC_T1L_MIN_NS 0
#define LEDC_T1L_MAX_NS 5100

#define LEDC_T0H_MIN_NS 0
#define LEDC_T0H_MAX_NS 5100

#define LEDC_T0L_MIN_NS 0
#define LEDC_T0L_MAX_NS 5100

#define LEDC_WAIT_TIME0_MIN_NS 20
#define LEDC_WAIT_TIME0_MAX_NS 10240

#define LEDC_WAIT_TIME1_MIN_NS 20
#define LEDC_WAIT_TIME1_MAX_NS 42949672960

#define LEDC_WAIT_DATA_TIME_MIN_NS 20
#define LEDC_WAIT_DATA_TIME_MAX_NS_IC 655360

#define LEDC_TEST_LED_COUNT 8

#define RESULT_COMPLETE	1
#define RESULT_ERR	2
