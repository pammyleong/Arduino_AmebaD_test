#ifndef __ODM_RAM_H__
#define __ODM_RAM_H__

/*-------------------- Define logic and bitwise operation  ---------------*/

#define MAX_2(_x_, _y_)	(((_x_) > (_y_)) ? (_x_) : (_y_))
#define MIN_2(_x_, _y_)	(((_x_) < (_y_)) ? (_x_) : (_y_))
#define DIFF_2(_x_, _y_)	((_x_ >= _y_) ? (_x_ - _y_) : (_y_ - _x_))

#define IS_GREATER(_x_, _y_)	(((_x_) >= (_y_)) ? _TRUE : _FALSE)
#define IS_LESS(_x_, _y_)	(((_x_) < (_y_)) ? _TRUE : _FALSE)

#define BYTE_DUPLICATE_2_DWORD(B0)	\
	(((B0) << 24) | ((B0) << 16) | ((B0) << 8) | (B0))

#define BYTE_2_DWORD(B3, B2, B1, B0)	\
	(((B3) << 24) | ((B2) << 16) | ((B1) << 8) | (B0))
#define BIT_2_BYTE(B3, B2, B1, B0)	\
	(((B3) << 3) | ((B2) << 2) | ((B1) << 1) | (B0))

#define HALRF_ABS(a,b) ((a>b) ? (a-b) : (b-a))

/*-------------------- Define Variables ----------------------------------*/

#define RATESIZE                   84
#define NUM_VHT_RATE               20
#define NUM_HT_RATE                16
#define NUM_MULTI_TRY               1
#define CONFIG_3SS                  0
#define CONFIG_2SS                  0
#define CONFIG_1SS                  1
#define GIDNUM_U1                  30

/*--------------------Define Enum---------------------------------------*/
/*typedef enum _rate_table_ {
    RATE_CCK_1M        = 0x00,
    RATE_CCK_2M        = 0x01,
    RATE_CCK_5M        = 0x02,
    RATE_CCK_11M      = 0x03,
    RATE_OFDM_6M       = 0x04,
    RATE_OFDM_9M       = 0x05,
    RATE_OFDM_12M      = 0x06,
    RATE_OFDM_18M      = 0x07,
    RATE_OFDM_24M      = 0x08,
    RATE_OFDM_36M      = 0x09,
    RATE_OFDM_48M      = 0x0A,
    RATE_OFDM_54M      = 0x0B,
    RATE_HT_MCS0       = 0x0C,
    RATE_HT_MCS1       = 0x0D,
    RATE_HT_MCS2       = 0x0E,
    RATE_HT_MCS3       = 0x0F,
    RATE_HT_MCS4       = 0x10,
    RATE_HT_MCS5       = 0x11,
    RATE_HT_MCS6       = 0x12,
    RATE_HT_MCS7       = 0x13,
    RATE_HT_MCS8       = 0x14,
    RATE_HT_MCS9       = 0x15,
    RATE_HT_MCS10      = 0x16,
    RATE_HT_MCS11      = 0x17,
    RATE_HT_MCS12      = 0x18,
    RATE_HT_MCS13      = 0x19,
    RATE_HT_MCS14      = 0x1A,
    RATE_HT_MCS15      = 0x1B,
    RATE_HT_MCS16      = 0x1C,
    RATE_HT_MCS17      = 0x1D,
    RATE_HT_MCS18      = 0x1E,
    RATE_HT_MCS19      = 0x1F,
    RATE_HT_MCS20      = 0x20,
    RATE_HT_MCS21      = 0x21,
    RATE_HT_MCS22      = 0x22,
    RATE_HT_MCS23      = 0x23,
    RATE_HT_MCS24      = 0x24,
    RATE_HT_MCS25      = 0x25,
    RATE_HT_MCS26      = 0x26,
    RATE_HT_MCS27      = 0x27,
    RATE_HT_MCS28      = 0x28,
    RATE_HT_MCS29      = 0x29,
    RATE_HT_MCS30      = 0x2A,
    RATE_HT_MCS31      = 0x2B,
    RATE_VHT1SS_MCS0   = 0x2C,
    RATE_VHT1SS_MCS1   = 0x2D,
    RATE_VHT1SS_MCS2   = 0x2E,
    RATE_VHT1SS_MCS3   = 0x2F,
    RATE_VHT1SS_MCS4   = 0x30,
    RATE_VHT1SS_MCS5   = 0x31,
    RATE_VHT1SS_MCS6   = 0x32,
    RATE_VHT1SS_MCS7   = 0x33,
    RATE_VHT1SS_MCS8   = 0x34,
    RATE_VHT1SS_MCS9   = 0x35,
    RATE_VHT2SS_MCS0   = 0x36,
    RATE_VHT2SS_MCS1   = 0x37,
    RATE_VHT2SS_MCS2   = 0x38,
    RATE_VHT2SS_MCS3   = 0x39,
    RATE_VHT2SS_MCS4   = 0x3A,
    RATE_VHT2SS_MCS5   = 0x3B,
    RATE_VHT2SS_MCS6   = 0x3C,
    RATE_VHT2SS_MCS7   = 0x3D,
    RATE_VHT2SS_MCS8   = 0x3E,
    RATE_VHT2SS_MCS9   = 0x3F,
    RATE_VHT3SS_MCS0   = 0x40,
    RATE_VHT3SS_MCS1   = 0x41,
    RATE_VHT3SS_MCS2   = 0x42,
    RATE_VHT3SS_MCS3   = 0x43,
    RATE_VHT3SS_MCS4   = 0x44,
    RATE_VHT3SS_MCS5   = 0x45,
    RATE_VHT3SS_MCS6   = 0x46,
    RATE_VHT3SS_MCS7   = 0x47,
    RATE_VHT3SS_MCS8   = 0x48,
    RATE_VHT3SS_MCS9   = 0x49,
    RATE_VHT4SS_MCS0   = 0x4A,
    RATE_VHT4SS_MCS1   = 0x4B,
    RATE_VHT4SS_MCS2   = 0x4C,
    RATE_VHT4SS_MCS3   = 0x4D,
    RATE_VHT4SS_MCS4   = 0x4E,
    RATE_VHT4SS_MCS5   = 0x4F,
    RATE_VHT4SS_MCS6   = 0x50,
    RATE_VHT4SS_MCS7   = 0x51,
    RATE_VHT4SS_MCS8   = 0x52,
    RATE_VHT4SS_MCS9   = 0x53,
}rate_table;*/

