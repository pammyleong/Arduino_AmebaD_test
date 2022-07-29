#ifndef __WIFIFW_CMD_RAM_H__
#define __WIFIFW_CMD_RAM_H__

/*--------------------Define --------------------------------------------*/
//Register H2C Command ID here
typedef enum _H2C_CMD_ {
	//1 Class1: Common
	H2CID_RSVDPAGE              = 0x00,
	H2CID_JOININFO              = 0x01,
	H2CID_SCAN                  = 0x02,
	H2CID_KEEP_ALIVE            = 0x03,
	H2CID_DISCONNECT_DECISION   = 0x04,
	H2CID_PSD_OFFLOAD           = 0x05,
	H2CID_Customer_string_rpt   = 0x06,
	rsvd3                       = 0x07,
	H2CID_AP_OFFLOAD            = 0x08,
	H2CID_BCN_RsvdPage          = 0x09,
	H2CID_Probersp_RsvdPage     = 0x0A,
	H2CID_TXPower_Index_Offlaod = 0x0B,
	H2CID_AP_PS_OFFLOAD         = 0x0C,
	H2CID_AP_PS_OFFLOAD_CTRL    = 0x0D,
	H2CID_ECSA                  = 0x0F,

	H2CID_FAST_CS_RSVDPAGE      = 0x10,
	H2CID_FAST_CHANNEL_SWITCH   = 0x11,
	H2CID_BB_GAIN_REPORT        = 0x12,
	H2CID_GPIO_CTRL             = 0x13,
	H2CID_HW_INFO               = 0x14,
	H2CID_MCC_RQT_TSF      = 0x15,
	H2CID_MCC_MACID_BITMAP      = 0x16,
	H2CID_MCC_CTRL              = 0x18,
	H2CID_MCC_TIME_PARAM         = 0x19,
	H2CID_MCC_IQK_PARAM         = 0x1A,
	H2CID_NAN_CTRL              = 0x1B,
	H2CID_SINGLE_CHANNEL_SWITCH = 0x1C,
	H2CID_SINGLE_CHANNEL_SWITCH_V2 = 0x1D,
	H2CID_TX_PAUSE_DRV_INFO		= 0x1E,
	H2CID_MACID_PAUSE_DRV_INFO  = 0x1F,


	//1 Class2: Power Save
	H2CID_SETPWRMODE            = 0x20,
	H2CID_PSTURNINGPARM         = 0x21,
	H2CID_PSTURNINGPARM2        = 0x22,
	H2CID_PSLPSPARM             = 0x23,
	H2CID_P2PPS_OFFLOAD         = 0x24,
	H2CID_PS_SCAN               = 0x25,
	H2CID_SAPPS                 = 0x26,
	H2CID_INACTIVE_PS           = 0x27,
	H2CID_NOLINK_PS             = 0x28,
	H2CID_PARTIAL_OFF_CTRL   = 0x29,
	H2CID_PARTIAL_OFF_PARM  = 0x2A,
	H2CID_S1_NULL1_CTRL         = 0x3F,

	/*//1 Class3: Dynamic Mechaism
	H2CID_MACID_CFG             = 0x40,
	H2CID_TxBF                  = 0x41,
	H2CID_RSSI_SETTING          = 0x42,
	H2CID_AP_REQ_TXRPT          = 0x43,
	H2CID_INIT_RATE_COLLECT     = 0x44,
	H2CID_IQK_OFFLOAD           = 0x45,
	H2CID_MACID_CFG_3SS         = 0x46,
	H2CID_RA_PARA_ADJUST        = 0x47,
	H2CID_DYNAMIC_TX_PATH       = 0x48,
	H2CID_FW_TRACE_EN           = 0x49,*/


	//1 Class4: BT Coex

	H2CID_B_TYPE_TDMA           = 0x60,
	H2CID_BT_INFO               = 0x61,
	H2CID_FORCE_BT_TXPWR        = 0x62,
	H2CID_BT_IGNORE_WLANACT     = 0x63,
	H2CID_DAC_SWING_VALUE       = 0x64,
	H2CID_ANT_SEL_REVERSE       = 0x65,
	H2CID_WL_OPMODE             = 0x66,
	H2CID_BT_MP_OPERATION       = 0x67,
	H2CID_BT_CONTROL            = 0x68,
	H2CID_BT_WIFICTRL           = 0x69,
	H2CID_BT_PATCH_DOWNLOAD     = 0x6A,
	H2CID_BT_SCO_eSCO_OPERATION	= 0x6B,
	H2CID_BT_Page_Scan_Interval = 0x6C,
	H2CID_WL_Calibraion         = 0x6D,
	H2CID_GNT_BT_CTRL           = 0x6E,
	H2CID_BT_ONLY_TEST          = 0x6F,
	H2CID_BT_INIT_PARAM         = 0x70,
	H2CID_WL_PORT_ID            = 0x71,


	//1 Class5: WOWLAN
	H2CID_WoWLAN                = 0x80,
	H2CID_RemoteWakeCtrl        = 0x81,
	H2CID_AOAC_Global_info      = 0x82,
	H2CID_AOAC_Rsvdpage1        = 0x83,
	H2CID_AOAC_Rsvdpage2        = 0x84,
	H2CID_D0_Scan_offload_info  = 0x85,
	H2CID_D0_Scan_offload_ctrl  = 0x86,
	H2CID_Switch_channel        = 0x87,
	H2CID_AOAC_Rsvdpage3        = 0x88,
	H2CID_GPIO_WF_Customize     = 0x89,
	H2CID_P2P_RsvdPage          = 0x8A,
	H2CID_P2P_Offload           = 0x8B,

	//1 Class6: LTECOEX
	H2CID_LTECOEX_EN            = 0xA0,
	H2CID_WLAN_High_Priority    = 0xA1,

	H2CID_FTM                   = 0xB0,
	H2CID_FTMRPT                = 0xB1,

	//1 Class7: Patch
	H2CID_TSF_RESET             = 0xC0,
	H2CID_BB_NHM                = 0xC1,
	H2CID_BCN_Ignore_EDCCA      = 0xC2,
	H2CID_Efuse_Hidden_Request  = 0xC3,
	H2CID_APoffload_MultiWakeupPulse = 0xC4,
	H2CID_BCN_HWSEQ	        = 0xC5,   //8814A BCN HWSEQ issue for Seam
	H2CID_Customer_string1      = 0xC6,
	H2CID_Customer_string2      = 0xC7,
	H2CID_Customer_string3      = 0xC8,
	H2CID_IOTDRV_CloseRF      = 0xCF,
	//1 Class8: Testing
	H2CID_H2C2HLB               = 0xE0,
	H2CID_FW_Verification       = 0xE4,

	//1 Class9:FW Offload
	CMD_ID_FW_OFFLOAD_H2C       = 0xFF
} H2C_CMD, *PH2C_CMD;

