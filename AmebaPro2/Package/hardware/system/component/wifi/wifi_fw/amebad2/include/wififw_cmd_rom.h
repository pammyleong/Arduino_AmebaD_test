#ifndef __WIFIFW_CMD_H__
#define __WIFIFW_CMD_H__

#ifndef __ASSEMBLY__
/*--------------------Define --------------------------------------------*/
//==================C2H event format ====================
// Field     SYNC       CMD_LEN     CONTENT    CMD_SEQ      CMD_ID
// BITS  [127:120]  [119:112]      [111:16]          [15:8]        [7:0]
typedef struct _C2H_EVT_HDR {
	u8  cmd_id;
	u8  cmd_seq;
	u8  content[32];//change 12B to 32B for FTM C2H
	u8  cmd_len;
} C2H_EVT_HDR, *PC2H_EVT_HDR;

//Register C2H Command ID here
typedef enum _C2H_CMD_ {
	C2HID_DEBUG								= 0,
	C2HID_H2C2HLB							= 1,
	C2HID_TXBF								= 2,
	C2HID_CCX_TXRPT						= 3,
	C2HID_AP_REQ_TXRPT					= 4,
	C2HID_INIT_RATE_COLLECT			= 5,
	C2HID_PSD_RPT							= 6,
	C2HID_SCAN_COMPLETE					= 7,
	C2HID_PSD_CONTROL					= 8,
	C2HID_BT_INFORMATION				= 9,
	C2HID_BT_LOOPBACK					= 0x0A,
	C2HID_BT_MP_REPORT					= 0x0B,
	C2HID_RA_RPT							= 0x0C,
	C2HID_SPE_STATIS						= 0x0D,
	C2HID_RA_PARA_RPT					= 0x0E,
	C2HID_DTP_RPT							= 0x0F,
	C2HID_CURRENT_CHANNEL 				= 0x10,
	C2HID_IQK_OFFLOAD					= 0x11,
	C2HID_BB_GAIN_REPORT				= 0x12,
	C2HID_RateAdaptive_RPT_88E		= 0x13,	// for 88e smic RA debug
	C2HID_GPIOWAKEUP						= 0x14,
	C2HID_MAILBOX_STATUS				= 0x15,
	C2HID_H2C_PKT_Response				= 0x16, //mips
	C2HID_MCC_STATUS 						= 0x17,
	C2HID_NAN_EVENT						= 0x18,
	C2HID_Efuse_Hidden_REPORT			= 0x19,
	C2HID_FTMC2H_RPT						= 0x1B,
	C2HID_FTMSession_END				= 0x1C,
	C2HID_DRVFTMC2H_RPT					= 0x1D,
	C2HID_BCN_EARLY_RPT					= 0x1E,
	C2HID_ECSA_RPT						= 0x1F,
	C2HID_TX_PAUSE_RPT					= 0x20,
	C2HID_MACID_PAUSE_RPT				= 0x21,
	C2HID_Customer_String_rpt			= 0x24,
	C2HID_Customer_String_rpt_1		= 0x25,
	C2HID_WLAN_INFO						= 0x27,

	C2HID_DEBUG_CODE						= 0xFE,
	C2HID_EXTEND_IND						= 0xFF
} C2H_CMD, *PC2H_CMD;

/*--------------------Define MACRO--------------------------------------*/
//3 HMETFR
#define H2CINTBOX_BITMASK				0xF
#define H2CINTBOX_NUMMASK				0x3
#define BIT_PTR_NOMATCH				BIT7

//RXDEC
#define BIT_MASK_RXDEC_LENGTH		0x3FFF
#define BIT_RXDEC_C2HINDEX    		BIT4

// H2C
#define LENGTH_H2C						8
#define LENGTH_H2C_CMD_HDR			sizeof(H2C_CMD_HDR)
#define LENGTH_H2C_CONTENT			(LENGTH_H2C -LENGTH_H2C_CMD_HDR)
#define ADOPT_H2C_VALUE				BIT7
#define LENGTH_H2C_BUFF				10
#define H2C_Q_FULL(x, y)				(((((x) == 0) && ((y) == (LENGTH_H2C_BUFF - 1)))||((y) == ((x) - 1))) ? _TRUE : _FALSE)
#define H2C_Q_EMPTY(x, y)				(((x) == (y)) ? _TRUE : _FALSE)
#define H2CPTR_REACH_BOTTOM(x)		(((x) == LENGTH_H2C_BUFF) ? _TRUE : _FALSE)

