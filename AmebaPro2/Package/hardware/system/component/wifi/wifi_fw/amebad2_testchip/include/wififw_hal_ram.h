#ifndef __WIFIFW_HAL_RAM_H__
#define __WIFIFW_HAL_RAM_H__

#ifndef __ASSEMBLY__

#include "wififw_init_ram.h"
#include "wififw_cmd_ram.h"
#include "wififw_phycfg_ram.h"
#include "wififw_packet_ram.h"
#include "wififw_powerctrl_ram.h"
#include "wififw_interrupt_ram.h"
#include "wififw_btconcurr_ram.h"
#include "wififw_normaldbg_ram.h"
#include "wififw_cpft_test_ram.h"
#include "wififw_hioe_ram.h"
#include "wififw_ramask_ram.h"

/*--------------------------Define -------------------------------------------*/
//Task List
#define TASK_INIT_8721D              0
#define TASK_IDLE_8721D              1
#define TASK_COMMON_8721D            2
#define TASK_PSDOffload_8721D        3
#define MAX_TASK_ID                  4


//3 Common Interface for each HAL
// Task List
#ifdef _MCU_8051_
#define TASK_INIT               TASK_INIT_8721D
#define TASK_IDLE               TASK_IDLE_8721D
#define TASK_COMMON             TASK_COMMON_8721D
#define TASK_PSDOffload         TASK_PSDOffload_8721D
#else
#define TASK_INIT
#define TASK_IDLE
#define TASK_COMMON
#define TASK_PSDOffload
#endif

//#define RAM_VERSION             RTL8721D_FW_VERSION //not yet at once
//#define RAM_SUBVERSION          RTL8721D_FW_SUBVERSION //not yet at once

//2 sysreg access
#define SYSTEM_CTRL_BASE_LPPMC_OFFSET    0x00000200

//1 DDMA access base
//3 MAC base address
#define RTL8721D_IOREG_DDMA_AXI_BASE			0x40000000
//3 BB base address
#define RTL8721D_BBREG_DDMA_AXI_BASE             	0x40000800
//3 RF base address
#define RTL8721D_RFREG_DDMA_AXI_BASE             	0x40003800
//3 DDMA control base address
#define RTL8721D_DDMA_CTRL_DDMA_AXI_BASE         	0x40000000 //0x4000_1200- 0x4000_12FF
//3 BT mailbox base address
#define RTL8721D_BT_MAILBOX_DDMA_AXI_BASE        	0x400011A4
//3 LLT Table base
#define RTL8721D_LLT_DDMA_AXI_BASE			0x40050000//256 byte/entry

//3 TxReport Buffer base address
#define RTL8721D_RPTBUF_DDMA_AXI_BASE            	0x40040000
#define RTL8721D_CtrlInfo_DDMA_AXI_BASE          	(RTL8721D_RPTBUF_AHB_BASE)
#define RTL8721D_TRXRPT_DDMA_AXI_BASE            	(RTL8721D_RPTBUF_AHB_BASE + 0x280)
#define RTL8721D_CRC5_DDMA_AXI_BASE              	(RTL8721D_RPTBUF_AHB_BASE + 0xA80)
#define RTL8721D_NANRPT_DDMA_AXI_BASE                	(RTL8721D_RPTBUF_AHB_BASE + 0xA90)

//3 Rx packet buffer base address
#define RTL8721D_RXFF_DDMA_AXI_BASE              	0x40030000

//3 Tx packet buffer base address
#define RTL8721D_TXFF_DDMA_AXI_BASE              	0x40010000

//3 CAM base address
#define RTL8721D_SECCAM_DDMA_AXI_BASE            	0x40050800
#define RTL8721D_BACAM_DDMA_AXI_BASE             	0x40051000
#define RTL8721D_MBIDCAM_DDMA_AXI_BASE 			0x40051800


// HAL Init
#define HALInit                 HALInit_8721D
//#define InterfaceDecision       InterfaceDecision_8721D_ROM //not yet at once
#define InitInterrupt           InitInterrupt_8721D
//#define MCUINTEnable            MCUINTEnable_8721D_ROM //not yet at once

// InitCommon
#define InitCommon              InitCommon_8721D

// Interrupt handle function
#define WLAN_INT_HDL_RAM        WLAN_INT_HDL_RAM_8721D
#define FT_INT_HDL_RAM          FT_INT_HDL_RAM_8721D
#define InitWlanIMR             InitWlanIMR_8721D
#define InitFTIMR               InitFTIMR_8721D

//3 2.) WLAN ISR
//#define ISR_TxClose             ISR_TxClose_8721D //not yet at once
#define ISR_TXCCX               ISR_TXCCX_8721D
#define ISR_RxDone              ISR_RxDone_8721D
#define ISR_H2CCMD              ISR_H2CCMD_8721D
#define ISR_HRCV                ISR_HRCV_8721D
//#define ISR_CTWEnd              ISR_CTWEnd_8721D //not yet at once
#define ISR_BcnEarly            ISR_BcnEarly_8721D
#define ISR_TBTT                ISR_TBTT_8721D
#define ISR_BCNRx               ISR_BCNRx_8721D
#define ISR_RxBMC_MD1           ISR_RxBMC_MD1_8721D
#define ISR_RxBMC_MD0           ISR_RxBMC_MD0_8721D
#define ISR_RxUnicast_MD1       ISR_RxUnicast_MD1_8721D
#define ISR_RxUnicast_MD0       ISR_RxUnicast_MD0_8721D
#define ISR_TXBCNERR            ISR_TXBCNERR_8721D
#define ISR_TXBCNOK             ISR_TXBCNOK_8721D
#define ISR_TxPKTIn             ISR_TxPKTIn_8721D
#define ISR_WlanActOn           ISR_WlanActOn_8721D
#define ISR_WlanActOff          ISR_WlanActOff_8721D
#define ISR_TxrptCntFull        ISR_TxrptCntFull_8721D
//#define ISR_SoundDone           ISR_SoundDone_8721D //not yet at once
#if CONFIG_SW_QUEUE_TX
#define ISR_CPUMGN_POLLED_PKT_DONE		ISR_CPUMGN_POLLED_PKT_DONE_8721D
#endif
//3 2.1) WLAN2 ISR
#define ISR_EQTxOK              ISR_EQTxOK_8721D
#define ISR_SyncBcnRxOK         ISR_SyncBcnRxOK_8721D
#define ISR_DWEarly                 ISR_DWEarly_8721D
#define ISR_DWEnd                   ISR_DWEnd_8721D
#define ISR_EQEarly                 ISR_EQEarly_8721D
#define ISR_TBTT1               ISR_TBTT1_8721D

