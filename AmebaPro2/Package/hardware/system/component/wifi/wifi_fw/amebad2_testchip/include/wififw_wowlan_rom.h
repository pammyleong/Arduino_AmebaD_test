#ifndef __WLAN_WoWLAN_H__
#define __WLAN_WoWLAN_H__

/*--------------------Define --------------------------------------------*/
#define REG_WoW_REASON          REG_DBG_BYTE_5   //1C7

#define Rx_Pairwisekey          0x01
#define Rx_GTK                  0x02
#define Rx_Fourway_Handshake    0x03
#define Rx_DisAssoc             0x04
#define Rx_DeAuth               0x08
#define Rx_ArpRequest           0x09
#define Rx_NS                       0x0a
#define RX_EAPREQ_IDENTIFY 0x0b
#define FWDecisionDisconnect    0x10
#define Rx_MagicPkt             0x21
#define Rx_UnicastPkt           0x22
#define Rx_PatternPkt           0x23
#define RTD3_SSID_Match         0x24
#define HW_RX_WAKEUP_PATTERN    0x25
#define RX_RealWoW_V2_WakeupPkt 0x30
#define RX_RealWoW_V2_AckLost   0x31
#define Enable_Fail_DMAIdle     0x40
#define Enable_Fail_DMAPause    0x41
#define RTime_Fail_DMAIdle      0x42
#define RTime_Fail_DMAPause     0x43
#define RxShift_Error       0x44
#define BT_Wakeup_Host          0x45
#define NLO_SSID_Match          0x55
#define AP_Offload_WakeUp       0x66
#define CLK_32K_UNLOCK          0xFD
#define CLK_32K_LOCK            0xFE


#define RXINDIRECTPAGESIZE  0xFF

#define DEFAULT_DISCONNECT_COUNT_LIMIT      8       //UNIT: beacon interval
#define DEFAULT_TRY_PKT_LIMIT               3
#define KeepAliveUnit                       10      //UNIT: beacon interval
#define DEFAULT_KEEP_ALIVE_COUNT_LIMIT      0x0A    //Unit: BCN interval
#define WAIT_RXDMA_CNT                      (2000)
#define CHECK_RXDMA_ONCE_TIME               (10)
#define SDD1RDY                             BIT3
#define MAGIC_WAKEUP                        BIT7
#define UNICAST_WAKEUP                      BIT6
#define PATTERN_WAKEUP                      BIT5
#define WAKEUPFEATURE                       BIT2
#define DMAIDLE                             BIT1
#define DMAPAUSE                            BIT2
#define ProtectedFrame                      BIT6

#define ARP_SEL_PASSIVE_RESPONSE            0
#define ARP_SEL_KEEPALIVE_UNICAST_GATEWAY   1

#define NDP_SEL_PASSIVE_RESPONSE            0
#define NDP_SEL_KEEPALIVE_UNICAST_GATEWAY   1


#define KEEPALIVE_TYPE_NULLDATA             0
#define KEEPALIVE_TYPE_ARP_RESPONSE         1

#define ARP_ACTION_ARP_RESPONSE             0
#define ARP_ACTION_WAKEUP_HOST              1

#define WAKEUP_HOST_FROM_AP_OFFLOAD         0
#define WAKEUP_HOST_FROM_WOWLAN             1

//WakeupHostDecision function Control
#define CHECK_WAKEUP_BY_DESC                BIT0
#define CHECK_WAKEUP_BY_INT                 BIT1

// below is IPv6 header offset
#define IPv6_ALEN               16
#define IPv6_NEXT_HEADER_OFFSET 6
#define IPv6_SRC_ADDRESS_OFFSET 8
#define CLIENT_PORT_IN_SRC_IPv6_OFFSET (IPv6_SRC_ADDRESS_OFFSET+10)
#define CLIENT_IPv4_IN_SRC_IPv6_OFFSET (IPv6_SRC_ADDRESS_OFFSET+12)
#define IPv6_DES_ADDRESS_OFFSET 24
#define IPv6_HEADER             40

