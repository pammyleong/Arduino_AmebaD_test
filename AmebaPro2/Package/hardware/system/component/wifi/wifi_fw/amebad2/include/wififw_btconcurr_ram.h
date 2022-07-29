#ifndef __WIFIFW_BTCONCURR_RAM_H__
#define __WIFIFW_BTCONCURR_RAM_H__

#ifndef __ASSEMBLY__
/*--------------------Define --------------------------------------------*/
#define DefaultTBTTOnPeriod         0xB
#define MaxTBTTOnPeriod             0x2A
#define MinTBTTOnPeriod             0x3
#define NULL_EARLY                  0x3
#define BTC_BCN_EARLY               DEFAULT_PS_BCN_EARLY + 3
#define BTC_FLEX_EXT_NUM            3
#define BTC_IQK_WAIT_CNT            6
#define BTC_AUTO_SLOT_TIME_THD      30

//for MAILBOX 0x11A4~0x11B7, OUT->WL2BT, IN->BT2WL
#define REG_MAILBOX_WL2BT_DATA0     0x0
#define REG_MAILBOX_WL2BT_DATA1     0x4
#define REG_MAILBOX_WL2BT_RDY       0x8  //bit[0] : OutReady, bit[1] : OutEmptyIntEn

#define REG_MAILBOX_BT2WL_DATA0     0xC
#define REG_MAILBOX_BT2WL_DATA1     0x10
#define REG_MAILBOX_BT2WL_RDY       0xA  //bit[0] : InReady, bit[1] : InRdyIntEn

#define BTC_PAN_DURATION_DEFAULT    50
#define BTC_PAN_DURATION_MAX        80
#define BTC_PAN_DURATION_MIN        30
#define BTC_PSPOLL_RTY_TIME         1

#define BTC_INTERVAL_UNDER_100      0
//TdmaIntervalMode=0: skip n-1 beacons , TdmaInterval: n
/*For example, BeaconInterval=40ms, we may set h2c 0x69 = 0xB 0x03,
so we omit 40ms(bcn early) and 80ms(bcn early) but noly care 120ms(bcn early) as slot.*/
#define BTC_INTERVAL_OVER_100       2
//TdmaIntervalMode=2: insert n 100ms , TdmaInterval: n,
/*For example, BeaconInterval=370ms, we may set h2c 0x69 = 0xB 0x83,
so we use 0ms 100ms(timer) 200ms(timer) 300ms(timer) and 370ms(bcn early) as slots. */
#define BTC_INTERVAL_SHORT          3
//TdmaIntervalMode=3: insert n 50ms , TdmaInterval: n,
/*For example, BeaconInterval=100ms, we may set h2c 0x69 = 0xB 0xc1,
so we use 0ms 50ms(timer) and 100ms(bcn early) as slots. */
#define BTC_DEFAULT_INTERVAL        102
#define BTC_SHORT_INTERVAL          51
#define BTC_MULTI_SLOT_TIMER        REG_TC3_CTRL

#define LEAK_AP_LIMIT               5
#define BTC_LEAK_AP_LIMIT           LEAK_AP_LIMIT
#define BTC_LEAK_AP_EXTEND          5

#define BTC_WAITBCN_TIMER           REG_TC4_CTRL
#define BTC_RETAIN_BT_SLOT_LEN      120

/*--------------------Define Enum---------------------------------------*/
typedef enum _BTC_Mailbox_Status_ {
	_BT_ACTIVE_OUTREADY_NOT_ZERO    = BIT0,
	_BT_NON_ACTIVE                  = BIT1,
	_BT_PATCH_TIMEOUT               = BIT2,
	_BT_CONTENT_ERROR               = BIT3,
	_BT_CONTENT_CHECKSUM_ERROR      = BIT4,
} BTC_Mailbox_Status, *PBTC_Mailbox_Status;