// C2H
#define LENGTH_C2H						16
#define LENGTH_C2H_EVT_HDR			2
#define LENGTH_C2H_LEN_FIELD			1
#define LENGTH_C2H_SYNC				1
#define LENGTH_C2H_CONTENT 			(LENGTH_C2H - LENGTH_C2H_EVT_HDR - LENGTH_C2H_LEN_FIELD - LENGTH_C2H_SYNC)
#define LENGTH_C2H_BUFF				8//10, modified by jackie;
#define WAIT_C2H_CHECK_CNT 			(1000)
#define CHECK_C2H_ONCE_TIME 			(10)
#define C2H_DATA_RDY					0xFF
#define C2HPTR_REACH_BOTTOM(x)		(((x) == LENGTH_C2H_BUFF) ? _TRUE : _FALSE)
#define C2H_Q_EMPTY(x, y)				(((x) == (y)) ? _TRUE : _FALSE)
#define C2H_Q_FULL(x, y)				(((((x) == 0) && ((y) == (LENGTH_C2H_BUFF - 1)))||((y) == ((x) - 1))) ? _TRUE : _FALSE)
#define C2HPKT_POLL						BIT0

#define MACID_NUM_NEW					(MACID_NUM/8)

/*--------------------Define Struct---------------------------------------*/
//3 Class5: WOWLAN

//H2C Index: 0x80
typedef struct _wwlan_enable_ {
	u8		fun_En: 1;
	u8		pattern_match_En: 1;
	u8		magic_pkt_En: 1;
	u8		unicast_En: 1;
	u8		All_pkt_drop_En: 1;
	u8		GPIO_Active_type_En: 1;
	u8		Rekey_Wakeup_En: 1;
	u8		Discon_Wakeup_En: 1;
} WWlan_En, *PWWlan_En;

typedef struct _wwlan_parm_ {
	WWlan_En		enable;

	u8		gpio_num: 7;
	u8		DataPinWakeUp: 1;

	u8		gpio_duration;
	u8		gpio_pulse_en: 1;
	u8		gpio_pulse_count: 7;

	u8		usbphy_disable: 1;
	u8		hst2dev_en: 1;
	u8		gpio_duration_ms: 1;
	u8		rsvd0: 5;
	//not H2C from here
	u8		nullpkt: 1;
	u8		DriverRdy: 1;
	u8		rsvd: 6;
} WWlan_Parm, *PWWlan_Parm;

//H2C Index: 0x81
typedef struct _remote_wakeup_enable_ {
	u8		RemoteWakeUpCtrlEn: 1;
	u8		ArpEn: 1;
	u8		NdpEn: 1;
	u8		GtkEn: 1;
	u8		NLOOffloadEn: 1;
	u8		RealWoWLanEn: 1;
	u8		RealWoWLanV2En: 1;
	u8		MatchApplQQ: 1;

	u8		P2POffloadEn: 1;
	u8		Runtime_PM_En: 1;
	u8		NetbiosDropEn: 1;
	u8 		TkipOffloadEn: 1;
	u8		TcpSyncDropEn: 1;
	u8		rsvd: 3;

	u8		ARP_ACTION: 1;
	u8		rsvd2: 3;
	u8		FWParsingUntilWakeup: 1;
	u8		FWParsingAfterWakeup: 1;
	u8		rsvd3: 2;
} Remote_wakeup_enable, *PRemote_wakeup_enable;

//H2C Index: 0x82
typedef struct _AOAC_GLOBAL_INFO_ {
	u8		PairwiseEncAlg;
	u8		GroupEncAlg;
	u8		rsvd[5];
} AOAC_GLOBAL_INFO, *PAOAC_GLOBAL_INFO;

//H2C Index: 0x83
typedef struct _AOAC_RSVDPAGE1_ {
	u8		loc_remoteCtrlInfo;
	u8		loc_arp;
	u8		loc_ndp;
	u8		loc_gtkRsp;
	u8		loc_gtkInfo;
	u8		loc_gtkExtMem;
	u8		loc_ndpInfo;
} AOAC_RSVDPAGE1, *PAOAC_RSVDPAGE1;

//H2C Index: 0x84
typedef struct _AOAC_RSVDPAGE2_ {
	u8		loc_routerSolicitation;
	u8		loc_bubblePacket;
	u8		loc_teredoInfo;
	u8		loc_RealwowInfo;
	u8		loc_KeepAlivePkt;
	u8		loc_AckPattern;
	u8		loc_WakeupPattern;
} AOAC_RSVDPAGE2, *PAOAC_RSVDPAGE2;

