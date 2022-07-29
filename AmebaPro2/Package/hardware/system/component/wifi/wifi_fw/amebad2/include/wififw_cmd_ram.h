#ifndef __WIFIFW_CMD_RAM_H__
#define __WIFIFW_CMD_RAM_H__
/*--------------------Define --------------------------------------------*/
/* Register H2C Command ID here */
typedef enum _H2C_CMD_ {
	/* 1 Class1: Common */
	H2CID_RSVDPAGE								= 0x00,
	H2CID_JOININFO              					= 0x01,
	H2CID_SCAN                  					= 0x02,
	H2CID_KEEP_ALIVE            					= 0x03,
	H2CID_DISCONNECT_DECISION   				= 0x04,
	H2CID_PSD_OFFLOAD           					= 0x05,
	H2CID_Customer_string_rpt   				= 0x06,
	rsvd3                       						= 0x07,
	H2CID_AP_OFFLOAD            					= 0x08,
	H2CID_BCN_RsvdPage          					= 0x09,
	H2CID_Probersp_RsvdPage     				= 0x0A,
	H2CID_TXPower_Index_Offlaod 				= 0x0B,
	H2CID_AP_PS_OFFLOAD         				= 0x0C,
	H2CID_AP_PS_OFFLOAD_CTRL    				= 0x0D,
	H2CID_ECSA                  					= 0x0F,

	H2CID_FAST_CS_RSVDPAGE     	 			= 0x10,
	H2CID_FAST_CHANNEL_SWITCH   				= 0x11,
	H2CID_BB_GAIN_REPORT        				= 0x12,
	H2CID_GPIO_CTRL             					= 0x13,
	H2CID_HW_INFO               					= 0x14,
	H2CID_MCC_RQT_TSF      						= 0x15,
	H2CID_MCC_MACID_BITMAP     	 			= 0x16,
	H2CID_MCC_CTRL              					= 0x18,
	H2CID_MCC_TIME_PARAM         				= 0x19,
	H2CID_MCC_IQK_PARAM         				= 0x1A,
	H2CID_NAN_CTRL              					= 0x1B,
	H2CID_SINGLE_CHANNEL_SWITCH 				= 0x1C,
	H2CID_SINGLE_CHANNEL_SWITCH_V2 			= 0x1D,
	H2CID_TX_PAUSE_DRV_INFO					= 0x1E,
	H2CID_MACID_PAUSE_DRV_INFO  				= 0x1F,
	/* 1 Class2: Power Save */
	H2CID_SETPWRMODE            					= 0x20,
	H2CID_PSTURNINGPARM         				= 0x21,
	H2CID_PSTURNINGPARM2        				= 0x22,
	H2CID_PSLPSPARM             					= 0x23,
	H2CID_P2PPS_OFFLOAD         				= 0x24,
	H2CID_PS_SCAN               					= 0x25,
	H2CID_SAPPS                 					= 0x26,
	H2CID_INACTIVE_PS           					= 0x27,
	H2CID_NOLINK_PS             					= 0x28,
	H2CID_PARTIAL_OFF_CTRL   					= 0x29,
	H2CID_PARTIAL_OFF_PARM  					= 0x2A,
	H2CID_S1_NULL1_CTRL         				= 0x3F,
	/* 1 Class3: Dynamic Mechaism */
	H2CID_MACID_CFG             					= 0x40,
	H2CID_TxBF                  					= 0x41,
	H2CID_RSSI_SETTING          					= 0x42,
	H2CID_AP_REQ_TXRPT          					= 0x43,
	H2CID_INIT_RATE_COLLECT     				= 0x44,
	H2CID_IQK_OFFLOAD           					= 0x45,
	H2CID_MACID_CFG_3SS        	 				= 0x46,
	H2CID_RA_PARA_ADJUST        				= 0x47,
	H2CID_DYNAMIC_TX_PATH       				= 0x48,
	H2CID_FW_TRACE_EN          		 			= 0x49,
	/* 1 Class4: BT Coex */
	H2CID_B_TYPE_TDMA           					= 0x60,
	H2CID_BT_INFO               					= 0x61,
	H2CID_FORCE_BT_TXPWR        				= 0x62,
	H2CID_BT_IGNORE_WLANACT     				= 0x63,
	H2CID_DAC_SWING_VALUE       				= 0x64,
	H2CID_ANT_SEL_REVERSE       				= 0x65,
	H2CID_WL_OPMODE             					= 0x66,
	H2CID_BT_MP_OPERATION       				= 0x67,
	H2CID_BT_CONTROL           			 		= 0x68,
	H2CID_BT_WIFICTRL           					= 0x69,
	H2CID_BT_PATCH_DOWNLOAD     				= 0x6A,
	H2CID_BT_SCO_eSCO_OPERATION				= 0x6B,
	H2CID_BT_Page_Scan_Interval			 	= 0x6C,
	H2CID_WL_Calibraion         				= 0x6D,
	H2CID_GNT_BT_CTRL           					= 0x6E,
	H2CID_BT_ONLY_TEST          					= 0x6F,
	H2CID_BT_INIT_PARAM         				= 0x70,
	H2CID_WL_PORT_ID            					= 0x71,
	/* 1 Class5: WOWLAN */
	H2CID_WoWLAN                					= 0x80,
	H2CID_RemoteWakeCtrl        				= 0x81,
	H2CID_AOAC_Global_info      				= 0x82,
	H2CID_AOAC_Rsvdpage1        				= 0x83,
	H2CID_AOAC_Rsvdpage2        				= 0x84,
	H2CID_D0_Scan_offload_info  				= 0x85,
	H2CID_D0_Scan_offload_ctrl  				= 0x86,
	H2CID_Switch_channel        				= 0x87,
	H2CID_AOAC_Rsvdpage3        				= 0x88,
	H2CID_GPIO_WF_Customize     				= 0x89,
	H2CID_P2P_RsvdPage          					= 0x8A,
	H2CID_P2P_Offload           					= 0x8B,
	/* 1 Class6: LTECOEX */
	H2CID_LTECOEX_EN            					= 0xA0,
	H2CID_WLAN_High_Priority    				= 0xA1,
	/* 1 Class7: FTM */
	H2CID_FTM                   						= 0xB0,
	H2CID_FTMRPT                					= 0xB1,
	/* 1 Class8: Patch */
	H2CID_TSF_RESET             					= 0xC0,
	H2CID_BB_NHM                					= 0xC1,
	H2CID_BCN_Ignore_EDCCA      				= 0xC2,
	H2CID_Efuse_Hidden_Request  				= 0xC3,
	H2CID_APoffload_MultiWakeupPulse 		= 0xC4,
	H2CID_BCN_HWSEQ	        					= 0xC5,   //8814A BCN HWSEQ issue for Seam
	H2CID_Customer_string1      				= 0xC6,
	H2CID_Customer_string2      				= 0xC7,
	H2CID_Customer_string3      				= 0xC8,
	H2CID_IOTDRV_CloseRF      					= 0xCF,
	/* 1 Class9: Testing */
	H2CID_H2C2HLB               					= 0xE0,
	H2CID_FW_Verification       				= 0xE4,
	/* 1 Class10:FW Offload */
	CMD_ID_FW_OFFLOAD_H2C       				= 0xFF
} H2C_CMD, *PH2C_CMD;

