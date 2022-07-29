#ifndef __RTL8721D_REG_H__
#define __RTL8721D_REG_H__

/*--------------------------Define -------------------------------------------*/

/* REG_SYS_PWC_CTRL 0x0000 */
#define BIT_SHIFT_ISO_MAC                            8
#define BIT_ISO_MAC                                  ((u32)0x00000001 << BIT_SHIFT_ISO_MAC)                            /*!<R/W 1  Isolation control for MAC, 1: isolation; 0: attach */
#define BIT_SHIFT_WL_SWR_REQ_1P1V                    4
#define BIT_WL_SWR_REQ_1P1V                          ((u32)0x00000001 << BIT_SHIFT_WL_SWR_REQ_1P1V)                    /*!<R/W 0  1: wl request switch SWR vlotage to 1.1V 0: wl request switch SWR vlotage to 0.9V */
#define BIT_SHIFT_WL_PWM_EN                          3
#define BIT_WL_PWM_EN                                ((u32)0x00000001 << BIT_SHIFT_WL_PWM_EN)                          /*!<R/W 0  1:WL request switch to PWM mode 0��WL request switch to PFM mode */
#define BIT_SHIFT_WL_SAVE_EN                         2
#define BIT_WL_SAVE_EN                               ((u32)0x00000001 << BIT_SHIFT_WL_SAVE_EN)                         /*!<R/W 0  0:gen req to restore register in power on flow 1:gen req to backup register in power on flow */
#define BIT_SHIFT_SPC_MAC_EN                         0
#define BIT_SPC_MAC_EN                               ((u32)0x00000001 << BIT_SHIFT_SPC_MAC_EN)                         /*!<R/W 0  1: Enable MAC small power cut */

/* REG_WL_CLK_CTRL 0x0002 */
#define BIT_SHIFT_IS_PMC_CLK_INSLP                   11
#define BIT_IS_PMC_CLK_INSLP                         ((u32)0x00000001 << BIT_SHIFT_IS_PMC_CLK_INSLP)                   /*!<RO 0  WL_PMC interrup ISR/IMR clock status: 0: TSF clock 1: 32K clock */
#define BIT_SHIFT_IS_SCH_CLK_INSLP_V2                9
#define BIT_IS_SCH_CLK_INSLP_V2                      ((u32)0x00000001 << BIT_SHIFT_IS_SCH_CLK_INSLP_V2)                /*!<RO 0  WL TSF clock status: 0: MAC clock 1: 32K clock */
#define BIT_SHIFT_TSF_CKSLP_SEL                      8
#define BIT_TSF_CKSLP_SEL                            ((u32)0x00000001 << BIT_SHIFT_TSF_CKSLP_SEL)                      /*!<R/W 0  1: TSF clock switch to 32.768KHz; 0: TSF clock switch to MAC clock */
#define BIT_SHIFT_WL_CKTSF_EN                        6
#define BIT_WL_CKTSF_EN                              ((u32)0x00000001 << BIT_SHIFT_WL_CKTSF_EN)                        /*!<R/W 0  1: enable tsf clock; 0: gated */
#define BIT_SHIFT_WL_FQSEL_CK32K                     5
#define BIT_WL_FQSEL_CK32K                           ((u32)0x00000001 << BIT_SHIFT_WL_FQSEL_CK32K)                     /*!<R/W 0  1:32K frequency select 32.768KHz 0:32K frequency select 32KHz */
#define BIT_SHIFT_CKSL_CK32K                         4
#define BIT_CKSL_CK32K                               ((u32)0x00000001 << BIT_SHIFT_CKSL_CK32K)                         /*!<R/W 0  1:select MAC internal 32K clk, 0:select MAC external 32K clk */
#define BIT_SHIFT_WL_CK32K_EN                        3
#define BIT_WL_CK32K_EN                              ((u32)0x00000001 << BIT_SHIFT_WL_CK32K_EN)                        /*!<R/W 0  1: enable 32k clock; 0: gated */
#define BIT_SHIFT_WL_CKMCU_EN                        2
#define BIT_WL_CKMCU_EN                              ((u32)0x00000001 << BIT_SHIFT_WL_CKMCU_EN)                        /*!<R/W 0  1: enable MCU engine clock; 0: gated */
#define BIT_SHIFT_WL_CKSEC_EN                        1
#define BIT_WL_CKSEC_EN                              ((u32)0x00000001 << BIT_SHIFT_WL_CKSEC_EN)                        /*!<R/W 0  1: enable MAC security engine clock; 0: gated */
#define BIT_SHIFT_WL_CKMAC_EN                        0
#define BIT_WL_CKMAC_EN                              ((u32)0x00000001 << BIT_SHIFT_WL_CKMAC_EN)                        /*!<R/W 0  1: enable MAC clock; 0: gated */

/* REG_WL_FUNC_EN 0x0004 */
#define BIT_SHIFT_FEN_BBRSTB_V2                      17
#define BIT_FEN_BBRSTB_V2                            ((u32)0x00000001 << BIT_SHIFT_FEN_BBRSTB_V2)                      /*!<R/W 0  When this bit is set to ��0��, CCK and OFDM are disabled, and clock are gated. Otherwise, CCK and OFDM are enabled. */
#define BIT_SHIFT_FEN_BB_GLB_RSTN_V2                 16
#define BIT_FEN_BB_GLB_RSTN_V2                       ((u32)0x00000001 << BIT_SHIFT_FEN_BB_GLB_RSTN_V2)                 /*!<R/W 0  When this bit is set to ��0��, whole BB is reset. When this bit is set, BB is enabled. */
//#define BIT_SHIFT_--                                 10
//#define BIT_MASK_--                                  ((u32)0x0000003F << BIT_SHIFT_--)                                 /*!<-- 0  Reserved */
#define BIT_SHIFT_FEN_MLPLT                          9
#define BIT_FEN_MLPLT                                ((u32)0x00000001 << BIT_SHIFT_FEN_MLPLT)                          /*!<R/W 0   */
#define BIT_SHIFT_RFAFE_HW33PDB                      8
#define BIT_RFAFE_HW33PDB                            ((u32)0x00000001 << BIT_SHIFT_RFAFE_HW33PDB)                      /*!<R/W 0   */
#define BIT_SHIFT_FEN_WLON                           4
#define BIT_FEN_WLON                                 ((u32)0x00000001 << BIT_SHIFT_FEN_WLON)                           /*!<R/W 0  1: enable WL partial ON; 0: reset */
#define BIT_SHIFT_FEN_WLMCU                          3
#define BIT_FEN_WLMCU                                ((u32)0x00000001 << BIT_SHIFT_FEN_WLMCU)                          /*!<R/W 0  1: enable WLMCU; 0: reset */
#define BIT_SHIFT_FEN_MACREG                         2
#define BIT_FEN_MACREG                               ((u32)0x00000001 << BIT_SHIFT_FEN_MACREG)                         /*!<R/W 0  1: enable MAC REG; 0: reset */
#define BIT_SHIFT_FEN_WLOFF                          1
#define BIT_FEN_WLOFF                                ((u32)0x00000001 << BIT_SHIFT_FEN_WLOFF)                          /*!<R/W 0  1: enable WLOFF; 0: reset */
#define BIT_SHIFT_FEN_MAC_PMC                        0
#define BIT_FEN_MAC_PMC                              ((u32)0x00000001 << BIT_SHIFT_FEN_MAC_PMC)                        /*!<R/W 0  1: enable MAC PMC; 0: reset */

/* REG_CLKDIV 0x0008 */
#define BIT_SHIFT_SEC_CLK_SEL                        20
#define BIT_MASK_SEC_CLK_SEL                         ((u32)0x00000003 << BIT_SHIFT_SEC_CLK_SEL)                        /*!<R/W 0  11/10:40M 01:80M 00:160M */
#define BIT_SHIFT_MAC_CLK_SEL                        18
#define BIT_MASK_MAC_CLK_SEL                         ((u32)0x00000003 << BIT_SHIFT_MAC_CLK_SEL)                        /*!<R/W 2'b10  11/10:20M 01:40M 00:80M */
#define BIT_SHIFT_CPU_CLK_SEL                        16
#define BIT_MASK_CPU_CLK_SEL                         ((u32)0x00000003 << BIT_SHIFT_CPU_CLK_SEL)                        /*!<R/W 0   */
#define BIT_SHIFT_WL_CLK_SYNC                        15
#define BIT_WL_CLK_SYNC                              ((u32)0x00000001 << BIT_SHIFT_WL_CLK_SYNC)                        /*!<R/W 0  1: sync 40M/80M clock phase with PLL */
#define BIT_SHIFT_WL_40M_PHASE                       4
#define BIT_MASK_WL_40M_PHASE                        ((u32)0x0000000F << BIT_SHIFT_WL_40M_PHASE)                       /*!<R/W 0  40M MAC clock phase control */
#define BIT_SHIFT_WL_80M_PHASE                       0
#define BIT_MASK_WL_80M_PHASE                        ((u32)0x0000000F << BIT_SHIFT_WL_80M_PHASE)                       /*!<R/W 0  80M security clock phase control */

/* REG_RSV_CTRL 0x001C */
#define BIT_SHIFT_HREG_DBG                           12
#define BIT_MASK_HREG_DBG                            ((u32)0x00000FFF << BIT_SHIFT_HREG_DBG)                           /*!<RO 0  HREG Access Debug information */
#define BIT_SHIFT_LOCK_REGALL_EN                     7
#define BIT_LOCK_REGALL_EN                           ((u32)0x00000001 << BIT_SHIFT_LOCK_REGALL_EN)                     /*!<R/W 0  1:Enable ��Locked All�� setting by Hardware, 0: Hardware Enable ��Locked All�� denied. */
#define BIT_SHIFT_PRST_WLMAC                         6
#define BIT_PRST_WLMAC                               ((u32)0x00000001 << BIT_SHIFT_PRST_WLMAC)                         /*!<R/W 0   */
#define BIT_SHIFT_WLOCK_1C_B6                        5
#define BIT_WLOCK_1C_B6                              ((u32)0x00000001 << BIT_SHIFT_WLOCK_1C_B6)                        /*!<R/W 0  1:Register Write Locked, 0: Register Accessible by SW/FW (offset:0x001C[6]) */
#define BIT_SHIFT_WLOCK_40                           4
#define BIT_WLOCK_40                                 ((u32)0x00000001 << BIT_SHIFT_WLOCK_40)                           /*!<R/W 0  1:Register Write Locked, 0: Register Accessible by SW/FW (offset:0x0040h~0x0043h) */
#define BIT_SHIFT_WLOCK_08                           3
#define BIT_WLOCK_08                                 ((u32)0x00000001 << BIT_SHIFT_WLOCK_08)                           /*!<R/W 0  1:Register Write Locked, 0: Register Accessible by SW/FW (offset:0x0008h~0x000Bh) */
#define BIT_SHIFT_WLOCK_04                           2
#define BIT_WLOCK_04                                 ((u32)0x00000001 << BIT_SHIFT_WLOCK_04)                           /*!<R/W 0  1:Register Write Locked, 0: Register Accessible by SW/FW (offset:0x0004h~0x0007h) */
#define BIT_SHIFT_WLOCK_00                           1
#define BIT_WLOCK_00                                 ((u32)0x00000001 << BIT_SHIFT_WLOCK_00)                           /*!<R/W 0  1:Register Write Locked, 0: Register Accessible by SW/FW (offset:0x0000h~0x0003h) */
#define BIT_SHIFT_WLOCK_ALL                          0
#define BIT_WLOCK_ALL                                ((u32)0x00000001 << BIT_SHIFT_WLOCK_ALL)                          /*!<R/W 0  1:Register Write Locked, 0: Register Accessible by SW/FW (offset:0x0000h~0x00FFh) */

/* REG_WL_PMC_CTRL 0x0020 */
#define BIT_SHIFT_WLPON_OPT_EXCKN2A                  25
#define BIT_WLPON_OPT_EXCKN2A                        ((u32)0x00000001 << BIT_SHIFT_WLPON_OPT_EXCKN2A)                  /*!<R/W 1   */
#define BIT_SHIFT_WLPON_OPT_EXCKP2A                  24
#define BIT_WLPON_OPT_EXCKP2A                        ((u32)0x00000001 << BIT_SHIFT_WLPON_OPT_EXCKP2A)                  /*!<R/W 1  PON option to enable AFE clock */
#define BIT_SHIFT_WL_PMC_CNT_PAR                     8
#define BIT_MASK_WL_PMC_CNT_PAR                      ((u32)0x0000003F << BIT_SHIFT_WL_PMC_CNT_PAR)                     /*!<R/W 0x1F  WL PMC FSM counting unit. */
#define BIT_SHIFT_CUR_PST_IS_LPS                     4
#define BIT_CUR_PST_IS_LPS                           ((u32)0x00000001 << BIT_SHIFT_CUR_PST_IS_LPS)                     /*!<RO   indicate current WL power status is LPS mode */
#define BIT_SHIFT_WL_PMC_LPS_EN                      2
#define BIT_WL_PMC_LPS_EN                            ((u32)0x00000001 << BIT_SHIFT_WL_PMC_LPS_EN)                      /*!<R/W 0  Inform WLAN PMC FSM to enter LPS mode. (auto clear when ready) */

#define BIT_SHIFT_WL_PMC_ONMAC                       0
#define BIT_WL_PMC_ONMAC                             ((u32)0x00000001 << BIT_SHIFT_WL_PMC_ONMAC)                       /*!<R/W 0  Inform WLAN PMC FSM to power On mode, include clock, isolation, power control for MAC only (clear when Power Ready) */

/* REG_WL_SYSCONFIG 0x0024 */
#define BIT_SHIFT_DIS_TIMEOUT_IO                     24
#define BIT_DIS_TIMEOUT_IO                           ((u32)0x00000001 << BIT_SHIFT_DIS_TIMEOUT_IO)                     /*!<R/W 0  Disabled timeout of IO wrapper */
#define BIT_SHIFT_MCU_WDT_MODE                       21
#define BIT_MCU_WDT_MODE                             ((u32)0x00000001 << BIT_SHIFT_MCU_WDT_MODE)                       /*!<R/W 0   */
#define BIT_SHIFT_WLCPU_ANA_PORT_IDLE                17
#define BIT_WLCPU_ANA_PORT_IDLE                      ((u32)0x00000001 << BIT_SHIFT_WLCPU_ANA_PORT_IDLE)                /*!<R 0   */
#define BIT_SHIFT_WLCPU_MAC_PORT_IDLE                16
#define BIT_WLCPU_MAC_PORT_IDLE                      ((u32)0x00000001 << BIT_SHIFT_WLCPU_MAC_PORT_IDLE)                /*!<R 0   */

/* REG_AFC_CTRL0 0x0030 */
#define BIT_SHIFT_POW_AFE_REQ                        13
#define BIT_POW_AFE_REQ                              ((u32)0x00000001 << BIT_SHIFT_POW_AFE_REQ)                        /*!<R/W 0  AFE power on request to afe_ctrl 1:request to turn on AFE pwr 0:turn off AFE pwr */
#define BIT_SHIFT_WL_XTAL_ACTIVE_MODE                7
#define BIT_WL_XTAL_ACTIVE_MODE                      ((u32)0x00000001 << BIT_SHIFT_WL_XTAL_ACTIVE_MODE)                /*!<R/W 1  1:WL request XTAL to enter active mode 0:WL request XTAL to enter LPS mode */
#define BIT_SHIFT_WL_XTAL_EN                         6
#define BIT_WL_XTAL_EN                               ((u32)0x00000001 << BIT_SHIFT_WL_XTAL_EN)                         /*!<R/W 0  1:WL enable XTAL 0:WL disable XTAL */

/* REG_FSIMR_V1 0x0040 */
#define BIT_SHIFT_FS_PWMERR_INT_EN_V1                1
#define BIT_FS_PWMERR_INT_EN_V1                      ((u32)0x00000001 << BIT_SHIFT_FS_PWMERR_INT_EN_V1)                /*!<R/W 0  Enable MCU Access Error interrupt source(TIE0) */
#define BIT_SHIFT_FS_BTON_STS_UPDATE_INT_EN          0
#define BIT_FS_BTON_STS_UPDATE_INT_EN                ((u32)0x00000001 << BIT_SHIFT_FS_BTON_STS_UPDATE_INT_EN)          /*!<R/W 0  BTON status update interrupt When 0xC8[31] toggled, this interrupt is issue to indicate the status updated. */

/* REG_FSISR_V1 0x0044 */
#define BIT_SHIFT_FS_PWMERR_INT_V1                   1
#define BIT_FS_PWMERR_INT_V1                         ((u32)0x00000001 << BIT_SHIFT_FS_PWMERR_INT_V1)                   /*!<R/W1C 0  MCU Access Error interrupt source Write 1 clear(TIE0) */
#define BIT_SHIFT_FS_BTON_STS_UPDATE_INT             0
#define BIT_FS_BTON_STS_UPDATE_INT                   ((u32)0x00000001 << BIT_SHIFT_FS_BTON_STS_UPDATE_INT)             /*!<R/W1C 0  BTON status update interrupt When 0xC8[31] toggled, this interrupt is issue to indicate the status updated. */

/* REG_FW_DBG0_V1 0x0050 */
#define BIT_SHIFT_FW_DBG0                            0
#define BIT_MASK_FW_DBG0                             ((u32)0xFFFFFFFF << BIT_SHIFT_FW_DBG0)                            /*!<R/W 0  fw debug0 */

/* REG_FW_DBG1_V1 0x0054 */
#define BIT_SHIFT_FW_DBG1                            0
#define BIT_MASK_FW_DBG1                             ((u32)0xFFFFFFFF << BIT_SHIFT_FW_DBG1)                            /*!<R/W 0  fw debug1 */

/* REG_FW_DBG2_V1 0x0008 */
#define BIT_SHIFT_FW_DBG2                            0
#define BIT_MASK_FW_DBG2                             ((u32)0xFFFFFFFF << BIT_SHIFT_FW_DBG2)                            /*!<R/W 0  fw debug2 */

/* REG_FW_DBG3_V1 0x000C */
#define BIT_SHIFT_FW_DBG3                            0
#define BIT_MASK_FW_DBG3                             ((u32)0xFFFFFFFF << BIT_SHIFT_FW_DBG3)                            /*!<R/W 0  fw debug3 */

/* REG_FW_DBG4_V1 0x0060 */
#define BIT_SHIFT_FW_DBG4                            0
#define BIT_MASK_FW_DBG4                             ((u32)0xFFFFFFFF << BIT_SHIFT_FW_DBG4)                            /*!<R/W 0  fw debug4 */

/* REG_FW_DBG5_V1 0x0064 */
#define BIT_SHIFT_FW_DBG5                            0
#define BIT_MASK_FW_DBG5                             ((u32)0xFFFFFFFF << BIT_SHIFT_FW_DBG5)                            /*!<R/W 0  fw debug5 */

/* REG_FW_DBG6_V1 0x0068 */
#define BIT_SHIFT_FW_DBG6                            0
#define BIT_MASK_FW_DBG6                             ((u32)0xFFFFFFFF << BIT_SHIFT_FW_DBG6)                            /*!<R/W 0  fw debug6 */

/* REG_FW_DBG7_V1 0x006C */
#define BIT_SHIFT_FW_DBG7                            0
#define BIT_MASK_FW_DBG7                             ((u32)0xFFFFFFFF << BIT_SHIFT_FW_DBG7)                            /*!<R/W 0  fw debug7 */

/* REG_WL_PIN_FUNC_CTRL0 0x0070 */
#define BIT_SHIFT_WL_DBG_SEL                         24
#define BIT_MASK_WL_DBG_SEL                          ((u32)0x000000FF << BIT_SHIFT_WL_DBG_SEL)                         /*!<R/W 0  WL debug select */

/* REG_WL_BTCOEX_CTRL 0x0074 */
#define BIT_SHIFT_LTECOEX_DBGEN                      20
#define BIT_LTECOEX_DBGEN                            ((u32)0x00000001 << BIT_SHIFT_LTECOEX_DBGEN)                      /*!<R/W 0   */
#define BIT_SHIFT_BTMODE_V1                          17
#define BIT_MASK_BTMODE_V1                           ((u32)0x00000003 << BIT_SHIFT_BTMODE_V1)                          /*!<R/W 0  Bluetooth Mode */
#define BIT_SHIFT_ENBT_V1                            16
#define BIT_ENBT_V1                                  ((u32)0x00000001 << BIT_SHIFT_ENBT_V1)                            /*!<R/W 0  Enable PTA ( from BT side) */
#define BIT_SHIFT_WL_DPDT1_IDV                       3
#define BIT_WL_DPDT1_IDV                             ((u32)0x00000001 << BIT_SHIFT_WL_DPDT1_IDV)                       /*!<R/W 1   */
#define BIT_SHIFT_WL_DPDT1_MUX                       2
#define BIT_WL_DPDT1_MUX                             ((u32)0x00000001 << BIT_SHIFT_WL_DPDT1_MUX)                       /*!<R/W 0   */
#define BIT_SHIFT_WL_DPDT0_IDV                       1
#define BIT_WL_DPDT0_IDV                             ((u32)0x00000001 << BIT_SHIFT_WL_DPDT0_IDV)                       /*!<R/W 1   */
#define BIT_SHIFT_WL_DPDT0_MUX                       0
#define BIT_WL_DPDT0_MUX                             ((u32)0x00000001 << BIT_SHIFT_WL_DPDT0_MUX)                       /*!<R/W 0   */

/* REG_DBG_PORT_REG 0x007C */
#define BIT_SHIFT_DEBUG_ST                           0
#define BIT_MASK_DEBUG_ST                            ((u32)0xFFFFFFFF << BIT_SHIFT_DEBUG_ST)                           /*!<RO 0  Debug signals, sel by 70[31:24] */

/* REG_WL_MCUFW_CTRL 0x0080 */
#define BIT_SHIFT_FW_INIT_RDY                        15
#define BIT_FW_INIT_RDY                              ((u32)0x00000001 << BIT_SHIFT_FW_INIT_RDY)                        /*!<R/W 0  CPU fw initialize ready, set by CPU */

/* REG_BLK_TST 0x0084 */
#define BIT_SHIFT_BLK_TST                            0
#define BIT_MASK_BLK_TST                             ((u32)0xFFFFFFFF << BIT_SHIFT_BLK_TST)                            /*!<R/W 0  fw debug8 */

/* REG_HOST_MSG0 0x0088 */
#define BIT_SHIFT_HOST_MSG_E1                        16
#define BIT_MASK_HOST_MSG_E1                         ((u32)0x0000FFFF << BIT_SHIFT_HOST_MSG_E1)                        /*!<R/W 0  User Defined Message */
#define BIT_SHIFT_HOST_MSG_E0                        0
#define BIT_MASK_HOST_MSG_E0                         ((u32)0x0000FFFF << BIT_SHIFT_HOST_MSG_E0)                        /*!<R/W 0  User Defined Message */

/* REG_HOST_MSG1 0x008C */
#define BIT_SHIFT_HOST_MSG_E3                        16
#define BIT_MASK_HOST_MSG_E3                         ((u32)0x0000FFFF << BIT_SHIFT_HOST_MSG_E3)                        /*!<R/W 0  User Defined Message */
#define BIT_SHIFT_HOST_MSG_E2                        0
#define BIT_MASK_HOST_MSG_E2                         ((u32)0x0000FFFF << BIT_SHIFT_HOST_MSG_E2)                        /*!<R/W 0  User Defined Message */

/* REG_LPS_CTRL 0x0090 */

#define BIT_SHIFT_LPS_MEMPM_PHYON                    28
#define BIT_LPS_MEMPM_PHYON                          ((u32)0x00000001 << BIT_SHIFT_LPS_MEMPM_PHYON)                    /*!<R/W 0   */
#define BIT_SHIFT_LPS_MEMPM_MACOFF_ARM_SPRAM         25
#define BIT_MASK_LPS_MEMPM_MACOFF_ARM_SPRAM          ((u32)0x00000007 << BIT_SHIFT_LPS_MEMPM_MACOFF_ARM_SPRAM)         /*!<R/W 111  MAC OFF ARM memory power mode when enable LPS memory power mode(for rxpktbuf/ txpktbuf low 24k[SHARE with system]) [pgen,ret1n,ret2n] 01x : normal mode 00x : selective precharge mode 10x : retention mode 1 110 : retention mode 2 111 : power down mode */
#define BIT_SHIFT_LPS_MEMPM_MACOFF_ARM_RF            22
#define BIT_MASK_LPS_MEMPM_MACOFF_ARM_RF             ((u32)0x00000007 << BIT_SHIFT_LPS_MEMPM_MACOFF_ARM_RF)            /*!<R/W 111  MAC OFF ARM memory power mode when enable LPS memory power mode (for txrptbuf/rxcsibuf) [pgen,ret1n,ret2n] 01x : normal mode 00x : selective precharge mode 10x : retention mode 1 110 : retention mode 2 111 : power down mode */
#define BIT_SHIFT_LPS_MEMPM_MACON_ARM_SPRAM          19
#define BIT_MASK_LPS_MEMPM_MACON_ARM_SPRAM           ((u32)0x00000007 << BIT_SHIFT_LPS_MEMPM_MACON_ARM_SPRAM)          /*!<R/W 110  MAC ON ARM memory power mode when enable LPS memory power mode (for txpktbuf high 8k) [pgen,ret1n,ret2n] 01x : normal mode 00x : selective precharge mode 10x : retention mode 1 110 : retention mode 2 111 : power down mode */
#define BIT_SHIFT_LPS_MEMPM_MACOFF_FTC               18
#define BIT_LPS_MEMPM_MACOFF_FTC                     ((u32)0x00000001 << BIT_SHIFT_LPS_MEMPM_MACOFF_FTC)               /*!<R/W 1  MAC OFF FTC memory power mode when enable LPS memory power mode (for txllt/rc4/txoqt/keysrch/rxfifo/txfifo/rxbacam/dmafifo) 0 : normal 1 : NAP */
#define BIT_SHIFT_LPS_MEMPM_MACON_FTC                17
#define BIT_LPS_MEMPM_MACON_FTC                      ((u32)0x00000001 << BIT_SHIFT_LPS_MEMPM_MACON_FTC)                /*!<R/W 1  MAC ON FTC memory power mode when enable LPS memory power mode(not used ) 0 : normal 1 : NAP */
#define BIT_SHIFT_LPS_MEMPM_MACOFF_SNPS              15
#define BIT_MASK_LPS_MEMPM_MACOFF_SNPS               ((u32)0x00000003 << BIT_SHIFT_LPS_MEMPM_MACOFF_SNPS)              /*!<R/W 11  MAC OFF SNPS memory power mode when enable LPS memory power mode(for zgb_txbuf/zgb_rxbuf) 00 : normal 01 : LS 10 : DS 11 : SD */
#define BIT_SHIFT_WL_LPS_OPT_PFM_EN                  14
#define BIT_WL_LPS_OPT_PFM_EN                        ((u32)0x00000001 << BIT_SHIFT_WL_LPS_OPT_PFM_EN)                  /*!<R/W 0  LPS option to switch to PFM mode 1: set to PFM mode 0: stay in PWM mode */
#define BIT_SHIFT_WL_LPS_OPT_SWR_0P9                 13
#define BIT_WL_LPS_OPT_SWR_0P9                       ((u32)0x00000001 << BIT_SHIFT_WL_LPS_OPT_SWR_0P9)                 /*!<R/W 0  LPS option to set SWR voltage 0.9V 1: set SWR voltage 0.9V 0: set SWR voltage 1.1V */
#define BIT_SHIFT_WL_LPS_OPT_LP_XTAL                 12
#define BIT_WL_LPS_OPT_LP_XTAL                       ((u32)0x00000001 << BIT_SHIFT_WL_LPS_OPT_LP_XTAL)                 /*!<R/W 0  LPS option to set XTAL low power mode when enable XTAL 1: set XTAL low power mode 0: set XTAL active mode */
#define BIT_SHIFT_WL_LPS_OPT_DIS_XTAL                11
#define BIT_WL_LPS_OPT_DIS_XTAL                      ((u32)0x00000001 << BIT_SHIFT_WL_LPS_OPT_DIS_XTAL)                /*!<R/W 0  LPS option to disable XTAL 1: disable XTAL 0: enable XTAL */
#define BIT_SHIFT_WL_LPS_OPT_EMACFUN                 10
#define BIT_WL_LPS_OPT_EMACFUN                       ((u32)0x00000001 << BIT_SHIFT_WL_LPS_OPT_EMACFUN)                 /*!<R/W 0  LPS option to reset WL MAC OFF block when enable WL MAC OFF power 1: not reset WL MAC OFF block 0: reset WL MAC OFF block */
#define BIT_SHIFT_WL_LPS_OPT_EPHYPWR                 9
#define BIT_WL_LPS_OPT_EPHYPWR                       ((u32)0x00000001 << BIT_SHIFT_WL_LPS_OPT_EPHYPWR)                 /*!<R/W 0  LPS option to enable WL BB block power 1: Enable WL BB block power 0: Disable WL BB block power */
#define BIT_SHIFT_WL_LPS_OPT_EMACPWR                 8
#define BIT_WL_LPS_OPT_EMACPWR                       ((u32)0x00000001 << BIT_SHIFT_WL_LPS_OPT_EMACPWR)                 /*!<R/W 0  LPS option to enable WL MAC OFF block power 1: Enable WL MAC OFF block power 0: Disable WL MAC OFF block power */

#define BIT_SHIFT_WL_LPS_MEMPM_EN_PG                 2
#define BIT_WL_LPS_MEMPM_EN_PG                       ((u32)0x00000001 << BIT_SHIFT_WL_LPS_MEMPM_EN_PG)                 /*!<R/W 0  enable LPS memory power mode control of pgen */
#define BIT_SHIFT_WL_LPS_MEMPM_EN                    1
#define BIT_WL_LPS_MEMPM_EN                          ((u32)0x00000001 << BIT_SHIFT_WL_LPS_MEMPM_EN)                    /*!<R/W 0  enable LPS memory power mode control */
#define BIT_SHIFT_WL_NRM_MEMPM_SL                    0
#define BIT_WL_NRM_MEMPM_SL                          ((u32)0x00000001 << BIT_SHIFT_WL_NRM_MEMPM_SL)                    /*!<R/W 0  MAC memory power mode when BIT_WL_LPS_MEMPM_EN is 0, 0 : Normal 1 : SD */

/* REG_BOOT_REASON 0x0098 */

#define BIT_SHIFT_WL_WDT_PLFM                        1
#define BIT_WL_WDT_PLFM                              ((u32)0x00000001 << BIT_SHIFT_WL_WDT_PLFM)                        /*!<R/W 0   */
#define BIT_SHIFT_WL_WDT_MCU                         0
#define BIT_WL_WDT_MCU                               ((u32)0x00000001 << BIT_SHIFT_WL_WDT_MCU)                         /*!<R/W 0   */

/* REG_RPWM2 0x009C */
#define BIT_SHIFT_RPWM2                              16
#define BIT_MASK_RPWM2                               ((u32)0x0000FFFF << BIT_SHIFT_RPWM2)                              /*!<RO 0  Host Request Power State. This register is a direct bus signal from each HCI block HRPWM register. When bit 31 is toggled, RPWMINT is issued to MCU. */
#define BIT_SHIFT_RPWM_V1                            0
#define BIT_MASK_RPWM_V1                             ((u32)0x000000FF << BIT_SHIFT_RPWM_V1)                            /*!<RO 0  Host Request Power State. This register is a direct bus signal from each HCI block HRPWM register. When bit 7 is toggled, RPWMINT is issued to MCU. */

/* REG_SCOREBOARD_CTRL 0x00A0 */
#define BIT_SHIFT_BT_INT_EN                          31
#define BIT_BT_INT_EN                                ((u32)0x00000001 << BIT_SHIFT_BT_INT_EN)                          /*!<R/W 0  For WL, write 1 to issue interrupt 1 : Issue one INT to BT 0 : Don't care */
#define BIT_SHIFT_RD_WR_WIFI_BT_INFO                 0
#define BIT_MASK_RD_WR_WIFI_BT_INFO                  ((u32)0x7FFFFFFF << BIT_SHIFT_RD_WR_WIFI_BT_INFO)                 /*!<R 0  Read Data : From BTON Status Report INFO Write Data : To BT INFO, WLON Status Report */

/* REG_SYSON_FSM_MON_V1 0x00A4 */

#define BIT_SHIFT_WLPMC_DEBUG_SEL                    24
#define BIT_MASK_WLPMC_DEBUG_SEL                     ((u32)0x0000000F << BIT_SHIFT_WLPMC_DEBUG_SEL)                    /*!<R/W 0  debug select signal for WL PMC */
#define BIT_SHIFT_WLPMC_DEBUG                        0
#define BIT_MASK_WLPMC_DEBUG                         ((u32)0x0000FFFF << BIT_SHIFT_WLPMC_DEBUG)                        /*!<RO 0  debug signal of WL PMC */

/* REG_PMC_DBG_CTRL1 0x00A8 */
#define BIT_SHIFT_PMC_WR_OVF                         8
#define BIT_PMC_WR_OVF                               ((u32)0x00000001 << BIT_SHIFT_PMC_WR_OVF)                         /*!<R/W1C 0  PMC Write Access Timer Overflow */
#define BIT_SHIFT_WLPMC_ERRINT                       0
#define BIT_MASK_WLPMC_ERRINT                        ((u32)0x000000FF << BIT_SHIFT_WLPMC_ERRINT)                       /*!<R/W1C 0  WLPMC Error interrupt */

/* REG_PMC_DBG_CTRL2_V1 0x00AC */

#define BIT_SHIFT_SYSON_REG_ARB                      0
#define BIT_MASK_SYSON_REG_ARB                       ((u32)0x00000003 << BIT_SHIFT_SYSON_REG_ARB)                      /*!<R/W 0  HW PMC Access Register Time Out Control */

/* REG_HIMR0 0x00B0 */
#define BIT_SHIFT_HISR1_INT_EN                       31
#define BIT_HISR1_INT_EN                             ((u32)0x00000001 << BIT_SHIFT_HISR1_INT_EN)                       /*!<R/W 0  HISR1 Indicator (HIISR1 andHIMR1 are true, this bit is set to 1) */
#define BIT_SHIFT_RXDES_UNAVAIL_INT_EN               30
#define BIT_RXDES_UNAVAIL_INT_EN                     ((u32)0x00000001 << BIT_SHIFT_RXDES_UNAVAIL_INT_EN)               /*!<R/W 0  Rx Descriptor Unavailable */
#define BIT_SHIFT_HISR2_INT_EN                       29
#define BIT_HISR2_INT_EN                             ((u32)0x00000001 << BIT_SHIFT_HISR2_INT_EN)                       /*!<R/W 0  HISR2 Indicator (HIISR2 andHIMR2 are true, this bit is set to 1) */
#define BIT_SHIFT_EVTQ_DONE_INT_EN                   28
#define BIT_EVTQ_DONE_INT_EN                         ((u32)0x00000001 << BIT_SHIFT_EVTQ_DONE_INT_EN)                   /*!<R/W 0  event queue done interrupt for NAN */
#define BIT_SHIFT_EVTQ_START_INT_EN_V1               27
#define BIT_EVTQ_START_INT_EN_V1                     ((u32)0x00000001 << BIT_SHIFT_EVTQ_START_INT_EN_V1)               /*!<R/W 0  event queue start interrupt for NAN */
#define BIT_SHIFT_FWMSG_INT_EN                       26
#define BIT_FWMSG_INT_EN                             ((u32)0x00000001 << BIT_SHIFT_FWMSG_INT_EN)                       /*!<R/W 0  FW message interrupt,CPU to Host Command INT Status, Write 1 clear */
#define BIT_SHIFT_HCPWM2_INT_EN                      25
#define BIT_HCPWM2_INT_EN                            ((u32)0x00000001 << BIT_SHIFT_HCPWM2_INT_EN)                      /*!<R/W 0  CPWM2 interrupt,CPU power Mode exchange INT Status, Write 1 clear */
#define BIT_SHIFT_HCPWM_INT_EN                       24
#define BIT_HCPWM_INT_EN                             ((u32)0x00000001 << BIT_SHIFT_HCPWM_INT_EN)                       /*!<R/W 0  CPWM interrupt,CPU power Mode exchange INT Status, Write 1 clear */
#define BIT_SHIFT_RXFF_FULL_INT_EN                   23
#define BIT_RXFF_FULL_INT_EN                         ((u32)0x00000001 << BIT_SHIFT_RXFF_FULL_INT_EN)                   /*!<R/W 0  Rxpktbuffer full interrupt */
#define BIT_SHIFT_RDE_ERR_INT_EN                     22
#define BIT_RDE_ERR_INT_EN                           ((u32)0x00000001 << BIT_SHIFT_RDE_ERR_INT_EN)                     /*!<R/W 0  Rxdma error interrupt */
#define BIT_SHIFT_TDE_ERR_INT_EN                     21
#define BIT_TDE_ERR_INT_EN                           ((u32)0x00000001 << BIT_SHIFT_TDE_ERR_INT_EN)                     /*!<R/W 0  Txdma error interrupt */
#define BIT_SHIFT_TXFF_FIFO_INT_EN                   20
#define BIT_TXFF_FIFO_INT_EN                         ((u32)0x00000001 << BIT_SHIFT_TXFF_FIFO_INT_EN)                   /*!<R/W 0  txpktbuffer full interrupt */
#define BIT_SHIFT_TXBCN8_ERR_INT_EN                  19
#define BIT_TXBCN8_ERR_INT_EN                        ((u32)0x00000001 << BIT_SHIFT_TXBCN8_ERR_INT_EN)                  /*!<R/W 0  port0 BSSID7 TX beacon error interrupt */
#define BIT_SHIFT_TXBCN7_ERR_INT_EN                  18
#define BIT_TXBCN7_ERR_INT_EN                        ((u32)0x00000001 << BIT_SHIFT_TXBCN7_ERR_INT_EN)                  /*!<R/W 0  port0 BSSID6 TX beacon error interrupt */
#define BIT_SHIFT_TXBCN6_ERR_INT_EN                  17
#define BIT_TXBCN6_ERR_INT_EN                        ((u32)0x00000001 << BIT_SHIFT_TXBCN6_ERR_INT_EN)                  /*!<R/W 0  port0 BSSID5 TX beacon error interrupt */
#define BIT_SHIFT_TXBCN5_ERR_INT_EN                  16
#define BIT_TXBCN5_ERR_INT_EN                        ((u32)0x00000001 << BIT_SHIFT_TXBCN5_ERR_INT_EN)                  /*!<R/W 0  port0 BSSID4 TX beacon error interrupt */
#define BIT_SHIFT_TXBCN4_ERR_INT_EN                  15
#define BIT_TXBCN4_ERR_INT_EN                        ((u32)0x00000001 << BIT_SHIFT_TXBCN4_ERR_INT_EN)                  /*!<R/W 0  port0 BSSID3 TX beacon error interrupt */
#define BIT_SHIFT_TXBCN3_ERR_INT_EN                  14
#define BIT_TXBCN3_ERR_INT_EN                        ((u32)0x00000001 << BIT_SHIFT_TXBCN3_ERR_INT_EN)                  /*!<R/W 0  port0 BSSID2 TX beacon error interrupt */
#define BIT_SHIFT_TXBCN2_ERR_INT_EN                  13
#define BIT_TXBCN2_ERR_INT_EN                        ((u32)0x00000001 << BIT_SHIFT_TXBCN2_ERR_INT_EN)                  /*!<R/W 0  port0 BSSID1 TX beacon error interrupt */
#define BIT_SHIFT_TXBCN1_ERR_INT_EN                  12
#define BIT_TXBCN1_ERR_INT_EN                        ((u32)0x00000001 << BIT_SHIFT_TXBCN1_ERR_INT_EN)                  /*!<R/W 0  port0 BSSID0 TX beacon error interrupt */
#define BIT_SHIFT_TXBCN8_OK_INT_EN                   11
#define BIT_TXBCN8_OK_INT_EN                         ((u32)0x00000001 << BIT_SHIFT_TXBCN8_OK_INT_EN)                   /*!<R/W 0  port0 BSSID7 TX beacon ok interrupt */
#define BIT_SHIFT_TXBCN7_OK_INT_EN                   10
#define BIT_TXBCN7_OK_INT_EN                         ((u32)0x00000001 << BIT_SHIFT_TXBCN7_OK_INT_EN)                   /*!<R/W 0  port0 BSSID6 TX beacon ok interrupt */
#define BIT_SHIFT_TXBCN6_OK_INT_EN                   9
#define BIT_TXBCN6_OK_INT_EN                         ((u32)0x00000001 << BIT_SHIFT_TXBCN6_OK_INT_EN)                   /*!<R/W 0  port0 BSSID5 TX beacon ok interrupt */
#define BIT_SHIFT_TXBCN5_OK_INT_EN                   8
#define BIT_TXBCN5_OK_INT_EN                         ((u32)0x00000001 << BIT_SHIFT_TXBCN5_OK_INT_EN)                   /*!<R/W 0  port0 BSSID4 TX beacon ok interrupt */
#define BIT_SHIFT_TXBCN4_OK_INT_EN                   7
#define BIT_TXBCN4_OK_INT_EN                         ((u32)0x00000001 << BIT_SHIFT_TXBCN4_OK_INT_EN)                   /*!<R/W 0  port0 BSSID3 TX beacon ok interrupt */
#define BIT_SHIFT_TXBCN3_OK_INT_EN                   6
#define BIT_TXBCN3_OK_INT_EN                         ((u32)0x00000001 << BIT_SHIFT_TXBCN3_OK_INT_EN)                   /*!<R/W 0  port0 BSSID2 TX beacon ok interrupt */
#define BIT_SHIFT_TXBCN2_OK_INT_EN                   5
#define BIT_TXBCN2_OK_INT_EN                         ((u32)0x00000001 << BIT_SHIFT_TXBCN2_OK_INT_EN)                   /*!<R/W 0  port0 BSSID1 TX beacon ok interrupt */
#define BIT_SHIFT_TXBCN1_OK_INT_EN                   4
#define BIT_TXBCN1_OK_INT_EN                         ((u32)0x00000001 << BIT_SHIFT_TXBCN1_OK_INT_EN)                   /*!<R/W 0  port0 BSSID0 TX beacon ok interrupt */
#define BIT_SHIFT_TSF_BIT32_TOGGLE_INT_EN            3
#define BIT_TSF_BIT32_TOGGLE_INT_EN                  ((u32)0x00000001 << BIT_SHIFT_TSF_BIT32_TOGGLE_INT_EN)            /*!<R/W 0  TSF Timer BIT32 toggle indication interrupt */
#define BIT_SHIFT_TIMEOUT2_INT_EN                    2
#define BIT_TIMEOUT2_INT_EN                          ((u32)0x00000001 << BIT_SHIFT_TIMEOUT2_INT_EN)                    /*!<R/W 0  tsf Timer2 interrupt */
#define BIT_SHIFT_TIMEOUT1_V1_INT_EN                 1
#define BIT_TIMEOUT1_V1_INT_EN                       ((u32)0x00000001 << BIT_SHIFT_TIMEOUT1_V1_INT_EN)                 /*!<R/W 0  tsf Timer1 interrupt */
#define BIT_SHIFT_TIMEOUT0_V1_INT_EN                 0
#define BIT_TIMEOUT0_V1_INT_EN                       ((u32)0x00000001 << BIT_SHIFT_TIMEOUT0_V1_INT_EN)                 /*!<R/W 0  tsf Timer0 interrupt */

/* REG_HISR0 0x00B4 */
#define BIT_SHIFT_HISR1_INT                          31
#define BIT_HISR1_INT                                ((u32)0x00000001 << BIT_SHIFT_HISR1_INT)                          /*!<R/W1C 0  HISR1 Indicator (HIISR1 andHIMR1 are true, this bit is set to 1) */
#define BIT_SHIFT_RXDES_UNAVAIL_INT                  30
#define BIT_RXDES_UNAVAIL_INT                        ((u32)0x00000001 << BIT_SHIFT_RXDES_UNAVAIL_INT)                  /*!<R/W1C 0  Rx Descriptor Unavailable */
#define BIT_SHIFT_HISR2_INT                          29
#define BIT_HISR2_INT                                ((u32)0x00000001 << BIT_SHIFT_HISR2_INT)                          /*!<R/W1C 0  HISR2 Indicator (HIISR2 andHIMR2 are true, this bit is set to 1) */
#define BIT_SHIFT_EVTQ_DONE_INT                      28
#define BIT_EVTQ_DONE_INT                            ((u32)0x00000001 << BIT_SHIFT_EVTQ_DONE_INT)                      /*!<R/W1C 0  event queue done interrupt for NAN */
#define BIT_SHIFT_EVTQ_START_INT_V1                  27
#define BIT_EVTQ_START_INT_V1                        ((u32)0x00000001 << BIT_SHIFT_EVTQ_START_INT_V1)                  /*!<R/W1C 0  event queue start interrupt for NAN */
#define BIT_SHIFT_FWMSG_INT                          26
#define BIT_FWMSG_INT                                ((u32)0x00000001 << BIT_SHIFT_FWMSG_INT)                          /*!<R/W1C 0  FW message interrupt,CPU to Host Command INT Status, Write 1 clear */
#define BIT_SHIFT_HCPWM2_INT                         25
#define BIT_HCPWM2_INT                               ((u32)0x00000001 << BIT_SHIFT_HCPWM2_INT)                         /*!<R/W1C 0  CPWM2 interrupt,CPU power Mode exchange INT Status, Write 1 clear */
#define BIT_SHIFT_HCPWM_INT                          24
#define BIT_HCPWM_INT                                ((u32)0x00000001 << BIT_SHIFT_HCPWM_INT)                          /*!<R/W1C 0  CPWM interrupt,CPU power Mode exchange INT Status, Write 1 clear */
#define BIT_SHIFT_RXFF_FULL_INT                      23
#define BIT_RXFF_FULL_INT                            ((u32)0x00000001 << BIT_SHIFT_RXFF_FULL_INT)                      /*!<R/W1C 0  Rxpktbuffer full interrupt */
#define BIT_SHIFT_RDE_ERR_INT                        22
#define BIT_RDE_ERR_INT                              ((u32)0x00000001 << BIT_SHIFT_RDE_ERR_INT)                        /*!<R/W1C 0  Rxdma error interrupt */
#define BIT_SHIFT_TDE_ERR_INT                        21
#define BIT_TDE_ERR_INT                              ((u32)0x00000001 << BIT_SHIFT_TDE_ERR_INT)                        /*!<R/W1C 0  Txdma error interrupt */
#define BIT_SHIFT_TXFF_FIFO_INT                      20
#define BIT_TXFF_FIFO_INT                            ((u32)0x00000001 << BIT_SHIFT_TXFF_FIFO_INT)                      /*!<R/W1C 0  txpktbuffer full interrupt */
#define BIT_SHIFT_TXBCN8_ERR_INT                     19
#define BIT_TXBCN8_ERR_INT                           ((u32)0x00000001 << BIT_SHIFT_TXBCN8_ERR_INT)                     /*!<R/W1C 0  port0 BSSID7 TX beacon error interrupt */
#define BIT_SHIFT_TXBCN7_ERR_INT                     18
#define BIT_TXBCN7_ERR_INT                           ((u32)0x00000001 << BIT_SHIFT_TXBCN7_ERR_INT)                     /*!<R/W1C 0  port0 BSSID6 TX beacon error interrupt */
#define BIT_SHIFT_TXBCN6_ERR_INT                     17
#define BIT_TXBCN6_ERR_INT                           ((u32)0x00000001 << BIT_SHIFT_TXBCN6_ERR_INT)                     /*!<R/W1C 0  port0 BSSID5 TX beacon error interrupt */
#define BIT_SHIFT_TXBCN5_ERR_INT                     16
#define BIT_TXBCN5_ERR_INT                           ((u32)0x00000001 << BIT_SHIFT_TXBCN5_ERR_INT)                     /*!<R/W1C 0  port0 BSSID4 TX beacon error interrupt */
#define BIT_SHIFT_TXBCN4_ERR_INT                     15
#define BIT_TXBCN4_ERR_INT                           ((u32)0x00000001 << BIT_SHIFT_TXBCN4_ERR_INT)                     /*!<R/W1C 0  port0 BSSID3 TX beacon error interrupt */
#define BIT_SHIFT_TXBCN3_ERR_INT                     14
#define BIT_TXBCN3_ERR_INT                           ((u32)0x00000001 << BIT_SHIFT_TXBCN3_ERR_INT)                     /*!<R/W1C 0  port0 BSSID2 TX beacon error interrupt */
#define BIT_SHIFT_TXBCN2_ERR_INT                     13
#define BIT_TXBCN2_ERR_INT                           ((u32)0x00000001 << BIT_SHIFT_TXBCN2_ERR_INT)                     /*!<R/W1C 0  port0 BSSID1 TX beacon error interrupt */
#define BIT_SHIFT_TXBCN1_ERR_INT                     12
#define BIT_TXBCN1_ERR_INT                           ((u32)0x00000001 << BIT_SHIFT_TXBCN1_ERR_INT)                     /*!<R/W1C 0  port0 BSSID0 TX beacon error interrupt */
#define BIT_SHIFT_TXBCN8_OK_INT                      11
#define BIT_TXBCN8_OK_INT                            ((u32)0x00000001 << BIT_SHIFT_TXBCN8_OK_INT)                      /*!<R/W1C 0  port0 BSSID7 TX beacon ok interrupt */
#define BIT_SHIFT_TXBCN7_OK_INT                      10
#define BIT_TXBCN7_OK_INT                            ((u32)0x00000001 << BIT_SHIFT_TXBCN7_OK_INT)                      /*!<R/W1C 0  port0 BSSID6 TX beacon ok interrupt */
#define BIT_SHIFT_TXBCN6_OK_INT                      9
#define BIT_TXBCN6_OK_INT                            ((u32)0x00000001 << BIT_SHIFT_TXBCN6_OK_INT)                      /*!<R/W1C 0  port0 BSSID5 TX beacon ok interrupt */
#define BIT_SHIFT_TXBCN5_OK_INT                      8
#define BIT_TXBCN5_OK_INT                            ((u32)0x00000001 << BIT_SHIFT_TXBCN5_OK_INT)                      /*!<R/W1C 0  port0 BSSID4 TX beacon ok interrupt */
#define BIT_SHIFT_TXBCN4_OK_INT                      7
#define BIT_TXBCN4_OK_INT                            ((u32)0x00000001 << BIT_SHIFT_TXBCN4_OK_INT)                      /*!<R/W1C 0  port0 BSSID3 TX beacon ok interrupt */
#define BIT_SHIFT_TXBCN3_OK_INT                      6
#define BIT_TXBCN3_OK_INT                            ((u32)0x00000001 << BIT_SHIFT_TXBCN3_OK_INT)                      /*!<R/W1C 0  port0 BSSID2 TX beacon ok interrupt */
#define BIT_SHIFT_TXBCN2_OK_INT                      5
#define BIT_TXBCN2_OK_INT                            ((u32)0x00000001 << BIT_SHIFT_TXBCN2_OK_INT)                      /*!<R/W1C 0  port0 BSSID1 TX beacon ok interrupt */
#define BIT_SHIFT_TXBCN1_OK_INT                      4
#define BIT_TXBCN1_OK_INT                            ((u32)0x00000001 << BIT_SHIFT_TXBCN1_OK_INT)                      /*!<R/W1C 0  port0 BSSID0 TX beacon ok interrupt */
#define BIT_SHIFT_TSF_BIT32_TOGGLE_INT               3
#define BIT_TSF_BIT32_TOGGLE_INT                     ((u32)0x00000001 << BIT_SHIFT_TSF_BIT32_TOGGLE_INT)               /*!<R/W1C 0  TSF Timer BIT32 toggle indication interrupt */
#define BIT_SHIFT_TIMEOUT2_INT                       2
#define BIT_TIMEOUT2_INT                             ((u32)0x00000001 << BIT_SHIFT_TIMEOUT2_INT)                       /*!<R/W1C 0  tsf Timer2 interrupt */
#define BIT_SHIFT_TIMEOUT1_INT_V1                    1
#define BIT_TIMEOUT1_INT_V1                          ((u32)0x00000001 << BIT_SHIFT_TIMEOUT1_INT_V1)                    /*!<R/W1C 0  tsf Timer1 interrupt */
#define BIT_SHIFT_TIMEOUT0_INT_V1                    0
#define BIT_TIMEOUT0_INT_V1                          ((u32)0x00000001 << BIT_SHIFT_TIMEOUT0_INT_V1)                    /*!<R/W1C 0  tsf Timer0 interrupt */

/* REG_HEMR 0x00B8 */
#define BIT_SHIFT_CTWEND1_INT_EN                     31
#define BIT_CTWEND1_INT_EN                           ((u32)0x00000001 << BIT_SHIFT_CTWEND1_INT_EN)                     /*!<R/W 0  Client1 traffic window end interrupt for P2P */
#define BIT_SHIFT_CTWEND0_INT_EN                     30
#define BIT_CTWEND0_INT_EN                           ((u32)0x00000001 << BIT_SHIFT_CTWEND0_INT_EN)                     /*!<R/W 0  Client0 traffic window end interrupt for P2P */
#define BIT_SHIFT_DWWIN_END_INT_EN_V1                29
#define BIT_DWWIN_END_INT_EN_V1                      ((u32)0x00000001 << BIT_SHIFT_DWWIN_END_INT_EN_V1)                /*!<R/W 0  discovery window end interrupt for NAN */
#define BIT_SHIFT_ATIMEND8_INT_EN                    28
#define BIT_ATIMEND8_INT_EN                          ((u32)0x00000001 << BIT_SHIFT_ATIMEND8_INT_EN)                    /*!<R/W 0  port1 atimend interrupt */
#define BIT_SHIFT_ATIMEND7_INT_EN                    27
#define BIT_ATIMEND7_INT_EN                          ((u32)0x00000001 << BIT_SHIFT_ATIMEND7_INT_EN)                    /*!<R/W 0  port0 BSSID7 atimend interrupt */
#define BIT_SHIFT_ATIMEND6_INT_EN                    26
#define BIT_ATIMEND6_INT_EN                          ((u32)0x00000001 << BIT_SHIFT_ATIMEND6_INT_EN)                    /*!<R/W 0  port0 BSSID6 atimend interrupt */
#define BIT_SHIFT_ATIMEND5_INT_EN                    25
#define BIT_ATIMEND5_INT_EN                          ((u32)0x00000001 << BIT_SHIFT_ATIMEND5_INT_EN)                    /*!<R/W 0  port0 BSSID5 atimend interrupt */
#define BIT_SHIFT_ATIMEND4_INT_EN                    24
#define BIT_ATIMEND4_INT_EN                          ((u32)0x00000001 << BIT_SHIFT_ATIMEND4_INT_EN)                    /*!<R/W 0  port0 BSSID4 atimend interrupt */
#define BIT_SHIFT_ATIMEND3_INT_EN                    23
#define BIT_ATIMEND3_INT_EN                          ((u32)0x00000001 << BIT_SHIFT_ATIMEND3_INT_EN)                    /*!<R/W 0  port0 BSSID3 atimend interrupt */
#define BIT_SHIFT_ATIMEND2_INT_EN                    22
#define BIT_ATIMEND2_INT_EN                          ((u32)0x00000001 << BIT_SHIFT_ATIMEND2_INT_EN)                    /*!<R/W 0  port0 BSSID2 atimend interrupt */
#define BIT_SHIFT_ATIMEND1_INT_EN                    21
#define BIT_ATIMEND1_INT_EN                          ((u32)0x00000001 << BIT_SHIFT_ATIMEND1_INT_EN)                    /*!<R/W 0  port0 BSSID1 atimend interrupt */
#define BIT_SHIFT_ATIMEND0_INT_EN                    20
#define BIT_ATIMEND0_INT_EN                          ((u32)0x00000001 << BIT_SHIFT_ATIMEND0_INT_EN)                    /*!<R/W 0  port0 BSSID0 atimend interrupt */
#define BIT_SHIFT_BCNERLY8_INT_EN                    19
#define BIT_BCNERLY8_INT_EN                          ((u32)0x00000001 << BIT_SHIFT_BCNERLY8_INT_EN)                    /*!<R/W 0  port1 beacon early interrupt */
#define BIT_SHIFT_BCNERLY7_INT_EN                    18
#define BIT_BCNERLY7_INT_EN                          ((u32)0x00000001 << BIT_SHIFT_BCNERLY7_INT_EN)                    /*!<R/W 0  port0 BSSID7 beacon early interrupt , only valid under MBSSID mode */
#define BIT_SHIFT_BCNERLY6_INT_EN                    17
#define BIT_BCNERLY6_INT_EN                          ((u32)0x00000001 << BIT_SHIFT_BCNERLY6_INT_EN)                    /*!<R/W 0  port0 BSSID6 beacon early interrupt , only valid under MBSSID mode */
#define BIT_SHIFT_BCNERLY5_INT_EN                    16
#define BIT_BCNERLY5_INT_EN                          ((u32)0x00000001 << BIT_SHIFT_BCNERLY5_INT_EN)                    /*!<R/W 0  port0 BSSID5 beacon early interrupt , only valid under MBSSID mode */
#define BIT_SHIFT_BCNERLY4_INT_EN                    15
#define BIT_BCNERLY4_INT_EN                          ((u32)0x00000001 << BIT_SHIFT_BCNERLY4_INT_EN)                    /*!<R/W 0  port0 BSSID4 beacon early interrupt, only valid under MBSSID mode */
#define BIT_SHIFT_BCNERLY3_INT_EN                    14
#define BIT_BCNERLY3_INT_EN                          ((u32)0x00000001 << BIT_SHIFT_BCNERLY3_INT_EN)                    /*!<R/W 0  port0 BSSID3 beacon early interrupt , only valid under MBSSID mode */
#define BIT_SHIFT_BCNERLY2_INT_EN                    13
#define BIT_BCNERLY2_INT_EN                          ((u32)0x00000001 << BIT_SHIFT_BCNERLY2_INT_EN)                    /*!<R/W 0  port0 BSSID2 beacon early interrupt, only valid under MBSSID mode */
#define BIT_SHIFT_BCNERLY1_INT_EN                    12
#define BIT_BCNERLY1_INT_EN                          ((u32)0x00000001 << BIT_SHIFT_BCNERLY1_INT_EN)                    /*!<R/W 0  port0 BSSID1 beacon early interrupt , only valid under MBSSID mode */
#define BIT_SHIFT_BCNERLY0_INT_EN                    11
#define BIT_BCNERLY0_INT_EN                          ((u32)0x00000001 << BIT_SHIFT_BCNERLY0_INT_EN)                    /*!<R/W 0  This interrupt is issued at the time set by DRVERLYINT register before TBTT time for port 0 root bssid */
#define BIT_SHIFT_CPU_MGQ_TXDONE_INT_EN              9
#define BIT_CPU_MGQ_TXDONE_INT_EN                    ((u32)0x00000001 << BIT_SHIFT_CPU_MGQ_TXDONE_INT_EN)              /*!<R/W 0  CPU_MQG_TXDONE ineterrupt source when HW TX CPUMGQ packet success, it issue interrupt to host */
#define BIT_SHIFT_PS_TIMER_C_INT_EN                  8
#define BIT_PS_TIMER_C_INT_EN                        ((u32)0x00000001 << BIT_SHIFT_PS_TIMER_C_INT_EN)                  /*!<R/W 0  PS_Timer_C interrupt source When the lower 4 bytes of TSF(that select by reg 0x1510[18:16]) matches the content of this register, the PS_Timer_C_INT interrupt is issued */
#define BIT_SHIFT_PS_TIMER_B_INT_EN                  7
#define BIT_PS_TIMER_B_INT_EN                        ((u32)0x00000001 << BIT_SHIFT_PS_TIMER_B_INT_EN)                  /*!<R/W 0  PS_Timer_B interrupt source When the lower 4 bytes of TSF(that select by reg 0x1510[10:8]) matches the content of this register, the PS_Timer_B_INT interrupt is issued */
#define BIT_SHIFT_PS_TIMER_A_INT_EN                  6
#define BIT_PS_TIMER_A_INT_EN                        ((u32)0x00000001 << BIT_SHIFT_PS_TIMER_A_INT_EN)                  /*!<R/W 0  PS_Timer_A interrupt source When the lower 4 bytes of TSF(that select by reg 0x1510[2:0]) matches the content of this register, the PS_Timer_A_INT interrupt is issued */
#define BIT_SHIFT_GTINT4_EN                          4
#define BIT_GTINT4_EN                                ((u32)0x00000001 << BIT_SHIFT_GTINT4_EN)                          /*!<R/W 0  When GTIMER4 expires, this bit is set to 1 */
#define BIT_SHIFT_GTINT3_EN                          3
#define BIT_GTINT3_EN                                ((u32)0x00000001 << BIT_SHIFT_GTINT3_EN)                          /*!<R/W 0  When GTIMER3 expires, this bit is set to 1 */
#define BIT_SHIFT_TXBCNOK9_INT_EN                    2
#define BIT_TXBCNOK9_INT_EN                          ((u32)0x00000001 << BIT_SHIFT_TXBCNOK9_INT_EN)                    /*!<R/W 0  PORT1 TX beacon OK interrupt */
#define BIT_SHIFT_TXBCNERE9_INT_EN                   1
#define BIT_TXBCNERE9_INT_EN                         ((u32)0x00000001 << BIT_SHIFT_TXBCNERE9_INT_EN)                   /*!<R/W 0  PORT1 TX beacon Error interrupt */

/* REG_HESR 0x00BC */
#define BIT_SHIFT_CTWEND1_INT                        31
#define BIT_CTWEND1_INT                              ((u32)0x00000001 << BIT_SHIFT_CTWEND1_INT)                        /*!<R/W1C 0  Client1 traffic window end interrupt for P2P */
#define BIT_SHIFT_CTWEND0_INT                        30
#define BIT_CTWEND0_INT                              ((u32)0x00000001 << BIT_SHIFT_CTWEND0_INT)                        /*!<R/W1C 0  Client0 traffic window end interrupt for P2P */
#define BIT_SHIFT_DWWIN_END_INT_V1                   29
#define BIT_DWWIN_END_INT_V1                         ((u32)0x00000001 << BIT_SHIFT_DWWIN_END_INT_V1)                   /*!<R/W1C 0  discovery window end interrupt for NAN */
#define BIT_SHIFT_ATIMEND8_INT                       28
#define BIT_ATIMEND8_INT                             ((u32)0x00000001 << BIT_SHIFT_ATIMEND8_INT)                       /*!<R/W1C 0  port1 atimend interrupt */
#define BIT_SHIFT_ATIMEND7_INT                       27
#define BIT_ATIMEND7_INT                             ((u32)0x00000001 << BIT_SHIFT_ATIMEND7_INT)                       /*!<R/W1C 0  port0 BSSID7 atimend interrupt */
#define BIT_SHIFT_ATIMEND6_INT                       26
#define BIT_ATIMEND6_INT                             ((u32)0x00000001 << BIT_SHIFT_ATIMEND6_INT)                       /*!<R/W1C 0  port0 BSSID6 atimend interrupt */
#define BIT_SHIFT_ATIMEND5_INT                       25
#define BIT_ATIMEND5_INT                             ((u32)0x00000001 << BIT_SHIFT_ATIMEND5_INT)                       /*!<R/W1C 0  port0 BSSID5 atimend interrupt */
#define BIT_SHIFT_ATIMEND4_INT                       24
#define BIT_ATIMEND4_INT                             ((u32)0x00000001 << BIT_SHIFT_ATIMEND4_INT)                       /*!<R/W1C 0  port0 BSSID4 atimend interrupt */
#define BIT_SHIFT_ATIMEND3_INT                       23
#define BIT_ATIMEND3_INT                             ((u32)0x00000001 << BIT_SHIFT_ATIMEND3_INT)                       /*!<R/W1C 0  port0 BSSID3 atimend interrupt */
#define BIT_SHIFT_ATIMEND2_INT                       22
#define BIT_ATIMEND2_INT                             ((u32)0x00000001 << BIT_SHIFT_ATIMEND2_INT)                       /*!<R/W1C 0  port0 BSSID2 atimend interrupt */
#define BIT_SHIFT_ATIMEND1_INT                       21
#define BIT_ATIMEND1_INT                             ((u32)0x00000001 << BIT_SHIFT_ATIMEND1_INT)                       /*!<R/W1C 0  port0 BSSID1 atimend interrupt */
#define BIT_SHIFT_ATIMEND0_INT                       20
#define BIT_ATIMEND0_INT                             ((u32)0x00000001 << BIT_SHIFT_ATIMEND0_INT)                       /*!<R/W1C 0  port0 BSSID0 atimend interrupt */
#define BIT_SHIFT_BCNERLY8_INT                       19
#define BIT_BCNERLY8_INT                             ((u32)0x00000001 << BIT_SHIFT_BCNERLY8_INT)                       /*!<R/W1C 0  port1 beacon early interrupt */
#define BIT_SHIFT_BCNERLY7_INT                       18
#define BIT_BCNERLY7_INT                             ((u32)0x00000001 << BIT_SHIFT_BCNERLY7_INT)                       /*!<R/W1C 0  port0 BSSID7 beacon early interrupt , only valid under MBSSID mode */
#define BIT_SHIFT_BCNERLY6_INT                       17
#define BIT_BCNERLY6_INT                             ((u32)0x00000001 << BIT_SHIFT_BCNERLY6_INT)                       /*!<R/W1C 0  port0 BSSID6 beacon early interrupt , only valid under MBSSID mode */
#define BIT_SHIFT_BCNERLY5_INT                       16
#define BIT_BCNERLY5_INT                             ((u32)0x00000001 << BIT_SHIFT_BCNERLY5_INT)                       /*!<R/W1C 0  port0 BSSID5 beacon early interrupt , only valid under MBSSID mode */
#define BIT_SHIFT_BCNERLY4_INT                       15
#define BIT_BCNERLY4_INT                             ((u32)0x00000001 << BIT_SHIFT_BCNERLY4_INT)                       /*!<R/W1C 0  port0 BSSID4 beacon early interrupt, only valid under MBSSID mode */
#define BIT_SHIFT_BCNERLY3_INT                       14
#define BIT_BCNERLY3_INT                             ((u32)0x00000001 << BIT_SHIFT_BCNERLY3_INT)                       /*!<R/W1C 0  port0 BSSID3 beacon early interrupt , only valid under MBSSID mode */
#define BIT_SHIFT_BCNERLY2_INT                       13
#define BIT_BCNERLY2_INT                             ((u32)0x00000001 << BIT_SHIFT_BCNERLY2_INT)                       /*!<R/W1C 0  port0 BSSID2 beacon early interrupt, only valid under MBSSID mode */
#define BIT_SHIFT_BCNERLY1_INT                       12
#define BIT_BCNERLY1_INT                             ((u32)0x00000001 << BIT_SHIFT_BCNERLY1_INT)                       /*!<R/W1C 0  port0 BSSID1 beacon early interrupt , only valid under MBSSID mode */
#define BIT_SHIFT_BCNERLY0_INT                       11
#define BIT_BCNERLY0_INT                             ((u32)0x00000001 << BIT_SHIFT_BCNERLY0_INT)                       /*!<R/W1C 0  This interrupt is issued at the time set by DRVERLYINT register before TBTT time for port 0 root bssid */
#define BIT_SHIFT_CPU_MGQ_TXDONE_INT                 9
#define BIT_CPU_MGQ_TXDONE_INT                       ((u32)0x00000001 << BIT_SHIFT_CPU_MGQ_TXDONE_INT)                 /*!<R/W1C 0  CPU_MQG_TXDONE ineterrupt source when HW TX CPUMGQ packet success, it issue interrupt to host */
#define BIT_SHIFT_PS_TIMER_C_INT                     8
#define BIT_PS_TIMER_C_INT                           ((u32)0x00000001 << BIT_SHIFT_PS_TIMER_C_INT)                     /*!<R/W1C 0  PS_Timer_C interrupt source When the lower 4 bytes of TSF(that select by reg 0x1510[18:16]) matches the content of this register, the PS_Timer_C_INT interrupt is issued */
#define BIT_SHIFT_PS_TIMER_B_INT                     7
#define BIT_PS_TIMER_B_INT                           ((u32)0x00000001 << BIT_SHIFT_PS_TIMER_B_INT)                     /*!<R/W1C 0  PS_Timer_B interrupt source When the lower 4 bytes of TSF(that select by reg 0x1510[10:8]) matches the content of this register, the PS_Timer_B_INT interrupt is issued */
#define BIT_SHIFT_PS_TIMER_A_INT                     6
#define BIT_PS_TIMER_A_INT                           ((u32)0x00000001 << BIT_SHIFT_PS_TIMER_A_INT)                     /*!<R/W1C 0  PS_Timer_A interrupt source When the lower 4 bytes of TSF(that select by reg 0x1510[2:0]) matches the content of this register, the PS_Timer_A_INT interrupt is issued */
#define BIT_SHIFT_GTINT4                             4
#define BIT_GTINT4                                   ((u32)0x00000001 << BIT_SHIFT_GTINT4)                             /*!<R/W1C 0  When GTIMER4 expires, this bit is set to 1 */
#define BIT_SHIFT_GTINT3                             3
#define BIT_GTINT3                                   ((u32)0x00000001 << BIT_SHIFT_GTINT3)                             /*!<R/W1C 0  When GTIMER3 expires, this bit is set to 1 */
#define BIT_SHIFT_TXBCNOK9_INT                       2
#define BIT_TXBCNOK9_INT                             ((u32)0x00000001 << BIT_SHIFT_TXBCNOK9_INT)                       /*!<R/W1C 0  PORT1 TX beacon OK interrupt */
#define BIT_SHIFT_TXBCNERR9_INT                      1
#define BIT_TXBCNERR9_INT                            ((u32)0x00000001 << BIT_SHIFT_TXBCNERR9_INT)                      /*!<R/W1C 0  PORT1 TX beacon Error interrupt */

/* REG_HIMR2 0x00C0 */
#define BIT_SHIFT_KM0_INT_EN                         31
#define BIT_KM0_INT_EN                               ((u32)0x00000001 << BIT_SHIFT_KM0_INT_EN)                         /*!<R/W 0  The gathering og interrupts of KM0 */
#define BIT_SHIFT_RXTMREQ_INT_EN                     16
#define BIT_RXTMREQ_INT_EN                           ((u32)0x00000001 << BIT_SHIFT_RXTMREQ_INT_EN)                     /*!<R/W 0  If BIT_RXTMREQ_INT_EN =1. When HW receive TMREQ packet, it will generate interrupt to firmware. */
#define BIT_SHIFT_RXTM_INT_EN                        15
#define BIT_RXTM_INT_EN                              ((u32)0x00000001 << BIT_SHIFT_RXTM_INT_EN)                        /*!<R/W 0  If BIT_RXTM_INT_EN =1. When HW receive TM and transmit ACK frame successfully. It will generate interrupt to firmware. */
#define BIT_SHIFT_TXTM_INT_EN                        14
#define BIT_TXTM_INT_EN                              ((u32)0x00000001 << BIT_SHIFT_TXTM_INT_EN)                        /*!<R/W 0  If BIT_TXTM_INT_EN =1. When HW transmit TM and receive ACK frame successfully. It will generate interrupt to firmware. */
#define BIT_SHIFT_RX_PAYLOAD_MATCH_INT_EN            13
#define BIT_RX_PAYLOAD_MATCH_INT_EN                  ((u32)0x00000001 << BIT_SHIFT_RX_PAYLOAD_MATCH_INT_EN)            /*!<R/W 0  indicate rx payload content match */
#define BIT_SHIFT_CHINFO_SEG_DONE_INT_EN             12
#define BIT_CHINFO_SEG_DONE_INT_EN                   ((u32)0x00000001 << BIT_SHIFT_CHINFO_SEG_DONE_INT_EN)             /*!<R/W 0  indicate one channel info segment is received ok */
#define BIT_SHIFT_CSI_BUF_FULL_INT_EN                11
#define BIT_CSI_BUF_FULL_INT_EN                      ((u32)0x00000001 << BIT_SHIFT_CSI_BUF_FULL_INT_EN)                /*!<R/W 0  indicate channel info rxcsibuffer is full */
#define BIT_SHIFT_WLAN2ZIGBEE_MAILBOX_INT_EN         10
#define BIT_WLAN2ZIGBEE_MAILBOX_INT_EN               ((u32)0x00000001 << BIT_SHIFT_WLAN2ZIGBEE_MAILBOX_INT_EN)         /*!<R/W 0  From Mailbox controller */
#define BIT_SHIFT_BT_RX_STOP_INT_EN                  9
#define BIT_BT_RX_STOP_INT_EN                        ((u32)0x00000001 << BIT_SHIFT_BT_RX_STOP_INT_EN)                  /*!<R/W 0  From PTA. BIT_BT_TX_START=(pre_gnt_bt_rx==1) &&(cur_gnt_bt_rx==0) */
#define BIT_SHIFT_BT_RX_START_INT_EN                 8
#define BIT_BT_RX_START_INT_EN                       ((u32)0x00000001 << BIT_SHIFT_BT_RX_START_INT_EN)                 /*!<R/W 0  From PTA. BIT_BT_TX_START=(pre_gnt_bt_rx==0) &&(cur_gnt_bt_rx==1) */
#define BIT_SHIFT_BT_TX_STOP_INT_EN                  7
#define BIT_BT_TX_STOP_INT_EN                        ((u32)0x00000001 << BIT_SHIFT_BT_TX_STOP_INT_EN)                  /*!<R/W 0  From PTA. BIT_BT_TX_START=(pre_gnt_bt_tx==1) &&(cur_gnt_bt_tx==0) */
#define BIT_SHIFT_BT_TX_START_INT_EN                 6
#define BIT_BT_TX_START_INT_EN                       ((u32)0x00000001 << BIT_SHIFT_BT_TX_START_INT_EN)                 /*!<R/W 0  From PTA. BIT_BT_TX_START=(pre_gnt_bt_tx==0) &&(cur_gnt_bt_tx==1) */
#define BIT_SHIFT_WLAN_RX_STOP_INT_EN                5
#define BIT_WLAN_RX_STOP_INT_EN                      ((u32)0x00000001 << BIT_SHIFT_WLAN_RX_STOP_INT_EN)                /*!<R/W 0  From wmac. BIT_WLAN_RX_START=(pre_wl_cca==1)&&(cur_wl_cca==0) */
#define BIT_SHIFT_WLAN_RX_START_INT_EN               4
#define BIT_WLAN_RX_START_INT_EN                     ((u32)0x00000001 << BIT_SHIFT_WLAN_RX_START_INT_EN)               /*!<R/W 0  From wmac. BIT_WLAN_RX_START=(pre_wl_cca==0)&&(cur_wl_cca==1) Zigbee */
#define BIT_SHIFT_WLAN_TX_STOP_INT_EN                3
#define BIT_WLAN_TX_STOP_INT_EN                      ((u32)0x00000001 << BIT_SHIFT_WLAN_TX_STOP_INT_EN)                /*!<R/W 0  From wmac. BIT_WLAN_TX_START=(pre_wl_mactxen==1)&&(cur_wl_mactxen=0) */
#define BIT_SHIFT_WLAN_TX_START_INT_EN               2
#define BIT_WLAN_TX_START_INT_EN                     ((u32)0x00000001 << BIT_SHIFT_WLAN_TX_START_INT_EN)               /*!<R/W 0  From wmac. BIT_WLAN_TX_START=(pre_wl_mactxen==0)&&(cur_wl_mactxen=1) Zigbee */
#define BIT_SHIFT_DIS_GNT_ZIGBEE_TX_INT_EN           1
#define BIT_DIS_GNT_ZIGBEE_TX_INT_EN                 ((u32)0x00000001 << BIT_SHIFT_DIS_GNT_ZIGBEE_TX_INT_EN)           /*!<R/W 0  from PTA. BIT_DIS_GNT_ZIGBEE_TX=(pre_gnt_zigbee_tx==1)&& (cur_gnt_zigbee_tx==0) */
#define BIT_SHIFT_GNT_ZIGBEE_TX_INT_EN               0
#define BIT_GNT_ZIGBEE_TX_INT_EN                     ((u32)0x00000001 << BIT_SHIFT_GNT_ZIGBEE_TX_INT_EN)               /*!<R/W 0  from PTA. BIT_GNT_ZIGBEE_TX=(pre_gnt_zigbee_tx==0)&& (cur_gnt_zigbee_tx==1) */

/* REG_HISR2 0x00C4 */
#define BIT_SHIFT_KM0_INT                            31
#define BIT_KM0_INT                                  ((u32)0x00000001 << BIT_SHIFT_KM0_INT)                            /*!<R/W1C 0  The gathering og interrupts of KM0 */
#define BIT_SHIFT_RXTMREQ_INT                        16
#define BIT_RXTMREQ_INT                              ((u32)0x00000001 << BIT_SHIFT_RXTMREQ_INT)                        /*!<R/W1C 0  If BIT_RXTMREQ_INT_EN =1. When HW receive TMREQ packet, it will generate interrupt to firmware. */
#define BIT_SHIFT_RXTM_INT                           15
#define BIT_RXTM_INT                                 ((u32)0x00000001 << BIT_SHIFT_RXTM_INT)                           /*!<R/W1C 0  If BIT_RXTM_INT_EN =1. When HW receive TM and transmit ACK frame successfully. It will generate interrupt to firmware. */
#define BIT_SHIFT_TXTM_INT                           14
#define BIT_TXTM_INT                                 ((u32)0x00000001 << BIT_SHIFT_TXTM_INT)                           /*!<R/W1C 0  If BIT_TXTM_INT_EN =1. When HW transmit TM and receive ACK frame successfully. It will generate interrupt to firmware. */
#define BIT_SHIFT_RX_PAYLOAD_MATCH_INT               13
#define BIT_RX_PAYLOAD_MATCH_INT                     ((u32)0x00000001 << BIT_SHIFT_RX_PAYLOAD_MATCH_INT)               /*!<R/W1C 0  indicate rx payload content match */
#define BIT_SHIFT_CHINFO_SEG_DONE_INT                12
#define BIT_CHINFO_SEG_DONE_INT                      ((u32)0x00000001 << BIT_SHIFT_CHINFO_SEG_DONE_INT)                /*!<R/W1C 0  indicate one channel info segment is received ok */
#define BIT_SHIFT_CSI_BUF_FULL_INT                   11
#define BIT_CSI_BUF_FULL_INT                         ((u32)0x00000001 << BIT_SHIFT_CSI_BUF_FULL_INT)                   /*!<R/W1C 0  indicate channel info rxcsibuffer is full */
#define BIT_SHIFT_WLAN2ZIGBEE_MAILBOX_INT            10
#define BIT_WLAN2ZIGBEE_MAILBOX_INT                  ((u32)0x00000001 << BIT_SHIFT_WLAN2ZIGBEE_MAILBOX_INT)            /*!<R/W1C 0  From Mailbox controller ָʾ��ǰwlan fw ���� mailbox(wlan->zigbee ) д����Ϣ */
#define BIT_SHIFT_BT_RX_STOP_INT                     9
#define BIT_BT_RX_STOP_INT                           ((u32)0x00000001 << BIT_SHIFT_BT_RX_STOP_INT)                     /*!<R/W1C 0  From PTA. BIT_BT_TX_START=(pre_gnt_bt_rx==1) &&(cur_gnt_bt_rx==0) */
#define BIT_SHIFT_BT_RX_START_INT                    8
#define BIT_BT_RX_START_INT                          ((u32)0x00000001 << BIT_SHIFT_BT_RX_START_INT)                    /*!<R/W1C 0  From PTA. BIT_BT_TX_START=(pre_gnt_bt_rx==0) &&(cur_gnt_bt_rx==1) */
#define BIT_SHIFT_BT_TX_STOP_INT                     7
#define BIT_BT_TX_STOP_INT                           ((u32)0x00000001 << BIT_SHIFT_BT_TX_STOP_INT)                     /*!<R/W1C 0  From PTA. BIT_BT_TX_START=(pre_gnt_bt_tx==1) &&(cur_gnt_bt_tx==0) */
#define BIT_SHIFT_BT_TX_START_INT                    6
#define BIT_BT_TX_START_INT                          ((u32)0x00000001 << BIT_SHIFT_BT_TX_START_INT)                    /*!<R/W1C 0  From PTA. BIT_BT_TX_START=(pre_gnt_bt_tx==0) &&(cur_gnt_bt_tx==1) */
#define BIT_SHIFT_WLAN_RX_STOP_INT                   5
#define BIT_WLAN_RX_STOP_INT                         ((u32)0x00000001 << BIT_SHIFT_WLAN_RX_STOP_INT)                   /*!<R/W1C 0  From wmac. BIT_WLAN_RX_START=(pre_wl_cca==1)&&(cur_wl_cca==0) */
#define BIT_SHIFT_WLAN_RX_START_INT                  4
#define BIT_WLAN_RX_START_INT                        ((u32)0x00000001 << BIT_SHIFT_WLAN_RX_START_INT)                  /*!<R/W1C 0  From wmac. BIT_WLAN_RX_START=(pre_wl_cca==0)&&(cur_wl_cca==1) Zigbee �յ����жϺ󣬿���ѡ���Ƿ�Ҫ�жϵ�ǰ���TX or RX */
#define BIT_SHIFT_WLAN_TX_STOP_INT                   3
#define BIT_WLAN_TX_STOP_INT                         ((u32)0x00000001 << BIT_SHIFT_WLAN_TX_STOP_INT)                   /*!<R/W1C 0  From wmac. BIT_WLAN_TX_START=(pre_wl_mactxen==1)&&(cur_wl_mactxen=0) */
#define BIT_SHIFT_WLAN_TX_START_INT                  2
#define BIT_WLAN_TX_START_INT                        ((u32)0x00000001 << BIT_SHIFT_WLAN_TX_START_INT)                  /*!<R/W1C 0  From wmac. BIT_WLAN_TX_START=(pre_wl_mactxen==0)&&(cur_wl_mactxen=1) Zigbee �յ����жϺ󣬿���ѡ���Ƿ�Ҫ�жϵ�ǰ���TX or RX */
#define BIT_SHIFT_DIS_GNT_ZIGBEE_TX_INT              1
#define BIT_DIS_GNT_ZIGBEE_TX_INT                    ((u32)0x00000001 << BIT_SHIFT_DIS_GNT_ZIGBEE_TX_INT)              /*!<R/W1C 0  from PTA. BIT_DIS_GNT_ZIGBEE_TX=(pre_gnt_zigbee_tx==1)&& (cur_gnt_zigbee_tx==0) */
#define BIT_SHIFT_GNT_ZIGBEE_TX_INT                  0
#define BIT_GNT_ZIGBEE_TX_INT                        ((u32)0x00000001 << BIT_SHIFT_GNT_ZIGBEE_TX_INT)                  /*!<R/W1C 0  from PTA. BIT_GNT_ZIGBEE_TX=(pre_gnt_zigbee_tx==0)&& (cur_gnt_zigbee_tx==1) */

/* REG_SDM_IDR_CTRL0 0x00E8 */
#define BIT_SHIFT_SDM_ADDR                           0
#define BIT_MASK_SDM_ADDR                            ((u32)0x0000003F << BIT_SHIFT_SDM_ADDR)                           /*!<R/W 0  SDM register offset */

/* REG_SDM_IDR_CTRL1 0x00EC */
#define BIT_SHIFT_SDM_DATA                           0
#define BIT_MASK_SDM_DATA                            ((u32)0xFFFFFFFF << BIT_SHIFT_SDM_DATA)                           /*!<R/W 0  SDM register data, support byte write */

/* REG_SYS_CONFIG0 0x00F0 */
#define BIT_SHIFT_IS_SCH_CLK_INSLP_V1                8
#define BIT_IS_SCH_CLK_INSLP_V1                      ((u32)0x00000001 << BIT_SHIFT_IS_SCH_CLK_INSLP_V1)                /*!<RO 0  WL TSF clock status: 0: MAC clock 1: 32K clock */
#define BIT_SHIFT_VENDOR_ID_V1                       4
#define BIT_MASK_VENDOR_ID_V1                        ((u32)0x0000000F << BIT_SHIFT_VENDOR_ID_V1)                       /*!<RO 4'b1000  Vendor ID [7:6] : Download FW version ; 00: TSMC , 01: SMIC, 10: UMC [5] ; 0 : Download FW , init BB and RF registers 1 : Do not download FW and do not init BB and RF registers [4] ; 0 : BT do not exist in IC 1 : BT exist in IC */
#define BIT_SHIFT_PLL_CK_RDY                         0
#define BIT_PLL_CK_RDY                               ((u32)0x00000001 << BIT_SHIFT_PLL_CK_RDY)                         /*!<RO 0  indicate AFE PLL clock is ready */

/* REG_CR 0x0100 */

#define BIT_SHIFT_DMACLBK                            28
#define BIT_DMACLBK                                  ((u32)0x00000001 << BIT_SHIFT_DMACLBK)                            /*!<R/W 0  [28:24] LBMODE [4]dual-mac lbk, [3] no buffer, 1: no delay, 0: delay; [2] dmalbk, [1] no_txphy, [0] diglbk. 00000: Normal 01011: Single MAC Direct loopback (no HW encryption/decryption) 00011: Single MAC Delay Loopback (with HW encryption/decryption) */
#define BIT_SHIFT_NO_TBUF                            27
#define BIT_NO_TBUF                                  ((u32)0x00000001 << BIT_SHIFT_NO_TBUF)                            /*!<R/W 0   */
#define BIT_SHIFT_DMALBK                             26
#define BIT_DMALBK                                   ((u32)0x00000001 << BIT_SHIFT_DMALBK)                             /*!<R/W 0   */
#define BIT_SHIFT_NO_TXPHY                           25
#define BIT_NO_TXPHY                                 ((u32)0x00000001 << BIT_SHIFT_NO_TXPHY)                           /*!<R/W 0   */
#define BIT_SHIFT_DIGLBK                             24
#define BIT_DIGLBK                                   ((u32)0x00000001 << BIT_SHIFT_DIGLBK)                             /*!<R/W 0   */

#define BIT_SHIFT_NETYPE1                            18
#define BIT_MASK_NETYPE1                             ((u32)0x00000003 << BIT_SHIFT_NETYPE1)                            /*!<R/W 0  Network Type for Port 1 00: No link 01: Link in ad hoc network 10: Link in infrastructure network 11 : AP mode Default: 00b. */
#define BIT_SHIFT_NETYPE0                            16
#define BIT_MASK_NETYPE0                             ((u32)0x00000003 << BIT_SHIFT_NETYPE0)                            /*!<R/W 0  Network Type for port 0 00: No link 01: Link in ad hoc network 10: Link in infrastructure network 11 : AP mode Default: 00b. */

#define BIT_SHIFT_I2C_MAILBOX_EN                     12
#define BIT_I2C_MAILBOX_EN                           ((u32)0x00000001 << BIT_SHIFT_I2C_MAILBOX_EN)                     /*!<R/W 0  Enable I2C mailbox */

#define BIT_SHIFT_MAC_SEC_EN                         9
#define BIT_MAC_SEC_EN                               ((u32)0x00000001 << BIT_SHIFT_MAC_SEC_EN)                         /*!<R/W 0  Enable MAC security engine When this bit is clear, security engine is reset */
#define BIT_SHIFT_ENSWBCN                            8
#define BIT_ENSWBCN                                  ((u32)0x00000001 << BIT_SHIFT_ENSWBCN)                            /*!<R/W 0  Enable SW TX beacon 0 = disable, beacon is DMAed from host memory by HW at BCNDMAINT 1 = enable, beacon is polled to DMA to TXBUF. In both case, as long as a beacon frame is set in BCN page, MAC will automatically sent beacon frame automatically. */
#define BIT_SHIFT_MACRXEN                            7
#define BIT_MACRXEN                                  ((u32)0x00000001 << BIT_SHIFT_MACRXEN)                            /*!<R/W 0  MAC Receiver Enable. When set to 1, and the receive state machine is idle, the receive machine becomes active. This bit will read back as 1 whenever the receive state machine is active. After initial power-up, software must ensure that the receiver has completely reset before setting this bit. 1: Enable 0: Disable Default: 0b. */
#define BIT_SHIFT_MACTXEN                            6
#define BIT_MACTXEN                                  ((u32)0x00000001 << BIT_SHIFT_MACTXEN)                            /*!<R/W 0  MAC Transmitter Enable. When set to 1, and the transmit state machine is idle, the transmit state machine becomes active. This bit will read back as 1 whenever the transmit state machine is active. After initial power-up, software must ensure that the transmitter has completely reset before setting this bit. 1: Enable 0: Disable Default: 0b. */
#define BIT_SHIFT_SCHEDULE_EN                        5
#define BIT_SCHEDULE_EN                              ((u32)0x00000001 << BIT_SHIFT_SCHEDULE_EN)                        /*!<R/W 0  Schedule Enable. */
#define BIT_SHIFT_PROTOCOL_EN                        4
#define BIT_PROTOCOL_EN                              ((u32)0x00000001 << BIT_SHIFT_PROTOCOL_EN)                        /*!<R/W 0  protocol Block Function Enable.��FW2HW) */
#define BIT_SHIFT_RXDMA_EN                           3
#define BIT_RXDMA_EN                                 ((u32)0x00000001 << BIT_SHIFT_RXDMA_EN)                           /*!<R/W 0  RXDMA Function Enable */
#define BIT_SHIFT_TXDMA_EN                           2
#define BIT_TXDMA_EN                                 ((u32)0x00000001 << BIT_SHIFT_TXDMA_EN)                           /*!<R/W 0  TXDMA Function Enable */
#define BIT_SHIFT_HCI_RXDMA_EN                       1
#define BIT_HCI_RXDMA_EN                             ((u32)0x00000001 << BIT_SHIFT_HCI_RXDMA_EN)                       /*!<R/W 0  HCI to RXDMA Interface Enable */
#define BIT_SHIFT_HCI_TXDMA_EN                       0
#define BIT_HCI_TXDMA_EN                             ((u32)0x00000001 << BIT_SHIFT_HCI_TXDMA_EN)                       /*!<R/W 0  HCI to TXDMA Interface Enable */


/* REG_TSF_CLK_STATE 0x0108 */

#define BIT_SHIFT_CLK_TSF_IS32K                      15
#define BIT_CLK_TSF_IS32K                            ((u32)0x00000001 << BIT_SHIFT_CLK_TSF_IS32K)                      /*!<R 0  Which Clock is Used by TSF Clock 1: 32K Clock 0: MAC Clock */

/* REG_TXDMA_PQ_MAP 0x010C */

#define BIT_SHIFT_TXDMA_CMQ_MAP                      16
#define BIT_MASK_TXDMA_CMQ_MAP                       ((u32)0x00000003 << BIT_SHIFT_TXDMA_CMQ_MAP)                      /*!<R/W 0  00: Extra priority queue 01: Low priority queue 10: Normal priority queue 11: High priority queue */
#define BIT_SHIFT_TXDMA_HIQ_MAP                      14
#define BIT_MASK_TXDMA_HIQ_MAP                       ((u32)0x00000003 << BIT_SHIFT_TXDMA_HIQ_MAP)                      /*!<R/W 0  00: Extra priority queue 01: Low priority queue 10: Normal priority queue 11: High priority queue */
#define BIT_SHIFT_TXDMA_MGQ_MAP                      12
#define BIT_MASK_TXDMA_MGQ_MAP                       ((u32)0x00000003 << BIT_SHIFT_TXDMA_MGQ_MAP)                      /*!<R/W 0  00: Extra priority queue 01: Low priority queue 10: Normal priority queue 11: High priority queue */
#define BIT_SHIFT_TXDMA_BKQ_MAP                      10
#define BIT_MASK_TXDMA_BKQ_MAP                       ((u32)0x00000003 << BIT_SHIFT_TXDMA_BKQ_MAP)                      /*!<R/W 0  00: Extra priority queue 01: Low priority queue 10: Normal priority queue 11: High priority queue */
#define BIT_SHIFT_TXDMA_BEQ_MAP                      8
#define BIT_MASK_TXDMA_BEQ_MAP                       ((u32)0x00000003 << BIT_SHIFT_TXDMA_BEQ_MAP)                      /*!<R/W 0  00: Extra priority queue 01: Low priority queue 10: Normal priority queue 11: High priority queue */
#define BIT_SHIFT_TXDMA_VIQ_MAP                      6
#define BIT_MASK_TXDMA_VIQ_MAP                       ((u32)0x00000003 << BIT_SHIFT_TXDMA_VIQ_MAP)                      /*!<R/W 0  00: Extra priority queue 01: Low priority queue 10: Normal priority queue 11: High priority queue */
#define BIT_SHIFT_TXDMA_VOQ_MAP                      4
#define BIT_MASK_TXDMA_VOQ_MAP                       ((u32)0x00000003 << BIT_SHIFT_TXDMA_VOQ_MAP)                      /*!<R/W 0  00: Extra priority queue 01: Low priority queue 10: Normal priority queue 11: High priority queue */

#define BIT_SHIFT_RXDMA_AGG_EN                       2
#define BIT_RXDMA_AGG_EN                             ((u32)0x00000001 << BIT_SHIFT_RXDMA_AGG_EN)                       /*!<R/W 0  When this bit is set, then RXDMA will inform host to receive RX packets, when packet page number in RXFF exceeds the threshold set in RXDMA_AGG_PG_TH register. When this bit is set, then page size of receive packet buffer shall be set larger than 64 bytes/page */
#define BIT_SHIFT_ENSHFT                             1
#define BIT_ENSHFT                                   ((u32)0x00000001 << BIT_SHIFT_ENSHFT)                             /*!<R/W 0  When this bit is set, RX shift to fit alignment is enabled. */
#define BIT_SHIFT_RXDMA_BW_EN                        0
#define BIT_RXDMA_BW_EN                              ((u32)0x00000001 << BIT_SHIFT_RXDMA_BW_EN)                        /*!<R/W 0  Enable RXDMA Arbitrator priority for Host interface. */

/* REG_TRXFF_BNDY 0x0114 */
#define BIT_SHIFT_RXPKT0ENDADDR                      16
#define BIT_MASK_RXPKT0ENDADDR                       ((u32)0x0000FFFF << BIT_SHIFT_RXPKT0ENDADDR)                      /*!<R/W 0x3F7F  This register sets the upper boundary of RXFF0. The unit is 1 byte. The available memory space in RXPKTBUF for RXFF0 is configurable. The value is set to the physical LX bus address. */

#define BIT_SHIFT_RXFFOVFL_RSV                       8
#define BIT_MASK_RXFFOVFL_RSV                        ((u32)0x0000000F << BIT_SHIFT_RXFFOVFL_RSV)                       /*!<R/W 0xF  Use this register to set reserved entries number of rxpktbuffer for overflow judgment. The rxpktbuffer overflow will be pre-asserted if the left entries count meets the value set here. */

/* REG_PTA_I2C_MBOX 0x0118 */

#define BIT_SHIFT_I2C_M_STATUS                       8
#define BIT_MASK_I2C_M_STATUS                        ((u32)0x0000000F << BIT_SHIFT_I2C_M_STATUS)                       /*!<R 0  Read these can get the I2C_M_STATUS of PTA_I2C's OUTPUT. */

#define BIT_SHIFT_I2C_M_BUS_GNT_FW                   4
#define BIT_MASK_I2C_M_BUS_GNT_FW                    ((u32)0x00000007 << BIT_SHIFT_I2C_M_BUS_GNT_FW)                   /*!<R/W 0  Use this bit to control PTA_I2C's BUS_GNT. 100 for gnt_txdata, 010 for gnt_txack, 001 for gnt_rxstatus. */
#define BIT_SHIFT_I2C_GNT_FW                         3
#define BIT_I2C_GNT_FW                               ((u32)0x00000001 << BIT_SHIFT_I2C_GNT_FW)                         /*!<R/W 0  Use this bit to control PTA_I2C_GNT_FW input. 1 for FW I2C bus arbiter, 0 for HW as I2C bus arbiter. */
#define BIT_SHIFT_I2C_M_SPEED                        1
#define BIT_MASK_I2C_M_SPEED                         ((u32)0x00000003 << BIT_SHIFT_I2C_M_SPEED)                        /*!<R/W 0  Use these bit to control PTA_I2C I2C interface data rate. SCL = clk / 2^(3 + I2C_DATA_RATE) */
#define BIT_SHIFT_I2C_M_UNLOCK                       0
#define BIT_I2C_M_UNLOCK                             ((u32)0x00000001 << BIT_SHIFT_I2C_M_UNLOCK)                       /*!<R/W 0  If this bit is set, PTA_I2C use 118H and 119H to control PTA_I2C */

/* REG_RXFF_PTR 0x011C */
#define BIT_SHIFT_RXFF0_RDPTR                        16
#define BIT_MASK_RXFF0_RDPTR                         ((u32)0x0000FFFF << BIT_SHIFT_RXFF0_RDPTR)                        /*!<R 0  The read pointer address of RXFF0. The value is set to the physical LX bus address. */
#define BIT_SHIFT_RXFF0_WTPTR                        0
#define BIT_MASK_RXFF0_WTPTR                         ((u32)0x0000FFFF << BIT_SHIFT_RXFF0_WTPTR)                        /*!<R 0  The write pointer address of RXFF0. The value is set to the physical LX bus address. */

/* REG_FE1IMR 0x0120 */
#define BIT_SHIFT_FS_NOT_BEACON_INT_EN               31
#define BIT_FS_NOT_BEACON_INT_EN                     ((u32)0x00000001 << BIT_SHIFT_FS_NOT_BEACON_INT_EN)               /*!<R/W 0  not beacon packet interrupt */
#define BIT_SHIFT_FS_BB_STOP_RX_INT_EN               29
#define BIT_FS_BB_STOP_RX_INT_EN                     ((u32)0x00000001 << BIT_SHIFT_FS_BB_STOP_RX_INT_EN)            /*!<R/W 0  BB STOP RX interrupt */
#define BIT_SHIFT_FS_RXPLCP_CHKOK_INT_EN             27
#define BIT_FS_RXPLCP_CHKOK_INT_EN                   ((u32)0x00000001 << BIT_SHIFT_FS_RXPLCP_CHKOK_INT_EN)          /*!<R/W 0  RXPCLP check ok interrupt */
#define BIT_SHIFT_FS_RX_BCN_P1_INT_EN                22
#define BIT_FS_RX_BCN_P1_INT_EN                      ((u32)0x00000001 << BIT_SHIFT_FS_RX_BCN_P1_INT_EN)             /*!<R/W 0  When this bit is enable, the interrupt is issued when RX beacon frame occurs in port1. */
#define BIT_SHIFT_FS_RX_BCN_P0_INT_EN                21
#define BIT_FS_RX_BCN_P0_INT_EN                      ((u32)0x00000001 << BIT_SHIFT_FS_RX_BCN_P0_INT_EN)                /*!<R/W 0  When this bit is enable, the interrupt is issued when RX beacon frame occurs in port0. */
#define BIT_SHIFT_FS_RX_UMD0_INT_EN                  20
#define BIT_FS_RX_UMD0_INT_EN                        ((u32)0x00000001 << BIT_SHIFT_FS_RX_UMD0_INT_EN)                  /*!<R/W 0  The interrupt is issued while receiving unicast data frame with More Data=0 */
#define BIT_SHIFT_FS_RX_UMD1_INT_EN                  19
#define BIT_FS_RX_UMD1_INT_EN                        ((u32)0x00000001 << BIT_SHIFT_FS_RX_UMD1_INT_EN)                  /*!<R/W 0  The interrupt is issued while receiving unicast data frame with More Data=1 */
#define BIT_SHIFT_FS_RX_BMD0_INT_EN                  18
#define BIT_FS_RX_BMD0_INT_EN                        ((u32)0x00000001 << BIT_SHIFT_FS_RX_BMD0_INT_EN)                  /*!<R/W 0  The interrupt is issued while receiving broadcast data frame with More Data=0 */
#define BIT_SHIFT_FS_RX_BMD1_INT_EN                  17
#define BIT_FS_RX_BMD1_INT_EN                        ((u32)0x00000001 << BIT_SHIFT_FS_RX_BMD1_INT_EN)                  /*!<R/W 0  The interrupt is issued while receiving broadcast data frame with More Data=1 */
#define BIT_SHIFT_FS_RXDONE0_INT_EN                  16
#define BIT_FS_RXDONE0_INT_EN                        ((u32)0x00000001 << BIT_SHIFT_FS_RXDONE0_INT_EN)                  /*!<R/W 0  Rx Packet 0 done interrupt (for WOL release packet) */
#define BIT_SHIFT_FS_WWLAN_INT_EN                    15
#define BIT_FS_WWLAN_INT_EN                          ((u32)0x00000001 << BIT_SHIFT_FS_WWLAN_INT_EN)                    /*!<R/W 0  HW detect rxpkt Wol WLAN event interrupt */
#define BIT_SHIFT_FS_SOUND_DONE_INT_EN               14
#define BIT_FS_SOUND_DONE_INT_EN                     ((u32)0x00000001 << BIT_SHIFT_FS_SOUND_DONE_INT_EN)               /*!<R/W 0  Be a beamformer, this interrupt is issued at the time after sounding finish */
#define BIT_SHIFT_FS_LP_STBY_INT_EN                  13
#define BIT_FS_LP_STBY_INT_EN                        ((u32)0x00000001 << BIT_SHIFT_FS_LP_STBY_INT_EN)                  /*!<R/W 0  Lower Power Standby Interrupt */
#define BIT_SHIFT_FS_BF1_PRETO_INT_EN                11
#define BIT_FS_BF1_PRETO_INT_EN                      ((u32)0x00000001 << BIT_SHIFT_FS_BF1_PRETO_INT_EN)                /*!<R/W 0  BF1 pretimeout interrupt */
#define BIT_SHIFT_FS_BF0_PRETO_INT_EN                10
#define BIT_FS_BF0_PRETO_INT_EN                      ((u32)0x00000001 << BIT_SHIFT_FS_BF0_PRETO_INT_EN)                /*!<R/W 0  BF0 pretimeout interrupt */
#define BIT_SHIFT_FS_PTCL_RELEASE_MACID_INT_EN       9
#define BIT_FS_PTCL_RELEASE_MACID_INT_EN             ((u32)0x00000001 << BIT_SHIFT_FS_PTCL_RELEASE_MACID_INT_EN)       /*!<R/W 0  PTCL release macid interrupt */
#define BIT_SHIFT_FS_PRETXERR_HANDLE_FSISR_EN        8
#define BIT_FS_PRETXERR_HANDLE_FSISR_EN              ((u32)0x00000001 << BIT_SHIFT_FS_PRETXERR_HANDLE_FSISR)           /*!<R/W 0  PRETXERR_HANDLE FW Flag Interrupt register. */

#define BIT_SHIFT_FS_WLACTOFF_INT_EN                 5
#define BIT_FS_WLACTOFF_INT_EN                       ((u32)0x00000001 << BIT_SHIFT_FS_WLACTOFF_INT_EN)                 /*!<R/W 0  WL_ACT_MASK_ON de-assertion for bt coexistence function interrupt */
#define BIT_SHIFT_FS_WLACTON_INT_EN                  4
#define BIT_FS_WLACTON_INT_EN                        ((u32)0x00000001 << BIT_SHIFT_FS_WLACTON_INT_EN)                  /*!<R/W 0  WL_ACT_MASK_ON assertion for bt coexistence function interrupt */
#define BIT_SHIFT_FS_BTCMD_INT_EN                    3
#define BIT_FS_BTCMD_INT_EN                          ((u32)0x00000001 << BIT_SHIFT_FS_BTCMD_INT_EN)                    /*!<R/W 0  the interrupt is issued when btcmd occurs. */
#define BIT_SHIFT_FS_REG_MAILBOX_TO_I2C_INT_EN       2
#define BIT_FS_REG_MAILBOX_TO_I2C_INT_EN             ((u32)0x00000001 << BIT_SHIFT_FS_REG_MAILBOX_TO_I2C_INT_EN)       /*!<R/W 0  Mailbox_TO_I2C_INT (BT bridge) */
#define BIT_SHIFT_FS_TRPC_TO_INT_EN                  1
#define BIT_FS_TRPC_TO_INT_EN                        ((u32)0x00000001 << BIT_SHIFT_FS_TRPC_TO_INT_EN)                  /*!<R/W 0  TRPC time out Interrupt */
#define BIT_SHIFT_FS_RPC_O_T_INT_EN                  0
#define BIT_FS_RPC_O_T_INT_EN                        ((u32)0x00000001 << BIT_SHIFT_FS_RPC_O_T_INT_EN)                  /*!<R/W 0  RPC over threshold Interrupt */

/* REG_FE1ISR 0x0124 */
#define BIT_FS_SHIFT_NOT_BEACON_INT                  31
#define BIT_FS_NOT_BEACON_INT                        ((u32)0x00000001 << BIT_FS_SHIFT_NOT_BEACON_INT)                     /*!<R/W1C 0  not beacon packet interrupt */
#define BIT_SHIFT_FS_BB_STOP_RX_INT                  29
#define BIT_FS_BB_STOP_RX_INT                        ((u32)0x00000001 << BIT_SHIFT_FS_BB_STOP_RX_INT)                  /*!<R/W1C 0  BB STOP RX interrupt */
#define BIT_SHIFT_FS_RXPLCP_CHKOK_INT                27
#define BIT_FS_RXPLCP_CHKOK_INT                      ((u32)0x00000001 << BIT_SHIFT_FS_RXPLCP_CHKOK_INT)                /*!<R/W1C 0  RXPCLP check ok interrupt */
#define BIT_SHIFT_FS_RX_BCN_P1_INT                   22
#define BIT_FS_RX_BCN_P1_INT                         ((u32)0x00000001 << BIT_SHIFT_FS_RX_BCN_P1_INT)                   /*!<R/W1C 0  When this bit is enable, the interrupt is issued when RX beacon frame occurs in port1. */
#define BIT_SHIFT_FS_RX_BCN_P0_INT                   21
#define BIT_FS_RX_BCN_P0_INT                         ((u32)0x00000001 << BIT_SHIFT_FS_RX_BCN_P0_INT)                   /*!<R/W1C 0  When this bit is enable, the interrupt is issued when RX beacon frame occurs in port0. */
#define BIT_SHIFT_FS_RX_UMD0_INT                     20
#define BIT_FS_RX_UMD0_INT                           ((u32)0x00000001 << BIT_SHIFT_FS_RX_UMD0_INT)                     /*!<R/W1C 0  The interrupt is issued while receiving unicast data frame with More Data=0 */
#define BIT_SHIFT_FS_RX_UMD1_INT                     19
#define BIT_FS_RX_UMD1_INT                           ((u32)0x00000001 << BIT_SHIFT_FS_RX_UMD1_INT)                     /*!<R/W1C 0  The interrupt is issued while receiving unicast data frame with More Data=1 */
#define BIT_SHIFT_FS_RX_BMD0_INT                     18
#define BIT_FS_RX_BMD0_INT                           ((u32)0x00000001 << BIT_SHIFT_FS_RX_BMD0_INT)                     /*!<R/W1C 0  The interrupt is issued while receiving broadcast data frame with More Data=0 */
#define BIT_SHIFT_FS_RX_BMD1_INT                     17
#define BIT_FS_RX_BMD1_INT                           ((u32)0x00000001 << BIT_SHIFT_FS_RX_BMD1_INT)                     /*!<R/W1C 0  The interrupt is issued while receiving broadcast data frame with More Data=1 */
#define BIT_SHIFT_FS_RXDONE0_INT                     16
#define BIT_FS_RXDONE0_INT                           ((u32)0x00000001 << BIT_SHIFT_FS_RXDONE0_INT)                     /*!<R/W1C 0  Rx Packet 0 done interrupt (for WOL release packet) */
#define BIT_SHIFT_FS_WWLAN_INT                       15
#define BIT_FS_WWLAN_INT                             ((u32)0x00000001 << BIT_SHIFT_FS_WWLAN_INT)                       /*!<R/W1C 0  HW detect rxpkt Wol WLAN event interrupt */
#define BIT_SHIFT_FS_SOUND_DONE_INT                  14
#define BIT_FS_SOUND_DONE_INT                        ((u32)0x00000001 << BIT_SHIFT_FS_SOUND_DONE_INT)                  /*!<R/W1C 0  Be a beamformer, this interrupt is issued at the time after sounding finish */
#define BIT_SHIFT_FS_LP_STBY_INT                     13
#define BIT_FS_LP_STBY_INT                           ((u32)0x00000001 << BIT_SHIFT_FS_LP_STBY_INT)                     /*!<R/W1C 0  Lower Power Standby Interrupt */
#define BIT_SHIFT_FS_BF1_PRETO_INT                   11
#define BIT_FS_BF1_PRETO_INT                         ((u32)0x00000001 << BIT_SHIFT_FS_BF1_PRETO_INT)                   /*!<R/W1C 0  BF1 pretimeout interrupt */
#define BIT_SHIFT_FS_BF0_PRETO_INT                   10
#define BIT_FS_BF0_PRETO_INT                         ((u32)0x00000001 << BIT_SHIFT_FS_BF0_PRETO_INT)                   /*!<R/W1C 0  BF0 pretimeout interrupt */
#define BIT_SHIFT_FS_PTCL_RELEASE_MACID_INT          9
#define BIT_FS_PTCL_RELEASE_MACID_INT                ((u32)0x00000001 << BIT_SHIFT_FS_PTCL_RELEASE_MACID_INT)          /*!<R/W1C 0  PTCL release macid interrupt */
#define BIT_SHIFT_FS_PRETXERR_HANDLE_FSISR           8
#define BIT_FS_PRETXERR_HANDLE_FSISR                 ((u32)0x00000001 << BIT_SHIFT_FS_PRETXERR_HANDLE_FSISR)           /*!<R/W1C 0  PRETXERR_HANDLE FW Flag Interrupt register. */

#define BIT_SHIFT_FS_WLACTOFF_INT                    5
#define BIT_FS_WLACTOFF_INT                          ((u32)0x00000001 << BIT_SHIFT_FS_WLACTOFF_INT)                    /*!<R/W1C 0  WL_ACT_MASK_ON de-assertion for bt coexistence function interrupt */
#define BIT_SHIFT_FS_WLACTON_INT                     4
#define BIT_FS_WLACTON_INT                           ((u32)0x00000001 << BIT_SHIFT_FS_WLACTON_INT)                     /*!<R/W1C 0  WL_ACT_MASK_ON assertion for bt coexistence function interrupt */
#define BIT_SHIFT_FS_BTCMD_INT                       3
#define BIT_FS_BTCMD_INT                             ((u32)0x00000001 << BIT_SHIFT_FS_BTCMD_INT)                       /*!<R/W1C 0  the interrupt is issued when btcmd occurs. */
#define BIT_SHIFT_FS_REG_MAILBOX_TO_I2C_INT          2
#define BIT_FS_REG_MAILBOX_TO_I2C_INT                ((u32)0x00000001 << BIT_SHIFT_FS_REG_MAILBOX_TO_I2C_INT)          /*!<R/WIC 0  Mailbox_TO_I2C_INT (BT bridge) */
#define BIT_SHIFT_FS_TRPC_TO_INT                     1
#define BIT_FS_TRPC_TO_INT                           ((u32)0x00000001 << BIT_SHIFT_FS_TRPC_TO_INT)                     /*!<R/WIC 0  TRPC time out Interrupt */
#define BIT_SHIFT_FS_RPC_O_T_INT                     0
#define BIT_FS_RPC_O_T_INT                           ((u32)0x00000001 << BIT_SHIFT_FS_RPC_O_T_INT)                     /*!<R/WIC 0  RPC over threshold Interrupt */

/* REG_CPWM 0x012C */
#define BIT_SHIFT_CPWM_TOGGLING                      31
#define BIT_CPWM_TOGGLING                            ((u32)0x00000001 << BIT_SHIFT_CPWM_TOGGLING)                      /*!<R/W 0  Toggling bit : one bit sequence number bit. When this bit is toggled, interrupt is send to HISR.CPWMINT. */
#define BIT_SHIFT_CPWM_MOD                           24
#define BIT_MASK_CPWM_MOD                            ((u32)0x0000007F << BIT_SHIFT_CPWM_MOD)                           /*!<R/W 0  The current power mode index. */

/* REG_FWIMR 0x0130 */
#define BIT_SHIFT_FS_TXBCNOK_MB7_INT_EN              31
#define BIT_FS_TXBCNOK_MB7_INT_EN                    ((u32)0x00000001 << BIT_SHIFT_FS_TXBCNOK_MB7_INT_EN)              /*!<R/W 0  MBSSID7 TX beacon OK interrupt */
#define BIT_SHIFT_FS_TXBCNOK_MB6_INT_EN              30
#define BIT_FS_TXBCNOK_MB6_INT_EN                    ((u32)0x00000001 << BIT_SHIFT_FS_TXBCNOK_MB6_INT_EN)              /*!<R/W 0  MBSSID6 TX beacon OK interrupt */
#define BIT_SHIFT_FS_TXBCNOK_MB5_INT_EN              29
#define BIT_FS_TXBCNOK_MB5_INT_EN                    ((u32)0x00000001 << BIT_SHIFT_FS_TXBCNOK_MB5_INT_EN)              /*!<R/W 0  MBSSID5 TX beacon OK interrupt */
#define BIT_SHIFT_FS_TXBCNOK_MB4_INT_EN              28
#define BIT_FS_TXBCNOK_MB4_INT_EN                    ((u32)0x00000001 << BIT_SHIFT_FS_TXBCNOK_MB4_INT_EN)              /*!<R/W 0  MBSSID4 TX beacon OK interrupt */
#define BIT_SHIFT_FS_TXBCNOK_MB3_INT_EN              27
#define BIT_FS_TXBCNOK_MB3_INT_EN                    ((u32)0x00000001 << BIT_SHIFT_FS_TXBCNOK_MB3_INT_EN)              /*!<R/W 0  MBSSID3 TX beacon OK interrupt */
#define BIT_SHIFT_FS_TXBCNOK_MB2_INT_EN              26
#define BIT_FS_TXBCNOK_MB2_INT_EN                    ((u32)0x00000001 << BIT_SHIFT_FS_TXBCNOK_MB2_INT_EN)              /*!<R/W 0  MBSSID2 TX beacon OK interrupt */
#define BIT_SHIFT_FS_TXBCNOK_MB1_INT_EN              25
#define BIT_FS_TXBCNOK_MB1_INT_EN                    ((u32)0x00000001 << BIT_SHIFT_FS_TXBCNOK_MB1_INT_EN)              /*!<R/W 0  MBSSID1 TX beacon OK interrupt */
#define BIT_SHIFT_FS_TXBCNOK_MB0_INT_EN              24
#define BIT_FS_TXBCNOK_MB0_INT_EN                    ((u32)0x00000001 << BIT_SHIFT_FS_TXBCNOK_MB0_INT_EN)              /*!<R/W 0  MBSSID0 TX beacon OK interrupt */
#define BIT_SHIFT_FS_TXBCNERR_MB7_INT_EN             23
#define BIT_FS_TXBCNERR_MB7_INT_EN                   ((u32)0x00000001 << BIT_SHIFT_FS_TXBCNERR_MB7_INT_EN)             /*!<R/W 0  MBSSID7 TX beacon Error interrupt */
#define BIT_SHIFT_FS_TXBCNERR_MB6_INT_EN             22
#define BIT_FS_TXBCNERR_MB6_INT_EN                   ((u32)0x00000001 << BIT_SHIFT_FS_TXBCNERR_MB6_INT_EN)             /*!<R/W 0  MBSSID6 TX beacon Error interrupt */
#define BIT_SHIFT_FS_TXBCNERR_MB5_INT_EN             21
#define BIT_FS_TXBCNERR_MB5_INT_EN                   ((u32)0x00000001 << BIT_SHIFT_FS_TXBCNERR_MB5_INT_EN)             /*!<R/W 0  MBSSID5 TX beacon Error interrupt */
#define BIT_SHIFT_FS_TXBCNERR_MB4_INT_EN             20
#define BIT_FS_TXBCNERR_MB4_INT_EN                   ((u32)0x00000001 << BIT_SHIFT_FS_TXBCNERR_MB4_INT_EN)             /*!<R/W 0  MBSSID4 TX beacon Error interrupt */
#define BIT_SHIFT_FS_TXBCNERR_MB3_INT_EN             19
#define BIT_FS_TXBCNERR_MB3_INT_EN                   ((u32)0x00000001 << BIT_SHIFT_FS_TXBCNERR_MB3_INT_EN)             /*!<R/W 0  MBSSID3 TX beacon Error interrupt */
#define BIT_SHIFT_FS_TXBCNERR_MB2_INT_EN             18
#define BIT_FS_TXBCNERR_MB2_INT_EN                   ((u32)0x00000001 << BIT_SHIFT_FS_TXBCNERR_MB2_INT_EN)             /*!<R/W 0  MBSSID2 TX beacon Error interrupt */
#define BIT_SHIFT_FS_TXBCNERR_MB1_INT_EN             17
#define BIT_FS_TXBCNERR_MB1_INT_EN                   ((u32)0x00000001 << BIT_SHIFT_FS_TXBCNERR_MB1_INT_EN)             /*!<R/W 0  MBSSID1 TX beacon Error interrupt */
#define BIT_SHIFT_FS_TXBCNERR_MB0_INT_EN             16
#define BIT_FS_TXBCNERR_MB0_INT_EN                   ((u32)0x00000001 << BIT_SHIFT_FS_TXBCNERR_MB0_INT_EN)             /*!<R/W 0  MBSSID0 TX beacon Error interrupt */
#define BIT_SHIFT_FS_CPUMGN_POLLED_PKT_DONE_INT_EN   15
#define BIT_FS_CPUMGN_POLLED_PKT_DONE_INT_EN         ((u32)0x00000001 << BIT_SHIFT_FS_CPUMGN_POLLED_PKT_DONE_INT_EN)   /*!<R/W 0  CPU management queue polled packet released done interrupt enable (check cpu management queue current flow) */
#define BIT_SHIFT_FS_MGNTQ_FF_RELEASE_INT_EN         13
#define BIT_FS_MGNTQ_FF_RELEASE_INT_EN               ((u32)0x00000001 << BIT_SHIFT_FS_MGNTQ_FF_RELEASE_INT_EN)         /*!<R/W 0  MgntQ ReadPtr FIFO release interrupt (for 8822B) */
#define BIT_SHIFT_FS_CPUMGQ_ERR_INT_EN               11
#define BIT_FS_CPUMGQ_ERR_INT_EN                     ((u32)0x00000001 << BIT_SHIFT_FS_CPUMGQ_ERR_INT_EN)               /*!<R/W 0  CPU management queue polled packet not TX OK while new packet comes in, enable to issue interrupt or not */
#define BIT_SHIFT_FS_HIOE_INT_EN                     10
#define BIT_FS_HIOE_INT_EN                           ((u32)0x00000001 << BIT_SHIFT_FS_HIOE_INT_EN)                     /*!<R/W 0  hioe interrupt */
#define BIT_SHIFT_FS_DDMA0_LP_INT_EN                 9
#define BIT_FS_DDMA0_LP_INT_EN                       ((u32)0x00000001 << BIT_SHIFT_FS_DDMA0_LP_INT_EN)                 /*!<R/W 0  Low priority ddma0 down interrupt . */
#define BIT_SHIFT_FS_DDMA0_HP_INT_EN                 8
#define BIT_FS_DDMA0_HP_INT_EN                       ((u32)0x00000001 << BIT_SHIFT_FS_DDMA0_HP_INT_EN)                 /*!<R/W 0  High priority ddma0 down interrupt */
#define BIT_SHIFT_FS_TXRPT_INT_EN                    7
#define BIT_FS_TXRPT_INT_EN                          ((u32)0x00000001 << BIT_SHIFT_FS_TXRPT_INT_EN)                    /*!<R/W 0  TX report interrupt */
#define BIT_SHIFT_FS_C2H_W_READY_INT_EN              6
#define BIT_FS_C2H_W_READY_INT_EN                    ((u32)0x00000001 << BIT_SHIFT_FS_C2H_W_READY_INT_EN)              /*!<R/W 0  C2H register ready for write interrupt */
#define BIT_SHIFT_FS_HRCV_INT_EN                     5
#define BIT_FS_HRCV_INT_EN                           ((u32)0x00000001 << BIT_SHIFT_FS_HRCV_INT_EN)                     /*!<R/W 0  Host to CPU Message Interrupt, generated on writing to 0x1CF */
#define BIT_SHIFT_FS_H2CCMD_INT_EN                   4
#define BIT_FS_H2CCMD_INT_EN                         ((u32)0x00000001 << BIT_SHIFT_FS_H2CCMD_INT_EN)                   /*!<R/W 0  Host To CPU Message Interrupt */
#define BIT_SHIFT_FS_ERRORHDL_INT_EN                 2
#define BIT_FS_ERRORHDL_INT_EN                       ((u32)0x00000001 << BIT_SHIFT_FS_ERRORHDL_INT_EN)                 /*!<R/W 0  FWHW/ TXDMA/ RXDMA/ WMAC error status interrupt(0x210[31:0], 0x288[31:0], 0x4E2[15:0], 0x6B8[31:0]). WMAC error state will be recovered by HW, the others won't. */
#define BIT_SHIFT_FS_TXCCX_INT_EN                    1
#define BIT_FS_TXCCX_INT_EN                          ((u32)0x00000001 << BIT_SHIFT_FS_TXCCX_INT_EN)                    /*!<R/W 0  CCX PKT TX Report Interrupt */
#define BIT_SHIFT_FS_PTCL_HANDLE_OK_INT_EN           0
#define BIT_FS_PTCL_HANDLE_OK_INT_EN                 ((u32)0x00000001 << BIT_SHIFT_FS_PTCL_HANDLE_OK_INT_EN)           /*!<R/W 0  TX Finish (Ack/BA process Finish) Interrupt. */

/* REG_FWISR 0x0134 */
#define BIT_SHIFT_FS_TXBCNOK_MB7_INT                 31
#define BIT_FS_TXBCNOK_MB7_INT                       ((u32)0x00000001 << BIT_SHIFT_FS_TXBCNOK_MB7_INT)                 /*!<R/W1C 0  MBSSID7 TX beacon OK interrupt */
#define BIT_SHIFT_FS_TXBCNOK_MB6_INT                 30
#define BIT_FS_TXBCNOK_MB6_INT                       ((u32)0x00000001 << BIT_SHIFT_FS_TXBCNOK_MB6_INT)                 /*!<R/W1C 0  MBSSID6 TX beacon OK interrupt */
#define BIT_SHIFT_FS_TXBCNOK_MB5_INT                 29
#define BIT_FS_TXBCNOK_MB5_INT                       ((u32)0x00000001 << BIT_SHIFT_FS_TXBCNOK_MB5_INT)                 /*!<R/W1C 0  MBSSID5 TX beacon OK interrupt */
#define BIT_SHIFT_FS_TXBCNOK_MB4_INT                 28
#define BIT_FS_TXBCNOK_MB4_INT                       ((u32)0x00000001 << BIT_SHIFT_FS_TXBCNOK_MB4_INT)                 /*!<R/W1C 0  MBSSID4 TX beacon OK interrupt */
#define BIT_SHIFT_FS_TXBCNOK_MB3_INT                 27
#define BIT_FS_TXBCNOK_MB3_INT                       ((u32)0x00000001 << BIT_SHIFT_FS_TXBCNOK_MB3_INT)                 /*!<R/W1C 0  MBSSID3 TX beacon OK interrupt */
#define BIT_SHIFT_FS_TXBCNOK_MB2_INT                 26
#define BIT_FS_TXBCNOK_MB2_INT                       ((u32)0x00000001 << BIT_SHIFT_FS_TXBCNOK_MB2_INT)                 /*!<R/W1C 0  MBSSID2 TX beacon OK interrupt */
#define BIT_SHIFT_FS_TXBCNOK_MB1_INT                 25
#define BIT_FS_TXBCNOK_MB1_INT                       ((u32)0x00000001 << BIT_SHIFT_FS_TXBCNOK_MB1_INT)                 /*!<R/W1C 0  MBSSID1 TX beacon OK interrupt */
#define BIT_SHIFT_FS_TXBCNOK_MB0_INT                 24
#define BIT_FS_TXBCNOK_MB0_INT                       ((u32)0x00000001 << BIT_SHIFT_FS_TXBCNOK_MB0_INT)                 /*!<R/W1C 0  MBSSID0 TX beacon OK interrupt */
#define BIT_SHIFT_FS_TXBCNERR_MB7_INT                23
#define BIT_FS_TXBCNERR_MB7_INT                      ((u32)0x00000001 << BIT_SHIFT_FS_TXBCNERR_MB7_INT)                /*!<R/W1C 0  MBSSID7 TX beacon Error interrupt */
#define BIT_SHIFT_FS_TXBCNERR_MB6_INT                22
#define BIT_FS_TXBCNERR_MB6_INT                      ((u32)0x00000001 << BIT_SHIFT_FS_TXBCNERR_MB6_INT)                /*!<R/W1C 0  MBSSID6 TX beacon Error interrupt */
#define BIT_SHIFT_FS_TXBCNERR_MB5_INT                21
#define BIT_FS_TXBCNERR_MB5_INT                      ((u32)0x00000001 << BIT_SHIFT_FS_TXBCNERR_MB5_INT)                /*!<R/W1C 0  MBSSID5 TX beacon Error interrupt */
#define BIT_SHIFT_FS_TXBCNERR_MB4_INT                20
#define BIT_FS_TXBCNERR_MB4_INT                      ((u32)0x00000001 << BIT_SHIFT_FS_TXBCNERR_MB4_INT)                /*!<R/W1C 0  MBSSID4 TX beacon Error interrupt */
#define BIT_SHIFT_FS_TXBCNERR_MB3_INT                19
#define BIT_FS_TXBCNERR_MB3_INT                      ((u32)0x00000001 << BIT_SHIFT_FS_TXBCNERR_MB3_INT)                /*!<R/W1C 0  MBSSID3 TX beacon Error interrupt */
#define BIT_SHIFT_FS_TXBCNERR_MB2_INT                18
#define BIT_FS_TXBCNERR_MB2_INT                      ((u32)0x00000001 << BIT_SHIFT_FS_TXBCNERR_MB2_INT)                /*!<R/W1C 0  MBSSID2 TX beacon Error interrupt */
#define BIT_SHIFT_FS_TXBCNERR_MB1_INT                17
#define BIT_FS_TXBCNERR_MB1_INT                      ((u32)0x00000001 << BIT_SHIFT_FS_TXBCNERR_MB1_INT)                /*!<R/W1C 0  MBSSID1 TX beacon Error interrupt */
#define BIT_SHIFT_FS_TXBCNERR_MB0_INT                16
#define BIT_FS_TXBCNERR_MB0_INT                      ((u32)0x00000001 << BIT_SHIFT_FS_TXBCNERR_MB0_INT)                /*!<R/W1C 0  MBSSID0 TX beacon Error interrupt */
#define BIT_SHIFT_FS_CPUMGN_POLLED_PKT_DONE_INT      15
#define BIT_FS_CPUMGN_POLLED_PKT_DONE_INT            ((u32)0x00000001 << BIT_SHIFT_FS_CPUMGN_POLLED_PKT_DONE_INT)      /*!<R/W1C 0  CPU management queue polled packet released done interrupt enable (check cpu management queue current flow) */
#define BIT_SHIFT_FS_MGNTQ_FF_RELEASE_INT            13
#define BIT_FS_MGNTQ_FF_RELEASE_INT                  ((u32)0x00000001 << BIT_SHIFT_FS_MGNTQ_FF_RELEASE_INT)            /*!<R/W1C 0  MgntQ ReadPtr FIFO release interrupt (for 8822B) */
#define BIT_SHIFT_FS_CPUMGQ_ERR_INT                  11
#define BIT_FS_CPUMGQ_ERR_INT                        ((u32)0x00000001 << BIT_SHIFT_FS_CPUMGQ_ERR_INT)                  /*!<R/W1C 0  CPU management queue polled packet not TX OK while new packet comes in, enable to issue interrupt or not */
#define BIT_SHIFT_FS_HIOE_INT                        10
#define BIT_FS_HIOE_INT                              ((u32)0x00000001 << BIT_SHIFT_FS_HIOE_INT)                        /*!<R/W1C 0  hioe interrupt */
#define BIT_SHIFT_FS_DDMA0_LP_INT                    9
#define BIT_FS_DDMA0_LP_INT                          ((u32)0x00000001 << BIT_SHIFT_FS_DDMA0_LP_INT)                    /*!<R/W1C 0  Low priority ddma0 down interrupt . */
#define BIT_SHIFT_FS_DDMA0_HP_INT                    8
#define BIT_FS_DDMA0_HP_INT                          ((u32)0x00000001 << BIT_SHIFT_FS_DDMA0_HP_INT)                    /*!<R/W1C 0  High priority ddma0 down interrupt */
#define BIT_SHIFT_FS_TXRPT_INT                       7
#define BIT_FS_TXRPT_INT                             ((u32)0x00000001 << BIT_SHIFT_FS_TXRPT_INT)                       /*!<R/W1C 0  TX report interrupt */
#define BIT_SHIFT_FS_C2H_W_READY_INT                 6
#define BIT_FS_C2H_W_READY_INT                       ((u32)0x00000001 << BIT_SHIFT_FS_C2H_W_READY_INT)                 /*!<R/W1C 0  C2H register ready for write interrupt */
#define BIT_SHIFT_FS_HRCV_INT                        5
#define BIT_FS_HRCV_INT                              ((u32)0x00000001 << BIT_SHIFT_FS_HRCV_INT)                        /*!<R/W1C 0  Host to CPU Message Interrupt, generated on writing to 0x1CF */
#define BIT_SHIFT_FS_H2CCMD_INT                      4
#define BIT_FS_H2CCMD_INT                            ((u32)0x00000001 << BIT_SHIFT_FS_H2CCMD_INT)                      /*!<R/W1C 0  Host To CPU Message Interrupt */
#define BIT_SHIFT_FS_ERRORHDL_INT                    2
#define BIT_FS_ERRORHDL_INT                          ((u32)0x00000001 << BIT_SHIFT_FS_ERRORHDL_INT)                    /*!<R/W1C 0  FWHW/ TXDMA/ RXDMA/ WMAC error status interrupt(0x210[31:0], 0x288[31:0], 0x4E2[15:0], 0x6B8[31:0]). WMAC error state will be recovered by HW, the others won't. */
#define BIT_SHIFT_FS_TXCCX_INT                       1
#define BIT_FS_TXCCX_INT                             ((u32)0x00000001 << BIT_SHIFT_FS_TXCCX_INT)                       /*!<R/W1C 0  CCX PKT TX Report Interrupt */
#define BIT_SHIFT_FS_PTCL_HANDLE_OK_INT              0
#define BIT_FS_PTCL_HANDLE_OK_INT                    ((u32)0x00000001 << BIT_SHIFT_FS_PTCL_HANDLE_OK_INT)              /*!<R/W1C 0  TX Finish (Ack/BA process Finish) Interrupt. */

/* REG_FTIMR 0x0138 */
#define BIT_SHIFT_FTSR1_INT_EN                       31
#define BIT_FTSR1_INT_EN                             ((u32)0x00000001 << BIT_SHIFT_FTSR1_INT_EN)                       /*!<R/W --  FTMR1 Indicator (FTMR1 and FTMR1 are true, this bit is set to 1) */
#define BIT_SHIFT_FTSR2_INT_EN                       30
#define BIT_FTSR2_INT_EN                             ((u32)0x00000001 << BIT_SHIFT_FTSR2_INT_EN)                       /*!<R/W --  FTMR2 Indicator (FTMR2 and FTMR2 are true, this bit is set to 1) */
#define BIT_SHIFT_FS_RPWM2_INT_EN                    29
#define BIT_FS_RPWM2_INT_EN                          ((u32)0x00000001 << BIT_SHIFT_FS_RPWM2_INT_EN)                    /*!<R/W --  RPWM2 interrupt */
#define BIT_SHIFT_FS_RPWM_INT_EN                     28
#define BIT_FS_RPWM_INT_EN                           ((u32)0x00000001 << BIT_SHIFT_FS_RPWM_INT_EN)                     /*!<R/W 0  RPWM interrupt */

#define BIT_SHIFT_FS_PS_TIMER_C_EARLY_INT_EN         23
#define BIT_FS_PS_TIMER_C_EARLY_INT_EN               ((u32)0x00000001 << BIT_SHIFT_FS_PS_TIMER_C_EARLY_INT_EN)         /*!<R/W 0  This interrupt is issued at the time set by PS_Timer_C_Early register before PS_Timer_C time. */
#define BIT_SHIFT_FS_PS_TIMER_B_EARLY_INT_EN         22
#define BIT_FS_PS_TIMER_B_EARLY_INT_EN               ((u32)0x00000001 << BIT_SHIFT_FS_PS_TIMER_B_EARLY_INT_EN)         /*!<R/W 0  This interrupt is issued at the time set by PS_Timer_B_Early register before PS_Timer_B time. */
#define BIT_SHIFT_FS_PS_TIMER_A_EARLY_INT_EN         21
#define BIT_FS_PS_TIMER_A_EARLY_INT_EN               ((u32)0x00000001 << BIT_SHIFT_FS_PS_TIMER_A_EARLY_INT_EN)         /*!<R/W 0  This interrupt is issued at the time set by PS_Timer_A_Early register before PS_Timer_A time. */
#define BIT_SHIFT_FS_PS_TIMER_C_INT_EN               19
#define BIT_FS_PS_TIMER_C_INT_EN                     ((u32)0x00000001 << BIT_SHIFT_FS_PS_TIMER_C_INT_EN)               /*!<R/W 0  PS_Timer_C interrupt When the lower 4 bytes of TSF(that select by reg 0x1510[18:16]) matches the content of this register, the PS_Timer_C_INT interrupt is issued */
#define BIT_SHIFT_FS_PS_TIMER_B_INT_EN               18
#define BIT_FS_PS_TIMER_B_INT_EN                     ((u32)0x00000001 << BIT_SHIFT_FS_PS_TIMER_B_INT_EN)               /*!<R/W 0  PS_Timer_B interrupt When the lower 4 bytes of TSF(that select by reg 0x1510[10:8]) matches the content of this register, the PS_Timer_B_INT interrupt is issued */
#define BIT_SHIFT_FS_PS_TIMER_A_INT_EN               17
#define BIT_FS_PS_TIMER_A_INT_EN                     ((u32)0x00000001 << BIT_SHIFT_FS_PS_TIMER_A_INT_EN)               /*!<R/W 0  PS_Timer_A interrupt When the lower 4 bytes of TSF(that select by reg 0x1510[2:0]) matches the content of this register, the PS_Timer_A_INT interrupt is issued */
#define BIT_SHIFT_FS_PS_TIMEOUT2_INT_EN              15
#define BIT_FS_PS_TIMEOUT2_INT_EN                    ((u32)0x00000001 << BIT_SHIFT_FS_PS_TIMEOUT2_INT_EN)              /*!<R/W 0  PS_TimeOut2 interrupt . When the lower 4 bytes of FREERUN CNT matches the content of this register(0x588), the FW PS_TimeOut2 interrupt is issued. */
#define BIT_SHIFT_FS_PS_TIMEOUT1_INT_EN              14
#define BIT_FS_PS_TIMEOUT1_INT_EN                    ((u32)0x00000001 << BIT_SHIFT_FS_PS_TIMEOUT1_INT_EN)              /*!<R/W 0  PS_TimeOut1 interrupt . When the lower 4 bytes of TSFTR(that select by 0x5b1[5:3]) matches the content of this register(0x584), the FW PS_TimeOut1 interrupt is issued. */
#define BIT_SHIFT_FS_PS_TIMEOUT0_INT_EN              13
#define BIT_FS_PS_TIMEOUT0_INT_EN                    ((u32)0x00000001 << BIT_SHIFT_FS_PS_TIMEOUT0_INT_EN)              /*!<R/W 0  PS_TimeOut0 interrupt . When the lower 4 bytes of TSFTR(that select by 0x5b4[2:0]) matches the content of this register(0x580), the FW PS_TimeOut0 interrupt is issued. */

#define BIT_SHIFT_FS_FTM_PTT_INT_EN                  7
#define BIT_FS_FTM_PTT_INT_EN                        ((u32)0x00000001 << BIT_SHIFT_FS_FTM_PTT_INT_EN)                  /*!<R/W 0  Partial tsf timer */
#define BIT_SHIFT_FS_GTINT6_INT_EN                   6
#define BIT_FS_GTINT6_INT_EN                         ((u32)0x00000001 << BIT_SHIFT_FS_GTINT6_INT_EN)                /*!<R/W 0  General Timer[6] interrupt */
#define BIT_SHIFT_FS_GTINT5_INT_EN                   5
#define BIT_FS_GTINT5_INT_EN                         ((u32)0x00000001 << BIT_SHIFT_FS_GTINT5_INT_EN)                /*!<R/W 0  General Timer[5] interrupt */
#define BIT_SHIFT_FS_GTINT4_INT_EN                   4
#define BIT_FS_GTINT4_INT_EN                         ((u32)0x00000001 << BIT_SHIFT_FS_GTINT4_INT_EN)                /*!<R/W 0  General Timer[4] interrupt */
#define BIT_SHIFT_FS_GTINT3_INT_EN                   3
#define BIT_FS_GTINT3_INT_EN                         ((u32)0x00000001 << BIT_SHIFT_FS_GTINT3_INT_EN)                /*!<R/W 0  General Timer[3] interrupt */
#define BIT_SHIFT_FS_GTINT2_INT_EN                   2
#define BIT_FS_GTINT2_INT_EN                         ((u32)0x00000001 << BIT_SHIFT_FS_GTINT2_INT_EN)                /*!<R/W 0  General Timer[2] interrupt */
#define BIT_SHIFT_FS_GTINT1_INT_EN                   1
#define BIT_FS_GTINT1_INT_EN                         ((u32)0x00000001 << BIT_SHIFT_FS_GTINT1_INT_EN)                /*!<R/W 0  General Timer[1] interrupt */
#define BIT_SHIFT_FS_GTINT0_INT_EN                   0
#define BIT_FS_GTINT0_INT_EN                         ((u32)0x00000001 << BIT_SHIFT_FS_GTINT0_INT_EN)                /*!<R/W 0  General Timer[0] interrupt */

/* REG_FTISR 0x013C */
#define BIT_SHIFT_FTSR1_INT                          31
#define BIT_FTSR1_INT                                ((u32)0x00000001 << BIT_SHIFT_FTSR1_INT)                          /*!<R/W1C --  FTMR1 Indicator (FTMR1 and FTMR1 are true, this bit is set to 1) */
#define BIT_SHIFT_FTSR2_INT                          30
#define BIT_FTSR2_INT                                ((u32)0x00000001 << BIT_SHIFT_FTSR2_INT)                          /*!<R/W1C --  FTMR2 Indicator (FTMR2 and FTMR2 are true, this bit is set to 1) */
#define BIT_SHIFT_FS_RPWM2_INT                       29
#define BIT_FS_RPWM2_INT                             ((u32)0x00000001 << BIT_SHIFT_FS_RPWM2_INT)                       /*!<R/W1C --  RPWM2 interrupt */
#define BIT_SHIFT_FS_RPWM_INT                        28
#define BIT_FS_RPWM_INT                              ((u32)0x00000001 << BIT_SHIFT_FS_RPWM_INT)                        /*!<R/W1C 0  RPWM interrupt */

#define BIT_SHIFT_FS_PS_TIMER_C_EARLY_INT            23
#define BIT_FS_PS_TIMER_C_EARLY_INT                  ((u32)0x00000001 << BIT_SHIFT_FS_PS_TIMER_C_EARLY_INT)            /*!<R/W1C 0  This interrupt is issued at the time set by PS_Timer_C_Early register before PS_Timer_C time. */
#define BIT_SHIFT_FS_PS_TIMER_B_EARLY_INT            22
#define BIT_FS_PS_TIMER_B_EARLY_INT                  ((u32)0x00000001 << BIT_SHIFT_FS_PS_TIMER_B_EARLY_INT)            /*!<R/W1C 0  This interrupt is issued at the time set by PS_Timer_B_Early register before PS_Timer_B time. */
#define BIT_SHIFT_FS_PS_TIMER_A_EARLY_INT            21
#define BIT_FS_PS_TIMER_A_EARLY_INT                  ((u32)0x00000001 << BIT_SHIFT_FS_PS_TIMER_A_EARLY_INT)            /*!<R/W1C 0  This interrupt is issued at the time set by PS_Timer_A_Early register before PS_Timer_A time. */
#define BIT_SHIFT_FS_PS_TIMER_C_INT                  19
#define BIT_FS_PS_TIMER_C_INT                        ((u32)0x00000001 << BIT_SHIFT_FS_PS_TIMER_C_INT)                  /*!<R/W1C 0  PS_Timer_C interrupt When the lower 4 bytes of TSF(that select by reg 0x1510[18:16]) matches the content of this register, the PS_Timer_C_INT interrupt is issued */
#define BIT_SHIFT_FS_PS_TIMER_B_INT                  18
#define BIT_FS_PS_TIMER_B_INT                        ((u32)0x00000001 << BIT_SHIFT_FS_PS_TIMER_B_INT)                  /*!<R/W1C 0  PS_Timer_B interrupt When the lower 4 bytes of TSF(that select by reg 0x1510[10:8]) matches the content of this register, the PS_Timer_B_INT interrupt is issued */
#define BIT_SHIFT_FS_PS_TIMER_A_INT                  17
#define BIT_FS_PS_TIMER_A_INT                        ((u32)0x00000001 << BIT_SHIFT_FS_PS_TIMER_A_INT)                  /*!<R/W1C 0  PS_Timer_A interrupt When the lower 4 bytes of TSF(that select by reg 0x1510[2:0]) matches the content of this register, the PS_Timer_A_INT interrupt is issued */
#define BIT_SHIFT_FS_PS_TIMEOUT2_INT                 15
#define BIT_FS_PS_TIMEOUT2_INT                       ((u32)0x00000001 << BIT_SHIFT_FS_PS_TIMEOUT2_INT)                 /*!<R/W1C 0  PS_TimeOut2 interrupt . When the lower 4 bytes of FREERUN CNT matches the content of this register(0x588), the FW PS_TimeOut2 interrupt is issued. */
#define BIT_SHIFT_FS_PS_TIMEOUT1_INT                 14
#define BIT_FS_PS_TIMEOUT1_INT                       ((u32)0x00000001 << BIT_SHIFT_FS_PS_TIMEOUT1_INT)                 /*!<R/W1C 0  PS_TimeOut1 interrupt . When the lower 4 bytes of TSFTR(that select by 0x5b1[5:3]) matches the content of this register(0x584), the FW PS_TimeOut1 interrupt is issued. */
#define BIT_SHIFT_FS_PS_TIMEOUT0_INT                 13
#define BIT_FS_PS_TIMEOUT0_INT                       ((u32)0x00000001 << BIT_SHIFT_FS_PS_TIMEOUT0_INT)                 /*!<R/W1C 0  PS_TimeOut0 interrupt . When the lower 4 bytes of TSFTR(that select by 0x5b4[2:0]) matches the content of this register(0x580), the FW PS_TimeOut0 interrupt is issued. */

#define BIT_SHIFT_FS_FTM_PTT_INT                     7
#define BIT_FS_FTM_PTT_INT                           ((u32)0x00000001 << BIT_SHIFT_FS_FTM_PTT_INT)                     /*!<R/W1C 0  Partial tsf timer */
#define BIT_SHIFT_FS_GTINT6_INT                      6
#define BIT_FS_GTINT6_INT                            ((u32)0x00000001 << BIT_SHIFT_FS_GTINT6_INT)                      /*!<R/W1C 0  General Timer[6] interrupt */
#define BIT_SHIFT_FS_GTINT5_INT                      5
#define BIT_FS_GTINT5_INT                            ((u32)0x00000001 << BIT_SHIFT_FS_GTINT5_INT)                      /*!<R/W1C 0  General Timer[5] interrupt */
#define BIT_SHIFT_FS_GTINT4_INT                      4
#define BIT_FS_GTINT4_INT                            ((u32)0x00000001 << BIT_SHIFT_FS_GTINT4_INT)                      /*!<R/W1C 0  General Timer[4] interrupt */
#define BIT_SHIFT_FS_GTINT3_INT                      3
#define BIT_FS_GTINT3_INT                            ((u32)0x00000001 << BIT_SHIFT_FS_GTINT3_INT)                      /*!<R/W1C 0  General Timer[3] interrupt */
#define BIT_SHIFT_FS_GTINT2_INT                      2
#define BIT_FS_GTINT2_INT                            ((u32)0x00000001 << BIT_SHIFT_FS_GTINT2_INT)                      /*!<R/W1C 0  General Timer[2] interrupt */
#define BIT_SHIFT_FS_GTINT1_INT                      1
#define BIT_FS_GTINT1_INT                            ((u32)0x00000001 << BIT_SHIFT_FS_GTINT1_INT)                      /*!<R/W1C 0  General Timer[1] interrupt */
#define BIT_SHIFT_FS_GTINT0_INT                      0
#define BIT_FS_GTINT0_INT                            ((u32)0x00000001 << BIT_SHIFT_FS_GTINT0_INT)                      /*!<R/W1C 0  General Timer[0] interrupt */



/* REG_CPWM2 0x014C */

#define BIT_SHIFT_L0S_TO_RCVY_NUM                    16
#define BIT_MASK_L0S_TO_RCVY_NUM                     ((u32)0x000000FF << BIT_SHIFT_L0S_TO_RCVY_NUM)                    /*!<R/W 0  Number of L0S to recovery of PCIE */
#define BIT_SHIFT_CPWM2_TOGGLING                     15
#define BIT_CPWM2_TOGGLING                           ((u32)0x00000001 << BIT_SHIFT_CPWM2_TOGGLING)                     /*!<R/W 0  Toggling bit : one bit sequence number bit. When this bit is toggled, interrupt is send to HISRE.CPWMINT. */
#define BIT_SHIFT_CPWM2_MOD                          0
#define BIT_MASK_CPWM2_MOD                           ((u32)0x00007FFF << BIT_SHIFT_CPWM2_MOD)                          /*!<R/W 0  The current power mode index. */

/* REG_TC0_CTRL 0x0150 */

#define BIT_SHIFT_TC0INT_EN                          26
#define BIT_TC0INT_EN                                ((u32)0x00000001 << BIT_SHIFT_TC0INT_EN)                          /*!<R/W 0  When write ��1�� to this bit, Counter 0 starts counting down. This is a one-bit pulse. */
#define BIT_SHIFT_TC0MODE                            25
#define BIT_TC0MODE                                  ((u32)0x00000001 << BIT_SHIFT_TC0MODE)                            /*!<R/W 0  Timer/Counter 0 mode 0=counter mode 1=timer mode */
#define BIT_SHIFT_TC0EN                              24
#define BIT_TC0EN                                    ((u32)0x00000001 << BIT_SHIFT_TC0EN)                              /*!<R/W 0  Timer/Counter 0 enable */
#define BIT_SHIFT_TC0DATA                            0
#define BIT_MASK_TC0DATA                             ((u32)0x00FFFFFF << BIT_SHIFT_TC0DATA)                            /*!<R/W 0  Timer/Counter 0 data register. It specifies the time-out duration. */

/* REG_TC1_CTRL 0x0154 */

#define BIT_SHIFT_TC1INT_EN                          26
#define BIT_TC1INT_EN                                ((u32)0x00000001 << BIT_SHIFT_TC1INT_EN)                          /*!<R/W 0  When write ��1�� to this bit, Counter 1 starts counting down. This is a one-bit pulse. */
#define BIT_SHIFT_TC1MODE                            25
#define BIT_TC1MODE                                  ((u32)0x00000001 << BIT_SHIFT_TC1MODE)                            /*!<R/W 0  Timer/Counter 1 mode 0=counter mode 1=timer mode */
#define BIT_SHIFT_TC1EN                              24
#define BIT_TC1EN                                    ((u32)0x00000001 << BIT_SHIFT_TC1EN)                              /*!<R/W 0  Timer/Counter 1 enable */
#define BIT_SHIFT_TC1DATA                            0
#define BIT_MASK_TC1DATA                             ((u32)0x00FFFFFF << BIT_SHIFT_TC1DATA)                            /*!<R/W 0  Timer/Counter 1 data register. It specifies the time-out duration. */

/* REG_TC2_CTRL 0x0158 */

#define BIT_SHIFT_TC2INT_EN                          26
#define BIT_TC2INT_EN                                ((u32)0x00000001 << BIT_SHIFT_TC2INT_EN)                          /*!<R/W 0  When write ��1�� to this bit, Counter 2 starts counting down. This is a one-bit pulse. */
#define BIT_SHIFT_TC2MODE                            25
#define BIT_TC2MODE                                  ((u32)0x00000001 << BIT_SHIFT_TC2MODE)                            /*!<R/W 0  Timer/Counter 2 mode 0=counter mode 1=timer mode */
#define BIT_SHIFT_TC2EN                              24
#define BIT_TC2EN                                    ((u32)0x00000001 << BIT_SHIFT_TC2EN)                              /*!<R/W 0  Timer/Counter 2 enable */
#define BIT_SHIFT_TC2DATA                            0
#define BIT_MASK_TC2DATA                             ((u32)0x00FFFFFF << BIT_SHIFT_TC2DATA)                            /*!<R/W 0  Timer/Counter 2 data register. It specifies the time-out duration. */

/* REG_TC3_CTRL 0x015C */

#define BIT_SHIFT_TC3INT_EN                          26
#define BIT_TC3INT_EN                                ((u32)0x00000001 << BIT_SHIFT_TC3INT_EN)                          /*!<R/W 0  When write ��1�� to this bit, Counter 3 starts counting down. This is a one-bit pulse. */
#define BIT_SHIFT_TC3MODE                            25
#define BIT_TC3MODE                                  ((u32)0x00000001 << BIT_SHIFT_TC3MODE)                            /*!<R/W 0  Timer/Counter 3 mode 0=counter mode 1=timer mode */
#define BIT_SHIFT_TC3EN                              24
#define BIT_TC3EN                                    ((u32)0x00000001 << BIT_SHIFT_TC3EN)                              /*!<R/W 0  Timer/Counter 3 enable */
#define BIT_SHIFT_TC3DATA                            0
#define BIT_MASK_TC3DATA                             ((u32)0x00FFFFFF << BIT_SHIFT_TC3DATA)                            /*!<R/W 0  Timer/Counter 3 data register. It specifies the time-out duration. */

/* REG_TC4_CTRL 0x0160 */

#define BIT_SHIFT_TC4INT_EN                          26
#define BIT_TC4INT_EN                                ((u32)0x00000001 << BIT_SHIFT_TC4INT_EN)                          /*!<R/W 0  When write ��1�� to this bit, Counter 4 starts counting down. This is a one-bit pulse. */
#define BIT_SHIFT_TC4MODE                            25
#define BIT_TC4MODE                                  ((u32)0x00000001 << BIT_SHIFT_TC4MODE)                            /*!<R/W 0  Timer/Counter 4mode 0=counter mode 1=timer mode */
#define BIT_SHIFT_TC4EN                              24
#define BIT_TC4EN                                    ((u32)0x00000001 << BIT_SHIFT_TC4EN)                              /*!<R/W 0  Timer/Counter 4 enable */
#define BIT_SHIFT_TC4DATA                            0
#define BIT_MASK_TC4DATA                             ((u32)0x00FFFFFF << BIT_SHIFT_TC4DATA)                            /*!<R/W 0  Timer/Counter 4 data register. It specifies the time-out duration. */

/* REG_TCUNIT_BASE 0x0164 */

#define BIT_SHIFT_TC_UNIT_BASE                       0
#define BIT_MASK_TC_UNIT_BASE                        ((u32)0x00003FFF << BIT_SHIFT_TC_UNIT_BASE)                       /*!<R/W 0  The register set the number of clocks that equals to the base time unit of timer/counter. The clock domain is 32k clock domain. */

/* REG_TC5_CTRL 0x0168 */

#define BIT_SHIFT_TC50INT_EN                         26
#define BIT_TC50INT_EN                               ((u32)0x00000001 << BIT_SHIFT_TC50INT_EN)                         /*!<R/W 0  When write ��1�� to this bit, Counter 5 starts counting down. This is a one-bit pulse. */
#define BIT_SHIFT_TC5MODE                            25
#define BIT_TC5MODE                                  ((u32)0x00000001 << BIT_SHIFT_TC5MODE)                            /*!<R/W 0  Timer/Counter 5 mode 0=counter mode 1=timer mode */
#define BIT_SHIFT_TC5EN                              24
#define BIT_TC5EN                                    ((u32)0x00000001 << BIT_SHIFT_TC5EN)                              /*!<R/W 0  Timer/Counter5 enable */
#define BIT_SHIFT_TC5DATA                            0
#define BIT_MASK_TC5DATA                             ((u32)0x00FFFFFF << BIT_SHIFT_TC5DATA)                            /*!<R/W 0  Timer/Counter 5 data register. It specifies the time-out duration. */

/* REG_TC6_CTRL 0x016C */

#define BIT_SHIFT_TC60INT_EN                         26
#define BIT_TC60INT_EN                               ((u32)0x00000001 << BIT_SHIFT_TC60INT_EN)                         /*!<R/W 0  When write ��1�� to this bit, Counter 6 starts counting down. This is a one-bit pulse. */
#define BIT_SHIFT_TC6MODE                            25
#define BIT_TC6MODE                                  ((u32)0x00000001 << BIT_SHIFT_TC6MODE)                            /*!<R/W 0  Timer/Counter 6 mode 0=counter mode 1=timer mode */
#define BIT_SHIFT_TC6EN                              24
#define BIT_TC6EN                                    ((u32)0x00000001 << BIT_SHIFT_TC6EN)                              /*!<R/W 0  Timer/Counter6 enable */
#define BIT_SHIFT_TC6DATA                            0
#define BIT_MASK_TC6DATA                             ((u32)0x00FFFFFF << BIT_SHIFT_TC6DATA)                            /*!<R/W 0  Timer/Counter 6 data register. It specifies the time-out duration. */

/* REG_HW_IOE_CR 0x01B0 */
#define BIT_SHIFT_HIOE_ACTIVE                        31
#define BIT_HIOE_ACTIVE                              ((u32)0x00000001 << BIT_SHIFT_HIOE_ACTIVE)                        /*!<R 0  indicate HIOE engine is active */

#define BIT_SHIFT_HIOE_RESTORE_REQ                   25
#define BIT_HIOE_RESTORE_REQ                         ((u32)0x00000001 << BIT_SHIFT_HIOE_RESTORE_REQ)                   /*!<W1C 0  WLOFF REG restore request, 1 pulse */
#define BIT_SHIFT_HIOE_BACKUP_REQ                    24
#define BIT_HIOE_BACKUP_REQ                          ((u32)0x00000001 << BIT_SHIFT_HIOE_BACKUP_REQ)                    /*!<W1C 0  WLOFF REG backup request, 1 pulse */
#define BIT_SHIFT_HIOE_END_ADDR                      12
#define BIT_MASK_HIOE_END_ADDR                       ((u32)0x00000FFF << BIT_SHIFT_HIOE_END_ADDR)                      /*!<R/W 0  HIOE command end address in txpktbuffer, unit:8byte */
#define BIT_SHIFT_HIOE_STR_ADDR                      0
#define BIT_MASK_HIOE_STR_ADDR                       ((u32)0x00000FFF << BIT_SHIFT_HIOE_STR_ADDR)                      /*!<R/W 0  HIOE command start address in txpktbuffer, unit:8byte */

/* REG_BB_RFC_ATR 0x01B4 */

#define BIT_SHIFT_PHYWR_SETUP_CNT                    8
#define BIT_MASK_PHYWR_SETUP_CNT                     ((u32)0x0000000F << BIT_SHIFT_PHYWR_SETUP_CNT)                    /*!<R/W 5  the timing WDATA stable before WE for host/cpu access BB/RFC REG */
#define BIT_SHIFT_PHYWR_HOLD_CNT                     4
#define BIT_MASK_PHYWR_HOLD_CNT                      ((u32)0x0000000F << BIT_SHIFT_PHYWR_HOLD_CNT)                     /*!<R/W 4  the timing WDATA stable after WE for host/cpu access BB/RFC REG */
#define BIT_SHIFT_PHYRD_WAIT_CNT                     0
#define BIT_MASK_PHYRD_WAIT_CNT                      ((u32)0x0000000F << BIT_SHIFT_PHYRD_WAIT_CNT)                     /*!<R/W 4  the timing RDATA stable after ADDR for host/cpu access BB/RFC REG */

/* REG_SW_DEFINED_PAGE1 0x01B8 */
#define BIT_SHIFT_SW_DEFINED_PAGE1_V1                0
#define BIT_MASK_SW_DEFINED_PAGE1_V1                 ((u32)0xFFFFFFFF << BIT_SHIFT_SW_DEFINED_PAGE1_V1)                /*!<R/W 0  User Defined Message */

/* REG_SW_DEFINED_PAGE2 0x01BC */
#define BIT_SHIFT_SW_DEFINED_PAGE2                   0
#define BIT_MASK_SW_DEFINED_PAGE2                    ((u32)0xFFFFFFFF << BIT_SHIFT_SW_DEFINED_PAGE2)                   /*!<R/W 0  User Defined Message */

/* REG_MCUTST_I 0x01C0 */
#define BIT_SHIFT_MCUDMSG_I                          0
#define BIT_MASK_MCUDMSG_I                           ((u32)0xFFFFFFFF << BIT_SHIFT_MCUDMSG_I)                          /*!<R/W 0  User Defined Message */

/* REG_MCUTST_II 0x01C4 */
#define BIT_SHIFT_MCUDMSG_II                         0
#define BIT_MASK_MCUDMSG_II                          ((u32)0xFFFFFFFF << BIT_SHIFT_MCUDMSG_II)                         /*!<R/W 0  User Defined Message */

/* REG_FMETHR 0x01C8 */
#define BIT_SHIFT_FWMSG_INTPS                        31
#define BIT_FWMSG_INTPS                              ((u32)0x00000001 << BIT_SHIFT_FWMSG_INTPS)                        /*!<R/W 0  Toggle this bit will generate C2H interrupt to Host */
#define BIT_SHIFT_FW_MSG                             0
#define BIT_MASK_FW_MSG                              ((u32)0x7FFFFFFF << BIT_SHIFT_FW_MSG)                             /*!<R/W 0  User Defined Message */

/* REG_HMETFR 0x01CC */
#define BIT_SHIFT_HRCV_MSG                           24
#define BIT_MASK_HRCV_MSG                            ((u32)0x000000FF << BIT_SHIFT_HRCV_MSG)                           /*!<R/W 0  Host Recover Message, Host Write This Byte will generate interrupt to 8051 (0x0134h[5]) */

#define BIT_SHIFT_H3MSG_VLD                          3
#define BIT_H3MSG_VLD                                ((u32)0x00000001 << BIT_SHIFT_H3MSG_VLD)                          /*!<R/W 0  MSG_BOX_3 Valid. Enable when the Entry is write, Clear when the Entry is Read by 8051. */
#define BIT_SHIFT_H2MSG_VLD                          2
#define BIT_H2MSG_VLD                                ((u32)0x00000001 << BIT_SHIFT_H2MSG_VLD)                          /*!<R/W 0  MSG_BOX_2 Valid. Enable when the Entry is write, Clear when the Entry is Read by 8051. */
#define BIT_SHIFT_H1MSG_VLD                          1
#define BIT_H1MSG_VLD                                ((u32)0x00000001 << BIT_SHIFT_H1MSG_VLD)                          /*!<R/W 0  MSG_BOX_1 Valid. Enable when the Entry is write, Clear when the Entry is Read by 8051. */
#define BIT_SHIFT_H0MSG_VLD                          0
#define BIT_H0MSG_VLD                                ((u32)0x00000001 << BIT_SHIFT_H0MSG_VLD)                          /*!<R/W 0  MSG_BOX_0 Valid. Enable when the Entry is write, Clear when the Entry is Read by 8051. */

/* REG_HMEBOX0 0x01D0 */
#define BIT_SHIFT_HOST_MSG_0                         0
#define BIT_MASK_HOST_MSG_0                          ((u32)0xFFFFFFFF << BIT_SHIFT_HOST_MSG_0)                         /*!<R/W 0  User Defined Message */

/* REG_HMEBOX1 0x01D4 */
#define BIT_SHIFT_HOST_MSG_1                         0
#define BIT_MASK_HOST_MSG_1                          ((u32)0xFFFFFFFF << BIT_SHIFT_HOST_MSG_1)                         /*!<R/W 0  User Defined Message */

/* REG_HMEBOX2 0x01D8 */
#define BIT_SHIFT_HOST_MSG_2                         0
#define BIT_MASK_HOST_MSG_2                          ((u32)0xFFFFFFFF << BIT_SHIFT_HOST_MSG_2)                         /*!<R/W 0  User Defined Message */

/* REG_HMEBOX3 0x01DC */
#define BIT_SHIFT_HOST_MSG_3                         0
#define BIT_MASK_HOST_MSG_3                          ((u32)0xFFFFFFFF << BIT_SHIFT_HOST_MSG_3)                         /*!<R/W 0  User Defined Message */

/* REG_GENTST 0x01E4 */
#define BIT_SHIFT_GENTST                             0
#define BIT_MASK_GENTST                              ((u32)0xFFFFFFFF << BIT_SHIFT_GENTST)                             /*!<R/W 0  Dummy register for MAC I/O REG Read/Write Access TEST */

/* REG_BB_ACCESS_CTRL 0x01E8 */
#define BIT_SHIFT_BB_WRITE_READ                      30
#define BIT_MASK_BB_WRITE_READ                       ((u32)0x00000003 << BIT_SHIFT_BB_WRITE_READ)                      /*!<R/W 0  00 : No Active Baseband cycle 01 : Baseband Write Access (auto return to 00 when access finished) 1X : Baseband Read Access (auto return to 00 when access finished) */

#define BIT_SHIFT_BB_WRITE_EN_V1                     15
#define BIT_MASK_BB_WRITE_EN_V1                      ((u32)0x0000000F << BIT_SHIFT_BB_WRITE_EN_V1)                     /*!<R/W 0  Byte Write Enable */
#define BIT_SHIFT_BB_ADDR_V1                         2
#define BIT_MASK_BB_ADDR_V1                          ((u32)0x00001FFF << BIT_SHIFT_BB_ADDR_V1)                         /*!<R/W 0  Baseband Access Write/Read Address (in DW unit) */

#define BIT_SHIFT_BB_ERRACC                          0
#define BIT_BB_ERRACC                                ((u32)0x00000001 << BIT_SHIFT_BB_ERRACC)                          /*!<R/W 0  Duplicate Access when previous cycle pending (write one clear) */

/* REG_BB_ACCESS_DATA 0x01EC */
#define BIT_SHIFT_BB_DATA                            0
#define BIT_MASK_BB_DATA                             ((u32)0xFFFFFFFF << BIT_SHIFT_BB_DATA)                            /*!<R/W 0  Baseband Access Write/Read Data (in DW unit) */

/* REG_HMEBOX_E0 0x01F0 */
#define BIT_SHIFT_HMEBOX_E0                          0
#define BIT_MASK_HMEBOX_E0                           ((u32)0xFFFFFFFF << BIT_SHIFT_HMEBOX_E0)                          /*!<R/W 0  User Defined Message */

/* REG_HMEBOX_E1 0x01F4 */
#define BIT_SHIFT_HMEBOX_E1                          0
#define BIT_MASK_HMEBOX_E1                           ((u32)0xFFFFFFFF << BIT_SHIFT_HMEBOX_E1)                          /*!<R/W 0  User Defined Message */

/* REG_HMEBOX_E2 0x01F8 */
#define BIT_SHIFT_HMEBOX_E2                          0
#define BIT_MASK_HMEBOX_E2                           ((u32)0xFFFFFFFF << BIT_SHIFT_HMEBOX_E2)                          /*!<R/W 0  User Defined Message */

/* REG_HMEBOX_E3 0x01FC */
#define BIT_SHIFT_HMEBOX_E3                          0
#define BIT_MASK_HMEBOX_E3                           ((u32)0xFFFFFFFF << BIT_SHIFT_HMEBOX_E3)                          /*!<R/W 0  User Defined Message */

/* REG_ZB2WL_MAILBOX 0x1110 */
#define BIT_SHIFT_ZB2WL_MAILBOX                      0
#define BIT_MASK_ZB2WL_MAILBOX                       ((u32)0xFFFFFFFF << BIT_SHIFT_ZB2WL_MAILBOX)                      /*!<R/W 0  Write to generate interrupt (0x116C [31]) */

/* REG_WL2ZB_MAILBOX 0x1114 */
#define BIT_SHIFT_WL2ZB_MAILBOX                      0
#define BIT_MASK_WL2ZB_MAILBOX                       ((u32)0xFFFFFFFF << BIT_SHIFT_WL2ZB_MAILBOX)                      /*!<R/W 0  Write to generate interrupt (0x0C4 [10]) */

/* REG_FE2IMR 0x1120 */

#define BIT_SHIFT_FS_ATIM_PORT1_INT_EN               24
#define BIT_FS_ATIM_PORT1_INT_EN                     ((u32)0x00000001 << BIT_SHIFT_FS_ATIM_PORT1_INT_EN)               /*!<R/W 0  PORT1 ATIM end window interrupt . */
#define BIT_SHIFT_FS_ATIM_MB7_INT_EN                 23
#define BIT_FS_ATIM_MB7_INT_EN                       ((u32)0x00000001 << BIT_SHIFT_FS_ATIM_MB7_INT_EN)                 /*!<R/W 0  MBSSID7 ATIM end window interrupt . */
#define BIT_SHIFT_FS_ATIM_MB6_INT_EN                 22
#define BIT_FS_ATIM_MB6_INT_EN                       ((u32)0x00000001 << BIT_SHIFT_FS_ATIM_MB6_INT_EN)                 /*!<R/W 0  MBSSID6 ATIM end window interrupt . */
#define BIT_SHIFT_FS_ATIM_MB5_INT_EN                 21
#define BIT_FS_ATIM_MB5_INT_EN                       ((u32)0x00000001 << BIT_SHIFT_FS_ATIM_MB5_INT_EN)                 /*!<R/W 0  MBSSID5 ATIM end window interrupt . */
#define BIT_SHIFT_FS_ATIM_MB4_INT_EN                 20
#define BIT_FS_ATIM_MB4_INT_EN                       ((u32)0x00000001 << BIT_SHIFT_FS_ATIM_MB4_INT_EN)                 /*!<R/W 0  MBSSID4 ATIM end window interrupt . */
#define BIT_SHIFT_FS_ATIM_MB3_INT_EN                 19
#define BIT_FS_ATIM_MB3_INT_EN                       ((u32)0x00000001 << BIT_SHIFT_FS_ATIM_MB3_INT_EN)                 /*!<R/W 0  MBSSID3 ATIM end window interrupt . */
#define BIT_SHIFT_FS_ATIM_MB2_INT_EN                 18
#define BIT_FS_ATIM_MB2_INT_EN                       ((u32)0x00000001 << BIT_SHIFT_FS_ATIM_MB2_INT_EN)                 /*!<R/W 0  MBSSID2 ATIM end window interrupt . */
#define BIT_SHIFT_FS_ATIM_MB1_INT_EN                 17
#define BIT_FS_ATIM_MB1_INT_EN                       ((u32)0x00000001 << BIT_SHIFT_FS_ATIM_MB1_INT_EN)                 /*!<R/W 0  MBSSID1 ATIM end window interrupt . */
#define BIT_SHIFT_FS_ATIM_MB0_INT_EN                 16
#define BIT_FS_ATIM_MB0_INT_EN                       ((u32)0x00000001 << BIT_SHIFT_FS_ATIM_MB0_INT_EN)                 /*!<R/W 0  MBSSID0 ATIM end window interrupt . */
#define BIT_SHIFT_FS_CTWE_INT2_EN                    15
#define BIT_FS_CTWE_INT2_EN                          ((u32)0x00000001 << BIT_SHIFT_FS_CTWE_INT2_EN)                    /*!<R/W 0  port2 CTWindow end interrupt . */
#define BIT_SHIFT_FS_CTWE_INT0_EN                    14
#define BIT_FS_CTWE_INT0_EN                          ((u32)0x00000001 << BIT_SHIFT_FS_CTWE_INT0_EN)                    /*!<R/W 0  port0 CTWindow end interrupt . */
#define BIT_SHIFT_FS_CTWE_INT1_EN                    13
#define BIT_FS_CTWE_INT1_EN                          ((u32)0x00000001 << BIT_SHIFT_FS_CTWE_INT1_EN)                    /*!<R/W 0  port1 CTWindow end interrupt . */
#define BIT_SHIFT_FS_TBTTALL_INT_EN                  12
#define BIT_FS_TBTTALL_INT_EN                        ((u32)0x00000001 << BIT_SHIFT_FS_TBTTALL_INT_EN)                  /*!<R/W 0  the interrupt from the exact TBTT time for all port. */
#define BIT_SHIFT_FS_TBTT2INT_EN                     9
#define BIT_FS_TBTT2INT_EN                           ((u32)0x00000001 << BIT_SHIFT_FS_TBTT2INT_EN)                     /*!<R/W 0  the interrupt from the exact TBTT time for P2. */
#define BIT_SHIFT_FS_TBTT1INT_EN                     8
#define BIT_FS_TBTT1INT_EN                           ((u32)0x00000001 << BIT_SHIFT_FS_TBTT1INT_EN)                     /*!<R/W 0  the interrupt from the exact TBTT time for P1. */
#define BIT_SHIFT_FS_TBTT0_MB7INT_EN                 7
#define BIT_FS_TBTT0_MB7INT_EN                       ((u32)0x00000001 << BIT_SHIFT_FS_TBTT0_MB7INT_EN)                 /*!<R/W 0  the interrupt from the exact TBTT time for P0 MBSSID7. */
#define BIT_SHIFT_FS_TBTT0_MB6INT_EN                 6
#define BIT_FS_TBTT0_MB6INT_EN                       ((u32)0x00000001 << BIT_SHIFT_FS_TBTT0_MB6INT_EN)                 /*!<R/W 0  the interrupt from the exact TBTT time for P0 MBSSID6. */
#define BIT_SHIFT_FS_TBTT0_MB5INT_EN                 5
#define BIT_FS_TBTT0_MB5INT_EN                       ((u32)0x00000001 << BIT_SHIFT_FS_TBTT0_MB5INT_EN)                 /*!<R/W 0  the interrupt from the exact TBTT time for P0 MBSSID5. */
#define BIT_SHIFT_FS_TBTT0_MB4INT_EN                 4
#define BIT_FS_TBTT0_MB4INT_EN                       ((u32)0x00000001 << BIT_SHIFT_FS_TBTT0_MB4INT_EN)                 /*!<R/W 0  the interrupt from the exact TBTT time for P0 MBSSID4. */
#define BIT_SHIFT_FS_TBTT0_MB3INT_EN                 3
#define BIT_FS_TBTT0_MB3INT_EN                       ((u32)0x00000001 << BIT_SHIFT_FS_TBTT0_MB3INT_EN)                 /*!<R/W 0  the interrupt from the exact TBTT time for P0 MBSSID3. */
#define BIT_SHIFT_FS_TBTT0_MB2INT_EN                 2
#define BIT_FS_TBTT0_MB2INT_EN                       ((u32)0x00000001 << BIT_SHIFT_FS_TBTT0_MB2INT_EN)                 /*!<R/W 0  the interrupt from the exact TBTT time for P0 MBSSID2. */
#define BIT_SHIFT_FS_TBTT0_MB1INT_EN                 1
#define BIT_FS_TBTT0_MB1INT_EN                       ((u32)0x00000001 << BIT_SHIFT_FS_TBTT0_MB1INT_EN)                 /*!<R/W 0  the interrupt from the exact TBTT time for P0 MBSSID1. */
#define BIT_SHIFT_FS_TBTT0_INT_EN                    0
#define BIT_FS_TBTT0_INT_EN                          ((u32)0x00000001 << BIT_SHIFT_FS_TBTT0_INT_EN)                    /*!<R/W 0  the interrupt from the exact TBTT time for P0 MBSSID0. */

/* REG_FE2ISR 0x1124 */

#define BIT_SHIFT_FS_ATIM_PORT1_INT                  24
#define BIT_FS_ATIM_PORT1_INT                        ((u32)0x00000001 << BIT_SHIFT_FS_ATIM_PORT1_INT)                  /*!<R/W1C 0  PORT1 ATIM end window interrupt . */
#define BIT_SHIFT_FS_ATIM_MB7_INT                    23
#define BIT_FS_ATIM_MB7_INT                          ((u32)0x00000001 << BIT_SHIFT_FS_ATIM_MB7_INT)                    /*!<R/W1C 0  MBSSID7 ATIM end window interrupt . */
#define BIT_SHIFT_FS_ATIM_MB6_INT                    22
#define BIT_FS_ATIM_MB6_INT                          ((u32)0x00000001 << BIT_SHIFT_FS_ATIM_MB6_INT)                    /*!<R/W1C 0  MBSSID6 ATIM end window interrupt . */
#define BIT_SHIFT_FS_ATIM_MB5_INT                    21
#define BIT_FS_ATIM_MB5_INT                          ((u32)0x00000001 << BIT_SHIFT_FS_ATIM_MB5_INT)                    /*!<R/W1C 0  MBSSID5 ATIM end window interrupt . */
#define BIT_SHIFT_FS_ATIM_MB4_INT                    20
#define BIT_FS_ATIM_MB4_INT                          ((u32)0x00000001 << BIT_SHIFT_FS_ATIM_MB4_INT)                    /*!<R/W1C 0  MBSSID4 ATIM end window interrupt . */
#define BIT_SHIFT_FS_ATIM_MB3_INT                    19
#define BIT_FS_ATIM_MB3_INT                          ((u32)0x00000001 << BIT_SHIFT_FS_ATIM_MB3_INT)                    /*!<R/W1C 0  MBSSID3 ATIM end window interrupt . */
#define BIT_SHIFT_FS_ATIM_MB2_INT                    18
#define BIT_FS_ATIM_MB2_INT                          ((u32)0x00000001 << BIT_SHIFT_FS_ATIM_MB2_INT)                    /*!<R/W1C 0  MBSSID2 ATIM end window interrupt . */
#define BIT_SHIFT_FS_ATIM_MB1_INT                    17
#define BIT_FS_ATIM_MB1_INT                          ((u32)0x00000001 << BIT_SHIFT_FS_ATIM_MB1_INT)                    /*!<R/W1C 0  MBSSID1 ATIM end window interrupt . */
#define BIT_SHIFT_FS_ATIM_MB0_INT                    16
#define BIT_FS_ATIM_MB0_INT                          ((u32)0x00000001 << BIT_SHIFT_FS_ATIM_MB0_INT)                    /*!<R/W1C 0  MBSSID0 ATIM end window interrupt . */
#define BIT_SHIFT_FS_CTWE_INT2                       15
#define BIT_FS_CTWE_INT2                             ((u32)0x00000001 << BIT_SHIFT_FS_CTWE_INT2)                       /*!<R/W1C 0  port2 CTWindow end interrupt . */
#define BIT_SHIFT_FS_CTWE_INT0                       14
#define BIT_FS_CTWE_INT0                             ((u32)0x00000001 << BIT_SHIFT_FS_CTWE_INT0)                       /*!<R/W1C 0  port0 CTWindow end interrupt . */
#define BIT_SHIFT_FS_CTWE_INT1                       13
#define BIT_FS_CTWE_INT1                             ((u32)0x00000001 << BIT_SHIFT_FS_CTWE_INT1)                       /*!<R/W1C 0  port1 CTWindow end interrupt . */
#define BIT_SHIFT_FS_TBTTALL_INT                     12
#define BIT_FS_TBTTALL_INT                           ((u32)0x00000001 << BIT_SHIFT_FS_TBTTALL_INT)                     /*!<R/W1C 0  the interrupt from the exact TBTT time for all port. */
#define BIT_SHIFT_FS_TBTT2INT                        9
#define BIT_FS_TBTT2INT                              ((u32)0x00000001 << BIT_SHIFT_FS_TBTT2INT)                        /*!<R/W1C 0  the interrupt from the exact TBTT time for P2. */
#define BIT_SHIFT_FS_TBTT1INT                        8
#define BIT_FS_TBTT1INT                              ((u32)0x00000001 << BIT_SHIFT_FS_TBTT1INT)                        /*!<R/W1C 0  the interrupt from the exact TBTT time for P1. */
#define BIT_SHIFT_FS_TBTT0_MB7INT                    7
#define BIT_FS_TBTT0_MB7INT                          ((u32)0x00000001 << BIT_SHIFT_FS_TBTT0_MB7INT)                    /*!<R/W1C 0  the interrupt from the exact TBTT time for P0 MBSSID7. */
#define BIT_SHIFT_FS_TBTT0_MB6INT                    6
#define BIT_FS_TBTT0_MB6INT                          ((u32)0x00000001 << BIT_SHIFT_FS_TBTT0_MB6INT)                    /*!<R/W1C 0  the interrupt from the exact TBTT time for P0 MBSSID6. */
#define BIT_SHIFT_FS_TBTT0_MB5INT                    5
#define BIT_FS_TBTT0_MB5INT                          ((u32)0x00000001 << BIT_SHIFT_FS_TBTT0_MB5INT)                    /*!<R/W1C 0  the interrupt from the exact TBTT time for P0 MBSSID5. */
#define BIT_SHIFT_FS_TBTT0_MB4INT                    4
#define BIT_FS_TBTT0_MB4INT                          ((u32)0x00000001 << BIT_SHIFT_FS_TBTT0_MB4INT)                    /*!<R/W1C 0  the interrupt from the exact TBTT time for P0 MBSSID4. */
#define BIT_SHIFT_FS_TBTT0_MB3INT                    3
#define BIT_FS_TBTT0_MB3INT                          ((u32)0x00000001 << BIT_SHIFT_FS_TBTT0_MB3INT)                    /*!<R/W1C 0  the interrupt from the exact TBTT time for P0 MBSSID3. */
#define BIT_SHIFT_FS_TBTT0_MB2INT                    2
#define BIT_FS_TBTT0_MB2INT                          ((u32)0x00000001 << BIT_SHIFT_FS_TBTT0_MB2INT)                    /*!<R/W1C 0  the interrupt from the exact TBTT time for P0 MBSSID2. */
#define BIT_SHIFT_FS_TBTT0_MB1INT                    1
#define BIT_FS_TBTT0_MB1INT                          ((u32)0x00000001 << BIT_SHIFT_FS_TBTT0_MB1INT)                    /*!<R/W1C 0  the interrupt from the exact TBTT time for P0 MBSSID1. */
#define BIT_SHIFT_FS_TBTT0_INT                       0
#define BIT_FS_TBTT0_INT                             ((u32)0x00000001 << BIT_SHIFT_FS_TBTT0_INT)                       /*!<R/W1C 0  the interrupt from the exact TBTT time for P0 MBSSID0. */

/* REG_FE3IMR 0x1128 */
#define BIT_SHIFT_FE1ISR_INT_EN                      31
#define BIT_FE1ISR_INT_EN                            ((u32)0x00000001 << BIT_SHIFT_FE1ISR_INT_EN)                      /*!<R/W 0  FE1ISR Indicator (FE1ISR and FE1IMR are true, this bit is set to 1) */
#define BIT_SHIFT_FE2ISR_INT_EN                      30
#define BIT_FE2ISR_INT_EN                            ((u32)0x00000001 << BIT_SHIFT_FE2ISR_INT_EN)                      /*!<R/W 0  FE2ISR Indicator (FE2ISR and FE2IMR are true, this bit is set to 1) */
#define BIT_SHIFT_FE4ISR_INT_EN                      29
#define BIT_FE4ISR_INT_EN                            ((u32)0x00000001 << BIT_SHIFT_FE4ISR_INT_EN)                      /*!<R/W 0  FE4ISR Indicator (FE4ISR and FE4IMR are true, this bit is set to 1) */
#define BIT_SHIFT_FE5ISR_INT_EN                      28
#define BIT_FE5ISR_INT_EN                            ((u32)0x00000001 << BIT_SHIFT_FE5ISR_INT_EN)                      /*!<R/W 0  FE5ISR Indicator (FE5ISR and FE5IMR are true, this bit is set to 1) */
#define BIT_SHIFT_FE6ISR_INT_EN                      27
#define BIT_FE6ISR_INT_EN                            ((u32)0x00000001 << BIT_SHIFT_FE6ISR_INT_EN)                      /*!<R/W 0  FE6ISR Indicator (FE6ISR and FE6IMR are true, this bit is set to 1) */
#define BIT_SHIFT_FISR_INT_EN                        26
#define BIT_FISR_INT_EN                              ((u32)0x00000001 << BIT_SHIFT_FISR_INT_EN)                        /*!<R/W 0  FISR Indicator (FISR and FIMR are true, this bit is set to 1) */
#define BIT_SHIFT_FISR1_INT_EN                       25
#define BIT_FISR1_INT_EN                             ((u32)0x00000001 << BIT_SHIFT_FISR1_INT_EN)                       /*!<R/W 0  FISR1 Indicator (FISR1 and FIMR1 are true, this bit is set to 1) */

#define BIT_SHIFT_FS_BCNELY2_AGGR_INT_EN             17
#define BIT_FS_BCNELY2_AGGR_INT_EN                   ((u32)0x00000001 << BIT_SHIFT_FS_BCNELY2_AGGR_INT_EN)             /*!<R/W 0  port 2 Beacon early aggregation interrupt */
#define BIT_SHIFT_FS_BCNELY1_AGGR_INT_EN             16
#define BIT_FS_BCNELY1_AGGR_INT_EN                   ((u32)0x00000001 << BIT_SHIFT_FS_BCNELY1_AGGR_INT_EN)             /*!<R/W 0  port 1 Beacon early aggregation interrupt */
#define BIT_SHIFT_FS_BCNELY0_AGGR_INT_EN             15
#define BIT_FS_BCNELY0_AGGR_INT_EN                   ((u32)0x00000001 << BIT_SHIFT_FS_BCNELY0_AGGR_INT_EN)             /*!<R/W 0  port 0 Beacon early aggregation interrupt */
#define BIT_SHIFT_FS_ON_SCK_INT_EN                   14
#define BIT_FS_ON_SCK_INT_EN                         ((u32)0x00000001 << BIT_SHIFT_FS_ON_SCK_INT_EN)                   /*!<R/W 0  This interrupt is issued at the time set by ALL DRVERLYINT register before TBTT time. */

#define BIT_SHIFT_FS_BCNERLY2_INT_EN                 9
#define BIT_FS_BCNERLY2_INT_EN                       ((u32)0x00000001 << BIT_SHIFT_FS_BCNERLY2_INT_EN)                 /*!<R/W 0  This interrupt is issued at the time set by DRVERLYINT register before TBTT2 time. */
#define BIT_SHIFT_FS_BCNERLY1_INT_EN                 8
#define BIT_FS_BCNERLY1_INT_EN                       ((u32)0x00000001 << BIT_SHIFT_FS_BCNERLY1_INT_EN)                 /*!<R/W 0  This interrupt is issued at the time set by DRVERLYINT register before TBTT1 time. */
#define BIT_SHIFT_FS_BCNERLY0_MB7INT_EN              7
#define BIT_FS_BCNERLY0_MB7INT_EN                    ((u32)0x00000001 << BIT_SHIFT_FS_BCNERLY0_MB7INT_EN)              /*!<R/W 0  This interrupt is issued at the time set by DRVERLYINTregister before TBTT0_MB7 time. */
#define BIT_SHIFT_FS_BCNERLY0_MB6INT_EN              6
#define BIT_FS_BCNERLY0_MB6INT_EN                    ((u32)0x00000001 << BIT_SHIFT_FS_BCNERLY0_MB6INT_EN)              /*!<R/W 0  This interrupt is issued at the time set by DRVERLYINT register before TBTT0_MB6 time. */
#define BIT_SHIFT_FS_BCNERLY0_MB5INT_EN              5
#define BIT_FS_BCNERLY0_MB5INT_EN                    ((u32)0x00000001 << BIT_SHIFT_FS_BCNERLY0_MB5INT_EN)              /*!<R/W 0  This interrupt is issued at the time set by DRVERLYINT register before TBTT0_MB5 time. */
#define BIT_SHIFT_FS_BCNERLY0_MB4INT_EN              4
#define BIT_FS_BCNERLY0_MB4INT_EN                    ((u32)0x00000001 << BIT_SHIFT_FS_BCNERLY0_MB4INT_EN)              /*!<R/W 0  This interrupt is issued at the time set by DRVERLYINTregister before TBTT0_MB4 time. */
#define BIT_SHIFT_FS_BCNERLY0_MB3INT_EN              3
#define BIT_FS_BCNERLY0_MB3INT_EN                    ((u32)0x00000001 << BIT_SHIFT_FS_BCNERLY0_MB3INT_EN)              /*!<R/W 0  This interrupt is issued at the time set by DRVERLYINT register before TBTT0_MB3 time. */
#define BIT_SHIFT_FS_BCNERLY0_MB2INT_EN              2
#define BIT_FS_BCNERLY0_MB2INT_EN                    ((u32)0x00000001 << BIT_SHIFT_FS_BCNERLY0_MB2INT_EN)              /*!<R/W 0  This interrupt is issued at the time set by DRVERLYINT register before TBTT0_MB2 time. */
#define BIT_SHIFT_FS_BCNERLY0_MB1INT_EN              1
#define BIT_FS_BCNERLY0_MB1INT_EN                    ((u32)0x00000001 << BIT_SHIFT_FS_BCNERLY0_MB1INT_EN)              /*!<R/W 0  This interrupt is issued at the time set by DRVERLYINTregister before TBTT0_MB1 time. */
#define BIT_SHIFT_FS_BCNERLY0_INT_EN                 0
#define BIT_FS_BCNERLY0_INT_EN                       ((u32)0x00000001 << BIT_SHIFT_FS_BCNERLY0_INT_EN)                 /*!<R/W 0  This interrupt is issued at the time set by DRVERLYINT register before TBTT0_MB0 time. */

/* REG_FE3ISR 0x112C */
#define BIT_SHIFT_FE1ISR_INT                         31
#define BIT_FE1ISR_INT                               ((u32)0x00000001 << BIT_SHIFT_FE1ISR_INT)                         /*!<R/W1C 0  FE1ISR Indicator (FE1ISR and FE1IMR are true, this bit is set to 1) */
#define BIT_SHIFT_FE2ISR_INT                         30
#define BIT_FE2ISR_INT                               ((u32)0x00000001 << BIT_SHIFT_FE2ISR_INT)                         /*!<R/W1C 0  FE2ISR Indicator (FE2ISR and FE2IMR are true, this bit is set to 1) */
#define BIT_SHIFT_FE4ISR_INT                         29
#define BIT_FE4ISR_INT                               ((u32)0x00000001 << BIT_SHIFT_FE4ISR_INT)                         /*!<R/W1C 0  FE4ISR Indicator (FE4ISR and FE4IMR are true, this bit is set to 1) */
#define BIT_SHIFT_FE5ISR_INT                         28
#define BIT_FE5ISR_INT                               ((u32)0x00000001 << BIT_SHIFT_FE5ISR_INT)                         /*!<R/W1C 0  FE5ISR Indicator (FE5ISR and FE5IMR are true, this bit is set to 1) */
#define BIT_SHIFT_FE6ISR_INT                         27
#define BIT_FE6ISR_INT                               ((u32)0x00000001 << BIT_SHIFT_FE6ISR_INT)                         /*!<R/W1C 0  FE6ISR Indicator (FE6ISR and FE6IMR are true, this bit is set to 1) */
#define BIT_SHIFT_FISR_INT                           26
#define BIT_FISR_INT                                 ((u32)0x00000001 << BIT_SHIFT_FISR_INT)                           /*!<R/W1C 0  FISR Indicator (FISR and FIMR are true, this bit is set to 1) */
#define BIT_SHIFT_FISR1_INT                          25
#define BIT_FISR1_INT                                ((u32)0x00000001 << BIT_SHIFT_FISR1_INT)                          /*!<R/W1C 0  FISR1 Indicator (FISR1 and FIMR1 are true, this bit is set to 1) */

#define BIT_SHIFT_FS_BCNELY2_AGGR_INT                17
#define BIT_FS_BCNELY2_AGGR_INT                      ((u32)0x00000001 << BIT_SHIFT_FS_BCNELY2_AGGR_INT)                /*!<R/W1C 0  port 2 Beacon early aggregation interrupt */
#define BIT_SHIFT_FS_BCNELY1_AGGR_INT                16
#define BIT_FS_BCNELY1_AGGR_INT                      ((u32)0x00000001 << BIT_SHIFT_FS_BCNELY1_AGGR_INT)                /*!<R/W1C 0  port 1 Beacon early aggregation interrupt */
#define BIT_SHIFT_FS_BCNELY0_AGGR_INT                15
#define BIT_FS_BCNELY0_AGGR_INT                      ((u32)0x00000001 << BIT_SHIFT_FS_BCNELY0_AGGR_INT)                /*!<R/W1C 0  port 0 Beacon early aggregation interrupt */
#define BIT_SHIFT_FS_ON_SCK_INT                      14
#define BIT_FS_ON_SCK_INT                            ((u32)0x00000001 << BIT_SHIFT_FS_ON_SCK_INT)                      /*!<R/W1C 0  This interrupt is issued at the time set by ALL DRVERLYINT register before TBTT time. */

#define BIT_SHIFT_FS_BCNERLY2_INT                    9
#define BIT_FS_BCNERLY2_INT                          ((u32)0x00000001 << BIT_SHIFT_FS_BCNERLY2_INT)                    /*!<R/W1C 0  This interrupt is issued at the time set by DRVERLYINT register before TBTT2 time. */
#define BIT_SHIFT_FS_BCNERLY1_INT                    8
#define BIT_FS_BCNERLY1_INT                          ((u32)0x00000001 << BIT_SHIFT_FS_BCNERLY1_INT)                    /*!<R/W1C 0  This interrupt is issued at the time set by DRVERLYINT register before TBTT1 time. */
#define BIT_SHIFT_FS_BCNERLY0_MB7INT                 7
#define BIT_FS_BCNERLY0_MB7INT                       ((u32)0x00000001 << BIT_SHIFT_FS_BCNERLY0_MB7INT)                 /*!<R/W1C 0  This interrupt is issued at the time set by DRVERLYINTregister before TBTT0_MB7 time. */
#define BIT_SHIFT_FS_BCNERLY0_MB6INT                 6
#define BIT_FS_BCNERLY0_MB6INT                       ((u32)0x00000001 << BIT_SHIFT_FS_BCNERLY0_MB6INT)                 /*!<R/W1C 0  This interrupt is issued at the time set by DRVERLYINT register before TBTT0_MB6 time. */
#define BIT_SHIFT_FS_BCNERLY0_MB5INT                 5
#define BIT_FS_BCNERLY0_MB5INT                       ((u32)0x00000001 << BIT_SHIFT_FS_BCNERLY0_MB5INT)                 /*!<R/W1C 0  This interrupt is issued at the time set by DRVERLYINT register before TBTT0_MB5 time. */
#define BIT_SHIFT_FS_BCNERLY0_MB4INT                 4
#define BIT_FS_BCNERLY0_MB4INT                       ((u32)0x00000001 << BIT_SHIFT_FS_BCNERLY0_MB4INT)                 /*!<R/W1C 0  This interrupt is issued at the time set by DRVERLYINTregister before TBTT0_MB4 time. */
#define BIT_SHIFT_FS_BCNERLY0_MB3INT                 3
#define BIT_FS_BCNERLY0_MB3INT                       ((u32)0x00000001 << BIT_SHIFT_FS_BCNERLY0_MB3INT)                 /*!<R/W1C 0  This interrupt is issued at the time set by DRVERLYINT register before TBTT0_MB3 time. */
#define BIT_SHIFT_FS_BCNERLY0_MB2INT                 2
#define BIT_FS_BCNERLY0_MB2INT                       ((u32)0x00000001 << BIT_SHIFT_FS_BCNERLY0_MB2INT)                 /*!<R/W1C 0  This interrupt is issued at the time set by DRVERLYINT register before TBTT0_MB2 time. */
#define BIT_SHIFT_FS_BCNERLY0_MB1INT                 1
#define BIT_FS_BCNERLY0_MB1INT                       ((u32)0x00000001 << BIT_SHIFT_FS_BCNERLY0_MB1INT)                 /*!<R/W1C 0  This interrupt is issued at the time set by DRVERLYINTregister before TBTT0_MB1 time. */
#define BIT_SHIFT_FS_BCNERLY0_INT                    0
#define BIT_FS_BCNERLY0_INT                          ((u32)0x00000001 << BIT_SHIFT_FS_BCNERLY0_INT)                    /*!<R/W1C 0  This interrupt is issued at the time set by DRVERLYINT register before TBTT0_MB0 time. */

/* REG_FE4IMR 0x1130 */
#define BIT_SHIFT_FS_PCIE_BCNDMAERR_INT_EN           31
#define BIT_FS_PCIE_BCNDMAERR_INT_EN                 ((u32)0x00000001 << BIT_SHIFT_FS_PCIE_BCNDMAERR_INT_EN)           /*!<R/W 0  PCIE BCN DMA error interrupt */
#define BIT_SHIFT_FS_BCNDMA1_INT_EN                  30
#define BIT_FS_BCNDMA1_INT_EN                        ((u32)0x00000001 << BIT_SHIFT_FS_BCNDMA1_INT_EN)                  /*!<R/W 0  When BCNDMA interval arrives before TBTT1, this interrupt informs MCU to prepare related beacon tasks. */
#define BIT_SHIFT_FS_BCNDMA0_MB7_INT_EN              29
#define BIT_FS_BCNDMA0_MB7_INT_EN                    ((u32)0x00000001 << BIT_SHIFT_FS_BCNDMA0_MB7_INT_EN)              /*!<R/W 0  When BCNDMA interval arrives before TBTT0_MB7, this interrupt informs MCU to prepare related beacon tasks. */
#define BIT_SHIFT_FS_BCNDMA0_MB6_INT_EN              28
#define BIT_FS_BCNDMA0_MB6_INT_EN                    ((u32)0x00000001 << BIT_SHIFT_FS_BCNDMA0_MB6_INT_EN)              /*!<R/W 0  When BCNDMA interval arrives before TBTT0_MB6, this interrupt informs MCU to prepare related beacon tasks. */
#define BIT_SHIFT_FS_BCNDMA0_MB5_INT_EN              27
#define BIT_FS_BCNDMA0_MB5_INT_EN                    ((u32)0x00000001 << BIT_SHIFT_FS_BCNDMA0_MB5_INT_EN)              /*!<R/W 0  When BCNDMA interval arrives before TBTT0_MB5, this interrupt informs MCU to prepare related beacon tasks. */
#define BIT_SHIFT_FS_BCNDMA0_MB4_INT_EN              26
#define BIT_FS_BCNDMA0_MB4_INT_EN                    ((u32)0x00000001 << BIT_SHIFT_FS_BCNDMA0_MB4_INT_EN)              /*!<R/W 0  When BCNDMA interval arrives before TBTT0_MB4, this interrupt informs MCU to prepare related beacon tasks. */
#define BIT_SHIFT_FS_BCNDMA0_MB3_INT_EN              25
#define BIT_FS_BCNDMA0_MB3_INT_EN                    ((u32)0x00000001 << BIT_SHIFT_FS_BCNDMA0_MB3_INT_EN)              /*!<R/W 0  When BCNDMA interval arrives before TBTT0_MB3, this interrupt informs MCU to prepare related beacon tasks. */
#define BIT_SHIFT_FS_BCNDMA0_MB2_INT_EN              24
#define BIT_FS_BCNDMA0_MB2_INT_EN                    ((u32)0x00000001 << BIT_SHIFT_FS_BCNDMA0_MB2_INT_EN)              /*!<R/W 0  When BCNDMA interval arrives before TBTT0_MB2, this interrupt informs MCU to prepare related beacon tasks. */
#define BIT_SHIFT_FS_BCNDMA0_MB1_INT_EN              23
#define BIT_FS_BCNDMA0_MB1_INT_EN                    ((u32)0x00000001 << BIT_SHIFT_FS_BCNDMA0_MB1_INT_EN)              /*!<R/W 0  When BCNDMA interval arrives before TBTT0_MB1, this interrupt informs MCU to prepare related beacon tasks. */
#define BIT_SHIFT_FS_BCNDMA0_INT_EN                  22
#define BIT_FS_BCNDMA0_INT_EN                        ((u32)0x00000001 << BIT_SHIFT_FS_BCNDMA0_INT_EN)                  /*!<R/W 0  When BCNDMA interval arrives before TBTT0_MB0, this interrupt informs MCU to prepare related beacon tasks. */
#define BIT_SHIFT_FS_BCNDMA2_INT_EN                  21
#define BIT_FS_BCNDMA2_INT_EN                        ((u32)0x00000001 << BIT_SHIFT_FS_BCNDMA2_INT_EN)                  /*!<R/W 0  When BCNDMA interval arrives before TBTT2, this interrupt informs MCU to prepare related beacon tasks. */

#define BIT_SHIFT_PORT0_PKTIN_INT_EN                 17
#define BIT_PORT0_PKTIN_INT_EN                       ((u32)0x00000001 << BIT_SHIFT_PORT0_PKTIN_INT_EN)                 /*!<R/W 0  port 0 packet assign to queue interrupt */
#define BIT_SHIFT_PORT1_PKTIN_INT_EN                 16
#define BIT_PORT1_PKTIN_INT_EN                       ((u32)0x00000001 << BIT_SHIFT_PORT1_PKTIN_INT_EN)                 /*!<R/W 0  port 1 packet assign to queue interrupt */
#define BIT_SHIFT_PORT1_RXUCMD0_OK_INT_EN            3
#define BIT_PORT1_RXUCMD0_OK_INT_EN                  ((u32)0x00000001 << BIT_SHIFT_PORT1_RXUCMD0_OK_INT_EN)            /*!<R/W 0  port 1 rx unicast packet with more data = 0 ok interrupt */
#define BIT_SHIFT_PORT1_RXUCMD1_OK_INT_EN            2
#define BIT_PORT1_RXUCMD1_OK_INT_EN                  ((u32)0x00000001 << BIT_SHIFT_PORT1_RXUCMD1_OK_INT_EN)            /*!<R/W 0  port 1 rx unicast packet with more data = 1 ok interrupt */
#define BIT_SHIFT_PORT1_RXBCMD0_OK_INT_EN            1
#define BIT_PORT1_RXBCMD0_OK_INT_EN                  ((u32)0x00000001 << BIT_SHIFT_PORT1_RXBCMD0_OK_INT_EN)            /*!<R/W 0  port 1 rx broadcast packet with more data = 0 ok interrupt */
#define BIT_SHIFT_PORT1_RXBCMD1_OK_INT_EN            0
#define BIT_PORT1_RXBCMD1_OK_INT_EN                  ((u32)0x00000001 << BIT_SHIFT_PORT1_RXBCMD1_OK_INT_EN)            /*!<R/W 0  port 1 rx broadcast packet with more data = 1 ok interrupt */

/* REG_FE4ISR 0x1134 */
#define BIT_SHIFT_FS_PCIE_BCNDMAERR_INT              31
#define BIT_FS_PCIE_BCNDMAERR_INT                    ((u32)0x00000001 << BIT_SHIFT_FS_PCIE_BCNDMAERR_INT)              /*!<R/WIC 0  PCIE BCN DMA error interrupt */
#define BIT_SHIFT_FS_BCNDMA1_INT                     30
#define BIT_FS_BCNDMA1_INT                           ((u32)0x00000001 << BIT_SHIFT_FS_BCNDMA1_INT)                     /*!<R/WIC 0  When BCNDMA interval arrives before TBTT1, this interrupt informs MCU to prepare related beacon tasks. */
#define BIT_SHIFT_FS_BCNDMA0_MB7_INT                 29
#define BIT_FS_BCNDMA0_MB7_INT                       ((u32)0x00000001 << BIT_SHIFT_FS_BCNDMA0_MB7_INT)                 /*!<R/WIC 0  When BCNDMA interval arrives before TBTT0_MB7, this interrupt informs MCU to prepare related beacon tasks. */
#define BIT_SHIFT_FS_BCNDMA0_MB6_INT                 28
#define BIT_FS_BCNDMA0_MB6_INT                       ((u32)0x00000001 << BIT_SHIFT_FS_BCNDMA0_MB6_INT)                 /*!<R/WIC 0  When BCNDMA interval arrives before TBTT0_MB6, this interrupt informs MCU to prepare related beacon tasks. */
#define BIT_SHIFT_FS_BCNDMA0_MB5_INT                 27
#define BIT_FS_BCNDMA0_MB5_INT                       ((u32)0x00000001 << BIT_SHIFT_FS_BCNDMA0_MB5_INT)                 /*!<R/WIC 0  When BCNDMA interval arrives before TBTT0_MB5, this interrupt informs MCU to prepare related beacon tasks. */
#define BIT_SHIFT_FS_BCNDMA0_MB4_INT                 26
#define BIT_FS_BCNDMA0_MB4_INT                       ((u32)0x00000001 << BIT_SHIFT_FS_BCNDMA0_MB4_INT)                 /*!<R/WIC 0  When BCNDMA interval arrives before TBTT0_MB4, this interrupt informs MCU to prepare related beacon tasks. */
#define BIT_SHIFT_FS_BCNDMA0_MB3_INT                 25
#define BIT_FS_BCNDMA0_MB3_INT                       ((u32)0x00000001 << BIT_SHIFT_FS_BCNDMA0_MB3_INT)                 /*!<R/WIC 0  When BCNDMA interval arrives before TBTT0_MB3, this interrupt informs MCU to prepare related beacon tasks. */
#define BIT_SHIFT_FS_BCNDMA0_MB2_INT                 24
#define BIT_FS_BCNDMA0_MB2_INT                       ((u32)0x00000001 << BIT_SHIFT_FS_BCNDMA0_MB2_INT)                 /*!<R/WIC 0  When BCNDMA interval arrives before TBTT0_MB2, this interrupt informs MCU to prepare related beacon tasks. */
#define BIT_SHIFT_FS_BCNDMA0_MB1_INT                 23
#define BIT_FS_BCNDMA0_MB1_INT                       ((u32)0x00000001 << BIT_SHIFT_FS_BCNDMA0_MB1_INT)                 /*!<R/WIC 0  When BCNDMA interval arrives before TBTT0_MB1, this interrupt informs MCU to prepare related beacon tasks. */
#define BIT_SHIFT_FS_BCNDMA0_INT                     22
#define BIT_FS_BCNDMA0_INT                           ((u32)0x00000001 << BIT_SHIFT_FS_BCNDMA0_INT)                     /*!<R/WIC 0  When BCNDMA interval arrives before TBTT0_MB0, this interrupt informs MCU to prepare related beacon tasks. */
#define BIT_SHIFT_FS_BCNDMA2_INT                     21
#define BIT_FS_BCNDMA2_INT                           ((u32)0x00000001 << BIT_SHIFT_FS_BCNDMA2_INT)                     /*!<R/WIC 0  When BCNDMA interval arrives before TBTT2, this interrupt informs MCU to prepare related beacon tasks. */

#define BIT_SHIFT_PORT0_PKTIN_INT                    17
#define BIT_PORT0_PKTIN_INT                          ((u32)0x00000001 << BIT_SHIFT_PORT0_PKTIN_INT)                    /*!<R/WIC 0  port 0 packet assign to queue interrupt */
#define BIT_SHIFT_PORT1_PKTIN_INT                    16
#define BIT_PORT1_PKTIN_INT                          ((u32)0x00000001 << BIT_SHIFT_PORT1_PKTIN_INT)                    /*!<R/WIC 0  port 1 packet assign to queue interrupt */
#define BIT_SHIFT_PORT1_RXUCMD0_OK_INT               3
#define BIT_PORT1_RXUCMD0_OK_INT                     ((u32)0x00000001 << BIT_SHIFT_PORT1_RXUCMD0_OK_INT)               /*!<R/WIC 0  port 1 rx unicast packet with more data = 0 ok interrupt */
#define BIT_SHIFT_PORT1_RXUCMD1_OK_INT               2
#define BIT_PORT1_RXUCMD1_OK_INT                     ((u32)0x00000001 << BIT_SHIFT_PORT1_RXUCMD1_OK_INT)               /*!<R/WIC 0  port 1 rx unicast packet with more data = 1 ok interrupt */
#define BIT_SHIFT_PORT1_RXBCMD0_OK_INT               1
#define BIT_PORT1_RXBCMD0_OK_INT                     ((u32)0x00000001 << BIT_SHIFT_PORT1_RXBCMD0_OK_INT)               /*!<R/WIC 0  port 1 rx broadcast packet with more data = 0 ok interrupt */
#define BIT_SHIFT_PORT1_RXBCMD1_OK_INT               0
#define BIT_PORT1_RXBCMD1_OK_INT                     ((u32)0x00000001 << BIT_SHIFT_PORT1_RXBCMD1_OK_INT)               /*!<R/WIC 0  port 1 rx broadcast packet with more data = 1 ok interrupt */

/* REG_FT1IMR 0x1138 */

#define BIT_SHIFT_FS_RXFTMREQ_INT_EN                 28
#define BIT_FS_RXFTMREQ_INT_EN                       ((u32)0x00000001 << BIT_SHIFT_FS_RXFTMREQ_INT_EN)                 /*!<R/W 0  If BIT_RXFTMREQ_INT_EN =1. When HW receive FTMREQ packet, it will generate interrupt to firmware. */
#define BIT_SHIFT_FS_RXFTM_INT_EN                    27
#define BIT_FS_RXFTM_INT_EN                          ((u32)0x00000001 << BIT_SHIFT_FS_RXFTM_INT_EN)                    /*!<R/W 0  If BIT_RXFTM_INT_EN =1. When HW receive FTM and transmit ACK frame successfully, the BB generate FTM report. It will generate interrupt to firmware. */
#define BIT_SHIFT_FS_TXFTM_INT_EN                    26
#define BIT_FS_TXFTM_INT_EN                          ((u32)0x00000001 << BIT_SHIFT_FS_TXFTM_INT_EN)                    /*!<R/W 0  If BIT_TXFTM_INT_EN =1. When HW transmit FTM and receive ACK frame successfully, the BB generate FTM report. It will generate interrupt to firmware. */
#define BIT_SHIFT_FS_RXTMREQ_INT_EN                  25
#define BIT_FS_RXTMREQ_INT_EN                        ((u32)0x00000001 << BIT_SHIFT_FS_RXTMREQ_INT_EN)                  /*!<R/W 0  If BIT_RXTMREQ_INT_EN =1. When HW receive TMREQ packet, it will generate interrupt to firmware. */
#define BIT_SHIFT_FS_RXTM_INT_EN                     24
#define BIT_FS_RXTM_INT_EN                           ((u32)0x00000001 << BIT_SHIFT_FS_RXTM_INT_EN)                     /*!<R/W 0  If BIT_RXTM_INT_EN =1. When HW receive TM and transmit ACK frame successfully. It will generate interrupt to firmware. */
#define BIT_SHIFT_FS_TXTM_INT_EN                     23
#define BIT_FS_TXTM_INT_EN                           ((u32)0x00000001 << BIT_SHIFT_FS_TXTM_INT_EN)                     /*!<R/W 0  If BIT_TXTM_INT_EN =1. When HW transmit TM and receive ACK frame successfully. It will generate interrupt to firmware. */

#define BIT_SHIFT_FS_CTWEND2_INT_EN                  17
#define BIT_FS_CTWEND2_INT_EN                        ((u32)0x00000001 << BIT_SHIFT_FS_CTWEND2_INT_EN)                  /*!<R/W 0  CTWindow End NOA2 interrupt. */
#define BIT_SHIFT_FS_CTWEND1_INT_EN                  16
#define BIT_FS_CTWEND1_INT_EN                        ((u32)0x00000001 << BIT_SHIFT_FS_CTWEND1_INT_EN)                  /*!<R/W 0  CTWindow End NOA1 interrupt. */
#define BIT_SHIFT_FS_CTWEND0_INT_EN                  15
#define BIT_FS_CTWEND0_INT_EN                        ((u32)0x00000001 << BIT_SHIFT_FS_CTWEND0_INT_EN)                  /*!<R/W 0  CTWindow End NOA0 interrupt. */
#define BIT_SHIFT_FS_TX_NULL1_P0_INT_EN              14
#define BIT_FS_TX_NULL1_P0_INT_EN                    ((u32)0x00000001 << BIT_SHIFT_FS_TX_NULL1_P0_INT_EN)              /*!<R/W 0  TX null 1 packet done interrupt */
#define BIT_SHIFT_FS_TX_NULL0_P0_INT_EN              13
#define BIT_FS_TX_NULL0_P0_INT_EN                    ((u32)0x00000001 << BIT_SHIFT_FS_TX_NULL0_P0_INT_EN)              /*!<R/W 0  TX null 0 packet done interrupt */
#define BIT_SHIFT_FS_NOA0_TSF_BIT32_INT_EN           12
#define BIT_FS_NOA0_TSF_BIT32_INT_EN                 ((u32)0x00000001 << BIT_SHIFT_FS_NOA0_TSF_BIT32_INT_EN)           /*!<R/W 0  NOA unit0 TSFT bit 32 toggle interrupt */
#define BIT_SHIFT_FS_P2P_RFON2_INT_EN                11
#define BIT_FS_P2P_RFON2_INT_EN                      ((u32)0x00000001 << BIT_SHIFT_FS_P2P_RFON2_INT_EN)                /*!<R/W 0  P2P NoA RF on time indication 2 interrupt */
#define BIT_SHIFT_FS_P2P_RFOFF2_INT_EN               10
#define BIT_FS_P2P_RFOFF2_INT_EN                     ((u32)0x00000001 << BIT_SHIFT_FS_P2P_RFOFF2_INT_EN)               /*!<R/W 0  P2P NoA RF off time indication 2 interrupt */
#define BIT_SHIFT_FS_P2P_RFON1_INT_EN                9
#define BIT_FS_P2P_RFON1_INT_EN                      ((u32)0x00000001 << BIT_SHIFT_FS_P2P_RFON1_INT_EN)                /*!<R/W 0  P2P NoA RF on time indication 1 interrupt */
#define BIT_SHIFT_FS_P2P_RFOFF1_INT_EN               8
#define BIT_FS_P2P_RFOFF1_INT_EN                     ((u32)0x00000001 << BIT_SHIFT_FS_P2P_RFOFF1_INT_EN)               /*!<R/W 0  P2P NoA RF off time indication 1 interrupt */
#define BIT_SHIFT_FS_P2P_RFON0_INT_EN                7
#define BIT_FS_P2P_RFON0_INT_EN                      ((u32)0x00000001 << BIT_SHIFT_FS_P2P_RFON0_INT_EN)                /*!<R/W 0  P2P NoA RF on time indication 0 interrupt */
#define BIT_SHIFT_FS_P2P_RFOFF0_INT_EN               6
#define BIT_FS_P2P_RFOFF0_INT_EN                     ((u32)0x00000001 << BIT_SHIFT_FS_P2P_RFOFF0_INT_EN)               /*!<R/W 0  P2P NoA RF off time indication 0 interrupt */
#define BIT_SHIFT_FS_RX_UAPSDMD1_EN                  5
#define BIT_FS_RX_UAPSDMD1_EN                        ((u32)0x00000001 << BIT_SHIFT_FS_RX_UAPSDMD1_EN)                     /*!<R/W 0  Setting this bit indicates Rx pkt is matched with one of below: 1.) QoS Unicast data frame with MD=1, UAPSD=0 2.) NonQoS Unicast data frame with MD=1 */
#define BIT_SHIFT_FS_RX_UAPSDMD0_EN                  4
#define BIT_FS_RX_UAPSDMD0_EN                        ((u32)0x00000001 << BIT_SHIFT_FS_RX_UAPSDMD0_EN)                     /*!<R/W 0  Setting this bit indicates Rx pkt is matched with one of below: 1.) QoS Unicast data frame with MD=0, UAPSD=0 2.) NonQoS Unicast data frame with MD=0 */
#define BIT_SHIFT_FS_TRIGGER_PKT_EN                  3
#define BIT_FS_TRIGGER_PKT_EN                        ((u32)0x00000001 << BIT_SHIFT_FS_TRIGGER_PKT_EN)                     /*!<R/W 0  tx TRIGGER_PKT interrupt */
#define BIT_SHIFT_FS_EOSP_INT_EN                     2
#define BIT_FS_EOSP_INT_EN                           ((u32)0x00000001 << BIT_SHIFT_FS_EOSP_INT_EN)                     /*!<R/W 0  EOSP_INT interrupt mask */

/* REG_FT1ISR 0x113C */

#define BIT_SHIFT_FS_RXFTMREQ_INT                    28
#define BIT_FS_RXFTMREQ_INT                          ((u32)0x00000001 << BIT_SHIFT_FS_RXFTMREQ_INT)                    /*!<R/W1C 0  If BIT_RXFTMREQ_INT_EN =1. When HW receive FTMREQ packet, it will generate interrupt to firmware. */
#define BIT_SHIFT_FS_RXFTM_INT                       27
#define BIT_FS_RXFTM_INT                             ((u32)0x00000001 << BIT_SHIFT_FS_RXFTM_INT)                       /*!<R/W1C 0  If BIT_RXFTM_INT_EN =1. When HW receive FTM and transmit ACK frame successfully, the BB generate FTM report. It will generate interrupt to firmware. */
#define BIT_SHIFT_FS_TXFTM_INT                       26
#define BIT_FS_TXFTM_INT                             ((u32)0x00000001 << BIT_SHIFT_FS_TXFTM_INT)                       /*!<R/W1C 0  If BIT_TXFTM_INT_EN =1. When HW transmit FTM and receive ACK frame successfully, the BB generate FTM report. It will generate interrupt to firmware. */
#define BIT_SHIFT_FS_RXTMREQ_INT                     25
#define BIT_FS_RXTMREQ_INT                           ((u32)0x00000001 << BIT_SHIFT_FS_RXTMREQ_INT)                     /*!<R/W1C 0  If BIT_RXTMREQ_INT_EN =1. When HW receive TMREQ packet, it will generate interrupt to firmware. */
#define BIT_SHIFT_FS_RXTM_INT                        24
#define BIT_FS_RXTM_INT                              ((u32)0x00000001 << BIT_SHIFT_FS_RXTM_INT)                        /*!<R/W1C 0  If BIT_RXTM_INT_EN =1. When HW receive TM and transmit ACK frame successfully. It will generate interrupt to firmware. */
#define BIT_SHIFT_FS_TXTM_INT                        23
#define BIT_FS_TXTM_INT                              ((u32)0x00000001 << BIT_SHIFT_FS_TXTM_INT)                        /*!<R/W1C 0  If BIT_TXTM_INT_EN =1. When HW transmit TM and receive ACK frame successfully. It will generate interrupt to firmware. */

#define BIT_SHIFT_FS_CTWEND2_INT                     17
#define BIT_FS_CTWEND2_INT                           ((u32)0x00000001 << BIT_SHIFT_FS_CTWEND2_INT)                     /*!<R/W1C 0  CTWindow End NOA2 interrupt. */
#define BIT_SHIFT_FS_CTWEND1_INT                     16
#define BIT_FS_CTWEND1_INT                           ((u32)0x00000001 << BIT_SHIFT_FS_CTWEND1_INT)                     /*!<R/W1C 0  CTWindow End NOA1 interrupt. */
#define BIT_SHIFT_FS_CTWEND0_INT                     15
#define BIT_FS_CTWEND0_INT                           ((u32)0x00000001 << BIT_SHIFT_FS_CTWEND0_INT)                     /*!<R/W1C 0  CTWindow End NOA0 interrupt. */
#define BIT_SHIFT_FS_TX_NULL1_P0_INT                 14
#define BIT_FS_TX_NULL1_P0_INT                       ((u32)0x00000001 << BIT_SHIFT_FS_TX_NULL1_P0_INT)                 /*!<R/W1C 0  TX null 1 packet done interrupt */
#define BIT_SHIFT_FS_TX_NULL0_P0_INT                 13
#define BIT_FS_TX_NULL0_P0_INT                       ((u32)0x00000001 << BIT_SHIFT_FS_TX_NULL0_P0_INT)                 /*!<R/W1C 0  TX null 0 packet done interrupt */
#define BIT_SHIFT_FS_NOA0_TSF_BIT32_INT              12
#define BIT_FS_NOA0_TSF_BIT32_INT                    ((u32)0x00000001 << BIT_SHIFT_FS_NOA0_TSF_BIT32_INT)              /*!<R/W1C 0  NOA unit0 TSFT bit 32 toggle interrupt */
#define BIT_SHIFT_FS_P2P_RFON2_INT                   11
#define BIT_FS_P2P_RFON2_INT                         ((u32)0x00000001 << BIT_SHIFT_FS_P2P_RFON2_INT)                   /*!<R/W1C 0  P2P NoA RF on time indication 2 interrupt */
#define BIT_SHIFT_FS_P2P_RFOFF2_INT                  10
#define BIT_FS_P2P_RFOFF2_INT                        ((u32)0x00000001 << BIT_SHIFT_FS_P2P_RFOFF2_INT)                  /*!<R/W1C 0  P2P NoA RF off time indication 2 interrupt */
#define BIT_SHIFT_FS_P2P_RFON1_INT                   9
#define BIT_FS_P2P_RFON1_INT                         ((u32)0x00000001 << BIT_SHIFT_FS_P2P_RFON1_INT)                   /*!<R/W1C 0  P2P NoA RF on time indication 1 interrupt */
#define BIT_SHIFT_FS_P2P_RFOFF1_INT                  8
#define BIT_FS_P2P_RFOFF1_INT                        ((u32)0x00000001 << BIT_SHIFT_FS_P2P_RFOFF1_INT)                  /*!<R/W1C 0  P2P NoA RF off time indication 1 interrupt */
#define BIT_SHIFT_FS_P2P_RFON0_INT                   7
#define BIT_FS_P2P_RFON0_INT                         ((u32)0x00000001 << BIT_SHIFT_FS_P2P_RFON0_INT)                   /*!<R/W1C 0  P2P NoA RF on time indication 0 interrupt */
#define BIT_SHIFT_FS_P2P_RFOFF0_INT                  6
#define BIT_FS_P2P_RFOFF0_INT                        ((u32)0x00000001 << BIT_SHIFT_FS_P2P_RFOFF0_INT)                  /*!<R/W1C 0  P2P NoA RF off time indication 0 interrupt */
#define BIT_SHIFT_FS_RX_UAPSDMD1                     5
#define BIT_FS_RX_UAPSDMD1                           ((u32)0x00000001 << BIT_SHIFT_FS_RX_UAPSDMD1)                     /*!<R/W1C 0  Setting this bit indicates Rx pkt is matched with one of below: 1.) QoS Unicast data frame with MD=1, UAPSD=0 2.) NonQoS Unicast data frame with MD=1 */
#define BIT_SHIFT_FS_RX_UAPSDMD0                     4
#define BIT_FS_RX_UAPSDMD0                           ((u32)0x00000001 << BIT_SHIFT_FS_RX_UAPSDMD0)                     /*!<R/W1C 0  Setting this bit indicates Rx pkt is matched with one of below: 1.) QoS Unicast data frame with MD=0, UAPSD=0 2.) NonQoS Unicast data frame with MD=0 */
#define BIT_SHIFT_FS_TRIGGER_PKT                     3
#define BIT_FS_TRIGGER_PKT                           ((u32)0x00000001 << BIT_SHIFT_FS_TRIGGER_PKT)                     /*!<R/W1C 0  tx TRIGGER_PKT interrupt */
#define BIT_SHIFT_FS_EOSP_INT                        2
#define BIT_FS_EOSP_INT                              ((u32)0x00000001 << BIT_SHIFT_FS_EOSP_INT)                        /*!<R/W1C 0  EOSP_INT interrupt mask */

/* REG_FE5IMR 0x1168 */
#define BIT_SHIFT_FS_ZIGBEE2WLAN_MAILBOX             31
#define BIT_FS_ZIGBEE2WLAN_MAILBOX                   ((u32)0x00000001 << BIT_SHIFT_FS_ZIGBEE2WLAN_MAILBOX)             /*!<R/W1C 0  Mailbox INT from ZIGBEE CPU */

#define BIT_SHIFT_FS_EXT_INTF4_EN_MSK                5
#define BIT_FS_EXT_INTF4_EN_MSK                      ((u32)0x00000001 << BIT_SHIFT_FS_EXT_INTF4_EN_MSK)                /*!<R/W1C 0  external bt mailbox int,mailbox_outempty_int| mailbox_in_rdy_int */
#define BIT_SHIFT_FS_GNT_BT_BB_FALL_MSK              4
#define BIT_FS_GNT_BT_BB_FALL_MSK                    ((u32)0x00000001 << BIT_SHIFT_FS_GNT_BT_BB_FALL_MSK)              /*!<R/W1C 0  Mailbox INT from btcoex */
#define BIT_SHIFT_FS_GNT_BT_BB_RISE_MSK              3
#define BIT_FS_GNT_BT_BB_RISE_MSK                    ((u32)0x00000001 << BIT_SHIFT_FS_GNT_BT_BB_RISE_MSK)              /*!<R/W1C 0  Mailbox INT from btcoex */
#define BIT_SHIFT_FS_BT2WL_STS_INTPS_MSK             2
#define BIT_FS_BT2WL_STS_INTPS_MSK                   ((u32)0x00000001 << BIT_SHIFT_FS_BT2WL_STS_INTPS_MSK)             /*!<R/W1C 0  Mailbox INT from ext BT */
#define BIT_SHIFT_FS_BT_MAILBOX_MSK                  1
#define BIT_FS_BT_MAILBOX_MSK                        ((u32)0x00000001 << BIT_SHIFT_FS_BT_MAILBOX_MSK)                  /*!<R/W1C 0  Mailbox INT from ext BT */
#define BIT_SHIFT_FS_INTF4_EN_MSK                    0
#define BIT_FS_INTF4_EN_MSK                          ((u32)0x00000001 << BIT_SHIFT_FS_INTF4_EN_MSK)                    /*!<R/W1C 0  bt mailbox int,mailbox_outempty_int| mailbox_in_rdy_int */

/* REG_FE5ISR 0x116C */
#define BIT_SHIFT_FS_ZIGBEE2WLAN_MAILBOX             31
#define BIT_FS_ZIGBEE2WLAN_MAILBOX                   ((u32)0x00000001 << BIT_SHIFT_FS_ZIGBEE2WLAN_MAILBOX)             /*!<R/W1C 0  Mailbox INT from ZIGBEE CPU */

#define BIT_SHIFT_FS_EXT_INT4_EN                     5
#define BIT_FS_EXT_INT4_EN                           ((u32)0x00000001 << BIT_SHIFT_FS_EXT_INT4_EN)                     /*!<R/W1C 0  external bt mailbox int,mailbox_outempty_int| mailbox_in_rdy_int */
#define BIT_SHIFT_FS_GNT_BT_BB_FALL                  4
#define BIT_FS_GNT_BT_BB_FALL                        ((u32)0x00000001 << BIT_SHIFT_FS_GNT_BT_BB_FALL)                  /*!<R/W1C 0  Mailbox INT from btcoex */
#define BIT_SHIFT_FS_GNT_BT_BB_RISE                  3
#define BIT_FS_GNT_BT_BB_RISE                        ((u32)0x00000001 << BIT_SHIFT_FS_GNT_BT_BB_RISE)                  /*!<R/W1C 0  Mailbox INT from btcoex */
#define BIT_SHIFT_FS_BT2WL_STS_INT                   2
#define BIT_FS_BT2WL_STS_INT                         ((u32)0x00000001 << BIT_SHIFT_FS_BT2WL_STS_INT)                   /*!<R/W1C 0  Mailbox INT from ext BT */
#define BIT_SHIFT_FS_BT_MAILBOX                      1
#define BIT_FS_BT_MAILBOX                            ((u32)0x00000001 << BIT_SHIFT_FS_BT_MAILBOX)                      /*!<R/W1C 0  Mailbox INT from ext BT */
#define BIT_SHIFT_FS_INTF4_EN                        0
#define BIT_FS_INTF4_EN                              ((u32)0x00000001 << BIT_SHIFT_FS_INTF4_EN)                        /*!<R/W1C 0  bt mailbox int,mailbox_outempty_int| mailbox_in_rdy_int */


/* REG_EXT QUEUE REGISTER 0x117C */
#define BIT_SHIFT_TXBUF_WKCAM_OFFSET                 3
#define BIT_MASK_TXBUF_WKCAM_OFFSET                  ((u32)0x00001FFF << BIT_SHIFT_TXBUF_WKCAM_OFFSET)                 /*!<R/W 0  the offset of WOL pattern stored in txpktbuffer, unit is 8byte */
#define BIT_SHIFT_H2CQ_PRI                           0
#define BIT_MASK_H2CQ_PRI                            ((u32)0x00000003 << BIT_SHIFT_H2CQ_PRI)                           /*!<R/W 0   */

/* REG_BT_MAILBOX_OUT_LOW 0x1190 */
#define BIT_SHIFT_MAILBOX_DATA_51TO81_L              0
#define BIT_MASK_MAILBOX_DATA_51TO81_L               ((u32)0xFFFFFFFF << BIT_SHIFT_MAILBOX_DATA_51TO81_L)              /*!<R/W 0   */

/* REG_BT_MAILBOX_OUT_HIGH 0x1194 */
#define BIT_SHIFT_MAILBOX_DATA_51TO81_H              0
#define BIT_MASK_MAILBOX_DATA_51TO81_H               ((u32)0xFFFFFFFF << BIT_SHIFT_MAILBOX_DATA_51TO81_H)              /*!<R/W 0   */

/* REG_BT_MAILBOX_CONTROL 0x1198 */
#define BIT_SHIFT_MAILBOX_IN_RDY_INTEN               17
#define BIT_MAILBOX_IN_RDY_INTEN                     ((u32)0x00000001 << BIT_SHIFT_MAILBOX_IN_RDY_INTEN)               /*!<R/W 0   */
#define BIT_SHIFT_MAILBOX_IN_RDY                     16
#define BIT_MAILBOX_IN_RDY                           ((u32)0x00000001 << BIT_SHIFT_MAILBOX_IN_RDY)                     /*!<R/W 0   */
#define BIT_SHIFT_MAILBOX_OUTEMPTY_INTEN             1
#define BIT_MAILBOX_OUTEMPTY_INTEN                   ((u32)0x00000001 << BIT_SHIFT_MAILBOX_OUTEMPTY_INTEN)             /*!<R/W 0   */
#define BIT_SHIFT_MAILBOX_OUT_VLD                    0
#define BIT_MAILBOX_OUT_VLD                          ((u32)0x00000001 << BIT_SHIFT_MAILBOX_OUT_VLD)                    /*!<R/W 0   */

/* REG_BT_MAILBOX_IN_LOW 0x119C */
#define BIT_SHIFT_MAILBOX_DATA_81TO51_L              0
#define BIT_MASK_MAILBOX_DATA_81TO51_L               ((u32)0xFFFFFFFF << BIT_SHIFT_MAILBOX_DATA_81TO51_L)              /*!<R 0   */

/* REG_BT_MAILBOX_IN_HIGH 0x11A0 */
#define BIT_SHIFT_MAILBOX_DATA_51TO81_H              0
#define BIT_MASK_MAILBOX_DATA_51TO81_H               ((u32)0xFFFFFFFF << BIT_SHIFT_MAILBOX_DATA_51TO81_H)              /*!<R/W 0   */

/* REG_EXT_BT_MAILBOX_OUT_LOW 0x11A4 */
#define BIT_SHIFT_EXT_MAILBOX_DATA_51TO81_L          0
#define BIT_MASK_EXT_MAILBOX_DATA_51TO81_L           ((u32)0xFFFFFFFF << BIT_SHIFT_EXT_MAILBOX_DATA_51TO81_L)          /*!<R/W 0   */

/* REG_EXT_BT_MAILBOX_OUT_HIGH 0x11A8 */
#define BIT_SHIFT_EXT_MAILBOX_DATA_51TO81_H          0
#define BIT_MASK_EXT_MAILBOX_DATA_51TO81_H           ((u32)0xFFFFFFFF << BIT_SHIFT_EXT_MAILBOX_DATA_51TO81_H)          /*!<R/W 0   */

/* REG_EXT_BT_MAILBOX_CONTROL 0x11AC */
#define BIT_SHIFT_EXT_MAILBOX_IN_RDY_INTEN           17
#define BIT_EXT_MAILBOX_IN_RDY_INTEN                 ((u32)0x00000001 << BIT_SHIFT_EXT_MAILBOX_IN_RDY_INTEN)           /*!<R/W 0  Mailbox IN ready interrupt enable */
#define BIT_SHIFT_EXT_MAILBOX_IN_RDY                 16
#define BIT_EXT_MAILBOX_IN_RDY                       ((u32)0x00000001 << BIT_SHIFT_EXT_MAILBOX_IN_RDY)                 /*!<R/W 0  Mailbox ready BT2Wifi */
#define BIT_SHIFT_EXTMAILBOX_OUTEMPTY_INTEN          1
#define BIT_EXTMAILBOX_OUTEMPTY_INTEN                ((u32)0x00000001 << BIT_SHIFT_EXTMAILBOX_OUTEMPTY_INTEN)          /*!<R/W 0  Mailbox OUT empty interrupt enable */
#define BIT_SHIFT_EXTMAILBOX_OUT_VLD                 0
#define BIT_EXTMAILBOX_OUT_VLD                       ((u32)0x00000001 << BIT_SHIFT_EXTMAILBOX_OUT_VLD)                 /*!<R/W 0  Mailbox ACK Wifi2BT */

/* REG_EXT_BT_MAILBOX_IN_LOW 0x11B0 */
#define BIT_SHIFT_EXT_MAILBOX_DATA_81TO51_L          0
#define BIT_MASK_EXT_MAILBOX_DATA_81TO51_L           ((u32)0xFFFFFFFF << BIT_SHIFT_EXT_MAILBOX_DATA_81TO51_L)          /*!<R 0   */

/* REG_EXT_BT_MAILBOX_IN_HIGH 0x11B4 */
#define BIT_SHIFT_EXT_MAILBOX_DATA_81_TO51_H         0
#define BIT_MASK_EXT_MAILBOX_DATA_81_TO51_H          ((u32)0xFFFFFFFF << BIT_SHIFT_EXT_MAILBOX_DATA_81_TO51_H)         /*!<R 0   */

/* REG_FWIMR1 0x11C0 */
#define BIT_SHIFT_FS_TXBCNOK_PORT1_INT_EN            31
#define BIT_FS_TXBCNOK_PORT1_INT_EN                  ((u32)0x00000001 << BIT_SHIFT_FS_TXBCNOK_PORT1_INT_EN)            /*!<R/W1C 0  ENABLE PORT1 TX beacon OK interrupt */
#define BIT_SHIFT_FS_TXBCNERR_PORT1_INT_EN           30
#define BIT_FS_TXBCNERR_PORT1_INT_EN                 ((u32)0x00000001 << BIT_SHIFT_FS_TXBCNERR_PORT1_INT_EN)           /*!<R/W1C 0  ENABLE PORT0 TX beacon Error interrupt */
#define BIT_SHIFT_FS_TXBCNOK_PORT2_INT_EN            29
#define BIT_FS_TXBCNOK_PORT2_INT_EN                  ((u32)0x00000001 << BIT_SHIFT_FS_TXBCNOK_PORT2_INT_EN)            /*!<R/W1C 0  PORT2 TX beacon OK interrupt */
#define BIT_SHIFT_FS_TXBCNERR_PORT2_INT_EN           28
#define BIT_FS_TXBCNERR_PORT2_INT_EN                 ((u32)0x00000001 << BIT_SHIFT_FS_TXBCNERR_PORT2_INT_EN)           /*!<R/W1C 0  PORT2 TX beacon Error interrupt */
#define BIT_SHIFT_FS_EVTQ_TXDONE_INT_EN              27
#define BIT_FS_EVTQ_TXDONE_INT_EN                    ((u32)0x00000001 << BIT_SHIFT_FS_EVTQ_TXDONE_INT_EN)              /*!<R/W1C 0   */
#define BIT_SHIFT_FS_EVTQ_START_INT_EN               26
#define BIT_FS_EVTQ_START_INT_EN                     ((u32)0x00000001 << BIT_SHIFT_FS_EVTQ_START_INT_EN)               /*!<R/W1C 0   */
#define BIT_SHIFT_FS_DWWIN_END_INT_EN                25
#define BIT_FS_DWWIN_END_INT_EN                      ((u32)0x00000001 << BIT_SHIFT_FS_DWWIN_END_INT_EN)                /*!<R/W1C 0   */
#define BIT_SHIFT_FS_BCN_IE_0_HIT_EN                 24
#define BIT_FS_BCN_IE_0_HIT_EN                       ((u32)0x00000001 << BIT_SHIFT_FS_BCN_IE_0_HIT)                    /*!<R/W1C 0   */
#define BIT_SHIFT_FS_BCN_IE_1_HIT_EN                 23
#define BIT_FS_BCN_IE_1_HIT_EN                       ((u32)0x00000001 << BIT_SHIFT_FS_BCN_IE_1_HIT)                    /*!<R/W1C 0   */


/* REG_FWISR1 0x11C4 */
#define BIT_SHIFT_FS_TXBCNOK_PORT1_INT               31
#define BIT_FS_TXBCNOK_PORT1_INT                     ((u32)0x00000001 << BIT_SHIFT_FS_TXBCNOK_PORT1_INT)               /*!<R/W1C 0  PORT1 TX beacon OK interrupt */
#define BIT_SHIFT_FS_TXBCNERR_PORT1_INT              30
#define BIT_FS_TXBCNERR_PORT1_INT                    ((u32)0x00000001 << BIT_SHIFT_FS_TXBCNERR_PORT1_INT)              /*!<R/W1C 0  PORT0 TX beacon Error interrupt */
#define BIT_SHIFT_FS_TXBCNOK_PORT2_INT               29
#define BIT_FS_TXBCNOK_PORT2_INT                     ((u32)0x00000001 << BIT_SHIFT_FS_TXBCNOK_PORT2_INT)               /*!<R/W1C 0  PORT2 TX beacon OK interrupt */
#define BIT_SHIFT_FS_TXBCNERR_PORT2_INT              28
#define BIT_FS_TXBCNERR_PORT2_INT                    ((u32)0x00000001 << BIT_SHIFT_FS_TXBCNERR_PORT2_INT)              /*!<R/W1C 0  PORT2 TX beacon Error interrupt */
#define BIT_SHIFT_FS_EVTQ_TXDONE_INT                 27
#define BIT_FS_EVTQ_TXDONE_INT                       ((u32)0x00000001 << BIT_SHIFT_FS_EVTQ_TXDONE_INT)                 /*!<R/W1C 0   */
#define BIT_SHIFT_FS_EVTQ_START_INT                  26
#define BIT_FS_EVTQ_START_INT                        ((u32)0x00000001 << BIT_SHIFT_FS_EVTQ_START_INT)                  /*!<R/W1C 0   */
#define BIT_SHIFT_FS_DWWIN_END_INT                   25
#define BIT_FS_DWWIN_END_INT                         ((u32)0x00000001 << BIT_SHIFT_FS_DWWIN_END_INT)                   /*!<R/W1C 0   */
#define BIT_SHIFT_FS_BCN_IE_0_HIT                    24
#define BIT_FS_BCN_IE_0_HIT                          ((u32)0x00000001 << BIT_SHIFT_FS_BCN_IE_0_HIT)                    /*!<R/W1C 0   */
#define BIT_SHIFT_FS_BCN_IE_1_HIT                    23
#define BIT_FS_BCN_IE_1_HIT                          ((u32)0x00000001 << BIT_SHIFT_FS_BCN_IE_1_HIT)                    /*!<R/W1C 0   */


/* REG_FT2IMR 0x11E0 */
#define BIT_SHIFT_PORT1_RX_UCMD1_UAPSD0_OK_INT_EN    19
#define BIT_PORT1_RX_UCMD1_UAPSD0_OK_INT_EN          ((u32)0x00000001 << BIT_SHIFT_PORT1_RX_UCMD1_UAPSD0_OK_INT_EN)   /*!<R/W 0  PORT1 rx unicast packet ok interrupt with more data =1 & UAPSD =0 */
#define BIT_SHIFT_PORT1_RX_UCMD0_UAPSD0_OK_INT_EN    18
#define BIT_PORT1_RX_UCMD0_UAPSD0_OK_INT_EN          ((u32)0x00000001 << BIT_SHIFT_PORT1_RX_UCMD0_UAPSD0_OK_INT_EN)   /*!<R/W 0  PORT1 rx unicast packet ok interrupt with more data =0 & UAPSD =0 */
#define BIT_SHIFT_PORT1_TRIPKT_OK_INT_EN             17
#define BIT_PORT1_TRIPKT_OK_INT_EN                   ((u32)0x00000001 << BIT_SHIFT_PORT1_TRIPKT_OK_INT_EN)             /*!<R/W 0  PORT1 trigger packet assign to queue or release interrupt */
#define BIT_SHIFT_PORT1_RX_EOSP_OK_INT_EN            16
#define BIT_PORT1_RX_EOSP_OK_INT_EN                  ((u32)0x00000001 << BIT_SHIFT_PORT1_RX_EOSP_OK_INT_EN)            /*!<R/W 0  PORT1 RX packet with EOSP =1 ok interrupt */

#define BIT_SHIFT_FS_TXPRPT_CNT_FULL_EN                 10
#define BIT_FS_TXPRPT_CNT_FULL_EN                       ((u32)0x00000001 << BIT_SHIFT_FS_TXPRPT_CNT_FULL_EN)                 /*!<R/W 0  txrpt buffer full interrupt */
#define BIT_SHIFT_FS_NOA2_TSFT_BIT32_INT_EN          9
#define BIT_FS_NOA2_TSFT_BIT32_INT_EN                ((u32)0x00000001 << BIT_SHIFT_FS_NOA2_TSFT_BIT32_INT_EN)          /*!<R/W 0  NOA unit2 TSFT bit 32 toggle interrupt */
#define BIT_SHIFT_FS_NOA1_TSFT_BIT32_INT_EN          8
#define BIT_FS_NOA1_TSFT_BIT32_INT_EN                ((u32)0x00000001 << BIT_SHIFT_FS_NOA1_TSFT_BIT32_INT_EN)          /*!<R/W 0  NOA unit1 TSFT bit 32 toggle interrupt */
#define BIT_SHIFT_PORT1_TX_NULL1_DONE_INT_EN         1
#define BIT_PORT1_TX_NULL1_DONE_INT_EN               ((u32)0x00000001 << BIT_SHIFT_PORT1_TX_NULL1_DONE_INT_EN)         /*!<R/W 0  PORT1 TX NULL1 packet ok interrupt */
#define BIT_SHIFT_PORT1_TX_NULL0_DONE_INT_EN         0
#define BIT_PORT1_TX_NULL0_DONE_INT_EN               ((u32)0x00000001 << BIT_SHIFT_PORT1_TX_NULL0_DONE_INT_EN)         /*!<R/W 1  PORT1 TX NULL0 packet ok interrupt */

/* REG_FT2ISR 0x11E4 */
#define BIT_SHIFT_PORT1_RX_UCMD1_UAPSD0_OK_INT       19
#define BIT_PORT1_RX_UCMD1_UAPSD0_OK_INT             ((u32)0x00000001 << BIT_SHIFT_PORT1_RX_UCMD1_UAPSD0_OK_INT)      /*!<R/W1C 0  PORT1 rx unicast packet ok interrupt with more data =1 & UAPSD =0 */
#define BIT_SHIFT_PORT1_RX_UCMD0_UAPSD0_OK_INT       18
#define BIT_PORT1_RX_UCMD0_UAPSD0_OK_INT             ((u32)0x00000001 << BIT_SHIFT_PORT1_RX_UCMD0_UAPSD0_OK_INT)      /*!<R/W1C 0  PORT1 rx unicast packet ok interrupt with more data =0 & UAPSD =0 */
#define BIT_SHIFT_PORT1_TRIPKT_OK_INT                17
#define BIT_PORT1_TRIPKT_OK_INT                      ((u32)0x00000001 << BIT_SHIFT_PORT1_TRIPKT_OK_INT)                /*!<R/W1C 0  PORT1 trigger packet assign to queue or release interrupt */
#define BIT_SHIFT_PORT1_RX_EOSP_OK_INT               16
#define BIT_PORT1_RX_EOSP_OK_INT                     ((u32)0x00000001 << BIT_SHIFT_PORT1_RX_EOSP_OK_INT)               /*!<R/W1C 0  PORT1 RX packet with EOSP =1 ok interrupt */

#define BIT_SHIFT_FS_TXPRPT_CNT_FULL                 10
#define BIT_FS_TXPRPT_CNT_FULL                       ((u32)0x00000001 << BIT_SHIFT_FS_TXPRPT_CNT_FULL)                 /*!<R/W1C 0  txrpt buffer full interrupt */
#define BIT_SHIFT_FS_NOA2_TSFT_BIT32_INT             9
#define BIT_FS_NOA2_TSFT_BIT32_INT                   ((u32)0x00000001 << BIT_SHIFT_FS_NOA2_TSFT_BIT32_INT)             /*!<R/W1C 0  NOA unit2 TSFT bit 32 toggle interrupt */
#define BIT_SHIFT_FS_NOA1_TSFT_BIT32_INT             8
#define BIT_FS_NOA1_TSFT_BIT32_INT                   ((u32)0x00000001 << BIT_SHIFT_FS_NOA1_TSFT_BIT32_INT)             /*!<R/W1C 0  NOA unit1 TSFT bit 32 toggle interrupt */
#define BIT_SHIFT_PORT1_TX_NULL1_DONE_INT            1
#define BIT_PORT1_TX_NULL1_DONE_INT                  ((u32)0x00000001 << BIT_SHIFT_PORT1_TX_NULL1_DONE_INT)            /*!<R/W1C 0  PORT1 TX NULL1 packet ok interrupt */
#define BIT_SHIFT_PORT1_TX_NULL0_DONE_INT            0
#define BIT_PORT1_TX_NULL0_DONE_INT                  ((u32)0x00000001 << BIT_SHIFT_PORT1_TX_NULL0_DONE_INT)            /*!<R/W2C 1  PORT1 TX NULL0 packet ok interrupt */

/* REG_RQPN_CTRL_HLPQ 0x0200 */
#define BIT_SHIFT_LOAD_R_PGNUM                       31
#define BIT_LOAD_R_PGNUM                             ((u32)0x00000001 << BIT_SHIFT_LOAD_R_PGNUM)                       /*!<R/W 0  Write 1 to set RQPN bit[79:0] value to page numbers for initialization */

#define BIT_SHIFT_EPQ_PUBLIC_DIS                     27
#define BIT_EPQ_PUBLIC_DIS                           ((u32)0x00000001 << BIT_SHIFT_EPQ_PUBLIC_DIS)                     /*!<R/W 0  When this bit is set, Extra queue available Tx page size excludes the public queue. Otherwise, Extra queue available Tx page size includes public queue */
#define BIT_SHIFT_NPQ_PUBLIC_DIS                     26
#define BIT_NPQ_PUBLIC_DIS                           ((u32)0x00000001 << BIT_SHIFT_NPQ_PUBLIC_DIS)                     /*!<R/W 0  When this bit is set, Normal queue available Tx page size excludes the public queue. Otherwise, Normal queue available Tx page size includes public queue */
#define BIT_SHIFT_LPQ_PUBLIC_DIS                     25
#define BIT_LPQ_PUBLIC_DIS                           ((u32)0x00000001 << BIT_SHIFT_LPQ_PUBLIC_DIS)                     /*!<R/W 0  When this bit is set, Low queue available Tx page size excludes the public queue. Otherwise, Low queue available Tx page size includes public queue */
#define BIT_SHIFT_HPQ_PUBLIC_DIS                     24
#define BIT_HPQ_PUBLIC_DIS                           ((u32)0x00000001 << BIT_SHIFT_HPQ_PUBLIC_DIS)                     /*!<R/W 0  When this bit is set, High queue available Tx page size excludes the public queue. Otherwise, High queue available Tx page size includes public queue */
#define BIT_SHIFT_PUBQ                               16
#define BIT_MASK_PUBQ                                ((u32)0x000000FF << BIT_SHIFT_PUBQ)                               /*!<R/W 0  Public Reserved Page Number */
#define BIT_SHIFT_LPQ                                8
#define BIT_MASK_LPQ                                 ((u32)0x000000FF << BIT_SHIFT_LPQ)                                /*!<R/W 0  Low Priority Queue Reserved Page Number */
#define BIT_SHIFT_HPQ                                0
#define BIT_MASK_HPQ                                 ((u32)0x000000FF << BIT_SHIFT_HPQ)                                /*!<R/W 0  High Priority Queue Reserved Page Number */

/* REG_FIFOPAGE_INFO 0x0204 */
#define BIT_SHIFT_TXPKTNUM                           24
#define BIT_MASK_TXPKTNUM                            ((u32)0x000000FF << BIT_SHIFT_TXPKTNUM)                           /*!<R 0  Packet number in TXPKTBUF (Normal/Low) */
#define BIT_SHIFT_PUBQ_AVAL_PG                       16
#define BIT_MASK_PUBQ_AVAL_PG                        ((u32)0x000000FF << BIT_SHIFT_PUBQ_AVAL_PG)                       /*!<R 0  Available Public Queue Page Number */
#define BIT_SHIFT_LPQ_AVAL_PG                        8
#define BIT_MASK_LPQ_AVAL_PG                         ((u32)0x000000FF << BIT_SHIFT_LPQ_AVAL_PG)                        /*!<R 0  Available Low Priority Queue Page Number */
#define BIT_SHIFT_HPQ_AVAL_PG                        0
#define BIT_MASK_HPQ_AVAL_PG                         ((u32)0x000000FF << BIT_SHIFT_HPQ_AVAL_PG)                        /*!<R 0  Available High Priority Queue Page Number */

/* REG_DWBCN0_CTRL 0x0208 */
#define BIT_SHIFT_LLT_FREE_PAGE                      24
#define BIT_MASK_LLT_FREE_PAGE                       ((u32)0x000000FF << BIT_SHIFT_LLT_FREE_PAGE)                      /*!<R 0  RSVD */
#define BIT_SHIFT_RSVD_BYTE1                         17
#define BIT_MASK_RSVD_BYTE1                          ((u32)0x0000007F << BIT_SHIFT_RSVD_BYTE1)                         /*!<R/W 0  RSVD */
#define BIT_SHIFT_BCN_VALID                          16
#define BIT_BCN_VALID                                ((u32)0x00000001 << BIT_SHIFT_BCN_VALID)                          /*!<R/W1C 0  When this bit is set, the beacon packet has finished to write to txpktbuffer. Clear by SW */
#define BIT_SHIFT_BCN_HEAD                           8
#define BIT_MASK_BCN_HEAD                            ((u32)0x000000FF << BIT_SHIFT_BCN_HEAD)                           /*!<R/W 0xF6  The head page of packet of Bcnq which is Tx DMA filled Bcnq packet from */
#define BIT_SHIFT_BLK_DESC_NUM                       4
#define BIT_MASK_BLK_DESC_NUM                        ((u32)0x0000000F << BIT_SHIFT_BLK_DESC_NUM)                       /*!<R/W 1  The Most Number of Tx Descriptor per Bulk Out Only for USB */

#define BIT_SHIFT_BLK_DESC_OPT                       0
#define BIT_BLK_DESC_OPT                             ((u32)0x00000001 << BIT_SHIFT_BLK_DESC_OPT)                       /*!<R/W 0  option to select usb descriptor number(according to 0x208[7:4]) 1 : usb_desc_num = 2 * r_blk_desc_num 0 : usb_desc_num = 4 * r_blk_desc_num */

/* REG_TXDMA_OFFSET_CHK 0x020C */
#define BIT_SHIFT_EN_CHKERR_FINISH                   31
#define BIT_EN_CHKERR_FINISH                         ((u32)0x00000001 << BIT_SHIFT_EN_CHKERR_FINISH)                   /*!<R/W 0  Let checksum offload statemachine finish if checksum parser error */
#define BIT_SHIFT_EN_DMA_PERMU_P                     30
#define BIT_EN_DMA_PERMU_P                           ((u32)0x00000001 << BIT_SHIFT_EN_DMA_PERMU_P)                     /*!<R/W 0  Enable every dma latch fifo ptr for pcie as usb mode as one pkt trans in permu */
#define BIT_SHIFT_EN_TXQUE_CLR                       29
#define BIT_EN_TXQUE_CLR                             ((u32)0x00000001 << BIT_SHIFT_EN_TXQUE_CLR)                       /*!<R/W 1  Enable tx queue clear tx pkt in tde in usb mode */
#define BIT_SHIFT_EN_PCIE_FIFO                       28
#define BIT_EN_PCIE_FIFO                             ((u32)0x00000001 << BIT_SHIFT_EN_PCIE_FIFO)                       /*!<R/W 0  Enable pcie fifo store forward txdesc as before mode */

#define BIT_SHIFT_PG_UNDER_TH                        16
#define BIT_MASK_PG_UNDER_TH                         ((u32)0x000000FF << BIT_SHIFT_PG_UNDER_TH)                        /*!<R/W 0xFD  Page threshold value is check by Tx DMA engine. */

#define BIT_SHIFT_DSC_CHKSUM_EN                      13
#define BIT_DSC_CHKSUM_EN                            ((u32)0x00000001 << BIT_SHIFT_DSC_CHKSUM_EN)                      /*!<R/W 0  Enable SDIO checksum */
#define BIT_SHIFT_RST_RDPTR                          12
#define BIT_RST_RDPTR                                ((u32)0x00000001 << BIT_SHIFT_RST_RDPTR)                          /*!<R/W 0  Reset the read pointer of sync FIFO */
#define BIT_SHIFT_RST_WRPTR                          11
#define BIT_RST_WRPTR                                ((u32)0x00000001 << BIT_SHIFT_RST_WRPTR)                          /*!<R/W 0  Reset the write pointer of sync FIFO */
#define BIT_SHIFT_CHK_PG_TH_EN                       10
#define BIT_CHK_PG_TH_EN                             ((u32)0x00000001 << BIT_SHIFT_CHK_PG_TH_EN)                       /*!<R/W 0  Enable Tx DMA to check total pages if it is under page threshold */
#define BIT_SHIFT_DROP_DATA_EN                       9
#define BIT_DROP_DATA_EN                             ((u32)0x00000001 << BIT_SHIFT_DROP_DATA_EN)                       /*!<R/W 0  Enable Tx DMA to drop the redundant data of packet */
#define BIT_SHIFT_CHECK_OFFSET_EN                    8
#define BIT_CHECK_OFFSET_EN                          ((u32)0x00000001 << BIT_SHIFT_CHECK_OFFSET_EN)                    /*!<R/W 0  Enable Tx DMA to check offset value */
#define BIT_SHIFT_CHK_OFFSET                         0
#define BIT_MASK_CHK_OFFSET                          ((u32)0x000000FF << BIT_SHIFT_CHK_OFFSET)                         /*!<R/W 0  Offset value is check by Tx DMA engine */

/* REG_TXDMA_STATUS 0x0210 */

#define BIT_SHIFT_HI_OQT_UDN                         17
#define BIT_HI_OQT_UDN                               ((u32)0x00000001 << BIT_SHIFT_HI_OQT_UDN)                         /*!<R/W1C 0  High Priority Queue_Tx OQT underflow */
#define BIT_SHIFT_HI_OQT_OVF                         16
#define BIT_HI_OQT_OVF                               ((u32)0x00000001 << BIT_SHIFT_HI_OQT_OVF)                         /*!<R/W1C 0  High Priority Queue_Tx OQT overflow */
#define BIT_SHIFT_PAYLOAD_CHKSUM_ERR                 15
#define BIT_PAYLOAD_CHKSUM_ERR                       ((u32)0x00000001 << BIT_SHIFT_PAYLOAD_CHKSUM_ERR)                 /*!<R/W1C 0  Payload checksum error */
#define BIT_SHIFT_PAYLOAD_UDN                        14
#define BIT_PAYLOAD_UDN                              ((u32)0x00000001 << BIT_SHIFT_PAYLOAD_UDN)                        /*!<R/W1C 0  Payload is under the packet length of Tx descriptor. Clear by SW. */
#define BIT_SHIFT_PAYLOAD_OVF                        13
#define BIT_PAYLOAD_OVF                              ((u32)0x00000001 << BIT_SHIFT_PAYLOAD_OVF)                        /*!<R/W1C 0  Payload is over the packet length of Tx descriptor. Clear by SW. */
#define BIT_SHIFT_DSC_CHKSUM_FAIL                    12
#define BIT_DSC_CHKSUM_FAIL                          ((u32)0x00000001 << BIT_SHIFT_DSC_CHKSUM_FAIL)                    /*!<R/W1C 0  Tx descriptor checksum error. Clear by SW. */
#define BIT_SHIFT_UNKNOWN_QSEL                       11
#define BIT_UNKNOWN_QSEL                             ((u32)0x00000001 << BIT_SHIFT_UNKNOWN_QSEL)                       /*!<R/W1C 0  An unknown QSEL of Tx descriptor is detected. Clear by SW. */
#define BIT_SHIFT_EP_QSEL_DIFF                       10
#define BIT_EP_QSEL_DIFF                             ((u32)0x00000001 << BIT_SHIFT_EP_QSEL_DIFF)                       /*!<R/W1C 0  Tx Endpoint is unmatched with the QSEL of descriptor. Clear by SW. */
#define BIT_SHIFT_TX_OFFS_UNMATCH                    9
#define BIT_TX_OFFS_UNMATCH                          ((u32)0x00000001 << BIT_SHIFT_TX_OFFS_UNMATCH)                    /*!<R/W1C 0  Tx offset is unmatched. Clear by SW. */
#define BIT_SHIFT_TXOQT_UDN                          8
#define BIT_TXOQT_UDN                                ((u32)0x00000001 << BIT_SHIFT_TXOQT_UDN)                          /*!<R/W1C 0  TXOQT Underflow. Clear by SW. */
#define BIT_SHIFT_TXOQT_OVF                          7
#define BIT_TXOQT_OVF                                ((u32)0x00000001 << BIT_SHIFT_TXOQT_OVF)                          /*!<R/W1C 0  TXOQT Overflow. Clear by SW. */
#define BIT_SHIFT_SFF_UDN                            6
#define BIT_SFF_UDN                                  ((u32)0x00000001 << BIT_SHIFT_SFF_UDN)                            /*!<R/W1C 0  TXDMA Sync FIFO Underflow. Clear by SW. */
#define BIT_SHIFT_SFF_OVF                            5
#define BIT_SFF_OVF                                  ((u32)0x00000001 << BIT_SHIFT_SFF_OVF)                            /*!<R/W1C 0  TXDMA Sync FIFO Overflow. Clear by SW. */
#define BIT_SHIFT_FREE_PG_FF                         4
#define BIT_FREE_PG_FF                               ((u32)0x00000001 << BIT_SHIFT_FREE_PG_FF)                         /*!<R/W1C 0  TXDMA reads NULL page. Clear by SW. */
#define BIT_SHIFT_PAGE_UNDER                         3
#define BIT_PAGE_UNDER                               ((u32)0x00000001 << BIT_SHIFT_PAGE_UNDER)                         /*!<R/W1C 0  Total pages included PTCL un-return pages are under the total reserved pages minus the page threshold. Clear by SW. */
#define BIT_SHIFT_PAGE_OVER                          2
#define BIT_PAGE_OVER                                ((u32)0x00000001 << BIT_SHIFT_PAGE_OVER)                          /*!<R/W1C 0  Total pages included PTCL un-return pages are over the total reserved pages. Clear by SW. */
#define BIT_SHIFT_PG_UDN                             1
#define BIT_PG_UDN                                   ((u32)0x00000001 << BIT_SHIFT_PG_UDN)                             /*!<R/W1C 0  TXFF page underflow in TDE page controller. Clear by SW. */
#define BIT_SHIFT_PG_OVF                             0
#define BIT_PG_OVF                                   ((u32)0x00000001 << BIT_SHIFT_PG_OVF)                             /*!<R/W1C 0  TXFF page overflow in TDE page controller.. Clear by SW. */

/* REG_RQPN_NPQ 0x0214 */
#define BIT_SHIFT_EPQ_PGNUM                          24
#define BIT_MASK_EPQ_PGNUM                           ((u32)0x000000FF << BIT_SHIFT_EPQ_PGNUM)                          /*!<R 0  Extra Queue Page Number */
#define BIT_SHIFT_EPQ_R_PGNUM                        16
#define BIT_MASK_EPQ_R_PGNUM                         ((u32)0x000000FF << BIT_SHIFT_EPQ_R_PGNUM)                        /*!<R/W 0  Extra Queue Reserved Page Number */
#define BIT_SHIFT_NPQ_PGNUM                          8
#define BIT_MASK_NPQ_PGNUM                           ((u32)0x000000FF << BIT_SHIFT_NPQ_PGNUM)                          /*!<R 0  Normal Priority Queue Page Number */
#define BIT_SHIFT_NPQ_R_PGNUM                        0
#define BIT_MASK_NPQ_R_PGNUM                         ((u32)0x000000FF << BIT_SHIFT_NPQ_R_PGNUM)                        /*!<R/W 0  Normal Priority Queue Reserved Page Number */

/* REG_TQPNT1 0x0218 */
#define BIT_SHIFT_NPQ_HIGH_TH                        24
#define BIT_MASK_NPQ_HIGH_TH                         ((u32)0x000000FF << BIT_SHIFT_NPQ_HIGH_TH)                        /*!<R/W 0  For SDIO, Normal Priority Queue Page Number High Threshold */
#define BIT_SHIFT_NPQ_LOW_TH                         16
#define BIT_MASK_NPQ_LOW_TH                          ((u32)0x000000FF << BIT_SHIFT_NPQ_LOW_TH)                         /*!<R/W 0  For SDIO, Normal Priority Queue Page Number Low Threshold */
#define BIT_SHIFT_HPQ_HIGH_TH                        8
#define BIT_MASK_HPQ_HIGH_TH                         ((u32)0x000000FF << BIT_SHIFT_HPQ_HIGH_TH)                        /*!<R/W 0  For SDIO, High Priority Queue Page Number High Threshold */
#define BIT_SHIFT_HPQ_LOW_TH                         0
#define BIT_MASK_HPQ_LOW_TH                          ((u32)0x000000FF << BIT_SHIFT_HPQ_LOW_TH)                         /*!<R/W 0  For SDIO, High Priority Queue Page Number Low Threshold */

/* REG_TQPNT2 0x021C */
#define BIT_SHIFT_EXQ_HIGH_TH                        24
#define BIT_MASK_EXQ_HIGH_TH                         ((u32)0x000000FF << BIT_SHIFT_EXQ_HIGH_TH)                        /*!<R/W 0  For SDIO, Extra Priority Queue Page Number High Threshold */
#define BIT_SHIFT_EXQ_LOW_TH                         16
#define BIT_MASK_EXQ_LOW_TH                          ((u32)0x000000FF << BIT_SHIFT_EXQ_LOW_TH)                         /*!<R/W 0  For SDIO, Extra Priority Queue Page Number Low Threshold */
#define BIT_SHIFT_LPQ_HIGH_TH                        8
#define BIT_MASK_LPQ_HIGH_TH                         ((u32)0x000000FF << BIT_SHIFT_LPQ_HIGH_TH)                        /*!<R/W 0  For SDIO, Low Priority Queue Page Number High Threshold */
#define BIT_SHIFT_LPQ_LOW_TH                         0
#define BIT_MASK_LPQ_LOW_TH                          ((u32)0x000000FF << BIT_SHIFT_LPQ_LOW_TH)                         /*!<R/W 0  For SDIO, Low Priority Queue Page Number Low Threshold */

/* REG_TDE_DEBUG 0x0220 */
#define BIT_SHIFT_TDE_DEBUG                          0
#define BIT_MASK_TDE_DEBUG                           ((u32)0xFFFFFFFF << BIT_SHIFT_TDE_DEBUG)                          /*!<R 0  tde debug port register. */

/* REG_AUTO_LLT 0x0224 */
#define BIT_SHIFT_TXPKTNUM_H                         24
#define BIT_MASK_TXPKTNUM_H                          ((u32)0x000000FF << BIT_SHIFT_TXPKTNUM_H)                         /*!<R 0  Packet number in TXPKTBUF (High and Extra) */
#define BIT_SHIFT_TDE_DBG_SEL                        23
#define BIT_TDE_DBG_SEL                              ((u32)0x00000001 << BIT_SHIFT_TDE_DBG_SEL)                        /*!<R/W 0  debug signals selection of Tx DMA */
#define BIT_SHIFT_MASK_QSEL_DIFF                     22
#define BIT_MASK_QSEL_DIFF                           ((u32)0x00000001 << BIT_SHIFT_MASK_QSEL_DIFF)                     /*!<R/W 0  Mask the error bit(tx endpoint is unmatched with qsel, 0x210[10]) */

#define BIT_SHIFT_AUTO_INIT_LLT                      16
#define BIT_AUTO_INIT_LLT                            ((u32)0x00000001 << BIT_SHIFT_AUTO_INIT_LLT)                      /*!<R/W 0  Write 1 to enable HW init LLT, driver need polling to 0 meaning init success */
#define BIT_SHIFT_TX_OQT_HE_FREE_SPACE               8
#define BIT_MASK_TX_OQT_HE_FREE_SPACE                ((u32)0x000000FF << BIT_SHIFT_TX_OQT_HE_FREE_SPACE)               /*!<R 0  High and Extra priority queue */
#define BIT_SHIFT_TX_OQT_NL_FREE_SPACE               0
#define BIT_MASK_TX_OQT_NL_FREE_SPACE                ((u32)0x000000FF << BIT_SHIFT_TX_OQT_NL_FREE_SPACE)               /*!<R 0  Normal and low priority queue */

/* REG_DWBCN1_CTRL 0x0228 */
#define BIT_SHIFT_BCN_HEAD_2                         24
#define BIT_MASK_BCN_HEAD_2                          ((u32)0x000000FF << BIT_SHIFT_BCN_HEAD_2)                         /*!<R/W 0xFA  The head page of packet of Bcnq which is Tx DMA filled Bcnq packet from. */

#define BIT_SHIFT_SW_BCN_SEL                         20
#define BIT_MASK_SW_BCN_SEL                          ((u32)0x00000003 << BIT_SHIFT_SW_BCN_SEL)                         /*!<R/W 0  Bcnq head selection from SW setting 2'b01 : r_bcn_head_1 2'b10 : r_bcn_head_2 */

#define BIT_SHIFT_BCN_VALID_2                        18
#define BIT_BCN_VALID_2                              ((u32)0x00000001 << BIT_SHIFT_BCN_VALID_2)                        /*!<R/W 0  When this bit is set, the beacon packet has finished to write to txpktbuffer. Clear by SW. */
#define BIT_SHIFT_SW_BCN_SEL_EN                      17
#define BIT_SW_BCN_SEL_EN                            ((u32)0x00000001 << BIT_SHIFT_SW_BCN_SEL_EN)                      /*!<R/W 0  Enable Bcnq head selection from SW setting */
#define BIT_SHIFT_BCN_VALID_1                        16
#define BIT_BCN_VALID_1                              ((u32)0x00000001 << BIT_SHIFT_BCN_VALID_1)                        /*!<R/W 0  When this bit is set, the beacon packet has finished to write to txpktbuffer. Clear by SW. */
#define BIT_SHIFT_BCN_HEAD_1                         8
#define BIT_MASK_BCN_HEAD_1                          ((u32)0x000000FF << BIT_SHIFT_BCN_HEAD_1)                         /*!<R/W 0  The head page of packet of Bcnq which is Tx DMA filled Bcnq packet from. */
#define BIT_SHIFT_MAX_TX_PKT                         0
#define BIT_MASK_MAX_TX_PKT                          ((u32)0x000000FF << BIT_SHIFT_MAX_TX_PKT)                         /*!<R/W 0  Unit : packet number Max_tx_pkt_for_USB_and_SDIO */

/* REG_TX_ALIGNMENT_CTRL 0x022C */

#define BIT_SHIFT_ADJUSTABLE_SIZE_EN                 15
#define BIT_ADJUSTABLE_SIZE_EN                       ((u32)0x00000001 << BIT_SHIFT_ADJUSTABLE_SIZE_EN)                 /*!<R/W 0  Enable tx alignment for sdio. SW can assign the alignment size of blocks in an aggregated-packet. */

#define BIT_SHIFT_ALIGNMENT_SIZE                     0
#define BIT_MASK_ALIGNMENT_SIZE                      ((u32)0x00000FFF << BIT_SHIFT_ALIGNMENT_SIZE)                     /*!<R/W 0  The alignment size of blocks in an aggregated-packet. Unit: Byte */

/* REG_TDE_GCK_CTRL 0x0230 */

#define BIT_SHIFT_DMA_WAIT_MORE_CYCLE                1
#define BIT_DMA_WAIT_MORE_CYCLE                      ((u32)0x00000001 << BIT_SHIFT_DMA_WAIT_MORE_CYCLE)                /*!<R/W 1  enable this bit,tde_ctl will wait for 16 dma_clk when host dma last data to tde_sync_fifo 1:used for 20M mac clk 0:used for 40M/80M mac clk(will wait for 12 dma_clk) */
#define BIT_SHIFT_TDE_GCLK_EN                        0
#define BIT_TDE_GCLK_EN                              ((u32)0x00000001 << BIT_SHIFT_TDE_GCLK_EN)                        /*!<R/W 1  enable this bit,txdma engine will use gated clk */



/* REG_RXDMA_AGG_PG_TH 0x0280 */
#define BIT_SHIFT_RXDMA_STORE                        31
#define BIT_RXDMA_STORE                              ((u32)0x00000001 << BIT_SHIFT_RXDMA_STORE)                        /*!<R/W 0  usb rx dma old mode store pkt and forward */

#define BIT_SHIFT_EN_PRE_CALC                        29
#define BIT_EN_PRE_CALC                              ((u32)0x00000001 << BIT_SHIFT_EN_PRE_CALC)                        /*!<R/W 0  0: rde start rxdma when aggregated length over specified threshold; 1: rde start rxdma when next packet, if aggregated, will cause the total length over specified threshold */

#define BIT_SHIFT_PKT_NUM_WOL                        16
#define BIT_MASK_PKT_NUM_WOL                         ((u32)0x000000FF << BIT_SHIFT_PKT_NUM_WOL)                        /*!<R 0  In wol mode, 8051 should refer this packet counter in RXFF */
#define BIT_SHIFT_DMA_TIMEOUT_TH                     8
#define BIT_MASK_DMA_TIMEOUT_TH                      ((u32)0x000000FF << BIT_SHIFT_DMA_TIMEOUT_TH)                     /*!<R/W 0x20  dma agg timeout time : unit : 32us */
#define BIT_SHIFT_RXDMA_AGG_PG_TH                    0
#define BIT_MASK_RXDMA_AGG_PG_TH                     ((u32)0x000000FF << BIT_SHIFT_RXDMA_AGG_PG_TH)                    /*!<R/W 3  rxdma agg length threshold if sdio : unit 1K, others unit is 4K if use RXDMA_AGG_OLD_MOD in use, unit is 1K */

/* REG_RXPKT_NUM 0x0284 */
#define BIT_SHIFT_RXPKT_QUEUED                       24
#define BIT_MASK_RXPKT_QUEUED                        ((u32)0x000000FF << BIT_SHIFT_RXPKT_QUEUED)                       /*!<R 0  The number of packets in RXPKTBUF. */

#define BIT_SHIFT_WMACSTOP_RXDMA                     20
#define BIT_WMACSTOP_RXDMA                           ((u32)0x00000001 << BIT_SHIFT_WMACSTOP_RXDMA)                     /*!<R/W1C 0  Notify rx dma engine to stop handling new request from macrx */
#define BIT_SHIFT_RXDMA_REQ                          19
#define BIT_RXDMA_REQ                                ((u32)0x00000001 << BIT_SHIFT_RXDMA_REQ)                          /*!<R/W 0  rxdma has request */
#define BIT_SHIFT_FW_RELEASE_EN                      18
#define BIT_FW_RELEASE_EN                            ((u32)0x00000001 << BIT_SHIFT_FW_RELEASE_EN)                      /*!<R/W 0  When this bit is set, RXDMA will enter this mode after on-going RXDMA packet to host completed, and stop DMA packet to host. RXDMA will then report */
#define BIT_SHIFT_RXDMA_IDLE                         17
#define BIT_RXDMA_IDLE                               ((u32)0x00000001 << BIT_SHIFT_RXDMA_IDLE)                         /*!<R 0  When RXMA finishes on-going DMA operation, RXMDA will report idle state in this bit. FW can start releasing packets after RXDMA entering idle mode. */
#define BIT_SHIFT_RXPKT_RELEASE_POLL                 16
#define BIT_RXPKT_RELEASE_POLL                       ((u32)0x00000001 << BIT_SHIFT_RXPKT_RELEASE_POLL)                 /*!<R/W 0  When this bit is set, RXDMA will decrease RX PKT counter by one. Before this bit is polled, FW shall update RXFF_RD_PTR first. */
#define BIT_SHIFT_FW_UPD_RXPKT_RDPTR                 0
#define BIT_MASK_FW_UPD_RXPKT_RDPTR                  ((u32)0x0000FFFF << BIT_SHIFT_FW_UPD_RXPKT_RDPTR)                 /*!<R/W 0  FW shall update this register before FW write RXPKT_RELEASE_POLL to 1. */

/* REG_RXDMA_STATUS 0x0288 */

#define BIT_SHIFT_C2H_PKT_OVF                        7
#define BIT_C2H_PKT_OVF                              ((u32)0x00000001 << BIT_SHIFT_C2H_PKT_OVF)                        /*!<R/W1C 0  CH2 pkt overflow. Clr by SW */
#define BIT_SHIFT_AGG_CONFGI_ISSUE                   6
#define BIT_AGG_CONFGI_ISSUE                         ((u32)0x00000001 << BIT_SHIFT_AGG_CONFGI_ISSUE)                   /*!<R/W1C 0  rxdma agg config error. Clr by SW */
#define BIT_SHIFT_FW_POLL_ISSUE                      5
#define BIT_FW_POLL_ISSUE                            ((u32)0x00000001 << BIT_SHIFT_FW_POLL_ISSUE)                      /*!<R/W1C 0  FW Release Poll Error. Clear by SW. */
#define BIT_SHIFT_RX_DATA_UDN                        4
#define BIT_RX_DATA_UDN                              ((u32)0x00000001 << BIT_SHIFT_RX_DATA_UDN)                        /*!<R/W1C 0  FW Release Poll Error. Clear by SW. */
#define BIT_SHIFT_RX_SFF_UDN                         3
#define BIT_RX_SFF_UDN                               ((u32)0x00000001 << BIT_SHIFT_RX_SFF_UDN)                         /*!<R/W1C 0  RX Sync FIFO Underflow. Clear by SW. */
#define BIT_SHIFT_RX_SFF_OVF                         2
#define BIT_RX_SFF_OVF                               ((u32)0x00000001 << BIT_SHIFT_RX_SFF_OVF)                         /*!<R/W1C 0  RX Sync FIFO Overflow. Clear by SW. */

#define BIT_SHIFT_RXPKT_OVF                          0
#define BIT_RXPKT_OVF                                ((u32)0x00000001 << BIT_SHIFT_RXPKT_OVF)                          /*!<R/W1C 0  When RX Packet is more than 255 packets remaining in FF. Clear by SW. */

/* REG_RXDMA_DPR 0x028C */
#define BIT_SHIFT_RDE_DBG                            0
#define BIT_MASK_RDE_DBG                             ((u32)0xFFFFFFFF << BIT_SHIFT_RDE_DBG)                            /*!<R 0  rde debug port register. */

/* REG_RXDMA_MODE 0x0290 */

#define BIT_SHIFT_RXDMA_GCLK_EN                      6
#define BIT_RXDMA_GCLK_EN                            ((u32)0x00000001 << BIT_SHIFT_RXDMA_GCLK_EN)                      /*!<R/W 1  rxdma_engine clock gating control��1��enable clock gating��0��disable clock gating */
#define BIT_SHIFT_BURST_SIZE                         4
#define BIT_MASK_BURST_SIZE                          ((u32)0x00000003 << BIT_SHIFT_BURST_SIZE)                         /*!<R/W 0  Every burst pkt len 2��b00 : 1KB 2��b01 : 512B 2��b10 : 64B Others : 64B P.S. USB 3.0 must set : 0x00 USB 2.0 High-speed must set : 0x01 USB 2.0 Full-speed must set : 0x10 */
#define BIT_SHIFT_BURST_CNT                          2
#define BIT_MASK_BURST_CNT                           ((u32)0x00000003 << BIT_SHIFT_BURST_CNT)                          /*!<R/W 1  Burst number in dma mode, support at most 4burst(2��b11) P.S, DD suggest 0x11 */
#define BIT_SHIFT_DMA_MODE                           1
#define BIT_DMA_MODE                                 ((u32)0x00000001 << BIT_SHIFT_DMA_MODE)                           /*!<R/W 0  For usb use dma mode; for pcie clr this bit ; for SDIO use Rx DMA Aggregation mode */
#define BIT_SHIFT_MASK_RX_PKT_PS                     0
#define BIT_MASK_RX_PKT_PS                           ((u32)0x00000001 << BIT_SHIFT_MASK_RX_PKT_PS)                     /*!<R/W 0  RSVD */

/* REG_C2H_PKT 0x0294 */

#define BIT_SHIFT_R_C2H_PKT_REQ                      16
#define BIT_R_C2H_PKT_REQ                            ((u32)0x00000001 << BIT_SHIFT_R_C2H_PKT_REQ)                      /*!<R/W 0  C2h packet dma request */
#define BIT_SHIFT_R_C2H_STR_ADDR                     0
#define BIT_MASK_R_C2H_STR_ADDR                      ((u32)0x0000FFFF << BIT_SHIFT_R_C2H_STR_ADDR)                     /*!<R/W 0  C2h packet start address */

/* REG_DDMA_CH0SA 0x1200 */
#define BIT_SHIFT_DDMACH0_SA                         0
#define BIT_MASK_DDMACH0_SA                          ((u32)0xFFFFFFFF << BIT_SHIFT_DDMACH0_SA)                         /*!<R/W 0  Source Address: the source SRAM address that DDMA will read from. This address bus support byte alignment. */

/* REG_DDMA_CH0DA 0x1204 */
#define BIT_SHIFT_DDMACH0_DA                         0
#define BIT_MASK_DDMACH0_DA                          ((u32)0xFFFFFFFF << BIT_SHIFT_DDMACH0_DA)                         /*!<R/W 0  Destination Address: This address bus support byte alignment. */

/* REG_DDMA_CH0CTRL 0x1208 */
#define BIT_SHIFT_DDMACH0_OWN                        31
#define BIT_DDMACH0_OWN                              ((u32)0x00000001 << BIT_SHIFT_DDMACH0_OWN)                        /*!<R/W 0  Set ��1�� by firmware/driver to denote this DMA channel info is ready for DMA engine to begin DMA activity; after DMA complete, DMA engine will clear it to ��0�� to denote for firmware that this channel is standby again. */
#define BIT_SHIFT_DDMACH0_IDMEM_ERR                  30
#define BIT_DDMACH0_IDMEM_ERR                        ((u32)0x00000001 << BIT_SHIFT_DDMACH0_IDMEM_ERR)                  /*!<R/W 0  1: Ddma I/D MEM fail. Please check 0x80[0]=1 or DMEM protection is release 0: No error */
#define BIT_SHIFT_DDMACH0_CHKSUM_EN                  29
#define BIT_DDMACH0_CHKSUM_EN                        ((u32)0x00000001 << BIT_SHIFT_DDMACH0_CHKSUM_EN)                  /*!<R/W 0  16bits Exclusive OR checksum enable */
#define BIT_SHIFT_DDMACH0_DA_W_DISABLE               28
#define BIT_DDMACH0_DA_W_DISABLE                     ((u32)0x00000001 << BIT_SHIFT_DDMACH0_DA_W_DISABLE)               /*!<R/W 0  DA write disable When DDMACH0_CHKSUM_EN=1, DDMACH0_DA_W_DISABLE = 1 means that DMA engine doesn��t move pkt to destination but executes checksum only and report status to DDMACH0_CHKSUM_STS. */
#define BIT_SHIFT_DDMACH0_CHKSUM_STS                 27
#define BIT_DDMACH0_CHKSUM_STS                       ((u32)0x00000001 << BIT_SHIFT_DDMACH0_CHKSUM_STS)                 /*!<R/W1C 0  0: Exclusive OR checksum ok 1: Exclusive OR checksum fail */
#define BIT_SHIFT_DDMACH0_DDMAMODE                   26
#define BIT_DDMACH0_DDMAMODE                         ((u32)0x00000001 << BIT_SHIFT_DDMACH0_DDMAMODE)                   /*!<R/W 0  0: access DMEM/IMEM using cpu idle time slot 1: access DMEM/IMEM block cpu */
#define BIT_SHIFT_DDMACH0_RESET_CHKSUM_STS           25
#define BIT_DDMACH0_RESET_CHKSUM_STS                 ((u32)0x00000001 << BIT_SHIFT_DDMACH0_RESET_CHKSUM_STS)           /*!<R/W 0  Write 1 to clear DDMACH0_CHKSUM_STS when download fw fail */
#define BIT_SHIFT_DDMACH0_CHKSUM_CONT                24
#define BIT_DDMACH0_CHKSUM_CONT                      ((u32)0x00000001 << BIT_SHIFT_DDMACH0_CHKSUM_CONT)                /*!<R/W 0  Set1, hw will continuously check sum in several ddma bursts */

#define BIT_SHIFT_DDMACH0_DLEN                       0
#define BIT_MASK_DDMACH0_DLEN                        ((u32)0x0003FFFF << BIT_SHIFT_DDMACH0_DLEN)                       /*!<R/W 0  DMA Length: Length count served by DMA engine, unit in 1 bytes. The range is from 1 to 256K. */

/* REG_DDMA_CH1SA 0x1210 */
#define BIT_SHIFT_DDMACH1_SA                         0
#define BIT_MASK_DDMACH1_SA                          ((u32)0xFFFFFFFF << BIT_SHIFT_DDMACH1_SA)                         /*!<R/W 0  Source Address: the source SRAM address that DDMA will read from. This address bus support byte alignment. */

/* REG_DDMA_CH1DA 0x1214 */
#define BIT_SHIFT_DDMACH1_DA                         0
#define BIT_MASK_DDMACH1_DA                          ((u32)0xFFFFFFFF << BIT_SHIFT_DDMACH1_DA)                         /*!<R/W 0  Destination Address: This address bus support byte alignment. */

/* REG_DDMA_CH1CTRL 0x1218 */
#define BIT_SHIFT_DDMACH1_OWN                        31
#define BIT_DDMACH1_OWN                              ((u32)0x00000001 << BIT_SHIFT_DDMACH1_OWN)                        /*!<R/W 0  Set ��1�� by firmware/driver to denote this DMA channel info is ready for DMA engine to begin DMA activity; after DMA complete, DMA engine will clear it to ��0�� to denote for firmware that this channel is standby again. */
#define BIT_SHIFT_DDMACH1_IDMEM_ERR                  30
#define BIT_DDMACH1_IDMEM_ERR                        ((u32)0x00000001 << BIT_SHIFT_DDMACH1_IDMEM_ERR)                  /*!<R/W 0  1: Ddma I/D MEM fail. Please check 0x80[0]=1 or DMEM protection is release 0: No error */
#define BIT_SHIFT_DDMACH1_CHKSUM_EN                  29
#define BIT_DDMACH1_CHKSUM_EN                        ((u32)0x00000001 << BIT_SHIFT_DDMACH1_CHKSUM_EN)                  /*!<R/W 0  16bits Exclusive OR checksum enable */
#define BIT_SHIFT_DDMACH1_DA_W_DISABLE               28
#define BIT_DDMACH1_DA_W_DISABLE                     ((u32)0x00000001 << BIT_SHIFT_DDMACH1_DA_W_DISABLE)               /*!<R/W 0  DA write disable When DDMACH1_CHKSUM_EN=1, DDMACH1_DA_W_DISABLE = 1 means that DMA engine doesn��t move pkt to destination but executes checksum only and report status to DDMACH1_CHKSUM_STS. */
#define BIT_SHIFT_DDMACH1_CHKSUM_STS                 27
#define BIT_DDMACH1_CHKSUM_STS                       ((u32)0x00000001 << BIT_SHIFT_DDMACH1_CHKSUM_STS)                 /*!<R/W1C 0  0: Exclusive OR checksum ok 1: Exclusive OR checksum fail */
#define BIT_SHIFT_DDMACH1_DDMAMODE                   26
#define BIT_DDMACH1_DDMAMODE                         ((u32)0x00000001 << BIT_SHIFT_DDMACH1_DDMAMODE)                   /*!<R/W 0  0: access DMEM/IMEM using cpu idle time slot 1: access DMEM/IMEM block cpu */
#define BIT_SHIFT_DDMACH1_RESET_CHKSUM_STS           25
#define BIT_DDMACH1_RESET_CHKSUM_STS                 ((u32)0x00000001 << BIT_SHIFT_DDMACH1_RESET_CHKSUM_STS)           /*!<R/W 0  Write 1 to clear DDMACH1_CHKSUM_STS when download fw fail */
#define BIT_SHIFT_DDMACH1_CHKSUM_CONT                24
#define BIT_DDMACH1_CHKSUM_CONT                      ((u32)0x00000001 << BIT_SHIFT_DDMACH1_CHKSUM_CONT)                /*!<R/W 0  Set1, hw will continuously check sum in several ddma bursts */

#define BIT_SHIFT_DDMACH1_DLEN                       0
#define BIT_MASK_DDMACH1_DLEN                        ((u32)0x0003FFFF << BIT_SHIFT_DDMACH1_DLEN)                       /*!<R/W 0  DMA Length: Length count served by DMA engine, unit in 1 bytes. The range is from 1 to 256K. */

/* REG_DDMA_CH2SA 0x1220 */
#define BIT_SHIFT_DDMACH2_SA                         0
#define BIT_MASK_DDMACH2_SA                          ((u32)0xFFFFFFFF << BIT_SHIFT_DDMACH2_SA)                         /*!<R/W 0  Source Address: the source SRAM address that DDMA will read from. This address bus support byte alignment. */

/* REG_DDMA_CH2DA 0x1224 */
#define BIT_SHIFT_DDMACH2_DA                         0
#define BIT_MASK_DDMACH2_DA                          ((u32)0xFFFFFFFF << BIT_SHIFT_DDMACH2_DA)                         /*!<R/W 0  Destination Address: This address bus support byte alignment. */

/* REG_DDMA_CH2CTRL 0x1228 */
#define BIT_SHIFT_DDMACH2_OWN                        31
#define BIT_DDMACH2_OWN                              ((u32)0x00000001 << BIT_SHIFT_DDMACH2_OWN)                        /*!<R/W 0  Set ��1�� by firmware/driver to denote this DMA channel info is ready for DMA engine to begin DMA activity; after DMA complete, DMA engine will clear it to ��0�� to denote for firmware that this channel is standby again. */
#define BIT_SHIFT_DDMACH2_IDMEM_ERR                  30
#define BIT_DDMACH2_IDMEM_ERR                        ((u32)0x00000001 << BIT_SHIFT_DDMACH2_IDMEM_ERR)                  /*!<R/W 0  1: Ddma I/D MEM fail. Please check 0x80[0]=1 or DMEM protection is release 0: No error */
#define BIT_SHIFT_DDMACH2_CHKSUM_EN                  29
#define BIT_DDMACH2_CHKSUM_EN                        ((u32)0x00000001 << BIT_SHIFT_DDMACH2_CHKSUM_EN)                  /*!<R/W 0  16bits Exclusive OR checksum enable */
#define BIT_SHIFT_DDMACH2_DA_W_DISABLE               28
#define BIT_DDMACH2_DA_W_DISABLE                     ((u32)0x00000001 << BIT_SHIFT_DDMACH2_DA_W_DISABLE)               /*!<R/W 0  DA write disable When DDMACH2_CHKSUM_EN=1, DDMACH2_DA_W_DISABLE = 1 means that DMA engine doesn��t move pkt to destination but executes checksum only and report status to DDMACH2_CHKSUM_STS. */
#define BIT_SHIFT_DDMACH2_CHKSUM_STS                 27
#define BIT_DDMACH2_CHKSUM_STS                       ((u32)0x00000001 << BIT_SHIFT_DDMACH2_CHKSUM_STS)                 /*!<R/W1C 0  0: Exclusive OR checksum ok 1: Exclusive OR checksum fail */
#define BIT_SHIFT_DDMACH2_DDMAMODE                   26
#define BIT_DDMACH2_DDMAMODE                         ((u32)0x00000001 << BIT_SHIFT_DDMACH2_DDMAMODE)                   /*!<R/W 0  0: access DMEM/IMEM using cpu idle time slot 1: access DMEM/IMEM block cpu */
#define BIT_SHIFT_DDMACH2_RESET_CHKSUM_STS           25
#define BIT_DDMACH2_RESET_CHKSUM_STS                 ((u32)0x00000001 << BIT_SHIFT_DDMACH2_RESET_CHKSUM_STS)           /*!<R/W 0  Write 1 to clear DDMACH2_CHKSUM_STS when download fw fail */
#define BIT_SHIFT_DDMACH2_CHKSUM_CONT                24
#define BIT_DDMACH2_CHKSUM_CONT                      ((u32)0x00000001 << BIT_SHIFT_DDMACH2_CHKSUM_CONT)                /*!<R/W 0  Set1, hw will continuously check sum in several ddma bursts */

#define BIT_SHIFT_DDMACH2_DLEN                       0
#define BIT_MASK_DDMACH2_DLEN                        ((u32)0x0003FFFF << BIT_SHIFT_DDMACH2_DLEN)                       /*!<R/W 0  DMA Length: Length count served by DMA engine, unit in 1 bytes. The range is from 1 to 256K. */

/* REG_DDMA_CH3SA 0x1230 */
#define BIT_SHIFT_DDMACH3_SA                         0
#define BIT_MASK_DDMACH3_SA                          ((u32)0xFFFFFFFF << BIT_SHIFT_DDMACH3_SA)                         /*!<R/W 0  Source Address: the source SRAM address that DDMA will read from. This address bus support byte alignment. */

/* REG_DDMA_CH3DA 0x1234 */
#define BIT_SHIFT_DDMACH3_DA                         0
#define BIT_MASK_DDMACH3_DA                          ((u32)0xFFFFFFFF << BIT_SHIFT_DDMACH3_DA)                         /*!<R/W 0  Destination Address: This address bus support byte alignment. */

/* REG_DDMA_CH3CTRL 0x1238 */
#define BIT_SHIFT_DDMACH3_OWN                        31
#define BIT_DDMACH3_OWN                              ((u32)0x00000001 << BIT_SHIFT_DDMACH3_OWN)                        /*!<R/W 0  Set ��1�� by firmware/driver to denote this DMA channel info is ready for DMA engine to begin DMA activity; after DMA complete, DMA engine will clear it to ��0�� to denote for firmware that this channel is standby again. */
#define BIT_SHIFT_DDMACH3_IDMEM_ERR                  30
#define BIT_DDMACH3_IDMEM_ERR                        ((u32)0x00000001 << BIT_SHIFT_DDMACH3_IDMEM_ERR)                  /*!<R/W 0  1: Ddma I/D MEM fail. Please check 0x80[0]=1 or DMEM protection is release 0: No error */
#define BIT_SHIFT_DDMACH3_CHKSUM_EN                  29
#define BIT_DDMACH3_CHKSUM_EN                        ((u32)0x00000001 << BIT_SHIFT_DDMACH3_CHKSUM_EN)                  /*!<R/W 0  16bits Exclusive OR checksum enable */
#define BIT_SHIFT_DDMACH3_DA_W_DISABLE               28
#define BIT_DDMACH3_DA_W_DISABLE                     ((u32)0x00000001 << BIT_SHIFT_DDMACH3_DA_W_DISABLE)               /*!<R/W 0  DA write disable When DDMACH3_CHKSUM_EN=1, DDMACH3_DA_W_DISABLE = 1 means that DMA engine doesn��t move pkt to destination but executes checksum only and report status to DDMACH3_CHKSUM_STS. */
#define BIT_SHIFT_DDMACH3_CHKSUM_STS                 27
#define BIT_DDMACH3_CHKSUM_STS                       ((u32)0x00000001 << BIT_SHIFT_DDMACH3_CHKSUM_STS)                 /*!<R/W1C 0  0: Exclusive OR checksum ok 1: Exclusive OR checksum fail */
#define BIT_SHIFT_DDMACH3_DDMAMODE                   26
#define BIT_DDMACH3_DDMAMODE                         ((u32)0x00000001 << BIT_SHIFT_DDMACH3_DDMAMODE)                   /*!<R/W 0  0: access DMEM/IMEM using cpu idle time slot 1: access DMEM/IMEM block cpu */
#define BIT_SHIFT_DDMACH3_RESET_CHKSUM_STS           25
#define BIT_DDMACH3_RESET_CHKSUM_STS                 ((u32)0x00000001 << BIT_SHIFT_DDMACH3_RESET_CHKSUM_STS)           /*!<R/W 0  Write 1 to clear DDMACH3_CHKSUM_STS when download fw fail */
#define BIT_SHIFT_DDMACH3_CHKSUM_CONT                24
#define BIT_DDMACH3_CHKSUM_CONT                      ((u32)0x00000001 << BIT_SHIFT_DDMACH3_CHKSUM_CONT)                /*!<R/W 0  Set1, hw will continuously check sum in several ddma bursts */

#define BIT_SHIFT_DDMACH3_DLEN                       0
#define BIT_MASK_DDMACH3_DLEN                        ((u32)0x0003FFFF << BIT_SHIFT_DDMACH3_DLEN)                       /*!<R/W 0  DMA Length: Length count served by DMA engine, unit in 1 bytes. The range is from 1 to 256K. */

/* REG_DDMA_CH4SA 0x1240 */
#define BIT_SHIFT_DDMACH4_SA                         0
#define BIT_MASK_DDMACH4_SA                          ((u32)0xFFFFFFFF << BIT_SHIFT_DDMACH4_SA)                         /*!<R/W 0  Source Address: the source SRAM address that DDMA will read from. This address bus support byte alignment. */

/* REG_DDMA_CH4DA 0x1244 */
#define BIT_SHIFT_DDMACH4_DA                         0
#define BIT_MASK_DDMACH4_DA                          ((u32)0xFFFFFFFF << BIT_SHIFT_DDMACH4_DA)                         /*!<R/W 0  Destination Address: This address bus support byte alignment. */

/* REG_DDMA_CH4CTRL 0x1248 */
#define BIT_SHIFT_DDMACH4_OWN                        31
#define BIT_DDMACH4_OWN                              ((u32)0x00000001 << BIT_SHIFT_DDMACH4_OWN)                        /*!<R/W 0  Set ��1�� by firmware/driver to denote this DMA channel info is ready for DMA engine to begin DMA activity; after DMA complete, DMA engine will clear it to ��0�� to denote for firmware that this channel is standby again. */
#define BIT_SHIFT_DDMACH4_IDMEM_ERR                  30
#define BIT_DDMACH4_IDMEM_ERR                        ((u32)0x00000001 << BIT_SHIFT_DDMACH4_IDMEM_ERR)                  /*!<R/W 0  1: Ddma I/D MEM fail. Please check 0x80[0]=1 or DMEM protection is release 0: No error */
#define BIT_SHIFT_DDMACH4_CHKSUM_EN                  29
#define BIT_DDMACH4_CHKSUM_EN                        ((u32)0x00000001 << BIT_SHIFT_DDMACH4_CHKSUM_EN)                  /*!<R/W 0  16bits Exclusive OR checksum enable */
#define BIT_SHIFT_DDMACH4_DA_W_DISABLE               28
#define BIT_DDMACH4_DA_W_DISABLE                     ((u32)0x00000001 << BIT_SHIFT_DDMACH4_DA_W_DISABLE)               /*!<R/W 0  DA write disable When DDMACH4_CHKSUM_EN=1, DDMACH4_DA_W_DISABLE = 1 means that DMA engine doesn��t move pkt to destination but executes checksum only and report status to DDMACH4_CHKSUM_STS. */
#define BIT_SHIFT_DDMACH4_CHKSUM_STS                 27
#define BIT_DDMACH4_CHKSUM_STS                       ((u32)0x00000001 << BIT_SHIFT_DDMACH4_CHKSUM_STS)                 /*!<R/W1C 0  0: Exclusive OR checksum ok 1: Exclusive OR checksum fail */
#define BIT_SHIFT_DDMACH4_DDMAMODE                   26
#define BIT_DDMACH4_DDMAMODE                         ((u32)0x00000001 << BIT_SHIFT_DDMACH4_DDMAMODE)                   /*!<R/W 0  0: access DMEM/IMEM using cpu idle time slot 1: access DMEM/IMEM block cpu */
#define BIT_SHIFT_DDMACH4_RESET_CHKSUM_STS           25
#define BIT_DDMACH4_RESET_CHKSUM_STS                 ((u32)0x00000001 << BIT_SHIFT_DDMACH4_RESET_CHKSUM_STS)           /*!<R/W 0  Write 1 to clear DDMACH4_CHKSUM_STS when download fw fail */
#define BIT_SHIFT_DDMACH4_CHKSUM_CONT                24
#define BIT_DDMACH4_CHKSUM_CONT                      ((u32)0x00000001 << BIT_SHIFT_DDMACH4_CHKSUM_CONT)                /*!<R/W 0  Set1, hw will continuously check sum in several ddma bursts */

#define BIT_SHIFT_DDMACH4_DLEN                       0
#define BIT_MASK_DDMACH4_DLEN                        ((u32)0x0003FFFF << BIT_SHIFT_DDMACH4_DLEN)                       /*!<R/W 0  DMA Length: Length count served by DMA engine, unit in 1 bytes. The range is from 1 to 256K. */

/* REG_DDMA_CH5SA 0x1250 */
#define BIT_SHIFT_DDMACH5_SA                         0
#define BIT_MASK_DDMACH5_SA                          ((u32)0xFFFFFFFF << BIT_SHIFT_DDMACH5_SA)                         /*!<R/W 0  Source Address: the source SRAM address that DDMA will read from. This address bus support byte alignment. */

/* REG_DDMA_CH5DA 0x1254 */
#define BIT_SHIFT_DDMACH5_DA                         0
#define BIT_MASK_DDMACH5_DA                          ((u32)0xFFFFFFFF << BIT_SHIFT_DDMACH5_DA)                         /*!<R/W 0  Destination Address: This address bus support byte alignment. */

/* REG_DDMA_CH5CTRL 0x1258 */
#define BIT_SHIFT_DDMACH5_OWN                        31
#define BIT_DDMACH5_OWN                              ((u32)0x00000001 << BIT_SHIFT_DDMACH5_OWN)                        /*!<R/W 0  Set ��1�� by firmware/driver to denote this DMA channel info is ready for DMA engine to begin DMA activity; after DMA complete, DMA engine will clear it to ��0�� to denote for firmware that this channel is standby again. */
#define BIT_SHIFT_DDMACH5_IDMEM_ERR                  30
#define BIT_DDMACH5_IDMEM_ERR                        ((u32)0x00000001 << BIT_SHIFT_DDMACH5_IDMEM_ERR)                  /*!<R/W 0  1: Ddma I/D MEM fail. Please check 0x80[0]=1 or DMEM protection is release 0: No error */
#define BIT_SHIFT_DDMACH5_CHKSUM_EN                  29
#define BIT_DDMACH5_CHKSUM_EN                        ((u32)0x00000001 << BIT_SHIFT_DDMACH5_CHKSUM_EN)                  /*!<R/W 0  16bits Exclusive OR checksum enable */
#define BIT_SHIFT_DDMACH5_DA_W_DISABLE               28
#define BIT_DDMACH5_DA_W_DISABLE                     ((u32)0x00000001 << BIT_SHIFT_DDMACH5_DA_W_DISABLE)               /*!<R/W 0  DA write disable When DDMACH5_CHKSUM_EN=1, DDMACH5_DA_W_DISABLE = 1 means that DMA engine doesn��t move pkt to destination but executes checksum only and report status to DDMACH5_CHKSUM_STS. */
#define BIT_SHIFT_DDMACH5_CHKSUM_STS                 27
#define BIT_DDMACH5_CHKSUM_STS                       ((u32)0x00000001 << BIT_SHIFT_DDMACH5_CHKSUM_STS)                 /*!<R/W1C 0  0: Exclusive OR checksum ok 1: Exclusive OR checksum fail */
#define BIT_SHIFT_DDMACH5_DDMAMODE                   26
#define BIT_DDMACH5_DDMAMODE                         ((u32)0x00000001 << BIT_SHIFT_DDMACH5_DDMAMODE)                   /*!<R/W 0  0: access DMEM/IMEM using cpu idle time slot 1: access DMEM/IMEM block cpu */
#define BIT_SHIFT_DDMACH5_RESET_CHKSUM_STS           25
#define BIT_DDMACH5_RESET_CHKSUM_STS                 ((u32)0x00000001 << BIT_SHIFT_DDMACH5_RESET_CHKSUM_STS)           /*!<R/W 0  Write 1 to clear DDMACH5_CHKSUM_STS when download fw fail */
#define BIT_SHIFT_DDMACH5_CHKSUM_CONT                24
#define BIT_DDMACH5_CHKSUM_CONT                      ((u32)0x00000001 << BIT_SHIFT_DDMACH5_CHKSUM_CONT)                /*!<R/W 0  Set1, hw will continuously check sum in several ddma bursts */

#define BIT_SHIFT_DDMACH5_DLEN                       0
#define BIT_MASK_DDMACH5_DLEN                        ((u32)0x0003FFFF << BIT_SHIFT_DDMACH5_DLEN)                       /*!<R/W 0  DMA Length: Length count served by DMA engine, unit in 1 bytes. The range is from 1 to 256K. */

/* REG_DDMA_INT_MSK 0x12E0 */

#define BIT_SHIFT_DDMACH5_MSK                        5
#define BIT_DDMACH5_MSK                              ((u32)0x00000001 << BIT_SHIFT_DDMACH5_MSK)                        /*!<R/W 0  When this bit is set, this DDMA channel will generate interrupt when the DMA done. FW may check the DDMA_CHSTATUS register to determine the DDMA status. */
#define BIT_SHIFT_DDMACH4_MSK                        4
#define BIT_DDMACH4_MSK                              ((u32)0x00000001 << BIT_SHIFT_DDMACH4_MSK)                        /*!<R/W 0  When this bit is set, this DDMA channel will generate interrupt when the DMA done. FW may check the DDMA_CHSTATUS register to determine the DDMA status. */
#define BIT_SHIFT_DDMACH3_MSK                        3
#define BIT_DDMACH3_MSK                              ((u32)0x00000001 << BIT_SHIFT_DDMACH3_MSK)                        /*!<R/W 0  When this bit is set, this DDMA channel will generate interrupt when the DMA done. FW may check the DDMA_CHSTATUS register to determine the DDMA status. */
#define BIT_SHIFT_DDMACH2_MSK                        2
#define BIT_DDMACH2_MSK                              ((u32)0x00000001 << BIT_SHIFT_DDMACH2_MSK)                        /*!<R/W 0  When this bit is set, this DDMA channel will generate interrupt when the DMA done. FW may check the DDMA_CHSTATUS register to determine the DDMA status. */
#define BIT_SHIFT_DDMACH1_MSK                        1
#define BIT_DDMACH1_MSK                              ((u32)0x00000001 << BIT_SHIFT_DDMACH1_MSK)                        /*!<R/W 0  When this bit is set, this DDMA channel will generate interrupt when the DMA done. FW may check the DDMA_CHSTATUS register to determine the DDMA status. */
#define BIT_SHIFT_DDMACH0_MSK                        0
#define BIT_DDMACH0_MSK                              ((u32)0x00000001 << BIT_SHIFT_DDMACH0_MSK)                        /*!<R/W 0  When this bit is set, this DDMA channel will generate interrupt when the DMA done. FW may check the DDMA_CHSTATUS register to determine the DDMA status. */

/* REG_DDMA_INT_STS 0x12E4 */

#define BIT_SHIFT_DDMACH5_DDMA_DONE                  5
#define BIT_DDMACH5_DDMA_DONE                        ((u32)0x00000001 << BIT_SHIFT_DDMACH5_DDMA_DONE)                  /*!<R/W 0  When this bit is set, this DDMA channel will generate interrupt when the DMA done. */
#define BIT_SHIFT_DDMACH4_DDMA_DONE                  4
#define BIT_DDMACH4_DDMA_DONE                        ((u32)0x00000001 << BIT_SHIFT_DDMACH4_DDMA_DONE)                  /*!<R/W 0  When this bit is set, this DDMA channel will generate interrupt when the DMA done. */
#define BIT_SHIFT_DDMACH3_DDMA_DONE                  3
#define BIT_DDMACH3_DDMA_DONE                        ((u32)0x00000001 << BIT_SHIFT_DDMACH3_DDMA_DONE)                  /*!<R/W 0  When this bit is set, this DDMA channel will generate interrupt when the DMA done. */
#define BIT_SHIFT_DDMACH2_DDMA_DONE                  2
#define BIT_DDMACH2_DDMA_DONE                        ((u32)0x00000001 << BIT_SHIFT_DDMACH2_DDMA_DONE)                  /*!<R/W 0  When this bit is set, this DDMA channel will generate interrupt when the DMA done. */
#define BIT_SHIFT_DDMACH1_DDMA_DONE                  1
#define BIT_DDMACH1_DDMA_DONE                        ((u32)0x00000001 << BIT_SHIFT_DDMACH1_DDMA_DONE)                  /*!<R/W 0  When this bit is set, this DDMA channel will generate interrupt when the DMA done. */
#define BIT_SHIFT_DDMACH0_DDMA_DONE                  0
#define BIT_DDMACH0_DDMA_DONE                        ((u32)0x00000001 << BIT_SHIFT_DDMACH0_DDMA_DONE)                  /*!<R/W 0  When this bit is set, this DDMA channel will generate interrupt when the DMA done. */

/* REG_DDMA_CHSTATUS 0x12E8 */

#define BIT_SHIFT_DDMACH5_REQ                        5
#define BIT_DDMACH5_REQ                              ((u32)0x00000001 << BIT_SHIFT_DDMACH5_REQ)                        /*!<R 0  After CH5CTRL.OWN bit is polled, DDMA starts and asserts this bit. After the DMA transactions finish, this bit is de-asserted. */
#define BIT_SHIFT_DDMACH4_REQ                        4
#define BIT_DDMACH4_REQ                              ((u32)0x00000001 << BIT_SHIFT_DDMACH4_REQ)                        /*!<R 0  After CH4CTRL.OWN bit is polled, DDMA starts and asserts this bit. After the DMA transactions finish, this bit is de-asserted. */
#define BIT_SHIFT_DDMACH3_REQ                        3
#define BIT_DDMACH3_REQ                              ((u32)0x00000001 << BIT_SHIFT_DDMACH3_REQ)                        /*!<R 0  After CH3CTRL.OWN bit is polled, DDMA starts and asserts this bit. After the DMA transactions finish, this bit is de-asserted. */
#define BIT_SHIFT_DDMACH2_REQ                        2
#define BIT_DDMACH2_REQ                              ((u32)0x00000001 << BIT_SHIFT_DDMACH2_REQ)                        /*!<R 0  After CH2CTRL.OWN bit is polled, DDMA starts and asserts this bit. After the DMA transactions finish, this bit is de-asserted. */
#define BIT_SHIFT_DDMACH1_REQ                        1
#define BIT_DDMACH1_REQ                              ((u32)0x00000001 << BIT_SHIFT_DDMACH1_REQ)                        /*!<R 0  After CH1CTRL.OWN bit is polled, DDMA starts and asserts this bit. After the DMA transactions finish, this bit is de-asserted. */
#define BIT_SHIFT_DDMACH0_REQ                        0
#define BIT_DDMACH0_REQ                              ((u32)0x00000001 << BIT_SHIFT_DDMACH0_REQ)                        /*!<R 0  After CH0CTRL.OWN bit is polled, DDMA starts and asserts this bit. After the DMA transactions finish, this bit is de-asserted. */

/* REG_DDMA_CHKSUM 0x12F0 */

#define BIT_SHIFT_DDMA_DST_CS                        22
#define BIT_MASK_DDMA_DST_CS                         ((u32)0x00000003 << BIT_SHIFT_DDMA_DST_CS)                        /*!<R 0  ddma_dst_ctl current status */
#define BIT_SHIFT_DDMA_SRC_CS                        20
#define BIT_MASK_DDMA_SRC_CS                         ((u32)0x00000003 << BIT_SHIFT_DDMA_SRC_CS)                        /*!<R 0  ddma_src_ctl current status */
#define BIT_SHIFT_DDMA_ARB_CS                        16
#define BIT_MASK_DDMA_ARB_CS                         ((u32)0x0000000F << BIT_SHIFT_DDMA_ARB_CS)                        /*!<R 0  ddma_arb_ctl current status */
#define BIT_SHIFT_IDDMA0_CHKSUM                      0
#define BIT_MASK_IDDMA0_CHKSUM                       ((u32)0x0000FFFF << BIT_SHIFT_IDDMA0_CHKSUM)                      /*!<R 0  Iddma0 Check sum Result */

/* REG_DDMA_MONITOR 0x12FC */

#define BIT_SHIFT_IDDMA0_PERMU_UNDERFLOW             14
#define BIT_IDDMA0_PERMU_UNDERFLOW                   ((u32)0x00000001 << BIT_SHIFT_IDDMA0_PERMU_UNDERFLOW)             /*!<R/W1C 0  IDDMA0 permu underflow,, write clear */
#define BIT_SHIFT_IDDMA0_FIFO_UNDERFLOW              13
#define BIT_IDDMA0_FIFO_UNDERFLOW                    ((u32)0x00000001 << BIT_SHIFT_IDDMA0_FIFO_UNDERFLOW)              /*!<R/W1C 0  IDDMA0 fifo underflow, write clear */
#define BIT_SHIFT_IDDMA0_FIFO_OVERFLOW               12
#define BIT_IDDMA0_FIFO_OVERFLOW                     ((u32)0x00000001 << BIT_SHIFT_IDDMA0_FIFO_OVERFLOW)               /*!<R/W1C 0  IDDMA0 fifo overflow, write clear */

#define BIT_SHIFT_CH5_ERR                            5
#define BIT_CH5_ERR                                  ((u32)0x00000001 << BIT_SHIFT_CH5_ERR)                            /*!<R/W1C 0  Ch5 is busy when it is set again, write clear */
#define BIT_SHIFT_CH4_ERR                            4
#define BIT_CH4_ERR                                  ((u32)0x00000001 << BIT_SHIFT_CH4_ERR)                            /*!<R/W1C 0  Ch4 is busy when it is set again, write clear */
#define BIT_SHIFT_CH3_ERR                            3
#define BIT_CH3_ERR                                  ((u32)0x00000001 << BIT_SHIFT_CH3_ERR)                            /*!<R/W1C 0  Ch3 is busy when it is set again, write clear */
#define BIT_SHIFT_CH2_ERR                            2
#define BIT_CH2_ERR                                  ((u32)0x00000001 << BIT_SHIFT_CH2_ERR)                            /*!<R/W1C 0  Ch2 is busy when it is set again, write clear */
#define BIT_SHIFT_CH1_ERR                            1
#define BIT_CH1_ERR                                  ((u32)0x00000001 << BIT_SHIFT_CH1_ERR)                            /*!<R/W1C 0  Ch1 is busy when it is set again, write clear */
#define BIT_SHIFT_CH0_ERR                            0
#define BIT_CH0_ERR                                  ((u32)0x00000001 << BIT_SHIFT_CH0_ERR)                            /*!<R/W1C 0  Ch0 is busy when it is set again, write clear */

/* REG_Q0_INFO 0x0400 */
#define BIT_SHIFT_QUEUEMACID_Q0_V1                   25
#define BIT_MASK_QUEUEMACID_Q0_V1                    ((u32)0x0000007F << BIT_SHIFT_QUEUEMACID_Q0_V1)                   /*!<R 00h  MacID of head pkt */
#define BIT_SHIFT_QUEUEAC_Q0_V1                      23
#define BIT_MASK_QUEUEAC_Q0_V1                       ((u32)0x00000003 << BIT_SHIFT_QUEUEAC_Q0_V1)                      /*!<R 0h  AC type of Queue 0. */
#define BIT_SHIFT_TAIL_PKT_Q0_V1                     15
#define BIT_MASK_TAIL_PKT_Q0_V1                      ((u32)0x000000FF << BIT_SHIFT_TAIL_PKT_Q0_V1)                     /*!<R FFh  The head page of the last packet of Queue 0. */
#define BIT_SHIFT_PKT_NUM_Q0_V1                      8
#define BIT_MASK_PKT_NUM_Q0_V1                       ((u32)0x0000007F << BIT_SHIFT_PKT_NUM_Q0_V1)                      /*!<R 0h  The total Queue 0 pkt number in TxPktbuffer */
#define BIT_SHIFT_HEAD_PKT_Q0                        0
#define BIT_MASK_HEAD_PKT_Q0                         ((u32)0x000000FF << BIT_SHIFT_HEAD_PKT_Q0)                        /*!<R FFh  The head page of the first packet of Queue 0. */

/* REG_Q1_INFO 0x0404 */
#define BIT_SHIFT_QUEUEMACID_Q1_V1                   25
#define BIT_MASK_QUEUEMACID_Q1_V1                    ((u32)0x0000007F << BIT_SHIFT_QUEUEMACID_Q1_V1)                   /*!<R 00h  MacID of head pkt */
#define BIT_SHIFT_QUEUEAC_Q1_V1                      23
#define BIT_MASK_QUEUEAC_Q1_V1                       ((u32)0x00000003 << BIT_SHIFT_QUEUEAC_Q1_V1)                      /*!<R 0h  AC type of Queue 1. */
#define BIT_SHIFT_TAIL_PKT_Q1_V1                     15
#define BIT_MASK_TAIL_PKT_Q1_V1                      ((u32)0x000000FF << BIT_SHIFT_TAIL_PKT_Q1_V1)                     /*!<R FFh  The head page of the last packet of Queue 1. */
#define BIT_SHIFT_PKT_NUM_Q1_V1                      8
#define BIT_MASK_PKT_NUM_Q1_V1                       ((u32)0x0000007F << BIT_SHIFT_PKT_NUM_Q1_V1)                      /*!<R 0h  The total Queue 1 pkt number in TxPktbuffer */
#define BIT_SHIFT_HEAD_PKT_Q1                        0
#define BIT_MASK_HEAD_PKT_Q1                         ((u32)0x000000FF << BIT_SHIFT_HEAD_PKT_Q1)                        /*!<R FFh  The head page of the first packet of Queue 1. */

/* REG_Q2_INFO 0x0408 */
#define BIT_SHIFT_QUEUEMACID_Q2_V1                   25
#define BIT_MASK_QUEUEMACID_Q2_V1                    ((u32)0x0000007F << BIT_SHIFT_QUEUEMACID_Q2_V1)                   /*!<R 00h  MacID of head pkt */
#define BIT_SHIFT_QUEUEAC_Q2_V1                      23
#define BIT_MASK_QUEUEAC_Q2_V1                       ((u32)0x00000003 << BIT_SHIFT_QUEUEAC_Q2_V1)                      /*!<R 0h  AC type of Queue 2. */
#define BIT_SHIFT_TAIL_PKT_Q2_V1                     15
#define BIT_MASK_TAIL_PKT_Q2_V1                      ((u32)0x000000FF << BIT_SHIFT_TAIL_PKT_Q2_V1)                     /*!<R FFh  The head page of the last packet of Queue 2. */
#define BIT_SHIFT_PKT_NUM_Q2_V1                      8
#define BIT_MASK_PKT_NUM_Q2_V1                       ((u32)0x0000007F << BIT_SHIFT_PKT_NUM_Q2_V1)                      /*!<R 0h  The total Queue 2 pkt number in TxPktbuffer */
#define BIT_SHIFT_HEAD_PKT_Q2                        0
#define BIT_MASK_HEAD_PKT_Q2                         ((u32)0x000000FF << BIT_SHIFT_HEAD_PKT_Q2)                        /*!<R FFh  The head page of the first packet of Queue 2. */

/* REG_Q3_INFO 0x040C */
#define BIT_SHIFT_QUEUEMACID_Q3_V1                   25
#define BIT_MASK_QUEUEMACID_Q3_V1                    ((u32)0x0000007F << BIT_SHIFT_QUEUEMACID_Q3_V1)                   /*!<R 00h  MacID of head pkt */
#define BIT_SHIFT_QUEUEAC_Q3_V1                      23
#define BIT_MASK_QUEUEAC_Q3_V1                       ((u32)0x00000003 << BIT_SHIFT_QUEUEAC_Q3_V1)                      /*!<R 0h  AC type of Queue 3. */
#define BIT_SHIFT_TAIL_PKT_Q3_V1                     15
#define BIT_MASK_TAIL_PKT_Q3_V1                      ((u32)0x000000FF << BIT_SHIFT_TAIL_PKT_Q3_V1)                     /*!<R FFh  The head page of the last packet of Queue 3. */
#define BIT_SHIFT_PKT_NUM_Q3_V1                      8
#define BIT_MASK_PKT_NUM_Q3_V1                       ((u32)0x0000007F << BIT_SHIFT_PKT_NUM_Q3_V1)                      /*!<R 0h  The total Queue 3 pkt number in TxPktbuffer */
#define BIT_SHIFT_HEAD_PKT_Q3                        0
#define BIT_MASK_HEAD_PKT_Q3                         ((u32)0x000000FF << BIT_SHIFT_HEAD_PKT_Q3)                        /*!<R FFh  The head page of the first packet of Queue 3. */

/* REG_MGQ_INFO 0x0410 */
#define BIT_SHIFT_QUEUEMACID_MGQ_V1                  25
#define BIT_MASK_QUEUEMACID_MGQ_V1                   ((u32)0x0000007F << BIT_SHIFT_QUEUEMACID_MGQ_V1)                  /*!<R 00h  MacID of head pkt */
#define BIT_SHIFT_QUEUEAC_MGQ_V1                     23
#define BIT_MASK_QUEUEAC_MGQ_V1                      ((u32)0x00000003 << BIT_SHIFT_QUEUEAC_MGQ_V1)                     /*!<R 0h  AC type of management Queue. */
#define BIT_SHIFT_TAIL_PKT_MGQ_V1                    15
#define BIT_MASK_TAIL_PKT_MGQ_V1                     ((u32)0x000000FF << BIT_SHIFT_TAIL_PKT_MGQ_V1)                    /*!<R FFh  The head page of the last packet of MGQ. */
#define BIT_SHIFT_PKT_NUM_MGQ_V1                     8
#define BIT_MASK_PKT_NUM_MGQ_V1                      ((u32)0x0000007F << BIT_SHIFT_PKT_NUM_MGQ_V1)                     /*!<R 0h  The total MGQ pkt number in TxPktbuffer */
#define BIT_SHIFT_HEAD_PKT_MGQ                       0
#define BIT_MASK_HEAD_PKT_MGQ                        ((u32)0x000000FF << BIT_SHIFT_HEAD_PKT_MGQ)                       /*!<R FFh  The head page of the first packet of MGQ. */

/* REG_HIQ_INFO 0x0414 */
#define BIT_SHIFT_QUEUEMACID_HIQ_V1                  25
#define BIT_MASK_QUEUEMACID_HIQ_V1                   ((u32)0x0000007F << BIT_SHIFT_QUEUEMACID_HIQ_V1)                  /*!<R 00h  MacID of head pkt */
#define BIT_SHIFT_QUEUEAC_HIQ_V1                     23
#define BIT_MASK_QUEUEAC_HIQ_V1                      ((u32)0x00000003 << BIT_SHIFT_QUEUEAC_HIQ_V1)                     /*!<R 0h  AC type of High Queue. */
#define BIT_SHIFT_TAIL_PKT_HIQ_V1                    15
#define BIT_MASK_TAIL_PKT_HIQ_V1                     ((u32)0x000000FF << BIT_SHIFT_TAIL_PKT_HIQ_V1)                    /*!<R FFh  The head page of the last packet of HIQ. */
#define BIT_SHIFT_PKT_NUM_HIQ_V1                     8
#define BIT_MASK_PKT_NUM_HIQ_V1                      ((u32)0x0000007F << BIT_SHIFT_PKT_NUM_HIQ_V1)                     /*!<R 0h  The total HIQ pkt number in TxPktbuffer */
#define BIT_SHIFT_HEAD_PKT_HIQ                       0
#define BIT_MASK_HEAD_PKT_HIQ                        ((u32)0x000000FF << BIT_SHIFT_HEAD_PKT_HIQ)                       /*!<R FFh  The head page of the first packet of HIQ. */

/* REG_BCNQ_INFO 0x0418 */
#define BIT_SHIFT_PKT_NUM_BCNQ                       8
#define BIT_MASK_PKT_NUM_BCNQ                        ((u32)0x000000FF << BIT_SHIFT_PKT_NUM_BCNQ)                       /*!<R 0h  The total BcnQ pkt number in TxPktbuffer */
#define BIT_SHIFT_BCNQ_HEAD_PG                       0
#define BIT_MASK_BCNQ_HEAD_PG                        ((u32)0x000000FF << BIT_SHIFT_BCNQ_HEAD_PG)                       /*!<R F6h  The head page of the first packet of Bcnq */

/* REG_TXPKT_EMPTY 0x041A */
#define BIT_SHIFT_BCNQ_EMPTY_P2                      15
#define BIT_BCNQ_EMPTY_P2                            ((u32)0x00000001 << BIT_SHIFT_BCNQ_EMPTY_P2)                      /*!<R 1h  When this bit is raised, beacon queue of PORT2 is empty. Report by MAC. */
#define BIT_SHIFT_BCNQ_EMPTY_P1                      14
#define BIT_BCNQ_EMPTY_P1                            ((u32)0x00000001 << BIT_SHIFT_BCNQ_EMPTY_P1)                      /*!<R 1h  When this bit is raised, beacon queue of PORT1 is empty. Report by MAC. */
#define BIT_SHIFT_BCNQ_EMPTY_P0                      13
#define BIT_BCNQ_EMPTY_P0                            ((u32)0x00000001 << BIT_SHIFT_BCNQ_EMPTY_P0)                      /*!<R 1h  When this bit is raised, beacon queue of PORT0 is empty. Report by MAC. */
#define BIT_SHIFT_EVTQ_EMPTY                         12
#define BIT_EVTQ_EMPTY                               ((u32)0x00000001 << BIT_SHIFT_EVTQ_EMPTY)                         /*!<R 1h  When this bit is raised, event queue is empty. Report by MAC. */
#define BIT_SHIFT_BCNQ_EMPTY                         11
#define BIT_BCNQ_EMPTY                               ((u32)0x00000001 << BIT_SHIFT_BCNQ_EMPTY)                         /*!<R 1h  When this bit is raised, beacon queue is empty. Report by MAC. */
#define BIT_SHIFT_HQQ_EMPTY                          10
#define BIT_HQQ_EMPTY                                ((u32)0x00000001 << BIT_SHIFT_HQQ_EMPTY)                          /*!<R 1h  When this bit is raised, High queue is empty. Report by MAC. */
#define BIT_SHIFT_MQQ_EMPTY                          9
#define BIT_MQQ_EMPTY                                ((u32)0x00000001 << BIT_SHIFT_MQQ_EMPTY)                          /*!<R 1h  When this bit is raised, MGQ queue is empty. Report by MAC. */
#define BIT_SHIFT_MGQ_CPU_EMPTY                      8
#define BIT_MGQ_CPU_EMPTY                            ((u32)0x00000001 << BIT_SHIFT_MGQ_CPU_EMPTY)                      /*!<R 1h  When this bit is raised, MGQ queue poll by cpu is empty. Report by MAC. */
#define BIT_SHIFT_AC7Q_EMPTY                         7
#define BIT_AC7Q_EMPTY                               ((u32)0x00000001 << BIT_SHIFT_AC7Q_EMPTY)                         /*!<R 1h  When this bit is raised, AC7 queue is empty. Report by MAC. */
#define BIT_SHIFT_AC6Q_EMPTY                         6
#define BIT_AC6Q_EMPTY                               ((u32)0x00000001 << BIT_SHIFT_AC6Q_EMPTY)                         /*!<R 1h  When this bit is raised, AC6 queue is empty. Report by MAC. */
#define BIT_SHIFT_AC5Q_EMPTY                         5
#define BIT_AC5Q_EMPTY                               ((u32)0x00000001 << BIT_SHIFT_AC5Q_EMPTY)                         /*!<R 1h  When this bit is raised, AC5 queue is empty. Report by MAC. */
#define BIT_SHIFT_AC4Q_EMPTY                         4
#define BIT_AC4Q_EMPTY                               ((u32)0x00000001 << BIT_SHIFT_AC4Q_EMPTY)                         /*!<R 1h  When this bit is raised, AC4 queue is empty. Report by MAC. */
#define BIT_SHIFT_AC3Q_EMPTY                         3
#define BIT_AC3Q_EMPTY                               ((u32)0x00000001 << BIT_SHIFT_AC3Q_EMPTY)                         /*!<R 1h  When this bit is raised, AC3 queue is empty. Report by MAC. */
#define BIT_SHIFT_AC2Q_EMPTY                         2
#define BIT_AC2Q_EMPTY                               ((u32)0x00000001 << BIT_SHIFT_AC2Q_EMPTY)                         /*!<R 1h  When this bit is raised, AC2 queue is empty. Report by MAC. */
#define BIT_SHIFT_AC1Q_EMPTY                         1
#define BIT_AC1Q_EMPTY                               ((u32)0x00000001 << BIT_SHIFT_AC1Q_EMPTY)                         /*!<R 1h  When this bit is raised, AC1 queue is empty. Report by MAC. */
#define BIT_SHIFT_AC0Q_EMPTY                         0
#define BIT_AC0Q_EMPTY                               ((u32)0x00000001 << BIT_SHIFT_AC0Q_EMPTY)                         /*!<R 1h  When this bit is raised, AC0 queue is empty. Report by MAC. */

/* REG_CPU_MGQ_INFO 0x041C */
#define BIT_SHIFT_BCN_POLL2                          31
#define BIT_BCN_POLL2                                ((u32)0x00000001 << BIT_SHIFT_BCN_POLL2)                          /*!<W   Polling BCN Queue2 Packet. Not used in 8723F */
#define BIT_SHIFT_BCN_POLL1                          30
#define BIT_BCN_POLL1                                ((u32)0x00000001 << BIT_SHIFT_BCN_POLL1)                          /*!<W   Polling BCN Queue1 Packet */
#define BIT_SHIFT_CPUMGT_POLL_SET                    29
#define BIT_CPUMGT_POLL_SET                          ((u32)0x00000001 << BIT_SHIFT_CPUMGT_POLL_SET)                    /*!<W   Polling to set CPU MGT Queue packet */
#define BIT_SHIFT_BCN_POLL                           28
#define BIT_BCN_POLL                                 ((u32)0x00000001 << BIT_SHIFT_BCN_POLL)                           /*!<W   Polling BCN Queue Packet */
#define BIT_SHIFT_CPUMGT_POLL_CLR                    27
#define BIT_CPUMGT_POLL_CLR                          ((u32)0x00000001 << BIT_SHIFT_CPUMGT_POLL_CLR)                    /*!<W   Polling to clear CPU MGT Queue packet */
#define BIT_SHIFT_EVTQ_VLD                           26
#define BIT_EVTQ_VLD                                 ((u32)0x00000001 << BIT_SHIFT_EVTQ_VLD)                           /*!<R/W 0h   */
#define BIT_SHIFT_CPUMGQ_FW_NUM                      8
#define BIT_CPUMGQ_FW_NUM                            ((u32)0x00000001 << BIT_SHIFT_CPUMGQ_FW_NUM)                      /*!<R 0h  The total cpu mgq fw number in TxPktbuffer */
#define BIT_SHIFT_CPUMGQ_HEAD_PG                     0
#define BIT_MASK_CPUMGQ_HEAD_PG                      ((u32)0x000000FF << BIT_SHIFT_CPUMGQ_HEAD_PG)                     /*!<R F6h  The head page of CPU MGQ */

/* REG_FWHW_TXQ_HWSSN_CTRL 0x0420 */
#define BIT_SHIFT_HW_SSN_EN_L                        24
#define BIT_MASK_HW_SSN_EN_L                         ((u32)0x000000FF << BIT_SHIFT_HW_SSN_EN_L)                        /*!<R/W 0h  HW update the SSN [7:0] */
#define BIT_SHIFT_RTS_LIMIT_IN_OFDM                  23
#define BIT_RTS_LIMIT_IN_OFDM                        ((u32)0x00000001 << BIT_SHIFT_RTS_LIMIT_IN_OFDM)                  /*!<R/W 0h  Rts rate will not down to cck rate */
#define BIT_SHIFT_EN_BCNQ_DL                         22
#define BIT_EN_BCNQ_DL                               ((u32)0x00000001 << BIT_SHIFT_EN_BCNQ_DL)                         /*!<R/W 1h  1: ptcl consider there is bcn pkt in TXBUF when bcn pkt first be transferd in; 0: mask bcn pkt num in bcn queue */
#define BIT_SHIFT_EN_RD_RESP_NAV_BK                  21
#define BIT_EN_RD_RESP_NAV_BK                        ((u32)0x00000001 << BIT_SHIFT_EN_RD_RESP_NAV_BK)                  /*!<R/W 1h  Control the RD responder NAV criteria for TX. When this bit is clear, RD responder may aggregates only according to the number of MPDUs existing in the TXPKTBUF, the limit of aggregation size and number, and also the break time. When this bit is set, RD responder will be under the RX NAV criteria for RD response sequence. No excess NAV is allowed */
#define BIT_SHIFT_EN_WR_FREE_TAIL                    20
#define BIT_EN_WR_FREE_TAIL                          ((u32)0x00000001 << BIT_SHIFT_EN_WR_FREE_TAIL)                    /*!<R/W 1h  1: Drive write Bcnq_boundary, Hw will set free_tail in Boundary-1 0: no update */
#define BIT_SHIFT_TXRPT_DIS                          19
#define BIT_TXRPT_DIS                                ((u32)0x00000001 << BIT_SHIFT_TXRPT_DIS)                          /*!<R/W 0h  when this bit is enabled, HW will not generate txrpt for driver's fixed rate packets */
#define BIT_SHIFT_TXFAILRPT_DIS                      18
#define BIT_TXFAILRPT_DIS                            ((u32)0x00000001 << BIT_SHIFT_TXFAILRPT_DIS)                      /*!<R/W 0h  when this bit is enabled, HW will not generate txrpt for tx failed packets */
#define BIT_SHIFT_EN_RTY_BC                          17
#define BIT_EN_RTY_BC                                ((u32)0x00000001 << BIT_SHIFT_EN_RTY_BC)                          /*!<R/W 0h  When this bit is enabled, retry the broadcast packet */
#define BIT_SHIFT_EN_RTY_BK_COND                     16
#define BIT_EN_RTY_BK_COND                           ((u32)0x00000001 << BIT_SHIFT_EN_RTY_BK_COND)                     /*!<R/W 0h  AMPDU aggregation mode with retry MPDUs and new MPDUs. When this bit is enabled, if new MPDU's data rate is not the same as retry MPDUs' fallback data rate, the aggregation will be broken. */
#define BIT_SHIFT_EN_QUEUE_RPT                       8
#define BIT_MASK_EN_QUEUE_RPT                        ((u32)0x000000FF << BIT_SHIFT_EN_QUEUE_RPT)                       /*!<R/W 3Fh  8723A/8812 1: HW will report tx_status 0: no report BIT0: BK Queue BIT1: BE Queue BIT2: VI Queue BIT3: VO Queue BIT4: MGT Queue BIT5: HI Queue BIT6: BCN Queue BIT7: CPU_MGT Queue */
#define BIT_SHIFT_EN_RTY_BK                          7
#define BIT_EN_RTY_BK                                ((u32)0x00000001 << BIT_SHIFT_EN_RTY_BK)                          /*!<R/W 1h  AMPDU aggregation mode with retry MPDUs and new MPDUs. When this bit is clear enabled, an AMPDU aggregates retried MPDU and new MPDU. All the aggregation criteria is still the same with normal AMPDU operation. */
#define BIT_SHIFT_EN_USE_INI_RAT                     6
#define BIT_EN_USE_INI_RAT                           ((u32)0x00000001 << BIT_SHIFT_EN_USE_INI_RAT)                     /*!<R/W 0h  0: If Txdesc's USE RATE = 0 and this field is equal to 0, the datarate of TXRPT SRAM is used as tx pkt's datarate. (ECO flow) 1: TXInfo's datarate is used as tx pkt's datarate. */
#define BIT_SHIFT_EN_RTS_NAV_BK                      5
#define BIT_EN_RTS_NAV_BK                            ((u32)0x00000001 << BIT_SHIFT_EN_RTS_NAV_BK)                      /*!<R/W 0h  Control The RTS NAV criteria for TX. When this bit is clear, TX may aggregates only according to the number of MPDUs existing in the TXPKTBUF, the limit of aggregation size and number, and also the break time. When this bit is set, TX will be under the RTS NAV criteria. No excess RTS NAV is allowed. */
#define BIT_SHIFT_DIS_SSN_CHECK                      4
#define BIT_DIS_SSN_CHECK                            ((u32)0x00000001 << BIT_SHIFT_DIS_SSN_CHECK)                      /*!<R/W 0h  Disable checker the SSN rule when generating AMPDU TX cmd. */
#define BIT_SHIFT_MACID_MATCH_RTS                    3
#define BIT_MACID_MATCH_RTS                          ((u32)0x00000001 << BIT_SHIFT_MACID_MATCH_RTS)                    /*!<R/W 0h  Enable the packet that follow the RTS have same MACID */
#define BIT_SHIFT_EN_BCN_TXRPT                       2
#define BIT_EN_BCN_TXRPT                             ((u32)0x00000001 << BIT_SHIFT_EN_BCN_TXRPT)                       /*!<R/W 1h  1: HW will report bcn tx_status 0: no report */
#define BIT_SHIFT_EN_FTM_RPT                         1
#define BIT_EN_FTM_RPT                               ((u32)0x00000001 << BIT_SHIFT_EN_FTM_RPT)                         /*!<R/W 1h  When this bit asserted, HW will report FTM rpt */
#define BIT_SHIFT_PROTECT_BMC_NAV                    0
#define BIT_PROTECT_BMC_NAV                          ((u32)0x00000001 << BIT_SHIFT_PROTECT_BMC_NAV)                    /*!<R/W 1h  Enable the NAV protection when transmit broadcast/multicast */

/* REG_BNDY_LIFETIME_TAIL 0x0424 */
#define BIT_SHIFT_FW_FREE_TAIL                       24
#define BIT_MASK_FW_FREE_TAIL                        ((u32)0x000000FF << BIT_SHIFT_FW_FREE_TAIL)                       /*!<R F5h  Free Tail Page Number */
#define BIT_SHIFT_BT_INT_TYPE                        22
#define BIT_MASK_BT_INT_TYPE                         ((u32)0x00000003 << BIT_SHIFT_BT_INT_TYPE)                        /*!<R/W 0h  BT Interrupt type 01: PTA 10: CPU */
#define BIT_SHIFT_HW_SSN_EN_H                        21
#define BIT_HW_SSN_EN_H                              ((u32)0x00000001 << BIT_SHIFT_HW_SSN_EN_H)                        /*!<R/W 0h  HW update the SSN [8] for eventq */
#define BIT_SHIFT_RTYBIT_CTRL_EN                     20
#define BIT_RTYBIT_CTRL_EN                           ((u32)0x00000001 << BIT_SHIFT_RTYBIT_CTRL_EN)                     /*!<R/W 1h  1: Enable Retry Count 0: Disable */
#define BIT_SHIFT_LIFETIME_BK_EN                     19
#define BIT_LIFETIME_BK_EN                           ((u32)0x00000001 << BIT_SHIFT_LIFETIME_BK_EN)                     /*!<R/W 0h  Enable BK queue lifetime function */
#define BIT_SHIFT_LIFETIME_BE_EN                     18
#define BIT_LIFETIME_BE_EN                           ((u32)0x00000001 << BIT_SHIFT_LIFETIME_BE_EN)                     /*!<R/W 0h  Enable BE queue lifetime function */
#define BIT_SHIFT_LIFETIME_VI_EN                     17
#define BIT_LIFETIME_VI_EN                           ((u32)0x00000001 << BIT_SHIFT_LIFETIME_VI_EN)                     /*!<R/W 0h  Enable VI queue lifetime function */
#define BIT_SHIFT_LIFETIME_VO_EN                     16
#define BIT_LIFETIME_VO_EN                           ((u32)0x00000001 << BIT_SHIFT_LIFETIME_VO_EN)                     /*!<R/W 0h  Enable VO queue lifetime function */
#define BIT_SHIFT_MGQ_PGBNDY                         8
#define BIT_MASK_MGQ_PGBNDY                          ((u32)0x000000FF << BIT_SHIFT_MGQ_PGBNDY)                         /*!<R/W F6h  TXDMA will pull CPU MGQ Pkt in this address. */
#define BIT_SHIFT_BCNQ_PGBNDY                        0
#define BIT_MASK_BCNQ_PGBNDY                         ((u32)0x000000FF << BIT_SHIFT_BCNQ_PGBNDY)                        /*!<R/W F6h  TXDMA will pull BCNQ Pkt in this address. */

/* REG_RETRY_LIMIT_SIFS 0x0428 */
#define BIT_SHIFT_SRL                                24
#define BIT_MASK_SRL                                 ((u32)0x0000003F << BIT_SHIFT_SRL)                                /*!<R/W 20h  Short Retry Limit */
#define BIT_SHIFT_LRL                                16
#define BIT_MASK_LRL                                 ((u32)0x0000003F << BIT_SHIFT_LRL)                                /*!<R/W 20h  Long Retry Limit */
#define BIT_SHIFT_SPEC_SIFS_OFDM_PTCL                8
#define BIT_MASK_SPEC_SIFS_OFDM_PTCL                 ((u32)0x000000FF << BIT_SHIFT_SPEC_SIFS_OFDM_PTCL)                /*!<R/W 16h  The spec SIFS value for duration calculation */
#define BIT_SHIFT_SPEC_SIFS_CCK_PTCL                 0
#define BIT_MASK_SPEC_SIFS_CCK_PTCL                  ((u32)0x000000FF << BIT_SHIFT_SPEC_SIFS_CCK_PTCL)                 /*!<R/W 16h  The spec SIFS value for duration calculation */

/* REG_TXBF_CTRL 0x042C */
#define BIT_SHIFT_R_ENABLE_NDPA                      31
#define BIT_R_ENABLE_NDPA                            ((u32)0x00000001 << BIT_SHIFT_R_ENABLE_NDPA)                      /*!<R/W 0h  Set ��1�� for MAC to enable sending NDPA or NDP Announcement MPDU */
#define BIT_SHIFT_USE_NDPA_PARAMETER                 30
#define BIT_USE_NDPA_PARAMETER                       ((u32)0x00000001 << BIT_SHIFT_USE_NDPA_PARAMETER)                 /*!<R/W 0h  1: NDPA rate and BW use reg0x45f settings 0: NDPA rate and BW use NDP settings in Tx descriptor */
#define BIT_SHIFT_R_PROP_TXBF                        29
#define BIT_R_PROP_TXBF                              ((u32)0x00000001 << BIT_SHIFT_R_PROP_TXBF)                        /*!<R/W 0h  1: enable proprietary beamforming; 0: disable proprietary beamforming */
#define BIT_SHIFT_R_EN_NDPA_INT                      28
#define BIT_R_EN_NDPA_INT                            ((u32)0x00000001 << BIT_SHIFT_R_EN_NDPA_INT)                      /*!<R/W 0h  1: enable ndpa interrupt; 0: disable ndpa interrupt */
#define BIT_SHIFT_R_TXBF1_80M                        27
#define BIT_R_TXBF1_80M                              ((u32)0x00000001 << BIT_SHIFT_R_TXBF1_80M)                        /*!<R/W 0h  TxBF status of beamformee1 xBW=80M. */
#define BIT_SHIFT_R_TXBF1_40M                        26
#define BIT_R_TXBF1_40M                              ((u32)0x00000001 << BIT_SHIFT_R_TXBF1_40M)                        /*!<R/W 0h  TxBF status of beamformee1 xBW=40M */
#define BIT_SHIFT_R_TXBF1_20M                        25
#define BIT_R_TXBF1_20M                              ((u32)0x00000001 << BIT_SHIFT_R_TXBF1_20M)                        /*!<R/W 0h  TxBF status of beamformee1 xBW=20M */
#define BIT_SHIFT_R_TXBF1_AID                        16
#define BIT_MASK_R_TXBF1_AID                         ((u32)0x000001FF << BIT_SHIFT_R_TXBF1_AID)                        /*!<R/W 0h  P_AID[8:0] of the associated beamformee1 */
#define BIT_SHIFT_NDP_BFEN_DIS                       15
#define BIT_NDP_BFEN_DIS                             ((u32)0x00000001 << BIT_SHIFT_NDP_BFEN_DIS)                       /*!<R/W 1h  1: disable beamforming with NDP */
#define BIT_SHIFT_BCN_NOBLOCK_NDP                    14
#define BIT_BCN_NOBLOCK_NDP                          ((u32)0x00000001 << BIT_SHIFT_BCN_NOBLOCK_NDP)                    /*!<R/W 1h  beacon packet will not block NDP packet */
#define BIT_SHIFT_R_TXBF0_80M                        11
#define BIT_R_TXBF0_80M                              ((u32)0x00000001 << BIT_SHIFT_R_TXBF0_80M)                        /*!<R/W 0h  TxBF status of beamformee0 xBW=80M */
#define BIT_SHIFT_R_TXBF0_40M                        10
#define BIT_R_TXBF0_40M                              ((u32)0x00000001 << BIT_SHIFT_R_TXBF0_40M)                        /*!<R/W 0h  TxBF status of beamformee0 xBW=40M */
#define BIT_SHIFT_R_TXBF0_20M                        9
#define BIT_R_TXBF0_20M                              ((u32)0x00000001 << BIT_SHIFT_R_TXBF0_20M)                        /*!<R/W 0h  TxBF status of beamformee0 xBW=20M */
#define BIT_SHIFT_R_TXBF0_AID                        0
#define BIT_MASK_R_TXBF0_AID                         ((u32)0x000001FF << BIT_SHIFT_R_TXBF0_AID)                        /*!<R/W 0h  P_AID[8:0] of the associated beamformee0 */

/* REG_DARFRC_L 0x0430 */
#define BIT_SHIFT_DATA_FALLBACK_RC4                  24
#define BIT_MASK_DATA_FALLBACK_RC4                   ((u32)0x0000001F << BIT_SHIFT_DATA_FALLBACK_RC4)                  /*!<R/W 04h  Data Auto Rate Fallback Retry Count After the number of retry, HW will fall back the rate to the next enabled MAC in ARFR. */
#define BIT_SHIFT_DATA_FALLBACK_RC3                  16
#define BIT_MASK_DATA_FALLBACK_RC3                   ((u32)0x0000001F << BIT_SHIFT_DATA_FALLBACK_RC3)                  /*!<R/W 03h  Data Auto Rate Fallback Retry Count After the number of retry, HW will fall back the rate to the next enabled MAC in ARFR. */
#define BIT_SHIFT_DATA_FALLBACK_RC2                  8
#define BIT_MASK_DATA_FALLBACK_RC2                   ((u32)0x0000001F << BIT_SHIFT_DATA_FALLBACK_RC2)                  /*!<R/W 02h  Data Auto Rate Fallback Retry Count After the number of retry, HW will fall back the rate to the next enabled MAC in ARFR. */
#define BIT_SHIFT_DATA_FALLBACK_RC1                  0
#define BIT_MASK_DATA_FALLBACK_RC1                   ((u32)0x0000001F << BIT_SHIFT_DATA_FALLBACK_RC1)                  /*!<R/W 01h  Data Auto Rate Fallback Retry Count After the number of retry, HW will fall back the rate to the next enabled MAC in ARFR. */

/* REG_DARFRC_H 0x0434 */
#define BIT_SHIFT_DATA_FALLBACK_RC8                  24
#define BIT_MASK_DATA_FALLBACK_RC8                   ((u32)0x0000001F << BIT_SHIFT_DATA_FALLBACK_RC8)                  /*!<R/W 08h  Data Auto Rate Fallback Retry Count After the number of retry, HW will fall back the rate to the next enabled MAC in ARFR. */
#define BIT_SHIFT_DATA_FALLBACK_RC7                  16
#define BIT_MASK_DATA_FALLBACK_RC7                   ((u32)0x0000001F << BIT_SHIFT_DATA_FALLBACK_RC7)                  /*!<R/W 07h  Data Auto Rate Fallback Retry Count After the number of retry, HW will fall back the rate to the next enabled MAC in ARFR. */
#define BIT_SHIFT_DATA_FALLBACK_RC6                  8
#define BIT_MASK_DATA_FALLBACK_RC6                   ((u32)0x0000001F << BIT_SHIFT_DATA_FALLBACK_RC6)                  /*!<R/W 06h  Data Auto Rate Fallback Retry Count After the number of retry, HW will fall back the rate to the next enabled MAC in ARFR. */
#define BIT_SHIFT_DATA_FALLBACK_RC5                  0
#define BIT_MASK_DATA_FALLBACK_RC5                   ((u32)0x0000001F << BIT_SHIFT_DATA_FALLBACK_RC5)                  /*!<R/W 05h  Data Auto Rate Fallback Retry Count After the number of retry, HW will fall back the rate to the next enabled MAC in ARFR. */

/* REG_RARFRC_L 0x0438 */
#define BIT_SHIFT_CTRL_FALLBACK_RC4                  24
#define BIT_MASK_CTRL_FALLBACK_RC4                   ((u32)0x0000001F << BIT_SHIFT_CTRL_FALLBACK_RC4)                  /*!<R/W 04h  RTS Auto Rate Fallback Retry Count After the number of retry, HW will fall back the rate to the next enabled MAC in ARFR. */
#define BIT_SHIFT_CTRL_FALLBACK_RC3                  16
#define BIT_MASK_CTRL_FALLBACK_RC3                   ((u32)0x0000001F << BIT_SHIFT_CTRL_FALLBACK_RC3)                  /*!<R/W 03h  RTS Auto Rate Fallback Retry Count After the number of retry, HW will fall back the rate to the next enabled MAC in ARFR. */
#define BIT_SHIFT_CTRL_FALLBACK_RC2                  8
#define BIT_MASK_CTRL_FALLBACK_RC2                   ((u32)0x0000001F << BIT_SHIFT_CTRL_FALLBACK_RC2)                  /*!<R/W 02h  RTS Auto Rate Fallback Retry Count After the number of retry, HW will fall back the rate to the next enabled MAC in ARFR. */
#define BIT_SHIFT_CTRL_FALLBACK_RC1                  0
#define BIT_MASK_CTRL_FALLBACK_RC1                   ((u32)0x0000001F << BIT_SHIFT_CTRL_FALLBACK_RC1)                  /*!<R/W 01h  RTS Auto Rate Fallback Retry Count After the number of retry, HW will fall back the rate to the next enabled MAC in ARFR. */

/* REG_RARFRC_H 0x043C */
#define BIT_SHIFT_CTRL_FALLBACK_RC8                  24
#define BIT_MASK_CTRL_FALLBACK_RC8                   ((u32)0x0000001F << BIT_SHIFT_CTRL_FALLBACK_RC8)                  /*!<R/W 08h  RTS Auto Rate Fallback Retry Count After the number of retry, HW will fall back the rate to the next enabled MAC in ARFR. */
#define BIT_SHIFT_CTRL_FALLBACK_RC7                  16
#define BIT_MASK_CTRL_FALLBACK_RC7                   ((u32)0x0000001F << BIT_SHIFT_CTRL_FALLBACK_RC7)                  /*!<R/W 07h  RTS Auto Rate Fallback Retry Count After the number of retry, HW will fall back the rate to the next enabled MAC in ARFR. */
#define BIT_SHIFT_CTRL_FALLBACK_RC6                  8
#define BIT_MASK_CTRL_FALLBACK_RC6                   ((u32)0x0000001F << BIT_SHIFT_CTRL_FALLBACK_RC6)                  /*!<R/W 06h  RTS Auto Rate Fallback Retry Count After the number of retry, HW will fall back the rate to the next enabled MAC in ARFR. */
#define BIT_SHIFT_CTRL_FALLBACK_RC5                  0
#define BIT_MASK_CTRL_FALLBACK_RC5                   ((u32)0x0000001F << BIT_SHIFT_CTRL_FALLBACK_RC5)                  /*!<R/W 05h  RTS Auto Rate Fallback Retry Count After the number of retry, HW will fall back the rate to the next enabled MAC in ARFR. */

/* REG_RRSR 0x0440 */
#define BIT_SHIFT_RRSR_RSC                           21
#define BIT_MASK_RRSR_RSC                            ((u32)0x0000000F << BIT_SHIFT_RRSR_RSC)                           /*!<R/W 3h  Response frame sub-channel configuration. Response frames (CTS, ACK, BA) are transmitted in the following condition. 00: Primary 20Mhz BW(0x483[3:0] = 0x8AC[5:2]). 01: Follow Rx packet BW mode. 10: Duplicate mode. */
#define BIT_SHIFT_R_RATE_CTRL_TABLE                  0
#define BIT_MASK_R_RATE_CTRL_TABLE                   ((u32)0x000FFFFF << BIT_SHIFT_R_RATE_CTRL_TABLE)                  /*!<R/W 00011h  Data Rate Control Table Register BitMap to indicate the response/protection/expected_response rate to use in this BSS. All management and control response frames should obey the rates set in the bitmap. Each bit is mapped as the following: Bit[0:3] = {1M, 2M, 5.5M, 11M } Bit[4:11] = {6M, 9M, 12M, 18M, 24M, 36M, 48M, 54M} Bit[12:19] = HT MCS0~MCS7 Response rate must be less than or equal to the rate of the initiating frame. If none of the bits are set, no response is generated by Rtl8712. If both the legacy rates and HT rates are defined as Basic Rates, fill in only the legacy portion of the bitmap. If only HT rates are defined as Basic Rates, fill in both the legacy and HT portion of the bitmap. */

/* REG_ARFR_L0 0x0444 */
#define BIT_SHIFT_ADPT_RATE_TABLE_L0                 0
#define BIT_MASK_ADPT_RATE_TABLE_L0                  ((u32)0xFFFFFFFF << BIT_SHIFT_ADPT_RATE_TABLE_L0)                 /*!<R/W 0h  Data Auto Rate Fallback Table Register 0, indexed by RATid in TXDESC. Each bit is mapped as the following: Bit[0:3] = {1M, 2M, 5.5M, 11M } Bit[4:11] = {6M, 9M, 12M, 18M, 24M, 36M, 48M, 54M} Bit[12:19] = HT MCS0~MCS7 Bit[20:27] = HT MCS8~MCS15 Bit[27:35] = HT MCS16~MCS23 Bit[36:43] = HT MCS24~MCS31 Bit[44:53] = VHT 1SS MCS0~MCS9 Bit[54:63] = VHT 2SS MCS0~MCS9 */

/* REG_ARFR_H0 0x0448 */
#define BIT_SHIFT_ADPT_RATE_TABLE_H0                 0
#define BIT_MASK_ADPT_RATE_TABLE_H0                  ((u32)0xFFFFFFFF << BIT_SHIFT_ADPT_RATE_TABLE_H0)                 /*!<R/W 0h  Data Auto Rate Fallback Table Register 0, indexed by RATid in TXDESC. Each bit is mapped as the following: Bit[0:3] = {1M, 2M, 5.5M, 11M } Bit[4:11] = {6M, 9M, 12M, 18M, 24M, 36M, 48M, 54M} Bit[12:19] = HT MCS0~MCS7 Bit[20:27] = HT MCS8~MCS15 Bit[27:35] = HT MCS16~MCS23 Bit[36:43] = HT MCS24~MCS31 Bit[44:53] = VHT 1SS MCS0~MCS9 Bit[54:63] = VHT 2SS MCS0~MCS9 */

/* REG_ARFR_L1 0x044C */
#define BIT_SHIFT_ADPT_RATE_TABLE_L1                 0
#define BIT_MASK_ADPT_RATE_TABLE_L1                  ((u32)0xFFFFFFFF << BIT_SHIFT_ADPT_RATE_TABLE_L1)                 /*!<R/W 0h  Data Auto Rate Fallback Table Register 1, indexed by RATid in TXDESC. The definition is the same as ARFR0. */

/* REG_ARFR_H1 0x0450 */
#define BIT_SHIFT_ADPT_RATE_TABLE_H1                 0
#define BIT_MASK_ADPT_RATE_TABLE_H1                  ((u32)0xFFFFFFFF << BIT_SHIFT_ADPT_RATE_TABLE_H1)                 /*!<R/W 0h  Data Auto Rate Fallback Table Register 1, indexed by RATid in TXDESC. The definition is the same as ARFR0. */

/* REG_BCN_AMPDU_CTCL 0x0454 */
#define BIT_SHIFT_BCNQ1_HEAD                         24
#define BIT_MASK_BCNQ1_HEAD                          ((u32)0x000000FF << BIT_SHIFT_BCNQ1_HEAD)                         /*!<R/W F6  TXDMA will pull BCNQ1 Pkt in this address. Port1 & VAP 1/3/5/7 of port0 */
#define BIT_SHIFT_AMPDU_MAX_TIME                     16
#define BIT_MASK_AMPDU_MAX_TIME                      ((u32)0x000000FF << BIT_SHIFT_AMPDU_MAX_TIME)                     /*!<R/W 64  AMPDU duration limit in the unit of 32us. */
#define BIT_SHIFT_BCNQ2_HEAD                         8
#define BIT_MASK_BCNQ2_HEAD                          ((u32)0x000000FF << BIT_SHIFT_BCNQ2_HEAD)                         /*!<R/W F6h  TXDMA will pull BCNQ2 Pkt in this address. Port2, NAN */
#define BIT_SHIFT_CHECK_CCK_EN                       7
#define BIT_CHECK_CCK_EN                             ((u32)0x00000001 << BIT_SHIFT_CHECK_CCK_EN)                       /*!<R/W 0h  If this bit is set, HW check Tx pkt��s data rate. When data rate is CCK rate, modify the rate to NON_CCK_RATE. */
#define BIT_SHIFT_EN_BCN_PKT_REL                     6
#define BIT_EN_BCN_PKT_REL                           ((u32)0x00000001 << BIT_SHIFT_EN_BCN_PKT_REL)                     /*!<R/W 0h  If this bit is set, the BCN pkt will be set to non-valid after BCN TX. */
#define BIT_SHIFT_BCN_PORT_SEL                       5
#define BIT_BCN_PORT_SEL                             ((u32)0x00000001 << BIT_SHIFT_BCN_PORT_SEL)                       /*!<R/W 0h  This bit use to select BCN on port 1 or port 0. This just useful in USB/SDIO interface. */
#define BIT_SHIFT_MOREDATA_BYPASS                    4
#define BIT_MOREDATA_BYPASS                          ((u32)0x00000001 << BIT_SHIFT_MOREDATA_BYPASS)                    /*!<R/W 0h  If this bit is set, the moredata bit will controlled by DES, otherwise controlled by PTCL according TXPKTBUF status. */
#define BIT_SHIFT_EN_CLR_CMD_REL_BCN_PKT             3
#define BIT_EN_CLR_CMD_REL_BCN_PKT                   ((u32)0x00000001 << BIT_SHIFT_EN_CLR_CMD_REL_BCN_PKT)             /*!<R/W 0h  If this bit is set, the BCN pkt will be set to non-valid when scheduler clear TX BCN CMD even non-TX. */
#define BIT_SHIFT_EN_SET_MOREDATA                    2
#define BIT_EN_SET_MOREDATA                          ((u32)0x00000001 << BIT_SHIFT_EN_SET_MOREDATA)                    /*!<R/W 1h  1: Enable HW set the more data bit of the PKT that MACID release function tx. 0: Disable HW set the more data bit of the PKT that MACID release function tx. */
#define BIT_SHIFT_DIS_CLEAR_MACID_RELEASE            1
#define BIT_DIS_CLEAR_MACID_RELEASE                  ((u32)0x00000001 << BIT_SHIFT_DIS_CLEAR_MACID_RELEASE)            /*!<R/W 0h  1: HW No clear MACID Release bit after release the pkt. 0: HW will clear MACID Release bit after release the pkt. */
#define BIT_SHIFT_EN_MACID_RELEASE                   0
#define BIT_EN_MACID_RELEASE                         ((u32)0x00000001 << BIT_SHIFT_EN_MACID_RELEASE)                   /*!<R/W 1h  1: Enable MACID Release function. (same as MACID DROP) 0: Disable MACID Release function. */

/* REG_AMPDU_MAX_LENGTH 0x0458 */
#define BIT_SHIFT_AMPDU_MAX_LENGTH                   0
#define BIT_MASK_AMPDU_MAX_LENGTH                    ((u32)0xFFFFFFFF << BIT_SHIFT_AMPDU_MAX_LENGTH)                   /*!<R/W FFFFFFFFh  AMPDU length limit */

/* REG_ACQ_STOP 0x045C */
#define BIT_SHIFT_AC7Q_STOP                          7
#define BIT_AC7Q_STOP                                ((u32)0x00000001 << BIT_SHIFT_AC7Q_STOP)                          /*!<R 0h  When this bit is raised, AC7 queue is stop. Report by MAC. */
#define BIT_SHIFT_AC6Q_STOP                          6
#define BIT_AC6Q_STOP                                ((u32)0x00000001 << BIT_SHIFT_AC6Q_STOP)                          /*!<R 0h  When this bit is raised, AC6 queue is stop. Report by MAC. */
#define BIT_SHIFT_AC5Q_STOP                          5
#define BIT_AC5Q_STOP                                ((u32)0x00000001 << BIT_SHIFT_AC5Q_STOP)                          /*!<R 0h  When this bit is raised, AC5 queue is stop. Report by MAC. */
#define BIT_SHIFT_AC4Q_STOP                          4
#define BIT_AC4Q_STOP                                ((u32)0x00000001 << BIT_SHIFT_AC4Q_STOP)                          /*!<R 0h  When this bit is raised, AC4 queue is stop. Report by MAC. */
#define BIT_SHIFT_AC3Q_STOP                          3
#define BIT_AC3Q_STOP                                ((u32)0x00000001 << BIT_SHIFT_AC3Q_STOP)                          /*!<R 0h  When this bit is raised, AC3 queue is stop. Report by MAC. */
#define BIT_SHIFT_AC2Q_STOP                          2
#define BIT_AC2Q_STOP                                ((u32)0x00000001 << BIT_SHIFT_AC2Q_STOP)                          /*!<R 0h  When this bit is raised, AC2 queue is stop. Report by MAC. */
#define BIT_SHIFT_AC1Q_STOP                          1
#define BIT_AC1Q_STOP                                ((u32)0x00000001 << BIT_SHIFT_AC1Q_STOP)                          /*!<R 0h  When this bit is raised, AC1 queue is stop. Report by MAC. */
#define BIT_SHIFT_AC0Q_STOP                          0
#define BIT_AC0Q_STOP                                ((u32)0x00000001 << BIT_SHIFT_AC0Q_STOP)                          /*!<R 0h  When this bit is raised, AC0 queue is stop. Report by MAC. */

/* REG_WMAC_LBK_BUF_HD 0x045D */
#define BIT_SHIFT_WMAC_LBK_BUF_HEAD                  0
#define BIT_MASK_WMAC_LBK_BUF_HEAD                   ((u32)0x000000FF << BIT_SHIFT_WMAC_LBK_BUF_HEAD)                  /*!<R/W F6h  In delay MAC LBK mode, this register indicate the LBK BUF head page. When this buffer size is not enough for LBK packet length, LBK test may fail. In ARP/NS mode, this register indicate the ARP/NS response packet head page. */

/* REG_QUEUE_CTRL 0x045E */
#define BIT_SHIFT_R_SIGTA_BW                         6
#define BIT_MASK_R_SIGTA_BW                          ((u32)0x00000003 << BIT_SHIFT_R_SIGTA_BW)                         /*!<R/W 0h  Enable signaling TA in duplicate BW, valid if EN_SIGTA = 1 in TX DESC */
#define BIT_SHIFT_R_SIGTA_BAR                        5
#define BIT_R_SIGTA_BAR                              ((u32)0x00000001 << BIT_SHIFT_R_SIGTA_BAR)                        /*!<R/W 0h  Enable BAR signaling TA in duplicate BW */
#define BIT_SHIFT_R_EOF_EN                           4
#define BIT_R_EOF_EN                                 ((u32)0x00000001 << BIT_SHIFT_R_EOF_EN)                           /*!<R/W 0h  when set to 1, enable eof packet qos packet,but also need set agg_en to 0 in tx_desc */
#define BIT_SHIFT_R_EN_GNT_BT_AWAKE                  3
#define BIT_R_EN_GNT_BT_AWAKE                        ((u32)0x00000001 << BIT_SHIFT_R_EN_GNT_BT_AWAKE)                  /*!<R/W 0h  Enable pollute bit function.(C card ECO item, modify hardware circuit and add two options) 0: Disable 1: Enable When (GNT_BT option/LTE_RX option/(GNT_WL==0)) == 1, retry count can't increase if Tx fail. One or more packets will record in polluted bit field of txreport when txreport generates in Tx ok or tx drop. */
#define BIT_SHIFT_DIS_RELEASE_RETRY                  2
#define BIT_DIS_RELEASE_RETRY                        ((u32)0x00000001 << BIT_SHIFT_DIS_RELEASE_RETRY)                  /*!<R/W 0h  when release one packet for a macid, retry should happen on the same ACQ. Set 1 to remove this requirement */
#define BIT_SHIFT_DIS_OQT_BLOCK                      1
#define BIT_DIS_OQT_BLOCK                            ((u32)0x00000001 << BIT_SHIFT_DIS_OQT_BLOCK)                      /*!<R/W 0h  If this bit is set, the OQT will not block by all AC queues occupied by other MACID. */
#define BIT_SHIFT_SEARCH_QUEUE_EN                    0
#define BIT_SEARCH_QUEUE_EN                          ((u32)0x00000001 << BIT_SHIFT_SEARCH_QUEUE_EN)                    /*!<R/W 0h  Search queue request enable in ptcl idle:0 disable; 1 enable */

/* REG_NDPA_OPT_CTRL 0x045F */
#define BIT_SHIFT_R_NDPA_RATE                        2
#define BIT_MASK_R_NDPA_RATE                         ((u32)0x0000003F << BIT_SHIFT_R_NDPA_RATE)                        /*!<R/W 04h  NDPA tx rate setting, from CCK 1M to VHT NSS2 MCS9 */
#define BIT_SHIFT_R_NDPA_BW                          0
#define BIT_MASK_R_NDPA_BW                           ((u32)0x00000003 << BIT_SHIFT_R_NDPA_BW)                          /*!<R/W 0h  NDPA bandwidth setting 3: 160M 2: 80M 1: 40M 0: 20M */

/* REG_RD_RESP_PKT_TH 0x0460 */
#define BIT_SHIFT_RD_RESP_PKT_TH                     24
#define BIT_MASK_RD_RESP_PKT_TH                      ((u32)0x0000003F << BIT_SHIFT_RD_RESP_PKT_TH)                     /*!<R/W 03h  When RD_CTRL responder enables, and the granted AC queue packet number is beyond this threshold, then responder will carry More PPDU =1 and piggyback data frames back. */

/* REG_CMDQ_INFO 0x0464 */
#define BIT_SHIFT_PKT_NUM_CMDQ_V2                    24
#define BIT_MASK_PKT_NUM_CMDQ_V2                     ((u32)0x000000FF << BIT_SHIFT_PKT_NUM_CMDQ_V2)                    /*!<R 0h  The total CMD Queue pkt number in TxPktbuffer */
#define BIT_SHIFT_TAIL_PKT_CMDQ                      16
#define BIT_MASK_TAIL_PKT_CMDQ                       ((u32)0x000000FF << BIT_SHIFT_TAIL_PKT_CMDQ)                      /*!<R FFh  The head page of the last packet of Queue 4. */
#define BIT_SHIFT_PKT_NUM_CMDQ                       8
#define BIT_MASK_PKT_NUM_CMDQ                        ((u32)0x000000FF << BIT_SHIFT_PKT_NUM_CMDQ)                       /*!<R 0h  The total Queue 4 pkt number in TxPktbuffer */
#define BIT_SHIFT_HEAD_PKT_CMDQ                      0
#define BIT_MASK_HEAD_PKT_CMDQ                       ((u32)0x000000FF << BIT_SHIFT_HEAD_PKT_CMDQ)                      /*!<R FFh  The head page of the first packet of Queue 4. */

/* REG_Q4_INFO 0x0468 */
#define BIT_SHIFT_QUEUEMACID_Q4_V1                   25
#define BIT_MASK_QUEUEMACID_Q4_V1                    ((u32)0x0000007F << BIT_SHIFT_QUEUEMACID_Q4_V1)                   /*!<R 00h  MacID of head pkt */
#define BIT_SHIFT_QUEUEAC_Q4_V1                      23
#define BIT_MASK_QUEUEAC_Q4_V1                       ((u32)0x00000003 << BIT_SHIFT_QUEUEAC_Q4_V1)                      /*!<R 0h  AC type of Queue 4. */
#define BIT_SHIFT_TAIL_PKT_Q4_V1                     15
#define BIT_MASK_TAIL_PKT_Q4_V1                      ((u32)0x000000FF << BIT_SHIFT_TAIL_PKT_Q4_V1)                     /*!<R FFh  The head page of the last packet of Queue 4. */
#define BIT_SHIFT_PKT_NUM_Q4_V1                      8
#define BIT_MASK_PKT_NUM_Q4_V1                       ((u32)0x0000007F << BIT_SHIFT_PKT_NUM_Q4_V1)                      /*!<R 0h  The total Queue 4 pkt number in TxPktbuffer */
#define BIT_SHIFT_HEAD_PKT_Q4                        0
#define BIT_MASK_HEAD_PKT_Q4                         ((u32)0x000000FF << BIT_SHIFT_HEAD_PKT_Q4)                        /*!<R FFh  The head page of the first packet of Queue 4. */

/* REG_Q5_INFO 0x046C */
#define BIT_SHIFT_QUEUEMACID_Q5_V1                   25
#define BIT_MASK_QUEUEMACID_Q5_V1                    ((u32)0x0000007F << BIT_SHIFT_QUEUEMACID_Q5_V1)                   /*!<R 00h  MacID of head pkt */
#define BIT_SHIFT_QUEUEAC_Q5_V1                      23
#define BIT_MASK_QUEUEAC_Q5_V1                       ((u32)0x00000003 << BIT_SHIFT_QUEUEAC_Q5_V1)                      /*!<R 0h  AC type of Queue 5. */
#define BIT_SHIFT_TAIL_PKT_Q5_V1                     15
#define BIT_MASK_TAIL_PKT_Q5_V1                      ((u32)0x000000FF << BIT_SHIFT_TAIL_PKT_Q5_V1)                     /*!<R FFh  The head page of the last packet of Queue 5. */
#define BIT_SHIFT_PKT_NUM_Q5_V1                      8
#define BIT_MASK_PKT_NUM_Q5_V1                       ((u32)0x0000007F << BIT_SHIFT_PKT_NUM_Q5_V1)                      /*!<R 0h  The total Queue 5 pkt number in TxPktbuffer */
#define BIT_SHIFT_HEAD_PKT_Q5                        0
#define BIT_MASK_HEAD_PKT_Q5                         ((u32)0x000000FF << BIT_SHIFT_HEAD_PKT_Q5)                        /*!<R FFh  The head page of the first packet of Queue5. */

/* REG_Q6_INFO 0x0470 */
#define BIT_SHIFT_QUEUEMACID_Q6_V1                   25
#define BIT_MASK_QUEUEMACID_Q6_V1                    ((u32)0x0000007F << BIT_SHIFT_QUEUEMACID_Q6_V1)                   /*!<R 00h  MacID of head pkt */
#define BIT_SHIFT_QUEUEAC_Q6_V1                      23
#define BIT_MASK_QUEUEAC_Q6_V1                       ((u32)0x00000003 << BIT_SHIFT_QUEUEAC_Q6_V1)                      /*!<R 0h  AC type of Queue 6. */
#define BIT_SHIFT_TAIL_PKT_Q6_V1                     15
#define BIT_MASK_TAIL_PKT_Q6_V1                      ((u32)0x000000FF << BIT_SHIFT_TAIL_PKT_Q6_V1)                     /*!<R FFh  The head page of the last packet of Queue 6. */
#define BIT_SHIFT_PKT_NUM_Q6_V1                      8
#define BIT_MASK_PKT_NUM_Q6_V1                       ((u32)0x0000007F << BIT_SHIFT_PKT_NUM_Q6_V1)                      /*!<R 0h  The total Queue 6 pkt number in TxPktbuffer */
#define BIT_SHIFT_HEAD_PKT_Q6                        0
#define BIT_MASK_HEAD_PKT_Q6                         ((u32)0x000000FF << BIT_SHIFT_HEAD_PKT_Q6)                        /*!<R FFh  The head page of the first packet of Queue 6. */

/* REG_Q7_INFO 0x0474 */
#define BIT_SHIFT_QUEUEMACID_Q7_V1                   25
#define BIT_MASK_QUEUEMACID_Q7_V1                    ((u32)0x0000007F << BIT_SHIFT_QUEUEMACID_Q7_V1)                   /*!<R 00h  MacID of head pkt */
#define BIT_SHIFT_QUEUEAC_Q7_V1                      23
#define BIT_MASK_QUEUEAC_Q7_V1                       ((u32)0x00000003 << BIT_SHIFT_QUEUEAC_Q7_V1)                      /*!<R 0h  AC type of Queue 7. */
#define BIT_SHIFT_TAIL_PKT_Q7_V1                     15
#define BIT_MASK_TAIL_PKT_Q7_V1                      ((u32)0x000000FF << BIT_SHIFT_TAIL_PKT_Q7_V1)                     /*!<R FFh  The head page of the last packet of Queue 7. */
#define BIT_SHIFT_PKT_NUM_Q7_V1                      8
#define BIT_MASK_PKT_NUM_Q7_V1                       ((u32)0x0000007F << BIT_SHIFT_PKT_NUM_Q7_V1)                      /*!<R 0h  The total Queue 7 pkt number in TxPktbuffer */
#define BIT_SHIFT_HEAD_PKT_Q7                        0
#define BIT_MASK_HEAD_PKT_Q7                         ((u32)0x000000FF << BIT_SHIFT_HEAD_PKT_Q7)                        /*!<R FFh  The head page of the first packet of Queue 7. */

/* REG_GCLK_CFG 0x0478 */
#define BIT_SHIFT_CLR_TXRPT_RW_PTR                   2
#define BIT_CLR_TXRPT_RW_PTR                         ((u32)0x00000001 << BIT_SHIFT_CLR_TXRPT_RW_PTR)                   /*!<R/W 0h  Write 1 to clear BIT_AMPDU_TXRPT_W_PTR & BIT_AMPDU_TXRPT_R_PTR (0x47C / 0x47D) */
#define BIT_SHIFT_EN_QUEUE_RPT_B8                    1
#define BIT_EN_QUEUE_RPT_B8                          ((u32)0x00000001 << BIT_SHIFT_EN_QUEUE_RPT_B8)                    /*!<R/W 1h  [8] of BIT_EN_QUEUE_RPT, BIT8: EVENT Queue */
#define BIT_SHIFT_EN_PTCL_GCLK                       0
#define BIT_EN_PTCL_GCLK                             ((u32)0x00000001 << BIT_SHIFT_EN_PTCL_GCLK)                       /*!<R/W 1h  1: enable clock gating */

/* REG_TXRPT_CTRL 0x047C */
#define BIT_SHIFT_AMPDU_TXRPT_TIME_THRS              24
#define BIT_MASK_AMPDU_TXRPT_TIME_THRS               ((u32)0x000000FF << BIT_SHIFT_AMPDU_TXRPT_TIME_THRS)              /*!<R/W 10h  Time threshold of ampdu txrpt */
#define BIT_SHIFT_AMPDU_TXRPT_LEN_THRS               16
#define BIT_MASK_AMPDU_TXRPT_LEN_THRS                ((u32)0x000000FF << BIT_SHIFT_AMPDU_TXRPT_LEN_THRS)               /*!<R/W 08h  Length threshold of ampdu txrpt */
#define BIT_SHIFT_AMPDU_TXRPT_R_PTR                  8
#define BIT_MASK_AMPDU_TXRPT_R_PTR                   ((u32)0x000000FF << BIT_SHIFT_AMPDU_TXRPT_R_PTR)                  /*!<R/W 0h  Read pointer of ampdu txrpt */
#define BIT_SHIFT_AMPDU_TXRPT_W_PTR                  0
#define BIT_MASK_AMPDU_TXRPT_W_PTR                   ((u32)0x000000FF << BIT_SHIFT_AMPDU_TXRPT_W_PTR)                  /*!<RO 0h  Write pointer of ampdu txrpt */

/* REG_CFEND_RATE_SC_CTRL 0x0480 */
#define BIT_SHIFT_TXSC_40M                           28
#define BIT_MASK_TXSC_40M                            ((u32)0x0000000F << BIT_SHIFT_TXSC_40M)                           /*!<R/W 0h  Value of Data frame Tx sub-carrier mode 40MHz */
#define BIT_SHIFT_TXSC_20M                           24
#define BIT_MASK_TXSC_20M                            ((u32)0x0000000F << BIT_SHIFT_TXSC_20M)                           /*!<R/W 0h  Value of Data frame Tx sub-carrier mode 20MHz */
#define BIT_SHIFT_STBC_CFEND_RATE                    16
#define BIT_MASK_STBC_CFEND_RATE                     ((u32)0x0000001F << BIT_SHIFT_STBC_CFEND_RATE)                    /*!<R/W Ch  The initial rate for STBC CFEND frame transmitted as EDCA originator. The response control frame shall be selected by the definition of 802.11n. */
#define BIT_SHIFT_BASIC_CFEND_RATE                   8
#define BIT_MASK_BASIC_CFEND_RATE                    ((u32)0x0000001F << BIT_SHIFT_BASIC_CFEND_RATE)                   /*!<R/W 4h  The initial rate for basic CFEND frame transmitted as EDCA originator. The response control frame shall be selected by the definition of 802.11n. */
#define BIT_SHIFT_LEAG_RTS_BW_DUP                    5
#define BIT_LEAG_RTS_BW_DUP                          ((u32)0x00000001 << BIT_SHIFT_LEAG_RTS_BW_DUP)                    /*!<R/W 0h  If this bit is set, leag rate RTS use Duplicate in 40M BW / 80M BW. */

/* REG_MACID_SLEEP3 0x0484 */
#define BIT_SHIFT_MACID127_96_PKTSLEEP               0
#define BIT_MASK_MACID127_96_PKTSLEEP                ((u32)0xFFFFFFFF << BIT_SHIFT_MACID127_96_PKTSLEEP)               /*!<R/W 0h  Macid 127~Macid 96 Packet Sleep (per bit controlled) */

/* REG_MACID_SLEEP1 0x0488 */
#define BIT_SHIFT_MACID63_32_PKTSLEEP                0
#define BIT_MASK_MACID63_32_PKTSLEEP                 ((u32)0xFFFFFFFF << BIT_SHIFT_MACID63_32_PKTSLEEP)                /*!<R/W 0h  Macid 63~Macid 32 Packet Sleep (per bit controlled) */

/* REG_ARFR_L2 0x048C */
#define BIT_SHIFT_ADPT_RATE_TABLE_L2                 0
#define BIT_MASK_ADPT_RATE_TABLE_L2                  ((u32)0xFFFFFFFF << BIT_SHIFT_ADPT_RATE_TABLE_L2)                 /*!<R/W 0h  Data Auto Rate Fallback Table Register 1, indexed by RATid in TXDESC. The definition is the same as ARFR0. */

/* REG_ARFR_H2 0x0490 */
#define BIT_SHIFT_ADPT_RATE_TABLE_H2                 0
#define BIT_MASK_ADPT_RATE_TABLE_H2                  ((u32)0xFFFFFFFF << BIT_SHIFT_ADPT_RATE_TABLE_H2)                 /*!<R/W 0h  Data Auto Rate Fallback Table Register 1, indexed by RATid in TXDESC. The definition is the same as ARFR0. */

/* REG_ARFR_L3 0x0494 */
#define BIT_SHIFT_ADPT_RATE_TABLE_L3                 0
#define BIT_MASK_ADPT_RATE_TABLE_L3                  ((u32)0xFFFFFFFF << BIT_SHIFT_ADPT_RATE_TABLE_L3)                 /*!<R/W 0h  Data Auto Rate Fallback Table Register 1, indexed by RATid in TXDESC. The definition is the same as ARFR0. */

/* REG_ARFR_H3 0x0498 */
#define BIT_SHIFT_ADPT_RATE_TABLE_H3                 0
#define BIT_MASK_ADPT_RATE_TABLE_H3                  ((u32)0xFFFFFFFF << BIT_SHIFT_ADPT_RATE_TABLE_H3)                 /*!<R/W 0h  Data Auto Rate Fallback Table Register 1, indexed by RATid in TXDESC. The definition is the same as ARFR0. */

/* REG_ARFR_L4 0x049C */
#define BIT_SHIFT_ADPT_RATE_TABLE_L4                 0
#define BIT_MASK_ADPT_RATE_TABLE_L4                  ((u32)0xFFFFFFFF << BIT_SHIFT_ADPT_RATE_TABLE_L4)                 /*!<R/W 0h  Data Auto Rate Fallback Table Register 1, indexed by RATid in TXDESC. The definition is the same as ARFR0. */

/* REG_ARFR_H4 0x04A0 */
#define BIT_SHIFT_ADPT_RATE_TABLE_H4                 0
#define BIT_MASK_ADPT_RATE_TABLE_H4                  ((u32)0xFFFFFFFF << BIT_SHIFT_ADPT_RATE_TABLE_H4)                 /*!<R/W 0h  Data Auto Rate Fallback Table Register 1, indexed by RATid in TXDESC. The definition is the same as ARFR0. */

/* REG_ARFR_L5 0x04A4 */
#define BIT_SHIFT_ADPT_RATE_TABLE_L5                 0
#define BIT_MASK_ADPT_RATE_TABLE_L5                  ((u32)0xFFFFFFFF << BIT_SHIFT_ADPT_RATE_TABLE_L5)                 /*!<R/W 0h  Data Auto Rate Fallback Table Register 1, indexed by RATid in TXDESC. The definition is the same as ARFR0. */

/* REG_ARFR_H5 0x04A8 */
#define BIT_SHIFT_ADPT_RATE_TABLE_H5                 0
#define BIT_MASK_ADPT_RATE_TABLE_H5                  ((u32)0xFFFFFFFF << BIT_SHIFT_ADPT_RATE_TABLE_H5)                 /*!<R/W 0h  Data Auto Rate Fallback Table Register 1, indexed by RATid in TXDESC. The definition is the same as ARFR0. */

/* REG_TXRPT_START_OFFSET 0x04AC */
#define BIT_SHIFT_RPTFIFO_1K                         16
#define BIT_RPTFIFO_1K                               ((u32)0x00000001 << BIT_SHIFT_RPTFIFO_1K)                         /*!<R/W 0h  select the size of rptfifo */
#define BIT_SHIFT_MACID_CTRL_OFFSET                  8
#define BIT_MASK_MACID_CTRL_OFFSET                   ((u32)0x000000FF << BIT_SHIFT_MACID_CTRL_OFFSET)                  /*!<R/W 2h  offset of macid control */
#define BIT_SHIFT_AMPDU_TXRPT_OFFSET                 0
#define BIT_MASK_AMPDU_TXRPT_OFFSET                  ((u32)0x000000FF << BIT_SHIFT_AMPDU_TXRPT_OFFSET)                 /*!<R/W 28h  offset of AMPDU txrpt */

/* REG_POWER_STAGE1 0x04B4 */
#define BIT_SHIFT_PTA_WL_PRI_MASK_CPU_MGQ            31
#define BIT_PTA_WL_PRI_MASK_CPU_MGQ                  ((u32)0x00000001 << BIT_SHIFT_PTA_WL_PRI_MASK_CPU_MGQ)            /*!<R/W 0h  PTCL send wl_pri to PTA when pktbuf has CPU_MGQ packet */
#define BIT_SHIFT_PTA_WL_PRI_MASK_BCNQ               30
#define BIT_PTA_WL_PRI_MASK_BCNQ                     ((u32)0x00000001 << BIT_SHIFT_PTA_WL_PRI_MASK_BCNQ)               /*!<R/W 0h  PTCL send wl_pri to PTA when pktbuf has BCNQ packet */
#define BIT_SHIFT_PTA_WL_PRI_MASK_HIQ                29
#define BIT_PTA_WL_PRI_MASK_HIQ                      ((u32)0x00000001 << BIT_SHIFT_PTA_WL_PRI_MASK_HIQ)                /*!<R/W 0h  PTCL send wl_pri to PTA when pktbuf has HIQ packet */
#define BIT_SHIFT_PTA_WL_PRI_MASK_MGQ                28
#define BIT_PTA_WL_PRI_MASK_MGQ                      ((u32)0x00000001 << BIT_SHIFT_PTA_WL_PRI_MASK_MGQ)                /*!<R/W 0h  PTCL send wl_pri to PTA when pktbuf has MGQ packet */
#define BIT_SHIFT_PTA_WL_PRI_MASK_BK                 27
#define BIT_PTA_WL_PRI_MASK_BK                       ((u32)0x00000001 << BIT_SHIFT_PTA_WL_PRI_MASK_BK)                 /*!<R/W 0h  PTCL send wl_pri to PTA when pktbuf has BKQ packet */
#define BIT_SHIFT_PTA_WL_PRI_MASK_BE                 26
#define BIT_PTA_WL_PRI_MASK_BE                       ((u32)0x00000001 << BIT_SHIFT_PTA_WL_PRI_MASK_BE)                 /*!<R/W 0h  PTCL send wl_pri to PTA when pktbuf has BEQ packet */
#define BIT_SHIFT_PTA_WL_PRI_MASK_VI                 25
#define BIT_PTA_WL_PRI_MASK_VI                       ((u32)0x00000001 << BIT_SHIFT_PTA_WL_PRI_MASK_VI)                 /*!<R/W 0h  PTCL send wl_pri to PTA when pktbuf has VIQ packet */
#define BIT_SHIFT_PTA_WL_PRI_MASK_VO                 24
#define BIT_PTA_WL_PRI_MASK_VO                       ((u32)0x00000001 << BIT_SHIFT_PTA_WL_PRI_MASK_VO)                 /*!<R/W 0h  PTCL send wl_pri to PTA when pktbuf has VOQ packet */
#define BIT_SHIFT_POWER_STAGE1                       0
#define BIT_MASK_POWER_STAGE1                        ((u32)0x00FFFFFF << BIT_SHIFT_POWER_STAGE1)                       /*!<R/W 00h  User define Power Satge1 */

/* REG_POWER_STAGE2 0x04B8 */
#define BIT_SHIFT_PTA_WL_PRI_MASK_EVT                25
#define BIT_PTA_WL_PRI_MASK_EVT                      ((u32)0x00000001 << BIT_SHIFT_PTA_WL_PRI_MASK_EVT)                /*!<R/W 0h  PTCL send wl_pri to PTA when pktbuf has EVTQ packet */
#define BIT_SHIFT_CTRL_PKT_PWR_ADJ_EN                24
#define BIT_CTRL_PKT_PWR_ADJ_EN                      ((u32)0x00000001 << BIT_SHIFT_CTRL_PKT_PWR_ADJ_EN)                /*!<R/W 0h  enable RTS power adjust by retry count */
#define BIT_SHIFT_POWER_STAGE2                       0
#define BIT_MASK_POWER_STAGE2                        ((u32)0x00FFFFFF << BIT_SHIFT_POWER_STAGE2)                       /*!<R/W 00h  User define Power Satge2 */

/* REG_SW_AMPDU_BURST_MODE_CTRL 0x04BC */
#define BIT_SHIFT_EVTQ_HEAD                          24
#define BIT_MASK_EVTQ_HEAD                           ((u32)0x000000FF << BIT_SHIFT_EVTQ_HEAD)                          /*!<R/W f6h  TXDMA will pull eventq Pkt in this address. NAN */
#define BIT_SHIFT_DMA_THIS_QUEUE                     20
#define BIT_MASK_DMA_THIS_QUEUE                      ((u32)0x0000000F << BIT_SHIFT_DMA_THIS_QUEUE)                     /*!<R/W 0h  scheduler enable */
#define BIT_SHIFT_TOTAL_LEN_THRS                     8
#define BIT_MASK_TOTAL_LEN_THRS                      ((u32)0x00000FFF << BIT_SHIFT_TOTAL_LEN_THRS)                     /*!<R/W 400h  aggregation length over threshold then fetch pad packet in early mode */
#define BIT_SHIFT_WEP_PRETX_EN                       7
#define BIT_WEP_PRETX_EN                             ((u32)0x00000001 << BIT_SHIFT_WEP_PRETX_EN)                       /*!<R/W 0h  Enable pretx for WEP/TKIP, to allow a slower security clock */
#define BIT_SHIFT_PRE_TX_CMD                         6
#define BIT_PRE_TX_CMD                               ((u32)0x00000001 << BIT_SHIFT_PRE_TX_CMD)                         /*!<R/W 1h  enable pre tx cmd to use aggr more packet */
#define BIT_SHIFT_NUM_SCL_EN                         4
#define BIT_MASK_NUM_SCL_EN                          ((u32)0x00000003 << BIT_SHIFT_NUM_SCL_EN)                         /*!<R/W 0h  SW MPDU Burst mode select 00: each length field for 1 MPDU 01: each length field is the summation of 2 MPDUs 10: each length field is the summation of 3 MPDUs 11: each length field is the summation of 4 MPDUs Note: the total MPDU number is no more than 15. */
#define BIT_SHIFT_BK_EN                              3
#define BIT_BK_EN                                    ((u32)0x00000001 << BIT_SHIFT_BK_EN)                              /*!<R/W 0h  AMPDU burst mode enable for AC_BK queue */
#define BIT_SHIFT_BE_EN                              2
#define BIT_BE_EN                                    ((u32)0x00000001 << BIT_SHIFT_BE_EN)                              /*!<R/W 0h  AMPDU burst mode enable for AC_BE queue */
#define BIT_SHIFT_VI_EN                              1
#define BIT_VI_EN                                    ((u32)0x00000001 << BIT_SHIFT_VI_EN)                              /*!<R/W 0h  AMPDU burst mode enable for AC_VI queue */
#define BIT_SHIFT_VO_EN                              0
#define BIT_VO_EN                                    ((u32)0x00000001 << BIT_SHIFT_VO_EN)                              /*!<R/W 0h  AMPDU burst mode enable for AC_VO queue */

/* REG_PKT_LIFE_TIME 0x04C0 */
#define BIT_SHIFT_PKT_LIFTIME_BEBK                   16
#define BIT_MASK_PKT_LIFTIME_BEBK                    ((u32)0x0000FFFF << BIT_SHIFT_PKT_LIFTIME_BEBK)                   /*!<R/W 1000h  BE/BK packet lifetime unit: 256us */
#define BIT_SHIFT_PKT_LIFTIME_VOVI                   0
#define BIT_MASK_PKT_LIFTIME_VOVI                    ((u32)0x0000FFFF << BIT_SHIFT_PKT_LIFTIME_VOVI)                   /*!<R/W 1000h  VO/VI packet lifetime unit: 256us */

/* REG_STBC_SETTING 0x04C4 */
#define BIT_SHIFT_CDEND_TXTIME_H                     8
#define BIT_MASK_CDEND_TXTIME_H                      ((u32)0x0000001F << BIT_SHIFT_CDEND_TXTIME_H)                     /*!<R/W 3h  Cfend packet txtime bit[8:4] */
#define BIT_SHIFT_CDEND_TXTIME_L                     4
#define BIT_MASK_CDEND_TXTIME_L                      ((u32)0x0000000F << BIT_SHIFT_CDEND_TXTIME_L)                     /*!<R/W 4h  Cfend packet txtime bit[3:0] */
#define BIT_SHIFT_NESS                               2
#define BIT_MASK_NESS                                ((u32)0x00000003 << BIT_SHIFT_NESS)                               /*!<R/W 0h  NESS */
#define BIT_SHIFT_STBC_CFEND                         0
#define BIT_MASK_STBC_CFEND                          ((u32)0x00000003 << BIT_SHIFT_STBC_CFEND)                         /*!<R/W 0h  CFEND STBC */

/* REG_PTA_CTRL 0x04C6 */
#define BIT_SHIFT_EN_SINGLE_APMDU                    15
#define BIT_EN_SINGLE_APMDU                          ((u32)0x00000001 << BIT_SHIFT_EN_SINGLE_APMDU)                    /*!<R/W 0h  If this bit is set, Enable single sub-frame APMDU. */
#define BIT_SHIFT_FORCE_RND_PRI                      6
#define BIT_FORCE_RND_PRI                            ((u32)0x00000001 << BIT_SHIFT_FORCE_RND_PRI)                      /*!<R/W 0h  queue select priority control 1:old round robin method 0:depend on last selected queue */
#define BIT_SHIFT_PTA_EDCCA_EN                       5
#define BIT_PTA_EDCCA_EN                             ((u32)0x00000001 << BIT_SHIFT_PTA_EDCCA_EN)                       /*!<R/W 0h  0 : wl_tx signal to PTA does not consider EDCCA 1 : wl_tx signal to PTA consider EDCCA */
#define BIT_SHIFT_PTA_WL_TX_EN                       4
#define BIT_PTA_WL_TX_EN                             ((u32)0x00000001 << BIT_SHIFT_PTA_WL_TX_EN)                       /*!<R/W 0h  enable WL PTA (should be set in init MAC) */
#define BIT_SHIFT_R_USE_DATA_BW                      3
#define BIT_R_USE_DATA_BW                            ((u32)0x00000001 << BIT_SHIFT_R_USE_DATA_BW)                      /*!<R/W 0h  1 : Use des2_data_bw for this packet 0 : when des1_cca_rts = 2'b10, update_bw depend on ch_bw_status */
#define BIT_SHIFT_TRI_PKT_STATUS                     2
#define BIT_TRI_PKT_STATUS                           ((u32)0x00000001 << BIT_SHIFT_TRI_PKT_STATUS)                     /*!<R/W 1h   */
#define BIT_SHIFT_TRI_PKT_PKTIN                      1
#define BIT_TRI_PKT_PKTIN                            ((u32)0x00000001 << BIT_SHIFT_TRI_PKT_PKTIN)                      /*!<R/W 0h  If trigger frame is transmitted into txpktbuf, HW generates interrupt 1: Enable 0: Disable */
#define BIT_SHIFT_ACQ_MODE_SEL                       0
#define BIT_ACQ_MODE_SEL                             ((u32)0x00000001 << BIT_SHIFT_ACQ_MODE_SEL)                       /*!<R/W 0h  1: Enable 88C 4AC Mode 0: Enable 8723 ACQ0~7 Mode */

/* REG_PROT_MODE_CTRL 0x04C8 */
#define BIT_SHIFT_RTS_MAX_AGG_NUM                    24
#define BIT_MASK_RTS_MAX_AGG_NUM                     ((u32)0x0000003F << BIT_SHIFT_RTS_MAX_AGG_NUM)                    /*!<R/W Ch  In RTS frame exchange sequence, the maximum aggregation packet number limit is defined by this register, unit is byte */
#define BIT_SHIFT_MAX_AGG_NUM                        16
#define BIT_MASK_MAX_AGG_NUM                         ((u32)0x0000003F << BIT_SHIFT_MAX_AGG_NUM)                        /*!<R/W 14h  the maximum aggregation packet number limit,unit is byte */
#define BIT_SHIFT_RTS_TXTIME_TH                      8
#define BIT_MASK_RTS_TXTIME_TH                       ((u32)0x000000FF << BIT_SHIFT_RTS_TXTIME_TH)                      /*!<R/W 1h  RTS packet txtime threshold, unit is 64 us */
#define BIT_SHIFT_RTSLEN_TH                          0
#define BIT_MASK_RTSLEN_TH                           ((u32)0x000000FF << BIT_SHIFT_RTSLEN_TH)                          /*!<R/W 1h  RTS packet Length threshold, unit is 128 bytes */

/* REG_BAR_MODE_CTRL 0x04CC */
#define BIT_SHIFT_RTY_PKT_LMT                        24
#define BIT_MASK_RTY_PKT_LMT                         ((u32)0x0000003F << BIT_SHIFT_RTY_PKT_LMT)                        /*!<R/W 1h  retry packet limit */
#define BIT_SHIFT_BAR_RTY_LMT                        16
#define BIT_MASK_BAR_RTY_LMT                         ((u32)0x00000003 << BIT_SHIFT_BAR_RTY_LMT)                        /*!<R/W 2h  BAR retry limit */
#define BIT_SHIFT_BAR_PKTTIME_THRS                   8
#define BIT_MASK_BAR_PKTTIME_THRS                    ((u32)0x000000FF << BIT_SHIFT_BAR_PKTTIME_THRS)                   /*!<R/W FFh  BAR packet time thrs */
#define BIT_SHIFT_BAR_PKTNUM_TH_V1                   0
#define BIT_MASK_BAR_PKTNUM_TH_V1                    ((u32)0x0000007F << BIT_SHIFT_BAR_PKTNUM_TH_V1)                   /*!<R/W 7Fh  BAR Pktnum Thrs */

/* REG_MACID_SLEEP2 0x04D0 */
#define BIT_SHIFT_MACID95_64PKTSLEEP                 0
#define BIT_MASK_MACID95_64PKTSLEEP                  ((u32)0xFFFFFFFF << BIT_SHIFT_MACID95_64PKTSLEEP)                 /*!<R/W 0h  Macid 95~Macid 64 Packet Sleep (per bit controlled) */

/* REG_MACID_SLEEP 0x04D4 */
#define BIT_SHIFT_MACID31_0_PKTSLEEP                 0
#define BIT_MASK_MACID31_0_PKTSLEEP                  ((u32)0xFFFFFFFF << BIT_SHIFT_MACID31_0_PKTSLEEP)                 /*!<R/W 0h  Macid31 ~ Macid 0Packet Sleep. (per bit controlled) */

/* REG_HW_SEQ0_1 0x04D8 */
#define BIT_SHIFT_HW_SSN_SEQ1                        16
#define BIT_MASK_HW_SSN_SEQ1                         ((u32)0x00000FFF << BIT_SHIFT_HW_SSN_SEQ1)                        /*!<R/W 000h  When TXDESC HWSEQEN is set, MAC will overwrite SEQ control by this register. Before DRV hand over the SEQ control to HW, DRV may set the current SEQ to this register. When DRV will take back the SEQ control from HW, DRV may get the current sequence from this register. */
#define BIT_SHIFT_HW_SSN_SEQ0                        0
#define BIT_MASK_HW_SSN_SEQ0                         ((u32)0x00000FFF << BIT_SHIFT_HW_SSN_SEQ0)                        /*!<R/W 000h  When TXDESC HWSEQEN is set, MAC will overwrite SEQ control by this register. Before DRV hand over the SEQ control to HW, DRV may set the current SEQ to this register. When DRV will take back the SEQ control from HW, DRV may get the current sequence from this register. */

/* REG_HW_SEQ2_3 0x04DC */
#define BIT_SHIFT_HW_SSN_SEQ3                        16
#define BIT_MASK_HW_SSN_SEQ3                         ((u32)0x00000FFF << BIT_SHIFT_HW_SSN_SEQ3)                        /*!<R/W 000h  When TXDESC HWSEQEN is set, MAC will overwrite SEQ control by this register. Before DRV hand over the SEQ control to HW, DRV may set the current SEQ to this register. When DRV will take back the SEQ control from HW, DRV may get the current sequence from this register. */
#define BIT_SHIFT_HW_SSN_SEQ2                        0
#define BIT_MASK_HW_SSN_SEQ2                         ((u32)0x00000FFF << BIT_SHIFT_HW_SSN_SEQ2)                        /*!<R/W 000h  When TXDESC HWSEQEN is set, MAC will overwrite SEQ control by this register. Before DRV hand over the SEQ control to HW, DRV may set the current SEQ to this register. When DRV will take back the SEQ control from HW, DRV may get the current sequence from this register. */

/* REG_NULL_PKT_STATUS 0x04E0 */
#define BIT_SHIFT_RD_FTMT2R_ERR                      15
#define BIT_RD_FTMT2R_ERR                            ((u32)0x00000001 << BIT_SHIFT_RD_FTMT2R_ERR)                      /*!<R/W1C 0  Indicates the timeout error in FTM t2r report */
#define BIT_SHIFT_CLI3_TX_NULL_1                     9
#define BIT_CLI3_TX_NULL_1                           ((u32)0x00000001 << BIT_SHIFT_CLI3_TX_NULL_1)                     /*!<RO 0  Port 4 Tx Null 1 packet ok indicator */
#define BIT_SHIFT_CLI3_TX_NULL_0                     8
#define BIT_CLI3_TX_NULL_0                           ((u32)0x00000001 << BIT_SHIFT_CLI3_TX_NULL_0)                     /*!<RO 0  Port 4 Tx Null 0 packet ok indicator */
#define BIT_SHIFT_CLI2_TX_NULL_1                     7
#define BIT_CLI2_TX_NULL_1                           ((u32)0x00000001 << BIT_SHIFT_CLI2_TX_NULL_1)                     /*!<RO 0  Port 3 Tx Null 1 packet ok indicator */
#define BIT_SHIFT_CLI2_TX_NULL_0                     6
#define BIT_CLI2_TX_NULL_0                           ((u32)0x00000001 << BIT_SHIFT_CLI2_TX_NULL_0)                     /*!<RO 0  Port 3 Tx Null 0 packet ok indicator */
#define BIT_SHIFT_CLI1_TX_NULL_1                     5
#define BIT_CLI1_TX_NULL_1                           ((u32)0x00000001 << BIT_SHIFT_CLI1_TX_NULL_1)                     /*!<RO 0  Port 2 Tx Null 1 packet ok indicator */
#define BIT_SHIFT_CLI1_TX_NULL_0                     4
#define BIT_CLI1_TX_NULL_0                           ((u32)0x00000001 << BIT_SHIFT_CLI1_TX_NULL_0)                     /*!<RO 0  Port 2 Tx Null 0 packet ok indicator */
#define BIT_SHIFT_CLI0_TX_NULL_1                     3
#define BIT_CLI0_TX_NULL_1                           ((u32)0x00000001 << BIT_SHIFT_CLI0_TX_NULL_1)                     /*!<RO 0  Port 1 Tx Null 1 packet ok indicator */
#define BIT_SHIFT_CLI0_TX_NULL_0                     2
#define BIT_CLI0_TX_NULL_0                           ((u32)0x00000001 << BIT_SHIFT_CLI0_TX_NULL_0)                     /*!<RO 0  Port 1 Tx Null 0 packet ok indicator */
#define BIT_SHIFT_TX_NULL_1                          1
#define BIT_TX_NULL_1                                ((u32)0x00000001 << BIT_SHIFT_TX_NULL_1)                          /*!<RO 0  Port 0 Tx Null 1 packet ok indicator */
#define BIT_SHIFT_TX_NULL_0                          0
#define BIT_TX_NULL_0                                ((u32)0x00000001 << BIT_SHIFT_TX_NULL_0)                          /*!<RO 0  Port 0 Tx Null 0 packet ok indicator */

/* REG_PTCL_ERR_STATUS 0x04E2 */
#define BIT_SHIFT_PTCL_TOTAL_PG0_7                   8
#define BIT_MASK_PTCL_TOTAL_PG0_7                    ((u32)0x000000FF << BIT_SHIFT_PTCL_TOTAL_PG0_7)                   /*!<RO 0  Total Page in PTCL */
#define BIT_SHIFT_PTCL_TOTAL_PG_8                    7
#define BIT_PTCL_TOTAL_PG_8                          ((u32)0x00000001 << BIT_SHIFT_PTCL_TOTAL_PG_8)                    /*!<RO 0  Total Page in PTCL */
#define BIT_SHIFT_PTCL_RATE_TABLE_INVALID            6
#define BIT_PTCL_RATE_TABLE_INVALID                  ((u32)0x00000001 << BIT_SHIFT_PTCL_RATE_TABLE_INVALID)            /*!<R/W1C 0  during rate fallback process, if the all rate table is invalid, then assert ERROR FLAG */
#define BIT_SHIFT_RD_TXHANG_ERR                      5
#define BIT_RD_TXHANG_ERR                            ((u32)0x00000001 << BIT_SHIFT_RD_TXHANG_ERR)                      /*!<R/W1C 0  Indicates the txhang error in RDG mode */
#define BIT_SHIFT_RD_STATUS_ERR                      4
#define BIT_RD_STATUS_ERR                            ((u32)0x00000001 << BIT_SHIFT_RD_STATUS_ERR)                      /*!<R/W1C 0  Indicates the status error in RDG mode */
#define BIT_SHIFT_RD_CTN_ERR                         3
#define BIT_RD_CTN_ERR                               ((u32)0x00000001 << BIT_SHIFT_RD_CTN_ERR)                         /*!<R/W1C 0  Indicates the cnt error in RDG mode */
#define BIT_SHIFT_RD_PKTIN_ERR                       0
#define BIT_MASK_RD_PKTIN_ERR                        ((u32)0x00000007 << BIT_SHIFT_RD_PKTIN_ERR)                       /*!<R/W1C 0  Indicates the pktin error in RDG mode */

/* REG_PRETX_DROP_CTRL 0x04E4 */
#define BIT_SHIFT_COLLI_DETEC_TIME_MAX               20
#define BIT_MASK_COLLI_DETEC_TIME_MAX                ((u32)0x0000000F << BIT_SHIFT_COLLI_DETEC_TIME_MAX)               /*!<R/W Fh  0~15: The field indicated collision detect time for broadcast or Beacon packet.(unit: us) */
#define BIT_SHIFT_PRETX_AGGR_EN                      19
#define BIT_PRETX_AGGR_EN                            ((u32)0x00000001 << BIT_SHIFT_PRETX_AGGR_EN)                      /*!<R/W 0  1: enable PRETX function 0: disable PRETX function */
#define BIT_SHIFT_PRETX_AGGR_TIME_MAX                8
#define BIT_MASK_PRETX_AGGR_TIME_MAX                 ((u32)0x000007FF << BIT_SHIFT_PRETX_AGGR_TIME_MAX)                /*!<R/W 230h  If BIT_PRETX_AGGR_EN = 1, the bits will count down after PHYTXON signal asserting every transmission in pre-tx mode.(Default: 7us) */
#define BIT_SHIFT_HGQ_DEL_EN                         7
#define BIT_HGQ_DEL_EN                               ((u32)0x00000001 << BIT_SHIFT_HGQ_DEL_EN)                         /*!<R/W 0  1: HGQ packet will be dropped when enable macid delete function; 0: HGQ packet cannot be dropped */
#define BIT_SHIFT_MGQ_DEL_EN                         6
#define BIT_MGQ_DEL_EN                               ((u32)0x00000001 << BIT_SHIFT_MGQ_DEL_EN)                         /*!<R/W 0  1: MGQ packet will be dropped when enable macid delete function; 0: MGQ packet cannot be dropped */

/* REG_BT_POLLUTE_PKT_CNT 0x04E8 */
#define BIT_SHIFT_BT_POLLUTE_PKT_CNT                 0
#define BIT_MASK_BT_POLLUTE_PKT_CNT                  ((u32)0x0000FFFF << BIT_SHIFT_BT_POLLUTE_PKT_CNT)                 /*!<R 0h  count the tx fail pkt caused by bt pollute, write 0x4E8[15] will clear the counter */

/* REG_DROP_PKT_NUM 0x04EC */
#define BIT_SHIFT_LIFE_DROP_NUM                      16
#define BIT_MASK_LIFE_DROP_NUM                       ((u32)0x0000FFFF << BIT_SHIFT_LIFE_DROP_NUM)                      /*!<R/W 0h  TIE 0 in 8723F */
#define BIT_SHIFT_DROP_PKT_NUM                       0
#define BIT_MASK_DROP_PKT_NUM                        ((u32)0x0000FFFF << BIT_SHIFT_DROP_PKT_NUM)                       /*!<R/WC 0h  Statistic the number of dropped packets */

/* REG_CPUMGQ_TIMER_CTRL 0x04F4 */
#define BIT_SHIFT_MGQ_TRI_HEAD                       16
#define BIT_MASK_MGQ_TRI_HEAD                        ((u32)0x00000FFF << BIT_SHIFT_MGQ_TRI_HEAD)                       /*!<R/W 0h  The head page of the CPUMGQ pkt If the CPUMGQ is triggered by TX TIMER. */
#define BIT_SHIFT_CPUMGQ_TRI_LIFETIME_EN             8
#define BIT_CPUMGQ_TRI_LIFETIME_EN                   ((u32)0x00000001 << BIT_SHIFT_CPUMGQ_TRI_LIFETIME_EN)             /*!<R/W 0h  When this bit is set, enable the lifetime function. This lifetime threshold only affect CPUMGQ trigger from Tx_Timer. */
#define BIT_SHIFT_CPUMGQ_TRI_LIFETIME                0
#define BIT_MASK_CPUMGQ_TRI_LIFETIME                 ((u32)0x000000FF << BIT_SHIFT_CPUMGQ_TRI_LIFETIME)                /*!<R/W 0h  LIFETIME Threshold: Unit = 256us. When CPU MgntQ is triggered, If BIT_CPUMGQ_TRI_LIFETIME_EN = 1, count down. If BIT_CPUMGQ_TRI_LIFETIME_EN = 0, do nothing. */

/* REG_DUMMY 0x04FC */
#define BIT_SHIFT_DUMMY_REG_1                        18
#define BIT_MASK_DUMMY_REG_1                         ((u32)0x00003FFF << BIT_SHIFT_DUMMY_REG_1)                        /*!<R/W 3FFFh  dummy reg */
#define BIT_SHIFT_EN_BCN_TRXRPT                      17
#define BIT_EN_BCN_TRXRPT                            ((u32)0x00000001 << BIT_SHIFT_EN_BCN_TRXRPT)                      /*!<R/W 1h  If this bit is set, PTCL will write BCN TRXRPT when BCNOK/BCNERR INT. FW have clear this bit before enter LPS 32K mode. */
#define BIT_SHIFT_DUMMY_REG_0                        0
#define BIT_MASK_DUMMY_REG_0                         ((u32)0x0001FFFF << BIT_SHIFT_DUMMY_REG_0)                        /*!<R/W 10000h  dummy reg */

/* REG_ARFR_L6 0x1400 */
#define BIT_SHIFT_ADPT_RATE_TABLE_L6                 0
#define BIT_MASK_ADPT_RATE_TABLE_L6                  ((u32)0xFFFFFFFF << BIT_SHIFT_ADPT_RATE_TABLE_L6)                 /*!<R/W 0h  Data Auto Rate Fallback Table Register 6, indexed by RATid in TXDESC. The definition is the same as ARFR0. */

/* REG_ARFR_H6 0x1404 */
#define BIT_SHIFT_ADPT_RATE_TABLE_H6                 0
#define BIT_MASK_ADPT_RATE_TABLE_H6                  ((u32)0xFFFFFFFF << BIT_SHIFT_ADPT_RATE_TABLE_H6)                 /*!<R/W 0h  Data Auto Rate Fallback Table Register 6, indexed by RATid in TXDESC. The definition is the same as ARFR0. */

/* REG_ARFR_L7 0x1408 */
#define BIT_SHIFT_ADPT_RATE_TABLE_L7                 0
#define BIT_MASK_ADPT_RATE_TABLE_L7                  ((u32)0xFFFFFFFF << BIT_SHIFT_ADPT_RATE_TABLE_L7)                 /*!<R/W 0h  Data Auto Rate Fallback Table Register 7, indexed by RATid in TXDESC. The definition is the same as ARFR0. */

/* REG_ARFR_H7 0x140C */
#define BIT_SHIFT_ADPT_RATE_TABLE_H7                 0
#define BIT_MASK_ADPT_RATE_TABLE_H7                  ((u32)0xFFFFFFFF << BIT_SHIFT_ADPT_RATE_TABLE_H7)                 /*!<R/W 0h  Data Auto Rate Fallback Table Register 7, indexed by RATid in TXDESC. The definition is the same as ARFR0. */

/* REG_ARFR_L8 0x1410 */
#define BIT_SHIFT_ADPT_RATE_TABLE_L8                 0
#define BIT_MASK_ADPT_RATE_TABLE_L8                  ((u32)0xFFFFFFFF << BIT_SHIFT_ADPT_RATE_TABLE_L8)                 /*!<R/W 0h  Data Auto Rate Fallback Table Register 8, indexed by RATid in TXDESC. The definition is the same as ARFR0. */

/* REG_ARFR_H8 0x1414 */
#define BIT_SHIFT_ADPT_RATE_TABLE_H8                 0
#define BIT_MASK_ADPT_RATE_TABLE_H8                  ((u32)0xFFFFFFFF << BIT_SHIFT_ADPT_RATE_TABLE_H8)                 /*!<R/W 0h  Data Auto Rate Fallback Table Register 8, indexed by RATid in TXDESC. The definition is the same as ARFR0. */

/* REG_AESIV_SETTING 0x1424 */
#define BIT_SHIFT_AESIV_OFFSET                       0
#define BIT_MASK_AESIV_OFFSET                        ((u32)0x00000FFF << BIT_SHIFT_AESIV_OFFSET)                       /*!<R/W 0h  aesiv offset in txrpt buffer (Unit:128Bytes). */

/* REG_BF0_TIME_SETTING 0x1428 */
#define BIT_SHIFT_BF0_TIMER_SET                      31
#define BIT_BF0_TIMER_SET                            ((u32)0x00000001 << BIT_SHIFT_BF0_TIMER_SET)                      /*!<R/W 0h  write 1 to set beamforming 0 timer to BIT_bf0_lifetime */
#define BIT_SHIFT_BF0_TIMER_CLR                      30
#define BIT_BF0_TIMER_CLR                            ((u32)0x00000001 << BIT_SHIFT_BF0_TIMER_CLR)                      /*!<R/W 0h  write 1 to clear beamforming 0 timer to 0 */
#define BIT_SHIFT_EN_BF0_UPDATE                      29
#define BIT_EN_BF0_UPDATE                            ((u32)0x00000001 << BIT_SHIFT_EN_BF0_UPDATE)                      /*!<R/W 0h  1: when tx ndp ok/fail, enable to update beamforming 0 timer */
#define BIT_SHIFT_EN_BF0_TIMER                       28
#define BIT_EN_BF0_TIMER                             ((u32)0x00000001 << BIT_SHIFT_EN_BF0_TIMER)                       /*!<R/W 0h  beamforming 0 timer enable */
#define BIT_SHIFT_BF0_PRETIME_OVER                   16
#define BIT_MASK_BF0_PRETIME_OVER                    ((u32)0x00000FFF << BIT_SHIFT_BF0_PRETIME_OVER)                   /*!<R/W FFFh  beamforming 0 pre timeout time */
#define BIT_SHIFT_BF0_LIFETIME                       0
#define BIT_MASK_BF0_LIFETIME                        ((u32)0x0000FFFF << BIT_SHIFT_BF0_LIFETIME)                       /*!<R/W FFFFh  beamforming 0 life time */

/* REG_BF1_TIME_SETTING 0x142C */
#define BIT_SHIFT_BF1_TIMER_SET                      31
#define BIT_BF1_TIMER_SET                            ((u32)0x00000001 << BIT_SHIFT_BF1_TIMER_SET)                      /*!<R/W 0h  write 1 to set beamforming 1 timer to BIT_bf1_lifetime */
#define BIT_SHIFT_BF1_TIMER_CLR                      30
#define BIT_BF1_TIMER_CLR                            ((u32)0x00000001 << BIT_SHIFT_BF1_TIMER_CLR)                      /*!<R/W 0h  write 1 to clear beamforming 1 timer to 0 */
#define BIT_SHIFT_EN_BF1_UPDATE                      29
#define BIT_EN_BF1_UPDATE                            ((u32)0x00000001 << BIT_SHIFT_EN_BF1_UPDATE)                      /*!<R/W 0h  1: when tx ndp ok/fail, enable to update beamforming 1 timer */
#define BIT_SHIFT_EN_BF1_TIMER                       28
#define BIT_EN_BF1_TIMER                             ((u32)0x00000001 << BIT_SHIFT_EN_BF1_TIMER)                       /*!<R/W 0h  beamforming 1 timer enable */
#define BIT_SHIFT_BF1_PRETIME_OVER                   16
#define BIT_MASK_BF1_PRETIME_OVER                    ((u32)0x00000FFF << BIT_SHIFT_BF1_PRETIME_OVER)                   /*!<R/W FFFh  beamforming 1 pre timeout time */
#define BIT_SHIFT_BF1_LIFETIME                       0
#define BIT_MASK_BF1_LIFETIME                        ((u32)0x0000FFFF << BIT_SHIFT_BF1_LIFETIME)                       /*!<R/W FFFFh  beamforming 1 life time */

/* REG_BF_TIMEOUT_EN 0x1430 */
#define BIT_SHIFT_EN_VHT_LDPC                        9
#define BIT_EN_VHT_LDPC                              ((u32)0x00000001 << BIT_SHIFT_EN_VHT_LDPC)                        /*!<R/W 1h  1: enable ldpc in vht rate mode */
#define BIT_SHIFT_EN_HT_LDPC                         8
#define BIT_EN_HT_LDPC                               ((u32)0x00000001 << BIT_SHIFT_EN_HT_LDPC)                         /*!<R/W 1h  1: enable ldpc in ht rate mode */
#define BIT_SHIFT_BF1_TIMEOUT_EN                     1
#define BIT_BF1_TIMEOUT_EN                           ((u32)0x00000001 << BIT_SHIFT_BF1_TIMEOUT_EN)                     /*!<R/W 1h  1: when beamforming 1 timer count to 0,then disable beamforming 0 */
#define BIT_SHIFT_BF0_TIMEOUT_EN                     0
#define BIT_BF0_TIMEOUT_EN                           ((u32)0x00000001 << BIT_SHIFT_BF0_TIMEOUT_EN)                     /*!<R/W 1h  1: when beamforming 0 timer count to 0,then disable beamforming 0 */

/* REG_MACID_RELEASE0 0x1434 */
#define BIT_SHIFT_MACID31_0_RELEASE                  0
#define BIT_MASK_MACID31_0_RELEASE                   ((u32)0xFFFFFFFF << BIT_SHIFT_MACID31_0_RELEASE)                  /*!<R/W 0h  Macid31~Macid0 Release(per bit controlled) */

/* REG_MACID_RELEASE1 0x1438 */
#define BIT_SHIFT_MACID63_32_RELEASE                 0
#define BIT_MASK_MACID63_32_RELEASE                  ((u32)0xFFFFFFFF << BIT_SHIFT_MACID63_32_RELEASE)                 /*!<R/W 0h  Macid63~Macid32 Release(per bit controlled) */

/* REG_MACID_RELEASE2 0x143C */
#define BIT_SHIFT_MACID95_64_RELEASE                 0
#define BIT_MASK_MACID95_64_RELEASE                  ((u32)0xFFFFFFFF << BIT_SHIFT_MACID95_64_RELEASE)                 /*!<R/W 0h  Macid95~Macid64 Release (per bit controlled) */

/* REG_MACID_RELEASE3 0x1440 */
#define BIT_SHIFT_MACID127_96_RELEASE                0
#define BIT_MASK_MACID127_96_RELEASE                 ((u32)0xFFFFFFFF << BIT_SHIFT_MACID127_96_RELEASE)                /*!<R/W 0h  Macid127~Macid96 Release (per bit controlled) */

/* REG_MACID_RELEASE_SETTING 0x1444 */
#define BIT_SHIFT_MACID_VALUE                        7
#define BIT_MACID_VALUE                              ((u32)0x00000001 << BIT_SHIFT_MACID_VALUE)                        /*!<R/W 0h  write this field to set REG_macid_release[BIT_macid_offset] = BIT_macid_value */
#define BIT_SHIFT_MACID_OFFSET                       0
#define BIT_MASK_MACID_OFFSET                        ((u32)0x0000007F << BIT_SHIFT_MACID_OFFSET)                       /*!<R/W 0h  write this field to set REG_macid_release[BIT_macid_offset] = BIT_macid_value */

/* REG_FAST_EDCA_VOVI_SETTING 0x1448 */
#define BIT_SHIFT_VI_FAST_EDCA_TO                    24
#define BIT_MASK_VI_FAST_EDCA_TO                     ((u32)0x000000FF << BIT_SHIFT_VI_FAST_EDCA_TO)                    /*!<R/W 8h  vi queue fast edca timeout value */
#define BIT_SHIFT_VI_THRESHOLD_SEL                   23
#define BIT_VI_THRESHOLD_SEL                         ((u32)0x00000001 << BIT_SHIFT_VI_THRESHOLD_SEL)                   /*!<R/W 0h  1: use all vi queue pktnum compare to pktnum_threshold; 0: use single macid pktnum compare to pktnum_threshold; */
#define BIT_SHIFT_VI_FAST_EDCA_PKT_TH                16
#define BIT_MASK_VI_FAST_EDCA_PKT_TH                 ((u32)0x0000007F << BIT_SHIFT_VI_FAST_EDCA_PKT_TH)                /*!<R/W 4h  vi queue fast edca pkt number threshold */
#define BIT_SHIFT_VO_FAST_EDCA_TO                    8
#define BIT_MASK_VO_FAST_EDCA_TO                     ((u32)0x000000FF << BIT_SHIFT_VO_FAST_EDCA_TO)                    /*!<R/W 8h  vo queue fast edca timeout value */
#define BIT_SHIFT_VO_THRESHOLD_SEL                   7
#define BIT_VO_THRESHOLD_SEL                         ((u32)0x00000001 << BIT_SHIFT_VO_THRESHOLD_SEL)                   /*!<R/W 0h  1: use all vo queue pktnum compare to pktnum_threshold; 0: use single macid pktnum compare to pktnum_threshold; */
#define BIT_SHIFT_VO_FAST_EDCA_PKT_TH                0
#define BIT_MASK_VO_FAST_EDCA_PKT_TH                 ((u32)0x0000007F << BIT_SHIFT_VO_FAST_EDCA_PKT_TH)                /*!<R/W 4h  vo queue fast edca pkt number threshold */

/* REG_FAST_EDCA_BEBK_SETTING 0x144C */
#define BIT_SHIFT_BK_FAST_EDCA_TO                    24
#define BIT_MASK_BK_FAST_EDCA_TO                     ((u32)0x000000FF << BIT_SHIFT_BK_FAST_EDCA_TO)                    /*!<R/W 8h  bk queue fast edca timeout value */
#define BIT_SHIFT_BK_THRESHOLD_SEL                   23
#define BIT_BK_THRESHOLD_SEL                         ((u32)0x00000001 << BIT_SHIFT_BK_THRESHOLD_SEL)                   /*!<R/W 0h  1: use all bk queue pktnum compare to pktnum_threshold; 0: use single macid pktnum compare to pktnum_threshold; */
#define BIT_SHIFT_BK_FAST_EDCA_PKT_TH                16
#define BIT_MASK_BK_FAST_EDCA_PKT_TH                 ((u32)0x0000007F << BIT_SHIFT_BK_FAST_EDCA_PKT_TH)                /*!<R/W 4h  bk queue fast edca pkt number threshold */
#define BIT_SHIFT_BE_FAST_EDCA_TO                    8
#define BIT_MASK_BE_FAST_EDCA_TO                     ((u32)0x000000FF << BIT_SHIFT_BE_FAST_EDCA_TO)                    /*!<R/W 8h  be queue fast edca timeout value */
#define BIT_SHIFT_BE_THRESHOLD_SEL                   7
#define BIT_BE_THRESHOLD_SEL                         ((u32)0x00000001 << BIT_SHIFT_BE_THRESHOLD_SEL)                   /*!<R/W 0h  1: use all be queue pktnum compare to pktnum_threshold; 0: use single macid pktnum compare to pktnum_threshold; */
#define BIT_SHIFT_BE_FAST_EDCA_PKT_TH                0
#define BIT_MASK_BE_FAST_EDCA_PKT_TH                 ((u32)0x0000007F << BIT_SHIFT_BE_FAST_EDCA_PKT_TH)                /*!<R/W 4h  be queue fast edca pkt number threshold */

/* REG_MACID_DROP0 0x1450 */
#define BIT_SHIFT_MACID31_0_DROP                     0
#define BIT_MASK_MACID31_0_DROP                      ((u32)0xFFFFFFFF << BIT_SHIFT_MACID31_0_DROP)                     /*!<R/W 0h  Macid31~Macid0 Drop (per bit controlled) */

/* REG_MACID_DROP1 0x1454 */
#define BIT_SHIFT_MACID63_32_DROP                    0
#define BIT_MASK_MACID63_32_DROP                     ((u32)0xFFFFFFFF << BIT_SHIFT_MACID63_32_DROP)                    /*!<R/W 0h  Macid63~Macid32 Drop (per bit controlled) */

/* REG_MACID_DROP2 0x1458 */
#define BIT_SHIFT_MACID95_64_DROP                    0
#define BIT_MASK_MACID95_64_DROP                     ((u32)0xFFFFFFFF << BIT_SHIFT_MACID95_64_DROP)                    /*!<R/W 0h  Macid95~Macid64 Drop (per bit controlled) */

/* REG_MACID_DROP3 0x145C */
#define BIT_SHIFT_MACID127_96_DROP                   0
#define BIT_MASK_MACID127_96_DROP                    ((u32)0xFFFFFFFF << BIT_SHIFT_MACID127_96_DROP)                   /*!<R/W 0h  Macid127~Macid96 Drop (per bit controlled) */

/* REG_R_MACID_RELEASE_SUCCESS_0 0x1460 */
#define BIT_SHIFT_R_MACID_RELEASE_SUCCESS_0          0
#define BIT_MASK_R_MACID_RELEASE_SUCCESS_0           ((u32)0xFFFFFFFF << BIT_SHIFT_R_MACID_RELEASE_SUCCESS_0)          /*!<R/W 0h  macid0~31 */

/* REG_R_MACID_RELEASE_SUCCESS_1 0x1464 */
#define BIT_SHIFT_R_MACID_RELEASE_SUCCESS_1          0
#define BIT_MASK_R_MACID_RELEASE_SUCCESS_1           ((u32)0xFFFFFFFF << BIT_SHIFT_R_MACID_RELEASE_SUCCESS_1)          /*!<R/W 0h  macid32~63 */

/* REG_R_MACID_RELEASE_SUCCESS_2 0x1468 */
#define BIT_SHIFT_R_MACID_RELEASE_SUCCESS_2          0
#define BIT_MASK_R_MACID_RELEASE_SUCCESS_2           ((u32)0xFFFFFFFF << BIT_SHIFT_R_MACID_RELEASE_SUCCESS_2)          /*!<R/W 0h  macid64~95 */

/* REG_R_MACID_RELEASE_SUCCESS_3 0x146C */
#define BIT_SHIFT_R_MACID_RELEASE_SUCCESS_3          0
#define BIT_MASK_R_MACID_RELEASE_SUCCESS_3           ((u32)0xFFFFFFFF << BIT_SHIFT_R_MACID_RELEASE_SUCCESS_3)          /*!<R/W 0h  macid96~127 */

/* REG_MGQ_FIFO_CTRL 0x1470 */
#define BIT_SHIFT_MGQ_FIFO_EN                        31
#define BIT_MGQ_FIFO_EN                              ((u32)0x00000001 << BIT_SHIFT_MGQ_FIFO_EN)                        /*!<R/W 0h  1: Enable MGQ FIFO Function. 0: Disable MGQ FIFO Function. */
#define BIT_SHIFT_MGQ_FIFO_PG_SIZE                   28
#define BIT_MASK_MGQ_FIFO_PG_SIZE                    ((u32)0x00000007 << BIT_SHIFT_MGQ_FIFO_PG_SIZE)                   /*!<R/W 1h  The page size of MGQ FIFO PKTs. */
#define BIT_SHIFT_MGQ_FIFO_START_PG                  16
#define BIT_MASK_MGQ_FIFO_START_PG                   ((u32)0x00000FFF << BIT_SHIFT_MGQ_FIFO_START_PG)                  /*!<R/W 0h  The start page of MGQ FIFO. */
#define BIT_SHIFT_MGQ_FIFO_SIZE                      14
#define BIT_MASK_MGQ_FIFO_SIZE                       ((u32)0x00000003 << BIT_SHIFT_MGQ_FIFO_SIZE)                      /*!<R/W 0h  2'b00 : FIFO size 4 pkts. 2'b01 : FIFO size 8 pkts. 2'b1x : FIFO size 16 pkts. */
#define BIT_SHIFT_MGQ_FIFO_PAUSE                     13
#define BIT_MGQ_FIFO_PAUSE                           ((u32)0x00000001 << BIT_SHIFT_MGQ_FIFO_PAUSE)                     /*!<R/W 0h  1: use all vo queue pktnum compare to pktnum_threshold; 0: use signle macid pktnum compare to pktnum_threshold; */
#define BIT_SHIFT_MGQ_FIFO_RPTR                      8
#define BIT_MASK_MGQ_FIFO_RPTR                       ((u32)0x0000001F << BIT_SHIFT_MGQ_FIFO_RPTR)                      /*!<W 0h  The read pointer of the MGQ FIFO.(clear when disable MGQ FIFO function) */
#define BIT_SHIFT_MGQ_FIFO_OV                        7
#define BIT_MGQ_FIFO_OV                              ((u32)0x00000001 << BIT_SHIFT_MGQ_FIFO_OV)                        /*!<W 0h  1: MGQ FIFO overflow. 0: NO MGQ FIFO overflow. */
#define BIT_SHIFT_MGQ_FIFO_WPTR_ERR                  6
#define BIT_MGQ_FIFO_WPTR_ERR                        ((u32)0x00000001 << BIT_SHIFT_MGQ_FIFO_WPTR_ERR)                  /*!<W 0h  1: Error of MGQ FIFO write pointer setting. 0: No error of MGQ FIFO write pointer setting. (clear when disable MGQ FIFO function) */
#define BIT_SHIFT_CPUM_LIFETIME_EN                   5
#define BIT_CPUM_LIFETIME_EN                         ((u32)0x00000001 << BIT_SHIFT_CPUM_LIFETIME_EN)                   /*!<R/W 0h  1: Enable Lifetime function of the MGQ FIFO pkts. 0: Disable Lifetime function of the MGQ FIFO pkts. */
#define BIT_SHIFT_MGQ_FIFO_WPTR                      0
#define BIT_MASK_MGQ_FIFO_WPTR                       ((u32)0x0000001F << BIT_SHIFT_MGQ_FIFO_WPTR)                      /*!<R/W 0h  The write pointer of the MGQ FIFO */

/* REG_MGQ_FIFO_RELEASE_INT 0x1474 */
#define BIT_SHIFT_MGQ_FIFO_INT_FLAG                  16
#define BIT_MASK_MGQ_FIFO_INT_FLAG                   ((u32)0x0000FFFF << BIT_SHIFT_MGQ_FIFO_INT_FLAG)                  /*!<W 0h  The flag of the MGQ FIFO PKT release interrupt, write one clear. */
#define BIT_SHIFT_MGQ_FIFO_INT_MASK                  0
#define BIT_MASK_MGQ_FIFO_INT_MASK                   ((u32)0x0000FFFF << BIT_SHIFT_MGQ_FIFO_INT_MASK)                  /*!<R/W 0h  The mask of the MGQ FIFO PKT release interrupt. */

/* REG_MGQ_FIFO_LIFETIME_VALID 0x1478 */
#define BIT_SHIFT_MGQ_FIFO_LIFETIME                  16
#define BIT_MASK_MGQ_FIFO_LIFETIME                   ((u32)0x0000FFFF << BIT_SHIFT_MGQ_FIFO_LIFETIME)                  /*!<R/W 1000h  MGQ FIFO packet lifetime unit: 256us */
#define BIT_SHIFT_MGQ_FIFO_VALID_CLR_1               8
#define BIT_MASK_MGQ_FIFO_VALID_CLR_1                ((u32)0x000000FF << BIT_SHIFT_MGQ_FIFO_VALID_CLR_1)               /*!<R/W 0h  Clear the valid map of the MGQ FIFO PKT, high [15:8] bits */
#define BIT_SHIFT_MGQ_FIFO_VALID_CLR_0               0
#define BIT_MASK_MGQ_FIFO_VALID_CLR_0                ((u32)0x000000FF << BIT_SHIFT_MGQ_FIFO_VALID_CLR_0)               /*!<R/W 0h  Clear the valid map of the MGQ FIFO PKT, low [7:0] bits */

/* REG_R_MACID_RELEASE_SUCCESS_CLEAR_OFFSET 0x147C */
#define BIT_SHIFT_R_MACID_RELEASE_SUCCESS_CLEAR_OFFSET 0
#define BIT_MASK_R_MACID_RELEASE_SUCCESS_CLEAR_OFFSET ((u32)0x0000007F << BIT_SHIFT_R_MACID_RELEASE_SUCCESS_CLEAR_OFFSET)/*!<R/W 0h  HW will set 0x2460~0x246C if one packet was released successfully for a given macid. SW use this register to reset the status. */

/* REG_EDCA_VO_PARAM 0x0500 */
#define BIT_SHIFT_TXOPLIMIT                          16
#define BIT_MASK_TXOPLIMIT                           ((u32)0x000007FF << BIT_SHIFT_TXOPLIMIT)                          /*!<R/W 0x2f  TXOP Limit An unsigned integer in units of 32 microseconds. Value of zero indicates that a single MSDU or MMPDU in addition to a protection frame exchange can be transmitted at any rate. Default: BK = 0h; BE = 0h; VI = 5Eh; VO = 2Fh. */
#define BIT_SHIFT_CW                                 8
#define BIT_MASK_CW                                  ((u32)0x000000FF << BIT_SHIFT_CW)                                 /*!<R/W 0x32  ECWmin and ECWmax encode the values of Cwmin and Cwmax respectively in an exponent form. Ex: Cwmax = 2^(ECWmax)-1 Default: BK = Ah/5h; BE = Ah/5h; VI = 5h/4h; VO = 4h/3h. */
#define BIT_SHIFT_AIFS                               0
#define BIT_MASK_AIFS                                ((u32)0x000000FF << BIT_SHIFT_AIFS)                               /*!<R/W 0x24  Arbitrary Inter frame space In unit of microsecond. AIFS indicates the time a non-AP QSTA should defer before either invoking a backoff or starting a transmission Default: BK = 49h; BE = 25h; VI = 1Ch; VO = 1Ch. */

/* REG_EDCA_VI_PARAM 0x0504 */
#define BIT_SHIFT_TXOPLIMIT                          16
#define BIT_MASK_TXOPLIMIT                           ((u32)0x000007FF << BIT_SHIFT_TXOPLIMIT)                          /*!<R/W 0x5e  TXOP Limit An unsigned integer in units of 32 microseconds. Value of zero indicates that a single MSDU or MMPDU in addition to a protection frame exchange can be transmitted at any rate. Default: BK = 0h; BE = 0h; VI = 5Eh; VO = 2Fh. */
#define BIT_SHIFT_CW                                 8
#define BIT_MASK_CW                                  ((u32)0x000000FF << BIT_SHIFT_CW)                                 /*!<R/W 0x43  ECWmin and ECWmax encode the values of Cwmin and Cwmax respectively in an exponent form. Ex: Cwmax = 2^(ECWmax)-1 Default: BK = Ah/5h; BE = Ah/5h; VI = 5h/4h; VO = 4h/3h. */
#define BIT_SHIFT_AIFS                               0
#define BIT_MASK_AIFS                                ((u32)0x000000FF << BIT_SHIFT_AIFS)                               /*!<R/W 0x26  Arbitrary Inter frame space In unit of microsecond. AIFS indicates the time a non-AP QSTA should defer before either invoking a backoff or starting a transmission Default: BK = 49h; BE = 25h; VI = 1Ch; VO = 1Ch. */

/* REG_EDCA_BE_PARAM 0x0508 */
#define BIT_SHIFT_TXOPLIMIT                          16
#define BIT_MASK_TXOPLIMIT                           ((u32)0x000007FF << BIT_SHIFT_TXOPLIMIT)                          /*!<R/W 0x00  TXOP Limit An unsigned integer in units of 32 microseconds. Value of zero indicates that a single MSDU or MMPDU in addition to a protection frame exchange can be transmitted at any rate. Default: BK = 0h; BE = 0h; VI = 5Eh; VO = 2Fh. */
#define BIT_SHIFT_CW                                 8
#define BIT_MASK_CW                                  ((u32)0x000000FF << BIT_SHIFT_CW)                                 /*!<R/W 0xa4  ECWmin and ECWmax encode the values of Cwmin and Cwmax respectively in an exponent form. Ex: Cwmax = 2^(ECWmax)-1 Default: BK = Ah/5h; BE = Ah/5h; VI = 5h/4h; VO = 4h/3h. */
#define BIT_SHIFT_AIFS                               0
#define BIT_MASK_AIFS                                ((u32)0x000000FF << BIT_SHIFT_AIFS)                               /*!<R/W 0x2b  Arbitrary Inter frame space In unit of microsecond. AIFS indicates the time a non-AP QSTA should defer before either invoking a backoff or starting a transmission Default: BK = 49h; BE = 25h; VI = 1Ch; VO = 1Ch. */

/* REG_EDCA_BK_PARAM 0x050C */
#define BIT_SHIFT_TXOPLIMIT                          16
#define BIT_MASK_TXOPLIMIT                           ((u32)0x000007FF << BIT_SHIFT_TXOPLIMIT)                          /*!<R/W 0x00  TXOP Limit An unsigned integer in units of 32 microseconds. Value of zero indicates that a single MSDU or MMPDU in addition to a protection frame exchange can be transmitted at any rate. Default: BK = 0h; BE = 0h; VI = 5Eh; VO = 2Fh. */
#define BIT_SHIFT_CW                                 8
#define BIT_MASK_CW                                  ((u32)0x000000FF << BIT_SHIFT_CW)                                 /*!<R/W 0xa5  ECWmin and ECWmax encode the values of Cwmin and Cwmax respectively in an exponent form. Ex: Cwmax = 2^(ECWmax)-1 Default: BK = Ah/5h; BE = Ah/5h; VI = 5h/4h; VO = 4h/3h. */
#define BIT_SHIFT_AIFS                               0
#define BIT_MASK_AIFS                                ((u32)0x000000FF << BIT_SHIFT_AIFS)                               /*!<R/W 0x49  Arbitrary Inter frame space In unit of microsecond. AIFS indicates the time a non-AP QSTA should defer before either invoking a backoff or starting a transmission Default: BK = 49h; BE = 25h; VI = 1Ch; VO = 1Ch. */

/* REG_BCN_CFG_PIFS 0x0510 */
#define BIT_SHIFT_RDG_PIFS                           24
#define BIT_MASK_RDG_PIFS                            ((u32)0x000000FF << BIT_SHIFT_RDG_PIFS)                           /*!<R/W 0x28  PIFS time. It is only used in RDG mode and in units of us. */
#define BIT_SHIFT_PIFS                               16
#define BIT_MASK_PIFS                                ((u32)0x000000FF << BIT_SHIFT_PIFS)                               /*!<R/W 0x1c  PIFS time. It is only used in AP mode and in units of us. */
#define BIT_SHIFT_BCNCW_MAX                          12
#define BIT_MASK_BCNCW_MAX                           ((u32)0x0000000F << BIT_SHIFT_BCNCW_MAX)                          /*!<R/W 0x4  Beacon Contention Window MAX Defines the contention window value for back off before transmitting beacon frame. This field is set to 0 in AP mode to indicate no back off window. In ad hoc mode, its default value is 6. 26-1 = 63 time slots. */
#define BIT_SHIFT_BCNCW_MIN                          8
#define BIT_MASK_BCNCW_MIN                           ((u32)0x0000000F << BIT_SHIFT_BCNCW_MIN)                          /*!<R/W 0x4  Beacon Contention Window Defines the contention window value for back off before transmitting beacon frame. This field is set to 0 in AP mode to indicate no back off window. In ad hoc mode, its default value is 6. 26-1 = 63 time slots. */
#define BIT_SHIFT_BCNIFS                             0
#define BIT_MASK_BCNIFS                              ((u32)0x000000FF << BIT_SHIFT_BCNIFS)                             /*!<R/W 0x13  Beacon Interframe Space In units of microseconds, this register defines the medium idle time required before transmitting beacon (AP mode) or entering random back off window. */

/* REG_SIFS 0x0514 */
#define BIT_SHIFT_SIFS_OFDM_TRX                      24
#define BIT_MASK_SIFS_OFDM_TRX                       ((u32)0x000000FF << BIT_SHIFT_SIFS_OFDM_TRX)                      /*!<R/W 0xE  This register sets the SIFS time required in NAV protection period after receiving any immediate response. for example Ack-Data or RTS/CTS-Data. It is in unit of us. */
#define BIT_SHIFT_SIFS_CCK_TRX                       16
#define BIT_MASK_SIFS_CCK_TRX                        ((u32)0x000000FF << BIT_SHIFT_SIFS_CCK_TRX)                       /*!<R/W 0xA  This register sets the SIFS time required in NAV protection period after receiving any immediate response. for example Ack-Data or RTS/CTS-Data. It is in unit of us. */
#define BIT_SHIFT_SIFS_OFDM_CTX                      8
#define BIT_MASK_SIFS_OFDM_CTX                       ((u32)0x000000FF << BIT_SHIFT_SIFS_OFDM_CTX)                      /*!<R/W 0xE  This register sets the SIFS time required for consecutive TX events for example CTS2S-Data, or broadcast bursting. It is in unit of us. */
#define BIT_SHIFT_SIFS_CCK_CTX                       0
#define BIT_MASK_SIFS_CCK_CTX                        ((u32)0x000000FF << BIT_SHIFT_SIFS_CCK_CTX)                       /*!<R/W 0xA  This register sets the SIFS time required for consecutive TX events for example CTS2S-Data, or broadcast bursting. It is in unit of us. */

/* REG_TSFT_SYN_OFFSET_SLOT 0x0518 */
#define BIT_SHIFT_SLOTTIME                           24
#define BIT_MASK_SLOTTIME                            ((u32)0x000000FF << BIT_SHIFT_SLOTTIME)                           /*!<R/W 0x09  This register sets the slot time value mentioned in 802.11 specification. It is in units of us. Default: 0x9 */
#define BIT_SHIFT_AGGR_BK_TIME                       16
#define BIT_MASK_AGGR_BK_TIME                        ((u32)0x000000FF << BIT_SHIFT_AGGR_BK_TIME)                       /*!<R/W 0x14  Hw will break aggr. In sifs condition */
#define BIT_SHIFT_TSFTR_SYNC_OFFSET                  0
#define BIT_MASK_TSFTR_SYNC_OFFSET                   ((u32)0x0000FFFF << BIT_SHIFT_TSFTR_SYNC_OFFSET)                  /*!<R/W 0x640  tsft sync. Offset (bcn0 sync to bcn1 offset or bcn1 sync to bcn0 offset). Unit : 32us, default is 50ms */

/* REG_PS_NOA_ERLY_TIME 0x051C */
#define BIT_SHIFT_NOA_OFF_ERLY_TIME                  8
#define BIT_MASK_NOA_OFF_ERLY_TIME                   ((u32)0x000000FF << BIT_SHIFT_NOA_OFF_ERLY_TIME)                  /*!<R/W 0x5  NOA off early interval, Time unit is TU. */

/* REG_TX_PTCL_CTRL 0x0520 */
#define BIT_SHIFT_DIS_EDCCA                          15
#define BIT_DIS_EDCCA                                ((u32)0x00000001 << BIT_SHIFT_DIS_EDCCA)                          /*!<R?/W 0x0  Disable EDCCA function 0: PHY_EDCCA can block TX (default) 1: PHY_EDCCA cannot block TX OK -> TX beacon; X -> cannot TX beacon 0x528[7] 0x520[15] 0x520[14] TX bcn TX bcn (OFDMCCA=0, (OFDMCCA=1, EDCCA=1) EDCCA=1) 0 0 0 X X 0 0 1 X X 0 1 0 OK X 0 1 1 OK OK 1 0 0 X X 1 0 1 X X 1 1 0 OK X 1 1 1 OK OK */
#define BIT_SHIFT_DIS_CCA                            14
#define BIT_DIS_CCA                                  ((u32)0x00000001 << BIT_SHIFT_DIS_CCA)                            /*!<R/W 0x0  Disable CCA */
#define BIT_SHIFT_LSIG_TXOP_TXCMD_NAV                13
#define BIT_LSIG_TXOP_TXCMD_NAV                      ((u32)0x00000001 << BIT_SHIFT_LSIG_TXOP_TXCMD_NAV)                /*!<R/W 0x1  Set LSIG_TXOP from TXCMD_NAV field */
#define BIT_SHIFT_SIFS_BK_EN                         12
#define BIT_SIFS_BK_EN                               ((u32)0x00000001 << BIT_SHIFT_SIFS_BK_EN)                         /*!<R?/W 0x1  SIFS Break Check Criteria enable for AMPDU aggregation */
#define BIT_SHIFT_TXQ_NAV_MSK                        8
#define BIT_MASK_TXQ_NAV_MSK                         ((u32)0x0000000F << BIT_SHIFT_TXQ_NAV_MSK)                        /*!<R/W 0xF  1: Queue BKF must wait TX Nav finished 0: Queue not need wait */
#define BIT_SHIFT_DIS_CW                             7
#define BIT_DIS_CW                                   ((u32)0x00000001 << BIT_SHIFT_DIS_CW)                             /*!<R/W 0x0  When this bit is set, disable CW. */
#define BIT_SHIFT_NAV_END_TXOP                       6
#define BIT_NAV_END_TXOP                             ((u32)0x00000001 << BIT_SHIFT_NAV_END_TXOP)                       /*!<R/W 0x0  1: In txop mode, Nav protect all txop 0: In txop mode, Nav protect to next pkt */
#define BIT_SHIFT_RDG_END_TXOP                       5
#define BIT_RDG_END_TXOP                             ((u32)0x00000001 << BIT_SHIFT_RDG_END_TXOP)                       /*!<R/W 0x0  1: In tx RDG mode, Nav protect all txop 0: In tx RDG mode, Nav protect to next pkt */
#define BIT_SHIFT_MGTQ_TXOP_EN                       3
#define BIT_MGTQ_TXOP_EN                             ((u32)0x00000001 << BIT_SHIFT_MGTQ_TXOP_EN)                       /*!<R/W 0x1  When this bit is set, MGTQ may sent packets by using ACQ TXOP. */
#define BIT_SHIFT_MGTQ_RTSMF_EN                      2
#define BIT_MGTQ_RTSMF_EN                            ((u32)0x00000001 << BIT_SHIFT_MGTQ_RTSMF_EN)                      /*!<R/W 0x1  When this bit is set, MTGQ will be TX, not wait until RTS or MF transaction finished. */
#define BIT_SHIFT_HIQ_RTSMF_EN                       1
#define BIT_HIQ_RTSMF_EN                             ((u32)0x00000001 << BIT_SHIFT_HIQ_RTSMF_EN)                       /*!<R/W 0x1  When this bit is set, HIQ will be TX, not wait until RTS or MF transaction finished. */
#define BIT_SHIFT_BCN_RTSMF_EN                       0
#define BIT_BCN_RTSMF_EN                             ((u32)0x00000001 << BIT_SHIFT_BCN_RTSMF_EN)                       /*!<R/W 0x1  When this bit is set, BCNQ will be TX, not wait until RTS or MF transaction finished. */

/* REG_TXPAUSE 0x0522 */
#define BIT_SHIFT_STOP_CPUMGQ                        7
#define BIT_STOP_CPUMGQ                              ((u32)0x00000001 << BIT_SHIFT_STOP_CPUMGQ)                        /*!<R/W 0x0  To control CPUMGQ queues contention circuit. 1: CPUMGQ queues all stop. 0: Enable CPUMGQ queues contention circuit */
#define BIT_SHIFT_MAC_STOPBCNQ                       6
#define BIT_MAC_STOPBCNQ                             ((u32)0x00000001 << BIT_SHIFT_MAC_STOPBCNQ)                       /*!<R/W 0x0  Stop BCNQ Queue Write a 1 to this bit via software to immediately stop the transmission of packet from this queue including retry attempts. */
#define BIT_SHIFT_MAC_STOPHIQ                        5
#define BIT_MAC_STOPHIQ                              ((u32)0x00000001 << BIT_SHIFT_MAC_STOPHIQ)                        /*!<R/W 0x0  Stop High Queue Write a 1 to this bit via software to immediately stop the transmission of packet from this queue including retry attempts. */
#define BIT_SHIFT_MAC_STOPMGQ                        4
#define BIT_MAC_STOPMGQ                              ((u32)0x00000001 << BIT_SHIFT_MAC_STOPMGQ)                        /*!<R/W 0x0  Stop Management Queue Write a 1 to this bit via software to immediately stop the transmission of packet from this queue including retry attempts. */
#define BIT_SHIFT_MAC_STOPBK                         3
#define BIT_MAC_STOPBK                               ((u32)0x00000001 << BIT_SHIFT_MAC_STOPBK)                         /*!<R/W 0x0  Stop BK Queue Write a 1 to this bit via software to immediately stop the transmission of packet from this queue including retry attempts. */
#define BIT_SHIFT_MAC_STOPBE                         2
#define BIT_MAC_STOPBE                               ((u32)0x00000001 << BIT_SHIFT_MAC_STOPBE)                         /*!<R/W 0x0  Stop BE Queue Write a 1 to this bit via software to immediately stop the transmission of packet from this queue including retry attempts. */
#define BIT_SHIFT_MAC_STOPVI                         1
#define BIT_MAC_STOPVI                               ((u32)0x00000001 << BIT_SHIFT_MAC_STOPVI)                         /*!<R/W 0x0  Stop VI Queue Write a 1 to this bit via software to immediately stop the transmission of packet from this queue including retry attempts. */
#define BIT_SHIFT_MAC_STOPVO                         0
#define BIT_MAC_STOPVO                               ((u32)0x00000001 << BIT_SHIFT_MAC_STOPVO)                         /*!<R/W 0x0  Stop VO Queue Write a 1 to this bit via software to immediately stop the transmission of packet from this queue including retry attempts. */

/* REG_DIS_TXREQ_CLR 0x0523 */
#define BIT_SHIFT_DIS_BT_CCA                         7
#define BIT_DIS_BT_CCA                               ((u32)0x00000001 << BIT_SHIFT_DIS_BT_CCA)                         /*!<R/W 0x0  Disable BT_CCA */
#define BIT_SHIFT_DIS_TXREQ_CLR_CPUMGQ               6
#define BIT_DIS_TXREQ_CLR_CPUMGQ		     ((u32)0x00000001 << BIT_SHIFT_DIS_TXREQ_CLR_CPUMGQ)               /*!<R/W 0x0  1: if this queue can��t own channel ,txcmd will be cleared 0:Only TX_finish can clear txreq */
#define BIT_SHIFT_DIS_TXREQ_CLR_HI                   5
#define BIT_DIS_TXREQ_CLR_HI                         ((u32)0x00000001 << BIT_SHIFT_DIS_TXREQ_CLR_HI)                   /*!<R/W 0x0  0: if this queue can��t own channel ,txcmd will be cleared 1:Only TX_finish can clear txreq */
#define BIT_SHIFT_DIS_TXREQ_CLR_MGQ                  4
#define BIT_DIS_TXREQ_CLR_MGQ                        ((u32)0x00000001 << BIT_SHIFT_DIS_TXREQ_CLR_MGQ)                  /*!<R/W 0x0  1: if this queue can��t own channel ,txcmd will be cleared 0:Only TX_finish can clear txreq */
#define BIT_SHIFT_DIS_TXREQ_CLR_BK                   3
#define BIT_DIS_TXREQ_CLR_BK                         ((u32)0x00000001 << BIT_SHIFT_DIS_TXREQ_CLR_BK)                   /*!<R/W 0x0  0: if this queue can��t own channel ,txcmd will be cleared 1:Only TX_finish can clear txreq */
#define BIT_SHIFT_DIS_TXREQ_CLR_BE                   2
#define BIT_DIS_TXREQ_CLR_BE                         ((u32)0x00000001 << BIT_SHIFT_DIS_TXREQ_CLR_BE)                   /*!<R/W 0x0  0: if this queue can��t own channel ,txcmd will be cleared 1:Only TX_finish can clear txreq */
#define BIT_SHIFT_DIS_TXREQ_CLR_VI                   1
#define BIT_DIS_TXREQ_CLR_VI                         ((u32)0x00000001 << BIT_SHIFT_DIS_TXREQ_CLR_VI)                   /*!<R/W 0x0  0: if this queue can��t own channel ,txcmd will be cleared 1:Only TX_finish can clear txreq */
#define BIT_SHIFT_DIS_TXREQ_CLR_VO                   0
#define BIT_DIS_TXREQ_CLR_VO                         ((u32)0x00000001 << BIT_SHIFT_DIS_TXREQ_CLR_VO)                   /*!<R/W 0x0  0: if this queue can��t own channel ,txcmd will be cleared 1:Only TX_finish can clear txreq */

/* REG_RD_CTRL 0x0524 */
#define BIT_SHIFT_DIS_TX_OVER_BCNQ                   14
#define BIT_DIS_TX_OVER_BCNQ                         ((u32)0x00000001 << BIT_SHIFT_DIS_TX_OVER_BCNQ)                   /*!<R/W 0x1  1: Tx Packet with ignoring Beacon Area time 0: Disable */
#define BIT_SHIFT_EN_BCNERR_INCCCA                   13
#define BIT_EN_BCNERR_INCCCA                         ((u32)0x00000001 << BIT_SHIFT_EN_BCNERR_INCCCA)                   /*!<R/W 0x0  eneble force tx becon ignore CCA in disable contention area */
#define BIT_SHIFT_EN_BCNERR_INEDCCA                  12
#define BIT_EN_BCNERR_INEDCCA                        ((u32)0x00000001 << BIT_SHIFT_EN_BCNERR_INEDCCA)                  /*!<R/W 0x0  eneble force tx becon ignore EDCCA in disable contention area */
#define BIT_SHIFT_EDCCA_MSK_CNTDOWN_EN               11
#define BIT_EDCCA_MSK_CNTDOWN_EN                     ((u32)0x00000001 << BIT_SHIFT_EDCCA_MSK_CNTDOWN_EN)               /*!<R/W 0x1  1: disable EDCCA count down, 0: enable EDCCA count down AC backoff �Ƿ���Ҫ����PHY_EDCCA 0: ������PHY_EDCCA 1: ����PHY_EDCCA (default, PHY_EDCCA=1�rֹͣbackoff) */
#define BIT_SHIFT_DIS_TXOP_CFE                       10
#define BIT_DIS_TXOP_CFE                             ((u32)0x00000001 << BIT_SHIFT_DIS_TXOP_CFE)                       /*!<R/W 0x0  Disable TXOP_CFE function */
#define BIT_SHIFT_DIS_LSIG_CFE                       9
#define BIT_DIS_LSIG_CFE                             ((u32)0x00000001 << BIT_SHIFT_DIS_LSIG_CFE)                       /*!<R/W 0x0  Disable LSIG_TXOP CF-END function */
#define BIT_SHIFT_DIS_STBC_CFE                       8
#define BIT_DIS_STBC_CFE                             ((u32)0x00000001 << BIT_SHIFT_DIS_STBC_CFE)                       /*!<R/W 0x0  Disable STBC CF-END function */
#define BIT_SHIFT_BKQ_RD_INIT_EN                     7
#define BIT_BKQ_RD_INIT_EN                           ((u32)0x00000001 << BIT_SHIFT_BKQ_RD_INIT_EN)                     /*!<R/W 0x0  Enable BKQ RD initiator function */
#define BIT_SHIFT_BEQ_RD_INIT_EN                     6
#define BIT_BEQ_RD_INIT_EN                           ((u32)0x00000001 << BIT_SHIFT_BEQ_RD_INIT_EN)                     /*!<R/W 0x0  Enable BEQ RD initiator function */
#define BIT_SHIFT_VIQ_RD_INIT_EN                     5
#define BIT_VIQ_RD_INIT_EN                           ((u32)0x00000001 << BIT_SHIFT_VIQ_RD_INIT_EN)                     /*!<R/W 0x0  Enable VIQ RD initiator function */
#define BIT_SHIFT_VOQ_RD_INIT_EN                     4
#define BIT_VOQ_RD_INIT_EN                           ((u32)0x00000001 << BIT_SHIFT_VOQ_RD_INIT_EN)                     /*!<R/W 0x0  Enable VOQ RD initiator function */
#define BIT_SHIFT_BKQ_RD_RESP_EN                     3
#define BIT_BKQ_RD_RESP_EN                           ((u32)0x00000001 << BIT_SHIFT_BKQ_RD_RESP_EN)                     /*!<R/W 0x1  Enable BKQ RD responder function */
#define BIT_SHIFT_BEQ_RD_RESP_EN                     2
#define BIT_BEQ_RD_RESP_EN                           ((u32)0x00000001 << BIT_SHIFT_BEQ_RD_RESP_EN)                     /*!<R/W 0x1  Enable BEQ RD responder function */
#define BIT_SHIFT_VIQ_RD_RESP_EN                     1
#define BIT_VIQ_RD_RESP_EN                           ((u32)0x00000001 << BIT_SHIFT_VIQ_RD_RESP_EN)                     /*!<R/W 0x1  Enable VIQ RD responder function */
#define BIT_SHIFT_VOQ_RD_RESP_EN                     0
#define BIT_VOQ_RD_RESP_EN                           ((u32)0x00000001 << BIT_SHIFT_VOQ_RD_RESP_EN)                     /*!<R/W 0x1  Enable VOQ RD responder function */

/* REG_MBSSID_CTRL 0x0526 */
#define BIT_SHIFT_MBID_BCNQ7_EN                      7
#define BIT_MBID_BCNQ7_EN                            ((u32)0x00000001 << BIT_SHIFT_MBID_BCNQ7_EN)                      /*!<R/W 0x1  When enable, auto MBSSID for virtual interface 7 is enable. */
#define BIT_SHIFT_MBID_BCNQ6_EN                      6
#define BIT_MBID_BCNQ6_EN                            ((u32)0x00000001 << BIT_SHIFT_MBID_BCNQ6_EN)                      /*!<R/W 0x1  When enable, auto MBSSID for virtual interface 6 is enable. */
#define BIT_SHIFT_MBID_BCNQ5_EN                      5
#define BIT_MBID_BCNQ5_EN                            ((u32)0x00000001 << BIT_SHIFT_MBID_BCNQ5_EN)                      /*!<R/W 0x1  When enable, auto MBSSID for virtual interface 5 is enable. */
#define BIT_SHIFT_MBID_BCNQ4_EN                      4
#define BIT_MBID_BCNQ4_EN                            ((u32)0x00000001 << BIT_SHIFT_MBID_BCNQ4_EN)                      /*!<R/W 0x1  When enable, auto MBSSID for virtual interface 4 is enable. */
#define BIT_SHIFT_MBID_BCNQ3_EN                      3
#define BIT_MBID_BCNQ3_EN                            ((u32)0x00000001 << BIT_SHIFT_MBID_BCNQ3_EN)                      /*!<R/W 0x1  When enable, auto MBSSID for virtual interface 3 is enable. */
#define BIT_SHIFT_MBID_BCNQ2_EN                      2
#define BIT_MBID_BCNQ2_EN                            ((u32)0x00000001 << BIT_SHIFT_MBID_BCNQ2_EN)                      /*!<R/W 0x1  When enable, auto MBSSID for virtual interface 2 is enable. */
#define BIT_SHIFT_MBID_BCNQ1_EN                      1
#define BIT_MBID_BCNQ1_EN                            ((u32)0x00000001 << BIT_SHIFT_MBID_BCNQ1_EN)                      /*!<R/W 0x1  When enable, auto MBSSID for virtual interface 1 is enable. */
#define BIT_SHIFT_MBID_BCNQ0_EN                      0
#define BIT_MBID_BCNQ0_EN                            ((u32)0x00000001 << BIT_SHIFT_MBID_BCNQ0_EN)                      /*!<R/W 0x1  When enable, auto MBSSID for root interface is enable. */

/* REG_P2P_NOA0_CTRL 0x0527 */
#define BIT_SHIFT_P2P_NOA0_ALLSTASLEEP               7
#define BIT_P2P_NOA0_ALLSTASLEEP                     ((u32)0x00000001 << BIT_SHIFT_P2P_NOA0_ALLSTASLEEP)               /*!<R/W 0x0  It indicates that the state from CTWindow End to BcnEarly 1: Sleep 0: Wake */
#define BIT_SHIFT_P2P_NOA0_DISTX_EN                  6
#define BIT_P2P_NOA0_DISTX_EN                        ((u32)0x00000001 << BIT_SHIFT_P2P_NOA0_DISTX_EN)                  /*!<R/W 0x0  1: Hw will disable TX in P2P_off period 0: Do Nothing */
#define BIT_SHIFT_P2P_NOA0_PWR_MGT_EN                5
#define BIT_P2P_NOA0_PWR_MGT_EN                      ((u32)0x00000001 << BIT_SHIFT_P2P_NOA0_PWR_MGT_EN)                /*!<R/W 0x0  A main switch for P2P PowerSaving 1: Enable 0: Disable */
#define BIT_SHIFT_P2P_NOA0_EN                        3
#define BIT_MASK_P2P_NOA0_EN                         ((u32)0x00000003 << BIT_SHIFT_P2P_NOA0_EN)                        /*!<R/W 0x0  The condition that noa_unit0, [1]-NOA1, [0]-NOA0 1: Enable 0: Disable */
#define BIT_SHIFT_P2P_NOA0_UNIT_SEL                  1
#define BIT_MASK_P2P_NOA0_UNIT_SEL                   ((u32)0x00000003 << BIT_SHIFT_P2P_NOA0_UNIT_SEL)                  /*!<R/W 0x0  The selector for the source of noa unit0. 0 for port 0, 1 for port 1��2 for port2 */
#define BIT_SHIFT_EN_TSFBIT32_RST_NOA0               0
#define BIT_EN_TSFBIT32_RST_NOA0                     ((u32)0x00000001 << BIT_SHIFT_EN_TSFBIT32_RST_NOA0)               /*!<R/W 0x1  when enable, if tsft_bit32_int is asserted, reset power_cs of noa_unit0 */

/* REG_PKT_LIFETIME_CTRL 0x0528 */
#define BIT_SHIFT_CHANGE_POW_BCN_AREA                23
#define BIT_CHANGE_POW_BCN_AREA                      ((u32)0x00000001 << BIT_SHIFT_CHANGE_POW_BCN_AREA)                /*!<R/W 0x0  select real_ctwindow & real_bcnq_area for noa_unit */
#define BIT_SHIFT_EN_BKF_CLR_TXREQ                   22
#define BIT_EN_BKF_CLR_TXREQ                         ((u32)0x00000001 << BIT_SHIFT_EN_BKF_CLR_TXREQ)                   /*!<R/W 0x1  when gen tx command done, while will backoff is invalid, then tx command will be cleared */
#define BIT_SHIFT_EN_BCN_TX_BTCCA                    20
#define BIT_EN_BCN_TX_BTCCA                          ((u32)0x00000001 << BIT_SHIFT_EN_BCN_TX_BTCCA)                    /*!<R/W 0x0  1: Enable Beacon Tx at TBTT if BT_CCA is enabled 0: Disable */
#define BIT_SHIFT_DIS_PKT_TX_ATIM                    19
#define BIT_DIS_PKT_TX_ATIM                          ((u32)0x00000001 << BIT_SHIFT_DIS_PKT_TX_ATIM)                    /*!<R/W 0x1  1: Disable AC Queue Packet Tx in ATIM (only valid at Nettype: Adhoc/AP) 0: Enable AC Queue packet Tx in ATIM */
#define BIT_SHIFT_DIS_BCN_DIS_CTN                    18
#define BIT_DIS_BCN_DIS_CTN                          ((u32)0x00000001 << BIT_SHIFT_DIS_BCN_DIS_CTN)                    /*!<R/W 0x1  Disable the Beacon queue disable contention,when set to 0 enable the force beacon function. */
#define BIT_SHIFT_EN_NAVEND_RST_TXOP                 17
#define BIT_EN_NAVEND_RST_TXOP                       ((u32)0x00000001 << BIT_SHIFT_EN_NAVEND_RST_TXOP)                 /*!<R/W 0x0  When set this bit, TXOP will be reset while NAV end. */
#define BIT_SHIFT_EN_FILTER_CCA                      16
#define BIT_EN_FILTER_CCA                            ((u32)0x00000001 << BIT_SHIFT_EN_FILTER_CCA)                      /*!<R/W 0x0  Enable CCA filter threshold */
#define BIT_SHIFT_CCA_FILTER_THRS                    8
#define BIT_MASK_CCA_FILTER_THRS                     ((u32)0x000000FF << BIT_SHIFT_CCA_FILTER_THRS)                    /*!<R/W 0xA  If PHY_CCA signal width is bigger than this threshold, this PHY_CCA signal is valid for MAC. Unit: us */
#define BIT_SHIFT_EDCCA_THRS                         0
#define BIT_MASK_EDCCA_THRS                          ((u32)0x000000FF << BIT_SHIFT_EDCCA_THRS)                         /*!<R/W 0x8F  EDCCA threshold value, edcca over this threshold will cause bkf_rst Bit[7]: PHY_EDCCA��1�r����timer timeout�r��סTX Bit[6:0]: timer (��λ:32us) */

/* REG_P2P_NOA0_SPEC_STATE_H 0x052B */
#define BIT_SHIFT_POWER_STATE_0                      7
#define BIT_POWER_STATE_0                            ((u32)0x00000001 << BIT_SHIFT_POWER_STATE_0)                      /*!<RO   1: On, 0: Off. (It is including early time. ) */
#define BIT_SHIFT_CTWINDOW_ON_0                      6
#define BIT_CTWINDOW_ON_0                            ((u32)0x00000001 << BIT_SHIFT_CTWINDOW_ON_0)                      /*!<RO   Spec time and Beacon Early Time to TBTT Time. (It is including early time. ) */
#define BIT_SHIFT_BEACON_AREA_ON_0                   5
#define BIT_BEACON_AREA_ON_0                         ((u32)0x00000001 << BIT_SHIFT_BEACON_AREA_ON_0)                   /*!<RO   The time is from HOLD Time to BeaconTx or Timeout. (It is including early time. ) */
#define BIT_SHIFT_CTWIN_EARLY_DISTX_0                4
#define BIT_CTWIN_EARLY_DISTX_0                      ((u32)0x00000001 << BIT_SHIFT_CTWIN_EARLY_DISTX_0)                /*!<RO   ctwin_early_distx. (It is including early time. ) */
#define BIT_SHIFT_NOA1_OFF_PERIOD_0                  3
#define BIT_NOA1_OFF_PERIOD_0                        ((u32)0x00000001 << BIT_SHIFT_NOA1_OFF_PERIOD_0)                  /*!<RO   Spec time but exclude BCNDMATIM time for wake. (It is including early time. ) */
#define BIT_SHIFT_FORCE_DOZE1_0                      2
#define BIT_FORCE_DOZE1_0                            ((u32)0x00000001 << BIT_SHIFT_FORCE_DOZE1_0)                      /*!<RO   If NoA_Count == 1, this value is 1. else 0. (It is including early time. ) */
#define BIT_SHIFT_NOA0_OFF_PERIOD_0                  1
#define BIT_NOA0_OFF_PERIOD_0                        ((u32)0x00000001 << BIT_SHIFT_NOA0_OFF_PERIOD_0)                  /*!<RO   Spec time but exclude BCNDMATIM time for wake. (It is including early time. ) */
#define BIT_SHIFT_FORCE_DOZE0_0                      0
#define BIT_FORCE_DOZE0_0                            ((u32)0x00000001 << BIT_SHIFT_FORCE_DOZE0_0)                      /*!<RO   If NoA_Count == 1, this value is 1. else 0. (It is including early time. ) */

/* REG_P2PON_DIS_TXTIME 0x0530 */
#define BIT_SHIFT_P2PON_DIS_TXTIME                   8
#define BIT_MASK_P2PON_DIS_TXTIME                    ((u32)0x000000FF << BIT_SHIFT_P2PON_DIS_TXTIME)                   /*!<R/W 0x0  The time of the disable TX period after the P2P RF on interrupt occur. Unit: 64us. */

/* REG_NAN_SETTING_2 0x0534 */
#define BIT_SHIFT_SYNC_BCN_DELAY                     0
#define BIT_MASK_SYNC_BCN_DELAY                      ((u32)0x00003FFF << BIT_SHIFT_SYNC_BCN_DELAY)                     /*!<R/W 0x168  r_HC * r_SLOTTIME * 8'd40 (unit:us) default: r_HC = 1, r_SLOTTIME = 9, => 360us max is 16ms (DW) */

/* REG_QUEUE_INCOL_THR 0x0538 */
#define BIT_SHIFT_BK_QUEUE_THR                       24
#define BIT_MASK_BK_QUEUE_THR                        ((u32)0x000000FF << BIT_SHIFT_BK_QUEUE_THR)                       /*!<R/W 0x0  0: Disable this BK queue condition. Otherwise: When internal collision number of queue equal threshold, the priority of queue enhance. But have more 2 queues which satisfy each queue threshold, the priority will follow VO>VI>BE>BK. */
#define BIT_SHIFT_BE_QUEUE_THR                       16
#define BIT_MASK_BE_QUEUE_THR                        ((u32)0x000000FF << BIT_SHIFT_BE_QUEUE_THR)                       /*!<R/W 0x0  0: Disable this BE queue condition. Otherwise: When internal collision number of queue equal threshold, the priority of queue enhance. But have more 2 queues which satisfy each queue threshold, the priority will follow VO>VI>BE>BK. */
#define BIT_SHIFT_VI_QUEUE_THR                       8
#define BIT_MASK_VI_QUEUE_THR                        ((u32)0x000000FF << BIT_SHIFT_VI_QUEUE_THR)                       /*!<R/W 0x0  0: Disable this VI queue condition. Otherwise: When internal collision number of queue equal threshold, the priority of queue enhance. But have more 2 queues which satisfy each queue threshold, the priority will follow VO>VI>BE>BK. */
#define BIT_SHIFT_VO_QUEUE_THR                       0
#define BIT_MASK_VO_QUEUE_THR                        ((u32)0x000000FF << BIT_SHIFT_VO_QUEUE_THR)                       /*!<R/W 0x0  0: Disable this VO queue condition. Otherwise: When internal collision number of queue equal threshold, the priority of queue enhance. But have more 2 queues which satisfy each queue threshold, the priority will follow VO>VI>BE>BK. */

/* REG_QUEUE_INCOL_EN 0x053C */
#define BIT_SHIFT_DIS_ZGBCCA                         31
#define BIT_DIS_ZGBCCA                               ((u32)0x00000001 << BIT_SHIFT_DIS_ZGBCCA)                         /*!<R/W 0x0  Disable zigbee CCA */
#define BIT_SHIFT_TXOP_FAIL_BREAK                    21
#define BIT_TXOP_FAIL_BREAK                          ((u32)0x00000001 << BIT_SHIFT_TXOP_FAIL_BREAK)                    /*!<R/W 0x0  1: if tx pkt fail in txop, then tx cfend to end txop */
#define BIT_SHIFT_EN_TBTT_AREA_BLK_4AC               20
#define BIT_EN_TBTT_AREA_BLK_4AC                     ((u32)0x00000001 << BIT_SHIFT_EN_TBTT_AREA_BLK_4AC)               /*!<R/W 0x1  When set this bit, 4AC backoff is disabled on TBTT setup period */
#define BIT_SHIFT_ENABLE_RANDOM_SHIFT_TX             19
#define BIT_ENABLE_RANDOM_SHIFT_TX                   ((u32)0x00000001 << BIT_SHIFT_ENABLE_RANDOM_SHIFT_TX)             /*!<R/W 0x1  When this bit set 1, enable random shift TX function */
#define BIT_SHIFT_ENABLE_EDCA_REF_FUNCTION           18
#define BIT_ENABLE_EDCA_REF_FUNCTION                 ((u32)0x00000001 << BIT_SHIFT_ENABLE_EDCA_REF_FUNCTION)           /*!<R/W 0x0  When this bit set 1, enable EDCA REF function */
#define BIT_SHIFT_ENABLE_INTERCOL_EDCA_REF           17
#define BIT_ENABLE_INTERCOL_EDCA_REF                 ((u32)0x00000001 << BIT_SHIFT_ENABLE_INTERCOL_EDCA_REF)           /*!<R/W 0x0  When this bit set 1, enable inter-collision edca_ref */
#define BIT_SHIFT_ACQ_MAX_INCOL_EN                   16
#define BIT_ACQ_MAX_INCOL_EN                         ((u32)0x00000001 << BIT_SHIFT_ACQ_MAX_INCOL_EN)                   /*!<R/W 0x0  1:Enable 0 :Disable */
#define BIT_SHIFT_BK_TRIGGER_NUM                     12
#define BIT_MASK_BK_TRIGGER_NUM                      ((u32)0x0000000F << BIT_SHIFT_BK_TRIGGER_NUM)                     /*!<R/W1C 0x0  The number is triggered by bkq inter collision */
#define BIT_SHIFT_BE_TRIGGER_NUM                     8
#define BIT_MASK_BE_TRIGGER_NUM                      ((u32)0x0000000F << BIT_SHIFT_BE_TRIGGER_NUM)                     /*!<R/W1C 0x0  The number is triggered by beq inter collision */
#define BIT_SHIFT_VI_TRIGGER_NUM                     4
#define BIT_MASK_VI_TRIGGER_NUM                      ((u32)0x0000000F << BIT_SHIFT_VI_TRIGGER_NUM)                     /*!<R/W1C 0x0  The number is triggered by viq inter collision */
#define BIT_SHIFT_VO_TRIGGER_NUM                     0
#define BIT_MASK_VO_TRIGGER_NUM                      ((u32)0x0000000F << BIT_SHIFT_VO_TRIGGER_NUM)                     /*!<R/W1C 0x0  The number is triggered by voq inter collision */

/* REG_TBTT_PROHIBIT 0x0540 */
#define BIT_SHIFT_EN_TBTT_AREA_FOR_BB                20
#define BIT_EN_TBTT_AREA_FOR_BB                      ((u32)0x00000001 << BIT_SHIFT_EN_TBTT_AREA_FOR_BB)                /*!<R/W 0x0  enable notify bb that mac p0 is in tbtt area */
#define BIT_SHIFT_TBTT_HOLD_TIME                     8
#define BIT_MASK_TBTT_HOLD_TIME                      ((u32)0x00000FFF << BIT_SHIFT_TBTT_HOLD_TIME)                     /*!<R/W 0xc8  TBTT_prohibit_hold time for AP mode, unit is 32 us */
#define BIT_SHIFT_TBTT_HOLD_TIME_INFRA               4
#define BIT_MASK_TBTT_HOLD_TIME_INFRA                ((u32)0x0000000F << BIT_SHIFT_TBTT_HOLD_TIME_INFRA)               /*!<R/W 0x01  TBTT_prohibit_hold time for infrastructure mode , unit is 2 ms */
#define BIT_SHIFT_TBTT_PROHIBIT_SETUP                0
#define BIT_MASK_TBTT_PROHIBIT_SETUP                 ((u32)0x0000000F << BIT_SHIFT_TBTT_PROHIBIT_SETUP)                /*!<R/W 0x02  TBTT_prohibit_setup, unit is 32us */

/* REG_P2P_NOA0_SPEC_STATE_L 0x0543 */
#define BIT_SHIFT_SPEC_POWER_STATE_0                 7
#define BIT_SPEC_POWER_STATE_0                       ((u32)0x00000001 << BIT_SHIFT_SPEC_POWER_STATE_0)                 /*!<RO   1: On, 0: Off */
#define BIT_SHIFT_SPEC_CTWINDOW_ON_0                 6
#define BIT_SPEC_CTWINDOW_ON_0                       ((u32)0x00000001 << BIT_SHIFT_SPEC_CTWINDOW_ON_0)                 /*!<RO   The time from TBTT <-> CTWEND (with BCNDMATIM early time) */
#define BIT_SHIFT_SPEC_BEACON_AREA_ON_0              5
#define BIT_SPEC_BEACON_AREA_ON_0                    ((u32)0x00000001 << BIT_SHIFT_SPEC_BEACON_AREA_ON_0)              /*!<RO   The time is from TBTT to BeaconTx or Timeout */
#define BIT_SHIFT_SPEC_CTWIN_EARLY_DISTX_0           4
#define BIT_SPEC_CTWIN_EARLY_DISTX_0                 ((u32)0x00000001 << BIT_SHIFT_SPEC_CTWIN_EARLY_DISTX_0)           /*!<RO   ctwin_early_distx */
#define BIT_SHIFT_SPEC_NOA1_OFF_PERIOD_0             3
#define BIT_SPEC_NOA1_OFF_PERIOD_0                   ((u32)0x00000001 << BIT_SHIFT_SPEC_NOA1_OFF_PERIOD_0)             /*!<RO   Spec time */
#define BIT_SHIFT_SPEC_FORCE_DOZE1_0                 2
#define BIT_SPEC_FORCE_DOZE1_0                       ((u32)0x00000001 << BIT_SHIFT_SPEC_FORCE_DOZE1_0)                 /*!<RO   If NoA_Count == 1, this value is 1. else 0. */
#define BIT_SHIFT_SPEC_NOA0_OFF_PERIOD_0             1
#define BIT_SPEC_NOA0_OFF_PERIOD_0                   ((u32)0x00000001 << BIT_SHIFT_SPEC_NOA0_OFF_PERIOD_0)             /*!<RO   Spec time */
#define BIT_SHIFT_SPEC_FORCE_DOZE0_0                 0
#define BIT_SPEC_FORCE_DOZE0_0                       ((u32)0x00000001 << BIT_SHIFT_SPEC_FORCE_DOZE0_0)                 /*!<RO   If NoA_Count == 1, this value is 1. else 0. */

/* REG_NAV_CTRL 0x0544 */
#define BIT_SHIFT_NAV_PROT_LEN                       16
#define BIT_MASK_NAV_PROT_LEN                        ((u32)0x0000FFFF << BIT_SHIFT_NAV_PROT_LEN)                       /*!<R/W 0x40  In TXOP mode ,NAV setting which protects next packets */
#define BIT_SHIFT_RD_NAV_PROT_NXT                    0
#define BIT_MASK_RD_NAV_PROT_NXT                     ((u32)0x0000FFFF << BIT_SHIFT_RD_NAV_PROT_NXT)                    /*!<R/W 0x180  In RDG mode ,NAV setting which protects next packets */

/* REG_FTM_CTRL 0x0548 */
#define BIT_SHIFT_FTM_TSF_R2T_PORT                   24
#define BIT_FTM_TSF_R2T_PORT                         ((u32)0x00000001 << BIT_SHIFT_FTM_TSF_R2T_PORT)                   /*!<R/W 0x0  0:R2T latch count sync tsf of port 0 1: R2T latch count sync tsf of port 1 */
#define BIT_SHIFT_FTM_TSF_T2R_PORT                   20
#define BIT_FTM_TSF_T2R_PORT                         ((u32)0x00000001 << BIT_SHIFT_FTM_TSF_T2R_PORT)                   /*!<R/W 0x0  0:T2R latch count sync tsf of port 0 1: T2R latch count sync tsf of port 1 */
#define BIT_SHIFT_FTM_PTT_PORT                       16
#define BIT_FTM_PTT_PORT                             ((u32)0x00000001 << BIT_SHIFT_FTM_PTT_PORT)                       /*!<R/W 0x0  0: sync tsf of port 0 1: sync tsf of port 1 */
#define BIT_SHIFT_FTM_PTT                            0
#define BIT_MASK_FTM_PTT                             ((u32)0x0000FFFF << BIT_SHIFT_FTM_PTT)                            /*!<R/W 0x0  partial tsf timer setting */

/* REG_FTM_TSF_CNT 0x054C */
#define BIT_SHIFT_FTM_TSF_R2T                        16
#define BIT_MASK_FTM_TSF_R2T                         ((u32)0x0000FFFF << BIT_SHIFT_FTM_TSF_R2T)                        /*!<R 0x0  R2T latch count sync tsf timer */
#define BIT_SHIFT_FTM_TSF_T2R                        0
#define BIT_MASK_FTM_TSF_T2R                         ((u32)0x0000FFFF << BIT_SHIFT_FTM_TSF_T2R)                        /*!<R 0x0  T2R latch count sync tsf timer */

/* REG_BCN_CTRL_PORT0 0x0550 */
#define BIT_SHIFT_P0_RXBCN_RPT_ENABLE                7
#define BIT_P0_RXBCN_RPT_ENABLE                      ((u32)0x00000001 << BIT_SHIFT_P0_RXBCN_RPT_ENABLE)                /*!<R/W 0x0  When this bit asserted, RXBCNOK report is issued */
#define BIT_SHIFT_P0_DIS_RX_BSSID_FIT                6
#define BIT_P0_DIS_RX_BSSID_FIT                      ((u32)0x00000001 << BIT_SHIFT_P0_DIS_RX_BSSID_FIT)                /*!<R/W 0x0  0:HW will handle rx_beacon 1:HW will ignore rx_beacon_pk */
#define BIT_SHIFT_P0_TXBCN_RPT_ENABLE                5
#define BIT_P0_TXBCN_RPT_ENABLE                      ((u32)0x00000001 << BIT_SHIFT_P0_TXBCN_RPT_ENABLE)                /*!<R/W 0x0  When this bit and BIT_P0_EN_BCN_RPT are set, then TXBCN ERROR report is issued */
#define BIT_SHIFT_P0_DIS_TSF_UDT                     4
#define BIT_P0_DIS_TSF_UDT                           ((u32)0x00000001 << BIT_SHIFT_P0_DIS_TSF_UDT)                     /*!<R/W 0x1  When set, disable port 0 TSF update when beacon frames or probe response frames are received. */
#define BIT_SHIFT_P0_EN_BCN_FUNCTION                 3
#define BIT_P0_EN_BCN_FUNCTION                       ((u32)0x00000001 << BIT_SHIFT_P0_EN_BCN_FUNCTION)                 /*!<R/W 0x0  When this bit is set, TSF and other beacon related functions are then enabled. 0x610(MACID)��enable�_�P */
#define BIT_SHIFT_P0_EN_BCN_RPT                      2
#define BIT_P0_EN_BCN_RPT                            ((u32)0x00000001 << BIT_SHIFT_P0_EN_BCN_RPT)                      /*!<R/W 0x1  When this bit asserted, txbcnok_int and txbcnerr_int will valid. */
#define BIT_SHIFT_P0_EN_P2P_CTWINDOW                 1
#define BIT_P0_EN_P2P_CTWINDOW                       ((u32)0x00000001 << BIT_SHIFT_P0_EN_P2P_CTWINDOW)                 /*!<R/W 0x0  1: Enable P2P CTN WINDOWS function. 0: Disable P2P CTN WINDOWS function. */
#define BIT_SHIFT_P0_EN_P2P_BCNQ_AREA                0
#define BIT_P0_EN_P2P_BCNQ_AREA                      ((u32)0x00000001 << BIT_SHIFT_P0_EN_P2P_BCNQ_AREA)                /*!<R/W 0x0  1: Enable P2P BCN area on function. 0 : Disable P2P BCN area on function. */

/* REG_BCN_CTRL_PORT1 0x0551 */
#define BIT_SHIFT_P1_RXBCN_RPT_ENABLE                7
#define BIT_P1_RXBCN_RPT_ENABLE                      ((u32)0x00000001 << BIT_SHIFT_P1_RXBCN_RPT_ENABLE)                /*!<R/W 0x0  When this bit asserted, RXBCNOK report is issued */
#define BIT_SHIFT_P1_DIS_RX_BSSID_FIT                6
#define BIT_P1_DIS_RX_BSSID_FIT                      ((u32)0x00000001 << BIT_SHIFT_P1_DIS_RX_BSSID_FIT)                /*!<R/W 0x0  0:HW will handle rx_beacon 1:HW will ignore rx_beacon_pk */
#define BIT_SHIFT_P1_TXBCN_RPT_ENABLE                5
#define BIT_P1_TXBCN_RPT_ENABLE                      ((u32)0x00000001 << BIT_SHIFT_P1_TXBCN_RPT_ENABLE)                /*!<R/W 0x0  When this bit and BIT_P1_EN_BCN_RPT are set, then TXBCN ERROR report is issued */
#define BIT_SHIFT_P1_DIS_TSF_UDT                     4
#define BIT_P1_DIS_TSF_UDT                           ((u32)0x00000001 << BIT_SHIFT_P1_DIS_TSF_UDT)                     /*!<R/W 0x1  When set, disable clint 0 TSF update when beacon frames or probe response frames are received. */
#define BIT_SHIFT_P1_EN_BCN_FUNCTION                 3
#define BIT_P1_EN_BCN_FUNCTION                       ((u32)0x00000001 << BIT_SHIFT_P1_EN_BCN_FUNCTION)                 /*!<R/W 0x0  When this bit is set, TSF and other beacon related functions are then enabled. 0x700(MACID1)��enable�_�P */
#define BIT_SHIFT_P1_EN_BCN_RPT                      2
#define BIT_P1_EN_BCN_RPT                            ((u32)0x00000001 << BIT_SHIFT_P1_EN_BCN_RPT)                      /*!<R/W 0x1  When this bit asserted, txbcnok_int and txbcnerr_int will valid. */
#define BIT_SHIFT_P1_ENP2P_CTWINDOW                  1
#define BIT_P1_ENP2P_CTWINDOW                        ((u32)0x00000001 << BIT_SHIFT_P1_ENP2P_CTWINDOW)                  /*!<R/W 0x0  1: Enable P2P CTN WINDOWS function. 0: Disable P2P CTN WINDOWS function. */
#define BIT_SHIFT_P1_ENP2P_BCNQ_AREA                 0
#define BIT_P1_ENP2P_BCNQ_AREA                       ((u32)0x00000001 << BIT_SHIFT_P1_ENP2P_BCNQ_AREA)                 /*!<R/W 0x0  1: Enable P2P BCN area on function. 0 : Disable P2P BCN area on function. */

/* REG_MBID_NUM_P2P_RST 0x0552 */
#define BIT_SHIFT_P2P_PWR_RST5                       7
#define BIT_P2P_PWR_RST5                             ((u32)0x00000001 << BIT_SHIFT_P2P_PWR_RST5)                       /*!<W 0x0  rst p2p circuit NOA 5, noa_unit2 */
#define BIT_SHIFT_P2P_PWR_RST4                       6
#define BIT_P2P_PWR_RST4                             ((u32)0x00000001 << BIT_SHIFT_P2P_PWR_RST4)                       /*!<W 0x0  rst p2p circuit NOA 4, noa_unit2 */
#define BIT_SHIFT_P2P_PWR_RST3                       5
#define BIT_P2P_PWR_RST3                             ((u32)0x00000001 << BIT_SHIFT_P2P_PWR_RST3)                       /*!<W 0x0  rst p2p circuit NOA 3, noa_unit1 */
#define BIT_SHIFT_P2P_PWR_RST2                       4
#define BIT_P2P_PWR_RST2                             ((u32)0x00000001 << BIT_SHIFT_P2P_PWR_RST2)                       /*!<W 0x0  rst p2p circuit NOA 2, noa_unit1 */
#define BIT_SHIFT_EN_PRE_DL_BEACON                   3
#define BIT_EN_PRE_DL_BEACON                         ((u32)0x00000001 << BIT_SHIFT_EN_PRE_DL_BEACON)                   /*!<R/W 0x0  If set 1, hw will enable pre_download beacon */
#define BIT_SHIFT_MBID_BCN_NUM                       0
#define BIT_MASK_MBID_BCN_NUM                        ((u32)0x00000007 << BIT_SHIFT_MBID_BCN_NUM)                       /*!<R/W 0x0  The number of virtual interface number excluding the root number. */

/* REG_DUAL_TSF_RST 0x0553 */
#define BIT_SHIFT_P2P_PWR_RST1                       6
#define BIT_P2P_PWR_RST1                             ((u32)0x00000001 << BIT_SHIFT_P2P_PWR_RST1)                       /*!<W 0x0  rst p2p circuit NOA 1, noa_unit0 */
#define BIT_SHIFT_SCHEDULER_RST                      5
#define BIT_SCHEDULER_RST                            ((u32)0x00000001 << BIT_SHIFT_SCHEDULER_RST)                      /*!<W 0x0  Write this bit reset scheduler, ioreg_txfail */
#define BIT_SHIFT_P2P_PWR_RST0                       4
#define BIT_P2P_PWR_RST0                             ((u32)0x00000001 << BIT_SHIFT_P2P_PWR_RST0)                       /*!<W 0x0  rst p2p circuit NOA 0, noa_unit0 */
#define BIT_SHIFT_TSFTR1_SYNC_EN                     3
#define BIT_TSFTR1_SYNC_EN                           ((u32)0x00000001 << BIT_SHIFT_TSFTR1_SYNC_EN)                     /*!<W 0x0  write this bit, bcn1 will sync to bcn0 with TSFTF_SYN_OFFSET */
#define BIT_SHIFT_TSFTR_SYNC_EN                      2
#define BIT_TSFTR_SYNC_EN                            ((u32)0x00000001 << BIT_SHIFT_TSFTR_SYNC_EN)                      /*!<W 0x0  write this bit, bcn0 will sync to bcn1 with TSFTF_SYN_OFFSET */
#define BIT_SHIFT_TSFTR1_RST                         1
#define BIT_TSFTR1_RST                               ((u32)0x00000001 << BIT_SHIFT_TSFTR1_RST)                         /*!<W 0x0  write this bit , bcn1 tsft will auto reset */
#define BIT_SHIFT_TSFTR_RST                          0
#define BIT_TSFTR_RST                                ((u32)0x00000001 << BIT_SHIFT_TSFTR_RST)                          /*!<W 0x0  write this bit , bcn0 tsft will auto reset */

/* REG_PORT0_BCN_SPACE 0x0554 */
#define BIT_SHIFT_BCN_SUB_SPACE_PORT0                16
#define BIT_MASK_BCN_SUB_SPACE_PORT0                 ((u32)0x0000FFFF << BIT_SHIFT_BCN_SUB_SPACE_PORT0)                /*!<R/W 0x64  Unit is ms. The sub-beacon interval of the port 0.(valid if mbssid function is enable) */
#define BIT_SHIFT_BCN_SPACE_PORT0                    0
#define BIT_MASK_BCN_SPACE_PORT0                     ((u32)0x0000FFFF << BIT_SHIFT_BCN_SPACE_PORT0)                    /*!<R/W 0x64  Unit is ms. When MBSSID is disable, this field is the beacon interval. When MBSSID is enable, this register is the beacon space of root. */

/* REG_PORT0_BCN_ERLY_DMA_CTRL 0x0558 */
#define BIT_SHIFT_BCNDMATIM_P0                       8
#define BIT_MASK_BCNDMATIM_P0                        ((u32)0x000000FF << BIT_SHIFT_BCNDMATIM_P0)                       /*!<R/W 0x03  Indicates the time before TBTT to perform beacon queue DMA. This register is shared by the time to assert ATIM window end interrupt. Measured in units of ��TU�� before TBTT and before ATIM window end. */
#define BIT_SHIFT_DRVERLYITV_P0                      0
#define BIT_MASK_DRVERLYITV_P0                       ((u32)0x000000FF << BIT_SHIFT_DRVERLYITV_P0)                      /*!<R/W 0x05  Time to send interrupt to notify driver to change beacon content. Time unit is TU. The register also is shared by P2P-CTW and P2P-NoA (from NoA-Absent to NoA-On). It is used to wake up early at DriverEarlyTime */

/* REG_ATIMWND0 0x055A */
#define BIT_SHIFT_ATIMWND0                           0
#define BIT_MASK_ATIMWND0                            ((u32)0x0000FFFF << BIT_SHIFT_ATIMWND0)                           /*!<R/W 0x02  ATIM window width of root VAP in units of TU. */

/* REG_USTIME_TSF 0x055C */
#define BIT_SHIFT_USTIME_TSF                         0
#define BIT_MASK_USTIME_TSF                          ((u32)0x000000FF << BIT_SHIFT_USTIME_TSF)                         /*!<R/W 0x14  Set the microsecond time unit used by MAC TSF clock. default 20MHz */

/* REG_BCN_MAX_ERR 0x055D */
#define BIT_SHIFT_BCN_MAX_ERR                        0
#define BIT_MASK_BCN_MAX_ERR                         ((u32)0x000000FF << BIT_SHIFT_BCN_MAX_ERR)                        /*!<R/W 0x10  When beacon TX error counter goes over this threshold, Beacon will transmit within PIFS. */

/* REG_RXTSF_OFFSET_CCK 0x055E */
#define BIT_SHIFT_CCK_RXTSF_OFFSET                   0
#define BIT_MASK_CCK_RXTSF_OFFSET                    ((u32)0x000000FF << BIT_SHIFT_CCK_RXTSF_OFFSET)                   /*!<R/W 0x0F  The Datapath of CCK RX_tsf */

/* REG_RXTSF_OFFSET_OFDM 0x055F */
#define BIT_SHIFT_OFDM_RXTSF_OFFSET                  0
#define BIT_MASK_OFDM_RXTSF_OFFSET                   ((u32)0x000000FF << BIT_SHIFT_OFDM_RXTSF_OFFSET)                  /*!<R/W 0x0F  The Datapath of OFDM RX_tsf */

/* REG_P0_TSFTR_L 0x0560 */
#define BIT_SHIFT_P0_TSF_TIMER_L                     0
#define BIT_MASK_P0_TSF_TIMER_L                      ((u32)0xFFFFFFFF << BIT_SHIFT_P0_TSF_TIMER_L)                     /*!<R/W 0x1  low 32bits of port0's tsft */

/* REG_P0_TSFTR_H 0x0564 */
#define BIT_SHIFT_P0_TSF_TIMER_H                     0
#define BIT_MASK_P0_TSF_TIMER_H                      ((u32)0xFFFFFFFF << BIT_SHIFT_P0_TSF_TIMER_H)                     /*!<R/W 0x0  high 32bits of port0's tsft */

/* REG_P1_TSFTR_L 0x0568 */
#define BIT_SHIFT_P1_TSF_TIMER_L                     0
#define BIT_MASK_P1_TSF_TIMER_L                      ((u32)0xFFFFFFFF << BIT_SHIFT_P1_TSF_TIMER_L)                     /*!<R/W 0x1  low 32bits of port1's tsft */

/* REG_P1_TSFTR_H 0x056C */
#define BIT_SHIFT_P1_TSF_TIMER_H                     0
#define BIT_MASK_P1_TSF_TIMER_H                      ((u32)0xFFFFFFFF << BIT_SHIFT_P1_TSF_TIMER_H)                     /*!<R/W 0x1  high 32bits of port1's tsft */

/* REG_BCN_ERLY_CTW_CTRL 0x0570 */
#define BIT_SHIFT_BCNIVLCUNT_P0                      24
#define BIT_MASK_BCNIVLCUNT_P0                       ((u32)0x0000007F << BIT_SHIFT_BCNIVLCUNT_P0)                      /*!<R 0x7f  Be used in multiple BCNIVL early INT. When this counter =1, multiple BCNIVL early INT will be triggered. */
#define BIT_SHIFT_CTWND_P0                           16
#define BIT_MASK_CTWND_P0                            ((u32)0x000000FF << BIT_SHIFT_CTWND_P0)                           /*!<R/W 0x0a  CTWindow width in units of TU. PORT0 */
#define BIT_SHIFT_ATIMWND1                           0
#define BIT_MASK_ATIMWND1                            ((u32)0x0000FFFF << BIT_SHIFT_ATIMWND1)                           /*!<R/W 0x02  ATIM window width of VAP1 in units of TU. */

/* REG_BCNDROPCTRL 0x0574 */
#define BIT_SHIFT_BEACON_DROP_EN                     7
#define BIT_BEACON_DROP_EN                           ((u32)0x00000001 << BIT_SHIFT_BEACON_DROP_EN)                     /*!<R/W 0  enable beacon drop function */
#define BIT_SHIFT_BEACON_DROP_IVL                    0
#define BIT_MASK_BEACON_DROP_IVL                     ((u32)0x0000007F << BIT_SHIFT_BEACON_DROP_IVL)                    /*!<R/W 0  indicate the timeout of beacon drop */

/* REG_HGQ_TIMEOUT_PERIOD 0x0575 */
#define BIT_SHIFT_HGQ_TIMEOUT_PERIOD                 0
#define BIT_MASK_HGQ_TIMEOUT_PERIOD                  ((u32)0x000000FF << BIT_SHIFT_HGQ_TIMEOUT_PERIOD)                 /*!<R/W 0x10  When hgq empty for this period, close atim window. And this will block hgq dma for pcie, unless 0x524[12] set enable. TU: 32us */

/* REG_MISC_CTRL 0x0577 */
#define BIT_SHIFT_TSF_TIMER_0_SEL                    6
#define BIT_MASK_TSF_TIMER_0_SEL                     ((u32)0x00000003 << BIT_SHIFT_TSF_TIMER_0_SEL)                    /*!<R/W 0x0  genarete tsfime_int[0] 00: PORT0's tsft 01: PORT1's tsft 10��PORT2's tsft 11: FREERUN CUT */
#define BIT_SHIFT_TSF_TIMER_1_SEL                    4
#define BIT_MASK_TSF_TIMER_1_SEL                     ((u32)0x00000003 << BIT_SHIFT_TSF_TIMER_1_SEL)                    /*!<R/W 0x0  genarete tsfime_int[1] 00: PORT0's tsft 01: PORT1's tsft 10��PORT2's tsft 11: FREERUN CUT */
#define BIT_SHIFT_TSF_TIMER_2_SEL                    2
#define BIT_MASK_TSF_TIMER_2_SEL                     ((u32)0x00000003 << BIT_SHIFT_TSF_TIMER_2_SEL)                    /*!<R/W 0x0  genarete tsfime_int[2] 00: PORT0's tsft 01: PORT1's tsft 10��PORT2's tsft 11: FREERUN CUT */
#define BIT_SHIFT_DIS_SECONDARY_CCA                  0
#define BIT_MASK_DIS_SECONDARY_CCA                   ((u32)0x00000003 << BIT_SHIFT_DIS_SECONDARY_CCA)                  /*!<R/W 0x0  Bit 0 : 1=Disable secondary CCA 20M, 0=Enable secondary CCA 20M. Bit 1 : 1=Disable secondary CCA 40M, 0=Enable secondary CCA 40M. */

/* REG_P2_TSFTR_L 0x0578 */
#define BIT_SHIFT_P2_TSF_TIMER_L                     0
#define BIT_MASK_P2_TSF_TIMER_L                      ((u32)0xFFFFFFFF << BIT_SHIFT_P2_TSF_TIMER_L)                     /*!<R/W 0x1  low 32bits of port2's tsft */

/* REG_P2_TSFTR_H 0x057C */
#define BIT_SHIFT_P2_TSF_TIMER_H                     0
#define BIT_MASK_P2_TSF_TIMER_H                      ((u32)0xFFFFFFFF << BIT_SHIFT_P2_TSF_TIMER_H)                     /*!<R/W 0x1  high 32bits of port2's tsft */

/* REG_TSF_TIMER1 0x0580 */
#define BIT_SHIFT_TSTTIMER1                          0
#define BIT_MASK_TSTTIMER1                           ((u32)0xFFFFFFFF << BIT_SHIFT_TSTTIMER1)                          /*!<R/W 0x00  When the lower 4 bytes of TSFTR matches the content of this register, the FW tsftime_int[0] interrupt is issued. */

/* REG_TSF_TIMER2 0x0584 */
#define BIT_SHIFT_TSTTIMER2                          5
#define BIT_MASK_TSTTIMER2                           ((u32)0x07FFFFFF << BIT_SHIFT_TSTTIMER2)                          /*!<R/W 0x00  When the lower 4 bytes of TSFTR matches the content of this register, the FW tsftime_int[1] interrupt is issued. */

/* REG_TSF_TIMER3 0x0588 */
#define BIT_SHIFT_TSTTIMER3                          5
#define BIT_MASK_TSTTIMER3                           ((u32)0x07FFFFFF << BIT_SHIFT_TSTTIMER3)                          /*!<R/W 0x00  When the lower 4 bytes of TSFTR matches the content of this register, the FW tsftime_int[2] interrupt is issued. */

/* REG_BCN_IFS_TBTT_CTN 0x058C */
#define BIT_SHIFT_PRE_BCN_DMATIM                     24
#define BIT_MASK_PRE_BCN_DMATIM                      ((u32)0x000000FF << BIT_SHIFT_PRE_BCN_DMATIM)                     /*!<R/W 0x06  when 0x552[3] is set, hw will enable pre_download beacon. this register Indicates the time before TBTT to perform beacon queue DMA. */
#define BIT_SHIFT_FORCE_BCN_IFS                      16
#define BIT_MASK_FORCE_BCN_IFS                       ((u32)0x000000FF << BIT_SHIFT_FORCE_BCN_IFS)                      /*!<R/W 0x20  when 0x528 Bit18 set to 0 and TBTT contention area end,force tx beacon use this IFS */
#define BIT_SHIFT_TBTT_CTN_AREA                      0
#define BIT_MASK_TBTT_CTN_AREA                       ((u32)0x000000FF << BIT_SHIFT_TBTT_CTN_AREA)                      /*!<R/W 0x60  TBTT contention area,Time unit is 32us,for PORT 0 / 1 / 2 */

/* REG_TXOP_MIN 0x0590 */
#define BIT_SHIFT_NAV_BLK_HGQ                        15
#define BIT_NAV_BLK_HGQ                              ((u32)0x00000001 << BIT_SHIFT_NAV_BLK_HGQ)                        /*!<R/W 0x0  rxnav block HGQ */
#define BIT_SHIFT_NAV_BLK_MGQ                        14
#define BIT_NAV_BLK_MGQ                              ((u32)0x00000001 << BIT_SHIFT_NAV_BLK_MGQ)                        /*!<R/W 0x0  rxnav block MGQ */
#define BIT_SHIFT_TXOP_MIN                           0
#define BIT_MASK_TXOP_MIN                            ((u32)0x00003FFF << BIT_SHIFT_TXOP_MIN)                           /*!<R/W 0x0f  if txop counter is more than this value, than tx pkt is considered not cross tbtt */

/* REG_PRE_BKF_TIME 0x0592 */
#define BIT_SHIFT_PRE_BKF_TIME                       0
#define BIT_MASK_PRE_BKF_TIME                        ((u32)0x000000FF << BIT_SHIFT_PRE_BKF_TIME)                       /*!<R/W 0x0f  when bkf timer count down this value, sel queue and gen txcmd will start */

/* REG_CROSS_TXOP_CTRL 0x0593 */
#define BIT_SHIFT_NOPKT_END_RTSMF                    7
#define BIT_NOPKT_END_RTSMF                          ((u32)0x00000001 << BIT_SHIFT_NOPKT_END_RTSMF)                    /*!<R/W 0x1  1: enable exit rts hold mode when there is no corresponding ac pkt to tx */
#define BIT_SHIFT_PRETX_US                           3
#define BIT_MASK_PRETX_US                            ((u32)0x0000000F << BIT_SHIFT_PRETX_US)                           /*!<R/W 0x6  For wep/tkip, enable security engine earlier than mactx by this amount of time. Unit is microsecond (us) */
#define BIT_SHIFT_DTIM_BYPASS                        2
#define BIT_DTIM_BYPASS                              ((u32)0x00000001 << BIT_SHIFT_DTIM_BYPASS)                        /*!<R/W 0x0  1: dtim counter will keep 0 */
#define BIT_SHIFT_RTS_NAV_TXOP                       1
#define BIT_RTS_NAV_TXOP                             ((u32)0x00000001 << BIT_SHIFT_RTS_NAV_TXOP)                       /*!<R/W 0x0  enable RTS NAV protect all txop */
#define BIT_SHIFT_NOT_CROSS_TXOP                     0
#define BIT_NOT_CROSS_TXOP                           ((u32)0x00000001 << BIT_SHIFT_NOT_CROSS_TXOP)                     /*!<R/W 0x0  1:tx pkt cross tbtt is prohibited 0:tx pkt cross tbtt is permitted */

/* REG_FREERUN_CNT_L 0x0594 */
#define BIT_SHIFT_FREERUN_CNT_TIMER_L                0
#define BIT_MASK_FREERUN_CNT_TIMER_L                 ((u32)0xFFFFFFFF << BIT_SHIFT_FREERUN_CNT_TIMER_L)                /*!<R/W 0x1  LOW 32bits of freerun cnt */

/* REG_FREERUN_CNT_H 0x0598 */
#define BIT_SHIFT_FREERUN_CNT_TIMER_H                0
#define BIT_MASK_FREERUN_CNT_TIMER_H                 ((u32)0xFFFFFFFF << BIT_SHIFT_FREERUN_CNT_TIMER_H)                /*!<R/W 0x1  high 32bits of freerun cnt */

/* REG_BCN_ERLY_CTW_CTRL_P1_2 0x059C */
#define BIT_SHIFT_BCNIVLCUNT_P2                      24
#define BIT_MASK_BCNIVLCUNT_P2                       ((u32)0x0000007F << BIT_SHIFT_BCNIVLCUNT_P2)                      /*!<R 0x7f  Be used in multiple BCNIVL early INT. When this counter =1, multiple BCNIVL early INT will be triggered. */
#define BIT_SHIFT_CTWND_P2                           16
#define BIT_MASK_CTWND_P2                            ((u32)0x000000FF << BIT_SHIFT_CTWND_P2)                           /*!<R/W 0x0a  CTWindow width in units of TU. PORT2 */
#define BIT_SHIFT_BCNIVLCUNT_P1                      8
#define BIT_MASK_BCNIVLCUNT_P1                       ((u32)0x0000007F << BIT_SHIFT_BCNIVLCUNT_P1)                      /*!<R 0x7f  Be used in multiple BCNIVL early INT. When this counter =1, multiple BCNIVL early INT will be triggered. */
#define BIT_SHIFT_CTWND_P1                           0
#define BIT_MASK_CTWND_P1                            ((u32)0x000000FF << BIT_SHIFT_CTWND_P1)                           /*!<R/W 0x0a  CTWindow width in units of TU. PORT1 */

/* REG_ATIMWND2 0x05A0 */
#define BIT_SHIFT_ATIMWND2                           0
#define BIT_MASK_ATIMWND2                            ((u32)0x000000FF << BIT_SHIFT_ATIMWND2)                           /*!<R/W 0x02  ATIM window width of VAP2 in units of TU. */

/* REG_ATIMWND3 0x05A1 */
#define BIT_SHIFT_ATIMWND3                           0
#define BIT_MASK_ATIMWND3                            ((u32)0x000000FF << BIT_SHIFT_ATIMWND3)                           /*!<R/W 0x02  ATIM window width of VAP3 in units of TU. */

/* REG_ATIMWND4 0x05A2 */
#define BIT_SHIFT_ATIMWND4                           0
#define BIT_MASK_ATIMWND4                            ((u32)0x000000FF << BIT_SHIFT_ATIMWND4)                           /*!<R/W 0x02  ATIM window width of VAP4 in units of TU. */

/* REG_ATIMWND5 0x05A3 */
#define BIT_SHIFT_ATIMWND5                           0
#define BIT_MASK_ATIMWND5                            ((u32)0x000000FF << BIT_SHIFT_ATIMWND5)                           /*!<R/W 0x02  ATIM window width of VAP5 in units of TU. */

/* REG_ATIMWND6 0x05A4 */
#define BIT_SHIFT_ATIMWND6                           0
#define BIT_MASK_ATIMWND6                            ((u32)0x000000FF << BIT_SHIFT_ATIMWND6)                           /*!<R/W 0x02  ATIM window width of VAP6 in units of TU. */

/* REG_ATIMWND7 0x05A5 */
#define BIT_SHIFT_ATIMWND7                           0
#define BIT_MASK_ATIMWND7                            ((u32)0x000000FF << BIT_SHIFT_ATIMWND7)                           /*!<R/W 0x02  ATIM window width of VAP7 in units of TU. */

/* REG_ATIM_URGENT 0x05A6 */
#define BIT_SHIFT_ATIM_URGENT                        0
#define BIT_MASK_ATIM_URGENT                         ((u32)0x000000FF << BIT_SHIFT_ATIM_URGENT)                        /*!<R/W 0x01  Indicates the time before ATIM Window end . When BSSID[n] (n=0~7) has HIQ packet to send, HW only DMA BSSID[n]��s HIQ packet in this interval. (unit : TU) */

/* REG_HIQ_NO_LMT_EN 0x05A7 */
#define BIT_SHIFT_HIQ_NO_LMT_EN_VAP7                 7
#define BIT_HIQ_NO_LMT_EN_VAP7                       ((u32)0x00000001 << BIT_SHIFT_HIQ_NO_LMT_EN_VAP7)                 /*!<R/W 0x0  1: Packet in Hi Queue Tx immediately (No constraint for ATIM Period) 0: Disable */
#define BIT_SHIFT_HIQ_NO_LMT_EN_VAP6                 6
#define BIT_HIQ_NO_LMT_EN_VAP6                       ((u32)0x00000001 << BIT_SHIFT_HIQ_NO_LMT_EN_VAP6)                 /*!<R/W 0x0  1: Packet in Hi Queue Tx immediately (No constraint for ATIM Period) 0: Disable */
#define BIT_SHIFT_HIQ_NO_LMT_EN_VAP5                 5
#define BIT_HIQ_NO_LMT_EN_VAP5                       ((u32)0x00000001 << BIT_SHIFT_HIQ_NO_LMT_EN_VAP5)                 /*!<R/W 0x0  1: Packet in Hi Queue Tx immediately (No constraint for ATIM Period) 0: Disable */
#define BIT_SHIFT_HIQ_NO_LMT_EN_VAP4                 4
#define BIT_HIQ_NO_LMT_EN_VAP4                       ((u32)0x00000001 << BIT_SHIFT_HIQ_NO_LMT_EN_VAP4)                 /*!<R/W 0x0  1: Packet in Hi Queue Tx immediately (No constraint for ATIM Period) 0: Disable */
#define BIT_SHIFT_HIQ_NO_LMT_EN_VAP3                 3
#define BIT_HIQ_NO_LMT_EN_VAP3                       ((u32)0x00000001 << BIT_SHIFT_HIQ_NO_LMT_EN_VAP3)                 /*!<R/W 0x0  1: Packet in Hi Queue Tx immediately (No constraint for ATIM Period) 0: Disable */
#define BIT_SHIFT_HIQ_NO_LMT_EN_VAP2                 2
#define BIT_HIQ_NO_LMT_EN_VAP2                       ((u32)0x00000001 << BIT_SHIFT_HIQ_NO_LMT_EN_VAP2)                 /*!<R/W 0x0  1: Packet in Hi Queue Tx immediately (No constraint for ATIM Period) 0: Disable */
#define BIT_SHIFT_HIQ_NO_LMT_EN_VAP1                 1
#define BIT_HIQ_NO_LMT_EN_VAP1                       ((u32)0x00000001 << BIT_SHIFT_HIQ_NO_LMT_EN_VAP1)                 /*!<R/W 0x0  1: Packet in Hi Queue Tx immediately (No constraint for ATIM Period) 0: Disable */
#define BIT_SHIFT_HIQ_NO_LMT_EN_ROOT                 0
#define BIT_HIQ_NO_LMT_EN_ROOT                       ((u32)0x00000001 << BIT_SHIFT_HIQ_NO_LMT_EN_ROOT)                 /*!<R/W 0x0  1: Packet in Hi Queue Tx immediately (No constraint for ATIM Period) 0: Disable */

/* REG_DTIM_COUNT_0_3 0x05A8 */
#define BIT_SHIFT_DTIM_COUNT_VAP3                    24
#define BIT_MASK_DTIM_COUNT_VAP3                     ((u32)0x000000FF << BIT_SHIFT_DTIM_COUNT_VAP3)                    /*!<R/W 0x0   */
#define BIT_SHIFT_DTIM_COUNT_VAP2                    16
#define BIT_MASK_DTIM_COUNT_VAP2                     ((u32)0x000000FF << BIT_SHIFT_DTIM_COUNT_VAP2)                    /*!<R/W 0x0   */
#define BIT_SHIFT_DTIM_COUNT_VAP1                    8
#define BIT_MASK_DTIM_COUNT_VAP1                     ((u32)0x000000FF << BIT_SHIFT_DTIM_COUNT_VAP1)                    /*!<R/W 0x0   */
#define BIT_SHIFT_DTIM_COUNT_ROOT                    0
#define BIT_MASK_DTIM_COUNT_ROOT                     ((u32)0x000000FF << BIT_SHIFT_DTIM_COUNT_ROOT)                    /*!<R/W 0x0   */

/* REG_DTIM_COUNT_4_7 0x05AC */
#define BIT_SHIFT_DTIM_COUNT_VAP7                    24
#define BIT_MASK_DTIM_COUNT_VAP7                     ((u32)0x000000FF << BIT_SHIFT_DTIM_COUNT_VAP7)                    /*!<R/W 0x0   */
#define BIT_SHIFT_DTIM_COUNT_VAP6                    16
#define BIT_MASK_DTIM_COUNT_VAP6                     ((u32)0x000000FF << BIT_SHIFT_DTIM_COUNT_VAP6)                    /*!<R/W 0x0   */
#define BIT_SHIFT_DTIM_COUNT_VAP5                    8
#define BIT_MASK_DTIM_COUNT_VAP5                     ((u32)0x000000FF << BIT_SHIFT_DTIM_COUNT_VAP5)                    /*!<R/W 0x0   */
#define BIT_SHIFT_DTIM_COUNT_VAP4                    0
#define BIT_MASK_DTIM_COUNT_VAP4                     ((u32)0x000000FF << BIT_SHIFT_DTIM_COUNT_VAP4)                    /*!<R/W 0x0   */

/* REG_DIS_ATIM 0x05B0 */
#define BIT_SHIFT_DIS_ATIM_VAP7                      7
#define BIT_DIS_ATIM_VAP7                            ((u32)0x00000001 << BIT_SHIFT_DIS_ATIM_VAP7)                      /*!<R/W 0x0   */
#define BIT_SHIFT_DIS_ATIM_VAP6                      6
#define BIT_DIS_ATIM_VAP6                            ((u32)0x00000001 << BIT_SHIFT_DIS_ATIM_VAP6)                      /*!<R/W 0x0   */
#define BIT_SHIFT_DIS_ATIM_VAP5                      5
#define BIT_DIS_ATIM_VAP5                            ((u32)0x00000001 << BIT_SHIFT_DIS_ATIM_VAP5)                      /*!<R/W 0x0   */
#define BIT_SHIFT_DIS_ATIM_VAP4                      4
#define BIT_DIS_ATIM_VAP4                            ((u32)0x00000001 << BIT_SHIFT_DIS_ATIM_VAP4)                      /*!<R/W 0x0   */
#define BIT_SHIFT_DIS_ATIM_VAP3                      3
#define BIT_DIS_ATIM_VAP3                            ((u32)0x00000001 << BIT_SHIFT_DIS_ATIM_VAP3)                      /*!<R/W 0x0   */
#define BIT_SHIFT_DIS_ATIM_VAP2                      2
#define BIT_DIS_ATIM_VAP2                            ((u32)0x00000001 << BIT_SHIFT_DIS_ATIM_VAP2)                      /*!<R/W 0x0   */
#define BIT_SHIFT_DIS_ATIM_VAP1                      1
#define BIT_DIS_ATIM_VAP1                            ((u32)0x00000001 << BIT_SHIFT_DIS_ATIM_VAP1)                      /*!<R/W 0x0   */
#define BIT_SHIFT_DIS_ATIM_ROOT                      0
#define BIT_DIS_ATIM_ROOT                            ((u32)0x00000001 << BIT_SHIFT_DIS_ATIM_ROOT)                      /*!<R/W 0x0   */

/* REG_EARLY_128US 0x05B1 */
#define BIT_SHIFT_EARLY_128US_P1                     3
#define BIT_MASK_EARLY_128US_P1                      ((u32)0x00000007 << BIT_SHIFT_EARLY_128US_P1)                     /*!<R/W 0x0  the BCN EARLY interrupt find tune with unit 128us. The Total Early time of BCN early interrupt is the 0x558 x 1ms + EARLY_128us x 128us. For port 1 */
#define BIT_SHIFT_EARLY_128US_P0                     0
#define BIT_MASK_EARLY_128US_P0                      ((u32)0x00000007 << BIT_SHIFT_EARLY_128US_P0)                     /*!<R/W 0x2  the BCN EARLY interrupt find tune with unit 128us. The Total Early time of BCN early interrupt is the 0x558 x 1ms + EARLY_128us x 128us. */

/* REG_TBTT_HOLD_PREDICT_P1 0x05B2 */
#define BIT_SHIFT_DIS_BCN_P2                         7
#define BIT_DIS_BCN_P2                               ((u32)0x00000001 << BIT_SHIFT_DIS_BCN_P2)                         /*!<R/W 0x0  set 1 to mask the beacon early interrupt of port2 */
#define BIT_SHIFT_DIS_BCN_P1                         6
#define BIT_DIS_BCN_P1                               ((u32)0x00000001 << BIT_SHIFT_DIS_BCN_P1)                         /*!<R/W 0x0  set 1 to mask the beacon early interrupt of port1 */
#define BIT_SHIFT_DIS_BCN_P0                         5
#define BIT_DIS_BCN_P0                               ((u32)0x00000001 << BIT_SHIFT_DIS_BCN_P0)                         /*!<R/W 0x0  set 1 to mask the beacon early interrupt of port0 */
#define BIT_SHIFT_TBTT_HOLD_PREDICT_P1               0
#define BIT_MASK_TBTT_HOLD_PREDICT_P1                ((u32)0x0000001F << BIT_SHIFT_TBTT_HOLD_PREDICT_P1)               /*!<R/W 0x2  the predicted hold time after tbtt for beacon tx of port1, unit is 32us */

/* REG_MULTI_BCN_CS 0x05B3 */
#define BIT_SHIFT_TSFTR3_SYNC_EN                     7
#define BIT_TSFTR3_SYNC_EN                           ((u32)0x00000001 << BIT_SHIFT_TSFTR3_SYNC_EN)                     /*!<W 0x0  write this bit, PORT3 will sync to PORT2 with TSFTF_SYN_OFFSET */
#define BIT_SHIFT_TSFTR2_SYNC_EN                     5
#define BIT_TSFTR2_SYNC_EN                           ((u32)0x00000001 << BIT_SHIFT_TSFTR2_SYNC_EN)                     /*!<W 0x0  write this bit, PORT2 will sync to PORT3 with TSFTF_SYN_OFFSET */
#define BIT_SHIFT_TSFTR2_RST                         4
#define BIT_TSFTR2_RST                               ((u32)0x00000001 << BIT_SHIFT_TSFTR2_RST)                         /*!<W 0x0  write this bit , bcn2 tsft will auto reset */
#define BIT_SHIFT_MULTI_BCN_CS                       0
#define BIT_MASK_MULTI_BCN_CS                        ((u32)0x0000000F << BIT_SHIFT_MULTI_BCN_CS)                       /*!<RO 0x0  indicate which port is tx beacon */

/* REG_FREERUN_CNT_CTRL 0x05B4 */
#define BIT_SHIFT_EN_FREECNT                         13
#define BIT_EN_FREECNT                               ((u32)0x00000001 << BIT_SHIFT_EN_FREECNT)                         /*!<R/W 0x0  enable freerun tsft */
#define BIT_SHIFT_RESET_FREECNT_P                    12
#define BIT_RESET_FREECNT_P                          ((u32)0x00000001 << BIT_SHIFT_RESET_FREECNT_P)                    /*!<W 0x0  reset pulse of freerun tsft */

/* REG_P2POFF_DIS_TXTIME 0x05B7 */
#define BIT_SHIFT_P2POFF_DIS_TXTIME                  0
#define BIT_MASK_P2POFF_DIS_TXTIME                   ((u32)0x000000FF << BIT_SHIFT_P2POFF_DIS_TXTIME)                  /*!<R/W 0x0  The time of the disable TX period after the P2P RF off interrupt occur. Unit: 64us. */

/* REG_PTA_TRXBCN_CTRL 0x05B8 */
#define BIT_SHIFT_PTA_RXBCN_PRI_MASK                 31
#define BIT_PTA_RXBCN_PRI_MASK                       ((u32)0x00000001 << BIT_SHIFT_PTA_RXBCN_PRI_MASK)                 /*!<R/W 0x1   */
#define BIT_SHIFT_PTA_RXBCN_EN                       30
#define BIT_PTA_RXBCN_EN                             ((u32)0x00000001 << BIT_SHIFT_PTA_RXBCN_EN)                       /*!<R/W 0x1   */
#define BIT_SHIFT_PTA_RXBCN_DIR                      29
#define BIT_PTA_RXBCN_DIR                            ((u32)0x00000001 << BIT_SHIFT_PTA_RXBCN_DIR)                      /*!<R/W 0x1   */
#define BIT_SHIFT_PTA_RXBCN_DUR                      20
#define BIT_MASK_PTA_RXBCN_DUR                       ((u32)0x000001FF << BIT_SHIFT_PTA_RXBCN_DUR)                      /*!<R/W 0x60   */
#define BIT_SHIFT_PTA_RXBCN_TIME                     13
#define BIT_MASK_PTA_RXBCN_TIME                      ((u32)0x0000007F << BIT_SHIFT_PTA_RXBCN_TIME)                     /*!<R/W 0x6   */
#define BIT_SHIFT_PTA_PRETX_EN                       12
#define BIT_PTA_PRETX_EN                             ((u32)0x00000001 << BIT_SHIFT_PTA_PRETX_EN)                       /*!<R/W 0x1   */
#define BIT_SHIFT_PTA_PRETX_TIME                     0
#define BIT_MASK_PTA_PRETX_TIME                      ((u32)0x00000FFF << BIT_SHIFT_PTA_PRETX_TIME)                     /*!<R/W 0x64  WIFI TX shall wait settle time when antenna is switched from BT to WIFI, if the BT use the same RFAFE as WIFI. Unit: 1us */

/* REG_P2P_NOA1_CTRL 0x05BC */
#define BIT_SHIFT_P2P_NOA1_ALLSTASLEEP               7
#define BIT_P2P_NOA1_ALLSTASLEEP                     ((u32)0x00000001 << BIT_SHIFT_P2P_NOA1_ALLSTASLEEP)               /*!<R/W 0x0  It indicates that the state from CTWindow End to BcnEarly 1: Sleep 0: Wake */
#define BIT_SHIFT_P2P_NOA1_DISTX_EN                  6
#define BIT_P2P_NOA1_DISTX_EN                        ((u32)0x00000001 << BIT_SHIFT_P2P_NOA1_DISTX_EN)                  /*!<R/W 0x0  1: Hw will disable TX in P2P_off period 0: Do Nothing */
#define BIT_SHIFT_P2P_NOA1_PWR_MGT_EN                5
#define BIT_P2P_NOA1_PWR_MGT_EN                      ((u32)0x00000001 << BIT_SHIFT_P2P_NOA1_PWR_MGT_EN)                /*!<R/W 0x0  A main switch for P2P PowerSaving 1: Enable 0: Disable */
#define BIT_SHIFT_P2P_NOA1_EN                        3
#define BIT_MASK_P2P_NOA1_EN                         ((u32)0x00000003 << BIT_SHIFT_P2P_NOA1_EN)                        /*!<R/W 0x0  The condition that noa_unit0, [1]-NOA1, [0]-NOA0 1: Enable 0: Disable */
#define BIT_SHIFT_P2P_NOA1_UNIT_SEL                  1
#define BIT_MASK_P2P_NOA1_UNIT_SEL                   ((u32)0x00000003 << BIT_SHIFT_P2P_NOA1_UNIT_SEL)                  /*!<R/W 0x0  The selector for the source of noa unit0. 0 for port 0, 1 for port 1 */
#define BIT_SHIFT_EN_TSFBIT32_RST_NOA1               0
#define BIT_EN_TSFBIT32_RST_NOA1                     ((u32)0x00000001 << BIT_SHIFT_EN_TSFBIT32_RST_NOA1)               /*!<R/W 0x1   */

/* REG_P2P_NOA1_SPEC_STATE 0x05BE */
#define BIT_SHIFT_POWER_STATE_1                      15
#define BIT_POWER_STATE_1                            ((u32)0x00000001 << BIT_SHIFT_POWER_STATE_1)                      /*!<RO   1: On, 0: Off. (It is including early time. ) */
#define BIT_SHIFT_CTWINDOW_ON_1                      14
#define BIT_CTWINDOW_ON_1                            ((u32)0x00000001 << BIT_SHIFT_CTWINDOW_ON_1)                      /*!<RO   Spec time and Beacon Early Time to TBTT Time. (It is including early time. ) */
#define BIT_SHIFT_BEACON_AREA_ON_1                   13
#define BIT_BEACON_AREA_ON_1                         ((u32)0x00000001 << BIT_SHIFT_BEACON_AREA_ON_1)                   /*!<RO   The time is from HOLD Time to BeaconTx or Timeout. (It is including early time. ) */
#define BIT_SHIFT_CTWIN_EARLY_DISTX_1                12
#define BIT_CTWIN_EARLY_DISTX_1                      ((u32)0x00000001 << BIT_SHIFT_CTWIN_EARLY_DISTX_1)                /*!<RO   ctwin_early_distx. (It is including early time. ) */
#define BIT_SHIFT_NOA1_OFF_PERIOD_1                  11
#define BIT_NOA1_OFF_PERIOD_1                        ((u32)0x00000001 << BIT_SHIFT_NOA1_OFF_PERIOD_1)                  /*!<RO   Spec time but exclude BCNDMATIM time for wake. (It is including early time. ) */
#define BIT_SHIFT_FORCE_DOZE1_1                      10
#define BIT_FORCE_DOZE1_1                            ((u32)0x00000001 << BIT_SHIFT_FORCE_DOZE1_1)                      /*!<RO   If NoA_Count == 1, this value is 1. else 0. (It is including early time. ) */
#define BIT_SHIFT_NOA0_OFF_PERIOD_1                  9
#define BIT_NOA0_OFF_PERIOD_1                        ((u32)0x00000001 << BIT_SHIFT_NOA0_OFF_PERIOD_1)                  /*!<RO   Spec time but exclude BCNDMATIM time for wake. (It is including early time. ) */
#define BIT_SHIFT_FORCE_DOZE0_1                      8
#define BIT_FORCE_DOZE0_1                            ((u32)0x00000001 << BIT_SHIFT_FORCE_DOZE0_1)                      /*!<RO   If NoA_Count == 1, this value is 1. else 0. (It is including early time. ) */
#define BIT_SHIFT_SPEC_POWER_STATE_1                 7
#define BIT_SPEC_POWER_STATE_1                       ((u32)0x00000001 << BIT_SHIFT_SPEC_POWER_STATE_1)                 /*!<RO   1: On, 0: Off */
#define BIT_SHIFT_SPEC_CTWINDOW_ON_1                 6
#define BIT_SPEC_CTWINDOW_ON_1                       ((u32)0x00000001 << BIT_SHIFT_SPEC_CTWINDOW_ON_1)                 /*!<RO   The time from TBTT <-> CTWEND (with BCNDMATIM early time) */
#define BIT_SHIFT_SPEC_BEACON_AREA_ON_1              5
#define BIT_SPEC_BEACON_AREA_ON_1                    ((u32)0x00000001 << BIT_SHIFT_SPEC_BEACON_AREA_ON_1)              /*!<RO   The time is from TBTT to BeaconTx or Timeout */
#define BIT_SHIFT_SPEC_CTWIN_EARLY_DISTX_1           4
#define BIT_SPEC_CTWIN_EARLY_DISTX_1                 ((u32)0x00000001 << BIT_SHIFT_SPEC_CTWIN_EARLY_DISTX_1)           /*!<RO   ctwin_early_distx */
#define BIT_SHIFT_SPEC_NOA1_OFF_PERIOD_1             3
#define BIT_SPEC_NOA1_OFF_PERIOD_1                   ((u32)0x00000001 << BIT_SHIFT_SPEC_NOA1_OFF_PERIOD_1)             /*!<RO   Spec time */
#define BIT_SHIFT_SPEC_FORCE_DOZE1_1                 2
#define BIT_SPEC_FORCE_DOZE1_1                       ((u32)0x00000001 << BIT_SHIFT_SPEC_FORCE_DOZE1_1)                 /*!<RO   If NoA_Count == 1, this value is 1. else 0. */
#define BIT_SHIFT_SPEC_NOA0_OFF_PERIOD_1             1
#define BIT_SPEC_NOA0_OFF_PERIOD_1                   ((u32)0x00000001 << BIT_SHIFT_SPEC_NOA0_OFF_PERIOD_1)             /*!<RO   Spec time */
#define BIT_SHIFT_SPEC_FORCE_DOZE0_1                 0
#define BIT_SPEC_FORCE_DOZE0_1                       ((u32)0x00000001 << BIT_SHIFT_SPEC_FORCE_DOZE0_1)                 /*!<RO   If NoA_Count == 1, this value is 1. else 0. */

/* REG_ACMHWCTRL 0x05C0 */
#define BIT_SHIFT_BEQ_ACM_STATUS                     7
#define BIT_BEQ_ACM_STATUS                           ((u32)0x00000001 << BIT_SHIFT_BEQ_ACM_STATUS)                     /*!<R 0x0  This bit indicates if the used_time >= admitted_time of AC BE when HW ACM. 0: BEQ ACM Not Exceed. 1: BEQ ACM Exceed. Default: 0h */
#define BIT_SHIFT_VIQ_ACM_STATUS                     6
#define BIT_VIQ_ACM_STATUS                           ((u32)0x00000001 << BIT_SHIFT_VIQ_ACM_STATUS)                     /*!<R 0x0  This bit indicates if the used_time >= admitted_time of AC VI when HW ACM. 0: VIQ ACM Not Exceed. 1: VIQ ACM Exceed. Default: 0h */
#define BIT_SHIFT_VOQ_ACM_STATUS                     5
#define BIT_VOQ_ACM_STATUS                           ((u32)0x00000001 << BIT_SHIFT_VOQ_ACM_STATUS)                     /*!<R 0x0  This bit indicates if the used_time >= admitted_time of AC VO when HW ACM. 0: VOQ ACM Not Exceed. 1: VOQ ACM Exceed. Default: 0h */
#define BIT_SHIFT_BEQ_ACM_EN                         3
#define BIT_BEQ_ACM_EN                               ((u32)0x00000001 << BIT_SHIFT_BEQ_ACM_EN)                         /*!<R/W 0x0  Set this bit to enable ACM of BE queue. 1: Enable 0: Disable Default: 0h */
#define BIT_SHIFT_VIQ_ACM_EN                         2
#define BIT_VIQ_ACM_EN                               ((u32)0x00000001 << BIT_SHIFT_VIQ_ACM_EN)                         /*!<R/W 0x0  Set this bit to enable ACM of VI queue. 1: Enable 0: Disable Default: 0h. */
#define BIT_SHIFT_VOQ_ACM_EN                         1
#define BIT_VOQ_ACM_EN                               ((u32)0x00000001 << BIT_SHIFT_VOQ_ACM_EN)                         /*!<R/W 0x0  Set this bit to enable ACM of VO queue. 1: Enable 0: Disable Default: 0h. */
#define BIT_SHIFT_ACMHWEN                            0
#define BIT_ACMHWEN                                  ((u32)0x00000001 << BIT_SHIFT_ACMHWEN)                            /*!<R/W 0x0  Set this bit to enable hardware to take control of ACM. 1: Hardware Control 0: Software Control Default: 0h. */

/* REG_ACMRSTCTRL 0x05C1 */
#define BIT_SHIFT_BE_ACM_RESET_USED_TIME             2
#define BIT_BE_ACM_RESET_USED_TIME                   ((u32)0x00000001 << BIT_SHIFT_BE_ACM_RESET_USED_TIME)             /*!<W 0x0  When HwEn is enabled, software set this bit to inform hardware to reset used_time to 0. Read this bit is always 0. */
#define BIT_SHIFT_VI_ACM_RESET_USED_TIME             1
#define BIT_VI_ACM_RESET_USED_TIME                   ((u32)0x00000001 << BIT_SHIFT_VI_ACM_RESET_USED_TIME)             /*!<W 0x0  When HwEn is enabled, software set this bit to inform hardware to reset used_time to 0. Read this bit is always 0. */
#define BIT_SHIFT_VO_ACM_RESET_USED_TIME             0
#define BIT_VO_ACM_RESET_USED_TIME                   ((u32)0x00000001 << BIT_SHIFT_VO_ACM_RESET_USED_TIME)             /*!<W 0x0  When HwEn is enabled, software set this bit to inform hardware to reset used_time to 0. Read this bit is always 0. */

/* REG_ACMAVG 0x05C2 */
#define BIT_SHIFT_AVGPERIOD                          0
#define BIT_MASK_AVGPERIOD                           ((u32)0x0000FFFF << BIT_SHIFT_AVGPERIOD)                          /*!<R/W 0x00  In unit of 32 us. It is the value Dot11EDCAAveragingPeriod in SPEC. HW will recalculate used_time every this period. Max is 2 sec */

/* REG_VO_ADMTIME 0x05C4 */
#define BIT_SHIFT_VO_ADMITTED_TIME                   0
#define BIT_MASK_VO_ADMITTED_TIME                    ((u32)0x0000FFFF << BIT_SHIFT_VO_ADMITTED_TIME)                   /*!<R/W 0x00  Admitted_time of VO queue. In unit of 32 microsecond. Calculated and set by driver. */

/* REG_VI_ADMTIME 0x05C6 */
#define BIT_SHIFT_VI_ADMITTED_TIME                   0
#define BIT_MASK_VI_ADMITTED_TIME                    ((u32)0x0000FFFF << BIT_SHIFT_VI_ADMITTED_TIME)                   /*!<R/W 0x00  Admitted_time of VI queue. In unit of 32 microsecond. Calculated and set by driver. */

/* REG_BE_ADMTIME 0x05C8 */
#define BIT_SHIFT_DIS_NDPA_NAV_CHK                   24
#define BIT_DIS_NDPA_NAV_CHK                         ((u32)0x00000001 << BIT_SHIFT_DIS_NDPA_NAV_CHK)                   /*!<R/W 0x0  1-->tx NDPA/NDP can cross TBTT,0-->tx NDPA/NDP can't cross TBTT */
#define BIT_SHIFT_MHDR_NAV_OFFSET                    16
#define BIT_MASK_MHDR_NAV_OFFSET                     ((u32)0x000000FF << BIT_SHIFT_MHDR_NAV_OFFSET)                    /*!<R/W 0x0  NDPA NAV compensation value */
#define BIT_SHIFT_BE_ADMITTED_TIME                   0
#define BIT_MASK_BE_ADMITTED_TIME                    ((u32)0x0000FFFF << BIT_SHIFT_BE_ADMITTED_TIME)                   /*!<R/W 0x00  Admitted_time of BE queue. In unit of 32 microsecond. Calculated and set by driver. */

/* REG_EDCA_RANDOM_GEN 0x05CC */
#define BIT_SHIFT_RANDOM_GEN                         0
#define BIT_MASK_RANDOM_GEN                          ((u32)0x00FFFFFF << BIT_SHIFT_RANDOM_GEN)                         /*!<R/W 0xe21051  Random number generator polynomial */

/* REG_TXCMD_NOA_SEL 0x05CF */
#define BIT_SHIFT_NOA_SEL                            4
#define BIT_MASK_NOA_SEL                             ((u32)0x00000007 << BIT_SHIFT_NOA_SEL)                            /*!<R/W 0x0  TX NoA parameter select (noa_unit0~2,parameter0~5) 0: NoA0 , 1:NoA1, 2:NoA2, 3:NoA3, 4:NoA4, default: NoA5 To control the register setting for which NOA. (register 0x05E0[103:0]) */
#define BIT_SHIFT_TXCMD_SEG_SEL                      0
#define BIT_MASK_TXCMD_SEG_SEL                       ((u32)0x0000000F << BIT_SHIFT_TXCMD_SEG_SEL)                      /*!<R/W 0x1  [HW Debug Info]To select which one TXCMD Segment. For example, ������0x5CF[3:0]�� 0 or 6 �xȡ 0x5F8[7:0] : Tx Agg 0x5F9[7:0] : Tx Rate */

/* REG_TXPAUSE_CFG 0x05D0 */
#define BIT_SHIFT_TSF_DIFF_P1P2                      16
#define BIT_MASK_TSF_DIFF_P1P2                       ((u32)0x0000FFFF << BIT_SHIFT_TSF_DIFF_P1P2)                      /*!<R 0x0  the difference of beacon count down value between port0 and port1, unit is TU */
#define BIT_SHIFT_TXPAUSE1                           8
#define BIT_MASK_TXPAUSE1                            ((u32)0x000000FF << BIT_SHIFT_TXPAUSE1)                           /*!<R/W 0x0  same as 0x522[7:0], allow FW/DR to control pause jointly */
#define BIT_SHIFT_DRVERLYITV_P2                      0
#define BIT_MASK_DRVERLYITV_P2                       ((u32)0x000000FF << BIT_SHIFT_DRVERLYITV_P2)                      /*!<R/W 0x05  Time to send interrupt to notify driver to change beacon content. Time unit is TU. It is used to wake up early at DriverEarlyTime. For port 2 */

/* REG_NAN_SETTING 0x05D4 */
#define BIT_SHIFT_EN_MULTI_BCN                       31
#define BIT_EN_MULTI_BCN                             ((u32)0x00000001 << BIT_SHIFT_EN_MULTI_BCN)                       /*!<R/W 0x1  enable multiple beacons of port0~port2 */
#define BIT_SHIFT_ENP2P_DW_AREA                      30
#define BIT_ENP2P_DW_AREA                            ((u32)0x00000001 << BIT_SHIFT_ENP2P_DW_AREA)                      /*!<R/W 0x0  DW condition for P2P,for port2 */
#define BIT_SHIFT_TBTT_PROHIBIT_HOLD_P2              18
#define BIT_MASK_TBTT_PROHIBIT_HOLD_P2               ((u32)0x00000FFF << BIT_SHIFT_TBTT_PROHIBIT_HOLD_P2)              /*!<R/W 0x100  the predicted hold time after tbtt for beacon tx of port2, unit is 32us */
#define BIT_SHIFT_BCN_PORT_PRI                       16
#define BIT_MASK_BCN_PORT_PRI                        ((u32)0x00000003 << BIT_SHIFT_BCN_PORT_PRI)                       /*!<R/W 0x1  the priority of port0 and port2. 10: port2 has higher priority than port0; 01:port0 has higher priority than port2. 00: port0 and port2 have the same priority */
#define BIT_SHIFT_DRVERLYITV_P1                      8
#define BIT_MASK_DRVERLYITV_P1                       ((u32)0x000000FF << BIT_SHIFT_DRVERLYITV_P1)                      /*!<R/W 0x05  Time to send interrupt to notify driver to change beacon content. Time unit is TU. It is used to wake up early at DriverEarlyTime. For port1 */
#define BIT_SHIFT_P2_RXBCN_RPT_ENABLE                7
#define BIT_P2_RXBCN_RPT_ENABLE                      ((u32)0x00000001 << BIT_SHIFT_P2_RXBCN_RPT_ENABLE)                /*!<R/W 0x0  When this bit asserted, RXBCNOK report is issued */
#define BIT_SHIFT_P2_DIS_RX_BSSID_FIT                6
#define BIT_P2_DIS_RX_BSSID_FIT                      ((u32)0x00000001 << BIT_SHIFT_P2_DIS_RX_BSSID_FIT)                /*!<R/W 0x0  0:HW will handle rx_beacon 1:HW will ignore rx_beacon_pk */
#define BIT_SHIFT_P2_TXBCN_RPT_ENABLE                5
#define BIT_P2_TXBCN_RPT_ENABLE                      ((u32)0x00000001 << BIT_SHIFT_P2_TXBCN_RPT_ENABLE)                /*!<R/W 0x0  When this bit asserted, then TXBCN ERROR report is issued */
#define BIT_SHIFT_P2_DIS_TSF_UDT                     4
#define BIT_P2_DIS_TSF_UDT                           ((u32)0x00000001 << BIT_SHIFT_P2_DIS_TSF_UDT)                     /*!<R/W 0x1  When set, disable clint 2 TSF update when beacon frames or probe response frames are received. */
#define BIT_SHIFT_P2_EN_BCN_FUNCTION                 3
#define BIT_P2_EN_BCN_FUNCTION                       ((u32)0x00000001 << BIT_SHIFT_P2_EN_BCN_FUNCTION)                 /*!<R/W 0x0  When this bit is set, TSF and other beacon related functions are then enabled. */
#define BIT_SHIFT_P2_EN_BCN_RPT                      2
#define BIT_P2_EN_BCN_RPT                            ((u32)0x00000001 << BIT_SHIFT_P2_EN_BCN_RPT)                      /*!<R/W 0x1  When this bit asserted, txbcnok_int and txbcnerr_int will valid. */
#define BIT_SHIFT_P2_ENP2P_CTWINDOW                  1
#define BIT_P2_ENP2P_CTWINDOW                        ((u32)0x00000001 << BIT_SHIFT_P2_ENP2P_CTWINDOW)                  /*!<R/W 0x0  1: Enable P2P CTN WINDOWS function. 0: Disable P2P CTN WINDOWS function. */
#define BIT_SHIFT_P2_ENP2P_BCNQ_AREA                 0
#define BIT_P2_ENP2P_BCNQ_AREA                       ((u32)0x00000001 << BIT_SHIFT_P2_ENP2P_BCNQ_AREA)                 /*!<R/W 0x0  1: Enable P2P BCN area on function. 0 : Disable P2P BCN area on function. */

/* REG_BCN_SPACE_PORT1 0x05D8 */
#define BIT_SHIFT_BCN_SPACE3                         0
#define BIT_MASK_BCN_SPACE3                          ((u32)0x0000FFFF << BIT_SHIFT_BCN_SPACE3)                         /*!<R/W 0x64  sync beacon space of port1 */

/* REG_BCN_SPACE_PORT2 0x05DA */
#define BIT_SHIFT_BCN_SPACE4                         0
#define BIT_MASK_BCN_SPACE4                          ((u32)0x0000FFFF << BIT_SHIFT_BCN_SPACE4)                         /*!<R/W 0x64  sync beacon space of port2 */

/* REG_NAN_SETTING_1 0x05DC */
#define BIT_SHIFT_SYNCBCN_RXNUM                      27
#define BIT_MASK_SYNCBCN_RXNUM                       ((u32)0x0000001F << BIT_SHIFT_SYNCBCN_RXNUM)                      /*!<R/W 0x0  if DW is permitted to end early, the number of rx sync beacons is defined in this register */
#define BIT_SHIFT_DW_END_EARLY                       26
#define BIT_DW_END_EARLY                             ((u32)0x00000001 << BIT_SHIFT_DW_END_EARLY)                       /*!<R/W 0x0  when set, the DW window end earlier than spec definition. When sync bcn and SDF had tx, and rx enough sync bcns defined by 0x5DC[31:27]. DW can early end */
#define BIT_SHIFT_NAN_ROLE                           24
#define BIT_MASK_NAN_ROLE                            ((u32)0x00000003 << BIT_SHIFT_NAN_ROLE)                           /*!<R/W 0x0  the role of NAN device, including master, no-master sync, and no-master no-sync. */
#define BIT_SHIFT_MSLOT_EVTQ                         16
#define BIT_MASK_MSLOT_EVTQ                          ((u32)0x000000FF << BIT_SHIFT_MSLOT_EVTQ)                         /*!<R/W 0x0  evtq packet will tx in the m-th SLOT of the m-th DWs */
#define BIT_SHIFT_MDW_EVTQ                           8
#define BIT_MASK_MDW_EVTQ                            ((u32)0x000000FF << BIT_SHIFT_MDW_EVTQ)                           /*!<R/W 0x0  evtq packet will tx in the m-th SLOT of the m-th DWs */
#define BIT_SHIFT_EVTQ_EARLY                         5
#define BIT_MASK_EVTQ_EARLY                          ((u32)0x00000007 << BIT_SHIFT_EVTQ_EARLY)                         /*!<R/W 0x1  the early time of evtq tx window. unit is TU */

/* REG_NOA_PARAM_V1 0x05E0 */
#define BIT_SHIFT_NOA_DURATION_V1                    0
#define BIT_MASK_NOA_DURATION_V1                     ((u32)0xFFFFFFFF << BIT_SHIFT_NOA_DURATION_V1)                    /*!<R/W 0x00001000  The maximum duration in units of microseconds that the P2P Group Owner shall remain absent following the start of a Notice of Absence interval. */

/* REG_NOA_PARAM_V2 0x05E4 */
#define BIT_SHIFT_NOA_INTERVAL_V2                    0
#define BIT_MASK_NOA_INTERVAL_V2                     ((u32)0xFFFFFFFF << BIT_SHIFT_NOA_INTERVAL_V2)                    /*!<R/W 0x00003000  The length of the Notice of Absence interval in units of microseconds. */

/* REG_NOA_PARAM_V3 0x05E8 */
#define BIT_SHIFT_NOA_START_TIME_V3                  0
#define BIT_MASK_NOA_START_TIME_V3                   ((u32)0xFFFFFFFF << BIT_SHIFT_NOA_START_TIME_V3)                  /*!<R/W 0x00001000  The start time for the schedule expressed in terms of the lower 4 bytes of the TSF timer. */

/* REG_NOA_PARAM_4 0x05EC */
#define BIT_SHIFT_NOA_COUNT_V4                       0
#define BIT_MASK_NOA_COUNT_V4                        ((u32)0x000000FF << BIT_SHIFT_NOA_COUNT_V4)                       /*!<R/W 0x03  indicates the number of absence intervals */

/* REG_SCHEDULER_DBG 0x05F4 */
#define BIT_SHIFT_DBG_SCHEDULER                      0
#define BIT_MASK_DBG_SCHEDULER                       ((u32)0xFFFFFFFF << BIT_SHIFT_DBG_SCHEDULER)                      /*!<R 0x0   */

/* REG_SCH_TXCMD 0x05F8 */
#define BIT_SHIFT_SCH_TXCMD                          0
#define BIT_MASK_SCH_TXCMD                           ((u32)0xFFFFFFFF << BIT_SHIFT_SCH_TXCMD)                          /*!<R 0x0  Scheduler TXCMD Content */

/* REG_PAGE5_DUMMY 0x05FC */
#define BIT_SHIFT_DUMMY                              0
#define BIT_MASK_DUMMY                               ((u32)0xFFFFFFFF << BIT_SHIFT_DUMMY)                              /*!<R/W 0xffff0000  Dummy */

/* REG_PS_TIMER_A_L 0x1500 */
#define BIT_SHIFT_PS_TIMER_A_L                       0
#define BIT_MASK_PS_TIMER_A_L                        ((u32)0xFFFFFFFF << BIT_SHIFT_PS_TIMER_A_L)                       /*!<R/W 0x0  When the TSF (that select by reg 0x1520 [25��24]) matches the content of this register, the PS_TIMER_A_INT interrupt is issued */

/* REG_PS_TIMER_A_H 0x1504 */
#define BIT_SHIFT_PS_TIMER_A_H                       0
#define BIT_MASK_PS_TIMER_A_H                        ((u32)0xFFFFFFFF << BIT_SHIFT_PS_TIMER_A_H)                       /*!<R/W 0x0  When the TSF (that select by reg 0x1520 [25��24]) matches the content of this register, the PS_TIMER_A_INT interrupt is issued */

/* REG_PS_TIMER_B_L 0x1508 */
#define BIT_SHIFT_PS_TIMER_B_L                       0
#define BIT_MASK_PS_TIMER_B_L                        ((u32)0xFFFFFFFF << BIT_SHIFT_PS_TIMER_B_L)                       /*!<R/W 0x0  When the TSF (that select by reg 0x1520 [29:28]) matches the content of this register, the PS_TIMER_B_INT interrupt is issued */

/* REG_PS_TIMER_B_H 0x150C */
#define BIT_SHIFT_PS_TIMER_B_H                       0
#define BIT_MASK_PS_TIMER_B_H                        ((u32)0xFFFFFFFF << BIT_SHIFT_PS_TIMER_B_H)                       /*!<R/W 0x0  When the TSF(that select by reg 0x1520 [29:28]) matches the content of this register, the PS_TIMER_B_INT interrupt is issued */

/* REG_PS_TIMER_C_L 0x1510 */
#define BIT_SHIFT_PS_TIMER_C_L                       0
#define BIT_MASK_PS_TIMER_C_L                        ((u32)0xFFFFFFFF << BIT_SHIFT_PS_TIMER_C_L)                       /*!<R/W 0x0  When the TSF(that select by reg 0x1520 [21:20]) matches the content of this register, the PS_TIMER_C_INT interrupt is issued */

/* REG_PS_TIMER_C_H 0x1514 */
#define BIT_SHIFT_PS_TIMER_C_H                       0
#define BIT_MASK_PS_TIMER_C_H                        ((u32)0xFFFFFFFF << BIT_SHIFT_PS_TIMER_C_H)                       /*!<R/W 0x0  When the TSF(that select by reg 0x1520 [21:20]) matches the content of this register, the PS_TIMER_C_INT interrupt is issued */

/* REG_CPUMGQ_PARAMETER 0x1518 */
#define BIT_SHIFT_CW                                 8
#define BIT_MASK_CW                                  ((u32)0x000000FF << BIT_SHIFT_CW)                                 /*!<R/W 0x32  ECWmin and ECWmax encode the values of Cwmin and Cwmax respectively in an exponent form. Ex: Cwmax = 2^(ECWmax)-1 Default: BK = Ah/5h; BE = Ah/5h; VI = 5h/4h; VO = 4h/3h. */
#define BIT_SHIFT_AIFS                               0
#define BIT_MASK_AIFS                                ((u32)0x000000FF << BIT_SHIFT_AIFS)                               /*!<R/W 0x24  Arbitrary Inter frame space In unit of microsecond. AIFS indicates the time a non-AP QSTA should defer before either invoking a backoff or starting a transmission Default: BK = 49h; BE = 25h; VI = 1Ch; VO = 1Ch */

/* REG_PS_TIMER_EARLY 0x151C */
#define BIT_SHIFT_PS_TIMER_C_EARLY                   16
#define BIT_MASK_PS_TIMER_C_EARLY                    ((u32)0x000000FF << BIT_SHIFT_PS_TIMER_C_EARLY)                   /*!<R/W 0x0  It is used to wake up early at PS_Timer_C_Early Time. Time unit is TU. */
#define BIT_SHIFT_PS_TIMER_B_EARLY                   8
#define BIT_MASK_PS_TIMER_B_EARLY                    ((u32)0x000000FF << BIT_SHIFT_PS_TIMER_B_EARLY)                   /*!<R/W 0x0  It is used to wake up early at PS_Timer_B_Early Time. Time unit is TU. */
#define BIT_SHIFT_PS_TIMER_A_EARLY                   0
#define BIT_MASK_PS_TIMER_A_EARLY                    ((u32)0x000000FF << BIT_SHIFT_PS_TIMER_A_EARLY)                   /*!<R/W 0x0  It is used to wake up early at PS_Timer_A_Early Time. Time unit is TU. */

/* REG_PS_TIMER_TWT_CRTL 0x1520 */
#define BIT_SHIFT_PS_TIMER_B_EN                      31
#define BIT_PS_TIMER_B_EN                            ((u32)0x00000001 << BIT_SHIFT_PS_TIMER_B_EN)                      /*!<R/W 0x0  Enable PS_TIMER_B */
#define BIT_SHIFT_PS_TIMER_B_TSF_SEL                 28
#define BIT_MASK_PS_TIMER_B_TSF_SEL                  ((u32)0x00000003 << BIT_SHIFT_PS_TIMER_B_TSF_SEL)                 /*!<R/W 0x2  0 for port 0, 1 for port1, 2 for port2, 3 for freerun */
#define BIT_SHIFT_PS_TIMER_A_EN                      27
#define BIT_PS_TIMER_A_EN                            ((u32)0x00000001 << BIT_SHIFT_PS_TIMER_A_EN)                      /*!<R/W 0x0  Enable PS_TIMER_A */
#define BIT_SHIFT_PS_TIMER_A_TSF_SEL                 24
#define BIT_MASK_PS_TIMER_A_TSF_SEL                  ((u32)0x00000003 << BIT_SHIFT_PS_TIMER_A_TSF_SEL)                 /*!<R/W 0x2  0 for port 0, 1 for port1, 2 for port2, 3 for freerun */
#define BIT_SHIFT_PS_TIMER_C_EN                      23
#define BIT_PS_TIMER_C_EN                            ((u32)0x00000001 << BIT_SHIFT_PS_TIMER_C_EN)                      /*!<R/W 0x0  Enable PS_TIMER_C */
#define BIT_SHIFT_PS_TIMER_C_TSF_SEL                 20
#define BIT_MASK_PS_TIMER_C_TSF_SEL                  ((u32)0x00000003 << BIT_SHIFT_PS_TIMER_C_TSF_SEL)                 /*!<R/W 0x2  0 for port 0, 1 for port1, 2 for port2, 3 for freerun */
#define BIT_SHIFT_GET_TSFT_OFFSET_EN                 1
#define BIT_GET_TSFT_OFFSET_EN                       ((u32)0x00000001 << BIT_SHIFT_GET_TSFT_OFFSET_EN)                 /*!<R/W 0x0  1: Enable Enable get TSFT offset function */
#define BIT_SHIFT_RXBCN_TIME_PORT                    0
#define BIT_RXBCN_TIME_PORT                          ((u32)0x00000001 << BIT_SHIFT_RXBCN_TIME_PORT)                    /*!<R/W 0x0  report the difference between rx beacon and TSFT, show in REG 0x1524 0: port0 1: port1 default is port0. */

/* REG_RX_TSFT_DIFF 0x1524 */
#define BIT_SHIFT_RXBCN_TIME_VLD                     31
#define BIT_RXBCN_TIME_VLD                           ((u32)0x00000001 << BIT_SHIFT_RXBCN_TIME_VLD)                     /*!<R/W1C   1: indicate [30:0] is valid. Write 1 to clear this bit */
#define BIT_SHIFT_RXBCN_TIME_DIFF                    0
#define BIT_MASK_RXBCN_TIME_DIFF                     ((u32)0x7FFFFFFF << BIT_SHIFT_RXBCN_TIME_DIFF)                    /*!<R   unit:1us wmac_rx_tsf - TSFT (selected by 0x1520[0]). [30] is the sign bit */

/* REG_SCHEDULER_COUNTER 0x1528 */
#define BIT_SHIFT_SCHEDULER_COUNTER                  16
#define BIT_MASK_SCHEDULER_COUNTER                   ((u32)0x0000FFFF << BIT_SHIFT_SCHEDULER_COUNTER)                  /*!<R 0x0  The reported counter value corresponding to Report type selected. */
#define BIT_SHIFT_SCHEDULER_COUNTER_RST              8
#define BIT_SCHEDULER_COUNTER_RST                    ((u32)0x00000001 << BIT_SHIFT_SCHEDULER_COUNTER_RST)              /*!<R/W 0x0  write "1" to set the count to zero */
#define BIT_SHIFT_SCHEDULER_COUNTER_SEL              0
#define BIT_MASK_SCHEDULER_COUNTER_SEL               ((u32)0x000000FF << BIT_SHIFT_SCHEDULER_COUNTER_SEL)              /*!<R/W 0x0  0: No count 1: If backoff finished but CCA still assert, this counter plus one. */

/* REG_P2P_NOA2_CTRL 0x152C */
#define BIT_SHIFT_P2P_NOA2_ALLSTASLEEP               7
#define BIT_P2P_NOA2_ALLSTASLEEP                     ((u32)0x00000001 << BIT_SHIFT_P2P_NOA2_ALLSTASLEEP)               /*!<R/W 0x0  It indicates that the state from CTWindow End to BcnEarly 1: Sleep 0: Wake */
#define BIT_SHIFT_P2P_NOA2_DISTX_EN                  6
#define BIT_P2P_NOA2_DISTX_EN                        ((u32)0x00000001 << BIT_SHIFT_P2P_NOA2_DISTX_EN)                  /*!<R/W 0x0  1: Hw will disable TX in P2P_off period 0: Do Nothing */
#define BIT_SHIFT_P2P_NOA2_PWR_MGT_EN                5
#define BIT_P2P_NOA2_PWR_MGT_EN                      ((u32)0x00000001 << BIT_SHIFT_P2P_NOA2_PWR_MGT_EN)                /*!<R/W 0x0  A main switch for P2P PowerSaving 1: Enable 0: Disable */
#define BIT_SHIFT_P2P_NOA2_EN                        3
#define BIT_MASK_P2P_NOA2_EN                         ((u32)0x00000003 << BIT_SHIFT_P2P_NOA2_EN)                        /*!<R/W 0x0  The condition that noa_unit0, [1]-NOA1, [0]-NOA0 1: Enable 0: Disable */
#define BIT_SHIFT_P2P_NOA2_UNIT_SEL                  1
#define BIT_MASK_P2P_NOA2_UNIT_SEL                   ((u32)0x00000003 << BIT_SHIFT_P2P_NOA2_UNIT_SEL)                  /*!<R/W 0x0  The selector for the source of noa unit0. 0 for port 0, 1 for port 1, 2 for port 2 */
#define BIT_SHIFT_EN_TSFBIT32_RST_NOA2               0
#define BIT_EN_TSFBIT32_RST_NOA2                     ((u32)0x00000001 << BIT_SHIFT_EN_TSFBIT32_RST_NOA2)               /*!<R/W 0x1   */

/* REG_P2P_NOA2_SPEC_STATE 0x152E */
#define BIT_SHIFT_POWER_STATE_2                      15
#define BIT_POWER_STATE_2                            ((u32)0x00000001 << BIT_SHIFT_POWER_STATE_2)                      /*!<RO   1: On, 0: Off. (It is including early time. ) */
#define BIT_SHIFT_CTWINDOW_ON_2                      14
#define BIT_CTWINDOW_ON_2                            ((u32)0x00000001 << BIT_SHIFT_CTWINDOW_ON_2)                      /*!<RO   Spec time and Beacon Early Time to TBTT Time. (It is including early time. ) */
#define BIT_SHIFT_BEACON_AREA_ON_2                   13
#define BIT_BEACON_AREA_ON_2                         ((u32)0x00000001 << BIT_SHIFT_BEACON_AREA_ON_2)                   /*!<RO   The time is from HOLD Time to BeaconTx or Timeout. (It is including early time. ) */
#define BIT_SHIFT_CTWIN_EARLY_DISTX_2                12
#define BIT_CTWIN_EARLY_DISTX_2                      ((u32)0x00000001 << BIT_SHIFT_CTWIN_EARLY_DISTX_2)                /*!<RO   ctwin_early_distx. (It is including early time. ) */
#define BIT_SHIFT_NOA1_OFF_PERIOD_2                  11
#define BIT_NOA1_OFF_PERIOD_2                        ((u32)0x00000001 << BIT_SHIFT_NOA1_OFF_PERIOD_2)                  /*!<RO   Spec time but exclude BCNDMATIM time for wake. (It is including early time. ) */
#define BIT_SHIFT_FORCE_DOZE1_2                      10
#define BIT_FORCE_DOZE1_2                            ((u32)0x00000001 << BIT_SHIFT_FORCE_DOZE1_2)                      /*!<RO   If NoA_Count == 1, this value is 1. else 0. (It is including early time. ) */
#define BIT_SHIFT_NOA0_OFF_PERIOD_2                  9
#define BIT_NOA0_OFF_PERIOD_2                        ((u32)0x00000001 << BIT_SHIFT_NOA0_OFF_PERIOD_2)                  /*!<RO   Spec time but exclude BCNDMATIM time for wake. (It is including early time. ) */
#define BIT_SHIFT_FORCE_DOZE0_2                      8
#define BIT_FORCE_DOZE0_2                            ((u32)0x00000001 << BIT_SHIFT_FORCE_DOZE0_2)                      /*!<RO   If NoA_Count == 1, this value is 1. else 0. (It is including early time. ) */
#define BIT_SHIFT_SPEC_POWER_STATE_2                 7
#define BIT_SPEC_POWER_STATE_2                       ((u32)0x00000001 << BIT_SHIFT_SPEC_POWER_STATE_2)                 /*!<RO   1: On, 0: Off */
#define BIT_SHIFT_SPEC_CTWINDOW_ON_2                 6
#define BIT_SPEC_CTWINDOW_ON_2                       ((u32)0x00000001 << BIT_SHIFT_SPEC_CTWINDOW_ON_2)                 /*!<RO   The time from TBTT <-> CTWEND (with BCNDMATIM early time) */
#define BIT_SHIFT_SPEC_BEACON_AREA_ON_2              5
#define BIT_SPEC_BEACON_AREA_ON_2                    ((u32)0x00000001 << BIT_SHIFT_SPEC_BEACON_AREA_ON_2)              /*!<RO   The time is from TBTT to BeaconTx or Timeout */
#define BIT_SHIFT_SPEC_CTWIN_EARLY_DISTX_2           4
#define BIT_SPEC_CTWIN_EARLY_DISTX_2                 ((u32)0x00000001 << BIT_SHIFT_SPEC_CTWIN_EARLY_DISTX_2)           /*!<RO   ctwin_early_distx */
#define BIT_SHIFT_SPEC_NOA1_OFF_PERIOD_2             3
#define BIT_SPEC_NOA1_OFF_PERIOD_2                   ((u32)0x00000001 << BIT_SHIFT_SPEC_NOA1_OFF_PERIOD_2)             /*!<RO   Spec time */
#define BIT_SHIFT_SPEC_FORCE_DOZE1_2                 2
#define BIT_SPEC_FORCE_DOZE1_2                       ((u32)0x00000001 << BIT_SHIFT_SPEC_FORCE_DOZE1_2)                 /*!<RO   If NoA_Count == 1, this value is 1. else 0. */
#define BIT_SHIFT_SPEC_NOA0_OFF_PERIOD_2             1
#define BIT_SPEC_NOA0_OFF_PERIOD_2                   ((u32)0x00000001 << BIT_SHIFT_SPEC_NOA0_OFF_PERIOD_2)             /*!<RO   Spec time */
#define BIT_SHIFT_SPEC_FORCE_DOZE0_2                 0
#define BIT_SPEC_FORCE_DOZE0_2                       ((u32)0x00000001 << BIT_SHIFT_SPEC_FORCE_DOZE0_2)                 /*!<RO   If NoA_Count == 1, this value is 1. else 0. */

/* REG_TM_CFG 0x1530 */
#define BIT_SHIFT_TM_TSFT_PORT_SEL                   3
#define BIT_MASK_TM_TSFT_PORT_SEL                    ((u32)0x00000003 << BIT_SHIFT_TM_TSFT_PORT_SEL)                   /*!<R/W 0x0  selected TM timer port 0: port0; 1: port1; 2: port2; 3: freerun */
#define BIT_SHIFT_RXTM_EN                            2
#define BIT_RXTM_EN                                  ((u32)0x00000001 << BIT_SHIFT_RXTM_EN)                            /*!<R/W 0x0  1: HW will parsing rx packet, to find TM frame */
#define BIT_SHIFT_RXTMREQ_EN                         1
#define BIT_RXTMREQ_EN                               ((u32)0x00000001 << BIT_SHIFT_RXTMREQ_EN)                         /*!<R/W 0x0  1: HW will parsing rx packet, to find TM request frame */
#define BIT_SHIFT_TM_FUNC_EN                         0
#define BIT_TM_FUNC_EN                               ((u32)0x00000001 << BIT_SHIFT_TM_FUNC_EN)                         /*!<R/W 0x0  1: Enable Timing Measurement function */

/* REG_TM_TSFT_T1 0x1534 */
#define BIT_SHIFT_TM_TSFT_T1                         0
#define BIT_MASK_TM_TSFT_T1                          ((u32)0xFFFFFFFF << BIT_SHIFT_TM_TSFT_T1)                         /*!<RO 0x0  Latch tsft timer of Tx TM frame, unit: 1us */

/* REG_TM_TSFT_T2 0x1538 */
#define BIT_SHIFT_TM_TSFT_T2                         0
#define BIT_MASK_TM_TSFT_T2                          ((u32)0xFFFFFFFF << BIT_SHIFT_TM_TSFT_T2)                         /*!<RO 0x0  Latch tsft timer of Rx TM frame, unit: 1us */

/* REG_TM_TSFT_T3 0x153C */
#define BIT_SHIFT_TM_TSFT_T3                         0
#define BIT_MASK_TM_TSFT_T3                          ((u32)0xFFFFFFFF << BIT_SHIFT_TM_TSFT_T3)                         /*!<RO 0x0  Latch tsft timer of Tx ACK frame, unit: 1us */

/* REG_TM_TSFT_T4 0x1540 */
#define BIT_SHIFT_TM_TSFT_T4                         0
#define BIT_MASK_TM_TSFT_T4                          ((u32)0xFFFFFFFF << BIT_SHIFT_TM_TSFT_T4)                         /*!<RO 0x0  Latch tsft timer of Rx ACK frame, unit: 1us */

/* REG_TM_TIMER_OFFSET 0x1544 */
#define BIT_SHIFT_TM_TX_PATH_TIME_OFFSET             16
#define BIT_MASK_TM_TX_PATH_TIME_OFFSET              ((u32)0x0000FFFF << BIT_SHIFT_TM_TX_PATH_TIME_OFFSET)             /*!<R/W 0x0  Compensate the time, from PHYTXON rising edge to transmit antenna connector. unit: 1us */
#define BIT_SHIFT_TM_RX_PATH_TIME_OFFSET             0
#define BIT_MASK_TM_RX_PATH_TIME_OFFSET              ((u32)0x0000FFFF << BIT_SHIFT_TM_RX_PATH_TIME_OFFSET)             /*!<R/W 0x0  Compensate the time, from receive antenna connector to DATAON rising edge. unit: 1us */

/* REG_BCN_ELY_ADJ 0x1548 */
#define BIT_SHIFT_BCN_ELY_ADJ                        0
#define BIT_MASK_BCN_ELY_ADJ                         ((u32)0x0000FFFF << BIT_SHIFT_BCN_ELY_ADJ)                        /*!<R/W 0  beacon early time adjust, unit is 32us */

/* REG_WMAC_CR 0x0600 */
#define BIT_SHIFT_APSDOFF                            6
#define BIT_APSDOFF                                  ((u32)0x00000001 << BIT_SHIFT_APSDOFF)                            /*!<R/W 0  1��MAC issue sleep signal to disable BB/AFE/RF TRX function. After MAC has finished, APSDOFF_STATUS will report��1��. 0��MAC issue wakeup signal to recall BB/AFE/RF back to RX idle mode. After MAC has finished,APSDOFF _STATUS will report ��0��. */
#define BIT_SHIFT_IC_MACPHY_M                        0
#define BIT_IC_MACPHY_M                              ((u32)0x00000001 << BIT_SHIFT_IC_MACPHY_M)                        /*!<R/W 0  To make ASIC become BB+RF only, and put out the MAC_PHY interface */

/* REG_WMAC_BWOPMODE 0x0603 */
#define BIT_SHIFT_WMAC_20MHZBW                       2
#define BIT_WMAC_20MHZBW                             ((u32)0x00000001 << BIT_SHIFT_WMAC_20MHZBW)                       /*!<R/W 1   */
#define BIT_SHIFT_WMAC_M11J                          0
#define BIT_WMAC_M11J                                ((u32)0x00000001 << BIT_SHIFT_WMAC_M11J)                          /*!<R/W 0   */

/* REG_TCR 0x0604 */
#define BIT_SHIFT_WMAC_EN_RTS_ADDR                   31
#define BIT_WMAC_EN_RTS_ADDR                         ((u32)0x00000001 << BIT_SHIFT_WMAC_EN_RTS_ADDR)                   /*!<R/W 0  when set to 1, enable change RTS multicast address */
#define BIT_SHIFT_WMAC_DISABLE_CCK                   30
#define BIT_WMAC_DISABLE_CCK                         ((u32)0x00000001 << BIT_SHIFT_WMAC_DISABLE_CCK)                   /*!<R/W 0  when set to 1, disable cck rate packet */
#define BIT_SHIFT_WMAC_RAW_LEN                       29
#define BIT_WMAC_RAW_LEN                             ((u32)0x00000001 << BIT_SHIFT_WMAC_RAW_LEN)                       /*!<R/W 0  1: use raw ppdu_len 0: use 4byte alignment ppdu_len */
#define BIT_SHIFT_WMAC_NOTX_IN_RXNDP                 28
#define BIT_WMAC_NOTX_IN_RXNDP                       ((u32)0x00000001 << BIT_SHIFT_WMAC_NOTX_IN_RXNDP)                 /*!<R/W 0  1: block original tx when receiving NDP packet */
#define BIT_SHIFT_WMAC_EN_EOF                        27
#define BIT_WMAC_EN_EOF                              ((u32)0x00000001 << BIT_SHIFT_WMAC_EN_EOF)                        /*!<R/W 0  when set to 1, enable single ampdu for qos packet. In early mode,not set to 1. */
#define BIT_SHIFT_WMAC_BF_SEL                        26
#define BIT_WMAC_BF_SEL                              ((u32)0x00000001 << BIT_SHIFT_WMAC_BF_SEL)                        /*!<R/W 0  1: set ndp_rx_standby when rx ppdu of ndpa end; 0: set ndp_rx_standby when rx ndpa packet fcs end; */
#define BIT_SHIFT_WMAC_ANTMODE_SEL                   25
#define BIT_WMAC_ANTMODE_SEL                         ((u32)0x00000001 << BIT_SHIFT_WMAC_ANTMODE_SEL)                   /*!<R/W 1  0:4x1 mode, 1:8x1 mode */
#define BIT_SHIFT_WMAC_TCRPWRMGT_HWCTL               24
#define BIT_WMAC_TCRPWRMGT_HWCTL                     ((u32)0x00000001 << BIT_SHIFT_WMAC_TCRPWRMGT_HWCTL)               /*!<R/W 1  If this bit is set to 1, MAC will overwrite power bit of frame control according to PWR_ST. (only for RTS/CTS/ACK/CFEND/BA/BAR frames) */
#define BIT_SHIFT_WMAC_SMOOTH_VAL                    23
#define BIT_WMAC_SMOOTH_VAL                          ((u32)0x00000001 << BIT_SHIFT_WMAC_SMOOTH_VAL)                    /*!<R/W 0  smooth value of plcp header HTSIG2 */
#define BIT_SHIFT_WMAC_EN_SCRAM_INC                  22
#define BIT_WMAC_EN_SCRAM_INC                        ((u32)0x00000001 << BIT_SHIFT_WMAC_EN_SCRAM_INC)                  /*!<R/W 0  Increase 1 in service field scrambler seed per tx end */
#define BIT_SHIFT_UNDERFLOWEN_CMPLEN_SEL             21
#define BIT_UNDERFLOWEN_CMPLEN_SEL                   ((u32)0x00000001 << BIT_SHIFT_UNDERFLOWEN_CMPLEN_SEL)             /*!<R/W 0  compare length selector for enable condition of underflow, consider plcp header when set 1 */
#define BIT_SHIFT_FETCH_MPDU_AFTER_WSECRDY           20
#define BIT_FETCH_MPDU_AFTER_WSECRDY                 ((u32)0x00000001 << BIT_SHIFT_FETCH_MPDU_AFTER_WSECRDY)           /*!<R/W 1  If set to 1,mactx_mpdu_gen will fetch mpdu after wsec is ready when sectype is not tkip/wep40/wep104 */
#define BIT_SHIFT_WMAC_TCR_EN_20MST                  19
#define BIT_WMAC_TCR_EN_20MST                        ((u32)0x00000001 << BIT_SHIFT_WMAC_TCR_EN_20MST)                  /*!<R/W 0  when set to 1, enable ndpa signaling TA when BW =20MHz */
#define BIT_SHIFT_WMAC_DIS_SIGTA                     18
#define BIT_WMAC_DIS_SIGTA                           ((u32)0x00000001 << BIT_SHIFT_WMAC_DIS_SIGTA)                     /*!<R/W 0  when set to 1, disable signaling TA information for response packet */
#define BIT_SHIFT_WMAC_DIS_A2B0                      17
#define BIT_WMAC_DIS_A2B0                            ((u32)0x00000001 << BIT_SHIFT_WMAC_DIS_A2B0)                      /*!<R/W 0  when set to 1, not check bit 0 of rx a2 */
#define BIT_SHIFT_WMAC_MSK_SIGBCRC                   16
#define BIT_WMAC_MSK_SIGBCRC                         ((u32)0x00000001 << BIT_SHIFT_WMAC_MSK_SIGBCRC)                   /*!<R/W 0  when set to 1, mask sigb crc in service field for vht packet */
#define BIT_SHIFT_WMAC_TCR_ERRSTEN_3                 15
#define BIT_WMAC_TCR_ERRSTEN_3                       ((u32)0x00000001 << BIT_SHIFT_WMAC_TCR_ERRSTEN_3)                 /*!<R/W 0  Use phytxend_ps to reset mactx state machine */
#define BIT_SHIFT_WMAC_TCR_ERRSTEN_2                 14
#define BIT_WMAC_TCR_ERRSTEN_2                       ((u32)0x00000001 << BIT_SHIFT_WMAC_TCR_ERRSTEN_2)                 /*!<R/W 0  If txd fifo underflow when txtype is cmpba, reset mactx state machine */
#define BIT_SHIFT_WMAC_TCR_ERRSTEN_1                 13
#define BIT_WMAC_TCR_ERRSTEN_1                       ((u32)0x00000001 << BIT_SHIFT_WMAC_TCR_ERRSTEN_1)                 /*!<R/W 0  If txd fifo underflow, reset mactx state machine */
#define BIT_SHIFT_WMAC_TCR_ERRSTEN_0                 12
#define BIT_WMAC_TCR_ERRSTEN_0                       ((u32)0x00000001 << BIT_SHIFT_WMAC_TCR_ERRSTEN_0)                 /*!<R/W 0  Phytxend_ps comes but mactx still active, reset mactx state machine */
#define BIT_SHIFT_WMAC_TCR_TXSK_PERPKT               11
#define BIT_WMAC_TCR_TXSK_PERPKT                     ((u32)0x00000001 << BIT_SHIFT_WMAC_TCR_TXSK_PERPKT)               /*!<R/W 0  Search key for each mpdu */
#define BIT_SHIFT_WMAC_TCR_ICV                       10
#define BIT_WMAC_TCR_ICV                             ((u32)0x00000001 << BIT_SHIFT_WMAC_TCR_ICV)                       /*!<R/W 0  Integrity Check Value. This bit indicates the existence of an ICV appended to an encipherment packet. 1: No ICV appended 0: ICV appended */
#define BIT_SHIFT_WMAC_CFENDFOR                      9
#define BIT_WMAC_CFENDFOR                            ((u32)0x00000001 << BIT_SHIFT_WMAC_CFENDFOR)                      /*!<R/W 0  CF-End Frame Format.The Address 2 field of CF-End is defined to be the address of the STA contained in the AP, but in 802.11n a STA can also send CF-End.The Address 2 field is not specified clearly in this case. This register chooses between MAC ID of the STA or BSSID of the network. 0: BSSID 1: MAC ID */
#define BIT_SHIFT_WMAC_TCR_CRC                       8
#define BIT_WMAC_TCR_CRC                             ((u32)0x00000001 << BIT_SHIFT_WMAC_TCR_CRC)                       /*!<R/W 0  Append 32-bit Cyclic Redundancy Check. This bit indicates the existence of a CRC32 appended to a packet. 1: No CRC32 appended 0: A CRC32 is appended */
#define BIT_SHIFT_WMAC_TCR_PWRMGT_CTL                7
#define BIT_WMAC_TCR_PWRMGT_CTL                      ((u32)0x00000001 << BIT_SHIFT_WMAC_TCR_PWRMGT_CTL)                /*!<R/W 0  If this bit is set to 1, MAC will overwrite power bit of frame control according to PWR_ST. (only for data frame) */
#define BIT_SHIFT_WMAC_TCR_PWRMGT_VAL                6
#define BIT_WMAC_TCR_PWRMGT_VAL                      ((u32)0x00000001 << BIT_SHIFT_WMAC_TCR_PWRMGT_VAL)                /*!<R/W 0  MAC will overwrite power bit of frame control according to PWR_ST.(only for data frame) */
#define BIT_SHIFT_WMAC_TCR_UPD_TIMIE                 5
#define BIT_WMAC_TCR_UPD_TIMIE                       ((u32)0x00000001 << BIT_SHIFT_WMAC_TCR_UPD_TIMIE)                 /*!<R/W 0  when set to 1, enable hw to update beacon's time field */
#define BIT_SHIFT_WMAC_TCR_UPD_HGQMD                 4
#define BIT_WMAC_TCR_UPD_HGQMD                       ((u32)0x00000001 << BIT_SHIFT_WMAC_TCR_UPD_HGQMD)                 /*!<R/W 0  when set to 1, enable HGQ set moredata bit in Frame control field */
#define BIT_SHIFT_WMAC_TCR_VHTSIGA1_TXPS             3
#define BIT_WMAC_TCR_VHTSIGA1_TXPS                   ((u32)0x00000001 << BIT_SHIFT_WMAC_TCR_VHTSIGA1_TXPS)             /*!<R/W 0  This bit controls TXOP_PS_NOT_ALLOWED bit value of VHT-SIG-A1 field in TX VHT packets 1: TXOP_PS_NOT_ALLOWED is set to 1 0: TXOP_PS_NOT_ALLOWED is set to 0 */
#define BIT_SHIFT_WMAC_TCR_PADSEL                    2
#define BIT_WMAC_TCR_PADSEL                          ((u32)0x00000001 << BIT_SHIFT_WMAC_TCR_PADSEL)                    /*!<R/W 0  AMPDU Padding pattern selection 0: 32-bit Zero padding, 1: Zero length delimiter. */
#define BIT_SHIFT_WMAC_TCR_DISGCLK                   1
#define BIT_WMAC_TCR_DISGCLK                         ((u32)0x00000001 << BIT_SHIFT_WMAC_TCR_DISGCLK)                   /*!<R/W 0  when set to 1��disable MACTX clock gating control. */

/* REG_RCR 0x0608 */
#define BIT_SHIFT_APP_FCS                            31
#define BIT_APP_FCS                                  ((u32)0x00000001 << BIT_SHIFT_APP_FCS)                            /*!<R/W 0  When set, wmac RX will append FCS after payload. */
#define BIT_SHIFT_APP_MIC                            30
#define BIT_APP_MIC                                  ((u32)0x00000001 << BIT_SHIFT_APP_MIC)                            /*!<R/W 0  When this bit is set to 1, MACRX will retain the MIC at the bottom of the packet. Otherwise, MIC will be removed and reported the status in RXDESC. When a MPDU is encrypted with TKIP without MIC, MACRX will ignore this option, that is, MIC must be remained in back of the plain text. */
#define BIT_SHIFT_APP_ICV                            29
#define BIT_APP_ICV                                  ((u32)0x00000001 << BIT_SHIFT_APP_ICV)                            /*!<R/W 0  When this bit is set to 1, MACRX will retain the ICV at the bottom of the packet. Otherwise, MIC will be removed and reported the status in RXDESC. */
#define BIT_SHIFT_APP_PHYSTS                         28
#define BIT_APP_PHYSTS                               ((u32)0x00000001 << BIT_SHIFT_APP_PHYSTS)                         /*!<R/W 0  Append RXFF0 PHY Status Enable When this bit is set, then PHY Status is appended before RX packet in RXFF. When this bit is set, the RX_DRV_INFO_SZ shall be set to include PHY Status report. */
#define BIT_SHIFT_APP_BASSN                          27
#define BIT_APP_BASSN                                ((u32)0x00000001 << BIT_SHIFT_APP_BASSN)                          /*!<R/W 0  Append SSN of previous TXBA Enable When this bit is set, then SSN of previous TXBA is appended as after original RXDESC as the 4-th DW of RXDESC. */
#define BIT_SHIFT_VHT_DACK                           26
#define BIT_VHT_DACK                                 ((u32)0x00000001 << BIT_SHIFT_VHT_DACK)                           /*!<R/W 0  This bit to control response type for vht single mpdu data packet. 1�� ACK as response 0�� BA as response */
#define BIT_SHIFT_TCPOFLD_EN                         25
#define BIT_TCPOFLD_EN                               ((u32)0x00000001 << BIT_SHIFT_TCPOFLD_EN)                         /*!<R/W 0  When set��Enable TCP checksum offload */
#define BIT_SHIFT_ENMBID                             24
#define BIT_ENMBID                                   ((u32)0x00000001 << BIT_SHIFT_ENMBID)                             /*!<R/W 0  Enable Multiple Bssid. 1: Enable. Only response ACK to the packets whose DID(A1) matching to the addresses in the MBSSID CAM Entries. 0: Disable. */
#define BIT_SHIFT_LSIGEN                             23
#define BIT_LSIGEN                                   ((u32)0x00000001 << BIT_SHIFT_LSIGEN)                             /*!<R/W 0  Enable LSIG TXOP Protection function. 1: Enable. Search KEYCAM for each rx packet to check if LSIGEN bit is set. If LSIGEN is set, then sender support LSIG TXOP protection and we need send response with LSIG TXOP protection 0: Disable */
#define BIT_SHIFT_MFBEN                              22
#define BIT_MFBEN                                    ((u32)0x00000001 << BIT_SHIFT_MFBEN)                              /*!<R/W 0  Enable immediate MCS Feedback function 1: Enable. When Rx packet with MRQ = 1?b1, then search KEYCAM to find sender?s MCS Feedback function and send response 0: Disable */
#define BIT_SHIFT_DISCHKPPDLLEN                      21
#define BIT_DISCHKPPDLLEN                            ((u32)0x00000001 << BIT_SHIFT_DISCHKPPDLLEN)                      /*!<R/W 0  When set��do not check PPDU while the PPDU length is smaller than 14 byte. */
#define BIT_SHIFT_PKTCTL_DLKEN                       20
#define BIT_PKTCTL_DLKEN                             ((u32)0x00000001 << BIT_SHIFT_PKTCTL_DLKEN)                       /*!<R/W 0  When set��while rx path dead lock occurs, reset rx path */
#define BIT_SHIFT_DISGCLK                            19
#define BIT_DISGCLK                                  ((u32)0x00000001 << BIT_SHIFT_DISGCLK)                            /*!<R/W 0  When set��disable macrx clock gating control */
#define BIT_SHIFT_TIMPSR_EN                          18
#define BIT_TIMPSR_EN                                ((u32)0x00000001 << BIT_SHIFT_TIMPSR_EN)                          /*!<R/W 0  When set, enable RX Beacon TIM Parser */
#define BIT_SHIFT_BCMDINT_EN                         17
#define BIT_BCMDINT_EN                               ((u32)0x00000001 << BIT_SHIFT_BCMDINT_EN)                         /*!<R/W 0  Broadcast data packet interrupt enable. When this bit is set, this bit is auto clear by MAC. As long as a data type broadcast packet is received, this bit will be set. */
#define BIT_SHIFT_UCMDINT_EN                         16
#define BIT_UCMDINT_EN                               ((u32)0x00000001 << BIT_SHIFT_UCMDINT_EN)                         /*!<R/W 0  Unicast data packet with FC.MD = 1 interrupt enable. When this bit is set, this bit is auto clear by MAC. As long as a data type unicast packet is received, this bit will be set. */
#define BIT_SHIFT_RXSK_PERPKT                        15
#define BIT_RXSK_PERPKT                              ((u32)0x00000001 << BIT_SHIFT_RXSK_PERPKT)                        /*!<R/W 0  Executing key search per MPDU */
#define BIT_SHIFT_HTCBFMC                            14
#define BIT_HTCBFMC                                  ((u32)0x00000001 << BIT_SHIFT_HTCBFMC)                            /*!<R/W 0  1: HTC -> MFC 0: MFC-> HTC */
#define BIT_SHIFT_CHK_PREVTXA2                       13
#define BIT_CHK_PREVTXA2                             ((u32)0x00000001 << BIT_SHIFT_CHK_PREVTXA2)                       /*!<R/W 0  When set,enable check rxa1 with txa2. */
#define BIT_SHIFT_ACK_CBSSID                         12
#define BIT_ACK_CBSSID                               ((u32)0x00000001 << BIT_SHIFT_ACK_CBSSID)                         /*!<R/W 0  The field effects behavior of BA/ACK frame. 0:Only A1 match to send BA/ACK frame. 1:A1 match and satisfy BSSID condition(if BIT_CBSSID_DATA = 1) will send BA/ACK frame. If BIT_CBSSID_DATA = 0, hardware send BA/ACK frame decided by A1 match condition. */
#define BIT_SHIFT_CHKTA_MGNT                         11
#define BIT_CHKTA_MGNT                               ((u32)0x00000001 << BIT_SHIFT_CHKTA_MGNT)                         /*!<R/W 0  Check Transmitter_BCN When set to 1, MAC will check the Transmitter Address (A2) of RX beacon or Probe response to determine if this packet belongs to this Transmitter Address (Address 2) . Both in Infrastructure mode and Ad-hoc mode. */
#define BIT_SHIFT_DISDECNMYPKT                       10
#define BIT_DISDECNMYPKT                             ((u32)0x00000001 << BIT_SHIFT_DISDECNMYPKT)                       /*!<R/W 0  This bit determines whether hw need to do decryption. 1: If A1 match or broadcast, do decryption. 0: Do decryption. */
#define BIT_SHIFT_AICV                               9
#define BIT_AICV                                     ((u32)0x00000001 << BIT_SHIFT_AICV)                               /*!<R/W 0  Accept Integrity Check Value Error packets. This bit determines whether packets with ICV errors will be accepted or rejected. 1: Accept 0: Reject */
#define BIT_SHIFT_ACRC32                             8
#define BIT_ACRC32                                   ((u32)0x00000001 << BIT_SHIFT_ACRC32)                             /*!<R/W 0  Accept CRC32 Error packets. When set to 1, packets with CRC32 errors will be accepted. When set to 0, packets with CRC32 errors will be rejected. 1: Accept 0: Reject */
#define BIT_SHIFT_CBSSID_MGNT                        7
#define BIT_CBSSID_MGNT                              ((u32)0x00000001 << BIT_SHIFT_CBSSID_MGNT)                        /*!<R/W 0  Check BSSID_BCN When set to 1, MAC will check the BSSID of RX beacon or Probe response to determine if this packet belongs to this BSSID. */
#define BIT_SHIFT_CBSSID_DATA                        6
#define BIT_CBSSID_DATA                              ((u32)0x00000001 << BIT_SHIFT_CBSSID_DATA)                        /*!<R/W 0  Check BSSID_DATA, To DS, From DS Match Packet. When set to 1, MAC will check the Rx data type frame?s BSSID, To DS, and From DS fields, to determine if it is set to Link OK in an Infrastructure or Ad hoc network. Note this setting is independent of nettype. Driver must set this bit in ad hoc mode and client mode. */
#define BIT_SHIFT_APWRMGT                            5
#define BIT_APWRMGT                                  ((u32)0x00000001 << BIT_SHIFT_APWRMGT)                            /*!<R/W 0  Accept Power Management Packet. This bit determines whether the RTL8192D will accept or reject packets with the power management bit set. 1: Accept 0: Reject */
#define BIT_SHIFT_ADD3                               4
#define BIT_ADD3                                     ((u32)0x00000001 << BIT_SHIFT_ADD3)                               /*!<R/W 0  Accept Address 3 Match Packets. Set this bit to 1 to accept broadcast/multicast data type frames that Address 3 matching RTL8190?s MAC address. This bit is valid only when NETYPE (bit 3-2, MSR) is set to Link OK on an Infrastructure network. */
#define BIT_SHIFT_AB                                 3
#define BIT_AB                                       ((u32)0x00000001 << BIT_SHIFT_AB)                                 /*!<R/W 0  Accept Broadcast packets. This bit determines whether broadcast packets will be accepted or rejected. 1: Accept 0: Reject */
#define BIT_SHIFT_AM                                 2
#define BIT_AM                                       ((u32)0x00000001 << BIT_SHIFT_AM)                                 /*!<R/W 0  Accept Multicast packets. This bit determines whether multicast packets will be accepted or rejected. 1: Accept 0: Reject */
#define BIT_SHIFT_APM                                1
#define BIT_APM                                      ((u32)0x00000001 << BIT_SHIFT_APM)                                /*!<R/W 0  Accept Physical Match packets. This bit determines whether physical match packets will be accepted or rejected. 1: Accept 0: Reject */
#define BIT_SHIFT_AAP                                0
#define BIT_AAP                                      ((u32)0x00000001 << BIT_SHIFT_AAP)                                /*!<R/W 0  Accept Destination Address packets. This bit determines whether packets with a destination address will be accepted or rejected. 1: Accept 0: Reject */

/* REG_RXPKT_LIMIT 0x060C */
#define BIT_SHIFT_RXPKTLMT                           0
#define BIT_MASK_RXPKTLMT                            ((u32)0x0000003F << BIT_SHIFT_RXPKTLMT)                           /*!<R/W 0x10  RX PKT Upper Limit. The unit is 512 bytes. When ��0��, no RX limit is forced. */

/* REG_RX_DLK 0x060D */
#define BIT_SHIFT_RX_DLK_TIME                        0
#define BIT_MASK_RX_DLK_TIME                         ((u32)0x000000FF << BIT_SHIFT_RX_DLK_TIME)                        /*!<R/W 0x04  macrx dead lock timer timeout value (unit in 2us). As CCA is deasserted and no RXD is received but macrx still waits coming RXD, the deadlock timer will be enabled in this case */

/* REG_MBIDCTRL 0x060E */
#define BIT_SHIFT_MBID_EN                            7
#define BIT_MBID_EN                                  ((u32)0x00000001 << BIT_SHIFT_MBID_EN)                            /*!<R/W 0   */
#define BIT_SHIFT_MBID_BCNNO                         4
#define BIT_MASK_MBID_BCNNO                          ((u32)0x00000007 << BIT_SHIFT_MBID_BCNNO)                         /*!<R/W 0   */

/* REG_RX_DRVINFO_SZ 0x060F */
#define BIT_SHIFT_APP_PHYSTS_PER_SUBMPDU             7
#define BIT_APP_PHYSTS_PER_SUBMPDU                   ((u32)0x00000001 << BIT_SHIFT_APP_PHYSTS_PER_SUBMPDU)             /*!<R/W 0  When this bit is set to 1,append phy status for each mpdu if phy status is valid. Otherwise,append phy status for each ppdu. */
#define BIT_SHIFT_APP_MH_SHIFT_VAL                   6
#define BIT_APP_MH_SHIFT_VAL                         ((u32)0x00000001 << BIT_SHIFT_APP_MH_SHIFT_VAL)                   /*!<R/W 0  When this bit is set to 1,append MAC header shift value in rx descriptor,otherwise, not append */
#define BIT_SHIFT_WMAC_ENSHIFT                       5
#define BIT_WMAC_ENSHIFT                             ((u32)0x00000001 << BIT_SHIFT_WMAC_ENSHIFT)                       /*!<R/W 0  MAC header shift function enable signal in MACRX */
#define BIT_SHIFT_RX_DRVINFO_SZ                      0
#define BIT_MASK_RX_DRVINFO_SZ                       ((u32)0x0000000F << BIT_SHIFT_RX_DRVINFO_SZ)                      /*!<R/W 0x4  RX DESC Driver Info Size: For RXPKTBUF layout, this field indicates the offset starting from the end of RXDESC to the beginning of RX packet. The unit is 8-byte. This value will be copied to DRV_INFO_SIZE field in RXDESC. */

/* REG_MACID 0x0610 */
#define BIT_SHIFT_MACID_V1                           0
#define BIT_MASK_MACID_V1                            ((u32)0xFFFFFFFF << BIT_SHIFT_MACID_V1)                           /*!<   MAC Identification Number Register BIT[31:0] */

/* REG_MACID_H 0x0614 */
#define BIT_SHIFT_AP_BSSID_FIT_UC                    21
#define BIT_AP_BSSID_FIT_UC                          ((u32)0x00000001 << BIT_SHIFT_AP_BSSID_FIT_UC)                    /*!<R/W 0  When set1��bssid fit when AP port0 rx unciast data packet */
#define BIT_SHIFT_EN_PORT1                           17
#define BIT_EN_PORT1                                 ((u32)0x00000001 << BIT_SHIFT_EN_PORT1)                           /*!<R/W 0x1  When set1��enable PORT1 */
#define BIT_SHIFT_EN_PORT0                           16
#define BIT_EN_PORT0                                 ((u32)0x00000001 << BIT_SHIFT_EN_PORT0)                           /*!<R/W 0x1  When set1��enable PORT0 */
#define BIT_SHIFT_MACID_H                            0
#define BIT_MASK_MACID_H                             ((u32)0x0000FFFF << BIT_SHIFT_MACID_H)                            /*!<R/W 0  MAC Identification Number Register BIT[47:32] */

/* REG_BSSID 0x0618 */
#define BIT_SHIFT_BSSID_V1                           0
#define BIT_MASK_BSSID_V1                            ((u32)0xFFFFFFFF << BIT_SHIFT_BSSID_V1)                           /*!<R/W 0  Basic Station Set Identification BIT[31:0] */

/* REG_BSSID_H 0x061C */
#define BIT_SHIFT_BSSID_H                            0
#define BIT_MASK_BSSID_H                             ((u32)0x0000FFFF << BIT_SHIFT_BSSID_H)                            /*!<R/W 0  Basic Station Set Identification BIT[47:32] */

/* REG_MAR 0x0620 */
#define BIT_SHIFT_MAR_V1                             0
#define BIT_MASK_MAR_V1                              ((u32)0xFFFFFFFF << BIT_SHIFT_MAR_V1)                             /*!<R/W 0  Multicast Address Register BIT[31:0]. The value of this register is written by the driver to specify the type of multicast address supported by RTL8192D. The value is created by a hashed calculation that is also implemented by the hardware for multicast address filtering. */

/* REG_MAR_H 0x0624 */
#define BIT_SHIFT_MAR_H                              0
#define BIT_MASK_MAR_H                               ((u32)0xFFFFFFFF << BIT_SHIFT_MAR_H)                              /*!<R/W 0  Multicast Address Register BIT[63:32].The value of this register is written by the driver to specify the type of multicast address supported by RTL8192D. The value is created by a hashed calculation that is also implemented by the hardware for multicast address filtering. */

/* REG_MBIDCAMCFG_1 0x0628 */
#define BIT_SHIFT_MBIDCAM_WDATA_L                    0
#define BIT_MASK_MBIDCAM_WDATA_L                     ((u32)0xFFFFFFFF << BIT_SHIFT_MBIDCAM_WDATA_L)                    /*!<R/W 0  BSSID[31:0] */

/* REG_MBIDCAM_CFG 0x062C */
#define BIT_SHIFT_MBIDCAM_POLL                       31
#define BIT_MBIDCAM_POLL                             ((u32)0x00000001 << BIT_SHIFT_MBIDCAM_POLL)                       /*!<W 0  Pooling bit. */
#define BIT_SHIFT_MBIDCAM_WT_EN                      30
#define BIT_MBIDCAM_WT_EN                            ((u32)0x00000001 << BIT_SHIFT_MBIDCAM_WT_EN)                      /*!<R/W 0  Write Enable. */
#define BIT_SHIFT_MBIDCAM_DA_EN                      29
#define BIT_MBIDCAM_DA_EN                            ((u32)0x00000001 << BIT_SHIFT_MBIDCAM_DA_EN)                      /*!<R/W 0  CAM Direct Acess Enable */
#define BIT_SHIFT_MBIDCAM_ADDR_V1                    24
#define BIT_MASK_MBIDCAM_ADDR_V1                     ((u32)0x0000001F << BIT_SHIFT_MBIDCAM_ADDR_V1)                    /*!<R/W 0  CAM Address */
#define BIT_SHIFT_MBIDCAM_VALID                      23
#define BIT_MBIDCAM_VALID                            ((u32)0x00000001 << BIT_SHIFT_MBIDCAM_VALID)                      /*!<R/W 0  CAM Valid bit. */
#define BIT_SHIFT_LSIC_TXOP_EN                       17
#define BIT_LSIC_TXOP_EN                             ((u32)0x00000001 << BIT_SHIFT_LSIC_TXOP_EN)                       /*!<R/W 0  LSIG TXOP enable */
#define BIT_SHIFT_CTS_EN                             16
#define BIT_CTS_EN                                   ((u32)0x00000001 << BIT_SHIFT_CTS_EN)                             /*!<R/W 0  Dual CTS/CFE enable */
#define BIT_SHIFT_MBIDCAM_RWDATA_H                   0
#define BIT_MASK_MBIDCAM_RWDATA_H                    ((u32)0x0000FFFF << BIT_SHIFT_MBIDCAM_RWDATA_H)                   /*!<R/W 0  BSSID[47:32] */

/* REG_WMAC_TCR_TSFT_OFS 0x0630 */
#define BIT_SHIFT_WMAC_TCR_TSFT_OFS                  0
#define BIT_MASK_WMAC_TCR_TSFT_OFS                   ((u32)0x0000FFFF << BIT_SHIFT_WMAC_TCR_TSFT_OFS)                  /*!<R/W 0  BIT_WMAC_TCR_TSFT_OFS[7:0] is for cck stamp time offset; BIT_WMAC_TCR_TSFT_OFS[15:8] is for other rate time offset; */

/* REG_UDF_THSD 0x0632 */
#define BIT_SHIFT_UDF_THSD_V1                        7
#define BIT_UDF_THSD_V1                              ((u32)0x00000001 << BIT_SHIFT_UDF_THSD_V1)                        /*!<R/W 0x1  BIT_UDF_THSD[7]=1,enable underflow recovery;r_UDF_THSD[7]=0,disable underflow recovery; BIT_UDF_THSD[6:0]: when mac_wrptr - PHY_rdptr is less than this value, set underflow; */
#define BIT_SHIFT_UDF_THSD_VALUE                     0
#define BIT_MASK_UDF_THSD_VALUE                      ((u32)0x0000007F << BIT_SHIFT_UDF_THSD_VALUE)                     /*!<R/W 0x4  Underflow threshold */

/* REG_ZLD_NUM 0x0633 */
#define BIT_SHIFT_ZLD_NUM                            0
#define BIT_MASK_ZLD_NUM                             ((u32)0x000000FF << BIT_SHIFT_ZLD_NUM)                            /*!<R/W 0x8  Fetch zero length delimiter number(unit : 4bytes) when mactx underflow */

/* REG_STMP_THSD 0x0634 */
#define BIT_SHIFT_STMP_THSD                          0
#define BIT_MASK_STMP_THSD                           ((u32)0x000000FF << BIT_SHIFT_STMP_THSD)                          /*!<R/W 0x2  when PHY_rdptr is greater than this value, then latch STMP value from TSFT */

/* REG_WMAC_TXTIMEOUT 0x0635 */
#define BIT_SHIFT_WMAC_TXTIMEOUT                     0
#define BIT_MASK_WMAC_TXTIMEOUT                      ((u32)0x000000FF << BIT_SHIFT_WMAC_TXTIMEOUT)                     /*!<R/W 0  BIT_WMAC_TXTIMEOUT[7]=1: enable mac tx timeout function;r_WMAC_TXTIMEOUT[7]=0, disable mac tx timeout function; BIT_WMAC_TXTIMEOUT[6:0]: timeout threshold */

/* REG_USTIME_EDCA 0x0638 */
#define BIT_SHIFT_USTIME_EDCA                        0
#define BIT_MASK_USTIME_EDCA                         ((u32)0x000000FF << BIT_SHIFT_USTIME_EDCA)                        /*!<R/W 0x50  Sets the microsecond time unit used by MAC EDCA clock. */

/* REG_ACKTO_CCK 0x0639 */
#define BIT_SHIFT_ACKTO_CCK                          0
#define BIT_MASK_ACKTO_CCK                           ((u32)0x000000FF << BIT_SHIFT_ACKTO_CCK)                          /*!<R/W 0x14  This register sets the Ack time out value after Tx unicast packet with CCK rate. It is in units of us. */

/* REG_MAC_SPEC_SIFS 0x063A */
#define BIT_SHIFT_SPEC_SIFS_OFDM                     8
#define BIT_MASK_SPEC_SIFS_OFDM                      ((u32)0x000000FF << BIT_SHIFT_SPEC_SIFS_OFDM)                     /*!<R/W 0x10  The spec SIFS value for duration calculation */
#define BIT_SHIFT_SPEC_SIFS_CCK                      0
#define BIT_MASK_SPEC_SIFS_CCK                       ((u32)0x000000FF << BIT_SHIFT_SPEC_SIFS_CCK)                      /*!<R/W 0x0A  The spec SIFS value for duration calculation */

/* REG_RESP_SIFS_CCK 0x063C */
#define BIT_SHIFT_R2T_SIFS_CCK                       8
#define BIT_MASK_R2T_SIFS_CCK                        ((u32)0x000000FF << BIT_SHIFT_R2T_SIFS_CCK)                       /*!<R/W 0x0A  This register sets the SIFS time required for any immediate response for example Data-Ack. It is in unit of us. */
#define BIT_SHIFT_T2T_SIFS_CCK                       0
#define BIT_MASK_T2T_SIFS_CCK                        ((u32)0x000000FF << BIT_SHIFT_T2T_SIFS_CCK)                       /*!<R/W 0x0A  This register sets the SIFS time required for consecutive TX events for example CTS-Data, or broadcast bursting. It is in unit of us. */

/* REG_RESP_SIFS_OFDM 0x063E */
#define BIT_SHIFT_R2T_SIFS_OFDM                      8
#define BIT_MASK_R2T_SIFS_OFDM                       ((u32)0x000000FF << BIT_SHIFT_R2T_SIFS_OFDM)                      /*!<R/W 0x0E  This register sets the SIFS time required for any immediate response for example Data-Ack. It is in unit of us. */
#define BIT_SHIFT_T2T_SIFS_OFDM                      0
#define BIT_MASK_T2T_SIFS_OFDM                       ((u32)0x000000FF << BIT_SHIFT_T2T_SIFS_OFDM)                      /*!<R/W 0x0E  This register sets the SIFS time required for consecutive TX events for example CTS-Data, or broadcast bursting. It is in unit of us. */

/* REG_ACKTO 0x0640 */
#define BIT_SHIFT_ACKTO                              0
#define BIT_MASK_ACKTO                               ((u32)0x000000FF << BIT_SHIFT_ACKTO)                              /*!<R/W 0x14  This register sets the Ack time out value after Tx unicast packet. It is in units of us. */

/* REG_CTS2TO 0x0641 */
#define BIT_SHIFT_CTS2TO                             0
#define BIT_MASK_CTS2TO                              ((u32)0x000000FF << BIT_SHIFT_CTS2TO)                             /*!<R/W 0x14  This register sets the CTS2 time out value after CTS1 in Dual CTS sequence. It is in units of us. */

/* REG_EIFS 0x0642 */
#define BIT_SHIFT_EIFS                               0
#define BIT_MASK_EIFS                                ((u32)0x0000FFFF << BIT_SHIFT_EIFS)                               /*!<R/W 0x013A  This register sets the EIFS value mentioned in 802.11 specification. It is in units of us. To receive 1Mbps ACK frame, EIFS = SIFS + 144us (preamble length) + 48us (PLCP header length) + 112us (14 bytes of data) = 314us. */

/* REG_NAV_CTRL 0x0650 */
#define BIT_SHIFT_NAV_UPBDY                          16
#define BIT_MASK_NAV_UPBDY                           ((u32)0x000000FF << BIT_SHIFT_NAV_UPBDY)                          /*!<R/W 0  When NAV update is beyond this value, then NAV update is aborted. When this field is 0x00, NAV_UPPER function is disable. The unit is 128us. */
#define BIT_SHIFT_RXMYRTS_NAV                        8
#define BIT_MASK_RXMYRTS_NAV                         ((u32)0x0000000F << BIT_SHIFT_RXMYRTS_NAV)                        /*!<R/W 0x4  RX my RTS NAV. As rx my unicast RTS and RxMyRTS_NAV is not equal to zero, then rx NAV is set to wait response transition time and RxMyRTS_NAV to avoid contention with the TXOP originator. If RxMyRTS_NAV is equal to zero, this mechanism is disabled */
#define BIT_SHIFT_RTS_RST_DUR                        0
#define BIT_MASK_RTS_RST_DUR                         ((u32)0x000000FF << BIT_SHIFT_RTS_RST_DUR)                        /*!<R/W 0x26  RTS NAV Reset Time. This is the value in us, not including the time of CTS frame, to reset the NAV set by an RTS frame if no PHY indication occurred during this time. Refer to 802.11 1999 Section 9.2.5.4 for detailed description. */

/* REG_BACAMCMD 0x0654 */
#define BIT_SHIFT_BACAM_POLL                         31
#define BIT_BACAM_POLL                               ((u32)0x00000001 << BIT_SHIFT_BACAM_POLL)                         /*!<W 0  Polling bit BA CAM */
#define BIT_SHIFT_BACAM_RST                          17
#define BIT_BACAM_RST                                ((u32)0x00000001 << BIT_SHIFT_BACAM_RST)                          /*!<RW1C 0  Set 1 to reset BA CAM. Hardware will set the invalid bit for all entries. After reset is finished this bit is reset to 0. */
#define BIT_SHIFT_BACAM_RW                           16
#define BIT_BACAM_RW                                 ((u32)0x00000001 << BIT_SHIFT_BACAM_RW)                           /*!<R/W 0  Set 1 = Write, set 0 = Read */
#define BIT_SHIFT_TXSBMPMOD                          14
#define BIT_MASK_TXSBMPMOD                           ((u32)0x00000003 << BIT_SHIFT_TXSBMPMOD)                          /*!<R/W 0  Bit[15]: if macrx_dma idle, grant txsbmp_req Bit[14]: if macrx is idle, grant txsbmp_req 00: If FSM is idle, grant txsbmp_req 01: If FSM and mac rx is idle, grant txsbmp_req 10: If FSM and macrx_dma is idle, grant txsbmp_req 11: if FSM, macrx and macrx_dma is idle, grant txsbmp_req */
#define BIT_SHIFT_RXBACAM_DA_EN                      13
#define BIT_RXBACAM_DA_EN                            ((u32)0x00000001 << BIT_SHIFT_RXBACAM_DA_EN)                      /*!<R/W 0  CAM Direct Acess enable */
#define BIT_SHIFT_BACAM_AD                           0
#define BIT_MASK_BACAM_AD                            ((u32)0x0000003F << BIT_SHIFT_BACAM_AD)                           /*!<R/W 0  BA CAM address. Memory is double-word access. */

/* REG_BACAM_WD 0x0658 */
#define BIT_SHIFT_BA_CONTENT_L                       0
#define BIT_MASK_BA_CONTENT_L                        ((u32)0xFFFFFFFF << BIT_SHIFT_BA_CONTENT_L)                       /*!<R/W 0  Used for CAM content read and write access register. Because BA CAM is 64 bit access, the double word (32-bit) responds to the lower 32 bits of CAM content. */

/* REG_BACAM_WD_H 0x065C */
#define BIT_SHIFT_BA_CONTENT_H                       0
#define BIT_MASK_BA_CONTENT_H                        ((u32)0xFFFFFFFF << BIT_SHIFT_BA_CONTENT_H)                       /*!<R/W 0  Used for CAM content read and write access register. Because BA CAM is 64 bit access, the double word (32-bit) responds to the upper 32 bits of CAM content. */

/* REG_LBK_DLY 0x0660 */
#define BIT_SHIFT_LBK_DLY                            0
#define BIT_MASK_LBK_DLY                             ((u32)0x0000001F << BIT_SHIFT_LBK_DLY)                            /*!<R/W 0x10  Loopback Delay. In unit of 'us'; indicates the delay after which the tdrdy_mac starts. In wep/tkip mode, the delay should be larger than 15, because the initial delay of security is about 1320 cycles, approximately to 16.5 us. */

/* REG_BITMAP_CMD 0x0661 */
#define BIT_SHIFT_BITMAP_SSNBK_COUNTER               2
#define BIT_MASK_BITMAP_SSNBK_COUNTER                ((u32)0x0000003F << BIT_SHIFT_BITMAP_SSNBK_COUNTER)               /*!<R 0  Count the sequence number out of BITMAP condition (0x663[3:2]). */
#define BIT_SHIFT_BITMAP_EN                          1
#define BIT_BITMAP_EN                                ((u32)0x00000001 << BIT_SHIFT_BITMAP_EN)                          /*!<R/W 0  1:Enable of counter and WMAC_BITMAP_CTL(0x663) 0:Disable function */
#define BIT_SHIFT_BACAM_RPMEN                        0
#define BIT_BACAM_RPMEN                              ((u32)0x00000001 << BIT_SHIFT_BACAM_RPMEN)                        /*!<R/W 0  1:Enable repeat mode 0:Disable function */

/* REG_TX_RX_STATUS 0x0662 */
#define BIT_SHIFT_RXPKT_TYPE                         2
#define BIT_MASK_RXPKT_TYPE                          ((u32)0x0000003F << BIT_SHIFT_RXPKT_TYPE)                         /*!<R 0  The type and subtype field of frame control of rx packet */
#define BIT_SHIFT_TXACT_IND                          1
#define BIT_TXACT_IND                                ((u32)0x00000001 << BIT_SHIFT_TXACT_IND)                          /*!<R 0  Indicate MAC/PHY is busy to tx packet */
#define BIT_SHIFT_RXACT_IND                          0
#define BIT_RXACT_IND                                ((u32)0x00000001 << BIT_SHIFT_RXACT_IND)                          /*!<R 0  Indicate MAC is busy to rx packet */

/* REG_WMAC_BITMAP_CTL 0x0663 */
#define BIT_SHIFT_BITMAP_FLAG_VO                     7
#define BIT_BITMAP_FLAG_VO                           ((u32)0x00000001 << BIT_SHIFT_BITMAP_FLAG_VO)                     /*!<RW1C 0  When BIT_BITMAP_VO = 1, HW will check received packet's sequence number by BIT_BITMAP_CONDITION, and clear the bit after occur one time which received the correct sequence number. */
#define BIT_SHIFT_BITMAP_FLAG_VI                     6
#define BIT_BITMAP_FLAG_VI                           ((u32)0x00000001 << BIT_SHIFT_BITMAP_FLAG_VI)                     /*!<RW1C 0  When BIT_BITMAP_VI = 1, HW will check received packet��s sequence number by BIT_BITMAP_CONDITION, and clear the bit after occur one time which received the correct sequence number. */
#define BIT_SHIFT_BITMAP_FLAG_BE                     5
#define BIT_BITMAP_FLAG_BE                           ((u32)0x00000001 << BIT_SHIFT_BITMAP_FLAG_BE)                     /*!<RW1C 0  When BIT_BITMAP_BE = 1, HW will check received packet's sequence number by BIT_BITMAP_CONDITION, and clear the bit after occur one time which received the correct sequence number. */
#define BIT_SHIFT_BITMAP_FLAG_BK                     4
#define BIT_BITMAP_FLAG_BK                           ((u32)0x00000001 << BIT_SHIFT_BITMAP_FLAG_BK)                     /*!<RW1C 0  When BIT_BITMAP_BK = 1, HW will check received packet's sequence number by BIT_BITMAP_CONDITION, and clear the bit after occur one time which received the correct sequence number. */
#define BIT_SHIFT_BITMAP_CONDITION                   2
#define BIT_MASK_BITMAP_CONDITION                    ((u32)0x00000003 << BIT_SHIFT_BITMAP_CONDITION)                   /*!<R/W 0  ADDBA condition: 0: HW start sequence - 64. 1: HW start sequence - 128. 2: HW start sequence - 256. 3: HW start sequence - 512. */
#define BIT_SHIFT_BITMAP_SSNBK_COUNTER_CLR           1
#define BIT_BITMAP_SSNBK_COUNTER_CLR                 ((u32)0x00000001 << BIT_SHIFT_BITMAP_SSNBK_COUNTER_CLR)           /*!<W1C 0  Clear BIT_BITMAP_SSNBK_COUNTER. */
#define BIT_SHIFT_BITMAP_FORCE                       0
#define BIT_BITMAP_FORCE                             ((u32)0x00000001 << BIT_SHIFT_BITMAP_FORCE)                       /*!<R/W 0  Under the BIT_BITMAP_EN = 1 condition. 1: Rx��s packet always checks sequence number by BIT_BITMAP_CONDITION. 0: Disable */

/* REG_RXERR_RPT 0x0664 */
#define BIT_SHIFT_RXERR_RPT_SEL_V1_3_0               28
#define BIT_MASK_RXERR_RPT_SEL_V1_3_0                ((u32)0x0000000F << BIT_SHIFT_RXERR_RPT_SEL_V1_3_0)               /*!<R/W 0  Rx packet counter report selection bit3~bit0 RXERR_RPT_SEL[4:0]: Counter description 5'd0: OFDM MPDU OK counter 5'd1: OFDM MPDU Fail counter 5'd2: OFDM False Alarm counter 5'd3: CCK MPDU OK counter 5'd4: CCK MPDU Fail counter 5'd5: CCK False Alarm counter; 5'd6: HT MPDU OK counter 5'd7: HT MPDU Fail counter 5'd8: HT PPDU counter 5'd9: HT False Alarm counter 5'd10: Rx full drop packet counter 5'd11: RSVD 5'd12: user define 0 counter 5'd13: user define 1 counter 5'd14: user define 2 counter 5'd15: user define 3 counter 5'd16: VHT MPDU OK counter 5'd17: VHT MPDU Fail counter 5'd18: VHT PPDU counter 5'd19: VHT False Alarm counter 5'd23: invalid_pkt counter */
#define BIT_SHIFT_RXERR_RPT_RST                      27
#define BIT_RXERR_RPT_RST                            ((u32)0x00000001 << BIT_SHIFT_RXERR_RPT_RST)                      /*!<W 0  Write ��one�� to set the counter to zero. */
#define BIT_SHIFT_RXERR_RPT_SEL_V1_4                 26
#define BIT_RXERR_RPT_SEL_V1_4                       ((u32)0x00000001 << BIT_SHIFT_RXERR_RPT_SEL_V1_4)                 /*!<R/W 0  Rx packet counter report selection bit4 */
#define BIT_SHIFT_UD_SELECT_BSSID_2_1                24
#define BIT_MASK_UD_SELECT_BSSID_2_1                 ((u32)0x00000003 << BIT_SHIFT_UD_SELECT_BSSID_2_1)                /*!<R/W 0  {25,24,22} Select BSSID: 3'b0: Port 0 3'b1: Port 1 3'b2: Port 2 3'b3: Port 3 3'b4: Port 4 */
#define BIT_SHIFT_W1S                                23
#define BIT_W1S                                      ((u32)0x00000001 << BIT_SHIFT_W1S)                                /*!<R/W 0  Write One Setting, it is only valid for RXERR_RPT_SEL (4'd12 ~ 4'd15) */
#define BIT_SHIFT_UD_SELECT_BSSID                    22
#define BIT_UD_SELECT_BSSID                          ((u32)0x00000001 << BIT_SHIFT_UD_SELECT_BSSID)                    /*!<R/W 0  Select BSSID: 0: Port 0 1: Port 1 */
#define BIT_SHIFT_UD_SUB_TYPE                        18
#define BIT_MASK_UD_SUB_TYPE                         ((u32)0x0000000F << BIT_SHIFT_UD_SUB_TYPE)                        /*!<R/W 0  User defined: SubType */
#define BIT_SHIFT_UD_TYPE                            16
#define BIT_MASK_UD_TYPE                             ((u32)0x00000003 << BIT_SHIFT_UD_TYPE)                            /*!<R/W 0  User defined: Type */
#define BIT_SHIFT_RPT_COUNTER                        0
#define BIT_MASK_RPT_COUNTER                         ((u32)0x0000FFFF << BIT_SHIFT_RPT_COUNTER)                        /*!<R/W 0  The reported counter value corresponding to Report type selected. */

/* REG_WMAC_TRXPTCL_CTL 0x0668 */
#define BIT_SHIFT_BLK_EDCA_BBSLP                     31
#define BIT_BLK_EDCA_BBSLP                           ((u32)0x00000001 << BIT_SHIFT_BLK_EDCA_BBSLP)                     /*!<R/W 0  Block EDCA Tx while BB in sleep state */
#define BIT_SHIFT_BLK_EDCA_BBSBY                     30
#define BIT_BLK_EDCA_BBSBY                           ((u32)0x00000001 << BIT_SHIFT_BLK_EDCA_BBSBY)                     /*!<R/W 0  Block EDCA Tx while BB in standby state */
#define BIT_SHIFT_EN_STOP_UPDNAV                     28
#define BIT_EN_STOP_UPDNAV                           ((u32)0x00000001 << BIT_SHIFT_EN_STOP_UPDNAV)                     /*!<R/W 0  When this bit set 1. If RX packet with EDCA_REF is low, not update NAV. */
#define BIT_SHIFT_RST_EDCA_ACKTO                     27
#define BIT_RST_EDCA_ACKTO                           ((u32)0x00000001 << BIT_SHIFT_RST_EDCA_ACKTO)                     /*!<R/W 0x1  While in ACKTO duration, reset scheduler top to TX */
#define BIT_SHIFT_RST_EDCA_EIFS                      26
#define BIT_RST_EDCA_EIFS                            ((u32)0x00000001 << BIT_SHIFT_RST_EDCA_EIFS)                      /*!<R/W 0x1  While in EIFS duration, reset scheduler top to TX */
#define BIT_SHIFT_PLCPCHK_RST_EIFS                   25
#define BIT_PLCPCHK_RST_EIFS                         ((u32)0x00000001 << BIT_SHIFT_PLCPCHK_RST_EIFS)                   /*!<R/W 0x1  Reset EIFS counter while receive correct PLCP. */
#define BIT_SHIFT_CCA_RST_EIFS                       24
#define BIT_CCA_RST_EIFS                             ((u32)0x00000001 << BIT_SHIFT_CCA_RST_EIFS)                       /*!<R/W 0  Reset EIFS counter while CCA on */
#define BIT_SHIFT_DIS_UPD_MYRXPKTNAV                 23
#define BIT_DIS_UPD_MYRXPKTNAV                       ((u32)0x00000001 << BIT_SHIFT_DIS_UPD_MYRXPKTNAV)                 /*!<R/W 0  Do not update NAV, while receiving my packet. */
#define BIT_SHIFT_EARLY_TXBA                         22
#define BIT_EARLY_TXBA                               ((u32)0x00000001 << BIT_SHIFT_EARLY_TXBA)                         /*!<R/W 0  While phyrxon down, mac_rxactive on. Ignore mac rx busy, respond BA immediately. */
#define BIT_SHIFT_RESP_CHNBUSY                       20
#define BIT_MASK_RESP_CHNBUSY                        ((u32)0x00000003 << BIT_SHIFT_RESP_CHNBUSY)                       /*!<R/W 0x3  Define channel busy condition in responder to determine RX busy 1: PHYRXON (OFDM_VBON/CCKCCA) 0: CCA (CCKCCA/OFDMCCA) */
#define BIT_SHIFT_RESP_DCTS_EN                       19
#define BIT_RESP_DCTS_EN                             ((u32)0x00000001 << BIT_SHIFT_RESP_DCTS_EN)                       /*!<R/W 0  Enable responder send dual CTS for responding Rx RTS */
#define BIT_SHIFT_RESP_DCFE_EN                       18
#define BIT_RESP_DCFE_EN                             ((u32)0x00000001 << BIT_SHIFT_RESP_DCFE_EN)                       /*!<R/W 0  Enable responder send dual CF-END for responding RX CF-END */
#define BIT_SHIFT_RESP_SPLCPEN                       17
#define BIT_RESP_SPLCPEN                             ((u32)0x00000001 << BIT_SHIFT_RESP_SPLCPEN)                       /*!<R/W 0  Enable responder send SPLCP CCK response for acknowledging Rx SPLCP CCK packet */
#define BIT_SHIFT_RESP_SGIEN                         16
#define BIT_RESP_SGIEN                               ((u32)0x00000001 << BIT_SHIFT_RESP_SGIEN)                         /*!<R/W 0  Enable responder send SGI HT-OFDM response for acknowledging Rx SGI HT-OFDM packet */
#define BIT_SHIFT_RESP_LDPC_EN                       15
#define BIT_RESP_LDPC_EN                             ((u32)0x00000001 << BIT_SHIFT_RESP_LDPC_EN)                       /*!<R/W 0  if rxpkt with ldpc, response pkt with ldpc */
#define BIT_SHIFT_DIS_RESP_ACKINCCA                  14
#define BIT_DIS_RESP_ACKINCCA                        ((u32)0x00000001 << BIT_SHIFT_DIS_RESP_ACKINCCA)                  /*!<R/W 0  Disable to response ack when cca goes high after SIFS */
#define BIT_SHIFT_DIS_RESP_CTSINCCA                  13
#define BIT_DIS_RESP_CTSINCCA                        ((u32)0x00000001 << BIT_SHIFT_DIS_RESP_CTSINCCA)                  /*!<R/W 0  8812 Disable to response cts when cca goes high after SIFS */
#define BIT_SHIFT_SECOND_CCA_TIMER                   10
#define BIT_MASK_SECOND_CCA_TIMER                    ((u32)0x00000007 << BIT_SHIFT_SECOND_CCA_TIMER)                   /*!<R/W 0x4  8812 The maximum time interval in us that secondary cca is pull high before primary cca When receive duplicated rts. When station response with cts, if the time that secondary cca pull high before primary cca is larger than this threshold, then secondary cca is judged to be interference, otherwise it is judged to the received RTS frame. default: 3?b0 */
#define BIT_SHIFT_RFMOD                              7
#define BIT_MASK_RFMOD                               ((u32)0x00000003 << BIT_SHIFT_RFMOD)                              /*!<R/W 0  8812 RF_BW indication, Used to decide response duplicated cts txsc 2?b00: 20M, 2?b01: 40M, 2?b10: 80M e.g: when RF_BW= 80M, duplicated cts BW= 40M, txsc = 9 or 10 when RF_BW = 40M, duplicated cts BW = 40M, txsc = 0 */
#define BIT_SHIFT_RESP_CTS_DYNBW_SEL                 5
#define BIT_MASK_RESP_CTS_DYNBW_SEL                  ((u32)0x00000003 << BIT_SHIFT_RESP_CTS_DYNBW_SEL)                 /*!<R/W 0  8812 Response cts bw selection when dynamic rts frame is received 00: current maximum bw indicated by secondary cca 01: bw fall back by one level based on bw in 2?b00 if not reach 20M 10: bw fall back by one level based on bw in 2?b01 if not reach 20M 11: bw fall back by one level based on bw in 2?b10 if not reach 20M e.g, current maximum bw indicated by secondary_cca is 80M, when set to 2?b00, the response cts bw is 80M, when set to 2?b01, cts bw is 40M, when set to 2?b10 or 2?b11 , cts bw is 20M */
#define BIT_SHIFT_DLY_TX_WAIT_RXANTSEL               4
#define BIT_DLY_TX_WAIT_RXANTSEL                     ((u32)0x00000001 << BIT_SHIFT_DLY_TX_WAIT_RXANTSEL)               /*!<R/W 0  8188E/8812 In some Cases, the phy status may be received too late to be used in the response frame. Enable this bit to postpone the tx of response frame until the phy status is obtained. Otherwise, If the phy status unavailable for its delay, The IOREG value of 0x06D8[6] will be used as before. */
#define BIT_SHIFT_TXRESP_BY_RXANTSEL                 3
#define BIT_TXRESP_BY_RXANTSEL                       ((u32)0x00000001 << BIT_SHIFT_TXRESP_BY_RXANTSEL)                 /*!<R/W 0  8188E/8812 Enable responder send the response frame with the antenna selection information which from the phy status of the previous rx frame. */
#define BIT_SHIFT_ORIG_DCTS_CHK                      0
#define BIT_MASK_ORIG_DCTS_CHK                       ((u32)0x00000003 << BIT_SHIFT_ORIG_DCTS_CHK)                      /*!<R/W 0  Txok condition for dual CTS frame exchange: 00: Either one Rx ok 01: 1st one Rx ok 10: 2nd one Rx ok 11: both Rx ok */

/* REG_WMAC_TRXPTCL_CTL_H 0x066C */
#define BIT_SHIFT_ACKBA_TYPSEL                       28
#define BIT_MASK_ACKBA_TYPSEL                        ((u32)0x0000000F << BIT_SHIFT_ACKBA_TYPSEL)                       /*!<R/W 0  Determine response type for RX BA, and the definition as the bellow 0: NAV 1: Send ACK ACKBA_TYPESEL[0]: used for Basic BA ACKBA_TYPESEL[1]: used for Compression BA ACKBA_TYPESEL[2]: RSVD ACKBA_TYPESEL[3]: used for MTID BA */
#define BIT_SHIFT_ACKBA_ACKPCHK                      24
#define BIT_MASK_ACKBA_ACKPCHK                       ((u32)0x0000000F << BIT_SHIFT_ACKBA_ACKPCHK)                      /*!<R/W 0  If set 1, then check ACK Policy of BA control field to determine whether send response or not. When this bit set to 1 and a. ACK Policy of Rx BA control field is 0, then response type is controlled by ACLBA_TYPESEL. b. ACK Policy of Rx BA control field is 1, then don't send response If set 0, then ignore the ACK policy of RX BA control field and response type controlled by ACKBA_TYPESEL ACKBA_ACKPCHK[0]: used for Basic BA ACKBA_ACKPCHK[1]: used for Compression BA ACKBA_ACKPCHK[2]: RSVD ACKBA_ACKPCHK[3]: used for MTID BA */
#define BIT_SHIFT_ACKBAR_TYPESEL                     16
#define BIT_MASK_ACKBAR_TYPESEL                      ((u32)0x000000FF << BIT_SHIFT_ACKBAR_TYPESEL)                     /*!<R/W 0x4  Determine response type for RX BAR, and the definition as the bellow 00: NAV 01: Send BA 10: Send ACK ACKBAR_TYPESEL[1:0]: used for Basic BAR ACKBAR_TYPESEL[3:2]: used for Compression BAR ACKBAR_TYPESEL[5:4]: RSVD ACKBAR_TYPESEL[7:6]: used for MTID BAR */
#define BIT_SHIFT_ACKBAR_ACKPCHK                     12
#define BIT_MASK_ACKBAR_ACKPCHK                      ((u32)0x0000000F << BIT_SHIFT_ACKBAR_ACKPCHK)                     /*!<R/W 0x2  If set 1, then check ACK Policy of BAR control field to determine whether send response or not. When this bit set to 1 and a. ACK Policy of Rx BAR control field is 0, then response type is controlled by ACLBAR_TYPESEL. b. ACK Policy of Rx BAR control field is 1, then don't send response If set 0, then ignore the ACK policy of RX BAR control field and response type controlled by ACKBA_TYPESEL ACKBA_ACKPCHK[0]: used for Basic BAR ACKBA_ACKPCHK[1]: used for Compression BAR ACKBA_ACKPCHK[2]: RSVD ACKBA_ACKPCHK[3]: used for MTID BAR */
#define BIT_SHIFT_RXBA_IGNOREA2_V1                   10
#define BIT_RXBA_IGNOREA2_V1                         ((u32)0x00000001 << BIT_SHIFT_RXBA_IGNOREA2_V1)                   /*!<R/W 0  Disable check A2 field of RX BA */
#define BIT_SHIFT_EN_SAVE_ALL_TXOPADDR_V1            9
#define BIT_EN_SAVE_ALL_TXOPADDR_V1                  ((u32)0x00000001 << BIT_SHIFT_EN_SAVE_ALL_TXOPADDR_V1)            /*!<R/W 0   */
#define BIT_SHIFT_EN_TXCTS_TO_TXOPOWNER_INRXNAV_V1   8
#define BIT_EN_TXCTS_TO_TXOPOWNER_INRXNAV_V1         ((u32)0x00000001 << BIT_SHIFT_EN_TXCTS_TO_TXOPOWNER_INRXNAV_V1)   /*!<R/W 0  together with bit41, implement 802.11ac txop owner function */
#define BIT_SHIFT_DIS_TXBA_AMPDUFCSERR_V1            7
#define BIT_DIS_TXBA_AMPDUFCSERR_V1                  ((u32)0x00000001 << BIT_SHIFT_DIS_TXBA_AMPDUFCSERR_V1)            /*!<R/W 0  Disable to send BA for responding RX AMPDU with FCS error subframe */
#define BIT_SHIFT_DIS_TXBA_RXBARINFULL_V1            6
#define BIT_DIS_TXBA_RXBARINFULL_V1                  ((u32)0x00000001 << BIT_SHIFT_DIS_TXBA_RXBARINFULL_V1)            /*!<R/W 0  Disable to send BA for responding RX control wrapper BAR dropped by rxpkbuffer full */
#define BIT_SHIFT_DIS_TXCFE_INFULL_V1                5
#define BIT_DIS_TXCFE_INFULL_V1                      ((u32)0x00000001 << BIT_SHIFT_DIS_TXCFE_INFULL_V1)                /*!<R/W 0  Disable to send CF-END for responding RX control wrapper CF-END dropped by rxpktbuffer full. This bit is valid when RESP_DCFE_EN is set to 1 */
#define BIT_SHIFT_DIS_TXCTS_INFULL_V1                4
#define BIT_DIS_TXCTS_INFULL_V1                      ((u32)0x00000001 << BIT_SHIFT_DIS_TXCTS_INFULL_V1)                /*!<R/W 0  Disable to send CTS for responding RX control wrapper RTS dropped by rxpktbuffer full */
#define BIT_SHIFT_EN_TXACKBA_INTX_RDG_V1             3
#define BIT_EN_TXACKBA_INTX_RDG_V1                   ((u32)0x00000001 << BIT_SHIFT_EN_TXACKBA_INTX_RDG_V1)             /*!<R/W 0  If this bit is set, then MAC will Tx ACK/BA to respond previous rx my unicast packets send by another STA during TX RDG */
#define BIT_SHIFT_EN_TXACKBA_INTXOP_V1               2
#define BIT_EN_TXACKBA_INTXOP_V1                     ((u32)0x00000001 << BIT_SHIFT_EN_TXACKBA_INTXOP_V1)               /*!<R/W 1  If this bit is set, then MAC will Tx ACK/BA to respond previous rx my unitcast packets send by another STA during my TXOP */
#define BIT_SHIFT_EN_TXCTS_INRXNAV_V1                1
#define BIT_EN_TXCTS_INRXNAV_V1                      ((u32)0x00000001 << BIT_SHIFT_EN_TXCTS_INRXNAV_V1)                /*!<R/W 1  Enable to send CTS in Rx NAV */
#define BIT_SHIFT_EN_TXCTS_INTXOP_V1                 0
#define BIT_EN_TXCTS_INTXOP_V1                       ((u32)0x00000001 << BIT_SHIFT_EN_TXCTS_INTXOP_V1)                 /*!<R/W 1  Enable to send CTS for responding RX RTS during our TXOP period */

/* REG_KEYCAMCMD 0x0670 */
#define BIT_SHIFT_KEYCAM_POLLING                     31
#define BIT_KEYCAM_POLLING                           ((u32)0x00000001 << BIT_SHIFT_KEYCAM_POLLING)                     /*!<W 0  Security CAM Polling */
#define BIT_SHIFT_KEYCAM_CLEAR                       30
#define BIT_KEYCAM_CLEAR                             ((u32)0x00000001 << BIT_SHIFT_KEYCAM_CLEAR)                       /*!<W 0  Set to 1 to clear all valid bits in CAM. After reset will self clear to 0. */
#define BIT_SHIFT_MFBCAM_CLEAR                       29
#define BIT_MFBCAM_CLEAR                             ((u32)0x00000001 << BIT_SHIFT_MFBCAM_CLEAR)                       /*!<W 0  Write 1 to clear all MFB value in CAM to 7'h7F. After reset will self clear to 0 */
#define BIT_SHIFT_KEYCAM_DA_EN                       17
#define BIT_KEYCAM_DA_EN                             ((u32)0x00000001 << BIT_SHIFT_KEYCAM_DA_EN)                       /*!<R/W 0  Security CAM Direct Acess Enable */
#define BIT_SHIFT_SECCAM_WE                          16
#define BIT_SECCAM_WE                                ((u32)0x00000001 << BIT_SHIFT_SECCAM_WE)                          /*!<R/W 0  Security CAM Write Enable */
#define BIT_SHIFT_KEYCAM_AD                          0
#define BIT_MASK_KEYCAM_AD                           ((u32)0x000003FF << BIT_SHIFT_KEYCAM_AD)                          /*!<R/W 0  Security CAM Address Offset CAM address is organized into 8 double-words/entry. */

/* REG_KEYCAM_WD 0x0674 */
#define BIT_SHIFT_KEYCAM_WDATA                       0
#define BIT_MASK_KEYCAM_WDATA                        ((u32)0xFFFFFFFF << BIT_SHIFT_KEYCAM_WDATA)                       /*!<R/W 0  Security CAM Write Content */

/* REG_CAMREAD 0x0678 */
#define BIT_SHIFT_CAMR_DATA                          0
#define BIT_MASK_CAMR_DATA                           ((u32)0xFFFFFFFF << BIT_SHIFT_CAMR_DATA)                          /*!<R/W 0  Security CAM Read Content */

/* REG_CAMDBG 0x067C */
#define BIT_SHIFT_KEYCAM_DBGSEL                      31
#define BIT_KEYCAM_DBGSEL                            ((u32)0x00000001 << BIT_SHIFT_KEYCAM_DBGSEL)                      /*!<R/W 0  Select TX/RX CAM Information. Set to 1 to retrieve latest Tx search result. Set to 0 to retrieve latest Rx search result. */
#define BIT_SHIFT_SEC_KEYFOUND_V1                    15
#define BIT_SEC_KEYFOUND_V1                          ((u32)0x00000001 << BIT_SHIFT_SEC_KEYFOUND_V1)                    /*!<R 0  Security Key Found in CAM 0: key not found 1: key found */
#define BIT_SHIFT_CAMDBG_SEC_TYPE_V1                 12
#define BIT_MASK_CAMDBG_SEC_TYPE_V1                  ((u32)0x00000007 << BIT_SHIFT_CAMDBG_SEC_TYPE_V1)                 /*!<R 0  Found security key type */
#define BIT_SHIFT_EXT_SECTYPE                        11
#define BIT_EXT_SECTYPE                              ((u32)0x00000001 << BIT_SHIFT_EXT_SECTYPE)                        /*!<R 0  Found security key ext_sectype */
#define BIT_SHIFT_CAMDBG_MIC_KEY_IDX_V3              5
#define BIT_MASK_CAMDBG_MIC_KEY_IDX_V3               ((u32)0x0000001F << BIT_SHIFT_CAMDBG_MIC_KEY_IDX_V3)              /*!<R 0  Mic KEY INDEX */
#define BIT_SHIFT_CAMDBG_SEC_KEY_IDX_V2              0
#define BIT_MASK_CAMDBG_SEC_KEY_IDX_V2               ((u32)0x0000001F << BIT_SHIFT_CAMDBG_SEC_KEY_IDX_V2)              /*!<R 0  Security KEY INDEX */

/* REG_SECCFG 0x0680 */
#define BIT_SHIFT_DIS_GCLK_WAPI                      15
#define BIT_DIS_GCLK_WAPI                            ((u32)0x00000001 << BIT_SHIFT_DIS_GCLK_WAPI)                      /*!<R/W 0  Disable gated clock control for WAPI engine */
#define BIT_SHIFT_DIS_GCLK_AES                       14
#define BIT_DIS_GCLK_AES                             ((u32)0x00000001 << BIT_SHIFT_DIS_GCLK_AES)                       /*!<R/W 0  Disable gated clock control for AES engine. */
#define BIT_SHIFT_DIS_GCLK_TKIP                      13
#define BIT_DIS_GCLK_TKIP                            ((u32)0x00000001 << BIT_SHIFT_DIS_GCLK_TKIP)                      /*!<R/W 0  not used */
#define BIT_SHIFT_AES_SEL_QC_1                       12
#define BIT_AES_SEL_QC_1                             ((u32)0x00000001 << BIT_SHIFT_AES_SEL_QC_1)                       /*!<R/W 0  1: use QC[7] to compute mic 0: not use QC[7] to compute mic */
#define BIT_SHIFT_AES_SEL_QC_0                       11
#define BIT_AES_SEL_QC_0                             ((u32)0x00000001 << BIT_SHIFT_AES_SEL_QC_0)                       /*!<R/W 0  1:use QC[7] to compute ctr 0: not use QC[7] to compute ctr */
#define BIT_SHIFT_WMAC_CKECK_BMC                     9
#define BIT_WMAC_CKECK_BMC                           ((u32)0x00000001 << BIT_SHIFT_WMAC_CKECK_BMC)                     /*!<R/W 0  If this bit is set to 1, key search engine need to check if broadcast/multicast bit matched. */
#define BIT_SHIFT_CHK_KEYID                          8
#define BIT_CHK_KEYID                                ((u32)0x00000001 << BIT_SHIFT_CHK_KEYID)                          /*!<R/W 0  If this bit is set to 1, key search engine need to check if key ID matched. If this bit is set to 0, then key ID table must be filled with 2?b00. */
#define BIT_SHIFT_RXBCUSEDK                          7
#define BIT_RXBCUSEDK                                ((u32)0x00000001 << BIT_SHIFT_RXBCUSEDK)                          /*!<R/W 0  Force RX Broadcast packets Use Default Key If this bit is set to 1, use default key for RX key search when received packet is broadcast and multicast. */
#define BIT_SHIFT_TXBCUSEDK                          6
#define BIT_TXBCUSEDK                                ((u32)0x00000001 << BIT_SHIFT_TXBCUSEDK)                          /*!<R/W 0  Force Tx Broadcast packets Use Default Key If this bit is set to 1, use default key for TX key search when transmitted packet is broadcast and multicast. */
#define BIT_SHIFT_NOSKMC                             5
#define BIT_NOSKMC                                   ((u32)0x00000001 << BIT_SHIFT_NOSKMC)                             /*!<R/W 0  No Key Search for Multicast Setting 1 to disable key search for multicast frames. Used in MBSSID AP mode. Software should manage security encryption and decryption. */
#define BIT_SHIFT_SKBYA2                             4
#define BIT_SKBYA2                                   ((u32)0x00000001 << BIT_SHIFT_SKBYA2)                             /*!<R/W 0  Search Key by A2 Setting 1 to search security CAM by address 2 for TX and search CAM by address 1 for RX. Setting 0 to search security CAM by address 1 for TX and search CAM by address 2 for RX. Used in MBSSID client mode. */
#define BIT_SHIFT_RXDEC                              3
#define BIT_RXDEC                                    ((u32)0x00000001 << BIT_SHIFT_RXDEC)                              /*!<R/W 1  Enable Rx Decryption Setting 1 to enable Rx hardware decryption. */
#define BIT_SHIFT_TXENC                              2
#define BIT_TXENC                                    ((u32)0x00000001 << BIT_SHIFT_TXENC)                              /*!<R/W 1  Enable Tx Encryption Setting to 1 to enable Tx hardware encryption. */
#define BIT_SHIFT_RXUHUSEDK                          1
#define BIT_RXUHUSEDK                                ((u32)0x00000001 << BIT_SHIFT_RXUHUSEDK)                          /*!<R/W 0  Force RX Unicast Use Default Key If this bit is set to 1, use default key for RX key search when pairwise key is not found. */
#define BIT_SHIFT_TXUHUSEDK                          0
#define BIT_TXUHUSEDK                                ((u32)0x00000001 << BIT_SHIFT_TXUHUSEDK)                          /*!<R/W 0  Force Tx Unicast Use Default Key If this bit is set to 1, use default key for TX key search when pairwise key is not found. */

/* REG_RXFILTER_CATEGORY 0x0682 */
#define BIT_SHIFT_RXFILTER_CATEGORY_1                0
#define BIT_MASK_RXFILTER_CATEGORY_1                 ((u32)0x000000FF << BIT_SHIFT_RXFILTER_CATEGORY_1)                /*!<R/W 0  Configured by FW, Refer to 0x68E[10] to decide accepting this frame or not */

/* REG_RXFILTER_ACTION 0x0683 */
#define BIT_SHIFT_RXFILTER_ACTION_1                  0
#define BIT_MASK_RXFILTER_ACTION_1                   ((u32)0x000000FF << BIT_SHIFT_RXFILTER_ACTION_1)                  /*!<R/W 0x0  Configured by FW, Refer to 0x68E[10] to decide accepting this frame or not */

/* REG_RXFILTER_CATEGORY_ACTION 0x0684 */
#define BIT_SHIFT_RXFILTER_ACTION_3                  24
#define BIT_MASK_RXFILTER_ACTION_3                   ((u32)0x000000FF << BIT_SHIFT_RXFILTER_ACTION_3)                  /*!<R/W 0x0  Configured by FW, Refer to 0x68E[15] to decide accepting this frame or not */
#define BIT_SHIFT_RXFILTER_CATEGORY_3                16
#define BIT_MASK_RXFILTER_CATEGORY_3                 ((u32)0x000000FF << BIT_SHIFT_RXFILTER_CATEGORY_3)                /*!<R/W 0x0  Configured by FW, Refer to 0x68E[15] to decide accepting this frame or not */
#define BIT_SHIFT_RXFILTER_ACTION_2                  8
#define BIT_MASK_RXFILTER_ACTION_2                   ((u32)0x000000FF << BIT_SHIFT_RXFILTER_ACTION_2)                  /*!<R/W 0x0  Configured by FW, Refer to 0x68E[11] to decide accepting this frame or not */
#define BIT_SHIFT_RXFILTER_CATEGORY_2                0
#define BIT_MASK_RXFILTER_CATEGORY_2                 ((u32)0x000000FF << BIT_SHIFT_RXFILTER_CATEGORY_2)                /*!<R/W 0x0  Configured by FW, Refer to 0x68E[11] to decide accepting this frame or not */

/* REG_RXFLTMAP3 0x0688 */
#define BIT_SHIFT_MGTFLT15EN_FW                      15
#define BIT_MGTFLT15EN_FW                            ((u32)0x00000001 << BIT_SHIFT_MGTFLT15EN_FW)                      /*!<R/W 0  When set, frames with type=00 and subtype=1111 are received into FWFF. */
#define BIT_SHIFT_MGTFLT14EN_FW                      14
#define BIT_MGTFLT14EN_FW                            ((u32)0x00000001 << BIT_SHIFT_MGTFLT14EN_FW)                      /*!<R/W 0  When set, all the frames with type=00 and subtype=1110 are received into FWFF. When set to 0, refer to 0x68E[15:12] for deciding which action noack frames will be accepted */
#define BIT_SHIFT_MGTFLT13EN_FW                      13
#define BIT_MGTFLT13EN_FW                            ((u32)0x00000001 << BIT_SHIFT_MGTFLT13EN_FW)                      /*!<R/W 0  When set, all the frames with type=00 and subtype=1101 are received into FWFF. When set to 0, refer to 0x68E[11:0] for deciding which action frames will be accepted */
#define BIT_SHIFT_MGTFLT12EN_FW                      12
#define BIT_MGTFLT12EN_FW                            ((u32)0x00000001 << BIT_SHIFT_MGTFLT12EN_FW)                      /*!<R/W 0  When set, frames with type=00 and subtype=1100 are received into FWFF. */
#define BIT_SHIFT_MGTFLT11EN_FW                      11
#define BIT_MGTFLT11EN_FW                            ((u32)0x00000001 << BIT_SHIFT_MGTFLT11EN_FW)                      /*!<R/W 0  When set, frames with type=00 and subtype=1011 are received into FWFF. */
#define BIT_SHIFT_MGTFLT10EN_FW                      10
#define BIT_MGTFLT10EN_FW                            ((u32)0x00000001 << BIT_SHIFT_MGTFLT10EN_FW)                      /*!<R/W 0  When set, frames with type=00 and subtype=1010 are received into FWFF. */
#define BIT_SHIFT_MGTFLT9EN_FW                       9
#define BIT_MGTFLT9EN_FW                             ((u32)0x00000001 << BIT_SHIFT_MGTFLT9EN_FW)                       /*!<R/W 0  When set, frames with type=00 and subtype=1001 are received into FWFF. */
#define BIT_SHIFT_MGTFLT8EN_FW                       8
#define BIT_MGTFLT8EN_FW                             ((u32)0x00000001 << BIT_SHIFT_MGTFLT8EN_FW)                       /*!<R/W 0  When set, frames with type=00 and subtype=1000 are received into FWFF. */
#define BIT_SHIFT_MGTFLT7EN_FW                       7
#define BIT_MGTFLT7EN_FW                             ((u32)0x00000001 << BIT_SHIFT_MGTFLT7EN_FW)                       /*!<R/W 0  When set, frames with type=00 and subtype=0111 are received into FWFF. */
#define BIT_SHIFT_MGTFLT6EN_FW                       6
#define BIT_MGTFLT6EN_FW                             ((u32)0x00000001 << BIT_SHIFT_MGTFLT6EN_FW)                       /*!<R/W 0  When set, frames with type=00 and subtype=0110 are received into FWFF. */
#define BIT_SHIFT_MGTFLT5EN_FW                       5
#define BIT_MGTFLT5EN_FW                             ((u32)0x00000001 << BIT_SHIFT_MGTFLT5EN_FW)                       /*!<R/W 0  When set, frames with type=00 and subtype=0101 are received into FWFF. */
#define BIT_SHIFT_MGTFLT4EN_FW                       4
#define BIT_MGTFLT4EN_FW                             ((u32)0x00000001 << BIT_SHIFT_MGTFLT4EN_FW)                       /*!<R/W 0  When set, frames with type=00 and subtype=0100 are received into FWFF. */
#define BIT_SHIFT_MGTFLT3EN_FW                       3
#define BIT_MGTFLT3EN_FW                             ((u32)0x00000001 << BIT_SHIFT_MGTFLT3EN_FW)                       /*!<R/W 0  When set, frames with type=00 and subtype=0011 are received into FWFF. */
#define BIT_SHIFT_MGTFLT2EN_FW                       2
#define BIT_MGTFLT2EN_FW                             ((u32)0x00000001 << BIT_SHIFT_MGTFLT2EN_FW)                       /*!<R/W 0  When set, frames with type=00 and subtype=0010 are received into FWFF. */
#define BIT_SHIFT_MGTFLT1EN_FW                       1
#define BIT_MGTFLT1EN_FW                             ((u32)0x00000001 << BIT_SHIFT_MGTFLT1EN_FW)                       /*!<R/W 0  When set, frames with type=00 and subtype=0001 are received into FWFF. */
#define BIT_SHIFT_MGTFLT0EN_FW                       0
#define BIT_MGTFLT0EN_FW                             ((u32)0x00000001 << BIT_SHIFT_MGTFLT0EN_FW)                       /*!<R/W 0  When set, frames with type=00 and subtype=0000 are received into FWFF. */

/* REG_RXFLTMAP4 0x068A */
#define BIT_SHIFT_CTRLFLT15EN_FW                     15
#define BIT_CTRLFLT15EN_FW                           ((u32)0x00000001 << BIT_SHIFT_CTRLFLT15EN_FW)                     /*!<R/W 0  When set, frames with type=01 and subtype=1111 are received into FWFF. */
#define BIT_SHIFT_CTRLFLT14EN_FW                     14
#define BIT_CTRLFLT14EN_FW                           ((u32)0x00000001 << BIT_SHIFT_CTRLFLT14EN_FW)                     /*!<R/W 0  When set, frames with type=01 and subtype=1110 are received into FWFF. */
#define BIT_SHIFT_CTRLFLT13EN_FW                     13
#define BIT_CTRLFLT13EN_FW                           ((u32)0x00000001 << BIT_SHIFT_CTRLFLT13EN_FW)                     /*!<R/W 0  When set, frames with type=01 and subtype=1101 are received into FWFF. */
#define BIT_SHIFT_CTRLFLT12EN_FW                     12
#define BIT_CTRLFLT12EN_FW                           ((u32)0x00000001 << BIT_SHIFT_CTRLFLT12EN_FW)                     /*!<R/W 0  When set, frames with type=01 and subtype=1100 are received into FWFF. */
#define BIT_SHIFT_CTRLFLT11EN_FW                     11
#define BIT_CTRLFLT11EN_FW                           ((u32)0x00000001 << BIT_SHIFT_CTRLFLT11EN_FW)                     /*!<R/W 0  When set, frames with type=01 and subtype=1011 are received into FWFF. */
#define BIT_SHIFT_CTRLFLT10EN_FW                     10
#define BIT_CTRLFLT10EN_FW                           ((u32)0x00000001 << BIT_SHIFT_CTRLFLT10EN_FW)                     /*!<R/W 0  When set, frames with type=01 and subtype=1010 are received into FWFF. */
#define BIT_SHIFT_CTRLFLT9EN_FW                      9
#define BIT_CTRLFLT9EN_FW                            ((u32)0x00000001 << BIT_SHIFT_CTRLFLT9EN_FW)                      /*!<R/W 0  When set, frames with type=01 and subtype=1001 are received into FWFF. */
#define BIT_SHIFT_CTRLFLT8EN_FW                      8
#define BIT_CTRLFLT8EN_FW                            ((u32)0x00000001 << BIT_SHIFT_CTRLFLT8EN_FW)                      /*!<R/W 0  When set, frames with type=01 and subtype=1000 are received into FWFF. */
#define BIT_SHIFT_CTRLFLT7EN_FW                      7
#define BIT_CTRLFLT7EN_FW                            ((u32)0x00000001 << BIT_SHIFT_CTRLFLT7EN_FW)                      /*!<R/W 0  When set, frames with type=01 and subtype=0111 are received into FWFF. */
#define BIT_SHIFT_CTRLFLT6EN_FW                      6
#define BIT_CTRLFLT6EN_FW                            ((u32)0x00000001 << BIT_SHIFT_CTRLFLT6EN_FW)                      /*!<R/W 0  When set, frames with type=01 and subtype=0110 are received into FWFF. */
#define BIT_SHIFT_CTRLFLT5EN_FW                      5
#define BIT_CTRLFLT5EN_FW                            ((u32)0x00000001 << BIT_SHIFT_CTRLFLT5EN_FW)                      /*!<R/W 0  When set, frames with type=01 and subtype=0101 are received into FWFF. */
#define BIT_SHIFT_CTRLFLT4EN_FW                      4
#define BIT_CTRLFLT4EN_FW                            ((u32)0x00000001 << BIT_SHIFT_CTRLFLT4EN_FW)                      /*!<R/W 0  When set, frames with type=01 and subtype=0100 are received into FWFF. */
#define BIT_SHIFT_CTRLFLT3EN_FW                      3
#define BIT_CTRLFLT3EN_FW                            ((u32)0x00000001 << BIT_SHIFT_CTRLFLT3EN_FW)                      /*!<R/W 0  When set, frames with type=01 and subtype=0011 are received into FWFF. */
#define BIT_SHIFT_CTRLFLT2EN_FW                      2
#define BIT_CTRLFLT2EN_FW                            ((u32)0x00000001 << BIT_SHIFT_CTRLFLT2EN_FW)                      /*!<R/W 0  When set, frames with type=01 and subtype=0010 are received into FWFF. */
#define BIT_SHIFT_CTRLFLT1EN_FW                      1
#define BIT_CTRLFLT1EN_FW                            ((u32)0x00000001 << BIT_SHIFT_CTRLFLT1EN_FW)                      /*!<R/W 0  When set, frames with type=01 and subtype=0001 are received into FWFF. */
#define BIT_SHIFT_CTRLFLT0EN_FW                      0
#define BIT_CTRLFLT0EN_FW                            ((u32)0x00000001 << BIT_SHIFT_CTRLFLT0EN_FW)                      /*!<R/W 0  When set, frames with type=01 and subtype=0000 are received into FWFF. */

/* REG_RXFLTMAP5 0x068C */
#define BIT_SHIFT_DATAFLT15EN_FW                     15
#define BIT_DATAFLT15EN_FW                           ((u32)0x00000001 << BIT_SHIFT_DATAFLT15EN_FW)                     /*!<R/W 0  When set, frames with type=10 and subtype=1111 are received into FWFF. */
#define BIT_SHIFT_DATAFLT14EN_FW                     14
#define BIT_DATAFLT14EN_FW                           ((u32)0x00000001 << BIT_SHIFT_DATAFLT14EN_FW)                     /*!<R/W 0  When set, frames with type=10 and subtype=1110 are received into FWFF. */
#define BIT_SHIFT_DATAFLT13EN_FW                     13
#define BIT_DATAFLT13EN_FW                           ((u32)0x00000001 << BIT_SHIFT_DATAFLT13EN_FW)                     /*!<R/W 0  When set, frames with type=10 and subtype=1101 are received into FWFF. */
#define BIT_SHIFT_DATAFLT12EN_FW                     12
#define BIT_DATAFLT12EN_FW                           ((u32)0x00000001 << BIT_SHIFT_DATAFLT12EN_FW)                     /*!<R/W 0  When set, frames with type=10 and subtype=1100 are received into FWFF. */
#define BIT_SHIFT_DATAFLT11EN_FW                     11
#define BIT_DATAFLT11EN_FW                           ((u32)0x00000001 << BIT_SHIFT_DATAFLT11EN_FW)                     /*!<R/W 0  When set, frames with type=10 and subtype=1011 are received into FWFF. */
#define BIT_SHIFT_DATAFLT10EN_FW                     10
#define BIT_DATAFLT10EN_FW                           ((u32)0x00000001 << BIT_SHIFT_DATAFLT10EN_FW)                     /*!<R/W 0  When set, frames with type=10 and subtype=1010 are received into FWFF. */
#define BIT_SHIFT_DATAFLT9EN_FW                      9
#define BIT_DATAFLT9EN_FW                            ((u32)0x00000001 << BIT_SHIFT_DATAFLT9EN_FW)                      /*!<R/W 0  When set, frames with type=10 and subtype=1001 are received into FWFF. */
#define BIT_SHIFT_DATAFLT8EN_FW                      8
#define BIT_DATAFLT8EN_FW                            ((u32)0x00000001 << BIT_SHIFT_DATAFLT8EN_FW)                      /*!<R/W 0  When set, frames with type=10 and subtype=1000 are received into FWFF. */
#define BIT_SHIFT_DATAFLT7EN_FW                      7
#define BIT_DATAFLT7EN_FW                            ((u32)0x00000001 << BIT_SHIFT_DATAFLT7EN_FW)                      /*!<R/W 0  When set, frames with type=10 and subtype=0111 are received into FWFF. */
#define BIT_SHIFT_DATAFLT6EN_FW                      6
#define BIT_DATAFLT6EN_FW                            ((u32)0x00000001 << BIT_SHIFT_DATAFLT6EN_FW)                      /*!<R/W 0  When set, frames with type=10 and subtype=0110 are received into FWFF. */
#define BIT_SHIFT_DATAFLT5EN_FW                      5
#define BIT_DATAFLT5EN_FW                            ((u32)0x00000001 << BIT_SHIFT_DATAFLT5EN_FW)                      /*!<R/W 0  When set, frames with type=10 and subtype=0101 are received into FWFF. */
#define BIT_SHIFT_DATAFLT4EN_FW                      4
#define BIT_DATAFLT4EN_FW                            ((u32)0x00000001 << BIT_SHIFT_DATAFLT4EN_FW)                      /*!<R/W 0  When set, frames with type=10 and subtype=0100 are received into FWFF. */
#define BIT_SHIFT_DATAFLT3EN_FW                      3
#define BIT_DATAFLT3EN_FW                            ((u32)0x00000001 << BIT_SHIFT_DATAFLT3EN_FW)                      /*!<R/W 0  When set, frames with type=10 and subtype=0011 are received into FWFF. */
#define BIT_SHIFT_DATAFLT2EN_FW                      2
#define BIT_DATAFLT2EN_FW                            ((u32)0x00000001 << BIT_SHIFT_DATAFLT2EN_FW)                      /*!<R/W 0  When set, frames with type=10 and subtype=0010 are received into FWFF. */
#define BIT_SHIFT_DATAFLT1EN_FW                      1
#define BIT_DATAFLT1EN_FW                            ((u32)0x00000001 << BIT_SHIFT_DATAFLT1EN_FW)                      /*!<R/W 0  When set, frames with type=10 and subtype=0001 are received into FWFF. */
#define BIT_SHIFT_DATAFLT0EN_FW                      0
#define BIT_DATAFLT0EN_FW                            ((u32)0x00000001 << BIT_SHIFT_DATAFLT0EN_FW)                      /*!<R/W 0  When set, frames with type=10 and subtype=0000 are received into FWFF. */

/* REG_RXFLTMAP6 0x068E */
#define BIT_SHIFT_ACTIONFLT15EN_FW                   15
#define BIT_ACTIONFLT15EN_FW                         ((u32)0x00000001 << BIT_SHIFT_ACTIONFLT15EN_FW)                   /*!<R/W 0  When set, Action noack frame with category = r_RXFILTER_CATEGORY_3(0x686[7:0]) and action = r_RXFILTER_ACTION_3(0x687[7:0]) will be received into FWFF */
#define BIT_SHIFT_ACTIONFLT14EN_FW                   14
#define BIT_ACTIONFLT14EN_FW                         ((u32)0x00000001 << BIT_SHIFT_ACTIONFLT14EN_FW)                   /*!<R/W 0  When set, VHT compressed beamforming frame will be received into FWFF. */
#define BIT_SHIFT_ACTIONFLT13EN_FW                   13
#define BIT_ACTIONFLT13EN_FW                         ((u32)0x00000001 << BIT_SHIFT_ACTIONFLT13EN_FW)                   /*!<R/W 0  When set, HT compressed beamforming frame will be received into FWFF. */
#define BIT_SHIFT_ACTIONFLT12EN_FW                   12
#define BIT_ACTIONFLT12EN_FW                         ((u32)0x00000001 << BIT_SHIFT_ACTIONFLT12EN_FW)                   /*!<R/W 0  When set, CSI frame will be received into FWFF. */
#define BIT_SHIFT_ACTIONFLT11EN_FW                   11
#define BIT_ACTIONFLT11EN_FW                         ((u32)0x00000001 << BIT_SHIFT_ACTIONFLT11EN_FW)                   /*!<R/W 0  When set, Action frame with category = r_RXFILTER_CATEGORY_2(0x684[7:0]) and action = r_RXFILTER_ACTION_2(0x685[7:0]) will be received into FWFF */
#define BIT_SHIFT_ACTIONFLT10EN_FW                   10
#define BIT_ACTIONFLT10EN_FW                         ((u32)0x00000001 << BIT_SHIFT_ACTIONFLT10EN_FW)                   /*!<R/W 0  When set, Action frame with category = r_RXFILTER_CATEGORY_1(0x682[7:0]) and action = r_RXFILTER_ACTION_1(0x683[7:0]) will be received into FWFF */
#define BIT_SHIFT_ACTIONFLT9EN_FW                    9
#define BIT_ACTIONFLT9EN_FW                          ((u32)0x00000001 << BIT_SHIFT_ACTIONFLT9EN_FW)                    /*!<R/W 0  When set, Operating mode notification frame will be received into FWFF. */
#define BIT_SHIFT_ACTIONFLT8EN_FW                    8
#define BIT_ACTIONFLT8EN_FW                          ((u32)0x00000001 << BIT_SHIFT_ACTIONFLT8EN_FW)                    /*!<R/W 0  When set, Group ID Management frame will be received into FWFF. */
#define BIT_SHIFT_ACTIONFLT7EN_FW                    7
#define BIT_ACTIONFLT7EN_FW                          ((u32)0x00000001 << BIT_SHIFT_ACTIONFLT7EN_FW)                    /*!<R/W 0  When set, Notify channel width frame will be received into FWFF. */
#define BIT_SHIFT_ACTIONFLT6EN_FW                    6
#define BIT_ACTIONFLT6EN_FW                          ((u32)0x00000001 << BIT_SHIFT_ACTIONFLT6EN_FW)                    /*!<R/W 0  When set, DELBA frame will be received into FWFF. */
#define BIT_SHIFT_ACTIONFLT5EN_FW                    5
#define BIT_ACTIONFLT5EN_FW                          ((u32)0x00000001 << BIT_SHIFT_ACTIONFLT5EN_FW)                    /*!<R/W 0  When set, ADDBA Response frame will be received into FWFF. */
#define BIT_SHIFT_ACTIONFLT4EN_FW                    4
#define BIT_ACTIONFLT4EN_FW                          ((u32)0x00000001 << BIT_SHIFT_ACTIONFLT4EN_FW)                    /*!<R/W 0  When set, ADDBA Request frame will be received into FWFF. */
#define BIT_SHIFT_ACTIONFLT3EN_FW                    3
#define BIT_ACTIONFLT3EN_FW                          ((u32)0x00000001 << BIT_SHIFT_ACTIONFLT3EN_FW)                    /*!<R/W 0  When set, DELTS frame will be received into FWFF. */
#define BIT_SHIFT_ACTIONFLT2EN_FW                    2
#define BIT_ACTIONFLT2EN_FW                          ((u32)0x00000001 << BIT_SHIFT_ACTIONFLT2EN_FW)                    /*!<R/W 0  When set, ADDTS Response frame will be received into FWFF. */
#define BIT_SHIFT_ACTIONFLT1EN_FW                    1
#define BIT_ACTIONFLT1EN_FW                          ((u32)0x00000001 << BIT_SHIFT_ACTIONFLT1EN_FW)                    /*!<R/W 0  When set, ADDTS Request frame will be received into FWFF. */
#define BIT_SHIFT_ACTIONFLT0EN_FW                    0
#define BIT_ACTIONFLT0EN_FW                          ((u32)0x00000001 << BIT_SHIFT_ACTIONFLT0EN_FW)                    /*!<R/W 0  When set, Channel Switch Announcement frame will be received into FWFF. */

/* REG_WOW_CTRL 0x0690 */
#define BIT_SHIFT_PSF_BSSIDSEL_H                     6
#define BIT_MASK_PSF_BSSIDSEL_H                      ((u32)0x00000003 << BIT_SHIFT_PSF_BSSIDSEL_H)                     /*!<R/W 0  Bit 1,2 of Select to check the MACID of which port for the WMAC PSF NSARP function. 0: to check the MACID of port0; 1: to check the MACID of port1. 2: to check the MACID of port2. 3: to check the MACID of port3. 4: to check the MACID of port4. */
#define BIT_SHIFT_WOWHCI                             5
#define BIT_WOWHCI                                   ((u32)0x00000001 << BIT_SHIFT_WOWHCI)                             /*!<R/W 0  This bit is set to allow wake host as wake on wlan event occurring */
#define BIT_SHIFT_PSF_BSSIDSEL_L                     4
#define BIT_PSF_BSSIDSEL_L                           ((u32)0x00000001 << BIT_SHIFT_PSF_BSSIDSEL_L)                     /*!<R/W 0  Bit 0 of Select to check the MACID of which port for the WMAC PSF NSARP function. 0: to check the MACID of port0; 1: to check the MACID of port1. 2: to check the MACID of port2. 3: to check the MACID of port3. 4: to check the MACID of port4. */
#define BIT_SHIFT_UWF                                3
#define BIT_UWF                                      ((u32)0x00000001 << BIT_SHIFT_UWF)                                /*!<R/W 0  Unicast Packet. 1: Enable to check packet?s DA match MAC address or not. 0: Disable. (default value) */
#define BIT_SHIFT_MAGIC                              2
#define BIT_MAGIC                                    ((u32)0x00000001 << BIT_SHIFT_MAGIC)                              /*!<R/W 0  Magic Packet. This bit is valid when the PMEn bit of the PMR register is set. The RTL8192 will assert the PMEB signal to wakeup the operating system when a Magic Packet is received. Once the RTL8192 has been enabled for Magic Packet wakeup, it scans incoming packets addressed to the node for a data sequence. The correct sequence indicates to the controller that this is a Magic Packet frame. A Magic Packet frame must also meet the basic requirements: Frame Control + Duration/ID + Destination address + Address 2 + Address 3 + Sequence Control + data + CRC. The destination address may be the node ID of the receiving station or a multicast address, including the broadcast address. The specific sequence consists of 16 duplications of 6 byte ID registers, with no breaks or interrupts. This sequence can be located anywhere within the packet, but must be preceded by a synchronization stream, 6 bytes of FFh. The device will also accept a multicast address, as long as the 16 duplications of the IEEE address match the address of the ID registers. If the Node ID is 11h 22h 33h 44h 55h 66h, then the magic frame?s format is as follows: Frame Control + Duration/ID + Destination address + Address 2 + Address 3 + Sequence Control + MISC + FF FF FF FF FF FF + MISC + 11 22 33 44 55 66 + 11 22 33 44 55 66 + 11 22 33 44 55 66 + 11 22 33 44 55 66 + 11 22 33 44 55 66 + 11 22 33 44 55 66 + 11 22 33 44 55 66 + 11 22 33 44 55 66 + 11 22 33 44 55 66 + 11 22 33 44 55 66 + 11 22 33 44 55 66 + 11 22 33 44 55 66 + 11 22 33 44 55 66 + 11 22 33 44 55 66 + 11 22 33 44 55 66 + 11 22 33 44 55 66 + MISC + CRC. */
#define BIT_SHIFT_WFMSK                              1
#define BIT_WFMSK                                    ((u32)0x00000001 << BIT_SHIFT_WFMSK)                              /*!<R/W 0  WoW function on or off. */

/* REG_NAN_RX_FILTER 0x0691 */
#define BIT_SHIFT_NAN_RX_CHKTA                       2
#define BIT_NAN_RX_CHKTA                             ((u32)0x00000001 << BIT_SHIFT_NAN_RX_CHKTA)                       /*!<R/W 0  Enable bit for check TSF filter When set to 1, the TSF address filter will enable. When set to 0, the TSF address filter will disable. */
#define BIT_SHIFT_NAN_RX_CHKBSSID                    1
#define BIT_NAN_RX_CHKBSSID                          ((u32)0x00000001 << BIT_SHIFT_NAN_RX_CHKBSSID)                    /*!<R/W 0  Check BSSID_BCN for TSF When set to 1, MAC will check the BSSID (A3) of RX beacon or Probe to determine if this packet will sync TSF or not */
#define BIT_SHIFT_NAN_RX_FILTER_EN                   0
#define BIT_NAN_RX_FILTER_EN                         ((u32)0x00000001 << BIT_SHIFT_NAN_RX_FILTER_EN)                   /*!<R/W 0  When set to 1, the TSF address filter will enable. When set to 0, the TSF address filter will disable. */

/* REG_PS_RX_INFO 0x0692 */
#define BIT_SHIFT_PORTSEL_PS_RX_INFO                 5
#define BIT_MASK_PORTSEL_PS_RX_INFO                  ((u32)0x00000007 << BIT_SHIFT_PORTSEL_PS_RX_INFO)                 /*!<R/W 0  The selector for the source of PS RX information (0x692[4:0]). 0 for port 0, 1 for clint0, 2 for clint1, 3 for clint2, 4 for clint3. */
#define BIT_SHIFT_RXCTRLIN0                          4
#define BIT_RXCTRLIN0                                ((u32)0x00000001 << BIT_SHIFT_RXCTRLIN0)                          /*!<R/W 0  It is set to 1 if NIC received control frame with correct DA. */
#define BIT_SHIFT_RXMGTIN0                           3
#define BIT_RXMGTIN0                                 ((u32)0x00000001 << BIT_SHIFT_RXMGTIN0)                           /*!<R/W 0  It is set to 1 if NIC received management frame with correct BSSID and DA (including unicast and BMC). */
#define BIT_SHIFT_RXDATAIN2                          2
#define BIT_RXDATAIN2                                ((u32)0x00000001 << BIT_SHIFT_RXDATAIN2)                          /*!<R/W 0  It is set to 1 if NIC received data frame with correct BSSID and DA (including unicast and BMC). */
#define BIT_SHIFT_RXDATAIN1                          1
#define BIT_RXDATAIN1                                ((u32)0x00000001 << BIT_SHIFT_RXDATAIN1)                          /*!<R/W 0  It is set to 1 if NIC received data frame with correct BSSID and DA (including unicast and BMC). */
#define BIT_SHIFT_RXDATAIN0                          0
#define BIT_RXDATAIN0                                ((u32)0x00000001 << BIT_SHIFT_RXDATAIN0)                          /*!<R/W 0  It is set to 1 if NIC received data frame with correct BSSID and DA (including unicast and BMC). */

/* REG_WMMPS_UAPSD_TID 0x0693 */
#define BIT_SHIFT_WMMPS_UAPSD_TID7                   7
#define BIT_WMMPS_UAPSD_TID7                         ((u32)0x00000001 << BIT_SHIFT_WMMPS_UAPSD_TID7)                   /*!<R/W 0  Disable interrupt 8051 when rx WMMPS UAPSD Qos data with TID7 */
#define BIT_SHIFT_WMMPS_UAPSD_TID6                   6
#define BIT_WMMPS_UAPSD_TID6                         ((u32)0x00000001 << BIT_SHIFT_WMMPS_UAPSD_TID6)                   /*!<R/W 0  Disable interrupt 8051 when rx WMMPS UAPSD Qos data with TID6 */
#define BIT_SHIFT_WMMPS_UAPSD_TID5                   5
#define BIT_WMMPS_UAPSD_TID5                         ((u32)0x00000001 << BIT_SHIFT_WMMPS_UAPSD_TID5)                   /*!<R/W 0  Disable interrupt 8051 when rx WMMPS UAPSD Qos data with TID5 */
#define BIT_SHIFT_WMMPS_UAPSD_TID4                   4
#define BIT_WMMPS_UAPSD_TID4                         ((u32)0x00000001 << BIT_SHIFT_WMMPS_UAPSD_TID4)                   /*!<R/W 0  Disable interrupt 8051 when rx WMMPS UAPSD Qos data with TID4 */
#define BIT_SHIFT_WMMPS_UAPSD_TID3                   3
#define BIT_WMMPS_UAPSD_TID3                         ((u32)0x00000001 << BIT_SHIFT_WMMPS_UAPSD_TID3)                   /*!<R/W 0  Disable interrupt 8051 when rx WMMPS UAPSD Qos data with TID3 */
#define BIT_SHIFT_WMMPS_UAPSD_TID2                   2
#define BIT_WMMPS_UAPSD_TID2                         ((u32)0x00000001 << BIT_SHIFT_WMMPS_UAPSD_TID2)                   /*!<R/W 0  Disable interrupt 8051 when rx WMMPS UAPSD Qos data with TID2 */
#define BIT_SHIFT_WMMPS_UAPSD_TID1                   1
#define BIT_WMMPS_UAPSD_TID1                         ((u32)0x00000001 << BIT_SHIFT_WMMPS_UAPSD_TID1)                   /*!<R/W 0  Disable interrupt 8051 when rx WMMPS UAPSD Qos data with TID1 */
#define BIT_SHIFT_WMMPS_UAPSD_TID0                   0
#define BIT_WMMPS_UAPSD_TID0                         ((u32)0x00000001 << BIT_SHIFT_WMMPS_UAPSD_TID0)                   /*!<R/W 0  Disable interrupt 8051 when rx WMMPS UAPSD Qos data with TID0 */

/* REG_LPNAV_CTRL 0x0694 */
#define BIT_SHIFT_LPNAV_EN                           31
#define BIT_LPNAV_EN                                 ((u32)0x00000001 << BIT_SHIFT_LPNAV_EN)                           /*!<R/W 0  Low Power NAV Mode Enable. When this bit is set, enable MAC low power NAV mode */
#define BIT_SHIFT_LPNAV_EARLY                        16
#define BIT_MASK_LPNAV_EARLY                         ((u32)0x00007FFF << BIT_SHIFT_LPNAV_EARLY)                        /*!<R/W 0x0A  When in LPNAV mode, MAC will recall BB and RF into RX idle mode. The unit is us. */
#define BIT_SHIFT_LPNAV_THR                          0
#define BIT_MASK_LPNAV_THR                           ((u32)0x0000FFFF << BIT_SHIFT_LPNAV_THR)                          /*!<R/W 0x200  When protected NAV in the received frame is greater than this threshold value, then MAC enters into LPNAV mode. The time unit is 16us. */

/* REG_WKFMCAM_CMD 0x0698 */
#define BIT_SHIFT_WKFMCAM_WE                         16
#define BIT_WKFMCAM_WE                               ((u32)0x00000001 << BIT_SHIFT_WKFMCAM_WE)                         /*!<R/W 0  CAM Write Enable */
#define BIT_SHIFT_WKFMCAM_AD                         8
#define BIT_MASK_WKFMCAM_AD                          ((u32)0x000000FF << BIT_SHIFT_WKFMCAM_AD)                         /*!<R/W 0  Entry address */
#define BIT_SHIFT_CAM_NUM                            0
#define BIT_MASK_CAM_NUM                             ((u32)0x000000FF << BIT_SHIFT_CAM_NUM)                            /*!<R/W 0  CAM Entry Number */

/* REG_WKFMCAM_WD 0x069C */
#define BIT_SHIFT_WKFMCAM_WD                         0
#define BIT_MASK_WKFMCAM_WD                          ((u32)0xFFFFFFFF << BIT_SHIFT_WKFMCAM_WD)                         /*!<R/W   CAM Write Data */

/* REG_RXFLTMAP0 0x06A0 */
#define BIT_SHIFT_MGTFLT15EN                         15
#define BIT_MGTFLT15EN                               ((u32)0x00000001 << BIT_SHIFT_MGTFLT15EN)                         /*!<R/W 0  When set, frames with type=00 and subtype=1111 are received into RXFF. */
#define BIT_SHIFT_MGTFLT14EN                         14
#define BIT_MGTFLT14EN                               ((u32)0x00000001 << BIT_SHIFT_MGTFLT14EN)                         /*!<R/W 0  When set, frames with type=00 and subtype=1110 are received into RXFF. */
#define BIT_SHIFT_MGTFLT13EN                         13
#define BIT_MGTFLT13EN                               ((u32)0x00000001 << BIT_SHIFT_MGTFLT13EN)                         /*!<R/W 0  When set, frames with type=00 and subtype=1101 are received into RXFF. */
#define BIT_SHIFT_MGTFLT12EN                         12
#define BIT_MGTFLT12EN                               ((u32)0x00000001 << BIT_SHIFT_MGTFLT12EN)                         /*!<R/W 0  When set, frames with type=00 and subtype=1100 are received into RXFF. */
#define BIT_SHIFT_MGTFLT11EN                         11
#define BIT_MGTFLT11EN                               ((u32)0x00000001 << BIT_SHIFT_MGTFLT11EN)                         /*!<R/W 0  When set, frames with type=00 and subtype=1011 are received into RXFF. */
#define BIT_SHIFT_MGTFLT10EN                         10
#define BIT_MGTFLT10EN                               ((u32)0x00000001 << BIT_SHIFT_MGTFLT10EN)                         /*!<R/W 0  When set, frames with type=00 and subtype=1010 are received into RXFF */
#define BIT_SHIFT_MGTFLT9EN                          9
#define BIT_MGTFLT9EN                                ((u32)0x00000001 << BIT_SHIFT_MGTFLT9EN)                          /*!<R/W 0  When set, frames with type=00 and subtype=1001 are received into RXFF. */
#define BIT_SHIFT_MGTFLT8EN                          8
#define BIT_MGTFLT8EN                                ((u32)0x00000001 << BIT_SHIFT_MGTFLT8EN)                          /*!<R/W 0  When set, frames with type=00 and subtype=1000 are received into RXFF */
#define BIT_SHIFT_MGTFLT7EN                          7
#define BIT_MGTFLT7EN                                ((u32)0x00000001 << BIT_SHIFT_MGTFLT7EN)                          /*!<R/W 0  When set, frames with type=00 and subtype=0111 are received into RXFF. */
#define BIT_SHIFT_MGTFLT6EN                          6
#define BIT_MGTFLT6EN                                ((u32)0x00000001 << BIT_SHIFT_MGTFLT6EN)                          /*!<R/W 0  When set, frames with type=00 and subtype=0110 are received into RXFF. */
#define BIT_SHIFT_MGTFLT5EN                          5
#define BIT_MGTFLT5EN                                ((u32)0x00000001 << BIT_SHIFT_MGTFLT5EN)                          /*!<R/W 0  When set, frames with type=00 and subtype=0101 are received into RXFF */
#define BIT_SHIFT_MGTFLT4EN                          4
#define BIT_MGTFLT4EN                                ((u32)0x00000001 << BIT_SHIFT_MGTFLT4EN)                          /*!<R/W 0  When set, frames with type=00 and subtype=0100 are received into RXFF. */
#define BIT_SHIFT_MGTFLT3EN                          3
#define BIT_MGTFLT3EN                                ((u32)0x00000001 << BIT_SHIFT_MGTFLT3EN)                          /*!<R/W 0  When set, frames with type=00 and subtype=0011 are received into RXFF */
#define BIT_SHIFT_MGTFLT2EN                          2
#define BIT_MGTFLT2EN                                ((u32)0x00000001 << BIT_SHIFT_MGTFLT2EN)                          /*!<R/W 0  When set, frames with type=00 and subtype=0010 are received into RXFF */
#define BIT_SHIFT_MGTFLT1EN                          1
#define BIT_MGTFLT1EN                                ((u32)0x00000001 << BIT_SHIFT_MGTFLT1EN)                          /*!<R/W 0  When set, frames with type=00 and subtype=0001 are received into RXFF */
#define BIT_SHIFT_MGTFLT0EN                          0
#define BIT_MGTFLT0EN                                ((u32)0x00000001 << BIT_SHIFT_MGTFLT0EN)                          /*!<R/W 0  When set, frames with type=00 and subtype=0000 are received into RXFF */

/* REG_RXFLTMAP1 0x06A2 */
#define BIT_SHIFT_CTRLFLT15EN                        15
#define BIT_CTRLFLT15EN                              ((u32)0x00000001 << BIT_SHIFT_CTRLFLT15EN)                        /*!<R/W 0  When set, frames with type=01 and subtype=1111 are received into RXFF */
#define BIT_SHIFT_CTRLFLT14EN                        14
#define BIT_CTRLFLT14EN                              ((u32)0x00000001 << BIT_SHIFT_CTRLFLT14EN)                        /*!<R/W 0  When set, frames with type=01 and subtype=1110 are received into RXFF */
#define BIT_SHIFT_CTRLFLT13EN                        13
#define BIT_CTRLFLT13EN                              ((u32)0x00000001 << BIT_SHIFT_CTRLFLT13EN)                        /*!<R/W 0  When set, frames with type=01 and subtype=1101 are received into RXFF. */
#define BIT_SHIFT_CTRLFLT12EN                        12
#define BIT_CTRLFLT12EN                              ((u32)0x00000001 << BIT_SHIFT_CTRLFLT12EN)                        /*!<R/W 0  When set, frames with type=01 and subtype=1100 are received into RXFF. */
#define BIT_SHIFT_CTRLFLT11EN                        11
#define BIT_CTRLFLT11EN                              ((u32)0x00000001 << BIT_SHIFT_CTRLFLT11EN)                        /*!<R/W 0  When set, frames with type=01 and subtype=1011 are received into RXFF */
#define BIT_SHIFT_CTRLFLT10EN                        10
#define BIT_CTRLFLT10EN                              ((u32)0x00000001 << BIT_SHIFT_CTRLFLT10EN)                        /*!<R/W 0  When set, frames with type=01 and subtype=1010 are received into RXFF. */
#define BIT_SHIFT_CTRLFLT9EN                         9
#define BIT_CTRLFLT9EN                               ((u32)0x00000001 << BIT_SHIFT_CTRLFLT9EN)                         /*!<R/W 0  When set, frames with type=01 and subtype=1001 are received into RXFF */
#define BIT_SHIFT_CTRLFLT8EN                         8
#define BIT_CTRLFLT8EN                               ((u32)0x00000001 << BIT_SHIFT_CTRLFLT8EN)                         /*!<R/W 0  When set, frames with type=01 and subtype=1000 are received into RXFF */
#define BIT_SHIFT_CTRLFLT7EN                         7
#define BIT_CTRLFLT7EN                               ((u32)0x00000001 << BIT_SHIFT_CTRLFLT7EN)                         /*!<R/W 0  When set, frames with type=01 and subtype=0111 are received into RXFF */
#define BIT_SHIFT_CTRLFLT6EN                         6
#define BIT_CTRLFLT6EN                               ((u32)0x00000001 << BIT_SHIFT_CTRLFLT6EN)                         /*!<R/W 0  When set, frames with type=01 and subtype=0110 are received into RXFF. */
#define BIT_SHIFT_CTRLFLT5EN                         5
#define BIT_CTRLFLT5EN                               ((u32)0x00000001 << BIT_SHIFT_CTRLFLT5EN)                         /*!<R/W 0  When set, frames with type=01 and subtype=0101 are received into RXFF. */
#define BIT_SHIFT_CTRLFLT4EN                         4
#define BIT_CTRLFLT4EN                               ((u32)0x00000001 << BIT_SHIFT_CTRLFLT4EN)                         /*!<R/W 0  When set, frames with type=01 and subtype=0100 are received into RXFF. */
#define BIT_SHIFT_CTRLFLT3EN                         3
#define BIT_CTRLFLT3EN                               ((u32)0x00000001 << BIT_SHIFT_CTRLFLT3EN)                         /*!<R/W 0  When set, frames with type=01 and subtype=0011 are received into RXFF. */
#define BIT_SHIFT_CTRLFLT2EN                         2
#define BIT_CTRLFLT2EN                               ((u32)0x00000001 << BIT_SHIFT_CTRLFLT2EN)                         /*!<R/W 0  When set, frames with type=01 and subtype=0010 are received into RXFF. */
#define BIT_SHIFT_CTRLFLT1EN                         1
#define BIT_CTRLFLT1EN                               ((u32)0x00000001 << BIT_SHIFT_CTRLFLT1EN)                         /*!<R/W 0  When set, frames with type=01 and subtype=0001 are received into RXFF. */
#define BIT_SHIFT_CTRLFLT0EN                         0
#define BIT_CTRLFLT0EN                               ((u32)0x00000001 << BIT_SHIFT_CTRLFLT0EN)                         /*!<R/W 0  When set, frames with type=01 and subtype=0000 are received into RXFF. */

/* REG_RXFLTMAP 0x06A4 */
#define BIT_SHIFT_DATAFLT15EN                        15
#define BIT_DATAFLT15EN                              ((u32)0x00000001 << BIT_SHIFT_DATAFLT15EN)                        /*!<R/W 0  When set, frames with type=10 and subtype=1111 are received into RXFF */
#define BIT_SHIFT_DATAFLT14EN                        14
#define BIT_DATAFLT14EN                              ((u32)0x00000001 << BIT_SHIFT_DATAFLT14EN)                        /*!<R/W 0  When set, frames with type=10 and subtype=1110 are received into RXFF */
#define BIT_SHIFT_DATAFLT13EN                        13
#define BIT_DATAFLT13EN                              ((u32)0x00000001 << BIT_SHIFT_DATAFLT13EN)                        /*!<R/W 0  When set, frames with type=10 and subtype=1101 are received into RXFF. */
#define BIT_SHIFT_DATAFLT12EN                        12
#define BIT_DATAFLT12EN                              ((u32)0x00000001 << BIT_SHIFT_DATAFLT12EN)                        /*!<R/W 0  When set, frames with type=10 and subtype=1100 are received into RXFF. */
#define BIT_SHIFT_DATAFLT11EN                        11
#define BIT_DATAFLT11EN                              ((u32)0x00000001 << BIT_SHIFT_DATAFLT11EN)                        /*!<R/W 0  When set, frames with type=10 and subtype=1011 are received into RXFF. */
#define BIT_SHIFT_DATAFLT10EN                        10
#define BIT_DATAFLT10EN                              ((u32)0x00000001 << BIT_SHIFT_DATAFLT10EN)                        /*!<R/W 0  When set, frames with type=10 and subtype=1010 are received into RXFF. */
#define BIT_SHIFT_DATAFLT9EN                         9
#define BIT_DATAFLT9EN                               ((u32)0x00000001 << BIT_SHIFT_DATAFLT9EN)                         /*!<R/W 0  When set, frames with type=10 and subtype=1001 are received into RXFF */
#define BIT_SHIFT_DATAFLT8EN                         8
#define BIT_DATAFLT8EN                               ((u32)0x00000001 << BIT_SHIFT_DATAFLT8EN)                         /*!<R/W 0  When set, frames with type=10 and subtype=1000 are received into RXFF */
#define BIT_SHIFT_DATAFLT7EN                         7
#define BIT_DATAFLT7EN                               ((u32)0x00000001 << BIT_SHIFT_DATAFLT7EN)                         /*!<R/W 0  When set, frames with type=10 and subtype=0111 are received into RXFF. */
#define BIT_SHIFT_DATAFLT6EN                         6
#define BIT_DATAFLT6EN                               ((u32)0x00000001 << BIT_SHIFT_DATAFLT6EN)                         /*!<R/W 0  When set, frames with type=10 and subtype=0110 are received into RXFF */
#define BIT_SHIFT_DATAFLT5EN                         5
#define BIT_DATAFLT5EN                               ((u32)0x00000001 << BIT_SHIFT_DATAFLT5EN)                         /*!<R/W 0  When set, frames with type=10 and subtype=0101 are received into RXFF */
#define BIT_SHIFT_DATAFLT4EN                         4
#define BIT_DATAFLT4EN                               ((u32)0x00000001 << BIT_SHIFT_DATAFLT4EN)                         /*!<R/W 0  When set, frames with type=10 and subtype=0100 are received into RXFF. */
#define BIT_SHIFT_DATAFLT3EN                         3
#define BIT_DATAFLT3EN                               ((u32)0x00000001 << BIT_SHIFT_DATAFLT3EN)                         /*!<R/W 0  When set, frames with type=10 and subtype=0011 are received into RXFF */
#define BIT_SHIFT_DATAFLT2EN                         2
#define BIT_DATAFLT2EN                               ((u32)0x00000001 << BIT_SHIFT_DATAFLT2EN)                         /*!<R/W 0  When set, frames with type=10 and subtype=0010 are received into RXFF. */
#define BIT_SHIFT_DATAFLT1EN                         1
#define BIT_DATAFLT1EN                               ((u32)0x00000001 << BIT_SHIFT_DATAFLT1EN)                         /*!<R/W 0  When set, frames with type=10 and subtype=0001 are received into RXFF. */
#define BIT_SHIFT_DATAFLT0EN                         0
#define BIT_DATAFLT0EN                               ((u32)0x00000001 << BIT_SHIFT_DATAFLT0EN)                         /*!<R/W 0  When set, frames with type=10 and subtype=0000 are received into RXFF. */

/* REG_BCN_PSR_RPT 0x06A8 */
#define BIT_SHIFT_DTIM_CNT                           24
#define BIT_MASK_DTIM_CNT                            ((u32)0x000000FF << BIT_SHIFT_DTIM_CNT)                           /*!<R 0  The DTIM count field of the TIM element of Rx beacon */
#define BIT_SHIFT_DTIM_PERIOD                        16
#define BIT_MASK_DTIM_PERIOD                         ((u32)0x000000FF << BIT_SHIFT_DTIM_PERIOD)                        /*!<R 0  The DTIM period field of the TIM element of Rx beacon */
#define BIT_SHIFT_DTIM                               15
#define BIT_DTIM                                     ((u32)0x00000001 << BIT_SHIFT_DTIM)                               /*!<R 0  Indicate the TIM element of Beacon is DTIM */
#define BIT_SHIFT_TIM                                14
#define BIT_TIM                                      ((u32)0x00000001 << BIT_SHIFT_TIM)                                /*!<R 0  Indicate MACID0 AID is set to 1 in the bit map control field of the TIM element of Rx Beacon frame */
#define BIT_SHIFT_PS_AID_0                           0
#define BIT_MASK_PS_AID_0                            ((u32)0x000007FF << BIT_SHIFT_PS_AID_0)                           /*!<R/W 0  AID0 for MACID0 */

/* REG_FLC_CTRL 0x06AC */
#define BIT_SHIFT_FLC_RPC                            0
#define BIT_MASK_FLC_RPC                             ((u32)0x000000FF << BIT_SHIFT_FLC_RPC)                            /*!<R 0  Number of Rx PKT in the interval which is specified by FLC_TRPC. The Rx PKT type is specified by 0x6AE[2:0] */

/* REG_FLC_RPCT 0x06AD */
#define BIT_SHIFT_FLC_PKTTH                          0
#define BIT_MASK_FLC_PKTTH                           ((u32)0x000000FF << BIT_SHIFT_FLC_PKTTH)                          /*!<R/W 0  Rx PKT number threshold */

/* REG_FLC_PTS 0x06AE */
#define BIT_SHIFT_FLC_CMFEN                          2
#define BIT_FLC_CMFEN                                ((u32)0x00000001 << BIT_SHIFT_FLC_CMFEN)                          /*!<R/W 0  Count Management Frame (1: Enable, 0:Disable) */
#define BIT_SHIFT_FLC_CCFEN                          1
#define BIT_FLC_CCFEN                                ((u32)0x00000001 << BIT_SHIFT_FLC_CCFEN)                          /*!<R/W 0  Count Control Frame (1: Enable, 0:Disable) */
#define BIT_SHIFT_FLC_CDFEN                          0
#define BIT_FLC_CDFEN                                ((u32)0x00000001 << BIT_SHIFT_FLC_CDFEN)                          /*!<R/W 0  Count Data Frame (1: Enable, 0:Disable) */

/* REG_FLC_TRPC 0x06AF */
#define BIT_SHIFT_FLC_RPCT_V1                        7
#define BIT_FLC_RPCT_V1                              ((u32)0x00000001 << BIT_SHIFT_FLC_RPCT_V1)                        /*!<R/W 0  When write ��1�� to this bit, FLC_TRPC will be enabled. */
#define BIT_SHIFT_FLC_MODSL                          6
#define BIT_FLC_MODSL                                ((u32)0x00000001 << BIT_SHIFT_FLC_MODSL)                          /*!<R/W 0  1:Timer Mode 0:Counter Mode */
#define BIT_SHIFT_TORRD                              0
#define BIT_MASK_TORRD                               ((u32)0x0000003F << BIT_SHIFT_TORRD)                              /*!<R/W 0  It specifies the time-out duration. (unit: 32 ms) */

/* REG_RXPKTMON_CTRL 0x06B0 */
#define BIT_SHIFT_RXBKQPKT_SEQ                       20
#define BIT_MASK_RXBKQPKT_SEQ                        ((u32)0x0000000F << BIT_SHIFT_RXBKQPKT_SEQ)                       /*!<R 0  The expected Rx BKQ packet index */
#define BIT_SHIFT_RXBEQPKT_SEQ                       16
#define BIT_MASK_RXBEQPKT_SEQ                        ((u32)0x0000000F << BIT_SHIFT_RXBEQPKT_SEQ)                       /*!<R 0  The expected Rx BEQ packet index */
#define BIT_SHIFT_RXVIQPKT_SEQ                       12
#define BIT_MASK_RXVIQPKT_SEQ                        ((u32)0x0000000F << BIT_SHIFT_RXVIQPKT_SEQ)                       /*!<R 0  The expected Rx VIQ packet index */
#define BIT_SHIFT_RXVOQPKT_SEQ                       8
#define BIT_MASK_RXVOQPKT_SEQ                        ((u32)0x0000000F << BIT_SHIFT_RXVOQPKT_SEQ)                       /*!<R 0  The expected Rx VOQ packet index */
#define BIT_SHIFT_RXBKQPKT_ERR                       7
#define BIT_RXBKQPKT_ERR                             ((u32)0x00000001 << BIT_SHIFT_RXBKQPKT_ERR)                       /*!<R 0  Indicate monitor find the Rx BKQ packet without incremental index */
#define BIT_SHIFT_RXBEQPKT_ERR                       6
#define BIT_RXBEQPKT_ERR                             ((u32)0x00000001 << BIT_SHIFT_RXBEQPKT_ERR)                       /*!<R 0  Indicate monitor find the Rx BEQ packet without incremental index */
#define BIT_SHIFT_RXVIQPKT_ERR                       5
#define BIT_RXVIQPKT_ERR                             ((u32)0x00000001 << BIT_SHIFT_RXVIQPKT_ERR)                       /*!<R 0  Indicate monitor find the Rx VIQ packet without incremental index */
#define BIT_SHIFT_RXVOQPKT_ERR                       4
#define BIT_RXVOQPKT_ERR                             ((u32)0x00000001 << BIT_SHIFT_RXVOQPKT_ERR)                       /*!<R 0  Indicate monitor find the Rx VOQ packet without incremental index */
#define BIT_SHIFT_RXDMA_MON_EN                       2
#define BIT_RXDMA_MON_EN                             ((u32)0x00000001 << BIT_SHIFT_RXDMA_MON_EN)                       /*!<R/W 0  Enable packet loss monitor function for Rx DMA. If this bit is set to 1, then MACRX append the incremental index to fragment field of sequence number field of rxmpdu restored to rxpkbuffer successfully */
#define BIT_SHIFT_RXPKT_MON_EN                       0
#define BIT_RXPKT_MON_EN                             ((u32)0x00000001 << BIT_SHIFT_RXPKT_MON_EN)                       /*!<R/W 0  Enable packet loss monitor function for Rx packets. If this bit is set to 1, then MACRX uses fragment field of sequence number field of rxmpdu as the mpdu index and check if the index is incremental. */

/* REG_STATE_MON 0x06B4 */
#define BIT_SHIFT_STATE_SEL                          24
#define BIT_MASK_STATE_SEL                           ((u32)0x0000001F << BIT_SHIFT_STATE_SEL)                          /*!<R/W 0  WMAC FSM selection */
#define BIT_SHIFT_STATE_INFO                         7
#define BIT_MASK_STATE_INFO                          ((u32)0x000001FF << BIT_SHIFT_STATE_INFO)                         /*!<R 0  Report the other relation information about FSM */
#define BIT_SHIFT_CUR_STATE                          0
#define BIT_MASK_CUR_STATE                           ((u32)0x0000007F << BIT_SHIFT_CUR_STATE)                          /*!<R/W 0  Indicate the FSM current state */

/* REG_ERROR_EVT_CTL 0x06B8 */
#define BIT_SHIFT_CSIRPT_LEN_BB_MORE_THAN_MAC        23
#define BIT_CSIRPT_LEN_BB_MORE_THAN_MAC              ((u32)0x00000001 << BIT_SHIFT_CSIRPT_LEN_BB_MORE_THAN_MAC)        /*!<R 0  Indicate MAC Rx csi rxd number overflow */
#define BIT_SHIFT_CSI_CHKSUM_ERROR                   22
#define BIT_CSI_CHKSUM_ERROR                         ((u32)0x00000001 << BIT_SHIFT_CSI_CHKSUM_ERROR)                   /*!<R 0  Indicate MAC Rx csi rpt checksum error */
#define BIT_SHIFT_MACRX_ERR_4                        20
#define BIT_MACRX_ERR_4                              ((u32)0x00000001 << BIT_SHIFT_MACRX_ERR_4)                        /*!<R 0  Indicate last MPDU length of AMPDU or PPDU length is error. */
#define BIT_SHIFT_MACRX_ERR_3                        19
#define BIT_MACRX_ERR_3                              ((u32)0x00000001 << BIT_SHIFT_MACRX_ERR_3)                        /*!<R 0  Indicate rxfifo or mac phy interface fifo overflow */
#define BIT_SHIFT_MACRX_ERR_2                        18
#define BIT_MACRX_ERR_2                              ((u32)0x00000001 << BIT_SHIFT_MACRX_ERR_2)                        /*!<R 0  Indicate MAC Rx occurs internal halt event */
#define BIT_SHIFT_MACRX_ERR_1                        17
#define BIT_MACRX_ERR_1                              ((u32)0x00000001 << BIT_SHIFT_MACRX_ERR_1)                        /*!<R 0  Indicate Rx packet length >= 12K bytes */
#define BIT_SHIFT_MACRX_ERR_0                        16
#define BIT_MACRX_ERR_0                              ((u32)0x00000001 << BIT_SHIFT_MACRX_ERR_0)                        /*!<R 0  Indicate MAC Rx occurs halt event */
#define BIT_SHIFT_PRETX_ERRHDL_EN                    15
#define BIT_PRETX_ERRHDL_EN                          ((u32)0x00000001 << BIT_SHIFT_PRETX_ERRHDL_EN)                    /*!<R/W 0  Pre tx error block enable signal */
#define BIT_SHIFT_MACTX_ERR_4                        4
#define BIT_MACTX_ERR_4                              ((u32)0x00000001 << BIT_SHIFT_MACTX_ERR_4)                        /*!<R 0  Indicate pre tx error */
#define BIT_SHIFT_MACTX_ERR_3                        3
#define BIT_MACTX_ERR_3                              ((u32)0x00000001 << BIT_SHIFT_MACTX_ERR_3)                        /*!<R 0  Indicate PHY Tx finish */
#define BIT_SHIFT_MACTX_ERR_2                        2
#define BIT_MACTX_ERR_2                              ((u32)0x00000001 << BIT_SHIFT_MACTX_ERR_2)                        /*!<R 0  Indicate TXD FIFO underflow when MAC Tx cmpba */
#define BIT_SHIFT_MACTX_ERR_1                        1
#define BIT_MACTX_ERR_1                              ((u32)0x00000001 << BIT_SHIFT_MACTX_ERR_1)                        /*!<R 0  Indicate TXD FIFO underflow */
#define BIT_SHIFT_MACTX_ERR_0                        0
#define BIT_MACTX_ERR_0                              ((u32)0x00000001 << BIT_SHIFT_MACTX_ERR_0)                        /*!<R 0  Indicate PHY finish TX before MAC */

/* REG_SEARCH_MACID 0x06BC */
#define BIT_SHIFT_EN_TXRPTBUF_CLK                    31
#define BIT_EN_TXRPTBUF_CLK                          ((u32)0x00000001 << BIT_SHIFT_EN_TXRPTBUF_CLK)                    /*!<R/W 0  when set to 1,keep txrptbuf sram always have clock */
#define BIT_SHIFT_INFO_INDEX_OFFSET                  16
#define BIT_MASK_INFO_INDEX_OFFSET                   ((u32)0x00001FFF << BIT_SHIFT_INFO_INDEX_OFFSET)                  /*!<R/W 0x380  Pre-macid information index address offset. */
#define BIT_SHIFT_WMAC_SRCH_FIFOFULL                 15
#define BIT_WMAC_SRCH_FIFOFULL                       ((u32)0x00000001 << BIT_SHIFT_WMAC_SRCH_FIFOFULL)                 /*!<R/W 0  when set to 1, when fifofull, stop macid search; */
#define BIT_SHIFT_DIS_INFOSRCH                       14
#define BIT_DIS_INFOSRCH                             ((u32)0x00000001 << BIT_SHIFT_DIS_INFOSRCH)                       /*!<R/W 0  when set to 1,disable to search information */
#define BIT_SHIFT_DISABLE_B0                         13
#define BIT_DISABLE_B0                               ((u32)0x00000001 << BIT_SHIFT_DISABLE_B0)                         /*!<R/W 0  when set to 1,disable to check a2[0] */
#define BIT_SHIFT_INFO_ADDR_OFFSET                   0
#define BIT_MASK_INFO_ADDR_OFFSET                    ((u32)0x00001FFF << BIT_SHIFT_INFO_ADDR_OFFSET)                   /*!<R/W 0  per-macid information address offset (Unit:8bytes). */

/* REG_BT_COEX_TABLE_V1 0x06C0 */
#define BIT_SHIFT_COEX_TABLE_1                       0
#define BIT_MASK_COEX_TABLE_1                        ((u32)0xFFFFFFFF << BIT_SHIFT_COEX_TABLE_1)                       /*!<R/W 0  coexistence table, used at dual antenna & out of band */

/* REG_BT_COEX_TABLE2_V1 0x06C4 */
#define BIT_SHIFT_COEX_TABLE_2                       0
#define BIT_MASK_COEX_TABLE_2                        ((u32)0xFFFFFFFF << BIT_SHIFT_COEX_TABLE_2)                       /*!<R/W 0  coexistence table, used at dual antenna & in band or single antenna */

/* REG_BT_COEX_BREAK_TABLE 0x06C8 */
#define BIT_SHIFT_BREAK_TABLE_2                      16
#define BIT_MASK_BREAK_TABLE_2                       ((u32)0x0000FFFF << BIT_SHIFT_BREAK_TABLE_2)                      /*!<R/W 0  Table used to break BT activity, when new WLAN request is coming and BT is on transmitting or receiving */
#define BIT_SHIFT_BREAK_TABLE_1                      0
#define BIT_MASK_BREAK_TABLE_1                       ((u32)0x0000FFFF << BIT_SHIFT_BREAK_TABLE_1)                      /*!<R/W 0  Table used to break WLAN activity, when new BT request is coming and WLAN is on transmitting or receiving */

/* REG_BT_COEX_TABLE_H_V1 0x06CC */
#define BIT_SHIFT_PRI_MASK_RX_RESP_V1                30
#define BIT_PRI_MASK_RX_RESP_V1                      ((u32)0x00000001 << BIT_SHIFT_PRI_MASK_RX_RESP_V1)                /*!<R/W 0  Priority Mask for RX Response Packet */
#define BIT_SHIFT_PRI_MASK_RXOFDM_V1                 29
#define BIT_PRI_MASK_RXOFDM_V1                       ((u32)0x00000001 << BIT_SHIFT_PRI_MASK_RXOFDM_V1)                 /*!<R/W 0  Priority Mask for RX OFDM */
#define BIT_SHIFT_PRI_MASK_RXCCK_V1                  28
#define BIT_PRI_MASK_RXCCK_V1                        ((u32)0x00000001 << BIT_SHIFT_PRI_MASK_RXCCK_V1)                  /*!<R/W 0  Priority Mask for RX CCK */
#define BIT_SHIFT_PRI_MASK_TXAC                      21
#define BIT_MASK_PRI_MASK_TXAC                       ((u32)0x0000007F << BIT_SHIFT_PRI_MASK_TXAC)                      /*!<R/W 0  Priority Mask for Tx Queue */
#define BIT_SHIFT_PRI_MASK_NAV                       13
#define BIT_MASK_PRI_MASK_NAV                        ((u32)0x000000FF << BIT_SHIFT_PRI_MASK_NAV)                       /*!<R/W 0  Priority Mask for Tx NAV */
#define BIT_SHIFT_PRI_MASK_CCK_V1                    12
#define BIT_PRI_MASK_CCK_V1                          ((u32)0x00000001 << BIT_SHIFT_PRI_MASK_CCK_V1)                    /*!<R/W 0  Priority Mask for Tx CCK */
#define BIT_SHIFT_PRI_MASK_OFDM_V1                   11
#define BIT_PRI_MASK_OFDM_V1                         ((u32)0x00000001 << BIT_SHIFT_PRI_MASK_OFDM_V1)                   /*!<R/W 0  Priority Mask for Tx OFDM */
#define BIT_SHIFT_PRI_MASK_RTY_V1                    10
#define BIT_PRI_MASK_RTY_V1                          ((u32)0x00000001 << BIT_SHIFT_PRI_MASK_RTY_V1)                    /*!<R/W 0  Priority Mask for Tx Retry Packet */
#define BIT_SHIFT_PRI_MASK_NUM                       6
#define BIT_MASK_PRI_MASK_NUM                        ((u32)0x0000000F << BIT_SHIFT_PRI_MASK_NUM)                       /*!<R/W 0  Priority Mask for Tx packet number */
#define BIT_SHIFT_PRI_MASK_TYPE                      2
#define BIT_MASK_PRI_MASK_TYPE                       ((u32)0x0000000F << BIT_SHIFT_PRI_MASK_TYPE)                      /*!<R/W 0  Priority Mask for Tx packet type [98]: Rx response [99]: Tx response [100]: beacon */
#define BIT_SHIFT_OOB_V1                             1
#define BIT_OOB_V1                                   ((u32)0x00000001 << BIT_SHIFT_OOB_V1)                             /*!<R/W 0  out of band indication (0: in band ; 1 : out of band) */
#define BIT_SHIFT_ANT_SEL_V1                         0
#define BIT_ANT_SEL_V1                               ((u32)0x00000001 << BIT_SHIFT_ANT_SEL_V1)                         /*!<R/W 0  single or dual antenna selection (0: single; 1 : dual) */

/* REG_RXCMD_0 0x06D0 */
#define BIT_SHIFT_RXCMD_EN                           31
#define BIT_RXCMD_EN                                 ((u32)0x00000001 << BIT_SHIFT_RXCMD_EN)                           /*!<R/W 0  RXCMD function enable */
#define BIT_SHIFT_RXCMD_INFO                         0
#define BIT_MASK_RXCMD_INFO                          ((u32)0x7FFFFFFF << BIT_SHIFT_RXCMD_INFO)                         /*!<R/W 0  The Information is send to rxpktbuffer for host SW */

/* REG_RXCMD_1 0x06D4 */
#define BIT_SHIFT_RXCMD_PRD                          0
#define BIT_MASK_RXCMD_PRD                           ((u32)0x0000FFFF << BIT_SHIFT_RXCMD_PRD)                          /*!<R/W 0  Define the period unit in us to send the RXCMD_INFO to rxpktbuffer for host SW */

/* REG_RESP_TXINFO_CFG 0x06D8 */
#define BIT_SHIFT_RESP_MFB                           25
#define BIT_MASK_RESP_MFB                            ((u32)0x0000007F << BIT_SHIFT_RESP_MFB)                           /*!<R/W 0  MFB information in register for response packet */
#define BIT_SHIFT_ANTINF_SEL                         23
#define BIT_MASK_ANTINF_SEL                          ((u32)0x00000003 << BIT_SHIFT_ANTINF_SEL)                         /*!<R/W 0  Antsel information for response frame in register or ctrl info 00: Antsel_en always disable, 01:Antsel_en field follow ctrl info 1X:Antsel_en always enable */
#define BIT_SHIFT_ANTSEL_SEL                         21
#define BIT_MASK_ANTSEL_SEL                          ((u32)0x00000003 << BIT_SHIFT_ANTSEL_SEL)                         /*!<R/W 0  antenna select 0: use rx phystatus antsel information; 1: use tx report antsel information; other: use register antsel information. */
#define BIT_SHIFT_RESP_TXPOWER                       18
#define BIT_MASK_RESP_TXPOWER                        ((u32)0x00000007 << BIT_SHIFT_RESP_TXPOWER)                       /*!<R/W 0  tx power setting when send response packet */
#define BIT_SHIFT_RESP_TXANT                         0
#define BIT_MASK_RESP_TXANT                          ((u32)0x0003FFFF << BIT_SHIFT_RESP_TXANT)                         /*!<R/W 0x3F  tx antenna information */

/* REG_BBPSF_CTRL 0x06DC */
#define BIT_SHIFT_WMAC_CSI_RATE_FORCE_EN             15
#define BIT_WMAC_CSI_RATE_FORCE_EN                   ((u32)0x00000001 << BIT_SHIFT_WMAC_CSI_RATE_FORCE_EN)             /*!<R/W 0  0: disable CSI force rate. Refer to RRSR bitmask 1: CSI frame Tx rate refers to 0x6DC[29:24] */
#define BIT_SHIFT_WMAC_CSI_RSC_FORCE                 13
#define BIT_MASK_WMAC_CSI_RSC_FORCE                  ((u32)0x00000003 << BIT_SHIFT_WMAC_CSI_RSC_FORCE)                 /*!<R/W 0  If csi_force_rate_en = 1, CSI frame sub-channel configuration 00: Primary 20Mhz BW(0x483[3:0]) 01: Follow Rx packet BW. 10: Duplicate mode. 11: Reserved */
#define BIT_SHIFT_CSI_GID_SEL                        12
#define BIT_CSI_GID_SEL                              ((u32)0x00000001 << BIT_SHIFT_CSI_GID_SEL)                        /*!<R/W    */
#define BIT_SHIFT_RDCSIMD_FLAG_TRIG_SEL              11
#define BIT_RDCSIMD_FLAG_TRIG_SEL                    ((u32)0x00000001 << BIT_SHIFT_RDCSIMD_FLAG_TRIG_SEL)              /*!<R/W 0  0: Trigger read csi mode flag raising when mac_csi_granted & ndp_valid positive edge 1: Trigger read csi mode flag raising when mac_csi_granted positive edge */
#define BIT_SHIFT_NDPVLD_POS_RST_FFPTR_DIS_V1        10
#define BIT_NDPVLD_POS_RST_FFPTR_DIS_V1              ((u32)0x00000001 << BIT_SHIFT_NDPVLD_POS_RST_FFPTR_DIS_V1)        /*!<R/W 0  0: Reset rx_fifo read/wrtie pointer when ndp_valid positive edge 1: Not reset rx_fifo read/wrtie pointer when ndp_valid positive edge */
#define BIT_SHIFT_NDPVLD_PROTECT_RDRDY_DIS           9
#define BIT_NDPVLD_PROTECT_RDRDY_DIS                 ((u32)0x00000001 << BIT_SHIFT_NDPVLD_PROTECT_RDRDY_DIS)           /*!<R/W 0  0: Protect write enable of rx_fifo when ndp_valid =1 1: Not Protect write enable of rx_fifo when ndp_valid =1 */
#define BIT_SHIFT_CSIRD_EMPTY_APPZERO                8
#define BIT_CSIRD_EMPTY_APPZERO                      ((u32)0x00000001 << BIT_SHIFT_CSIRD_EMPTY_APPZERO)                /*!<R/W 0  0: Not append zero data when rx_fifo read csi data to empty. If csi data length of BB transmitted is smaller than MAC expected, Tx CSI report would be FCS error. 1: Append zero data when rx_fifo read csi data to empty. If csi data length of BB transmitted is smaller than MAC expected, there would be zero before FCS field of Tx CSI report pkt and the CSI report pkt would be FCS ok */
#define BIT_SHIFT_WMC_CSI_RATE_FB_EN                 7
#define BIT_WMC_CSI_RATE_FB_EN                       ((u32)0x00000001 << BIT_SHIFT_WMC_CSI_RATE_FB_EN)                 /*!<R/W 0  Enable CSI frame rate fallback (only one step in CSI RRSR) This bit is set to 1 to enable MAC to use previous latched csi resp rate for retry pkt. */
#define BIT_SHIFT_RXFIFO_WRPTR_WO_CHKSUM             6
#define BIT_RXFIFO_WRPTR_WO_CHKSUM                   ((u32)0x00000001 << BIT_SHIFT_RXFIFO_WRPTR_WO_CHKSUM)             /*!<R/W 0  This bit is set to 1 when rx_fifo don��t enable csi data checksum. */

/* REG_RESP_TXINFO_RATE 0x06DE */
#define BIT_SHIFT_CTL_IDLE_CLR_CSI_RPT_V1            15
#define BIT_CTL_IDLE_CLR_CSI_RPT_V1                  ((u32)0x00000001 << BIT_SHIFT_CTL_IDLE_CLR_CSI_RPT_V1)            /*!<R/W 0  ckr csi report request if response fsm idle */
#define BIT_SHIFT_USE_NDPARATE                       14
#define BIT_USE_NDPARATE                             ((u32)0x00000001 << BIT_SHIFT_USE_NDPARATE)                       /*!<R/W 1  1: use ndpa rx rate to decide csi report rate 0: use ndp rx rate to decide csi report rate */
#define BIT_SHIFT_CSI_RATE                           8
#define BIT_MASK_CSI_RATE                            ((u32)0x0000003F << BIT_SHIFT_CSI_RATE)                           /*!<R/W 0xB  csi report init tx rate */
#define BIT_SHIFT_RESP_TXRATE                        0
#define BIT_MASK_RESP_TXRATE                         ((u32)0x000000FF << BIT_SHIFT_RESP_TXRATE)                        /*!<R/W 0x04  tx rate use to decide response rate */

/* REG_P2P_RX_BCN_NOA 0x06E0 */
#define BIT_SHIFT_P2P_NOA_PARSER_EN                  15
#define BIT_P2P_NOA_PARSER_EN                        ((u32)0x00000001 << BIT_SHIFT_P2P_NOA_PARSER_EN)                  /*!<R/W 0  NoA Parser enabled. */
#define BIT_SHIFT_P2P_BSSID_SEL_V1                   12
#define BIT_MASK_P2P_BSSID_SEL_V1                    ((u32)0x00000007 << BIT_SHIFT_P2P_BSSID_SEL_V1)                   /*!<R/W 0  When this valueis 0/1/2/3/4, then beacon with matched BSSID0/1/2/3/4 is parsed. */
#define BIT_SHIFT_P2P_OUI_TYPE                       0
#define BIT_MASK_P2P_OUI_TYPE                        ((u32)0x000000FF << BIT_SHIFT_P2P_OUI_TYPE)                       /*!<R/W 0  NOA OUI Type */

/* REG_ASSOCIATED_BFMER0_INFO 0x06E4 */
#define BIT_SHIFT_R_WMAC_SOUNDING_RXADD_R0_V1        0
#define BIT_MASK_R_WMAC_SOUNDING_RXADD_R0_V1         ((u32)0xFFFFFFFF << BIT_SHIFT_R_WMAC_SOUNDING_RXADD_R0_V1)        /*!<R/W 0  MACID of the associated beamformer0 bit[31:0] */

/* REG_SOUNDING_CFG1 0x06E8 */
#define BIT_SHIFT_R_WMAC_TXCSI_AID0                  16
#define BIT_MASK_R_WMAC_TXCSI_AID0                   ((u32)0x000001FF << BIT_SHIFT_R_WMAC_TXCSI_AID0)                  /*!<R/W 0  P_AID of the associated bemaformer0 */
#define BIT_SHIFT_R_WMAC_SOUNDING_RXADD_R0_H         0
#define BIT_MASK_R_WMAC_SOUNDING_RXADD_R0_H          ((u32)0x0000FFFF << BIT_SHIFT_R_WMAC_SOUNDING_RXADD_R0_H)         /*!<R/W 0  MACID of the associated beamformer0 bit[47:32] */

/* REG_SOUNDING_CFG2 0x06EC */
#define BIT_SHIFT_R_WMAC_SOUNDING_RXADD_L            0
#define BIT_MASK_R_WMAC_SOUNDING_RXADD_L             ((u32)0xFFFFFFFF << BIT_SHIFT_R_WMAC_SOUNDING_RXADD_L)            /*!<R/W 0  MACID of the associated beamformer1 bit[31:0] */

/* REG_SOUNDING_CFG3 0x06F0 */
#define BIT_SHIFT_R_WMAC_TXCSI_AID1                  16
#define BIT_MASK_R_WMAC_TXCSI_AID1                   ((u32)0x000001FF << BIT_SHIFT_R_WMAC_TXCSI_AID1)                  /*!<R/W 0  P_AID of the associated bemaformer1 */
#define BIT_SHIFT_R_WMAC_SOUNDING_RXADD_H            0
#define BIT_MASK_R_WMAC_SOUNDING_RXADD_H             ((u32)0x0000FFFF << BIT_SHIFT_R_WMAC_SOUNDING_RXADD_H)            /*!<R/W 0  MACID of the associated beamformer1 bit[15:0] */

/* REG_SOUNDING_CFG0 0x06F4 */
#define BIT_SHIFT_R_WMAC_BFINFO_20M_1                16
#define BIT_MASK_R_WMAC_BFINFO_20M_1                 ((u32)0x00000FFF << BIT_SHIFT_R_WMAC_BFINFO_20M_1)                /*!<R/W 0  BF Info of the associated beamformer1 at BW=20M bit[18:16]: Nc index bit[21:19]: Nr index bit[23:22]: grouping bit[25:24]: codebook info bit[27:26]: coefficient size */
#define BIT_SHIFT_R_WMAC_BFINFO_20M_0                0
#define BIT_MASK_R_WMAC_BFINFO_20M_0                 ((u32)0x00000FFF << BIT_SHIFT_R_WMAC_BFINFO_20M_0)                /*!<R/W 0  BF Info of the associated beamformer0 at BW=20M bit[2:0]: Nc index bit[5:3]: Nr index bit[7:6]: grouping bit[9:8]: codebook info bit[11:10]: coefficient size */

/* REG_ANTCD_INFO 0x06F8 */
#define BIT_SHIFT_WMAC_RESP_ANTD                     12
#define BIT_MASK_WMAC_RESP_ANTD                      ((u32)0x0000000F << BIT_SHIFT_WMAC_RESP_ANTD)                     /*!<R/W 0  used for antenna select d value BIT_WMAC_RESP_ANTCD[3:2], used for antsel_d value; */
#define BIT_SHIFT_WMAC_RESP_ANTC                     8
#define BIT_MASK_WMAC_RESP_ANTC                      ((u32)0x0000000F << BIT_SHIFT_WMAC_RESP_ANTC)                     /*!<R/W 0  used for antenna select c value BIT_WMAC_RESP_ANTCD[3:3], used for antsel_d value; */
#define BIT_SHIFT_WMAC_RESP_ANTB                     4
#define BIT_MASK_WMAC_RESP_ANTB                      ((u32)0x0000000F << BIT_SHIFT_WMAC_RESP_ANTB)                     /*!<R/W 0  used for antenna select b value BIT_WMAC_RESP_ANTCD[3:4], used for antsel_d value; */
#define BIT_SHIFT_WMAC_RESP_ANTA                     0
#define BIT_MASK_WMAC_RESP_ANTA                      ((u32)0x0000000F << BIT_SHIFT_WMAC_RESP_ANTA)                     /*!<R/W 0  used for antenna select a value BIT_WMAC_RESP_ANTCD[3:5], used for antsel_d value; */

/* REG_CSI_PTR 0x06FC */
#define BIT_SHIFT_CSI_RADDR_LATCH_V2                 16
#define BIT_MASK_CSI_RADDR_LATCH_V2                  ((u32)0x0000FFFF << BIT_SHIFT_CSI_RADDR_LATCH_V2)                 /*!<R 0  Tx_fifo read pointer latch value after Tx CSI report pkt (unit: 8B) */
#define BIT_SHIFT_CSI_WADDR_LATCH_V2                 0
#define BIT_MASK_CSI_WADDR_LATCH_V2                  ((u32)0x0000FFFF << BIT_SHIFT_CSI_WADDR_LATCH_V2)                 /*!<R 0  Tx_fifo write pointer latch value at ndp_valid negative edge (unit: 8B) */

/* REG_BCN_PSR_RPT2 0x1600 */
#define BIT_SHIFT_DTIM_CNT2                          24
#define BIT_MASK_DTIM_CNT2                           ((u32)0x000000FF << BIT_SHIFT_DTIM_CNT2)                          /*!<R 0  The DTIM count field of the TIM element of Rx beacon for MACID2 */
#define BIT_SHIFT_DTIM_PERIOD2                       16
#define BIT_MASK_DTIM_PERIOD2                        ((u32)0x000000FF << BIT_SHIFT_DTIM_PERIOD2)                       /*!<R 0  The DTIM period field of the TIM element of Rx beacon for MACID2 */
#define BIT_SHIFT_DTIM2                              15
#define BIT_DTIM2                                    ((u32)0x00000001 << BIT_SHIFT_DTIM2)                              /*!<R 0  Indicate the TIM element of Beacon is DTIM for MACID2 */
#define BIT_SHIFT_TIM2                               14
#define BIT_TIM2                                     ((u32)0x00000001 << BIT_SHIFT_TIM2)                               /*!<R 0  Indicate MACID2 AID is set to 1 in the bit map control field of the TIM element of Rx Beacon frame */
#define BIT_SHIFT_RPT_VALID2                         13
#define BIT_RPT_VALID2                               ((u32)0x00000001 << BIT_SHIFT_RPT_VALID2)                         /*!<R 0  indicate tim info is valid if 1, or is invalid. */
#define BIT_SHIFT_PS_AID_2                           0
#define BIT_MASK_PS_AID_2                            ((u32)0x000007FF << BIT_SHIFT_PS_AID_2)                           /*!<R/W 0  AID2 for MACID2 */

/* REG_BCN_PSR_RPT3 0x1604 */
#define BIT_SHIFT_DTIM_CNT3                          24
#define BIT_MASK_DTIM_CNT3                           ((u32)0x000000FF << BIT_SHIFT_DTIM_CNT3)                          /*!<R 0  The DTIM count field of the TIM element of Rx beacon for MACID3 */
#define BIT_SHIFT_DTIM_PERIOD3                       16
#define BIT_MASK_DTIM_PERIOD3                        ((u32)0x000000FF << BIT_SHIFT_DTIM_PERIOD3)                       /*!<R 0  The DTIM period field of the TIM element of Rx beacon for MACID3 */
#define BIT_SHIFT_DTIM3                              15
#define BIT_DTIM3                                    ((u32)0x00000001 << BIT_SHIFT_DTIM3)                              /*!<R 0  Indicate the TIM element of Beacon is DTIM for MACID3 */
#define BIT_SHIFT_TIM3                               14
#define BIT_TIM3                                     ((u32)0x00000001 << BIT_SHIFT_TIM3)                               /*!<R 0  Indicate MACID2 AID is set to 1 in the bit map control field of the TIM element of Rx Beacon frame */
#define BIT_SHIFT_RPT_VALID3                         13
#define BIT_RPT_VALID3                               ((u32)0x00000001 << BIT_SHIFT_RPT_VALID3)                         /*!<R 0  indicate tim info is valid if 1, or is invalid. */
#define BIT_SHIFT_PS_AID_3                           0
#define BIT_MASK_PS_AID_3                            ((u32)0x000007FF << BIT_SHIFT_PS_AID_3)                           /*!<R/W 0  AID3 for MACID3 */

/* REG_BCN_PSR_RPT4 0x1608 */
#define BIT_SHIFT_DTIM_CNT4                          24
#define BIT_MASK_DTIM_CNT4                           ((u32)0x000000FF << BIT_SHIFT_DTIM_CNT4)                          /*!<R 0  The DTIM count field of the TIM element of Rx beacon for MACID4 */
#define BIT_SHIFT_DTIM_PERIOD4                       16
#define BIT_MASK_DTIM_PERIOD4                        ((u32)0x000000FF << BIT_SHIFT_DTIM_PERIOD4)                       /*!<R 0  The DTIM period field of the TIM element of Rx beacon for MACID4 */
#define BIT_SHIFT_DTIM4                              15
#define BIT_DTIM4                                    ((u32)0x00000001 << BIT_SHIFT_DTIM4)                              /*!<R 0  Indicate the TIM element of Beacon is DTIM for MACID4 */
#define BIT_SHIFT_TIM4                               14
#define BIT_TIM4                                     ((u32)0x00000001 << BIT_SHIFT_TIM4)                               /*!<R 0  Indicate MACID2 AID is set to 1 in the bit map control field of the TIM element of Rx Beacon frame */
#define BIT_SHIFT_RPT_VALID4                         13
#define BIT_RPT_VALID4                               ((u32)0x00000001 << BIT_SHIFT_RPT_VALID4)                         /*!<R 0  indicate tim info is valid if 1, or is invalid. */
#define BIT_SHIFT_PS_AID_4                           0
#define BIT_MASK_PS_AID_4                            ((u32)0x000007FF << BIT_SHIFT_PS_AID_4)                           /*!<R/W 0  AID4 for MACID4 */

/* REG_A1_ADDR_MASK 0x160C */
#define BIT_SHIFT_A1_ADDR_MASK                       0
#define BIT_MASK_A1_ADDR_MASK                        ((u32)0xFFFFFFFF << BIT_SHIFT_A1_ADDR_MASK)                       /*!<R 0xFFFF  mask rx A1 addr [39:8] for test */

/* REG_RXPSF_CTRL 0x1610 */
#define BIT_SHIFT_RXGCK_FIFOTHR_EN                   28
#define BIT_RXGCK_FIFOTHR_EN                         ((u32)0x00000001 << BIT_SHIFT_RXGCK_FIFOTHR_EN)                   /*!<R/W 0  1: enable RXGCK fifo threshold 0: disable RXGCK fifo threshold (ignore fifo threshold) Should be 0 if MAC loopback mode */
#define BIT_SHIFT_RXGCK_VHT_FIFOTHR                  26
#define BIT_MASK_RXGCK_VHT_FIFOTHR                   ((u32)0x00000003 << BIT_SHIFT_RXGCK_VHT_FIFOTHR)                  /*!<R/W 0  VHT rate RXGCK fifo threshold If RXVHT = 1 and RXGCK fifo write pointer >= this threshold, MAC_RX clock will stop gating. 0: 0 1: 1 (minimum RDRDY threshold for avoiding false alarm), can work at all situation. 2: 3 (number of RDRDY before receiving MAC header - 1), may cause error at some situation. 3: 4 (number of RDRDY before receiving MAC header), may cause error at some situation. */
#define BIT_SHIFT_RXGCK_HT_FIFOTHR                   24
#define BIT_MASK_RXGCK_HT_FIFOTHR                    ((u32)0x00000003 << BIT_SHIFT_RXGCK_HT_FIFOTHR)                   /*!<R/W 0  HT rate RXGCK fifo threshold If RXHT = 1 and RXGCK fifo write pointer >= this threshold, MAC_RX clock will stop gating. 0: 0 1: 1 (minimum RDRDY threshold for avoiding false alarm), can work at all situation. 2: 2 (number of RDRDY before receiving MAC header - 1), may cause error at some situation. 3: 3 (number of RDRDY before receiving MAC header), may cause error at some situation. */
#define BIT_SHIFT_RXGCK_OFDM_FIFOTHR                 22
#define BIT_MASK_RXGCK_OFDM_FIFOTHR                  ((u32)0x00000003 << BIT_SHIFT_RXGCK_OFDM_FIFOTHR)                 /*!<R/W 0  OFDM rate RXGCK fifo threshold If OFDM_VBON = 1 and RXGCK fifo write pointer >= this threshold, MAC_RX clock will stop gating. 0: 0 1: 1 (number of RDRDY before receiving MAC header = minimum RDRDY threshold for avoiding false alarm), can work at all situation. 2: 2, may cause error at some situation. 3: 3 (minimum RDRDY number within one packet), may cause error at some situation. */
#define BIT_SHIFT_RXGCK_CCK_FIFOTHR                  20
#define BIT_MASK_RXGCK_CCK_FIFOTHR                   ((u32)0x00000003 << BIT_SHIFT_RXGCK_CCK_FIFOTHR)                  /*!<R/W 0  CCK rate RXGCK fifo threshold If CCKCCA = 1 and RXGCK fifo write pointer >= this threshold, MAC_RX clock will stop gating. 0: 0 1: 1 (minimum RDRDY threshold for avoiding false alarm), can work at all situation. 2: 8, may cause error at some situation. 3: 15 (number of RDRDY before receiving MAC header), may cause error at some situation. */
#define BIT_SHIFT_RXGCK_ENTRY_DELAY                  17
#define BIT_MASK_RXGCK_ENTRY_DELAY                   ((u32)0x00000007 << BIT_SHIFT_RXGCK_ENTRY_DELAY)                  /*!<R/W 0x2  MAC_RX wait some time to gate clock after making the decision (about gating clock). Unit: T (MAC clock cycle) 0: 0 1: 2 2: 4 3: 8 4: 16 5: 32 6: 64 7: 128 */
#define BIT_SHIFT_RXGCK_OFDMCCA_EN                   16
#define BIT_RXGCK_OFDMCCA_EN                         ((u32)0x00000001 << BIT_SHIFT_RXGCK_OFDMCCA_EN)                   /*!<R/W 0  This bit is set to 1 to let OFDMCCA be one of the signals that can wakeup MAC from Rx_idle */
#define BIT_SHIFT_RXPSF_PKTLENTHR                    13
#define BIT_MASK_RXPSF_PKTLENTHR                     ((u32)0x00000007 << BIT_SHIFT_RXPSF_PKTLENTHR)                    /*!<R/W 0  Packet length threshold 3'd0: 16 Bytes 3'd1: 32 Bytes 3'd2: 64 Bytes 3'd3: 128 Bytes 3'd4: 256 Bytes 3'd5: 512 Bytes 3'd6: 1024 Bytes 3'd7: 2048 Bytes Only the packet which packet length is longer than this threshold will trigger an invalid_pkt pulse. */
#define BIT_SHIFT_RXPSF_CTRLEN                       12
#define BIT_RXPSF_CTRLEN                             ((u32)0x00000001 << BIT_SHIFT_RXPSF_CTRLEN)                       /*!<R/W 0  This bit is set to 1 to enable MAC to consider trigging invalid_pkt as rx packet Type=01. */
#define BIT_SHIFT_RXPSF_VHTCHKEN                     11
#define BIT_RXPSF_VHTCHKEN                           ((u32)0x00000001 << BIT_SHIFT_RXPSF_VHTCHKEN)                     /*!<R/W 0  This bit is set to 1 to enable MAC to consider trigging invalid_pkt as rx packet rate = VHT */
#define BIT_SHIFT_RXPSF_HTCHKEN                      10
#define BIT_RXPSF_HTCHKEN                            ((u32)0x00000001 << BIT_SHIFT_RXPSF_HTCHKEN)                      /*!<R/W 0  This bit is set to 1 to enable MAC to consider trigging invalid_pkt as rx packet rate = HT */
#define BIT_SHIFT_RXPSF_OFDMCHKEN                    9
#define BIT_RXPSF_OFDMCHKEN                          ((u32)0x00000001 << BIT_SHIFT_RXPSF_OFDMCHKEN)                    /*!<R/W 0  This bit is set to 1 to enable MAC to consider trigging invalid_pkt as rx packet rate = OFDM */
#define BIT_SHIFT_RXPSF_CCKCHKEN                     8
#define BIT_RXPSF_CCKCHKEN                           ((u32)0x00000001 << BIT_SHIFT_RXPSF_CCKCHKEN)                     /*!<R/W 0  This bit is set to 1 to enable MAC to consider trigging invalid_pkt as rx packet rate = CCK */
#define BIT_SHIFT_RXPSF_OFDMRST                      7
#define BIT_RXPSF_OFDMRST                            ((u32)0x00000001 << BIT_SHIFT_RXPSF_OFDMRST)                      /*!<R/W 1  This bit is set to 1 to reset MAC Rx before sending OFDM (include OFDM, HT, VHT) packet triggered invalid_pkt pulse (0 for debug) */
#define BIT_SHIFT_RXPSF_CCKRST                       6
#define BIT_RXPSF_CCKRST                             ((u32)0x00000001 << BIT_SHIFT_RXPSF_CCKRST)                       /*!<R/W 1  This bit is set to 1 to reset MAC Rx before sending CCK packet triggered invalid_pkt pulse(0 for debug) */
#define BIT_SHIFT_RXPSF_MHCHKEN                      5
#define BIT_RXPSF_MHCHKEN                            ((u32)0x00000001 << BIT_SHIFT_RXPSF_MHCHKEN)                      /*!<R/W 0  This bit is set to 1 to enable MAC to inform BB enter power saving mode as rx unmatch my MACID unicast or unmatch my BSSID Broadcast/Mutlicast packets (including aggrigation and non-aggrigation) */
#define BIT_SHIFT_RXPSF_CONT_ERRCHKEN                4
#define BIT_RXPSF_CONT_ERRCHKEN                      ((u32)0x00000001 << BIT_SHIFT_RXPSF_CONT_ERRCHKEN)                /*!<R/W 0  This bit is set to 1 to enable MAC to inform BB enter power saving mode as continuous rx FCS error packets number in a PPDU is large than the FCS error packet threshold defined by BBPSF_ERRTHR. This function is independent from rate, type and IDs. */
#define BIT_SHIFT_RXPSF_ALL_ERRCHKEN                 3
#define BIT_RXPSF_ALL_ERRCHKEN                       ((u32)0x00000001 << BIT_SHIFT_RXPSF_ALL_ERRCHKEN)                 /*!<R/W 0  This bit is set to 1 to enable MAC to inform BB enter power saving mode as rx FCS error packets number in a PPDU is larger than the FCS error packet threshold defined by BBPSF_ERRTHR. This function is independent from rate, type and IDs. */
#define BIT_SHIFT_RXPSF_ERRTHR                       0
#define BIT_MASK_RXPSF_ERRTHR                        ((u32)0x00000007 << BIT_SHIFT_RXPSF_ERRTHR)                       /*!<R/W 0  FCS error packet threshold 3'd0: 1 packet 3'd1: 4 packets 3'd2: 8 packets 3'd3: 12 packets 3'd4: 16 packets 3'd5: 20 packets 3'd6: 24 packets 3'd7: 28 packets */

/* REG_RXPSF_TYPE_CTRL 0x1614 */
#define BIT_SHIFT_RXPSF_DATA15EN                     31
#define BIT_RXPSF_DATA15EN                           ((u32)0x00000001 << BIT_SHIFT_RXPSF_DATA15EN)                     /*!<R/W 0  This bit is set to 1 to enable MAC to consider trigging invalid_pkt as rx packet Type=10 and subtype=1111. */
#define BIT_SHIFT_RXPSF_DATA14EN                     30
#define BIT_RXPSF_DATA14EN                           ((u32)0x00000001 << BIT_SHIFT_RXPSF_DATA14EN)                     /*!<R/W 0  This bit is set to 1 to enable MAC to consider trigging invalid_pkt as rx packet Type=10 and subtype=1110. */
#define BIT_SHIFT_RXPSF_DATA13EN                     29
#define BIT_RXPSF_DATA13EN                           ((u32)0x00000001 << BIT_SHIFT_RXPSF_DATA13EN)                     /*!<R/W 0  This bit is set to 1 to enable MAC to consider trigging invalid_pkt as rx packet Type=10 and subtype=1101. */
#define BIT_SHIFT_RXPSF_DATA12EN                     28
#define BIT_RXPSF_DATA12EN                           ((u32)0x00000001 << BIT_SHIFT_RXPSF_DATA12EN)                     /*!<R/W 0  This bit is set to 1 to enable MAC to consider trigging invalid_pkt as rx packet Type=10 and subtype=1100. */
#define BIT_SHIFT_RXPSF_DATA11EN                     27
#define BIT_RXPSF_DATA11EN                           ((u32)0x00000001 << BIT_SHIFT_RXPSF_DATA11EN)                     /*!<R/W 0  This bit is set to 1 to enable MAC to consider trigging invalid_pkt as rx packet Type=10 and subtype=1011. */
#define BIT_SHIFT_RXPSF_DATA10EN                     26
#define BIT_RXPSF_DATA10EN                           ((u32)0x00000001 << BIT_SHIFT_RXPSF_DATA10EN)                     /*!<R/W 0  This bit is set to 1 to enable MAC to consider trigging invalid_pkt as rx packet Type=10 and subtype=1010. */
#define BIT_SHIFT_RXPSF_DATA9EN                      25
#define BIT_RXPSF_DATA9EN                            ((u32)0x00000001 << BIT_SHIFT_RXPSF_DATA9EN)                      /*!<R/W 0  This bit is set to 1 to enable MAC to consider trigging invalid_pkt as rx packet Type=10 and subtype=1001. */
#define BIT_SHIFT_RXPSF_DATA8EN                      24
#define BIT_RXPSF_DATA8EN                            ((u32)0x00000001 << BIT_SHIFT_RXPSF_DATA8EN)                      /*!<R/W 0  This bit is set to 1 to enable MAC to consider trigging invalid_pkt as rx packet Type=10 and subtype=1000. */
#define BIT_SHIFT_RXPSF_DATA7EN                      23
#define BIT_RXPSF_DATA7EN                            ((u32)0x00000001 << BIT_SHIFT_RXPSF_DATA7EN)                      /*!<R/W 0  This bit is set to 1 to enable MAC to consider trigging invalid_pkt as rx packet Type=10 and subtype=0111. */
#define BIT_SHIFT_RXPSF_DATA6EN                      22
#define BIT_RXPSF_DATA6EN                            ((u32)0x00000001 << BIT_SHIFT_RXPSF_DATA6EN)                      /*!<R/W 0  This bit is set to 1 to enable MAC to consider trigging invalid_pkt as rx packet Type=10 and subtype=0110. */
#define BIT_SHIFT_RXPSF_DATA5EN                      21
#define BIT_RXPSF_DATA5EN                            ((u32)0x00000001 << BIT_SHIFT_RXPSF_DATA5EN)                      /*!<R/W 0  This bit is set to 1 to enable MAC to consider trigging invalid_pkt as rx packet Type=10 and subtype=0101. */
#define BIT_SHIFT_RXPSF_DATA4EN                      20
#define BIT_RXPSF_DATA4EN                            ((u32)0x00000001 << BIT_SHIFT_RXPSF_DATA4EN)                      /*!<R/W 0  This bit is set to 1 to enable MAC to consider trigging invalid_pkt as rx packet Type=10 and subtype=0100. */
#define BIT_SHIFT_RXPSF_DATA3EN                      19
#define BIT_RXPSF_DATA3EN                            ((u32)0x00000001 << BIT_SHIFT_RXPSF_DATA3EN)                      /*!<R/W 0  This bit is set to 1 to enable MAC to consider trigging invalid_pkt as rx packet Type=10 and subtype=0011. */
#define BIT_SHIFT_RXPSF_DATA2EN                      18
#define BIT_RXPSF_DATA2EN                            ((u32)0x00000001 << BIT_SHIFT_RXPSF_DATA2EN)                      /*!<R/W 0  This bit is set to 1 to enable MAC to consider trigging invalid_pkt as rx packet Type=10 and subtype=0010. */
#define BIT_SHIFT_RXPSF_DATA1EN                      17
#define BIT_RXPSF_DATA1EN                            ((u32)0x00000001 << BIT_SHIFT_RXPSF_DATA1EN)                      /*!<R/W 0  This bit is set to 1 to enable MAC to consider trigging invalid_pkt as rx packet Type=10 and subtype=0001. */
#define BIT_SHIFT_RXPSF_DATA0EN                      16
#define BIT_RXPSF_DATA0EN                            ((u32)0x00000001 << BIT_SHIFT_RXPSF_DATA0EN)                      /*!<R/W 0  This bit is set to 1 to enable MAC to consider trigging invalid_pkt as rx packet Type=10 and subtype=0000. */
#define BIT_SHIFT_RXPSF_MGT15EN                      15
#define BIT_RXPSF_MGT15EN                            ((u32)0x00000001 << BIT_SHIFT_RXPSF_MGT15EN)                      /*!<R/W 0  This bit is set to 1 to enable MAC to consider trigging invalid_pkt as rx packet Type=00 and subtype=1111. */
#define BIT_SHIFT_RXPSF_MGT14EN                      14
#define BIT_RXPSF_MGT14EN                            ((u32)0x00000001 << BIT_SHIFT_RXPSF_MGT14EN)                      /*!<R/W 0  This bit is set to 1 to enable MAC to consider trigging invalid_pkt as rx packet Type=00 and subtype=1110. */
#define BIT_SHIFT_RXPSF_MGT13EN                      13
#define BIT_RXPSF_MGT13EN                            ((u32)0x00000001 << BIT_SHIFT_RXPSF_MGT13EN)                      /*!<R/W 0  This bit is set to 1 to enable MAC to consider trigging invalid_pkt as rx packet Type=00 and subtype=1101. */
#define BIT_SHIFT_RXPSF_MGT12EN                      12
#define BIT_RXPSF_MGT12EN                            ((u32)0x00000001 << BIT_SHIFT_RXPSF_MGT12EN)                      /*!<R/W 0  This bit is set to 1 to enable MAC to consider trigging invalid_pkt as rx packet Type=00 and subtype=1100. */
#define BIT_SHIFT_RXPSF_MGT11EN                      11
#define BIT_RXPSF_MGT11EN                            ((u32)0x00000001 << BIT_SHIFT_RXPSF_MGT11EN)                      /*!<R/W 0  This bit is set to 1 to enable MAC to consider trigging invalid_pkt as rx packet Type=00 and subtype=1011. */
#define BIT_SHIFT_RXPSF_MGT10EN                      10
#define BIT_RXPSF_MGT10EN                            ((u32)0x00000001 << BIT_SHIFT_RXPSF_MGT10EN)                      /*!<R/W 0  This bit is set to 1 to enable MAC to consider trigging invalid_pkt as rx packet Type=00 and subtype=1010. */
#define BIT_SHIFT_RXPSF_MGT9EN                       9
#define BIT_RXPSF_MGT9EN                             ((u32)0x00000001 << BIT_SHIFT_RXPSF_MGT9EN)                       /*!<R/W 0  This bit is set to 1 to enable MAC to consider trigging invalid_pkt as rx packet Type=00 and subtype=1001. */
#define BIT_SHIFT_RXPSF_MGT8EN                       8
#define BIT_RXPSF_MGT8EN                             ((u32)0x00000001 << BIT_SHIFT_RXPSF_MGT8EN)                       /*!<R/W 0  This bit is set to 1 to enable MAC to consider trigging invalid_pkt as rx packet Type=00 and subtype=1000. */
#define BIT_SHIFT_RXPSF_MGT7EN                       7
#define BIT_RXPSF_MGT7EN                             ((u32)0x00000001 << BIT_SHIFT_RXPSF_MGT7EN)                       /*!<R/W 0  This bit is set to 1 to enable MAC to consider trigging invalid_pkt as rx packet Type=00 and subtype=0111. */
#define BIT_SHIFT_RXPSF_MGT6EN                       6
#define BIT_RXPSF_MGT6EN                             ((u32)0x00000001 << BIT_SHIFT_RXPSF_MGT6EN)                       /*!<R/W 0  This bit is set to 1 to enable MAC to consider trigging invalid_pkt as rx packet Type=00 and subtype=0110. */
#define BIT_SHIFT_RXPSF_MGT5EN                       5
#define BIT_RXPSF_MGT5EN                             ((u32)0x00000001 << BIT_SHIFT_RXPSF_MGT5EN)                       /*!<R/W 0  This bit is set to 1 to enable MAC to consider trigging invalid_pkt as rx packet Type=00 and subtype=0101. */
#define BIT_SHIFT_RXPSF_MGT4EN                       4
#define BIT_RXPSF_MGT4EN                             ((u32)0x00000001 << BIT_SHIFT_RXPSF_MGT4EN)                       /*!<R/W 0  This bit is set to 1 to enable MAC to consider trigging invalid_pkt as rx packet Type=00 and subtype=0100. */
#define BIT_SHIFT_RXPSF_MGT3EN                       3
#define BIT_RXPSF_MGT3EN                             ((u32)0x00000001 << BIT_SHIFT_RXPSF_MGT3EN)                       /*!<R/W 0  This bit is set to 1 to enable MAC to consider trigging invalid_pkt as rx packet Type=00 and subtype=0011. */
#define BIT_SHIFT_RXPSF_MGT2EN                       2
#define BIT_RXPSF_MGT2EN                             ((u32)0x00000001 << BIT_SHIFT_RXPSF_MGT2EN)                       /*!<R/W 0  This bit is set to 1 to enable MAC to consider trigging invalid_pkt as rx packet Type=00 and subtype=0010. */
#define BIT_SHIFT_RXPSF_MGT1EN                       1
#define BIT_RXPSF_MGT1EN                             ((u32)0x00000001 << BIT_SHIFT_RXPSF_MGT1EN)                       /*!<R/W 0  This bit is set to 1 to enable MAC to consider trigging invalid_pkt as rx packet Type=00 and subtype=0001. */
#define BIT_SHIFT_RXPSF_MGT0EN                       0
#define BIT_RXPSF_MGT0EN                             ((u32)0x00000001 << BIT_SHIFT_RXPSF_MGT0EN)                       /*!<R/W 0  This bit is set to 1 to enable MAC to consider trigging invalid_pkt as rx packet Type=00 and subtype=0000. */

/* REG_WAIT_PHYSTS_CTL 0x1618 */
#define BIT_SHIFT_BB_RST_RESP                        7
#define BIT_BB_RST_RESP                              ((u32)0x00000001 << BIT_SHIFT_BB_RST_RESP)                        /*!<R/W 0  When set to 1��enable bb/rdrdy_err/cca_spoofing to reset mac and will not tx response */
#define BIT_SHIFT_CCA_SPOOFING_EN                    6
#define BIT_CCA_SPOOFING_EN                          ((u32)0x00000001 << BIT_SHIFT_CCA_SPOOFING_EN)                    /*!<R/W 0  When set to 1��enable cca_spoofing reset macrx */
#define BIT_SHIFT_RDRDY_NUM_CHK_EN                   5
#define BIT_RDRDY_NUM_CHK_EN                         ((u32)0x00000001 << BIT_SHIFT_RDRDY_NUM_CHK_EN)                   /*!<R/W 1  When set, enable check rdrdy number is enough or not. If number is not enough will rst macrx */
#define BIT_SHIFT_WAIT_PHYSTS_EN                     4
#define BIT_WAIT_PHYSTS_EN                           ((u32)0x00000001 << BIT_SHIFT_WAIT_PHYSTS_EN)                     /*!<R/W 0  When set to 1��enable wait physts rpt valid function */
#define BIT_SHIFT_WAIT_PHYSTS_TIME                   0
#define BIT_MASK_WAIT_PHYSTS_TIME                    ((u32)0x0000000F << BIT_SHIFT_WAIT_PHYSTS_TIME)                   /*!<R/W 0x4  Wait physts rpt timeout ,unit ��s��6��s is the recommeded value�� */

/* REG_MACID2 0x1620 */
#define BIT_SHIFT_MACID2_V1                          0
#define BIT_MASK_MACID2_V1                           ((u32)0xFFFFFFFF << BIT_SHIFT_MACID2_V1)                          /*!<R/W 0  MAC Identification Number 2 Register */

/* REG_MACID2_H 0x1624 */
#define BIT_SHIFT_MACID2_H_V1                        0
#define BIT_MASK_MACID2_H_V1                         ((u32)0x0000FFFF << BIT_SHIFT_MACID2_H_V1)                        /*!<R/W 0  MAC Identification Number 2 Register */

/* REG_BSSID2 0x1628 */
#define BIT_SHIFT_BSSID2_V1                          0
#define BIT_MASK_BSSID2_V1                           ((u32)0xFFFFFFFF << BIT_SHIFT_BSSID2_V1)                          /*!<R/W 0  Basic Station Set Identification 2 */

/* REG_BSSID2_H 0x162C */
#define BIT_SHIFT_BSSID2_H_V1                        0
#define BIT_MASK_BSSID2_H_V1                         ((u32)0x0000FFFF << BIT_SHIFT_BSSID2_H_V1)                        /*!<R/W 0  Basic Station Set Identification 2 */

/* REG_MACID3 0x1630 */
#define BIT_SHIFT_MACID3_V1                          0
#define BIT_MASK_MACID3_V1                           ((u32)0xFFFFFFFF << BIT_SHIFT_MACID3_V1)                          /*!<R/W 0  MAC Identification Number 3 Register */

/* REG_MACID3_H 0x1634 */
#define BIT_SHIFT_MACID3_H_V1                        0
#define BIT_MASK_MACID3_H_V1                         ((u32)0x0000FFFF << BIT_SHIFT_MACID3_H_V1)                        /*!<R/W 0  MAC Identification Number 3 Register */

/* REG_BSSID3 0x1638 */
#define BIT_SHIFT_BSSID3_V1                          0
#define BIT_MASK_BSSID3_V1                           ((u32)0xFFFFFFFF << BIT_SHIFT_BSSID3_V1)                          /*!<R/W 0  Basic Station Set Identification 3 */

/* REG_BSSID3_H 0x163C */
#define BIT_SHIFT_BSSID3_H_V1                        0
#define BIT_MASK_BSSID3_H_V1                         ((u32)0x0000FFFF << BIT_SHIFT_BSSID3_H_V1)                        /*!<R/W 0  Basic Station Set Identification 3 */

/* REG_MACID4 0x1640 */
#define BIT_SHIFT_MACID4_V1                          0
#define BIT_MASK_MACID4_V1                           ((u32)0xFFFFFFFF << BIT_SHIFT_MACID4_V1)                          /*!<R/W 0  MAC Identification Number 4 Register */

/* REG_MACID4_H 0x1644 */
#define BIT_SHIFT_MACID4_H_V1                        0
#define BIT_MASK_MACID4_H_V1                         ((u32)0x0000FFFF << BIT_SHIFT_MACID4_H_V1)                        /*!<R/W 0  MAC Identification Number 4 Register */

/* REG_BSSID4 0x1648 */
#define BIT_SHIFT_BSSID4_V1                          0
#define BIT_MASK_BSSID4_V1                           ((u32)0xFFFFFFFF << BIT_SHIFT_BSSID4_V1)                          /*!<R/W 0  Basic Station Set Identification 4 */

/* REG_BSSID4_H 0x164C */
#define BIT_SHIFT_BSSID4_H_V1                        0
#define BIT_MASK_BSSID4_H_V1                         ((u32)0x0000FFFF << BIT_SHIFT_BSSID4_H_V1)                        /*!<R/W 0  Basic Station Set Identification 4 */

/* REG_NOA_REPORT 0x1650 */
#define BIT_SHIFT_NOA_RPT                            0
#define BIT_MASK_NOA_RPT                             ((u32)0xFFFFFFFF << BIT_SHIFT_NOA_RPT)                            /*!<R/W 0   */

/* REG_NOA_REPORT_1 0x1654 */
#define BIT_SHIFT_NOA_RPT_1                          0
#define BIT_MASK_NOA_RPT_1                           ((u32)0xFFFFFFFF << BIT_SHIFT_NOA_RPT_1)                          /*!<R/W 0   */

/* REG_NOA_REPORT_2 0x1658 */
#define BIT_SHIFT_NOA_RPT_2                          0
#define BIT_MASK_NOA_RPT_2                           ((u32)0xFFFFFFFF << BIT_SHIFT_NOA_RPT_2)                          /*!<R/W 0   */

/* REG_NOA_REPORT_3 0x165C */
#define BIT_SHIFT_NOA_RPT_3                          0
#define BIT_MASK_NOA_RPT_3                           ((u32)0x000000FF << BIT_SHIFT_NOA_RPT_3)                          /*!<R/W 0   */

/* REG_PWRBIT_SETTING 0x1660 */
#define BIT_SHIFT_CLI3_PWRBIT_OW_EN                  7
#define BIT_CLI3_PWRBIT_OW_EN                        ((u32)0x00000001 << BIT_SHIFT_CLI3_PWRBIT_OW_EN)                  /*!<R/W 0  For client3 (port4). If this bit is set to 1, MAC will overwrite power bit of frame control according to CLI3_PWR_ST. (only for data frame) */
#define BIT_SHIFT_CLI3_PWR_ST                        6
#define BIT_CLI3_PWR_ST                              ((u32)0x00000001 << BIT_SHIFT_CLI3_PWR_ST)                        /*!<R/W 0  For client3 (port4). MAC will overwrite power bit of frame control according to CLI3_PWR_ST.(only for data frame) */
#define BIT_SHIFT_CLI2_PWRBIT_OW_EN                  5
#define BIT_CLI2_PWRBIT_OW_EN                        ((u32)0x00000001 << BIT_SHIFT_CLI2_PWRBIT_OW_EN)                  /*!<R/W 0  For client2 (port3). If this bit is set to 1, MAC will overwrite power bit of frame control according to CLI2_PWR_ST. (only for data frame) */
#define BIT_SHIFT_CLI2_PWR_ST                        4
#define BIT_CLI2_PWR_ST                              ((u32)0x00000001 << BIT_SHIFT_CLI2_PWR_ST)                        /*!<R/W 0  For client2 (port3). MAC will overwrite power bit of frame control according to CLI2_PWR_ST.(only for data frame) */
#define BIT_SHIFT_CLI1_PWRBIT_OW_EN                  3
#define BIT_CLI1_PWRBIT_OW_EN                        ((u32)0x00000001 << BIT_SHIFT_CLI1_PWRBIT_OW_EN)                  /*!<R/W 0  For client1 (port2). If this bit is set to 1, MAC will overwrite power bit of frame control according to CLI1_PWR_ST. (only for data frame) */
#define BIT_SHIFT_CLI1_PWR_ST                        2
#define BIT_CLI1_PWR_ST                              ((u32)0x00000001 << BIT_SHIFT_CLI1_PWR_ST)                        /*!<R/W 0  For client1 (port2). MAC will overwrite power bit of frame control according to CLI1_PWR_ST.(only for data frame) */
#define BIT_SHIFT_CLI0_PWRBIT_OW_EN                  1
#define BIT_CLI0_PWRBIT_OW_EN                        ((u32)0x00000001 << BIT_SHIFT_CLI0_PWRBIT_OW_EN)                  /*!<R/W 0  For client0 (port1). If this bit is set to 1, MAC will overwrite power bit of frame control according to CLI0_PWR_ST. (only for data frame) */
#define BIT_SHIFT_CLI0_PWR_ST                        0
#define BIT_CLI0_PWR_ST                              ((u32)0x00000001 << BIT_SHIFT_CLI0_PWR_ST)                        /*!<R/W 0  For client0 (port1). MAC will overwrite power bit of frame control according to CLI0_PWR_ST.(only for data frame) */

/* REG_GENERAL_OPTION 0x1664 */
#define BIT_SHIFT_EXT_DBGSEL                         6
#define BIT_EXT_DBGSEL                               ((u32)0x00000001 << BIT_SHIFT_EXT_DBGSEL)                         /*!<R/W 0  enable extend dbg port sel */
#define BIT_SHIFT_TXSERV_FIELD_SEL                   2
#define BIT_TXSERV_FIELD_SEL                         ((u32)0x00000001 << BIT_SHIFT_TXSERV_FIELD_SEL)                   /*!<R/W 0   */

/* REG_RXAI_CTRL 0x1668 */
#define BIT_SHIFT_RXAI_INFO_RST                      7
#define BIT_RXAI_INFO_RST                            ((u32)0x00000001 << BIT_SHIFT_RXAI_INFO_RST)                      /*!<R/W 0  Write 1 to reset the RXAI events */
#define BIT_SHIFT_RXAI_PRTCT_REL                     6
#define BIT_RXAI_PRTCT_REL                           ((u32)0x00000001 << BIT_SHIFT_RXAI_PRTCT_REL)                     /*!<RO 0  If MAC_reset_protect is set to 0 by MAC decision circuit (address/A-MPDU checking), set this bit to 1. Reset by BIT_RXAI_INFO_RST = 1 */
#define BIT_SHIFT_RXAI_PRTCT_VIO                     5
#define BIT_RXAI_PRTCT_VIO                           ((u32)0x00000001 << BIT_SHIFT_RXAI_PRTCT_VIO)                     /*!<RO 0  If MAC gets BB_reset_MAC pulse when MAC_reset_protect = 1, set this bit to 1. Reset by BIT_RXAI_INFO_RST = 1 */
#define BIT_SHIFT_RXAI_PRTCT_SEL                     2
#define BIT_RXAI_PRTCT_SEL                           ((u32)0x00000001 << BIT_SHIFT_RXAI_PRTCT_SEL)                     /*!<R/W 0  MAC_reset_protect rises at 0: DATA_ON rises 1: PLCP check OK (OFDM/CCK) or receiving 3rd/2nd (VHT/HT) RDRDY */
#define BIT_SHIFT_RXAI_AGG_CHKEN                     1
#define BIT_RXAI_AGG_CHKEN                           ((u32)0x00000001 << BIT_SHIFT_RXAI_AGG_CHKEN)                     /*!<R/W 0  This bit is only workable when BIT_RXAI_ADDR_CHKEN = 1. 1: if and only if the receiving address matched PPDU is A-MPDU and is not VHT single MPDU, then MAC inform BB not doing reCCA. */
#define BIT_SHIFT_RXAI_ADDR_CHKEN                    0
#define BIT_RXAI_ADDR_CHKEN                          ((u32)0x00000001 << BIT_SHIFT_RXAI_ADDR_CHKEN)                    /*!<R/W 0  This bit is set to 1 to enable MAC to inform BB not doing reCCA during receiving the address matched PPDU. */

/* REG_RX_BCN_TM 0x166C */
#define BIT_SHIFT_RX_BCN_TIMER                       0
#define BIT_MASK_RX_BCN_TIMER                        ((u32)0x0000FFFF << BIT_SHIFT_RX_BCN_TIMER)                       /*!<R/W 0  indicate rx beacon timer from cca up to fcs ok, units us */

/* REG_CSI_RRSR 0x1678 */
#define BIT_SHIFT_CSI_LDPC_EN                        29
#define BIT_CSI_LDPC_EN                              ((u32)0x00000001 << BIT_SHIFT_CSI_LDPC_EN)                        /*!<R/W 0  Enable LDPC in Tx CSI Frame */
#define BIT_SHIFT_CSI_STBC_EN                        28
#define BIT_CSI_STBC_EN                              ((u32)0x00000001 << BIT_SHIFT_CSI_STBC_EN)                        /*!<R/W 0  Enable STBC in Tx CSI Frame */
#define BIT_SHIFT_CSI_RRSC_BITMAP                    4
#define BIT_MASK_CSI_RRSC_BITMAP                     ((u32)0x00FFFFFF << BIT_SHIFT_CSI_RRSC_BITMAP)                    /*!<R/W 0  BitMap to indicate the CSI frame rate in this BSS. Each bit is mapped as the following: Bit[4:11] = {6M, 9M, 12M, 18M, 24M, 36M, 48M, 54M} Bit[12:19] = HT MCS0~MCS7 BIT[27:20] = VHT 1SSMCS0~7 The modulation of response rate must be less than or equal to the rate of the initiating frame. If none of the bits are set, no response is generated by Rtl8712. If both legacy rates and HT rates are defined as Basic Rates, fill in only the legacy portion of the bitmap. If only HT rates are defined as Basic Rates, fill in both the legacy and HT portion of the bitmap. */
#define BIT_SHIFT_OFDM_LEN_TH                        0
#define BIT_MASK_OFDM_LEN_TH                         ((u32)0x0000000F << BIT_SHIFT_OFDM_LEN_TH)                        /*!<R/W 0  CSI frame length threshold for using legacy OFDM (unit: 128B). 0 means disabled. If CSI frame length > threshold, search from VHT or HT bitmap If CSI frame length < threshold, search from legacy OFDM bitmap */

/* REG_MU_BF_OPTION 0x167C */
#define BIT_SHIFT_WMAC_RESP_NONSTA1_DIS              7
#define BIT_WMAC_RESP_NONSTA1_DIS                    ((u32)0x00000001 << BIT_SHIFT_WMAC_RESP_NONSTA1_DIS)              /*!<R/W 0  Disable response BA when receive non-STA1 user position MU PPDU */
#define BIT_SHIFT_WMAC_MU_BFEE_PORT_SEL              1
#define BIT_MASK_WMAC_MU_BFEE_PORT_SEL               ((u32)0x00000007 << BIT_SHIFT_WMAC_MU_BFEE_PORT_SEL)              /*!<R/W 0  Enable software to set initial state of MU arbiter */
#define BIT_SHIFT_WMAC_MU_BFEE_DIS                   0
#define BIT_WMAC_MU_BFEE_DIS                         ((u32)0x00000001 << BIT_SHIFT_WMAC_MU_BFEE_DIS)                   /*!<R/W 0  If set to 1, HW will be SU only beamformee and not response to NDPA or Beamforming report poll. */

/* REG_WMAC_PAUSE_BB_CLR_TH 0x167D */
#define BIT_SHIFT_WMAC_PAUSE_BB_CLR_TH               0
#define BIT_MASK_WMAC_PAUSE_BB_CLR_TH                ((u32)0x000000FF << BIT_SHIFT_WMAC_PAUSE_BB_CLR_TH)               /*!<R/W 8'h48  MAC_PAUSE_BB High to Low clear threshold of csidma syncff read-write pointer */

/* REG_WMAC_ARB_CLR 0x167E */
#define BIT_SHIFT_ARB_HW_ADAPT_EN                    7
#define BIT_ARB_HW_ADAPT_EN                          ((u32)0x00000001 << BIT_SHIFT_ARB_HW_ADAPT_EN)                    /*!<R/W 0  Enable hardware to arbitrate data according to rate offset of user0 and user1 */
#define BIT_SHIFT_ARB_SW_EN                          6
#define BIT_ARB_SW_EN                                ((u32)0x00000001 << BIT_SHIFT_ARB_SW_EN)                          /*!<R/W 0  Enable software to set initial state of MU arbiter */
#define BIT_SHIFT_ARB_SW_STATE                       0
#define BIT_MASK_ARB_SW_STATE                        ((u32)0x0000003F << BIT_SHIFT_ARB_SW_STATE)                       /*!<R/W 0  MU arbiter software initial state */

/* REG_WMAC_MU_OPTION 0x167F */
#define BIT_SHIFT_WMAC_NOCHK_BFPOLL_BMP              7
#define BIT_WMAC_NOCHK_BFPOLL_BMP                    ((u32)0x00000001 << BIT_SHIFT_WMAC_NOCHK_BFPOLL_BMP)              /*!<R/W 0  Set this bit to ignore retransmission bitmap of rx beamforming report poll */
#define BIT_SHIFT_WMAC_CSI_PARA_RDY_DLYCNT           0
#define BIT_MASK_WMAC_CSI_PARA_RDY_DLYCNT            ((u32)0x0000001F << BIT_SHIFT_WMAC_CSI_PARA_RDY_DLYCNT)           /*!<R/W 0x1F  1:Cycle number from txctl state machine IDLE(VBON falling) to CSI_standby falling. 2:Half of this value is txctl state machine IDLE(VBON falling) to CSI_parameter_ready rising cycle number. */

/* REG_WMAC_MU_BF_CTL 0x1680 */
#define BIT_SHIFT_WMAC_INVLD_BFPRT_CHK               15
#define BIT_WMAC_INVLD_BFPRT_CHK                     ((u32)0x00000001 << BIT_SHIFT_WMAC_INVLD_BFPRT_CHK)               /*!<R/W 0  Check invalid case of received beamforming report */
#define BIT_SHIFT_WMAC_RETXBFRPTSEQ_UPD              14
#define BIT_WMAC_RETXBFRPTSEQ_UPD                    ((u32)0x00000001 << BIT_SHIFT_WMAC_RETXBFRPTSEQ_UPD)              /*!<R/W 0  Update sequence number and not set retry bit when retransmit beamforming report. */
#define BIT_SHIFT_WMAC_MU_BFRPTSEG_SEL               12
#define BIT_MASK_WMAC_MU_BFRPTSEG_SEL                ((u32)0x00000003 << BIT_SHIFT_WMAC_MU_BFRPTSEG_SEL)               /*!<R/W 0  Beamforming report segment length select 2'h00 :3895 bytes(also means csi segmentation enable),2'h01:7991bytes, 2'h10:11454bytes */
#define BIT_SHIFT_WMAC_MU_BF_MYAID                   0
#define BIT_MASK_WMAC_MU_BF_MYAID                    ((u32)0x00000FFF << BIT_SHIFT_WMAC_MU_BF_MYAID)                   /*!<R/W 0  When I'm one of Bfees, my AID12 to identify STA_info in NDPA */

/* REG_WMAC_MU_BFRPT_PARA 0x1682 */
#define BIT_SHIFT_BFRPT_PARA_USERID_SEL_V1           13
#define BIT_MASK_BFRPT_PARA_USERID_SEL_V1            ((u32)0x00000007 << BIT_SHIFT_BFRPT_PARA_USERID_SEL_V1)           /*!<R/W 0  User ID of associated Bfee, MU: 2~7 ,SU:0~1 */
#define BIT_SHIFT_BFRPT_PARA_V1                      0
#define BIT_MASK_BFRPT_PARA_V1                       ((u32)0x00001FFF << BIT_SHIFT_BFRPT_PARA_V1)                      /*!<R 0  CSI report parameter of selected user ID BFee {bw[1:0],cb[1:0],ng[1:0],nr[2:0],nc[2:0]} ; */

/* REG_WMAC_ASSOCIATED_MU_BFMEE2 0x1684 */
#define BIT_SHIFT_STATUS_BFEE2                       10
#define BIT_STATUS_BFEE2                             ((u32)0x00000001 << BIT_SHIFT_STATUS_BFEE2)                       /*!<R 0  beamforming report status of beamformee2 0: fail, 1: success */
#define BIT_SHIFT_WMAC_MU_BFEE2_EN                   9
#define BIT_WMAC_MU_BFEE2_EN                         ((u32)0x00000001 << BIT_SHIFT_WMAC_MU_BFEE2_EN)                   /*!<R/W 0  If enabled, NDPA/BF-rpt-poll would be sent to beamformee2, and CSI rpt of beamformee2 can be read from 0x1682[11:0] when 0x1682[14:12] is 2 */
#define BIT_SHIFT_WMAC_MU_BFEE2_AID                  0
#define BIT_MASK_WMAC_MU_BFEE2_AID                   ((u32)0x000001FF << BIT_SHIFT_WMAC_MU_BFEE2_AID)                  /*!<R/W 0  P_AID of the target beamformee2 */

/* REG_WMAC_ASSOCIATED_MU_BFMEE3 0x1686 */
#define BIT_SHIFT_STATUS_BFEE3                       10
#define BIT_STATUS_BFEE3                             ((u32)0x00000001 << BIT_SHIFT_STATUS_BFEE3)                       /*!<R 0  beamforming report status of beamformee3 0: fail, 1: success */
#define BIT_SHIFT_WMAC_MU_BFEE3_EN                   9
#define BIT_WMAC_MU_BFEE3_EN                         ((u32)0x00000001 << BIT_SHIFT_WMAC_MU_BFEE3_EN)                   /*!<R/W 0  If enabled, NDPA/BF-rpt-poll would be sent to beamformee3, and CSI rpt of beamformee3 can be read from 0x1682[11:0] when 0x1682[14:12] is 3 */
#define BIT_SHIFT_WMAC_MU_BFEE3_AID                  0
#define BIT_MASK_WMAC_MU_BFEE3_AID                   ((u32)0x000001FF << BIT_SHIFT_WMAC_MU_BFEE3_AID)                  /*!<R/W 0  P_AID of the target beamformee3 */

/* REG_WMAC_ASSOCIATED_MU_BFMEE4 0x1688 */
#define BIT_SHIFT_STATUS_BFEE4                       10
#define BIT_STATUS_BFEE4                             ((u32)0x00000001 << BIT_SHIFT_STATUS_BFEE4)                       /*!<R 0  beamforming report status of beamformee4 0: fail, 1: success */
#define BIT_SHIFT_WMAC_MU_BFEE4_EN                   9
#define BIT_WMAC_MU_BFEE4_EN                         ((u32)0x00000001 << BIT_SHIFT_WMAC_MU_BFEE4_EN)                   /*!<R/W 0  If enabled, NDPA/BF-rpt-poll would be sent to beamformee4, and CSI rpt of beamformee4 can be read from 0x1682[11:0] when 0x1682[14:12] is 4 */
#define BIT_SHIFT_WMAC_MU_BFEE4_AID                  0
#define BIT_MASK_WMAC_MU_BFEE4_AID                   ((u32)0x000001FF << BIT_SHIFT_WMAC_MU_BFEE4_AID)                  /*!<R/W 0  P_AID of the target beamformee4 */

/* REG_WMAC_ASSOCIATED_MU_BFMEE5 0x168A */
#define BIT_SHIFT_BIT_STATUS_BFEE5                   10
#define BIT_BIT_STATUS_BFEE5                         ((u32)0x00000001 << BIT_SHIFT_BIT_STATUS_BFEE5)                   /*!<R 0  beamforming report status of beamformee5 0: fail 1: success */
#define BIT_SHIFT_WMAC_MU_BFEE5_EN                   9
#define BIT_WMAC_MU_BFEE5_EN                         ((u32)0x00000001 << BIT_SHIFT_WMAC_MU_BFEE5_EN)                   /*!<R/W 0  If enabled, NDPA/BF-rpt-poll would be sent to beamformee5, and CSI rpt of beamformee5 can be read from 0x1682[11:0] when 0x1682[14:12] is 5 */
#define BIT_SHIFT_WMAC_MU_BFEE5_AID                  0
#define BIT_MASK_WMAC_MU_BFEE5_AID                   ((u32)0x000001FF << BIT_SHIFT_WMAC_MU_BFEE5_AID)                  /*!<R/W 0  P_AID of the target beamformee5 */

/* REG_WMAC_ASSOCIATED_MU_BFMEE6 0x168C */
#define BIT_SHIFT_STATUS_BFEE6                       10
#define BIT_STATUS_BFEE6                             ((u32)0x00000001 << BIT_SHIFT_STATUS_BFEE6)                       /*!<R 0  beamforming report status of beamformee6 0: fail 1: success */
#define BIT_SHIFT_WMAC_MU_BFEE6_EN                   9
#define BIT_WMAC_MU_BFEE6_EN                         ((u32)0x00000001 << BIT_SHIFT_WMAC_MU_BFEE6_EN)                   /*!<R/W 0  If enabled, NDPA/BF-rpt-poll would be sent to beamformee6, and CSI rpt of beamformee6 can be read from 0x1682[11:0] when 0x1682[14:12] is 6 */
#define BIT_SHIFT_WMAC_MU_BFEE6_AID                  0
#define BIT_MASK_WMAC_MU_BFEE6_AID                   ((u32)0x000001FF << BIT_SHIFT_WMAC_MU_BFEE6_AID)                  /*!<R/W 0  P_AID of the target beamformee6 */

/* REG_WMAC_ASSOCIATED_MU_BFMEE7 0x168E */
#define BIT_SHIFT_STATUS_BFEE7                       10
#define BIT_STATUS_BFEE7                             ((u32)0x00000001 << BIT_SHIFT_STATUS_BFEE7)                       /*!<R 0  beamforming report status of beamformee7 0: fail 1: success */
#define BIT_SHIFT_WMAC_MU_BFEE7_EN                   9
#define BIT_WMAC_MU_BFEE7_EN                         ((u32)0x00000001 << BIT_SHIFT_WMAC_MU_BFEE7_EN)                   /*!<R/W 0  If enabled, NDPA/BF-rpt-poll would be sent to beamformee7, and CSI rpt of beamformee7 can be read from 0x1682[11:0] when 0x1682[14:12] is 7 */
#define BIT_SHIFT_WMAC_MU_BFEE7_AID                  0
#define BIT_MASK_WMAC_MU_BFEE7_AID                   ((u32)0x000001FF << BIT_SHIFT_WMAC_MU_BFEE7_AID)                  /*!<R/W 0  P_AID of the target beamformee7 */

/* REG_WMAC_BB_STOP_RX_COUNTER 0x1690 */
#define BIT_SHIFT_RST_ALL_COUNTER                    31
#define BIT_RST_ALL_COUNTER                          ((u32)0x00000001 << BIT_SHIFT_RST_ALL_COUNTER)                    /*!<W1C 0  Write one to reset all counters to zero. */
#define BIT_SHIFT_ABORT_RX_VBON_COUNTER              16
#define BIT_MASK_ABORT_RX_VBON_COUNTER               ((u32)0x000000FF << BIT_SHIFT_ABORT_RX_VBON_COUNTER)              /*!<R 0  Increase when mac_abort_rx_vbon trigger. 0x120[29] / 0x124[29] : BB_STOP_RX mask/interrupt 0x0B8[0] / 0x0BC[0] : BB_STOP_RX mask/interrupt Interrupts will be trigger when mac detect any counter of 0x1690 increase. */
#define BIT_SHIFT_ABORT_RX_RDRDY_COUNTER             8
#define BIT_MASK_ABORT_RX_RDRDY_COUNTER              ((u32)0x000000FF << BIT_SHIFT_ABORT_RX_RDRDY_COUNTER)             /*!<R 0  Increase when mac_abort_rx_rdrdy trigger 0x120[29] / 0x124[29] : BB_STOP_RX mask/interrupt 0x0B8[0] / 0x0BC[0] : BB_STOP_RX mask/interrupt Interrupts will be trigger when mac detect any counter of 0x1690 increase. */
#define BIT_SHIFT_VBON_EARLY_FALLING_COUNTER         0
#define BIT_MASK_VBON_EARLY_FALLING_COUNTER          ((u32)0x000000FF << BIT_SHIFT_VBON_EARLY_FALLING_COUNTER)         /*!<R 0  Increase when VBON fall & no rx plcp error & rx_parser is waiting for rdrdy which is expected but not received . 0x120[29] / 0x124[29] : BB_STOP_RX mask/interrupt 0x0B8[0] / 0x0BC[0] : BB_STOP_RX mask/interrupt Interrupts will be trigger when mac detect any counter of 0x1690 increase. */

/* REG_WMAC_PLCP_MONITOR 0x1694 */
#define BIT_SHIFT_WMAC_PLCP_TRX_SEL                  31
#define BIT_WMAC_PLCP_TRX_SEL                        ((u32)0x00000001 << BIT_SHIFT_WMAC_PLCP_TRX_SEL)                  /*!<R/W 0  Selection of Tx/Rx plcp header 0:Rx 1:Tx */
#define BIT_SHIFT_WMAC_PLCP_RDSIG_SEL                28
#define BIT_MASK_WMAC_PLCP_RDSIG_SEL                 ((u32)0x00000007 << BIT_SHIFT_WMAC_PLCP_RDSIG_SEL)                /*!<R/W 0  Selection of plcp header signal field 0:LSIG 1:HTSIG1/VHTSIGA1 2:HTSIG2/VHTSIGA2 3:VHTSIGB 4: SERVICE field */
#define BIT_SHIFT_WMAC_RATE_IDX                      24
#define BIT_MASK_WMAC_RATE_IDX                       ((u32)0x0000000F << BIT_SHIFT_WMAC_RATE_IDX)                      /*!<R 0  4'b0001 : CCK rate 4'b0010 : OFDM rate 4'b0110 : HT rate 4'b1010 : VHT rate */
#define BIT_SHIFT_WMAC_PLCP_RDSIG                    0
#define BIT_MASK_WMAC_PLCP_RDSIG                     ((u32)0x00FFFFFF << BIT_SHIFT_WMAC_PLCP_RDSIG)                    /*!<R 0  Selected signal field to read out */

/* REG_WMAC_CSIDMA_CFG 0x169C */
#define BIT_SHIFT_CSI_SEG_SIZE                       16
#define BIT_MASK_CSI_SEG_SIZE                        ((u32)0x00000FFF << BIT_SHIFT_CSI_SEG_SIZE)                       /*!<R/W 0xF16  CSI data segmentation size (bytes) = Max. MPDU length - mac hdr (24) - act type (1) - category (1) �C mimo ctrl (3) �C FCS (4) */
#define BIT_SHIFT_CSI_START_PAGE                     0
#define BIT_MASK_CSI_START_PAGE                      ((u32)0x00000FFF << BIT_SHIFT_CSI_START_PAGE)                     /*!<R/W 0x7CE  The starting page number of csi buffer in TXPKTBUF */

/* REG_TRANSMIT_ADDRSS_0 0x16A0 */
#define BIT_SHIFT_TA0_V1                             0
#define BIT_MASK_TA0_V1                              ((u32)0xFFFFFFFF << BIT_SHIFT_TA0_V1)                             /*!<R/W 0  Transmitter address for port 0 */

/* REG_TRANSMIT_ADDRSS_0_H 0x16A4 */
#define BIT_SHIFT_TA0_H_V1                           0
#define BIT_MASK_TA0_H_V1                            ((u32)0x0000FFFF << BIT_SHIFT_TA0_H_V1)                           /*!<R/W 0  Transmitter address for port 0 */

/* REG_TRANSMIT_ADDRSS_1 0x16A8 */
#define BIT_SHIFT_TA1_V1                             0
#define BIT_MASK_TA1_V1                              ((u32)0xFFFFFFFF << BIT_SHIFT_TA1_V1)                             /*!<R/W 0  Transmitter address for port 1 */

/* REG_TRANSMIT_ADDRSS_1_H 0x16AC */
#define BIT_SHIFT_TA1_H_V1                           0
#define BIT_MASK_TA1_H_V1                            ((u32)0x0000FFFF << BIT_SHIFT_TA1_H_V1)                           /*!<R/W 0  Transmitter address for port 1 */

/* REG_TRANSMIT_ADDRSS_2 0x16B0 */
#define BIT_SHIFT_TA2_V1                             0
#define BIT_MASK_TA2_V1                              ((u32)0xFFFFFFFF << BIT_SHIFT_TA2_V1)                             /*!<R/W 0  Transmitter address for port 2 */

/* REG_TRANSMIT_ADDRSS_2_H 0x16B4 */
#define BIT_SHIFT_TA2_H_V1                           0
#define BIT_MASK_TA2_H_V1                            ((u32)0x0000FFFF << BIT_SHIFT_TA2_H_V1)                           /*!<R/W 0  Transmitter address for port 2 */

/* REG_TRANSMIT_ADDRSS_3 0x16B8 */
#define BIT_SHIFT_TA3_V1                             0
#define BIT_MASK_TA3_V1                              ((u32)0xFFFFFFFF << BIT_SHIFT_TA3_V1)                             /*!<R/W 0  Transmitter address for port 3 */

/* REG_TRANSMIT_ADDRSS_3_H 0x16BC */
#define BIT_SHIFT_TA3_H_V1                           0
#define BIT_MASK_TA3_H_V1                            ((u32)0x0000FFFF << BIT_SHIFT_TA3_H_V1)                           /*!<R/W 0  Transmitter address for port 3 */

/* REG_TRANSMIT_ADDRSS_4 0x16C0 */
#define BIT_SHIFT_TA4_V1                             0
#define BIT_MASK_TA4_V1                              ((u32)0xFFFFFFFF << BIT_SHIFT_TA4_V1)                             /*!<R/W 0  Transmitter address for port 4 */

/* REG_TRANSMIT_ADDRSS_4_H 0x16C4 */
#define BIT_SHIFT_TA4_H_V1                           0
#define BIT_MASK_TA4_H_V1                            ((u32)0x0000FFFF << BIT_SHIFT_TA4_H_V1)                           /*!<R/W 0  Transmitter address for port 4 */

/* REG_NAN_FUN 0x16C8 */
#define BIT_SHIFT_R_WMAC_ATTRI_ID1                   24
#define BIT_MASK_R_WMAC_ATTRI_ID1                    ((u32)0x000000FF << BIT_SHIFT_R_WMAC_ATTRI_ID1)                   /*!<R/W 0  the NAN attribute whose ID is r_WMAC_ATTRI_ID1 will be written into NAN beacon report */
#define BIT_SHIFT_R_WMAC_ATTRI_ID0                   16
#define BIT_MASK_R_WMAC_ATTRI_ID0                    ((u32)0x000000FF << BIT_SHIFT_R_WMAC_ATTRI_ID0)                   /*!<R/W 0  the NAN attribute whose ID is r_WMAC_ATTRI_ID0 will be written into NAN beacon report */
#define BIT_SHIFT_R_WMAC_ATTRI_IDI_VLD               8
#define BIT_MASK_R_WMAC_ATTRI_IDI_VLD                ((u32)0x0000001F << BIT_SHIFT_R_WMAC_ATTRI_IDI_VLD)               /*!<R/W 0  valid flag bitmap of r_WMAC_ATTRI_IDi */
#define BIT_SHIFT_R_TXRPT_NAN_ENTRY_NUM              4
#define BIT_MASK_R_TXRPT_NAN_ENTRY_NUM               ((u32)0x00000007 << BIT_SHIFT_R_TXRPT_NAN_ENTRY_NUM)              /*!<R/W 0  number of NAN beacon report entry in txrptbuffer */
#define BIT_SHIFT_R_NAN_ENTRY_SIZE                   1
#define BIT_MASK_R_NAN_ENTRY_SIZE                    ((u32)0x00000007 << BIT_SHIFT_R_NAN_ENTRY_SIZE)                   /*!<R/W 0  size of one NAN beacon report entry, unit is 8byte */
#define BIT_SHIFT_R_WMAC_RXNANPSR_EN                 0
#define BIT_R_WMAC_RXNANPSR_EN                       ((u32)0x00000001 << BIT_SHIFT_R_WMAC_RXNANPSR_EN)                 /*!<R/W 0  parse enable of rx NAN sync beacon */

/* REG_NAN_CTL 0x16CC */
#define BIT_SHIFT_R_TXRPT_NAN_ENTRY_FLAG             24
#define BIT_MASK_R_TXRPT_NAN_ENTRY_FLAG              ((u32)0x000000FF << BIT_SHIFT_R_TXRPT_NAN_ENTRY_FLAG)             /*!<R/W 0  indicate NAN beacon report(i) in txrptbuffer is valid, it is set by HW and clear by FW */
#define BIT_SHIFT_R_WMAC_ATTRI_ID4                   16
#define BIT_MASK_R_WMAC_ATTRI_ID4                    ((u32)0x000000FF << BIT_SHIFT_R_WMAC_ATTRI_ID4)                   /*!<R/W 0  the NAN attribute whose ID is r_WMAC_ATTRI_ID4 will be written into NAN beacon report */
#define BIT_SHIFT_R_WMAC_ATTRI_ID3                   8
#define BIT_MASK_R_WMAC_ATTRI_ID3                    ((u32)0x000000FF << BIT_SHIFT_R_WMAC_ATTRI_ID3)                   /*!<R/W 0  the NAN attribute whose ID is r_WMAC_ATTRI_ID3 will be written into NAN beacon report */
#define BIT_SHIFT_R_WMAC_ATTRI_ID2                   0
#define BIT_MASK_R_WMAC_ATTRI_ID2                    ((u32)0x000000FF << BIT_SHIFT_R_WMAC_ATTRI_ID2)                   /*!<R/W 0  the NAN attribute whose ID is r_WMAC_ATTRI_ID2 will be written into NAN beacon report */

/* REG_NAN_ADDR_FILTER 0x16D0 */
#define BIT_SHIFT_R_RX_NAN_ADDR_FILTER_EN            13
#define BIT_R_RX_NAN_ADDR_FILTER_EN                  ((u32)0x00000001 << BIT_SHIFT_R_RX_NAN_ADDR_FILTER_EN)            /*!<R/W 0  enable of rx nan beacon address filter */
#define BIT_SHIFT_R_NAN_START_ADDR_OFFSET            0
#define BIT_MASK_R_NAN_START_ADDR_OFFSET             ((u32)0x00001FFF << BIT_SHIFT_R_NAN_START_ADDR_OFFSET)            /*!<R/W 0  Start offset Location of NAN beacon report FIFO. Unit: 8bytes */

/* REG_NAN_ADDR 0x16D4 */
#define BIT_SHIFT_R_RX_NAN_ADDR_FILTER               0
#define BIT_MASK_R_RX_NAN_ADDR_FILTER                ((u32)0xFFFFFFFF << BIT_SHIFT_R_RX_NAN_ADDR_FILTER)               /*!<R/W 0  bitmap for rx nan beacon address filter */

/* REG_BCN_IEPSR0 0x16D8 */
#define BIT_SHIFT_R_WMAC_BCN_CLR_N                   30
#define BIT_R_WMAC_BCN_CLR_N                         ((u32)0x00000001 << BIT_SHIFT_R_WMAC_BCN_CLR_N)                   /*!<R/W 0  enable clear macbssid indicator when no multiple BSSID element is found. */
#define BIT_SHIFT_R_WMAC_BCN_IE1_PSR                 29
#define BIT_R_WMAC_BCN_IE1_PSR                       ((u32)0x00000001 << BIT_SHIFT_R_WMAC_BCN_IE1_PSR)                 /*!<R/W 0  enable parser specified ie 1 element */
#define BIT_SHIFT_R_WMAC_BCN_IE0_PSR                 28
#define BIT_R_WMAC_BCN_IE0_PSR                       ((u32)0x00000001 << BIT_SHIFT_R_WMAC_BCN_IE0_PSR)                 /*!<R/W 0  enable parser specified ie0 element */
#define BIT_SHIFT_R_WMAC_BCN_MBSSID_PSR              27
#define BIT_R_WMAC_BCN_MBSSID_PSR                    ((u32)0x00000001 << BIT_SHIFT_R_WMAC_BCN_MBSSID_PSR)              /*!<R/W 0  enable parser multiple BSSID element */
#define BIT_SHIFT_R_WMAC_BCN_SW_MBSSID               26
#define BIT_R_WMAC_BCN_SW_MBSSID                     ((u32)0x00000001 << BIT_SHIFT_R_WMAC_BCN_SW_MBSSID)               /*!<R/W 0  enable the MaxBSSID indicator value from SW */
#define BIT_SHIFT_R_WMAC_BCN_MBSSID_N                18
#define BIT_MASK_R_WMAC_BCN_MBSSID_N                 ((u32)0x000000FF << BIT_SHIFT_R_WMAC_BCN_MBSSID_N)                /*!<R/W 0  SW write the value of MaxBSSID Indicator field */
#define BIT_SHIFT_R_WMAC_BCN_ID1_EXT                 17
#define BIT_R_WMAC_BCN_ID1_EXT                       ((u32)0x00000001 << BIT_SHIFT_R_WMAC_BCN_ID1_EXT)                 /*!<R/W 0  indicate current ie is the extend element which need to parser extend id field */
#define BIT_SHIFT_R_WMAC_BCN_IE_ID1                  9
#define BIT_MASK_R_WMAC_BCN_IE_ID1                   ((u32)0x000000FF << BIT_SHIFT_R_WMAC_BCN_IE_ID1)                  /*!<R/W 0  specified Element ID, set corresponding interrupt when it is parsed */
#define BIT_SHIFT_R_WMAC_BCN_ID0_EXT                 8
#define BIT_R_WMAC_BCN_ID0_EXT                       ((u32)0x00000001 << BIT_SHIFT_R_WMAC_BCN_ID0_EXT)                 /*!<R/W 0  indicate current ie is the extend element which need to parser extend id field */
#define BIT_SHIFT_R_WMAC_BCN_IE_ID0                  0
#define BIT_MASK_R_WMAC_BCN_IE_ID0                   ((u32)0x000000FF << BIT_SHIFT_R_WMAC_BCN_IE_ID0)                  /*!<R/W 0  specified Element ID, set corresponding interrupt when it is parsed */

/* REG_BCN_IEPSR1 0x16DC */
#define BIT_SHIFT_R_WMAC_BCN_MBSSID_OFS              16
#define BIT_MASK_R_WMAC_BCN_MBSSID_OFS               ((u32)0x0000FFFF << BIT_SHIFT_R_WMAC_BCN_MBSSID_OFS)              /*!<R 0  the multiple bssid element offset (byte unit) in frame body */
#define BIT_SHIFT_R_WMAC_BCN_N0_CHG                  15
#define BIT_R_WMAC_BCN_N0_CHG                        ((u32)0x00000001 << BIT_SHIFT_R_WMAC_BCN_N0_CHG)                  /*!<R 0  indicate parsed maxmbssid indicator field value has changed which leads to the change of N0. */
#define BIT_SHIFT_R_WMAC_BCN_MBSSID_VAL              14
#define BIT_R_WMAC_BCN_MBSSID_VAL                    ((u32)0x00000001 << BIT_SHIFT_R_WMAC_BCN_MBSSID_VAL)              /*!<R 0  indicate ofs and n0 change bit is valid. */
#define BIT_SHIFT_R_WMAC_BCN_MBSSID_IDX              0
#define BIT_MASK_R_WMAC_BCN_MBSSID_IDX               ((u32)0x000000FF << BIT_SHIFT_R_WMAC_BCN_MBSSID_IDX)              /*!<R/W 0  the multiple bssid index that current sta connect with */

/* REG_CHINFO_ADDR 0x16E0 */
#define BIT_SHIFT_R_CHINFO_TX_ADDR_L                 0
#define BIT_MASK_R_CHINFO_TX_ADDR_L                  ((u32)0xFFFFFFFF << BIT_SHIFT_R_CHINFO_TX_ADDR_L)                 /*!<R/W 0  low 32bit tx address for trigger channel info */

/* REG_CHINFO_CFG 0x16E4 */
#define BIT_SHIFT_R_CHINFO_WTM_OUT                   27
#define BIT_R_CHINFO_WTM_OUT                         ((u32)0x00000001 << BIT_SHIFT_R_CHINFO_WTM_OUT)                   /*!<R/W1C 0  BB does��t send channel info when timeout occur */
#define BIT_SHIFT_R_CHINFO_TIME_OUT                  26
#define BIT_R_CHINFO_TIME_OUT                        ((u32)0x00000001 << BIT_SHIFT_R_CHINFO_TIME_OUT)                  /*!<R/W1C 0  BB send channel info length is less than report length */
#define BIT_SHIFT_R_CSI_BUFF_FULL                    25
#define BIT_R_CSI_BUFF_FULL                          ((u32)0x00000001 << BIT_SHIFT_R_CSI_BUFF_FULL)                    /*!<R/W1C 0  Indicate rxcsibuff full occur */
#define BIT_SHIFT_R_CHINFO_TIMER                     22
#define BIT_MASK_R_CHINFO_TIMER                      ((u32)0x00000007 << BIT_SHIFT_R_CHINFO_TIMER)                     /*!<R/W 0x4  Wait timeout value, unit 4 mac clock cycles */
#define BIT_SHIFT_R_CHINFO_MGNT                      21
#define BIT_R_CHINFO_MGNT                            ((u32)0x00000001 << BIT_SHIFT_R_CHINFO_MGNT)                      /*!<R/W 0  management frame will trigger channel info. Valid when r_CHINFO_EN is 1. */
#define BIT_SHIFT_R_CHINFO_CTRL                      20
#define BIT_R_CHINFO_CTRL                            ((u32)0x00000001 << BIT_SHIFT_R_CHINFO_CTRL)                      /*!<R/W 0  control frame will trigger channel info. Valid when r_CHINFO_EN is 1. */
#define BIT_SHIFT_R_CHINFO_DATA                      19
#define BIT_R_CHINFO_DATA                            ((u32)0x00000001 << BIT_SHIFT_R_CHINFO_DATA)                      /*!<R/W 0  data frame will trigger channel info. Valid when r_CHINFO_EN is 1. */
#define BIT_SHIFT_R_CHINFO_MODE                      17
#define BIT_MASK_R_CHINFO_MODE                       ((u32)0x00000003 << BIT_SHIFT_R_CHINFO_MODE)                      /*!<R/W 0  channel info mode setting. 1: enable normal rx trigger; 2: enable ndpa trigger; note: repsonse mode decided by tx descriptor. Valid when r_CHINFO_EN is 1. */
#define BIT_SHIFT_R_CHINFO_EN                        16
#define BIT_R_CHINFO_EN                              ((u32)0x00000001 << BIT_SHIFT_R_CHINFO_EN)                        /*!<R/W 0  enable for getting channel info from BB. When set to 0, will not trigger channel info function */
#define BIT_SHIFT_R_CHINFO_TX_ADDR_H                 0
#define BIT_MASK_R_CHINFO_TX_ADDR_H                  ((u32)0x0000FFFF << BIT_SHIFT_R_CHINFO_TX_ADDR_H)                 /*!<R/W 0  high 16 bits tx address for trigger channel info */

/* REG_RXCSIBUF_CFG 0x16E8 */
#define BIT_SHIFT_R_CSIBUF_THRESHOD                  8
#define BIT_MASK_R_CSIBUF_THRESHOD                   ((u32)0x0000000F << BIT_SHIFT_R_CSIBUF_THRESHOD)                  /*!<R/W 0x4  rxcsibuffer full threshold, size must greater than or equal to csi descriptors */
#define BIT_SHIFT_R_CSIBUF_ENDADDR                   0
#define BIT_MASK_R_CSIBUF_ENDADDR                    ((u32)0x000000FF << BIT_SHIFT_R_CSIBUF_ENDADDR)                   /*!<R/W 0xFF  End address of rxcsibuffer, unit 8bytes. Rxcsibuffer is 2K bytes */

/* REG_BT_ZB_COEX_TB 0x16EC */
#define BIT_SHIFT_R_BT_ZB_COEX_TABLE                 0
#define BIT_MASK_R_BT_ZB_COEX_TABLE                  ((u32)0xFFFFFFFF << BIT_SHIFT_R_BT_ZB_COEX_TABLE)                 /*!<R/W 0  uo */

/* REG_MACID1 0x0700 */
#define BIT_SHIFT_MACID1_0                           0
#define BIT_MASK_MACID1_0                            ((u32)0xFFFFFFFF << BIT_SHIFT_MACID1_0)                           /*!<R/W 0  MAC Identification Number Register for port 1 */

/* REG_MACID1_1 0x0704 */
#define BIT_SHIFT_MACID1_1                           0
#define BIT_MASK_MACID1_1                            ((u32)0x0000FFFF << BIT_SHIFT_MACID1_1)                           /*!<R/W 0  MAC Identification Number Register for port 1 */

/* REG_BSSID1 0x0708 */
#define BIT_SHIFT_BSSID1_0                           0
#define BIT_MASK_BSSID1_0                            ((u32)0xFFFFFFFF << BIT_SHIFT_BSSID1_0)                           /*!<R/W 0  Basic Station Set Identification for port 1. */

/* REG_BSSID1_1 0x070C */
#define BIT_SHIFT_BSSID1_1                           0
#define BIT_MASK_BSSID1_1                            ((u32)0x0000FFFF << BIT_SHIFT_BSSID1_1)                           /*!<R/W 0  Basic Station Set Identification for port 1. */

/* REG_BCN_PSR_RPT1 0x0710 */
#define BIT_SHIFT_DTIM_CNT1                          24
#define BIT_MASK_DTIM_CNT1                           ((u32)0x000000FF << BIT_SHIFT_DTIM_CNT1)                          /*!<R 0  DTIM count */
#define BIT_SHIFT_DTIM_PERIOD1                       16
#define BIT_MASK_DTIM_PERIOD1                        ((u32)0x000000FF << BIT_SHIFT_DTIM_PERIOD1)                       /*!<R 0  DTIM Period */
#define BIT_SHIFT_DTIM1                              15
#define BIT_DTIM1                                    ((u32)0x00000001 << BIT_SHIFT_DTIM1)                              /*!<R 0  when set to 1 ,indicate DTIM beacon */
#define BIT_SHIFT_TIM1                               14
#define BIT_TIM1                                     ((u32)0x00000001 << BIT_SHIFT_TIM1)                               /*!<R 0  when set to 1 , indicate tim beacon */
#define BIT_SHIFT_TIM_VALID                          13
#define BIT_TIM_VALID                                ((u32)0x00000001 << BIT_SHIFT_TIM_VALID)                          /*!<R 0  when set to 1 , indicate tim report valid */
#define BIT_SHIFT_PS_AID_1                           0
#define BIT_MASK_PS_AID_1                            ((u32)0x000007FF << BIT_SHIFT_PS_AID_1)                           /*!<R/W 0  AID1 for MACID1 */

/* REG_ASSOCIATED_BFMEE_SEL 0x0714 */
#define BIT_SHIFT_BFMEE1_EN                          25
#define BIT_BFMEE1_EN                                ((u32)0x00000001 << BIT_SHIFT_BFMEE1_EN)                          /*!<R/W 0  If enabled, NDPA would be sent to beamformee1. */
#define BIT_SHIFT_BFMEE1_AID                         16
#define BIT_MASK_BFMEE1_AID                          ((u32)0x000001FF << BIT_SHIFT_BFMEE1_AID)                         /*!<R/W 0  P_AID of the target beamformee1 */
#define BIT_SHIFT_BFMEE0_EN                          9
#define BIT_BFMEE0_EN                                ((u32)0x00000001 << BIT_SHIFT_BFMEE0_EN)                          /*!<R/W 0  If enabled, NDPA would be sent to beamformee0. */
#define BIT_SHIFT_BFMEE0_AID                         0
#define BIT_MASK_BFMEE0_AID                          ((u32)0x000001FF << BIT_SHIFT_BFMEE0_AID)                         /*!<R/W 0  P_AID of the target beamformee0 */

/* REG_SND_PTCL_CTRL 0x0718 */
#define BIT_SHIFT_NDP_RX_STANDBY_TIMER               24
#define BIT_MASK_NDP_RX_STANDBY_TIMER                ((u32)0x000000FF << BIT_SHIFT_NDP_RX_STANDBY_TIMER)               /*!<R/W 0x20  A timeout value for MAC to leave NDP_Rx_standby_state and go back to normal Rx mode. (unit: 2us) */
#define BIT_SHIFT_R_WMAC_CHK_RPTPOLL_A2_DIS          23
#define BIT_R_WMAC_CHK_RPTPOLL_A2_DIS                ((u32)0x00000001 << BIT_SHIFT_R_WMAC_CHK_RPTPOLL_A2_DIS)          /*!<R/W 0  1: For any A1-matched BF Rpt Poll, send back VHT-CB 0: If A1-matched BF Rpt Poll's A2 fails to match the previous receiving NDPA's A2, do not send VHT-CB */
#define BIT_SHIFT_R_WMAC_CHK_UCNDPA_A2_DIS           22
#define BIT_R_WMAC_CHK_UCNDPA_A2_DIS                 ((u32)0x00000001 << BIT_SHIFT_R_WMAC_CHK_UCNDPA_A2_DIS)           /*!<R/W 0  0: If A1-matched NDPA's A2 fails to match 0x6E4 or 0x6EC, use default csi parameter 1: For any receiving A1-matched NDPA, use 0x6F4[11:0] as csi parameter */
#define BIT_SHIFT_R_WMAC_HT_CATEGORY                 16
#define BIT_MASK_R_WMAC_HT_CATEGORY                  ((u32)0x0000003F << BIT_SHIFT_R_WMAC_HT_CATEGORY)                 /*!<R/W 0  csi report offset for ht mode */
#define BIT_SHIFT_R_WMAC_OFFSET_RPTPOLL_EN           15
#define BIT_R_WMAC_OFFSET_RPTPOLL_EN                 ((u32)0x00000001 << BIT_SHIFT_R_WMAC_OFFSET_RPTPOLL_EN)           /*!<R/W 0  1: If previous Tx pkt is BF Rpt Poll or VHT NDP, use vht csi start offset; otherwise ht csi start offset 0: If previous Tx pkt is vht rate, use vht csi start offset; otherwise ht csi start offset */
#define BIT_SHIFT_R_WMAC_CSI_CHKSUM_DIS              14
#define BIT_R_WMAC_CSI_CHKSUM_DIS                    ((u32)0x00000001 << BIT_SHIFT_R_WMAC_CSI_CHKSUM_DIS)              /*!<R/W 0  1:Disable check 16bit checksum value of csi report from BB 0:Enable check 16bit checksum value of csi report from BB */
#define BIT_SHIFT_R_WMAC_VHT_CATEGORY                8
#define BIT_MASK_R_WMAC_VHT_CATEGORY                 ((u32)0x0000003F << BIT_SHIFT_R_WMAC_VHT_CATEGORY)                /*!<R/W 0x02  used as csi report offset */
#define BIT_SHIFT_R_WMAC_USE_NSTS                    7
#define BIT_R_WMAC_USE_NSTS                          ((u32)0x00000001 << BIT_SHIFT_R_WMAC_USE_NSTS)                    /*!<R/W 1  1: use Nsts as Nr, 0: use register value as Nr */
#define BIT_SHIFT_R_DISABLE_CHECK_VHTSIGB_CRC        6
#define BIT_R_DISABLE_CHECK_VHTSIGB_CRC              ((u32)0x00000001 << BIT_SHIFT_R_DISABLE_CHECK_VHTSIGB_CRC)        /*!<R/W 0  1: disable, 0: enable */
#define BIT_SHIFT_R_DISABLE_CHECK_VHTSIGA_CRC        5
#define BIT_R_DISABLE_CHECK_VHTSIGA_CRC              ((u32)0x00000001 << BIT_SHIFT_R_DISABLE_CHECK_VHTSIGA_CRC)        /*!<R/W 0  1: disable, 0: enable */
#define BIT_SHIFT_R_WMAC_BFPARAM_SEL                 4
#define BIT_R_WMAC_BFPARAM_SEL                       ((u32)0x00000001 << BIT_SHIFT_R_WMAC_BFPARAM_SEL)                 /*!<R/W 0  1: use beamforming nc/nr/ng parameter from register 0x6F4 0: use beamforming nc/nr/ng parameter from tx report buffer */
#define BIT_SHIFT_R_WMAC_CSISEQ_SEL                  3
#define BIT_R_WMAC_CSISEQ_SEL                        ((u32)0x00000001 << BIT_SHIFT_R_WMAC_CSISEQ_SEL)                  /*!<R/W 0  By which the sequence number of CSI frame is controlled 1: non-QoS SEQ number 0: counter */
#define BIT_SHIFT_R_WMAC_CSI_WITHHTC_EN              2
#define BIT_R_WMAC_CSI_WITHHTC_EN                    ((u32)0x00000001 << BIT_SHIFT_R_WMAC_CSI_WITHHTC_EN)              /*!<R/W 0  Set to 1, CSI frame would carry HTC in MAC header. */
#define BIT_SHIFT_R_WMAC_HT_NDPA_EN                  1
#define BIT_R_WMAC_HT_NDPA_EN                        ((u32)0x00000001 << BIT_SHIFT_R_WMAC_HT_NDPA_EN)                  /*!<R/W 0  Set to 1, MAC would inform BB of preparing to receive NDP if the received NDP Announcement MPDU is valid. */
#define BIT_SHIFT_R_WMAC_VHT_NDPA_EN                 0
#define BIT_R_WMAC_VHT_NDPA_EN                       ((u32)0x00000001 << BIT_SHIFT_R_WMAC_VHT_NDPA_EN)                 /*!<R/W 0  Set to 1, MAC would inform BB of preparing to receive NDP if the received NDPA is valid. */

/* REG_BEAMFORM_STATUS 0x071C */
#define BIT_SHIFT_WRITE_ENABLE                       31
#define BIT_WRITE_ENABLE                             ((u32)0x00000001 << BIT_SHIFT_WRITE_ENABLE)                       /*!<R/W 0  Access flag. '0' for read. ��1�� for write, 0x72C[15:0] must be sett before this bit is set */
#define BIT_SHIFT_WMAC_CHECK_SOUNDING_SEQ            30
#define BIT_WMAC_CHECK_SOUNDING_SEQ                  ((u32)0x00000001 << BIT_SHIFT_WMAC_CHECK_SOUNDING_SEQ)            /*!<R/W 0  Set to 1,MAC would check sounding sequence number of received CSI report and transmitted NDPA */
#define BIT_SHIFT_VHTHT_MIMO_CTRL_FIELD              1
#define BIT_MASK_VHTHT_MIMO_CTRL_FIELD               ((u32)0x00FFFFFF << BIT_SHIFT_VHTHT_MIMO_CTRL_FIELD)              /*!<R 0  when 'read': [24:1]: currently received VHT MIMO Control field or [16:1]: currently received HT MIMO Control field */
#define BIT_SHIFT_CSI_INTRRUPT_STATUS                0
#define BIT_CSI_INTRRUPT_STATUS                      ((u32)0x00000001 << BIT_SHIFT_CSI_INTRRUPT_STATUS)                /*!<R 0  sounding status: '0��: fail; ��1��: success; */

/* REG_NSARP_CFG 0x0720 */
#define BIT_SHIFT_NSARP_RESPEN                       15
#define BIT_NSARP_RESPEN                             ((u32)0x00000001 << BIT_SHIFT_NSARP_RESPEN)                       /*!<R/W 0  NAARP parser enable */
#define BIT_SHIFT_NSARP_PARP                         9
#define BIT_NSARP_PARP                               ((u32)0x00000001 << BIT_SHIFT_NSARP_PARP)                         /*!<R/W 0  when set to 1, reject ARP */
#define BIT_SHIFT_NSARP_RIPV6                        8
#define BIT_NSARP_RIPV6                              ((u32)0x00000001 << BIT_SHIFT_NSARP_RIPV6)                        /*!<R/W 0  when set to 1, reject IPV6 */
#define BIT_SHIFT_NSARP_MODEN                        6
#define BIT_MASK_NSARP_MODEN                         ((u32)0x00000003 << BIT_SHIFT_NSARP_MODEN)                        /*!<R/W 0  r_WMAC_NSARP_MODEN[0]: when set to 1, enable arp request; r_WMAC_NSARP_MODEN[1]: when set to 1, enable ipv6 request; */
#define BIT_SHIFT_NSARP_RSPFTP                       4
#define BIT_MASK_NSARP_RSPFTP                        ((u32)0x00000003 << BIT_SHIFT_NSARP_RSPFTP)                       /*!<R/W 0  used to select Response_type and TID */
#define BIT_SHIFT_NSARP_RSPSEC                       0
#define BIT_MASK_NSARP_RSPSEC                        ((u32)0x0000000F << BIT_SHIFT_NSARP_RSPSEC)                       /*!<R/W 0  select response packet security type */

/* REG_ZB_STATISTIC_1 0x0724 */
#define BIT_SHIFT_ZB_HI_RX                           16
#define BIT_MASK_ZB_HI_RX                            ((u32)0x0000FFFF << BIT_SHIFT_ZB_HI_RX)                           /*!<R   for statistic */
#define BIT_SHIFT_ZB_HI_TX                           0
#define BIT_MASK_ZB_HI_TX                            ((u32)0x0000FFFF << BIT_SHIFT_ZB_HI_TX)                           /*!<R    */

/* REG_ZB_STATISTIC_2 0x0728 */
#define BIT_SHIFT_ZB_LO_RX                           16
#define BIT_MASK_ZB_LO_RX                            ((u32)0x0000FFFF << BIT_SHIFT_ZB_LO_RX)                           /*!<R   for statistic */
#define BIT_SHIFT_ZB_LO_TX                           0
#define BIT_MASK_ZB_LO_TX                            ((u32)0x0000FFFF << BIT_SHIFT_ZB_LO_TX)                           /*!<R    */

/* REG_BEAMFORMING_INFO_NSARP 0x072C */
#define BIT_SHIFT_UPD_BFMEE_USERID                   13
#define BIT_MASK_UPD_BFMEE_USERID                    ((u32)0x00000007 << BIT_SHIFT_UPD_BFMEE_USERID)                   /*!<R/W 0  Select BFMEE User ID */
#define BIT_SHIFT_UPD_BFMEE_FBTP                     12
#define BIT_UPD_BFMEE_FBTP                           ((u32)0x00000001 << BIT_SHIFT_UPD_BFMEE_FBTP)                     /*!<R/W 0  Feedback Type(B11) of VHT MIMO Control field, HT is no used */
#define BIT_SHIFT_UPD_BFMEE_BW                       10
#define BIT_MASK_UPD_BFMEE_BW                        ((u32)0x00000003 << BIT_SHIFT_UPD_BFMEE_BW)                       /*!<R/W 0  Channel Width of VHT MIMO control field (B7-6) and (B4) when HT mode */
#define BIT_SHIFT_UPD_BFMEE_CB                       8
#define BIT_MASK_UPD_BFMEE_CB                        ((u32)0x00000003 << BIT_SHIFT_UPD_BFMEE_CB)                       /*!<R/W 0  Codebook Information of MIMO control field [8] for VHT (B10) and (B10-9) when HT mode */
#define BIT_SHIFT_UPD_BFMEE_NG                       6
#define BIT_MASK_UPD_BFMEE_NG                        ((u32)0x00000003 << BIT_SHIFT_UPD_BFMEE_NG)                       /*!<R/W 0  Grouping of MIMO control field [7:6] for VHT (B9-8) and (B6-5) when HT mode */
#define BIT_SHIFT_UPD_BFMEE_NR                       3
#define BIT_MASK_UPD_BFMEE_NR                        ((u32)0x00000007 << BIT_SHIFT_UPD_BFMEE_NR)                       /*!<R/W 0  Nr Index of MIMO control field [5:3] for VHT (B5-3) ,[4:3] for HT mode (B3-2) */
#define BIT_SHIFT_UPD_BFMEE_NC                       0
#define BIT_MASK_UPD_BFMEE_NC                        ((u32)0x00000007 << BIT_SHIFT_UPD_BFMEE_NC)                       /*!<R/W 0  Nc Index of MIMO control field [2:0] for VHT (B2-0) , [1:0] for HT mode (B1-0) */

/* REG_IPV6_0 0x0730 */
#define BIT_SHIFT_IPV6_MYIPAD_0                      0
#define BIT_MASK_IPV6_MYIPAD_0                       ((u32)0xFFFFFFFF << BIT_SHIFT_IPV6_MYIPAD_0)                      /*!<R/W 0   */

/* REG_IPV6_1 0x0734 */
#define BIT_SHIFT_IPV6_MYIPAD_1                      0
#define BIT_MASK_IPV6_MYIPAD_1                       ((u32)0xFFFFFFFF << BIT_SHIFT_IPV6_MYIPAD_1)                      /*!<R/W 0   */

/* REG_IPV6_2 0x0738 */
#define BIT_SHIFT_IPV6_MYIPAD_2                      0
#define BIT_MASK_IPV6_MYIPAD_2                       ((u32)0xFFFFFFFF << BIT_SHIFT_IPV6_MYIPAD_2)                      /*!<R/W 0   */

/* REG_IPV6_3 0x073C */
#define BIT_SHIFT_IPV6_MYIPAD_3                      0
#define BIT_MASK_IPV6_MYIPAD_3                       ((u32)0xFFFFFFFF << BIT_SHIFT_IPV6_MYIPAD_3)                      /*!<R/W 0   */

/* REG_IPV6_3 0x073C */
#define BIT_SHIFT_IPV6_MYIPAD_3                      0
#define BIT_MASK_IPV6_MYIPAD_3                       ((u32)0xFFFFFFFF << BIT_SHIFT_IPV6_MYIPAD_3)                      /*!<R/W 0   */

/* REG_ZB_COEX_TABLE_1 0x0740 */
#define BIT_SHIFT_ZB_COEX_TABLE_1                    0
#define BIT_MASK_ZB_COEX_TABLE_1                     ((u32)0xFFFFFFFF << BIT_SHIFT_ZB_COEX_TABLE_1)                    /*!<R/W 0  coexistence table between WLAN and Zigbee, selected by BIT_COEX_TABLE_SEL = 0 */

/* REG_ZB_COEX_TABLE_2 0x0744 */
#define BIT_SHIFT_ZB_COEX_TABLE_2                    0
#define BIT_MASK_ZB_COEX_TABLE_2                     ((u32)0xFFFFFFFF << BIT_SHIFT_ZB_COEX_TABLE_2)                    /*!<R/W 0  coexistence table between WLAN and Zigbee, selected by BIT_COEX_TABLE_SEL = 1 */

/* REG_ZB_BREAK_TABLE 0x0748 */
#define BIT_SHIFT_ZB_BREAK_TABLE_2                   16
#define BIT_MASK_ZB_BREAK_TABLE_2                    ((u32)0x0000FFFF << BIT_SHIFT_ZB_BREAK_TABLE_2)                   /*!<R/W 0  Table used to break ZB activity, when new WLAN request is coming and ZB is on transmitting or receiving */
#define BIT_SHIFT_ZB_BREAK_TABLE_1                   0
#define BIT_MASK_ZB_BREAK_TABLE_1                    ((u32)0x0000FFFF << BIT_SHIFT_ZB_BREAK_TABLE_1)                   /*!<R/W 0  Table used to break WLAN activity, when new ZB request is coming and WLAN is on transmitting or receiving */

/* REG_EXT_ZB_DETEC_CTRL 0x074C */
#define BIT_SHIFT_ZB_TRX_DETECT_TIME                 24
#define BIT_MASK_ZB_TRX_DETECT_TIME                  ((u32)0x000000FF << BIT_SHIFT_ZB_TRX_DETECT_TIME)                 /*!<R / W 'd64  Valid if BIT_ZIGBEE_MODE = 1 & BIT_EXT_ZIGBEE_MODE = 0 (external mode, directional PRIORITY) After ZB_PRI_DETECT_TIME duration, if ZB_PRIORITY is low or goes low during ZB_TRX_INIT_DETECT_TIME, Zigbee will receive packets; otherwise, if ZG_PRIORITY is high or goes high, ZB will TX data. Unit 1us. */
#define BIT_SHIFT_ZB_PRI_DETECT_TIME                 16
#define BIT_MASK_ZB_PRI_DETECT_TIME                  ((u32)0x000000FF << BIT_SHIFT_ZB_PRI_DETECT_TIME)                 /*!<R / W 'd200  Valid if BIT_ZIGBEE_MODE = 1 & BIT_EXT_ZIGBEE_MODE = 0 (external mode, directional PRIORITY) After ZB_REQUEST asserting, if ZG_PRIORITY is asserted within this ZB_PRI_DETECT_TIME duration, ZG will initiate high priority activities; otherwise, if ZB_PRIORITY is not asserted within this duration, it would be low priority activities. Units 1us. (0-255us) */
#define BIT_SHIFT_ZB_CNT_THR                         8
#define BIT_MASK_ZB_CNT_THR                          ((u32)0x000000FF << BIT_SHIFT_ZB_CNT_THR)                         /*!<R/W 0  ZB count threshold, unit: us */
#define BIT_SHIFT_ZB_ARB_TIME                        0
#define BIT_MASK_ZB_ARB_TIME                         ((u32)0x000000FF << BIT_SHIFT_ZB_ARB_TIME)                        /*!<R/W 0  8 bit timer register : Arbitration window of ZB trx request (unit: us) */

/* REG_WMAC_RTX_CTX_SUBTYPE 0x0750 */
#define BIT_SHIFT_R_WMAC_CTX_SUBTYPE                 4
#define BIT_MASK_R_WMAC_CTX_SUBTYPE                  ((u32)0x0000000F << BIT_SHIFT_R_WMAC_CTX_SUBTYPE)                 /*!<R/W 0x7   */
#define BIT_SHIFT_R_WMAC_RTX_SUBTYPE                 0
#define BIT_MASK_R_WMAC_RTX_SUBTYPE                  ((u32)0x0000000F << BIT_SHIFT_R_WMAC_RTX_SUBTYPE)                 /*!<R/W 0x6   */

/* REG_WMAC_RTX_SWAES_RD_1 0x0754 */
#define BIT_SHIFT_WMAC_SWAES_RD                      0
#define BIT_MASK_WMAC_SWAES_RD                       ((u32)0xFFFFFFFF << BIT_SHIFT_WMAC_SWAES_RD)                      /*!<R 0   */

/* REG_WMAC_RTX_SWAES_RD_2 0x0758 */
#define BIT_SHIFT_WMAC_SWAES_RD                      0
#define BIT_MASK_WMAC_SWAES_RD                       ((u32)0xFFFFFFFF << BIT_SHIFT_WMAC_SWAES_RD)                      /*!<R 0   */

/* REG_WMAC_RTX_SWAES_RD_3 0x075C */
#define BIT_SHIFT_WMAC_SWAES_RD                      0
#define BIT_MASK_WMAC_SWAES_RD                       ((u32)0xFFFFFFFF << BIT_SHIFT_WMAC_SWAES_RD)                      /*!<R 0   */

/* REG_WMAC_SWAES_CFG 0x0760 */
#define BIT_SHIFT_SWAES_REQ                          7
#define BIT_SWAES_REQ                                ((u32)0x00000001 << BIT_SHIFT_SWAES_REQ)                          /*!<R 0  software aes engine request polling */
#define BIT_SHIFT_R_WMAC_SWAES_WE                    3
#define BIT_R_WMAC_SWAES_WE                          ((u32)0x00000001 << BIT_SHIFT_R_WMAC_SWAES_WE)                    /*!<R/W 0  Write enable of register ro_WMAC_SWAES_RD */
#define BIT_SHIFT_R_WMAC_SWAES_SEL                   0
#define BIT_R_WMAC_SWAES_SEL                         ((u32)0x00000001 << BIT_SHIFT_R_WMAC_SWAES_SEL)                   /*!<R/W 0  When R_WMAC_SWAES_SEL =1,the content of register 0750-075F used to be aes engine data in or data out . When R_WMAC_SWAES_SEL =0, the content of register 0754-075F used to be aes engine security key */

/* REG_BT_PRI 0x0762 */
#define BIT_SHIFT_BTCOEX_SW_RST                      15
#define BIT_BTCOEX_SW_RST                            ((u32)0x00000001 << BIT_SHIFT_BTCOEX_SW_RST)                      /*!<R/W 0   */
#define BIT_SHIFT_GNT_BOTH_POL                       12
#define BIT_GNT_BOTH_POL                             ((u32)0x00000001 << BIT_SHIFT_GNT_BOTH_POL)                       /*!<R/W 0  grant both choose GNT_BT polarity: 0 : deassert GNT_BT signal as PTA grant both WiFI and BT. 1 : assert GNT_BT signal as PTA grant both WiFi and BT. */
#define BIT_SHIFT_BT_ARB_INST_EN                     8
#define BIT_BT_ARB_INST_EN                           ((u32)0x00000001 << BIT_SHIFT_BT_ARB_INST_EN)                     /*!<R/W 0  1: enable GNT_BT_BYPASS_PRIORITY 0 : disable */
#define BIT_SHIFT_BT_ARB_TIME                        0
#define BIT_MASK_BT_ARB_TIME                         ((u32)0x000000FF << BIT_SHIFT_BT_ARB_TIME)                        /*!<R/W 0  8 bit timer register : Arbitration window of bt trx request ( in the unit of us) */

/* REG_BT_COEX_ENH 0x0764 */
#define BIT_SHIFT_ZIGBEE_EN                          31
#define BIT_ZIGBEE_EN                                ((u32)0x00000001 << BIT_SHIFT_ZIGBEE_EN)                          /*!<R / W 0  Enable ZigBee function */
#define BIT_SHIFT_ZIGBEE_MODE                        30
#define BIT_ZIGBEE_MODE                              ((u32)0x00000001 << BIT_SHIFT_ZIGBEE_MODE)                        /*!<R / W 0  0: SOC 1: external */
#define BIT_SHIFT_EXT_ZIGBEE_MODE                    29
#define BIT_EXT_ZIGBEE_MODE                          ((u32)0x00000001 << BIT_SHIFT_EXT_ZIGBEE_MODE)                    /*!<R / W 0  The mode of external ZigBee 1: static PRIORITY 0: directional PRIORITY */
#define BIT_SHIFT_COEX_TABLE_SEL                     28
#define BIT_COEX_TABLE_SEL                           ((u32)0x00000001 << BIT_SHIFT_COEX_TABLE_SEL)                     /*!<R / W 1  Select coexistence table for WLAN & ZB 0: BIT_COEX_TABLE_WL_ZB_1 1: BIT_COEX_TABLE_WL_ZB_2 */
#define BIT_SHIFT_EXT_ZB_GNT_POLAR                   27
#define BIT_EXT_ZB_GNT_POLAR                         ((u32)0x00000001 << BIT_SHIFT_EXT_ZB_GNT_POLAR)                   /*!<R / W 1  Select the polar of ZB_GRANT, for extarnal ZB 0: low active 1: high active */
#define BIT_SHIFT_ZB_ARB_INST_EN                     26
#define BIT_ZB_ARB_INST_EN                           ((u32)0x00000001 << BIT_SHIFT_ZB_ARB_INST_EN)                     /*!<R/W 0  1: enable the time limit of ZigBee request (zb_pri | zb_rx | zb_tx), PTA is valid during ( <=BIT_ZB_ARB_TIME) 0: disable Co-work with BIT_ZB_ARB_TIME */
#define BIT_SHIFT_ZB_CNT_THREN                       25
#define BIT_ZB_CNT_THREN                             ((u32)0x00000001 << BIT_SHIFT_ZB_CNT_THREN)                       /*!<R/W 0  ZB count threshold enable, for statistics co-work with BIT_ZB_CNT_THR */
#define BIT_SHIFT_GNT_ZB_BB_SW_EN                    23
#define BIT_GNT_ZB_BB_SW_EN                          ((u32)0x00000001 << BIT_SHIFT_GNT_ZB_BB_SW_EN)                    /*!<R / W 0  Enable SW control gnt_zb_bb */
#define BIT_SHIFT_GNT_ZB_BB_SW                       22
#define BIT_GNT_ZB_BB_SW                             ((u32)0x00000001 << BIT_SHIFT_GNT_ZB_BB_SW)                       /*!<R / W 0  SW value */
#define BIT_SHIFT_GNT_ZB_RFC_SW_EN                   21
#define BIT_GNT_ZB_RFC_SW_EN                         ((u32)0x00000001 << BIT_SHIFT_GNT_ZB_RFC_SW_EN)                   /*!<R / W 0  Enable SW control gnt_zb_rfc */
#define BIT_SHIFT_GNT_ZB_RFC_SW                      20
#define BIT_GNT_ZB_RFC_SW                            ((u32)0x00000001 << BIT_SHIFT_GNT_ZB_RFC_SW)                      /*!<R / W 0  SW value */
#define BIT_SHIFT_GNT_ZB_EXT_SW_EN                   19
#define BIT_GNT_ZB_EXT_SW_EN                         ((u32)0x00000001 << BIT_SHIFT_GNT_ZB_EXT_SW_EN)                   /*!<R / W 0  Enable SW control gnt_zb_o of external ZigBee */
#define BIT_SHIFT_GNT_ZB_EXT_SW                      18
#define BIT_GNT_ZB_EXT_SW                            ((u32)0x00000001 << BIT_SHIFT_GNT_ZB_EXT_SW)                      /*!<R / W 0  SW value, external ZigBee */
#define BIT_SHIFT_EXT_ZB_REQ_POLAR                   17
#define BIT_EXT_ZB_REQ_POLAR                         ((u32)0x00000001 << BIT_SHIFT_EXT_ZB_REQ_POLAR)                   /*!<R / W 1  Select the polar of ZB_REQUEST, for static mode external ZB 0: low active 1: high active */
#define BIT_SHIFT_R_GNT_BT_RFC_SW                    12
#define BIT_R_GNT_BT_RFC_SW                          ((u32)0x00000001 << BIT_SHIFT_R_GNT_BT_RFC_SW)                    /*!<R/W 1  SW control BT RF */
#define BIT_SHIFT_R_GNT_BT_RFC_SW_EN                 11
#define BIT_R_GNT_BT_RFC_SW_EN                       ((u32)0x00000001 << BIT_SHIFT_R_GNT_BT_RFC_SW_EN)                 /*!<R/W 1  SW control BT RF enable */
#define BIT_SHIFT_R_GNT_BT_BB_SW                     10
#define BIT_R_GNT_BT_BB_SW                           ((u32)0x00000001 << BIT_SHIFT_R_GNT_BT_BB_SW)                     /*!<R/W 1  SW control BT baseband */
#define BIT_SHIFT_R_GNT_BT_BB_SW_EN                  9
#define BIT_R_GNT_BT_BB_SW_EN                        ((u32)0x00000001 << BIT_SHIFT_R_GNT_BT_BB_SW_EN)                  /*!<R/W 1  SW control BT baseband enable */
#define BIT_SHIFT_R_BT_CNT_THREN                     8
#define BIT_R_BT_CNT_THREN                           ((u32)0x00000001 << BIT_SHIFT_R_BT_CNT_THREN)                     /*!<R/W 0  BT count threshold enable */
#define BIT_SHIFT_R_BT_CNT_THR                       0
#define BIT_MASK_R_BT_CNT_THR                        ((u32)0x000000FF << BIT_SHIFT_R_BT_CNT_THR)                       /*!<R/W 0  BT count threshold */

/* REG_WLAN_ACT_MASK_CTRL 0x0768 */
#define BIT_SHIFT_WACTMSK_OFF_DUR                    8
#define BIT_MASK_WACTMSK_OFF_DUR                     ((u32)0x000000FF << BIT_SHIFT_WACTMSK_OFF_DUR)                    /*!<R/W 0  WLAN will reserve channel for BT during MASK OFF duration. Unit 0.625ms */
#define BIT_SHIFT_WACTMSK_ON_DUR                     0
#define BIT_MASK_WACTMSK_ON_DUR                      ((u32)0x000000FF << BIT_SHIFT_WACTMSK_ON_DUR)                     /*!<R/W 0  WLAN can block BT during MASK On duration. Unit 0.625ms */

/* REG_WLAN_ACT_MASK_CTRL_1 0x076C */
#define BIT_SHIFT_WLRX_TER_BY_CTL_1                  11
#define BIT_WLRX_TER_BY_CTL_1                        ((u32)0x00000001 << BIT_SHIFT_WLRX_TER_BY_CTL_1)                  /*!<R/W 0  When wlan receive a control packet without fit address, whether the signal indicating wlan rx can be terminated as soon as the address check finish is not only controlled by r_WLRX_TER_BY_AD, but also should be refereed to this bit. 1: enable; 0: disable */
#define BIT_SHIFT_WLRX_TER_BY_AD_1                   10
#define BIT_WLRX_TER_BY_AD_1                         ((u32)0x00000001 << BIT_SHIFT_WLRX_TER_BY_AD_1)                   /*!<R/W 0  When wlan receive the packet without fit address, the signal indicating wlan rx can be terminated as soon as the address check finish. This feature can be enabled by this bit. 1: en */
#define BIT_SHIFT_ANT_DIVERSITY_SEL_1                9
#define BIT_ANT_DIVERSITY_SEL_1                      ((u32)0x00000001 << BIT_SHIFT_ANT_DIVERSITY_SEL_1)                /*!<R/W 0  Antenna diversity for 2 antenna mode: MAC_ANT_SEL = GNT_BT ^ ANT_DIVERDITY_SEL */
#define BIT_SHIFT_ANTSEL_FOR_BT_CTRL_EN_1            8
#define BIT_ANTSEL_FOR_BT_CTRL_EN_1                  ((u32)0x00000001 << BIT_SHIFT_ANTSEL_FOR_BT_CTRL_EN_1)            /*!<R/W 0  Enable the control of antenna selection through GNT_BT: GNT_BT=1: ANT_SEL for BT device; GNT_BT=0: ANT_SEL for WL device. */
#define BIT_SHIFT_WLACT_LOW_GNTWL_EN_1               2
#define BIT_WLACT_LOW_GNTWL_EN_1                     ((u32)0x00000001 << BIT_SHIFT_WLACT_LOW_GNTWL_EN_1)               /*!<R/W 0  When WLACT_LOW_GNTWL_EN = 1, the TRX of WLAN are blocked according to the BTCOEX table arbitration during MASK OFF duration. WLACT_LOW_GNTWL_EN = 0, the TRX of WLAN are paused during MASK OFF duration.. */
#define BIT_SHIFT_WLACT_HIGH_GNTBT_EN_1              1
#define BIT_WLACT_HIGH_GNTBT_EN_1                    ((u32)0x00000001 << BIT_SHIFT_WLACT_HIGH_GNTBT_EN_1)              /*!<R/W 0  When WLACT_HIGH_GNTBT_EN = 1, the TRX of WLAN are blocked according to the BTCOEX table arbitration during MASK ON duration. When WLACT_HIGH_ GNTBT_EN = 0, the TRX of WLAN are not paused during MASK OFF duration. */
#define BIT_SHIFT_EN_WLACT_MASK_SYNC                 0
#define BIT_EN_WLACT_MASK_SYNC                       ((u32)0x00000001 << BIT_SHIFT_EN_WLACT_MASK_SYNC)                 /*!<R/W 0  When NAV update is beyond this value, then NAV update is aborted. When this field is 0x00, NAV_UPPER function is disable. The unit is 128us. */

/* REG_BT_COEX_ENHANCED_INTR_CTRL 0x076E */
#define BIT_SHIFT_BT_STAT_DELAY                      12
#define BIT_MASK_BT_STAT_DELAY                       ((u32)0x0000000F << BIT_SHIFT_BT_STAT_DELAY)                      /*!<R/W 0  For CSR, BT_PRI and BT_STAT go high form low at the same time. Thus, BT_STAT need delay BT_STAT_DELAY time to trigger hardware. Unit: 1us */
#define BIT_SHIFT_BT_TRX_INIT_DETECT                 8
#define BIT_MASK_BT_TRX_INIT_DETECT                  ((u32)0x0000000F << BIT_SHIFT_BT_TRX_INIT_DETECT)                 /*!<R/W 0  After BT_PRI asserting for BT_TRX_INIT_DETECT us, if BT_STAT is low, then BT will receive packets; otherwise, if BT goes high, BT will TX data. Unit 4us. */
#define BIT_SHIFT_BT_PRI_DETECT_TO                   4
#define BIT_MASK_BT_PRI_DETECT_TO                    ((u32)0x0000000F << BIT_SHIFT_BT_PRI_DETECT_TO)                   /*!<R/W 0  After BT_PRI asserting, if BT_STAT is asserted within this TO duration, BT will initiate high priority activities; otherwise, if BT_STAT is not asserted within this duration, it would be low priority activities. Units 1us. */
#define BIT_SHIFT_R_GRANTALL_WLMASK                  3
#define BIT_R_GRANTALL_WLMASK                        ((u32)0x00000001 << BIT_SHIFT_R_GRANTALL_WLMASK)                  /*!<R/W 0  grant all mask */
#define BIT_SHIFT_STATIS_BT_EN                       2
#define BIT_STATIS_BT_EN                             ((u32)0x00000001 << BIT_SHIFT_STATIS_BT_EN)                       /*!<R/W 0  When this bit is set, the BT_ACT_STATISTICS counters starts counting */
#define BIT_SHIFT_EN_WL_ACT_MASK                     1
#define BIT_EN_WL_ACT_MASK                           ((u32)0x00000001 << BIT_SHIFT_EN_WL_ACT_MASK)                     /*!<R/W 0  Enable WLAN_ACT Mask Function (related to 0x768h-0x76Dh) */
#define BIT_SHIFT_ENHBT                              0
#define BIT_ENHBT                                    ((u32)0x00000001 << BIT_SHIFT_ENHBT)                              /*!<R/W 0  Enable Enhanced BT Interface (we suggest to use with BT mode 2) */

/* REG_BT_ENHANCED_CTRL0 0x0770 */
#define BIT_SHIFT_STATIS_BT                          0
#define BIT_MASK_STATIS_BT                           ((u32)0xFFFFFFFF << BIT_SHIFT_STATIS_BT)                          /*!<R 0   */

/* REG_BT_ENHANCED_CTRL1 0x0774 */
#define BIT_SHIFT_STATIS_BT                          0
#define BIT_MASK_STATIS_BT                           ((u32)0xFFFFFFFF << BIT_SHIFT_STATIS_BT)                          /*!<R 0   */

/* REG_BT_PROPRI 0x0778 */
#define BIT_SHIFT_BT_CMD_RPT                         16
#define BIT_MASK_BT_CMD_RPT                          ((u32)0x0000FFFF << BIT_SHIFT_BT_CMD_RPT)                         /*!<R 0   */
#define BIT_SHIFT_RPT_FROM_BT                        8
#define BIT_MASK_RPT_FROM_BT                         ((u32)0x000000FF << BIT_SHIFT_RPT_FROM_BT)                        /*!<R 0   */
#define BIT_SHIFT_BT_HID_ISR_SET                     6
#define BIT_MASK_BT_HID_ISR_SET                      ((u32)0x00000003 << BIT_SHIFT_BT_HID_ISR_SET)                     /*!<R/W 0  When EN_BT_PROFILE_OR_HID is set ?1?, hardware also need to check this value to trigger an interrupt. 0: default, TX and RX 1: TX 2: RX 3: Reserved */
#define BIT_SHIFT_TDMA_BT_START_NOTIFY               5
#define BIT_TDMA_BT_START_NOTIFY                     ((u32)0x00000001 << BIT_SHIFT_TDMA_BT_START_NOTIFY)               /*!<R/W 0  When the control of TDMA mode is firmware and firmware also receive signal that NULL packet for BT had sent, firmware can fill this bit to notify HW PTA to pull WLAN_ACT to low and the interval is Tbt */
#define BIT_SHIFT_ENABLE_TDMA_HW_MODE                4
#define BIT_ENABLE_TDMA_HW_MODE                      ((u32)0x00000001 << BIT_SHIFT_ENABLE_TDMA_HW_MODE)                /*!<R/W 0  0: default, PTA TDMA mode is hardware mode. 1: enable firmware mode. */
#define BIT_SHIFT_ENABLE_PTA_TDMA_MODE               3
#define BIT_ENABLE_PTA_TDMA_MODE                     ((u32)0x00000001 << BIT_SHIFT_ENABLE_PTA_TDMA_MODE)               /*!<R/W 0  0: default, disable PTA TDMA mode 1: enable TDMA mode: a. WLAN_ACT default is high. b. Hardware mode: When NULL packet for BT had sent, hardware will notify PTA to start TDMA mode. Firmware mode: When NULL packet for BT had sent, hardware will trigger an interrupt to notify firmware. Then, firmware need to set TDMA_BT_START_NOTIFY to notify PTA to start TDMA mode. */
#define BIT_SHIFT_ENABLE_COEXIST_TAB_IN_TDMA         2
#define BIT_ENABLE_COEXIST_TAB_IN_TDMA               ((u32)0x00000001 << BIT_SHIFT_ENABLE_COEXIST_TAB_IN_TDMA)         /*!<R/W 0  0: default, no matter which WLAN_ACT is high or low, PTA doesn't execute co-exist table scheme 1: enable, When WLAN_ACT is high, PTA execute xo-exist table scheme */
#define BIT_SHIFT_GPIO2_GPIO3_EXANGE_OR_NO_BT_CCA    1
#define BIT_GPIO2_GPIO3_EXANGE_OR_NO_BT_CCA          ((u32)0x00000001 << BIT_SHIFT_GPIO2_GPIO3_EXANGE_OR_NO_BT_CCA)   /*!<R/W 0  Enable GPIO2 and GPIO3 exchange. (Note: need to enable mode2 and enhance 3 wire) If Enable RTK BT mode, set this bit to 1 to disable granting to BT device when arbitration */
#define BIT_SHIFT_RTK_BT_ENABLE                      0
#define BIT_RTK_BT_ENABLE                            ((u32)0x00000001 << BIT_SHIFT_RTK_BT_ENABLE)                      /*!<R/W 0  Enable RTK BT mode */

/* REG_BT_STATUS_REPORT_REGISTER 0x077C */
#define BIT_SHIFT_BT_PROFILE                         24
#define BIT_MASK_BT_PROFILE                          ((u32)0x000000FF << BIT_SHIFT_BT_PROFILE)                         /*!<R 0  When WLAN received CMD_ID 0x3, it will recorder to this. */
#define BIT_SHIFT_BT_POWER                           16
#define BIT_MASK_BT_POWER                            ((u32)0x000000FF << BIT_SHIFT_BT_POWER)                           /*!<R 0  When WLAN received CMD_ID 0x2, it will recorder to this */
#define BIT_SHIFT_BT_PREDECT_STATUS                  8
#define BIT_MASK_BT_PREDECT_STATUS                   ((u32)0x000000FF << BIT_SHIFT_BT_PREDECT_STATUS)                  /*!<R 0  When WLAN received CMD_ID 0x0, it will recorder to this */
#define BIT_SHIFT_BT_CMD_ID                          0
#define BIT_MASK_BT_CMD_ID                           ((u32)0x000000FF << BIT_SHIFT_BT_CMD_ID)                          /*!<R/W 0  command information from BT */

/* REG_BT_INTERRUPT_CONTROL_REGISTER 0x0780 */
#define BIT_SHIFT_EN_MAC_NULL_PKT_NOTIFY             31
#define BIT_EN_MAC_NULL_PKT_NOTIFY                   ((u32)0x00000001 << BIT_SHIFT_EN_MAC_NULL_PKT_NOTIFY)             /*!<R/W 0  When MAC had sent NULL packet for BT and firmware also set nav_for_bt bit, hardware triggers an interrupt to notify firmware. 0: Disable 1: Enable */
#define BIT_SHIFT_EN_WLAN_RPT_AND_BT_QUERY           30
#define BIT_EN_WLAN_RPT_AND_BT_QUERY                 ((u32)0x00000001 << BIT_SHIFT_EN_WLAN_RPT_AND_BT_QUERY)           /*!<R/W 0  Enable two interrupt: 1) PTA sent the report packet successfully 2) PTA sent a query packet 0: Disable 1: Enable */
#define BIT_SHIFT_EN_BT_STSTUS_RPT                   29
#define BIT_EN_BT_STSTUS_RPT                         ((u32)0x00000001 << BIT_SHIFT_EN_BT_STSTUS_RPT)                   /*!<R/W 0  When WLAN receive cmd_id ��0��, hardware trigger an interrupt to notify firmware. 0: Disable 1: Enable */
#define BIT_SHIFT_EN_BT_POWER                        28
#define BIT_EN_BT_POWER                              ((u32)0x00000001 << BIT_SHIFT_EN_BT_POWER)                        /*!<R/W 0  When WLAN received the packet including BT Power and check register ��BT_STATUS_RPT��, if data contents aren't the same, hardware can trigger an interrupt to notify firmware. 0: Disable 1: Enable */
#define BIT_SHIFT_EN_BT_CHANNEL                      27
#define BIT_EN_BT_CHANNEL                            ((u32)0x00000001 << BIT_SHIFT_EN_BT_CHANNEL)                      /*!<R/W 0  When WLAN received the packet including BT channel number, hardware can trigger an interrupt to notify firmware. 0: Disable 1: Enable */
#define BIT_SHIFT_EN_BT_SLOT_CHANGE                  26
#define BIT_EN_BT_SLOT_CHANGE                        ((u32)0x00000001 << BIT_SHIFT_EN_BT_SLOT_CHANGE)                  /*!<R/W 0  When WLAN received the packet including that BT had multi-slots, hardware can trigger an interrupt to notify firmware. 0: Disable 1: Enable */
#define BIT_SHIFT_EN_BT_PROFILE_OR_HID               25
#define BIT_EN_BT_PROFILE_OR_HID                     ((u32)0x00000001 << BIT_SHIFT_EN_BT_PROFILE_OR_HID)               /*!<R/W 0  Enable two interrupt 1) When WLAN received the packet including that WLAN specific profile and check register ��BT_STATUS_RPT��, if data contents aren't the same, hardware can trigger an interrupt to notify firmware. 2) When WLAN received the report packet including HID information, hardware will trigger an interrupt to notify firmware. 0: Disable 1: Enable */
#define BIT_SHIFT_WLAN_RPT_NOTIFY                    24
#define BIT_WLAN_RPT_NOTIFY                          ((u32)0x00000001 << BIT_SHIFT_WLAN_RPT_NOTIFY)                    /*!<R/W 0  When firmware had prepared packet to send to BT, it need to set this bit to notify hardware that it can transmit. 0: There isn't a valid packet in register�� WLAN_RPT_ PKT��. 1: There is a valid packet in register�� WLAN_RPT_ PKT��. */
#define BIT_SHIFT_WLAN_RPT_DATA                      16
#define BIT_MASK_WLAN_RPT_DATA                       ((u32)0x000000FF << BIT_SHIFT_WLAN_RPT_DATA)                      /*!<R/W 0  Data contents, When the report packet had sent, hardware will clear this register. */
#define BIT_SHIFT_TO_BT_CMDID                        8
#define BIT_MASK_TO_BT_CMDID                         ((u32)0x000000FF << BIT_SHIFT_TO_BT_CMDID)                        /*!<R/W 0  Command id: 0x80~FF */
#define BIT_SHIFT_BT_DATA                            0
#define BIT_MASK_BT_DATA                             ((u32)0x000000FF << BIT_SHIFT_BT_DATA)                            /*!<R 0  When WLAN received the packet BT sent, hardware will place data to this register in addition to CMD_ID 0x0 ~ 0x3. */

/* REG_WLAN_REPORT_TIME_OUT_CONTROL_REGISTER 0x0784 */
#define BIT_SHIFT_WLAN_RPT_TO                        0
#define BIT_MASK_WLAN_RPT_TO                         ((u32)0x000000FF << BIT_SHIFT_WLAN_RPT_TO)                        /*!<R/W 0  When WLAN��W received query packet, HW timer counts. If timer equals to WLAN_RPT_TO and HW can?t send packet, it will give up query packet at this time. When BT sent another query packet, WLAN HW need to send the previous packet and it shouldn't trigger an interrupt to firmware. Unit: 4us. */

/* REG_CH_COEXIST 0x0785 */
#define BIT_SHIFT_ISOLATION_CHK_0                    1
#define BIT_MASK_ISOLATION_CHK_0                     ((u32)0x007FFFFF << BIT_SHIFT_ISOLATION_CHK_0)                    /*!<R/W 0  0: leave PTA 1: enter PTA */
#define BIT_SHIFT_ISOLATION_EN                       0
#define BIT_ISOLATION_EN                             ((u32)0x00000001 << BIT_SHIFT_ISOLATION_EN)                       /*!<R/W 0  Isolation table enable bit. 0: disable 1: enable */

/* REG_BT_ISOLATION_TABLE_REGISTER_REGISTER_1 0x0788 */
#define BIT_SHIFT_ISOLATION_CHK_1                    0
#define BIT_MASK_ISOLATION_CHK_1                     ((u32)0xFFFFFFFF << BIT_SHIFT_ISOLATION_CHK_1)                    /*!<R/W 0  0: leave PTA 1: enter PTA */

/* REG_BT_ISOLATION_TABLE_REGISTER_REGISTER_2 0x078C */
#define BIT_SHIFT_ISOLATION_CHK_2                    0
#define BIT_MASK_ISOLATION_CHK_2                     ((u32)0x00FFFFFF << BIT_SHIFT_ISOLATION_CHK_2)                    /*!<R/W 0  0: leave PTA 1: enter PTA */

/* REG_BT_INTERRUPT_STATUS_REGISTER 0x078F */
#define BIT_SHIFT_BT_HID_ISR                         7
#define BIT_BT_HID_ISR                               ((u32)0x00000001 << BIT_SHIFT_BT_HID_ISR)                         /*!<R/W1C 0  When WLAN received the report packet including HID information, hardware will trigger an interrupt to notify firmware */
#define BIT_SHIFT_BT_QUERY_ISR                       6
#define BIT_BT_QUERY_ISR                             ((u32)0x00000001 << BIT_SHIFT_BT_QUERY_ISR)                       /*!<R/W1C 0  When WLAN received a query packet, hardware triggers an interrupt to notify firmware */
#define BIT_SHIFT_MAC_NULL_PKT_NOTIFY_ISR            5
#define BIT_MAC_NULL_PKT_NOTIFY_ISR                  ((u32)0x00000001 << BIT_SHIFT_MAC_NULL_PKT_NOTIFY_ISR)            /*!<R/W1C 0  When MAC had sent NULL packet for BT and firmware also set nav_for_bt bit, hardware triggers an interrupt to notify firmware */
#define BIT_SHIFT_WLAN_RPT_ISR                       4
#define BIT_WLAN_RPT_ISR                             ((u32)0x00000001 << BIT_SHIFT_WLAN_RPT_ISR)                       /*!<R/W1C 0  When PTA sent the report packet successfully, hardware triggers an interrupt to notify firmware. */
#define BIT_SHIFT_BT_POWER_ISR                       3
#define BIT_BT_POWER_ISR                             ((u32)0x00000001 << BIT_SHIFT_BT_POWER_ISR)                       /*!<R/W1C 0  When WLAN received the packet including BT Power and check register ��BT_STATUS_RPT��, if data contents aren't the same, hardware can trigger an interrupt to notify firmware */
#define BIT_SHIFT_BT_CHANNEL_ISR                     2
#define BIT_BT_CHANNEL_ISR                           ((u32)0x00000001 << BIT_SHIFT_BT_CHANNEL_ISR)                     /*!<R/W1C 0  When WLAN received the packet including BT channel number, hardware can trigger an interrupt to notify firmware. */
#define BIT_SHIFT_BT_SLOT_CHANGE_ISR                 1
#define BIT_BT_SLOT_CHANGE_ISR                       ((u32)0x00000001 << BIT_SHIFT_BT_SLOT_CHANGE_ISR)                 /*!<R/W1C 0  When WLAN received the packet including that BT had multi-slots, hardware can trigger an interrupt to notify firmware */
#define BIT_SHIFT_BT_PROFILE_ISR                     0
#define BIT_BT_PROFILE_ISR                           ((u32)0x00000001 << BIT_SHIFT_BT_PROFILE_ISR)                     /*!<R/W1C 0  When WLAN received the packet including that WLAN specific profile and check register ��BT_STATUS_RPT��, if data contents aren't the same, hardware can trigger an interrupt to notify firmware. */

/* REG_BT_TDMA_TIME_REGISTER 0x0790 */
#define BIT_SHIFT_BT_TIME                            6
#define BIT_MASK_BT_TIME                             ((u32)0x03FFFFFF << BIT_SHIFT_BT_TIME)                            /*!<R/W 0  The time is that WLAN_ACT is low. Unit: us */
#define BIT_SHIFT_BT_RPT_SAMPLE_RATE                 0
#define BIT_MASK_BT_RPT_SAMPLE_RATE                  ((u32)0x0000003F << BIT_SHIFT_BT_RPT_SAMPLE_RATE)                 /*!<R/W 0  When wifi detected the raising edge of BT report packet, wifi need to counter BT_RPT_SAMPLE_RATE. Then hw could detect which is high or low. Uint: 20 ns */

/* REG_BT_ACT_REGISTER 0x0794 */
#define BIT_SHIFT_B_AX_BT_BLE_EN                     24
#define BIT_B_AX_BT_BLE_EN                           ((u32)0x00000001 << BIT_SHIFT_B_AX_BT_BLE_EN)                     /*!<R/W 0  Decide the GNT_BT_TX / RX 0: GNT_BT_TX = GNT_BT & BT_TX ; GNT_BT_RX = GNT_BT & BT_RX 1: GNT_BT_TX = GNT_BT & (BT_TX | BT_BLE) ; GNT_BT_RX = GNT_BT & (BT_RX | BT_BLE) */
#define BIT_SHIFT_BT_EISR_EN                         16
#define BIT_MASK_BT_EISR_EN                          ((u32)0x000000FF << BIT_SHIFT_BT_EISR_EN)                         /*!<R/W 0  BT eisr enable */
#define BIT_SHIFT_BT_ACT_FALLING_ISR                 10
#define BIT_BT_ACT_FALLING_ISR                       ((u32)0x00000001 << BIT_SHIFT_BT_ACT_FALLING_ISR)                 /*!<R/W1C 0  When BT_ACT signal is falling edge, it will trigger an interrupt. */
#define BIT_SHIFT_BT_ACT_RISING_ISR                  9
#define BIT_BT_ACT_RISING_ISR                        ((u32)0x00000001 << BIT_SHIFT_BT_ACT_RISING_ISR)                  /*!<R/W1C 0  When BT_ACT signal is raising edge, it will trigger an interrupt */
#define BIT_SHIFT_TDMA_TO_ISR                        8
#define BIT_TDMA_TO_ISR                              ((u32)0x00000001 << BIT_SHIFT_TDMA_TO_ISR)                        /*!<R/W1C 0  When BT_TIME expired, it will trigger an interrupt. */
#define BIT_SHIFT_BT_CH                              0
#define BIT_MASK_BT_CH                               ((u32)0x0000007F << BIT_SHIFT_BT_CH)                              /*!<R 0x7f  When hardware receive cm_id ��1��, it will recorder to this. */

/* REG_LTR_IDLE_LATENCY_V2 0x0798 */
#define BIT_SHIFT_LTR_IDLE_LATENCY                   0
#define BIT_MASK_LTR_IDLE_LATENCY                    ((u32)0xFFFFFFFF << BIT_SHIFT_LTR_IDLE_LATENCY)                   /*!<R/W 0x04444400  LTR idle latency. */

/* REG_LTR_ACTIVE_LATENCY_V2 0x079C */
#define BIT_SHIFT_LTR_ACTIVE_LATENCY                 0
#define BIT_MASK_LTR_ACTIVE_LATENCY                  ((u32)0xFFFFFFFF << BIT_SHIFT_LTR_ACTIVE_LATENCY)                 /*!<R/W 0x02030405  LTR Active latency. */

/* REG_OBFF_CTRL 0x07A0 */
#define BIT_SHIFT_LTR_CTRL                           24
#define BIT_MASK_LTR_CTRL                            ((u32)0x000000FF << BIT_SHIFT_LTR_CTRL)                           /*!<R/W 0x4a   */
#define BIT_SHIFT_LTR_IDLE_FLAG                      23
#define BIT_LTR_IDLE_FLAG                            ((u32)0x00000001 << BIT_SHIFT_LTR_IDLE_FLAG)                      /*!<R 0   */
#define BIT_SHIFT_LTR_ACT_FLAG                       22
#define BIT_LTR_ACT_FLAG                             ((u32)0x00000001 << BIT_SHIFT_LTR_ACT_FLAG)                       /*!<R 0   */
#define BIT_SHIFT_OBFF_CTRL                          0
#define BIT_MASK_OBFF_CTRL                           ((u32)0x003FFFFF << BIT_SHIFT_OBFF_CTRL)                          /*!<R/W 0x4010   */

/* REG_LTR_CTRL 0x07A4 */
#define BIT_SHIFT_LTR_RPBACC_ID_HIGH                 25
#define BIT_MASK_LTR_RPBACC_ID_HIGH                  ((u32)0x00000007 << BIT_SHIFT_LTR_RPBACC_ID_HIGH)                 /*!<R/W 3'b101  Threshold to send ltr act msg after accumulating high rate rx payload page number. */
#define BIT_SHIFT_LTR_RPBACC_ID_MEDIA                22
#define BIT_MASK_LTR_RPBACC_ID_MEDIA                 ((u32)0x00000007 << BIT_SHIFT_LTR_RPBACC_ID_MEDIA)                /*!<R/W 3'b100  Threshold to send ltr act msg after accumulating media rate rx payload page number. */
#define BIT_SHIFT_LTR_RPBACC_ID_LOW                  19
#define BIT_MASK_LTR_RPBACC_ID_LOW                   ((u32)0x00000007 << BIT_SHIFT_LTR_RPBACC_ID_LOW)                  /*!<R/W 3'b100  Threshold to send ltr act msg after accumulating low rate rx payload page number. */
#define BIT_SHIFT_RPBACC_CLRBLOCK                    18
#define BIT_RPBACC_CLRBLOCK                          ((u32)0x00000001 << BIT_SHIFT_RPBACC_CLRBLOCK)                    /*!<R/W 0  Clear rx dma and int block after rx packet page large than threshold */
#define BIT_SHIFT_LTR_RPBACC_EN                      17
#define BIT_LTR_RPBACC_EN                            ((u32)0x00000001 << BIT_SHIFT_LTR_RPBACC_EN)                      /*!<R/W 1  Enable gen ltr active msg according to occupied pages in rx packet buffer */
#define BIT_SHIFT_LTR_SPACE_ID                       15
#define BIT_MASK_LTR_SPACE_ID                        ((u32)0x00000003 << BIT_SHIFT_LTR_SPACE_ID)                       /*!<R/W 2'b00  Ltr space index.0:h100(for test),1:h3000(300us),2:h5000(512us),3:h9000(921us) */
#define BIT_SHIFT_LTR_IDLE_TIMER_ID                  12
#define BIT_MASK_LTR_IDLE_TIMER_ID                   ((u32)0x00000007 << BIT_SHIFT_LTR_IDLE_TIMER_ID)                  /*!<R/W 3'b011  Send ltr idle message after trx state machine in idle for more than this time. 0:2 us,1: 13us,2 :100us,3: 800us,4:1.13ms,5:2.25ms,6: 6ms */
#define BIT_SHIFT_BLKHWBCN_TIMER_ID                  9
#define BIT_MASK_BLKHWBCN_TIMER_ID                   ((u32)0x00000007 << BIT_SHIFT_BLKHWBCN_TIMER_ID)                  /*!<R/W 3'b010  Use obff block timer to send ltr active */
#define BIT_SHIFT_OBFF_LTRIDLE_EN                    8
#define BIT_OBFF_LTRIDLE_EN                          ((u32)0x00000001 << BIT_SHIFT_OBFF_LTRIDLE_EN)                    /*!<R/W 0  Send LTR idle message in obff or cpu active window */
#define BIT_SHIFT_CFG_DELAY_LTR_ACT                  7
#define BIT_CFG_DELAY_LTR_ACT                        ((u32)0x00000001 << BIT_SHIFT_CFG_DELAY_LTR_ACT)                  /*!<R/W 0  Use obff block timer to send ltr active */
#define BIT_SHIFT_CFG_CTS_LTRACT                     6
#define BIT_CFG_CTS_LTRACT                           ((u32)0x00000001 << BIT_SHIFT_CFG_CTS_LTRACT)                     /*!<R/W 0  CTS direct to send ltr active */
#define BIT_SHIFT_LTRIDLE_NO_SNOOP                   5
#define BIT_LTRIDLE_NO_SNOOP                         ((u32)0x00000001 << BIT_SHIFT_LTRIDLE_NO_SNOOP)                   /*!<R/W 1  Calculating ltr active message sending timing according to no snoop or snoop latency. */
#define BIT_SHIFT_LTRACT_EN_INCPUACT                 4
#define BIT_LTRACT_EN_INCPUACT                       ((u32)0x00000001 << BIT_SHIFT_LTRACT_EN_INCPUACT)                 /*!<R/W 0  Send LTR active in OBFF or CPU active window. */
#define BIT_SHIFT_APP_REQ_LTRACT                     3
#define BIT_APP_REQ_LTRACT                           ((u32)0x00000001 << BIT_SHIFT_APP_REQ_LTRACT)                     /*!<R 0  Driver or cpu direct LTR active message. A message with LTR_ACTIVE_LATENCY will be sent. AUTO CLEAR */
#define BIT_SHIFT_APP_REQ_LTRIDLE                    2
#define BIT_APP_REQ_LTRIDLE                          ((u32)0x00000001 << BIT_SHIFT_APP_REQ_LTRIDLE)                    /*!<R 1  Driver or cpu direct LTR idle message. A message with LTR_IDLE_LATENCY will be sent. AUTO CLEAR */
#define BIT_SHIFT_LTR_HW_EN                          1
#define BIT_LTR_HW_EN                                ((u32)0x00000001 << BIT_SHIFT_LTR_HW_EN)                          /*!<R/W 0  Enable hardware LTR message */
#define BIT_SHIFT_LTR_EN                             0
#define BIT_LTR_EN                                   ((u32)0x00000001 << BIT_SHIFT_LTR_EN)                             /*!<R/W 1  Enable LTR message */

/* REG_LTR_CTRL2 0x07A8 */
#define BIT_SHIFT_OBFF_TIMER_ID_HIGH                 29
#define BIT_MASK_OBFF_TIMER_ID_HIGH                  ((u32)0x00000007 << BIT_SHIFT_OBFF_TIMER_ID_HIGH)                 /*!<R/W 3'b000  When media rate rx packet in , delay rx dma timeout value index. 0: no delay,1: 12.8us; 2: 102.4us; 3: 204.8us; 4: 819.2 us; 5: 1.638ms; 6: 52ms; 7: always block until obff or cpu active window */
#define BIT_SHIFT_HIGH_RATE_BDRY                     16
#define BIT_MASK_HIGH_RATE_BDRY                      ((u32)0x0000007F << BIT_SHIFT_HIGH_RATE_BDRY)                     /*!<R/W 7'b0001110  High, media, low rate boundary */
#define BIT_SHIFT_LOW_RATE_BDRY                      9
#define BIT_MASK_LOW_RATE_BDRY                       ((u32)0x0000007F << BIT_SHIFT_LOW_RATE_BDRY)                      /*!<R/W 7'b1000100  High, media, low rate boundary */
#define BIT_SHIFT_HIGH_RATE_TRIGS                    7
#define BIT_MASK_HIGH_RATE_TRIGS                     ((u32)0x00000003 << BIT_SHIFT_HIGH_RATE_TRIGS)                    /*!<R/W 2'b01  High rate rx ltr trigger point select: 0 plcp ready;1: rx a1 latch OK; 2: fcs ready. */
#define BIT_SHIFT_MEDIA_RATE_TRIGS                   5
#define BIT_MASK_MEDIA_RATE_TRIGS                    ((u32)0x00000003 << BIT_SHIFT_MEDIA_RATE_TRIGS)                   /*!<R/W 2'b11  Media rate rx ltr trigger point select: 0 plcp ready;1: rx a1 latch OK; 2: fcs ready. */
#define BIT_SHIFT_LOW_RATE_TRIGS                     3
#define BIT_MASK_LOW_RATE_TRIGS                      ((u32)0x00000003 << BIT_SHIFT_LOW_RATE_TRIGS)                     /*!<R/W 2'b00  Low rate rx ltr trigger point select: 0 plcp ready;1: rx a1 latch OK; 2: fcs ready. */
#define BIT_SHIFT_RX_EXHAUST_ID                      0
#define BIT_MASK_RX_EXHAUST_ID                       ((u32)0x00000007 << BIT_SHIFT_RX_EXHAUST_ID)                      /*!<R/W 3'b000  When rx page less than this threshold, release obff block rx. */

/* REG_ANTTRN_CTR_V1 0x07B0 */
#define BIT_SHIFT_TRAIN_STA_ADDR1                    0
#define BIT_MASK_TRAIN_STA_ADDR1                     ((u32)0xFFFFFFFF << BIT_SHIFT_TRAIN_STA_ADDR1)                    /*!<R/W 0  The Address of the trained station. Only available when ADDR2_MATCH_EN = 1 */

/* REG_ANTTRN_CTR_1_V1 0x07B4 */
#define BIT_SHIFT_ANTTRN_SWITCH                      19
#define BIT_ANTTRN_SWITCH                            ((u32)0x00000001 << BIT_SHIFT_ANTTRN_SWITCH)                      /*!<R/W 0  Smart antenna use address cam or port register to search A2. 0:Use address cam 1:Use port register */
#define BIT_SHIFT_APPEND_MACID_IN_RESP_EN            18
#define BIT_APPEND_MACID_IN_RESP_EN                  ((u32)0x00000001 << BIT_SHIFT_APPEND_MACID_IN_RESP_EN)            /*!<R/W 0  Whether to append MACID in the rx descriptor of rx response packet */
#define BIT_SHIFT_ADDR2_MATCH_EN                     17
#define BIT_ADDR2_MATCH_EN                           ((u32)0x00000001 << BIT_SHIFT_ADDR2_MATCH_EN)                     /*!<R/W 0  Enable the comparison of ADDR2 for the rx packet.. */
#define BIT_SHIFT_ANTTRN_EN                          16
#define BIT_ANTTRN_EN                                ((u32)0x00000001 << BIT_SHIFT_ANTTRN_EN)                          /*!<R/W 0  Enable the antenna training function */
#define BIT_SHIFT_TRAIN_STA_ADDR2                    0
#define BIT_MASK_TRAIN_STA_ADDR2                     ((u32)0x0000FFFF << BIT_SHIFT_TRAIN_STA_ADDR2)                    /*!<R/W 0  The Address of the trained station. Only available when ADDR2_MATCH_EN = 1 */

/* REG_WMAC_PKTCNT_RWD 0x07B8 */
#define BIT_SHIFT_PKTCNT_BSSIDMAP                    4
#define BIT_MASK_PKTCNT_BSSIDMAP                     ((u32)0x0000000F << BIT_SHIFT_PKTCNT_BSSIDMAP)                    /*!<R/W 0  To decide this counter is for which MBSSID (16�M), default : 0 for counter 0 1 for counter 1 2 for counter 2 3 for counter 3 4 for counter 4 5 for counter 5 6 for counter 6 7 for counter 7 */
#define BIT_SHIFT_PKTCNT_CNTRST                      1
#define BIT_PKTCNT_CNTRST                            ((u32)0x00000001 << BIT_SHIFT_PKTCNT_CNTRST)                      /*!<R/W 0  Write 1 to reset Counter after DRV read all counters , DRV set this bit and HW return 0 after reset */

/* REG_WMAC_PKTCNT_CTRL 0x07BC */
#define BIT_SHIFT_WMAC_PKTCNT_FEN                    8
#define BIT_WMAC_PKTCNT_FEN                          ((u32)0x00000001 << BIT_SHIFT_WMAC_PKTCNT_FEN)                    /*!<R/W 0  Packet counter function enable */
#define BIT_SHIFT_WMAC_PKTCNT_CFGAD                  0
#define BIT_MASK_WMAC_PKTCNT_CFGAD                   ((u32)0x000000FF << BIT_SHIFT_WMAC_PKTCNT_CFGAD)                  /*!<R/W 0  Packet counter configure register read/write address */

/* REG_IQ_DUMP 0x07C0 */
#define BIT_SHIFT_DUMP_OK_ADDR                       16
#define BIT_MASK_DUMP_OK_ADDR                        ((u32)0x0000FFFF << BIT_SHIFT_DUMP_OK_ADDR)                       /*!<R/W 0  [31] : dump signal addr has round up [30:16] : dump finish addr in txpktbuffer */
#define BIT_SHIFT_MACDBG_TRIG_IQDUMP                 15
#define BIT_MACDBG_TRIG_IQDUMP                       ((u32)0x00000001 << BIT_SHIFT_MACDBG_TRIG_IQDUMP)                 /*!<R/W 0  Enable dump bb ADC signal trigger from MAC debug port which controled by r_LEVEL_PULSE_SEL. */
#define BIT_SHIFT_R_TRIG_TIME_SEL                    8
#define BIT_MASK_R_TRIG_TIME_SEL                     ((u32)0x0000007F << BIT_SHIFT_R_TRIG_TIME_SEL)                    /*!<R/W 0  dump ok time to finish dump signal(unit is 1us) */
#define BIT_SHIFT_R_MAC_TRIG_SEL                     6
#define BIT_MASK_R_MAC_TRIG_SEL                      ((u32)0x00000003 << BIT_SHIFT_R_MAC_TRIG_SEL)                     /*!<R/W 0  dump bb ADC sel mac strigger even 2'b00 : rxpkt ok trig dump ok 2'b01 : rxpkt_fauil trig dump ok 2'b10 : rxpkt cca rise edge to trig dump ok */
#define BIT_SHIFT_MAC_TRIG_REG                       5
#define BIT_MAC_TRIG_REG                             ((u32)0x00000001 << BIT_SHIFT_MAC_TRIG_REG)                       /*!<R/W 0  dump bb ADC sel mac strigger even write this reg to 1 to trig dump finish */
#define BIT_SHIFT_R_LEVEL_PULSE_SEL                  3
#define BIT_MASK_R_LEVEL_PULSE_SEL                   ((u32)0x00000003 << BIT_SHIFT_R_LEVEL_PULSE_SEL)                  /*!<R/W 0  if dump bb ADC signal : [3] for sel mac trigger event if dump mac dbg signal [4:3] : 2'b00 : level signal match [4:3] : 2'b01 : posedge match [4:3] : 2'b10 : negdge match */
#define BIT_SHIFT_EN_LA_MAC                          2
#define BIT_EN_LA_MAC                                ((u32)0x00000001 << BIT_SHIFT_EN_LA_MAC)                          /*!<R/W 0  enable dump mac dbg signal */
#define BIT_SHIFT_R_EN_IQDUMP                        1
#define BIT_R_EN_IQDUMP                              ((u32)0x00000001 << BIT_SHIFT_R_EN_IQDUMP)                        /*!<R/W 0  enable dump bb ADC signal */
#define BIT_SHIFT_R_IQDATA_DUMP                      0
#define BIT_R_IQDATA_DUMP                            ((u32)0x00000001 << BIT_SHIFT_R_IQDATA_DUMP)                      /*!<R/W 0  enable data dump for txpktbuffer high 64K */

/* REG_MASK_LA_MAC 0x07C4 */
#define BIT_SHIFT_MASK_LA_MAC                        0
#define BIT_MASK_MASK_LA_MAC                         ((u32)0x00FFFFFF << BIT_SHIFT_MASK_LA_MAC)                        /*!<R/W 0   */

/* REG_MATCH_REF_MAC 0x07C8 */
#define BIT_SHIFT_MATCH_REF_MAC                      0
#define BIT_MASK_MATCH_REF_MAC                       ((u32)0xFFFFFFFF << BIT_SHIFT_MATCH_REF_MAC)                      /*!<R/W 0   */

/* REG_WMAC_FTM_CTL 0x07CC */
#define BIT_SHIFT_RXFTM_TXACK_SC                     6
#define BIT_RXFTM_TXACK_SC                           ((u32)0x00000001 << BIT_SHIFT_RXFTM_TXACK_SC)                     /*!<R/W 0  When HW receive FTM pkt, HW will use RX FTM BW as response ACK TXBW. */
#define BIT_SHIFT_RXFTM_TXACK_BW                     5
#define BIT_RXFTM_TXACK_BW                           ((u32)0x00000001 << BIT_SHIFT_RXFTM_TXACK_BW)                     /*!<R/W 0  When HW receive FTM pkt, HW will use RX FTM SC as response ACK TXSC. */
#define BIT_SHIFT_RXFTM_EN                           3
#define BIT_RXFTM_EN                                 ((u32)0x00000001 << BIT_SHIFT_RXFTM_EN)                           /*!<R/W 0  If BIT_FTM_TYPE = 1 && BIT_RXFTM_EN=1, HW will parsing rx packet, to find FTM request frame. */
#define BIT_SHIFT_RXFTMREQ_BYDRV                     2
#define BIT_RXFTMREQ_BYDRV                           ((u32)0x00000001 << BIT_SHIFT_RXFTMREQ_BYDRV)                     /*!<R/W 0  If set this bit to 1,Rx FTMREQ/FTM can be receive into rxpktbuffer. */
#define BIT_SHIFT_RXFTMREQ_EN                        1
#define BIT_RXFTMREQ_EN                              ((u32)0x00000001 << BIT_SHIFT_RXFTMREQ_EN)                        /*!<R/W 0  If BIT_FTM_TYPE = 1 && BIT_RXFTMREQ_EN=1, HW will parsing rx packet, to find FTM request frame. */
#define BIT_SHIFT_FTM_EN                             0
#define BIT_FTM_EN                                   ((u32)0x00000001 << BIT_SHIFT_FTM_EN)                             /*!<R/W 0  Fine timing measurement function; 0: Disable 1:enable */

/* REG_WMAC_LA_DUMP_FUNC_EXT 0x07CE */
#define BIT_SHIFT_EN_TIMEOUT                         13
#define BIT_EN_TIMEOUT                               ((u32)0x00000001 << BIT_SHIFT_EN_TIMEOUT)                         /*!<R/W 0  Set this bit to 1 to reset mdpk read pointer */
#define BIT_SHIFT_EN_RE_START                        12
#define BIT_EN_RE_START                              ((u32)0x00000001 << BIT_SHIFT_EN_RE_START)                        /*!<R/W 0  Before setting 0x7C0[1:0] =2��b11, set this bit to 1 to enable MDPK access mode */
#define BIT_SHIFT_LA_MAC_TIMEOUT_UNIT_SEL            10
#define BIT_MASK_LA_MAC_TIMEOUT_UNIT_SEL             ((u32)0x00000003 << BIT_SHIFT_LA_MAC_TIMEOUT_UNIT_SEL)            /*!<R/W 0  LA mode triggered by mac debug port timeout value unit selection. 2'b00: 1us, 2'b01:32us, 2'b10: 1ms, 2'b11:RSVD */
#define BIT_SHIFT_LA_MAC_TIMEOUT_VALUE               4
#define BIT_MASK_LA_MAC_TIMEOUT_VALUE                ((u32)0x0000003F << BIT_SHIFT_LA_MAC_TIMEOUT_VALUE)               /*!<R/W 0  LA mode triggered by mac debug port timeout value, available with non-zero value. */
#define BIT_SHIFT_LEVEL_PULSE_SEL_EXT                3
#define BIT_LEVEL_PULSE_SEL_EXT                      ((u32)0x00000001 << BIT_SHIFT_LEVEL_PULSE_SEL_EXT)                /*!<R/W 0  LA mode triggered by mac debug port timeout event */
#define BIT_SHIFT_TRIG_TIME_UNIT_SEL                 0
#define BIT_MASK_TRIG_TIME_UNIT_SEL                  ((u32)0x00000007 << BIT_SHIFT_TRIG_TIME_UNIT_SEL)                 /*!<R/W 0  Select trigger time unit of 0x7C0[14:8]. 3��b000 : 1us , 3��b001 : 2us , 3��b010 : 4us , 3��b011 : 8us , 3��b100 : 16us , 3��b101 : 32us , 3��b110 : 64us, 3��b111 : RSV */

/* REG_OFDM_CCK_LEN_MASK 0x07D0 */
#define BIT_SHIFT_RX_OFDM_LEN_TH                     16
#define BIT_MASK_RX_OFDM_LEN_TH                      ((u32)0x0000FFFF << BIT_SHIFT_RX_OFDM_LEN_TH)                     /*!<R/W 0x0FFF  rx ofdm len over this len to drop pkt(not for ht/vht) */
#define BIT_SHIFT_RX_CCK_LEN_TH                      0
#define BIT_MASK_RX_CCK_LEN_TH                       ((u32)0x0000FFFF << BIT_SHIFT_RX_CCK_LEN_TH)                      /*!<R/W 0x0FFF  rx cck len over this length to drop pkt */

/* REG_WMAC_OPTION_FUNCTION_1 0x07D4 */
#define BIT_SHIFT_R_WMAC_RXFIFO_FULL_TH_1            24
#define BIT_MASK_R_WMAC_RXFIFO_FULL_TH_1             ((u32)0x000000FF << BIT_SHIFT_R_WMAC_RXFIFO_FULL_TH_1)            /*!<R/W 0x50  csi report mac pause bb almost full threshold */
#define BIT_SHIFT_R_WMAC_RX_SYNCFIFO_SYNC_1          23
#define BIT_R_WMAC_RX_SYNCFIFO_SYNC_1                ((u32)0x00000001 << BIT_SHIFT_R_WMAC_RX_SYNCFIFO_SYNC_1)          /*!<R/W 1   */
#define BIT_SHIFT_R_WMAC_RXRST_DLY_1                 22
#define BIT_R_WMAC_RXRST_DLY_1                       ((u32)0x00000001 << BIT_SHIFT_R_WMAC_RXRST_DLY_1)                 /*!<R/W 0  when this bit is set 1, rxrst pulse lasts for 20 cycle of MAC clock, when this bit is set 0, rxrst pulse lasts for 10 cycle of MAC clock, */
#define BIT_SHIFT_R_WMAC_SRCH_TXRPT_REF_DROP_1       21
#define BIT_R_WMAC_SRCH_TXRPT_REF_DROP_1             ((u32)0x00000001 << BIT_SHIFT_R_WMAC_SRCH_TXRPT_REF_DROP_1)       /*!<R/W 0  when this bit is set 1, reference macid drop information when macid search */
#define BIT_SHIFT_R_WMAC_SRCH_TXRPT_UA1_1            20
#define BIT_R_WMAC_SRCH_TXRPT_UA1_1                  ((u32)0x00000001 << BIT_SHIFT_R_WMAC_SRCH_TXRPT_UA1_1)            /*!<R/W 0  when this bit is set 1, use tx A1 to search txrpt when rx ack/cts, when BIT_r_WMAC_SRCH_TXRPT_TYPE is set 0, BIT_r_WMAC_SRCH_TXRPT_UA1 should be set 1 */
#define BIT_SHIFT_R_WMAC_SRCH_TXRPT_TYPE_1           19
#define BIT_R_WMAC_SRCH_TXRPT_TYPE_1                 ((u32)0x00000001 << BIT_SHIFT_R_WMAC_SRCH_TXRPT_TYPE_1)           /*!<R/W 0  for rx ack/cts pkt not to search txrpt buffer macid */
#define BIT_SHIFT_R_WMAC_NDP_RST_1                   18
#define BIT_R_WMAC_NDP_RST_1                         ((u32)0x00000001 << BIT_SHIFT_R_WMAC_NDP_RST_1)                   /*!<R/W 0  rx pkt is ndp to clr macrx_active */
#define BIT_SHIFT_R_WMAC_POWINT_EN_1                 17
#define BIT_R_WMAC_POWINT_EN_1                       ((u32)0x00000001 << BIT_SHIFT_R_WMAC_POWINT_EN_1)                 /*!<R/W 0  enable rx pkt fc column power bit int for FISR */
#define BIT_SHIFT_R_WMAC_SRCH_TXRPT_PERPKT_1         16
#define BIT_R_WMAC_SRCH_TXRPT_PERPKT_1               ((u32)0x00000001 << BIT_SHIFT_R_WMAC_SRCH_TXRPT_PERPKT_1)         /*!<R/W 0  enable search txrpt buffer for macid every pkt */
#define BIT_SHIFT_R_WMAC_SRCH_TXRPT_MID_1            15
#define BIT_R_WMAC_SRCH_TXRPT_MID_1                  ((u32)0x00000001 << BIT_SHIFT_R_WMAC_SRCH_TXRPT_MID_1)            /*!<R/W 1  enable search txrpt buffer for macid */
#define BIT_SHIFT_R_WMAC_PFIN_TOEN_1                 14
#define BIT_R_WMAC_PFIN_TOEN_1                       ((u32)0x00000001 << BIT_SHIFT_R_WMAC_PFIN_TOEN_1)                 /*!<R/W 0  rx fifo fsm flush state timeout to error stage */
#define BIT_SHIFT_R_WMAC_FIL_SECERR_1                13
#define BIT_R_WMAC_FIL_SECERR_1                      ((u32)0x00000001 << BIT_SHIFT_R_WMAC_FIL_SECERR_1)                /*!<R/W 1  sec len error drop(sec len is zero) */
#define BIT_SHIFT_R_WMAC_FIL_CTLPKTLEN_1             12
#define BIT_R_WMAC_FIL_CTLPKTLEN_1                   ((u32)0x00000001 << BIT_SHIFT_R_WMAC_FIL_CTLPKTLEN_1)             /*!<R/W 0  drop the rx pkt if the rx ctrl pkt len large than r_WMAC_RX_FIL_LEN */
#define BIT_SHIFT_R_WMAC_FIL_FCTYPE_1                11
#define BIT_R_WMAC_FIL_FCTYPE_1                      ((u32)0x00000001 << BIT_SHIFT_R_WMAC_FIL_FCTYPE_1)                /*!<R/W 0  drop the ofdm pkt if the rx ofdm leg pkt fc type is 2'b11 */
#define BIT_SHIFT_R_WMAC_FIL_FCPROVER_1              10
#define BIT_R_WMAC_FIL_FCPROVER_1                    ((u32)0x00000001 << BIT_SHIFT_R_WMAC_FIL_FCPROVER_1)              /*!<R/W 0  drop the ofdm pkt if the rx ofdm leg pkt fc version illegal */
#define BIT_SHIFT_R_WMAC_PHYSTS_SNIF_1               9
#define BIT_R_WMAC_PHYSTS_SNIF_1                     ((u32)0x00000001 << BIT_SHIFT_R_WMAC_PHYSTS_SNIF_1)               /*!<R/W 0  append sniff info after phy status */
#define BIT_SHIFT_R_WMAC_PHYSTS_PLCP_1               8
#define BIT_R_WMAC_PHYSTS_PLCP_1                     ((u32)0x00000001 << BIT_SHIFT_R_WMAC_PHYSTS_PLCP_1)               /*!<R/W 0  append plcp header after phy status */
#define BIT_SHIFT_R_MAC_TCR_VBONF_RD_1               7
#define BIT_R_MAC_TCR_VBONF_RD_1                     ((u32)0x00000001 << BIT_SHIFT_R_MAC_TCR_VBONF_RD_1)               /*!<R/W 0  vbon neg edge to read all data of mac rx sync fifo for rx parser */
#define BIT_SHIFT_R_WMAC_TCR_MPAR_NDP_1              6
#define BIT_R_WMAC_TCR_MPAR_NDP_1                    ((u32)0x00000001 << BIT_SHIFT_R_WMAC_TCR_MPAR_NDP_1)              /*!<R/W 0  nop ok check bb ndp vld & mac rx ndp check ok */
#define BIT_SHIFT_R_WMAC_NDP_FILTER_1                5
#define BIT_R_WMAC_NDP_FILTER_1                      ((u32)0x00000001 << BIT_SHIFT_R_WMAC_NDP_FILTER_1)                /*!<R/W 0  mac rx ndp pkt set ppdu len to 0 */
#define BIT_SHIFT_R_WMAC_RXLEN_SEL_1                 4
#define BIT_R_WMAC_RXLEN_SEL_1                       ((u32)0x00000001 << BIT_SHIFT_R_WMAC_RXLEN_SEL_1)                 /*!<R/W 0  rx vht len sel lsig len VHT PPDU length selection 0: �յ�VHT PPDU PKT ������ VHTSIGB PPDU length ��parsing �cӋ�� 1: �յ�VHT PPDU PKT ������ BB ��� LSIG length ��parsing �cӋ�� */
#define BIT_SHIFT_R_WMAC_RXLEN_SEL1_1                3
#define BIT_R_WMAC_RXLEN_SEL1_1                      ((u32)0x00000001 << BIT_SHIFT_R_WMAC_RXLEN_SEL1_1)                /*!<R/W 0  rx vht len sel lsig len if sigb len is more than lsig len */
#define BIT_SHIFT_R_OFDM_FILTER_1                    2
#define BIT_R_OFDM_FILTER_1                          ((u32)0x00000001 << BIT_SHIFT_R_OFDM_FILTER_1)                    /*!<R/W 0  RSVD */
#define BIT_SHIFT_R_WMAC_CHK_OFDM_LEN_1              1
#define BIT_R_WMAC_CHK_OFDM_LEN_1                    ((u32)0x00000001 << BIT_SHIFT_R_WMAC_CHK_OFDM_LEN_1)              /*!<R/W 0  enable to check ofdm len */
#define BIT_SHIFT_R_WMAC_CHK_CCK_LEN_1               0
#define BIT_R_WMAC_CHK_CCK_LEN_1                     ((u32)0x00000001 << BIT_SHIFT_R_WMAC_CHK_CCK_LEN_1)               /*!<R/W 0  enable to check rx cck len */

/* REG_WMAC_OPTION_FUNCTION_2 0x07D8 */
#define BIT_SHIFT_R_WMAC_RX_FIL_LEN_2                0
#define BIT_MASK_R_WMAC_RX_FIL_LEN_2                 ((u32)0x0000FFFF << BIT_SHIFT_R_WMAC_RX_FIL_LEN_2)                /*!<R/W 0x41  use with BIT_r_WMAC_FIL_CTLPKTLEN */

/* REG_RX_FILTER_FUNCTION 0x07DA */
#define BIT_SHIFT_RXHANG_EN                          15
#define BIT_RXHANG_EN                                ((u32)0x00000001 << BIT_SHIFT_RXHANG_EN)                          /*!<R/W 0  Force read error content from fifo to solve rxhang. */
#define BIT_SHIFT_R_WMAC_MHRDDY_LATCH                14
#define BIT_R_WMAC_MHRDDY_LATCH                      ((u32)0x00000001 << BIT_SHIFT_R_WMAC_MHRDDY_LATCH)                /*!<R/W 0  Adjust mach_rdy timing if rx_parser and rxpktfifo FSM is not sync. */
#define BIT_SHIFT_R_WMAC_MHRDDY_CLR                  13
#define BIT_R_WMAC_MHRDDY_CLR                        ((u32)0x00000001 << BIT_SHIFT_R_WMAC_MHRDDY_CLR)                  /*!<R/W 1  Reset mach_rdy_latch when rx parser begin parsing mac header. */
#define BIT_SHIFT_R_RXPKTCTL_FSM_BASED_MPDURDY1      12
#define BIT_R_RXPKTCTL_FSM_BASED_MPDURDY1            ((u32)0x00000001 << BIT_SHIFT_R_RXPKTCTL_FSM_BASED_MPDURDY1)      /*!<R/W 1  Adjust mpdu_rdy timing to solve FSM behavier error. */
#define BIT_SHIFT_WMAC_DIS_VHT_PLCP_CHK_MU           11
#define BIT_WMAC_DIS_VHT_PLCP_CHK_MU                 ((u32)0x00000001 << BIT_SHIFT_WMAC_DIS_VHT_PLCP_CHK_MU)           /*!<R/W 0  Disable check sigb crc value of MU plcp header. */
#define BIT_SHIFT_R_CHK_DELIMIT_LEN                  10
#define BIT_R_CHK_DELIMIT_LEN                        ((u32)0x00000001 << BIT_SHIFT_R_CHK_DELIMIT_LEN)                  /*!<R/W 0  Drop mpdu if delimeter mpdu length smaller than mac header length + 4. */
#define BIT_SHIFT_R_REAPTER_ADDR_MATCH               9
#define BIT_R_REAPTER_ADDR_MATCH                     ((u32)0x00000001 << BIT_SHIFT_R_REAPTER_ADDR_MATCH)               /*!<R/W 0  when this bit is set 1, physical address is matched when rx A1 is equal to tx A2, used in repeater mode */
#define BIT_SHIFT_R_RXPKTCTL_FSM_BASED_MPDURDY       8
#define BIT_R_RXPKTCTL_FSM_BASED_MPDURDY             ((u32)0x00000001 << BIT_SHIFT_R_RXPKTCTL_FSM_BASED_MPDURDY)       /*!<R/W 0  when this bit is set 1, rxpktfifo_ctl FSM jumps based on mpdu_valid(all MPDU data has been transferred to rxpktbuffer), when this bit is set 0, rxpktfifo_ctl FSM jumps based on fcs_valid(all MPDU data has been parsed by rx_parser) */
#define BIT_SHIFT_R_LATCH_MACHRDY                    7
#define BIT_R_LATCH_MACHRDY                          ((u32)0x00000001 << BIT_SHIFT_R_LATCH_MACHRDY)                    /*!<R/W 1  when this bit set 1,mach_rdy signal is latched to make sure that rxpktfifo_ctl can detect it */
#define BIT_SHIFT_R_WMAC_RXFIL_REND                  6
#define BIT_R_WMAC_RXFIL_REND                        ((u32)0x00000001 << BIT_SHIFT_R_WMAC_RXFIL_REND)                  /*!<R/W 0  when this bit set 1,icvmic_valid signal is cleared when icvmic_rdy is valid(ICV/MIC is parsed) */
#define BIT_SHIFT_R_WMAC_MPDURDY_CLR                 5
#define BIT_R_WMAC_MPDURDY_CLR                       ((u32)0x00000001 << BIT_SHIFT_R_WMAC_MPDURDY_CLR)                 /*!<R/W 0  when the bit is set 1, the last MPDU which will be transferred to rxpktfifo is ready and error occurs, mpdu_rdy signal is also valid(is means all MPDU data has been transferred to rxpktbuffer) */
#define BIT_SHIFT_R_WMAC_CLRRXSEC                    4
#define BIT_R_WMAC_CLRRXSEC                          ((u32)0x00000001 << BIT_SHIFT_R_WMAC_CLRRXSEC)                    /*!<R/W 0  If new rx pkt is coming, reset the previous rx key search result. */
#define BIT_SHIFT_R_WMAC_RXFIL_RDEL                  3
#define BIT_R_WMAC_RXFIL_RDEL                        ((u32)0x00000001 << BIT_SHIFT_R_WMAC_RXFIL_RDEL)                  /*!<R/W 0  If new rx pkt is coming, reset the rxpkt_ctl FSM after parsing plcp. */
#define BIT_SHIFT_R_WMAC_RXFIL_FCSE                  2
#define BIT_R_WMAC_RXFIL_FCSE                        ((u32)0x00000001 << BIT_SHIFT_R_WMAC_RXFIL_FCSE)                  /*!<R/W 0  If rx pkt is not ampdu and rejected, reset rxpkt_ctl FSM immediately after parsing header */
#define BIT_SHIFT_R_WMAC_RXFIL_MESH_DEL              1
#define BIT_R_WMAC_RXFIL_MESH_DEL                    ((u32)0x00000001 << BIT_SHIFT_R_WMAC_RXFIL_MESH_DEL)              /*!<R/W 0  drop the ofdm pkt if the rx ofdm leg pkt fc type is 2'b11 */
#define BIT_SHIFT_R_WMAC_RXFIL_MASKM                 0
#define BIT_R_WMAC_RXFIL_MASKM                       ((u32)0x00000001 << BIT_SHIFT_R_WMAC_RXFIL_MASKM)                 /*!<R/W 1  drop the ofdm pkt if the rx ofdm leg pkt fc type is 2'b11 */

/* REG_WMAC_OPTION_FUNCTION_2 0x07E0 */
#define BIT_SHIFT_R_WMAC_TXNDP_SIGB                  0
#define BIT_MASK_R_WMAC_TXNDP_SIGB                   ((u32)0x001FFFFF << BIT_SHIFT_R_WMAC_TXNDP_SIGB)                  /*!<R/W 0x1845A5  SIGB for NDP packet when BW =40MHz */

/* REG_WMAC_DBG_SEL 0x07E4 */
#define BIT_SHIFT_MAC_DBG_SHIFT                      8
#define BIT_MASK_MAC_DBG_SHIFT                       ((u32)0x00000007 << BIT_SHIFT_MAC_DBG_SHIFT)                      /*!<R/W 0   */
#define BIT_SHIFT_MAC_DBG_SEL                        0
#define BIT_MASK_MAC_DBG_SEL                         ((u32)0x00000003 << BIT_SHIFT_MAC_DBG_SEL)                        /*!<R/W 0   */

/* REG_WMAC_DBG_SHIFT 0x07E8 */
#define BIT_SHIFT_MACTX_CMD_SHIFT                    0
#define BIT_MASK_MACTX_CMD_SHIFT                     ((u32)0xFFFFFFFF << BIT_SHIFT_MACTX_CMD_SHIFT)                    /*!<R 0   */

/* REG_WSEC_OPTION 0x07EC */
#define BIT_SHIFT_RXDEC_BM_MGNT                      22
#define BIT_RXDEC_BM_MGNT                            ((u32)0x00000001 << BIT_SHIFT_RXDEC_BM_MGNT)                      /*!<R/W 1  decryption enable of rx multicast management pkt, 0x680[3] shall also be set valid */
#define BIT_SHIFT_TXENC_BM_MGNT                      21
#define BIT_TXENC_BM_MGNT                            ((u32)0x00000001 << BIT_SHIFT_TXENC_BM_MGNT)                      /*!<R/W 1  encryption enable of tx multicast management pkt, 0x680[2] shall also be set valid */
#define BIT_SHIFT_RXDEC_UNI_MGNT                     20
#define BIT_RXDEC_UNI_MGNT                           ((u32)0x00000001 << BIT_SHIFT_RXDEC_UNI_MGNT)                     /*!<R/W 1  decryption enable of rx unicast management pkt, 0x680[3] shall also be set valid */
#define BIT_SHIFT_TXENC_UNI_MGNT                     19
#define BIT_TXENC_UNI_MGNT                           ((u32)0x00000001 << BIT_SHIFT_TXENC_UNI_MGNT)                     /*!<R/W 1  encryption enable of tx unicast management pkt, 0x680[2] shall also be set valid */
#define BIT_SHIFT_WMAC_SEC_MASKIV                    18
#define BIT_WMAC_SEC_MASKIV                          ((u32)0x00000001 << BIT_SHIFT_WMAC_SEC_MASKIV)                    /*!<R/W 0  MASK IV[15:8] for GCMP security */
#define BIT_SHIFT_WMAC_SEC_PN_SEL                    16
#define BIT_MASK_WMAC_SEC_PN_SEL                     ((u32)0x00000003 << BIT_SHIFT_WMAC_SEC_PN_SEL)                    /*!<R/W 0  Security GCMP header PN selection */
#define BIT_SHIFT_BT_TIME_CNT                        0
#define BIT_MASK_BT_TIME_CNT                         ((u32)0x000000FF << BIT_SHIFT_BT_TIME_CNT)                        /*!<R/W 0x64  US timer counter boundary of BTCOEXIST */

/* REG_RTS_ADDRESS_0 0x07F0 */
#define BIT_SHIFT_R_WMAC_RTS_ADDR0                   0
#define BIT_MASK_R_WMAC_RTS_ADDR0                    ((u32)0xFFFFFFFF << BIT_SHIFT_R_WMAC_RTS_ADDR0)                   /*!<R/W 0  if 0x604[31]=1 & rts is multicast, use this value as Address1 of RTS */

/* REG_RTS_ADDRESS_0_1 0x07F4 */
#define BIT_SHIFT_R_WMAC_RTS_ADDR0_1                 0
#define BIT_MASK_R_WMAC_RTS_ADDR0_1                  ((u32)0x0000FFFF << BIT_SHIFT_R_WMAC_RTS_ADDR0_1)                 /*!<R/W 0  if 0x604[31]=1 & rts is multicast, use this value as Address1 of RTS */

/* REG_RTS_ADDRESS_1 0x07F8 */
#define BIT_SHIFT_R_WMAC_RTS_ADDR1                   0
#define BIT_MASK_R_WMAC_RTS_ADDR1                    ((u32)0xFFFFFFFF << BIT_SHIFT_R_WMAC_RTS_ADDR1)                   /*!<R/W 0  if 0x604[31]=1 & rts is multicast, use this value as Address1 of RTS */

/* REG_RTS_ADDRESS_1_1 0x07FC */
#define BIT_SHIFT_R_WMAC_RTS_ADDR1_1                 0
#define BIT_MASK_R_WMAC_RTS_ADDR1_1                  ((u32)0x0000FFFF << BIT_SHIFT_R_WMAC_RTS_ADDR1_1)                 /*!<R/W 0  if 0x604[31]=1 & rts is multicast, use this value as Address1 of RTS */



/*========== Register Address Definition==========*/
#define REG_SYS_PWC_CTRL                             0x0000
#define REG_WL_CLK_CTRL                              0x0002
#define REG_WL_FUNC_EN                               0x0004
#define REG_CLKDIV                                   0x0008
#define REG_RSV_CTRL                                 0x001C
#define REG_WL_PMC_CTRL                              0x0020
#define REG_WL_SYSCONFIG                             0x0024
#define REG_AFC_CTRL0                                0x0030
#define REG_AFE_CTRL1_V1                             0x0034
#define REG_AFE_CTRL2_V1                             0x0038
#define REG_AFE_CTRL3_V1                             0x003C
#define REG_FSIMR_V1                                 0x0040
#define REG_FSISR_V1                                 0x0044
#define REG_FW_DBG0_V1                               0x0050
#define REG_FW_DBG1_V1                               0x0054
#define REG_FW_DBG2_V1                               0x0008
#define REG_FW_DBG3_V1                               0x000C
#define REG_FW_DBG4_V1                               0x0060
#define REG_FW_DBG5_V1                               0x0064
#define REG_FW_DBG6_V1                               0x0068
#define REG_FW_DBG7_V1                               0x006C
#define REG_WL_PIN_FUNC_CTRL0                        0x0070
#define REG_WL_BTCOEX_CTRL                           0x0074
#define REG_DBG_PORT_REG                             0x007C
#define REG_WL_MCUFW_CTRL                            0x0080
#define REG_BLK_TST                                  0x0084
#define REG_HOST_MSG0                                0x0088
#define REG_HOST_MSG1                                0x008C
#define REG_LPS_CTRL                                 0x0090
#define REG_BOOT_REASON                              0x0098
#define REG_RPWM2                                    0x009C
#define REG_SCOREBOARD_CTRL                          0x00A0
#define REG_SYSON_FSM_MON_V1                         0x00A4
#define REG_PMC_DBG_CTRL1                            0x00A8
#define REG_PMC_DBG_CTRL2_V1                         0x00AC
#define REG_HIMR0                                    0x00B0
#define REG_HISR0                                    0x00B4
#define REG_HEMR                                     0x00B8
#define REG_HESR                                     0x00BC
#define REG_HIMR2                                    0x00C0
#define REG_HISR2                                    0x00C4
#define REG_SDM_IDR_CTRL0                            0x00E8
#define REG_SDM_IDR_CTRL1                            0x00EC
#define REG_SYS_CONFIG0                              0x00F0

/*========== Register Address Definition==========*/
#define REG_CR                                       0x0100
#define REG_PG_SIZE                                  0x0104
#define REG_TSF_CLK_STATE                            0x0108
#define REG_TXDMA_PQ_MAP                             0x010C
#define REG_TRXFF_BNDY                               0x0114
#define REG_PTA_I2C_MBOX                             0x0118
#define REG_RXFF_PTR                                 0x011C
#define REG_FE1IMR                                   0x0120
#define REG_FE1ISR                                   0x0124
#define REG_CPWM                                     0x012C
#define REG_FWIMR                                    0x0130
#define REG_FWISR                                    0x0134
#define REG_FTIMR                                    0x0138
#define REG_FTISR                                    0x013C
#define REG_PKTBUF_DBG_CTRL                          0x0140
#define REG_PKTBUF_DBG_DATA_L                        0x0144
#define REG_PKTBUF_DBG_DATA_H                        0x0148
#define REG_CPWM2                                    0x014C
#define REG_TC0_CTRL                                 0x0150
#define REG_TC1_CTRL                                 0x0154
#define REG_TC2_CTRL                                 0x0158
#define REG_TC3_CTRL                                 0x015C
#define REG_TC4_CTRL                                 0x0160
#define REG_TCUNIT_BASE                              0x0164
#define REG_TC5_CTRL                                 0x0168
#define REG_TC6_CTRL                                 0x016C
#define REG_MBIST_DRF_FAIL                           0x0170
#define REG_MBIST_START_PAUSE                        0x0174
#define REG_MBIST_DONE                               0x0178
#define REG_MBIST_NRML_FAIL                          0x017C
#define REG_AES_DECRPT_DATA                          0x0180
#define REG_AES_DECRPT_CFG                           0x0184
#define REG_RSHA1_DATA                               0x0188
#define REG_MACCLKFRQ                                0x018C
#define REG_TMETER                                   0x0190
#define REG_OSC_32K_CTRL                             0x0194
#define REG_32K_CAL_REG0                             0x0198
#define REG_32K_XTAL_CR                              0x019C
#define REG_C2HEVT                                   0x01A0
#define REG_C2HEVT_1                                 0x01A4
#define REG_C2HEVT_2                                 0x01A8
#define REG_C2HEVT_3                                 0x01AC
#define REG_HW_IOE_CR                                0x01B0
#define REG_BB_RFC_ATR                               0x01B4
#define REG_SW_DEFINED_PAGE1                         0x01B8
#define REG_SW_DEFINED_PAGE2                         0x01BC
#define REG_MCUTST_I                                 0x01C0
#define REG_MCUTST_II                                0x01C4
#define REG_FMETHR                                   0x01C8
#define REG_HMETFR                                   0x01CC
#define REG_HMEBOX0                                  0x01D0
#define REG_HMEBOX1                                  0x01D4
#define REG_HMEBOX2                                  0x01D8
#define REG_HMEBOX3                                  0x01DC
#define REG_LLT_IND_ACCESS                           0x01E0
#define REG_GENTST                                   0x01E4
#define REG_BB_ACCESS_CTRL                           0x01E8
#define REG_BB_ACCESS_DATA                           0x01EC
#define REG_HMEBOX_E0                                0x01F0
#define REG_HMEBOX_E1                                0x01F4
#define REG_HMEBOX_E2                                0x01F8
#define REG_HMEBOX_E3                                0x01FC
#define REG_ZB2WL_MAILBOX                            0x1110
#define REG_WL2ZB_MAILBOX                            0x1114
#define REG_FE2IMR                                   0x1120
#define REG_FE2ISR                                   0x1124
#define REG_FE3IMR                                   0x1128
#define REG_FE3ISR                                   0x112C
#define REG_FE4IMR                                   0x1130
#define REG_FE4ISR                                   0x1134
#define REG_FT1IMR                                   0x1138
#define REG_FT1ISR                                   0x113C
#define REG_FE5IMR                                   0x1168
#define REG_FE5ISR                                   0x116C
#define REG_FE6IMR                                   0x1170
#define REG_FE6ISR                                   0x1174
#define REG_EXT_QUEUE_REGISTER                       0x117C
#define REG_BT_MAILBOX_OUT_LOW                       0x1190
#define REG_BT_MAILBOX_OUT_HIGH                      0x1194
#define REG_BT_MAILBOX_CONTROL                       0x1198
#define REG_BT_MAILBOX_IN_LOW                        0x119C
#define REG_BT_MAILBOX_IN_HIGH                       0x11A0
#define REG_EXT_BT_MAILBOX_OUT_LOW                   0x11A4
#define REG_EXT_BT_MAILBOX_OUT_HIGH                  0x11A8
#define REG_EXT_BT_MAILBOX_CONTROL                   0x11AC
#define REG_EXT_BT_MAILBOX_IN_LOW                    0x11B0
#define REG_EXT_BT_MAILBOX_IN_HIGH                   0x11B4
#define REG_FWIMR1                                   0x11C0
#define REG_FWISR1                                   0x11C4
#define REG_FT2IMR                                   0x11E0
#define REG_FT2ISR                                   0x11E4

/*========== Register Address Definition==========*/
#define REG_RQPN_CTRL_HLPQ                           0x0200
#define REG_FIFOPAGE_INFO                            0x0204
#define REG_DWBCN0_CTRL                              0x0208
#define REG_TXDMA_OFFSET_CHK                         0x020C
#define REG_TXDMA_STATUS                             0x0210
#define REG_RQPN_NPQ                                 0x0214
#define REG_TQPNT1                                   0x0218
#define REG_TQPNT2                                   0x021C
#define REG_TDE_DEBUG                                0x0220
#define REG_AUTO_LLT                                 0x0224
#define REG_DWBCN1_CTRL                              0x0228
#define REG_TX_ALIGNMENT_CTRL                        0x022C
#define REG_TDE_GCK_CTRL                             0x0230
#define REG_TQPNT3_V1                                0x0234
#define REG_H2C_HEAD                                 0x0244
#define REG_RXDMA_AGG_PG_TH                          0x0280
#define REG_RXPKT_NUM                                0x0284
#define REG_RXDMA_STATUS                             0x0288
#define REG_RXDMA_DPR                                0x028C
#define REG_RXDMA_MODE                               0x0290
#define REG_C2H_PKT                                  0x0294
#define REG_DDMA_CH0SA                               0x1200
#define REG_DDMA_CH0DA                               0x1204
#define REG_DDMA_CH0CTRL                             0x1208
#define REG_DDMA_CH1SA                               0x1210
#define REG_DDMA_CH1DA                               0x1214
#define REG_DDMA_CH1CTRL                             0x1218
#define REG_DDMA_CH2SA                               0x1220
#define REG_DDMA_CH2DA                               0x1224
#define REG_DDMA_CH2CTRL                             0x1228
#define REG_DDMA_CH3SA                               0x1230
#define REG_DDMA_CH3DA                               0x1234
#define REG_DDMA_CH3CTRL                             0x1238
#define REG_DDMA_CH4SA                               0x1240
#define REG_DDMA_CH4DA                               0x1244
#define REG_DDMA_CH4CTRL                             0x1248
#define REG_DDMA_CH5SA                               0x1250
#define REG_DDMA_CH5DA                               0x1254
#define REG_DDMA_CH5CTRL                             0x1258
#define REG_DDMA_INT_MSK                             0x12E0
#define REG_DDMA_INT_STS                             0x12E4
#define REG_DDMA_CHSTATUS                            0x12E8
#define REG_DDMA_CHKSUM                              0x12F0
#define REG_DDMA_MONITOR                             0x12FC

/*========== Register Address Definition==========*/
#define REG_Q0_INFO                                  0x0400
#define REG_Q1_INFO                                  0x0404
#define REG_Q2_INFO                                  0x0408
#define REG_Q3_INFO                                  0x040C
#define REG_MGQ_INFO                                 0x0410
#define REG_HIQ_INFO                                 0x0414
#define REG_BCNQ_INFO                                0x0418
#define REG_TXPKT_EMPTY                              0x041A
#define REG_CPU_MGQ_INFO                             0x041C
#define REG_FWHW_TXQ_HWSSN_CTRL                      0x0420
#define REG_BNDY_LIFETIME_TAIL                       0x0424
#define REG_RETRY_LIMIT_SIFS                         0x0428
#define REG_TXBF_CTRL                                0x042C
#define REG_DARFRC_L                                 0x0430
#define REG_DARFRC_H                                 0x0434
#define REG_RARFRC_L                                 0x0438
#define REG_RARFRC_H                                 0x043C
#define REG_RRSR                                     0x0440
#define REG_ARFR_L0                                  0x0444
#define REG_ARFR_H0                                  0x0448
#define REG_ARFR_L1                                  0x044C
#define REG_ARFR_H1                                  0x0450
#define REG_BCN_AMPDU_CTCL                           0x0454
#define REG_AMPDU_MAX_LENGTH                         0x0458
#define REG_ACQ_STOP                                 0x045C
#define REG_WMAC_LBK_BUF_HD                          0x045D
#define REG_QUEUE_CTRL                               0x045E
#define REG_NDPA_OPT_CTRL                            0x045F
#define REG_RD_RESP_PKT_TH                           0x0460
#define REG_CMDQ_INFO                                0x0464
#define REG_Q4_INFO                                  0x0468
#define REG_Q5_INFO                                  0x046C
#define REG_Q6_INFO                                  0x0470
#define REG_Q7_INFO                                  0x0474
#define REG_GCLK_CFG                                 0x0478
#define REG_TXRPT_CTRL                               0x047C
#define REG_CFEND_RATE_SC_CTRL                       0x0480
#define REG_MACID_SLEEP3                             0x0484
#define REG_MACID_SLEEP1                             0x0488
#define REG_ARFR_L2                                  0x048C
#define REG_ARFR_H2                                  0x0490
#define REG_ARFR_L3                                  0x0494
#define REG_ARFR_H3                                  0x0498
#define REG_ARFR_L4                                  0x049C
#define REG_ARFR_H4                                  0x04A0
#define REG_ARFR_L5                                  0x04A4
#define REG_ARFR_H5                                  0x04A8
#define REG_TXRPT_START_OFFSET                       0x04AC
#define REG_POWER_STAGE1                             0x04B4
#define REG_POWER_STAGE2                             0x04B8
#define REG_SW_AMPDU_BURST_MODE_CTRL                 0x04BC
#define REG_PKT_LIFE_TIME                            0x04C0
#define REG_STBC_SETTING                             0x04C4
#define REG_PTA_CTRL                                 0x04C6
#define REG_PROT_MODE_CTRL                           0x04C8
#define REG_BAR_MODE_CTRL                            0x04CC
#define REG_MACID_SLEEP2                             0x04D0
#define REG_MACID_SLEEP                              0x04D4
#define REG_HW_SEQ0_1                                0x04D8
#define REG_HW_SEQ2_3                                0x04DC
#define REG_NULL_PKT_STATUS                          0x04E0
#define REG_PTCL_ERR_STATUS                          0x04E2
#define REG_PRETX_DROP_CTRL                          0x04E4
#define REG_BT_POLLUTE_PKT_CNT                       0x04E8
#define REG_DROP_PKT_NUM                             0x04EC
#define REG_CPUMGQ_TIMER_CTRL                        0x04F4
#define REG_DUMMY                                    0x04FC
#define REG_ARFR_L6                                  0x1400
#define REG_ARFR_H6                                  0x1404
#define REG_ARFR_L7                                  0x1408
#define REG_ARFR_H7                                  0x140C
#define REG_ARFR_L8                                  0x1410
#define REG_ARFR_H8                                  0x1414
#define REG_AESIV_SETTING                            0x1424
#define REG_BF0_TIME_SETTING                         0x1428
#define REG_BF1_TIME_SETTING                         0x142C
#define REG_BF_TIMEOUT_EN                            0x1430
#define REG_MACID_RELEASE0                           0x1434
#define REG_MACID_RELEASE1                           0x1438
#define REG_MACID_RELEASE2                           0x143C
#define REG_MACID_RELEASE3                           0x1440
#define REG_MACID_RELEASE_SETTING                    0x1444
#define REG_FAST_EDCA_VOVI_SETTING                   0x1448
#define REG_FAST_EDCA_BEBK_SETTING                   0x144C
#define REG_MACID_DROP0                              0x1450
#define REG_MACID_DROP1                              0x1454
#define REG_MACID_DROP2                              0x1458
#define REG_MACID_DROP3                              0x145C
#define REG_R_MACID_RELEASE_SUCCESS_0                0x1460
#define REG_R_MACID_RELEASE_SUCCESS_1                0x1464
#define REG_R_MACID_RELEASE_SUCCESS_2                0x1468
#define REG_R_MACID_RELEASE_SUCCESS_3                0x146C
#define REG_MGQ_FIFO_CTRL                            0x1470
#define REG_MGQ_FIFO_RELEASE_INT                     0x1474
#define REG_MGQ_FIFO_LIFETIME_VALID                  0x1478
#define REG_R_MACID_RELEASE_SUCCESS_CLEAR_OFFSET     0x147C

/*========== Register Address Definition==========*/
#define REG_EDCA_VO_PARAM                            0x0500
#define REG_EDCA_VI_PARAM                            0x0504
#define REG_EDCA_BE_PARAM                            0x0508
#define REG_EDCA_BK_PARAM                            0x050C
#define REG_BCN_CFG_PIFS                             0x0510
#define REG_SIFS                                     0x0514
#define REG_TSFT_SYN_OFFSET_SLOT                     0x0518
#define REG_PS_NOA_ERLY_TIME                         0x051C
#define REG_TX_PTCL_CTRL                             0x0520
#define REG_TXPAUSE                                  0x0522
#define REG_DIS_TXREQ_CLR                            0x0523
#define REG_RD_CTRL                                  0x0524
#define REG_MBSSID_CTRL                              0x0526
#define REG_P2P_NOA0_CTRL                            0x0527
#define REG_PKT_LIFETIME_CTRL                        0x0528
#define REG_P2P_NOA0_SPEC_STATE_H                    0x052B
#define REG_P2PON_DIS_TXTIME                         0x0530
#define REG_NAN_SETTING_2                            0x0534
#define REG_QUEUE_INCOL_THR                          0x0538
#define REG_QUEUE_INCOL_EN                           0x053C
#define REG_TBTT_PROHIBIT                            0x0540
#define REG_P2P_NOA0_SPEC_STATE_L                    0x0543
#define REG_NAV_CTRL                                 0x0544
#define REG_FTM_CTRL                                 0x0548
#define REG_FTM_TSF_CNT                              0x054C
#define REG_BCN_CTRL_PORT0                           0x0550
#define REG_BCN_CTRL_PORT1                           0x0551
#define REG_MBID_NUM_P2P_RST                         0x0552
#define REG_DUAL_TSF_RST                             0x0553
#define REG_PORT0_BCN_SPACE                          0x0554
#define REG_PORT0_BCN_ERLY_DMA_CTRL                  0x0558
#define REG_DRVERLYINT 			REG_PORT0_BCN_ERLY_DMA_CTRL
#define REG_ATIMWND0                                 0x055A
#define REG_USTIME_TSF                               0x055C
#define REG_BCN_MAX_ERR                              0x055D
#define REG_RXTSF_OFFSET_CCK                         0x055E
#define REG_RXTSF_OFFSET_OFDM                        0x055F
#define REG_P0_TSFTR_L                               0x0560
#define REG_P0_TSFTR_H                               0x0564
#define REG_P1_TSFTR_L                               0x0568
#define REG_P1_TSFTR_H                               0x056C
#define REG_BCN_ERLY_CTW_CTRL                        0x0570
#define REG_BCNDROPCTRL                              0x0574
#define REG_HGQ_TIMEOUT_PERIOD                       0x0575
#define REG_TXCMD_TIMEOUT_PERIOD                     0x0576
#define REG_MISC_CTRL                                0x0577
#define REG_P2_TSFTR_L                               0x0578
#define REG_P2_TSFTR_H                               0x057C
#define REG_TSF_TIMER1                               0x0580
#define REG_TSF_TIMER2                               0x0584
#define REG_TSF_TIMER3                               0x0588
#define REG_BCN_IFS_TBTT_CTN                         0x058C
#define REG_TXOP_MIN                                 0x0590
#define REG_PRE_BKF_TIME                             0x0592
#define REG_CROSS_TXOP_CTRL                          0x0593
#define REG_FREERUN_CNT_L                            0x0594
#define REG_FREERUN_CNT_H                            0x0598
#define REG_BCN_ERLY_CTW_CTRL_P1_2                   0x059C
#define REG_ATIMWND2                                 0x05A0
#define REG_ATIMWND3                                 0x05A1
#define REG_ATIMWND4                                 0x05A2
#define REG_ATIMWND5                                 0x05A3
#define REG_ATIMWND6                                 0x05A4
#define REG_ATIMWND7                                 0x05A5
#define REG_ATIM_URGENT                              0x05A6
#define REG_HIQ_NO_LMT_EN                            0x05A7
#define REG_DTIM_COUNT_0_3                           0x05A8
#define REG_DTIM_COUNT_4_7                           0x05AC
#define REG_DIS_ATIM                                 0x05B0
#define REG_EARLY_128US                              0x05B1
#define REG_TBTT_HOLD_PREDICT_P1                     0x05B2
#define REG_MULTI_BCN_CS                             0x05B3
#define REG_FREERUN_CNT_CTRL                         0x05B4
#define REG_P2POFF_DIS_TXTIME                        0x05B7
#define REG_PTA_TRXBCN_CTRL                          0x05B8
#define REG_P2P_NOA1_CTRL                            0x05BC
#define REG_P2P_NOA1_SPEC_STATE                      0x05BE
#define REG_ACMHWCTRL                                0x05C0
#define REG_ACMRSTCTRL                               0x05C1
#define REG_ACMAVG                                   0x05C2
#define REG_VO_ADMTIME                               0x05C4
#define REG_VI_ADMTIME                               0x05C6
#define REG_BE_ADMTIME                               0x05C8
#define REG_EDCA_RANDOM_GEN                          0x05CC
#define REG_TXCMD_NOA_SEL                            0x05CF
#define REG_TXPAUSE_CFG                              0x05D0
#define REG_NAN_SETTING                              0x05D4
#define REG_BCN_SPACE_PORT1                          0x05D8
#define REG_BCN_SPACE_PORT2                          0x05DA
#define REG_NAN_SETTING_1                            0x05DC
#define REG_NOA_PARAM_V1                             0x05E0
#define REG_NOA_PARAM_V2                             0x05E4
#define REG_NOA_PARAM_V3                             0x05E8
#define REG_NOA_PARAM_4                              0x05EC
#define REG_SCHEDULER_DBG                            0x05F4
#define REG_SCH_TXCMD                                0x05F8
#define REG_PAGE5_DUMMY                              0x05FC
#define REG_PS_TIMER_A_L                             0x1500
#define REG_PS_TIMER_A_H                             0x1504
#define REG_PS_TIMER_B_L                             0x1508
#define REG_PS_TIMER_B_H                             0x150C
#define REG_PS_TIMER_C_L                             0x1510
#define REG_PS_TIMER_C_H                             0x1514
#define REG_CPUMGQ_PARAMETER                         0x1518
#define REG_PS_TIMER_EARLY                           0x151C
#define REG_PS_TIMER_TWT_CRTL                        0x1520
#define REG_RX_TSFT_DIFF                             0x1524
#define REG_SCHEDULER_COUNTER                        0x1528
#define REG_P2P_NOA2_CTRL                            0x152C
#define REG_P2P_NOA2_SPEC_STATE                      0x152E
#define REG_TM_CFG                                   0x1530
#define REG_TM_TSFT_T1                               0x1534
#define REG_TM_TSFT_T2                               0x1538
#define REG_TM_TSFT_T3                               0x153C
#define REG_TM_TSFT_T4                               0x1540
#define REG_TM_TIMER_OFFSET                          0x1544
#define REG_BCN_ELY_ADJ                              0x1548

/*========== Register Address Definition==========*/
#define REG_WMAC_CR                                  0x0600
#define REG_WMAC_BWOPMODE                            0x0603
#define REG_TCR                                      0x0604
#define REG_RCR                                      0x0608
#define REG_RXPKT_LIMIT                              0x060C
#define REG_RX_DLK                                   0x060D
#define REG_MBIDCTRL                                 0x060E
#define REG_RX_DRVINFO_SZ                            0x060F
#define REG_MACID                                    0x0610
#define REG_MACID_H                                  0x0614
#define REG_BSSID                                    0x0618
#define REG_BSSID_H                                  0x061C
#define REG_MAR                                      0x0620
#define REG_MAR_H                                    0x0624
#define REG_MBIDCAMCFG_1                             0x0628
#define REG_MBIDCAM_CFG                              0x062C
#define REG_WMAC_TCR_TSFT_OFS                        0x0630
#define REG_UDF_THSD                                 0x0632
#define REG_ZLD_NUM                                  0x0633
#define REG_STMP_THSD                                0x0634
#define REG_WMAC_TXTIMEOUT                           0x0635
#define REG_USTIME_EDCA                              0x0638
#define REG_ACKTO_CCK                                0x0639
#define REG_MAC_SPEC_SIFS                            0x063A
#define REG_RESP_SIFS_CCK                            0x063C
#define REG_RESP_SIFS_OFDM                           0x063E
#define REG_ACKTO                                    0x0640
#define REG_CTS2TO                                   0x0641
#define REG_EIFS                                     0x0642
#define REG_NAV_THRSHOLD                             0x0650
#define REG_BACAMCMD                                 0x0654
#define REG_BACAM_WD                                 0x0658
#define REG_BACAM_WD_H                               0x065C
#define REG_LBK_DLY                                  0x0660
#define REG_BITMAP_CMD                               0x0661
#define REG_TX_RX_STATUS                             0x0662
#define REG_WMAC_BITMAP_CTL                          0x0663
#define REG_RXERR_RPT                                0x0664
#define REG_WMAC_TRXPTCL_CTL                         0x0668
#define REG_WMAC_TRXPTCL_CTL_H                       0x066C
#define REG_KEYCAMCMD                                0x0670
#define REG_KEYCAM_WD                                0x0674
#define REG_CAMREAD                                  0x0678
#define REG_CAMDBG                                   0x067C
#define REG_SECCFG                                   0x0680
#define REG_RXFILTER_CATEGORY                        0x0682
#define REG_RXFILTER_ACTION                          0x0683
#define REG_RXFILTER_CATEGORY_ACTION                 0x0684
#define REG_RXFLTMAP3                                0x0688
#define REG_RXFLTMAP4                                0x068A
#define REG_RXFLTMAP5                                0x068C
#define REG_RXFLTMAP6                                0x068E
#define REG_WOW_CTRL                                 0x0690
#define REG_NAN_RX_FILTER                            0x0691
#define REG_PS_RX_INFO                               0x0692
#define REG_WMMPS_UAPSD_TID                          0x0693
#define REG_LPNAV_CTRL                               0x0694
#define REG_WKFMCAM_CMD                              0x0698
#define REG_WKFMCAM_WD                               0x069C
#define REG_RXFLTMAP0                                0x06A0
#define REG_RXFLTMAP1                                0x06A2
#define REG_RXFLTMAP                                 0x06A4
#define REG_BCN_PSR_RPT                              0x06A8
#define REG_FLC_CTRL                                 0x06AC
#define REG_FLC_RPCT                                 0x06AD
#define REG_FLC_PTS                                  0x06AE
#define REG_FLC_TRPC                                 0x06AF
#define REG_RXPKTMON_CTRL                            0x06B0
#define REG_STATE_MON                                0x06B4
#define REG_ERROR_EVT_CTL                            0x06B8
#define REG_SEARCH_MACID                             0x06BC
#define REG_BT_COEX_TABLE_V1                         0x06C0
#define REG_BT_COEX_TABLE2_V1                        0x06C4
#define REG_BT_COEX_BREAK_TABLE                      0x06C8
#define REG_BT_COEX_TABLE_H_V1                       0x06CC
#define REG_RXCMD_0                                  0x06D0
#define REG_RXCMD_1                                  0x06D4
#define REG_RESP_TXINFO_CFG                          0x06D8
#define REG_BBPSF_CTRL                               0x06DC
#define REG_RESP_TXINFO_RATE                         0x06DE
#define REG_P2P_RX_BCN_NOA                           0x06E0
#define REG_ASSOCIATED_BFMER0_INFO                   0x06E4
#define REG_SOUNDING_CFG1                            0x06E8
#define REG_SOUNDING_CFG2                            0x06EC
#define REG_SOUNDING_CFG3                            0x06F0
#define REG_SOUNDING_CFG0                            0x06F4
#define REG_ANTCD_INFO                               0x06F8
#define REG_CSI_PTR                                  0x06FC
#define REG_BCN_PSR_RPT2                             0x1600
#define REG_BCN_PSR_RPT3                             0x1604
#define REG_BCN_PSR_RPT4                             0x1608
#define REG_A1_ADDR_MASK                             0x160C
#define REG_RXPSF_CTRL                               0x1610
#define REG_RXPSF_TYPE_CTRL                          0x1614
#define REG_WAIT_PHYSTS_CTL                          0x1618
#define REG_MACID2                                   0x1620
#define REG_MACID2_H                                 0x1624
#define REG_BSSID2                                   0x1628
#define REG_BSSID2_H                                 0x162C
#define REG_MACID3                                   0x1630
#define REG_MACID3_H                                 0x1634
#define REG_BSSID3                                   0x1638
#define REG_BSSID3_H                                 0x163C
#define REG_MACID4                                   0x1640
#define REG_MACID4_H                                 0x1644
#define REG_BSSID4                                   0x1648
#define REG_BSSID4_H                                 0x164C
#define REG_NOA_REPORT                               0x1650
#define REG_NOA_REPORT_1                             0x1654
#define REG_NOA_REPORT_2                             0x1658
#define REG_NOA_REPORT_3                             0x165C
#define REG_PWRBIT_SETTING                           0x1660
#define REG_GENERAL_OPTION                           0x1664
#define REG_RXAI_CTRL                                0x1668
#define REG_RX_BCN_TM                                0x166C
#define REG_CSI_RRSR                                 0x1678
#define REG_MU_BF_OPTION                             0x167C
#define REG_WMAC_PAUSE_BB_CLR_TH                     0x167D
#define REG_WMAC_ARB_CLR                             0x167E
#define REG_WMAC_MU_OPTION                           0x167F
#define REG_WMAC_MU_BF_CTL                           0x1680
#define REG_WMAC_MU_BFRPT_PARA                       0x1682
#define REG_WMAC_ASSOCIATED_MU_BFMEE2                0x1684
#define REG_WMAC_ASSOCIATED_MU_BFMEE3                0x1686
#define REG_WMAC_ASSOCIATED_MU_BFMEE4                0x1688
#define REG_WMAC_ASSOCIATED_MU_BFMEE5                0x168A
#define REG_WMAC_ASSOCIATED_MU_BFMEE6                0x168C
#define REG_WMAC_ASSOCIATED_MU_BFMEE7                0x168E
#define REG_WMAC_BB_STOP_RX_COUNTER                  0x1690
#define REG_WMAC_PLCP_MONITOR                        0x1694
#define REG_WMAC_CSIDMA_CFG                          0x169C
#define REG_TRANSMIT_ADDRSS_0                        0x16A0
#define REG_TRANSMIT_ADDRSS_0_H                      0x16A4
#define REG_TRANSMIT_ADDRSS_1                        0x16A8
#define REG_TRANSMIT_ADDRSS_1_H                      0x16AC
#define REG_TRANSMIT_ADDRSS_2                        0x16B0
#define REG_TRANSMIT_ADDRSS_2_H                      0x16B4
#define REG_TRANSMIT_ADDRSS_3                        0x16B8
#define REG_TRANSMIT_ADDRSS_3_H                      0x16BC
#define REG_TRANSMIT_ADDRSS_4                        0x16C0
#define REG_TRANSMIT_ADDRSS_4_H                      0x16C4
#define REG_NAN_FUN                                  0x16C8
#define REG_NAN_CTL                                  0x16CC
#define REG_NAN_ADDR_FILTER                          0x16D0
#define REG_NAN_ADDR                                 0x16D4
#define REG_BCN_IEPSR0                               0x16D8
#define REG_BCN_IEPSR1                               0x16DC
#define REG_CHINFO_ADDR                              0x16E0
#define REG_CHINFO_CFG                               0x16E4
#define REG_RXCSIBUF_CFG                             0x16E8
#define REG_BT_ZB_COEX_TB                            0x16EC

/*========== Register Address Definition==========*/
#define REG_MACID1                                   0x0700
#define REG_MACID1_1                                 0x0704
#define REG_BSSID1                                   0x0708
#define REG_BSSID1_1                                 0x070C
#define REG_BCN_PSR_RPT1                             0x0710
#define REG_ASSOCIATED_BFMEE_SEL                     0x0714
#define REG_SND_PTCL_CTRL                            0x0718
#define REG_BEAMFORM_STATUS                          0x071C
#define REG_NSARP_CFG                                0x0720
#define REG_ZB_STATISTIC_1                           0x0724
#define REG_ZB_STATISTIC_2                           0x0728
#define REG_BEAMFORMING_INFO_NSARP                   0x072C
#define REG_IPV6_0                                   0x0730
#define REG_IPV6_1                                   0x0734
#define REG_IPV6_2                                   0x0738
#define REG_IPV6_3                                   0x073C
#define REG_IPV6_3                                   0x073C
#define REG_ZB_COEX_TABLE_1                          0x0740
#define REG_ZB_COEX_TABLE_2                          0x0744
#define REG_ZB_BREAK_TABLE                           0x0748
#define REG_EXT_ZB_DETEC_CTRL                        0x074C
#define REG_WMAC_RTX_CTX_SUBTYPE                     0x0750
#define REG_WMAC_RTX_SWAES_RD_1                      0x0754
#define REG_WMAC_RTX_SWAES_RD_2                      0x0758
#define REG_WMAC_RTX_SWAES_RD_3                      0x075C
#define REG_WMAC_SWAES_CFG                           0x0760
#define REG_BT_PRI                                   0x0762
#define REG_BT_COEX_ENH                              0x0764
#define REG_WLAN_ACT_MASK_CTRL                       0x0768
#define REG_WLAN_ACT_MASK_CTRL_1                     0x076C
#define REG_BT_COEX_ENHANCED_INTR_CTRL               0x076E
#define REG_BT_ENHANCED_CTRL0                        0x0770
#define REG_BT_ENHANCED_CTRL1                        0x0774
#define REG_BT_PROPRI                                0x0778
#define REG_BT_STATUS_REPORT_REGISTER                0x077C
#define REG_BT_INTERRUPT_CONTROL_REGISTER            0x0780
#define REG_WLAN_REPORT_TIME_OUT_CONTROL_REGISTER    0x0784
#define REG_CH_COEXIST                               0x0785
#define REG_BT_ISOLATION_TABLE_REGISTER_REGISTER_1   0x0788
#define REG_BT_ISOLATION_TABLE_REGISTER_REGISTER_2   0x078C
#define REG_BT_INTERRUPT_STATUS_REGISTER             0x078F
#define REG_BT_TDMA_TIME_REGISTER                    0x0790
#define REG_BT_ACT_REGISTER                          0x0794
#define REG_LTR_IDLE_LATENCY_V2                      0x0798
#define REG_LTR_ACTIVE_LATENCY_V2                    0x079C
#define REG_OBFF_CTRL                                0x07A0
#define REG_LTR_CTRL                                 0x07A4
#define REG_LTR_CTRL2                                0x07A8
#define REG_ANTTRN_CTR_V1                            0x07B0
#define REG_ANTTRN_CTR_1_V1                          0x07B4
#define REG_WMAC_PKTCNT_RWD                          0x07B8
#define REG_WMAC_PKTCNT_CTRL                         0x07BC
#define REG_IQ_DUMP                                  0x07C0
#define REG_MASK_LA_MAC                              0x07C4
#define REG_MATCH_REF_MAC                            0x07C8
#define REG_WMAC_FTM_CTL                             0x07CC
#define REG_WMAC_LA_DUMP_FUNC_EXT                    0x07CE
#define REG_OFDM_CCK_LEN_MASK                        0x07D0
#define REG_WMAC_OPTION_FUNCTION_1                   0x07D4
#define REG_WMAC_OPTION_FUNCTION_2                   0x07D8
#define REG_RX_FILTER_FUNCTION                       0x07DA
#define REG_WMAC_OPTION_FUNCTION_3                   0x07E0
#define REG_WMAC_DBG_SEL                             0x07E4
#define REG_WMAC_DBG_SHIFT                           0x07E8
#define REG_WSEC_OPTION                              0x07EC
#define REG_RTS_ADDRESS_0                            0x07F0
#define REG_RTS_ADDRESS_0_1                          0x07F4
#define REG_RTS_ADDRESS_1                            0x07F8
#define REG_RTS_ADDRESS_1_1                          0x07FC

//-----------------------------------------------------
//
//  0x0800h ~ 0x0FFFh   BB Control Register setting
//
//-----------------------------------------------------
#define REG_RFE_INV                 0x092C
#define REG_RFE_CTRL89              0x0930
#define REG_RFE_SWCTRL              0x0948
#define REG_R_RFE_SEL01             0x0CB0
#define REG_R_RFE_SEL89             0x0CB4

//for MAILBOX 0x11A4~0x11B7
#define REG_OUTDATA0            0x0
#define REG_OUTDATA1            0x4
#define REG_OUTRDY              0x8  //bit[0] : OutReady, bit[1] : OutEmptyIntEn 

#define REG_INDATA0             0xC
#define REG_INDATA1             0x10
#define REG_INRDY               0xA  //bit[0] : InReady, bit[1] : InRdyIntEn

//============================================================================
//       8721D Regsiter Bit and Content definition
//============================================================================
//-----------------------------------------------------
//
//  0x0000h ~ 0x00FFh   System Configuration
//
//-----------------------------------------------------
//2 SPS0_CTRL
#define SW18_FPWM                   BIT3

//2 SYS_ISO_CTRL
#define ISO_MD2PP                   BIT0
#define ISO_UA2USB                  BIT1
#define ISO_UD2CORE                 BIT2
#define ISO_PA2PCIE                 BIT3
#define ISO_PD2CORE                 BIT4
#define ISO_IP2MAC                  BIT5
#define ISO_DIOP                    BIT6
#define ISO_DIOE                    BIT7
#define ISO_EB2CORE                 BIT8
#define ISO_DIOR                    BIT9
#define UA12PC_EN                   BIT10   // For RTL8723 only.
#define UA33PC_EN                   BIT11   // For RTL8723 only.
#define PA12PC_EN                   BIT12   // For RTL8723 only.
#define PA33PC_EN                   BIT13   // For RTL8723 only.
#define PWC_EV25V                   BIT14
#define PWC_EV12V                   BIT15


//2 SYS_FUNC_EN
#define FEN_BBRSTB                  BIT0
#define FEN_BB_GLB_RSTn             BIT1
#define FEN_USBA                    BIT2
#define FEN_UPLL                    BIT3
#define FEN_USBD                    BIT4
#define FEN_DIO_PCIE                BIT5
#define FEN_PCIEA                   BIT6
#define FEN_PPLL                    BIT7
#define FEN_PCIED                   BIT8
#define FEN_DIOE                    BIT9
#define FEN_CPUEN                   BIT10
#define FEN_DCORE                   BIT11
#define FEN_ELDR                    BIT12
#define FEN_DIO_RF                  BIT13
#define FEN_HWPDN                   BIT14
#define FEN_MREGEN                  BIT15

//2 APS_FSMCO
#define PFM_LDALL                   BIT0
#define PFM_ALDN                    BIT1
#define PFM_LDKP                    BIT2
#define PFM_WOWL                    BIT3
#define EnPDN                       BIT4
#define PDN_PL                      BIT5
#define APFM_ONMAC                  BIT8
#define APFM_OFF                    BIT9
#define APFM_RSM                    BIT10
#define AFSM_HSUS                   BIT11
#define AFSM_PCIE                   BIT12
#define APDM_MAC                    BIT13
#define APDM_HOST                   BIT14
#define APDM_HPDN                   BIT15
#define RDY_MACON                   BIT16
#define SUS_HOST                    BIT17
#define ROP_ALD                     BIT20
#define ROP_PWR                     BIT21
#define ROP_SPS                     BIT22
#define SOP_MRST                    BIT25
#define SOP_FUSE                    BIT26
#define SOP_ABG                     BIT27
#define SOP_AMB                     BIT28
#define SOP_RCK                     BIT29
#define SOP_A8M                     BIT30
#define XOP_BTCK                    BIT31

//2 SYS_CLKR
#define ANAD16V_EN                  BIT0
#define ANA8M                       BIT1
#define MACSLP                      BIT4
#define LOADER_CLK_EN               BIT5
#define _80M_SSC_DIS                BIT7
#define _80M_SSC_EN_HO              BIT8
#define PHY_SSC_RSTB                BIT9
#define SEC_CLK_EN                  BIT10
#define MAC_CLK_EN                  BIT11
#define SYS_CLK_EN                  BIT12
#define RING_CLK_EN                 BIT13
#define CPU_CLK_EN                  BIT14

//2 9346CR

#define     BOOT_FROM_EEPROM        BIT4
#define     EEPROM_EN               BIT5

//2 AFE_MISC
#define AFE_BGEN                    BIT0
#define AFE_MBEN                    BIT1
#define MAC_ID_EN                   BIT7

//2 RSV_CTRL
#define WLOCK_ALL                   BIT0
#define WLOCK_00                    BIT1
#define WLOCK_04                    BIT2
#define WLOCK_08                    BIT3
#define WLOCK_40                    BIT4
#define R_DIS_PRST_0                BIT5
#define R_DIS_PRST_1                BIT6
#define LOCK_ALL_EN                 BIT7

//2 RF_CTRL
#define RF_EN                       BIT0
#define RF_RSTB                     BIT1
#define RF_SDMRSTB                  BIT2

//2 LDOA15_CTRL
#define LDA15_EN                    BIT0
#define LDA15_STBY                  BIT1
#define LDA15_OBUF                  BIT2
#define LDA15_REG_VOS               BIT3
#define _LDA15_VOADJ(x)             (((x) & 0x7) << 4)

//2 LDOV12D_CTRL
#define LDV12_EN                    BIT0
#define LDV12_SDBY                  BIT1
#define LPLDO_HSM                   BIT2
#define LPLDO_LSM_DIS               BIT3
#define _LDV12_VADJ(x)              (((x) & 0xF) << 4)


//2 AFE_XTAL_CTRL
#define XTAL_EN                     BIT0
#define XTAL_BSEL                   BIT1
#define _XTAL_BOSC(x)               (((x) & 0x3) << 2)
#define _XTAL_CADJ(x)               (((x) & 0xF) << 4)
#define XTAL_GATE_USB               BIT8
#define _XTAL_USB_DRV(x)            (((x) & 0x3) << 9)
#define XTAL_GATE_AFE               BIT11
#define _XTAL_AFE_DRV(x)            (((x) & 0x3) << 12)
#define XTAL_RF_GATE                BIT14
#define _XTAL_RF_DRV(x)             (((x) & 0x3) << 15)
#define XTAL_GATE_DIG               BIT17
#define _XTAL_DIG_DRV(x)            (((x) & 0x3) << 18)
#define XTAL_BT_GATE                BIT20
#define _XTAL_BT_DRV(x)             (((x) & 0x3) << 21)
#define _XTAL_GPIO(x)               (((x) & 0x7) << 23)


#define CKDLY_AFE                   BIT26
#define CKDLY_USB                   BIT27
#define CKDLY_DIG                   BIT28
#define CKDLY_BT                    BIT29


//2 AFE_PLL_CTRL
#define APLL_EN                     BIT0
#define APLL_320_EN                 BIT1
#define APLL_FREF_SEL               BIT2
#define APLL_EDGE_SEL               BIT3
#define APLL_WDOGB                  BIT4
#define APLL_LPFEN                  BIT5

#define APLL_REF_CLK_13MHZ          0x1
#define APLL_REF_CLK_19_2MHZ        0x2
#define APLL_REF_CLK_20MHZ          0x3
#define APLL_REF_CLK_25MHZ          0x4
#define APLL_REF_CLK_26MHZ          0x5
#define APLL_REF_CLK_38_4MHZ        0x6
#define APLL_REF_CLK_40MHZ          0x7

#define APLL_320EN                  BIT14
#define APLL_80EN                   BIT15
#define APLL_1MEN                   BIT24


//2 EFUSE_CTRL
#define ALD_EN                      BIT18
#define EF_PD                       BIT19
#define EF_FLAG                     BIT31

//2 EFUSE_TEST (For RTL8723 partially)
#define EF_TRPT                     BIT7
#define EF_CELL_SEL                 (BIT8|BIT9) // 00: Wifi Efuse, 01: BT Efuse0, 10: BT Efuse1, 11: BT Efuse2
#define LDOE25_EN                   BIT31
#define EFUSE_SEL(x)                (((x) & 0x3) << 8)
#define EFUSE_SEL_MASK              0x300
#define EFUSE_WIFI_SEL_0            0x0
#define EFUSE_BT_SEL_0              0x1
#define EFUSE_BT_SEL_1              0x2
#define EFUSE_BT_SEL_2              0x3

#define EFUSE_ACCESS_ON             0x69    // For RTL8723 only.
#define EFUSE_ACCESS_OFF            0x00    // For RTL8723 only.

//2 ACLK_MON
#define RSM_EN                      BIT0
#define Timer_EN                    BIT4


//2 GPIO_MUXCFG
#define TRSW0EN                     BIT2
#define TRSW1EN                     BIT3
#define EROM_EN                     BIT4
#define EnBT                        BIT5
#define EnUart                      BIT8
#define Uart_910                    BIT9
#define EnPMAC                      BIT10
#define SIC_SWRST                   BIT11
#define EnSIC                       BIT12
#define SIC_23                      BIT13
#define EnHDP                       BIT14
#define SIC_LBK                     BIT15

//2 LEDCFG
#define LED0PL                      BIT4
#define LED1PL                      BIT12
#define LED0DIS                     BIT7


//2 FSIMR
//2 FSISR
#define SYSINT_GPIO0_SHT            4//12
#define SYSINT_GPIO1_SHT            5//13
#define SYSINT_GPIO2_SHT            6//14
#define SYSINT_GPIO3_SHT            7//15

#define SYSINT_GPIO4_SHT            0//16
#define SYSINT_GPIO5_SHT            1//17
#define SYSINT_GPIO6_SHT            2//18
#define SYSINT_GPIO7_SHT            3//19
#define SYSINT_GPIO8_SHT            4//20
#define SYSINT_GPIO9_SHT            5//21
#define SYSINT_GPIOA_SHT            6//22
#define SYSINT_GPIOB_SHT            7//23

#define SYSINT_HPON_WRE_SHT         4//28   
#define SYSINT_SPS_OCP_SHT          5//29
#define SYSINT_HWSYS_TIMER_SHT      6//30
#define SYSINT_PDNINT_SHT           7//31


#define SYSINT_GPIO0INT             BIT(SYSINT_GPIO0_SHT)
#define SYSINT_GPIO1INT             BIT(SYSINT_GPIO1_SHT)
#define SYSINT_GPIO2INT             BIT(SYSINT_GPIO2_SHT)
#define SYSINT_GPIO3INT             BIT(SYSINT_GPIO3_SHT)

#define SYSINT_GPIO4INT             BIT(SYSINT_GPIO4_SHT)
#define SYSINT_GPIO5INT             BIT(SYSINT_GPIO5_SHT)
#define SYSINT_GPIO6INT             BIT(SYSINT_GPIO6_SHT)
#define SYSINT_GPIO7INT             BIT(SYSINT_GPIO7_SHT)
#define SYSINT_GPIO8INT             BIT(SYSINT_GPIO8_SHT)
#define SYSINT_GPIO9INT             BIT(SYSINT_GPIO9_SHT)
#define SYSINT_GPIOAINT             BIT(SYSINT_GPIOA_SHT)

#define SYSINT_HPON_WRE             BIT(SYSINT_HPON_WRE_SHT)
#define SYSINT_SPS_OCP              BIT(SYSINT_SPS_OCP_SHT)
#define SYSINT_HWSYS_TIMER          BIT(SYSINT_HWSYS_TIMER_SHT)
#define SYSINT_PDNINT               BIT(SYSINT_PDNINT_SHT)

//2 WLAN PHY EN        0x0006
#define BIT_FEN_BB_GLB_RST     BIT0
#define BIT_FEN_BB_RSTB              BIT1

//2WLAN RF EN       0x0007
#define BIT_RF_EN           BIT0
#define BIT_RF_RSTB         BIT1
#define BIT_RF_SDMRSTB      BIT2

//2 MCUFWDL     0x0080
#define MCUFWDL_EN                  BIT0
#define MCUFWDL_RDY                 BIT1
#define MCUFWDL_CHK_RPT             BIT2

#define WINTINI_RDY                 BIT6
#define RAM_DL_SEL                  BIT7


#define MCU_ROM_INITIAL_READY       BIT2    //10

#define ROMDLFW_EN                  BIT3    //11    
#define FWDL2TXBUF_RDY              BIT4    //12
#define MCUFWDL_DMA_EN      BIT5    //13

#define ROM_DLEN                    BIT3    //19
#define CPRST                       BIT7    //23

//2 REG_USB_SIE_INTF        0x00E0
#define USB2_SIE_READ               0x01
#define USB2_SIE_WRITE              0x03
#define USB3_SIE_READ               0x40
#define USB3_SIE_WRITE              0x42
#define USB_WRITE_END               BIT0
#define USB_SIE_INTF_WE             BIT1


//2 REG_PCIE_MIO_INTF       0x00E4
#define PCIE_MIO_WRITE              0x20
#define PCIE_MIO_READ               0x30


//2 REG_PCIE_MIO_INTD       0x00E8


//2 REG_HPON_FSM
#define BOND92CE_1T2R_CFG           BIT22


//2 REG_SYS_CFG
#define XCLK_VLD                    BIT0
#define ACLK_VLD                    BIT1
#define UCLK_VLD                    BIT2
#define PCLK_VLD                    BIT3
#define PCIRSTB                     BIT4
#define V15_VLD                     BIT5

#define INIT_OFFLOAD_ROM_EN         BIT7
#define SIC_IDLE                    BIT8
#define BD_MAC2                     BIT9
#define BD_MAC1                     BIT10
#define IC_MACPHY_MODE              BIT11
#define CHIP_VER                    (BIT12|BIT13|BIT14|BIT15)
#define BT_FUNC                     BIT16
#define VENDOR_ID                   BIT19
#define PAD_HWPD_IDN                BIT22
#define TRP_VAUX_EN                 BIT23   // RTL ID
#define TRP_BT_EN                   BIT24
#define BD_PKG_SEL                  BIT25
#define BD_HCI_SEL                  BIT26
#define TYPE_ID                     BIT27

#define CHIP_VER_RTL_MASK           0xF000  //Bit 12 ~ 15
#define CHIP_VER_RTL_SHIFT          12

//2REG_GPIO_OUTSTS (For RTL8723 only)
//2 REG_SYS_STATUS_RPT
#define EFS_HCI_SEL                 (BIT0|BIT1)
#define PAD_HCI_SEL                 (BIT2|BIT3)
#define HCI_SEL                     (BIT4|BIT5) //8723BA
#define PKG_SEL_HCI                 BIT6
#define FEN_GPS                     BIT7
#define FEN_BT                      BIT8
#define FEN_WL                      BIT9
#define FEN_PCI                     BIT10
#define FEN_USB                     BIT11
#define BTRF_HWPDN_N                BIT12
#define WLRF_HWPDN_N                BIT13
#define PDN_BT_N                    BIT14
#define PDN_GPS_N                   BIT15
#define BT_CTL_HWPDN                BIT16
#define GPS_CTL_HWPDN               BIT17
#define PPHY_SUSB                   BIT20
#define UPHY_SUSB                   BIT21
#define PCI_SUSEN                   BIT22
#define USB_SUSEN                   BIT23

#define RF_RL_ID                    (BIT31|BIT30|BIT29|BIT28)
#define TRAP_PKG_SEL                BIT5

//2 REG_USB_CFG
#define USB2_SEL                    BIT7
//-----------------------------------------------------
//
//  0x0100h ~ 0x01FFh   MACTOP General Configuration
//
//-----------------------------------------------------

//2 Function Enable Registers

#define REG_LBMODE                  (REG_CR + 3)

#define HCI_TXDMA_EN                BIT0
#define HCI_RXDMA_EN                BIT1
#define TXDMA_EN                    BIT2
#define RXDMA_EN                    BIT3
#define PROTOCOL_EN                 BIT4
#define SCHEDULE_EN                 BIT5
#define MACTXEN                     BIT6
#define MACRXEN                     BIT7

#define ENSWBCN                     BIT0
#define ENSEC                       BIT1

// Network type
#define _NETTYPE(x)                 (((x) & 0x3) << 16)
#define MASK_NETTYPE                0x30000
#define NT_NO_LINK                  0x0
#define NT_LINK_AD_HOC              0x1
#define NT_LINK_AP                  0x2
#define NT_AS_AP                    0x3

#define _LBMODE(x)                  (((x) & 0xF) << 24)
#define MASK_LBMODE                 0xF000000
#define LOOPBACK_NORMAL             0x0
#define LOOPBACK_IMMEDIATELY        0xB
#define LOOPBACK_MAC_DELAY          0x3
#define LOOPBACK_PHY                0x1
#define LOOPBACK_DMA                0x7


//2 PLAYFORM_CLOCK Register 0x0109
#define CLK_STABLE_32K              BIT7        // 1: 32K Stable, 0: 40M Stable

//2 PBP - Page Size Register
#define GET_RX_PAGE_SIZE(value)     ((value) & 0xF)
#define GET_TX_PAGE_SIZE(value)     (((value) & 0xF0) >> 4)
#define _PSRX_MASK                  0xF
#define _PSTX_MASK                  0xF0
#define _PSRX(x)                    (x)
#define _PSTX(x)                    ((x) << 4)

#define PBP_64                      0x0
#define PBP_128                     0x1
#define PBP_256                     0x2
#define PBP_512                     0x3
#define PBP_1024                    0x4


//2 TX/RXDMA
#define RXDMA_ARBBW_EN              BIT0
#define RXSHFT_EN                   BIT1
#define RXDMA_AGG_EN                BIT2
#define QS_VO_QUEUE                 BIT8
#define QS_VI_QUEUE                 BIT9
#define QS_BE_QUEUE                 BIT10
#define QS_BK_QUEUE                 BIT11
#define QS_MANAGER_QUEUE            BIT12
#define QS_HIGH_QUEUE               BIT13

#define HQSEL_VOQ                   BIT0
#define HQSEL_VIQ                   BIT1
#define HQSEL_BEQ                   BIT2
#define HQSEL_BKQ                   BIT3
#define HQSEL_MGTQ                  BIT4
#define HQSEL_HIQ                   BIT5

// For normal driver, 0x10C
#define _TXDMA_HIQ_MAP(x)           (((x)&0x3) << 14)
#define _TXDMA_MGQ_MAP(x)           (((x)&0x3) << 12)
#define _TXDMA_BKQ_MAP(x)           (((x)&0x3) << 10)
#define _TXDMA_BEQ_MAP(x)           (((x)&0x3) << 8 )
#define _TXDMA_VIQ_MAP(x)           (((x)&0x3) << 6 )
#define _TXDMA_VOQ_MAP(x)           (((x)&0x3) << 4 )

#define QUEUE_LOW                   1
#define QUEUE_NORMAL                2
#define QUEUE_HIGH                  3


//2 LLT_INIT
#define _LLT_NO_ACTIVE              0x00
#define _LLT_WRITE_ACCESS           0x40
#define _LLT_READ_ACCESS            0x80

#define _LLT_INIT_DATA(x)           ((x) & 0xFF)
#define _LLT_INIT_ADDR(x)           (((x) & 0xFF) << 8)
#define _LLT_OP(x)                  (((x) & 0x3) << 30)
#define _LLT_OP_VALUE(x)            (((x) >> 30) & 0x3)


//2 BB_ACCESS_CTRL
#define BB_WRITE_READ_MASK          (BIT31 | BIT30)
#define BB_WRITE_EN                 BIT30
#define BB_READ_EN                  BIT31

//-----------------------------------------------------
//
//  0x0200h ~ 0x027Fh   TXDMA Configuration
//
//-----------------------------------------------------
//2 RQPN
#define _HPQ(x)                     ((x) & 0xFF)
#define _LPQ(x)                     (((x) & 0xFF) << 8)
#define _PUBQ(x)                    (((x) & 0xFF) << 16)
#define _NPQ(x)                     ((x) & 0xFF)            // NOTE: in RQPN_NPQ register


#define HPQ_PUBLIC_DIS              BIT24
#define LPQ_PUBLIC_DIS              BIT25
#define LD_RQPN                     BIT31


//2 TDECTRL
#define BCN_VALID                   BIT16
#define BCN_HEAD(x)                 (((x) & 0xFF) << 8)
#define BCN_HEAD_MASK               0xFF00

//2 TDECTL
#define BLK_DESC_NUM_SHIFT          4
#define BLK_DESC_NUM_MASK           0xF


//2 TXDMA_OFFSET_CHK
#define DROP_DATA_EN                BIT9


//2 RX pkt unm  0x286
#define RXDMA_IDLE                  BIT1
#define STOP_RXDMA                  BIT2

//-----------------------------------------------------
//
//  0x0300h ~ 0x03FFh   PCIE
//
//-----------------------------------------------------
//2  REG_DBI_CTRL                   0x0350

//2 REG_DBI_RWCMD               0x0352
#define DBI_WRITE                   BIT0
#define DBI_READ                    BIT1


//2 REG_MDIO_CTRL               0x0358
#define MDIO_PCIE_READ              BIT6
#define MDIO_PCIE_WRITE             BIT5

//-----------------------------------------------------
//
//  0x0400h ~ 0x047Fh   Protocol Configuration
//
//-----------------------------------------------------

//2 CPU_MGT_INFORMATION
#define CPUMGT_POLL                 BIT5
#define P0BCN_POLL                  BIT4
#define P1BCN_POLL                  BIT6
#define NANBCN_POLL                 BIT7


//2 FWHW_TXQ_CTRL
#define EN_AMPDU_RTY_NEW            BIT7

//2 INIRTSMCS_SEL
#define _INIRTSMCS_SEL(x)           ((x) & 0x3F)

//2 SPEC SIFS
#define _SPEC_SIFS_CCK(x)           ((x) & 0xFF)
#define _SPEC_SIFS_OFDM(x)          (((x) & 0xFF) << 8)


//2 RRSR

#define RATE_REG_BITMAP_ALL         0xFFFFF

#define _RRSC_BITMAP(x)             ((x) & 0xFFFFF)

#define _RRSR_RSC(x)                (((x) & 0x3) << 21)
#define RRSR_RSC_RESERVED           0x0
#define RRSR_RSC_UPPER_SUBCHANNEL   0x1
#define RRSR_RSC_LOWER_SUBCHANNEL   0x2
#define RRSR_RSC_DUPLICATE_MODE     0x3


//2 ARFR
#define USE_SHORT_G1                BIT20

//2 AGGLEN_LMT_L
#define _AGGLMT_MCS0(x)             ((x) & 0xF)
#define _AGGLMT_MCS1(x)             (((x) & 0xF) << 4)
#define _AGGLMT_MCS2(x)             (((x) & 0xF) << 8)
#define _AGGLMT_MCS3(x)             (((x) & 0xF) << 12)
#define _AGGLMT_MCS4(x)             (((x) & 0xF) << 16)
#define _AGGLMT_MCS5(x)             (((x) & 0xF) << 20)
#define _AGGLMT_MCS6(x)             (((x) & 0xF) << 24)
#define _AGGLMT_MCS7(x)             (((x) & 0xF) << 28)

//3 LIFETIME_CTRL
#define BT_INT_MCU                  BIT7
#define BT_INT_PTA                  BIT6

//2 RL
#define RETRY_LIMIT_SHORT_SHIFT     8
#define RETRY_LIMIT_LONG_SHIFT      0


//2 DARFRC
#define _DARF_RC1(x)                ((x) & 0x1F)
#define _DARF_RC2(x)                (((x) & 0x1F) << 8)
#define _DARF_RC3(x)                (((x) & 0x1F) << 16)
#define _DARF_RC4(x)                (((x) & 0x1F) << 24)
// NOTE: shift starting from address (DARFRC + 4)
#define _DARF_RC5(x)                ((x) & 0x1F)
#define _DARF_RC6(x)                (((x) & 0x1F) << 8)
#define _DARF_RC7(x)                (((x) & 0x1F) << 16)
#define _DARF_RC8(x)                (((x) & 0x1F) << 24)


//2 RARFRC
#define _RARF_RC1(x)                ((x) & 0x1F)
#define _RARF_RC2(x)                (((x) & 0x1F) << 8)
#define _RARF_RC3(x)                (((x) & 0x1F) << 16)
#define _RARF_RC4(x)                (((x) & 0x1F) << 24)
// NOTE: shift starting from address (RARFRC + 4)
#define _RARF_RC5(x)                ((x) & 0x1F)
#define _RARF_RC6(x)                (((x) & 0x1F) << 8)
#define _RARF_RC7(x)                (((x) & 0x1F) << 16)
#define _RARF_RC8(x)                (((x) & 0x1F) << 24)

//-----------------------------------------------------
//
//  0x0500h ~ 0x05FFh   EDCA Configuration
//
//-----------------------------------------------------
//2 EDCA setting
#define AC_PARAM_TXOP_LIMIT_OFFSET  16
#define AC_PARAM_ECW_MAX_OFFSET     12
#define AC_PARAM_ECW_MIN_OFFSET     8
#define AC_PARAM_AIFS_OFFSET        0


//2 EDCA_VO_PARAM
#define _AIFS(x)                    (x)
#define _ECW_MAX_MIN(x)             ((x) << 8)
#define _TXOP_LIMIT(x)              ((x) << 16)

#define _BCNIFS(x)                  ((x) & 0xFF)
#define _BCNECW(x)                  (((x) & 0xF))<< 8)

#define _LRL(x)                     ((x) & 0x3F)
#define _SRL(x)                     (((x) & 0x3F) << 8)

//2 SIFS_CCK
#define _SIFS_CCK_CTX(x)            ((x) & 0xFF)
#define _SIFS_CCK_TRX(x)            (((x) & 0xFF) << 8);

//2 SIFS_OFDM
#define _SIFS_OFDM_CTX(x)           ((x) & 0xFF)
#define _SIFS_OFDM_TRX(x)           (((x) & 0xFF) << 8);

//2 TXPAUSE 0x522
#define MAC_STOPBK                  BIT0
#define MAC_STOPBE                  BIT1
#define MAC_STOPVI                  BIT2
#define MAC_STOPVO                  BIT3
#define MAC_STOPMGQ                 BIT4
#define MAC_STOPHIQ                 BIT5
#define MAC_STOPBCNQ                BIT6
#define MAC_STOP_BCN_HI_MGT         BIT7


//2 TBTT PROHIBIT
#define _TBTT_PROHIBIT_HOLD(x)      (((x) & 0xFF) << 8)

//2 REG_RD_CTRL 0x524
#define DIS_EDCA_CNT_DWN            BIT11

//2 MBSSID_CTRL 0x526

//2 P2PPS_CTRL 0x527
#define P2P_BCN_SEL                 BIT0
#define P2P_NOA0_EN                 BIT1
#define P2P_NOA1_EN                 BIT2
#define P2P_CTWND_EN                BIT3
#define P2P_BCN_AREA_EN             BIT4
#define P2P_PWR_MGT_EN              BIT5
#define P2P_OFF_DISTX_EN            BIT6
#define P2P_CTW_ALLSTASLEEP         BIT7


//2 P2PPS_SPEC_STATE 0x52B
#define P2P_SPEC_FORCE_DOZE0        BIT0
#define P2P_SPEC_NOA0_OFF_PERIOD    BIT1
#define P2P_SPEC_FORCE_DOZE1        BIT2
#define P2P_SPEC_NOA1_OFF_PERIOD    BIT3
#define P2P_CTWIN_EARLY_DISTX       BIT4
#define P2P_SPEC_BEACON_AREA_ON     BIT5
#define P2P_SPEC_CTW_ON             BIT6
#define P2P_SPEC_POWER_STATE        BIT7        // 1: on, 0: off


//2 P2PPS_STATE 0x543
#define P2P_FORCE_DOZE0             BIT0
#define P2P_NOA0_OFF_PERIOD         BIT1
#define P2P_FORCE_DOZE1             BIT2
#define P2P_NOA1_OFF_PERIOD         BIT3
#define P2P_NOA_POWEROFF            BIT4
#define P2P_BEACON_AREA_ON          BIT5
#define P2P_CTW_ON                  BIT6
#define P2P_POWER_STATE             BIT7        // 1: on, 0: off


//2 BCN_CTRL
#define EN_MBSSID                   BIT1
#define EN_TXBCN_RPT                BIT2
#define EN_BCN_FUNCTION             BIT3

//2 DUAL_TSF_RST
#define TSFTR_RST                   BIT0
#define TSFTR1_RST                  BIT1


#define STOP_BCNQ                   BIT6

// The same function but different bit field.
#define DIS_TSF_UDT0_NORMAL_CHIP    BIT4
#define DIS_TSF_UDT0_TEST_CHIP      BIT5

//2 ACMHWCTRL
#define AcmHw_HwEn                  BIT0
#define AcmHw_BeqEn                 BIT1
#define AcmHw_ViqEn                 BIT2
#define AcmHw_VoqEn                 BIT3
#define AcmHw_BeqStatus             BIT4
#define AcmHw_ViqStatus             BIT5
#define AcmHw_VoqStatus             BIT6

//-----------------------------------------------------
//
//  0x0600h ~ 0x07FFh   WMAC Configuration
//
//-----------------------------------------------------

//2 APSD_CTRL
#define APSDOFF                     BIT6
#define APSDOFF_STATUS              BIT7


//2 BWOPMODE
#define BW_20MHZ                    BIT2

#define RATE_BITMAP_ALL             0xFFFFF

// Only use CCK 1M rate for ACK
#define RATE_RRSR_CCK_ONLY_1M       0xFFFF1

//2 TCR
#define TSFRST                      BIT0
#define DIS_GCLK                    BIT1
#define PAD_SEL                     BIT2
#define PWR_ST                      BIT6
#define PWRBIT_OW_EN                BIT7
#define ACRC                        BIT8
#define CFENDFORM                   BIT9
#define ICV                         BIT10

//2 RCR
#define AAP                         BIT0
#define APM                         BIT1
#define AM                          BIT2
#define AB                          BIT3
#define ADD3                        BIT4
#define APWRMGT                     BIT5
#define CBSSID                      BIT6
#define CBSSID_DATA                 BIT6
#define CBSSID_BCN                  BIT7
#define ACRC32                      BIT8
#define AICV                        BIT9
#define ADF                         BIT11
#define ACF                         BIT12
#define AMF                         BIT13
#define HTC_LOC_CTRL                BIT14
#define UC_DATA_EN                  BIT16
#define BM_DATA_EN                  BIT17
#define MFBEN                       BIT22
#define LSIGEN                      BIT23
#define EnMBID                      BIT24
#define APP_BASSN                   BIT27
#define APP_PHYSTS                  BIT28
#define APP_ICV                     BIT29
#define APP_MIC                     BIT30
#define APP_FCS                     BIT31

//2 RX_PKT_LIMIT

//2 RX_DLK_TIME

//2 MBIDCAMCFG

//2 WOW_CTRL 0x690
#define FORCE_WAKE_UP               BIT0
#define PATTERN_MATCH_EN            BIT1
#define MAGIC_PKT_EN                BIT2
#define UNICAST_EN                  BIT3
#define WOWHCI_EN                   BIT5

//2 AMPDU_MIN_SPACE
#define _MIN_SPACE(x)               ((x) & 0x7)
#define _SHORT_GI_PADDING(x)        (((x) & 0x1F) << 3)

//2 RXERR_RPT
#define RXERR_TYPE_OFDM_PPDU            0
#define RXERR_TYPE_OFDM_FALSE_ALARM     1
#define RXERR_TYPE_OFDM_MPDU_OK         2
#define RXERR_TYPE_OFDM_MPDU_FAIL       3
#define RXERR_TYPE_CCK_PPDU             4
#define RXERR_TYPE_CCK_FALSE_ALARM      5
#define RXERR_TYPE_CCK_MPDU_OK          6
#define RXERR_TYPE_CCK_MPDU_FAIL        7
#define RXERR_TYPE_HT_PPDU              8
#define RXERR_TYPE_HT_FALSE_ALARM       9
#define RXERR_TYPE_HT_MPDU_TOTAL        10
#define RXERR_TYPE_HT_MPDU_OK           11
#define RXERR_TYPE_HT_MPDU_FAIL         12
#define RXERR_TYPE_RX_FULL_DROP         15

#define RXERR_COUNTER_MASK              0xFFFFF
#define RXERR_RPT_RST                   BIT27
#define _RXERR_RPT_SEL(type)            ((u32)((type) << 28))

//2 SECCFG
#define SCR_TxUseDK                     BIT0            //Force Tx Use Default Key
#define SCR_RxUseDK                     BIT1            //Force Rx Use Default Key
#define SCR_TxEncEnable                 BIT2            //Enable Tx Encryption
#define SCR_RxDecEnable                 BIT3            //Enable Rx Decryption
#define SCR_SKByA2                      BIT4            //Search kEY BY A2
#define SCR_NoSKMC                      BIT5            //No Key Search Multicast
#define SCR_TXBCUSEDK                   BIT6            // Force Tx Broadcast packets Use Default Key
#define SCR_RXBCUSEDK                   BIT7            // Force Rx Broadcast packets Use Default Key

//1 BCN_PSR_RPT [31:0]: Beacon Parser Report Register
//0~10      AID0
//11~13     RSVD
#define PS_TIM                          BIT6      //14
#define PS_DTIM                         BIT7      //15
//16~23     DTIM period
//24~31     DTIM COUNT


//1NAN CTRL
#define NAN_ENTRY_SIZE  64
#define NAN_ENTRY_NUM   1

#define NAN_PSR_EN      BIT0
#define _NAN_ENTRY_SIZE(size)   ((u8)(((((size)>>5)-2)&0x7)<<1))
#define _NAN_ENTRY_NUM(num)     ((u8)(((num)&0x7)<<4))
#define NAN_ATTRI_ID0_VLD   BIT0
#define NAN_ATTRI_ID1_VLD   BIT1
#define NAN_ATTRI_ID2_VLD   BIT2
#define NAN_ATTRI_ID3_VLD   BIT3
#define NAN_ATTRI_ID4_VLD   BIT4
#define NAN_RXA2_FILTER_EN  BIT5

//1 CPU DOMAIN
//-----------------------------------------------------
//
//  0xFD00h ~ 0xFDFFh   8051 CPU Local REG
//
//-----------------------------------------------------

//3 REG_SYS_CTRL(0xFD00)
//0xFD00[0]: 8051 sw reset for fpga use
//0xFD00[1:2] : rsvd
//0xFD00[3]: write reg 00[4] to trigger int pkt
#define WAKEUP_BUS                      BIT4    //dw8051 wakeup usb2/3
//0xFD00[5] : rsvd
#define SYS_CTRL_TXBUF_ROM_ENABLE       BIT6    //enable this bit when 8051 want to run instruntion and disable while leaving.       
//0xFD00[7]: auto clr 0xFD20 ~ 0xFD3F reg

//3 REG_PONSTS_RPT1(0xFD01)
#define PONSTS1_FW_DATA_RDY             BIT0
#define PONSTS1_HCI_SEL                 BIT1    //usb/pcie hci sel(0:pcie, 1:usb)    
#define PONSTS1_USB2_SEL                BIT2    //usb2 card emulation to usb2
#define PONSTS1_EEPROM_LOAD_OK          BIT3    //reg0x0A[5]
#define PONSTS1_MCUFWDL_RDY             BIT4    //reg0x80[1]
#define PONSTS1_MCUFWDL_EN              BIT5    //reg0x80[0]
#define PONSTS1_USB_BUS_ACTIVE          BIT6    //usb suspend
#define PONSTS1_RAM_SPACE_SEL           BIT7

/*------------------------------Define Enum-----------------------------------*/

/*--------------------------Define MACRO--------------------------------------*/

/*------------------------------Define Struct---------------------------------*/

/*------------------------Export global variable------------------------------*/

/*------------------------------Function declaration--------------------------*/


#endif  //__RTL8721D_REG_H__

