#ifndef __WIFIFW_UTIL_TEST_H__
#define __WIFIFW_UTIL_TEST_H__

/*--------------------Define --------------------------------------------*/

/*--------------------Define Enum---------------------------------------*/

/*--------------------Define MACRO--------------------------------------*/

//3 General Purpose Timer (Offset: 0x0150 - 0x016Fh)
#define MODE_TIMER                  1
#define MODE_COUNTER                0

#define TC_ENABLE                   BIT0
#define TC_TIMER_MODE               BIT1
#define TC_INT_ENABLE               BIT2

#define MBIDCAM_POLL                BIT7
#define MBIDCAM_WT_EN               BIT6

#define WAIT_BBRW_STABLE_BREAK_CNT      (5000)
#define WAIT_BBRW_STABLE_CNT            (100)
#define WAIT_BBRW_STABLE_ONCE_TIME      (20)

/*--------------------Define Struct---------------------------------------*/

/*--------------------Export global variable-------------------------------*/

/*--------------------Function declaration---------------------------------*/

#ifndef __ASSEMBLY__

extern BOOLEAN CheckBBRWIsStable(void);

extern u32 PHY_QueryBBReg(u16 RegAddr);   //access delay 20us

extern void PHY_SetBBReg(u16 RegAddr, u32 Data);    //access delay 20us

extern void ReadSECCAM(u16 Addr, u8 *Data);

extern void WriteSECCAM(u16 Addr, u8 *Data);

extern void ReadBACAM(u8 Addr, u8 *Data);

extern void WriteBACAM(u8 Addr, u8 *Data);

extern void ReadMBIDCAM(u8 Addr, u8 *Data);

extern void WriteMBIDCAM(u8 Addr, u8 *Data);

#endif  //#ifndef __ASSEMBLY__

#endif

