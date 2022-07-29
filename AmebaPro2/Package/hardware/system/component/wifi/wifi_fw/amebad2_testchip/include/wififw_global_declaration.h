#ifndef _RTL8721D_GLOBAL_DECLARATION_H
#define _RTL8721D_GLOBAL_DECLARATION_H

#ifndef __ASSEMBLY__
//Extern Variable
#ifdef __RTL8721D_INIT_C__


/*--------------------Define Struct-------------------------------------*/



FW_ROM_BSS_SECTION     u8                          TaskBitMap;

//2 INT HAL
FW_ROM_BSS_SECTION     PHAL_DATA_8721D             pIntHdl;

//2 Wlan
FW_ROM_BSS_SECTION     PRsvdPageLoc                pRPL;
FW_ROM_BSS_SECTION     PH2C_EVT                    pH2CEvt;
FW_ROM_BSS_SECTION     PC2H_EVT                    pC2HEvt;
FW_ROM_BSS_SECTION     u16                         RXFF0_BNDY;
FW_ROM_BSS_SECTION     u8     					   H2C_rptr;


//2 PS
//P2PPS
FW_ROM_BSS_SECTION     PPS_PARM                    pPSParm;
FW_ROM_BSS_SECTION     PPS_TUNING_PPARM            pPSTParm;
FW_ROM_BSS_SECTION     PPS_BT_Parm                 pPSBTParm;
FW_ROM_BSS_SECTION     u8                          ScanEn;

//2 Media Status
FW_ROM_BSS_SECTION     PMEDIA_STATUS               pMediaStatus;


//2 BT Coex
FW_ROM_BSS_SECTION     PBT_B_TYPE_TDMA_Parm        pBtTdmaParm;
FW_ROM_BSS_SECTION     PBTTxStatus_Parm            pBTTxStatus;
FW_ROM_BSS_SECTION     PBT_MAILBOX_Parm            pBtParm;
FW_ROM_BSS_SECTION     PWLAN_Opmode_Parm           pWIFI_Info;
FW_ROM_BSS_SECTION     PBT_Page_Scan_Interval_Parm pBT_Page_Scan_Interval;
FW_ROM_BSS_SECTION     PBT_Init_Parm               pBT_Init_Info;
FW_ROM_BSS_SECTION     u8                          BTDebugEN;
FW_ROM_BSS_SECTION     u8                          BTcnt[40];


//2 WoWLAN

FW_ROM_BSS_SECTION     PAOAC_INFO                  pAOACInfo;
FW_ROM_BSS_SECTION     PARP_INFO                   pARPInfo;
FW_ROM_BSS_SECTION     PNDP_INFO                   pNDPInfo[2];
FW_ROM_BSS_SECTION     PIPV6_PSEUDO_HEADER_INFO    pIpv6PseudoHeaderInfo;
FW_ROM_BSS_SECTION     PSECURITY_INFO              pSecurityInfo;
FW_ROM_BSS_SECTION     PAOAC_REPORT                pAOACReport;
FW_ROM_BSS_SECTION     PAOAC_GLOBAL_INFO           pAOACGlobalInfo;
FW_ROM_BSS_SECTION     PAOAC_RSVDPAGE1             pAOACPage1;
/*--------------------Export global variable----------------------------*/

#else
extern     u8                          TaskBitMap;

//2 INT HAL
extern     PHAL_DATA_8721D                      pIntHdl;

//2 Wlan
extern     PRsvdPageLoc                         pRPL;
extern     PH2C_EVT                             pH2CEvt;
extern     PC2H_EVT                             pC2HEvt;
extern     u16                                  RXFF0_BNDY;
extern     u8     					   			H2C_rptr;


//2 PS
extern PPS_PARM                                 pPSParm;
extern PPS_TUNING_PPARM                         pPSTParm;
extern PPS_BT_Parm                              pPSBTParm;
extern u8                                       ScanEn;

//2 Media Status
extern PMEDIA_STATUS                            pMediaStatus;


//2 BT Coex
extern PBT_B_TYPE_TDMA_Parm                     pBtTdmaParm;
extern PBTTxStatus_Parm                         pBTTxStatus;
extern PBT_MAILBOX_Parm                         pBtParm;
extern PWLAN_Opmode_Parm                        pWIFI_Info;
extern PBT_Page_Scan_Interval_Parm              pBT_Page_Scan_Interval;
extern PBT_Init_Parm                            pBT_Init_Info;
extern u8                                       BTDebugEN;
extern u8                                       BTcnt[40];


//2 WoWLAN

extern PAOAC_INFO                               pAOACInfo;
extern PARP_INFO                                pARPInfo;
extern PNDP_INFO                                pNDPInfo[2];
extern PIPV6_PSEUDO_HEADER_INFO                 pIpv6PseudoHeaderInfo;
extern PSECURITY_INFO                           pSecurityInfo;
extern PAOAC_REPORT                             pAOACReport;
extern PAOAC_GLOBAL_INFO                        pAOACGlobalInfo;
extern PAOAC_RSVDPAGE1                          pAOACPage1;


#endif  //#ifdef __RTL8721D_HWINIT_ROM_C__
#endif //#ifndef __ASSEMBLY__

#endif //_RTL8822C_GLOBAL_DECLARATION_H
