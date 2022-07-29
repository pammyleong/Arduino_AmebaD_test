#ifndef __WIFIFW_HAL_H__
#define __WIFIFW_HAL_H__

#include "wififw_reg_rom.h"
#include "wififw_debug_rom.h"
#include "wififw_init_rom.h"
#include "wififw_interrupt_rom.h"
#include "wififw_btconcurr_rom.h"
#include "wififw_cmd_rom.h"
#include "wififw_packet_rom.h"
#include "wififw_powerctrl_rom.h"
#include "wififw_txreport_rom.h"
#include "wififw_dma_rom.h"
#include "wififw_hioe_rom.h"

/*--------------------------Define -------------------------------------------*/
//3 TaskBitMap0
#define RATEADAPTIVE        						BIT0
#define H2CEVENT            							BIT1
#define C2HEVENT            							BIT2
#define RLPSEVENT           							BIT3
#define REMOTEWAKEEVENT     						BIT4
#define APOFFLOADEVENT      						BIT5
#define SWTIMEREVENT        						BIT7
#define BTMAILBOXEVENT      						BIT8

//2 KM0 access base
//3 MAC base address
#define RTL8730A_IOREG_AHB_BASE					0x43000000
//3 BB base address
#define RTL8730A_BBREG_AHB_BASE             	0x43010000
//3 RF base address
#define RTL8730A_RFREG_AHB_BASE             	0x43017000
//3 DDMA control base address
#define RTL8730A_DDMA_CTRL_AHB_BASE         	0x43000000 //0x4000_1200- 0x4000_12FF
//3 BT mailbox base address
#define RTL8730A_BT_MAILBOX_AHB_BASE        	0x430011A4
//3 LPSYSON local base
#define RTL8730A_LPSYSON_AHB_BASE				0x42008000
//3 LLT Table base
#define RTL8730A_LLT_AHB_BASE					0x43050000//256 byte/entry
//3 TxReport Buffer base address
#define RTL8730A_RPTBUF_AHB_BASE            	0x43040000
#define RTL8730A_CtrlInfo_AHB_BASE          	(RTL8730A_RPTBUF_AHB_BASE)
#define RTL8730A_TRXRPT_AHB_BASE            	(RTL8730A_RPTBUF_AHB_BASE + 0x280)
#define RTL8730A_CRC5_AHB_BASE              	(RTL8730A_RPTBUF_AHB_BASE + 0xA80)
#define RTL8730A_NANRPT_AHB_BASE             	(RTL8730A_RPTBUF_AHB_BASE + 0xA90)
//3 Rx packet buffer base address
#define RTL8730A_RXFF_AHB_BASE              	0x43030000
//3 Tx packet buffer base address
#define RTL8730A_TXFF_AHB_BASE              	0x43020000
//3 CAM base address
#define RTL8730A_SECCAM_AHB_BASE            	0x43050800
#define RTL8730A_BACAM_AHB_BASE             	0x43051000
#define RTL8730A_MBIDCAM_AHB_BASE 				0x43051800
//2 sysreg access
#define SYSTEM_CTRL_BASE_LPPMC_OFFSET    	0x00000200

//2 DDMA access base
//3 MAC base address
#define RTL8730A_IOREG_DDMA_AXI_BASE			0x40000000
//3 BB base address
#define RTL8730A_BBREG_DDMA_AXI_BASE         0x40010000
//3 RF base address
#define RTL8730A_RFREG_DDMA_AXI_BASE         0x40017000
//3 DDMA control base address
#define RTL8730A_DDMA_CTRL_DDMA_AXI_BASE   0x40000000 //0x4000_1200- 0x4000_12FF
//3 BT mailbox base address
#define RTL8730A_BT_MAILBOX_DDMA_AXI_BASE  0x400011A4
//3 LLT Table base
#define RTL8730A_LLT_DDMA_AXI_BASE			0x40050000//256 byte/entry
//3 TxReport Buffer base address
#define RTL8730A_RPTBUF_DDMA_AXI_BASE     	0x40040000
#define RTL8730A_CtrlInfo_DDMA_AXI_BASE  	(RTL8730A_RPTBUF_AHB_BASE)
#define RTL8730A_TRXRPT_DDMA_AXI_BASE       	(RTL8730A_RPTBUF_AHB_BASE + 0x280)
#define RTL8730A_CRC5_DDMA_AXI_BASE          	(RTL8730A_RPTBUF_AHB_BASE + 0xA80)
#define RTL8730A_NANRPT_DDMA_AXI_BASE     	(RTL8730A_RPTBUF_AHB_BASE + 0xA90)
//3 Rx packet buffer base address
#define RTL8730A_RXFF_DDMA_AXI_BASE          	0x40030000
//3 Tx packet buffer base address
#define RTL8730A_TXFF_DDMA_AXI_BASE          	0x40020000
//3 CAM base address
#define RTL8730A_SECCAM_DDMA_AXI_BASE      	0x40050800
#define RTL8730A_BACAM_DDMA_AXI_BASE        	0x40051000
#define RTL8730A_MBIDCAM_DDMA_AXI_BASE 		0x40051800

