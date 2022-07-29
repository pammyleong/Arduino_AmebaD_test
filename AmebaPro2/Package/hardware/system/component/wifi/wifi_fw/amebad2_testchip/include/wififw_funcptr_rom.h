#ifndef __RTL8721D_FUNCPTR_ROM_H__
#define __RTL8721D_FUNCPTR_ROM_H__

/*--------------------Define -------------------------------------------*/

/*--------------------Define Enum---------------------------------------*/

/*--------------------Define MACRO--------------------------------------*/

/*--------------------Define Struct-------------------------------------*/
//1 function pointer
//2 OS
typedef void (*_OSSendSignalCommon_8721D_PTR)(u8  event);
typedef void (*_SendSignalCommon_8721D_PTR)(u8  event);  //brian for function both called in isrhdl or not
typedef void (*_ISRSendSignalCommon_8721D_PTR)(u8  event);


//3 Basic ISR
typedef void (*_UpdateISRSys_8721D_PTR)(void);
typedef void (*_UpdateISRWlan_8721D_PTR)(void);
typedef void (*_UpdateISRFT_8721D_PTR)(void);

typedef void (*_ClrAllFWUsedIMR_8721D_PTR)(void);
typedef void (*_ClrAllFWUsedISR_8721D_PTR)(void);

typedef void (*_setfwimr_8721D_PTR)(IN u32 index, IN u32 bitmask);
typedef void (*_clrfwimr_8721D_PTR)(IN u32 index, IN u32 bitmask);
typedef void (*_setwlanimr_8721D_PTR)(IN u32 index, IN u32 bitmask);
typedef void (*_clrwlanimr_8721D_PTR)(IN u32 index, IN u32 bitmask);
typedef void (*_setftimr_8721D_PTR)(IN u32 index, IN u32 bitmask);
typedef void (*_clrftimr_8721D_PTR)(IN u32 index, IN u32 bitmask);


//3 DDMA
typedef BOOLEAN(*_InitDDMA_8721D_PTR)(IN  u8  ch_num, IN  u32 saddr, IN  u32 daddr, IN  u32 dma_size,
									  IN  BOOLEAN chksum_en, IN  BOOLEAN blockcpu,
									  IN  BOOLEAN spic_burst_mode, IN  BOOLEAN flash_burst_mode);
typedef BOOLEAN(*_WaitDDMARDY_8721D_PTR)(u8 ch_num);
typedef BOOLEAN(*_ChkDDMAChksum_8721D_PTR)(u8 ch_num);
typedef BOOLEAN(*_CheckDDMADone_8721D_PTR)(IN u8 ch_num, IN u8 chk_chksum);


//3 FWLBK
typedef void (*_FwlbkLLTWrite_8721D_PTR)(IN u8 address, IN u8 value);
typedef void (*_FwlbkHWInitialLLT_8721D_PTR)(void);
typedef void (*_FwlbkDbgPrtU16_8721D_PTR)(IN u16 addr, IN u16 wdata);
typedef void (*_FwlbkMode_8721D_PTR)(void);
typedef void (*_FwlbkPreparePkt_8721D_PTR)(void);
typedef void (*_FwlbkModeSel_8721D_PTR)(void);
typedef void (*_FwlbkCheckRxPayload_8721D_PTR)(void);
typedef void (*_FwlbkSetCAM_8721D_PTR)(IN u8 sec_type);
typedef void (*_FwlbkUpdateParam_8721D_PTR)(IN u8 Datarate);
typedef u8(*_FwlbkMcuPollMgq_8721D_PTR)(void);
typedef void (*_FwlbkModeTxNoCheck_8721D_PTR)(void);
typedef void (*_FwlbkModeTx_8721D_PTR)(void);
typedef void (*_FwlbkModeMaclbk_8721D_PTR)(void);
typedef void (*_FwlbkModeSecTest_8721D_PTR)(void);
typedef void (*_FwlbkModeAFElbk_8721D_PTR)(void);
typedef BOOLEAN(*_CheckFWLBKEnable_8721D_PTR)(void);

//3 Util func
typedef  u8(*_PollingReg_8721D_PTR)(u16 RegOffset, u8 PollingBit, u8 PollingResult, u16 PollingLimit, u16 *PollingCount);
//Gtimer
typedef void (*_InitGTimer32us_8721D_PTR)(IN u16 timer_addr, IN u8  _mode, IN u8 Unit2s, IN u8 Unit8ms, IN u8 Unit32us);
typedef void (*_InitGTimer1ms_8721D_PTR)(IN  u16 timer_addr, IN  u8 _mode, IN  u8 Unit65s,  IN  u8 Unit256ms,
		IN  u8 Unit1ms);
typedef BOOLEAN(*_CheckBBRWIsStable_8721D_PTR)(void);
typedef u32(*_PHY_QueryBBReg_8721D_PTR)(IN  u16         RegAddr);     //access delay 20us
typedef void (*_PHY_SetBBReg_8721D_PTR)(IN  u16         RegAddr, IN  u32         Data);   //access delay 20us
typedef void (*_ReadSECCAM_8721D_PTR)(u16 Addr, u8 *Data);
typedef void (*_WriteSECCAM_8721D_PTR)(u16 Addr, u8 *Data);
typedef void (*_ReadBACAM_8721D_PTR)(u8 Addr, u8 *Data);
typedef void (*_WriteBACAM_8721D_PTR)(u8 Addr, u8 *Data);
typedef void (*_ReadMBIDCAM_8721D_PTR)(u8 Addr, u8 *Data);
typedef void (*_WriteMBIDCAM_8721D_PTR)(u8 Addr, u8 *Data);

//3 CMD
typedef void (*_H2CInQueue_8721D_PTR)(void);
typedef void (*_H2CDeQueue_8721D_PTR)(void);
typedef void (*_InitC2H_8721D_PTR)(void);
typedef BOOLEAN(*_WaitC2HOk_8721D_PTR)(u16 TriggerAddr);
typedef void (*_C2HPKTRxDESC_8721D_PTR)(IN  u16 PktLength, IN  u16  C2HDescOffset);
typedef void (*_FillC2HContant_8721D_PTR)(IN u16  C2HPKTOffset, IN  PC2H_EVT_HDR pc2h_hdr);
typedef void (*_IssueC2HPKT_8721D_PTR)(IN  PC2H_EVT_HDR pc2h_hdr);
typedef void (*_C2HDeQueue_8721D_PTR)(void);
typedef void (*_C2HInQueue_8721D_PTR)(PC2H_EVT_HDR pc2h_hdr);
typedef u8(*_CheckMaxMacidNum_8721D_PTR)(void);
typedef void (*_SetMediaStatus_8721D_PTR)(IN u8   macid, IN u8   status);
typedef BOOLEAN(*_GetMediaStatus_8721D_PTR)(IN u8   macid);
//3 JumpRam
typedef void (*_H2CCmdFunc_8721D_PTR)(u8  CmdID, u8  *content);