//3 2.2) WLAN4 ISR
#define ISR_BTScoreboard        ISR_BTScoreboard_8730A
#define ISR_ZBMailbox           ISR_ZBMailbox_8730A
#define ISR_GNT_BT_Rise         ISR_GNT_BT_Rise_8730A
#define ISR_GNT_BT_Fall         ISR_GNT_BT_Fall_8730A

//3 3.) FT ISR
//#define ISR_GTimer0             ISR_GTimer0_8721D
#define ISR_GTimer1             ISR_GTimer1_8721D
#define ISR_GTimer2             ISR_GTimer2_8721D
#define ISR_GTimer3             ISR_GTimer3_8721D
#define ISR_GTimer4             ISR_GTimer4_8721D
#define ISR_GTimer5             ISR_GTimer5_8721D
#define ISR_GTimer6             ISR_GTimer6_8721D
//#define ISR_TimerOut0           ISR_TimerOut0_8721D //not yet at once
#define ISR_RPWM                ISR_RPWM_8721D
#define ISR_RPWM2               ISR_RPWM2Common
#define ISR_EOSP                ISR_EOSP_8721D
#define ISR_BCNERLY1            ISR_BCNERLY1_8721D
//#define ISR_P2PRFOn             ISR_P2PRFOn_8721D //not yet at once
//#define ISR_P2PRFOff            ISR_P2PRFOff_8721D //not yet at once
#define ISR_TRIGGER_PKT         ISR_TRIGGER_PKT_8721D
#define ISR_TSF_BIT32_TOGGLE    ISR_TSF_BIT32_TOGGLECommon
#define ISR_RETRIVE_BUFFERED    ISR_RETRIVE_BUFFERED_8721D
#define ISR_CLR_PS_STATUS       ISR_CLR_PS_STATUS_8721D
#define ISR_BcnEarlyAGG         ISR_BcnEarlyAGG_8721D
#define ISR_TxNull0             ISR_TxNull0_8721D
#define ISR_TxNull1             ISR_TxNull1_8721D
//3 4.) RAM func
#define PHY_InitBBRFRegDef              PHY_InitBBRFRegDef_8721D

//ODM
#define RateDecision            phydm_ratedecision
#define InitRAInfo              phydm_init_rainfo
#define ArfrRefresh             phydm_arfrrefresh
#define Init_DM                 ODM_Init_DM
#define CheckTryDone            phydm_checktrydone
#define FWIQK                   ODM_IQK_Offload
#define DrvIQKBackupAll         ODM_IQK_backup_all
//#define ReloadIQK               ODM_IQK_ReloadIQK
#define ReloadIQKAll            ODM_IQK_ReloadIQK_All
#define FWPowerTracking         ODM_PowerTracking
#define FWPSD                   ODM_PSD

#if CONFIG_RA_FPGA_DEBUG
#define PsuseTxrpt                      PsuseTxrpt_8721D //not yet at once
#define ResetTxrpt                      ResetTxrpt_8721D //not yet at once
#endif
#define CheckH2CMailbox         CheckH2CMailboxCommon
#define C2HExtInQueue           C2HExtInQueueCommon
#define C2HExtDeQueue           C2HExtDeQueueCommon
#define MacidDropAction         MacidDropActionCommon
#define MediaConnection         MediaConnectionCommon
#define MediaDisconnection      MediaDisconnectionCommon
#define GetOccupyTxInd                  GetOccupyTxIndCommon
#define GetRPWMValue                    GetRPWMValueCommon
#define GetRPWM2Value                   GetRPWMValue2Common
#define CheckTSFIsStable                CheckTSFIsStableCommon
#define WaitHWStateReady                WaitHWStateReadyCommon
#define SysClkDown                      SysClkDown_8721D
#define SysClkUp                          SysClkUp_8721D
#define SetTxPauseFWInfo            SetTxPauseFWInfo_8721D
#define PHY_QueryRFRegRAM               PHY_QueryRFReg_8721D_RAM
#define PHY_SetRFRegRAM                 PHY_SetRFReg_8721D_RAM
#define PHY_RFSerialReadRAM         PHY_RFSerialRead_8721D_RAM
#define PHY_RFSerialWriteRAM        PHY_RFSerialWrite_8721D_RAM
#undef PHY_RFSerialRead
#undef PHY_RFSerialWrite
#define PHY_RFSerialRead                PHY_RFSerialRead_8721D_RAM
#define PHY_RFSerialWrite               PHY_RFSerialWrite_8721D_RAM

#undef PHY_QueryRFReg
#define PHY_QueryRFReg                  PHY_QueryRFReg_8721D_RAM
#define PHY_SetRFReg                    PHY_SetRFReg_8721D_RAM

#define BcnEarlyAdjustByTSF             BcnEarlyAdjustByTSF_8721D
#define TSF_After(a,b)  ((s32)(b)-(s32)(a)<0)
#define LowLPSOff                       LowLPSOff_8721D
//sw tx queue
#if CONFIG_SW_QUEUE_TX
#define InitFreeRunTSF						InitFreeRunTSF_8721D_RAM
#define GetFreeRunCnt						GetFreeRunCnt_8721D_RAM
#define GetFreeRunCntU32					GetFreeRunCntU32_8721D_RAM
#define TxPktPollMgntQ						TxPktPollMgntQ_8721D_RAM
#define CPUMGQCancelTx						CPUMGQCancelTx_8721D_RAM
#define SWQTXCheckBusyQState				SWQTXCheckBusyQState_8721D_RAM
#define IsSWQTXAllQEmpty					IsSWQTXAllQEmpty_8721D_RAM
#define PS_PreTxNull						PS_PreTxNull_8721D_RAM
#define PS_PostTxNull1						PS_PostTxNull1_8721D_RAM
#define PS_PostTxNull0						PS_PostTxNull0_8721D_RAM
#define PostTxNull							PostTxNull_8721D_RAM
#define CheckTxNullResult					CheckTxNullResult_8721D_RAM
#define SWQTXTxFeedBack					SWQTXTxFeedBack_8721D_RAM
#define SWQTXEnqueueWaitQ					SWQTXEnqueueWaitQ_8721D_RAM

#endif

