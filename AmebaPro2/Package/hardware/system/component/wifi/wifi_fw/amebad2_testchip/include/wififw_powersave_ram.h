#ifndef __WLAN_POWERSAVE_RAM_H__
#define __WLAN_POWERSAVE_RAM_H__


/*--------------------------Define -------------------------------------------*/
//#define MACID_CLIENT        0
#define MAX_CFG_FILE        5
#define SS 		    1
#define PS_32K_IN               BIT0
#define PS_32K_PG               BIT4

#define REG_SAPPS_DEBUG_DWORD1 			    REG_DBG_DWORD_2		//50
#define REG_SAPPS_DEBUG_DWORD2 			    REG_DBG_DWORD_4		//58
#define REG_SAPPS_DEBUG_DWORD3 			    REG_DBG_DWORD_5		//5A
#define REG_SAPPS_DEBUG_DWORD4 			    REG_DBG_DWORD_6

#define DEFAULT_PS_BCN_EARLY_MIN     1
#define DEFAULT_PS_BCN_EARLY   	     3
#define DEFAULT_PS_BCN_EARLY_128US   5
#define DEFAULT_PS_BCN_EARLY_32US    0
#define DEFAULT_PS_BCN_EARLY_32K   	 3
#define DEFAULT_PS_BCN_EARLY_128US_32K   2
#define DEFAULT_PS_BCN_EARLY_32US_32K    0

#define DEFAULT_PS_BCN_EARLY_V_32K   	 3
#define DEFAULT_PS_BCN_EARLY_V_128US_32K   3
#define DEFAULT_PS_BCN_EARLY_V_32US_32K    0

#define DEFAULT_BCN_TO_PERIOD_32K	 15
#define DEFAULT_PS_32K_EARLY(x)       	(((DEFAULT_PS_BCN_EARLY_V_32K+(x)) << 5)+(DEFAULT_PS_BCN_EARLY_V_128US_32K<< 2)+(DEFAULT_PS_BCN_EARLY_V_32US_32K))
#define BCN_PS_32K_SHIFT_MAX(x)        	(((DEFAULT_PS_BCN_EARLY_V_32K+(x)) << 5)+(DEFAULT_PS_BCN_EARLY_V_128US_32K<< 2)+(DEFAULT_PS_BCN_EARLY_V_32US_32K))
#define DEFAULT_PS_EARLY(x)       		(((DEFAULT_PS_BCN_EARLY+(x)) << 5)+(DEFAULT_PS_BCN_EARLY_128US<< 2)+(DEFAULT_PS_BCN_EARLY_32US))
#define BCN_PS_SHIFT_MAX(x)        		(((DEFAULT_PS_BCN_EARLY+(x)) << 5)+(DEFAULT_PS_BCN_EARLY_128US<< 2)+(DEFAULT_PS_BCN_EARLY_32US))

#define PS_TIM_NEW                          BIT5      //14
#if CONFIG_PS_DEBUG
#define DBG_LPS_WRITE(x,y)		(x = y)
#define DBG_LPS_INCREASE(x)		(++x)
#define DBG_LPS_SM(x,y) 			(SysMib.PSDbgParm.DbgLpsSM[x] = y)
#else
#define DBG_LPS_WRITE(x,y)
#define DBG_LPS_INCREASE(x)
#define DBG_LPS_SM(x,y)
#endif

/*------------------------------Define Enum-----------------------------------*/


typedef enum _SMART_PS_MODE_FOR_LEGACY_ {
	SMART_PS_MODE_LEGACY_PWR1           = 0,        // TRX all use PS_POLL
	SMART_PS_MODE_TX_PWR0               = 1,        // TX: pwr bit = 0, RX: PS_POLL
	SMART_PS_MODE_TRX_PWR0              = 2         // TX: pwr bit = 0, RX: NULL(0)
} SMART_PS_MODE_FOR_LEGACY, *PSMART_PS_MODE_FOR_LEGACY;


typedef enum _SMART_PS_MODE_FOR_UAPSD_ {
	SMART_PS_MODE_UAPSD                 = 0,
	SMART_PS_MODE_UAPSD_TX_QOSNULL      = 1
} SMART_PS_MODE_FOR_UAPSD, *PSMART_PS_MODE_FOR_UAPSD;

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

enum PS_MODE_OBJECTIVE {
	PS_MODE_OBJECTIVE_THROUGHPUT        = 0,
	PS_MODE_OBJECTIVE_BATTERY
};

