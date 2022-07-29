#ifndef __RTL8721D_BTCONCURR_H__
#define __RTL8721D_BTCONCURR_H__

#ifndef __ASSEMBLY__
/*--------------------Define --------------------------------------------*/
#define DefaultTBTTOnPeriod 0xB
#define DefaultMedOnPeroid  0x8
#define MaxTBTTOnPeriod     0x2A   // 0X16
#define MaxMedOnPeroid      0x2A   // 0X16
#define MinTBTTOnPeriod     0x3
#define MinMedOnPeroid      0x3
#define NULL_EARLY          0x3
#define REDUCTIONPERIOD     0x5
#define DefaultRCount       0x4
#define DOWN                0
#define UP                  1
#define MAILBOX_MAX_LENGTH  7
#define EXTENSIONTHRESHOLD  65
#define NORESPONSELIMIT     5
#define SLOT_WIFI           0
#define SLOT_BT             1
#define DEFAULTSETTING      3

#define MAILBOX_STATUS	0


#define SCO_eSCO_slot_unit	320	//320us
#define SCO_eSCO_timer_unit	32	//32us	

#define WLAN_ON             0
#define WLAN_OFF            1

typedef enum _MAILBOX_STATUS_ {
	BT_Active_OutReady_not_zero	= BIT0,
	BT_Non_Ative				= BIT1,
	BT_Patch_Timeout			= BIT2,
	BT_Content_Error			= BIT3,
	BT_Content_Checksum_error	= BIT4,
} MAILBOX_STATUS_ENUM;

#define ANT_CTRL_BY_PTA     0x66
#define ANT_CTRL_BY_BBSW    0x77

#define ANT_TOGGLE_WIFI     0x20000000
#define ANT_TOGGLE_BT       0x10000000

#define MAILBOX_RTY_LMT     4

#define RSP_WIFI_FW         0
#define RSP_WIFI_REQ        1
#define RSP_BT_CHANGE_STS   2

#define SEL_COEX_TABLE_1    0x03//0x6c0  bit[1:0]=2'b11
#define SEL_COEX_TABLE_2    0xFC//0x6c4  bit[1:0]=2'b00

#define ONBT                0
#define ONWIFI              1
#define NOCHANGE            2
#define ONBBSW              0
#define ONPTA               1

#define DACSWING_ADDR       0x880
#define DACSWING_SHF        25
#define DACSWING_MASK       0xC1ffffff

#define BTPATCH_STATUS      REG_BT_Cal_Ind  //0x49d[7:6]
#define BTNRDY              BIT6
#define BTRDY               BIT7

#define MAILBOXIVT          0xA


/*--------------------Define Enum---------------------------------------*/

typedef enum _MAILBOX_CMD_ {
	MBID_HW_CHANGE_INFO0      = 0x00,
	MBID_HW_CHANGE_INFO1      = 0x01,
	MBID_HW_CHANGE_INFO2      = 0x02,
	MBID_HW_CHANGE_INFO3      = 0x03,
	MBID_HW_CHANGE_INFO4      = 0x04,
	MBID_HW_CHANGE_INFO5      = 0x05,
	MBID_HW_CHANGE_INFO6      = 0x06,
	MBID_HW_CHANGE_INFO7      = 0x07,
	MBID_HW_CHANGE_INFO8      = 0x08,
	MBID_TBT                  = 0x0E,
	MBID_RPT_RSSI             = 0x0F,
	MBID_CFO                  = 0x15,
	MBID_PSD_CTRL             = 0x21,
	MBID_RPT_INFO             = 0x23,
	MBID_V_RPT_INFO           = 0x27,
	MBID_MP_RPT               = 0x30,
	MBID_BT_CAL               = 0x34,
} MAILBOX_CMD_ENUM;

/*--------------------Define MACRO--------------------------------------*/

#define MAILBOX_TIMERINT_MASK BIT_FS_GTINT6_INT_EN
#define MAILBOX_TIMER_MASK    REG_TC6_CTRL

/*--------------------Define Struct---------------------------------------*/

typedef struct _BTOption_Parm_ {
	u8              BTOptionMode;
} BTOption_Parm, *PBTOption_Parm;

typedef struct _PSD_Control_Parm_ {
	u8      enable;
} PSD_Control_Parm, *PPSD_Control_Parm;

