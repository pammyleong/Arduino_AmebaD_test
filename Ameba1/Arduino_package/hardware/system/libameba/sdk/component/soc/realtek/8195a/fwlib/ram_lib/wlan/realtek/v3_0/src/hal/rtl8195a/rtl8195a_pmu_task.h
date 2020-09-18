/******************************************************************************
 *
 * Copyright(c) 2007 - 2012 Realtek Corporation. All rights reserved.
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of version 2 of the GNU General Public License as
 * published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for
 * more details.
 *
 * You should have received a copy of the GNU General Public License along with
 * this program; if not, write to the Free Software Foundation, Inc.,
 * 51 Franklin Street, Fifth Floor, Boston, MA 02110, USA
 *
 *
 ******************************************************************************/
#ifndef __RTL8195A_PMU_TASK_H__
#define __RTL8195A_PMU_TASK_H__
#ifdef CONFIG_LITTLE_WIFI_MCU_FUNCTION_THREAD
//BitMAPDefine
#define RATEADAPTIVE        BIT0
#define H2CEVENT            BIT1
#define C2HEVENT            BIT2
#define RATRYDONE           BIT3
#define REMOTEWAKEEVENT     BIT4
#define APOFFLOADEVENT      BIT5
#define MAILBOXEVENT        BIT6
#define SWTIMEREVENT        BIT7

#define BBNHMEVENT          BIT8
#define DBGPKTEVENT         BIT9
#define SIDEBANDWoWLAN      BIT10

#if 0
#ifdef CONFIG_POWER_SAVING
#define BCNEARLY			BIT11
#define MTIBCNIVLEAR		BIT12
#define BCNRX				BIT13
#define RXBMD1				BIT14
#define RXBMD0				BIT15
#define RXUMD1				BIT16
#define RXUMD0				BIT17
#define TXPKTIN				BIT18
#define GTIMER6TO			BIT19
#define GTIMER7TO			BIT20
#endif //#ifdef CONFIG_POWER_SAVING
#endif

//BT mailbox
#define SETDATA BIT2
#define SETACK  BIT1
#define GETDATA BIT0




#define CONFIG_SW_MAILBOX       0 //temporary
#define CONFIG_DEBUGPRT_BT      1 //temporary

#ifdef CONFIG_BT_MAILBOX
//BTConCurr
#define DefaultTBTTOnPeriod 0xB
#define DefaultMedOnPeroid  0x8
#define MaxTBTTOnPeriod     0x2A   // 0X16
#define MaxMedOnPeroid      0x2A   // 0X16
#define MinTBTTOnPeriod     0x3
#define MinMedOnPeroid      0x3
#define NULL_EARLY          0x3
#define REDUCTIONPERIOD     0x5
#define DefaultRCount       0x4
#define DOWN                0
#define UP                  1
#define MAILBOX_MAX_LENGTH  7
#define EXTENSIONTHRESHOLD  65	//Alan 2013_0801
#define NORESPONSELIMIT     5
#define SLOT_WIFI           0
#define SLOT_BT             1
#define DEFAULTSETTING      3


//Alan 2013_0720
#define MAILBOX_STATUS	0

//Alan 2013_0923
#define SCO_eSCO_slot_unit	320	//320us
#define SCO_eSCO_timer_unit	32	//32us	
//#define SCO_WiFi_slot			0
//#define SCO_BT_slot			1
#define BT_reduce_code_size	1

//Alan 
#define WLAN_ON             0
#define WLAN_OFF            1

#define ANT_CTRL_BY_PTA     0x66
#define ANT_CTRL_BY_BBSW    0x77

#define ANT_TOGGLE_WIFI     0x20000000
#define ANT_TOGGLE_BT       0x10000000

#define MAILBOX_RTY_LMT     4

#define RSP_WIFI_FW         0
#define RSP_WIFI_REQ        1
#define RSP_BT_CHANGE_STS   2

#define SEL_COEX_TABLE_1    0x03//0x6c0  bit[1:0]=2'b11
#define SEL_COEX_TABLE_2    0xFC//0x6c4  bit[1:0]=2'b00

#define ONBT                0
#define ONWIFI              1
#define NOCHANGE            2
#define ONBBSW              0
#define ONPTA               1

#define DACSWING_ADDR       0x880

#define DACSWING_SHF        25
#define DACSWING_MASK       0xC1ffffff

#define RTY_LMT_SCONULL     5
#define RTY_LMT_BTQNULL     8
#define RTY_LMT_QNULL       8
#define RTY_LMT_CTS2SELF    0	//Alan ,use 0 is correct, suggest by Ausin-Lo



#define REG_MAILBOX_OUT_DATA0   0x70 
#define REG_MAILBOX_OUT_DATA1   0x74 
#define REG_MAILBOX_OUT_CTRL    0x78 
#define REG_MAILBOX_IN_DATA0    0x80 
#define REG_MAILBOX_IN_DATA1    0x84 
#define REG_VNDR_WL_PMC_IMR     0x88

#define WLCALIBRATION               0x01E7

#define REG_DBG_BYTE_22             0x048F
#define REG_DBG_BYTE_15             0x049C
#define REG_DBG_BYTE_16	            0x049D
#define REG_AntSwitchOutSide        REG_DBG_BYTE_22
#define REG_Null1_fail_counter	    REG_DBG_BYTE_15
#define REG_BT_Cal_Ind		        REG_DBG_BYTE_16

#define REG_TX_PKT_NUM              0x04E3
#define REG_ANT_SEL                 0x06CC

#define REG_BT_COEX                 0x0764
#define REG_WLAN_ACT_MSK_CTRL       0x0768
#define REG_REG_BT_STATISTICS_CTRL  0x076E
#define REG_BT_ACT_STATISTICS_RPT   0x0770
#define REG_BT_STATISTICS_OTH_CTRL  0x0778
#define REG_BT_ISR_CTRL             0x0783
#define REG_BT_ISR_STA              0x078F

#define REG_RFE_INV                 0x092C
#define REG_RFE_CTRL89              0x0930
#define REG_RFE_SWCTRL              rS0S1_PathSwitch //Page 9: 0x948

//Jimmy 
#define ANT_092C_CTRL_WIFI          0x00
#define ANT_092C_CTRL_BT            0x01



