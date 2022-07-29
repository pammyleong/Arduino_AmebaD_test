#ifndef __WIFIFW_TXREPORT_RAM_H__
#define __WIFIFW_TXREPORT_RAM_H__

#define TEST_FORCE_TRXRPT_FULL          0       //set 1 to force TRxRPT full
#define TXRPTFIELD_RPT_SEL              (BIT7|BIT6|BIT5)


typedef enum _RPT_TYPE_ {

	TXRPT       = 0,
	FTMRPT      = 1,
	CCXRPT      = 2,
	FTMACKRPT   = 3,
	TXBCNRPT    = 4,
	RXBCNRPT    = 5,


} RPT_TYPE, *PRPT_TYPE;

/*--------------------Define MACRO--------------------------------------*/

#define ReadTRXRPTByte(rpt_idx, offset)         rtl_inb(RTL8721D_TRXRPT_BASE + (rpt_idx<<4) + offset)
#define ReadTRXRPTDWORD(rpt_idx, offset)        rtl_inl(RTL8721D_TRXRPT_BASE + (rpt_idx<<4) + offset)
#define WriteTRXRPTByte(rpt_idx, offset,value)         rtl_outb(RTL8721D_TRXRPT_BASE + (rpt_idx<<4) + offset, value)
#define WriteTRXRPTDWord(rpt_idx, offset,value)        rtl_outl(RTL8721D_TRXRPT_BASE + (rpt_idx<<4) + offset, value)

//#define ReadMURateByteROM8723F(gid, user_position)         rtl_inb(RTL8723F_MURATE_BASE + (gid<<1) + user_position)
//#define WriteMURateByteROM8723F(gid, user_position, val)   rtl_outb(RTL8723F_MURATE_BASE + (gid<<1) + user_position, val)


/*--------------------Define -------------------------------------------*/

/*--------------------Define Enum---------------------------------------*/

/*--------------------Define Struct-------------------------------------*/
#if CONFIG_RLE1080_A_CUT
typedef struct _TxRpt_Info_ {
	/*RA report*/
	u16 TOTAL[RA_MACID_NUM];   /* TOTAL = 1*R[0]+2*R[1]+...+(N+1)*R[N]:rate down*/
	u16 DROP[RA_MACID_NUM];
	u16 OK[RA_MACID_NUM];      /* OK = R[0]+R[1]+R[2]+R[3]: Initial rate, no rate down*/
	u16 OK_ALL[RA_MACID_NUM];  /* OK_ALL = R[0]+R[1]+...+R[N]:rate down*/
	u8  TOTAL_PKT[RA_MACID_NUM]; /*Total Packet*/
	u8  TXCLS_PKT[RA_MACID_NUM]; /*Tx Collision Packet*/


	/*RA report for Beacon Cnt*/
	u16 BCN_TOTAL[RA_MACID_NUM];	/* TOTAL = 1*R[0]+2*R[1]+...+(N+1)*R[N]:rate down*/
	u16 BCN_OK[RA_MACID_NUM];		/* OK = R[0]+R[1]+R[2]+R[3]: Initial rate, no rate down*/
	u8  BCN_CNT[RA_MACID_NUM];

	/*RA report for try rate*/
	u16 TRY_OK[RA_MACID_NUM];
	u16 TRY_TOTAL[RA_MACID_NUM];
	u16 TRY_DROP[RA_MACID_NUM];
	u16 TRY_OK_ALL[RA_MACID_NUM];

	/*for H2C_AP_Req_Txrpt*/
	u16 PASS_C2H[RA_MACID_NUM];
	u16 DROP_C2H[RA_MACID_NUM];
	u32 RTY_C2H;
	u16 RTY_CNT_C2H[RA_MACID_NUM];
	u16 TOTAL_CNT_C2H[RA_MACID_NUM];
	u16 TOTAL_RTY_C2H[RA_MACID_NUM]; /*total "try" number despite of pkts TX OK or Fail*/
	u16 acq_rpt[2][RA_MACID_NUM][4]; /*0: pass, 1: drop*/
} TxRpt_Info, *PTxRpt_Info;

typedef struct _TxRpt_Cfg_ {
	//offset 0
	u8 bt_polluted: 1;
	u8 miss_rpt_num: 1;
	u8 rsvd0: 3;
	u8 rpt_sel: 3;
	//offset 1
	u8 rpt_qsel: 5;
	u8 collision_head: 1; //for 97G/12F
	u8 collision_tail: 1; //for 97G/12F
	u8 fixed_rate: 1; //driver fixed rate
	//offset 2
	u8 macid: 7;
	u8 rsvd2: 1;
	//offset 3
	u8 rate;
	//offset 4
	u8 ok_num: 6;
	u8 rsvd4: 1;
	u8 try_rate: 1;
	//offset 5
	u8 drop_num: 6;
	u8 bitmap_short: 2; /*????*/
	//offset 6
	u8 sw_def;
	//offset 7
	u8 rts_rty_num: 4;
	u8 rts_rty_drop: 1;
	u8 rts_bmc: 1;
	u8 tx_state: 2;
	//offset 8
	u8 rty_idx: 6;
	u8 rts_ndpa_flag: 1; //only for 12F
	u8 ex_tx_state: 1;
	//offset 9
	u8 final_rate;
	//offset 10
	u8 ch_lsb;
	//offset 11
	u8 ch_msb: 2;
	u8 ch_sc: 4;
	u8 ch_bw: 2;
	//offset 12
	u8 total_cnt: 6; /*total number of MPDU have been transmitted*/
	u8 rsvd12: 2;
	//offset 13
	u8 gid: 6;
	u8 mu2su: 1;
	u8 mu_lmt: 1;
	//offset 14
	u8 tx_time_lsb;
	//offset 15
	u8 tx_time_msb;
} TxRpt_Cfg, *pTxRpt_Cfg;
#endif


