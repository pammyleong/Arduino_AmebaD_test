#ifndef __WIFIFW_BTCONCURR_H__
#define __WIFIFW_BTCONCURR_H__

#ifndef __ASSEMBLY__
/*--------------------Define --------------------------------------------*/
#define BTC_TIMER_MASK						REG_TC6_CTRL

#define SLOT_WIFI								0
#define SLOT_BT                     			1
#define SLOT_DEFAULT                		3
#define SEL_COEX_TABLE_1            		0x03   //0x6CC[1:0]=2'b11 -> select 0x6C0
#define SEL_COEX_TABLE_2            		0xFC   //0x6CC[1:0]=2'b00 -> select 0x6C4
/*--------------------Define Enum---------------------------------------*/
typedef enum _BTC_Mailbox_CMD_ {
	_BT_FW_PATCH                      			= 0x0a,
	_WL_OP_MODE                       			= 0x11,
	_WIFI_RF_CALIBRATION_EN           		= 0x15,
	_FORCE_BT_TXPWR                   		= 0x17,
	_BT_IGNORE_WLAN_ACT               		= 0x1b,
	_PSD_CONTROL                      			= 0x21,
	_BT_INFO_REPORT                   		= 0x23,
	_BT_PSD_REPORT                    		= 0x24,
	_BT_INFO_REPORT_BY_ITSELF         	= 0x27,
	_BT_INFO_REPORT_CONTROL           		= 0x28,
	_BT_SET_TXRETRY_REPORT_PARAMETER  	= 0x29,
	_BT_SET_PTA_TABLE                 		= 0x2A,
	_BT_MP_REPORT                     			= 0x30,
	_BT_PSD_MODE                      			= 0x31,
	_BT_SET_BT_LNA_CONSTRAINT         	= 0x32,
	_BT_LOOPBACK                      			= 0x33,
	_BT_CALIBRATION                   		= 0x34,
	_INTERNAL_SWITCH                  		= 0x35,
	_BT_CHECK_WLAN_STATE              		= 0x36,
	_CHANGE_WIFI_RF_STATE             		= 0x37,
	_BT_PAGE_SCAN_INTERVAL            		= 0x38,
	_BT_AUTO_SLOT                     			= 0x39,
	_MAILBOX_EN                       			= 0x40,
	_BT_CALIBRATION_FAIL              		= 0x41,
	_WIFI_TDMA_IN_BT_SLOT             		= 0x42,
	_WIFI_RPT_TDMA                    		= 0x43
} BTC_Mailbox_CMD, *PBTC_Mailbox_CMD;

/*--------------------Define Struct---------------------------------------*/
typedef struct _BTC_PsTdma_Parm_ {
	u8		WifiActive			: 1;
	u8		TxNull1				: 1;
	u8  	TxNull1ok 			: 1;
	u8  	BTCalibration		: 1;
	u8    	BTChangeType		: 1;
	u8   	BTConnect 	 		: 1;
	u8   	BTRptConnect		: 1;
	u8   	AutoSlotBackup	: 1;

	u8  	BTCalibrationPeriod;

	u8  	BTCTCount			: 4;
	u8  	BTCTCTh				: 4;

	u32 	AutoSlotTimeBackup;
	u8  	AutoSlotCnt;
	u8   	AutoSlotFailCnt;
	u8   	A2DPEmptyThd;
	u8   	BCNIvl;
	u8   	HalfBCNIvl;
	u8   	WLANPeriodCount;
	u8    	NullExtensionCount;
	u8   	NAVTemp;
	u8    	ValueBackup2;

	u8  	WLANOnPeriod		: 1;
	u8   	DynamicSlotState	: 2;
	u8    	PanProtection		: 1;
	u8   	TdmaChange			: 1;
	u8   	WLPeriodCntIncrease	: 1;
	u8   	UnderBCNProtection	: 1;
	u8   	Rsvd1				: 1;

	u32 	BtSlotStartTime;
	u8   	H2cTdmaValue[7];
	u32  	DACSwingLevel;
	u32 	DACSwingInitValue;
	u8   	RAOffsetEn;
	u8   	RAOffset;
	u8  	RAOffsetMCS7;
	u8   	RAOffsetMCS6;
	u8   	RAOffsetMCS5;
	u32  	HIDPTATable;
	u32 	HIDPTATableBackUp;
	u8  	HIDSlotCnt;
	u8  	HIDPTATableInterval;
	u32 	HIDPTATableNew;

	u8   	PanDurUserMode		: 1;
	u8  	PanDuration				: 7;

	u8   	TxNullCnt;
	u8   	TxNullRtyCnt;
	u8   	TxNullOkCnt;

	u8   	TdmaLeakAPModeDisable	: 1;
	u8   	LeakAPCount           		: 7;

	u8  	LeakAPRxCount;
	u8   	LeakAPCountForObservation;

	u8   	TdmaIntervalMode		: 2;
	u8   	TdmaInterval       	: 6;
	u8   	TdmaIntervalCnt    	: 7;
	u8  	TdmaTimerFlag      	: 1;

	u8    	TDMASlotToggleCount;
	u8   	TbttISRCnt;    /*Count the TBTT function called by TBTT ISR but not TDMA.*/
	u8    	BtSlotLen[20];
	u8    	BtSlotCnt;
	u8   	RandomWLSlotCnt;
} BTC_PsTdma_Parm, *PBTC_PsTdma_Parm;

