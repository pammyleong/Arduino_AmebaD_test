#ifndef __WLAN_POWERSAVE_RAM_H__
#define __WLAN_POWERSAVE_RAM_H__

/*--------------------------Define -------------------------------------------*/
#define REG_PGRSStateInd	REG_FWLBK_DBG0
#define MACPGResumeDone	(0x12345678)

#if CONFIG_PS_DEBUG
#define DBG_LPS_WRITE(x,y)		(x = y)
#define DBG_LPS_INCREASE(x)		(++x)
#define DBG_LPS_SM(x,y) 			(SysMib.PSDbgParm.DbgLpsSM[x] = y)
#else
#define DBG_LPS_WRITE(x,y)
#define DBG_LPS_INCREASE(x)
#define DBG_LPS_SM(x,y)
#endif

//Power Save Tuning Parameter
#define BCN_RX_ON_DELAY         			2        //Beacons are transmitted in 1MHz, then 1bit per 1microsecond. If 2ms are added, it prevents from losing approximately 250bytes in worst case.
#define BCN_EARLY_32K_MARGIN    			2        // 1ms would be enough, but 2ms is better for multicast receiving in open space
#define BCN_EARLY_DRV_MARGIN    			1        // 1ms would be better in open space
#define BCN_RECEIVE_32K_BUFFER  		(BCN_RX_ON_DELAY+BCN_EARLY_32K_MARGIN)
#define BCN_RECEIVE_DRV_BUFFER  		(BCN_RX_ON_DELAY+BCN_EARLY_DRV_MARGIN)
#define BCN_DISTRIBUTION        			8  //5ms ,generally is 5 ms
#define DEFAULT_BCN_TO_PERIOD   		(BCN_RECEIVE_32K_BUFFER+BCN_DISTRIBUTION)  //choose the bigger one
#define DEFAULT_BCN_TO_LIMIT    			2  // 1
#define DEFAULT_BCN_TO_TIMES_LIMIT  	2
#define DEFAULT_DTIM_TIMEOUT    			15  // 7         // 7 ms
#define DEFAULT_PS_TIMEOUT      			20  // 20       // 20 ms
#define DEFAULT_PS_DTIM_PERIOD  		7

#define DEFAULT_PS_BCN_EARLY_MIN     1
#define DEFAULT_PS_BCN_EARLY   	     	0//0-0xff
#define DEFAULT_PS_BCN_EARLY_128US   5//0-7
#define DEFAULT_PS_BCN_EARLY_32US    0//0-0xffff
#define DEFAULT_PS_BCN_EARLY_32K   	 3
#define DEFAULT_PS_BCN_EARLY_128US_32K   2
#define DEFAULT_PS_BCN_EARLY_32US_32K    0
#define DEFAULT_BCN_TO_PERIOD_32K	 15

#define DEFAULT_PS_BCN_EARLY_V_32K   	 3
#define DEFAULT_PS_BCN_EARLY_V_128US_32K   3
#define DEFAULT_PS_BCN_EARLY_V_32US_32K    0

#define DEFAULT_PS_32K_EARLY(x)       	(((DEFAULT_PS_BCN_EARLY_V_32K+(x)) << 5)+(DEFAULT_PS_BCN_EARLY_V_128US_32K<< 2)+(DEFAULT_PS_BCN_EARLY_V_32US_32K))
#define BCN_PS_32K_SHIFT_MAX(x)        	(((DEFAULT_PS_BCN_EARLY_V_32K+(x)) << 5)+(DEFAULT_PS_BCN_EARLY_V_128US_32K<< 2)+(DEFAULT_PS_BCN_EARLY_V_32US_32K))
#define DEFAULT_PS_EARLY(x)       		(((DEFAULT_PS_BCN_EARLY+(x)) << 5)+(DEFAULT_PS_BCN_EARLY_128US<< 2)+(DEFAULT_PS_BCN_EARLY_32US))
#define BCN_PS_SHIFT_MAX(x)        		(((DEFAULT_PS_BCN_EARLY+(x)) << 5)+(DEFAULT_PS_BCN_EARLY_128US<< 2)+(DEFAULT_PS_BCN_EARLY_32US))

