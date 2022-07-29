#ifndef __ODM_RATEADAPTIVE_JGR3_RAM_H__
#define __ODM_RATEADAPTIVE_JGR3_RAM_H__

/*--------------------Define -------------------------------------------*/

#define DIFF(A,B) ((A>=B) ? (A-B):(B-A))
#define SHIFT_ROUND(A, SHIFT)  ((A + (1 << (SHIFT-1)))>>SHIFT)
#define MA_ADD(NEW, OLD, SHIFT) (NEW + OLD - (OLD>>SHIFT))
#define MINUS(A,B) ((A > B) ? (A-B) : 0)
#define PHYRATE_LGI2SGI(rate) (rate + (rate >> 4) + (rate >> 5) + (rate >> 7)) //1+0.0625+0.03125+0.0078125 ~= 0.102
#define PHYDM_IS_LEGACY_RATE(rate) ((rate <= RATE_OFDM_54M) ? true : false)
#define PHYDM_IS_CCK_RATE(rate) ((rate <= RATE_CCK_11M) ? true : false)

#define FIRST_MACID 0

#define RA_BW_MULTI_TRY_MODE    1
#define COMMON_RATE_DOWN_OFFSET 3
#define LIMIT_RATE_SIZE         2
#define RAMSK_HT_VHT_OFFSET     32

//---C2H DBG----------
#define RATE_DEFAULT	0
#define RATE_UP			1
#define RATE_DOWN		2

#define CLEAN_ENV_VAR_TH    2
#define GOOD_PER_TH         10
#define DEC_OFFSET_MAX_N    40

//4  MACID_CFG H2C CMD
//offset0
#define H2CID40_MACID                   0xFF
//offset1
#define H2CID40_RATEID                  0x1F
#define H2CID40_RSSI_LEVEL           (BIT6|BIT5)
#define H2CID40_SGI                     BIT7
//offset2
#define H2CID40_BW                      (BIT0|BIT1)
#define H2CID40_enldpc                  BIT2
#define H2CID40_NOUPDATE                BIT3
#define H2CID40_VHT_EN                  (BIT5|BIT4)
#define H2CID40_DISPT                   BIT6
#define H2CID40_DISRA                   BIT7

//4  TxCtrlInfo
// offset0
#define TXCTRLINFO_DATA_RATE            (BIT6|BIT5|BIT4|BIT3|BIT2|BIT1|BIT0)
#define TXCTRLINFO_SGI                  (BIT7)
// offset1
#define TXCTRLINFO_PWR_STS              (BIT2|BIT1|BIT0)
#define TXCTRLINFO_DATA_BW              (BIT4|BIT3)
#define TXCTRLINFO_TRY_RATE             (BIT6)
// offset2

// offset 6
#define DARFC_RC_IDX                    (BIT1 | BIT0)

//4 MACID_CFG_3SS H2C CMD
//offset 0
#define H2CID46_MACID                   0xFF

//4 AP_Req_Tx_Rpt H2C CMD
#define H2CID43_RTY_OK_TOTAL            BIT0
#define H2CID43_RTY_CNT_MACID           BIT1

/*----------------------------------------------------------*/

#define RATE_UNUSED                     0xff
#define BW_NO_UPDATE                    0xff
#define RAMASK_SIZE                     2

// -------- PARA RA ------------
#define RATE_TYPE_NUM_U8    9
#define FAST_DECISION_TRUE  1
#define FAST_DECISION_FALSE 0

#define DROP_TH             3
#define RA_ALGO_DBG_REG     0x453

// packet based RA
#define RATIO_CNT_TH            3
#define RATIO_SHIFT_SGI         1
#define TRY_SUCCESS_RATIO_SHIFT 5
#define RATE_UP_CNT             3
#define RATE_UP_FAIL_CNT_LMT    50
#define RATE_DOWN_CNT           2
#define RATE_DOWN_RATIO_TH      30
#define FORCE_RATE_DOWN_TH      80
#define RSSI_TOLERANCE          2
#define MULTI_RATE_NUM          2 /*MULTI_TRY_NUM after first try rate, will try 1+2 times */
#define SMOOTHING_FACTOR        3
#define RETRY_RATIO_VAR_SIZE    10
#define DIFF2VAR_SHIFT          10
#define RETRY_RATIO_VAR_MAX     30

