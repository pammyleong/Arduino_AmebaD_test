#ifndef __WIFIFW_INIT_H__
#define __WIFIFW_INIT_H__
/*--------------------------Define -------------------------------------------*/
/* General Purpose Timer (Offset: 0x0150 - 0x016Fh) */
#define MODE_TIMER					1
#define MODE_COUNTER				0

#define TC_ENABLE						BIT0
#define TC_TIMER_MODE				BIT1
#define TC_INT_ENABLE				BIT2
/*------------------------------Function declaration--------------------------*/
extern void InitFuncPtrTable_8730A_ROM(void);
extern void InitGTimer32us_8730A_ROM(u16 timer_addr, u8 _mode, u8 Unit2s, u8 Unit8ms, u8 Unit32us);
extern void InitGTimer1ms_8730A_ROM(u16 timer_addr, u8 _mode, u8 Unit65s, u8 Unit256ms, u8 Unit1ms);

#endif /* __WIFIFW_INIT_H__ */
