#ifndef __WIFIFW_FUNCPTR_ROM_H__
#define __WIFIFW_FUNCPTR_ROM_H__

/*--------------------Define -------------------------------------------*/
/* 1 function pointer */
/* 2 OS */
typedef void (*_OSSendSignalCommon_8730A_PTR)(u32  event);
typedef void (*_SendSignalCommon_8730A_PTR)(u32  event);  //brian for function both called in isrhdl or not
typedef void (*_ISRSendSignalCommon_8730A_PTR)(u32  event);

/* 3 Basic ISR */
typedef void (*_UpdateISRSys_8730A_PTR)(void);
typedef void (*_UpdateISRWlan_8730A_PTR)(void);
typedef void (*_UpdateISRFT_8730A_PTR)(void);
typedef void (*_ClrAllFWUsedIMR_8730A_PTR)(void);
typedef void (*_ClrAllFWUsedISR_8730A_PTR)(void);
typedef void (*_setfwimr_8730A_PTR)(u32 index, u32 bitmask);
typedef void (*_clrfwimr_8730A_PTR)(u32 index, u32 bitmask);
typedef void (*_setwlanimr_8730A_PTR)(u32 index, u32 bitmask);
typedef void (*_clrwlanimr_8730A_PTR)(u32 index, u32 bitmask);
typedef void (*_setftimr_8730A_PTR)(u32 index, u32 bitmask);
typedef void (*_clrftimr_8730A_PTR)(u32 index, u32 bitmask);

/* 3 DDMA */
typedef BOOLEAN(*_InitDDMA_8730A_PTR)(u8  ch_num, u32 saddr, u32 daddr, u32 dma_size, BOOLEAN chksum_en);
typedef BOOLEAN(*_WaitDDMARDY_8730A_PTR)(u8 ch_num);
typedef BOOLEAN(*_ChkDDMAChksum_8730A_PTR)(u8 ch_num);
typedef BOOLEAN(*_CheckDDMADone_8730A_PTR)(u8 ch_num, u8 chk_chksum);

/* 3 Util func */
typedef  u8(*_PollingReg_8730A_PTR)(u16 RegOffset, u8 PollingBit, u8 PollingResult, u16 PollingLimit, u16 *PollingCount);
/* Gtimer */
typedef void (*_InitGTimer32us_8730A_PTR)(u16 timer_addr, u8  _mode, u8 Unit2s, u8 Unit8ms, u8 Unit32us);
typedef void (*_InitGTimer1ms_8730A_PTR)(u16 timer_addr, u8 _mode, u8 Unit65s, u8 Unit256ms, u8 Unit1ms);
typedef BOOLEAN(*_CheckBBRWIsStable_8730A_PTR)(void);
typedef u32(*_PHY_QueryBBReg_8730A_PTR)(u16         RegAddr);     //access delay 20us
typedef void (*_PHY_SetBBReg_8730A_PTR)(u16         RegAddr, u32         Data);   //access delay 20us
typedef void (*_ReadSECCAM_8730A_PTR)(u16 Addr, u8 *Data);
typedef void (*_WriteSECCAM_8730A_PTR)(u16 Addr, u8 *Data);
typedef void (*_ReadBACAM_8730A_PTR)(u8 Addr, u8 *Data);
typedef void (*_WriteBACAM_8730A_PTR)(u8 Addr, u8 *Data);
typedef void (*_ReadMBIDCAM_8730A_PTR)(u8 Addr, u8 *Data);
typedef void (*_WriteMBIDCAM_8730A_PTR)(u8 Addr, u8 *Data);

/* 3 CMD */
typedef void (*_H2CInQueue_8730A_PTR)(void);
typedef void (*_H2CDeQueue_8730A_PTR)(void);
typedef void (*_InitC2H_8730A_PTR)(void);
typedef BOOLEAN(*_WaitC2HOk_8730A_PTR)(u16 TriggerAddr);
typedef void (*_C2HPKTRxDESC_8730A_PTR)(u16 PktLength, u16  C2HDescOffset);
typedef void (*_FillC2HContant_8730A_PTR)(u16  C2HPKTOffset, PC2H_EVT_HDR pc2h_hdr);
typedef void (*_IssueC2HPKT_8730A_PTR)(PC2H_EVT_HDR pc2h_hdr);
typedef void (*_C2HDeQueue_8730A_PTR)(void);
typedef void (*_C2HInQueue_8730A_PTR)(PC2H_EVT_HDR pc2h_hdr);
typedef u8(*_CheckMaxMacidNum_8730A_PTR)(void);
typedef void (*_SetMediaStatus_8730A_PTR)(u8   macid, u8   status);
typedef BOOLEAN(*_GetMediaStatus_8730A_PTR)(u8   macid);
/* 3 JumpRam */
typedef void (*_H2CCmdFunc_8730A_PTR)(u8  CmdID, u8  *content);
typedef void (*_Media_Disconnection_8730A_PTR)(void);

/* 3 Packet */
typedef void (*_ChangeTransmiteRate_8730A_PTR)(u16 offset);
typedef void (*_PowerBitSetting_8730A_PTR)(u8 bPowerBit, u16 offset);
typedef void (*_IssuePSPoll_8730A_PTR)(void);
typedef void (*_ChkandChangePS_8730A_PTR)(u8 bPowerBit);
typedef void (*_IssueQNull_8730A_PTR)(u8  bPowerBit);
typedef void (*_CTS2SelfSetting_8730A_PTR)(u16 offset, u16 NAV);
typedef void (*_IssueCTS2Self_8730A_PTR)(IN  u8 location, u16 NAV);
typedef u16(*_IssueRsvdPagePacketSetting_8730A_PTR)(u8 PageNum, BOOLEAN bHwSEQEn, u8 RtyLmt, u8 TxInd);
typedef u8(*_ReadRxBuff_8730A_PTR)(u16 headaddr, u8  offset);
typedef BOOLEAN(*_WaitCPUMGQEmpty_8730A_PTR)(void);
typedef u8(*_PollingReg_8730A_PTR)(u16 RegOffset, u8 PollingBit, u8 PollingResult, u16 PollingLimit, u16 *PollingCount);

