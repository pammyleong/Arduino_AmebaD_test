#ifndef __WIFIFW_HAL_RAM_H__
#define __WIFIFW_HAL_RAM_H__

#ifndef __ASSEMBLY__

#include "wififw_init_ram.h"
#include "wififw_cmd_ram.h"
#include "wififw_packet_ram.h"
#include "wififw_powerctrl_ram.h"
#include "wififw_txreport_ram.h"
#include "wififw_interrupt_ram.h"
#include "wififw_btconcurr_ram.h"
#include "wififw_hioe_ram.h"

/*--------------------------Define -------------------------------------------*/
//2 Common Interface for each HAL
/* Func Init */
#define HALInit								HALInit_8730A
#define InitInterrupt           			InitInterrupt_8730A
#define InitCommon              				InitCommon_8730A

/* Interrupt handle function */
#define WLAN_INT_HDL        				WLAN_INT_HDL_8730A
#define FT_INT_HDL          					FT_INT_HDL_8730A
#define InitWlanIMR             				InitWlanIMR_8730A
#define InitFTIMR               				InitFTIMR_8730A
#define InitMAC2LPIntByps					InitMAC2LPIntByps_8730A
/* 2 1.) WLAN ISR */
#define ISR_TXCCX               				ISR_TXCCX_8730A
#define ISR_RxDone              				ISR_RxDone_8730A
#define ISR_H2CCMD              				ISR_H2CCMD_8730A
#define ISR_BcnEarly            			ISR_BcnEarly_8730A
#define ISR_TBTT                				ISR_TBTT_8730A
#define ISR_P0_TBTT_AGG					ISR_P0_TBTT_AGG_8730A
#define ISR_TIM_NO_HIT						ISR_TIM_NO_HIT_8730A
#define ISR_TIM_HIT							ISR_TIM_HIT_8730A
#define ISR_HIOE_CHN0						ISR_HIOE_CHN0_8730A
#define ISR_HIOE_CHN1						ISR_HIOE_CHN1_8730A
#define ISR_HIOE_CHN_ON					ISR_HIOE_CHN_ON_8730A
#define ISR_HIOE_CHN_OFF					ISR_HIOE_CHN_OFF_8730A
#define ISR_BCNRx               				ISR_BCNRx_8730A
#define ISR_BCNRxErr						ISR_BCNRxErr_8730A
#define ISR_RxBMC_MD1           			ISR_RxBMC_MD1_8730A
#define ISR_RxBMC_MD0           			ISR_RxBMC_MD0_8730A
#define ISR_RxUnicast_MD1       			ISR_RxUnicast_MD1_8730A
#define ISR_RxUnicast_MD0       			ISR_RxUnicast_MD0_8730A
#define ISR_TXBCNERR            			ISR_TXBCNERR_8730A
#define ISR_TXBCNOK             				ISR_TXBCNOK_8730A
#define ISR_TSF_GT_THRES					ISR_TSF_GT_THRES_8730A
#define ISR_RXBCN_TIMEUP					ISR_RXBCN_TIMEUP_8730A
#define ISR_RXBCN_TIMEOUT_CNT			ISR_RXBCN_TIMEOUT_CNT_8730A
#define ISR_TxPKTIn             				ISR_TxPKTIn_8730A
#define ISR_WlanActOn           			ISR_WlanActOn_8730A
#define ISR_WlanActOff          			ISR_WlanActOff_8730A
#define ISR_TxrptCntFull        			ISR_TxrptCntFull_8730A
#define ISR_TryDone             				ISR_TryDone_8730A
/* 2 1.) WLAN2 ISR */
#define ISR_TBTT1               				ISR_TBTT1_8730A
/* 2 3.) WLAN4 ISR */
#define ISR_BTScoreboard        			ISR_BTScoreboard_8730A
#define ISR_ZBMailbox           			ISR_ZBMailbox_8730A
#define ISR_GNT_BT_Rise        	 		ISR_GNT_BT_Rise_8730A
#define ISR_GNT_BT_Fall         			ISR_GNT_BT_Fall_8730A
/* 2 4.) FT ISR */
#define ISR_GTimer0           				ISR_GTimer0_8730A
#define ISR_GTimer1             				ISR_GTimer1_8730A
#define ISR_GTimer2             				ISR_GTimer2_8730A
#define ISR_GTimer3             				ISR_GTimer3_8730A
#define ISR_GTimer4             				ISR_GTimer4_8730A
#define ISR_GTimer5             				ISR_GTimer5_8730A
#define ISR_GTimer6             				ISR_GTimer6_8730A
#define ISR_RPWM                				ISR_RPWM_8730A
#define ISR_BCNERLY1            			ISR_BCNERLY1_8730A
#define ISR_BcnEarlyAGG         			ISR_BcnEarlyAGG_8730A
#define ISR_TxNull0             				ISR_TxNull0_8730A
#define ISR_TxNull1             				ISR_TxNull1_8730A