typedef struct _PTA_Parm_ {
	u8      data0;
	u8      data1;
	u8      data2;
	u8      data3;
	u8      data4;
	u8      data5;
} PTA_Parm, *PPTA_Parm;

typedef struct _Report_Parm_ {
	u8      data0;
	u8      data1;
	u8      data2;
	u8      data3;
	u8      data4;
	u8      data5;
	u8      data6;
} Report_Parm, *PReport_Parm;

typedef struct _BTTxStatus_Parm_ {
	u8      StatusWLOpmode: 1;
	u8      StatusWLOpmodeTx: 1;
	u8      StatusBTInfo: 1;
	u8      StatusBTInfoTx: 1;
	u8      StatusIgnoreWLAct: 1;
	u8      StatusIgnoreWLActTx: 1;
	u8      StatusBTMP: 1;
	u8      StatusBTMPTx: 1;
	u8      StatusAutoRPT: 1;
	u8      StatusAutoRPTTx: 1;
	u8      rsvd: 6;
	u8      BTInfo;
	u8      IgnoreWLAct;
	u8      AutoRPT;
	u8      BTMPContent[5];
} BTTxStatus_Parm, *PBTTxStatus_Parm;

typedef struct _BT_B_TYPE_TDMA_Parm_ {
	//B0
	u8      Enable                  : 1;
	u8      ValueofReg870InBT       : 1;    //1:0x870 = 0x300, 0:0x870 = 0x310

	u8      HIDSlotToggle     : 1;

	u8      ValueOfReg870           : 1;    // when disable 1:0x870 = 0x310, 0:0x870 = 0x300
	//when enable 1: 0x860 = 0x110, 0:0x860 = 0x210
	u8      AutoWakeUp              : 1;		//when set 1, use null(0) and null(1) packet
	u8      NoPS                    : 1;			//when set 1, in BT slot will pause WiFi Tx
	u8      AllowBTHighPriority     : 1;
	u8      ValueofReg870InWIFI     : 1;    //1:0x870 = 0x300, 0:0x870 = 0x310
	//B1
	u8      TBTTOnPeriod;
	//B2
	u8      MedPeriod;
	//B3
	u8      NoTxPause               : 1;
	u8      Valueof778InWIFI        : 1;
	u8      Valueof778InWIFIOnSCO   : 1;
	u8      ValueofReg778           : 1;    //when disable 1: 778=3, 0: 778=1
	//when enable 1:allow 32k, 0:not allow 32k
	u8      SCOOption               : 1;
	u8      ValueofReg860InWIFI     : 1;
	u8      TwoAntenna              : 1;
	u8      ReduceWIFIPower         : 1;
	//B4
	u8      ExtraDecisonOf778             : 1;

	u8      CCK_Priority_toggle   : 1;

	u8      WifiAutoSlot            : 1;

	u8		CTS2Self				  : 1;
	u8      mChangeCoexTable         : 1;            //name modified by jackie liu, ChangeCoexTable->mChangeCoexTable
	u8      LongNAV                 : 1;			// use large NAV to protect BT slot
	u8      FlexibleExtension       : 1;
	u8      ValueofReg778B1InBT     : 1;       // 1:778[1]=1, 0:778[1]=0 in bt

	//DHCP
	u8      DtimExt;
	u8      DHCPOn                  : 1;
	u8      NoRxBCNCondition        : 1;
	u8      Write860                : 1;
	u8      Value860                : 1;

	u8      DTIMFlag                : 1;
	u8      WifiActive              : 1;
	u8      rsvd2                   : 2;

	u8      BTTxAbort               : 1;
	u8      TxNull1                 : 1;
	u8      TxNull1ok               : 1;
	u8      rsvd3                   : 5;

	u8      WLANPeriodTemp;
	u8      ExtensionThreshold1;
	u8      ExtensionThreshold2;
	u8      ExtensionThreshold3;
	u8      HalfTBTTOnPeriod;
	u8      HalfMedPeriod;
	u8      RNum;
	u8      RCount;
	u8      HalfBCNIvl;
	u8      BCNIvl;
	u8      WLANOnPeriod;
	u8      WLANPeriodCount;
	u8      InitialBTPower;
	u8      ExtensionCount;
	u8      NullExtensionCount;
	u8      NAVTemp;
	u8      TxCounter;
	u8      BTConnect;
	u8      BTRptConnect;
	u8      BTChangeType: 1;
	u8      BTCTCount: 4;
	u8      BTCTCTh: 3;
	u32     ValueBackup;
	u8      ValueBackup2;
	u8      ValueBackup3;
	u8      ValueBackup4;
	u8      MailboxRdy;
	u8      BTDisable;
	u8      RxExtension             : 1;
	u8      WLCalibrationEn         : 1;
	u8      GNT_BT_Val              : 1;
	u8      BTOnlyTest              : 1;
	u8      DynamicSlotBackup       : 1;
	u8      PanProtection           : 1;
	u8      rsvd4: 2;
	u16     Reg948Backup;
	BTTxStatus_Parm BTTxStatus;

	u8      extensionthreshold;

	u32      HIDPTATable;
	u32      HIDPTATableBackUp;
	u8      HIDPTATableEn;
	u8      HIDSlotCnt;
	u8      HIDPTATableInterval;


} BT_B_TYPE_TDMA_Parm, *PBT_B_TYPE_TDMA_Parm;

