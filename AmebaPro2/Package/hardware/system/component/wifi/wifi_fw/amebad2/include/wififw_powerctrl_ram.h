#ifndef __WIFIFW_POWERCTRL_RAM_H__
#define __WIFIFW_POWERCTRL_RAM_H__

/*--------------------Function declaration---------------------------------*/
extern u8 GetRPWMValue_8730A(void);
extern void WaitHWStateReady_8730A(void);
extern void PsOpenRF_8730A(void);
extern void PsCloseRF_8730A(void);
extern void PsOpenRFHIOE_8730A(void);
extern void PsCloseRFHIOE_8730A(void);
extern void SysClkDown_8730A(void);
extern void SysClkUp_8730A(void);
extern void LowLPSOff_8730A(u8 LowLPSEnable);
extern BOOLEAN WaitTxStateMachineOk_8730A(void);
extern void WriteTxPause_8730A(u8 value, u8 rcode);
extern void SetTxPauseFWInfo_8730A(u8 BitMask, u8 UserValue);
extern void WriteTxPauseWithMask_8730A(u8 mask, u8 value, u8 rcode);

#endif  /* __WIFIFW_POWERCTRL_RAM_H__ */