/* 3 Powersave */
typedef void (*_LPSOfld_HIOECmdFileToTXFF_8730A_PTR)(u32 *HIOECmdFileTab, HIOECmdFileRSVal *HIOECmdFileRsValTab, u32 TXFF_Offset);
typedef void (*_LPSOfld_HIOECmdFileInit_8730A_PTR)(void);
typedef void (*_LPSOfld_HIOECmdFilePGRSInit_8730A_PTR)(void);
typedef void (*_LPSOfld_ByPassLsysWakeInt_8730A_PTR)(BOOLEAN ByPassLsysWakeEn, BOOLEAN HWCtrlTRXOnOff);
typedef void (*_LPSOfld_SwtHIOECmdFile_8730A_PTR)(BOOLEAN OnHIOECmdFileType, BOOLEAN OffHIOECmdFileType);
typedef void (*_LPSOfld_IMRSetting_8730A_PTR)(BOOLEAN HWCtrlTRXOnOff);
typedef void (*_LPSOfld_SetBcnErlyandTimeout_8730A_PTR)(u8 bcnearlyitvl, u32 bcntimeout);
typedef void (*_LPSOfld_FuncInit_8730A_PTR)(void);
typedef void (*_LPSOfld_RPWMExitPG_8730A_PTR)(void);
typedef void (*_LPSOfld_HWCtrlTRXOnOff_8730A_PTR)(BOOLEAN HWCtrlTRXOnOff);
typedef void (*_LPSOfld_Reload_PHYREG_8730A_PTR)(void);
typedef void (*_SetSmartPSTimer_8730A_PTR)(void);
typedef void (*_SetPwrStateReg_8730A_PTR)(u8 PwrStateType, u8 value);
typedef void (*_ResetPSParm_8730A_PTR)(void);
typedef BOOLEAN(*_ChkTxQueueIsEmpty_8730A_PTR)(void);
typedef void (*_Legacy_PS_Setting_8730A_PTR)(void);
typedef void (*_PSModeSetting_8730A_PTR)(u8 on);
typedef void (*_ConfigListenBeaconPeriod_8730A_PTR)(u8  RLBM, u8  AwakeInterval);
typedef void (*_PSSetMode_8730A_PTR)(PLEGACY_PS_PARM pparm);
typedef void (*_PS_S2ToS3State_8730A_PTR)(u8  nulldata0Allow);
typedef void (*_PS_S2ToS0State_8730A_PTR)(void);
typedef void (*_PS_S3ToS2orS0State_8730A_PTR)(void);
typedef void (*_PS_S0ToS1State_8730A_PTR)(void);
typedef void (*_PS_S1ToS0orS2State_8730A_PTR)(void);
typedef void (*_PS_S2ToS4State_8730A_PTR)(void);
typedef void (*_PS_S2ToS5State_8730A_PTR)(void);
typedef void (*_PS_S5ToS2State_8730A_PTR)(void);
typedef void (*_PS_S4ToS2State_8730A_PTR)(u8  ReleaseTxPause);
typedef void (*_SmartPS2InitTimerAndToGetRxPkt_8730A_PTR)(void);
typedef void (*_SetBcnEarlyAndTimeout_8730A_PTR)(u8 BcnAheadShift, u8 BcnEarlyShift, u8 BcnTimeout, u8 ReasonCode);
typedef void (*_EnlargeBcnEarlyAndTimeout_8730A_PTR)(void);
typedef void (*_PS_S0ToS6State_8730A_PTR)(void);
typedef void (*_PS_S6ToS0State_8730A_PTR)(void);
/* 3 jumptoram */
typedef void (*_Change_PS_State_8730A_PTR)(u8  request_ps_state, u8  nulldata0Allow);
typedef BOOLEAN(*_PS_S2_Condition_Match_8730A_PTR)(void);
typedef u8(*_PS_S4_Condition_Match_8730A_PTR)(void);
typedef void (*_WriteTxPauseWithMask_8730A_PTR)(u8 mask, u8 value, u8 rcode);
typedef BOOLEAN(*_WaitTxStateMachineOk_8730A_PTR)(void);
typedef void (*_WriteTxPause_8730A_PTR)(u8 value, u8 rcode);
typedef void (*_PsOpenRF_8730A_PTR)(void);
typedef void (*_PsCloseRF_8730A_PTR)(void);
typedef BOOLEAN(*_IssueNullData_8730A_PTR)(u8 bPowerBit, u8 RtyLmt);

//3 Wowlan
typedef void (*_InitKeepAlive_8730A_PTR)(void) ;
typedef void(*_H2CHDL_KeepAlive_8730A_PTR)(u8 *pbuf) ;
typedef void(*_UpdateRxFFReadPtr_DropPkt_8730A_PTR)(u16 RPtr) ;
typedef BOOLEAN(*_WaitRXDMAIdle_8730A_PTR)(void) ;
typedef u16(*_PageOffsetAlignment_8730A_PTR)(IN u16 offset) ;
typedef u8(*_DropCHK_8730A_PTR)(void) ;
typedef void (*_EnableWoWLAN_8730A_PTR)(void) ;
typedef void (*_DisWoWLAN_8730A_PTR)(void) ;
typedef void(*_H2CHDL_WoWLAN_8730A_PTR)(u8 *pbuf) ;
typedef BOOLEAN(*_DropDecision_8730A_PTR)(void) ;
typedef void (*_FwDisConnectWakeUpHost_8730A_PTR)(IN u8 type) ;
typedef BOOLEAN(*_DestinationMatch_8730A_PTR)(u16 addrl_frame_ctrl) ;
typedef void(*_PassSecurityInfoToDriver_8730A_PTR)(u8 pagenum) ;
typedef void(*_GetRemoteControlInfo_8730A_PTR)(u8 pagenum) ;
typedef void (*_GetARPInfo_8730A_PTR)(u8 pagenum) ;
typedef BOOLEAN(*_OnARP_8730A_PTR)(u16 addrl_frame_ctrl, u8 MacHeaderLen) ;
typedef void(*_GetNDPInfo_8730A_PTR)(u8 pagenum) ;
typedef BOOLEAN(*_IsIPV6_8730A_PTR)(u16 addrl_frame_ctrl, u8 MacHeaderLen) ;
typedef BOOLEAN(*_OnNS_8730A_PTR)(u16 addrl_frame_ctrl, u8 MacHeaderLen) ;
typedef BOOLEAN(*_Ipv4Match_8730A_PTR)(u16 addrl_frame_ctrl, u8 MacHeaderLen) ;
typedef BOOLEAN(*_MatchUnicastFilter_8730A_PTR)(u16 addrl_frame_ctrl, u8 MacHeaderLen) ;
typedef BOOLEAN(*_WakeUpHostDecision_8730A_PTR)(u8 RxDescWakeReason, u8 CheckMode) ;
typedef u8(*_CheckIV_8730A_PTR)(u8 *IVToCheck, u8 raaddr, BOOLEAN unicast_check) ;
typedef void (*_H2CHDL_AOACGlobalInfo_8730A_PTR)(u8 *pbuf) ;
typedef void(*_H2CHDL_AOACRsvdpage1_8730A_PTR)(u8 *pbuf) ;
typedef void(*_H2CHDL_AOACRsvdpage2_8730A_PTR)(u8 *pbuf) ;
typedef void(*_H2CHDL_AOACRsvdpage3_8730A_PTR)(u8 *pbuf) ;
typedef void (*_GetAddr_8730A_PTR)(void) ;
typedef void(*_ARP_hdl_8730A_PTR)(u8 bFunEnable) ;
typedef void(*_NDP_hdl_8730A_PTR)(u8 bFunEnable) ;
typedef void (*_InitDisconnectDecision_8730A_PTR)(void) ;
typedef void(*_DisconnectChk_8730A_PTR)(void) ;
typedef void(*_DisconnectTxNullChk_8730A_PTR)(IN u8 pwr) ;
typedef void (*_H2CHDL_DisconnectDecision_8730A_PTR)(u8 *pbuf) ;

