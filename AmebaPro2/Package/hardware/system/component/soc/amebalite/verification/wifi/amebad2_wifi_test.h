#ifndef _AMEBAD2_WIFI_TEST_H_
#define _AMEBAD2_WIFI_TEST_H_
#include "FreeRTOS.h"

struct trigger_common {
	u32 trigger_type: 4;
	u32 ul_len: 12;
	u32 more_tf: 1;
	u32 cs_rqd: 1;
	u32 ul_bw: 2;
	u32 gi_ltf: 2;
	u32 mimo_ltfmode: 1;
	u32 num_heltf: 3;
	u32 ul_stbc: 1;
	u32 ldpc_extra_sym: 1;

	u32 ap_tx_pwr: 6;
	u32 pre_fec_padding_factor: 2;
	u32 pe_disambiguity: 1;
	u32 ul_sr: 16;
	u32 doppler: 1;
	u32 ul_siga2_rsvd: 9;
	u32 rsvd: 1;
};

struct trigger_user {
	u32 aid12: 12;
	u32 ru_pos: 8;
	u32 ul_fec_code: 1;
	u32 ul_mcs: 4;
	u32 ul_dcm: 1;
	u32 ss_alloc: 6;
	u16 ul_tgt_rssi: 7;
	u16 rsvd1: 1;
	u16 spacing_factor: 2;
	u16 tid_agg_limit: 3;
	u16 rsvd2: 1;
	u16 pre_ac: 2;
};

struct murts_user {
	u32 aid12: 12;
	u32 ru_pos: 8;
	u32 ul_fec_code: 1;
	u32 ul_mcs: 4;
	u32 ul_dcm: 1;
	u32 ss_alloc: 6;
	u8 ul_tgt_rssi: 7;
	u8 rsvd1: 1;
};

struct ampdu_delimiter {
	u32 eof: 1;
	u32 rsvd: 1;
	u32 len: 14;
	u32 crc: 8;
	u32 signature: 8;
};

struct wifi_test_para_t {
	u8 show_rx_desc;
	u8 show_tx_desc;
	u8 show_rx;
	u8 show_tx;
	u16 show_bytes;
	u8 show_phystatus;
	u64 target_wake_time[5];
	u8 twt_port;
	u8 basic_trx_ac;
	u8 mu_ul_rate_test;
	u32 mu_ul_rate_test_len;
	u8 dcm;
	u8 er;
	u8 er_bw;
	u8 bw;
	u8 contious_tx;
	u8 ctx_nodelay;
	u16 acq;
	u16 payload_len;
	u16 rate;
	u8 len_rand;
	u8 rate_rand;
	u32 tx_cnt_data;
	u32 tx_cnt_mgnt;
	u32 rx_cnt_trigger_bc;
	u32 rx_cnt_trigger_uc;
	u32 rx_cnt_trigger_basic;
	u32 rx_cnt_trigger_bar;
	u32 rx_cnt_trigger_rts;
	u32 rx_cnt_data;
	u32 rx_cnt_data_rty;
	u32 rx_cnt_mgnt;
	xSemaphoreHandle dfs_int;
	u8 tp_rx_start;
	u32 tp_rx_last_time;
	u64 tp_rx_last_time_tsft;
	u32 tp_rx_size;
	u32 tp_rx_size_tsft;
	u8 mba_bc;
	u8 mba_type;
	u8 mba_tid;
	u8 mba_user;
	u8 mba_start;
	u16 mba_aid;
	u8 bitmap_oft;
	u8 bitmap_tim0;
	u8 bitmap_tim1;
};

#define RTL8730A_BB_REG_BASE	(WIFI_REG_BASE + 0x10000)

#define TXDESC_BFRP_VHT	1
#define TXDESC_MU_RTS	4
#define TXDESC_BFRP_HE	5
#define TXDESC_TF_OTHER	7
#define NOT_SPECIFIC	0xff


void WifiShowRX(u8 *rx_data, struct rx_pkt_attrib	*pattrib, u8 *rx_desc);
void WifiShowTX(u8 *buf1, u32 len1, u8 *buf0, u32 len0);
void WifiTWTTimerIrqHandler(u32 isr, u32 isr1);
void WifiBasicTrxTest(PTXDESC_8723B ptxdesc);
void WifiTestSetTxdesc(PTXDESC_8723B ptxdesc);
void WifiDfsIrqHandler(u32 isr);
#endif