//3 Packet
typedef void (*_ChangeTransmiteRate_8721D_PTR)(IN u16 offset);
typedef void (*_PowerBitSetting_8721D_PTR)(IN  u8 bPowerBit, IN  u16 offset);
typedef void (*_IssuePSPoll_8721D_PTR)(void);
typedef void (*_ChkandChangePS_8721D_PTR)(IN  u8 bPowerBit);
typedef void (*_IssueQNull_8721D_PTR)(IN  u8  bPowerBit);
typedef void (*_CTS2SelfSetting_8721D_PTR)(IN  u16 offset, IN  u16 NAV);
typedef void (*_IssueCTS2Self_8721D_PTR)(IN  u8 location, IN u16 NAV);
typedef BOOLEAN(*_CheckCPUMGQEmpty_8721D_PTR)(void);
typedef u16(*_IssueRsvdPagePacketSetting_8721D_PTR)(IN  u8 PageNum, IN  BOOLEAN bHwSEQEn, IN  u8 RtyLmt,
		IN  u8 TxInd);
typedef u8(*_ReadRxBuff_8721D_PTR)(IN u16 headaddr, IN u8  offset);

//3 Powersave
typedef void (*_SetSmartPSTimer_8721D_PTR)(void);
typedef void (*_SetPwrStateReg_8721D_PTR)(IN u8 PwrStateType, IN u8 value);
typedef void (*_ResetPSParm_8721D_PTR)(void);
typedef BOOLEAN(*_ChkTxQueueIsEmpty_8721D_PTR)(void);
typedef void (*_Legacy_PS_Setting_8721D_PTR)(void);
typedef void (*_PSModeSetting_8721D_PTR)(IN u8 on);
typedef void (*_ConfigListenBeaconPeriod_8721D_PTR)(IN u8  RLBM,  IN u8  AwakeInterval);
typedef void (*_PSSetMode_8721D_PTR)(IN PLEGACY_PS_PARM pparm);
typedef void (*_PS_S2ToS3State_8721D_PTR)(IN u8  nulldata0Allow);
typedef void (*_PS_S2ToS0State_8721D_PTR)(void);
typedef void (*_PS_S3ToS2orS0State_8721D_PTR)(void);
typedef void (*_PS_S0ToS1State_8721D_PTR)(void);
typedef void (*_PS_S1ToS0orS2State_8721D_PTR)(void);
typedef void (*_PS_S2ToS4State_8721D_PTR)(void);
typedef void (*_PS_S2ToS5State_8721D_PTR)(void);
typedef void (*_PS_S5ToS2State_8721D_PTR)(void);
typedef void (*_PS_S4ToS2State_8721D_PTR)(IN  u8  ReleaseTxPause);
typedef void (*_SmartPS2InitTimerAndToGetRxPkt_8721D_PTR)(void);
typedef void (*_SetBcnEarlyAndTimeout_8721D_PTR)(u8 BcnAheadShift, u8 BcnEarlyShift, u8 BcnTimeout, u8 ReasonCode);
typedef void (*_EnlargeBcnEarlyAndTimeout_8721D_PTR)(void);
typedef void (*_ResetBcnEarlyAdjustParm_8721D_PTR)(BOOLEAN OnJoin);
typedef void (*_PS_S0ToS6State_8721D_PTR)(void);
typedef void (*_PS_S6ToS0State_8721D_PTR)(void);
//3 jumptoram
typedef void (*_Change_PS_State_8721D_PTR)(IN  u8  request_ps_state,  IN  u8  nulldata0Allow);
typedef BOOLEAN(*_PS_S2_Condition_Match_8721D_PTR)(void);
typedef u8(*_PS_S4_Condition_Match_8721D_PTR)(void);
typedef void (*_WriteTxPauseWithMask_8721D_PTR)(IN u8 mask, IN u8 value, IN u8 rcode);
typedef BOOLEAN(*_WaitTxStateMachineOk_8721D_PTR)(void);
typedef void (*_WriteTxPause_8721D_PTR)(IN u8 value, IN u8 rcode);
typedef void (*_PsOpenRF_8721D_PTR)(void);
typedef void (*_PsCloseRF_8721D_PTR)(void);
typedef BOOLEAN(*_IssueNullData_8721D_PTR)(IN  u8 bPowerBit, IN  u8 RtyLmt);

//3 Wowlan
typedef void (*_GetIV_8721D_PTR)(u16 addrl_frame_ctrl, u8 MacHeaderLen, u8 IvLen, u8 *IV) ;
typedef u8(*_GetIVLenAndSecurityType_8721D_PTR)(IN u8 raaddr) ;
typedef u8(*_GetMACHeaderLen_8721D_PTR)(IN u8  macheader, IN u8  FrameCtrl, IN u8  raaddr) ;
typedef void (*_UpdateIV_8721D_PTR)(IN u8 *buf, IN u8 retry_bit) ;
//GTK
typedef void (*_AesTkipIvFun_8721D_PTR)(IN u8 *pattrib_iv, IN u8 RetryBit, IN u8 SecurityType) ;
typedef void (*_WepIvFun_8721D_PTR)(IN unsigned char *iv, IN unsigned char retry_bit) ;
typedef s8(*_RTmemcmpBackward_8721D_PTR)(IN const void *Dest, IN const void *Src, IN u8 count);
typedef void (*_AssignIvToKeyRsc_8721D_PTR)(IN u8 *pattrib_iv, IN u8 *KeyRsc, IN u8 *KeyID, IN u8 SecurityType);
typedef void (*_AssignKeyRscToIV_8721D_PTR)(IN u8 *pattrib_iv, IN u8 *KeyRsc, IN u8 SecurityType);
typedef u8(*_AesTkipIvCheck_8721D_PTR)(IN u8 *rx_iv_ori, IN u8 *rx_iv, IN u8 SecurityType);
typedef u8(*_WepIvCheck_8721D_PTR)(IN u8 *rx_iv_ori, IN u8 *rx_iv);
//Jumptoram
typedef void (*_WakeUpHost_8721D_PTR)(IN u8 source) ;