typedef enum _BTC_Scoreboard_CMD_ {
	BTC_SB_BT_ENABLE        = BIT1,
	BTC_SB_BT_A2DP_STATE    = BIT4,
	BTC_SB_BT_UNDER_IQK     = BIT5,
	BTC_SB_BT_IQK_REQ       = BIT6,
	BTC_SB_BT_LPS           = BIT7,
	BTC_SB_BT_HID_NOTIFY    = BIT8,
	BTC_SB_BT_XTAL_WRITE    = BIT15,
	BTC_SB_BT_EFUSE         = BIT30
} BTC_Scoreboard_CMD, *PBTC_Scoreboard_CMD;

typedef enum _BTC_BT_PMC_State_ {
	_BT_IDLE_MODE           = 0,
	_BT_XTAL_EN_MODE        = 1,
	_BT_LDO_EN_MODE         = 2,
	_BT_PLL_EN_MODE         = 3,
	_BT_ACTIVE_MODE         = 4,
	_BT_LDO_DIS_MODE        = 5,
	_BT_LOW_POWER_MODE      = 6,
	_BT_CAL_EN_MODE         = 10,
	_BT_CALIBRATE_MODE      = 11,
	_BT_POWER_DOWN_MODE     = 12,
	_BT_LP2ACTIVE_MODE      = 13,
	_BT_AFELDO_MODE         = 14
} BTC_BT_PMC_State, *PBTC_BT_PMC_State;

typedef enum _BTC_PWRBitOverWrite_State_ {
	DisablePWRBitOverWrite   = 0,
	EnablePWRBitOverWrite    = 1,
	OverWritePWRBit0         = 2,
	OverWritePWRBit1         = 3
} BTC_PWRBitOverWrite_State, *PBTC_PWRBitOverWrite_State;

typedef enum _BTC_MultiPort_Role_ {
	PORT0      = 0,
	PORT1      = 1,
	PORT2      = 2,
	PORT3      = 3,
	PORT4      = 4
} BTC_MultiPort_Role, *PBTC_MultiPort_Role;

typedef enum _BTC_TdmaFlexibleExtension_State_ {
	_BT_TDMA_FLEX_IDLE_STATE = 0,
	_BT_TDMA_FLEX_NULL_STATE = 1
} BTC_TdmaFlexibleExtension_State, *PBTC_TdmaFlexibleExtension_State;

typedef enum _BTC_AOAC_Switch_State_ {
	BTC_AOAC_RF_OFF           = 0,
	BTC_AOAC_RF_ON            = 1,
	BTC_AOAC_BT_START_IQK     = 2,
	BTC_AOAC_BT_STOP_IQK      = 3
} BTC_AOAC_Switch_State, *PBTC_AOAC_Switch_State;

typedef enum _BTC_Function_Caller_ {
	TBTT_TDMA                 = 0,
	TBTT_ISR                  = 1,
	BCNEARLY_TDMA             = 2,
	BCNEARLY_ISR              = 3
} BTC_Function_Caller, *PBTC_Function_Caller;

/* C2H Index: 0x9 */
typedef enum _C2H_BT_INFO_ {
	RSP_WIFI_FW             = 0,
	RSP_WIFI_REQ            = 1,
	RSP_BT_CHANGE_STS       = 2,
	RSP_BT_IQK              = 3,
	RSP_BT_SB               = 4,
	RSP_BT_RPT_TDMA         = 5,
	RSP_BT_PSD_REPORT       = 6,
	RSP_BT_SLOT_LENGTH      = 7
} C2H_BT_INFO, *PC2H_BT_INFO;

/* H2C Index: 0x69 */
typedef enum _H2C_BTWIFI_CTRL_ {
	BT_SET_TXRETRY_REPORT   = 0,
	BT_SET_PTATABLE         = 1,
	BT_SET_PSD_MODE         = 2,
	BT_SET_LNA_CONSTRAINT   = 3,
	BT_MAILBOX_LB_TEST      = 4,
	BT_H2C2H_LB_TEST        = 5,
	BT_RA_RETRYPENALTY      = 6,
	BT_HID_SLOT_TABLE       = 7,
	BT_WIFI_RQT_INFO        = 8,
	BT_SET_PAN_DURATION     = 9,
	BT_SET_A2DP_EMPTY_THD   = 10,
	BT_SET_BCN_INTERVAL     = 11,
	BT_SET_LEAK_AP_MODE     = 12,
	BT_HID_SLOT_TABLE_2     = 13
} H2C_BTWIFI_CTRL, *PH2C_BTWIFI_CTRL;