typedef enum _C2H_CMD_SUBID_ {
	C2HEXTID_DEBUG_PRT          = 0,


} C2H_CMD_SUBID, *PC2H_CMD_SUBID;

/*--------------------------Define MACRO--------------------------------------*/
#define LENGTH_H2C              8

#define LENGTH_C2HEXT_EVT_HDR   4
#define LENGTH_C2HEXT_BUFF      32
#define LENGTH_C2HEXT_CONTENT   100  //128-24-4 
#define C2HEXTPTR_REACH_BOTTOM(x)  (((x) == LENGTH_C2HEXT_BUFF) ? _TRUE : _FALSE)
#define C2HEXT_Q_EMPTY(x, y)       (((x) == (y)) ? _TRUE : _FALSE)
#define C2HEXT_Q_FULL(x, y)        (((((x) == 0) && ((y) == (LENGTH_C2HEXT_BUFF - 1)))||((y) == ((x) - 1))) ? _TRUE : _FALSE)

// DRV_FW_INTF
#define DRV_FW_EN               BIT7
#define DRV_FW_RWM              BIT6
#define BYTE_CNT               	(BIT0|BIT1|BIT2)

#define DRV_FW_MODE            	(BIT5|BIT4)

#define MODE_SRAM               0
#define MODE_TXBUF              0x10
#define MODE_RXBUF              0x20