typedef enum _odm_cmninfo_e_ {
	ODM_CMNINFO_PLATFORM = 0,
	ODM_CMNINFO_RF_TYPE,
	ODM_CMNINFO_BOARD_TYPE,
	ODM_CMNINFO_PACKAGE_TYPE,
	ODM_CMNINFO_EXT_LNA,
	ODM_CMNINFO_5G_EXT_LNA,
	ODM_CMNINFO_EXT_PA,
	ODM_CMNINFO_5G_EXT_PA,
	ODM_CMNINFO_GPA,
	ODM_CMNINFO_APA,
	ODM_CMNINFO_GLNA,
	ODM_CMNINFO_ALNA,
	ODM_CMNINFO_EXT_TRSW,

} odm_cmninfo_e;

#define BW20M   0x0
#define BW40M   0x100
#define BW80M   0x200
#define BW160M  0x300

typedef enum _odm_ability_e_ {

	ODM_BB_DIG                    = BIT(0),
	ODM_BB_RA_MASK            = BIT(1),
	ODM_BB_DYNAMIC_TXPWR        = BIT(2),
	ODM_BB_FA_CNT                = BIT(3),
	ODM_BB_RSSI_MONITOR        = BIT(4),
	ODM_BB_CCK_PD                = BIT(5),
	ODM_BB_ANT_DIV                = BIT(6),
	ODM_BB_SMT_ANT            = BIT(7),
	ODM_BB_PWR_TRAIN            = BIT(8),
	ODM_BB_RATE_ADAPTIVE        = BIT(9),
	ODM_BB_PATH_DIV            = BIT(10),
	/*BIT(11),*/
	/*BIT(12),*/
	ODM_BB_ADAPTIVITY            = BIT(13),
	ODM_BB_CFO_TRACKING        = BIT(14),
	ODM_BB_CCX_MONITOR        = BIT(15),
	ODM_BB_PRIMARY_CCA        = BIT(16),
	ODM_BB_DYNAMIC_ARFR        = BIT(18),
	ODM_BB_DYNAMIC_PSDTOOL    = BIT(19),
	ODM_BB_DYNAMIC_RX_PATH    = BIT(21),
	ODM_BB_ADAPTIVE_SOML        = BIT(23),
} odm_ability_e;

typedef enum _phydm_bb_op_mode_ {
	PHYDM_PERFORMANCE_MODE = 0,    /*Service one device*/
	PHYDM_BALANCE_MODE = 1,        /*Service more than one device*/
} phydm_bb_op_mode;