typedef void (*_GetIV_8730A_PTR)(u16 addrl_frame_ctrl, u8 MacHeaderLen, u8 IvLen, u8 *IV) ;
typedef u8(*_GetIVLenAndSecurityType_8730A_PTR)(IN u8 raaddr) ;
typedef u8(*_GetMACHeaderLen_8730A_PTR)(IN u8  macheader, IN u8  FrameCtrl, IN u8  raaddr) ;
typedef void (*_UpdateIV_8730A_PTR)(IN u8 *buf, IN u8 retry_bit) ;
//GTK
typedef void (*_AesTkipIvFun_8730A_PTR)(IN u8 *pattrib_iv, IN u8 RetryBit, IN u8 SecurityType) ;
typedef void (*_WepIvFun_8730A_PTR)(IN unsigned char *iv, IN unsigned char retry_bit) ;
typedef s8(*_RTmemcmpBackward_8730A_PTR)(IN const void *Dest, IN const void *Src, IN u8 count);
typedef void (*_AssignIvToKeyRsc_8730A_PTR)(IN u8 *pattrib_iv, IN u8 *KeyRsc, IN u8 *KeyID, IN u8 SecurityType);
typedef void (*_AssignKeyRscToIV_8730A_PTR)(IN u8 *pattrib_iv, IN u8 *KeyRsc, IN u8 SecurityType);
typedef u8(*_AesTkipIvCheck_8730A_PTR)(IN u8 *rx_iv_ori, IN u8 *rx_iv, IN u8 SecurityType);
typedef u8(*_WepIvCheck_8730A_PTR)(IN u8 *rx_iv_ori, IN u8 *rx_iv);
//Jumptoram
typedef void (*_WakeUpHost_8730A_PTR)(IN u8 source) ;
typedef void (*_issue_ARP_8730A_PTR)(u8 *TargetIP, u8 *TargetMAC, u8  retry_bit, u8  arpsel);
typedef void (*_IssueNA_8730A_PTR)(u8 *TargetIP, u8 *TargetMAC, u8 *OurIP, u8 *OurMAC, u8  retry_bit, u8  ndpsel);

/* 3 BT Coex */
typedef void (*_H2CHDL_BTInfo_8730A_PTR)(u8 *pbuf);
typedef void (*_H2CHDL_ForceBTTxpwr_8730A_PTR)(u8 *pbuf);
typedef void (*_H2CHDL_BTIgnoreWlanAct_8730A_PTR)(u8 *pbuf);
typedef void (*_H2CHDL_AntSelReverse_8730A_PTR)(u8 *pbuf);
typedef void (*_H2CHDL_WLOpmode_8730A_PTR)(u8 *pbuf);
typedef void (*_H2CHDL_BTMpH2C_8730A_PTR)(u8 *pbuf);
typedef void (*_H2CHDL_BTControl_8730A_PTR)(u8 *pbuf);
typedef void (*_H2CHDL_BT_Page_Scan_Interval_8730A_PTR)(u8 *pbuf);
typedef void (*_H2CHDL_GNT_BT_Ctrl_8730A_PTR)(u8 *pbuf);
typedef void (*_H2CHDL_BT_Only_Test_8730A_PTR)(u8 *pbuf);
typedef void (*_H2CHDL_WL_Port_ID_8730A_PTR)(u8 *pbuf);
typedef void (*_C2HBTLoopback_8730A_PTR)(u8 *pbuf);
typedef void (*_C2HBTMpRpt_8730A_PTR)(u8 idx, u8 status, u8 req_num);
typedef void (*_C2HBTMailBoxStatus_8730A_PTR)(u8 status);
typedef void (*_InitBTCoexTimer_8730A_PTR)(u8 duration);
typedef void (*_Write778_8730A_PTR)(u8 value);
typedef void (*_TdmaChangeCoexTable_8730A_PTR)(u8 slot);
typedef void (*_BTNullSetting_8730A_PTR)(u8 bPowerBit, u16 offset, u8 lsb, u8 msb);
//Jumptoram
typedef void (*_WL2BTMailboxSend_8730A_PTR)(u8 cmd, u8 length, u8 *pparm);

/*------------------------Export global variable------------------------------*/
#ifdef  __WIFIFW_INIT_C__
//Direct Mapping HW Register

//1 function pointer
//2 OS
FW_ROM_BSS_SECTION  _OSSendSignalCommon_8730A_PTR         OSSendSignalCommon_8730A_PTR;
FW_ROM_BSS_SECTION  _SendSignalCommon_8730A_PTR           SendSignalCommon_8730A_PTR;
FW_ROM_BSS_SECTION  _ISRSendSignalCommon_8730A_PTR		  ISRSendSignalCommon_8730A_PTR;

//2 Basic ISR
FW_ROM_BSS_SECTION  _UpdateISRSys_8730A_PTR               UpdateISRSys_8730A_PTR;
FW_ROM_BSS_SECTION  _UpdateISRWlan_8730A_PTR			  UpdateISRWlan_8730A_PTR;
FW_ROM_BSS_SECTION	_UpdateISRFT_8730A_PTR				  UpdateISRFT_8730A_PTR;
FW_ROM_BSS_SECTION 	_ClrAllFWUsedIMR_8730A_PTR	     	  ClrAllFWUsedIMR_8730A_PTR;
FW_ROM_BSS_SECTION 	_ClrAllFWUsedISR_8730A_PTR	          ClrAllFWUsedISR_8730A_PTR;
FW_ROM_BSS_SECTION 	_setfwimr_8730A_PTR         		  setfwimr_8730A_PTR;
FW_ROM_BSS_SECTION 	_clrfwimr_8730A_PTR				      clrfwimr_8730A_PTR;
FW_ROM_BSS_SECTION 	_setwlanimr_8730A_PTR         		  setwlanimr_8730A_PTR;
FW_ROM_BSS_SECTION 	_clrwlanimr_8730A_PTR				  clrwlanimr_8730A_PTR;
FW_ROM_BSS_SECTION 	_setftimr_8730A_PTR 			      setftimr_8730A_PTR;
FW_ROM_BSS_SECTION 	_clrftimr_8730A_PTR                   clrftimr_8730A_PTR;

//2 DDMA
FW_ROM_BSS_SECTION 	_InitDDMA_8730A_PTR					  InitDDMA_8730A_PTR;
FW_ROM_BSS_SECTION 	_WaitDDMARDY_8730A_PTR                WaitDDMARDY_8730A_PTR;
FW_ROM_BSS_SECTION 	_ChkDDMAChksum_8730A_PTR              ChkDDMAChksum_8730A_PTR;
FW_ROM_BSS_SECTION 	_CheckDDMADone_8730A_PTR              CheckDDMADone_8730A_PTR;

//2 Util Func
//Gtimer
FW_ROM_BSS_SECTION  _InitGTimer32us_8730A_PTR             InitGTimer32us_8730A_PTR;
FW_ROM_BSS_SECTION  _InitGTimer1ms_8730A_PTR              InitGTimer1ms_8730A_PTR;

