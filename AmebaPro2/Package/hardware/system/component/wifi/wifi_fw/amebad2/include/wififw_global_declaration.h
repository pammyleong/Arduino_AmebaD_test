#ifndef _WIFIFW_GLOBAL_DECLARATION_H
#define _WIFIFW_GLOBAL_DECLARATION_H

#ifndef __ASSEMBLY__
/* Extern Variable */
#ifdef __WIFIFW_INIT_C__
/*--------------------Define Struct-------------------------------------*/
FW_ROM_BSS_SECTION     u32                         TaskBitMap;

//2 INT HAL
FW_ROM_BSS_SECTION     PHAL_DATA_8730A             pIntHdl;

//2 Wlan
FW_ROM_BSS_SECTION     PRsvdPageLoc                pRPL;
FW_ROM_BSS_SECTION     PH2C_EVT                    pH2CEvt;
FW_ROM_BSS_SECTION     PC2H_EVT                    pC2HEvt;
FW_ROM_BSS_SECTION     u16                         RXFF0_BNDY;
FW_ROM_BSS_SECTION     u8     					   H2C_rptr;

//2 PS
FW_ROM_BSS_SECTION     PPS_PARM                    pPSParm;
FW_ROM_BSS_SECTION     PPS_TUNING_PPARM            pPSTParm;
FW_ROM_BSS_SECTION     u8                          ScanEn;

//2 Media Status
FW_ROM_BSS_SECTION     PMEDIA_STATUS               pMediaStatus;

//2 BT Coex
FW_ROM_BSS_SECTION     PBTC_PsTdma_Parm                 pBtcPsTdma;
FW_ROM_BSS_SECTION     PH2C_BT_Tdma_Parm                pH2cBtTdma;                //H2C Index: 0x60
FW_ROM_BSS_SECTION     PH2C_Ant_Sel_Reverse_Parm        pH2cAntSelReverse;         //H2C Index: 0x65
FW_ROM_BSS_SECTION     PH2C_WL_Opmode_Parm              pH2cWlOpmode;              //H2C Index: 0x66
FW_ROM_BSS_SECTION     PH2C_BT_Page_Scan_Interval_Parm  pH2cBtPageScanInterval;    //H2C Index: 0x6C
FW_ROM_BSS_SECTION     PH2C_WL_Calibration_Parm         pH2cWlCalibration;         //H2C Index: 0x6D
FW_ROM_BSS_SECTION     PH2C_BT_OnlyTest_Parm            pH2cBtOnlyTest;            //H2C Index: 0x6F
FW_ROM_BSS_SECTION     PH2C_BT_Init_Parm                pH2cBtInit;                //H2C Index: 0x70
FW_ROM_BSS_SECTION     PH2C_WL_PortID_Parm              pH2cWlPortID;              //H2C Index: 0x71
FW_ROM_BSS_SECTION     PBTC_Mailbox_Parm                pBtcMailbox;
FW_ROM_BSS_SECTION     PBTC_Scoreboard_Parm             pBtcScoreboard;

//2 WoWLAN
FW_ROM_BSS_SECTION     PAOAC_INFO                  pAOACInfo;
FW_ROM_BSS_SECTION     PARP_INFO                   pARPInfo;
FW_ROM_BSS_SECTION     PNDP_INFO                   pNDPInfo[2];
FW_ROM_BSS_SECTION     PIPV6_PSEUDO_HEADER_INFO    pIpv6PseudoHeaderInfo;
FW_ROM_BSS_SECTION     PSECURITY_INFO              pSecurityInfo;
FW_ROM_BSS_SECTION     PAOAC_REPORT                pAOACReport;
FW_ROM_BSS_SECTION     PAOAC_GLOBAL_INFO           pAOACGlobalInfo;
FW_ROM_BSS_SECTION     PAOAC_RSVDPAGE1             pAOACPage1;
FW_ROM_BSS_SECTION     PAOAC_RSVDPAGE2             pAOACPage2;
FW_ROM_BSS_SECTION     PAOAC_RSVDPAGE3             pAOACPage3;
FW_ROM_BSS_SECTION     PKeepAlive_Parm             pKeepAliveParm;
FW_ROM_BSS_SECTION     PRemoteWakeup_Parm          pRemoteWakeupCtrl;
FW_ROM_BSS_SECTION     PDisconnect_Parm            pDisconnectParm;

/*--------------------Export global variable----------------------------*/
#else
extern     u32                                  TaskBitMap;

/* 2 INT HAL */
extern     PHAL_DATA_8730A                      pIntHdl;

/* 2 Wlan */
extern     PRsvdPageLoc                         pRPL;
extern     PH2C_EVT                             pH2CEvt;
extern     PC2H_EVT                             pC2HEvt;
extern     u16                                  RXFF0_BNDY;
extern     u8     					   			H2C_rptr;

/* 2 PS */
extern PPS_PARM                                 pPSParm;
extern PPS_TUNING_PPARM                         pPSTParm;
extern u8                                       ScanEn;
/* 2 Media Status */
extern PMEDIA_STATUS                            pMediaStatus;

/* 2 BT Coex */
extern PBTC_PsTdma_Parm                         pBtcPsTdma;
extern PH2C_BT_Tdma_Parm                        pH2cBtTdma;
extern PH2C_Ant_Sel_Reverse_Parm                pH2cAntSelReverse;
extern PH2C_WL_Opmode_Parm                      pH2cWlOpmode;
extern PH2C_BT_Page_Scan_Interval_Parm          pH2cBtPageScanInterval;
extern PH2C_WL_Calibration_Parm                 pH2cWlCalibration;
extern PH2C_BT_OnlyTest_Parm                    pH2cBtOnlyTest;
extern PH2C_BT_Init_Parm                        pH2cBtInit;
extern PH2C_WL_PortID_Parm                      pH2cWlPortID;
extern PBTC_Mailbox_Parm                        pBtcMailbox;
extern PBTC_Scoreboard_Parm                     pBtcScoreboard;

/* 2 WoWLAN */
extern PAOAC_INFO                               pAOACInfo;
extern PARP_INFO                                pARPInfo;
extern PNDP_INFO                                pNDPInfo[2];
extern PIPV6_PSEUDO_HEADER_INFO                 pIpv6PseudoHeaderInfo;
extern PSECURITY_INFO                           pSecurityInfo;
extern PAOAC_REPORT                             pAOACReport;
extern PAOAC_GLOBAL_INFO                        pAOACGlobalInfo;
extern PAOAC_RSVDPAGE1                          pAOACPage1;
extern PAOAC_RSVDPAGE2                          pAOACPage2;
extern PAOAC_RSVDPAGE3                          pAOACPage3;
extern PKeepAlive_Parm             				pKeepAliveParm;
extern PRemoteWakeup_Parm						pRemoteWakeupCtrl;
extern PDisconnect_Parm 						pDisconnectParm;

#endif
#endif /* #ifndef __ASSEMBLY__ */
#endif /* _WIFIFW_GLOBAL_DECLARATION_H */
