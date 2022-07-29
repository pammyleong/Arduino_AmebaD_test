#ifndef __HALCOM_CMD_ODM_RAM_H__
#define __HALCOM_CMD_ODM_RAM_H__

/*--------------------Define -------------------------------------------*/
#define IS_JGR3_IC     1


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
#define RA_NOISY_STATE_SHT              2
#define RA_CHANGE_RATE_SHT              3
#define RA_NO_USE_2_SHT                 4
#define RA_INIT_RATE_RSSI_SHT           5
#define RA_BF_STATE_SHT                 6
#define RA_IGNORE_DROP_SHT              7

//4 MACID_CFG_3SS H2C CMD
//offset 0
#define H2CID46_MACID                   0xFF

//4 AP_Req_Tx_Rpt H2C CMD
// offset 2
#define H2CID43_RTY_OK_TOTAL            BIT0
#define H2CID43_RTY_CNT_MACID           BIT1
#define H2CID43_RTY_ALL_MACID           BIT3

// offset3
#define H2CID43_RA_VERSION              BIT0


//4 DROP_Rpt H2C CMD
#define H2CID53_RTS_RTY_CNT             BIT0

/*--------------------Define Enum---------------------------------------*/

/*--------------------Define MACRO--------------------------------------*/
// H2C ID for ODM: 0x40~0x5F
typedef enum _H2CCMD_ODM_CMD_CODE_ {
	//1 Class3: Dynamic Mechaism
	H2CID_MACID_CFG             = 0x40,
	H2CID_TxBF                  = 0x41,
	H2CID_RSSI_SETTING          = 0x42,
	H2CID_REQ_TXRPT             = 0x43,
	H2CID_INIT_RATE_COLLECT     = 0x44,
	H2CID_IQK_OFFLOAD           = 0x45,
	H2CID_MACID_CFG_3SS         = 0x46,
	H2CID_RA_PARA_ADJUST        = 0x47,
	H2CID_DYNAMIC_TX_PATH       = 0x48,
	H2CID_FW_TRACE_EN           = 0x49,
	H2CID_FW_MU                 = 0x4a,
	H2CID_Set_BFEntry           = 0x4b,
	H2CID_GENERAL_INFO          = 0x4c,
	H2CID_FW_CLM_MNTR           = 0x4d,
	H2CID_REQ_PER_RPT           = 0x4e,
	H2CID_MCC_DM_SW	            = 0x4f,
	H2CID_RESP_TX_PATH_CTRL     = 0x50,
	H2CID_RESP_TX_ANT_CTRL      = 0x51,
	H2CID_REQ_TXRPT_ACQ     = 0x52,
	H2CID_REQ_DROP_RPT          = 0x53,
	H2CID_MU_SCORE_RPT		= 0x54
} H2CCMD_ODM_CMD_CODE, *PH2CCMD_ODM_CMD_CODE;
/*--------------------Define Struct-------------------------------------*/

/*--------------------Export global variable----------------------------*/

/*--------------------Function declaration------------------------------*/


extern void
drvprint(
	const char *fmt, ...
);

extern void
C2H_RA_Dbg_code(
	u4Byte  dbg_comp,
	u8  function,
	u8  dbg_num,
	u16  content_0,
	u16  content_1,
	u16  content_2,
	u16  content_3,
	u16  content_4
);

extern void
phydm_h2ccmd_func(
	u8  CmdID,
	u8  *content
);

extern void
phydm_c2h_fw_trace(
	u8  *string
);



extern void
phydm_c2h_dtp_result(
	u8  macid,
	u8  target
);

extern void
H2CHDL_Set_MU(
	u8  *pbuf
);

extern u8
phydm_fwoffload_func(
	u8  SubCMDID,
	u8  *content
);
#if 0//CONFIG_MU_GROUPING
void C2H_phydm_mu_score_rpt(void);
#endif
#endif //__HALCOM_CMD_ODM_RAM_H__




