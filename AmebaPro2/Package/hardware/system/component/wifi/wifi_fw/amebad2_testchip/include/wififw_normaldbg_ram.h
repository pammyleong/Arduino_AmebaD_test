#ifndef __WIFIFW_NORMAL_DBG_H__
#define __WIFIFW_NORMAL_DBG_H__

#define REG_32K_MATCH_CNT			    REG_DBG_BYTE_18

typedef enum _FW_ERR_POWER_STATUS_ {
	BIT_POWER_STATUS_CHANGE      		= BIT0,
	BIT_S2_Condition_Not_Macth         	= BIT1,
	BIT_S4_Condition_Not_Macth		= BIT2,
	BIT_32K_Condition_Not_Macth         	= BIT3
} FW_ERR_POWER_STATUS, *PFW_ERR_POWER_STATUS;

typedef enum _FW_ERR_POWER_REASON1_ {
	BIT_H2CHDL0x20         	= BIT0,
	BIT_S0ToS1_ERROR         	= BIT1,
	BIT_TxNull0_FAIL     		= BIT2,
	BIT_S2ToS3_ERROR         	= BIT3,
	BIT_TxNull1_FAIL            	= BIT4
} FW_ERR_POWER_REASON1, *PFW_ERR_POWER_REASON1;

typedef enum _FW_ERR_POWER_REASON2_ {
	BIT_S2_TXQUEUE_NOT_EMPTY  	= BIT0,
	BIT_TRX_PERIOD        	 	= BIT1,
	BIT_S2_RPWM_NOT_MATCH     	= BIT2,
	BIT_RLPSRFOn       		= BIT3,
	BIT_WIFI_ACTIVE        		= BIT4,
	BIT_SAPPS_ACTIVE             	= BIT5
} FW_ERR_POWER_REASON2, *PFW_ERR_POWER_REASON2;


typedef enum _FW_ERR_POWER_REASON3_ {
	BIT_S4_TXQUEUE_NOT_EMPTY        = 0,
	BIT_TRX_TIM_DTIM          	= 0x11,
	BIT_S4_RPWM_NOT_MATCH     	= 0x22,
	BIT_USP_NOT_OVER         	= 0x33,
	BIT_TX_ACTIVE_INDEX 		= 0x44,
	BIT_RX_ACTIVE_INDEX 		= 0x55,
	BIT_BCN_DATA_OPEN            	= 0x66,
	BIT_RfOffLicenseForBCNRx    	= 0x77,
	BIT_WLANON_PERIOD          	= 0x88,
	BIT_SCAN_EN      		= 0x99,
	BIT_S4_TXCPUMGQ_NOT_EMPTY				= 0xaa

} FW_ERR_POWER_REASON3, *PFW_ERR_POWER_REASON3;

typedef enum _FW_ERR_POWER_REASON4_ {
	BIT_RXFF_NOT_EMPTY         	= 0,
	BIT_MAC_SCHDULE_SET        	= 0x11,
	BIT_C2HPKT_REQ     		= 0x22,
	BIT_RXDMA_NOT_IDLE         	= 0x33,
	BIT_RXPKT_REQ            	= 0x44,
	BIT_WOW_WAKEUP 			= 0x55,
	BIT_BT_CALIBRATION 		= 0x66,
	BIT_CPUMQ_EMPTY 		= 0x77,
	BIT_IOT_DELAY_WAKEUP 		= 0x88

} FW_ERR_POWER_REASON4, *PFW_ERR_POWER_REASON4;

extern u32
Isspace(
	char ch
);

extern u32
Strtoul(
	IN  const u8 *nptr,
	IN  u8 **endptr,
	IN  u32 base
);

extern void
RegCmdDump(
	u16 stAddr,
	u16 endAddr,
	u8 type
);

extern u8 *
StrUpr(
	IN  u8  *string
);

extern u8
prvStrCmp(
	IN  const   u8  *string1,
	IN  const   u8  *string2
);

extern u32
CmdFW(
	IN u16 argc,
	IN u8  *argv[]
);

extern void
CmdRegRW(
	IN  u16 argc,
	const char  *argv[]
);

void
REG_CMD_Dump(
	const char *argv[]
);

extern void
FwDbgCmdHelp(
	IN  u16 argc,
	const char  *argv[]
);

VOID
NorFWdbgInit(void);

void
CmdBufRW(
	IN  u16 argc,
	const char  *argv[]
);

void
NorDbgBuf(
	const char *argv[]
);

void
CmdTxrptRW(
	IN  u16 argc,
	const char  *argv[]
);

void
NorDbgTxrpt(
	const char *argv[]
);

void
NorDbgDumpTxrpt(
	void
);

#endif