//BTCOEX
#define FillMailboxNew                  FillMailboxNew_8730A
#define WL2BTMailboxSend                WL2BTMailboxSend_8730A
#define BT2WLMailboxINTHDL              BT2WLMailboxINTHDL_8730A
#define BT2WLMailboxINTCheck            BT2WLMailboxINTCheck_8730A
#define TdmaChangeCoexTable             TdmaChangeCoexTable_8730A
#define DynamicSlotDecision	            DynamicSlotDecision_8730A
#define BTypeTDMABCNEarlyNew            BTypeTDMABCNEarlyNew_8730A
#define BTypeTDMATBTThdlNew             BTypeTDMATBTThdlNew_8730A
#define H2CHDL_WL_Port_ID               H2CHDL_WL_Port_ID_8730A
#define BTRoleChangeDefaultSettingNew   BTRoleChangeDefaultSettingNew_8730A
#define BTC_BackupAntennaSettingNew     BTC_BackupAntennaSettingNew_8730A
#define H2CHDL_BTPSTDMANew              H2CHDL_BTPSTDMANew_8730A
#define BTC_PsTdmaActionDelay           BTC_PsTdmaActionDelay_8730A
#define BTC_PsTdmaAction                BTC_PsTdmaAction_8730A
#define C2HWlanInfo                     C2HWlanInfo_8730A
#define InitBTCoex                      InitBTCoex_8730A
#define InitBTScoreboard                InitBTScoreboard_8730A
#define BTypeTDMAMultiSlots             BTypeTDMAMultiSlots_8730A
#define BTypeTDMALeakAPOperation        BTypeTDMALeakAPOperation_8730A
#define BTC_RestoreDefaultCoexTable     BTC_RestoreDefaultCoexTable_8730A
#define BTC_PWRBitOverWrite             BTC_PWRBitOverWrite_8730A
#define BTC_PsTdmaIssueNull             BTC_PsTdmaIssueNull_8730A
#define BTC_PsTdmaIssuePsPoll           BTC_PsTdmaIssuePsPoll_8730A
#define BTC_PsTdmaOnBcn                 BTC_PsTdmaOnBcn_8730A
#define BTC_BtIqkAction                 BTC_BtIqkAction_8730A
#define BTC_BtIqkCheck                  BTC_BtIqkCheck_8730A
#define BTC_WlanInfoCounterReset        BTC_WlanInfoCounterReset_8730A
#define BTC_ProceedBtSlot               BTC_ProceedBtSlot_8730A
#define BTC_ProtectBCN                  BTC_ProtectBCN_8730A
#define BTC_RestoreBtSlot               BTC_RestoreBtSlot_8730A
#define BTC_GenRandomValue              BTC_GenRandomValue_8730A
#define BTC_WifiRandomSlot              BTC_WifiRandomSlot_8730A
#define InitBTCoexGpioDebug             InitBTCoexGpioDebug_8730A
#define BTC_AOACSwitch                  BTC_AOACSwitch_8730A

//lpssyson
#define WriteLSONDWord(offset, value)        rtl_outl((offset+RTL8721D_LPSYSON_AHB_BASE), value)
#define WriteLSONWord(offset, value)         rtl_outw((offset+RTL8721D_LPSYSON_AHB_BASE), value)
#define WriteLSONByte(offset, value)         rtl_outb((offset+RTL8721D_LPSYSON_AHB_BASE), value)

#define ReadLSONDWord(offset)                (rtl_inl((offset+RTL8721D_LPSYSON_AHB_BASE)))
#define ReadLSONWord(offset)                 (rtl_inw((offset+RTL8721D_LPSYSON_AHB_BASE)))
#define ReadLSONByte(offset)                 (rtl_inb((offset+RTL8721D_LPSYSON_AHB_BASE)))

/*------------------------------Define Enum-----------------------------------*/


/*--------------------------Define MACRO--------------------------------------*/
#if 1

//-----------------------------------------------------
//
//  0x0800h ~ 0x0FFFh   BB Control Register setting
//
//-----------------------------------------------------
#define REG_RFE_INV                 0x092C
#define REG_RFE_CTRL89              0x0930
#define REG_RFE_SWCTRL              0x0948
#define REG_R_RFE_SEL01             0x0CB0
#define REG_R_RFE_SEL89             0x0CB4


//============================================================================
//       8721D Regsiter Bit and Content definition
//============================================================================
//-----------------------------------------------------
//
//  0x0000h ~ 0x00FFh   System Configuration
//
//-----------------------------------------------------
//2 SPS0_CTRL
#define SW18_FPWM                   BIT3

//2 SYS_ISO_CTRL
#define ISO_MD2PP                   BIT0
#define ISO_UA2USB                  BIT1
#define ISO_UD2CORE                 BIT2
#define ISO_PA2PCIE                 BIT3
#define ISO_PD2CORE                 BIT4
#define ISO_IP2MAC                  BIT5
#define ISO_DIOP                    BIT6
#define ISO_DIOE                    BIT7
#define ISO_EB2CORE                 BIT8
#define ISO_DIOR                    BIT9
#define UA12PC_EN                   BIT10   // For RTL8723 only.
#define UA33PC_EN                   BIT11   // For RTL8723 only.
#define PA12PC_EN                   BIT12   // For RTL8723 only.
#define PA33PC_EN                   BIT13   // For RTL8723 only.
#define PWC_EV25V                   BIT14
#define PWC_EV12V                   BIT15


//2 SYS_FUNC_EN
#define FEN_BBRSTB                  BIT0
#define FEN_BB_GLB_RSTn             BIT1
#define FEN_USBA                    BIT2
#define FEN_UPLL                    BIT3
#define FEN_USBD                    BIT4
#define FEN_DIO_PCIE                BIT5
#define FEN_PCIEA                   BIT6
#define FEN_PPLL                    BIT7
#define FEN_PCIED                   BIT8
#define FEN_DIOE                    BIT9
#define FEN_CPUEN                   BIT10
#define FEN_DCORE                   BIT11
#define FEN_ELDR                    BIT12
#define FEN_DIO_RF                  BIT13
#define FEN_HWPDN                   BIT14
#define FEN_MREGEN                  BIT15

//2 APS_FSMCO
#define PFM_LDALL                   BIT0
#define PFM_ALDN                    BIT1
#define PFM_LDKP                    BIT2
#define PFM_WOWL                    BIT3
#define EnPDN                       BIT4
#define PDN_PL                      BIT5
#define APFM_ONMAC                  BIT8
#define APFM_OFF                    BIT9
#define APFM_RSM                    BIT10
#define AFSM_HSUS                   BIT11
#define AFSM_PCIE                   BIT12
#define APDM_MAC                    BIT13
#define APDM_HOST                   BIT14
#define APDM_HPDN                   BIT15
#define RDY_MACON                   BIT16
#define SUS_HOST                    BIT17
#define ROP_ALD                     BIT20
#define ROP_PWR                     BIT21
#define ROP_SPS                     BIT22
#define SOP_MRST                    BIT25
#define SOP_FUSE                    BIT26
#define SOP_ABG                     BIT27
#define SOP_AMB                     BIT28
#define SOP_RCK                     BIT29
#define SOP_A8M                     BIT30
#define XOP_BTCK                    BIT31

