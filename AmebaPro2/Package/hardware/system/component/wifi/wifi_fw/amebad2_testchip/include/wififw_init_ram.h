#ifndef __WIFIFW_INIT_RAM_H__
#define __WIFIFW_INIT_RAM_H__


#ifndef CONFIG_WIFI_FW_VERIFY
#define CONFIG_WIFI_FW_VERIFY 0
#endif

/* REG_CLKDIV 0x0008 */
#define MAC_CLK_20M				(0x2 << BIT_SHIFT_MAC_CLK_SEL)
#define MAC_CLK_40M				(0x1 << BIT_SHIFT_MAC_CLK_SEL)

//REG_FWHW_TXQ_HWSSN_CTRL[31:24]
#define BIT_HWSEQ_VO_EN		BIT0
#define BIT_HWSEQ_VI_EN		BIT1
#define BIT_HWSEQ_BE_EN		BIT2
#define BIT_HWSEQ_BK_EN		BIT3
#define BIT_HWSEQ_MGT_EN	BIT4
#define BIT_HWSEQ_HI_EN		BIT5
#define BIT_HWSEQ_BCN_EN	BIT6
#define BIT_HWSEQ_CPUM_EN	BIT7

/*==========PMC Register Address Definition==========*/
#define REG_WAK_STATUS0                                  0x0100
#define REG_WAK_STATUS1                                  0x0104
#define REG_WAK_MASK0_LP                                 0x0108
#define REG_WAK_MASK1_LP                                 0x010C
#define REG_WAK_MASK0_NP                                 0x0110
#define REG_WAK_MASK1_NP                                 0x0114
#define REG_WAK_MASK0_AP                                 0x0118
#define REG_WAK_MASK1_AP                                 0x011C
#define REG_WLPMC_ISR                                    0x0120
#define REG_WLAN_PWRCTL                                  0x0124
#define REG_SYSPMC_CTRL                                  0x0128
#define REG_SYSPMC_OPT                                   0x012C
#define REG_MEM_PWR_CTRL                                 0x0130
#define REG_PMC_PATCH_GRP0_0                             0x0134
#define REG_PMC_PATCH_GRP0_1                             0x0138
#define REG_PMC_PATCH_GRP1_0                             0x013C
#define REG_PMC_PATCH_GRP1_1                             0x0140
#define REG_PMC_PATCH_GRP2_0                             0x0144
#define REG_PMC_PATCH_GRP2_1                             0x0148
#define REG_PMC_PATCH_GRP3_0                             0x014C
#define REG_PMC_PATCH_GRP3_1                             0x0150
#define REG_PMC_PATCH_GRP4_0                             0x0154
#define REG_PMC_PATCH_GRP4_1                             0x0158
#define REG_PMC_PATCH_GRP5_0                             0x015C
#define REG_PMC_PATCH_GRP5_1                             0x0160

/*--------------------Define Struct---------------------------------------*/
typedef struct _DE_Feature_ {
	u8          Miracast_EN;
	u8          FTM_EN;
	u8          TDLS_EN;
	u8          AntNum;
	u8          BW;
	u8          Protocol;
	u8          Miracast_flag;
	u8          TDLS_flag;
	u8          AntNum_flag;
	u8          BW_flag;
	u8          Protocol_flag;
} DE_Feature, *pDE_Feature;


/*--------------------Function declaration---------------------------------*/
extern void
driver_fw_flow_ipc_int(
	VOID *Data,
	u32 IrqStatus,
	u32 ChanNum
);

extern void
wifi_FW_Vera_test(
	void
);

extern void
SetBcnEarlyTime(
	void
);

extern void
BcnEarlyAdjustByTSF_8721D(
	void
);

extern BOOLEAN
IssueNullData_8721D(
	IN  u8          bPowerBit,
	IN  u8          RtyLmt
) ;

extern void
AesTkipIvFun_8721D(
	u8 *pattrib_iv,
	u8 RetryBit
) ;

extern void
WepIvFun_8721D(
	u8 *iv,
	u8 retry_bit
) ;

extern u8
GetMACHeaderLen_8721D(
	u8  macheader,
	u8  FrameCtrl,
	u8  raaddr
) ;

extern void
UpdateIV_8721D(
	u8 *buf,
	u8 retry_bit
);

extern void
wifi_FW_init_ram(
	void
);

extern void
TaskCommon_8721D(
	void
);

extern void
TaskInit_8721D(
	void
);

extern void
Wifi_FW_TaskIdle(
	void
);

extern void
WlanInit(
	void
);

void
InitMacClk(
	u8 clk
);

extern void
Fw_test_main(
	void
);

extern void
FwIntInit(
	void
);

extern void
TimerTest(
	void
);

extern void
InitFuncPtrTable_8721D_RAM(
	void
);

#endif