/*--------------------Define MACRO--------------------------------------*/
#define MAILBOX_MAX_LENGTH    7
/* Mailbox MP Rpt OPCODE */
#define BTMPRPT_OPCODE_WRITE_ADDR           0x0C
#define BTMPRPT_OPCODE_WRITE_VALUE          0x0D

/*--------------------Function declaration---------------------------------*/
extern void BTRoleChangeTimerHDL_8730A(void);
extern void BTRoleChangeTBTTHDL_8730A(void);
extern void BTRoleChangeDefaultSetting_8730A(void);
extern void BTC_BackupAntennaSetting_8730A(u8  option);
extern void InitBTMailbox_8730A(void);
extern BOOLEAN FillMailbox_8730A(u8 cmd, u8 length, u8 *pparm);
extern void WL2BTMailboxSend_8730A(u8 cmd, u8 length, u8 *pparm);
extern void BT2WLMailboxINTHDL_8730A(void);
extern void BT2WLMailboxINTCheck_8730A(void);
extern void H2CHDL_BTPSTDMA_8730A(u8  *pbuf);
extern void BTC_PsTdmaActionDelay_8730A(void);
extern void BTC_PsTdmaAction_8730A(u8  *pbuf);
extern void H2CHDL_BTWifiCtrl_8730A(u8  *pbuf);
extern void H2CHDL_WLCalibration_8730A(u8 *pbuf);
extern void H2CHDL_BT_Init_Param_8730A(u8 *pbuf);
extern void C2HBTInfo_8730A(u8  option);
extern void C2HWlanInfo_8730A(void);
extern void InitBTCoex_8730A(void);
extern void InitBTScoreboard_8730A(void);
extern void BT_TDMA_Slot_Operation_0and3_8730A(u8  slot_num);
extern void BT_TDMA_Slot_Operation_1and4_8730A(u8  slot_num);
extern void BT_TDMA_Slot_Operation_2and5_8730A(u8  slot_num);
extern u8 DynamicSlotDecision_8730A(void);
extern u8 BTypeTDMAMultiSlots_8730A(void);
extern void BTypeTDMABCNEarly_8730A(u8  type);
extern void BTypeTDMATBTThdl_8730A(u8  type);
extern void BTypeTDMALeakAPOperation_8730A(void);
extern void BTypeTDMATimeOuthdl_8730A(void);
extern void BTC_RestoreDefaultCoexTable_8730A(void);
extern void BTC_PWRBitOverWrite_8730A(u8  PortNum, u8  mode);
extern void BTC_PsTdmaIssueNull_8730A(BOOLEAN Powerbit, u8 PortNum);
extern void BTC_PsTdmaIssuePsPoll_8730A(void);
extern void BTC_PsTdmaOnBcn_8730A(void);
extern void BTC_BtIqkAction_8730A(u8  allow);
extern BOOLEAN BTC_BtIqkCheck_8730A(void);
extern void BTC_WlanInfoCounterReset_8730A(void);
extern BOOLEAN BTC_ProceedBtSlot_8730A(void);
extern void BTC_ProtectBCN_8730A(void);
extern void BTC_RestoreBtSlot_8730A(void);
extern u8 BTC_GenRandomValue_8730A(u8 range, u8 count);
extern void BTC_WifiRandomSlot_8730A(void);
extern void IssueBTQNull_8730A(u8 bPowerBit, u8 lsb, u8 msb);
extern void InitBTCoexGpioDebug_8730A(void);
extern void BTC_AOACSwitch_8730A(u8  state);

#endif /* #ifndef __ASSEMBLY__ */
#endif /*  __WIFIFW_BTCONCURR_RAM_H__ */
