#ifndef __WIFIFW_INIT_RAM_H__
#define __WIFIFW_INIT_RAM_H__

#ifndef CONFIG_WIFI_FW_VERIFY
#define CONFIG_WIFI_FW_VERIFY 0
#endif

/* REG_CLKDIV 0x0008 */
#define MAC_CLK_20M				(0x2 << BIT_SHIFT_MAC_CLK_SEL)
#define MAC_CLK_40M				(0x1 << BIT_SHIFT_MAC_CLK_SEL)
#define BIT_SHIFT_PRETX_AGGR_TIME_MAX                8
#define BIT_SHIFT_MAC_CLK_SEL                        18

/* REG_FWHW_TXQ_HWSSN_CTRL[31:24] */
#define BIT_HWSEQ_VO_EN		BIT0
#define BIT_HWSEQ_VI_EN		BIT1
#define BIT_HWSEQ_BE_EN		BIT2
#define BIT_HWSEQ_BK_EN		BIT3
#define BIT_HWSEQ_MGT_EN		BIT4
#define BIT_HWSEQ_HI_EN		BIT5
#define BIT_HWSEQ_BCN_EN		BIT6
#define BIT_HWSEQ_CPUM_EN		BIT7

/*--------------------Function declaration---------------------------------*/
extern void driver_fw_flow_ipc_int(VOID *Data, u32 IrqStatus, u32 ChanNum);
extern void wifi_FW_Vera_test(void);
extern void wifi_FW_init_ram(void);
extern void TaskCommon_8730A(void);
extern void TaskInit_8730A(void);
extern void Wifi_FW_TaskIdle(void);
extern void Fw_test_main(void);
extern void FwIntInit(void);
extern void TimerTest(void);

#endif /* __WIFIFW_INIT_RAM_H__ */

