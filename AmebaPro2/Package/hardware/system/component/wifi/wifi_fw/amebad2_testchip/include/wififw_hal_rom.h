#ifndef __RTL8721D_HAL_H__
#define __RTL8721D_HAL_H__

#include "wififw_reg_rom.h"
#include "wififw_debug_rom.h"
#include "wififw_init_rom.h"
#include "wififw_interrupt_rom.h"
#include "wififw_util_rom.h"
#include "wififw_btconcurr_rom.h"
#include "wififw_cmd_rom.h"
#include "wififw_phyreg_rom.h"
#include "wififw_packet_rom.h"
#include "wififw_powerctrl_rom.h"
#include "wififw_loopback_rom.h"
#include "wififw_txreport_rom.h"
#include "wififw_dma_rom.h"


/*--------------------------Define -------------------------------------------*/
//3 TaskBitMap0
#define RATEADAPTIVE        BIT0
#define H2CEVENT            BIT1
#define C2HEVENT            BIT2
#define RLPSEVENT           BIT3
#define REMOTEWAKEEVENT     BIT4
#define APOFFLOADEVENT      BIT5
#define MAILBOXEVENT        BIT6
#define SWTIMEREVENT        BIT7

//3 TaskBitMap1
#define BBNHMEVENT          BIT0
#define DBGPKTEVENT         BIT1
#define SIDEBANDWoWLAN      BIT2


//3 MAC base address
#define RTL8721D_IOREG_AHB_BASE			0x43000000
//3 BB base address
#define RTL8721D_BBREG_AHB_BASE             	0x43000800
//3 RF base address
#define RTL8721D_RFREG_AHB_BASE             	0x43003800
//3 DDMA control base address
#define RTL8721D_DDMA_CTRL_AHB_BASE         	0x43000000 //0x4000_1200- 0x4000_12FF
//3 BT mailbox base address
#define RTL8721D_BT_MAILBOX_AHB_BASE        	0x430011A4
//3 CPU local base
#define RTL8721D_LPSYSON_AHB_BASE		0x42008000
//3 LLT Table base
#define RTL8721D_LLT_AHB_BASE			0x43050000//256 byte/entry

//3 TxReport Buffer base address
#define RTL8721D_RPTBUF_AHB_BASE            	0x43040000
#define RTL8721D_CtrlInfo_BASE          	(RTL8721D_RPTBUF_AHB_BASE)
#define RTL8721D_TRXRPT_BASE            	(RTL8721D_RPTBUF_AHB_BASE + 0x280)
#define RTL8721D_CRC5_BASE              	(RTL8721D_RPTBUF_AHB_BASE + 0xA80)
#define RTL8721D_NANRPT_BASE                	(RTL8721D_RPTBUF_AHB_BASE + 0xA90)

//3 Rx packet buffer base address
#define RTL8721D_RXFF_AHB_BASE              	0x43030000

//3 Tx packet buffer base address
#define RTL8721D_TXFF_AHB_BASE              	0x43010000

//3 CAM base address
#define RTL8721D_SECCAM_AHB_BASE            	0x43050800
#define RTL8721D_BACAM_AHB_BASE             	0x43051000
#define RTL8721D_MBIDCAM_AHB_BASE 		0x43051800

//offset:
#define rtl_inb(offset)             (*(volatile u8 *)((u32)offset))
#define rtl_inw(offset)             (*(volatile u16 *)((u32)offset))
#define rtl_inl(offset)             (*(volatile u32 *)((u32)offset))

#define rtl_outb(offset,val)        do { (*(volatile u8 *)((u32)offset) = (val));    } while(0)
#define rtl_outw(offset,val)        do { (*(volatile u16 *)((u32)offset) = (val));    } while(0)
#define rtl_outl(offset,val)        do { (*(volatile u32 *)((u32)offset) = (val));    } while(0)


//3 MACREG

//offset :
#define WritePONRegDWord(offset, value)     rtl_outl((offset+RTL8721D_IOREG_AHB_BASE), value)
#define WritePONRegWord(offset, value)      rtl_outw((offset+RTL8721D_IOREG_AHB_BASE), value)
#define WritePONRegByte(offset, value)      rtl_outb((offset+RTL8721D_IOREG_AHB_BASE), value)

