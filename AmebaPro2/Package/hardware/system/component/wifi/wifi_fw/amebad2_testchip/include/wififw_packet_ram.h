#ifndef __WIFIFW_PACKET_RAM_H__
#define __WIFIFW_PACKET_RAM_H__

/*--------------------Define --------------------------------------------*/
// retry limit

//#define RTY_LMT_LTECOEXNULL         8
//#define RTY_LMT_LTECOEXQNULL        3
//#define RTY_LMT_DBGPKT              8

//issue rsvdpage marco
#define _ISSUE_BTQNULL              1
//#define _ISSUE_DBGPKT_              2
//#define _ISSUE_FCSNULL_             3
//#define _ISSUE_LTEQNULL_            4
//#define _ISSUE_NDPA_                5
//#define _ISSUE_PROBERSP_            6
//#define _ISSUE_PROBEREQ_            7
//#define _ISSUE_GTKRSP_              8
#define _ISSUE_PSPOLL_              9
#define _ISSUE_NULL_                10
#define _ISSUE_QNULL_               11
#define _ISSUE_CTS2SELF_            12
//#define _ISSUE_REALWOW_KA_          13
//#define _ISSUE_RS_                  14
//#define _ISSUE_BUBBLE_              15
#define _ISSUE_ARP_                 16
#define _ISSUE_NA_                  17

//#define ISSUEPKT_TYPE_NULLDATA      1
//#define ISSUEPKT_TYPE_FCSNULLDATA   2
//#define ISSUEPKT_TYPE_BTQNULL       3


/*----------------------------Define-------------------------------------*/
#if (CONFIG_SW_QUEUE_TX)

#define TX_PKT_WAIT_Q_SIZE			16
#define TX_PKT_BUSY_Q_SIZE			1
#define IS_CPUMGQ_TXING()				(!CheckCPUMGQEmpty())
#define CPUMGQ_TX_TIMEOUT_US			5000

enum TSF_HIGH_LOW_VALUE {
	TSF_LOW         = 0,
	TSF_HIGH        = 1
};

typedef enum _TX_RESULT_ {
	TXRESULT_TX_DONE 				= 0,
	TXRESULT_TX_TIMEOUT 		= 1,
	TXRESULT_TX_PREEMPTED 		= 2,
	TXRESULT_CANCELED 			= 3,
	TXRESULT_TX_ACKED 			= 4,
	TXRESULT_TX_DROPPED 		= 5,
	TXRESULT_MAX
} TX_RESULT, *PTX_RESULT;
//TX PS Poll
typedef struct {
	u16 		RsvPageLoc;
	u8			RtyLmt;
} TX_PSPOLL_PKT_CONTEXT, *PTX_PSPOLL_PKT_CONTEXT;
//TX null data
typedef struct {
	u16 		u2RsvPageLoc;
	BOOLEAN 	bPowerBit;
	u8			RtyLmt;
} TX_NULL_PKT_CONTEXT, *PTX_NULL_PKT_CONTEXT;
//CTS2Self
typedef struct {
	u8 			location;
	u16 		NAV;
} TX_CTS_TO_SELF_PKT_CONTEXT, *PTX_CTS_TO_SELF_PKT_CONTEXT;
//Arp
typedef struct {
	u8  		TargetIP[4];
	u8  		TargetMAC[6];
	u8  		retry_bit;
	u8  		arpsel;
} TX_ARP, *PTX_ARP;
//NA
typedef struct {
	u8    		TargetIP[4];
	u8    		TargetMAC[6];
	u8    		OurIP[4];
	u8    		OurMAC[6];
	u8    		retry_bit;
	u8    		ndpsel;
} TX_NA, *PTX_NA;

typedef union _TX_PKT_CONTEXT_ {
	TX_NULL_PKT_CONTEXT			Null;
	TX_PSPOLL_PKT_CONTEXT		PSPOLL;
	TX_CTS_TO_SELF_PKT_CONTEXT	CTS2Self;
	TX_ARP	ARP;
	TX_NA		NA;
} TX_PKT_CONTEXT, *PTX_PKT_CONTEXT;

typedef BOOLEAN(*PRE_TX_CALLBACK)(PTX_PKT_CONTEXT, u32);
typedef void (*POST_TX_CALLBACK)(TX_RESULT, u32);

typedef struct _TX_PKT_ENTRY_ {
	PRE_TX_CALLBACK		PreTxCallback;
	POST_TX_CALLBACK		PostTxCallback;
	u32 		IssueTxTime;
	u32 		HWTxTime;
	TX_PKT_CONTEXT		TxPktCxt;
	u8 			id;
	u8 			canceled;
	u16 		timeout;
	u8 			has_txfb;
} TX_PKT_ENTRY, *PTX_PKT_ENTRY;

/*--------------------Function declaration---------------------------------*/

extern void InitFreeRunTSF_8721D_RAM(void);
extern u64 GetFreeRunCnt_8721D_RAM(void);
extern u32 GetFreeRunCntU32_8721D_RAM(BOOLEAN u1HighLowValue);
extern u8 TxPktPollMgntQ_8721D_RAM(void);
extern BOOLEAN CPUMGQCancelTx_8721D_RAM(void);
extern void SWQTXCheckBusyQState_8721D_RAM(void);
extern BOOLEAN IsSWQTXAllQEmpty_8721D_RAM(void);
extern BOOLEAN PS_PreTxNull_8721D_RAM(PTX_PKT_CONTEXT  pcontext, u32 queue_time);
extern void PS_PostTxNull1_8721D_RAM(IN  TX_RESULT result, IN  u32 tx_time);
extern void PS_PostTxNull0_8721D_RAM(IN  TX_RESULT result, IN  u32 tx_time);
extern void PostTxNull_8721D_RAM(IN  TX_RESULT result, IN  u32 tx_time);
extern u8 CheckTxNullResult_8721D_RAM(u8 PORT_ID, u8 Null_Type);
extern void SWQTXTxFeedBack_8721D_RAM(u8 acked/*, void* context*/);
extern u8 SWQTXEnqueueWaitQ_8721D_RAM(TX_PKT_ENTRY txpkt_entry);
#if 0
extern BOOLEAN PreTxPSPoll_8721D_RAM(PTX_PKT_CONTEXT  pcontext, u32 queue_time);
extern void PostTxPSPoll_8721D_RAM(IN  TX_RESULT result, IN  u32 tx_time);
extern BOOLEAN PreTxNA_8721D_RAM(PTX_PKT_CONTEXT  pcontext, u32 queue_time);
extern void PostTxNA_8721D_RAM(IN	TX_RESULT result, IN  u32 tx_time);
extern BOOLEAN PreTxARP_8721D_RAM(PTX_PKT_CONTEXT	pcontext, u32 queue_time);
extern void PostTxARP_8721D_RAM(IN  TX_RESULT result, IN  u32 tx_time);
#endif

#endif


/*--------------------Function declaration---------------------------------*/
extern BOOLEAN CheckCPUMGQEmpty_8721D_RAM(void);

extern BOOLEAN
IssueNullData_8721D_RAM(
	IN  u8          bPowerBit,
	IN  u8          RtyLmt
);

extern u8
GetOccupyTxIndCommon(
	void
) ;

extern void
PowerBitSetting_8721D_RAM(
	IN  u8          bPowerBit,
	IN  u16         offset
);

extern u16
IssueRsvdPagePacketSetting_8721D_RAM(
	IN  u8          PageNum,
	IN  BOOLEAN     bHwSEQEn,
	IN  u8          RtyLmt,
	IN  u8          TxInd
);
#endif  //__WIFIFW_PACKET_RAM_H__

