#ifndef __CST328_H
#define __CST328_H

#include "sys.h"

#define RST_PIN             _PA_10
#define SCL_PIN             _PA_1
#define SDA_PIN             _PA_0
#define INT_PIN             _PA_11

#define CST_TP1_REG         0XD000
#define CST_TP2_REG         0XD007
#define CST_TP3_REG         0XD00C
#define CST_TP4_REG         0XD011
#define CST_TP5_REG         0XD017

#define CST_DEBUG_INFO_MODE     0xD101
#define CST_FW_INFO     0xD208
#define CST_DEVIDE_MODE     0xD109

typedef enum {
	TOUCH_PRESS = 1,
	TOUCH_RELEASE = 0,
} cst328_touch_state;

typedef struct cst328_touch_data {
	u8 state;
	u16 x;
	u16 y;
} cst328_touch_data_t;

void CST328_Init(void);
void CST328_Touch_Report(void);
void CST328_Get_TPosition(u16 *x, u16 *y, u8 *state);

#endif