//H2C Index: 0x60
typedef struct _BT_MAILBOX_Parm_ {
	u8          signal_ant_en: 1;
	u8          DAC_swing_en: 1;
	u8          NAV_en: 1;
	u8          TDMA_En: 1;
	u8          rvsd: 4;

	u8          bt_rssi_init_value;
	u8          bt_rssi_current_value;
	u32         DAC_swing_level;
	u32         DAC_swing_init_value;
	u8          init_value_0x2e;
	u8          init_value_0x2d;
	u8          OneAntSCOEnable;
	u8          BTNoResponseCount;
	u8          AntSelReverse;
	u8          SwitchOutside;
	u8          RAOffsetEn;
	u8          RAOffset;
	u8          RAOffsetMCS7;
	u8          RAOffsetMCS6;
	u8          RAOffsetMCS5;
	u8		 BTCalibration: 1;
	u8           rsvd1: 7;
	u8		 BTCalibrationPeriod;

} BT_MAILBOX_Parm, *PBT_MAILBOX_Parm;

//H2C Index: 0x61
typedef struct _BT_Info_Parm_ {
	u8          trigger;
} BT_Info_Parm, *PBT_Info_Parm;


//H2C Index: 0x62
typedef struct _Force_BT_Txpwr_Parm_ {
	u8          pwr_idx;
} Force_BT_Txpwr_Parm, *PForce_BT_Txpwr_Parm;

//H2C Index: 0x63
typedef struct _BT_Ignore_WlanAct_Parm_ {
	u8          enable;
} BT_Ignore_WlanAct_Parm, *PBT_Ignore_WlanAct_Parm;


//H2C Index: 0x64
typedef struct _DAC_Swing_Value_Parm_ {
	u8          value;
} DAC_Swing_Value_Parm, *PDAC_Swing_Value_Parm;


//H2C Index: 0x65
typedef struct _Ant_Sel_Reverse_Parm_ {
	u8          Reverse;
	u8          SwitchOutside;
} Ant_Sel_Reverse_Parm, *PAnt_Sel_Reverse_Parm;

//H2C Index: 0x66
typedef struct _WLAN_Opmode_Parm_ {
	u8          opmode; // RT_MEDIA_STATUS
	u8          chl_idx;
	u8          bw;

	u8          rsvd[4];
} WLAN_Opmode_Parm, *PWLAN_Opmode_Parm;


//H2C Index:0x6C
typedef struct _H2CHDL_BT_Page_Scan_Interval_Parm_ {
	u8	LSB_Interval;
	u8	MSB_Interval;
} BT_Page_Scan_Interval_Parm, *PBT_Page_Scan_Interval_Parm;

typedef struct _H2CHDL_BT_Init_Parm_ {
	u8  Enhance3wireMode: 1;
	u8  HighPowerPAMode: 1;
	u8  rsvd: 6;
} BT_Init_Parm, *PBT_Init_Parm;

/*--------------------Export global variable-------------------------------*/

/*--------------------Function declaration---------------------------------*/
extern void
BTRoleChangeTimerHDL_8721D_ROM(
	void
);

