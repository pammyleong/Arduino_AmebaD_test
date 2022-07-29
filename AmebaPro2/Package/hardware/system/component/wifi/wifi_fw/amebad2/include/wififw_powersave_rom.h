#ifndef __WIFIFW_POWERSAVE_H__
#define __WIFIFW_POWERSAVE_H__

/*--------------------Define --------------------------------------------*/
#define MACID_CLIENT						0
/*TIMER allcation*/
#define TIMER_TC0_CTRL						REG_TC0_CTRL    //instead of PowerTranning
#define TIMER_TC1_CTRL						REG_TC1_CTRL    //by PS or APOffload(AP mode)
#define TIMER_TC2_CTRL						REG_TC2_CTRL    //by PS
#define TIMER_TC3_CTRL						REG_TC3_CTRL    //by BT Multi-slot TDMA
#define TIMER_TC4_CTRL						REG_TC4_CTRL    //Rsvd for driver
#define TIMER_TCUNIT						REG_TCUNIT_BASE
#define TIMER_TC5_CTRL						REG_TC5_CTRL    //by BT i2c timeout ( 92e only)
#define TIMER_TC6_CTRL						REG_TC6_CTRL    //by BT TDMA

#define COUNTER_WAITFCS					TIMER_TC0_CTRL //start a protect timer for MAC not receive FCS after lps offload tim hit
#define COUNTER_BCNTO						TIMER_TC1_CTRL  // counter used by BCNTO is the same with DTIM
#define COUNTER_DTIM						TIMER_TC1_CTRL
#define COUNTER_PSTRX 						TIMER_TC2_CTRL
#define COUNTER_WAITHOST					TIMER_TC3_CTRL
#define COUNTER_DELAYKEEPALIVE			TIMER_TC5_CTRL
/*
    PS_RX_INFO[7:0]: Power Save RX Information Register
    initial value: 0x00
    REG III.220 (Offset 0x 0692h) PS_RX_INFO Register Definition
*/
#define RXDATAIN0								BIT0  //PSTX
#define RXDATAIN1								BIT1  //PSRX
#define RXDATAIN2								BIT2
#define RXMGTIN0								BIT3
#define RXCTRLIN0								BIT4

#define NULL_DATA0_ALLOW        			1
#define NULL_DATA0_DENY         			0

#define PS_RF_OFF               				0
#define PS_GO_ON                				BIT0
#define PS_TX_NULL              				BIT1
#define PS_RF_ON               	 			BIT2
#define PS_REGISTER_ACTIVE      			BIT3

//0x009C
#define PS_32K_IN               				BIT0
#define PS_32K_PG               				BIT4
#define PS_ACK                  				BIT6
#define PS_TOGGLE              			 	BIT7

#define PS_STATE_MASK           			(0x0F)
#define PS_IS_TX_NULL(x)        			((x) & PS_TX_NULL )
#define PS_IS_CLK_ON(x)         			((x) & (PS_RF_OFF |PS_ALL_ON ))
#define PS_IS_RF_OFF(x)         			((x)|PS_RF_OFF)
#define PS_IS_RF_ON(x)          			((x) & (PS_RF_ON))
#define PS_IS_ACTIVE(x)         			((x) & (PS_REGISTER_ACTIVE))

#define PS_STATUS_S0            			(PS_REGISTER_ACTIVE | PS_RF_ON)                    //(1,1,0) all on = register active + rf on
#define PS_STATUS_S1            			(PS_REGISTER_ACTIVE | PS_RF_ON | PS_TX_NULL)        //(1,1,1) all on + tx null(1)
#define PS_STATUS_S2            			(PS_RF_ON)                                         //(0,1,0) register sleep + rf on
#define PS_STATUS_S3            			(PS_RF_ON | PS_TX_NULL)                            //(0,1,1) register sleep + rf on + tx null(0)
#define PS_STATUS_S4            			0                                                 //(0,0,0) all OFF
#define PS_STATUS_S5            			(PS_TX_NULL )                                      //(0,0,1) SCAN = register sleep + rf on + scan enable
#define PS_STATUS_S6            			(PS_REGISTER_ACTIVE)                               //(1,0,0) NoA off = register active + rf off