typedef struct _BTC_Mailbox_Parm_ {
	u8   	pBuffer[8];
} BTC_Mailbox_Parm, *PBTC_Mailbox_Parm;

typedef struct _BTC_Scoreboard_Parm_ {
	u32  	State;
} BTC_Scoreboard_Parm, *PBTC_Scoreboard_Parm;

/*------------------H2C Define Struct---------------------------------------*/
/*H2C Index: 0x60*/
typedef struct _H2C_BT_Tdma_Parm_ {
	/* B0 */
	u8  	Enable						: 1;
	u8    	ValueofReg870InBT       	: 1;    /* 1:0x870 = 0x300, 0:0x870 = 0x310*/
	u8    	HIDSlotToggle           	: 1;
	u8   	ValueOfReg870           	: 1;    /* when disable 1:0x870 = 0x310, 0:0x870 = 0x300*/
	/* when enable 1: 0x860 = 0x110, 0:0x860 = 0x210*/
	u8   	AutoWakeUp              	: 1;    /* when set 1, use null(0) and null(1) packet*/
	u8   	NoPS                    		: 1;    /* when set 1, in BT slot will pause WiFi Tx*/
	u8   	AllowBTHighPriority		: 1;
	u8   	ValueofReg870InWIFI		: 1;    /* 1:0x870 = 0x300, 0:0x870 = 0x310*/
	/* B1 */
	u8  	TBTTOnPeriod;
	/* B2 */
	u8  	Rsvd0                   		: 2;
	u8   	PanEnable               		: 1;
	u8   	PsPoll                  		: 1;
	u8   	WifiRandomSlot          	: 1;
	u8   	Rsvd1                   		: 3;
	/* B3 */
	u8  	NoTxPause               		: 1;
	u8  	Valueof778InWIFI        	: 1;
	u8   	Valueof778InWIFIOnSCO	: 1;
	u8   	ValueofReg778           	: 1;    /* when disable 1: 778=3, 0: 778=1 */
	/* when enable 1:allow 32k, 0:not allow 32k */
	u8  	SCOOption               		: 1;
	u8   	ValueofReg860InWIFI		: 1;
	u8   	TwoAntenna              	: 1;
	u8  	ReduceWIFIPower         	: 1;
	/* B4 */
	u8 		ExtraDecisionOf778      	: 1;
	u8   	CCKPriorityToggle       	: 1;
	u8    	WifiAutoSlot            	: 1;
	u8    	CTS2Self                		: 1;
	u8  	ChangeCoexTable         	: 1;
	u8  	LongNAV                 		: 1;    /* use large NAV to protect BT slot */
	u8   	DynamicSlot             	: 1;
	u8   	ValueofReg778B1InBT		: 1;    /* 1:778[1]=1, 0:778[1]=0 in bt */
	/* B5 */
	u8  	Rsvd5;
	/* B6 */
	u8 		Rsvd6;
} H2C_BT_Tdma_Parm, *PH2C_BT_Tdma_Parm;

//H2C Index: 0x61
typedef struct _H2C_BT_Info_Parm_ {
	u8		Trigger		: 1;
	u8   	Rsvd0 		: 7;
	/* B1-B6 */
	u8   	Rsvd1[6];
} H2C_BT_Info_Parm, *PH2C_BT_Info_Parm;

/* H2C Index: 0x62 */
typedef struct _H2C_Force_BT_TxPower_Parm_ {
	u8 		PowerIndex;
	//B1-B6
	u8   	Rsvd1[6];
} H2C_Force_BT_TxPower_Parm, *PH2C_Force_BT_TxPower_Parm;

/* H2C Index: 0x63 */
typedef struct _H2C_BT_Ignore_WLACT_Parm_ {
	u8  	Enable		: 1;
	u8   	Rsvd0 		: 7;
	//B1-B6
	u8  	Rsvd1[6];
} H2C_BT_Ignore_WLACT_Parm, *PH2C_BT_Ignore_WLACT_Parm;

