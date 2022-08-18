#ifndef _EXAMPLE_GUI_GATEWAY_DEMO_H
#define _EXAMPLE_GUI_GATEWAY_DEMO_H

#include "ameba_soc.h"
#include "bt_mesh_app_list_intf.h"

#define GROUP_NUMBER_MAX 6
#define GROUP_NUMBER_DEF 6
#define DEVICE_NUMBER_MAX 20

typedef struct bt_device_info {
	u8 uuid[16];
	u8 active_status;
	u32 last_active_time;
	u8 light_status;
	u16 mesh_address;
	u16 group_address;
	char group_name[16];
	char node_name[16];
} bt_device_info_t;

typedef struct bt_group_info {
	u16 group_address;
	char group_name[16];
	u8 device_number;
} bt_group_info_t;

void gateway_demo(void);
void gateway_wifi_info(void);
void gateway_get_unprovisioned_device(u8 *param);
void gateway_get_connected_device(struct BT_MESH_DEVICE_INFO *dev_info);
void gateway_delete_node(struct BT_MESH_DEVICE_INFO *dev_info);
void gateway_get_node_status(void *data);
void gateway_set_node_status(struct BT_MESH_DEVICE_INFO *dev_info);
void gateway_set_node_group(struct BT_MESH_DEVICE_INFO *dev_info);
void lcd_status_update(char *s);
#endif