#endif //#ifdef CONFIG_BT_MAILBOX


/*--------------------------Define -------------------------------------------*/
#ifdef CONFIG_POWER_SAVING
#define MACID_CLIENT        0
#endif //#ifdef CONFIG_POWER_SAVING

/*------------------------------Define Enum-----------------------------------*/
#ifdef CONFIG_POWER_SAVING

//REGDUMP_FW_ERR0
typedef enum _FW_ERR0_STATUS_
{
    FES0_H2C_CMDID              = BIT0,
    FES0_H2C_PTR                = BIT1,
    FES0_BB_RW                  = BIT2,
    FES0_TXPKT_TXPAUSE          = BIT3,
    FES0_TSF_STABLE             = BIT4,
    FES0_TXSM_STABLE            = BIT5,
    FES0_RPWM_STABLE            = BIT6,
    FES0_C2H_TIMEOUT_ERR        = BIT7,
    
}FW_ERR0_STATUS, *PFW_ERR0_STATUS;


//TxPauseReasonCode
typedef enum _TRPC_ {
    TPRC_ISSUEBTQNull_1             = 0x1,
    TPRC_ISSUEBTQNull_2             = 0x2,
    TPRC_FLEXIBLEEXTENDECISION_1    = 0x3,
    TPRC_BTTDMA03_1                 = 0x4,
    TPRC_BTTDMABCN_1                = 0x4,
    TPRC_BTTDMATBTT_1               = 0x5,    
    TPRC_BTTDMA14_1                 = 0x6,
    TPRC_BTTDMATIMEOUT_1            = 0x6,    
    TPRC_BTTDMA25_3                 = 0x8,
    TPRC_BTTDMATIMEOUT_3            = 0x8,    
    TPRC_BTTDMA25_5                 = 0x9,
    TPRC_BTTDMATIMEOUT_4            = 0x9,    
    TPRC_BTTDMA25_7                 = 0xA,
    TPRC_BTTDMATIMEOUT_5            = 0xA,    
    TPRC_BTTDMA03_2                 = 0xB,
    TPRC_BTTDMATIMEOUT_6            = 0xB,    
    TPRC_BTTDMA14_2                 = 0xC,
    TPRC_BTTDMATIMEOUT_7            = 0xC,    
    TPRC_BTTDMA25_4                 = 0xE,
    TPRC_BTTDMATIMEOUT_9            = 0xE,    
    TPRC_BTTDMA25_6                 = 0xF,
    TPRC_BTTDMATIMEOUT_10           = 0xF,    
    TPRC_BTTDMA25_8                 = 0x10,
    TPRC_BTTDMATIMEOUT_11           = 0x10,
    TPRC_BACKUPANTENNA_1            = 0x11,
    TPRC_BTROLECHANGETIMER          = 0x12,    
	TPRC_ISSUENULLDATA_1			= 0x26,
	TPRC_ISSUENULLDATA_2			= 0x27,
    TPRC_ISSUENULLDATA_3            = 0x28,
    TPRC_ISSUEQNULL_1               = 0x29,
    TPRC_ISSUEQNULL_2               = 0x2A,    
	TPRC_PSS2TS3                    = 0x2B,
	TPRC_PSS0TS1					= 0x2C,
	TPRC_PSS2TS4                    = 0x2D,
	TPRC_PSS2TS5                    = 0x2E,
    TPRC_PSS0TS6                    = 0x2F,
    TPRC_SCOESCO_1                  = 0x36,
    TPRC_ISSUECTS2SELF_1            = 0x36,
    TPRC_ISSUECTS2SELF_2            = 0x37,    
    TPRC_ISSUECTS2SELF_3            = 0x38,
    TRPC_WAITTXSMOK_1               = 0x47,
    TRPC_WAITTXSMOK_2               = 0x48,    
} TRPC, *PTRPC;


typedef enum _PS_MODE_SETTING_SELECTION_
{
    MODE_SETTING_ACTIVE     = 0,
    MODE_SETTING_LEGACY     = 1,
    MODE_SETTING_WMMPS      = 2,
    #ifdef TDMA_POWER_SAVING
    MODE_SETTING_TDMA       = 3
    #endif //#ifdef TDMA_POWER_SAVING    
}PS_MODE_SETTING_SELECTION, *PPS_MODE_SETTING_SELECTION;

typedef enum _RxListenBeaconMode_
{
    RLBM_MIN                = 0,
    RLBM_MAX				= 1,
    RLBM_SELF_DEFINED		= 2

}RxListenBeaconMode, *PRxListenBeaconMode;

typedef enum _SMART_PS_MODE_FOR_LEGACY_
{
    SMART_PS_MODE_LEGACY_PWR1           = 0,        // TRX all use PS_POLL
    SMART_PS_MODE_TX_PWR0               = 1,        // TX: pwr bit = 0, RX: PS_POLL
    SMART_PS_MODE_TRX_PWR0              = 2         // TX: pwr bit = 0, RX: NULL(0)
}SMART_PS_MODE_FOR_LEGACY, *PSMART_PS_MODE_FOR_LEGACY;

#endif //#ifdef CONFIG_POWER_SAVING


#ifdef CONFIG_BT_MAILBOX

typedef enum _MAILBOX_STATUS_ {
    BT_Active_OutReady_not_zero	= BIT0,
    BT_Non_Ative				= BIT1,
    BT_Patch_Timeout			=BIT2,	
    BT_Content_Error			=BIT3,
    BT_Content_Checksum_error	=BIT4,
};