//offset:
#define rtl_inb(offset)             				(*(volatile u8 *)((u32)offset))
#define rtl_inw(offset)             				(*(volatile u16 *)((u32)offset))
#define rtl_inl(offset)             				(*(volatile u32 *)((u32)offset))

#define rtl_outb(offset,val)        				do { (*(volatile u8 *)((u32)offset) = (val));    } while(0)
#define rtl_outw(offset,val)        				do { (*(volatile u16 *)((u32)offset) = (val));    } while(0)
#define rtl_outl(offset,val)        				do { (*(volatile u32 *)((u32)offset) = (val));    } while(0)

//3 MACREG
//offset :
#define WritePONRegDWord(offset, value)		rtl_outl((offset+RTL8730A_IOREG_AHB_BASE), value)
#define WritePONRegWord(offset, value)		rtl_outw((offset+RTL8730A_IOREG_AHB_BASE), value)
#define WritePONRegByte(offset, value) 		rtl_outb((offset+RTL8730A_IOREG_AHB_BASE), value)

#define ReadPONRegDWord(offset)             	(rtl_inl((offset+RTL8730A_IOREG_AHB_BASE)))
#define ReadPONRegWord(offset)              	(rtl_inw((offset+RTL8730A_IOREG_AHB_BASE)))
#define ReadPONRegByte(offset)              	(rtl_inb((offset+RTL8730A_IOREG_AHB_BASE)))

//offset :
#define WriteMACRegDWord(offset, value)		rtl_outl((offset+RTL8730A_IOREG_AHB_BASE), value)
#define WriteMACRegWord(offset, value)      	rtl_outw((offset+RTL8730A_IOREG_AHB_BASE), value)
#define WriteMACRegByte(offset, value)      	rtl_outb((offset+RTL8730A_IOREG_AHB_BASE), value)

#define ReadMACRegDWord(offset)             	(rtl_inl((offset+RTL8730A_IOREG_AHB_BASE)))
#define ReadMACRegWord(offset)              	(rtl_inw((offset+RTL8730A_IOREG_AHB_BASE)))
#define ReadMACRegByte(offset)              	(rtl_inb((offset+RTL8730A_IOREG_AHB_BASE)))

//3 LLT TABLE
#define WriteLLTTableDWord(offset, value)   rtl_outl((offset+RTL8730A_LLT_AHB_BASE), value)
#define WriteLLTTableWord(offset, value)   	rtl_outw((offset+RTL8730A_LLT_AHB_BASE), value)
#define WriteLLTTableByte(offset, value)   	rtl_outb((offset+RTL8730A_LLT_AHB_BASE), value)

#define ReadLLTTableDWord(offset)           	(rtl_inl((offset+RTL8730A_LLT_AHB_BASE)))
#define ReadLLTTableWord(offset)            	(rtl_inw((offset+RTL8730A_LLT_AHB_BASE)))
#define ReadLLTTableByte(offset)            	(rtl_inb((offset+RTL8730A_LLT_AHB_BASE)))

//3 BB Reg
#define WritePortBBUlong(offset, value)		rtl_outl((offset+RTL8730A_BBREG_AHB_BASE), value)
#define WritePortBBUshort(offset, value)  	rtl_outw((offset+RTL8730A_BBREG_AHB_BASE), value)
#define WritePortBBUchar(offset, value)     rtl_outb((offset+RTL8730A_BBREG_AHB_BASE), value)