/* H2C Index: 0x64 */
typedef struct _H2C_DAC_Swing_Value_Parm_ {
	u8		Value;
	//B1-B6
	u8		Rsvd1[6];
} H2C_DAC_Swing_Value_Parm, *PH2C_DAC_Swing_Value_Parm;

/* H2C Index: 0x65 */
typedef struct _H2C_Ant_Sel_Reverse_Parm_ {
	u8 		AntReverse;
	u8 		SwitchOutside;
	//B2-B6
	u8 		Rsvd2[5];
} H2C_Ant_Sel_Reverse_Parm, *PH2C_Ant_Sel_Reverse_Parm;

/* H2C Index: 0x66 */
typedef struct _H2C_WL_Opmode_Parm_ {
	u8		Opmode;
	u8  	ChannelIndex;
	u8   	BandWidth;
	//B3-B6
	u8   	Rsvd3[4];
} H2C_WL_Opmode_Parm, *PH2C_WL_Opmode_Parm;

/* H2C Index: 0x6C */
typedef struct _H2C_BT_Page_Scan_Interval_Parm_ {
	u8  	LSB_Interval;
	u8   	MSB_Interval;
	//B2-B6
	u8   	Rsvd2[5];
} H2C_BT_Page_Scan_Interval_Parm, *PH2C_BT_Page_Scan_Interval_Parm;

/* H2C Index: 0x6D */
typedef struct _H2C_WL_Calibration_Parm_ {
	u8   	WLCalibrationEn	: 1;
	u8    	Rsvd0            		: 7;
	//B1-B6
	u8   	Rsvd1[6];
} H2C_WL_Calibration_Parm, *PH2C_WL_Calibration_Parm;

/* H2C Index: 0x6E */
typedef struct _H2C_GNTBT_Value_Parm_ {
	u8  	GntBtValue			: 1;
	u8    	Rsvd0          		: 7;
	//B1-B6
	u8    	Rsvd1[6];
} H2C_GNTBT_Value_Parm, *PH2C_GNTBT_Value_Parm;

/* H2C Index: 0x6F */
typedef struct _H2C_BT_OnlyTest_Parm_ {
	u8 		BTOnlyTest      	: 1;
	u8   	Rsvd0           		: 7;
	//B1-B6
	u8   	Rsvd1[6];
} H2C_BT_OnlyTest_Parm, *PH2C_BT_OnlyTest_Parm;

/* H2C Index: 0x70 */
typedef struct _H2C_BT_Init_Parm_ {
	u8    	Enhance3wireMode	: 1;
	u8   	HighPowerPAMode	: 1;
	u8   	Rsvd0             	: 6;
	//B1-B6
	u8    	Rsvd1[6];
} H2C_BT_Init_Parm, *PH2C_BT_Init_Parm;

/* H2C Index: 0x71 */
typedef struct _H2C_WL_PortID_Parm_ {
	u8   	PortID         		: 3;
	u8   	Rsvd0          		: 5;
	//B1-B6
	u8   	Rsvd1[6];
} H2C_WL_PortID_Parm, *PH2C_WL_PortID_Parm;

/*--------------------Function declaration---------------------------------*/
extern void H2CHDL_BTInfo_8730A_ROM(u8  *pbuf);
extern void H2CHDL_ForceBTTxpwr_8730A_ROM(u8  *pbuf);
extern void H2CHDL_BTIgnoreWlanAct_8730A_ROM(u8   *pbuf);
extern void H2CHDL_AntSelReverse_8730A_ROM(u8   *pbuf);
extern void H2CHDL_WLOpmode_8730A_ROM(u8   *pbuf);
extern void H2CHDL_BTMpH2C_8730A_ROM(u8   *pbuf);
extern void H2CHDL_BTControl_8730A_ROM(u8   *pbuf);
extern void H2CHDL_BT_Page_Scan_Interval_8730A_ROM(u8 *pbuf);
extern void H2CHDL_GNT_BT_Ctrl_8730A_ROM(u8 *pbuf);
extern void H2CHDL_BT_Only_Test_8730A_ROM(u8 *pbuf);
extern void H2CHDL_WL_Port_ID_8730A_ROM(u8 *pbuf);
extern void C2HBTLoopback_8730A_ROM(u8  *pbuf);
extern void C2HBTMpRpt_8730A_ROM(u8  idx, u8  status, u8  req_num);
extern void C2HBTMailBoxStatus_8730A_ROM(u8  status);
extern void InitBTCoexTimer_8730A_ROM(u8 duration);
extern void Write778_8730A_ROM(u8 value);
extern void TdmaChangeCoexTable_8730A_ROM(u8  slot);
extern void BTNullSetting_8730A_ROM(u8  bPowerBit, u16 offset, u8  lsb, u8  msb);

#endif   /* #ifndef __ASSEMBLY__ */
#endif  /* __WIFIFW_BTCONCURR_H__ */