//#define FSM_MON_BT_DBG          0x5
//#define BT_ACTIVE_MODE          0x4

//#define SIGNAL_SEND_ISR         0
//#define SIGNAL_SEND_OS          1

//#define BT_ANT_TDMA_FUNC_EN         BIT0
//#define BT_ANT_TDMA_SINGLE_ANT      BIT1
//#define BT_ANT_TDMA_NAV_EN          BIT2
//#define BT_ANT_TDMA_DAC_SWING_EN    BIT4

//#define WLCALIBRATION           0x1e7
// FCS
#define FCS_REQ_END             0xF


#define FIX_DELAY_FORWARD	BIT5

//MACID Drop Action
#define MACID_DROP_DISABLE      0
#define MACID_DROP_ENABLE       1

/*------------------------------Define Struct---------------------------------*/
//================H2C command format====================
typedef struct _H2C_CMD_HDR {
	u8 cmd_id;
} H2C_CMD_HDR, *PH2C_CMD_HDR;

typedef struct _C2HEXT_EVT_HDR {
	u8  cmd_id;
	u8  cmd_seq;
	u8  subid;
	u8  cmd_len;//content len
	u8  content[LENGTH_C2HEXT_CONTENT];
} C2HEXT_EVT_HDR, *PC2HEXT_EVT_HDR;

//3 Class1: Common

//H2C Index: 0x0
typedef struct _H2CParam_RsvdPage_ {
	RsvdPageLoc loc;
} H2CParam_RsvdPage, *PH2CParam_RsvdPage;


//H2C Index: 0x1
typedef struct _H2CParam_JoinInfo_ {
	BOOLEAN     bConnected: 1;
	BOOLEAN     bMacid_ind: 1;
	u8          Miracast: 1;
	u8          Miracast_role: 1;
	u8          Macid_Dest_Role: 4;
	u8          macid;
	u8          macid_end;
} H2CParam_JoinInfo, *PH2CParam_JoinInfo;


//H2C Index: 0x2
typedef struct _H2CParam_Scan_ {
	BOOLEAN            bScan;
	BOOLEAN            bNIC;           // 1: NIC, 0: AP
} H2CParam_Scan, *PH2CParam_Scan;

//H2C Index: 0x3
typedef struct _keep_alive_parm_ {
	u8          Enable: 1;
	u8          AdoptUserSetting: 1;
	u8          PktType: 1;
	u8          rsvd: 4;
	u8          KeepAliveNullTx: 1;

	u8          KeepAliveCountLimit;
	u8          KeepAliveCount;
	u8          SameTBTTRsvdPageCount;
} KeepAlive_Parm, *PKeepAlive_Parm;

//H2C Index: 0x4
typedef struct _disconnect_parm_ {
	u8          Enable: 1;
	u8          AdoptUserSetting: 1;
	u8          TryOkBcnFailCountEn: 1;
	u8          DisconnectEN: 1;
	u8          rsvd: 4;
	u8          DisconnectCountLimit;
	u8          TryPKTCountLimit;
	u8          TryOkBcnFailCountLimit;
	//------------------------------------
	u8          DisconnectCount;
	u8          TryPKTCount;
	u8          BCNCount;
	u8          WHCKPatchEn;
} Disconnect_Parm, *PDisconnect_Parm;

//H2C Index: 0x12
typedef struct _H2CParam_BB_Gain_RPT_ {
	u8 enable;
} H2CParam_BB_Gain_RPT, *PH2CParam_BB_Gain_RPT;

//H2C Index: 0x13
typedef struct _H2CParam_GPIO_CTRL_ {
	u8 gpioidx: 4;
	u8 c2hen: 1;
	u8 pulse: 1;
	u8 highactive: 1;
	u8 en: 1;
	u8 duration: 7;
	u8 unitms: 1;
	u8 duration_c2h;
	u8 hoststate: 1;
	u8 RSVD: 7;
} H2CParam_GPIO_CTRL, *PH2CParam_GPIO_CTRL;

//H2C Index: 0x14
typedef struct _H2CParam_HW_INFO_ {
	u8 single_chip: 1;

} H2CParam_HW_INFO, *PH2CParam_HW_INFO;