#define ReadPortBBUlong(offset)             	(rtl_inl((offset+RTL8730A_BBREG_AHB_BASE)))
#define ReadPortBBUshort(offset)            	(rtl_inw((offset+RTL8730A_BBREG_AHB_BASE)))
#define ReadPortBBUchar(offset)             	(rtl_inb((offset+RTL8730A_BBREG_AHB_BASE)))

//3 RF Reg only support dword mode
#define WritePortRFUlong(offset, value)     	rtl_outl((4*offset+RTL8730A_RFREG_AHB_BASE), value)
#define ReadPortRFUlong(offset)             	(rtl_inl((4*offset+RTL8730A_RFREG_AHB_BASE)))

//3 SEC CAM
#define WriteSECCAMDWord(offset, value)  	rtl_outl((offset+RTL8730A_SECCAM_AHB_BASE), value)
#define WriteSECCAMWord(offset, value)   	rtl_outw((offset+RTL8730A_SECCAM_AHB_BASE), value)
#define WriteSECCAMByte(offset, value)   	rtl_outb((offset+RTL8730A_SECCAM_AHB_BASE), value)

#define ReadSECCAMDWord(offset)          		(rtl_inl((offset+RTL8730A_SECCAM_AHB_BASE)))
#define ReadSECCAMWord(offset)           		(rtl_inw((offset+RTL8730A_SECCAM_AHB_BASE)))
#define ReadSECCAMByte(offset)           		(rtl_inb((offset+RTL8730A_SECCAM_AHB_BASE)))

//3 MBID CAM
#define WriteMBIDCAMDWord(offset, value)  	rtl_outl((offset+RTL8730A_MBIDCAM_AHB_BASE), value)
#define WriteMBIDCAMWord(offset, value)   	rtl_outw((offset+RTL8730A_MBIDCAM_AHB_BASE), value)
#define WriteMBIDCAMByte(offset, value)   	rtl_outb((offset+RTL8730A_MBIDCAM_AHB_BASE), value)

#define ReadMBIDCAMDWord(offset)          		(rtl_inl((offset+RTL8730A_MBIDCAM_AHB_BASE)))
#define ReadMBIDCAMWord(offset)           		(rtl_inw((offset+RTL8730A_MBIDCAM_AHB_BASE)))
#define ReadMBIDCAMByte(offset)           		(rtl_inb((offset+RTL8730A_MBIDCAM_AHB_BASE)))

//3 BA CAM
#define WriteBACAMDWord(offset, value)  		rtl_outl((offset+RTL8730A_BACAM_AHB_BASE), value)
#define WriteBACAMWord(offset, value)   		rtl_outw((offset+RTL8730A_BACAM_AHB_BASE), value)
#define WriteBACAMByte(offset, value)   		rtl_outb((offset+RTL8730A_BACAM_AHB_BASE), value)

#define ReadBACAMDWord(offset)          		(rtl_inl((offset+RTL8730A_BACAM_AHB_BASE)))
#define ReadBACAMWord(offset)           		(rtl_inw((offset+RTL8730A_BACAM_AHB_BASE)))
#define ReadBACAMByte(offset)           		(rtl_inb((offset+RTL8730A_BACAM_AHB_BASE)))

//3 ReportBUFF
#define WriteRPTBUFDWord(offset, value)  	rtl_outl((offset+RTL8730A_RPTBUF_AHB_BASE), value)
#define WriteRPTBUFWord(offset, value)   	rtl_outw((offset+RTL8730A_RPTBUF_AHB_BASE), value)
#define WriteRPTBUFByte(offset, value)   	rtl_outb((offset+RTL8730A_RPTBUF_AHB_BASE), value)

#define ReadRPTBUFDWord(offset)          		(rtl_inl((offset+RTL8730A_RPTBUF_AHB_BASE)))
#define ReadRPTBUFWord(offset)           		(rtl_inw((offset+RTL8730A_RPTBUF_AHB_BASE)))
#define ReadRPTBUFByte(offset)           		(rtl_inb((offset+RTL8730A_RPTBUF_AHB_BASE)))

//3 RXFF
#define WriteRXFFDWord(offset, value)   		rtl_outl((offset+RTL8730A_RXFF_AHB_BASE), value)
#define WriteRXFFWord(offset, value)    		rtl_outw((offset+RTL8730A_RXFF_AHB_BASE), value)
#define WriteRXFFByte(offset, value)    		rtl_outb((offset+RTL8730A_RXFF_AHB_BASE), value)

