#ifndef __WIFIFW_INT_RAM_H__
#define __WIFIFW_INT_RAM_H__

/*--------------------Function declaration---------------------------------*/
extern void WLAN_INT_HDL_8730A(void);
extern void FT_INT_HDL_8730A(void);
extern void ISRSendSignalCommon_8730A(u32  event);
extern void ISR_TBTT_8730A(void);
extern void ISR_BCNRx_8730A(void);
extern void ISR_BCNRxErr_8730A(void);
extern void ISR_P0_TBTT_AGG_8730A(void);
extern void ISR_TIM_NO_HIT_8730A(void);
extern void ISR_TIM_HIT_8730A(void);
extern void ISR_HIOE_CHN0_8730A(void);
extern void ISR_HIOE_CHN1_8730A(void);
extern void ISR_HIOE_CHN_ON_8730A(void);
extern void ISR_HIOE_CHN_OFF_8730A(void);
extern void ISR_TSF_GT_THRES_8730A(void);
extern void ISR_RXBCN_TIMEUP_8730A(void);
extern void ISR_RXBCN_TIMEOUT_CNT_8730A(void);
extern void ISR_RxBMC_MD0_8730A(void);
extern void ISR_RxBMC_MD1_8730A(void);
extern void ISR_RxUnicast_MD1_8730A(void);
extern void ISR_RxUnicast_MD0_8730A(void);
extern void ISR_TxPKTIn_8730A(void);
extern void ISR_GTimer0_8730A(void);
extern void ISR_GTimer1_8730A(void);
extern void ISR_GTimer2_8730A(void);
extern void ISR_RPWM_8730A(void);
extern void ISR_GTimer5_8730A(void);
extern void ISR_BcnEarlyAGG_8730A(void);
extern void ISR_GTimer6_8730A(void);
extern void ISR_WlanActOn_8730A(void);
extern void ISR_WlanActOff_8730A(void);
extern void ISR_TxNull0_8730A(void);
extern void ISR_TxNull1_8730A(void);
extern void ISR_TBTT1_8730A(void);
extern void ISR_TXCCX_8730A(void);
extern void ISR_RxDone_8730A(void);
extern void ISR_H2CCMD_8730A(void);
extern void ISR_HRCV_8730A(void);
extern void ISR_BcnEarly_8730A(void);
extern void ISR_GTimer3_8730A(void);
extern void ISR_GTimer4_8730A(void);
extern void ISR_BCNERLY1_8730A(void);
extern void ISR_BTScoreboard_8730A(void);
extern void ISR_ZBMailbox_8730A(void);
extern void ISR_GNT_BT_Rise_8730A(void);
extern void ISR_GNT_BT_Fall_8730A(void);
#if CONFIG_SW_QUEUE_TX
extern void ISR_CPUMGN_POLLED_PKT_DONE_8730A(void);
#endif

#endif  /* __WIFIFW_INT_RAM_H__ */
