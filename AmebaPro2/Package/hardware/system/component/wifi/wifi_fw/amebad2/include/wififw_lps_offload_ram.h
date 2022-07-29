#ifndef _WIFIFW_LPS_OFFLOAD_RAM_H_
#define _WIFIFW_LPS_OFFLOAD_RAM_H_

/*--------------------Define --------------------------------------------*/
#define CmdFileType_Delay	0
#define CmdFileType_RealOnOff	1
#define LPSOfld_KeepCurrentVal	(0)
#define LPSOfld_WaitFCSToms	(5)
#define LPSOfld_HIOEOnClrIntCmdNum	(2) //unit 8 bytes
#define LPSOfld_BCNTO	(8000)//us
#define LPSOfld_TSFT_DIFF_THRES	(200)//us
#define KeyCAMHIOEEntrySize (16)
#define LPSOfld_ChkHWHIOEIdle()	((ReadMACRegDWord(REG_HW_IOE_CR_CHN_ON) & BIT_HIOE_ACTIVE_CHN_ON) | (ReadMACRegDWord(REG_HW_IOE_CR_CHN_OFF) & BIT_HIOE_ACTIVE_CHN_OFF))

/*------------------------------Function declaration--------------------------*/
extern void LPSOfld_HIOECmdFileToTXFF_8730A(u32 *HIOECmdFileTab, HIOECmdFileRSVal *HIOECmdFileRsValTab, u32 TXFF_Offset);
extern void LPSOfld_HIOECmdFileInit_8730A(void);
extern void LPSOfld_HIOECmdFilePGRSInit_8730A(void);
extern void LPSOfld_ByPassLsysWakeInt_8730A(BOOLEAN ByPassLsysWakeEn, BOOLEAN HWCtrlTRXOnOff);
extern void LPSOfld_SwtHIOECmdFile_8730A(BOOLEAN OnHIOECmdFileType, BOOLEAN OffHIOECmdFileType);
extern void LPSOfld_IMRSetting_8730A(BOOLEAN HWCtrlTRXOnOff);
extern void LPSOfld_SetBcnErlyandTimeout_8730A(u8 bcnearlyitvl, u32 bcntimeout);
extern void LPSOfld_FuncInit_8730A(void);
extern void LPSOfld_RPWMExitPG_8730A(void);
extern void LPSOfld_Reload_PHYREG_8730A(void);
extern void LPSOfld_HWCtrlTRXOnOff_8730A(BOOLEAN HWCtrlTRXOnOff);

#endif
