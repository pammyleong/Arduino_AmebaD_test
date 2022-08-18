/*
 *  Routines to access hardware
 *
 *  Copyright (c) 2013 Realtek Semiconductor Corp.
 *
 *  This module is a confidential and proprietary property of RealTek and
 *  possession or use of this module requires written permission of RealTek.
 */
#include "ameba_soc.h"

typedef struct {
	AUDIO_SPORT_TypeDef *SPORTx;
	AUDIO_SPORT_TypeDef *SPORTx_S;
	u32 SP_IRQ;
	u32 SP_IRQ_AP;
} SPORT_DevTable;

extern const SPORT_DevTable SPORT_DEV_TABLE[4];

