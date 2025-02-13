/******************************************************************************
 *
 * Copyright(c) 2007 - 2011 Realtek Corporation. All rights reserved.
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
#ifndef __RTL8188E_XMIT_H__
#define __RTL8188E_XMIT_H__

#define 	MAX_TX_AGG_PACKET_NUMBER 	0xFF
//
// Queue Select Value in TxDesc
//
#define QSLT_BK							0x2//0x01
#define QSLT_BE							0x0
#define QSLT_VI							0x5//0x4
#define QSLT_VO							0x7//0x6
#define QSLT_BEACON						0x10
#define QSLT_HIGH						0x11
#define QSLT_MGNT						0x12
#define QSLT_CMD						0x13

//For 88e early mode
#define SET_EARLYMODE_PKTNUM(__pAddr, __Value) SET_BITS_TO_LE_4BYTE(__pAddr, 0, 3, __Value)
#define SET_EARLYMODE_LEN0(__pAddr, __Value) SET_BITS_TO_LE_4BYTE(__pAddr, 4, 12, __Value)
#define SET_EARLYMODE_LEN1(__pAddr, __Value) SET_BITS_TO_LE_4BYTE(__pAddr, 16, 12, __Value)
#define SET_EARLYMODE_LEN2_1(__pAddr, __Value) SET_BITS_TO_LE_4BYTE(__pAddr, 28, 4, __Value)
#define SET_EARLYMODE_LEN2_2(__pAddr, __Value) SET_BITS_TO_LE_4BYTE(__pAddr+4, 0, 8, __Value)
#define SET_EARLYMODE_LEN3(__pAddr, __Value) SET_BITS_TO_LE_4BYTE(__pAddr+4, 8, 12, __Value)
#define SET_EARLYMODE_LEN4(__pAddr, __Value) SET_BITS_TO_LE_4BYTE(__pAddr+4, 20, 12, __Value)

//
//defined for TX DESC Operation
//

#define MAX_TID (15)

//OFFSET 0
#define OFFSET_SZ	0
#define OFFSET_SHT	16
#define BMC		BIT(24)
#define LSG		BIT(26)
#define FSG		BIT(27)
#define OWN 		BIT(31)


//OFFSET 4
#define PKT_OFFSET_SZ		0
#define QSEL_SHT			8
#define RATE_ID_SHT			16
#define NAVUSEHDR			BIT(20)
#define SEC_TYPE_SHT 		22
#define PKT_OFFSET_SHT		26

//OFFSET 8
#define AGG_EN				BIT(12)
#define AGG_BK					BIT(16)
#define AMPDU_DENSITY_SHT	20
#define ANTSEL_A			BIT(24)
#define ANTSEL_B			BIT(25)
#define TX_ANT_CCK_SHT		26
#define TX_ANTL_SHT			28
#define TX_ANT_HT_SHT		30

//OFFSET 12
#define SEQ_SHT				16
#define EN_HWSEQ			BIT(31)

//OFFSET 16
#define 	QOS                          BIT(6)
#define	HW_SSN				BIT(7)
#define 	USERATE			BIT(8)
#define 	DISDATAFB			BIT(10)
#define   CTS_2_SELF			BIT(11)
#define	RTS_EN				BIT(12)
#define	HW_RTS_EN			BIT(13)
#define 	DATA_SHORT			BIT(24)
#define 	PWR_STATUS_SHT	15
#define 	DATA_SC_SHT		20
#define 	DATA_BW			BIT(25)

//OFFSET 20
#define	RTY_LMT_EN			BIT(17)

enum TXDESC_SC{
	SC_DONT_CARE = 0x00,
	SC_UPPER= 0x01,	
	SC_LOWER=0x02,
	SC_DUPLICATE=0x03
};
//OFFSET 20
#define SGI					BIT(6)
#define USB_TXAGG_NUM_SHT	24

typedef struct txdescriptor_8188e
{
	//Offset 0
	u32 pktlen:16;
	u32 offset:8;
	u32 bmc:1;
	u32 htc:1;
	u32 ls:1;
	u32 fs:1;
	u32 linip:1;
	u32 noacm:1;
	u32 gf:1;
	u32 own:1;

	//Offset 4
	u32 macid:6;
	u32 rsvd0406:2;	
	u32 qsel:5;
	u32 rd_nav_ext:1;
	u32 lsig_txop_en:1;
	u32 pifs:1;
	u32 rate_id:4;
	u32 navusehdr:1;
	u32 en_desc_id:1;
	u32 sectype:2;
	u32 rsvd0424:2;
	u32 pkt_offset:5;	// unit: 8 bytes
	u32 rsvd0431:1;

	//Offset 8
	u32 rts_rc:6;
	u32 data_rc:6;
	u32 agg_en:1;
	u32 rd_en:1;
	u32 bar_rty_th:2;
	u32 bk:1;
	u32 morefrag:1;
	u32 raw:1;
	u32 ccx:1;
	u32 ampdu_density:3;
	u32 bt_null:1;
	u32 ant_sel_a:1;
	u32 ant_sel_b:1;
	u32 tx_ant_cck:2;
	u32 tx_antl:2;
	u32 tx_ant_ht:2;

	//Offset 12
	u32 nextheadpage:8;
	u32 tailpage:8;
	u32 seq:12;
	u32 cpu_handle:1;
	u32 tag1:1;
	u32 trigger_int:1;
	u32 hwseq_en:1;

	//Offset 16
	u32 rtsrate:5;
	u32 ap_dcfe:1;
	u32 hwseq_sel:2;
	u32 userate:1;
	u32 disrtsfb:1;
	u32 disdatafb:1;
	u32 cts2self:1;
	u32 rtsen:1;
	u32 hw_rts_en:1;
	u32 port_id:1;	
	u32 pwr_status:3;
	u32 wait_dcts:1;
	u32 cts2ap_en:1;
	u32 data_sc:2;
	u32 data_stbc:2;
	u32 data_short:1;
	u32 data_bw:1;
	u32 rts_short:1;
	u32 rts_bw:1;
	u32 rts_sc:2;
	u32 vcs_stbc:2;

	//Offset 20
	u32 datarate:6;
	u32 sgi:1;
	u32 try_rate:1;
	u32 data_ratefb_lmt:5;
	u32 rts_ratefb_lmt:4;
	u32 rty_lmt_en:1;
	u32 data_rt_lmt:6;
	u32 usb_txagg_num:8;

	//Offset 24
	u32 txagg_a:5;
	u32 txagg_b:5;
	u32 use_max_len:1;
	u32 max_agg_num:5;
	u32 mcsg1_max_len:4;
	u32 mcsg2_max_len:4;
	u32 mcsg3_max_len:4;
	u32 mcs7_sgi_max_len:4;

	//Offset 28
	u32 checksum:16;	// TxBuffSize(PCIe)/CheckSum(USB)
	u32 mcsg4_max_len:4;
	u32 mcsg5_max_len:4;
	u32 mcsg6_max_len:4;
	u32 mcs15_sgi_max_len:4;
}TXDESC, *PTXDESC;


void rtl8188e_fill_fake_txdesc(_adapter * padapter, u8*pDesc,u32 BufferLen,u8 IsPsPoll,u8	IsBTQosNull);
#if defined(CONFIG_SDIO_HCI) || defined(CONFIG_GSPI_HCI)
#ifdef CONFIG_SDIO_TX_MULTI_QUEUE
s32 rtw_sdio_xmit_buf_handler(_adapter * padapter);
#define hal_xmit_handler rtw_sdio_xmit_buf_handler
#endif
#endif

#ifdef CONFIG_USB_HCI
s32 rtl8188eu_init_xmit_priv(_adapter * padapter);
void rtl8188eu_free_xmit_priv(_adapter * padapter);
s32 rtl8188eu_hal_xmit(_adapter * padapter, struct xmit_frame *pxmitframe);
s32 rtl8188eu_mgnt_xmit(_adapter * padapter, struct xmit_frame *pmgntframe);
s32 rtl8188eu_xmit_buf_handler(_adapter * padapter);
#define hal_xmit_handler rtl8188eu_xmit_buf_handler
void rtl8188eu_xmit_tasklet(void *priv);
s32 rtl8188eu_xmitframe_complete(_adapter * padapter, struct xmit_priv *pxmitpriv, struct xmit_buf *pxmitbuf);
#endif

#ifdef CONFIG_PCI_HCI
s32 rtl8188ee_init_xmit_priv(_adapter * padapter);
void rtl8188ee_free_xmit_priv(_adapter * padapter);
struct xmit_buf *rtl8188ee_dequeue_xmitbuf(struct rtw_tx_ring *ring);
void	rtl8188ee_xmitframe_resume(_adapter * padapter);
s32 rtl8188ee_hal_xmit(_adapter * padapter, struct xmit_frame *pxmitframe);
s32 rtl8188ee_mgnt_xmit(_adapter * padapter, struct xmit_frame *pmgntframe);
void rtl8188ee_xmit_tasklet(void *priv);
#endif



#ifdef CONFIG_TX_EARLY_MODE
void UpdateEarlyModeInfo8188E(struct xmit_priv *pxmitpriv,struct xmit_buf *pxmitbuf );
#endif
void rtl8188e_update_txdesc(struct xmit_frame *pxmitframe, u8 *pbuf);

void _dbg_dump_tx_info(_adapter	*padapter,int frame_tag,struct tx_desc *ptxdesc);
#endif //__RTL8188E_XMIT_H__

