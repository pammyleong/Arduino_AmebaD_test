/******************************************************************************\
|* Copyright (c) 2017-2021 by Vivante Corporation.  All Rights Reserved.      *|
|*                                                                            *|
|* The material in this file is confidential and contains trade secrets of    *|
|* of Vivante Corporation.  This is proprietary information owned by Vivante  *|
|* Corporation.  No part of this work may be disclosed, reproduced, copied,   *|
|* transmitted, or used in any way for any purpose, without the express       *|
|* written permission of Vivante Corporation.                                 *|
|*                                                                            *|
\******************************************************************************/

#ifndef _VIP_LITE_DEBUG_H
#define _VIP_LITE_DEBUG_H

#include <vip_lite.h>
#include <gc_vip_user_port.h>


#define GCVIP_GET_STRING    gcvip_os_snprint
#define GCVIP_DUMP_STRING   gcvip_user_print_string


#if vpmdENABLE_LAYER_DUMP
vip_status_e gcvip_layer_dump(
	gcvip_lite_segment_t *segment,
	vip_network_t *network,
	vip_uint32_t id
);
#endif

#if vpmdENABLE_HANG_DUMP || vpmdDUMP_COMMANDS_EVERY_RUN || vpmdENABLE_CAPTURE
typedef enum gcvip_dump_buf_type {
	GCVIP_DUMP_COMMAND = 0,
	GCVIP_DUMP_STATES,
	GCVIP_DUMP_POOL,
	GCVIP_DUMP_INPUT,
	GCVIP_DUMP_VERIFY,
	GCVIP_DUMP_MEMORY,
}   gcvip_dump_buf_type_e;

void gcvip_dump_duffer(
	gcvip_file_t fp,
	void  *buffers,
	vip_uint32_t physical,
	vip_uint32_t size,
	gcvip_dump_buf_type_e type
);
#endif

#if vpmdENABLE_HANG_DUMP || vpmdDUMP_COMMANDS_EVERY_RUN
typedef enum _gcvip_dump_type {
	HANG_DUMP = 0,
	RUN_DUMP  = 1,
} gcvip_dump_type_e;

void gcvip_dump_states_command(
	vip_network_t *network,
	gcvip_lite_segment_t *segment,
	vip_uint32_t flag
);
#endif

#if vpmdENABLE_CAPTURE
typedef enum gcvip_command_type {
	NN_COMMAND = 0,
	TP_COMMAND,
	SH_COMMAND,
	STATES,
} gcvip_command_type_e;

void gcvip_capture_dump_list(
	gcvip_lite_context_t *context,
	vip_network_t *network
);

void gcvip_capture_add_list(
	gcvip_lite_segment_t *segment,
	vip_uint32_t offset,
	vip_uint32_t size,
	vip_uint32_t layer_id,
	vip_uint32_t uid,
	vip_uint32_t type
);

vip_status_e gcvip_capture_dump_states(
	gcvip_lite_context_t *context,
	vip_network_t *network,
	gcvip_lite_segment_t *segment
);

vip_status_e gcvip_capture_hardware_info(
	gcvip_lite_context_t *context
);

vip_status_e gcvip_capture_init_command(
	gcvip_lite_context_t *context,
	vip_network_t *network
);

vip_status_e gcvip_capture_init(
	gcvip_lite_context_t *context
);

vip_status_e gcvip_capture_uninit(
	gcvip_lite_context_t *context
);
#endif

#if vpmdENABLE_BW_PROFILING
vip_status_e gcvip_bw_profiling(
	vip_network_t *network
);
#endif

#if vpmdENABLE_CNN_PROFILING
vip_uint32_t gcvip_get_num_initend_operation(
	vip_network_t *network
);

vip_status_e gcvip_layer_profile(
	vip_network_t *network,
	gcvip_lite_segment_t *segment
);
#endif

#endif
