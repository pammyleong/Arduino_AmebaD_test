#ifndef __RTL8721D_UTIL_H__
#define __RTL8721D_UTIL_H__

/*--------------------Define --------------------------------------------*/

/*--------------------Define Enum---------------------------------------*/

/*--------------------Define MACRO--------------------------------------*/

//3 General Purpose Timer (Offset: 0x0150 - 0x016Fh)
#define MODE_TIMER                  1
#define MODE_COUNTER                0

#define TC_ENABLE                   BIT0
#define TC_TIMER_MODE               BIT1

#define WAIT_BBRW_STABLE_BREAK_CNT      (5000)
#define WAIT_BBRW_STABLE_CNT            (100)
#define WAIT_BBRW_STABLE_ONCE_TIME      (20)

/*--------------------Define Struct---------------------------------------*/

/*--------------------Export global variable-------------------------------*/

/*--------------------Function declaration---------------------------------*/

#ifndef __ASSEMBLY__

extern u8
PollingReg_8721D_ROM(
	u16 RegOffset,
	u8 PollingBit,
	u8 PollingResult,
	u16 PollingLimit,
	u16 *PollingCount
);

extern void
InitGTimer32us_8721D_ROM(
	IN  u16     timer_addr,
	IN  u8      _mode,
	IN  u8      Unit2s,
	IN  u8      Unit8ms,
	IN  u8      Unit32us
);  //mode=0: counter, 1: timer

extern void
InitGTimer1ms_8721D_ROM(
	IN  u16     timer_addr,
	IN  u8      _mode,
	IN  u8      Unit65s,
	IN  u8      Unit256ms,
	IN  u8      Unit1ms
);  //mode=0: counter, 1: timer

extern BOOLEAN
CheckBBRWIsStable_8721D_ROM(
	void
);

extern u32
PHY_QueryBBReg_8721D_ROM(
	IN  u16         RegAddr
)   ;   //access delay 20us

extern void
PHY_SetBBReg_8721D_ROM(
	IN  u16         RegAddr,
	IN  u32         Data
)   ;    //access delay 20us

extern void
ReadSECCAM_8721D_ROM(
	u16 Addr,
	u8 *Data
);

extern void
WriteSECCAM_8721D_ROM(
	u16 Addr,
	u8 *Data
);

extern void
ReadBACAM_8721D_ROM(
	u8 Addr,
	u8 *Data
);

extern void
WriteBACAM_8721D_ROM(
	u8 Addr,
	u8 *Data
);

extern void
ReadMBIDCAM_8721D_ROM(
	u8 Addr,
	u8 *Data
);

extern void
WriteMBIDCAM_8721D_ROM(
	u8 Addr,
	u8 *Data
);

#endif  //#ifndef __ASSEMBLY__

#endif  //__RTL8721D_UTIL_H__