#define ReadPONRegDWord(offset)             (rtl_inl((offset+RTL8721D_IOREG_AHB_BASE)))
#define ReadPONRegWord(offset)              (rtl_inw((offset+RTL8721D_IOREG_AHB_BASE)))
#define ReadPONRegByte(offset)              (rtl_inb((offset+RTL8721D_IOREG_AHB_BASE)))

//offset :
#define WriteMACRegDWord(offset, value)     rtl_outl((offset+RTL8721D_IOREG_AHB_BASE), value)
#define WriteMACRegWord(offset, value)      rtl_outw((offset+RTL8721D_IOREG_AHB_BASE), value)
#define WriteMACRegByte(offset, value)      rtl_outb((offset+RTL8721D_IOREG_AHB_BASE), value)

#define ReadMACRegDWord(offset)             (rtl_inl((offset+RTL8721D_IOREG_AHB_BASE)))
#define ReadMACRegWord(offset)              (rtl_inw((offset+RTL8721D_IOREG_AHB_BASE)))
#define ReadMACRegByte(offset)              (rtl_inb((offset+RTL8721D_IOREG_AHB_BASE)))

//3 LLT TABLE
#define WriteLLTTableDWord(offset, value)   rtl_outl((offset+RTL8721D_LLT_AHB_BASE), value)
#define WriteLLTTableWord(offset, value)   rtl_outw((offset+RTL8721D_LLT_AHB_BASE), value)
#define WriteLLTTableByte(offset, value)   rtl_outb((offset+RTL8721D_LLT_AHB_BASE), value)

#define ReadLLTTableDWord(offset)           (rtl_inl((offset+RTL8721D_LLT_AHB_BASE)))
#define ReadLLTTableWord(offset)            (rtl_inw((offset+RTL8721D_LLT_AHB_BASE)))
#define ReadLLTTableByte(offset)            (rtl_inb((offset+RTL8721D_LLT_AHB_BASE)))

//3 BB Reg
#define WritePortBBUlong(offset, value)     rtl_outl((offset+RTL8721D_BBREG_AHB_BASE), value)
#define WritePortBBUshort(offset, value)    rtl_outw((offset+RTL8721D_BBREG_AHB_BASE), value)
#define WritePortBBUchar(offset, value)     rtl_outb((offset+RTL8721D_BBREG_AHB_BASE), value)

#define ReadPortBBUlong(offset)             (rtl_inl((offset+RTL8721D_BBREG_AHB_BASE)))
#define ReadPortBBUshort(offset)            (rtl_inw((offset+RTL8721D_BBREG_AHB_BASE)))
#define ReadPortBBUchar(offset)             (rtl_inb((offset+RTL8721D_BBREG_AHB_BASE)))

//3 RF Reg only support dword mode
#define WritePortRFUlong(offset, value)     rtl_outl((4*offset+RTL8721D_RFREG_AHB_BASE), value)
#define ReadPortRFUlong(offset)             (rtl_inl((4*offset+RTL8721D_RFREG_AHB_BASE)))

//3 SEC CAM
#define WriteSECCAMDWord(offset, value)  rtl_outl((offset+RTL8721D_SECCAM_AHB_BASE), value)
#define WriteSECCAMWord(offset, value)   rtl_outw((offset+RTL8721D_SECCAM_AHB_BASE), value)
#define WriteSECCAMByte(offset, value)   rtl_outb((offset+RTL8721D_SECCAM_AHB_BASE), value)

#define ReadSECCAMDWord(offset)          (rtl_inl((offset+RTL8721D_SECCAM_AHB_BASE)))
#define ReadSECCAMWord(offset)           (rtl_inw((offset+RTL8721D_SECCAM_AHB_BASE)))
#define ReadSECCAMByte(offset)           (rtl_inb((offset+RTL8721D_SECCAM_AHB_BASE)))