typedef struct _HW_Info_ {
	u8 single_chip: 1;

} HW_Info, *PHW_Info;


//H2C Index: 0x15
typedef struct _H2CParam_FCS_Update_Param_ {
	u8 order: 4;
	u8 rsvd: 4;

	u8 mask_duration: 1; //if this bit mask = 1, fw will update parameter: duration
	u8 mask_InCurCh: 1; //if this bit mask = 1, fw will update parameter: InCurCh
	u8 mask_distxnull: 1; //if this bit mask = 1, fw will update parameter: distxnull
	u8 mask_c2hrpt: 1;  //if this bit mask = 1, fw will update parameter: c2hrpt
	u8 rsvd1: 4;

	u8 duration;    // UNIT:1TU

	u8 InCurCh: 1;  //1: if null pkt retry fail, keep in current channel,  0: if null pkt retry fail, switch to next channel
	u8 distxnull: 1;
	u8 c2hrpt: 2;
	u8 rsvd2: 4;
} H2CParam_FCS_Update_Param, *PH2CParam_FCS_Update_Param;

//H2C Index: 0x16
typedef struct _H2CParam_FCS_MacidBitMap_ {
	u8 macid_bitmap0_low;
	u8 macid_bitmap0_high;
	u8 macid_bitmap1_low;
	u8 macid_bitmap1_high;
	u8 macid_bitmap2_low;
	u8 macid_bitmap2_high;
} H2CParam_FCS_MacidBitMap, *PH2CParam_FCS_MacidBitMap;


//H2C Index: 0x1C
typedef struct _H2CParam_Channel_Switch_ {
	u8 channel_num;

	u8 BW       : 2;
	u8 BW40sc   : 3;
	u8 BW80sc   : 3;

	u8 RFEType  : 4;
	u8 rsvd     : 4;
} H2CParam_Channel_Switch, *PH2CParam_Channel_Switch;

//3 Class2: Power Save
typedef struct _PS_TUNING_PPARM2_ {
	u8      adopt: 1;
	u8      ps_bcn_to: 7;
	u8      ps_drv_early_itv;
} PS_TUNING_PPARM2, *PPS_TUNING_PPARM2;

//H2C Index: 0x20
typedef struct _H2CParam_SetPwrMode_parm_ {
	LEGACY_PS_PARM      PwrModeParm;
} H2CParam_PwrMode, *PH2CParam_PwrMode;

//H2C Index: 0x21
typedef struct _H2CParam_PSTuningParm_ {
	PS_TUNING_PPARM    PSTuningParm;
} H2CParam_PSTuningParm, *PH2CParam_PSTuningParm;

//H2C Index: 0x22
typedef struct _H2CParam_PSTuningParm2_ {
	PS_TUNING_PPARM2    PSTuningParm2;
} H2CParam_PSTuningParm2, *PH2CParam_PSTuningParm2;

//H2C Index: 0x23
typedef struct _H2CParam_PSLPSParm_ {
	u8  lpscontrol;
} H2CParam_PSLPSParm, *PH2CParam_PSLPSParm;

//H2C Index: 0x25
typedef struct _Scan_Parm_ {
	u8          Enable;
} Scan_Parm, *PScan_Parm;

//H2C Index: 0x26
typedef struct _H2CParam_SAPPSParm_ {
	u8  Enable: 1;
	u8  EnPS: 1;
	u8  EnLPRx: 1;
	u8  Manual32k: 1;   //revised by isaac on 20141202
	u8  rsvd: 4;
	u8  Duration;
	u8 SegNum;
} H2CParam_SAPPSParm, *PH2CParam_SAPPSParm;

//H2C Index: 0x27
typedef struct _H2CParam_INACTIVEPSParm_ {
	u8      Enable: 1;
	u8      IgnorePsCondition: 1;
	u8      rsvd: 6;
	u8      Frequency;
	u8      Duration;
	u8      FrequencyCount;
} H2CParam_INACTIVEPSParm, *PH2CParam_INACTIVEPSParm;