//2 CMD
FW_ROM_BSS_SECTION  _H2CInQueue_8730A_PTR                 H2CInQueue_8730A_PTR;
FW_ROM_BSS_SECTION  _H2CDeQueue_8730A_PTR                 H2CDeQueue_8730A_PTR;
FW_ROM_BSS_SECTION  _InitC2H_8730A_PTR					  InitC2H_8730A_PTR;
FW_ROM_BSS_SECTION  _WaitC2HOk_8730A_PTR				  WaitC2HOk_8730A_PTR;
FW_ROM_BSS_SECTION  _C2HPKTRxDESC_8730A_PTR               C2HPKTRxDESC_8730A_PTR;
FW_ROM_BSS_SECTION  _FillC2HContant_8730A_PTR             FillC2HContant_8730A_PTR;
FW_ROM_BSS_SECTION  _IssueC2HPKT_8730A_PTR                IssueC2HPKT_8730A_PTR;
FW_ROM_BSS_SECTION  _C2HDeQueue_8730A_PTR                 C2HDeQueue_8730A_PTR;
FW_ROM_BSS_SECTION  _C2HInQueue_8730A_PTR                 C2HInQueue_8730A_PTR;
FW_ROM_BSS_SECTION  _CheckMaxMacidNum_8730A_PTR			  CheckMaxMacidNum_8730A_PTR;
FW_ROM_BSS_SECTION  _SetMediaStatus_8730A_PTR			  SetMediaStatus_8730A_PTR;
FW_ROM_BSS_SECTION  _GetMediaStatus_8730A_PTR		      GetMediaStatus_8730A_PTR;
//3 JumpRam
FW_ROM_BSS_SECTION  _H2CCmdFunc_8730A_PTR                 H2CCmdFunc_8730A_PTR;
FW_ROM_BSS_SECTION  _Media_Disconnection_8730A_PTR	Media_Disconnection_8730A_PTR;

//2 Packet
FW_ROM_BSS_SECTION  _ChangeTransmiteRate_8730A_PTR        ChangeTransmiteRate_8730A_PTR;
FW_ROM_BSS_SECTION  _PowerBitSetting_8730A_PTR            PowerBitSetting_8730A_PTR;
FW_ROM_BSS_SECTION  _IssuePSPoll_8730A_PTR                IssuePSPoll_8730A_PTR;
FW_ROM_BSS_SECTION  _ChkandChangePS_8730A_PTR             ChkandChangePS_8730A_PTR;
FW_ROM_BSS_SECTION  _IssueQNull_8730A_PTR                 IssueQNull_8730A_PTR;
FW_ROM_BSS_SECTION  _CTS2SelfSetting_8730A_PTR			  CTS2SelfSetting_8730A_PTR;
FW_ROM_BSS_SECTION  _IssueCTS2Self_8730A_PTR              IssueCTS2Self_8730A_PTR;
FW_ROM_BSS_SECTION  _IssueRsvdPagePacketSetting_8730A_PTR IssueRsvdPagePacketSetting_8730A_PTR;
FW_ROM_BSS_SECTION  _ReadRxBuff_8730A_PTR                 ReadRxBuff_8730A_PTR;
FW_ROM_BSS_SECTION  _WaitCPUMGQEmpty_8730A_PTR                 WaitCPUMGQEmpty_8730A_PTR;
FW_ROM_BSS_SECTION  _PollingReg_8730A_PTR						PollingReg_8730A_PTR;

//2 Powersave
FW_ROM_BSS_SECTION _LPSOfld_HIOECmdFileToTXFF_8730A_PTR LPSOfld_HIOECmdFileToTXFF_8730A_PTR;
FW_ROM_BSS_SECTION _LPSOfld_HIOECmdFileInit_8730A_PTR LPSOfld_HIOECmdFileInit_8730A_PTR;
FW_ROM_BSS_SECTION _LPSOfld_HIOECmdFilePGRSInit_8730A_PTR LPSOfld_HIOECmdFilePGRSInit_8730A_PTR;
FW_ROM_BSS_SECTION _LPSOfld_ByPassLsysWakeInt_8730A_PTR LPSOfld_ByPassLsysWakeInt_8730A_PTR;
FW_ROM_BSS_SECTION _LPSOfld_SwtHIOECmdFile_8730A_PTR LPSOfld_SwtHIOECmdFile_8730A_PTR;
FW_ROM_BSS_SECTION _LPSOfld_IMRSetting_8730A_PTR LPSOfld_IMRSetting_8730A_PTR;
FW_ROM_BSS_SECTION _LPSOfld_SetBcnErlyandTimeout_8730A_PTR LPSOfld_SetBcnErlyandTimeout_8730A_PTR;
FW_ROM_BSS_SECTION _LPSOfld_FuncInit_8730A_PTR LPSOfld_FuncInit_8730A_PTR;
FW_ROM_BSS_SECTION _LPSOfld_RPWMExitPG_8730A_PTR LPSOfld_RPWMExitPG_8730A_PTR;
FW_ROM_BSS_SECTION _LPSOfld_HWCtrlTRXOnOff_8730A_PTR LPSOfld_HWCtrlTRXOnOff_8730A_PTR;
FW_ROM_BSS_SECTION  _LPSOfld_Reload_PHYREG_8730A_PTR	LPSOfld_Reload_PHYREG_8730A_PTR;
FW_ROM_BSS_SECTION  _SetSmartPSTimer_8730A_PTR            SetSmartPSTimer_8730A_PTR;
FW_ROM_BSS_SECTION  _SetPwrStateReg_8730A_PTR             SetPwrStateReg_8730A_PTR;
FW_ROM_BSS_SECTION  _ResetPSParm_8730A_PTR                ResetPSParm_8730A_PTR;
FW_ROM_BSS_SECTION  _ChkTxQueueIsEmpty_8730A_PTR		  ChkTxQueueIsEmpty_8730A_PTR;
FW_ROM_BSS_SECTION  _Legacy_PS_Setting_8730A_PTR          Legacy_PS_Setting_8730A_PTR;
FW_ROM_BSS_SECTION  _PSModeSetting_8730A_PTR              PSModeSetting_8730A_PTR;
FW_ROM_BSS_SECTION  _ConfigListenBeaconPeriod_8730A_PTR   ConfigListenBeaconPeriod_8730A_PTR;
FW_ROM_BSS_SECTION  _PSSetMode_8730A_PTR				  PSSetMode_8730A_PTR;
FW_ROM_BSS_SECTION  _PS_S2ToS3State_8730A_PTR			  PS_S2ToS3State_8730A_PTR;
FW_ROM_BSS_SECTION  _PS_S2ToS0State_8730A_PTR             PS_S2ToS0State_8730A_PTR;
FW_ROM_BSS_SECTION  _PS_S3ToS2orS0State_8730A_PTR   	  PS_S3ToS2orS0State_8730A_PTR;
FW_ROM_BSS_SECTION  _PS_S0ToS1State_8730A_PTR			  PS_S0ToS1State_8730A_PTR;
FW_ROM_BSS_SECTION  _PS_S1ToS0orS2State_8730A_PTR		  PS_S1ToS0orS2State_8730A_PTR;
FW_ROM_BSS_SECTION  _PS_S2ToS4State_8730A_PTR			  PS_S2ToS4State_8730A_PTR;
FW_ROM_BSS_SECTION  _PS_S2ToS5State_8730A_PTR			  PS_S2ToS5State_8730A_PTR;
FW_ROM_BSS_SECTION  _PS_S5ToS2State_8730A_PTR			  PS_S5ToS2State_8730A_PTR;
FW_ROM_BSS_SECTION  _PS_S4ToS2State_8730A_PTR			  PS_S4ToS2State_8730A_PTR;
FW_ROM_BSS_SECTION  _SmartPS2InitTimerAndToGetRxPkt_8730A_PTR	 SmartPS2InitTimerAndToGetRxPkt_8730A_PTR;
FW_ROM_BSS_SECTION  _SetBcnEarlyAndTimeout_8730A_PTR      SetBcnEarlyAndTimeout_8730A_PTR;
FW_ROM_BSS_SECTION  _EnlargeBcnEarlyAndTimeout_8730A_PTR  EnlargeBcnEarlyAndTimeout_8730A_PTR;
FW_ROM_BSS_SECTION  _PS_S0ToS6State_8730A_PTR			  PS_S0ToS6State_8730A_PTR;
FW_ROM_BSS_SECTION  _PS_S6ToS0State_8730A_PTR			  PS_S6ToS0State_8730A_PTR;
//3 jump to ram
FW_ROM_BSS_SECTION  _Change_PS_State_8730A_PTR            Change_PS_State_8730A_PTR;
FW_ROM_BSS_SECTION  _PS_S2_Condition_Match_8730A_PTR      PS_S2_Condition_Match_8730A_PTR;
FW_ROM_BSS_SECTION  _PS_S4_Condition_Match_8730A_PTR      PS_S4_Condition_Match_8730A_PTR;
FW_ROM_BSS_SECTION  _WriteTxPauseWithMask_8730A_PTR       WriteTxPauseWithMask_8730A_PTR;
FW_ROM_BSS_SECTION  _WaitTxStateMachineOk_8730A_PTR       WaitTxStateMachineOk_8730A_PTR;
FW_ROM_BSS_SECTION  _WriteTxPause_8730A_PTR               WriteTxPause_8730A_PTR;
FW_ROM_BSS_SECTION  _PsOpenRF_8730A_PTR                   PsOpenRF_8730A_PTR;
FW_ROM_BSS_SECTION  _PsCloseRF_8730A_PTR                  PsCloseRF_8730A_PTR;
FW_ROM_BSS_SECTION  _IssueNullData_8730A_PTR              IssueNullData_8730A_PTR;

