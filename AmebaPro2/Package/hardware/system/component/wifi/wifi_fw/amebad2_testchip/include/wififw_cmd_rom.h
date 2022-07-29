#ifndef __RTL8721D_CMD_H__
#define __RTL8721D_CMD_H__

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
	C2HID_DEBUG                 = 0,
	C2HID_H2C2HLB               = 1,
	C2HID_TXBF                  = 2,
	C2HID_CCX_TXRPT             = 3,
	C2HID_AP_REQ_TXRPT          = 4,
	C2HID_INIT_RATE_COLLECT     = 5,
	C2HID_PSD_RPT               = 6,
	C2HID_SCAN_COMPLETE         = 7,
	C2HID_PSD_CONTROL           = 8,
	C2HID_BT_INFORMATION        = 9,
	C2HID_BT_LOOPBACK           = 0x0A,
	C2HID_BT_MP_REPORT          = 0x0B,
	C2HID_RA_RPT                = 0x0C,
	C2HID_SPE_STATIS            = 0x0D,
	C2HID_RA_PARA_RPT           = 0x0E,
	C2HID_DTP_RPT               = 0x0F,
	C2HID_CURRENT_CHANNEL       = 0x10,
	C2HID_IQK_OFFLOAD           = 0x11,
	C2HID_BB_GAIN_REPORT        = 0x12,
	C2HID_RateAdaptive_RPT_88E  = 0x13,	// for 88e smic RA debug
	C2HID_GPIOWAKEUP            = 0x14,
	C2HID_MAILBOX_STATUS        = 0x15,
	C2HID_H2C_PKT_Response      = 0x16, //mips
	C2HID_MCC_STATUS            = 0x17,
	C2HID_NAN_EVENT             = 0x18,
	C2HID_Efuse_Hidden_REPORT   = 0x19,
	C2HID_FTMC2H_RPT            = 0x1B,
	C2HID_FTMSession_END        = 0x1C,
	C2HID_DRVFTMC2H_RPT         = 0x1D,
	C2HID_BCN_EARLY_RPT         = 0x1E,
	C2HID_ECSA_RPT              = 0x1F,
	C2HID_TX_PAUSE_RPT			= 0x20,
	C2HID_MACID_PAUSE_RPT       = 0x21,
	C2HID_Customer_String_rpt   = 0x24,
	C2HID_Customer_String_rpt_1 = 0x25,
	C2HEXTID_CCX_RPT                  = 0x26,
	C2HID_PER_RPT                   = 0x2C, // Wilson 171201
	C2HID_DEBUG_CODE            = 0xFE,
	C2HID_EXTEND_IND            = 0xFF
} C2H_CMD, *PC2H_CMD;


// BUFFER ACCESS CTRL
#define DBGBUF_TXPKTBUF         0x69
#define DBGBUF_RXPKTBUF         0xA5
#define DBGBUF_TXRPTBUF         0x7F

#define READ_BUF                0
#define WRITE_BUF               1

#define TXBUF64K_IND            0
#define TXBUF128K_IND           1

#define BIT_TXPKTBUF_DBG        BIT7
#define BIT_RXPKTBUF_DBG        BIT0
#define BIT_TXRPTBUF_DBG        BIT4

#define BIT_SHIFT_TXPKTBUF      7
#define BIT_SHIFT_RXPKTBUF      0
#define BIT_SHIFT_TXRPTBUF      4

/*--------------------Define Enum---------------------------------------*/
typedef enum _RTL8721D_INIT_OFFLOAD_CMD_ {
	CMD_INIT_LLT                = BIT0,
	CMD_READ_EFUSE_MAP          = BIT1,
	CMD_EFUSE_PATCH             = BIT2,
	CMD_IOCONFIG                = BIT3
} RTL8721D_INIT_OFFLOAD_CMD, *PRTL8721D_INIT_OFFLOAD_CMD;

typedef enum _RTL8721D_INIT_OFFLOAD_ERRSTS_ {
	ERR_INIT_LLT                = BIT4,
	ERR_READ_EFUSE_MAP          = BIT5,
	ERR_EFUSE_PATCH             = BIT6,
	ERR_IOCONFIG                = BIT7
} RTL8721D_INIT_OFFLOAD_ERRSTS, *PRTL8721D_INIT_OFFLOAD_ERRSTS;



/*--------------------Define MACRO--------------------------------------*/
//3 HMETFR
#define H2CINTBOX_BITMASK           0xF
#define H2CINTBOX_NUMMASK           0x3
#define BIT_PTR_NOMATCH 			BIT7

// H2C
#define LENGTH_H2C              8
#define LENGTH_H2C_CMD_HDR      sizeof(H2C_CMD_HDR)
#define LENGTH_H2C_CONTENT      (LENGTH_H2C -LENGTH_H2C_CMD_HDR)
#define ADOPT_H2C_VALUE         BIT7
#define LENGTH_H2C_BUFF         10
#define H2C_Q_FULL(x, y)        (((((x) == 0) && ((y) == (LENGTH_H2C_BUFF - 1)))||((y) == ((x) - 1))) ? _TRUE : _FALSE)
#define H2C_Q_EMPTY(x, y)       (((x) == (y)) ? _TRUE : _FALSE)
#define H2CPTR_REACH_BOTTOM(x)  (((x) == LENGTH_H2C_BUFF) ? _TRUE : _FALSE)

