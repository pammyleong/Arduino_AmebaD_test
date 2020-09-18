#ifndef _BT8752_H_
#define _BT8752_H_

#include <inttypes.h>

#define BT_EV_LE_AUTHEN_COMPLETE (1)
#define BT_EV_LINK_KEY_REQ       (2)
#define BT_EV_APP_DATA           (3)
#define BT_EV_APP_READ_IND       (4)

#define BT8752_HCI_SINC_WORD	(0x55)
#define BT8752_HCI_CHKSUM_LEN	1
//From BT8752 to 8711B
#define BT8752_HCI_COMMAND_ACK  (0x0000)
#define BT8752_HCI_COMMAND_POWER_ON  (0x0001)
#define BT8752_HCI_COMMAND_POWER_OFF  (0x0002)
#define BT8752_HCI_COMMAND_SIMPLE_CONFIG (0x0003)
#define BT8752_HCI_COMMAND_SEND_VOICE_PACKET  (0x0004)
#define BT8752_HCI_COMMAND_START_VOICE_PACKET  (0x0005)
#define BT8752_HCI_COMMAND_STOP_VOICE_PACKET  (0x0006)

//From 8711B to BT8752
#define BT8752_HCI_EVENT_ACK    (0x0000)
#define BT8752_HCI_EVENT_CONNECT_STATE    (0x0001)
#define BT8752_HCI_EVENT_DEVICE_STATE   (0x0002)
#define BT8752_HCI_EVENT_VOICE_STATE    (0x0003)


#define BT8752_MAX_PACKET_LEN    (512)
#define BT8752_MAX_PARAMETER_LEN (253)

#define BT8761_HCI_COMMAND_PACKET  (0x01)
#define BT8761_HCI_ACL_DATA_PACKET (0x02)
#define BT8761_HCI_EVENT_PACKET    (0x04)
#define BT8752_HCI_MAX_DATA_LEN (244)

#define BT8752_UART_TX      PA_26// PA_23// 
#define BT8752_UART_RX      PA_25// PA_18//  
#define BT8752_UART_BAUDRATE  115200


#if 0
typedef struct _bt_status_t {
    uint8_t gap_init_state;
    uint8_t gap_adv_sub_state;
    uint8_t gap_adv_state;
    uint8_t gap_conn_state;
    uint8_t gap_scan_state;
    uint8_t radio_state;
    uint8_t spp_state;
} bt_status_t;

typedef struct _bt_addr_t {
    uint8_t addr_type;
    uint8_t bd_addr[6];
} bt_addr_t;

typedef struct _bt_link_key_req_t {
    uint8_t bd_addr[6];
    uint8_t remote_addr_type;
    uint8_t key_type;
} bt_link_key_req_t;

typedef struct _bt_link_key_t {
	uint8_t key_type;
    uint8_t link_key[28];
} bt_link_key_t;

typedef struct _bt_link_info_t {
    uint8_t valid;
	uint8_t bd_addr[6];
	uint8_t remote_addr_type;
    bt_link_key_t ltk;
    bt_link_key_t irk;
} bt_link_info_t;

#define BT8752_MAX_LINK_INFO_SIZE (4)

typedef struct _bt_link_table_t {
    uint8_t tblname[10];
    bt_link_info_t link_info[BT8752_MAX_LINK_INFO_SIZE];
} bt_link_table_t;
#endif 
int bt8752_init();
#if 0
int bt8752_dl_patchcfg(uint8_t *patch, uint32_t patch_len);
int bt8752_read_bt_status(bt_status_t *bs);
int bt8752_ble_read_addr(bt_addr_t *addr);
int bt8752_set_adv_mode(uint8_t mode);
int bt8752_ble_adv_enable(uint8_t enable);
int bt8752_ble_set_name(char *name);
int bt8752_set_adv_data(uint8_t *data, uint8_t len);
int bt8752_hci_le_cmd_all_paired_device_info(bt_link_key_req_t *req);
int bt8752_hci_send_raw(uint16_t cmd, uint8_t *data, uint32_t len);

void bt8752_reg_event_listener( void (*callback)(uint32_t type, void *data, uint32_t len) );
#endif 
#endif
