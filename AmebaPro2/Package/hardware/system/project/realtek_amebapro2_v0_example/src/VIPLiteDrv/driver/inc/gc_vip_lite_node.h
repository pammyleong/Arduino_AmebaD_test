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
#ifndef _GCVIP_LITE_NODE_H
#define _GCVIP_LITE_NODE_H

#include "vip_lite_node.h"
#include "gc_vip_common.h"
#include "gc_vip_lite.h"


#define MAX_IMAGE_DEPTH             4

typedef enum _gcvip_node_type {
	GCVIP_NODE_TYPE_NONE    = 0x00,
	GCVIP_NODE_TYPE_SCALER  = 0x01,
	GCVIP_NODE_TYPE_MAX,
} gcvip_node_type_t;

typedef struct _gcvip_image_params_t {
	vip_uint32_t         height;
	vip_uint32_t         width;
	vip_uint32_t         depth;
	vip_enum             color;
	vip_enum             data_format;
	vip_uint32_t         memory_type;
} gcvip_image_params_t;

typedef struct _vip_image {
	gcvip_object_t       object;
	gcvip_videomemory_t  memories[MAX_IMAGE_DEPTH];
	vip_uint32_t         allocated;
	gcvip_image_params_t param;
} vip_image_t;

typedef struct _vip_node_t {
	gcvip_object_t       object;
	gcvip_node_type_t    type;

	gcvip_videomemory_t  states_buffer;
#if vpmdENABLE_CAPTURE
	/* mark to capture complete, don't need capture again*/
	vip_uint8_t          capture_done;
#endif
	vip_ptr             *inputs;
	vip_ptr             *outputs;
	vip_uint32_t         input_num;
	vip_uint32_t         output_num;

#if vpmdENABLE_CNN_PROFILING
	vip_uint64_t        start_time;
	vip_uint64_t        end_time;
#endif
} vip_node_t;

vip_status_e gcvip_create_node(
	vip_node_t **node_ptr
);

vip_status_e gcvip_create_preprocess(
	const vip_preprocess_type_e type,
	const void *param,
	const vip_uint32_t param_size,
	const vip_image input_buffer,
	const vip_buffer output_buffer,
	vip_node *out_node
);

vip_status_e gcvip_update_preprocess(
	vip_node node,
	const vip_preprocess_type_e type,
	const void *param,
	const vip_uint32_t param_size,
	const vip_image input_buffer,
	const vip_buffer output_buffer
);

#endif