//Register C2H Command ID here
typedef enum _C2H_CMD_ {
    C2HID_DEBUG                 = 0,
    C2HID_H2C2HLB               = 1,
    C2HID_TXBF                  = 2,
    C2HID_CCX_TXRPT             = 3,
    C2HID_AP_REQ_TXRPT          = 4,
    C2HID_INIT_RATE_COLLECT     = 5,
    C2HID_PSD_RPT               = 6,
    C2HID_SCAN_COMPLETE         = 7,
    C2HID_PSD_CONTROL           = 8,
    C2HID_BT_INFORMATION        = 9,
    C2HID_BT_LOOPBACK           = 0x0A,
    C2HID_BT_MP_REPORT          = 0x0B,
    C2HID_RA_RPT                = 0x0C,
    C2HID_SPE_STATIS            = 0x0D,
    C2HID_RA_PARA_RPT            = 0x0E,
    C2HID_CURRENT_CHANNEL       = 0x10,
    C2HID_IQK_OFFLOAD           = 0x11,
    C2HID_BB_GAIN_REPORT        = 0x12,
    C2HID_RateAdaptive_RPT_88E  = 0x13,	//Ben, 130515, for 88e smic RA debug
    C2HID_GPIOWAKEUP            = 0x14,
    C2HID_MAILBOX_STATUS        = 0x15,		// Alan 2013_0720
    C2HID_P2P_RPT               = 0x16,
    C2HID_MCC_STATUS            = 0x17,

    C2HID_DEBUG_CODE           = 0xFE,
    C2HID_EXTEND_IND            = 0xFF
} C2H_CMD, *PC2H_CMD;


#endif //#ifdef CONFIG_BT_MAILBOX


/*--------------------------Define MACRO--------------------------------------*/
#ifdef CONFIG_POWER_SAVING

#define HAL_WL_READ32(addr)     \
                HAL_READ32(WIFI_REG_BASE, addr)
#define HAL_WL_WRITE32(addr, value)     \
                HAL_WRITE32(WIFI_REG_BASE, addr, value)
#define HAL_WL_READ16(addr)     \
                HAL_READ16(WIFI_REG_BASE, addr)
#define HAL_WL_WRITE16(addr, value)     \
                HAL_WRITE16(WIFI_REG_BASE, addr, value)
#define HAL_WL_READ8(addr)     \
                HAL_READ8(WIFI_REG_BASE, addr)
#define HAL_WL_WRITE8(addr, value)     \
                HAL_WRITE8(WIFI_REG_BASE, addr, value)

#define mtou(x) ((x)<<10) //ms->us

#define WAIT_TSF_STABLE_BREAK_CNT       5000
#define WAIT_TSF_STABLE_CNT             50
#define WAIT_TSF_STABLE_ONCE_TIME       20
#define TSFIS32K                        1
#define TSFIS40M                        0
#define GET_TSF_STATE() (((HAL_WL_READ16(0xF0) & BIT8) && (HAL_WL_READ16(0xF0) & BIT9)) ? TSFIS32K : TSFIS40M)


#define REG_ARFR5_8723B				0x04A4
#define WAIT_TXSM_STABLE_CNT		1000
#define WAIT_TXSM_STABLE_ONCE_TIME	50

#define MODE_TIMER                  1
#define MODE_COUNTER                0


#define GTIMER6						6
#define GTIMER7						7

#define TIMER_BCNTO					GTIMER6 //6
#define TIMER_DTIM					GTIMER6 //6
#define TIMER_CHECKSTATE            GTIMER6 //6
#define TIMER_PSTRX					GTIMER7 //7
#ifdef TDMA_POWER_SAVING
#define TIMER_TDMA					GTIMER7 //7
#endif //#ifdef TDMA_POWER_SAVING

#define RTY_LMT_NULLDATA            8
#define RTY_LMT_PSPOLL				24
#define RTY_LMT_MORE_NULLDATA       24


/*
    PS_RX_INFO[7:0]: Power Save RX Information Register
    initial value: 0x00
    REG III.220 (Offset 0x 0692h) PS_RX_INFO Register Definition    
*/
#define RXDATAIN0               BIT0  //PSTX
#define RXDATAIN1               BIT1  //PSRX
#define RXDATAIN2               BIT2
#define RXMGTIN0                BIT3
#define RXCTRLIN0               BIT4

//CPWM Definition
#define CLK_DOWN_RDY            BIT4

//Power Save Tuning Parameter
//#if IS_CATEGORY_WOWLAN(CONFIG_CATEGORY_SEL)
//#define DEFAULT_BCN_TO_LIMIT    5 // 1
//#define DEFAULT_BCN_TO_PERIOD   8   //5
//#else
#define DEFAULT_BCN_TO_LIMIT    2  // 1
#define DEFAULT_BCN_TO_PERIOD   4   //5
//#endif

#define DEFAULT_BCN_TO_TIMES_LIMIT  2 // 20140806
#define DEFAULT_DTIM_TIMEOUT    15  // 7         // 7 ms
#define DEFAULT_PS_TIMEOUT      15  // 20       // 20 ms
#define DEFAULT_PS_DTIM_PERIOD  7
#define DEFAULT_PS_DRV_EARLY    2
#define DEFAULT_ENTER32K_TIMER  1000 //us
//#define PS_DRV_BCN_SHIFT_MAX   DEFAULT_PS_DRV_EARLY-1


#define NULL_DATA0_ALLOW        1
#define NULL_DATA0_DENY         0

#define PS_RF_OFF_8723B			0	
#define PS_GO_ON                BIT0
#define PS_TX_NULL              BIT1
#define PS_RF_ON                BIT2
#define PS_REGISTER_ACTIVE      BIT3
//#define PS_ACK                  BIT6
//#define PS_TOGGLE               BIT7


#define PS_STATE_MASK           (0x0F)
//#define PS_STATE(x)             (PS_STATE_MASK & (x))
#define PS_IS_TX_NULL(x)        ((x) & PS_TX_NULL )
//#define PS_IS_ACK(x)            ((x) & PS_ACK ) 
#define PS_IS_CLK_ON(x)         ((x) & (PS_RF_OFF_8723B |PS_ALL_ON ))
#define PS_IS_RF_OFF(x)         ((x)|PS_RF_OFF_8723B)
//#define PS_IS_RF_ON(x)          ((x) & (PS_RF_ON))
//#define PS_IS_ACTIVE(x)         ((x) & (PS_REGISTER_ACTIVE))