//3 BT Coex
typedef void (*_BTRoleChangeTimerHDL_8721D_PTR)(void);
typedef void (*_BTRoleChangeTBTTHDL_8721D_PTR)(void);
typedef void (*_FillMailbox_8721D_PTR)(IN u8 cmd, IN u8 length,	IN u8 *pparm);
typedef u8(*_WL2BTMailbox_8721D_PTR)(IN u8 cmd, IN u8 length, IN u8 *pparm);
typedef void (*_MailboxINTHDL_8721D_PTR)(void);
typedef void (*_BTMailboxRetry_8721D_PTR)(void);
typedef void (*_H2CHDL_BTInfo_8721D_PTR)(IN u8 *pbuf);
typedef void (*_H2CHDL_ForceBTTxpwr_8721D_PTR)(IN u8 *pbuf);
typedef void (*_H2CHDL_BTIgnoreWlanAct_8721D_PTR)(IN u8 *pbuf);
typedef void (*_H2CHDL_DACSwingValue_8721D_PTR)(IN u8 *pbuf);
typedef void (*_H2CHDL_AntSelReverse_8721D_PTR)(IN u8 *pbuf);
typedef void (*_H2CHDL_WLOpmode_8721D_PTR)(IN u8 *pbuf);
typedef void (*_H2CHDL_BTMpH2C_8721D_PTR)(IN u8 *pbuf);
typedef void (*_H2CHDL_BTControl_8721D_PTR)(IN u8 *pbuf);
typedef void (*_H2CHDL_BTWifiCtrl_8721D_PTR)(IN u8 *pbuf);
typedef void (*_H2CHDL_BT_Page_Scan_Interval_8721D_PTR)(u8 *pbuf);
typedef void (*_H2CHDL_WLCalibration_8721D_PTR)(u8 *pbuf);
typedef void (*_H2CHDL_GNT_BT_CTRL_8721D_PTR)(u8 *pbuf);
typedef void (*_H2CHDL_BT_ONLY_TEST_8721D_PTR)(u8 *pbuf);
typedef void (*_H2CHDL_BT_Init_Param_8721D_PTR)(u8 *pbuf);
typedef void (*_C2HBTInfo_8721D_PTR)(IN u8 option);
typedef void (*_C2HBTLoopback_8721D_PTR)(IN u8 *pbuf);
typedef void (*_C2HBTMpRpt_8721D_PTR)(IN u8 idx, IN u8 status, IN u8 req_num);
typedef void (*_C2HBTMailBoxStatus_8721D_PTR)(IN u8 status);
typedef void (*_InitBTMailbox_8721D_PTR)(void);
typedef void (*_InitBTypeTDMA2_8721D_PTR)(void);
typedef void (*_InitBTCoexTimer_8721D_PTR)(IN u8 duration);
typedef void (*_Write778_8721D_PTR)(IN u8 value);
typedef void (*_ChangeCoexTable_8721D_PTR)(IN u8 slot);
typedef void (*_DacSwing_8721D_PTR)(IN u8 action);
typedef void (*_BTNullSetting_8721D_PTR)(IN u8 bPowerBit, IN u16 offset, IN u8 lsb, IN u8 msb);
typedef void (*_IssueBTQNull_8721D_PTR)(IN u8 bPowerBit, IN u8 lsb, IN u8 msb);
typedef void (*_WlanActCtrl_8721D_PTR)(void);
typedef void (*_BT_TDMA_Slot_Operation_0and3_8721D_PTR)(IN u8 slot_num);
typedef void (*_BT_TDMA_Slot_Operation_1and4_8721D_PTR)(IN u8 slot_num);
typedef void (*_BT_TDMA_Slot_Operation_2and5_8721D_PTR)(IN u8 slot_num);
typedef void (*_FlexibleExtensionDecision_8721D_PTR)(void);
typedef void (*_BTypeTDMABCNEarly_8721D_PTR)(void);
typedef void (*_BTypeTDMATBTThdl_8721D_PTR)(void);
typedef void (*_BTypeTDMATimeOuthdl_8721D_PTR)(void);
//Jumptoram
typedef void(*_BTRoleChangeDefaultSetting_8721D_PTR)(void);
typedef void(*_BackupAntennaSetting_8721D_PTR)(IN u8 option);
typedef void(*_MailboxINTHDL_Patch_8721D_PTR)(u8 cmd);
typedef void(*_H2CHDL_BTPSTDMA_8721D_PTR)(IN u8 *pbuf);
typedef void(*_H2CHDL_BTFwPatch_8721D_PTR)(u8 *pbuf);

/*------------------------Export global variable------------------------------*/
#ifdef  __RTL8721D_INIT_C__

//Direct Mapping HW Register

//1 function pointer
//2 OS
FW_ROM_BSS_SECTION  _OSSendSignalCommon_8721D_PTR         OSSendSignalCommon_8721D_PTR;
FW_ROM_BSS_SECTION  _SendSignalCommon_8721D_PTR           SendSignalCommon_8721D_PTR;
FW_ROM_BSS_SECTION  _ISRSendSignalCommon_8721D_PTR		  ISRSendSignalCommon_8721D_PTR;


//2 Basic ISR
FW_ROM_BSS_SECTION  _UpdateISRSys_8721D_PTR               UpdateISRSys_8721D_PTR;
FW_ROM_BSS_SECTION  _UpdateISRWlan_8721D_PTR			  UpdateISRWlan_8721D_PTR;
FW_ROM_BSS_SECTION	_UpdateISRFT_8721D_PTR				  UpdateISRFT_8721D_PTR;

FW_ROM_BSS_SECTION 	_ClrAllFWUsedIMR_8721D_PTR	     	  ClrAllFWUsedIMR_8721D_PTR;
FW_ROM_BSS_SECTION 	_ClrAllFWUsedISR_8721D_PTR	          ClrAllFWUsedISR_8721D_PTR;

FW_ROM_BSS_SECTION 	_setfwimr_8721D_PTR         		  setfwimr_8721D_PTR;
FW_ROM_BSS_SECTION 	_clrfwimr_8721D_PTR				      clrfwimr_8721D_PTR;
FW_ROM_BSS_SECTION 	_setwlanimr_8721D_PTR         		  setwlanimr_8721D_PTR;
FW_ROM_BSS_SECTION 	_clrwlanimr_8721D_PTR				  clrwlanimr_8721D_PTR;
FW_ROM_BSS_SECTION 	_setftimr_8721D_PTR 			      setftimr_8721D_PTR;
FW_ROM_BSS_SECTION 	_clrftimr_8721D_PTR                   clrftimr_8721D_PTR;


//2 DDMA
FW_ROM_BSS_SECTION 	_InitDDMA_8721D_PTR					  InitDDMA_8721D_PTR;
FW_ROM_BSS_SECTION 	_WaitDDMARDY_8721D_PTR                WaitDDMARDY_8721D_PTR;
FW_ROM_BSS_SECTION 	_ChkDDMAChksum_8721D_PTR              ChkDDMAChksum_8721D_PTR;
FW_ROM_BSS_SECTION 	_CheckDDMADone_8721D_PTR              CheckDDMADone_8721D_PTR;

//2 FWLBK
FW_ROM_BSS_SECTION  _FwlbkLLTWrite_8721D_PTR              FwlbkLLTWrite_8721D_PTR;
FW_ROM_BSS_SECTION  _FwlbkHWInitialLLT_8721D_PTR          FwlbkHWInitialLLT_8721D_PTR;
FW_ROM_BSS_SECTION  _FwlbkDbgPrtU16_8721D_PTR             FwlbkDbgPrtU16_8721D_PTR;
FW_ROM_BSS_SECTION  _FwlbkMode_8721D_PTR                  FwlbkMode_8721D_PTR;
FW_ROM_BSS_SECTION  _FwlbkPreparePkt_8721D_PTR            FwlbkPreparePkt_8721D_PTR;
FW_ROM_BSS_SECTION  _FwlbkModeSel_8721D_PTR               FwlbkModeSel_8721D_PTR;
FW_ROM_BSS_SECTION  _FwlbkCheckRxPayload_8721D_PTR        FwlbkCheckRxPayload_8721D_PTR;
FW_ROM_BSS_SECTION  _FwlbkSetCAM_8721D_PTR                FwlbkSetCAM_8721D_PTR;
FW_ROM_BSS_SECTION  _FwlbkUpdateParam_8721D_PTR           FwlbkUpdateParam_8721D_PTR;
FW_ROM_BSS_SECTION  _FwlbkMcuPollMgq_8721D_PTR            FwlbkMcuPollMgq_8721D_PTR;
FW_ROM_BSS_SECTION  _FwlbkModeTxNoCheck_8721D_PTR         FwlbkModeTxNoCheck_8721D_PTR;
FW_ROM_BSS_SECTION  _FwlbkModeTx_8721D_PTR                FwlbkModeTx_8721D_PTR;
FW_ROM_BSS_SECTION  _FwlbkModeMaclbk_8721D_PTR            FwlbkModeMaclbk_8721D_PTR;
FW_ROM_BSS_SECTION  _FwlbkModeSecTest_8721D_PTR           FwlbkModeSecTest_8721D_PTR;
FW_ROM_BSS_SECTION  _FwlbkModeAFElbk_8721D_PTR            FwlbkModeAFElbk_8721D_PTR;
FW_ROM_BSS_SECTION  _CheckFWLBKEnable_8721D_PTR  		  CheckFWLBKEnable_8721D_PTR;