// below is IPv6 header offset
#define ICMPV6_TYPE_OFFSET             0
#define ICMPV6_CHECKSUM_OFFSET         2
#define ICMPV6_TARGETADDRESS_OFFSET        8
#define ICMPV6_OPTION_TYPE_OFFSET      24
#define ICMPV6_OPTION_LENGTH_OFFSET    25
#define ICMPV6_OPTION_TARGET_ADDR_OFFSET    26
#define ICMPV6_HEADER           32
#define ICMP_CHECKSUM_SRC_ADDR_OFFSET    0
#define ICMP_CHECKSUM_DES_ADDR_OFFSET    72
/*--------------------Define Enum---------------------------------------*/
enum WIFI_FRAME_TYPE {
	WIFI_MGT_TYPE  = (0),
	WIFI_CTRL_TYPE = (BIT2),
	WIFI_DATA_TYPE = (BIT3),
};

enum WIFI_FRAME_SUBTYPE {

	// below is for mgt frame
	WIFI_ASSOCREQ       = (0 | WIFI_MGT_TYPE),
	WIFI_ASSOCRSP       = (BIT4 | WIFI_MGT_TYPE),
	WIFI_REASSOCREQ     = (BIT5 | WIFI_MGT_TYPE),
	WIFI_REASSOCRSP     = (BIT5 | BIT4 | WIFI_MGT_TYPE),
	WIFI_PROBEREQ       = (BIT6 | WIFI_MGT_TYPE),
	WIFI_PROBERSP       = (BIT6 | BIT4 | WIFI_MGT_TYPE),
	WIFI_BEACON         = (BIT7 | WIFI_MGT_TYPE),
	WIFI_ATIM           = (BIT7 | BIT4 | WIFI_MGT_TYPE),
	WIFI_DISASSOC       = (BIT7 | BIT5 | WIFI_MGT_TYPE),
	WIFI_AUTH           = (BIT7 | BIT5 | BIT4 | WIFI_MGT_TYPE),
	WIFI_DEAUTH         = (BIT7 | BIT6 | WIFI_MGT_TYPE),
	WIFI_ACTION         = (BIT7 | BIT6 | BIT4 | WIFI_MGT_TYPE),

	// below is for control frame
	WIFI_PSPOLL         = (BIT7 | BIT5 | WIFI_CTRL_TYPE),
	WIFI_RTS            = (BIT7 | BIT5 | BIT4 | WIFI_CTRL_TYPE),
	WIFI_CTS            = (BIT7 | BIT6 | WIFI_CTRL_TYPE),
	WIFI_ACK            = (BIT7 | BIT6 | BIT4 | WIFI_CTRL_TYPE),
	WIFI_CFEND          = (BIT7 | BIT6 | BIT5 | WIFI_CTRL_TYPE),
	WIFI_CFEND_CFACK    = (BIT7 | BIT6 | BIT5 | BIT4 | WIFI_CTRL_TYPE),

	// below is for data frame
	WIFI_DATA           = (0 | WIFI_DATA_TYPE),
	WIFI_DATA_CFACK     = (BIT4 | WIFI_DATA_TYPE),
	WIFI_DATA_CFPOLL    = (BIT5 | WIFI_DATA_TYPE),
	WIFI_DATA_CFACKPOLL = (BIT5 | BIT4 | WIFI_DATA_TYPE),
	WIFI_DATA_NULL      = (BIT6 | WIFI_DATA_TYPE),
	WIFI_CF_ACK         = (BIT6 | BIT4 | WIFI_DATA_TYPE),
	WIFI_CF_POLL        = (BIT6 | BIT5 | WIFI_DATA_TYPE),
	WIFI_CF_ACKPOLL     = (BIT6 | BIT5 | BIT4 | WIFI_DATA_TYPE),
	WIFI_QOS_DATA       = (BIT7 | WIFI_DATA_TYPE),
	WIFI_QOS_NULL       = (BIT7 | BIT6 | WIFI_DATA_TYPE),
};

