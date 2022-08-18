/*
 *******************************************************************************
 * Copyright(c) 2021, Realtek Semiconductor Corporation. All rights reserved.
 *******************************************************************************
 */

#ifndef __RTK_BLE_IMPL_COMM_H__
#define __RTK_BLE_IMPL_COMM_H__

#include <rtk_bt_defs.h>
#include <bluetooth.h>

#ifdef __cplusplus
extern "C" {
#endif

void record_conn_by_index(struct bt_conn *conn, uint8_t index);

void remove_conn_record_by_index(uint8_t index);

struct bt_conn *lookup_conn_by_index(uint8_t index);

void bt_addr_user_to_stack(rtk_ble_bd_addr_t *user_bt_addr,
                                        bt_addr_le_t **stack_bt_addr);

void bt_addr_stack_to_user(bt_addr_le_t *stack_bt_addr,
                                        rtk_ble_bd_addr_t *user_bt_addr);

#ifdef __cplusplus
}
#endif

#endif /* __RTK_BLE_IMPL_COMM_H__ */