//H2C Index: 0x28
typedef struct _H2CParam_NOLINKPSParm_ {
	u8      Enable: 1;
	u8      NoConnect32k: 1;
	u8      rsvd: 6;
} H2CParam_NOLINKPSParm, *PH2CParam_NOLINKPSParm;

//H2C Index: 0x29
typedef struct  _H2CParam_PARTIALOFFCtrl_ {
	u8      Enable: 1;
	u8      rsvd: 7;
} H2CParam_PARTIALOFFCtrl, *PH2CParam_PARTIALOFFCtrl;

//H2C Index: 0x2A
typedef struct _H2CParam_PARTIALOFFParm_ {
	u8      ReadVld: 1;
	u8      WriteVld: 1;
	u8      rsvd: 6;
	u8      StartAddrL;
	u8      StartAddrH;
	u8      EndAddrL;
	u8      EndAddrH;
} H2CParam_PARTIALOFFParm, *PH2CParam_PARTIALOFFParm;

typedef struct _H2CParam_PSD_Result_ {
	u8          Data0;
	u8          Data1;
	u8          Data2;
	u8          Data3;
	u8          Data4;
} PSDResultParm, *PPSDResultParm;

//3 Class5: WOWLAN

// blow is WOWLAN define struct
//H2C Index: 0x80
typedef struct _wwlan_enable_ {
	u8          fun_En: 1;
	u8          pattern_match_En: 1;
	u8          magic_pkt_En: 1;
	u8          unicast_En: 1;
	u8          All_pkt_drop_En: 1;
	u8          GPIO_Active_type_En: 1;
	u8          Rekey_Wakeup_En: 1;
	u8          Discon_Wakeup_En: 1;
} WWlan_En, *PWWlan_En;

typedef struct _wwlan_parm_ {
	WWlan_En    enable;

	u8          gpio_num: 7;
	u8          DataPinWakeUp: 1;

	u8          gpio_duration;
	u8          gpio_pulse_en: 1;
	u8          gpio_pulse_count: 7;

	u8          usbphy_disable: 1;
	u8			hst2dev_en: 1;
	u8			gpio_duration_ms: 1;
	u8			rsvd0: 5;

	//not H2C from here
	u8          nullpkt: 1;
	u8          DriverRdy: 1;
	u8          rsvd: 6;
} WWlan_Parm, *PWWlan_Parm;


//H2C Index: 0x81
typedef struct _remote_wakeup_enable_ {
	u8          RemoteWakeUpCtrlEn: 1;
	u8          ArpEn: 1;
	u8          NdpEn: 1;
	u8          GtkEn: 1;
	u8          NLOOffloadEn: 1;
	u8          RealWoWLanEn: 1;
	u8          RealWoWLanV2En: 1;
	u8          MatchApplQQ: 1;

	u8          P2POffloadEn: 1;
	u8          Runtime_PM_En: 1;
	u8          NetbiosDropEn: 1;
	u8          TkipOffloadEn: 1;
	u8          TcpSyncDropEn: 1;
	u8          rsvd: 3;

	u8          ARP_ACTION: 1;
	u8          rsvd2: 3;
	u8          FWParsingUntilWakeup: 1;
	u8          FWParsingAfterWakeup: 1;
	u8          rsvd3: 2;

} Remote_wakeup_enable, *PRemote_wakeup_enable;

typedef struct _remote_wakeup_ {
	Remote_wakeup_enable funcEn;

	WWlan_Parm      WWlanCtrl;
	u8              Wakeup: 1;
#if CONFIG_DELAY_WAKEUP
	u8              delay_wake_wait: 1;
	u8              delay_wake_flag: 6;
#else
	u8              rsvd: 7;
#endif
	u8              MACAddr[6];
	u8              BSSIDAddr[6];
	u8              Debug[7];
	u8              AntSwitchOutside;
	u8              TwoAnt;
	u8              AntSelReverse;
	u8              RunTimePMFilter;
	u32             TotalRSSIByFw;


} RemoteWakeup_Parm, *PRemoteWakeup_Parm;