//2 SYS_CLKR
#define ANAD16V_EN                  BIT0
#define ANA8M                       BIT1
#define MACSLP                      BIT4
#define LOADER_CLK_EN               BIT5
#define _80M_SSC_DIS                BIT7
#define _80M_SSC_EN_HO              BIT8
#define PHY_SSC_RSTB                BIT9
#define SEC_CLK_EN                  BIT10
#define MAC_CLK_EN                  BIT11
#define SYS_CLK_EN                  BIT12
#define RING_CLK_EN                 BIT13
#define CPU_CLK_EN                  BIT14

//2 9346CR

#define     BOOT_FROM_EEPROM        BIT4
#define     EEPROM_EN               BIT5

//2 AFE_MISC
#define AFE_BGEN                    BIT0
#define AFE_MBEN                    BIT1
#define MAC_ID_EN                   BIT7

//2 RSV_CTRL
#define WLOCK_ALL                   BIT0
#define WLOCK_00                    BIT1
#define WLOCK_04                    BIT2
#define WLOCK_08                    BIT3
#define WLOCK_40                    BIT4
#define R_DIS_PRST_0                BIT5
#define R_DIS_PRST_1                BIT6
#define LOCK_ALL_EN                 BIT7

//2 RF_CTRL
#define RF_EN                       BIT0
#define RF_RSTB                     BIT1
#define RF_SDMRSTB                  BIT2

//2 LDOA15_CTRL
#define LDA15_EN                    BIT0
#define LDA15_STBY                  BIT1
#define LDA15_OBUF                  BIT2
#define LDA15_REG_VOS               BIT3
#define _LDA15_VOADJ(x)             (((x) & 0x7) << 4)

//2 LDOV12D_CTRL
#define LDV12_EN                    BIT0
#define LDV12_SDBY                  BIT1
#define LPLDO_HSM                   BIT2
#define LPLDO_LSM_DIS               BIT3
#define _LDV12_VADJ(x)              (((x) & 0xF) << 4)


//2 AFE_XTAL_CTRL
#define XTAL_EN                     BIT0
#define XTAL_BSEL                   BIT1
#define _XTAL_BOSC(x)               (((x) & 0x3) << 2)
#define _XTAL_CADJ(x)               (((x) & 0xF) << 4)
#define XTAL_GATE_USB               BIT8
#define _XTAL_USB_DRV(x)            (((x) & 0x3) << 9)
#define XTAL_GATE_AFE               BIT11
#define _XTAL_AFE_DRV(x)            (((x) & 0x3) << 12)
#define XTAL_RF_GATE                BIT14
#define _XTAL_RF_DRV(x)             (((x) & 0x3) << 15)
#define XTAL_GATE_DIG               BIT17
#define _XTAL_DIG_DRV(x)            (((x) & 0x3) << 18)
#define XTAL_BT_GATE                BIT20
#define _XTAL_BT_DRV(x)             (((x) & 0x3) << 21)
#define _XTAL_GPIO(x)               (((x) & 0x7) << 23)


#define CKDLY_AFE                   BIT26
#define CKDLY_USB                   BIT27
#define CKDLY_DIG                   BIT28
#define CKDLY_BT                    BIT29


//2 AFE_PLL_CTRL
#define APLL_EN                     BIT0
#define APLL_320_EN                 BIT1
#define APLL_FREF_SEL               BIT2
#define APLL_EDGE_SEL               BIT3
#define APLL_WDOGB                  BIT4
#define APLL_LPFEN                  BIT5

#define APLL_REF_CLK_13MHZ          0x1
#define APLL_REF_CLK_19_2MHZ        0x2
#define APLL_REF_CLK_20MHZ          0x3
#define APLL_REF_CLK_25MHZ          0x4
#define APLL_REF_CLK_26MHZ          0x5
#define APLL_REF_CLK_38_4MHZ        0x6
#define APLL_REF_CLK_40MHZ          0x7

#define APLL_320EN                  BIT14
#define APLL_80EN                   BIT15
#define APLL_1MEN                   BIT24


//2 EFUSE_CTRL
#define ALD_EN                      BIT18
#define EF_PD                       BIT19
#define EF_FLAG                     BIT31

//2 EFUSE_TEST (For RTL8723 partially)
#define EF_TRPT                     BIT7
#define EF_CELL_SEL                 (BIT8|BIT9) // 00: Wifi Efuse, 01: BT Efuse0, 10: BT Efuse1, 11: BT Efuse2
#define LDOE25_EN                   BIT31
#define EFUSE_SEL(x)                (((x) & 0x3) << 8)
#define EFUSE_SEL_MASK              0x300
#define EFUSE_WIFI_SEL_0            0x0
#define EFUSE_BT_SEL_0              0x1
#define EFUSE_BT_SEL_1              0x2
#define EFUSE_BT_SEL_2              0x3

#define EFUSE_ACCESS_ON             0x69    // For RTL8723 only.
#define EFUSE_ACCESS_OFF            0x00    // For RTL8723 only.

//2 ACLK_MON
#define RSM_EN                      BIT0
#define Timer_EN                    BIT4


//2 GPIO_MUXCFG
#define TRSW0EN                     BIT2
#define TRSW1EN                     BIT3
#define EROM_EN                     BIT4
#define EnBT                        BIT5
#define EnUart                      BIT8
#define Uart_910                    BIT9
#define EnPMAC                      BIT10
#define SIC_SWRST                   BIT11
#define EnSIC                       BIT12
#define SIC_23                      BIT13
#define EnHDP                       BIT14
#define SIC_LBK                     BIT15

//2 LEDCFG
#define LED0PL                      BIT4
#define LED1PL                      BIT12
#define LED0DIS                     BIT7


//2 FSIMR
//2 FSISR
#define SYSINT_GPIO0_SHT            4//12
#define SYSINT_GPIO1_SHT            5//13
#define SYSINT_GPIO2_SHT            6//14
#define SYSINT_GPIO3_SHT            7//15

#define SYSINT_GPIO4_SHT            0//16
#define SYSINT_GPIO5_SHT            1//17
#define SYSINT_GPIO6_SHT            2//18
#define SYSINT_GPIO7_SHT            3//19
#define SYSINT_GPIO8_SHT            4//20
#define SYSINT_GPIO9_SHT            5//21
#define SYSINT_GPIOA_SHT            6//22
#define SYSINT_GPIOB_SHT            7//23

#define SYSINT_HPON_WRE_SHT         4//28   
#define SYSINT_SPS_OCP_SHT          5//29
#define SYSINT_HWSYS_TIMER_SHT      6//30
#define SYSINT_PDNINT_SHT           7//31


