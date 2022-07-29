#ifndef __WIFIFW_TXREPORT_RAM_H__
#define __WIFIFW_TXREPORT_RAM_H__
/*--------------------Define MACRO--------------------------------------*/
#define TEST_FORCE_TRXRPT_FULL          0       //set 1 to force TRxRPT full
#define TXRPTFIELD_RPT_SEL              (BIT7|BIT6|BIT5)

/*--------------------Define Struct---------------------------------------*/
typedef enum _RPT_TYPE_ {
	TXRPT       = 0,
	FTMRPT      = 1,
	CCXRPT      = 2,
	FTMACKRPT   = 3,
	TXBCNRPT    = 4,
	RXBCNRPT    = 6,
	TXRPTNew	= 7,
	TRIGGER		= 8,
} RPT_TYPE, *PRPT_TYPE;

/*------------------------------Function declaration--------------------------*/
extern void InitCtrlInfo_8730A(void);

#endif  /* #ifndef   __WIFIFW_TXREPORT_RAM_H__ */