//3 MBID CAM
#define WriteMBIDCAMDWord(offset, value)  rtl_outl((offset+RTL8721D_MBIDCAM_AHB_BASE), value)
#define WriteMBIDCAMWord(offset, value)   rtl_outw((offset+RTL8721D_MBIDCAM_AHB_BASE), value)
#define WriteMBIDCAMByte(offset, value)   rtl_outb((offset+RTL8721D_MBIDCAM_AHB_BASE), value)

#define ReadMBIDCAMDWord(offset)          (rtl_inl((offset+RTL8721D_MBIDCAM_AHB_BASE)))
#define ReadMBIDCAMWord(offset)           (rtl_inw((offset+RTL8721D_MBIDCAM_AHB_BASE)))
#define ReadMBIDCAMByte(offset)           (rtl_inb((offset+RTL8721D_MBIDCAM_AHB_BASE)))

//3 BA CAM
#define WriteBACAMDWord(offset, value)  rtl_outl((offset+RTL8721D_BACAM_AHB_BASE), value)
#define WriteBACAMWord(offset, value)   rtl_outw((offset+RTL8721D_BACAM_AHB_BASE), value)
#define WriteBACAMByte(offset, value)   rtl_outb((offset+RTL8721D_BACAM_AHB_BASE), value)

#define ReadBACAMDWord(offset)          (rtl_inl((offset+RTL8721D_BACAM_AHB_BASE)))
#define ReadBACAMWord(offset)           (rtl_inw((offset+RTL8721D_BACAM_AHB_BASE)))
#define ReadBACAMByte(offset)           (rtl_inb((offset+RTL8721D_BACAM_AHB_BASE)))

//3 ReportBUFF
#define WriteRPTBUFDWord(offset, value)  rtl_outl((offset+RTL8721D_RPTBUF_AHB_BASE), value)
#define WriteRPTBUFWord(offset, value)   rtl_outw((offset+RTL8721D_RPTBUF_AHB_BASE), value)
#define WriteRPTBUFByte(offset, value)   rtl_outb((offset+RTL8721D_RPTBUF_AHB_BASE), value)

#define ReadRPTBUFDWord(offset)          (rtl_inl((offset+RTL8721D_RPTBUF_AHB_BASE)))
#define ReadRPTBUFWord(offset)           (rtl_inw((offset+RTL8721D_RPTBUF_AHB_BASE)))
#define ReadRPTBUFByte(offset)           (rtl_inb((offset+RTL8721D_RPTBUF_AHB_BASE)))

//3 RXFF
#define WriteRXFFDWord(offset, value)   rtl_outl((offset+RTL8721D_RXFF_AHB_BASE), value)
#define WriteRXFFWord(offset, value)    rtl_outw((offset+RTL8721D_RXFF_AHB_BASE), value)
#define WriteRXFFByte(offset, value)    rtl_outb((offset+RTL8721D_RXFF_AHB_BASE), value)

#define ReadRXFFDWord(offset)           (rtl_inl((offset+RTL8721D_RXFF_AHB_BASE)))
#define ReadRXFFWord(offset)            (rtl_inw((offset+RTL8721D_RXFF_AHB_BASE)))
#define ReadRXFFByte(offset)            (rtl_inb((offset+RTL8721D_RXFF_AHB_BASE)))

//3 TXFF
#define WriteTXFFDWord(offset, value)     rtl_outl((offset+RTL8721D_TXFF_AHB_BASE), value)
#define WriteTXFFWord(offset, value)      rtl_outw((offset+RTL8721D_TXFF_AHB_BASE), value)
#define WriteTXFFByte(offset, value)      rtl_outb((offset+RTL8721D_TXFF_AHB_BASE), value)

#define ReadTXFFDWord(offset)             (rtl_inl((offset+RTL8721D_TXFF_AHB_BASE)))
#define ReadTXFFWord(offset)              (rtl_inw((offset+RTL8721D_TXFF_AHB_BASE)))
#define ReadTXFFByte(offset)              (rtl_inb((offset+RTL8721D_TXFF_AHB_BASE)))