#define PS_STATUS_S0            (PS_REGISTER_ACTIVE | PS_RF_ON)                    //(1,1,0) all on = register active + rf on
#define PS_STATUS_S1            (PS_REGISTER_ACTIVE | PS_RF_ON | PS_TX_NULL)        //(1,1,1) all on + tx null(1)
#define PS_STATUS_S2            (PS_RF_ON)                                         //(0,1,0) register sleep + rf on
#define PS_STATUS_S3            (PS_RF_ON | PS_TX_NULL)                            //(0,1,1) register sleep + rf on + tx null(0)
#define PS_STATUS_S4            0                                                 //(0,0,0) all OFF
#define PS_STATUS_S5            (PS_TX_NULL )                                      //(0,0,1) SCAN = register sleep + rf on + scan enable
#define PS_STATUS_S6            (PS_REGISTER_ACTIVE)                               //(1,0,0) NoA off = register active + rf off


/* DATA FIN Condition Flags */
#define STA_DATA_OPEN           BIT0                                            // indicate that FW open due to TIM = 1 condition. (PS-POLL as trigger frame)
#define BC_DATA_OPEN            BIT1                                            // indicate that FW open due to DTIM = 1 condition.  (BC & MC)
#define QOS_DATA_OPEN           BIT2                                            // indicate that FW open due to UAPSD trigger condition. (QNULL)
    
#define ALL_80211_DATA_OPEN     (STA_DATA_OPEN | BC_DATA_OPEN | QOS_DATA_OPEN)
#define IS_80211_DATA_OPEN(x)   ((x) & ALL_80211_DATA_OPEN)

#define C2H_DATA_OPEN           BIT3                                            // indicate that FW open due to C2H event 
#define IS_C2H_DATA_OPEN(x)     ((x) & C2H_DATA_OPEN)

#define BCN_DATA_OPEN           BIT4
#define APP_DATA_OPEN           BIT5

#define SET_DATA_OPEN(x, type)  ((x) |= (type))
#define CLR_DATA_OPEN(x, type)  ((x) &= (~type))
#define IS_DATA_OPEN(x, type)   ((x) & (type))

//pwr state
#define PS_TYPE_32KPERMISSION       0
#define PS_TYPE_CURRENT_PS_STATE    1
#define PS_TYPE_LASTRPWM            2

#define CCXRPT_START_ADDR       0x0000
#define SW_DEFINE_NULL0         0x123
#define SW_DEFINE_NULL1         0x321
#define SW_DEFINE_OFFSET        6
#define RETRY_OVER              BIT7

#define CCXRPT_OFFSET(x)           (x << 3)

#define WLAN_ENTERCRITICAL()    __disable_irq() 
#define WLAN_EXITCRITICAL()     __enable_irq()

#endif //#ifdef CONFIG_POWER_SAVING

#ifdef CONFIG_BT_MAILBOX
#define BTNRDY              BIT6
#define BTRDY               BIT7
#define FTINT_BTCMD         BIT18  
#define FTINT_TRIGGER_PKT   BIT19 

#define GTIMER3				3
#define GTIMER4				4
#define GTIMER5				5
#define MAILBOX_TIMER_MASK  GTIMER4
#define BTTDMA_TIMER_MASK   GTIMER3 
#define BT_GTIMER3          0x1
#define BT_GTIMER4          0x2

#define LENGTH_C2H_BUFF     10
#define C2H_Q_FULL(x, y)        (((((x) == 0) && ((y) == (LENGTH_C2H_BUFF - 1)))||((y) == ((x) - 1))) ? _TRUE : _FALSE)



#endif //#ifdef CONFIG_BT_MAILBOX


/*------------------------------Define Struct---------------------------------*/
#ifdef CONFIG_POWER_SAVING
typedef struct _PS_PARM_ {

    u8      Enter32KHzPermission;
    u8      bAllQueueUAPSD;   
    u8      ps_dtim_flag;             // indicate dtim of current beacon.
    u8      pstrx_rxcnt_period;
    u8      NoConnect32k;
    u8      ack_last_rpwm;
    u8      TxNull0;
    u8      TxNull1;
    
    u8      TxNull0ok;
    u8      TxNull1ok;
    u8      RfOffLicenseForBCNRx;     //filen: After we received ps_bcn_cnt beacons, we can sleep(rf off).
    u8      BCNAggEn;
    u8      IsGoingTo32K;    
	u8      bMaxTrackingBcnMode;
    u8      BcnTraceDone;
        
/*
    filen: to indicate whether it is smart power saving or not
    0: Legacy PS 
    1: Smart PS(RX use ps_poll)
    2: Smart PS (RX use null_data(0))
*/
    u8      smart_ps:4;                 //enum SMART_PS_MODE
    u8      RLBM:4;                     // RX BCN MODE (min, max, active, ...)
    u8      AwakeInterval;
    u8      ps_mode;                    // ps type (avtive, legacy, wmmps)
    u8      ClkRequestEnable;
    u8      last_rpwm;
    u8      current_ps_state;
    u8      ps_data_open;
    u8      ps_bcn_pass_time;           // fw will only report one beacon information to driver after ps_bcn_pass_time ms. Unit: 100ms

    u8      ps_dtim_period;
    u8      ps_dtim_cnt;
    u8      ps_bcn_to;                  // beacon timeout (ms).
    u8      bcn_to_cnt;                 // indicate the total number of contnuous BCN_TO we have received.
    u8      bcn_to_times_cnt;           //20140806
    u8      min_rate_in_rrsr;
//    u8      lps_control;
    u16     ps_drv_early_itv;           
//    u32     RFECtrl;
    u32     null1_ok_cnt;
    #ifdef TDMA_POWER_SAVING
    u8      SlotPeriod;
    u8      FirstOnPeriod;
    u8      SecondOnPeriod;
    u8      ThirdOnPeriod;
    u8      CurrentSlot;
    BOOLEAN TDMAOnPeriod;
    #endif // #ifdef TDMA_POWER_SAVING

#if 0
    u8      BcnAheadShift;
    u8      BcnEarlyShift;
    u8      BcnEarlyShiftMax;	
    u8      DefaultBcnEarly;
    u8      RxBcnCount;
    u8      TBTTCount;
    u8      CurrentEarly;
    u8      CurrentTimeOut;
    u8      ReachBcnLimitCount;
    u8      BcnDelayInAheadGroupOfAP;
    u8      BcnDelayInRearGroupOfAP;
    u8      BcnDelay[BCN_CALCULATION_MAX];
    u8      XtalDelay;

    u16     TSFOnTBTT;              //unit in TU
    u32     TSFOnRxBcn;
    u32     TSFOnBcnEarly;
#endif

#if 0
#if CONFIG_BCNEARLY_ADJUST
    u8      BcnEalyIndex;
    u8      BcnEarlyAdjustPosition;
    u8      BcnAdjustTogo;
    u8      RxBcnArray[BCN_ADJUST_COUNT];
#endif
#endif
}PS_PARM, *PPS_PARM;