/*--------------------Define MACRO--------------------------------------*/

#define _reg_11N(_name)            ODM_REG_##_name##_11N
#define _reg_11AC(_name)        ODM_REG_##_name##_11AC
#define _bit_11N(_name)            ODM_BIT_##_name##_11N
#define _bit_11AC(_name)        ODM_BIT_##_name##_11AC

#define _cat(_name, _ic_type, _func)      (((_ic_type)) ? _func##_11N(_name) : 0)

#define ODM_REG(_name, _pdm_odm)    _cat(_name, _pdm_odm->support_ic_type, _reg)
#define ODM_BIT(_name, _pdm_odm)    _cat(_name, _pdm_odm->support_ic_type, _bit)

/*--------------------Define IQK--------------------------------------*/


#define 	MAC_REG_NUM 3
#define 	BB_REG_NUM 11
#define 	RF_REG_NUM 3
#define		SS 1
#define 	IQK_STEP_8723F 6
#define 	RXK_STEP_8723F 6
#define		IQK_CMD_8723F 0x8
#define		Reload_ch 0x2

#define ODM_IQK_Offload ODM_IQK_Offload_8723F
#define ODM_DO_DPK      do_dpk_8723f


#define TX_IQK 0
#define RX_IQK 1
#define TXIQK 0
#define RXIQK1 1
#define RXIQK2 2
#define kcount_limit_80m 2
#define kcount_limit_others 4
#define rxiqk_gs_limit 10

/*--------------------Define DPK--------------------------------------*/
#define GAIN_LOSS 1
#define DO_DPK 2
#define DPK_ON 3
#define DAGC 4
#define LOSS_CHK 0
#define GAIN_CHK 1
#define PAS_READ 2
#define AVG_THERMAL_NUM 8
#define AVG_THERMAL_NUM_DPK 8
#define THERMAL_DPK_AVG_NUM 4
#define ODM_DPK_DATA_SIZE 19

/*--------------------Define Struct-------------------------------------*/
typedef struct _DBG_PARM_ {
	//ODM Write,debug info
	s1Byte                  RxSNRdB[4];
	u4Byte              NumQryPhyStatus;
	u4Byte              NumQryPhyStatusCCK;
	u4Byte              NumQryPhyStatusOFDM;
	u4Byte              NumQryMuPkt;
	u4Byte              NumQryBfPkt;
	u1Byte              NumQryBeaconPkt;
	//Others
	s4Byte                  RxEVM[4];

} DBG_PARM, *PDBG_PARM;

typedef struct _PHY_INFO_PARM_ {
	//
	// Be care, if you want to add any element please insert between
	// RxPWDBAll & SignalStrength.
	//
	u1Byte        RxPWDBAll;
	u1Byte        SignalQuality;                /* in 0-100 index. */
	s1Byte        RxMIMOSignalQuality[4];        /* per-path's EVM */
	u1Byte        RxMIMOEVMdbm[4];            /* per-path's EVM dbm */
	u1Byte        RxMIMOSignalStrength[4];    /* in 0~100 index */
	s2Byte        Cfo_short[4];                /* per-path's Cfo_short */
	s2Byte        Cfo_tail[4];                    /* per-path's Cfo_tail */
	s1Byte        RxPower;                    /* in dBm Translate from PWdB */
	s1Byte
	RecvSignalPower;            /* Real power in dBm for this packet, no beautification and aggregation. Keep this raw info to be used for the other procedures. */
	u1Byte        BTRxRSSIPercentage;
//u1Byte        SignalStrength;                /* in 0-100 index. */
	s1Byte        RxPwr[4];                    /* per-path's pwdb */
	s1Byte        RxSNR[4];                    /* per-path's SNR    */
	u1Byte        RxCount: 2;                   /* RX path counter---*/
	u1Byte        BandWidth: 2;
	u1Byte        rxsc: 4;                       /* sub-channel---*/
	u1Byte        btCoexPwrAdjust;
	u1Byte        channel;                        /* channel number---*/
	BOOLEAN        bMuPacket;                    /* is MU packet or not---*/
	BOOLEAN        bBeamformed;                /* BF packet---*/
} PHY_INFO_PARM, *PPHY_INFO_PARM;