//3 Retention RAM
#define WriteRRamDWord(offset, value)     rtl_outl((offset+RETENTION_RAM_BASE), value)
#define WriteRRamWord(offset, value)      rtl_outw((offset+RETENTION_RAM_BASE), value)
#define WriteRRamByte(offset, value)      rtl_outb((offset+RETENTION_RAM_BASE), value)

#define ReadRRamDWord(offset)             (rtl_inl((offset+RETENTION_RAM_BASE)))
#define ReadRRamWord(offset)              (rtl_inw((offset+RETENTION_RAM_BASE)))
#define ReadRRamByte(offset)              (rtl_inb((offset+RETENTION_RAM_BASE)))

//3 TX report buffer access

#define ReadCtrlInfoByte(macid, offset)         rtl_inb(RTL8721D_CtrlInfo_BASE + (macid*40) + offset)    //macid range: 0~16; offset range: 0~40
#define ReadCtrlInfoDWord(macid, offset)        rtl_inl(RTL8721D_CtrlInfo_BASE + (macid*40) + offset)    //macid range: 0~16; offset range: 0~40
#define WriteCtrlInfoByte(macid, offset, val)   rtl_outb(RTL8721D_CtrlInfo_BASE + (macid*40) + offset, val)
#define WriteCtrlInfoDWord(macid, offset, val)  rtl_outl(RTL8721D_CtrlInfo_BASE + (macid*40) + offset, val)


#define WriteTxrptByte(macid,offset,val)        rtl_outb(RTL8721D_TRXRPT_BASE + (macid<<4) + offset, val) //macid range: 0~16; offset range: 0~15
#define WriteTxrptDWord(macid,offset,val)       rtl_outl(RTL8721D_TRXRPT_BASE + (macid<<4) + offset, val)
#define ReadTxrptByte(macid,offset)             rtl_inb(RTL8721D_TRXRPT_BASE + (macid<<4) + offset)
#define ReadTxrptDWord(macid,offset)            rtl_inl(RTL8721D_TRXRPT_BASE + (macid<<4) + offset)

#define ReadCRC5Byte(macid, offset)         	rtl_inb(RTL8721D_CRC5_BASE + (macid) + offset)       //rpt_idx range: 0~15; offset range: 0~1
#define WriteCRC5Byte(macid, offset, val)   	rtl_outb(RTL8721D_CRC5_BASE + (macid) + offset, val)

#define ReadNANrptByte(offset)                  rtl_inb(RTL8721D_NANRPT_BASE  + offset)
#define ReadNANrptDWORD(offset)                 rtl_inl(RTL8721D_NANRPT_BASE  + offset)
#define WriteNANrptByte(offset, val)            rtl_outb(RTL8721D_NANRPT_BASE + offset, val)
#define WriteNANrptDWORD(offset, val)           rtl_outl(RTL8721D_NANRPT_BASE + offset, val)

//3 BT mailbox
#define WriteBTMailboxDWord(offset, value)      rtl_outl((offset+RTL8721D_BT_MAILBOX_AHB_BASE), value)
#define WriteBTMailboxWord(offset, value)       rtl_outw((offset+RTL8721D_BT_MAILBOX_AHB_BASE), value)
#define WriteBTmailboxByte(offset, value)       rtl_outb((offset+RTL8721D_BT_MAILBOX_AHB_BASE), value)

#define ReadBTMailboxDWord(offset)             (rtl_inl((offset+RTL8721D_BT_MAILBOX_AHB_BASE)))
#define ReadBTMailboxWord(offset)              (rtl_inw((offset+RTL8721D_BT_MAILBOX_AHB_BASE)))
#define ReadBTMailboxByte(offset)              (rtl_inb((offset+RTL8721D_BT_MAILBOX_AHB_BASE)))

//3 DDMA
#define WriteDDMADWord(offset, value)           rtl_outl((offset+RTL8721D_DDMA_CTRL_AHB_BASE), value)
#define WriteDDMAWord(offset, value)            rtl_outw((offset+RTL8721D_DDMA_CTRL_AHB_BASE), value)
#define WriteDDMAByte(offset, value)            rtl_outb((offset+RTL8721D_DDMA_CTRL_AHB_BASE), value)