typedef struct _LEGACY_PS_PPARM_ {
    u8      ps_mode:7;
    u8      ClkRequestEnable:1;
    u8      RLBM:4;             	//RX Listen BCN Mode
    u8      smart_ps:4;
    u8      AwakeInterval;      	//Unit: beacon interval, this field is only valid in PS Self-Defined mode
    u8      bAllQueueUAPSD:1;     	// 1: all queue are uapsd 0: not all queue are uapsd
    u8      bMaxTrackingBcnMode:1;
    u8      rsvd:6;
//#if CONFIG_FAST_CPWM
    u8      PwrState;
//#else
//    u8      permission32k:1;
//    u8      rsvd1:7;
//#endif

    u8      LowPwrRxBCN     :1;
    u8      AntAutoSwitch   :1;
    u8      PSAllowBTHighPri:1;
    u8      ProtectBCN      :1;
    u8      SilencePeriod   :1;
    u8      FastBTConnect   :1;
    u8      TwoAntennaEn    :1;
    u8      rsvd2           :1;
    u8      AdoptUserSetting:1;
    u8      DrvBcnEarlyShift :3;
    u8      DrvBcnTimeOut :4;
    #ifdef TDMA_POWER_SAVING
    u8      SlotPeriod;
    u8      FirstOnPeriod;
    u8      SecondOnPeriod;
    u8      ThirdOnPeriod;
    #endif //#ifdef TDMA_POWER_SAVING
}LEGACY_PS_PARM, *PLEGACY_PS_PARM;

//H2C Index: 0x20
typedef struct _H2CParam_SetPwrMode_parm_ {
    LEGACY_PS_PARM      PwrModeParm;
}H2CParam_PwrMode, *PH2CParam_PwrMode;

#endif //#ifdef CONFIG_POWER_SAVING

#ifdef CONFIG_BT_MAILBOX
typedef struct _BTTxStatus_Parm_ {
    u8      StatusWLOpmode:1;
    u8      StatusWLOpmodeTx:1;
    u8      StatusBTInfo:1;
    u8      StatusBTInfoTx:1;
    u8      StatusIgnoreWLAct:1;
    u8      StatusIgnoreWLActTx:1;
    u8      StatusBTMP:1;
    u8      StatusBTMPTx:1;
    u8      StatusAutoRPT:1;
    u8      StatusAutoRPTTx:1;
    u8      rsvd:6;
    u8      BTInfo;
    u8      IgnoreWLAct;
    u8      AutoRPT;
    u8      BTMPContent[5];
}BTTxStatus_Parm, *PBTTxStatus_Parm;

typedef struct _BT_B_TYPE_TDMA_Parm_ {
    //B0
    u8      Enable                  :1;
    u8      ValueofReg870InBT       :1;     //1:0x870 = 0x300, 0:0x870 = 0x310
    u8      TxPspollIntheMedium     :1;
    u8      ValueOfReg870           :1;     // when disable 1:0x870 = 0x310, 0:0x870 = 0x300  
                                            //when enable 1: 0x860 = 0x110, 0:0x860 = 0x210
    u8      AutoWakeUp              :1;		//when set 1, use null(0) and null(1) packet
    u8      NoPS                    :1;			//when set 1, in BT slot will pause WiFi Tx
    u8      AllowBTHighPriority     :1;
    u8      ValueofReg870InWIFI     :1;     //1:0x870 = 0x300, 0:0x870 = 0x310
    //B1
    u8      TBTTOnPeriod;
    //B2
    u8      MedPeriod;
    //B3              
    u8      NoTxPause               :1;
    u8      Valueof778InWIFI        :1;
    u8      Valueof778InWIFIOnSCO   :1;
    u8      ValueofReg778           :1;     //when disable 1: 778=3, 0: 778=1
                                            //when enable 1:allow 32k, 0:not allow 32k
    u8      SCOOption               :1;
    u8      ValueofReg860InWIFI     :1;
    u8      TwoAntenna              :1;
    u8      ReduceWIFIPower         :1;
    //B4
    u8      ExtraDecisonOf778             :1;
    	//u8      RxExtension             :1; // no use : Alan 2013_0805
    u8      CCK_Priority_toggle   :1;
    //u8      NoPSRFCtrl              :1;		//When set 1. in BT slot need to close WiFi RF 
    u8      WifiAutoSlot            :1;
    //u8      ChangeCoexTable2        :1;	//no use: Alan 2013_0805
    u8		CTS2Self				  :1;	
    u8      ChangeCoexTable         :1;
    u8      LongNAV                 :1;			// use large NAV to protect BT slot
    u8      FlexibleExtension       :1;
    u8      ValueofReg778B1InBT     :1;        // 1:778[1]=1, 0:778[1]=0 in bt

    //DHCP
    u8      DtimExt;
    u8      DHCPOn                  :1;
    u8      NoRxBCNCondition        :1;
    u8      Write860                :1;
    u8      Value860                :1;
    
    u8      DTIMFlag                :1;
    u8      WifiActive              :1;
    u8      rsvd2                   :2;    

    u8      BTTxAbort               :1;
    u8      TxNull1                 :1;
    u8      TxNull1ok               :1;
    u8      rsvd3                   :5;
    
    u8      WLANPeriodTemp;
    u8      ExtensionThreshold1;
    u8      ExtensionThreshold2;
    u8      ExtensionThreshold3;
    u8      HalfTBTTOnPeriod;
    u8      HalfMedPeriod;
    u8      RNum;
    u8      RCount;
    u8      HalfBCNIvl;
    u8      BCNIvl;			//Alan 2013_0911
    u8      WLANOnPeriod;
    u8      WLANPeriodCount;
    u8      InitialBTPower;
    u8      ExtensionCount;
    u8      NullExtensionCount;
    u8      NAVTemp;
    u8      TxCounter;
    u8      BTConnect;
    u8      BTRptConnect;
    u8      BTChangeType:1;
    u8      BTCTCount:4;
    u8      BTCTCTh:3;
    u32     ValueBackup;
    u8      ValueBackup2;
    u8      ValueBackup3;
    u8      ValueBackup4;
    u8      MailboxRdy;
    u8      BTDisable;
    u8      RxExtension             :1;				// Alan 2013_0905
    u8      WLCalibrationEn         :1;
    u8      GNT_BT_Val              :1;                        //Alan 2014_0226
    u8      BTOnlyTest              :1;     
    u8      DynamicSlotBackup       :1;
    u8      rsvd4:3;
    u16     Reg948Backup;
    BTTxStatus_Parm BTTxStatus;
    u8      extensionthreshold;                     //alan 20150108
} BT_B_TYPE_TDMA_Parm, *PBT_B_TYPE_TDMA_Parm;