//RAInfo
#define MASK_RA_ULDL_STATE              BIT0
#define MASK_RA_STBC_STATE              BIT1
#define MASK_RA_NOISY_STATE             BIT2
#define MASK_RA_CHANGE_RATE_STATE       BIT3
#define MASK_RA_NO_USE_2                BIT4
#define MASK_RA_INIT_RATE_RSSI_STATE    BIT5
#define MASK_RA_BF_STATE                BIT6
#define MASK_RA_IGNORE_DROP             BIT7

#define RA_ULDL_STATE_SHT               0
#define RA_STBC_STATE_SHT               1
//#define RA_LDPC_CAP_STATE_SHT         2
//#define RA_SHORTCUT_STATE_SHT         3
//#define RA_SHORTCUT_FLAG_SHT          4
#define RA_INIT_RATE_RSSI_SHT           5
#define RA_BF_STATE_SHT                 6
//#define RA_DELAY_RATE_SHT             7

#define TRYING_DISABLE   0
#define TRYING_ENABLE    1

#define TRY_SUCCESS      1
#define TRY_FAIL         0

#define DTP_CANDIDATE_NUM       3

#define PHYDM_A     BIT0
#define PHYDM_B     BIT1
#define PHYDM_C     BIT2
#define PHYDM_D     BIT3
#define PHYDM_AB    (BIT0 | BIT1)  // 0
#define PHYDM_AC    (BIT0 | BIT2)  // 1
#define PHYDM_AD    (BIT0 | BIT3)  // 2
#define PHYDM_BC    (BIT1 | BIT2)  // 3
#define PHYDM_BD    (BIT1 | BIT3)  // 4
#define PHYDM_CD    (BIT2 | BIT3)  // 5
#define PHYDM_ABC   (BIT0 | BIT1 | BIT2) // 0
#define PHYDM_ABD   (BIT0 | BIT1 | BIT3) // 1
#define PHYDM_ACD   (BIT0 | BIT2 | BIT3) // 2
#define PHYDM_BCD   (BIT1 | BIT2 | BIT3) // 3
#define PHYDM_ABCD  (BIT0 | BIT1 | BIT2 | BIT3)

// BF-Ctrl
#define Mask_TxBF_Nc_STATE          (BIT0 | BIT1 )
#define Mask_TxBF_BW_STATE          (BIT2 | BIT3)
#define Mask_TxBF_Entry_STATE       (BIT4 | BIT5 | BIT6)
#define Mask_TxBF_CaseEnable_STATE   BIT7
#define TxBF_Nc_SHT             0
#define TxBF_BW_SHT             2
#define TxBF_Entry_SHT          4
#define TxBF_CaseEnable_SHT     7

// ------------------ Debug Define ------------------- //

#define START_RATE_RSSI_LV1 55
#define START_RATE_RSSI_LV2 35
#define START_RATE_RSSI_LV3 20