typedef struct _ODM_Per_Pkt_Info_ {
	//u1Byte        Rate;
	u1Byte        DataRate;
	u1Byte        macid;
	BOOLEAN        bPacketMatchBSSID;
	BOOLEAN        bPacketToSelf;
	BOOLEAN        bPacketBeacon;
	BOOLEAN        bToSelf;
} ODM_PACKET_INFO_T, *PODM_PACKET_INFO_T;

typedef struct _STA_INFO_PARM_ {
	s4Byte  UndecoratedSmoothedPWDB;
} STA_INFO_PARM, *PSTA_INFO_PARM;

typedef struct  _TxBFEntry_PARM_ {
	u8  macid[2];
	u8  BFNc[2];
	u8  RestoreBFCtrl[2];
	u8  CtrlApplyV; // Bit0~1 for Entry 0~1
	u8  SoundingResult; // Bit0~1 for Entry 0~1
	u8  CtrlErrNc;  // Bit0~1 for Entry 0~1
	u8  case_enable;

} TxBFEntry_PARM, *PTxBFEntry_PARM;


#if 1//CONFIG_MU_RA_SUPPORT
typedef struct  _MURA_PARM_ {
	u8  entry_macid[6];
	u8  macid_u0[30];
	u8  macid_u1[30];
	//u8  rate_u0[30];
	//u8  rate_u1[30];
	u8  dbg_gid;
	u8  dbg_user_position;
	u8  dbg_total_num;
	u8  dbg_ok_num;
	u8  dbg_drop_num;
	u8  dbg_down_sample;
	u8  dbg_trxpt_cnt;
	u8  disable_mu: 1;
	u8  disable_mu_time: 7;
	u32  MU2SU_cnt;
	u32  MU_pkt_cnt;
} MURA_PARM, *PMURA_PARM;


typedef struct mu_info_8814b {
// --------------- u32 -1
	u8 musta_macid[4];
	u8 Nc_num[4];
// --------------- u32 -2/3/4/5/6
	u8 buf_ok_cnt[4];
	u8 buf_total_cnt[4];
	u8 buf_r4_cnt[4];
	u8 buf_drop_cnt[4];
	u8 buf_rty_idx[4];
	u8 buf_init_rate[4];
// --------------- u32 -7
	u8 buf_pri_user: 2;
	u8 buf_user_cnt: 2;
	u8 buf_rsvd0: 4;
//----//
	u8 gpmap: 4;
	u8 txrpt_musts: 1;
	u8 rsvd1: 3;

// -------- DeGen ----------
	u8 mu_degen_sts[4];
	u8 mu_degen_sts_pre[4];
	u8 degen_highest_rate_tmp[76];
//-------------u32 -BIT15 16
	u32 mu_mac_score[4]; //4bit for one group
	u16 mu_driver_score[4]; //2bit for one group
	u8 mu_h2c_score[4];
} PHYDM_MU_INFO_8814B, *PPHYDM_MU_INFO_8814B;


typedef struct _MU_STAINFO_PARM_ {
	u8  MU_drop_cnt;
	u8  trying_enable: 1;
	u8  mu_rsvd: 7;
	u32 MU_total_pkt_cnt;
	u32 MU_rty_pkt_cnt;
	u32 MU_R4_pkt_cnt;

} MU_STAINFO_PARM, *PMU_STAINFO_PARM;

#endif

struct phydm_dig_struct {
	/*    u8        rf_gain_idx;*/
	u8        agc_table_idx;
	/*    u8        big_jump_lmt[16];*/
	/*    u8        enable_adjust_big_jump:1;*/
	/*    u8        big_jump_step1:3;*/
	/*    u8        big_jump_step2:2;*/
	/*    u8        big_jump_step3:2;*/
};



struct phydm_physts {
	u8			cck_gi_u_bnd;
	u8			cck_gi_l_bnd;
};

struct dm_dpk_info {

	BOOLEAN	is_dpk_enable;
	BOOLEAN	is_dpk_pwr_on;
	BOOLEAN	is_dpk_by_channel;
	BOOLEAN is_tssi_mode;
	u8	dpk_status;			/*bit[0]:reload;bit[1]:cal;bit[2]:cal_ok*/
	u16 	dpk_path_ok;
	/*@BIT(15)~BIT(12) : 5G reserved, BIT(11)~BIT(8) 5G_S3~5G_S0*/
	/*@BIT(7)~BIT(4) : 2G reserved, BIT(3)~BIT(0) 2G_S3~2G_S0*/
	u8	thermal_dpk[2][4];				/*channel/path*/
	u8	thermal_dpk_avg[4][AVG_THERMAL_NUM_DPK];	/*path*/
	u8	pre_pwsf[4];
	u8	thermal_dpk_avg_index;
	u32	gnt_control;
	u32	gnt_value;
	u8	dpk_ch;
	u8	dpk_band;
	u8	dpk_bw;
	u32	dpk_rf18[2];
	u8	thermal_dpk_delta[2][2];	/*channel/path*/