#define SYSINT_GPIO0INT             BIT(SYSINT_GPIO0_SHT)
#define SYSINT_GPIO1INT             BIT(SYSINT_GPIO1_SHT)
#define SYSINT_GPIO2INT             BIT(SYSINT_GPIO2_SHT)
#define SYSINT_GPIO3INT             BIT(SYSINT_GPIO3_SHT)

#define SYSINT_GPIO4INT             BIT(SYSINT_GPIO4_SHT)
#define SYSINT_GPIO5INT             BIT(SYSINT_GPIO5_SHT)
#define SYSINT_GPIO6INT             BIT(SYSINT_GPIO6_SHT)
#define SYSINT_GPIO7INT             BIT(SYSINT_GPIO7_SHT)
#define SYSINT_GPIO8INT             BIT(SYSINT_GPIO8_SHT)
#define SYSINT_GPIO9INT             BIT(SYSINT_GPIO9_SHT)
#define SYSINT_GPIOAINT             BIT(SYSINT_GPIOA_SHT)

#define SYSINT_HPON_WRE             BIT(SYSINT_HPON_WRE_SHT)
#define SYSINT_SPS_OCP              BIT(SYSINT_SPS_OCP_SHT)
#define SYSINT_HWSYS_TIMER          BIT(SYSINT_HWSYS_TIMER_SHT)
#define SYSINT_PDNINT               BIT(SYSINT_PDNINT_SHT)

//2 WLAN PHY EN        0x0006
#define BIT_FEN_BB_GLB_RST     BIT0
#define BIT_FEN_BB_RSTB              BIT1

//2WLAN RF EN       0x0007
#define BIT_RF_EN           BIT0
#define BIT_RF_RSTB         BIT1
#define BIT_RF_SDMRSTB      BIT2

//2 MCUFWDL     0x0080
#define MCUFWDL_EN                  BIT0
#define MCUFWDL_RDY                 BIT1
#define MCUFWDL_CHK_RPT             BIT2

#define WINTINI_RDY                 BIT6
#define RAM_DL_SEL                  BIT7


#define MCU_ROM_INITIAL_READY       BIT2    //10

#define ROMDLFW_EN                  BIT3    //11    
#define FWDL2TXBUF_RDY              BIT4    //12
#define MCUFWDL_DMA_EN      BIT5    //13

#define ROM_DLEN                    BIT3    //19
#define CPRST                       BIT7    //23

//2 REG_USB_SIE_INTF        0x00E0
#define USB2_SIE_READ               0x01
#define USB2_SIE_WRITE              0x03
#define USB3_SIE_READ               0x40
#define USB3_SIE_WRITE              0x42
#define USB_WRITE_END               BIT0
#define USB_SIE_INTF_WE             BIT1


//2 REG_PCIE_MIO_INTF       0x00E4
#define PCIE_MIO_WRITE              0x20
#define PCIE_MIO_READ               0x30


//2 REG_PCIE_MIO_INTD       0x00E8


//2 REG_HPON_FSM
#define BOND92CE_1T2R_CFG           BIT22


//2 REG_SYS_CFG
#define XCLK_VLD                    BIT0
#define ACLK_VLD                    BIT1
#define UCLK_VLD                    BIT2
#define PCLK_VLD                    BIT3
#define PCIRSTB                     BIT4
#define V15_VLD                     BIT5

#define INIT_OFFLOAD_ROM_EN         BIT7
#define SIC_IDLE                    BIT8
#define BD_MAC2                     BIT9
#define BD_MAC1                     BIT10
#define IC_MACPHY_MODE              BIT11
#define CHIP_VER                    (BIT12|BIT13|BIT14|BIT15)
#define BT_FUNC                     BIT16
#define VENDOR_ID                   BIT19
#define PAD_HWPD_IDN                BIT22
#define TRP_VAUX_EN                 BIT23   // RTL ID
#define TRP_BT_EN                   BIT24
#define BD_PKG_SEL                  BIT25
#define BD_HCI_SEL                  BIT26
#define TYPE_ID                     BIT27

#define CHIP_VER_RTL_MASK           0xF000  //Bit 12 ~ 15
#define CHIP_VER_RTL_SHIFT          12

//2REG_GPIO_OUTSTS (For RTL8723 only)
//2 REG_SYS_STATUS_RPT
#define EFS_HCI_SEL                 (BIT0|BIT1)
#define PAD_HCI_SEL                 (BIT2|BIT3)
#define HCI_SEL                     (BIT4|BIT5) //8723BA
#define PKG_SEL_HCI                 BIT6
#define FEN_GPS                     BIT7
#define FEN_BT                      BIT8
#define FEN_WL                      BIT9
#define FEN_PCI                     BIT10
#define FEN_USB                     BIT11
#define BTRF_HWPDN_N                BIT12
#define WLRF_HWPDN_N                BIT13
#define PDN_BT_N                    BIT14
#define PDN_GPS_N                   BIT15
#define BT_CTL_HWPDN                BIT16
#define GPS_CTL_HWPDN               BIT17
#define PPHY_SUSB                   BIT20
#define UPHY_SUSB                   BIT21
#define PCI_SUSEN                   BIT22
#define USB_SUSEN                   BIT23

#define RF_RL_ID                    (BIT31|BIT30|BIT29|BIT28)
#define TRAP_PKG_SEL                BIT5

//2 REG_USB_CFG
#define USB2_SEL                    BIT7
//-----------------------------------------------------
//
//  0x0100h ~ 0x01FFh   MACTOP General Configuration
//
//-----------------------------------------------------

//2 Function Enable Registers


// Network type
#define _NETTYPE(x)                 (((x) & 0x3) << 16)
#define MASK_NETTYPE                0x30000
#define NT_NO_LINK                  0x0
#define NT_LINK_AD_HOC              0x1
#define NT_LINK_AP                  0x2
#define NT_AS_AP                    0x3

#define _LBMODE(x)                  (((x) & 0xF) << 24)
#define MASK_LBMODE                 0xF000000
#define LOOPBACK_NORMAL             0x0
#define LOOPBACK_IMMEDIATELY        0xB
#define LOOPBACK_MAC_DELAY          0x3
#define LOOPBACK_PHY                0x1
#define LOOPBACK_DMA                0x7


//2 PLAYFORM_CLOCK Register 0x0109
#define CLK_STABLE_32K              BIT7        // 1: 32K Stable, 0: 40M Stable

//2 PBP - Page Size Register
#define GET_RX_PAGE_SIZE(value)     ((value) & 0xF)
#define GET_TX_PAGE_SIZE(value)     (((value) & 0xF0) >> 4)
#define _PSRX_MASK                  0xF
#define _PSTX_MASK                  0xF0
#define _PSRX(x)                    (x)
#define _PSTX(x)                    ((x) << 4)

