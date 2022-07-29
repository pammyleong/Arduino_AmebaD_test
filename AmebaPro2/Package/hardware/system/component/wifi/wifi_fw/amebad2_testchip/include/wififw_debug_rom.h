#ifndef __RTL8721D_DEBUG_H__
#define __RTL8721D_DEBUG_H__


/*--------------------------Define -------------------------------------------*/
//
//**Note**:
//      If one of these register is used, we should register MACRO at RTLXXX_debug.h.
//
// Range List:
//      1.) 0x1B8 ~ 0x1BF : there are no control circuit. But these register can be R/W.
//      2.) 0x1C0 ~ 0x1C7: there are no control circuit. But these register can be R/W.
//      3.) 0x630 ~ 0x637: there are  control circuit. So should not be used; now change them to
//		0x644 ~ 0x64f:there are no control circuit. But these register can be R/W.

//      4.) 0x084 ~ 0x08F: there are no control circuit. But these register can be R/W.
//      5.) 0x168 ~ 0x16F: there are no control circuit. But these register can be R/W.
//                                  This register is reserved for GTimer usage in 8723D!!
//      6.) 0x2F0 ~ 0x2FF: there are no control circuit. But these register can be R/W.

//2 page 0 rsvd REG USERDEF


#define REG_DBG_DWORD_13        0x0054

#define REG_DBG_BYTE_6          0x0088
#define REG_DBG_BYTE_7          0x0089
#define REG_DBG_BYTE_8          0x008A
#define REG_DBG_BYTE_9          0x008B

//#define  0x008C
#define REG_ROM_VERSION             0x0099//RSVD

#define REG_BIST_ROM_RPT            0x00D8
#define REG_MEM_CTRL0               0x00E0
#define REG_MEM_CTRL1               0x00E4

#define REG_DBG_DWORD_9         0x00fc


//2 page1 rsvd REG userdef

// 4 Bytes
#define REG_DBG_DWORD_2         0x1A0
#define REG_DBG_DWORD_3         0x1A4

#define REG_DBG_DWORD_0         0x01B8
#define REG_DBG_DWORD_1         0x01BC

// 1 Bytes
#define REG_DBG_BYTE_0          0x01C0
#define REG_DBG_BYTE_1          0x01C1
#define REG_DBG_BYTE_2          0x01C2
#define REG_DBG_BYTE_3          0x01C3

// 2 Bytes
#define REG_DBG_WORD_0          0x01C4

#define REG_DBG_BYTE_4          0x01C6
#define REG_DBG_BYTE_5          0x01C7

#define REG_DBG_BYTE_14         0x01C8

//#define 0x1E0
//RAM Info
#define REG_RAM_VERSION             0x01E4
#define REG_RAM_SUBVERSION          0x01E5

//2 PAGE2 rsvd reg suerdef
#define REG_DBG_WORD_2    		0x0238
#define REG_DBG_WORD_3    		0x023A

#define REG_DBG_DWORD_10        0x02E4
#define REG_DBG_DWORD_11        0x02E8
#define REG_DBG_DWORD_12        0x02EC

#define REG_DBG_DWORD_4         0x02F0
#define REG_DBG_DWORD_5         0x02F4
#define REG_DBG_DWORD_6         0x02F8
#define REG_DBG_DWORD_7         0x02FC

//2 PAGE4 rsvd reg userdef
#define REG_DBG_BYTE_15		    0x04F0
#define REG_DBG_BYTE_16		    0x04F1
#define REG_DBG_BYTE_17		    0x04F2
#define REG_DBG_BYTE_18		    0x04F3
#define REG_DBG_BYTE_19         0x04F8
#define REG_DBG_BYTE_20         0x04F9
#define REG_DBG_BYTE_21         0x04FA
#define REG_DBG_BYTE_22         0x04FB

//2 PAGE 6 rsvd page userdef
#define REG_DBG_BYTE_10         0x0644
#define REG_DBG_BYTE_11         0x0645
#define REG_DBG_BYTE_12         0x0646
#define REG_DBG_BYTE_13         0x0647

#define REG_DBG_DWORD_8         0x0648


//1  Indirect define

// 5.) Power saving debug
#define REG_PS_32K              REG_DBG_DWORD_0  //1B8

#define REG_AntSwitchOutSide    REG_DBG_BYTE_22

#define REG_FWLBK_CTRL          REG_DBG_DWORD_12 //8

//3 Register Debug register for our purpose
// 1.) Firmware Component Error
#define REGDUMP_FW_ERR0         REG_DBG_BYTE_0
#define REGDUMP_FW_ERR1         REG_DBG_BYTE_1
#define REGDUMP_FW_ERR2         REG_DBG_BYTE_3