extern void
BTRoleChangeTBTTHDL_8721D_ROM(
	void
);

extern void
FillMailbox_8721D_ROM(
	IN  u8 cmd,
	IN  u8 length,
	IN  u8 *pparm
);

extern u8
WL2BTMailbox_8721D_ROM(
	IN  u8 cmd,
	IN  u8 length,
	IN  u8 *pparm
);

extern void
MailboxINTHDL_8721D_ROM(
	void
);

extern void
BTMailboxRetry_8721D_ROM(
	void
);

extern void
H2CHDL_BTInfo_8721D_ROM(
	IN  u8  *pbuf
);

extern void
H2CHDL_ForceBTTxpwr_8721D_ROM(
	IN  u8  *pbuf
);

extern void
H2CHDL_BTIgnoreWlanAct_8721D_ROM(
	IN  u8   *pbuf
);

extern void
H2CHDL_DACSwingValue_8721D_ROM(
	IN  u8   *pbuf
);

extern void
H2CHDL_AntSelReverse_8721D_ROM(
	IN  u8   *pbuf
);

extern void
H2CHDL_WLOpmode_8721D_ROM(
	IN  u8   *pbuf
);

extern void
H2CHDL_BTMpH2C_8721D_ROM(
	IN  u8   *pbuf
);

extern void
H2CHDL_BTControl_8721D_ROM(
	IN  u8   *pbuf
);

extern void
H2CHDL_BTWifiCtrl_8721D_ROM(
	IN  u8  *pbuf
);

extern void
H2CHDL_BTFwPatch_8721D_ROM(
	u8 *pbuf
);

extern void
H2CHDL_BT_Page_Scan_Interval_8721D_ROM(
	u8 *pbuf
);

extern void
H2CHDL_WLCalibration_8721D_ROM(
	u8 *pbuf
);

extern void
H2CHDL_GNT_BT_CTRL_8721D_ROM(
	u8 *pbuf
);

extern void
H2CHDL_BT_ONLY_TEST_8721D_ROM(
	u8 *pbuf
);

extern void
H2CHDL_BT_Init_Param_8721D_ROM(
	u8 *pbuf
);

extern void
C2HBTInfo_8721D_ROM(
	IN  u8  option
);

extern void
C2HBTLoopback_8721D_ROM(
	IN  u8  *pbuf
);

extern void
C2HBTMpRpt_8721D_ROM(
	IN  u8  idx,
	IN  u8  status,
	IN  u8  req_num
);

extern void
C2HBTMailBoxStatus_8721D_ROM(
	IN  u8  status
);

extern void
InitBTMailbox_8721D_ROM(
	void
);

extern void
InitBTypeTDMA2_8721D_ROM(
	void
);

extern void
InitBTCoexTimer_8721D_ROM(
	IN  u8 duration
);

extern void
Write778_8721D_ROM(
	IN u8 value
);

extern void
ChangeCoexTable_8721D_ROM(
	IN  u8  slot
);

extern void
DacSwing_8721D_ROM(
	IN u8 action
);

extern void
BTNullSetting_8721D_ROM(
	IN  u8  bPowerBit,
	IN  u16 offset,
	IN  u8  lsb,
	IN  u8  msb
);

extern void
IssueBTQNull_8721D_ROM(
	IN  u8  bPowerBit,
	IN  u8  lsb,
	IN  u8  msb
);

extern void
WlanActCtrl_8721D_ROM(
	void
);

extern void
BT_TDMA_Slot_Operation_0and3_8721D_ROM(
	IN	u8	slot_num
);

extern void
BT_TDMA_Slot_Operation_1and4_8721D_ROM(
	IN	u8	slot_num
);

extern void
BT_TDMA_Slot_Operation_2and5_8721D_ROM(
	IN	u8	slot_num
);

extern void
FlexibleExtensionDecision_8721D_ROM(
	void
);

extern void
BTypeTDMABCNEarly_8721D_ROM(
	void
);

extern void
BTypeTDMATBTThdl_8721D_ROM(
	void
);

extern void
BTypeTDMATimeOuthdl_8721D_ROM(
	void
);

#endif   //#ifndef __ASSEMBLY__

#endif  //__RTL8721D_BTCONCURR_H__