//2 Util Func
FW_ROM_BSS_SECTION  _PollingReg_8721D_PTR                 PollingReg_8721D_PTR;
//Gtimer
FW_ROM_BSS_SECTION  _InitGTimer32us_8721D_PTR             InitGTimer32us_8721D_PTR;
FW_ROM_BSS_SECTION  _InitGTimer1ms_8721D_PTR              InitGTimer1ms_8721D_PTR;
FW_ROM_BSS_SECTION  _CheckBBRWIsStable_8721D_PTR 		  CheckBBRWIsStable_8721D_PTR;
FW_ROM_BSS_SECTION  _PHY_QueryBBReg_8721D_PTR			  PHY_QueryBBReg_8721D_PTR;
FW_ROM_BSS_SECTION  _PHY_SetBBReg_8721D_PTR				  PHY_SetBBReg_8721D_PTR;
FW_ROM_BSS_SECTION  _ReadSECCAM_8721D_PTR    	 		  ReadSECCAM_8721D_PTR;
FW_ROM_BSS_SECTION 	_WriteSECCAM_8721D_PTR   			  WriteSECCAM_8721D_PTR;
FW_ROM_BSS_SECTION 	_ReadBACAM_8721D_PTR  				  ReadBACAM_8721D_PTR;
FW_ROM_BSS_SECTION  _WriteBACAM_8721D_PTR  				  WriteBACAM_8721D_PTR;
FW_ROM_BSS_SECTION 	_ReadMBIDCAM_8721D_PTR  			  ReadMBIDCAM_8721D_PTR;
FW_ROM_BSS_SECTION 	_WriteMBIDCAM_8721D_PTR  			  WriteMBIDCAM_8721D_PTR;

//2 CMD
FW_ROM_BSS_SECTION  _H2CInQueue_8721D_PTR                 H2CInQueue_8721D_PTR;
FW_ROM_BSS_SECTION  _H2CDeQueue_8721D_PTR                 H2CDeQueue_8721D_PTR;
FW_ROM_BSS_SECTION  _InitC2H_8721D_PTR					  InitC2H_8721D_PTR;
FW_ROM_BSS_SECTION  _WaitC2HOk_8721D_PTR				  WaitC2HOk_8721D_PTR;
FW_ROM_BSS_SECTION  _C2HPKTRxDESC_8721D_PTR               C2HPKTRxDESC_8721D_PTR;
FW_ROM_BSS_SECTION  _FillC2HContant_8721D_PTR             FillC2HContant_8721D_PTR;
FW_ROM_BSS_SECTION  _IssueC2HPKT_8721D_PTR                IssueC2HPKT_8721D_PTR;
FW_ROM_BSS_SECTION  _C2HDeQueue_8721D_PTR                 C2HDeQueue_8721D_PTR;
FW_ROM_BSS_SECTION  _C2HInQueue_8721D_PTR                 C2HInQueue_8721D_PTR;
FW_ROM_BSS_SECTION  _CheckMaxMacidNum_8721D_PTR			  CheckMaxMacidNum_8721D_PTR;
FW_ROM_BSS_SECTION  _SetMediaStatus_8721D_PTR			  SetMediaStatus_8721D_PTR;
FW_ROM_BSS_SECTION  _GetMediaStatus_8721D_PTR		      GetMediaStatus_8721D_PTR;
//3 JumpRam
FW_ROM_BSS_SECTION  _H2CCmdFunc_8721D_PTR                 H2CCmdFunc_8721D_PTR;


//2 Packet
FW_ROM_BSS_SECTION  _ChangeTransmiteRate_8721D_PTR        ChangeTransmiteRate_8721D_PTR;
FW_ROM_BSS_SECTION  _PowerBitSetting_8721D_PTR            PowerBitSetting_8721D_PTR;
FW_ROM_BSS_SECTION  _IssuePSPoll_8721D_PTR                IssuePSPoll_8721D_PTR;
FW_ROM_BSS_SECTION  _ChkandChangePS_8721D_PTR             ChkandChangePS_8721D_PTR;
FW_ROM_BSS_SECTION  _IssueQNull_8721D_PTR                 IssueQNull_8721D_PTR;
FW_ROM_BSS_SECTION  _CTS2SelfSetting_8721D_PTR			  CTS2SelfSetting_8721D_PTR;
FW_ROM_BSS_SECTION  _IssueCTS2Self_8721D_PTR              IssueCTS2Self_8721D_PTR;
FW_ROM_BSS_SECTION  _CheckCPUMGQEmpty_8721D_PTR			  CheckCPUMGQEmpty_8721D_PTR;
FW_ROM_BSS_SECTION  _IssueRsvdPagePacketSetting_8721D_PTR IssueRsvdPagePacketSetting_8721D_PTR;
FW_ROM_BSS_SECTION  _ReadRxBuff_8721D_PTR                 ReadRxBuff_8721D_PTR;