//H2C Index: 0x60
typedef struct _BT_MAILBOX_Parm_ {
    u8          signal_ant_en:1;
    u8          DAC_swing_en:1;
    u8          NAV_en:1;
    u8          TDMA_En:1;
    u8          rvsd:4;
    
    u8          bt_rssi_init_value;
    u8          bt_rssi_current_value;
    u32         DAC_swing_level;
    u32         DAC_swing_init_value;
    u8          init_value_0x2e;
    u8          init_value_0x2d;
    u8          OneAntSCOEnable;
    u8          BTNoResponseCount;
    u8          AntSelReverse;
    u8          SwitchOutside;
    u8          RAOffsetEn;
    u8          RAOffset;
    u8          RAOffsetMCS7;
    u8          RAOffsetMCS6;
    u8          RAOffsetMCS5;
    u8		 BTCalibration:1;
    u8           rsvd1:7;
    u8		 BTCalibrationPeriod;
    u8  	 Null1_FAIL_Counter;	
}BT_MAILBOX_Parm, *PBT_MAILBOX_Parm;

//H2C Index: 0x66
typedef struct _WLAN_Opmode_Parm_ {
    u8          opmode; // RT_MEDIA_STATUS
    u8          chl_idx;
    u8          bw;     
}WLAN_Opmode_Parm, *PWLAN_Opmode_Parm;

//H2C Index:0x6B
typedef struct _BT_SCO_eSCO_operation_Parm_{

	//Byte0	
	u8    enable:1;
	u8	Control_Pkt_Type:2;
	u8	Tx_Pause_BT_slot:1;
	u8	Coex_Table_toggle:1;
	u8	Antenna_Toggle:1;
	u8	rsvd_1:2;

	//Byte1	
	u8	ValueOf778WiFi_slot:2;
	u8	Ant_position_wifi_slot:1;
	u8	rsvd_2:1;
	u8	ValueOf778BT_slot:2;
	u8	Ant_position_bt_slot:1;
	u8	rsvd_3:1;

	//Byte2
	u8	WiFi_slot;		
	//Byte3	
	u8	BT_slot;		
	//Byte4	
	u8	CTS2Self_NAV;	

	//not from H2C
	u8	stage;
	u8	INT_count;
	u8	issue_null_stage;
	u8	SCO_eSCO_TX_null_flag;
	u8	SCO_eSCO_period_end_flag;
	u16	WiFi_slot_real;
	u16	BT_slot_real;
	u16	CTS2Self_NAV_real;
}BT_SCO_eSCO_operation_Parm,*PBT_SCO_eSCO_operation_Parm;

//H2C Index:0x6C
typedef struct _H2CHDL_BT_Page_Scan_Interval_Parm_{
	u8	LSB_Interval;
	u8	MSB_Interval;
}BT_Page_Scan_Interval_Parm,*PBT_Page_Scan_Interval_Parm;

typedef struct _H2CHDL_BT_Init_Parm_ {
    u8  Enhance3wireMode:1;
    u8  HighPowerPAMode:1;
    u8  rsvd:6;
}BT_Init_Parm, *PBT_Init_Parm;

typedef struct _PS_BT_Parm_ {
    u8      PspollTxFlag;
    u8      LowPwrRxBCN     :1;
    u8      AntAutoSwitch   :1;
    u8      PSAllowBTHighPri:1;
    u8      ProtectBCN      :1;
    u8      SilencePeriod   :1;
    u8      FastBTConnect   :1;
    u8      TwoAntennaEn    :1;
    u8      LowPwrRxBCNLeave:1;
}PS_BT_Parm, *PPS_BT_Parm;

typedef struct _BtCoex_info_ {
        BT_B_TYPE_TDMA_Parm     BtTdmaParm;
        BT_MAILBOX_Parm         BtParm;
        WLAN_Opmode_Parm        WIFI_Info;           
        BT_SCO_eSCO_operation_Parm      BT_SCO_eSCO_info;   
        BT_Page_Scan_Interval_Parm      BT_Page_Scan_Interval;
        BT_Init_Parm            BT_Init_Info;
        
#ifdef CONFIG_POWER_SAVING        
        PS_BT_Parm              PSBTParm;
#endif //#ifdef CONFIG_POWER_SAVING

#if CONFIG_DEBUGPRT_BT
        u8                      BTcnt[40];
#endif  
        u8                      BT_Timer_Flag;

}BtCoex_info, *PBtCoex_info;


//==================C2H event format ====================
// Field     SYNC       CMD_LEN     CONTENT    CMD_SEQ      CMD_ID
// BITS  [127:120]  [119:112]      [111:16]          [15:8]        [7:0]
typedef struct _C2H_EVT_HDR_H {
    u8  cmd_id;
    u8  cmd_seq;
    u8  content[12];
    u8  cmd_len;
}C2H_EVT_HDR_H, *PC2H_EVT_HDR_H;


typedef struct _C2H_INFO_ {
    u8  c2h_w_ptr;
    u8  c2h_r_ptr;
    PC2H_EVT_HDR_H  pc2h_evt_hdr[LENGTH_C2H_BUFF];
}C2H_INFO, *PC2H_INFO;
#endif //#ifdef CONFIG_BT_MAILBOX


/*------------------------------Function declaration--------------------------*/