/* 3 4.) RAM func */
#define MacidDropAction         			MacidDropAction_8730A
#define MediaConnection         			MediaConnection_8730A
#define GetRPWMValue                    	GetRPWMValue_8730A
#define WaitHWStateReady                	WaitHWStateReady_8730A
#define SysClkDown                      		SysClkDown_8730A
#define SysClkUp                          	SysClkUp_8730A
#define SetTxPauseFWInfo            		SetTxPauseFWInfo_8730A
#define C2HSpeRPT								C2HSpeRPT_8730A
#define SetTxPauseDRVInfo					SetTxPauseDRVInfo_8730A
// hioe
#define SetHIOEConfigFile 				SetHIOEConfigFile_8730A
#define HIOEBackupRestore 				HIOEBackupRestore_8730A
#define CHKHigh8kTXFFPGUseOverlap 		CHKHigh8kTXFFPGUseOverlap_8730A
//lps
#define PS_32K_Condition_Match  		PS_32K_Condition_Match_8730A
#define InitPS  								InitPS_8730A
#define ChangePSStateByRPWM  			ChangePSStateByRPWM_8730A
#define PSBcnEarlyProcess 				PSBcnEarlyProcess_8730A
#define PSBcnAggEarlyProcess 			PSBcnAggEarlyProcess_8730A
#define PsBcnToProcess 					PsBcnToProcess_8730A
#define TxPktInPSOn 							TxPktInPSOn_8730A
#define PSSleepTo32K 						PSSleepTo32K_8730A
#define PSRxBcnProcess 					PSRxBcnProcess_8730A
#define LowPowerRxBeacon 					LowPowerRxBeacon_8730A
#define Set32KLpsOption 					Set32KLpsOption_8730A
#define InitBcnEarlyAdjustStat 			InitBcnEarlyAdjustStat_8730A
#define InitBcnEarlyAdjustPID 			InitBcnEarlyAdjustPID_8730A
#define LowLPSOff                       		LowLPSOff_8730A
//Sapps
#define InitSAPPS 							InitSAPPS_8730A
#define SAPPSTBTTHDL 						SAPPSTBTTHDL_8730A
#define SAPPSTimeOutHDL 					SAPPSTimeOutHDL_8730A
#define SAPPSEarlyHDL 						SAPPSEarlyHDL_8730A
#define SAPLPS 								SAPLPS_8730A
//IPS
#define InitInactivePS  					InitInactivePS_8730A
#define InactivePSTBTTHDL 				InactivePSTBTTHDL_8730A
#define InactivePSBCNAggEarlyHDL 		InactivePSBCNAggEarlyHDL_8730A
#define InactivePSEnableHEL 				InactivePSEnableHEL_8730A
//RA
#define InitCtrlInfo 						InitCtrlInfo_8730A
//Wolwan
#define InitRemoteWakeUp 					InitRemoteWakeUp_8730A
#define RemoteWakeUp 						RemoteWakeUp_8730A
#define ClearRxBuff 							ClearRxBuff_8730A
#define H2CHDL_RemoteWakeUp 				H2CHDL_RemoteWakeUp_8730A
#define KeepAliveChk 						KeepAliveChk_8730A
#define TryPKT 								TryPKT_8730A
#define GetCheckSum 								GetCheckSum_8730A
#define GetSumValue 								GetSumValue_8730A
#define UpdateCheckSumVer2 						UpdateCheckSumVer2_8730A
#define FillIpv6PseudoHeader 						FillIpv6PseudoHeader_8730A