	u8	result[2];
	u8	dpk_txagc[2][2];		/*channel/path*/
	u32	coef[2][2][20];			/*channel/path/MDPD coefficient*/
	u16	dpk_gs[2][2];			/*channel/MDPD coef gs*/

	u32	reg_1b08;
};

typedef    struct _COMMON_PARM_ {

	u32    support_ic_type;    /*PHYDM supported IC*/
	u64    support_ability;    /*PHYDM function Supportability*/
	u32    debug_components;
	u32    debug_level;
	u8      RXAntStatus;
	u8      rf_type;
	u8      bDisablePhyApi;
	u8      mp_mode_hook_val;
	u8      RSSI_A;
	u8      RSSI_B;
	u8      RSSI_C;
	u8      RSSI_D;
	u8      pre_rssi_min;
	u8      rssi_min;
	u8      is_linked;
	// HW information
	u8      cut_version;
	u8      rfe_type;
	u8      package_type;
	u8      support_interface;
	u8      bDivision;
	u8      ant_div_type;
	BOOLEAN is_one_entry_only;

	/*Add by YuChen*/
	u8        tx_ant_status;
	u8		tx_1ss_status;
	u8	tx_2ss_status;
	u8        rx_ant_status;
	BOOLEAN    is_init_hw_info_by_rfe;
	BOOLEAN    is_disable_phy_api;
	BOOLEAN    cck_new_agc;
	/*    u8        board_type;*/
	/*    u16        type_glna;*/
	/*    u16        type_gpa;*/
	/*    u16        type_alna;*/
	/*    u16        type_apa;*/
	u8        normal_rx_path;
	BOOLEAN    wifi_test;
	u8        rfe_hwsetting_band;
	u8         brxagcswitch;
	u16		dis_dpd_rate;
	BOOLEAN	en_dis_dpd;

	/*--------- POINTER REFERENCE-----------*/
	/*Central channel location Ch1/Ch2/....*/
	u8        *channel;            /*central channel number*/
	u8        *band_width;    /*BW info 20M/40M/80M = 0/1/2*/
	u8        *antenna_test;
	u8        *mp_mode;
	u8		*band_type;	/*@2.4G/5G = 0/1*/

	/*--------- PHYDM STRUCTURE-----------*/
	struct phydm_dig_struct    dm_dig_table;
	/*struct phydm_fa_struct     false_alm_cnt;*/
	/*Add by YuChen*/


	u8			ofdm_rxagc_l_bnd[16];
	BOOLEAN			l_bnd_detect[16];
	/*@-------------------phydm_phystatus report --------------------*/
	struct phydm_physts dm_physts_table;
	u32 bp_0x9b0;

	struct dm_dpk_info   dpk_info;

} COMMON_PARM, *PCOMMON_PARM;

typedef  struct _PHYDM_FUNC_ { /*the 4-th layer*/

	COMMON_PARM             Common_Parm;
	DBG_PARM                     Dbg_info_Parm;
	PHY_INFO_PARM            Phy_info_Parm;
	STA_INFO_PARM            Sta_info_Parm[MACID_NUM];
	MURA_PARM                   Mu_ra_Parm;
	//FA_PARM                        Fa_Parm;
	//DIG_PARM                      Dig_Parm;
#if 0//CONFIG_MCC
	MCC_DM_PARM               mcc_parm;
#endif
#if 0//CONFIG_RABFCTRL
	TxBFEntry_PARM              TxBFEntry_Parm;
#endif
#if 0//CONFIG_FW_CLM_MOITOR
	CCX_INFO_PARM           ccx_Parm;
#endif
#if 0//CONFIG_MU_RA_SUPPORT_JAGUARIII
	PHYDM_MU_INFO_8814B mu_info;
#endif
} PHYDM_FUNC, *P_PHYDM_FUNC;

typedef struct _DACK_RELOAD_PARM_ {
	BOOLEAN dack_en;
	u16 msbk_d[2][2][15];
	u16 biask_d[2][2];
} DACK_RELOAD_PARM, *PDACK_RELOAD_PARM;