// C2H
#define LENGTH_C2H              16
#define LENGTH_C2H_EVT_HDR      2
#define LENGTH_C2H_LEN_FIELD    1
#define LENGTH_C2H_SYNC         1
#define LENGTH_C2H_CONTENT      (LENGTH_C2H - LENGTH_C2H_EVT_HDR - LENGTH_C2H_LEN_FIELD - LENGTH_C2H_SYNC)
#define LENGTH_C2H_BUFF         8//10, modified by jackie;
#define WAIT_C2H_CHECK_CNT      (1000)
#define CHECK_C2H_ONCE_TIME     (10)
#define C2H_DATA_RDY            0xFF
#define C2HPTR_REACH_BOTTOM(x)  (((x) == LENGTH_C2H_BUFF) ? _TRUE : _FALSE)
#define C2H_Q_EMPTY(x, y)       (((x) == (y)) ? _TRUE : _FALSE)
#define C2H_Q_FULL(x, y)        (((((x) == 0) && ((y) == (LENGTH_C2H_BUFF - 1)))||((y) == ((x) - 1))) ? _TRUE : _FALSE)
#define C2HPKT_POLL              BIT0

// DRV_FW_INTF
#define DRV_FW_EN               BIT7
#define DRV_FW_RWM              BIT6
#define BYTE_CNT                (BIT0|BIT1|BIT2)

#define DRV_FW_MODE            (BIT5|BIT4)

#define MODE_SRAM               0
#define MODE_TXBUF              0x10
#define MODE_RXBUF              0x20

#define FSM_MON_BT_DBG          0x5
#define BT_ACTIVE_MODE          0x4

#define SIGNAL_SEND_ISR         0
#define SIGNAL_SEND_OS          1

#define BT_ANT_TDMA_FUNC_EN         BIT0
#define BT_ANT_TDMA_SINGLE_ANT      BIT1
#define BT_ANT_TDMA_NAV_EN          BIT2
#define BT_ANT_TDMA_DAC_SWING_EN    BIT4

#define WLCALIBRATION               0x1e7

#define MACID_NUM_NEW           (MACID_NUM/8)

/*--------------------Define Struct---------------------------------------*/
//3 Class5: WOWLAN

//H2C Index: 0x82
typedef struct _AOAC_GLOBAL_INFO_ {
	u8  PairwiseEncAlg;
	u8  GroupEncAlg;
	u8          rsvd[5];

} AOAC_GLOBAL_INFO, *PAOAC_GLOBAL_INFO;

//H2C Index: 0x83
typedef struct _AOAC_RSVDPAGE1_ {
	u8  loc_remoteCtrlInfo;
	u8  loc_arp;
	u8  loc_ndp;
	u8  loc_gtkRsp;
	u8  loc_gtkInfo;
	u8  loc_gtkExtMem;
	u8  loc_ndpInfo;
} AOAC_RSVDPAGE1, *PAOAC_RSVDPAGE1;

//3 Class8: Testing

typedef struct _H2C_EVT_CONTENT {
	u8                 Content[LENGTH_H2C];
} H2C_EVT_CONTENT, *PH2C_EVT_CONTENT;

typedef struct _H2C_EVT_ {
	H2C_EVT_CONTENT    H2CFWBuff[LENGTH_H2C_BUFF];
	u8                 H2CRPtr;
	u8                 H2CWPtr;
} H2C_EVT, *PH2C_EVT;



typedef struct _C2H_EVT_ {
	C2H_EVT_HDR        c2h_sfbuff[LENGTH_C2H_BUFF];
	u8                 c2h_r_ptr;
	u8                 c2h_w_ptr;
} C2H_EVT, *PC2H_EVT;


//H2C Index: 0x06
typedef struct _H2CParam_InitOffload_ {
	u8    Cmd_Index;
	u8    Loc_Data;
} H2CParam_InitOffload, *PH2CParam_InitOffload;

typedef struct _MEDIA_STATUS_ {
	BOOLEAN             bConnected[MACID_NUM_NEW];
	u8                  MaxConnectedMacid;
} MEDIA_STATUS, *PMEDIA_STATUS;


/*--------------------Export global variable-------------------------------*/

/*--------------------Function declaration---------------------------------*/

extern void
H2CInQueue_8721D_ROM(
	void
);

extern void
H2CDeQueue_8721D_ROM(
	void
) ;

extern BOOLEAN
WaitC2HOk_8721D_ROM(
	u16 TriggerAddr
) ;

void
InitC2H_8721D_ROM(
	void
);

extern void
C2HPKTRxDESC_8721D_ROM(
	IN  u16 PktLength,
	IN  u16 C2HDescOffset
);

extern void
FillC2HContant_8721D_ROM(
	IN  u16             C2HPKTOffset,
	IN  PC2H_EVT_HDR    pc2h_hdr
);

extern void
IssueC2HPKT_8721D_ROM(
	PC2H_EVT_HDR pc2h_hdr
);

void
C2HDeQueue_8721D_ROM(
	void
);

extern void
C2HInQueue_8721D_ROM(
	PC2H_EVT_HDR pc2h_hdr
) ;

extern u8
CheckMaxMacidNum_8721D_ROM(
	void
);

extern void
SetMediaStatus_8721D_ROM(
	IN u8   macid,
	IN u8   status
);

extern BOOLEAN
GetMediaStatus_8721D_ROM(
	IN u8   macid
);

#endif  //#ifndef __ASSEMBLY__

#endif  //__RTL8721D_CMD_H__