#define ReadDDMADWord(offset)                  (rtl_inl((offset+RTL8721D_DDMA_CTRL_AHB_BASE)))
#define ReadDDMAWord(offset)                   (rtl_inw((offset+RTL8721D_DDMA_CTRL_AHB_BASE)))
#define ReadDDMAByte(offset)                   (rtl_inb((offset+RTL8721D_DDMA_CTRL_AHB_BASE)))

//3 CPU
#define WriteCPUDWord(offset, value)        rtl_outl((offset+RTL8721D_LPSYSON_AHB_BASE), value)
#define WriteCPUWord(offset, value)         rtl_outw((offset+RTL8721D_LPSYSON_AHB_BASE), value)
#define WriteCPUByte(offset, value)         rtl_outb((offset+RTL8721D_LPSYSON_AHB_BASE), value)

#define ReadCPUDWord(offset)                (rtl_inl((offset+RTL8721D_LPSYSON_AHB_BASE)))
#define ReadCPUWord(offset)                 (rtl_inw((offset+RTL8721D_LPSYSON_AHB_BASE)))
#define ReadCPUByte(offset)                 (rtl_inb((offset+RTL8721D_LPSYSON_AHB_BASE)))

//Interrupt List
#ifdef _MCU_8051_
#define INT_USB_8721D         0
#define INT_WLAN_8721D        2
#define INT_UART_8721D        4
#define INT_SYS_8721D         8
#define INT_FT_8721D          9
#define INT_MAILBOX_8721D    10
#else
#define INT_USB_8721D
#define INT_WLAN_8721D
#define INT_UART_8721D
#define INT_SYS_8721D
#define INT_FT_8721D
#define INT_MAILBOX_8721D
#endif

//1 function pointer

//1 ROMFunc
//2 Basic ISR

#define UpdateISRWlan           			UpdateISRWlan_8721D_PTR
#define UpdateISRFT             			UpdateISRFT_8721D_PTR

#define ClrAllFWUsedIMR         			ClrAllFWUsedIMR_8721D_PTR
#define ClrAllFWUsedISR         			ClrAllFWUsedISR_8721D_PTR

#define setfwimr 							setfwimr_8721D_PTR
#define clrfwimr 							clrfwimr_8721D_PTR
#define setwlanimr 							setwlanimr_8721D_PTR
#define clrwlanimr 							clrwlanimr_8721D_PTR
#define setftimr					  		setftimr_8721D_PTR
#define clrftimr                     		clrftimr_8721D_PTR

//2 ddma
#define InitDDMA					  		InitDDMA_8721D_PTR
#define WaitDDMARDY                			WaitDDMARDY_8721D_PTR
#define ChkDDMAChksum               		ChkDDMAChksum_8721D_PTR
#define CheckDDMADone               		CheckDDMADone_8721D_PTR


//2 FWLBK
#define FwlbkLLTWrite               		FwlbkLLTWrite_8721D_PTR
#define FwlbkHWInitialLLT           		FwlbkHWInitialLLT_8721D_PTR
#define FwlbkDbgPrtU16              		FwlbkDbgPrtU16_8721D_PTR
#define FwlbkMode                   		FwlbkMode_8721D_PTR
#define FwlbkPreparePkt             		FwlbkPreparePkt_8721D_PTR
#define FwlbkModeSel                		FwlbkModeSel_8721D_PTR
#define FwlbkCheckRxPayload         		FwlbkCheckRxPayload_8721D_PTR
#define FwlbkSetCAM                 		FwlbkSetCAM_8721D_PTR
#define FwlbkUpdateParam            		FwlbkUpdateParam_8721D_PTR
#define FwlbkMcuPollMgq             		FwlbkMcuPollMgq_8721D_PTR
#define FwlbkModeTxNoCheck          		FwlbkModeTxNoCheck_8721D_PTR
#define FwlbkModeTx                 		FwlbkModeTx_8721D_PTR
#define FwlbkModeMaclbk             		FwlbkModeMaclbk_8721D_PTR
#define FwlbkModeSecTest            		FwlbkModeSecTest_8721D_PTR
#define FwlbkModeAFElbk             		FwlbkModeAFElbk_8721D_PTR
#define CheckFWLBKEnable        			CheckFWLBKEnable_8721D_PTR