//2 Powersave
FW_ROM_BSS_SECTION  _SetSmartPSTimer_8721D_PTR            SetSmartPSTimer_8721D_PTR;
FW_ROM_BSS_SECTION  _SetPwrStateReg_8721D_PTR             SetPwrStateReg_8721D_PTR;
FW_ROM_BSS_SECTION  _ResetPSParm_8721D_PTR                ResetPSParm_8721D_PTR;
FW_ROM_BSS_SECTION  _ChkTxQueueIsEmpty_8721D_PTR		  ChkTxQueueIsEmpty_8721D_PTR;
FW_ROM_BSS_SECTION  _Legacy_PS_Setting_8721D_PTR          Legacy_PS_Setting_8721D_PTR;
FW_ROM_BSS_SECTION  _PSModeSetting_8721D_PTR              PSModeSetting_8721D_PTR;
FW_ROM_BSS_SECTION  _ConfigListenBeaconPeriod_8721D_PTR   ConfigListenBeaconPeriod_8721D_PTR;
FW_ROM_BSS_SECTION  _PSSetMode_8721D_PTR				  PSSetMode_8721D_PTR;
FW_ROM_BSS_SECTION  _PS_S2ToS3State_8721D_PTR			  PS_S2ToS3State_8721D_PTR;
FW_ROM_BSS_SECTION  _PS_S2ToS0State_8721D_PTR             PS_S2ToS0State_8721D_PTR;
FW_ROM_BSS_SECTION  _PS_S3ToS2orS0State_8721D_PTR   	  PS_S3ToS2orS0State_8721D_PTR;
FW_ROM_BSS_SECTION  _PS_S0ToS1State_8721D_PTR			  PS_S0ToS1State_8721D_PTR;
FW_ROM_BSS_SECTION  _PS_S1ToS0orS2State_8721D_PTR		  PS_S1ToS0orS2State_8721D_PTR;
FW_ROM_BSS_SECTION  _PS_S2ToS4State_8721D_PTR			  PS_S2ToS4State_8721D_PTR;
FW_ROM_BSS_SECTION  _PS_S2ToS5State_8721D_PTR			  PS_S2ToS5State_8721D_PTR;
FW_ROM_BSS_SECTION  _PS_S5ToS2State_8721D_PTR			  PS_S5ToS2State_8721D_PTR;
FW_ROM_BSS_SECTION  _PS_S4ToS2State_8721D_PTR			  PS_S4ToS2State_8721D_PTR;
FW_ROM_BSS_SECTION  _SmartPS2InitTimerAndToGetRxPkt_8721D_PTR	 SmartPS2InitTimerAndToGetRxPkt_8721D_PTR;
FW_ROM_BSS_SECTION  _SetBcnEarlyAndTimeout_8721D_PTR      SetBcnEarlyAndTimeout_8721D_PTR;
FW_ROM_BSS_SECTION  _EnlargeBcnEarlyAndTimeout_8721D_PTR  EnlargeBcnEarlyAndTimeout_8721D_PTR;
FW_ROM_BSS_SECTION  _ResetBcnEarlyAdjustParm_8721D_PTR    ResetBcnEarlyAdjustParm_8721D_PTR;
FW_ROM_BSS_SECTION  _PS_S0ToS6State_8721D_PTR			  PS_S0ToS6State_8721D_PTR;
FW_ROM_BSS_SECTION  _PS_S6ToS0State_8721D_PTR			  PS_S6ToS0State_8721D_PTR;
//3 jump to ram
FW_ROM_BSS_SECTION  _Change_PS_State_8721D_PTR            Change_PS_State_8721D_PTR;
FW_ROM_BSS_SECTION  _PS_S2_Condition_Match_8721D_PTR      PS_S2_Condition_Match_8721D_PTR;
FW_ROM_BSS_SECTION  _PS_S4_Condition_Match_8721D_PTR      PS_S4_Condition_Match_8721D_PTR;
FW_ROM_BSS_SECTION  _WriteTxPauseWithMask_8721D_PTR       WriteTxPauseWithMask_8721D_PTR;
FW_ROM_BSS_SECTION  _WaitTxStateMachineOk_8721D_PTR       WaitTxStateMachineOk_8721D_PTR;
FW_ROM_BSS_SECTION  _WriteTxPause_8721D_PTR               WriteTxPause_8721D_PTR;
FW_ROM_BSS_SECTION  _PsOpenRF_8721D_PTR                   PsOpenRF_8721D_PTR;
FW_ROM_BSS_SECTION  _PsCloseRF_8721D_PTR                  PsCloseRF_8721D_PTR;
FW_ROM_BSS_SECTION  _IssueNullData_8721D_PTR              IssueNullData_8721D_PTR;

//2 Wowlan
FW_ROM_BSS_SECTION  _GetIV_8721D_PTR					  GetIV_8721D_PTR;
FW_ROM_BSS_SECTION  _GetIVLenAndSecurityType_8721D_PTR    GetIVLenAndSecurityType_8721D_PTR;
FW_ROM_BSS_SECTION  _GetMACHeaderLen_8721D_PTR            GetMACHeaderLen_8721D_PTR;
FW_ROM_BSS_SECTION  _UpdateIV_8721D_PTR                   UpdateIV_8721D_PTR;
//GTK
FW_ROM_BSS_SECTION  _AesTkipIvFun_8721D_PTR           	  AesTkipIvFun_8721D_PTR;
FW_ROM_BSS_SECTION  _WepIvFun_8721D_PTR                   WepIvFun_8721D_PTR;
FW_ROM_BSS_SECTION  _RTmemcmpBackward_8721D_PTR           RTmemcmpBackward_8721D_PTR;
FW_ROM_BSS_SECTION  _AssignIvToKeyRsc_8721D_PTR           AssignIvToKeyRsc_8721D_PTR ;
FW_ROM_BSS_SECTION  _AssignKeyRscToIV_8721D_PTR           AssignKeyRscToIV_8721D_PTR;
FW_ROM_BSS_SECTION  _AesTkipIvCheck_8721D_PTR             AesTkipIvCheck_8721D_PTR;
FW_ROM_BSS_SECTION  _WepIvCheck_8721D_PTR                 WepIvCheck_8721D_PTR;
//3 Jumptoram
FW_ROM_BSS_SECTION  _WakeUpHost_8721D_PTR                 WakeUpHost_8721D_PTR;