//2 Wowlan
FW_ROM_BSS_SECTION  _InitKeepAlive_8730A_PTR				InitKeepAlive_8730A_PTR ;
FW_ROM_BSS_SECTION  _H2CHDL_KeepAlive_8730A_PTR 			H2CHDL_KeepAlive_8730A_PTR ;
FW_ROM_BSS_SECTION  _UpdateRxFFReadPtr_DropPkt_8730A_PTR 	UpdateRxFFReadPtr_DropPkt_8730A_PTR ;
FW_ROM_BSS_SECTION  _WaitRXDMAIdle_8730A_PTR 				WaitRXDMAIdle_8730A_PTR ;
FW_ROM_BSS_SECTION  _PageOffsetAlignment_8730A_PTR 			PageOffsetAlignment_8730A_PTR ;
FW_ROM_BSS_SECTION  _DropCHK_8730A_PTR 						DropCHK_8730A_PTR ;
FW_ROM_BSS_SECTION  _EnableWoWLAN_8730A_PTR 				EnableWoWLAN_8730A_PTR ;
FW_ROM_BSS_SECTION  _DisWoWLAN_8730A_PTR 					DisWoWLAN_8730A_PTR ;
FW_ROM_BSS_SECTION  _H2CHDL_WoWLAN_8730A_PTR 				H2CHDL_WoWLAN_8730A_PTR ;
FW_ROM_BSS_SECTION  _DropDecision_8730A_PTR 				DropDecision_8730A_PTR ;
FW_ROM_BSS_SECTION  _FwDisConnectWakeUpHost_8730A_PTR 		FwDisConnectWakeUpHost_8730A_PTR ;
FW_ROM_BSS_SECTION  _DestinationMatch_8730A_PTR 			DestinationMatch_8730A_PTR ;
FW_ROM_BSS_SECTION  _PassSecurityInfoToDriver_8730A_PTR 		PassSecurityInfoToDriver_8730A_PTR ;
FW_ROM_BSS_SECTION  _GetRemoteControlInfo_8730A_PTR 		GetRemoteControlInfo_8730A_PTR ;
FW_ROM_BSS_SECTION  _GetARPInfo_8730A_PTR 					GetARPInfo_8730A_PTR ;
FW_ROM_BSS_SECTION  _OnARP_8730A_PTR 						OnARP_8730A_PTR ;
FW_ROM_BSS_SECTION  _GetNDPInfo_8730A_PTR 					GetNDPInfo_8730A_PTR ;
FW_ROM_BSS_SECTION  _IsIPV6_8730A_PTR 						IsIPV6_8730A_PTR ;
FW_ROM_BSS_SECTION  _OnNS_8730A_PTR 						OnNS_8730A_PTR ;
FW_ROM_BSS_SECTION  _Ipv4Match_8730A_PTR 					Ipv4Match_8730A_PTR ;
FW_ROM_BSS_SECTION  _MatchUnicastFilter_8730A_PTR 			MatchUnicastFilter_8730A_PTR ;
FW_ROM_BSS_SECTION  _WakeUpHostDecision_8730A_PTR 			WakeUpHostDecision_8730A_PTR ;
FW_ROM_BSS_SECTION  _CheckIV_8730A_PTR 						CheckIV_8730A_PTR ;
FW_ROM_BSS_SECTION  _H2CHDL_AOACGlobalInfo_8730A_PTR 		H2CHDL_AOACGlobalInfo_8730A_PTR ;
FW_ROM_BSS_SECTION  _H2CHDL_AOACRsvdpage1_8730A_PTR 		H2CHDL_AOACRsvdpage1_8730A_PTR ;
FW_ROM_BSS_SECTION  _H2CHDL_AOACRsvdpage2_8730A_PTR 		H2CHDL_AOACRsvdpage2_8730A_PTR ;
FW_ROM_BSS_SECTION  _H2CHDL_AOACRsvdpage3_8730A_PTR 		H2CHDL_AOACRsvdpage3_8730A_PTR ;
FW_ROM_BSS_SECTION  _GetAddr_8730A_PTR 						GetAddr_8730A_PTR ;
FW_ROM_BSS_SECTION  _ARP_hdl_8730A_PTR 						ARP_hdl_8730A_PTR ;
FW_ROM_BSS_SECTION  _NDP_hdl_8730A_PTR 						NDP_hdl_8730A_PTR ;
FW_ROM_BSS_SECTION  _InitDisconnectDecision_8730A_PTR 		InitDisconnectDecision_8730A_PTR ;
FW_ROM_BSS_SECTION  _DisconnectChk_8730A_PTR 				DisconnectChk_8730A_PTR ;
FW_ROM_BSS_SECTION  _DisconnectTxNullChk_8730A_PTR 			DisconnectTxNullChk_8730A_PTR ;
FW_ROM_BSS_SECTION  _H2CHDL_DisconnectDecision_8730A_PTR 	H2CHDL_DisconnectDecision_8730A_PTR ;