#define ReadRXFFDWord(offset)           		(rtl_inl((offset+RTL8730A_RXFF_AHB_BASE)))
#define ReadRXFFWord(offset)            			(rtl_inw((offset+RTL8730A_RXFF_AHB_BASE)))
#define ReadRXFFByte(offset)            			(rtl_inb((offset+RTL8730A_RXFF_AHB_BASE)))

//3 TXFF
#define WriteTXFFDWord(offset, value)     	rtl_outl((offset+RTL8730A_TXFF_AHB_BASE), value)
#define WriteTXFFWord(offset, value)      	rtl_outw((offset+RTL8730A_TXFF_AHB_BASE), value)
#define WriteTXFFByte(offset, value)      	rtl_outb((offset+RTL8730A_TXFF_AHB_BASE), value)

#define ReadTXFFDWord(offset)             		(rtl_inl((offset+RTL8730A_TXFF_AHB_BASE)))
#define ReadTXFFWord(offset)              		(rtl_inw((offset+RTL8730A_TXFF_AHB_BASE)))
#define ReadTXFFByte(offset)              		(rtl_inb((offset+RTL8730A_TXFF_AHB_BASE)))

//3 Retention RAM
#define WriteRRamDWord(offset, value)     	rtl_outl((offset+RETENTION_RAM_BASE), value)
#define WriteRRamWord(offset, value)      	rtl_outw((offset+RETENTION_RAM_BASE), value)
#define WriteRRamByte(offset, value)     	 	rtl_outb((offset+RETENTION_RAM_BASE), value)

#define ReadRRamDWord(offset)             		(rtl_inl((offset+RETENTION_RAM_BASE)))
#define ReadRRamWord(offset)              		(rtl_inw((offset+RETENTION_RAM_BASE)))
#define ReadRRamByte(offset)              		(rtl_inb((offset+RETENTION_RAM_BASE)))

//3 TX report buffer access

#define ReadCtrlInfoByte(macid, offset) 		rtl_inb(RTL8730A_CtrlInfo_AHB_BASE + (macid*40) + offset)    //macid range: 0~16; offset range: 0~40
#define ReadCtrlInfoDWord(macid, offset) 	rtl_inl(RTL8730A_CtrlInfo_AHB_BASE + (macid*40) + offset)    //macid range: 0~16; offset range: 0~40
#define WriteCtrlInfoByte(macid, offset, val)		rtl_outb(RTL8730A_CtrlInfo_AHB_BASE + (macid*40) + offset, val)
#define WriteCtrlInfoDWord(macid, offset, val)	rtl_outl(RTL8730A_CtrlInfo_AHB_BASE + (macid*40) + offset, val)


#define WriteTxrptByte(macid,offset,val)	rtl_outb(RTL8730A_TRXRPT_AHB_BASE + (macid<<4) + offset, val) //macid range: 0~16; offset range: 0~15
#define WriteTxrptDWord(macid,offset,val)	rtl_outl(RTL8730A_TRXRPT_AHB_BASE + (macid<<4) + offset, val)
#define ReadTxrptByte(macid,offset)   		rtl_inb(RTL8730A_TRXRPT_AHB_BASE + (macid<<4) + offset)
#define ReadTxrptDWord(macid,offset)  		rtl_inl(RTL8730A_TRXRPT_AHB_BASE + (macid<<4) + offset)

#define ReadCRC5Byte(macid, offset)  			rtl_inb(RTL8730A_CRC5_AHB_BASE + (macid) + offset)       //rpt_idx range: 0~15; offset range: 0~1
#define WriteCRC5Byte(macid, offset, val)  	rtl_outb(RTL8730A_CRC5_AHB_BASE + (macid) + offset, val)

#define ReadNANrptByte(offset)         			rtl_inb(RTL8730A_NANRPT_AHB_BASE  + offset)
#define ReadNANrptDWORD(offset)        			rtl_inl(RTL8730A_NANRPT_AHB_BASE  + offset)
#define WriteNANrptByte(offset, val)      	rtl_outb(RTL8730A_NANRPT_AHB_BASE + offset, val)
#define WriteNANrptDWORD(offset, val)      	rtl_outl(RTL8730A_NANRPT_AHB_BASE + offset, val)