#define PBP_64                      0x0
#define PBP_128                     0x1
#define PBP_256                     0x2
#define PBP_512                     0x3
#define PBP_1024                    0x4


//2 TX/RXDMA
#define RXDMA_ARBBW_EN              BIT0
#define RXSHFT_EN                   BIT1
#define RXDMA_AGG_EN                BIT2
#define QS_VO_QUEUE                 BIT8
#define QS_VI_QUEUE                 BIT9
#define QS_BE_QUEUE                 BIT10
#define QS_BK_QUEUE                 BIT11
#define QS_MANAGER_QUEUE            BIT12
#define QS_HIGH_QUEUE               BIT13

#define HQSEL_VOQ                   BIT0
#define HQSEL_VIQ                   BIT1
#define HQSEL_BEQ                   BIT2
#define HQSEL_BKQ                   BIT3
#define HQSEL_MGTQ                  BIT4
#define HQSEL_HIQ                   BIT5

// For normal driver, 0x10C
#define _TXDMA_HIQ_MAP(x)           (((x)&0x3) << 14)
#define _TXDMA_MGQ_MAP(x)           (((x)&0x3) << 12)
#define _TXDMA_BKQ_MAP(x)           (((x)&0x3) << 10)
#define _TXDMA_BEQ_MAP(x)           (((x)&0x3) << 8 )
#define _TXDMA_VIQ_MAP(x)           (((x)&0x3) << 6 )
#define _TXDMA_VOQ_MAP(x)           (((x)&0x3) << 4 )

#define QUEUE_LOW                   1
#define QUEUE_NORMAL                2
#define QUEUE_HIGH                  3


//2 LLT_INIT
#define _LLT_NO_ACTIVE              0x00
#define _LLT_WRITE_ACCESS           0x40
#define _LLT_READ_ACCESS            0x80

#define _LLT_INIT_DATA(x)           ((x) & 0xFF)
#define _LLT_INIT_ADDR(x)           (((x) & 0xFF) << 8)
#define _LLT_OP(x)                  (((x) & 0x3) << 30)
#define _LLT_OP_VALUE(x)            (((x) >> 30) & 0x3)


//2 BB_ACCESS_CTRL
#define BB_WRITE_READ_MASK          (BIT31 | BIT30)
#define BB_WRITE_EN                 BIT30
#define BB_READ_EN                  BIT31

//-----------------------------------------------------
//
//  0x0200h ~ 0x027Fh   TXDMA Configuration
//
//-----------------------------------------------------
//2 RQPN
#define _HPQ(x)                     ((x) & 0xFF)
#define _LPQ(x)                     (((x) & 0xFF) << 8)
#define _PUBQ(x)                    (((x) & 0xFF) << 16)
#define _NPQ(x)                     ((x) & 0xFF)            // NOTE: in RQPN_NPQ register


#define HPQ_PUBLIC_DIS              BIT24
#define LPQ_PUBLIC_DIS              BIT25
#define LD_RQPN                     BIT31


//2 TDECTRL
#define BCN_VALID                   BIT16
#define BCN_HEAD(x)                 (((x) & 0xFF) << 8)
#define BCN_HEAD_MASK               0xFF00

//2 TDECTL
#define BLK_DESC_NUM_SHIFT          4
#define BLK_DESC_NUM_MASK           0xF


//2 TXDMA_OFFSET_CHK
#define DROP_DATA_EN                BIT9



//-----------------------------------------------------
//
//  0x0300h ~ 0x03FFh   PCIE
//
//-----------------------------------------------------
//2  REG_DBI_CTRL                   0x0350

//2 REG_DBI_RWCMD               0x0352
#define DBI_WRITE                   BIT0
#define DBI_READ                    BIT1


//2 REG_MDIO_CTRL               0x0358
#define MDIO_PCIE_READ              BIT6
#define MDIO_PCIE_WRITE             BIT5

//-----------------------------------------------------
//
//  0x0400h ~ 0x047Fh   Protocol Configuration
//
//-----------------------------------------------------

//2 FWHW_TXQ_CTRL
#define EN_AMPDU_RTY_NEW            BIT7

//2 INIRTSMCS_SEL
#define _INIRTSMCS_SEL(x)           ((x) & 0x3F)

//2 SPEC SIFS
#define _SPEC_SIFS_CCK(x)           ((x) & 0xFF)
#define _SPEC_SIFS_OFDM(x)          (((x) & 0xFF) << 8)


//2 RRSR

#define RATE_REG_BITMAP_ALL         0xFFFFF

#define _RRSC_BITMAP(x)             ((x) & 0xFFFFF)

#define _RRSR_RSC(x)                (((x) & 0x3) << 21)
#define RRSR_RSC_RESERVED           0x0
#define RRSR_RSC_UPPER_SUBCHANNEL   0x1
#define RRSR_RSC_LOWER_SUBCHANNEL   0x2
#define RRSR_RSC_DUPLICATE_MODE     0x3


//2 ARFR
#define USE_SHORT_G1                BIT20

//2 AGGLEN_LMT_L
#define _AGGLMT_MCS0(x)             ((x) & 0xF)
#define _AGGLMT_MCS1(x)             (((x) & 0xF) << 4)
#define _AGGLMT_MCS2(x)             (((x) & 0xF) << 8)
#define _AGGLMT_MCS3(x)             (((x) & 0xF) << 12)
#define _AGGLMT_MCS4(x)             (((x) & 0xF) << 16)
#define _AGGLMT_MCS5(x)             (((x) & 0xF) << 20)
#define _AGGLMT_MCS6(x)             (((x) & 0xF) << 24)
#define _AGGLMT_MCS7(x)             (((x) & 0xF) << 28)

//3 LIFETIME_CTRL
#define BT_INT_MCU                  BIT7
#define BT_INT_PTA                  BIT6

//2 RL
#define RETRY_LIMIT_SHORT_SHIFT     8
#define RETRY_LIMIT_LONG_SHIFT      0


//2 DARFRC
#define _DARF_RC1(x)                ((x) & 0x1F)
#define _DARF_RC2(x)                (((x) & 0x1F) << 8)
#define _DARF_RC3(x)                (((x) & 0x1F) << 16)
#define _DARF_RC4(x)                (((x) & 0x1F) << 24)
// NOTE: shift starting from address (DARFRC + 4)
#define _DARF_RC5(x)                ((x) & 0x1F)
#define _DARF_RC6(x)                (((x) & 0x1F) << 8)
#define _DARF_RC7(x)                (((x) & 0x1F) << 16)
#define _DARF_RC8(x)                (((x) & 0x1F) << 24)