#define TXRPT_DEFAULT_LEN_TH            5   //0x20
#define TXRPT_DEFAULT_TIMER_TH          0xFE  //10ms  //unit:64us

#define C2HEXTID_CCX_RPT_LENGTH	16

//4 RA MASK
//offset 7
#define RAMASKFIELD_RAFT_RDY            BIT7

//3 TXRPT format
//offset 0
#define TXRPTFIELD_POLLUTED             BIT0
#define TXRPTFIELD_MISS_RPT_NUM         BIT1
#define TXRPTFIELD_RPT_SEL              (BIT7|BIT6|BIT5)

//offset 1
#define TXRPTFIELD_QSEL                 (BIT4|BIT3|BIT2|BIT1|BIT0)
#define TXRPTFIELD_FIX_RATE		        BIT7

//offset 2
#define TXRPTFIELD_MACID                (BIT6|BIT5|BIT4|BIT3|BIT2|BIT1|BIT0)

//offset 3
#define TXRPTFIELD_DATA_RATE            (BIT6|BIT5|BIT4|BIT3|BIT2|BIT1|BIT0)
#define TXRPTFIELD_SGI                  BIT7

//offset 4
#define TXRPTFIELD_OK_PKT_NUM           (BIT5|BIT4|BIT3|BIT2|BIT1|BIT0)
#define TXRPTFIELD_TRY_RATE             BIT7

//offset 5
#define TXRPTFIELD_DROP_PKT_NUM         (BIT5|BIT4|BIT3|BIT2|BIT1|BIT0)
#define TXRPTFIELD_BITMAP_SHORT         (BIT7|BIT6)

//offset 6
#define TXRPTFIELD_SW_DEFINE7_0         (BIT7|BIT6|BIT5|BIT4|BIT3|BIT2|BIT1|BIT0)

//offset 7
#define TXRPTFIELD_RTS_RETRY_COUNT      (BIT3|BIT2|BIT1|BIT0)
#define TXRPTFIELD_RTS_RTY_DROP         BIT4
#define TXRPTFIELD_BMC                  BIT5
#define TXRPTFIELD_TX_STATE             (BIT7|BIT6)

//offset 8
#define TXRPTFIELD_DATA_RTY_CNT         (BIT5|BIT4|BIT3|BIT2|BIT1|BIT0)
#define TXRPTFIELD_EX_TX_STATE          BIT7    //8723F/8812F always = 1, FW should ignore this bit

//offset 9
#define TXRPTFIELD_FINAL_DATA_RATE      (BIT6|BIT5|BIT4|BIT3|BIT2|BIT1|BIT0)
#define TXRPTFIELD_FINAL_SGI            BIT7

//offset 10
#define TXRPTFIELD_CHANNEL_NUM_LSB      (BIT7|BIT6|BIT5|BIT4|BIT3|BIT2|BIT1|BIT0)

//offset 11
#define TXRPTFIELD_CHANNEL_NUM_MSB      (BIT1|BIT0)
#define TXRPTFIELD_SC                   (BIT5|BIT4|BIT3|BIT2)
#define TXRPTFIELD_BW                   (BIT7|BIT6)

//offset 12
#define TXRPTFIELD_TOTAL_PKT_NUM        (BIT5|BIT4|BIT3|BIT2|BIT1|BIT0)

//offset 13
#define TXRPTFIELD_GID                  (BIT5|BIT4|BIT3|BIT2|BIT1|BIT0)//NEW_AGG_PKT_NUM
#define TXRPTFIELD_MU2SU                BIT6//reserved
#define TXRPTFIELD_MU_LMT               BIT7//reserved

//offset 14
#define TXRPTFIELD_ACCTXTIME_LSB        (BIT7|BIT6|BIT5|BIT4|BIT3|BIT2|BIT1|BIT0)

//offset15
#define TXRPTFIELD_ACCTXTIME_MSB        (BIT7|BIT6|BIT5|BIT4|BIT3|BIT2|BIT1|BIT0)


/*--------------------Function declaration------------------------------*/
#if CONFIG_RLE1080_A_CUT
extern  void
ParseTRXRpt(
	void
);
#endif
extern void
phydm_reset_c2hrpt(
	IN u8 macid
);

extern  void
phydm_init_txrpt(
	void
);

extern void
phydm_reset_txrpt_jgr3(
	IN u8 macid
);

extern void
phydm_reset_bcn_txrpt_jgr3(
	IN u8 macid
);

extern void
phydm_get_txrptstatistic_jgr3(
	IN u8 rpt_idx
);

u8
phydm_get_txrptstatistic_mu(
	void
);

extern void
InitTxrpt(
	void
);

extern void
ResetTxRpt(
	IN u8 macid
);

extern  void
ParseTRXRpt(
	void
);

extern  void
GetCcxRpt(
	IN u8 rpt_idx
);

extern void
InitCtrlInfo(
	void
);
#endif  //#ifndef   __WIFIFW_TXREPORT_RAM_H__


