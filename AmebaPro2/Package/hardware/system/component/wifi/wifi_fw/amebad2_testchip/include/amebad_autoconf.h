#ifndef _AUTOCONF_H_
#define _AUTOCONF_H_
#define CONFIG_FPGA_TEST 1

//2 Main Config
//3 1.) Chip Select
#define CONFIG_CHIP_SEL RTL8721D_A_CUT_S


#define AUTOBUILD_END_PREFIX 1
//#define PAGE_SIZE_IA_TXPKTBUF       256   //not used
//#define PAGE_SIZE_IA_RXPKTBUF       256   //not used

//Page Size
#define PAGESIZE_TX                 128
#define PAGESIZE_RX                 8 // no page size,only for FW release RXBUF
#define TX_PAGE_NUM		    256

//TRX DESC Size
#define SIZE_RX_DESC_MAC            24
#define SIZE_TX_DESC_MAC            40

#define LENGTH_IEEE80211_HDR_3ADDR  24
#define FIX_IE_LENGTH               12

//security cam
#define SECCAM_SIZE      			640
#define SECCAM_ENTRY_NUM        		20
#define SECCAM_DIRECT_ENTRY_SIZE          	32
#define SECCAM_START_ADDR        		0x800 //not used for normal
/******************************************

    ROM Code Configuration

*******************************************/
//1 ROM Version
#if IS_CUT_TEST(CONFIG_CHIP_SEL)
#define ROM_VERSION   1
#elif IS_CUT_A(CONFIG_CHIP_SEL)
#define ROM_VERSION   2
#elif IS_CUT_B(CONFIG_CHIP_SEL)
#define ROM_VERSION   3
#else
#error "Cut Error"
#endif  //IS_CUT_TEST(CONFIG_CHIP_SEL)
#define ROM_VERSION_VERA            0xFF


//1 Functionality

//2 Common - Immobilization
#define CONFIG_FWLB                     0
#define CONFIG_RF_JAGUAR                0   //8723d no support new 3-wire
#define CONFIG_ROM_32K                  1

//2 Common
#define CONFIG_C2H_PKT                  1
#define CONFIG_PSD_OFFLOAD              0

//3 General
#define CONFIG_DISCONNECT_DECISION      1
#define CONFIG_KEEP_ALIVE               1

#define CONFIG_TXBEACON_IGNORE_EDCCA	0
#define CONFIG_TX_PAUSE_DRV_INFO		1
#define CONFIG_MACID_PAUSE_DRV_INFO		0
#define CONFIG_TX_PAUSE_WO_MASK         0
#define CONFIG_SW_QUEUE_TX			0


//3 PS Related
#define CONFIG_SAPPS                    1
#define CONFIG_INACTIVE_PS              1//must enable in formal FW //for RTD3
#define CONFIG_POWERSAVING              1   //must enable in formal FW

#define CONFIG_HW_PS_CTRL               1
#define CONFIG_PS_SUPPORT_32K           1
#define CONFIG_PARTIAL_OFF              1
#define CONFIG_LOWPWR_RXMODE            0   //It is not supported by 88E
#define CONFIG_FAST_CPWM                1
#define CONFIG_TASK_IDLE_CHK            1
#define CONFIG_BCNEARLY_FIXED		1
#define CONFIG_BCNEARLY_ADJUST          0       //must not both enable!!
#define CONFIG_BCNEARLY_ADJUST_V1       0       //must not both enable!!
#define CONFIG_BCNEARLY_ADJUST_V2       0
#define CONFIG_BEACON_MODE		0
#define CONFIG_S1_NULL1_IVL_PATCH      0

//3 BT Coex Related
#define CONFIG_BTCOEX                    1//must enable in formal FW
#define CONFIG_BTMAILBOX                 1//should enable CONFIG_BTCOEX first
#define CONFIG_BTSCOREBRD                1
#define CONFIG_ZBMAILBOX                 1

#define CONFIG_CP_AFE_LBK_TEST       0

//3 Remote WakeUp
#define CONFIG_NDP                  0
#define CODE_REDUCE                 1
#define CONFIG_DELAY_WAKEUP       1

//3 Dynamic Mechanism Offload
#define CONFIG_RATE_ADAPTIVE            1//must enable in formal FW
#if CONFIG_RATE_ADAPTIVE
#define CONFIG_MU_RA_SUPPORT                    0
#define CONFIG_POWER_TRAINING                   0
#else
#define CONFIG_MU_RA_SUPPORT                    0
#define CONFIG_POWER_TRAINING                   0
#endif
#define nonMU_MACIDNUM                          16
#if CONFIG_MU_RA_SUPPORT
#define MACID_NUM                               (nonMU_MACIDNUM)
#define RA_MACID_NUM                               (nonMU_MACIDNUM+31)
#else
#define MACID_NUM                               nonMU_MACIDNUM
#define RA_MACID_NUM                               nonMU_MACIDNUM
#endif
#define CONFIG_RA_PS_MODE           0
#define CONFIG_CCX                  0
#define CONFIG_11AC_1SS             0
#define CONFIG_11AC_2SS             0
#define CONFIG_11N_1SS				1
#define CONFIG_11N_2SS				0
#define CONFIG_RA_MULTI_TRY         1
#define CONFIG_RA_NSC_CALCULATE     1
#define CONFIG_RA_SET_RAINFO        1
#define CONFIG_1SS_SL_GI_MULTI_TRY   1