/* DATA FIN Condition Flags */
#define STA_DATA_OPEN           			BIT0  // indicate that FW open due to TIM = 1 condition. (PS-POLL as trigger frame)
#define BC_DATA_OPEN            			BIT1   // indicate that FW open due to DTIM = 1 condition.  (BC & MC)
#define QOS_DATA_OPEN           			BIT2 // indicate that FW open due to UAPSD trigger condition. (QNULL)
#define C2H_DATA_OPEN          				BIT3   // indicate that FW open due to C2H event 
#define BCN_DATA_OPEN           			BIT4
#define APP_DATA_OPEN           			BIT5

#define ALL_80211_DATA_OPEN     			(STA_DATA_OPEN | BC_DATA_OPEN | QOS_DATA_OPEN)
#define IS_80211_DATA_OPEN(x)			((x) & ALL_80211_DATA_OPEN)
#define IS_C2H_DATA_OPEN(x)     			((x) & C2H_DATA_OPEN)

#define SET_DATA_OPEN(x, type)  		((x) |= (type))
#define CLR_DATA_OPEN(x, type)  		((x) &= (~type))
#define IS_DATA_OPEN(x, type)   			((x) & (type))

/* pwr state */
#define PS_TYPE_32KPERMISSION       	0
#define PS_TYPE_CURRENT_PS_STATE    	1
#define PS_TYPE_LASTRPWM            		2
/*--------------------Define Enum---------------------------------------*/
typedef enum _RxListenBeaconMode_ {
	RLBM_MIN                = 0,
	RLBM_MAX,
	RLBM_SELF_DEFINED
} RxListenBeaconMode, *PRxListenBeaconMode;

typedef enum _RT_MEDIA_STATUS {
	RT_MEDIA_DISCONNECT     = 0,
	RT_MEDIA_CONNECT        = 1
} RT_MEDIA_STATUS;

typedef enum _PS_MODE_SETTING_SELECTION_ {
	MODE_SETTING_ACTIVE     = 0,
	MODE_SETTING_LEGACY     = 1,
	MODE_SETTING_WMMPS      = 2

} PS_MODE_SETTING_SELECTION, *PPS_MODE_SETTING_SELECTION;

typedef struct _LEGACY_PS_PPARM_ {
	u8		ps_mode: 7;
	u8		ClkRequestEnable: 1;
	u8   	RLBM: 4;            //RX Listen BCN Mode
	u8 		smart_ps: 4;
	u8		AwakeInterval;      //Unit: beacon interval, this field is only valid in PS Self-Defined mode
	u8		bAllQueueUAPSD: 1;    // 1: all queue are uapsd 0: not all queue are uapsd
	u8		bMaxTrackingBcnMode: 1;
	u8		bBCNEarlyReport: 1;
	u8		XtalSel: 1;
	u8 		rsvd0: 4;
	u8		PwrState;
	u8		lpsofldEn: 1;
	u8		waitbcnfcsEn: 1;
	u8		rsvd1: 6;
	u8		BcnRecevingTime : 5;
	u8		BcnListenInterval : 2;
	u8		AdoptUserSetting: 1;
} LEGACY_PS_PARM, *PLEGACY_PS_PARM;

typedef struct _PS_TUNING_PPARM_ {
	u8		BCNTOLimit;
	u8		DTIMTimeOut;
	u8		Adopt: 1;
	u8		PSTimeOut: 7;
	u8		PS_DTIMPeriod;
	u8		rsvd1;
} PS_TUNING_PPARM, *PPS_TUNING_PPARM;
/*--------------------Define MACRO--------------------------------------*/

/*--------------------Define Struct---------------------------------------*/
typedef struct _BEACON_ADJUST_PARM_ {
	u8		BcnReceive32KBuffer;          //unit 128us
	u8		BcnReceiveDrvBuffer;          //unit 128us
	u16   	BcnAdjustCount;
	u8    	BcnExcludedNum;
	u8    	BcnEnlargeNum;
} BEACON_ADJUST_PARM, *PBEACON_ADJUST_PARM;