#define RATE_SET_CCK_0      0x0000000f
#define RATE_SET_CCK_1      0x0
#define RATE_SET_CCK_2      0x0
#define RATE_SET_OFDM_0     0x00000ff0
#define RATE_SET_OFDM_1     0x0
#define RATE_SET_OFDM_2     0x0
#define RATE_SET_1SS_0      0x000ff000
#define RATE_SET_1SS_1      0x003ff000
#define RATE_SET_1SS_2      0x0
#define RATE_SET_2SS_0      0x0ff00000
#define RATE_SET_2SS_1      0xffc00000
#define RATE_SET_2SS_2      0x0
#define RATE_SET_3SS_0      0xf0000000
#define RATE_SET_3SS_1      0x0000000f
#define RATE_SET_3SS_2      0x003ff
#define RATE_SET_4SS_0      0x0
#define RATE_SET_4SS_1      0x00000ff0
#define RATE_SET_4SS_2      0xffc00
#define RATE_SET_16QAM_0    0x81818180
#define RATE_SET_16QAM_1    0x06018181
#define RATE_SET_16QAM_2    0x06018
#define RATE_SET_64QAM_0    0x0e0e0e00
#define RATE_SET_64QAM_1    0x380e0e0e
#define RATE_SET_64QAM_2    0x380e0
#define RATE_SET_256QAM_0   0x0
#define RATE_SET_256QAM_1   0xc0300000
#define RATE_SET_256QAM_2   0xc0300


// -------- PARA MU RA ------------
#define MU_ratio_shift_256Q      2
#define MU_ratio_shift_64Q        5
#define MU_ratio_shift                  6
#define MU_try_shift                     4
#define MU_LOWEST_RATE              RATE_VHT1SS_MCS2
#define MU_SU_rate_diff             2
#define MU_SU_rate_diff_TH             3
#define REG_MU_Switch               0x19E2
#define REG_MU_Group_OK         0xF4C
#define MUDisableTime               50 // 1~127

/*--------------------Define MACRO--------------------------------------*/
typedef enum _Phydm_ra_dbg_para {
	RTY_PENALTY_IDX         = 1,  //u8
	N_HIGH_IDX              = 2,
	N_LOW_IDX               = 3,
	RATE_UP_TABLE_IDX       = 4,
	RATE_DOWN_TABLE_IDX     = 5,
	TRYING_NECESSARY_IDX    = 6,
	DROPING_NECESSARY_IDX   = 7,
	RATE_UP_RTY_RATIO_IDX   = 8, //u8
	RATE_DOWN_RTY_RATIO_IDX = 9, //u8
	PRINT_TEST              = 10,

	RA_DEBUG_MONITOR1       = 12,
	RA_DEBUG_MONITOR2       = 13,
	RA_DEBUG_MONITOR3       = 14,
	RA_DEBUG_MONITOR4       = 15,
	RA_DEBUG_MONITOR5       = 16,
	NUM_RA_PARA
} PHYDM_RA_DBG_PARA_E;

typedef enum _VHT_HT_SWITCH_ {
	TYPE_HT             = 0,
	TYPE_VHT            = 1,
	TYPE_MIX1           = 2,
	TYPE_MIX2           = 3

} VHT_SEL_SWITCH, *PVHT_SEL_SWITCH;

typedef enum _BW_TYPE_ {
	TYPE_BW_20M         = 0,
	TYPE_BW_40M         = 1,
	TYPE_BW_80M         = 2,
	TYPE_BW_160M        = 3

} BW_TYPE, *PBW_TYPE;

typedef enum _RTL8195_RATEID_IDX_ {
	MODE_BGN_40M_2SS    = 0,
	MODE_BGN_40M_1SS    = 1,
	MODE_BGN_20M_2SS_BN = 2,
	MODE_BGN_20M_1SS_BN = 3,
	MODE_GN_N2SS        = 4,
	MODE_GN_N1SS        = 5,
	MODE_BG             = 6,
	MODE_G              = 7,
	MODE_B              = 8,
	MODE_ARFR0          = 9,
	MODE_ARFR1          = 10,
	MODE_ARFR2          = 11,
	MODE_ARFR3          = 12,
	MODE_ARFR4          = 13,
	MODE_ARFR5          = 14
} RTL8195_RATEID_IDX, *PRTL8195_RATEID_IDX;

typedef enum _DEBUG_MONITOR_TYPE_ {
	TYPE_RAINFO         = 0,
	TYPE_TXCTRL         = 1,
	TYPE_RASTS          = 2,
	TYPE_RA_CNT         = 3,
	TYPE_MULTI_TRY_STS  = 4
} DEBUG_MONITOR_TYPE, *PDEBUG_MONITOR_TYPE;