//2 Basic IO
#define PollingReg                  		PollingReg_8721D_PTR
//GTimer
#define InitGTimer32us              		InitGTimer32us_8721D_PTR
#define InitGTimer1ms               		InitGTimer1ms_8721D_PTR
#define CheckBBRWIsStable               	CheckBBRWIsStable_8721D_PTR
#define PHY_QueryBBReg                  	PHY_QueryBBReg_8721D_PTR
#define PHY_SetBBReg                    	PHY_SetBBReg_8721D_PTR
#define ReadSECCAM 							ReadSECCAM_8721D_PTR
#define WriteSECCAM 						WriteSECCAM_8721D_PTR
#define ReadBACAM 							ReadBACAM_8721D_PTR
#define WriteBACAM 							WriteBACAM_8721D_PTR
#define ReadMBIDCAM 						ReadMBIDCAM_8721D_PTR
#define WriteMBIDCAM 						WriteMBIDCAM_8721D_PTR


//3 CMD
#define H2CInQueue              			H2CInQueue_8721D_PTR
#define H2CDeQueue              			H2CDeQueue_8721D_PTR
#define InitC2H                     		InitC2H_8721D_PTR
#define WaitC2HOk               			WaitC2HOk_8721D_PTR
#define C2HPKTRxDESC                		C2HPKTRxDESC_8721D_PTR
#define FillC2HContant                  	FillC2HContant_8721D_PTR
#define IssueC2HPKT                     	IssueC2HPKT_8721D_PTR
#define C2HDeQueue             	 			C2HDeQueue_8721D_PTR
#define C2HInQueue              			C2HInQueue_8721D_PTR
#define CheckMaxMacidNum        			CheckMaxMacidNum_8721D_PTR
#define SetMediaStatus          			SetMediaStatus_8721D_PTR
#define GetMediaStatus          			GetMediaStatus_8721D_PTR

//3 Packet
#define ChangeTransmiteRate         		ChangeTransmiteRate_8721D_PTR
#define PowerBitSetting                 	PowerBitSetting_8721D_PTR
#define IssuePSPoll                         IssuePSPoll_8721D_PTR
#define ChkandChangePS              		ChkandChangePS_8721D_PTR
#define IssueQNull                          IssueQNull_8721D_PTR
#define CTS2SelfSetting 					CTS2SelfSetting_8721D_PTR
#define IssueCTS2Self                   	IssueCTS2Self_8721D_PTR
#define CheckCPUMGQEmpty                	CheckCPUMGQEmpty_8721D_PTR
#define IssueRsvdPagePacketSetting    		IssueRsvdPagePacketSetting_8721D_PTR
#define ReadRxBuff                      	ReadRxBuff_8721D_PTR

//3 Powersave
#define SetSmartPSTimer						SetSmartPSTimer_8721D_PTR
#define	SetPwrStateReg						SetPwrStateReg_8721D_PTR
#define	ResetPSParm							ResetPSParm_8721D_PTR
#define	ChkTxQueueIsEmpty					ChkTxQueueIsEmpty_8721D_PTR
#define	Legacy_PS_Setting					Legacy_PS_Setting_8721D_PTR
#define PSModeSetting						PSModeSetting_8721D_PTR
#define	ConfigListenBeaconPeriod			ConfigListenBeaconPeriod_8721D_PTR
#define PSSetMode							PSSetMode_8721D_PTR
#define PS_S2ToS3State						PS_S2ToS3State_8721D_PTR
#define PS_S2ToS0State						PS_S2ToS0State_8721D_PTR
#define	PS_S3ToS2orS0State					PS_S3ToS2orS0State_8721D_PTR
#define	PS_S0ToS1State						PS_S0ToS1State_8721D_PTR
#define	PS_S1ToS0orS2State					PS_S1ToS0orS2State_8721D_PTR
#define	PS_S2ToS4State						PS_S2ToS4State_8721D_PTR
#define PS_S2ToS5State		        		PS_S2ToS5State_8721D_PTR
#define PS_S5ToS2State		        		PS_S5ToS2State_8721D_PTR
#define	PS_S4ToS2State						PS_S4ToS2State_8721D_PTR
#define	SmartPS2InitTimerAndToGetRxPkt		SmartPS2InitTimerAndToGetRxPkt_8721D_PTR
#define SetBcnEarlyAndTimeout				SetBcnEarlyAndTimeout_8721D_PTR
#define	EnlargeBcnEarlyAndTimeout			EnlargeBcnEarlyAndTimeout_8721D_PTR
#define ResetBcnEarlyAdjustParm				ResetBcnEarlyAdjustParm_8721D_PTR
#define PS_S0ToS6State						PS_S0ToS6State_8721D_PTR
#define PS_S6ToS0State						PS_S6ToS0State_8721D_PTR


