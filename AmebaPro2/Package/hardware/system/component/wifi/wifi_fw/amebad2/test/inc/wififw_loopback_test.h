#ifndef __WIFIFW_LOOPBACK_TEST_H__
#define __WIFIFW_LOOPBACK_TEST_H__

/*--------------------------Define -------------------------------------------*/
#define REG_FWLBK_CTRL_EXT                  REG_DBG_BYTE_9
//#define DBG_PC                              0x1C4
//#define TX_RTY_CNT                          0x10
//#define RX_RTY_CNT                          0x4000
#define RTY_CNT                             0x4000

//Tx page
#define TXPKTBUF_PGBNDY_FWLBK               0x60//Reserved 4k bytes, 2k for fwlbk packet, 2k for wmac buffer
#define TXPKTBUF_BNDY_FWLBK                 (PAGESIZE_TX*TXPKTBUF_PGBNDY_FWLBK)
#define RXPKTBUF_PGBNDY_FWLBK               0x6FF

//FWLBK MODE
//#define FWLBK_MOD_IDLE                      0x00
#define FWLBK_MOD_TX_Without_CHECK          0x20
#define FWLBK_MOD_TX_With_CHECK             0x40
#define FWLBK_MOD_MACLBK_With_CHECK         0x60
#define FWLBK_MOD_CP_MAC_TEST               0x80
//#define FWLBK_MOD_CP_BBLBK                  0xA0
#define FWLBK_MOD_CP_AFELBK                 0xC0
//#define FWLBK_MOD_MODULE_TEST               0xE0

//FWLBK MASK
#define FWLBK_MASK_LEN                      (BIT2 | BIT3)
#define FWLBK_MASK_CONT_TX                  BIT1
#define FWLBK_MASK_BW_40M                   BIT0
#define FWLBK_MASK_NUM						(BIT4 | BIT5 | BIT6)

#define FWLBK_MASK_MODE                     BIT5
#define FWLBK_MASK_SGI                      BIT4
#define FWLBK_MASK_SCANRATE                 BIT3
#define FWLBK_MASK_DATARATE                 (BIT0 | BIT1 | BIT2)

//FWLBK Extend MASK
#define FWLBK_MASK_UC                       BIT3
#define FWLBK_MASK_LEGACY_ONLY              BIT2
#define FWLBK_MASK_BW_EXT                   BIT1
#define FWLBK_MASK_VHT_EN                   BIT0

//FWLBK Debug

#if 0

//#define FWLBK_DBG_STOP_CNT                  0x01A0
#define FWLBK_DBG_PAYLD_OFSET               REG_FWLBK_DBG_WORD0//The n'th byte of payload which compare error
#define FWLBK_DBG_TXBUF_DATA                REG_FWLBK_DBG_BYTE16//The value of TXPKTBUF compared error
#define FWLBK_DBG_RXBUF_DATA                REG_FWLBK_DBG_BYTE17//The value of RXPKTBUF compared error
#define FWLBK_DBG_RX_LEN                    REG_FWLBK_DBG_WORD1//length field of RxDESC
#define FWLBK_DBG_RXFF_RP                   REG_FWLBK_DBG_WORD2//RXFF Read Pointer
#define FWLBK_DBG_PKTCNT                    REG_FWLBK_DBG_WORD3//Tx packet count or Rx Receive packet count
#define FWLBK_DBG_DATARATE                  REG_DBG_DWORD_1+2
#define FWLBK_DBG_RX_OK_CNT                 REG_FWLBK_DBG_BYTE19

//
//0x067C[31] : DBG_SEL.  1:TX, 0:RX
//0x067C[15] : KEY_FOUND
//0x067C[14:12] : Secrity Type
//0x067C[9:5] : MIC Key Index
//0x067C[4:0] : Security Key Index
//
#define FWLBK_DBG_CAM_0                     REG_FWLBK_DBG_BYTE20//0x67C
#define FWLBK_DBG_CAM_1                     REG_FWLBK_DBG_BYTE21//0x67D
#define FWLBK_DBG_POLL_OK_CNT               REG_FWLBK_DBG_BYTE22
#define FWLBK_DBG_CTL                       REG_FWLBK_DBG_BYTE23
#endif
//#define REG_LBMODE                  (REG_CR + 3)

#define HCI_TXDMA_EN                BIT0
//#define HCI_RXDMA_EN                BIT1
#define TXDMA_EN                    BIT2
//#define RXDMA_EN                    BIT3
#define PROTOCOL_EN                 BIT4
#define SCHEDULE_EN                 BIT5
#define MACTXEN                     BIT6
//#define MACRXEN                     BIT7

