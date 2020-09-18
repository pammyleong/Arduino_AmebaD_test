#ifndef __BT_CONFIG_H__
#define __BT_CONFIG_H__
#include <basic_types.h>
#include <wifi/wifi_conf.h>

#ifndef WLAN0_NAME
  #define WLAN0_NAME		"wlan0"
#endif

#define SSID_LEN 32
#define BTCONFIG_MAX_REQ_LEN			256
#define BTCONFIG_MAX_RPL_LEN			2634
#define BT_MAX_BSS_NUM					64
#define BT_SCAN_RESLUT_UNIT				3
#define BT_MSG_HDR_LEN					4
#define BT_CONN_ACK_LEN					5
#define BT_GATT_SCAN_SECTION_LEN		(9 + 41 * BT_SCAN_RESLUT_UNIT)

/* msg tag*/
//#define TAG_BT_CMD_START				0x01
//#define TAG_BT_CMD_REPLY_NONCE			0x02
//#define TAG_BT_CMD_AUTH					0x03
//#define TAG_BT_CMD_REPLY_AUTH			0x04
// bt_message
#define TAG_BT_CMD_SCAN					0x01
#define TAG_BT_CMD_REPLY_SCAN			0x02
#define TAG_BT_CMD_CONNECT				0x03
#define TAG_BT_CMD_REPLY_CONNECT		0x04
#define TAG_BT_CMD_GET_STATUS			0x05
#define TAG_BT_CMD_REPLY_GET_STATUS		0x06
#define TAG_BT_CMD_GET_WLAN_BAND		0x07
#define TAG_BT_CMD_REPLY_WLAN_BAND		0x08
// error
#define TAG_BTCMD_REPLY_FAIL			0xff

typedef struct
{

	unsigned char data[BTCONFIG_MAX_REQ_LEN];
	unsigned int len;
} bt_command;

RTW_PACK_STRUCT_BEGIN
struct bt_bss_info
{
	unsigned char authAlg;/*0:open,1:WPA,2:WEP*/
    unsigned char BSSID[6];
    unsigned char SSID[SSID_LEN];
    unsigned char channelNumber;
	unsigned char rssi;
}// __attribute__((packed));
RTW_PACK_STRUCT_STRUCT;
RTW_PACK_STRUCT_END

RTW_PACK_STRUCT_BEGIN
struct bt_scan_result
{
	unsigned char band;/*0 for 2.4G,1 for 5G*/
	unsigned int number;/*total number of results*/
	struct bt_bss_info bss_info[BT_MAX_BSS_NUM];
}// __attribute__((packed));
RTW_PACK_STRUCT_STRUCT;
RTW_PACK_STRUCT_END

RTW_PACK_STRUCT_BEGIN
struct bt_status
{
	unsigned char band;/*0 for 2.4G,1 for 5G*/
	unsigned char status;/*0:disconnected,1:connected*/
	unsigned char authAlg;/*0:open,1:WPA,2:WEP*/
    unsigned char ssid[32];
    unsigned char bssid[6];
	unsigned char rssi;
    unsigned char config_status;/*0:unconfigured,1:configured*/
}// __attribute__((packed));
RTW_PACK_STRUCT_STRUCT;
RTW_PACK_STRUCT_END

RTW_PACK_STRUCT_BEGIN
struct bt_band_info
{
	unsigned char support_2_4g;
	unsigned char support_5g;
	unsigned char product_type;	/* 1: Ameba */
}// __attribute__((packed));
RTW_PACK_STRUCT_STRUCT;
RTW_PACK_STRUCT_END
	
RTW_PACK_STRUCT_BEGIN
struct bt_connect_AP_info
{	
	unsigned char band; //0 for 2.4G,1 for 5G
	unsigned char authAlg;/*0:open,1:WPA,2:WEP*/
    unsigned char SSID[32];
    unsigned char BSSID[6];
	unsigned char password[64];
}// __attribute__((packed));
RTW_PACK_STRUCT_STRUCT;
RTW_PACK_STRUCT_END

#endif /* __BT_CONFIG_H__ */