#ifdef CONFIG_POWER_SAVING
#if 0
extern void ClockDown(PADAPTER padapter);
extern void ClockUp(PADAPTER padapter);
extern void PrintBcnFunction(void);
extern void DisDbgMsg(void);
extern void EnDbgMsg(void);
extern void UpChGain(void);
extern void StartCount(PADAPTER padapter);
extern void StopCount(PADAPTER padapter);
extern void IssueNullDataTest(PADAPTER padapter);
extern void ShowPowerState(PADAPTER padapter);
#endif
#ifdef TDMA_POWER_SAVING
extern void TDMAChangeStateTask(PADAPTER padapter);
#endif //#ifdef TDMA_POWER_SAVING
extern void EnterPS(PADAPTER padapter);
extern void GTimer6Handle(VOID *Data);
extern void GTimer7Handle(VOID *Data);
extern void InitGTimer1ms(PADAPTER padapter, u8 IRQDis, u8 TimerID, u32 Period);
extern void DeInitGTimer1ms(PADAPTER padapter, u8 TimerID);
extern void ChangeTransmiteRate(u16 offset, u8 rate);
extern void PowerBitSetting(PADAPTER padapter,BOOLEAN bPowerBit, u16 offset);
extern void ChkandChangePS(PPS_PARM pPSParm, BOOLEAN bPowerBit);
extern u16 IssueRsvdPagePacketSetting(PADAPTER padapter, u8 PageNum, BOOLEAN bHwSEQEn, u8 RtyLmt);
extern void InitRsvdPgPkt(void);
extern BOOLEAN IssueNullData(PADAPTER padapter, BOOLEAN bPowerBit, u8 RtyLmt);
extern void IssuePSPoll(PADAPTER padapter);
extern BOOLEAN WaitTxStateMachineOk(PADAPTER padapter);
extern void WriteTxPause(u8 value, u8 rcode);
extern void PsCloseRF(PADAPTER padapter);
extern void PsOpenRF(PADAPTER padapter);
extern void SetPwrStateReg(PPS_PARM pPSParm, u8 PwrStateType, u8 value);
extern BOOLEAN ChkTxQueueIsEmpty(void);
extern void InitPS(PADAPTER padapter);
extern void ResetPSParm(PADAPTER padapter);
extern void Legacy_PS_Setting(PADAPTER padapter);
extern void PSModeSetting(PADAPTER padapter, u8 on);
extern void ConfigListenBeaconPeriod(PPS_PARM pPSParm, u8 RLBM, u8 AwakeInterval);
extern void PSSetMode(PADAPTER padapter, PLEGACY_PS_PARM pparm);
extern BOOLEAN PS_S2_Condition_Match(PADAPTER padapter);
extern BOOLEAN PS_S4_Condition_Match(PADAPTER padapter);
extern BOOLEAN PS_32K_Condition_Match(void);
extern void PS_S2ToS3ToS0State(PADAPTER padapter, u8 nulldata0Allow);
extern void PS_S2ToS0State(PPS_PARM pPSParm);
extern void PS_S3ToS2orS0State(PPS_PARM pPSParm);
extern void PS_S0ToS1ToS2State(PADAPTER padapter);
extern void PS_S1ToS0orS2State(PPS_PARM pPSParm);
extern void PS_S2ToS4State(PADAPTER padapter);
extern void PS_S2ToS5State(PPS_PARM pPSParm);
extern void PS_S4ToS2State(PADAPTER padapter, u8 ReleaseTxPause);
extern void PS_S5ToS2State(PPS_PARM pPSParm);
extern void PS_S0ToS6State(PADAPTER padapter);
extern void PS_S6ToS0State(PADAPTER padapter);
extern void CheckTSFIsStable(u8 ReqState);
extern void WaitHWStateReady(void);
extern void SysClkDown(PADAPTER padapter);
extern void SysClkUp(PADAPTER padapter);
extern void SleepTo32K(PADAPTER padapter);
extern void Change_PS_State(PADAPTER padapter, u8 request_ps_state, u8 nulldata0Allow);
extern void ChangePSStateByRPWM(PADAPTER padapter);
extern void SetSmartPSTimer(PADAPTER padapter);
extern void SmartPS2InitTimerAndToGetRxPkt(PADAPTER padapter);
extern void PS_OnBeacon(PADAPTER padapter);
extern void PSBcnEarlyProcess(PADAPTER padapter);
extern void PSMtiBcnEarlyProcess(PADAPTER padapter);
extern void PSRxBcnProcess(PADAPTER padapter);
extern void TxPktInPSOn(PADAPTER padapter);
extern void PsBcnToProcess(PADAPTER padapter);
extern BOOL RPWMProcess(PADAPTER padapter, BOOLEAN benter32k);
extern void ISR_MtiBcnEarly(PADAPTER padapter);
extern void ISR_BcnEarly(PADAPTER padapter);
extern void ISR_RxBcn(PADAPTER padapter);
extern void ISR_RxBCMD1(PADAPTER padapter);
extern void ISR_RxBCMD0(PADAPTER padapter);
extern void ISR_RxUCMD1(PADAPTER padapter);
extern void ISR_RxUCMD0(PADAPTER padapter);
extern void ISR_TxPktIn(PADAPTER padapter);
extern void ISR_TXCCX(PADAPTER padapter);
extern void ISR_WlFTINT(PADAPTER padapter);
extern void ISR_SCO_OP(PADAPTER padapter);
extern void H2CHDL_SetPwrMode(PADAPTER padapter, u8* pCmdBuffer);
extern void H2CHDL_PS_SCAN(PADAPTER padapter, u8* pCmdBuffer);
extern void CheckInReqStateTask(PADAPTER padapter);
extern void HalSetRPWM(PADAPTER padapter, BOOLEAN benter32k);
extern u32  HalGetNullTxRpt(PADAPTER padapter);
//extern thread_return HalEnter32KThreadRtl8195a(thread_context context);
#endif //#ifdef CONFIG_POWER_SAVING

extern void ISR_TBTT(PADAPTER padapter);
extern void H2CHDL_BcnIgnoreEDCCA(PADAPTER padapter, u8* pCmdBuffer);

void PMUTask(PADAPTER padapter);
void PMUInitial(PADAPTER padapter);