//2 BT Coex
FW_ROM_BSS_SECTION  _BTRoleChangeTimerHDL_8721D_PTR		BTRoleChangeTimerHDL_8721D_PTR;
FW_ROM_BSS_SECTION  _BTRoleChangeTBTTHDL_8721D_PTR		BTRoleChangeTBTTHDL_8721D_PTR;
FW_ROM_BSS_SECTION  _FillMailbox_8721D_PTR		FillMailbox_8721D_PTR;
FW_ROM_BSS_SECTION  _WL2BTMailbox_8721D_PTR		WL2BTMailbox_8721D_PTR;
FW_ROM_BSS_SECTION  _MailboxINTHDL_8721D_PTR		MailboxINTHDL_8721D_PTR;
FW_ROM_BSS_SECTION  _BTMailboxRetry_8721D_PTR		BTMailboxRetry_8721D_PTR;
FW_ROM_BSS_SECTION  _H2CHDL_BTInfo_8721D_PTR		H2CHDL_BTInfo_8721D_PTR;
FW_ROM_BSS_SECTION  _H2CHDL_ForceBTTxpwr_8721D_PTR		H2CHDL_ForceBTTxpwr_8721D_PTR;
FW_ROM_BSS_SECTION  _H2CHDL_BTIgnoreWlanAct_8721D_PTR		H2CHDL_BTIgnoreWlanAct_8721D_PTR;
FW_ROM_BSS_SECTION  _H2CHDL_DACSwingValue_8721D_PTR		H2CHDL_DACSwingValue_8721D_PTR;
FW_ROM_BSS_SECTION  _H2CHDL_AntSelReverse_8721D_PTR		H2CHDL_AntSelReverse_8721D_PTR;
FW_ROM_BSS_SECTION  _H2CHDL_WLOpmode_8721D_PTR		H2CHDL_WLOpmode_8721D_PTR;
FW_ROM_BSS_SECTION  _H2CHDL_BTMpH2C_8721D_PTR		H2CHDL_BTMpH2C_8721D_PTR;
FW_ROM_BSS_SECTION  _H2CHDL_BTControl_8721D_PTR		H2CHDL_BTControl_8721D_PTR;
FW_ROM_BSS_SECTION  _H2CHDL_BTWifiCtrl_8721D_PTR		H2CHDL_BTWifiCtrl_8721D_PTR;
FW_ROM_BSS_SECTION  _H2CHDL_BT_Page_Scan_Interval_8721D_PTR		H2CHDL_BT_Page_Scan_Interval_8721D_PTR;
FW_ROM_BSS_SECTION  _H2CHDL_WLCalibration_8721D_PTR		H2CHDL_WLCalibration_8721D_PTR;
FW_ROM_BSS_SECTION  _H2CHDL_GNT_BT_CTRL_8721D_PTR		H2CHDL_GNT_BT_CTRL_8721D_PTR;
FW_ROM_BSS_SECTION  _H2CHDL_BT_ONLY_TEST_8721D_PTR		H2CHDL_BT_ONLY_TEST_8721D_PTR;
FW_ROM_BSS_SECTION  _H2CHDL_BT_Init_Param_8721D_PTR		H2CHDL_BT_Init_Param_8721D_PTR;
FW_ROM_BSS_SECTION  _C2HBTInfo_8721D_PTR		C2HBTInfo_8721D_PTR;
FW_ROM_BSS_SECTION  _C2HBTLoopback_8721D_PTR		C2HBTLoopback_8721D_PTR;
FW_ROM_BSS_SECTION  _C2HBTMpRpt_8721D_PTR		C2HBTMpRpt_8721D_PTR;
FW_ROM_BSS_SECTION  _C2HBTMailBoxStatus_8721D_PTR		C2HBTMailBoxStatus_8721D_PTR;
FW_ROM_BSS_SECTION  _InitBTMailbox_8721D_PTR		InitBTMailbox_8721D_PTR;
FW_ROM_BSS_SECTION  _InitBTypeTDMA2_8721D_PTR		InitBTypeTDMA2_8721D_PTR;
FW_ROM_BSS_SECTION  _InitBTCoexTimer_8721D_PTR		InitBTCoexTimer_8721D_PTR;
FW_ROM_BSS_SECTION  _Write778_8721D_PTR		Write778_8721D_PTR;
FW_ROM_BSS_SECTION  _ChangeCoexTable_8721D_PTR		ChangeCoexTable_8721D_PTR;
FW_ROM_BSS_SECTION  _DacSwing_8721D_PTR		DacSwing_8721D_PTR;
FW_ROM_BSS_SECTION  _BTNullSetting_8721D_PTR		BTNullSetting_8721D_PTR;
FW_ROM_BSS_SECTION  _IssueBTQNull_8721D_PTR		IssueBTQNull_8721D_PTR;
FW_ROM_BSS_SECTION  _WlanActCtrl_8721D_PTR		WlanActCtrl_8721D_PTR;
FW_ROM_BSS_SECTION  _BT_TDMA_Slot_Operation_0and3_8721D_PTR		BT_TDMA_Slot_Operation_0and3_8721D_PTR;
FW_ROM_BSS_SECTION  _BT_TDMA_Slot_Operation_1and4_8721D_PTR		BT_TDMA_Slot_Operation_1and4_8721D_PTR;
FW_ROM_BSS_SECTION  _BT_TDMA_Slot_Operation_2and5_8721D_PTR		BT_TDMA_Slot_Operation_2and5_8721D_PTR;
FW_ROM_BSS_SECTION  _FlexibleExtensionDecision_8721D_PTR		FlexibleExtensionDecision_8721D_PTR;
FW_ROM_BSS_SECTION  _BTypeTDMABCNEarly_8721D_PTR		BTypeTDMABCNEarly_8721D_PTR;
FW_ROM_BSS_SECTION  _BTypeTDMATBTThdl_8721D_PTR		BTypeTDMATBTThdl_8721D_PTR;
FW_ROM_BSS_SECTION  _BTypeTDMATimeOuthdl_8721D_PTR		BTypeTDMATimeOuthdl_8721D_PTR;
//3 Jumptoram
FW_ROM_BSS_SECTION  _BTRoleChangeDefaultSetting_8721D_PTR		BTRoleChangeDefaultSetting_8721D_PTR;
FW_ROM_BSS_SECTION  _BackupAntennaSetting_8721D_PTR		BackupAntennaSetting_8721D_PTR;
FW_ROM_BSS_SECTION  _MailboxINTHDL_Patch_8721D_PTR		MailboxINTHDL_Patch_8721D_PTR;
FW_ROM_BSS_SECTION  _H2CHDL_BTPSTDMA_8721D_PTR			H2CHDL_BTPSTDMA_8721D_PTR;
FW_ROM_BSS_SECTION  _H2CHDL_BTFwPatch_8721D_PTR			H2CHDL_BTFwPatch_8721D_PTR;


#else

//1 Function Pointer
//2 OS
extern  _OSSendSignalCommon_8721D_PTR          OSSendSignalCommon_8721D_PTR;
extern  _SendSignalCommon_8721D_PTR            SendSignalCommon_8721D_PTR;
extern  _ISRSendSignalCommon_8721D_PTR		   ISRSendSignalCommon_8721D_PTR;


//2 BasicISR
extern  _UpdateISRSys_8721D_PTR                UpdateISRSys_8721D_PTR;
extern  _UpdateISRWlan_8721D_PTR			   UpdateISRWlan_8721D_PTR;
extern  _UpdateISRFT_8721D_PTR				   UpdateISRFT_8721D_PTR;

extern  _ClrAllFWUsedIMR_8721D_PTR	     	   ClrAllFWUsedIMR_8721D_PTR;
extern  _ClrAllFWUsedISR_8721D_PTR	           ClrAllFWUsedISR_8721D_PTR;

extern 	_setfwimr_8721D_PTR         		   setfwimr_8721D_PTR;
extern 	_clrfwimr_8721D_PTR				       clrfwimr_8721D_PTR;
extern  _setwlanimr_8721D_PTR                  setwlanimr_8721D_PTR;
extern  _clrwlanimr_8721D_PTR				   clrwlanimr_8721D_PTR;
extern  _setftimr_8721D_PTR 				   setftimr_8721D_PTR;
extern  _clrftimr_8721D_PTR                    clrftimr_8721D_PTR;

//2 DDMA
extern  _InitDDMA_8721D_PTR					   InitDDMA_8721D_PTR;
extern  _WaitDDMARDY_8721D_PTR                 WaitDDMARDY_8721D_PTR;
extern  _ChkDDMAChksum_8721D_PTR               ChkDDMAChksum_8721D_PTR;
extern  _CheckDDMADone_8721D_PTR               CheckDDMADone_8721D_PTR;


//2 FWLBK
extern  _FwlbkLLTWrite_8721D_PTR               FwlbkLLTWrite_8721D_PTR;
extern  _FwlbkHWInitialLLT_8721D_PTR           FwlbkHWInitialLLT_8721D_PTR;
extern  _FwlbkDbgPrtU16_8721D_PTR              FwlbkDbgPrtU16_8721D_PTR;
extern  _FwlbkMode_8721D_PTR                   FwlbkMode_8721D_PTR;
extern  _FwlbkPreparePkt_8721D_PTR             FwlbkPreparePkt_8721D_PTR;
extern  _FwlbkModeSel_8721D_PTR                FwlbkModeSel_8721D_PTR;
extern  _FwlbkCheckRxPayload_8721D_PTR         FwlbkCheckRxPayload_8721D_PTR;
extern  _FwlbkSetCAM_8721D_PTR                 FwlbkSetCAM_8721D_PTR;
extern  _FwlbkUpdateParam_8721D_PTR            FwlbkUpdateParam_8721D_PTR;
extern  _FwlbkMcuPollMgq_8721D_PTR             FwlbkMcuPollMgq_8721D_PTR;
extern  _FwlbkModeTxNoCheck_8721D_PTR          FwlbkModeTxNoCheck_8721D_PTR;
extern  _FwlbkModeTx_8721D_PTR                 FwlbkModeTx_8721D_PTR;
extern  _FwlbkModeMaclbk_8721D_PTR             FwlbkModeMaclbk_8721D_PTR;
extern  _FwlbkModeSecTest_8721D_PTR            FwlbkModeSecTest_8721D_PTR;
extern  _FwlbkModeAFElbk_8721D_PTR             FwlbkModeAFElbk_8721D_PTR;
extern  _CheckFWLBKEnable_8721D_PTR  		   CheckFWLBKEnable_8721D_PTR;