//3 BT mailbox
#define WriteBTMailboxDWord(offset, value)	rtl_outl((offset+RTL8730A_BT_MAILBOX_AHB_BASE), value)
#define WriteBTMailboxWord(offset, value)	rtl_outw((offset+RTL8730A_BT_MAILBOX_AHB_BASE), value)
#define WriteBTmailboxByte(offset, value)	rtl_outb((offset+RTL8730A_BT_MAILBOX_AHB_BASE), value)

#define ReadBTMailboxDWord(offset)        	(rtl_inl((offset+RTL8730A_BT_MAILBOX_AHB_BASE)))
#define ReadBTMailboxWord(offset)          	(rtl_inw((offset+RTL8730A_BT_MAILBOX_AHB_BASE)))
#define ReadBTMailboxByte(offset)        		(rtl_inb((offset+RTL8730A_BT_MAILBOX_AHB_BASE)))

//3 DDMA
#define WriteDDMADWord(offset, value)     	rtl_outl((offset+RTL8730A_DDMA_CTRL_AHB_BASE), value)
#define WriteDDMAWord(offset, value)      	rtl_outw((offset+RTL8730A_DDMA_CTRL_AHB_BASE), value)
#define WriteDDMAByte(offset, value)      	rtl_outb((offset+RTL8730A_DDMA_CTRL_AHB_BASE), value)

#define ReadDDMADWord(offset)             		(rtl_inl((offset+RTL8730A_DDMA_CTRL_AHB_BASE)))
#define ReadDDMAWord(offset)                		(rtl_inw((offset+RTL8730A_DDMA_CTRL_AHB_BASE)))
#define ReadDDMAByte(offset)               		(rtl_inb((offset+RTL8730A_DDMA_CTRL_AHB_BASE)))

//3 lpssyson
#define WriteLSONDWord(offset, value)        rtl_outl((offset+RTL8730A_LPSYSON_AHB_BASE), value)
#define WriteLSONWord(offset, value)         	rtl_outw((offset+RTL8730A_LPSYSON_AHB_BASE), value)
#define WriteLSONByte(offset, value)         	rtl_outb((offset+RTL8730A_LPSYSON_AHB_BASE), value)

#define ReadLSONDWord(offset)                	(rtl_inl((offset+RTL8730A_LPSYSON_AHB_BASE)))
#define ReadLSONWord(offset)                 	(rtl_inw((offset+RTL8730A_LPSYSON_AHB_BASE)))
#define ReadLSONByte(offset)                 	(rtl_inb((offset+RTL8730A_LPSYSON_AHB_BASE)))

//2 function pointer

//3 ROMFunc
//2 Basic ISR
#define UpdateISRWlan           			UpdateISRWlan_8730A_PTR
#define UpdateISRFT             				UpdateISRFT_8730A_PTR
#define ClrAllFWUsedIMR         			ClrAllFWUsedIMR_8730A_PTR
#define ClrAllFWUsedISR         			ClrAllFWUsedISR_8730A_PTR
#define setfwimr 								setfwimr_8730A_PTR
#define clrfwimr 								clrfwimr_8730A_PTR
#define setwlanimr 							setwlanimr_8730A_PTR
#define clrwlanimr 							clrwlanimr_8730A_PTR
#define setftimr					  			setftimr_8730A_PTR
#define clrftimr                     			clrftimr_8730A_PTR

//2 ddma
#define InitDDMA					  			InitDDMA_8730A_PTR
#define WaitDDMARDY                			WaitDDMARDY_8730A_PTR
#define ChkDDMAChksum               		ChkDDMAChksum_8730A_PTR
#define CheckDDMADone               		CheckDDMADone_8730A_PTR

//2 Basic IO
//GTimer
#define 	InitGTimer32us              		InitGTimer32us_8730A_PTR
#define 	InitGTimer1ms               		InitGTimer1ms_8730A_PTR

