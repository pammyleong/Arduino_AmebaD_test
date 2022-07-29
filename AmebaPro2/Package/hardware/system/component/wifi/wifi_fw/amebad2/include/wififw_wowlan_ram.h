#ifndef __WIFIFW_WoWLAN_RAM_H__
#define __WIFIFW_WoWLAN_RAM_H__

/*--------------------Define MACRO--------------------------------------*/
#define IOT_WAITHOST_TO     5
#define UDP_LENGTH_OFFSET                   4
#define UDP_CHECK_SUM_OFFSET                6
#define ROL32( A, n )	( ((A) << (n)) | ( ((A)>>(32-(n)))  & ( (1UL << (n)) - 1 ) ) )
#define ROR32( A, n ) 	ROL32( (A), 32-(n) )

struct mic_data {
	u32  	K0, K1;         // Key
	u32  	L, R;           // Current state
	u32  	M;              // Message accumulator (single word)
	u32 	nBytesInM;      // # bytes in M
};
/*--------------------Define Enum---------------------------------------*/

typedef enum _CHECK_SUM_PROTOCOL_ {
	IP_CHECK_SUM    = 0,
	TCP_CHECK_SUM   = 6,
	UDP_CHECK_SUM   = 17,
	ICMPV6_CHECK_SUM = 58,
} CHECK_SUM_PROTOCOL, *PCHECK_SUM_PROTOCOL;

/*--------------------Function declaration---------------------------------*/
extern void DisconnectChk_8730A(void);
extern void DisconnectTxNullChk_8730A(IN u8 pwr);
extern void InitRemoteWakeUp_8730A(void);
extern void RemoteWakeUp_8730A(void);
extern void ClearRxBuff_8730A(void);
extern void H2CHDL_RemoteWakeUp_8730A(u8 *pbuf);
extern void issue_ARP_8730A(u8 *TargetIP, u8 *TargetMAC, u8  retry_bit, u8  arpsel);
extern u32 GetSumValue_8730A(u32 offset, u16 pktLen);
extern u16 GetCheckSum_8730A(u8 protocol, u16 pktLen, u32 src_addr, u32 dest_addr, u32 input);
extern void UpdateCheckSumVer2_8730A(u8 mode, u32 offset);
extern void FillIpv6PseudoHeader_8730A(u8 *TargetIP, u8 *OurIP, u32  PayLoadLength, u8  NextHeader);
extern void IssueNA_8730A(u8 *TargetIP, u8 *TargetMAC, u8 *OurIP, u8 *OurMAC, u8  retry_bit, u8  ndpsel);
extern void KeepAliveChk_8730A(void);
extern void TryPKT_8730A(void);
extern void WakeUpHost_8730A(u8 source);

#endif  /* __WIFIFW_WoWLAN_RAM_H__ */