#define BCN_ADVANCE_MAX         			10
#define BCN_EARLY_MARGIN        			1       //unit 256us
#define RF_ON_COMPENSATION          		50//70   1030        //unit 1us
#define BCN_RX_INT_DELAY              		90//  70   1030   //unit 1us
#define BCN_DELAY_MAX           			15
#define BCN_CALCULATION_MAX     			(BCN_ADVANCE_MAX+BCN_DELAY_MAX)

#define BCN_ADJUST_COUNT        			100
#define BCN_EXCLUDED_NUM        			(BCN_ADJUST_COUNT/20)
#define BCN_ENLARGE_NUM         			5
#define SHIFT_COMPENSATION      			1
#define BCN_DRIFT_COMPENSATION  		2

/*------------------------------Define Enum-----------------------------------*/
typedef enum _SMART_PS_MODE_FOR_LEGACY_ {
	SMART_PS_MODE_LEGACY_PWR1           = 0,        // TX: pwr bit = 1, RX: PS_POLL
	SMART_PS_MODE_TX_PWR0               = 1,        // TX: pwr bit = 0, RX: PS_POLL
	SMART_PS_MODE_TRX_PWR0              = 2,        // TX: pwr bit = 0, RX: NULL(0)
	SMART_PS_MODE_TX_PWR1				= 3 		// TX: pwr bit = 1, RX: NULL(0)
} SMART_PS_MODE_FOR_LEGACY, *PSMART_PS_MODE_FOR_LEGACY;

typedef struct _SAPPS_PARM_ {
	u8      Enable: 1;
	u8      EnPS: 1;
	u8      EnLPRx: 1;
	u8      Manual32k: 1;
	u8      Active: 1;
	u8      FlagToWaitHostCutPower: 1;
	u8      RF2Path: 1;
	u8      rsvd: 1;
	u8      Duration;
	u8      Duration_On;
	u8      Duration_Off;
	u8      AntSwitchOutside;
	u8      TwoAnt;
	u8      AntSelReverse;
	u8      TxPathCtrl;
} SAPPSParm, *PSAPPSParm;

typedef struct _INACTIVEPS_Parm_ {
	u8      Enable: 1;
	u8      IgnorePsCondition: 1;
	u8      rsvd: 6;
	u8      Frequency;
	u8      Duration;
	u8      FrequencyCount;
} INACTIVEPSParm, *PINACTIVEPSParm;

typedef struct _LPSOFFLOAD_Parm_ {
	u8	MACRXBCNOfldEn: 1;
	u8	HWCtrlTRXOnOff: 1;
	u8	ByPassLsysWakeEn: 1;
	u8	WaitFCSOptionEn: 1;
	u8	RcvingTimhitBcn: 1;
	u8	ReceiveTimhit: 1;
	u8	BKForPGResDone: 1;
	u8	rsvd: 1;
	u16 TRXOnCmdFileHWStartAddr;
	u16 TRXOnCmdFileFWStartAddr;
	u16 TRXOnCmdFileEndAddr;
	u16 TRXOffCmdFileStartAddr;
	u16 TRXOffCmdFileEndAddr;
	u16 Delay2USCmdFileStartAddr;
	u16 Delay2USCmdFileEndAddr;
	u16 PGHIOECH1BKStartAddr;
	u16 PGHIOECH1BKEndAddr;
	u16 PGRSCmdFileStartAddr;
	u16 PGRSCmdFileEndAddr;
	u16 PGRSStartDelayStartAddr;
	u16 PGRSStartDelayEndAddr;
} LPSOFFLOADParm, *PLPSOFFLOADParm;

typedef struct _Bcnearly_adjust_PID_ {
	u32 	PerDeltaTSF;  //unit us
	u32 	DeltaTSF;
	u32 	PerError;
	u32 	Error;
	u32 	Per1_TSFOnRxBcn;
	u32 	Per2_TSFOnRxBcn;
	u32 	PbaseMinDeltaTSF;
	u8	PbaseGetTime;
	u8	PbaseGetting;
	u16 	Pinc;
	u8  	LimitOutput;  //unit 32us
	u8	MaxOutput;	 //unit 32us
	u8	PITOOutput;	 //unit 32us
	u8	BaseOutput;	 //unit 32us
	u8	IBaseMinOutput;
	u8	Phase1Output;	 //unit 32us
	u8	Phase2Output;	 //unit 32us
	u8	Phase3StbAdd;
	u8	BaseOPGetTime;
	u8	BaseOutputSetDown;
	u8	BcnLossCount;
	u32 	DeltaTSFSum;  //unit us
} BCNEARLY_ADJUST_PID, *PBCNEARLY_ADJUST_PID;