typedef struct _PS_PARM_ {
	u8		Enter32KHzPermission: 1;
	u8		bAllQueueUAPSD: 1;
	u8		ps_dtim_flag: 1;            // indicate dtim of current beacon.
	u8		pstrx_rxcnt_period: 1;
	u8 		NoConnect32k: 1;
	u8		TxNull0: 1;
	u8		TxNull1: 1;
	u8		rsvd0: 1;

	u8 		TxNull0ok: 1;
	u8		TxNull1ok: 1;
	u8		RfOffLicenseForBCNRx: 1;    //filen: After we received ps_bcn_cnt beacons, we can sleep(rf off).
	u8		BCNAggEn: 1;
	u8		IsGoingTo32K: 1;
	u8		bMaxTrackingBcnMode: 1;
	u8		BcnTraceDone: 1;
	u8		BcnEarlyPeriodFlag: 1;

	u8		BcnEarlySettingFlag: 1;
	u8		bBCNEarlyReport: 1;
	u8		BcnEnter32kMode: 1;
	u8		XtalSel: 1;
	u8		rsvd: 4;
	/*
	    filen: to indicate whether it is smart power saving or not
	    0: Legacy PS
	    1: Smart PS(RX use ps_poll)
	    2: Smart PS (RX use null_data(0))
	*/
	u8		smart_ps: 4;                //enum SMART_PS_MODE
	u8		RLBM: 4;                    // RX BCN MODE (min, max, active, ...)
	u8		AwakeInterval;
	u8		ps_mode;                    // ps type (avtive, legacy, wmmps)
	u8		ClkRequestEnable;
	u8		last_rpwm;
	u8		current_ps_state;
	u8 		ps_data_open;
	u8		ps_dtim_period;
	u8		ps_dtim_cnt;
	u8		ps_bcn_to;                  //unit 128us        // beacon timeout (ms).
	u8		bcn_to_cnt;                 // indicate the total number of contnuous BCN_TO we have received.
	u8		bcn_to_times_cnt;        //20140806
	u8		ps_drv_early_itv;       //32us
	u8		BcnAheadShift;          //unit 32us
	u8		BcnEarlyShift;          //unit 32us
	u8		BcnEarlyShiftMax;           //unit 32us
	u8		DefaultBcnEarly;            //unit 32us
	u8 		RxBcnCount;
	u8		TBTTCount;
	u8		CurrentEarly;           //unit 32us
	u8 		CurrentTimeOut;         //unit 128us
	u8		ReachBcnLimitCount;
	u8		XtalDelay;
	union {
		u8		BcnDurationArray[2];
		u16	BcnDuration;
	} BcnDurationUnion;
	u32	TSFOnTBTT;              //unit in TU
	//ben modify for open/close RF speedup.
	union {
		u8		TSFOnRxBcnArray[4];
		u32	TSFOnRxBcn;
	} TSFOnRxBcnUnion;
	union {
		u8		TSFOnBcnEarlyArray[4];
		u32	TSFOnBcnEarly;
	} TSFOnBcnEarlyUnion;
	BEACON_ADJUST_PARM BeaconAdjustParm;
	u8		rcv_action;
	u8		AckNull0;
	u8 		Fix_Delay_forward;
	u8 		bTIM_Flag;
	u8		Null0_rty_cnt;
	u8 		Null0_rty_lmt;
	u8 		BCNNumForDRV;//driver deric
	u8 		ScanEn;
} PS_PARM, *PPS_PARM;

/*--------------------Function declaration---------------------------------*/
extern void SetPwrStateReg_8730A_ROM(u8 PwrStateType, u8 value);
extern void ResetPSParm_8730A_ROM(void);
extern BOOLEAN ChkTxQueueIsEmpty_8730A_ROM(void);
extern void Legacy_PS_Setting_8730A_ROM(void);
extern void PSModeSetting_8730A_ROM(u8 on) ;
extern void ConfigListenBeaconPeriod_8730A_ROM(u8  RLBM, u8 AwakeInterval);
extern void PSSetMode_8730A_ROM(PLEGACY_PS_PARM pparm);
extern void PS_S2ToS0State_8730A_ROM(void);
extern void PS_S3ToS2orS0State_8730A_ROM(void);
extern void PS_S1ToS0orS2State_8730A_ROM(void);
extern void PS_S2ToS4State_8730A_ROM(void);
extern void PS_S2ToS5State_8730A_ROM(void);
extern void PS_S5ToS2State_8730A_ROM(void);
extern void PS_S4ToS2State_8730A_ROM(u8  ReleaseTxPause);
extern void PS_S6ToS0State_8730A_ROM(void);
extern void PS_S0ToS6State_8730A_ROM(void);

#endif /* __WIFIFW_POWERSAVE_H__ */