FW_ROM_BSS_SECTION  _GetIV_8730A_PTR					  	GetIV_8730A_PTR;
FW_ROM_BSS_SECTION  _GetIVLenAndSecurityType_8730A_PTR   	GetIVLenAndSecurityType_8730A_PTR;
FW_ROM_BSS_SECTION  _GetMACHeaderLen_8730A_PTR            	GetMACHeaderLen_8730A_PTR;
FW_ROM_BSS_SECTION  _UpdateIV_8730A_PTR                   	UpdateIV_8730A_PTR;
//GTK
FW_ROM_BSS_SECTION  _AesTkipIvFun_8730A_PTR           	  	AesTkipIvFun_8730A_PTR;
FW_ROM_BSS_SECTION  _WepIvFun_8730A_PTR                   	WepIvFun_8730A_PTR;
FW_ROM_BSS_SECTION  _RTmemcmpBackward_8730A_PTR           	RTmemcmpBackward_8730A_PTR;
FW_ROM_BSS_SECTION  _AssignIvToKeyRsc_8730A_PTR           	AssignIvToKeyRsc_8730A_PTR ;
FW_ROM_BSS_SECTION  _AssignKeyRscToIV_8730A_PTR           	AssignKeyRscToIV_8730A_PTR;
FW_ROM_BSS_SECTION  _AesTkipIvCheck_8730A_PTR             	AesTkipIvCheck_8730A_PTR;
FW_ROM_BSS_SECTION  _WepIvCheck_8730A_PTR                 	WepIvCheck_8730A_PTR;
//3 Jumptoram
FW_ROM_BSS_SECTION  _WakeUpHost_8730A_PTR					WakeUpHost_8730A_PTR;
FW_ROM_BSS_SECTION  _issue_ARP_8730A_PTR					issue_ARP_8730A_PTR;
FW_ROM_BSS_SECTION  _IssueNA_8730A_PTR						IssueNA_8730A_PTR;

//2 BT Coex
FW_ROM_BSS_SECTION  _H2CHDL_BTInfo_8730A_PTR		H2CHDL_BTInfo_8730A_PTR;
FW_ROM_BSS_SECTION  _H2CHDL_ForceBTTxpwr_8730A_PTR		H2CHDL_ForceBTTxpwr_8730A_PTR;
FW_ROM_BSS_SECTION  _H2CHDL_BTIgnoreWlanAct_8730A_PTR		H2CHDL_BTIgnoreWlanAct_8730A_PTR;
FW_ROM_BSS_SECTION  _H2CHDL_AntSelReverse_8730A_PTR		H2CHDL_AntSelReverse_8730A_PTR;
FW_ROM_BSS_SECTION  _H2CHDL_WLOpmode_8730A_PTR		H2CHDL_WLOpmode_8730A_PTR;
FW_ROM_BSS_SECTION  _H2CHDL_BTMpH2C_8730A_PTR		H2CHDL_BTMpH2C_8730A_PTR;
FW_ROM_BSS_SECTION  _H2CHDL_BTControl_8730A_PTR		H2CHDL_BTControl_8730A_PTR;
FW_ROM_BSS_SECTION  _H2CHDL_BT_Page_Scan_Interval_8730A_PTR		H2CHDL_BT_Page_Scan_Interval_8730A_PTR;
FW_ROM_BSS_SECTION  _H2CHDL_GNT_BT_Ctrl_8730A_PTR		H2CHDL_GNT_BT_Ctrl_8730A_PTR;
FW_ROM_BSS_SECTION  _H2CHDL_BT_Only_Test_8730A_PTR		H2CHDL_BT_Only_Test_8730A_PTR;
FW_ROM_BSS_SECTION  _H2CHDL_WL_Port_ID_8730A_PTR		H2CHDL_WL_Port_ID_8730A_PTR;
FW_ROM_BSS_SECTION  _C2HBTLoopback_8730A_PTR		C2HBTLoopback_8730A_PTR;
FW_ROM_BSS_SECTION  _C2HBTMpRpt_8730A_PTR		C2HBTMpRpt_8730A_PTR;
FW_ROM_BSS_SECTION  _C2HBTMailBoxStatus_8730A_PTR		C2HBTMailBoxStatus_8730A_PTR;
FW_ROM_BSS_SECTION  _InitBTCoexTimer_8730A_PTR		InitBTCoexTimer_8730A_PTR;
FW_ROM_BSS_SECTION  _Write778_8730A_PTR		Write778_8730A_PTR;
FW_ROM_BSS_SECTION  _TdmaChangeCoexTable_8730A_PTR		TdmaChangeCoexTable_8730A_PTR;
FW_ROM_BSS_SECTION  _BTNullSetting_8730A_PTR		BTNullSetting_8730A_PTR;
//3 Jumptoram
FW_ROM_BSS_SECTION  _WL2BTMailboxSend_8730A_PTR		WL2BTMailboxSend_8730A_PTR;

#else
/* 1 Function Pointer */
/* 2 OS */
extern  _OSSendSignalCommon_8730A_PTR          OSSendSignalCommon_8730A_PTR;
extern  _SendSignalCommon_8730A_PTR            SendSignalCommon_8730A_PTR;
extern  _ISRSendSignalCommon_8730A_PTR		   ISRSendSignalCommon_8730A_PTR;

/* 2 BasicISR */
extern  _UpdateISRSys_8730A_PTR                UpdateISRSys_8730A_PTR;
extern  _UpdateISRWlan_8730A_PTR			   UpdateISRWlan_8730A_PTR;
extern  _UpdateISRFT_8730A_PTR				   UpdateISRFT_8730A_PTR;
extern  _ClrAllFWUsedIMR_8730A_PTR	     	   ClrAllFWUsedIMR_8730A_PTR;
extern  _ClrAllFWUsedISR_8730A_PTR	           ClrAllFWUsedISR_8730A_PTR;
extern 	_setfwimr_8730A_PTR         		   setfwimr_8730A_PTR;
extern 	_clrfwimr_8730A_PTR				       clrfwimr_8730A_PTR;
extern  _setwlanimr_8730A_PTR                  setwlanimr_8730A_PTR;
extern  _clrwlanimr_8730A_PTR				   clrwlanimr_8730A_PTR;
extern  _setftimr_8730A_PTR 				   setftimr_8730A_PTR;
extern  _clrftimr_8730A_PTR                    clrftimr_8730A_PTR;

/* 2 DDMA */
extern  _InitDDMA_8730A_PTR					   InitDDMA_8730A_PTR;
extern  _WaitDDMARDY_8730A_PTR                 WaitDDMARDY_8730A_PTR;
extern  _ChkDDMAChksum_8730A_PTR               ChkDDMAChksum_8730A_PTR;
extern  _CheckDDMADone_8730A_PTR               CheckDDMADone_8730A_PTR;

/* 2 Util Func */
/* Gtimer */
extern  _InitGTimer32us_8730A_PTR              InitGTimer32us_8730A_PTR;
extern  _InitGTimer1ms_8730A_PTR               InitGTimer1ms_8730A_PTR;

/* 2 CMD */
extern  _H2CInQueue_8730A_PTR                  H2CInQueue_8730A_PTR;
extern  _H2CDeQueue_8730A_PTR                  H2CDeQueue_8730A_PTR;
extern  _InitC2H_8730A_PTR					   InitC2H_8730A_PTR;
extern  _WaitC2HOk_8730A_PTR				   WaitC2HOk_8730A_PTR;
extern  _C2HPKTRxDESC_8730A_PTR                C2HPKTRxDESC_8730A_PTR;
extern  _FillC2HContant_8730A_PTR              FillC2HContant_8730A_PTR;
extern  _IssueC2HPKT_8730A_PTR                 IssueC2HPKT_8730A_PTR;
extern  _C2HDeQueue_8730A_PTR                  C2HDeQueue_8730A_PTR;
extern  _C2HInQueue_8730A_PTR                  C2HInQueue_8730A_PTR;
extern  _CheckMaxMacidNum_8730A_PTR			   CheckMaxMacidNum_8730A_PTR;
extern  _SetMediaStatus_8730A_PTR			   SetMediaStatus_8730A_PTR;
extern  _GetMediaStatus_8730A_PTR		       GetMediaStatus_8730A_PTR;
/* 3 JumpRam */
extern  _H2CCmdFunc_8730A_PTR                  H2CCmdFunc_8730A_PTR;
extern  _Media_Disconnection_8730A_PTR	Media_Disconnection_8730A_PTR;

