#ifndef __WIFIFW_WoWLAN_RAM_H__
#define __WIFIFW_WoWLAN_RAM_H__

/*--------------------Define --------------------------------------------*/
#define REG_SECURITY_INFO_DBG       0x0484
#define UDP_LENGTH_OFFSET                   4
#define UDP_CHECK_SUM_OFFSET                6

/*--------------------Define MACRO--------------------------------------*/
#define IOT_WAITHOST_TO     5
#define ROL32( A, n )	( ((A) << (n)) | ( ((A)>>(32-(n)))  & ( (1UL << (n)) - 1 ) ) )
#define ROR32( A, n ) 	ROL32( (A), 32-(n) )

struct mic_data {
	u32  K0, K1;         // Key
	u32  L, R;           // Current state
	u32  M;              // Message accumulator (single word)
	u32     nBytesInM;      // # bytes in M
};

/*--------------------Define enum---------------------------------------*/
typedef enum _CHECK_SUM_PROTOCOL_ {
	IP_CHECK_SUM    = 0,
	TCP_CHECK_SUM   = 6,
	UDP_CHECK_SUM   = 17,
	ICMPV6_CHECK_SUM = 58,
} CHECK_SUM_PROTOCOL, *PCHECK_SUM_PROTOCOL;

/*--------------------Export global variable-------------------------------*/

/*--------------------Function declaration---------------------------------*/
extern s8
RTmemcmpBackward_8721D_RAM(
	const void *Dest,
	const void *Src,
	u8 count
);

extern u8
CheckIV(
	u8 *IVToCheck,
	u8 raaddr,
	BOOLEAN unicast_check
) ;

extern BOOLEAN
WaitRXDMAIdle(
	void
) ;

extern void
UpdateRxFFReadPtr_DropPkt(
	u16 RPtr
) ;

extern void
InitRemoteWakeUp(
	void
) ;

extern void
IssueProbeRsp(
	IN u8 probeLoc,
	IN u8 SAAddr[]
)  ;

extern void
RemoteWakeUp(
	void
) ;

extern void
H2CHDL_RemoteWakeUp(
	u8 *pbuf
) ;

extern void
H2CHDL_WoWLAN(
	u8 *pbuf
) ;

extern void
H2CHDL_AOACGlobalInfo(
	u8 *pbuf
) ;

extern void
H2CHDL_AOACRsvdpage1(
	u8 *pbuf
) ;

extern void
H2CHDL_AOACRsvdpage2(
	u8 *pbuf
) ;

extern void
H2CHDL_AOACRsvdpage3(
	u8 *pbuf
) ;

extern void
RemoteWakeupCtrl_hdl(
	u8 bFunEnable
);

extern void
ARP_hdl(
	u8 bFunEnable
);

extern void
NDP_hdl(
	u8 bFunEnable
);

extern void
GTK_hdl(
	u8 bFunEnable
);

extern void
issue_ARP(
	u8 *TargetIP,
	u8 *TargetMAC,
	u8  retry_bit,
	u8  arpsel
);

extern BOOLEAN
OnARP(
	u16 addrl_frame_ctrl,
	u8 MacHeaderLen
) ;

extern void
GetARPInfo(
	u8 pagenum
);
extern u32
GetSumValue(
	u32 offset,
	u16 pktLen
);

extern u16
GetCheckSum(
	u8 protocol,
	u16 pktLen,
	u32 src_addr,
	u32 dest_addr,
	u32 input
);

extern void
UpdateCheckSumVer2(
	u8 mode,
	u32 offset
);

void
GetNDPInfo(
	u8 pagenum
);

BOOLEAN
OnNS(
	u16 addrl_frame_ctrl,
	u8 MacHeaderLen
) ;
void
IssueNA(
	u8 *TargetIP,
	u8 *TargetMAC,
	u8 *OurIP,
	u8 *OurMAC,
	u8  retry_bit,
	u8  ndpsel

);

void
FillIpv6PseudoHeader(
	u8 *TargetIP,
	u8 *OurIP,
	u32  PayLoadLength,
	u8  NextHeader
);


BOOLEAN
IsIPV6(
	u16 addrl_frame_ctrl,
	u8 MacHeaderLen
)  ;

void
PassSecurityInfoToDriver(
	u8 pagenum
) ;


void
GetRemoteControlInfo(
	u8 pagenum
)
;


extern void
InitDisconnectDecision(
	void
) ;

extern void
DisconnectChk(
	void
) ;

extern void
DisconnectTxNullChk(
	IN u8 pwr
) ;

extern void
H2CHDL_DisconnectDecision(
	u8 *pbuf
) ;

extern void
InitKeepAlive(
	void
) ;

extern void
KeepAliveChk(
	void
) ;

extern void
WakeUpHost_8721D_RAM(
	IN u8 source
);

extern void
H2CHDL_KeepAlive(
	u8 *pbuf
) ;

extern u16
PageOffsetAlignment(
	IN u16 offset
) ;

//RX pkt unm  0x284+2
#define RXDMA_IDLE                  BIT1
#define STOP_RXDMA                  BIT2
#endif  //__WIFIFW_WoWLAN_RAM_H__