/*--------------------Define MACRO--------------------------------------*/

/*--------------------Define Struct---------------------------------------*/

#define AOAC_REPORT_VERSION      0x1

typedef struct _AOAC_REPORT_ {
	u8   pPTKTXIV[8];
	u8   pReplayCntEapolKey[8];
	u8   pGroupKey[32];          //the last updated GTK data
	u8   u1KeyIdx;               //the last updated GTK index
	u8   u1SecurityType;         //per received packet
	u8   u1WowPatternIdx;        //per received packet
	u8   u1RptFormatVer;         //In old FW, this is a 1-byte rsvd, FW clear this byte certainly
	u8   u1Rsvd[4];              //In old FW, these 4 bytes are not include in AOAC rpt. Don't use these 4 bytes. Just for 8-byte alignment
	u8   u4RxPTKIV[8];           //Unicast IV
	u8   u4RxGTKIV_0[8];         //Broadcast/Mulicast IV, 4 GTK index
	u8   u4RxGTKIV_1[8];
	u8   u4RxGTKIV_2[8];
	u8   u4RxGTKIV_3[8];
} AOAC_REPORT, *PAOAC_REPORT;

typedef struct _SECURITY_INFO_ {
	H2C_WPA_TWO_WAY_PARA wpa_two_way_para;
	H2C_EAPOL_KEY_STRUCT gtk_req;
} SECURITY_INFO, *PSECURITY_INFO;

typedef struct _ARP_INFO_ {

	u8       A3Addr[6];//gateway's address
	u8       IPV4[4];
	u8       THA[6];
	u8       TPA[4];
} ARP_INFO, *PARP_INFO;


typedef struct _NDP_INFO_ {

	u8 Enable: 1;
	u8 bCheckRemoveIP: 1;  // Need to Check Sender IP or not
	u8 Rsvd: 6;  // Need to Check Sender IP or not
	u8 NumberOfTargetIP; // Number of Check IP which NA query IP
	u8 TagetLinkAddress[6];  // Maybe support change MAC address !!
	u8 RemoteIPv6Address[16]; // Just respond IP
	u8 TargetIP[2][16]; //  target IP

} NDP_INFO, *PNDP_INFO;

typedef struct _H2C_PROTOCOL_OFFLOAD_INFO {

	NDP_INFO NDPInfo[2];

} H2C_PROTOCOL_OFFLOAD_INFO, *PH2C_PROTOCOL_OFFLOAD_INFO;

typedef struct _IPV6_PSEUDO_HEADER_INFO {

	u8 SourceAddress[16];
	u8 DestinationAddress[16];
	u32 PayPloadLength;
	u8 rsvd1[3];
	u8 NextHeader;

} IPV6_PSEUDO_HEADER_INFO, *PIPV6_PSEUDO_HEADER_INFO;


typedef struct _AOAC_INFO_ {

	ARP_INFO    ARPInfo;
	NDP_INFO    NDPInfo[2];
	IPV6_PSEUDO_HEADER_INFO Ipv6PseudoHeaderInfo;
	SECURITY_INFO SecurityInfo;
	AOAC_REPORT AOACReport;
} AOAC_INFO, *PAOAC_INFO;

/*--------------------Export global variable-------------------------------*/

/*--------------------Function declaration---------------------------------*/
extern void
GetIV_8721D_ROM(
	u16 addrl_frame_ctrl,
	u8 MacHeaderLen,
	u8 IvLen,
	u8 *IV
);

extern u8
GetIVLenAndSecurityType_8721D_ROM(
	u8 raaddr
);

extern u8
GetMACHeaderLen_8721D_ROM(
	u8  macheader,
	u8  FrameCtrl,
	u8  raaddr
) ;

extern void
UpdateIV_8721D_ROM(
	u8 *buf,
	u8 retry_bit
);
#endif  //__WLAN_WoWLAN_H__