// 2.) Hardware Component Error
#define REGDUMP_HW_ERR0         REG_DBG_BYTE_2

// 3.) Program Counter
#define REGDUMP_CPUINST         REG_DBG_DWORD_13

// 4.) Unlock MCU inifinite-loop
//  0xFF: unlock Overall MCU while(1)
#define REG_UNLOCK_MCU          REG_DBG_BYTE_4

// 5.) FWLBK
#define REG_FTR                 REG_DBG_BYTE_3  //FWLBK

// 6.) Efuse Part Number
#define REG_PART_NUM            REG_DBG_BYTE_9
// Bit[7]: part number report enable
// Bit[6:4]: ant num
// Bit[3:2]: app_type
// BIT[1:0]: interface_type

// 7.) H2CPTR Index
#define REGDUMP_H2CPTR_IDX      REG_DBG_BYTE_8

// 8.) BT-COEX , null(1) send fail counter
#define REG_Null1_fail_counter	REG_DBG_BYTE_15
// 9.) BT-COEX , BT calibration indication bit for driver
#define REG_BT_Cal_Ind		    REG_DBG_BYTE_16

// 10.) BT Patch code checksum report (2 Byte)
#define REG_Checksum_L		    REG_DBG_BYTE_17
#define REG_Checksum_H		    REG_DBG_BYTE_18

// 11.) Pass Security Info to driver
#define REG_SECURITY_INFO       REG_DBG_DWORD_11
#define REG_KEY_INDEX           REG_DBG_BYTE_19
#define REG_WOW_PATTERN_INDEX   REG_DBG_BYTE_20

// 12.) update PS State to Driver
#define REG_Current_PS_STATE    REG_DBG_BYTE_6
#define REG_LastRpwm            REG_DBG_BYTE_7

// 13.) WoWlan wakeup reason
#define REG_WoW_REASON          REG_DBG_BYTE_5   //1C7

#define CLK_32K_UNLOCK          0xFD
#define CLK_32K_LOCK            0xFE


//REG_UNLOCK_MCU0 SubComponent
#define UNLOCK_MCU_TSF_STABLE   BIT0
#define UNLOCK_MCU_CPU_MGQ      BIT1
#define UNLOCK_MCU_RW_BB        BIT2
#define UNLOCK_MCU_32K_STABLE   BIT3
#define UNLOCK_MCU_GPIO_PUSLE   BIT4


#define DBG_ADDR(_addr)         WriteMACRegDWord(REGDUMP_CPUINST, _addr);

#define ManualDbg(stop)             while(ReadMACRegByte(0x01C3) <= stop) {}


#define REG_AOAC_REASON 		0x644
#define REG_AOAC_DEBUG 			0x648

//definition for 0x644    REG_AOAC_REASON
#define AOAC_ARP                            BIT0
#define AOAC_ISSUE_RS                       BIT1
#define AOAC_ON_RA                          BIT2
#define AOAC_ON_WAKEUP                      BIT3
#define AOAC_ISSUE_ARP                      BIT4
#define AOAC_IP_MISMATCH                    BIT5
#define AOAC_ON_BUBBLE                      BIT6
#define AOAC_ISSUE_BUBBLE                   BIT7


//definition for 0x645    REG_AOAC_REASON
#define AOAC_GTK_SHA1_POLLING_TIME_OUT_1    BIT0
#define AOAC_GTK_SHA1_POLLING_TIME_OUT_2    BIT1
#define AOAC_IPSEC_POLLING_TIME_OUT         BIT2
#define AOAC_ON_GTK                         BIT3
#define AOAC_ISSUE_GTK                      BIT4
#define AOAC_IPSEC_POLLING_FAIL             BIT5
#define AOAC_NLO_SCAN_EN		            BIT6
#define AOAC_NLO_FUNCTION_EN	    	    BIT7

//definition for 0x646    REG_AOAC_REASON
#define AOAC_D0_SCAN_EABLE                  BIT0
#define AOAC_RTD3_EABLE                     BIT1
#define AOAC_SCAN_START                     BIT2
#define AOAC_ISSUE_PROBE                    BIT3
#define AOAC_SSID_MATCH                     BIT4
#define AOAC_RWV2_ISSUE_KA                  BIT5
#define AOAC_RWV2_ON_ACK                    BIT6
#define AOAC_RWV2_ON_WAKEUP                 BIT7

//definition for 0x647    REG_AOAC_REASON
//This byte 0x646 is for D0_scan for channel info
//and for NDP offload
#define AOAC_ON_NDP             BIT0
#define AOAC_ISSUE_NDP          BIT1
#define AOAC_IPV6_MISMATCH      BIT2
#define AOAC_WPA2_ATTACK        BIT3
#define AOAC_GTK_M1_WPA         BIT4
#define AOAC_GTK_M1_RSN         BIT5
#define AOAC_GTK_M1_ERROR       BIT6