//H2C Index: 0x84
typedef struct _AOAC_RSVDPAGE2_ {
	u8  loc_routerSolicitation;
	u8  loc_bubblePacket;
	u8  loc_teredoInfo;
	u8  loc_RealwowInfo;
	u8  loc_KeepAlivePkt;
	u8  loc_AckPattern;
	u8  loc_WakeupPattern;
} AOAC_RSVDPAGE2, *PAOAC_RSVDPAGE2;


// H2C Index: 0x86
typedef struct _Scan_function_enable_ {
	u8  d0_fun_En: 1;
	u8  RTD3_fun_En: 1;
	u8  U3_SCAN_fun_En: 1;
	u8  NLO_fun_En: 1;
	u8  ips_dependent: 1;
	u8  rsvd: 3;
} Scan_function_enable, *PScan_function_enable;

typedef struct _D0_Scan_offload_ctrl_ {
	Scan_function_enable fun_En;
	u8  loc_probe_packet;
	u8  loc_scan_info;
	u8  loc_SSID_info;
} D0_Scan_offload_ctrl, *PD0_Scan_offload_ctrl;

// H2C Index: 0x88
typedef struct _AOAC_RSVDPAGE3_ {
	u8  loc_NLOInfo;
	u8  loc_AOACReport;
} AOAC_RSVDPAGE3, *PAOAC_RSVDPAGE3;



//3 Class6: Class no define


//3 Class7: Class no define


//3 Class8: Testing

//H2C Index: 0xE0
typedef struct _H2CParam_H2C2H_ {
	u8                 H2C2HPara;
} H2CParam_H2C2H, *PH2CParam_H2C2H;

typedef struct _C2HEXT_EVT_ {
	C2HEXT_EVT_HDR      sfbuff[LENGTH_C2HEXT_BUFF];
	u8                  r_ptr;
	u8                  w_ptr;
	u8                  sfbuff_last_num;    // 寫cmd到 sfbuff時更新的 sfbuff number
	u8                  sfbuff_last_ofset;  // 寫cmd到 sfbuff時更新的 sfbuff offset
} C2HEXT_EVT, *PC2HEXT_EVT;

typedef struct _C2HEXTHDR_PARM_ {
	u8  u1CmdId;
	u8  u1CmdSeq;
	u8  u1SubId;
	u8  u1CmdLen;//content len
	u8  pContent[LENGTH_C2HEXT_CONTENT];
} C2HEXTHDR_PARM, *PC2HEXTHDR_PARM;
/*------------------------Export global variable------------------------------*/

/*--------------------Function declaration---------------------------------*/

//brian for function both called in isrhdl or not
extern void
SendSignalCommon_8721D_RAM(
	u8  event
) ;

extern void
OSSendSignalCommon_8721D_RAM(
	u8  event
);

extern void
OSSendSignalCommon1(
	u8  event
) ;

extern void
CheckH2CMailboxCommon(
	void
);


extern void
C2HExtDeQueueCommon(
	void
) ;

extern void
C2HExtInQueueCommon(
	PC2HEXT_EVT_HDR pc2h_hdr
) ;

extern void
CfgTxBufAddrH(
	IN u8   h64,
	IN u8   offset_high
);

extern void
CfgRxBufAddrH(

	IN u8   offset_high
);

extern void
DrvFwIntfCtrl(
	void
);

extern void
MediaConnectionCommon(
	void
);


extern void
MediaDisconnectionCommon(
	void
);

extern BOOLEAN
GetMediaStatusCommon(
	IN u8   macid
);

extern void
C2HSpeRPT(
	void
);


extern void
Get_BB_Gain_Report(
	void
);

extern void
C2H_BB_Gain_Report(
	IN 	u8 Efuse_Thermal,
	IN 	u8 Efuse_BB_Gain_2G_TX,
	IN	u8 Efuse_BB_Gain_5GLB_TX,
	IN	u8 Efuse_BB_Gain_5GMB_TX,
	IN	u8 Efuse_BB_Gain_5GHB_TX
);

extern void
H2CCmdFunc_8721D_RAM(
	u8  CmdID,
	u8  *content
) ;

extern void
SetTxPauseDRVInfo(
	IN u8 BitMask,
	IN u8 UserValue
);

#endif  //__WIFIFW_CMD_RAM_H__