/* 2 Packet */
extern  _ChangeTransmiteRate_8730A_PTR         ChangeTransmiteRate_8730A_PTR;
extern  _PowerBitSetting_8730A_PTR             PowerBitSetting_8730A_PTR;
extern  _IssuePSPoll_8730A_PTR                 IssuePSPoll_8730A_PTR;
extern  _ChkandChangePS_8730A_PTR              ChkandChangePS_8730A_PTR;
extern  _IssueQNull_8730A_PTR                  IssueQNull_8730A_PTR;
extern  _CTS2SelfSetting_8730A_PTR			   CTS2SelfSetting_8730A_PTR;
extern  _IssueCTS2Self_8730A_PTR               IssueCTS2Self_8730A_PTR;
extern  _IssueRsvdPagePacketSetting_8730A_PTR  IssueRsvdPagePacketSetting_8730A_PTR;
extern  _ReadRxBuff_8730A_PTR                  ReadRxBuff_8730A_PTR;
extern  _WaitCPUMGQEmpty_8730A_PTR                 WaitCPUMGQEmpty_8730A_PTR;
extern  _PollingReg_8730A_PTR						PollingReg_8730A_PTR;

/* 2 Powersave */
extern _LPSOfld_HIOECmdFileToTXFF_8730A_PTR LPSOfld_HIOECmdFileToTXFF_8730A_PTR;
extern _LPSOfld_HIOECmdFileInit_8730A_PTR LPSOfld_HIOECmdFileInit_8730A_PTR;
extern _LPSOfld_HIOECmdFilePGRSInit_8730A_PTR LPSOfld_HIOECmdFilePGRSInit_8730A_PTR;
extern _LPSOfld_ByPassLsysWakeInt_8730A_PTR LPSOfld_ByPassLsysWakeInt_8730A_PTR;
extern _LPSOfld_SwtHIOECmdFile_8730A_PTR LPSOfld_SwtHIOECmdFile_8730A_PTR;
extern _LPSOfld_IMRSetting_8730A_PTR LPSOfld_IMRSetting_8730A_PTR;
extern _LPSOfld_SetBcnErlyandTimeout_8730A_PTR LPSOfld_SetBcnErlyandTimeout_8730A_PTR;
extern _LPSOfld_FuncInit_8730A_PTR LPSOfld_FuncInit_8730A_PTR;
extern _LPSOfld_RPWMExitPG_8730A_PTR LPSOfld_RPWMExitPG_8730A_PTR;
extern _LPSOfld_HWCtrlTRXOnOff_8730A_PTR LPSOfld_HWCtrlTRXOnOff_8730A_PTR;
extern  _LPSOfld_Reload_PHYREG_8730A_PTR	LPSOfld_Reload_PHYREG_8730A_PTR;
extern  _SetSmartPSTimer_8730A_PTR             SetSmartPSTimer_8730A_PTR;
extern  _SetPwrStateReg_8730A_PTR              SetPwrStateReg_8730A_PTR;
extern  _ResetPSParm_8730A_PTR                 ResetPSParm_8730A_PTR;
extern  _ChkTxQueueIsEmpty_8730A_PTR		   ChkTxQueueIsEmpty_8730A_PTR;
extern  _Legacy_PS_Setting_8730A_PTR           Legacy_PS_Setting_8730A_PTR;
extern  _PSModeSetting_8730A_PTR               PSModeSetting_8730A_PTR;
extern  _ConfigListenBeaconPeriod_8730A_PTR    ConfigListenBeaconPeriod_8730A_PTR;
extern  _PSSetMode_8730A_PTR				   PSSetMode_8730A_PTR;
extern  _PS_S2ToS3State_8730A_PTR			   PS_S2ToS3State_8730A_PTR;
extern  _PS_S2ToS0State_8730A_PTR              PS_S2ToS0State_8730A_PTR;
extern  _PS_S3ToS2orS0State_8730A_PTR   	   PS_S3ToS2orS0State_8730A_PTR;
extern  _PS_S0ToS1State_8730A_PTR			   PS_S0ToS1State_8730A_PTR;
extern  _PS_S1ToS0orS2State_8730A_PTR		   PS_S1ToS0orS2State_8730A_PTR;
extern  _PS_S2ToS4State_8730A_PTR			   PS_S2ToS4State_8730A_PTR;
extern  _PS_S2ToS5State_8730A_PTR			   PS_S2ToS5State_8730A_PTR;
extern  _PS_S5ToS2State_8730A_PTR			   PS_S5ToS2State_8730A_PTR;
extern  _PS_S4ToS2State_8730A_PTR			   PS_S4ToS2State_8730A_PTR;
extern  _SmartPS2InitTimerAndToGetRxPkt_8730A_PTR	 SmartPS2InitTimerAndToGetRxPkt_8730A_PTR;
extern  _SetBcnEarlyAndTimeout_8730A_PTR       SetBcnEarlyAndTimeout_8730A_PTR;
extern  _EnlargeBcnEarlyAndTimeout_8730A_PTR   EnlargeBcnEarlyAndTimeout_8730A_PTR;
extern  _PS_S0ToS6State_8730A_PTR			   PS_S0ToS6State_8730A_PTR;
extern  _PS_S6ToS0State_8730A_PTR			   PS_S6ToS0State_8730A_PTR;
/* 3 Jumptoram */
extern  _Change_PS_State_8730A_PTR             Change_PS_State_8730A_PTR;
extern  _PS_S2_Condition_Match_8730A_PTR       PS_S2_Condition_Match_8730A_PTR;
extern  _PS_S4_Condition_Match_8730A_PTR       PS_S4_Condition_Match_8730A_PTR;
extern  _WriteTxPauseWithMask_8730A_PTR        WriteTxPauseWithMask_8730A_PTR;
extern  _WaitTxStateMachineOk_8730A_PTR        WaitTxStateMachineOk_8730A_PTR;
extern  _WriteTxPause_8730A_PTR                WriteTxPause_8730A_PTR;
extern  _PsOpenRF_8730A_PTR                    PsOpenRF_8730A_PTR;
extern  _PsCloseRF_8730A_PTR                   PsCloseRF_8730A_PTR;
extern  _IssueNullData_8730A_PTR               IssueNullData_8730A_PTR;