/*--------------------Define Struct-------------------------------------*/


typedef struct dynamic_path_selection {
	u8 DTP_candidate[DTP_CANDIDATE_NUM];
	u8 num_DTP_candidate;
	u8 num_TX_Path;
	u8 DTP_state;
	BOOLEAN TX_PathTraining_en;
} PHYDM_DTP_T, *PPHYDM_DTP_T;

typedef struct phydm_rate_adaptive {
	u8 RATE_UP_RTY_RATIO[RATESIZE];
	u8 RATE_DOWN_RTY_RATIO[RATESIZE];
	u8 first_rate_down; /*ARFB first rate down number ex: Reg0x430=00000001, first_try_rate_down = 4*/
	u8 first_try_rate_down; /*ARFB first rate down number ex: Reg0x430=01020304, first_try_rate_down = 2*/
	u16 retry_ratio_per_rate_ma[RATESIZE];
	u16 variance_per_rate[RATESIZE];
	u8 DIFF2VAR_TABLE[RETRY_RATIO_VAR_SIZE];
	u8 rpt_per_macid[3];
} PHYDM_RA_T, *PPHYDM_RA_T;

typedef struct phydm_debug {
	u8 c2h_seq;
	u8 fw_trace_en;
	u8 monitor_mode;
	u8 macid;
	u8 bPER_RA: 1;
	u8 bMTRY_RA: 1;
	u8 bFIX_RATE: 1;
	u8 rsvd0: 5;
	u8 dbgmacid;
	u8 dbgmodeRA;
} PHY_FWDBG_PARM, *PPHY_FWDBG_PARM;

typedef struct  phydm_rate_adaptive_ram {
	u8 rpt_per_macid[3];
} PHYDM_RA_RAM, *PPHYDM_RA_RAM;

typedef struct  stainfo_rate_adaptive {
	u8 highest_rate;
	u8 lowest_rate;
	u8 rate;         /*curretn rate*/
	u8 pre_rate;     /*pre rate*/
	u8 multi_rate[MULTI_RATE_NUM]; /*multi_rate[0]: 2nd rate, multi_rate[1]: 3rd rate*/
	u8 max_start_rate;

	u8 Initial_BW: 2; /*max support bw*/
	u8 BW_setting: 2; /*current bw */
	u8 pre_bw: 2;    /*pre bw */
	u8 rsvd1: 2;

	u8 RateID: 5;
	u8 DISPT: 1;
	u8 DISRA: 1;
	u8 ra_info_ignore_drop: 1;

	u8 multi_rate_state_idx: 2;
	u8 updown_bitmap: 4;

	u8 rate_down_cnt: 4;
	u8 rate_up_cnt: 4;

	u8 try_fail_cnt: 4; /*Just for debug*/
	u8 rate_up_down: 4;

	u8 VHT_EN: 2;
	u8 SGI: 1;
	u8 multi_rate_state: 2;
	u8 try_fail_count: 2;
	u8 trying_enable: 1;

	u8  mu_support: 1;
	u8  mu_not_support_256Q: 1;
	u8  HRateUseSGI: 1;
	u8  mu_rsvd0: 5;
	u8  mu_rsvd1;

	u8 mode_ss: 4; /*for power training*/
	u8 MAX_SS_SUPPORT: 2;
	u8 bForcePktRA: 1;
	u8 rsvd2: 1;

	u8 try_ness;
	u8 try_ness_max;
	u8 try_pkt_cnt_success;
	u8 try_pkt_cnt_fail;
	u16 ra_ratio;       /*MA vlaue of ra_ratio*/
	u16 ra_down_ratio;  /*MA vlaue of ra_down_ratio*/
	u8 RSSI;
	u8 Stage_RA;

// ============= RA ctrl info ============== //
	u8 RAINFO_RX_STATE: 1;
	u8 RAINFO_STBC_STATE: 1;
	u8 RAINFO_LDPC_STATE: 1;
	u8 ra_info_rsvd0: 2; // instead of SHORT_CUT
	u8 bFirstConnect: 1;;
	u8 TxBF_STATE: 1;
	u8 ra_info_rsvd1: 1;
// ======================================== //

	u8 DTP_Utility[3];
	u8 per_shift;

	u8 pre_rty_idx: 5;
	u8 Rate_Support_Type: 3; /*0:legacy, 1:1SS, 2:2SS, 3:3SS, 4:4SS*/

	u8 pre_rate_up_cnt_th;
	u8 up_fail_limit_rate[LIMIT_RATE_SIZE]; /*for 1SS & 2ss rate*/
	u8 up_fail_limit_cnt[LIMIT_RATE_SIZE];
	u8 ra_decision_occur_num;
	u8 multi_bw[MULTI_RATE_NUM]; /*multi_bw[0]: 2nd rate, multi_bw[1]: 3rd rate*/
	u8 trig_ra_pkt_num; /*make ra decision when collect enough(trig_ra_pkt_num) pachets*/
	u16 Pkt_cnt;
	u16 total_cnt_rpt;
	u8 trigger_mode; /*0: default pkt based RA, 1: TBTT based RA*/
} STAINFO_RA, *PSTAINFO_RA;

