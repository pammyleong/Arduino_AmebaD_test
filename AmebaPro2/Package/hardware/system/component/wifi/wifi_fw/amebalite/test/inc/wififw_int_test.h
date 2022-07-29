#ifndef __WIFIFW_INT_TEST_H__
#define __WIFIFW_INT_TEST_H__

/*--------------------------Define -------------------------------------------*/
//Tx page
#define TXPKTBUF_PGBNDY_INTTEST               0x60//Reserved 4k bytes, 2k for inttest packet, 2k for wmac buffer
#define TXPKTBUF_BNDY_INTTEST                 (PAGESIZE_TX*TXPKTBUF_PGBNDY_INTTEST)

#define TXPKTBUF_MBIDBCNBNDY_INTTEST(x)       (PAGESIZE_TX*(TXPKTBUF_PGBNDY_INTTEST+x))
#define SIZE_WLAN_HEAD                      24

/*------------------------------Define Enum-----------------------------------*/
enum {
	TYPE_MORE_DATA = 0,
	TYPE_NO_MORE_DATA = 1,
	TYPE_BCM_MORE_DATA = 2,
	TYPE_BCM_NO_MORE_DATA = 3,
	TYPE_QOS_MORE_DATA = 4,
	TYPE_QOS_NO_MORE_DATA = 5,
	TYPE_QOS_EOSP = 6,
	TYPE_TRIGGER = 7,
	TYPE_NULL0 = 8,
	TYPE_NULL1 = 9,
	TYPE_CCX = 10,
	TYPE_BEACON = 11,
	TYPE_SYNC_BCN = 12,
	TYPE_MAGIC = 13,
	TYPE_TRY = 14,
	TYPE_MACID = 15,
	TYPE_FTMREQ = 16,
	TYPE_FTM = 17,
	TYPE_NDPA = 18,
	TYPE_TMREQ = 19,
	TYPE_TM = 20,
	TYPE_DIS_BCN = 21,
	TYPE_TIM = 22,
	TYPE_MAX,
};

enum {
	TYPE_RXUCMD0_ACK = 0,
	TYPE_RXUCMD1_ACK = 1,
	TYPE_RXBCMD0_ACK = 2,
	TYPE_RXBCMD1_ACK = 3,
	TYPE_RX_MORE_TF0 = 4,
	TYPE_RX_MORE_TF1 = 5,
	//TYPE_TIM = 6,
	TYPE_OPS = 6,
	TYPE_MAX_NEW,
};

enum {
	ITEM_PKT_INT = 0,
	ITEM_P0_TX_BCN = 1,
	ITEM_MBSSID_TXBCNOK_INT = 2,
	ITEM_MBSSID_TXBCNERR_INT = 3,
	ITEM_MBSSID_ATIM_INT = 4,
	ITEM_BCN_ERLY_ADJ = 5,
	ITEM_BCN_DMA_ERR = 6,
	ITEM_HWRPT_TEST = 7,
	ITEM_NULL,
};
/*--------------------------Define MACRO--------------------------------------*/


/*------------------------------Define Struct---------------------------------*/

typedef struct _STR_TYPE_ {
	const   u8 *str;
} STR_TYPE, *PSTR_TYPE;

/*------------------------Export global variable------------------------------*/
#ifndef __ASSEMBLY__

extern  u8  MAC_HEADER[];
extern  u8  INTTEST_TXDESC[];

/*------------------------------Function declaration--------------------------*/
extern void ParseTRXRptTest(void);
extern void AllPortReset(void);
extern void FwIntTest(void) ;
extern void FwIntTestExt(const char *argv[]);
extern void FwIntInit(void);
extern void ClrISRBitMap(void);
extern void PrintISRBitMap(void);
extern void RptbufTestInit(void);
extern void Port0ClientEn(u16 bcnspace, u8 elytime);
extern void PrepareIntPkt(u8 pktType);
extern void PrintISRBitMap(void);
extern void ClrISRBitMap(void);
extern void WLAN_INT_HDL_TEST(void);
extern void FT_INT_HDL_TEST(void);
extern void TimerTest(void);
extern void HIOEBackupAndRestoreTest(bool mode);
extern void SetHIOEConfigFileTest(void);
extern void PrintISRREG(void);
extern void ParseTRXRptTest(void);

#endif  /* #ifndef   __ASSEMBLY__ */
#endif  /* __WIFIFW_INT_TEST_H__ */