//2 Util Func
extern  _PollingReg_8721D_PTR                  PollingReg_8721D_PTR;
//Gtimer
extern  _InitGTimer32us_8721D_PTR              InitGTimer32us_8721D_PTR;
extern  _InitGTimer1ms_8721D_PTR               InitGTimer1ms_8721D_PTR;
extern  _CheckBBRWIsStable_8721D_PTR 		   CheckBBRWIsStable_8721D_PTR;
extern  _PHY_QueryBBReg_8721D_PTR			   PHY_QueryBBReg_8721D_PTR;
extern  _PHY_SetBBReg_8721D_PTR				   PHY_SetBBReg_8721D_PTR;
extern  _ReadSECCAM_8721D_PTR    	 		   ReadSECCAM_8721D_PTR;
extern 	_WriteSECCAM_8721D_PTR   			   WriteSECCAM_8721D_PTR;
extern 	_ReadBACAM_8721D_PTR  				   ReadBACAM_8721D_PTR;
extern  _WriteBACAM_8721D_PTR  				   WriteBACAM_8721D_PTR;
extern 	_ReadMBIDCAM_8721D_PTR  			   ReadMBIDCAM_8721D_PTR;
extern 	_WriteMBIDCAM_8721D_PTR  			   WriteMBIDCAM_8721D_PTR;


//2 CMD
extern  _H2CInQueue_8721D_PTR                  H2CInQueue_8721D_PTR;
extern  _H2CDeQueue_8721D_PTR                  H2CDeQueue_8721D_PTR;
extern  _InitC2H_8721D_PTR					   InitC2H_8721D_PTR;
extern  _WaitC2HOk_8721D_PTR				   WaitC2HOk_8721D_PTR;
extern  _C2HPKTRxDESC_8721D_PTR                C2HPKTRxDESC_8721D_PTR;
extern  _FillC2HContant_8721D_PTR              FillC2HContant_8721D_PTR;
extern  _IssueC2HPKT_8721D_PTR                 IssueC2HPKT_8721D_PTR;
extern  _C2HDeQueue_8721D_PTR                  C2HDeQueue_8721D_PTR;
extern  _C2HInQueue_8721D_PTR                  C2HInQueue_8721D_PTR;
extern  _CheckMaxMacidNum_8721D_PTR			   CheckMaxMacidNum_8721D_PTR;
extern  _SetMediaStatus_8721D_PTR			   SetMediaStatus_8721D_PTR;
extern  _GetMediaStatus_8721D_PTR		       GetMediaStatus_8721D_PTR;
//3 JumpRam
extern  _H2CCmdFunc_8721D_PTR                  H2CCmdFunc_8721D_PTR;

//2 Packet
extern  _ChangeTransmiteRate_8721D_PTR         ChangeTransmiteRate_8721D_PTR;
extern  _PowerBitSetting_8721D_PTR             PowerBitSetting_8721D_PTR;
extern  _IssuePSPoll_8721D_PTR                 IssuePSPoll_8721D_PTR;
extern  _ChkandChangePS_8721D_PTR              ChkandChangePS_8721D_PTR;
extern  _IssueQNull_8721D_PTR                  IssueQNull_8721D_PTR;
extern  _CTS2SelfSetting_8721D_PTR			   CTS2SelfSetting_8721D_PTR;
extern  _IssueCTS2Self_8721D_PTR               IssueCTS2Self_8721D_PTR;
extern  _CheckCPUMGQEmpty_8721D_PTR			   CheckCPUMGQEmpty_8721D_PTR;
extern  _IssueRsvdPagePacketSetting_8721D_PTR  IssueRsvdPagePacketSetting_8721D_PTR;
extern  _ReadRxBuff_8721D_PTR                  ReadRxBuff_8721D_PTR;

//2 Powersave
extern  _SetSmartPSTimer_8721D_PTR             SetSmartPSTimer_8721D_PTR;
extern  _SetPwrStateReg_8721D_PTR              SetPwrStateReg_8721D_PTR;
extern  _ResetPSParm_8721D_PTR                 ResetPSParm_8721D_PTR;
extern  _ChkTxQueueIsEmpty_8721D_PTR		   ChkTxQueueIsEmpty_8721D_PTR;
extern  _Legacy_PS_Setting_8721D_PTR           Legacy_PS_Setting_8721D_PTR;
extern  _PSModeSetting_8721D_PTR               PSModeSetting_8721D_PTR;
extern  _ConfigListenBeaconPeriod_8721D_PTR    ConfigListenBeaconPeriod_8721D_PTR;
extern  _PSSetMode_8721D_PTR				   PSSetMode_8721D_PTR;
extern  _PS_S2ToS3State_8721D_PTR			   PS_S2ToS3State_8721D_PTR;
extern  _PS_S2ToS0State_8721D_PTR              PS_S2ToS0State_8721D_PTR;
extern  _PS_S3ToS2orS0State_8721D_PTR   	   PS_S3ToS2orS0State_8721D_PTR;
extern  _PS_S0ToS1State_8721D_PTR			   PS_S0ToS1State_8721D_PTR;
extern  _PS_S1ToS0orS2State_8721D_PTR		   PS_S1ToS0orS2State_8721D_PTR;
extern  _PS_S2ToS4State_8721D_PTR			   PS_S2ToS4State_8721D_PTR;
extern  _PS_S2ToS5State_8721D_PTR			   PS_S2ToS5State_8721D_PTR;
extern  _PS_S5ToS2State_8721D_PTR			   PS_S5ToS2State_8721D_PTR;
extern  _PS_S4ToS2State_8721D_PTR			   PS_S4ToS2State_8721D_PTR;
extern  _SmartPS2InitTimerAndToGetRxPkt_8721D_PTR	 SmartPS2InitTimerAndToGetRxPkt_8721D_PTR;
extern  _SetBcnEarlyAndTimeout_8721D_PTR       SetBcnEarlyAndTimeout_8721D_PTR;
extern  _EnlargeBcnEarlyAndTimeout_8721D_PTR   EnlargeBcnEarlyAndTimeout_8721D_PTR;
extern  _ResetBcnEarlyAdjustParm_8721D_PTR     ResetBcnEarlyAdjustParm_8721D_PTR ;
extern  _PS_S0ToS6State_8721D_PTR			   PS_S0ToS6State_8721D_PTR;
extern  _PS_S6ToS0State_8721D_PTR			   PS_S6ToS0State_8721D_PTR;
//3 Jumptoram
extern  _Change_PS_State_8721D_PTR             Change_PS_State_8721D_PTR;
extern  _PS_S2_Condition_Match_8721D_PTR       PS_S2_Condition_Match_8721D_PTR;
extern  _PS_S4_Condition_Match_8721D_PTR       PS_S4_Condition_Match_8721D_PTR;
extern  _WriteTxPauseWithMask_8721D_PTR        WriteTxPauseWithMask_8721D_PTR;
extern  _WaitTxStateMachineOk_8721D_PTR        WaitTxStateMachineOk_8721D_PTR;
extern  _WriteTxPause_8721D_PTR                WriteTxPause_8721D_PTR;
extern  _PsOpenRF_8721D_PTR                    PsOpenRF_8721D_PTR;
extern  _PsCloseRF_8721D_PTR                   PsCloseRF_8721D_PTR;
extern  _IssueNullData_8721D_PTR               IssueNullData_8721D_PTR;



