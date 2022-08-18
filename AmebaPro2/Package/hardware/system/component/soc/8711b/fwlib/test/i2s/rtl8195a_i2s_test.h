/*
 *  Routines to access hardware
 *
 *  Copyright (c) 2013 Realtek Semiconductor Corp.
 *
 *  This module is a confidential and proprietary property of RealTek and
 *  possession or use of this module requires written permission of RealTek.
 */
#ifndef _RTL8195A_I2S_TEST_H_
#define _RTL8195A_I2S_TEST_H_

struct i2s_test {		
	u32 tx_isr_cnt;	//current tx isr count
	u32 rx_isr_cnt;	//current rx isr count

	u32 mono_val;	//when i2s playtone, set mono initial value
	u32 stereo_left_val;	//when i2s playtone, set stereo left channel init value
	u32 stereo_right_val;	//when i2s playtone, set stereo right channel init value
};

#endif