typedef struct _IQK_OFFLOAD_PARM_ {
//Info
	u8  Band;
	//0:2G, 1:5G
	u8    BW;
	// 2:20M, 1:40M, 0:80M
//    u16 Channel;
	u8 IQKtimes;
	u8    rxiqk_step;
	u8    IQKstep;
	u8    Kcount;
	u8    tmp1bcc;
	u32 lna_idx;
	u8 kcount;
	BOOLEAN is_fwiqk;
	u8		iqk_band;
	u8		iqk_ch;
	u8		iqk_bw;
	BOOLEAN     LOK_fail[SS];
	BOOLEAN	IQK_fail[2][SS];
	u32        IQC_Matrix[2][SS];
	u16     	iqk_cfir_real[2][SS][2][17]; //channel / path / TRX(TX:0, RX:1) / CFIR_real
	u16     	iqk_cfir_imag[2][SS][2][17]; //channel / path / TRX(TX:0, RX:1) / CFIR_imag
	BOOLEAN	iqk_fail_report[2][SS][2];
	u32		iqk_channel[SS];
	u32		rf_reg18;
	u8		rxiqk_fail_code[2][SS]; /* channel / path 0:SRXK1 fail, 1:RXK1 fail 2:RXK2 fail */
	u16		rxiqk_agc[2][SS];
	u32		lok_idac[2][SS]; //channel / path
	BOOLEAN	is_tssi_mode;
	u8        retry_count[2][SS][3];
	u8        gs_retry_count[2][SS][2]; /* channel / path / (GSRXK1:0, GSRXK2:1) */
//    u32        bypassIQK[2][SS];    /*channel / 0xc94/0xe94*/
	BOOLEAN        isbnd;
	BOOLEAN        is_BTG;
	u32        tmp_GNTWL;
	BOOLEAN	is_reload;
	u32 nbtxk_1b38[2];
	u32 nbrxk_1b3c[2];
} IQK_OFFLOAD_PARM, *PIQK_OFFLOAD_PARM;

typedef struct _H2CParam_POWER_TRACKING_ {
	//offset 0x8

	BOOLEAN enable_A: 1;
	BOOLEAN enable_B: 1;
	BOOLEAN enable_C: 1;
	BOOLEAN enable_D: 1;
	u8    TYPE: 3;
	BOOLEAN rsvd0: 1;
	u8    BBSWING_INDEX;
	u16    rsvd2;

	//offset 0xC
	u8 TX_PWR_INDEX_A;
	s8 PWR_TRACKING_OFFSET_VALUE_A;
	u8 TSSI_VALUE_A;
	u8 rsvd3;

	//offset 0x10
	u8 TX_PWR_INDEX_B;
	s8 PWR_TRACKING_OFFSET_VALUE_B;
	u8  TSSI_VALUE_B;
	u8 rsvd4;

	//offset 0x14
	u8 TX_PWR_INDEX_C;
	s8 PWR_TRACKING_OFFSET_VALUE_C;
	u8  TSSI_VALUE_C;
	u8 rsvd5;

	//offset 0x18
	u8 TX_PWR_INDEX_D;
	s8 PWR_TRACKING_OFFSET_VALUE_D;
	u8  TSSI_VALUE_D;
	u8 rsvd6;

} H2CParam_POWER_TRACKING, *PH2CParam_POWER_TRACKING;

/*--------------------Export global variable----------------------------*/

/*--------------------Function declaration------------------------------*/
extern u16
phydm_hw_division(
	u16 numerator,
	u16 denominator
);


extern void
phydm_dmWatchdog(
	void
);

extern void
ODM_msbk_backup(
	void
);

extern void
ODM_msbk_restore(
	void
);

extern u8
ODM_IQK_Offload(
	u8 *pbuf
);

extern void
ODM_IQK_GetRFInfo(
	void
);

extern void
ODM_IQK_ReloadIQK_All(
	void
);

extern BOOLEAN
ODM_IQK_ReloadIQK(
	IN u8        reset,
	IN BOOLEAN    PsOpenRF
);

extern void
ODM_IQK_reloadIQKSetting(
	u8        channel,
	BOOLEAN PsOpenRF
);

extern void
ODM_IQK_backup_all(
	void
);

extern u8
ODM_PowerTracking(
	u8 *pbuf
);

extern u8
ODM_PSD(
	u8 *pbuf
);

extern void
ODM_Init_DM(
	void
);

#endif //#ifndef __ODM_RAM_H__

