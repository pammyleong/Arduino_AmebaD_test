#ifndef __WIFIFW_INT_RAM_H__
#define __WIFIFW_INT_RAM_H__

/*--------------------Function declaration---------------------------------*/
extern void
WLAN_INT_HDL_RAM_8721D(
	void
);

extern void
FT_INT_HDL_RAM_8721D(
	void
);

extern void
ISRSendSignalCommon_8721D_RAM(
	u8  event
);


extern void
ISR_TBTT_8721D(
	void
);

extern void
ISR_BCNRx_8721D(
	void
);

extern  void
ISR_RxBMC_MD1_8721D(
	void
);

extern void
ISR_RxBMC_MD0_8721D(
	void
);

extern void
ISR_RxUnicast_MD1_8721D(
	void
);

extern void
ISR_RxUnicast_MD0_8721D(
	void
);

extern void
ISR_TxPKTIn_8721D(
	void
);

extern void
ISR_GTimer1_8721D(
	void
);

extern void
ISR_GTimer2_8721D(
	void
);

extern void
ISR_RPWM_8721D(
	void
);

extern void
ISR_EOSP_8721D(
	void
);

extern void
ISR_GTimer5_8721D(
	void
);

extern void
ISR_TRIGGER_PKT_8721D(
	void
);

extern void
ISR_RETRIVE_BUFFERED_8721D(
	void
);

extern void
ISR_CLR_PS_STATUS_8721D(
	void
);

extern void
ISR_BcnEarlyAGG_8721D(
	void
);

extern void
ISR_GTimer6_8721D(
	void
);

extern void
ISR_WlanActOn_8721D(
	void
);

extern void
ISR_WlanActOff_8721D(
	void
);

extern void
ISR_TxNull0_8721D(
	void
);

extern void
ISR_TxNull1_8721D(
	void
);

extern void
ISR_SyncBcnRxOK_8721D(
	void
);

extern void
ISR_DWEarly_8721D(
	void
);

extern void
ISR_DWEnd_8721D(
	void
);

extern void
ISR_EQEarly_8721D(
	void
);

extern void
ISR_EQTxOK_8721D(
	void
);

extern void
ISR_TBTT1_8721D(
	void
);

extern void
ISR_TSF_BIT32_TOGGLECommon(
	void
);

extern void
ISR_TXCCX_8721D(
	void
);

extern void
ISR_RxDone_8721D(
	void
);

#if CONFIG_SW_QUEUE_TX
extern  void
ISR_CPUMGN_POLLED_PKT_DONE_8721D(
	void
);
#endif

extern void
ISR_H2CCMD_8721D(
	void
);

extern void
ISR_HRCV_8721D(
	void
);

extern void
ISR_BcnEarly_8721D(
	void
);

extern void
ISR_GTimer3_8721D(
	void
);

extern void
ISR_GTimer4_8721D(
	void
);

extern void
ISR_BCNERLY1_8721D(
	void
);

extern void
ISR_BTScoreboard_8730A(
	void
);

extern void
ISR_ZBMailbox_8730A(
	void
);

extern void
ISR_GNT_BT_Rise_8730A(
	void
);

extern void
ISR_GNT_BT_Fall_8730A(
	void
);

#endif  //__WIFIFW_INT_RAM_H__