//3 CMD
#define 	H2CInQueue              			H2CInQueue_8730A_PTR
#define 	H2CDeQueue              			H2CDeQueue_8730A_PTR
#define 	InitC2H                     			InitC2H_8730A_PTR
#define 	WaitC2HOk               				WaitC2HOk_8730A_PTR
#define 	C2HPKTRxDESC                		C2HPKTRxDESC_8730A_PTR
#define 	FillC2HContant                  	FillC2HContant_8730A_PTR
#define 	IssueC2HPKT                     	IssueC2HPKT_8730A_PTR
#define 	C2HDeQueue             	 			C2HDeQueue_8730A_PTR
#define 	C2HInQueue              			C2HInQueue_8730A_PTR
#define 	CheckMaxMacidNum        			CheckMaxMacidNum_8730A_PTR
#define 	SetMediaStatus          			SetMediaStatus_8730A_PTR
#define 	GetMediaStatus          			GetMediaStatus_8730A_PTR
#define 	MediaDisconnection				Media_Disconnection_8730A_PTR

//3 Packet
#define 	ChangeTransmiteRate         	ChangeTransmiteRate_8730A_PTR
#define 	PowerBitSetting                 	PowerBitSetting_8730A_PTR
#define 	IssuePSPoll                       	IssuePSPoll_8730A_PTR
#define 	ChkandChangePS              		ChkandChangePS_8730A_PTR
#define 	IssueQNull                          IssueQNull_8730A_PTR
#define 	CTS2SelfSetting 					CTS2SelfSetting_8730A_PTR
#define 	IssueCTS2Self                   	IssueCTS2Self_8730A_PTR
#define 	IssueRsvdPagePacketSetting 	IssueRsvdPagePacketSetting_8730A_PTR
#define 	ReadRxBuff                      	ReadRxBuff_8730A_PTR
#define 	WaitCPUMGQEmpty					WaitCPUMGQEmpty_8730A_PTR
#define 	PollingReg							PollingReg_8730A_PTR

//3 Powersave
//LPS offload
#define 	LPSOfld_HIOECmdFileToTXFF 	LPSOfld_HIOECmdFileToTXFF_8730A_PTR
#define 	LPSOfld_HIOECmdFileInit 		LPSOfld_HIOECmdFileInit_8730A_PTR
#define 	LPSOfld_HIOECmdFilePGRSInit 	LPSOfld_HIOECmdFilePGRSInit_8730A_PTR
#define 	LPSOfld_ByPassLsysWakeInt 	LPSOfld_ByPassLsysWakeInt_8730A_PTR
#define 	LPSOfld_SwtHIOECmdFile 		LPSOfld_SwtHIOECmdFile_8730A_PTR
#define 	LPSOfld_IMRSetting 				LPSOfld_IMRSetting_8730A_PTR
#define 	LPSOfld_SetBcnErlyandTimeout	LPSOfld_SetBcnErlyandTimeout_8730A_PTR
#define 	LPSOfld_FuncInit 					LPSOfld_FuncInit_8730A_PTR
#define 	LPSOfld_RPWMExitPG 					LPSOfld_RPWMExitPG_8730A_PTR
#define 	LPSOfld_HWCtrlTRXOnOff 		LPSOfld_HWCtrlTRXOnOff_8730A_PTR
#define   LPSOfld_Reload_PHYREG	LPSOfld_Reload_PHYREG_8730A_PTR
#define 	SetSmartPSTimer					SetSmartPSTimer_8730A_PTR
#define	SetPwrStateReg					SetPwrStateReg_8730A_PTR
#define	ResetPSParm							ResetPSParm_8730A_PTR
#define	ChkTxQueueIsEmpty				ChkTxQueueIsEmpty_8730A_PTR
#define	Legacy_PS_Setting				Legacy_PS_Setting_8730A_PTR
#define 	PSModeSetting						PSModeSetting_8730A_PTR
#define	ConfigListenBeaconPeriod		ConfigListenBeaconPeriod_8730A_PTR
#define 	PSSetMode							PSSetMode_8730A_PTR
#define 	PS_S2ToS3State					PS_S2ToS3State_8730A_PTR
#define 	PS_S2ToS0State					PS_S2ToS0State_8730A_PTR
#define	PS_S3ToS2orS0State				PS_S3ToS2orS0State_8730A_PTR
#define	PS_S0ToS1State					PS_S0ToS1State_8730A_PTR
#define	PS_S1ToS0orS2State				PS_S1ToS0orS2State_8730A_PTR
#define	PS_S2ToS4State					PS_S2ToS4State_8730A_PTR
#define 	PS_S2ToS5State		        	PS_S2ToS5State_8730A_PTR
#define 	PS_S5ToS2State		        	PS_S5ToS2State_8730A_PTR
#define	PS_S4ToS2State					PS_S4ToS2State_8730A_PTR
#define	SmartPS2InitTimerAndToGetRxPkt	SmartPS2InitTimerAndToGetRxPkt_8730A_PTR
#define 	SetBcnEarlyAndTimeout			SetBcnEarlyAndTimeout_8730A_PTR
#define	EnlargeBcnEarlyAndTimeout		EnlargeBcnEarlyAndTimeout_8730A_PTR
#define 	PS_S0ToS6State					PS_S0ToS6State_8730A_PTR
#define 	PS_S6ToS0State					PS_S6ToS0State_8730A_PTR