//#define ENSWBCN                     BIT0
#define ENSEC                       BIT1

#define FUNC_EN_TX_PATH             (HCI_TXDMA_EN/*|TXDMA_EN*/|PROTOCOL_EN|SCHEDULE_EN|MACTXEN)
//for dynamic LLT initialization, TXDMA_EN shall not be reset.
//#define FUNC_EN_RX_PATH             (HCI_RXDMA_EN|RXDMA_EN|MACRXEN)

//FWLBK Status (0x01C3)
#define FWLBK_TEST_FINISH                   BIT7
#define FWLBK_TEST_FAIL                     BIT6
#define FWLBK_TEST_ERR_RX_RWPTR             BIT4
#define FWLBK_TEST_ERR_RXFF_NOEMPTY         BIT3
#define FWLBK_TEST_ERR_CPUMGQ               BIT2
#define FWLBK_ERR_RXDMABUSY                 BIT1
#define FWLBK_TEST_ERR_CMD                  BIT0

#define Auto_Init_LLT					BIT0

//FWLBK DBG CTRL (0x01DF)
//#define DBGCTRL_STEP                        BIT0
//#define DBGCTRL_STEP_NEXT                   BIT1
//#define DBGCTRL_ERR_CTX                     BIT2    //if Rx compare error, continue test.

//RX pkt unm  0x284+2
#define RXDMA_IDLE                  BIT1
#define STOP_RXDMA                  BIT2

//EXREG Status Report
//0xFD01
//#define EXREG_STATUS_HCI_TYPE               (BIT1|BIT2)
//#define EXREG_STATUS_HCI_SDIO               0
//#define EXREG_STATUS_HCI_USB                BIT1
//#define EXREG_STATUS_HCI_PCIE               (BIT1|BIT2)

//FWLBK Start Length
#define FWLBK_STARTLEN_64B                  0x58
#define FWLBK_STARTLEN_1024B                0x418
#define FWLBK_STARTLEN_1514B                0x602
#define FWLBK_STARTLEN_INCREMENTAL          0x58

#define SIZE_WLAN_HEAD                      24

//Security
#define SEC_TYPE_WEP40                      1
#define SEC_TYPE_WEP104                     5
#define SEC_TYPE_TKIP                       2
#define SEC_TYPE_AES                        4
#define SEC_TYPE_WAPI                       6

#define SEC_IDX_WEP40                       0
#define SEC_IDX_WEP104                      1
#define SEC_IDX_TKIP                        2
#define SEC_IDX_AES                         3
#define SEC_IDX_WAPI                        4

#define LAST_PAGE_OF_TXBUF_RSVDPAGE 0xFF
#define LAST_PAGE_OF_TXBUF_ACQ      0xFF
#define LLT_WRITE_COUNT_MAX         0xFFFF

/*------------------------------Define Enum-----------------------------------*/

/*--------------------------Define MACRO--------------------------------------*/

/*------------------------------Define Struct---------------------------------*/

/*------------------------Export global variable------------------------------*/
#ifndef __ASSEMBLY__

extern u8  FWLBK_HEADER[];
extern u8  FWLBK_TXDESC[];
extern u8  MIC[];
extern u16 FWLBK_LEN[];
extern u8  FWLBK_DATARATE[];

extern volatile u8 FWLBK_CTL_L, FWLBK_CTL_H;
extern volatile u8 TxDESC_len;

/*------------------------------Function declaration--------------------------*/
extern void FwlbkDbgPrtU16(u16 addr, u16 wdata);

extern void FwlbkLLTWrite(u8 address, u8 value);

extern void FwlbkHWInitialLLT(void);

extern void FwlbkMode(void);

extern void FwlbkPreparePkt(void);

extern void FwlbkModeSel(void);

extern void FwlbkCheckRxPayload(void);

extern void FwlbkSetCAM(u8 sec_type);

extern void FwlbkUpdateParam(u16 Datarate);

extern u8 FwlbkMcuPollMgq(void);

extern void FwlbkModeTxNoCheck(void);

extern void FwlbkModeTx(void);

extern void FwlbkModeMaclbk(void);

extern void FwlbkModeSecTest(void);

extern void FwlbkModeAFElbk(void);

extern BOOLEAN CheckFWLBKEnable(void);


#endif  /* #ifndef   __ASSEMBLY__ */


#endif  /* __WIFIFW_FWLBK_H__ */