//2 RARFRC
#define _RARF_RC1(x)                ((x) & 0x1F)
#define _RARF_RC2(x)                (((x) & 0x1F) << 8)
#define _RARF_RC3(x)                (((x) & 0x1F) << 16)
#define _RARF_RC4(x)                (((x) & 0x1F) << 24)
// NOTE: shift starting from address (RARFRC + 4)
#define _RARF_RC5(x)                ((x) & 0x1F)
#define _RARF_RC6(x)                (((x) & 0x1F) << 8)
#define _RARF_RC7(x)                (((x) & 0x1F) << 16)
#define _RARF_RC8(x)                (((x) & 0x1F) << 24)

//-----------------------------------------------------
//
//  0x0500h ~ 0x05FFh   EDCA Configuration
//
//-----------------------------------------------------
//2 EDCA setting
#define AC_PARAM_TXOP_LIMIT_OFFSET  16
#define AC_PARAM_ECW_MAX_OFFSET     12
#define AC_PARAM_ECW_MIN_OFFSET     8
#define AC_PARAM_AIFS_OFFSET        0


//2 EDCA_VO_PARAM
#define _AIFS(x)                    (x)
#define _ECW_MAX_MIN(x)             ((x) << 8)
#define _TXOP_LIMIT(x)              ((x) << 16)

#define _BCNIFS(x)                  ((x) & 0xFF)
#define _BCNECW(x)                  (((x) & 0xF))<< 8)

#define _LRL(x)                     ((x) & 0x3F)
#define _SRL(x)                     (((x) & 0x3F) << 8)

//2 SIFS_CCK
#define _SIFS_CCK_CTX(x)            ((x) & 0xFF)
#define _SIFS_CCK_TRX(x)            (((x) & 0xFF) << 8);

//2 SIFS_OFDM
#define _SIFS_OFDM_CTX(x)           ((x) & 0xFF)
#define _SIFS_OFDM_TRX(x)           (((x) & 0xFF) << 8);

//2 TXPAUSE 0x522
#define MAC_STOPBK                  BIT0
#define MAC_STOPBE                  BIT1
#define MAC_STOPVI                  BIT2
#define MAC_STOPVO                  BIT3
#define MAC_STOPMGQ                 BIT4
#define MAC_STOPHIQ                 BIT5
#define MAC_STOPBCNQ                BIT6
#define MAC_STOP_BCN_HI_MGT         BIT7


//2 TBTT PROHIBIT
#define _TBTT_PROHIBIT_HOLD(x)      (((x) & 0xFF) << 8)

//2 REG_RD_CTRL 0x524
#define DIS_EDCA_CNT_DWN            BIT11

//2 MBSSID_CTRL 0x526

//2 P2PPS_CTRL 0x527
#define P2P_BCN_SEL                 BIT0
#define P2P_NOA0_EN                 BIT1
#define P2P_NOA1_EN                 BIT2
#define P2P_CTWND_EN                BIT3
#define P2P_BCN_AREA_EN             BIT4
#define P2P_PWR_MGT_EN              BIT5
#define P2P_OFF_DISTX_EN            BIT6
#define P2P_CTW_ALLSTASLEEP         BIT7


//2 P2PPS_SPEC_STATE 0x52B
#define P2P_SPEC_FORCE_DOZE0        BIT0
#define P2P_SPEC_NOA0_OFF_PERIOD    BIT1
#define P2P_SPEC_FORCE_DOZE1        BIT2
#define P2P_SPEC_NOA1_OFF_PERIOD    BIT3
#define P2P_CTWIN_EARLY_DISTX       BIT4
#define P2P_SPEC_BEACON_AREA_ON     BIT5
#define P2P_SPEC_CTW_ON             BIT6
#define P2P_SPEC_POWER_STATE        BIT7        // 1: on, 0: off


//2 P2PPS_STATE 0x543
#define P2P_FORCE_DOZE0             BIT0
#define P2P_NOA0_OFF_PERIOD         BIT1
#define P2P_FORCE_DOZE1             BIT2
#define P2P_NOA1_OFF_PERIOD         BIT3
#define P2P_NOA_POWEROFF            BIT4
#define P2P_BEACON_AREA_ON          BIT5
#define P2P_CTW_ON                  BIT6
#define P2P_POWER_STATE             BIT7        // 1: on, 0: off


//2 BCN_CTRL
#define EN_MBSSID                   BIT1
#define EN_TXBCN_RPT                BIT2
#define EN_BCN_FUNCTION             BIT3

//2 DUAL_TSF_RST
#define TSFTR_RST                   BIT0
#define TSFTR1_RST                  BIT1


#define STOP_BCNQ                   BIT6

// The same function but different bit field.
#define DIS_TSF_UDT0_NORMAL_CHIP    BIT4
#define DIS_TSF_UDT0_TEST_CHIP      BIT5

//2 ACMHWCTRL
#define AcmHw_HwEn                  BIT0
#define AcmHw_BeqEn                 BIT1
#define AcmHw_ViqEn                 BIT2
#define AcmHw_VoqEn                 BIT3
#define AcmHw_BeqStatus             BIT4
#define AcmHw_ViqStatus             BIT5
#define AcmHw_VoqStatus             BIT6

//-----------------------------------------------------
//
//  0x0600h ~ 0x07FFh   WMAC Configuration
//
//-----------------------------------------------------

//2 APSD_CTRL
#define APSDOFF                     BIT6
#define APSDOFF_STATUS              BIT7


//2 BWOPMODE
#define BW_20MHZ                    BIT2

#define RATE_BITMAP_ALL             0xFFFFF

// Only use CCK 1M rate for ACK
#define RATE_RRSR_CCK_ONLY_1M       0xFFFF1

//2 TCR
#define TSFRST                      BIT0
#define DIS_GCLK                    BIT1
#define PAD_SEL                     BIT2
#define PWR_ST                      BIT6
#define PWRBIT_OW_EN                BIT7
#define ACRC                        BIT8
#define CFENDFORM                   BIT9
#define ICV                         BIT10

//2 RCR
#define AAP                         BIT0
#define APM                         BIT1
#define AM                          BIT2
#define AB                          BIT3
#define ADD3                        BIT4
#define APWRMGT                     BIT5
#define CBSSID                      BIT6
#define CBSSID_DATA                 BIT6
#define CBSSID_BCN                  BIT7
#define ACRC32                      BIT8
#define AICV                        BIT9
#define ADF                         BIT11
#define ACF                         BIT12
#define AMF                         BIT13
#define HTC_LOC_CTRL                BIT14
#define UC_DATA_EN                  BIT16
#define BM_DATA_EN                  BIT17
#define MFBEN                       BIT22
#define LSIGEN                      BIT23
#define EnMBID                      BIT24
#define APP_BASSN                   BIT27
#define APP_PHYSTS                  BIT28
#define APP_ICV                     BIT29
#define APP_MIC                     BIT30
#define APP_FCS                     BIT31

