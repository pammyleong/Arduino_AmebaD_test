#ifndef __WIFIFW_COEX_TEST_H__
#define __WIFIFW_COEX_TEST_H__

enum WifiWithZigbeeCOEX_TABLE_Type {
	ZB_WL	= 0x0,                                      //ZB > WL
	WL_ZB	= 0x1,                                      //WL > ZB
	WLHighPri_ZB_WLLowPri	= 0x2,                      //WL high-pri > ZB > WL low-pri
	ZBHighPri_WL_ZBLowPri	= 0x3,                      //ZB high-pri > WL > ZB low-pri
	WLHighPri_ZBHighPri_WLLowPri_ZBLowPri	= 0x4,      //WL high-Pri > ZB high-Pri > WL low-Pri > ZB low-Pri
	ZBHighPri_WLHighPri_ZBLowPri_WLLowPri	= 0x5,      //ZB high-Pri > WL high-Pri > ZB low-Pri > WL low-Pri
	WL_EQUAL_ZB	= 0x6,                                  //WL = ZB
	WZ_TABLE_MAX
};

enum BtWithZigbeeCOEX_TABLE_Type {
	ZB_BT	= 0x0,                                      //ZB > BT
	BT_ZB	= 0x1,                                      //BT > ZB
	BTHighPri_ZB_BTLowPri	= 0x2,                      //BT high-pri > ZB > BT low-pri
	ZBHighPri_BT_ZBLowPri	= 0x3,                      //ZB high-pri > BT > ZB low-pri
	BTHighPri_ZBHighPri_BTLowPri_ZBLowPri	= 0x4,      //BT high-Pri > ZB high-Pri > BT low-Pri > ZB low-Pri
	ZBHighPri_BTHighPri_ZBLowPri_BTLowPri	= 0x5,      //ZB high-Pri > BT high-Pri > ZB low-Pri > BT low-Pri
	BT_EQUAL_ZB	= 0x6,                                  //BT = ZB
	BZ_TABLE_MAX
};

enum WifiWithBtCOEX_TABLE_Type {
	BT_WL	= 0x0,                                      //BT > WL
	WL_BT	= 0x1,                                      //WL > BT
	WLHighPri_BT_WLLowPri	= 0x2,                      //WL high-pri > BT > WL low-pri
	BTHighPri_WL_BTLowPri	= 0x3,                      //BT high-pri > WL > BT low-pri
	WLHighPri_BTHighPri_WLLowPri_BTLowPri	= 0x4,      //WL high-Pri > BT high-Pri > WL low-Pri > BT low-Pri
	BTHighPri_WLHighPri_BTLowPri_WLLowPri	= 0x5,      //BT high-Pri > WL high-Pri > BT low-Pri > WL low-Pri
	WL_EQUAL_BT	= 0x6,                                  //WL = BT
	WB_TABLE_MAX
};

enum WifiWithZigbeeWithBtCOEX_TABLE_Type {
	WL_ZB_BT	= 0x0,                                  //WL > ZB > BT
	WL_BT_ZB	= 0x1,                                  //WL > BT > ZB
	ZB_WL_BT	= 0x2,                                  //ZB > WL > BT
	ZB_BT_WL	= 0x3,                                  //ZB > BT > WL
	BT_WL_ZB	= 0x4,                                  //BT > WL > ZB
	BT_ZB_WL	= 0x5,                                  //BT > ZB > WL
	WLHighPri_BTHighPri_ZB_BTLowPri_WLLowPri	= 0x6,  //WL high-pri > BT high-pri > ZB > BT low-pri > WL low-pri
	BTHighPri_WLHighPri_ZB_BTLowPri_WLLowPri	= 0x7,  //BT high-pri > WL high-pri > ZB > BT low-pri > WL low-pri
	ZBHighPri_WLHighPri_BTHighPri_ZBLowPri_WLLowPri_BTLowPri	= 0x8,  //ZB high-pri > WL high-pri > BT high-pri > ZB low-pri > WL low-pri > BT low-pri
	ZBHighPri_BTHighPri_WLHighPri_ZBLowPri_BTLowPri_WLLowPri	= 0x9,  //ZB high-pri > BT high-pri > WL high-pri > ZB low-pri > BT low-pri > WL low-pri
	BTHighPri_ZBHighPri_WLHighPri_ZBLowPri_BTLowPri_WLLowPri	= 0xA,  //BT high-pri > ZB high-pri > WL high-pri > ZB low-pri > BT low-pri > WL low-pri
	WL_EQUAL_ZB_EQUAL_BT	= 0xB,                      //WL = ZB = BT
	WZB_TABLE_MAX
};