//definition for 0x648 REG_AOAC_DEBUG
#define GTK_DEBUG                           0
#define GTK_DEBUG_SHA1_VERIFY               1
#define GTK_DEBUG_AES_VERIFY                2

//REG_DBG_CTRL
#define DBGFUN_STEP_ENABLE      BIT7
#define DBGFUN_PRT_ENABLE       BIT6
#define DBGFUN_CTRL_ENABLE      BIT5
#define DBGFUN_PS_STATE_EN      BIT4 //report to 0x88[15:0]

#define DBGFUN_NOSTOP           BIT0

#define Rx_Pairwisekey          0x01
#define Rx_GTK                  0x02
#define Rx_Fourway_Handshake    0x03
#define Rx_DisAssoc             0x04
#define Rx_DeAuth               0x08
#define Rx_ArpRequest           0x09
#define Rx_NS                       0x0a
#define FWDecisionDisconnect    0x10
#define Rx_MagicPkt             0x21
#define Rx_UnicastPkt           0x22
#define Rx_PatternPkt           0x23
#define RTD3_SSID_Match         0x24
#define HW_RX_WAKEUP_PATTERN    0x25
#define RX_RealWoW_V2_WakeupPkt 0x30
#define RX_RealWoW_V2_AckLost   0x31
#define Enable_Fail_DMAIdle     0x40
#define Enable_Fail_DMAPause    0x41
#define RTime_Fail_DMAIdle      0x42
#define RTime_Fail_DMAPause     0x43
#define NLO_SSID_Match          0x55
#define AP_Offload_WakeUp       0x66
#define CLK_32K_UNLOCK          0xFD
#define CLK_32K_LOCK            0xFE

/*------------------------------Define Enum-----------------------------------*/


/*--------------------------Define MACRO--------------------------------------*/

/*------------------------------Define Struct---------------------------------*/
#ifndef __ASSEMBLY__

//REGDUMP_FW_ERR0
typedef enum _FW_ERR0_STATUS_ {
	FES0_H2C_CMDID              = BIT0,
	FES0_H2C_PTR                = BIT1,
	FES0_BB_RW                  = BIT2,
	FES0_TXPKT_TXPAUSE          = BIT3,
	FES0_TSF_STABLE             = BIT4,
	FES0_TXSM_STABLE            = BIT5,
	FES0_RPWM_STABLE            = BIT6,
	FES0_C2H_TIMEOUT_ERR        = BIT7,

} FW_ERR0_STATUS, *PFW_ERR0_STATUS;

//REGDUMP_FW_ERR1
typedef enum _FW_ERR1_STATUS_ {
	FES1_H2C_QUEUE_FULL         = BIT0,
	FES1_C2H_QUEUE_FULL         = BIT1,
	FES1_RXDMA_NOT_IDLE_ERR     = BIT2,
	FES1_WOWLAN_PKT_PTR         = BIT3,
	FES1_FD_LOCK_ERR            = BIT4,
	FES1_TRY_EN_ERR             = BIT5,
	FES1_WOWLAN_RX_ERR          = BIT6,
	FES1_C2HEXT_QUEUE_FULL      = BIT7
} FW_ERR1_STATUS, *PFW_ERR1_STATUS;

//REGDUMP_FW_ERR2
typedef enum _FW_ERR2_STATUS_ {
	FES2_DBGPKT_QUEUE_FULL      = BIT0,
	FES2_PATCH_VAR_OVERFLOW      = BIT1,
	FES2_PATCH_VAR_UNDERFLOW      = BIT2,
} FW_ERR2_STATUS, *PFW_ERR2_STATUS;


//REGDUMP_HW_ERR0
typedef enum _HW_ERR0_STATUS_ {
	HES0_USB_MDIO_INTF_ERR      = BIT0,
	HES0_PCIE_MDIO_INTF_ERR     = BIT1,
	HES0_USB_PHY_CMD_ERR        = BIT2,
	HES0_PCIE_PHY_CMD_ERR       = BIT3,

} HW_ERR0_STATUS, *PHW_ERR0_STATUS;

/*------------------------Export global variable------------------------------*/

/*------------------------------Funciton declaration--------------------------*/
extern void
main_test(
	void
);

extern void
PrintMcuDbgMsg(
	IN u8 idx,
	IN u8 byte_offset,
	IN u8 val
);

extern void
PrintMcuDbgMsgU16(
	IN u8 *val
) ;

extern void
DbgMonitorSel(
	void
);


#endif  //#ifndef   __ASSEMBLY__


#endif  //__RTL8721D_DEBUG_H__