#ifdef CONFIG_BT_MAILBOX
extern void GTimer5Handle(VOID *Data);
extern void Write778(IN PADAPTER padapter, IN u8 value);
extern void DacSwing(IN PADAPTER padapter, IN u8 action);
extern void InitBTMailbox(IN PADAPTER padapter); 
extern void BTMailboxRetry(IN PADAPTER 	padapter); 
extern void C2HBTInfo (IN PADAPTER padapter, IN u8 option); 
extern void C2HBTLoopback (IN PADAPTER padapter, IN u8 *pbuf);
extern void C2HBTMpRpt(IN PADAPTER padapter, IN u8 idx, IN u8 status, IN u8 req_num); 
extern void C2HBTMailBoxStatus(IN u8 status); 


extern void BTNullSetting(IN PADAPTER padapter,IN u8 bPowerBit, IN u16 offset, IN u8 lsb, IN u8 msb);
extern void IssueBTQNull(IN PADAPTER padapter,IN u8 bPowerBit, IN u8 lsb, IN u8 msb);
extern void WlanActCtrl(IN PADAPTER padapter); 
extern void ChangeCoexTable(IN PADAPTER padapter, IN u8 slot); //#pragma disable 
extern void InitBTCoexTimer(IN PADAPTER padapter, IN u8 duration);
extern void InitSCOTimer(IN PADAPTER padapter, IN u16 duration);
extern void FlexibleExtensionDecision(IN PADAPTER padapter); 
extern void BT_TDMA_Slot_Operation_1and4(IN PADAPTER padapter, IN	u8 slot_num);
extern void BT_TDMA_Slot_Operation_2and5(IN PADAPTER padapter, IN	u8 slot_num);    
extern void BT_TDMA_Slot_Operation_0and3(IN PADAPTER padapter, IN	u8 slot_num); //#pragma disable      
extern void BT_TDMA_Dynamic_Slot(IN PADAPTER padapter); //#pragma disable  
extern void InitBTypeTDMA(IN PADAPTER padapter); 
extern void InitBTypeTDMA2(IN PADAPTER padapter); 
extern void BTypeTDMABCNEarly(IN PADAPTER padapter); 
extern void BTypeTDMATBTThdl(IN PADAPTER padapter); 
extern void BTypeTDMATimeOuthdl(IN PADAPTER padapter); 
extern void AntennaSwitchCtrl(IN PADAPTER padapter,u8 side,u8 ctrl); //#pragma disable  
extern void BackupAntennaSetting(IN PADAPTER padapter,IN u8 option); 
extern void BTRoleChangeTimerHDL(IN PADAPTER padapter);
extern void BTRoleChangeDefaultSetting(IN PADAPTER 	padapter); 
extern void BTRoleChangeTBTTHDL(IN PADAPTER padapter); 
extern void MailboxINTHDL(IN PADAPTER padapter); 
extern void SCO_eSCO_IssueCtrlData(IN PADAPTER padapter,IN u8 ctrl_pkt_type,IN u8 slot,IN u8 power_bit);
extern void BTSCOeSCOAntSetup(IN PADAPTER padapter,IN u8 slot); 
extern void BTSCOeSCOIssueNullHDL(IN PADAPTER padapter); //#pragma disable  

extern void IssueQNull(IN PADAPTER padapter,IN u8 bPowerBit); //#pragma disable  
extern void CTS2SelfSetting(IN u16 offset, IN u16 NAV); //#pragma disable  
extern void IssueCTS2Self(IN PADAPTER padapter,IN u16 NAV); //#pragma disable   


extern void FillMailbox(IN PADAPTER padapter,IN u8 cmd, IN u8 length, IN u8 *pparm); 
extern u8 WL2BTMailbox(IN  PADAPTER padapter,IN u8 cmd, IN u8 length, IN u8 *pparm); //#pragma disable  
extern void H2CHDL_BTPSTDMA(IN PADAPTER padapter,IN u8 *pbuf); //#pragma disable  
extern void H2CHDL_BTInfo(IN PADAPTER padapter,IN u8 *pbuf); 
extern void H2CHDL_ForceBTTxpwr(IN PADAPTER padapter,IN u8 *pbuf); 
extern void H2CHDL_BTIgnoreWlanAct(IN PADAPTER padapter,IN u8 *pbuf); 
extern void H2CHDL_DACSwingValue(IN PADAPTER padapter,IN u8 *pbuf); 
extern void H2CHDL_AntSelReverse(IN PADAPTER padapter,IN u8 *pbuf); 
extern void H2CHDL_WLOpmode(IN PADAPTER padapter,IN u8 *pbuf); 
extern void H2CHDL_BTMpH2C(IN PADAPTER padapter,IN u8 *pbuf); //#pragma disable  
extern void H2CHDL_BTControl(IN PADAPTER padapter,IN u8 *pbuf); //#pragma disable  
extern void H2CHDL_BTWifiCtrl(IN PADAPTER padapter,IN u8 *pbuf); 
extern void H2CHDL_BT_SCO_eSCO_Operation(IN PADAPTER padapter,IN u8 *pbuf); 
extern void H2CHDL_BT_Page_Scan_Interval(IN PADAPTER padapter,IN u8 *pbuf); 
extern void H2CHDL_WLCalibration(IN PADAPTER padapter,IN u8 *pbuf); 
extern void H2CHDL_GNT_BT_CTRL(IN PADAPTER padapter,IN u8 *pbuf); 
extern void H2CHDL_BT_ONLY_TEST(IN PADAPTER padapter,IN u8 *pbuf); 
extern void H2CHDL_BT_Init_Param(IN PADAPTER padapter,IN u8 *pbuf); 
#if !TASK_SCHEDULER_DISABLED
#ifdef CONFIG_BT_MAILBOX
void C2HInQueue(IN PADAPTER    padapter, PC2H_EVT_HDR_H pc2h_hdr);
#endif
#endif // !TASK_SCHEDULER_DISABLED

#endif //#ifdef CONFIG_BT_MAILBOX




#endif  //CONFIG_LITTLE_WIFI_MCU_FUNCTION_THREAD
#endif  //__RTL8195A_PMU_TASK_H__

