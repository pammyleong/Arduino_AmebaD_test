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

#include <gc_vip_user_cpu.h>

#if vpmdENABLE_SUPPORT_CPU_LAYER

#include <gc_vip_common.h>
#include <vip_lite_common.h>
#include <gc_vip_user_port.h>
#include <gc_vip_user.h>

/* minimum user layer CPU function implement */
vip_uint32_t minimum_cpu_func(gcvip_layer_buffer buffers, vip_uint32_t num_buffer)
{
	vip_uint32_t ret = 0;
	vip_uint32_t size = 1;
	vip_uint32_t i = 0;
	gcvip_layer_buffer input_1 = &buffers[0];
	gcvip_layer_buffer input_2 = &buffers[1];
	gcvip_layer_buffer output_buf = &buffers[2];
	float output = 0.0;

	for (i = 0; i < output_buf->dim_count; i++) {
		size *= output_buf->dims[i];
	}

	for (i = 0; i < size; i++) {
		float input1 = gcvip_get_dataext(input_1->data_format, input_1->quant_format, i, input_1->buffer,
										 input_1->fixpoint_zeropoint, input_1->fixpoint_zeropoint, input_1->tfscale);

		float input2 = gcvip_get_dataext(input_2->data_format, input_2->quant_format, i, input_2->buffer,
										 input_2->fixpoint_zeropoint, input_2->fixpoint_zeropoint, input_2->tfscale);

		output = gcvip_math_min(input1, input2);

		gcvip_save_dataext(output_buf->data_format, output_buf->quant_format, i, output, output_buf->buffer,
						   output_buf->fixpoint_zeropoint, output_buf->fixpoint_zeropoint, output_buf->tfscale, GCVIP_NN_ROUNDING_MODE_SIMPLE_ROUNDING);
	}

	return ret;

}


/*
@brief Dispatch user layer, call CPU function which customer implement.
@param segment The segment object.
*/
vip_status_e gcvip_do_user_layer(
	vip_network_t *network,
	gcvip_lite_segment_t *segment
)
{
	vip_status_e status = VIP_SUCCESS;
	gcvip_sw_layer_user_t *user_layer = VIP_NULL;
	vip_char_t *name = VIP_NULL;

	if ((VIP_NULL == segment) || (VIP_NULL == segment->base)) {
		gcvip_error("fail to do user operation, parameter is NULL\n");
		gcGoOnError(VIP_ERROR_FAILURE);
	}

	user_layer = (gcvip_sw_layer_user_t *)segment->base;
	name = segment->base->name;

	/* use/match name to dispatch user layer, and call CPU functions.
	   The name is customer CPU layer's node name which specify by vxSetReferenceName() API in unified driver.
	   Customer can modify the method of dispatch CPU layer.
	   Example: The 'minimum_cpu_func' is specify by vxSetReferenceName() and store in NBG file.
	*/
	if (gcvip_os_strcmp(name, "minimum_cpu_func") == 0) {
		minimum_cpu_func(user_layer->buffers, user_layer->buffer_num);
		/* cpu minimum CPU function */
	} else {
		gcvip_error("fail to do user operation, not match cpu function\n");
		gcGoOnError(VIP_ERROR_FAILURE);
	}

onError:
	return status;
}


#endif