//3 WoWlan
#define  InitKeepAlive						InitKeepAlive_8730A_PTR
#define  H2CHDL_KeepAlive					H2CHDL_KeepAlive_8730A_PTR
#define  UpdateRxFFReadPtr_DropPkt		UpdateRxFFReadPtr_DropPkt_8730A_PTR
#define  WaitRXDMAIdle						WaitRXDMAIdle_8730A_PTR
#define  PageOffsetAlignment				PageOffsetAlignment_8730A_PTR
#define  DropCHK								DropCHK_8730A_PTR
#define  EnableWoWLAN 						EnableWoWLAN_8730A_PTR
#define  DisWoWLAN 							DisWoWLAN_8730A_PTR
#define  H2CHDL_WoWLAN 						H2CHDL_WoWLAN_8730A_PTR
#define  DropDecision 						DropDecision_8730A_PTR
#define  FwDisConnectWakeUpHost			FwDisConnectWakeUpHost_8730A_PTR
#define  DestinationMatch					DestinationMatch_8730A_PTR
#define  PassSecurityInfoToDriver		PassSecurityInfoToDriver_8730A_PTR
#define  GetRemoteControlInfo 			GetRemoteControlInfo_8730A_PTR
#define  GetARPInfo 							GetARPInfo_8730A_PTR
#define  OnARP									OnARP_8730A_PTR
#define  GetNDPInfo 							GetNDPInfo_8730A_PTR
#define  IsIPV6 								IsIPV6_8730A_PTR
#define  OnNS									OnNS_8730A_PTR
#define  Ipv4Match 							Ipv4Match_8730A_PTR
#define  MatchUnicastFilter 				MatchUnicastFilter_8730A_PTR
#define  WakeUpHostDecision				WakeUpHostDecision_8730A_PTR
#define  CheckIV 								CheckIV_8730A_PTR
#define  H2CHDL_AOACGlobalInfo			H2CHDL_AOACGlobalInfo_8730A_PTR
#define  H2CHDL_AOACRsvdpage1			H2CHDL_AOACRsvdpage1_8730A_PTR
#define  H2CHDL_AOACRsvdpage2 			H2CHDL_AOACRsvdpage2_8730A_PTR
#define  H2CHDL_AOACRsvdpage3 			H2CHDL_AOACRsvdpage3_8730A_PTR
#define  GetAddr 								GetAddr_8730A_PTR
#define  ARP_hdl 								ARP_hdl_8730A_PTR
#define  NDP_hdl 								NDP_hdl_8730A_PTR
#define  InitDisconnectDecision 		InitDisconnectDecision_8730A_PTR
#define  DisconnectChk						DisconnectChk_8730A_PTR
#define  DisconnectTxNullChk 			DisconnectTxNullChk_8730A_PTR
#define  H2CHDL_DisconnectDecision 	H2CHDL_DisconnectDecision_8730A_PTR

#define 	WakeUpHost              			WakeUpHost_8730A_PTR
#define 	issue_ARP							issue_ARP_8730A_PTR
#define 	IssueNA								IssueNA_8730A_PTR
#define 	GetIV                					GetIV_8730A_PTR
#define 	GetIVLenAndSecurityType 		GetIVLenAndSecurityType_8730A_PTR
#define 	GetMACHeaderLen         			GetMACHeaderLen_8730A_PTR
#define 	UpdateIV								UpdateIV_8730A_PTR
//GTK
#define 	AesTkipIvFun            			AesTkipIvFun_8730A_PTR
#define 	WepIvFun                				WepIvFun_8730A_PTR
#define 	RTmemcmpBackward       			RTmemcmpBackward_8730A_PTR
#define 	AssignIvToKeyRsc       			AssignIvToKeyRsc_8730A_PTR
#define 	AssignKeyRscToIV       			AssignKeyRscToIV_8730A_PTR
#define 	AesTkipIvCheck       				AesTkipIvCheck_8730A_PTR
#define 	WepIvCheck       					WepIvCheck_8730A_PTR