//3 //1  Patch Control
#define CONFIG_TSF_RESET_PATCH          0
#define CONFIG_H2CSWQUEUE               0

//1  Debug control
#define CONFIG_PC_DEBUG                 1
#define CONFIG_REG_DEBUG                1
#define CONFIG_PS_DEBUG                 1
#define CONFIG_WOW_DEBUG                0
#define CONFIG_RA_DEBUG                 0
#define CONFIG_RA_FPGA_DEBUG            0
#define CONFIG_DBGSTEP                  0   // 1
#define CONFIG_RA_TP_DEBUG              0   // 1   //verify with test program
#define CONFIG_MAILBOX_DEBUG            0
#define CONFIG_32K_DEBUG                1

/******************************************

    Debug Configuration

*******************************************/

//3 Debug Mode Select: Below Flags must be clear to 0 before commit.
#define CONFIG_C2H_DEBUG                0
#define CONFIG_C2H_DEBUG_COMP           0
#define CONFIG_C2H_RA_DEBUG_CODE        1
#define CONFIG_SNIFFER_DEBUG            0
#define CONFIG_BTCOEX_DEBUG             0

#define CONFIG_C2HPRT_WOWLAN            0
#define CONFIG_C2HPRT_FCS               0
#define CONFIG_C2HPRT_POWERSAVEING      0

#define CONFIG_PRINT_DEBUG              1
#if CONFIG_PRINT_DEBUG
#define CONFIG_DEBUGPRT_COMMON          0
#define CONFIG_DEBUGPRT_RA              (CONFIG_PRINT_DEBUG & CONFIG_RATE_ADAPTIVE)
#define CONFIG_DEBUGPRT_CCX             0//(CONFIG_PRINT_DEBUG & CONFIG_CCX)    
#define CONFIG_DEBUGPRT_PS              0//(CONFIG_PRINT_DEBUG & CONFIG_POWERSAVING)
#define CONFIG_DEBUGPRT_BT              0//(CONFIG_PRINT_DEBUG & CONFIG_BTCOEX)
#define CONFIG_DEBUGPRT_IQK             0//(CONFIG_PRINT_DEBUG & CONFIG_IQK_OFFLOAD)
#define CONFIG_DEBUGPRT_WOWLAN          0//(CONFIG_PRINT_DEBUG & CONFIG_REMOTE_WAKEUP)
#define CONFIG_DEBUGPRT_FCS             0//(CONFIG_PRINT_DEBUG & CONFIG_FAST_CHANNEL_SWITCH)
#else
#define CONFIG_DEBUGPRT_COMMON          0
#define CONFIG_DEBUGPRT_RA              0
#define CONFIG_DEBUGPRT_CCX             0
#define CONFIG_DEBUGPRT_PS              0
#define CONFIG_DEBUGPRT_BT              0
#define CONFIG_DEBUGPRT_IQK             0
#define CONFIG_DEBUGPRT_WOWLAN          0
#define CONFIG_DEBUGPRT_FCS             0
#endif


/******************************************

    Test & verification Configuration

*******************************************/


//1 Test & verification control
#define CONFIG_DV_SIMULATION_TEST		0
#define CONFIG_8051_IOPATH_RESET_TESTING        0
#define CONFIG_FULL_RANGE_MEMORY_TEST           0
#define CONFIG_IO_DEBUG                         0
#if CONFIG_CP_AFE_LBK_TEST
#define CONFIG_VERA_SIMULATION                  1       //ben, 151013
#else
#define CONFIG_VERA_SIMULATION                  0       //ben, 151013
#endif
#define CONFIG_AFE_LOOPBACK                     0
#define CONFIG_TRX_BUFF_RW                      0
#define CONFIG_H2C2H_LB                         0
#define CONFIG_RPWM_CPWM_LB                     0
#define CONFIG_TXBUFF_ROM_EN                    0
#define CONFIG_ROM_VERIFICATION                 0
#define CONFIG_TXPKTBUFTEST                     0	// Alan
#define CONFIG_802_11W                          0
#define CONFIG_GTK_11W_HW					    0
#define CONFIG_FW_TEST                        0


#endif  //#ifndef _AUTOCONF_H_