#define REG_FWLBK_CTRL_COEX    REG_BT_MAILBOX_OUT_LOW

/************Function Declarations*************/
extern void
BtAndZigbeeFunctionEnable(
	void
);

extern void
CoexTest(
	u8 argc,
	const char *argv[]
) ;

/*******************PTA********************/
extern void
PTATest(
	u8 argc,
	const char *argv[]
) ;

extern void
WifiWithZigbeePTATest(
	u8 argc,
	const char *argv[]
) ;

extern void
ExternalZigbee_Init(
	u8 select
) ;

extern void
WifiWithZigbee_PTA_FpgaDbg(
	u8 select
) ;

extern void
WifiWithZigbee_PTA_TableSelect(
	u8 tablecase
) ;

extern void
BtWithZigbeePTATest(
	u8 argc,
	const char *argv[]
) ;

extern void
InternalBt_Init(
	void
) ;

extern void
BtWithZigbee_PTA_FpgaDbg(
	u8 select
) ;

extern void
BtWithZigbee_PTA_TableSelect(
	u8 tablecase
) ;

extern void
WifiWithInternalBtRTKmodePTATest(
	u8 argc,
	const char *argv[]
) ;

extern void
WifiWithBt_PTA_FpgaDbg(
	u8 select
) ;

extern void
WifiWithBt_PTA_TableSelect(
	u8 tablecase
) ;

extern void
WifiWithZigbeeWithBtPTATest(
	u8 argc,
	const char *argv[]
) ;

extern void
WifiWithZigbeeWithBt_PTA_FpgaDbg(
	u8 select
) ;

extern void
WifiWithZigbeeWithBt_PTA_TableSelect(
	u8 tablecase
) ;

/***************FW MAC Loop Back****************/
extern void
WifiFW_LoopBack(
	u8 enable,
	u32 looplimit
) ;

extern void
Coex_LoopBackLite(
	u8 enable,
	u32 looplimit
) ;

extern void
Coex_LoopBackLiteInit(
	void
) ;

extern void
FwlbkMode_Coex_Test(
	void
) ;

extern void
FwlbkModeAFElbk_Coex_Test(
	void
) ;

/*******************Mailbox********************/
extern void
MailboxTest(
	u8 argc,
	const char *argv[]
) ;

extern void
Wifi2BTMailboxTest(
	u8 argc,
	const char *argv[]
) ;

extern void
FillMailboxTest(
	IN  u8 cmd,
	IN  u8 length,
	IN  u8 *pparm
) ;

extern void
BT2WifiMailboxTest(
	void
) ;

extern void
BT2WifiMailboxIntTestHandler(
	void
) ;

extern void
Wifi2ZBMailboxTest(
	u8 argc,
	const char *argv[]
) ;

extern void
ZB2WifiMailboxTest(
	void
) ;

extern void
ZB2WifiMailboxIntTestHandler(
	void
);

/*******************Scoreboard********************/
extern void
ScoreboardTest(
	u8 argc,
	const char *argv[]
) ;

extern void
Wifi2BTScoreboardTest(
	u8 argc,
	const char *argv[]
) ;

extern void
BT2WifiScoreboardTest(
	void
) ;

extern void
BT2WifiScoreboardIntTestHandler(
	void
) ;

/********************Interrupts********************/
extern void
CoexIntTest(
	u8 argc,
	const char *argv[]
) ;

extern void
CoexIntTestInit(
	void
) ;

extern void GntIntTest(void);

extern void
BtActIntTest(
	void
) ;

extern void TxRptIntTest(void);

extern void
CoexIntTestHandler(
	void
) ;

extern void
GntBtRiseIntTestHandler(
	void
) ;

extern void
GntBtFallIntTestHandler(
	void
) ;

extern void
BtCmdIntTestHandler(
	void
) ;

extern void ParseTRXRptTXPollutedTest(void);

#endif      //#ifndef __WIFIFW_COEX_TEST_H__