// H2C Index: 0x88
typedef struct _AOAC_RSVDPAGE3_ {
	u8		loc_NLOInfo;
	u8		loc_AOACReport;
} AOAC_RSVDPAGE3, *PAOAC_RSVDPAGE3;

//H2C Index: 0x3
typedef struct _keep_alive_parm_ {
	u8		Enable: 1;
	u8 		AdoptUserSetting: 1;
	u8		PktType: 1;
	u8		DelayKeepalive: 1;
	u8		rsvd: 3;
	u8		KeepAliveNullTx: 1;

	u8		KeepAliveCountLimit;
	u8		KeepAliveCount;
	u8		SameTBTTRsvdPageCount;
} KeepAlive_Parm, *PKeepAlive_Parm;

typedef struct _remote_wakeup_ {
	Remote_wakeup_enable	funcEn;
	WWlan_Parm	WWlanCtrl;
	u8		Wakeup: 1;
	u8		delay_wake_wait: 1;
	u8		delay_wake_flag: 1;
	u8		rsvd: 5;

	u8		MACAddr[6];
	u8		BSSIDAddr[6];
	u8		Debug[7];
	u8		AntSwitchOutside;
	u8		TwoAnt;
	u8		AntSelReverse;
	u8		RunTimePMFilter;
	u32	TotalRSSIByFw;
} RemoteWakeup_Parm, *PRemoteWakeup_Parm;

//H2C Index: 0x4
typedef struct _disconnect_parm_ {
	u8		Enable: 1;
	u8		AdoptUserSetting: 1;
	u8		TryOkBcnFailCountEn: 1;
	u8 		DisconnectEN: 1;
	u8		rsvd: 4;

	u8		DisconnectCountLimit;
	u8		TryPKTCountLimit;
	u8		TryOkBcnFailCountLimit;
	u8		DisconnectCount;
	u8		TryPKTCount;
	u8		BCNCount;
	u8		WHCKPatchEn;
} Disconnect_Parm, *PDisconnect_Parm;

//3 Class8: Testing
typedef struct _H2C_EVT_CONTENT {
	u8		Content[LENGTH_H2C];
} H2C_EVT_CONTENT, *PH2C_EVT_CONTENT;

typedef struct _H2C_EVT_ {
	H2C_EVT_CONTENT    H2CFWBuff[LENGTH_H2C_BUFF];
	u8		H2CRPtr;
	u8		H2CWPtr;
} H2C_EVT, *PH2C_EVT;

typedef struct _C2H_EVT_ {
	C2H_EVT_HDR        c2h_sfbuff[LENGTH_C2H_BUFF];
	u8		c2h_r_ptr;
	u8		c2h_w_ptr;
} C2H_EVT, *PC2H_EVT;

/* H2C Index: 0x06 */
typedef struct _H2CParam_InitOffload_ {
	u8		Cmd_Index;
	u8		Loc_Data;
} H2CParam_InitOffload, *PH2CParam_InitOffload;

typedef struct _MEDIA_STATUS_ {
	BOOLEAN	bConnected[MACID_NUM_NEW];
	u8		MaxConnectedMacid;
} MEDIA_STATUS, *PMEDIA_STATUS;

/*--------------------Function declaration---------------------------------*/
extern void H2CInQueue_8730A_ROM(void);
extern void H2CDeQueue_8730A_ROM(void);
extern BOOLEAN WaitC2HOk_8730A_ROM(u16 TriggerAddr);
extern void InitC2H_8730A_ROM(void);
extern void C2HPKTRxDESC_8730A_ROM(u16 PktLength, u16 C2HDescOffset);
extern void FillC2HContant_8730A_ROM(u16 C2HPKTOffset, PC2H_EVT_HDR pc2h_hdr);
extern void IssueC2HPKT_8730A_ROM(PC2H_EVT_HDR pc2h_hdr);
extern void C2HDeQueue_8730A_ROM(void);
extern void C2HInQueue_8730A_ROM(PC2H_EVT_HDR pc2h_hdr);
extern u8 CheckMaxMacidNum_8730A_ROM(void);
extern void SetMediaStatus_8730A_ROM(u8 macid, u8 status);
extern BOOLEAN GetMediaStatus_8730A_ROM(u8 macid);
#endif  /* #ifndef __ASSEMBLY__ */
#endif  /* __WIFIFW_CMD_H__ */