//2 RX_PKT_LIMIT

//2 RX_DLK_TIME

//2 MBIDCAMCFG

//2 WOW_CTRL 0x690
#define FORCE_WAKE_UP               BIT0
#define PATTERN_MATCH_EN            BIT1
#define MAGIC_PKT_EN                BIT2
#define UNICAST_EN                  BIT3
#define WOWHCI_EN                   BIT5

//2 AMPDU_MIN_SPACE
#define _MIN_SPACE(x)               ((x) & 0x7)
#define _SHORT_GI_PADDING(x)        (((x) & 0x1F) << 3)

//2 RXERR_RPT
#define RXERR_TYPE_OFDM_PPDU            0
#define RXERR_TYPE_OFDM_FALSE_ALARM     1
#define RXERR_TYPE_OFDM_MPDU_OK         2
#define RXERR_TYPE_OFDM_MPDU_FAIL       3
#define RXERR_TYPE_CCK_PPDU             4
#define RXERR_TYPE_CCK_FALSE_ALARM      5
#define RXERR_TYPE_CCK_MPDU_OK          6
#define RXERR_TYPE_CCK_MPDU_FAIL        7
#define RXERR_TYPE_HT_PPDU              8
#define RXERR_TYPE_HT_FALSE_ALARM       9
#define RXERR_TYPE_HT_MPDU_TOTAL        10
#define RXERR_TYPE_HT_MPDU_OK           11
#define RXERR_TYPE_HT_MPDU_FAIL         12
#define RXERR_TYPE_RX_FULL_DROP         15

#define RXERR_COUNTER_MASK              0xFFFFF
#define RXERR_RPT_RST                   BIT27
#define _RXERR_RPT_SEL(type)            ((u32)((type) << 28))

//2 SECCFG
#define SCR_TxUseDK                     BIT0            //Force Tx Use Default Key
#define SCR_RxUseDK                     BIT1            //Force Rx Use Default Key
#define SCR_TxEncEnable                 BIT2            //Enable Tx Encryption
#define SCR_RxDecEnable                 BIT3            //Enable Rx Decryption
#define SCR_SKByA2                      BIT4            //Search kEY BY A2
#define SCR_NoSKMC                      BIT5            //No Key Search Multicast
#define SCR_TXBCUSEDK                   BIT6            // Force Tx Broadcast packets Use Default Key
#define SCR_RXBCUSEDK                   BIT7            // Force Rx Broadcast packets Use Default Key

//1 BCN_PSR_RPT [31:0]: Beacon Parser Report Register
//0~10      AID0
//11~13     RSVD
#define PS_TIM                          BIT6      //14
#define PS_DTIM                         BIT7      //15
//16~23     DTIM period
//24~31     DTIM COUNT


//1NAN CTRL
#define NAN_ENTRY_SIZE  64
#define NAN_ENTRY_NUM   1

#define NAN_PSR_EN      BIT0
#define _NAN_ENTRY_SIZE(size)   ((u8)(((((size)>>5)-2)&0x7)<<1))
#define _NAN_ENTRY_NUM(num)     ((u8)(((num)&0x7)<<4))
#define NAN_ATTRI_ID0_VLD   BIT0
#define NAN_ATTRI_ID1_VLD   BIT1
#define NAN_ATTRI_ID2_VLD   BIT2
#define NAN_ATTRI_ID3_VLD   BIT3
#define NAN_ATTRI_ID4_VLD   BIT4
#define NAN_RXA2_FILTER_EN  BIT5

//1 CPU DOMAIN
//-----------------------------------------------------
//
//  0xFD00h ~ 0xFDFFh   8051 CPU Local REG
//
//-----------------------------------------------------

//3 REG_SYS_CTRL(0xFD00)
//0xFD00[0]: 8051 sw reset for fpga use
//0xFD00[1:2] : rsvd
//0xFD00[3]: write reg 00[4] to trigger int pkt
#define WAKEUP_BUS                      BIT4    //dw8051 wakeup usb2/3
//0xFD00[5] : rsvd
#define SYS_CTRL_TXBUF_ROM_ENABLE       BIT6    //enable this bit when 8051 want to run instruntion and disable while leaving.       
//0xFD00[7]: auto clr 0xFD20 ~ 0xFD3F reg

//3 REG_PONSTS_RPT1(0xFD01)
#define PONSTS1_FW_DATA_RDY             BIT0
#define PONSTS1_HCI_SEL                 BIT1    //usb/pcie hci sel(0:pcie, 1:usb)    
#define PONSTS1_USB2_SEL                BIT2    //usb2 card emulation to usb2
#define PONSTS1_EEPROM_LOAD_OK          BIT3    //reg0x0A[5]
#define PONSTS1_MCUFWDL_RDY             BIT4    //reg0x80[1]
#define PONSTS1_MCUFWDL_EN              BIT5    //reg0x80[0]
#define PONSTS1_USB_BUS_ACTIVE          BIT6    //usb suspend
#define PONSTS1_RAM_SPACE_SEL           BIT7

#endif

#define RTL8721D_TESTCHIP_RFREG_AHB_BASE  		0x43003c00
//RF Reg only support dword mode,only 1 path
//#define WritePortRFDWORD(offset, value)     rtl_outl((4*offset+RTL8721D_TESTCHIP_RFREG_AHB_BASE), value)
//#define ReadPortRFDWORD(offset)             (rtl_inl((4*offset+RTL8721D_TESTCHIP_RFREG_AHB_BASE)))
#define WritePortRFDWORD(offset, value)     rtl_outl((offset+RTL8721D_TESTCHIP_RFREG_AHB_BASE), value)
#define ReadPortRFDWORD(offset)             (rtl_inl((offset+RTL8721D_TESTCHIP_RFREG_AHB_BASE)))

/*------------------------------Define Struct---------------------------------*/
//typedef struct _HAL_DATA_AS0_COMMON {

//IMR & ISR
//	u8  sysimr[4];
//	u8  sysisr[4];

//	u8  wlanimr[4];
//	u8  wlanisr[4];

//	u8  ftimr[4];
//	u8  ftisr[4];

//} HAL_DATA_AS0_COMMON, *PHAL_DATA_AS0_COMMON;



/*------------------------Export global variable------------------------------*/

/*------------------------------Funciton declaration--------------------------*/


#endif  // __ASSEMBLY__
#endif  //__WIFIFW_HAL_RAM_H__