//3 WoWlan
#define WakeUpHost              			WakeUpHost_8721D_PTR
#define GetIV                				GetIV_8721D_PTR
#define GetIVLenAndSecurityType 			GetIVLenAndSecurityType_8721D_PTR
#define GetMACHeaderLen         			GetMACHeaderLen_8721D_PTR
#define UpdateIV							UpdateIV_8721D_PTR
//GTK
#define AesTkipIvFun            			AesTkipIvFun_8721D_PTR
#define WepIvFun                			WepIvFun_8721D_PTR
#define RTmemcmpBackward       				RTmemcmpBackward_8721D_PTR
#define AssignIvToKeyRsc       				AssignIvToKeyRsc_8721D_PTR
#define AssignKeyRscToIV       				AssignKeyRscToIV_8721D_PTR
#define AesTkipIvCheck       				AesTkipIvCheck_8721D_PTR
#define WepIvCheck       					WepIvCheck_8721D_PTR

//3 BTCoex
#define BTRoleChangeTimerHDL			BTRoleChangeTimerHDL_8721D_PTR
#define BTRoleChangeTBTTHDL			BTRoleChangeTBTTHDL_8721D_PTR
#define FillMailbox			FillMailbox_8721D_PTR
#define WL2BTMailbox			WL2BTMailbox_8721D_PTR
#define MailboxINTHDL			MailboxINTHDL_8721D_PTR
#define BTMailboxRetry			BTMailboxRetry_8721D_PTR
#define H2CHDL_BTInfo			H2CHDL_BTInfo_8721D_PTR
#define H2CHDL_ForceBTTxpwr			H2CHDL_ForceBTTxpwr_8721D_PTR
#define H2CHDL_BTIgnoreWlanAct			H2CHDL_BTIgnoreWlanAct_8721D_PTR
#define H2CHDL_DACSwingValue			H2CHDL_DACSwingValue_8721D_PTR
#define H2CHDL_AntSelReverse			H2CHDL_AntSelReverse_8721D_PTR
#define H2CHDL_WLOpmode			H2CHDL_WLOpmode_8721D_PTR
#define H2CHDL_BTMpH2C			H2CHDL_BTMpH2C_8721D_PTR
#define H2CHDL_BTControl			H2CHDL_BTControl_8721D_PTR
#define H2CHDL_BTWifiCtrl			H2CHDL_BTWifiCtrl_8721D_PTR
#define H2CHDL_BT_Page_Scan_Interval			H2CHDL_BT_Page_Scan_Interval_8721D_PTR
#define H2CHDL_WLCalibration			H2CHDL_WLCalibration_8721D_PTR
#define H2CHDL_GNT_BT_CTRL			H2CHDL_GNT_BT_CTRL_8721D_PTR
#define H2CHDL_BT_ONLY_TEST			H2CHDL_BT_ONLY_TEST_8721D_PTR
#define H2CHDL_BT_Init_Param			H2CHDL_BT_Init_Param_8721D_PTR
#define C2HBTInfo			C2HBTInfo_8721D_PTR
#define C2HBTLoopback			C2HBTLoopback_8721D_PTR
#define C2HBTMpRpt			C2HBTMpRpt_8721D_PTR
#define C2HBTMailBoxStatus			C2HBTMailBoxStatus_8721D_PTR
#define InitBTMailbox			InitBTMailbox_8721D_PTR
#define InitBTypeTDMA2			InitBTypeTDMA2_8721D_PTR
#define InitBTCoexTimer			InitBTCoexTimer_8721D_PTR
#define Write778			Write778_8721D_PTR
#define ChangeCoexTable			ChangeCoexTable_8721D_PTR
#define DacSwing			DacSwing_8721D_PTR
#define BTNullSetting			BTNullSetting_8721D_PTR
#define IssueBTQNull			IssueBTQNull_8721D_PTR
#define WlanActCtrl			WlanActCtrl_8721D_PTR
#define BT_TDMA_Slot_Operation_0and3			BT_TDMA_Slot_Operation_0and3_8721D_PTR
#define BT_TDMA_Slot_Operation_1and4			BT_TDMA_Slot_Operation_1and4_8721D_PTR
#define BT_TDMA_Slot_Operation_2and5			BT_TDMA_Slot_Operation_2and5_8721D_PTR
#define FlexibleExtensionDecision			FlexibleExtensionDecision_8721D_PTR
#define BTypeTDMABCNEarly			BTypeTDMABCNEarly_8721D_PTR
#define BTypeTDMATBTThdl			BTypeTDMATBTThdl_8721D_PTR
#define BTypeTDMATimeOuthdl			BTypeTDMATimeOuthdl_8721D_PTR

