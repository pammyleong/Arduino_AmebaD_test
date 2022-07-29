#ifndef __TEST_H__
#define __TEST_H__

#if CONFIG_TEST_VERA
#define CMD_VERA_DDMA               0x1
#define CMD_VERA_SPIC_REG           0x2
#define CMD_VERA_UART               0x3
#define CMD_VERA_SPIC_DR            0x4
#define CMD_VERA_LPSPG              0x5
#define CMD_VERA_IOPATH             0x6
#define CMD_VERA_DIRCET_ACC_RF      0x7

#define REG_VERA_CMD        0x1a0
#define REG_VERA_RESULT     0x1a1


#define REG_VERA_DDMA_LEN      0x1a2
#define REG_VERA_DDMA_SA       0x1a4
#define REG_VERA_DDMA_DA       0x1a8
#define REG_VERA_DDMA_CH       0x1ac

#define PAGE_POFF_P2        0xf0
#define PAGE_POFF_P4        0xf1
#define PAGE_POFF_P6        0xf2
#define PAGE_POFF_P8        0xf4
#define PAGE_POFF_BA        0xfc
#define PAGE_POFF_SEC       0xea

#define PAGE_POFF_P2_TxSH        0xd0
#define PAGE_POFF_P4_TxSH        0xd1
#define PAGE_POFF_P6_TxSH        0xd2
#define PAGE_POFF_P8_TxSH        0xd4
#define PAGE_POFF_BA_TxSH        0xdc
#define PAGE_POFF_SEC_TxSH       0xca


#else
#define REG_TEST_CONTINUE   0x1a0

#define SIGNAL_UNLOCK       0x66
#endif

#define CONFIG_LPS_PG_DDMA 0
#define CONFIG_LPS_PG_HIOE 1

#if CONFIG_LPS_PG_TEST
#define LpsPG_En  1
#else
#define LpsPG_En  0
#endif

#define memory_pwr_mode_nml	0
#define memory_pwr_mode_nap	1
#define memory_pwr_mode_ret	2
#define memory_pwr_mode_slp	3

#define TSFIS32K                        1
#define TSFIS40M                        0
#define WAIT_TSF_STABLE_BREAK_CNT       (5000)
#define WAIT_TSF_STABLE_CNT             (50)
#define WAIT_TSF_STABLE_ONCE_TIME       (20)
#define GET_TSF_STATE() ((ReadMACRegWord(REG_TSF_CLK_STATE) & BIT_CLK_TSF_IS32K) ? TSFIS32K : TSFIS40M)


extern void FwCmdRomHelp(u16 argc, const char  *argv[]);

extern void FwCmdBufTest(u16 argc, const char  *argv[]);

extern void FwCmdRegTest(u16 argc, const char  *argv[]);

extern void FwCmdIntTest(u16 argc, const char  *argv[]);

extern void FwCmdDDMATest(u16 argc, const char  *argv[]);

extern void FwCmdSRamTest(u8 argc, u8  *argv[]);

extern void FwCmdFlash(u16 argc, const char *argv[]);

extern void FwCmdEfuse(u16 argc, const char  *argv[]);

extern void FwCmdIOPATH(u16   argc, const char  *argv[]);

extern void FwCmdReboot(u16 argc, const char  *argv[]);

extern void FwCmdRomTest(u16 argc, const char  *argv[]);

extern void FwCmdSecEngTest(u16 argc, const char *argv[]);

extern void CmdFwLbkTest(u16 argc, const char *argv[]);

extern void FwCmdCoexTest(u16 argc, const char *argv[]);

extern void GTimer1WKTest(void);

extern void BcnelyWKTest(void);

extern void LPSPGOperation(void);

extern void LPSPG_In(void);

extern void LPSPG_Out(void);



#endif      /* #ifndef __TEST_H__ */