/* 2 Wowlan */
extern  _InitKeepAlive_8730A_PTR 		InitKeepAlive_8730A_PTR ;
extern  _H2CHDL_KeepAlive_8730A_PTR 		H2CHDL_KeepAlive_8730A_PTR ;
extern  _UpdateRxFFReadPtr_DropPkt_8730A_PTR 		UpdateRxFFReadPtr_DropPkt_8730A_PTR ;
extern  _WaitRXDMAIdle_8730A_PTR 		WaitRXDMAIdle_8730A_PTR ;
extern  _PageOffsetAlignment_8730A_PTR 		PageOffsetAlignment_8730A_PTR ;
extern  _DropCHK_8730A_PTR 		DropCHK_8730A_PTR ;
extern  _EnableWoWLAN_8730A_PTR 		EnableWoWLAN_8730A_PTR ;
extern  _DisWoWLAN_8730A_PTR 		DisWoWLAN_8730A_PTR ;
extern  _H2CHDL_WoWLAN_8730A_PTR 		H2CHDL_WoWLAN_8730A_PTR ;
extern  _DropDecision_8730A_PTR 		DropDecision_8730A_PTR ;
extern  _FwDisConnectWakeUpHost_8730A_PTR 		FwDisConnectWakeUpHost_8730A_PTR ;
extern  _DestinationMatch_8730A_PTR 		DestinationMatch_8730A_PTR ;
extern  _PassSecurityInfoToDriver_8730A_PTR 		PassSecurityInfoToDriver_8730A_PTR ;
extern  _GetRemoteControlInfo_8730A_PTR 		GetRemoteControlInfo_8730A_PTR ;
extern  _GetARPInfo_8730A_PTR 		GetARPInfo_8730A_PTR ;
extern  _OnARP_8730A_PTR 		OnARP_8730A_PTR ;
extern  _GetNDPInfo_8730A_PTR 		GetNDPInfo_8730A_PTR ;
extern  _IsIPV6_8730A_PTR 		IsIPV6_8730A_PTR ;
extern  _OnNS_8730A_PTR 		OnNS_8730A_PTR ;
extern  _Ipv4Match_8730A_PTR 		Ipv4Match_8730A_PTR ;
extern  _MatchUnicastFilter_8730A_PTR 		MatchUnicastFilter_8730A_PTR ;
extern  _WakeUpHostDecision_8730A_PTR 		WakeUpHostDecision_8730A_PTR ;
extern  _CheckIV_8730A_PTR 		CheckIV_8730A_PTR ;
extern  _H2CHDL_AOACGlobalInfo_8730A_PTR 		H2CHDL_AOACGlobalInfo_8730A_PTR ;
extern  _H2CHDL_AOACRsvdpage1_8730A_PTR 		H2CHDL_AOACRsvdpage1_8730A_PTR ;
extern  _H2CHDL_AOACRsvdpage2_8730A_PTR 		H2CHDL_AOACRsvdpage2_8730A_PTR ;
extern  _H2CHDL_AOACRsvdpage3_8730A_PTR 		H2CHDL_AOACRsvdpage3_8730A_PTR ;
extern  _GetAddr_8730A_PTR 		GetAddr_8730A_PTR ;
extern  _ARP_hdl_8730A_PTR 		ARP_hdl_8730A_PTR ;
extern  _NDP_hdl_8730A_PTR 		NDP_hdl_8730A_PTR ;
extern  _InitDisconnectDecision_8730A_PTR 		InitDisconnectDecision_8730A_PTR ;
extern  _DisconnectChk_8730A_PTR 		DisconnectChk_8730A_PTR ;
extern  _DisconnectTxNullChk_8730A_PTR 		DisconnectTxNullChk_8730A_PTR ;
extern  _H2CHDL_DisconnectDecision_8730A_PTR 		H2CHDL_DisconnectDecision_8730A_PTR ;

extern  _GetIV_8730A_PTR					   GetIV_8730A_PTR;
extern  _GetIVLenAndSecurityType_8730A_PTR     GetIVLenAndSecurityType_8730A_PTR;
extern  _GetMACHeaderLen_8730A_PTR             GetMACHeaderLen_8730A_PTR;
extern  _UpdateIV_8730A_PTR                    UpdateIV_8730A_PTR;
/* GTK */
extern  _AesTkipIvFun_8730A_PTR                AesTkipIvFun_8730A_PTR;
extern  _WepIvFun_8730A_PTR                    WepIvFun_8730A_PTR;
extern  _RTmemcmpBackward_8730A_PTR            RTmemcmpBackward_8730A_PTR ;
extern  _AssignIvToKeyRsc_8730A_PTR            AssignIvToKeyRsc_8730A_PTR;
extern  _AssignKeyRscToIV_8730A_PTR            AssignKeyRscToIV_8730A_PTR;
extern  _AesTkipIvCheck_8730A_PTR              AesTkipIvCheck_8730A_PTR ;
extern  _WepIvCheck_8730A_PTR                  WepIvCheck_8730A_PTR;
/* 3 Jump toram */
extern  _WakeUpHost_8730A_PTR                  WakeUpHost_8730A_PTR;
extern  _issue_ARP_8730A_PTR			issue_ARP_8730A_PTR;
extern  _IssueNA_8730A_PTR			IssueNA_8730A_PTR;

/* 2 BT Coex */
extern  _H2CHDL_BTInfo_8730A_PTR		H2CHDL_BTInfo_8730A_PTR;
extern  _H2CHDL_ForceBTTxpwr_8730A_PTR		H2CHDL_ForceBTTxpwr_8730A_PTR;
extern  _H2CHDL_BTIgnoreWlanAct_8730A_PTR		H2CHDL_BTIgnoreWlanAct_8730A_PTR;
extern  _H2CHDL_AntSelReverse_8730A_PTR		H2CHDL_AntSelReverse_8730A_PTR;
extern  _H2CHDL_WLOpmode_8730A_PTR		H2CHDL_WLOpmode_8730A_PTR;
extern  _H2CHDL_BTMpH2C_8730A_PTR		H2CHDL_BTMpH2C_8730A_PTR;
extern  _H2CHDL_BTControl_8730A_PTR		H2CHDL_BTControl_8730A_PTR;
extern  _H2CHDL_BT_Page_Scan_Interval_8730A_PTR		H2CHDL_BT_Page_Scan_Interval_8730A_PTR;
extern  _H2CHDL_GNT_BT_Ctrl_8730A_PTR		H2CHDL_GNT_BT_Ctrl_8730A_PTR;
extern  _H2CHDL_BT_Only_Test_8730A_PTR		H2CHDL_BT_Only_Test_8730A_PTR;
extern  _H2CHDL_WL_Port_ID_8730A_PTR		H2CHDL_WL_Port_ID_8730A_PTR;
extern  _C2HBTLoopback_8730A_PTR		C2HBTLoopback_8730A_PTR;
extern  _C2HBTMpRpt_8730A_PTR		C2HBTMpRpt_8730A_PTR;
extern  _C2HBTMailBoxStatus_8730A_PTR		C2HBTMailBoxStatus_8730A_PTR;
extern  _InitBTCoexTimer_8730A_PTR		InitBTCoexTimer_8730A_PTR;
extern  _Write778_8730A_PTR		Write778_8730A_PTR;
extern  _TdmaChangeCoexTable_8730A_PTR		TdmaChangeCoexTable_8730A_PTR;
extern  _BTNullSetting_8730A_PTR		BTNullSetting_8730A_PTR;
//3 Jump toram
extern  _WL2BTMailboxSend_8730A_PTR		WL2BTMailboxSend_8730A_PTR;

#endif  /* #ifdef    __RTL8730A_INIT_C__ */

/*--------------------Function declaration------------------------------*/

#endif /* __WIFIFW_FUNCPTR_ROM_H__ */