typedef struct _SAPPS_PARM_ {
	u8      Enable: 1;
	u8      EnPS: 1;
	u8      EnLPRx: 1;
	u8      Manual32k: 1;   //revised by isaac on 20141202
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

typedef struct _NOLINK_Parm_ {
	u8      Enable: 1;
	u8      rsvd: 7;
	u8      CurrentFTIMR[4];
	u8      CurrentWLANIMR[4];

} NOLINKPSParm, *PNOLINKPSParm;

typedef struct _PG_PARM_ {

	u8      Enable;
	u32     LPS_Option;
	u8 	HIOESetDone;
	u32  	LPS32K_Time_Lock;
} PG_PARM, *PPG_PARM;

typedef struct _PS_BEADJ_V1_ {
	u8      curBcnEarly;        //unit 32us
	u8     minBcnEarly;     //unit 32us
	u16     minDeltaTSF;        //unit 1us
	u16     maxDeltaTSF;       //unit 1us
	u8     maxBcnTo;           //unit 1ms
	u16     curDeltaTSF;        //unit 1us
	u8      bToFlag;
	u8      count;
	u8      rxCount;
	u8      toCount;
	u8      bTryFlag;
	u8      adjStep;            //unit 32us
	u8      toAdjStep;          //unit 32us
	u8      rxCntLimit;
	u8      rxCntForTo;
	u16     tmpBcnTo;          //unit 32us

} PS_BEAdj_V1, *PPS_BEAdj_V1;

#if 0 //bcnpid test 1
typedef struct _Bcnearly_adjust_PID_ {
	u32 DeltaTSFSum;  //unit us
	u32 PerDeltaTSF;  //unit us
	u32 PerError;
	u32 Error;
	u32 Per1_TSFOnRxBcn;
	u32 Per2_TSFOnRxBcn;
	u16 Pinc;
	u16 Pbase;
	u8  PbaseGetTime;
	u32 PbaseSum;
	u16 PbasePart;
	u8  Output;
	u8  LimitOutput;  //unit 128us
	u8  LimitOPGetTime;
	u8  LimitOutputSetDown;
	u32 LimitMinDeltaTSF;
	u32 LimitMaxDeltaTSF;
	u8  MaxOutput;   //unit 128us
	u8  PbaseGetting;
	u8  BcnLossCount;

} BCNEARLY_ADJUST_PID, *PBCNEARLY_ADJUST_PID;
#else //bcnpid test 2
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
	u8  	LimitOutput;  //unit 128us
	u8	MaxOutput;	 //unit 128us
	u8	PITOOutput;	 //unit 128us
	u8	BaseOutput;	 //unit 128us
	u8	IBaseMinOutput;
	u8	Phase1Output;	 //unit 128us
	u8	Phase2Output;	 //unit 128us
	u8	Phase3StbAdd;
	u8	BaseOPGetTime;
	u8	BaseOutputSetDown;
	u8	BcnLossCount;
	u32 	DeltaTSFSum;  //unit us

} BCNEARLY_ADJUST_PID, *PBCNEARLY_ADJUST_PID;
#endif

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
	u32 	DeltaTSFSum;
	u8	Phase1Cnt;
	u8	Phase1Output;	 //unit 32us
	u8	Phase2Cnt;
	u8	Phase2Output;	 //unit32us
	u8	Phase3Stbflag;
	u8	Phase3StbAdd;
	u8	LimitOutput;

} BCNEARLY_ADJUST_Stat, *PBCNEARLY_ADJUST_Stat;

typedef struct _LPSPG_PARM_ {
	//DW
	u16 HIOE_STR_ADDR;
	u16 HIOE_END_ADDR;


	u32 DPK_FlowTableSel;


	u32 s0_rck_data;
	u32 s0_lok_data;
	u32 s0_acc_data2;

	u32 tx_gapk[11];

	u32 s0_x2k_data1;
	u32 s0_x2k_data2;
	u32 s0_x2k_data3;
	u32 s0_x2k_data4;

	u32	 RF1F;
	u32	 RF18;
	u32	 RF1E;
	u32	 RF20;

	u32 RXAS0LNACurLev;
	u32 RXGS0LNACurLev;
	u32 RXAS0PABiasofst;
	u32 RXGS0PABiasofst;

	u32 TXIQC_DATA;
	u32 RXIQC_DATA1;
	u32 RXIQC_DATA2;

	u32 DPK_GSDATA;
	u32 DPK_PWSF_OFFSET_DATA;
	u32 DPK_BND_DATA;
	u32 DPD_STATUS_DATA;
	u32 DPD_STATUS_DATA2;

	u32 Page43[48];

#if 0
	//DW
	u32     BakTxbufSA;//txbuf rsvdpage backup start addr
	u32     BakTxbufLen;
	u32     BakTxbufDmemLoc;//txbuf rsvdpage backup to the address in dmem
	u32     ofset;//ddma backup/restore temp offset
	u32     ofset_dbg;//ddma backup/restore offset

	//u8      DdmaDoneVal;

	//backup reg/data
	u32     gpr_sp;
	u32     gpr_ra;
	//u32     LpsBakData[LPS_BAK_SECTION_NUM][LPS_BAK_CONTENT_NUM];//[address][size]
	//u32     LpsBakData1[LPS_BAK_SECTION_NUM_IO][2];//reg offset, reg value
	//u32     LpsBakData2;//LTE addr 0x38
	//u32     LpsBakCAMData[LPS_BAK_SECCAM_ENTRY_NUM][6]; // 1st array->entry number, 2nd array->entry size
	//u32     LpsBakCAMData2[LPS_BAK_SECCAM_DEF_KEY_NUM][6]; //backup default key in wowlan
	//u32     LpsBakWKFMCAMData[LPS_BAK_WKFMCAM_ENTRY_NUM][LPS_BAK_WKFMCAM_ENTRY_SZ]; // 1st array->entry number, 2nd array->entry size
	//u32     RF18[2];
	//u32     BACAMdata[64][2];//total 32 entry = 64 addr = 128 dword
	//u8      LpsBakMbssidCAMData[8][6];
	//DW
	u16     Reg424;
	u16     dbggprofset;
	u32     Reg4D8;
	u32     Reg4DC;
	u32     Reg210;
	u32     Reg288;
	u32     Reg1114;
	u32		Reb1B20[SS];
	u8      Reg1C7;
	u8      Reg690;
	u8      Reg4E2;
	u8      Reg1F;
	u8      Reg1C24_BIT0; //backup/restore for close/openRF 0x1c24 check
	u8      Regrsvd1;
	u8      Regrsvd2;
	u8      Regrsvd3;

	u32      RF18S1;
	u32      RF1ES1;
	u32      RF1FS1;
	u32      RF20S1;

	u32 s0_acc_data1;
	u32 s1_lok_data;

	u32 s0_rf_5;
	u32 s1_rf_5;

	u32 RXGS1LNACurLev;
	u32 RXGS1PABiasofst;


	u8 DPK_FlowTableSel;
	u8 DPK_Rsvd0;
	u8 DPK_Rsvd1;
	u8 DPK_Rsvd2;
	u32 DPK_LUT_EVEN_DATA[16];
	u32 DPK_LUT_ODD_DATA[16];

#endif
} LPSPG_PARM, *PLPSPG_PARM;