typedef struct _Bcnearly_adjust_Stat_ {
	u32 	DeltaTSF;
	u32 	DeltaTSFMax;
	u32 	Per1_TSFOnRxBcn;
	u32 	Per2_TSFOnRxBcn;
	//u8      BcnMissMinRadio;
	u8      BcnDelay64us[128];
	u8      DelayCnt[128];
	u8 	Phase1MinSet;
	u8	Phase2CntFull;
	//u8	Phase3StbCK;
	u8	BcnLossCount;
	u32 	DeltaTSFSum;  //unit 32us
	u8	Phase1Cnt;
	u8	Phase1Output;	 //unit 32us
	u8	Phase2Cnt;
	u8	Phase2Output;	 //unit32us
	u8	Phase3Stbflag;
	u8	Phase3StbAdd;
	u8	LimitOutput;
} BCNEARLY_ADJUST_Stat, *PBCNEARLY_ADJUST_Stat;

typedef struct _LPSPG_PARM_ {
	u8      LpsPG_En;
	u32   	LPS_Option;
	u16 HIOE_STR_ADDR;
	u16 HIOE_END_ADDR;
	u8     	HioeRestoreDone: 1;
	u8     	HioeBackupDone: 1;
	u8	rsvd: 6;

} LPSPG_PARM, *PLPSPG_PARM;

typedef struct _PS_DBGPARM_ {
	//DW
	u8		DbgLpsSM[4];//state machine
	u16	IssueTxNull0;
	u16	TxNull0OK;
	u16	TxNull0Timeout;
	u16 	TxNull0Preempted;
	u16	IssueTxNull1;
	u16 	TxNull1OK;
	u16	TxNull1Timeout;
	u16	TxNull1Preempted;
} PS_DBGPARM, *PPS_DBGPARM;

/*------------------------------Function declaration--------------------------*/
extern void Change_PS_State_8730A(u8, u8);
extern u8 PS_S4_Condition_Match_8730A(void);
extern BOOLEAN PS_S2_Condition_Match_8730A(void);
extern BOOLEAN PS_32K_Condition_Match_8730A(void);
extern void PS_S2ToS3State_8730A(u8 nulldata0Allow);
extern void PS_S0ToS1State_8730A(void);
extern void SetBcnEarlyAndTimeout_8730A(u8 BcnAheadShift, u8 BcnEarlyShift, u8 BcnTimeout, u8 ReasonCode);
extern void EnlargeBcnEarlyAndTimeout_8730A(void);
extern void SmartPS2InitTimerAndToGetRxPkt_8730A(void);
extern void InitPS_8730A(void);
extern void SetSmartPSTimer_8730A(void);
extern void ChangePSStateByRPWM_8730A(void);
extern void PSBcnEarlyProcess_8730A(void);
extern void PSBcnAggEarlyProcess_8730A(void);
extern void PsBcnToProcess_8730A(void);
extern void TxPktInPSOn_8730A(void);
extern void PSSleepTo32K_8730A(void);
extern void PSRxBcnProcess_8730A(void);
extern void InitSAPPS_8730A(void);
extern void SAPPSTBTTHDL_8730A(void);
extern void SAPPSTimeOutHDL_8730A(void);
extern void SAPPSEarlyHDL_8730A(void);
extern void SAPLPS_8730A(void);
extern void InitInactivePS_8730A(void);
extern void InactivePSTBTTHDL_8730A(void);
extern void InactivePSBCNAggEarlyHDL_8730A(void);
extern void InactivePSEnableHEL_8730A(u8 op);
extern void InitBcnEarlyAdjustStat_8730A(void);
extern void BcnEarlyAdjustByDeltaTSFStat_8730A(void);
extern void InitBcnEarlyAdjustPID_8730A(void);
extern void BcnEarlyAdjustByDeltaTSFPID_8730A(void);
extern void LowPowerRxBeacon_8730A(BOOLEAN on);
extern void Set32KLpsOption_8730A(u32 *LpsControl, u8 CutPower);
#endif  //__WLAN_POWERSAVE_RAM_H__