//2 Wowlan
extern  _GetIV_8721D_PTR					   GetIV_8721D_PTR;
extern  _GetIVLenAndSecurityType_8721D_PTR     GetIVLenAndSecurityType_8721D_PTR;
extern  _GetMACHeaderLen_8721D_PTR             GetMACHeaderLen_8721D_PTR;
extern  _UpdateIV_8721D_PTR                    UpdateIV_8721D_PTR;
//GTK
extern  _AesTkipIvFun_8721D_PTR                AesTkipIvFun_8721D_PTR;
extern  _WepIvFun_8721D_PTR                    WepIvFun_8721D_PTR;
extern  _RTmemcmpBackward_8721D_PTR            RTmemcmpBackward_8721D_PTR ;
extern  _AssignIvToKeyRsc_8721D_PTR            AssignIvToKeyRsc_8721D_PTR;
extern  _AssignKeyRscToIV_8721D_PTR            AssignKeyRscToIV_8721D_PTR;
extern  _AesTkipIvCheck_8721D_PTR              AesTkipIvCheck_8721D_PTR ;
extern  _WepIvCheck_8721D_PTR                  WepIvCheck_8721D_PTR;
//3 Jump toram
extern  _WakeUpHost_8721D_PTR                  WakeUpHost_8721D_PTR;



//2 BT Coex
extern  _BTRoleChangeTimerHDL_8721D_PTR		BTRoleChangeTimerHDL_8721D_PTR;
extern  _BTRoleChangeTBTTHDL_8721D_PTR		BTRoleChangeTBTTHDL_8721D_PTR;
extern  _FillMailbox_8721D_PTR		FillMailbox_8721D_PTR;
extern  _WL2BTMailbox_8721D_PTR		WL2BTMailbox_8721D_PTR;
extern  _MailboxINTHDL_8721D_PTR		MailboxINTHDL_8721D_PTR;
extern  _BTMailboxRetry_8721D_PTR		BTMailboxRetry_8721D_PTR;
extern  _H2CHDL_BTInfo_8721D_PTR		H2CHDL_BTInfo_8721D_PTR;
extern  _H2CHDL_ForceBTTxpwr_8721D_PTR		H2CHDL_ForceBTTxpwr_8721D_PTR;
extern  _H2CHDL_BTIgnoreWlanAct_8721D_PTR		H2CHDL_BTIgnoreWlanAct_8721D_PTR;
extern  _H2CHDL_DACSwingValue_8721D_PTR		H2CHDL_DACSwingValue_8721D_PTR;
extern  _H2CHDL_AntSelReverse_8721D_PTR		H2CHDL_AntSelReverse_8721D_PTR;
extern  _H2CHDL_WLOpmode_8721D_PTR		H2CHDL_WLOpmode_8721D_PTR;
extern  _H2CHDL_BTMpH2C_8721D_PTR		H2CHDL_BTMpH2C_8721D_PTR;
extern  _H2CHDL_BTControl_8721D_PTR		H2CHDL_BTControl_8721D_PTR;
extern  _H2CHDL_BTWifiCtrl_8721D_PTR		H2CHDL_BTWifiCtrl_8721D_PTR;
extern  _H2CHDL_BT_Page_Scan_Interval_8721D_PTR		H2CHDL_BT_Page_Scan_Interval_8721D_PTR;
extern  _H2CHDL_WLCalibration_8721D_PTR		H2CHDL_WLCalibration_8721D_PTR;
extern  _H2CHDL_GNT_BT_CTRL_8721D_PTR		H2CHDL_GNT_BT_CTRL_8721D_PTR;
extern  _H2CHDL_BT_ONLY_TEST_8721D_PTR		H2CHDL_BT_ONLY_TEST_8721D_PTR;
extern  _H2CHDL_BT_Init_Param_8721D_PTR		H2CHDL_BT_Init_Param_8721D_PTR;
extern  _C2HBTInfo_8721D_PTR		C2HBTInfo_8721D_PTR;
extern  _C2HBTLoopback_8721D_PTR		C2HBTLoopback_8721D_PTR;
extern  _C2HBTMpRpt_8721D_PTR		C2HBTMpRpt_8721D_PTR;
extern  _C2HBTMailBoxStatus_8721D_PTR		C2HBTMailBoxStatus_8721D_PTR;
extern  _InitBTMailbox_8721D_PTR		InitBTMailbox_8721D_PTR;
extern  _InitBTypeTDMA2_8721D_PTR		InitBTypeTDMA2_8721D_PTR;
extern  _InitBTCoexTimer_8721D_PTR		InitBTCoexTimer_8721D_PTR;
extern  _Write778_8721D_PTR		Write778_8721D_PTR;
extern  _ChangeCoexTable_8721D_PTR		ChangeCoexTable_8721D_PTR;
extern  _DacSwing_8721D_PTR		DacSwing_8721D_PTR;
extern  _BTNullSetting_8721D_PTR		BTNullSetting_8721D_PTR;
extern  _IssueBTQNull_8721D_PTR		IssueBTQNull_8721D_PTR;
extern  _WlanActCtrl_8721D_PTR		WlanActCtrl_8721D_PTR;
extern  _BT_TDMA_Slot_Operation_0and3_8721D_PTR		BT_TDMA_Slot_Operation_0and3_8721D_PTR;
extern  _BT_TDMA_Slot_Operation_1and4_8721D_PTR		BT_TDMA_Slot_Operation_1and4_8721D_PTR;
extern  _BT_TDMA_Slot_Operation_2and5_8721D_PTR		BT_TDMA_Slot_Operation_2and5_8721D_PTR;
extern  _FlexibleExtensionDecision_8721D_PTR		FlexibleExtensionDecision_8721D_PTR;
extern  _BTypeTDMABCNEarly_8721D_PTR		BTypeTDMABCNEarly_8721D_PTR;
extern  _BTypeTDMATBTThdl_8721D_PTR		BTypeTDMATBTThdl_8721D_PTR;
extern  _BTypeTDMATimeOuthdl_8721D_PTR		BTypeTDMATimeOuthdl_8721D_PTR;
//3 Jump toram
extern  _BTRoleChangeDefaultSetting_8721D_PTR		BTRoleChangeDefaultSetting_8721D_PTR;
extern  _BackupAntennaSetting_8721D_PTR		BackupAntennaSetting_8721D_PTR;
extern  _MailboxINTHDL_Patch_8721D_PTR		MailboxINTHDL_Patch_8721D_PTR;
extern  _H2CHDL_BTPSTDMA_8721D_PTR			H2CHDL_BTPSTDMA_8721D_PTR;
extern  _H2CHDL_BTFwPatch_8721D_PTR			H2CHDL_BTFwPatch_8721D_PTR;

#endif  //#ifdef    __RTL8721D_INIT_C__

/*--------------------Function declaration------------------------------*/

#endif //__RTL8721D_FUNCPTR_ROM_H__