typedef enum _C2H_CMD_SUBID_ {
	C2HEXTID_DEBUG_PRT          = 0,


} C2H_CMD_SUBID, *PC2H_CMD_SUBID;

/*--------------------------Define MACRO--------------------------------------*/
#define FIX_DELAY_FORWARD					BIT5

//MACID Drop Action
#define MACID_DROP_DISABLE      			0
#define MACID_DROP_ENABLE       			1

/*------------------------------Define Struct---------------------------------*/
//================H2C command format====================
typedef struct _H2C_CMD_HDR {
	u8 cmd_id;
} H2C_CMD_HDR, *PH2C_CMD_HDR;

//3 Class1: Common
/* H2C Index: 0x0 */
typedef struct _H2CParam_RsvdPage_ {
	RsvdPageLoc loc;
} H2CParam_RsvdPage, *PH2CParam_RsvdPage;

/* H2C Index: 0x1 */
typedef struct _H2CParam_JoinInfo_ {
	BOOLEAN     bConnected: 1;
	BOOLEAN     bMacid_ind: 1;
	u8          Miracast: 1;
	u8          Miracast_role: 1;
	u8          Macid_Dest_Role: 4;
	u8          macid;
	u8          macid_end;
} H2CParam_JoinInfo, *PH2CParam_JoinInfo;

//3 Class2: Power Save
/* H2C Index: 0x20 */
typedef struct _H2CParam_SetPwrMode_parm_ {
	LEGACY_PS_PARM      PwrModeParm;
} H2CParam_PwrMode, *PH2CParam_PwrMode;

/* H2C Index: 0x21 */
typedef struct _H2CParam_PSTuningParm_ {
	PS_TUNING_PPARM    PSTuningParm;
} H2CParam_PSTuningParm, *PH2CParam_PSTuningParm;

/* H2C Index: 0x26 */
typedef struct _H2CParam_SAPPSParm_ {
	u8  Enable: 1;
	u8  EnPS: 1;
	u8  EnLPRx: 1;
	u8  Manual32k: 1;   //revised by isaac on 20141202
	u8  rsvd: 4;
	u8  Duration;
	u8 SegNum;
} H2CParam_SAPPSParm, *PH2CParam_SAPPSParm;

/* H2C Index: 0x27 */
typedef struct _H2CParam_INACTIVEPSParm_ {
	u8      Enable: 1;
	u8      IgnorePsCondition: 1;
	u8      rsvd: 6;
	u8      Frequency;
	u8      Duration;
	u8      FrequencyCount;
} H2CParam_INACTIVEPSParm, *PH2CParam_INACTIVEPSParm;

//3 Class6: Class no define

//3 Class7: Class no define

//3 Class8: Testing

/* H2C Index: 0xE0 */
typedef struct _H2CParam_H2C2H_ {
	u8                 H2C2HPara;
} H2CParam_H2C2H, *PH2CParam_H2C2H;

/*--------------------Function declaration---------------------------------*/
//brian for function both called in isrhdl or not
extern void SendSignalCommon_8730A(u32  event);
extern void OSSendSignalCommon_8730A(u32  event);
extern void MediaConnection_8730A(void);
extern void MediaDisconnection_8730A(void);
extern void C2HSpeRPT_8730A(void);
extern void H2CCmdFunc_8730A(u8  CmdID, u8  *content);
extern void SetTxPauseDRVInfo_8730A(u8 BitMask, u8 UserValue);
extern void MacidDropAction_8730A(u8 action);

#endif  /* __WIFIFW_CMD_RAM_H__ */
