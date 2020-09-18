#ifndef _RTL8195A_SSI_TEST_H_
#define _RTL8195A_SSI_TEST_H_


/* Function Prototype */

VOID SsiAIrqHandle(VOID *Data);
VOID SsiBIrqHandle(VOID *Data);
VOID DisableEEPROMPinmux(VOID);
VOID GdmaIpEnable(VOID);
u8   GetGdmaChannelIrq(u8 GdmaIndex, u8 GdmaChannel);
u16  GetGdmaChannelEnableValue(u8 GdmaChannel);
u32  GetSsiIrqNumber(u8 SsiIndex);
VOID DumpSsiRegInfo(u8 SsiIndex);
BOOL SsiDataCompare(u8 *pSrc, u8 *pDst, u32 Length);
VOID SsiGenerateRandomTxData(u8 *pTxArray, u32 Length, u32 Mode, BOOL MICROWIRE);

#endif