//BTCoex
#define BTRoleChangeTimerHDL           	BTRoleChangeTimerHDL_8730A
#define BTRoleChangeTBTTHDL            	BTRoleChangeTBTTHDL_8730A
#define BTRoleChangeDefaultSetting 	BTRoleChangeDefaultSetting_8730A
#define BTC_BackupAntennaSetting    	BTC_BackupAntennaSetting_8730A
#define InitBTMailbox                  		InitBTMailbox_8730A
#define FillMailbox                    		FillMailbox_8730A
#define BT2WLMailboxINTHDL             	BT2WLMailboxINTHDL_8730A
#define BT2WLMailboxINTCheck           	BT2WLMailboxINTCheck_8730A
#define H2CHDL_BTPSTDMA                	H2CHDL_BTPSTDMA_8730A
#define BTC_PsTdmaActionDelay          	BTC_PsTdmaActionDelay_8730A
#define BTC_PsTdmaAction               	BTC_PsTdmaAction_8730A
#define H2CHDL_BTWifiCtrl              	H2CHDL_BTWifiCtrl_8730A
#define H2CHDL_WLCalibration           	H2CHDL_WLCalibration_8730A
#define H2CHDL_BT_Init_Param           	H2CHDL_BT_Init_Param_8730A
#define C2HBTInfo                      		C2HBTInfo_8730A
#define C2HWlanInfo                    		C2HWlanInfo_8730A
#define InitBTCoex                     		InitBTCoex_8730A
#define InitBTScoreboard               	InitBTScoreboard_8730A
#define BT_TDMA_Slot_Operation_0and3	BT_TDMA_Slot_Operation_0and3_8730A
#define BT_TDMA_Slot_Operation_1and4	BT_TDMA_Slot_Operation_1and4_8730A
#define BT_TDMA_Slot_Operation_2and5	BT_TDMA_Slot_Operation_2and5_8730A
#define DynamicSlotDecision            	DynamicSlotDecision_8730A
#define BTypeTDMAMultiSlots            	BTypeTDMAMultiSlots_8730A
#define BTypeTDMABCNEarly              	BTypeTDMABCNEarly_8730A
#define BTypeTDMATBTThdl               	BTypeTDMATBTThdl_8730A
#define BTypeTDMALeakAPOperation		BTypeTDMALeakAPOperation_8730A
#define BTypeTDMATimeOuthdl				BTypeTDMATimeOuthdl_8730A
#define BTC_RestoreDefaultCoexTable	BTC_RestoreDefaultCoexTable_8730A
#define BTC_PWRBitOverWrite				BTC_PWRBitOverWrite_8730A
#define BTC_PsTdmaIssueNull            	BTC_PsTdmaIssueNull_8730A
#define BTC_PsTdmaIssuePsPoll			BTC_PsTdmaIssuePsPoll_8730A
#define BTC_PsTdmaOnBcn					BTC_PsTdmaOnBcn_8730A
#define BTC_BtIqkAction                	BTC_BtIqkAction_8730A
#define BTC_BtIqkCheck                 	BTC_BtIqkCheck_8730A
#define BTC_WlanInfoCounterReset		BTC_WlanInfoCounterReset_8730A
#define BTC_ProceedBtSlot              	BTC_ProceedBtSlot_8730A
#define BTC_ProtectBCN                 	BTC_ProtectBCN_8730A
#define BTC_RestoreBtSlot              	BTC_RestoreBtSlot_8730A
#define BTC_GenRandomValue             	BTC_GenRandomValue_8730A
#define BTC_WifiRandomSlot             	BTC_WifiRandomSlot_8730A
#define IssueBTQNull                   	IssueBTQNull_8730A
#if CONFIG_BTCOEX_DEBUG
#define InitBTCoexGpioDebug            	InitBTCoexGpioDebug_8730A
#endif
#define BTC_AOACSwitch                 	BTC_AOACSwitch_8730A
//other
#define TSF_After(a,b)  					((s32)(b)-(s32)(a)<0)
#define CheckCPUMGQEmpty					CheckCPUMGQEmpty_8730A

//sw tx queue
#if CONFIG_SW_QUEUE_TX
#define InitFreeRunTSF						InitFreeRunTSF_8730A
#define GetFreeRunCnt						GetFreeRunCnt_8730A
#define GetFreeRunCntU32					GetFreeRunCntU32_8730A
#define TxPktPollMgntQ						TxPktPollMgntQ_8730A
#define CPUMGQCancelTx						CPUMGQCancelTx_8730A
#define SWQTXCheckBusyQState				SWQTXCheckBusyQState_8730A
#define IsSWQTXAllQEmpty					IsSWQTXAllQEmpty_8730A
#define PS_PreTxNull						PS_PreTxNull_8730A
#define PS_PostTxNull1						PS_PostTxNull1_8730A
#define PS_PostTxNull0						PS_PostTxNull0_8730A
#define PostTxNull							PostTxNull_8730A
#define CheckTxNullResult					CheckTxNullResult_8730A
#define SWQTXTxFeedBack					SWQTXTxFeedBack_8730A
#define SWQTXEnqueueWaitQ					SWQTXEnqueueWaitQ_8730A
#define ISR_CPUMGN_POLLED_PKT_DONE	ISR_CPUMGN_POLLED_PKT_DONE_8730A

#endif
//============================================================================
//       8730A Regsiter Bit and Content definition
//============================================================================
//WLAN PHY EN        0x0006
#define BIT_FEN_BB_GLB_RST     			BIT0
#define BIT_FEN_BB_RSTB              		BIT1
//MCUFWDL     0x0080
#define WINTINI_RDY                 			BIT6
#define RAM_DL_SEL                  			BIT7
//TXPAUSE 0x522
#define MAC_STOPBK                  			BIT0
#define MAC_STOPBE                  			BIT1
#define MAC_STOPVI                  			BIT2
#define MAC_STOPVO                  			BIT3
#define MAC_STOPMGQ                 			BIT4
#define MAC_STOPHIQ                 			BIT5
#define MAC_STOPBCNQ                		BIT6
#define MAC_STOPCPUMGQ			        	BIT7

/*------------------------Export global variable------------------------------*/

#endif  /* __ASSEMBLY__ */
#endif  /* __WIFIFW_HAL_RAM_H__ */