/*------------------------Export global variable------------------------------*/

/*------------------------------Function declaration--------------------------*/
extern void
Change_PS_State_8721D_RAM(
	IN  u8,
	IN  u8
) ;

extern u8
PS_S4_Condition_Match_8721D_RAM(
	void
);

BOOLEAN
PS_S2_Condition_Match_8721D_RAM(
	void
);

extern void PS_S2ToS3State_8721D_RAM(u8 nulldata0Allow);
extern void PS_S0ToS1State_8721D_RAM(void);
extern void SmartPS2InitTimerAndToGetRxPkt_8721D_RAM(void);

extern void
InitPS(
	void
) ;

extern void
PSModeSetting_8721D_RAM(
	IN u8 on
) ;

extern void
PS_OnBeacon(
	void
) ;

extern void
ChangePSStateByRPWM(
	void
);

extern void
PSBcnEarlyProcess(
	void
);

extern void
PSBcnAggEarlyProcess(
	void
);

extern void
PsBcnToProcess(
	void
) ;

extern void
PSBcnEarlyC2H(
	BOOLEAN bDTIM
) ;

extern void
KeepRfOnForReceiving(
	void
);

extern void
TxPktInPSOn(
	void
);

extern void
PwrGatedInitRadioA(
	void
);

extern void
PwrGatedInitBB(
	void
);

extern void
PSSleepTo32K(
	void
);

extern void
PS_RFoffTo32KToRFoffState(
	void
) ;

void
PSRxBcnProcess(
	void
);

void
InitSAPPS(
	void
) ;

void
SAPPSTBTTHDL(
	void
) ;

void
SAPPSTimeOutHDL(
	void
) ;

void
SAPPSEarlyHDL(
	void
) ;

void
InitInactivePS(
	void
) ;

void
InactivePSTBTTHDL(
	void
) ;

void
InactivePSBCNAggEarlyHDL(
	void
) ;

void
InactivePSEnableHEL(
	IN u8 op
) ;

void
NoLinkPSEnableHEL(
	IN u8 op
) ;

void
InitBcnEarlyAdjustParm(
	void
);

void
BcnEarlyAdjustByTSF(
	void
);

void
InitBcnEarlyAdjustPID(
	void
);

void
BcnEarlyAdjustByDeltaTSFPID_8721D(
	void
);

void
InitBcnEarlyAdjustStat(
	void
);

void
BcnEarlyAdjustByDeltaTSFStat_8721D(
	void
);

void
BcnEarlyAdjustByDeltaTSFPID_DTIMMAX_8721D(
	void
);

void
RestoreNoLinkPSHEL(
	void
) ;

void
LowPowRx(
	u8 enable
) ;

void
SAPLPS(
	void
) ;

extern void
LowPowerRxBeacon(
	BOOLEAN on
);

extern void
SetBcnEarlyAndTimeout_8721D_RAM(
	u8 BcnAheadShift,
	u8 BcnEarlyShift,
	u8 BcnTimeout,
	UNUSED_WARN_DIS u8 ReasonCode
);

void
EnlargeBcnEarlyAndTimeout_8721D_RAM(
	void
);

void
Legacy_PS_Setting_8721D_RAM(
	void
);

#endif  //__WLAN_POWERSAVE_RAM_H__