//1 JumpRamFucPtr

//3 OS
#define OSSendSignalCommon      			OSSendSignalCommon_8721D_PTR
#define SendSignalCommon					SendSignalCommon_8721D_PTR
#define ISRSendSignalCommon     			ISRSendSignalCommon_8721D_PTR


//3 Powersave
#define Change_PS_State             		Change_PS_State_8721D_PTR
#define PS_S2_Condition_Match   			PS_S2_Condition_Match_8721D_PTR
#define PS_S4_Condition_Match   			PS_S4_Condition_Match_8721D_PTR
#define WriteTxPauseWithMask				WriteTxPauseWithMask_8721D_PTR
#define WaitTxStateMachineOk            	WaitTxStateMachineOk_8721D_PTR
#define WriteTxPause				     	WriteTxPause_8721D_PTR
#define PsOpenRF                         	PsOpenRF_8721D_PTR
#define PsCloseRF                        	PsCloseRF_8721D_PTR
#define IssueNullData                       IssueNullData_8721D_PTR

//3 CMD
#define H2CCmdFunc              			H2CCmdFunc_8721D_PTR

//3 BTCoex
#define BTRoleChangeDefaultSetting 		BTRoleChangeDefaultSetting_8721D_PTR
#define BackupAntennaSetting 		BackupAntennaSetting_8721D_PTR
#define MailboxINTHDL_Patch 		MailboxINTHDL_Patch_8721D_PTR
#define H2CHDL_BTPSTDMA 		H2CHDL_BTPSTDMA_8721D_PTR
#define H2CHDL_BTFwPatch 		H2CHDL_BTFwPatch_8721D_PTR

/*--------------------Define Enum---------------------------------------*/

/*--------------------Define MACRO--------------------------------------*/

/*--------------------Define Struct---------------------------------------*/

#ifndef __ASSEMBLY__

typedef struct _HAL_DATA_COMMON {

	u8  HCISel;

} HAL_DATA_COMMON, *PHAL_DATA_COMMON;

typedef struct _HAL_DATA_8721D {

	u32 fwimr[2];
	u32 fwisr[2];

	u32 wlanimr[6];
	u32 wlanisr[6];

	u32 ftimr[3];
	u32 ftisr[3];

} HAL_DATA_8721D, *PHAL_DATA_8721D;

#endif //__ASSEMBLY__
/*--------------------Export global variable-------------------------------*/

/*--------------------Function declaration---------------------------------*/


#endif  //__RTL8721D_HAL_H__