//3 BTCoex
#define 	H2CHDL_BTInfo						H2CHDL_BTInfo_8730A_PTR
#define 	H2CHDL_ForceBTTxpwr				H2CHDL_ForceBTTxpwr_8730A_PTR
#define 	H2CHDL_BTIgnoreWlanAct			H2CHDL_BTIgnoreWlanAct_8730A_PTR
#define 	H2CHDL_AntSelReverse			H2CHDL_AntSelReverse_8730A_PTR
#define	H2CHDL_WLOpmode					H2CHDL_WLOpmode_8730A_PTR
#define 	H2CHDL_BTMpH2C					H2CHDL_BTMpH2C_8730A_PTR
#define 	H2CHDL_BTControl					H2CHDL_BTControl_8730A_PTR
#define 	H2CHDL_BT_Page_Scan_Interval	H2CHDL_BT_Page_Scan_Interval_8730A_PTR
#define 	H2CHDL_GNT_BT_Ctrl				H2CHDL_GNT_BT_Ctrl_8730A_PTR
#define 	H2CHDL_BT_Only_Test				H2CHDL_BT_Only_Test_8730A_PTR
#define 	H2CHDL_WL_Port_ID				H2CHDL_WL_Port_ID_8730A_PTR
#define 	C2HBTLoopback						C2HBTLoopback_8730A_PTR
#define 	C2HBTMpRpt							C2HBTMpRpt_8730A_PTR
#define 	C2HBTMailBoxStatus				C2HBTMailBoxStatus_8730A_PTR
#define 	InitBTCoexTimer					InitBTCoexTimer_8730A_PTR
#define 	Write778								Write778_8730A_PTR
#define 	TdmaChangeCoexTable				TdmaChangeCoexTable_8730A_PTR
#define 	BTNullSetting						BTNullSetting_8730A_PTR

//1 JumpRamFucPtr

//3 OS
#define 	OSSendSignalCommon      			OSSendSignalCommon_8730A_PTR
#define 	SendSignalCommon					SendSignalCommon_8730A_PTR
#define 	ISRSendSignalCommon     		ISRSendSignalCommon_8730A_PTR

//3 Powersave
#define 	Change_PS_State             		Change_PS_State_8730A_PTR
#define 	PS_S2_Condition_Match   		PS_S2_Condition_Match_8730A_PTR
#define 	PS_S4_Condition_Match   		PS_S4_Condition_Match_8730A_PTR
#define 	WriteTxPauseWithMask			WriteTxPauseWithMask_8730A_PTR
#define 	WaitTxStateMachineOk       		WaitTxStateMachineOk_8730A_PTR
#define 	WriteTxPause				     	WriteTxPause_8730A_PTR
#define 	PsOpenRF                         	PsOpenRF_8730A_PTR
#define 	PsCloseRF                        	PsCloseRF_8730A_PTR
#define 	IssueNullData                     IssueNullData_8730A_PTR

//3 CMD
#define 	H2CCmdFunc              			H2CCmdFunc_8730A_PTR

//3 BTCoex
#define 	WL2BTMailboxSend					WL2BTMailboxSend_8730A_PTR

/*--------------------Define Struct---------------------------------------*/
#ifndef __ASSEMBLY__
typedef struct _HAL_DATA_COMMON {
	u8  HCISel;
} HAL_DATA_COMMON, *PHAL_DATA_COMMON;

typedef struct _HAL_DATA_8730A {

	u32 fwimr[2];
	u32 fwisr[2];

	u32 wlanimr[6];
	u32 wlanisr[6];

	u32 ftimr[3];
	u32 ftisr[3];

} HAL_DATA_8730A, *PHAL_DATA_8730A;

#endif /* __ASSEMBLY__ */

/*--------------------Function declaration---------------------------------*/

#endif /* __WIFIFW_HAL_H__ */