#if CONFIG_POWER_TRAINING
typedef  struct _POW_TRAN_FUNC_ { /*the 4-th layer*/
	/* PT use original MACID_NUM*/
	PT_Stats            pt_stats[MACID_NUM];

} PW_TRAN_FUNC, *P_PW_TRAN_FUNC;
#endif


typedef  struct _RA_ADP_FUNC_ { /*the 4-th layer*/

	STAINFO_RA              stainfo_ra[RA_MACID_NUM];
	PHYDM_RA_T             RA;
	PHY_FWDBG_PARM    Phy_fwdbgParm;
	TxRpt_Info                 TxRptInfo;


	TxRpt_Cfg              TxRptCfg;
	u8		RaMask[RA_MACID_NUM][8];
} RA_ADP_FUNC, *PRA_ADP_FUNC;

struct _ODM { /*the 3-rd layer*/

	PHYDM_FUNC            Phydm;

#if CONFIG_RATE_ADAPTIVE
	RA_ADP_FUNC           Ra_adp;
#endif

#if CONFIG_POWER_TRAINING
	PW_TRAN_FUNC        Pow_tran;
#endif

};
/*--------------------Define Prototype-------------------------------------*/

extern void
phydm_querry_ra_version(
	IN u8 *pversion,
	IN u8 *psub_version
);

extern u8
phydm_read_ctrl_info_rate_jgr3(
	IN u8 macid
);

extern u8
phydm_read_ctrl_info_bw_jgr3(
	IN u8 macid
);

extern void
phydm_txbf_sounddone(
	u8 sounding_result
);

extern void
phydm_store_bfctrl(
	IN  u8 entry_idx,
	IN  u8 BFBW
);

extern void
phydm_initialrate_update(
	IN u8 macid,
	IN u8 rate,
	IN u8 trybit,
	IN u8 bw_idx
);

extern  void
phydm_H2C_RA_dbg_monitor(
	void
);

extern void
phydm_start_rate_by_rssi(
	IN u8 macid,
	IN u8 start_rssi,
	IN u8 bw_idx
);

extern void
ODM_RlsRateUpLmtByRssi(
	IN u8   macid,
	IN u8   rssi_pre,
	IN u8   rssi,
	IN u8   forceReset
);

extern  void
phydm_try_result_decision(
	IN u8 macid
);

extern void
phydm_pkt_based_rate_decision_jgr3(
	IN u8 macid
);

extern void
phydm_ratedecision(
	void
);

extern void
phydm_arfrrefresh(
	IN u8 macid
);

extern void
phydm_init_rainfo(
	void
);

#endif

