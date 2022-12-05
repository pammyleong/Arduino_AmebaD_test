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

#include <gc_vip_cpu.h>
#if vpmdENABLE_SUPPORT_CPU_LAYER

#include <gc_vip_common.h>
#include <vip_lite_common.h>
#include <gc_vip_user_port.h>
#include <gc_vip_user.h>
#include <gc_vip_user_cpu.h>


#if defined(__linux__) || defined(_WIN32)
#else
vip_float64_t gcvip_math_exp(
	vip_float64_t x)
{
	x = 1.0 + x / 1024;
	x *= x;
	x *= x;
	x *= x;
	x *= x;
	x *= x;
	x *= x;
	x *= x;
	x *= x;
	x *= x;
	x *= x;

	return x;
}
#endif

#ifndef _WIN32 // note, TP modify not sync
static vip_float64_t _copysign(vip_float64_t number, vip_float64_t sign)
{
	vip_float64_t value = gcvip_math_abs(number);
	return (sign > 0) ? value : (-value);
}
#endif

static vip_float_t round_simple_rounding(vip_float_t x)
{
	/*#if defined(_M_X64)
	    return (vip_float_t) _copysignf(floor(fabs(x) + 0.5f), x);
	#else*/
	return (vip_float_t) _copysign(floor(fabs(x) + 0.5f), x);
	/*#endif*/
}

#if 0
static vip_float64_t round_rtne(vip_float64_t x)
{
#define EPSILON 1e-8

	vip_float64_t decimal;
	vip_float64_t inter;

	decimal = modf((vip_float64_t)x, &inter);

	if (gcvip_math_abs((gcvip_math_abs(decimal) - 0.5f)) < EPSILON) {
		inter += (vip_int32_t)(inter) % 2;
	} else {
		return round_simple_rounding((vip_float_t)x);
	}

	return inter;
}
#endif

static vip_float_t round_rtz(vip_float_t x)
{
	return (vip_float_t)_copysign(floor(fabs(x)), x);
}

static vip_float_t round_rtni(vip_float_t x)
{
	if (x > 0.0f) {
		return (vip_float_t)_copysign(floor(fabs(x)), x);
	} else {
		return (vip_float_t)_copysign(ceil(fabs(x)), x);
	}
}

static vip_float_t round_data(vip_float_t x, vip_enum roundMode)
{
	switch (roundMode) {
	case  GCVIP_NN_ROUNDING_MODE_SIMPLE_ROUNDING:
		return (vip_float_t) round_simple_rounding(x);

	case GCVIP_NN_ROUNDING_MODE_RTNE:
		gcvip_error("not support RTNE rounding mode\n");
		return 0;

	case GCVIP_NN_ROUNDING_MODE_RTZ:
		return round_rtz(x);

	case GCVIP_NN_ROUNDING_MODE_RTNI:
		return round_rtni(x);
	default:
		return (vip_float_t) round_simple_rounding(x);
	}
}

static vip_float_t convert_dynamicfixpointvalue_to_float32(
	vip_float_t value,
	vip_int8_t fixedPointPos
)
{
	vip_float_t result = 0.0f;

	if (fixedPointPos > 0) {
		result = value * (1.0f / ((vip_uint32_t)(1 << fixedPointPos)));
	} else {
		result = value * ((vip_float_t)(1 << -fixedPointPos));
	}

	return result;
}

static vip_float_t uint8_to_fp32(vip_uint8_t val, vip_int32_t zeroPoint, vip_float_t scale)
{
	vip_float_t result = 0.0f;

	result = (val - (vip_uint8_t)zeroPoint) * scale;

	return result;
}

static vip_float_t int32_to_fp32quant(vip_int32_t val, vip_int32_t zeroPoint, vip_float_t scale)
{
	vip_float_t result = 0.0f;

	result = (val - zeroPoint) * scale;

	return result;
}

static vip_float_t int8_to_fp32(vip_int8_t val, vip_int8_t fixedPointPos)
{
	return convert_dynamicfixpointvalue_to_float32((vip_float_t)val, fixedPointPos);
}

static vip_float_t uchar_to_fp32(vip_uint8_t val, vip_int8_t fixedPointPos)
{
	vip_float_t result = 0.0f;

	if (fixedPointPos >= 0) {
		result = (vip_float_t)val * (1.0f / ((vip_uint32_t)(1 << fixedPointPos)));
	} else {
		result = (vip_float_t)val * ((vip_float_t)(1 << -fixedPointPos));
	}

	return result;
}

static vip_float_t int16_to_fp32(vip_int16_t val, vip_int8_t fixedPointPos)
{
	return convert_dynamicfixpointvalue_to_float32((vip_float_t)val, fixedPointPos);
}

static vip_float_t int32_to_fp32(vip_int32_t val, vip_int8_t fixedPointPos)
{
	return convert_dynamicfixpointvalue_to_float32((vip_float_t)val, fixedPointPos);
}

static vip_float_t int64_to_fp32(vip_int64_t val, vip_int8_t fixedPointPos)
{
	vip_float_t result = 0.0f;

	if (fixedPointPos > 0) {
		result = val * (1.0f / ((vip_uint32_t)(1 << fixedPointPos)));
	} else {
		result = val * ((vip_float_t)(1 << -fixedPointPos));
	}

	return result;
}

static vip_float_t fp16_to_fp32(const vip_uint16_t in)
{
	vip_uint32_t t1;
	vip_uint32_t t2;
	vip_uint32_t t3;
	vip_float_t out;

	t1 = in & 0x7fff;                       /*Non-sign bits*/
	t2 = in & 0x8000;                       /*Sign bit*/
	t3 = in & 0x7c00;                       /*Exponent*/

	t1 <<= 13;                              /* Align mantissa on MSB*/
	t2 <<= 16;                              /* Shift sign bit into position*/

	t1 += 0x38000000;                       /*Adjust bias*/

	t1 = (t3 == 0 ? 0 : t1);                /* Denormals-as-zero*/

	t1 |= t2;                               /* Re-insert sign bit*/

	gcvip_os_memcopy(&out, &t1, sizeof(vip_float_t));

	return out;
}

static vip_uint8_t fp32_to_uint8(
	vip_float_t val,
	vip_int32_t zeroPoint,
	vip_float_t scale,
	vip_int32_t roundMode
)
{
	vip_uint8_t result = 0;
	vip_float_t data;

	data = round_data((val / scale + (vip_uint8_t)zeroPoint), roundMode);

	if (data > 255.0) {
		data = 255;
	}

	if (data < 0) {
		data = 0;
	}

	result = (vip_uint8_t)(data);

	return result;
}

static vip_int8_t fp32_to_int8(vip_float_t val, vip_int8_t fixedPointPos, vip_int32_t roundMode)
{
	vip_int8_t result = 0;

	if (fixedPointPos > 0) {
		vip_int32_t data = (vip_int32_t)round_data(val * (vip_float_t)(1 << fixedPointPos), roundMode);
		result = (vip_int8_t)((data > 127) ? 127 : (data < -128) ? -128 : data);

	} else {
		vip_int32_t data = (vip_int32_t)round_data(val * (1.0f / (vip_float_t)(1 << -fixedPointPos)),
						   roundMode);
		result = (vip_int8_t)((data > 127) ? 127 : (data < -128) ? -128 : data);
	}

	return result;
}

static vip_int8_t fp32_to_uchar(vip_float_t val, vip_int8_t fixedPointPos, vip_int32_t roundMode)
{
	vip_uint8_t result = 0;

	if (fixedPointPos >= 0) {
		vip_int32_t data = (vip_int32_t) round_data(val * (vip_float_t)(1 << fixedPointPos), roundMode);
		result = (vip_uint8_t)((data > 255) ? 255 : (data < 0) ? 0 : data);
	} else {
		vip_int32_t data = (vip_int32_t) round_data(val * (1.0f / (vip_float_t)(1 << -fixedPointPos)),
						   roundMode);
		result = (vip_uint8_t)((data > 255) ? 255 : (data < 0) ? 0 : data);
	}

	return result;
}

static vip_int16_t fp32_to_int16(vip_float_t val, vip_int8_t fixedPointPos, vip_int32_t roundMode)
{
	vip_int16_t result = 0;

	if (fixedPointPos > 0) {
		vip_int32_t data = (vip_int32_t) round_data(val * (vip_float_t)(1 << fixedPointPos), roundMode);
		result = (vip_int16_t)((data > 32767) ? 32767 : (data < -32768) ? -32768 : data);

	} else {
		vip_int32_t data = (vip_int32_t) round_data(val * (1.0f / (vip_float_t)(1 << -fixedPointPos)),
						   roundMode);
		result = (vip_int16_t)((data > 32767) ? 32767 : (data < -32768) ? -32768 : data);
	}

	return result;
}

static vip_int16_t fp32_to_fp16(vip_float_t val)
{
	vip_uint32_t f32 = 0;
	vip_int16_t f16 = 0;
	vip_int32_t sign = 0;
	vip_int32_t exponent = 0;
	vip_int32_t mantissa = 0;

	gcvip_os_memcopy(&f32, &val, sizeof(vip_uint32_t));

	/* Decode IEEE 754 little-endian 32-bit floating-point value */
	/* Map exponent to the range [-127,128] */
	sign = (f32 >> 16) & 0x8000;
	exponent = ((f32 >> 23) & 0xff) - 127;
	mantissa = f32 & 0x007fffff;

	if (exponent == 128) { /* Infinity or NaN */
		if (mantissa) {
			/* Flush NaN to 0. */
			f16 = (vip_int16_t)sign;
		} else {
			/* Clamp to HALF_MAX/HALF_MIN. */
			f16 = (vip_int16_t)(sign | ((F16_EXPONENT_BITS - 1) << F16_EXPONENT_SHIFT) | F16_MANTISSA_BITS);
		}
	} else if (exponent > 15) { /* Overflow - clamp to HALF_MAX/HALF_MIN. */
		f16 = (vip_int16_t)(sign | ((F16_EXPONENT_BITS - 1) << F16_EXPONENT_SHIFT) | F16_MANTISSA_BITS);
	} else if (exponent > -15) { /* Representable value */
		/* RTNE */
		vip_int32_t roundingBit = (mantissa >> (F16_MANTISSA_SHIFT - 1)) & 0x1;
		vip_int32_t stickyBits = mantissa & 0xFFF;
		exponent += F16_EXPONENT_BIAS;
		mantissa >>= F16_MANTISSA_SHIFT;
		if (roundingBit) {
			if (stickyBits || (mantissa & 0x1)) {
				mantissa++;
				if (mantissa > F16_MANTISSA_BITS) {
					exponent++;
					if (exponent > 30) {
						/* Clamp to HALF_MAX/HALF_MIN. */
						exponent--;
						mantissa--;
					} else {
						mantissa &= F16_MANTISSA_BITS;
					}
				}
			}
		}
		f16 = (vip_int16_t)(sign | exponent << F16_EXPONENT_SHIFT | mantissa);
	} else {
		f16 = (vip_int16_t)sign;
	}
	return f16;
}

static vip_status_e save_dataquant(
	vip_int32_t format,
	vip_int32_t index,
	vip_float64_t data,
	vip_ptr dst_data,
	vip_int32_t zeroPoint,
	vip_float_t scale,
	vip_enum roundMode)
{

	switch (format) {
	case VIP_BUFFER_FORMAT_UINT8: {
		vip_uint8_t *dst_data_p = (vip_uint8_t *)dst_data;
		dst_data_p[index] = fp32_to_uint8((vip_float_t)data, zeroPoint, scale, roundMode);
	}
	break;

	default:
		gcvip_error("Not support format :%d\n", format);
		return VIP_ERROR_INVALID_ARGUMENTS;
	}

	return VIP_SUCCESS;
}

static vip_status_e save_data(
	vip_int32_t format,
	vip_int32_t index,
	vip_float64_t data,
	vip_ptr dst_data,
	vip_int8_t fixedPointPos,
	vip_enum roundMode
)
{
	vip_int8_t fpPos = fixedPointPos;

	switch (format) {
	case VIP_BUFFER_FORMAT_INT8: {
		vip_int8_t *dst_data_p = (vip_int8_t *)dst_data;
		dst_data_p[index] = fp32_to_int8((vip_float_t)data, fpPos, roundMode);
	}
	break;
	case VIP_BUFFER_FORMAT_UINT8: {
		vip_uint8_t *dst_data_p = (vip_uint8_t *)dst_data;
		dst_data_p[index] = fp32_to_uchar((vip_float_t)data, fpPos, roundMode);
	}
	break;
	case VIP_BUFFER_FORMAT_INT16: {
		vip_int16_t *dst_data_p = (vip_int16_t *)dst_data;
		dst_data_p[index] = fp32_to_int16((vip_float_t)data, fpPos, roundMode);
	}
	break;
	case VIP_BUFFER_FORMAT_FP16: {
		vip_int16_t *dst_data_p = (vip_int16_t *)dst_data;
		dst_data_p[index] = fp32_to_fp16((vip_float_t)data);
	}
	break;
	case VIP_BUFFER_FORMAT_INT32: {
		vip_int32_t_ptr dst_data_p = (vip_int32_t_ptr)dst_data;
		dst_data_p[index] = (vip_int32_t)data;
	}
	break;
	case VIP_BUFFER_FORMAT_UINT32: {
		vip_uint32_t_ptr dst_data_p = (vip_uint32_t_ptr)dst_data;
		dst_data_p[index] = (vip_uint32_t)data;
	}
	break;
	case VIP_BUFFER_FORMAT_FP32: {
		vip_float_t_ptr dst_data_p = (vip_float_t_ptr)dst_data;
		dst_data_p[index] = (vip_float_t)(data);
	}
	break;
	default:
		gcvip_error("Not support format :%d\n", format);
		break;
	}

	return VIP_SUCCESS;
}

static vip_float_t get_data(
	vip_int32_t format,
	vip_int32_t index,
	vip_uint8_t_ptr data,
	vip_int8_t fixPointPos
)
{
	vip_float_t value = 0;
	vip_int8_t fpPos = fixPointPos;

	if (index >= 0) {
		switch (format) {
		case VIP_BUFFER_FORMAT_INT8: {
			vip_int8_t_ptr data_ptr = (vip_int8_t *)data;
			value = int8_to_fp32(data_ptr[index], fpPos);
		}
		break;
		case VIP_BUFFER_FORMAT_UINT8: {
			vip_uint8_t_ptr data_ptr = (vip_uint8_t *)data;
			value = uchar_to_fp32(data_ptr[index], fpPos);
		}
		break;
		case VIP_BUFFER_FORMAT_INT16: {
			vip_int16_t_ptr data_ptr = (vip_int16_t *)data;
			value = int16_to_fp32(data_ptr[index], fpPos);
		}
		break;
		case VIP_BUFFER_FORMAT_INT32: {
			vip_int32_t_ptr data_ptr = (vip_int32_t *)data;
			value = int32_to_fp32(data_ptr[index], fpPos);
		}
		break;
		case VIP_BUFFER_FORMAT_UINT32: {
			vip_uint32_t_ptr data_ptr = (vip_uint32_t *)data;
			value = (vip_float_t)data_ptr[index];
		}
		break;
		case VIP_BUFFER_FORMAT_INT64: {
			vip_int64_t_ptr data_ptr = (vip_int64_t *)data;
			value = int64_to_fp32(data_ptr[index], fpPos);
		}
		break;
		case VIP_BUFFER_FORMAT_FP16: {
			vip_int16_t_ptr data_ptr = (vip_int16_t_ptr)data;
			value = fp16_to_fp32(data_ptr[index]);
		}
		break;
		case VIP_BUFFER_FORMAT_FP32: {
			vip_float_t_ptr data_ptr = (vip_float_t_ptr)data;
			value = data_ptr[index];
		}
		break;
		default:
			gcvip_error("Not support format :%d\n", format);
			break;
		}
	}
	return value;
}

static vip_float_t get_dataquant(
	vip_int32_t format,
	vip_int32_t index,
	vip_uint8_t_ptr data,
	vip_int32_t zeroPoint,
	vip_float_t scale
)
{
	vip_float_t value = 0;

	if (index >= 0) {
		switch (format) {
		case VIP_BUFFER_FORMAT_UINT8: {
			vip_uint8_t_ptr data_ptr = (vip_uint8_t *)data;
			value = uint8_to_fp32(data_ptr[index], zeroPoint, scale);
		}
		break;
		case VIP_BUFFER_FORMAT_INT32: {
			vip_int32_t_ptr data_ptr = (vip_int32_t *)data;
			value = int32_to_fp32quant(data_ptr[index], zeroPoint, scale);
		}
		break;
		default:
			gcvip_error("Not support format :%d\n", format);
			break;
		}
	}

	return value;
}

static vip_float_t get_dataext(
	vip_int32_t format,
	vip_enum quant_format,
	vip_uint32_t index,
	vip_uint8_t_ptr data,
	vip_int8_t fixPointPos,
	vip_int32_t zeroPoint,
	vip_float_t scale
)
{
	if (quant_format == VIP_BUFFER_QUANTIZE_TF_ASYMM) {
		return get_dataquant(format, index,  data, zeroPoint, scale);
	} else {
		return get_data(format, index, data, fixPointPos);
	}
}

static vip_status_e save_dataext(
	vip_int32_t format,
	vip_enum quant_format,
	vip_int32_t index,
	vip_float64_t data,
	vip_ptr dst_data,
	vip_int8_t fixedPointPos,
	vip_int32_t zeroPoint,
	vip_float_t scale,
	vip_enum roundMode
)
{
	if (format == VIP_BUFFER_FORMAT_UINT8 && quant_format == VIP_BUFFER_QUANTIZE_TF_ASYMM) {
		return save_dataquant(format, index, data, dst_data, zeroPoint, scale, roundMode);
	} else {
		return save_data(format, index, data, dst_data, fixedPointPos, roundMode);
	}
}

/*
@brief Get data from buffer.
*/
vip_float_t gcvip_get_dataext(
	vip_int32_t format,
	vip_enum quant_format,
	vip_uint32_t index,
	vip_uint8_t_ptr data,
	vip_int8_t fixPointPos,
	vip_int32_t zeroPoint,
	vip_float_t scale
)
{
	return get_dataext(format, quant_format, index, data, fixPointPos, zeroPoint, scale);
}

/*
@brief Save data to buffer.
*/
vip_status_e gcvip_save_dataext(
	vip_int32_t format,
	vip_enum quant_format,
	vip_int32_t index,
	vip_float64_t data,
	vip_ptr dst_data,
	vip_int8_t fixedPointPos,
	vip_int32_t zeroPoint,
	vip_float_t scale,
	vip_enum roundMode
)
{
	return save_dataext(format, quant_format, index, data, dst_data,
						fixedPointPos, zeroPoint, scale, roundMode);
}

/* cpu function implement start */

static vip_int32_t rpn_transform_box(
	vip_float_t_ptr box,
	vip_float_t dx, vip_float_t dy,
	vip_float_t d_log_w, vip_float_t d_log_h,
	vip_float_t img_W, vip_float_t img_H,
	vip_float_t min_box_W, vip_float_t min_box_H
)
{
	vip_float_t w, h, ctr_x, ctr_y, pred_ctr_x, pred_ctr_y, pred_w, pred_h, box_w, box_h;

	/* width & height of box */
	w = box[2] - box[0] + 1.0f;
	h = box[3] - box[1] + 1.0f;

	/* center location of box */
	ctr_x = box[0] + 0.5f * w;
	ctr_y = box[1] + 0.5f * h;

	/* new center location according to gradient(dx, dy) */
	pred_ctr_x = dx * w + ctr_x;
	pred_ctr_y = dy * h + ctr_y;

	/* new width & height according to gradient d(log w), d(log h) */
	pred_w = gcvip_math_exp(d_log_w) * w;
	pred_h = gcvip_math_exp(d_log_h) * h;

	/* update upper-left corner location */
	box[0] = pred_ctr_x - 0.5f * pred_w;
	box[1] = pred_ctr_y - 0.5f * pred_h;

	/* update lower-right corner location */
	box[2] = pred_ctr_x + 0.5f * pred_w;
	box[3] = pred_ctr_y + 0.5f * pred_h;

	/* adjust new corner locations to be within the image region */
	box[0] = gcvip_math_max(0.0f, gcvip_math_min(box[0], img_W - 1.0f));
	box[1] = gcvip_math_max(0.0f, gcvip_math_min(box[1], img_H - 1.0f));
	box[2] = gcvip_math_max(0.0f, gcvip_math_min(box[2], img_W - 1.0f));
	box[3] = gcvip_math_max(0.0f, gcvip_math_min(box[3], img_H - 1.0f));

	/* recompute new width & height */
	box_w = box[2] - box[0] + 1.0f;
	box_h = box[3] - box[1] + 1.0f;

	/* check if new box's size >= threshold */
	return (box_w >= min_box_W) * (box_h >= min_box_H);
}

static vip_status_e rpn_qsort_box(
	vip_float_t_ptr box,
	vip_int32_t start,
	vip_int32_t end,
	vip_int32_t num_top
)
{
	/*
	    box[x] = {x1, y1, x2, y2, score};
	*/
	vip_status_e status = VIP_SUCCESS;
	vip_int32_t i;
	vip_float_t pivot_score = box[start * 5 + 4];
	vip_int32_t left = start + 1, right = end;
	vip_float_t temp[5];

	while (left <= right) {
		while (left <= end && box[left * 5 + 4] >= pivot_score) {
			++left;
		}

		while (right > start && box[right * 5 + 4] <= pivot_score) {
			--right;
		}

		if (left <= right) {
			/* swap box */
			for (i = 0; i < 5; ++i) {
				temp[i] = box[left * 5 + i];
			}
			for (i = 0; i < 5; ++i) {
				box[left * 5 + i] = box[right * 5 + i];
			}
			for (i = 0; i < 5; ++i) {
				box[right * 5 + i] = temp[i];
			}

			++left;
			--right;
		}
	}

	if (right > start) {
		for (i = 0; i < 5; ++i) {
			temp[i] = box[start * 5 + i];
		}

		for (i = 0; i < 5; ++i) {
			box[start * 5 + i] = box[right * 5 + i];
		}

		for (i = 0; i < 5; ++i) {
			box[right * 5 + i] = temp[i];
		}
	}

	if (start < right - 1) {
		rpn_qsort_box(box, start, right - 1, num_top);
	}
	if (right + 1 < num_top && right + 1 < end) {
		rpn_qsort_box(box, right + 1, end, num_top);
	}
	return status;
}

static vip_float_t rpn_iou_cpu(
	vip_float_t_ptr A,
	vip_float_t_ptr B
)
{
	vip_float_t x1, y1, x2, y2, width, height, area, A_area, B_area;

	if (A[0] > B[2] || A[1] > B[3] || A[2] < B[0] || A[3] < B[1]) {
		return 0;
	}

	/* overlapped region (=box) */
	x1 = gcvip_math_max(A[0], B[0]);
	y1 = gcvip_math_max(A[1], B[1]);
	x2 = gcvip_math_min(A[2], B[2]);
	y2 = gcvip_math_min(A[3], B[3]);

	/* intersection area */
	width    = gcvip_math_max(0.0f, x2 - x1 + 1.0f);
	height   = gcvip_math_max(0.0f, y2 - y1 + 1.0f);
	area     = width * height;

	/* area of A, B */
	A_area   = (A[2] - A[0] + 1.0f) * (A[3] - A[1] + 1.0f);
	B_area   = (B[2] - B[0] + 1.0f) * (B[3] - B[1] + 1.0f);

	/* IOU */
	return area / (A_area + B_area - area);
}

static vip_bool_e rpn_iou_cpu1(
	vip_float_t_ptr A,
	vip_float_t_ptr B,
	vip_float_t nms_thresh
)
{
	vip_float_t x1, y1, x2, y2, width, height, area, A_area, B_area;

	if (A[0] > B[2] || A[1] > B[3] || A[2] < B[0] || A[3] < B[1]) {
		return 0;
	}

	/* overlapped region (=box) */
	x1 = gcvip_math_max(A[0], B[0]);
	y1 = gcvip_math_max(A[1], B[1]);
	x2 = gcvip_math_min(A[2], B[2]);
	y2 = gcvip_math_min(A[3], B[3]);

	/* intersection area */
	width    = gcvip_math_max(0.0f, x2 - x1 + 1.0f);
	height   = gcvip_math_max(0.0f, y2 - y1 + 1.0f);
	area     = width * height;

	/* area of A, B */
	A_area   = (A[2] - A[0] + 1.0f) * (A[3] - A[1] + 1.0f);
	B_area   = (B[2] - B[0] + 1.0f) * (B[3] - B[1] + 1.0f);

	/* IOU */
	return (vip_bool_e)(area > (A_area + B_area - area) * nms_thresh);
}

static vip_status_e rpn_nms_cpu(
	vip_uint32_t num_boxes,
	vip_float_t_ptr boxes,
	vip_uint32_t_ptr index_out,
	vip_uint32_t_ptr num_out,
	vip_int32_t base_index,
	vip_float_t nms_thresh,
	vip_uint32_t max_num_out
)
{
	vip_status_e status = VIP_SUCCESS;
	if (index_out != VIP_NULL) {
		vip_uint32_t i, j, count = 0;
		vip_char_t_ptr is_dead = VIP_NULL;
		gcvip_user_allocate_memory(num_boxes * sizeof(vip_char_t), (void **)&is_dead);
		gcvip_user_zero_memory(is_dead, num_boxes * sizeof(vip_char_t));

		for (i = 0; i < num_boxes; ++i) {
			if (is_dead[i]) {
				continue;
			}

			index_out[count++] = base_index + i;
			if (count == max_num_out) {
				break;
			}

			for (j = i + 1; j < num_boxes; ++j) {
				if (!is_dead[j] && rpn_iou_cpu(&boxes[i * 5], &boxes[j * 5]) > nms_thresh) {
					is_dead[j] = 1;
				}
			}
		}

		*num_out = count;
		gcvip_user_free_memory(is_dead);
	} else {
		vip_uint32_t i, j, count = 0;
		/*vip_bool is_dead ;*/
		vip_bool_e is_dead ;
		vip_int32_t call_cnt = 0;
		count = 1;

		for (i = 1; i < num_boxes; i++) {
			is_dead = vip_false_e;
			for (j = 0; j < count; j++) {
				call_cnt ++;
				if (rpn_iou_cpu1(&boxes[j * 5], &boxes[i * 5], nms_thresh)) {
					is_dead = vip_true_e;
					break; /*boxes[i * 5] pk dead*/
				}
			}
			if (is_dead) {
				continue;
			}
			/*update boxes*/
			boxes[count * 5 + 0] = boxes[i * 5 + 0];
			boxes[count * 5 + 1] = boxes[i * 5 + 1];
			boxes[count * 5 + 2] = boxes[i * 5 + 2];
			boxes[count * 5 + 3] = boxes[i * 5 + 3];
			boxes[count * 5 + 4] = boxes[i * 5 + 4];
			count++;
			if (count == max_num_out) {
				break;
			}
		}

		*num_out = count;
	}
	return status;
}

void vx_nn_rpn_qsort_box(
	vip_float_t_ptr box,
	vip_int32_t start,
	vip_int32_t end,
	vip_int32_t num_top
)
{
	/*
	    box[x] = {x1, y1, x2, y2, score};
	*/
	int i;
	vip_float_t pivot_score = box[start * 5 + 4];
	vip_int32_t left = start + 1, right = end;
	vip_float_t temp[5];

	while (left <= right) {
		while (left <= end && box[left * 5 + 4] >= pivot_score) {
			++left;
		}

		while (right > start && box[right * 5 + 4] <= pivot_score) {
			--right;
		}

		if (left <= right) {
			/* swap box */
			for (i = 0; i < 5; ++i) {
				temp[i] = box[left * 5 + i];
			}
			for (i = 0; i < 5; ++i) {
				box[left * 5 + i] = box[right * 5 + i];
			}
			for (i = 0; i < 5; ++i) {
				box[right * 5 + i] = temp[i];
			}

			++left;
			--right;
		}
	}

	if (right > start) {
		for (i = 0; i < 5; ++i) {
			temp[i] = box[start * 5 + i];
		}

		for (i = 0; i < 5; ++i) {
			box[start * 5 + i] = box[right * 5 + i];
		}

		for (i = 0; i < 5; ++i) {
			box[right * 5 + i] = temp[i];
		}
	}

	if (start < right - 1) {
		vx_nn_rpn_qsort_box(box, start, right - 1, num_top);
	}
	if (right + 1 < num_top && right + 1 < end) {
		vx_nn_rpn_qsort_box(box, right + 1, end, num_top);
	}
}

static vip_status_e do_rpn_layer(
	vip_network_t *network,
	gcvip_lite_segment_t *segment
)
{
	vip_status_e status = VIP_SUCCESS;
	vip_int8_t out_score_fp = 0;
	vip_enum out_score_quant_format = 0;
	vip_int32_t out_score_zp = 0;
	vip_float_t out_score_scale = 0;
	vip_enum out_score_rMode = 0;
	vip_uint8_t_ptr out_score_data = VIP_NULL;

	gcvip_sw_layer_rpn_t *rpnLayer = (gcvip_sw_layer_rpn_t *)(segment->base);

	vip_uint32_t feat_stride   = *((vip_uint32_t *)rpnLayer->feature_stride.buffer);
	vip_uint32_t min_size      = *((vip_uint32_t *)rpnLayer->min_size.buffer);
	vip_uint32_t pre_nms_topn  = *((vip_uint32_t *)rpnLayer->pre_nms_topn.buffer);
	vip_uint32_t post_nms_topn = *((vip_uint32_t *)rpnLayer->post_nms_topn.buffer);
	vip_float_t nms_thresh   = *((vip_float_t *)rpnLayer->nms_thresh.buffer);

	vip_uint32_t score_channel = rpnLayer->score.dims[2];
	vip_uint32_t score_height  = rpnLayer->score.dims[1];
	vip_uint32_t score_width   = rpnLayer->score.dims[0];
	vip_uint32_t score_count   = score_width * score_height * score_channel / 2;

	vip_uint32_t bbox_height   = rpnLayer->bbox.dims[1];
	vip_uint32_t bbox_width    = rpnLayer->bbox.dims[0];

	vip_uint32_t anchor_count  = rpnLayer->anchor.dims[3]; /* anchor batch = anchor number */

	vip_int8_t in_score_fp         = (vip_int8_t)rpnLayer->score.fixpoint_zeropoint;
	vip_int8_t in_bbox_fp          = (vip_int8_t)rpnLayer->bbox.fixpoint_zeropoint;
	vip_int8_t in_anchor_fp        = (vip_int8_t)rpnLayer->anchor.fixpoint_zeropoint;
	vip_int8_t in_img_fp           = (vip_int8_t)rpnLayer->img_info.fixpoint_zeropoint;
	vip_int8_t out_roi_fp          = (vip_int8_t)rpnLayer->roi_output.fixpoint_zeropoint;
	vip_enum in_score_quant_format   = rpnLayer->score.quant_format;
	vip_enum in_bbox_quant_format    = rpnLayer->bbox.quant_format;
	vip_enum in_anchor_quant_format  = rpnLayer->anchor.quant_format;
	vip_enum in_img_quant_format     = rpnLayer->img_info.quant_format;
	vip_enum out_roi_quant_format    = rpnLayer->roi_output.quant_format;
	vip_int32_t in_score_zp            = rpnLayer->score.fixpoint_zeropoint;
	vip_int32_t in_bbox_zp             = rpnLayer->bbox.fixpoint_zeropoint;
	vip_int32_t in_anchor_zp           = rpnLayer->anchor.fixpoint_zeropoint;
	vip_int32_t in_img_zp              = rpnLayer->img_info.fixpoint_zeropoint;
	vip_int32_t out_roi_zp             = rpnLayer->roi_output.fixpoint_zeropoint;
	vip_float_t in_score_scale       = rpnLayer->score.tfscale;
	vip_float_t in_bbox_scale        = rpnLayer->bbox.tfscale;
	vip_float_t in_anchor_scale      = rpnLayer->anchor.tfscale;
	vip_float_t in_img_scale         = rpnLayer->img_info.tfscale;
	vip_float_t out_roi_scale        = rpnLayer->roi_output.tfscale;
	vip_enum out_roi_rMode           = GCVIP_NN_ROUNDING_MODE_SIMPLE_ROUNDING;

	vip_uint32_t proposal_width, proposal_height, proposal_area, proposal_count;
	vip_float_t img_W, img_H, img_scale_H, img_scale_W;
	vip_float_t min_box_H, min_box_W;
	vip_uint8_t_ptr score_data, bbox_data, img_data, anchor_data, out_roi_data;
	vip_float_t_ptr score_buffer = VIP_NULL, foreground_score = VIP_NULL;
	vip_float_t_ptr proposals    = VIP_NULL, p_proposals = VIP_NULL;
	vip_uint32_t_ptr roi_indices   = VIP_NULL;
	vip_uint32_t i = 0, w = 0, h = 0, k = 0;
	vip_uint32_t real_roi = 0;

	vip_uint32_t in_score_format   = rpnLayer->score.data_format;
	vip_uint32_t in_bbox_format    = rpnLayer->bbox.data_format;
	vip_uint32_t in_anchor_format  = rpnLayer->anchor.data_format;
	vip_uint32_t in_img_format     = rpnLayer->img_info.data_format;
	vip_enum out_roi_format        = rpnLayer->roi_output.data_format;
	vip_uint32_t out_score_format  = rpnLayer->score_output.data_format;

	if (score_height != bbox_height || score_width != bbox_width) {
		gcvip_info("parameter error: score_H[%u] != bbox_H[%u] || score_W[%u] != bbox_W[%u]\n",
				   score_height, bbox_height, score_width, bbox_width);
		return VIP_ERROR_INVALID_ARGUMENTS;
	}

	/* for forward compatible with NBG format, convert buffer format,
	   you can remove the convert if you NBG format always bigger than 0x0001000A
	*/
	if (network->fixed.header.version < 0x0001000A) {
		if ((rpnLayer->score.data_format >= 3) && (rpnLayer->score.data_format <= 6)) {
			in_score_format = rpnLayer->score.data_format - 1;
		}
		if ((rpnLayer->bbox.data_format >= 3) && (rpnLayer->bbox.data_format <= 6)) {
			in_bbox_format = rpnLayer->bbox.data_format - 1;
		}
		if ((rpnLayer->anchor.data_format >= 3) && (rpnLayer->anchor.data_format <= 6)) {
			in_anchor_format = rpnLayer->anchor.data_format - 1;
		}
		if ((rpnLayer->img_info.data_format >= 3) && (rpnLayer->img_info.data_format <= 6)) {
			in_img_format = rpnLayer->img_info.data_format - 1;
		}
		if ((rpnLayer->roi_output.data_format >= 3) && (rpnLayer->roi_output.data_format <= 6)) {
			out_roi_format = rpnLayer->roi_output.data_format - 1;
		}
		if ((rpnLayer->score_output.data_format >= 3) && (rpnLayer->score_output.data_format <= 6)) {
			out_score_format = rpnLayer->score_output.data_format - 1;
		}
	}

	proposal_width  = score_width;
	proposal_height = score_height;
	proposal_area   = proposal_width * proposal_height;
	proposal_count  = proposal_area * anchor_count;

	gcOnError(gcvip_user_allocate_memory((score_count * 2) * sizeof(vip_float_t),
										 (void **)&score_buffer));
	gcOnError(gcvip_user_allocate_memory((proposal_count * 5) * sizeof(vip_float_t),
										 (void **)&proposals));
	gcOnError(gcvip_user_allocate_memory(post_nms_topn * sizeof(vip_uint32_t) * sizeof(vip_float_t),
										 (void **)&roi_indices));

	score_data = rpnLayer->score.buffer;
	bbox_data = rpnLayer->bbox.buffer;
	img_data = rpnLayer->img_info.buffer;
	anchor_data = rpnLayer->anchor.buffer;
	out_roi_data = rpnLayer->roi_output.buffer;

	out_score_fp = (vip_int8_t)rpnLayer->score_output.fixpoint_zeropoint;
	out_score_quant_format = rpnLayer->score_output.quant_format;
	out_score_zp = rpnLayer->score_output.fixpoint_zeropoint;
	out_score_scale = rpnLayer->score_output.tfscale;
	out_score_rMode = GCVIP_NN_ROUNDING_MODE_SIMPLE_ROUNDING;
	out_score_data = rpnLayer->score_output.buffer;

	img_W       = (vip_float_t)get_dataext(in_img_format, in_img_quant_format, 0,
										   (vip_uint8_t_ptr)img_data, in_img_fp,
										   in_img_zp, in_img_scale);
	img_H       = (vip_float_t)get_dataext(in_img_format, in_img_quant_format, 1,
										   (vip_uint8_t_ptr)img_data, in_img_fp,
										   in_img_zp, in_img_scale);
	img_scale_W = (vip_float_t)get_dataext(in_img_format, in_img_quant_format, 2,
										   (vip_uint8_t_ptr)img_data, in_img_fp,
										   in_img_zp, in_img_scale);
	img_scale_H = (vip_float_t)get_dataext(in_img_format, in_img_quant_format, 3,
										   (vip_uint8_t_ptr)img_data, in_img_fp,
										   in_img_zp, in_img_scale);


	min_box_W   = min_size * img_scale_W;
	min_box_H   = min_size * img_scale_H;

	/*
	    1. prepare the score softmax
	      1.1 resharp score data
	      1.2 softmax the score data
	      1.3 resharp score data back
	*/
	for (i = 0; i < score_count; i++) {
		vip_float_t score0 = (vip_float_t)get_dataext(in_score_format, in_score_quant_format, i,
							 (vip_uint8_t_ptr)score_data, in_score_fp,
							 in_score_zp, in_score_scale);
		vip_float_t score1 = (vip_float_t)get_dataext(in_score_format, in_score_quant_format,
							 i + score_count, (vip_uint8_t_ptr)score_data,
							 in_score_fp, in_score_zp, in_score_scale);
		vip_float_t sum = 0.0f, max = gcvip_math_max(score0, score1);

		score0 -= max;
		score1 -= max;

		score0 = gcvip_math_exp(score0);
		score1 = gcvip_math_exp(score1);
		sum = score0 + score1;

		/*
		    score_buffer:
		        0 ~ score_count:                Background scores
		        score_count ~ score_count*2:    Foreground scores
		*/
		score_buffer[i] = score0 / sum;
		score_buffer[i + score_count] = score1 / sum;
	}
	foreground_score = score_buffer + score_count;

	/*
	    2. fill proposal
	      2.1 bbox regression
	      2.2 filter out too small boxes
	      2.3 fill score and bbox into proposal buffer
	*/
	p_proposals = proposals;
	for (h = 0; h < proposal_height; h++) {
		for (w = 0; w < proposal_width; w++) {
			vip_uint32_t x = w * feat_stride;
			vip_uint32_t y = h * feat_stride;
			vip_uint32_t offset    = h * proposal_width + w;
			vip_uint8_t_ptr p_box  = bbox_data + offset * gcvip_get_format_size(in_bbox_format);
			vip_float_t *p_score = foreground_score + offset;

			for (k = 0; k < anchor_count; k++) {
				vip_float_t dx = get_dataext(in_bbox_format, in_bbox_quant_format,
											 (k * 4 + 0) * proposal_area,
											 (vip_uint8_t_ptr)p_box, in_bbox_fp,
											 in_bbox_zp, in_bbox_scale);
				vip_float_t dy = get_dataext(in_bbox_format, in_bbox_quant_format,
											 (k * 4 + 1) * proposal_area,
											 (vip_uint8_t_ptr)p_box, in_bbox_fp,
											 in_bbox_zp, in_bbox_scale);
				vip_float_t d_log_w = get_dataext(in_bbox_format, in_bbox_quant_format,
												  (k * 4 + 2) * proposal_area,
												  (vip_uint8_t_ptr)p_box, in_bbox_fp,
												  in_bbox_zp, in_bbox_scale);
				vip_float_t d_log_h = get_dataext(in_bbox_format, in_bbox_quant_format,
												  (k * 4 + 3) * proposal_area,
												  (vip_uint8_t_ptr)p_box, in_bbox_fp,
												  in_bbox_zp, in_bbox_scale);

				p_proposals[0] = x + get_dataext(in_anchor_format, in_anchor_quant_format, (k * 4 + 0),
												 (vip_uint8_t_ptr)anchor_data, in_anchor_fp,
												 in_anchor_zp, in_anchor_scale);
				p_proposals[1] = y + get_dataext(in_anchor_format, in_anchor_quant_format, (k * 4 + 1),
												 (vip_uint8_t_ptr)anchor_data, in_anchor_fp,
												 in_anchor_zp, in_anchor_scale);
				p_proposals[2] = x + get_dataext(in_anchor_format, in_anchor_quant_format, (k * 4 + 2),
												 (vip_uint8_t_ptr)anchor_data, in_anchor_fp,
												 in_anchor_zp, in_anchor_scale);
				p_proposals[3] = y + get_dataext(in_anchor_format, in_anchor_quant_format, (k * 4 + 3),
												 (vip_uint8_t_ptr)anchor_data, in_anchor_fp,
												 in_anchor_zp, in_anchor_scale);

				p_proposals[4] = rpn_transform_box(
									 p_proposals,
									 dx, dy,
									 d_log_w, d_log_h,
									 img_W, img_H,
									 min_box_W, min_box_H
								 ) * p_score[k * proposal_area];
				p_proposals += 5;
			}
		}
	}

	/* 3. Sort the proposal buffer */
	if (proposal_count > 2) {
		rpn_qsort_box(proposals, 0, proposal_count - 1, pre_nms_topn);
	} else {
		rpn_qsort_box(proposals, 0, proposal_count, pre_nms_topn);
	}

	/* 4. NMS */
	rpn_nms_cpu(pre_nms_topn, proposals, roi_indices, &real_roi, 0, nms_thresh, post_nms_topn);

	/* 5. Retrieve the rois, output proposal buffer to roi_output & score_output */
	for (i = 0; i < real_roi; i++) {
		vip_float_t item_index = 0.0f; /* item_index = input score batch, but we only supported single batch */
		p_proposals = proposals + roi_indices[i] * 5;

		/* Copy proposals coordinate(x1, y1, x2, y2) to roi output tensor */
		save_dataext(out_roi_format, out_roi_quant_format, (i * 5 + 0), item_index,
					 (vip_uint8_t_ptr)out_roi_data, out_roi_fp, out_roi_zp, out_roi_scale, out_roi_rMode);
		save_dataext(out_roi_format, out_roi_quant_format, (i * 5 + 1), p_proposals[0],
					 (vip_uint8_t_ptr)out_roi_data, out_roi_fp, out_roi_zp, out_roi_scale, out_roi_rMode);
		save_dataext(out_roi_format, out_roi_quant_format, (i * 5 + 2), p_proposals[1],
					 (vip_uint8_t_ptr)out_roi_data, out_roi_fp, out_roi_zp, out_roi_scale, out_roi_rMode);
		save_dataext(out_roi_format, out_roi_quant_format, (i * 5 + 3), p_proposals[2],
					 (vip_uint8_t_ptr)out_roi_data, out_roi_fp, out_roi_zp, out_roi_scale, out_roi_rMode);
		save_dataext(out_roi_format, out_roi_quant_format, (i * 5 + 4), p_proposals[3],
					 (vip_uint8_t_ptr)out_roi_data, out_roi_fp, out_roi_zp, out_roi_scale, out_roi_rMode);

		/* Copy proposals score to score output tensor */
		save_dataext(out_score_format, out_score_quant_format, i, p_proposals[4],
					 (vip_uint8_t_ptr)out_score_data, out_score_fp, out_score_zp,
					 out_score_scale, out_score_rMode);
	}

onError:
	if (score_buffer) {
		gcvip_user_free_memory(score_buffer);
	}
	if (proposals) {
		gcvip_user_free_memory(proposals);
	}
	if (roi_indices) {
		gcvip_user_free_memory(roi_indices);
	}

	return status;
}

static vip_status_e do_rpn_sort_nms_layer(
	vip_network_t *network,
	gcvip_lite_segment_t *segment
)
{
	vip_status_e status = VIP_SUCCESS;
	gcvip_sw_layer_rpn_sort_nms_t *rpnSortNMSLayer = (gcvip_sw_layer_rpn_sort_nms_t *)segment->base;
	vip_uint32_t pre_nms_topn = *((vip_uint32_t *)rpnSortNMSLayer->pre_nms_topn.buffer);
	vip_uint32_t post_nms_topn = *((vip_uint32_t *)rpnSortNMSLayer->post_nms_topn.buffer);
	vip_float_t nms_thresh = *((vip_float_t *)rpnSortNMSLayer->nms_thresh.buffer);
	vip_int8_t roi_output_fp  = (vip_int8_t)rpnSortNMSLayer->roi_output.fixpoint_zeropoint;
	vip_uint32_t out_roi_quant_format = rpnSortNMSLayer->roi_output.quant_format;
	vip_int32_t out_roi_zp = rpnSortNMSLayer->roi_output.fixpoint_zeropoint;
	vip_float_t out_roi_scale = rpnSortNMSLayer->roi_output.tfscale;
	vip_uint32_t roi_output_rMode = GCVIP_NN_ROUNDING_MODE_SIMPLE_ROUNDING;
	vip_uint8_t_ptr proposals_data = VIP_NULL, roi_output_data = VIP_NULL, score_output_data = VIP_NULL;
	vip_uint32_t i = 0, real_roi = 0;
	vip_enum proposal_data_format = rpnSortNMSLayer->proposal.data_format;
	vip_enum roi_output_format = rpnSortNMSLayer->roi_output.data_format;
	vip_uint32_t proposal_count = 1;
	vip_float_t_ptr proposals_ptr = VIP_NULL;

	vip_enum out_score_format = 0;
	vip_int8_t out_score_fp = 0;
	vip_uint32_t out_score_quant_format = 0;
	vip_int32_t out_score_zp = 0;
	vip_float_t out_score_scale = 0;
	vip_uint32_t out_score_rMode = GCVIP_NN_ROUNDING_MODE_SIMPLE_ROUNDING;
	vip_uint32_t count = 1;

	for (i = 0; i < rpnSortNMSLayer->proposal.dim_count; i++) {
		count *= rpnSortNMSLayer->proposal.dims[i];
	}
	proposal_count = count / 5;

	out_score_format = rpnSortNMSLayer->score_output.data_format;
	out_score_fp = (vip_int8_t)rpnSortNMSLayer->score_output.fixpoint_zeropoint;
	out_score_quant_format = rpnSortNMSLayer->score_output.quant_format;
	out_score_zp = rpnSortNMSLayer->score_output.fixpoint_zeropoint;
	out_score_scale = rpnSortNMSLayer->score_output.tfscale;

	proposals_data = rpnSortNMSLayer->proposal.buffer;
	roi_output_data = rpnSortNMSLayer->roi_output.buffer;
	score_output_data = rpnSortNMSLayer->score_output.buffer;

	if (pre_nms_topn > proposal_count) {
		pre_nms_topn = proposal_count;
	}

	if (proposal_data_format == VIP_BUFFER_FORMAT_FP32) {
		proposals_ptr = (vip_float_t_ptr)proposals_data;
		if (proposal_count > 2) {
			vx_nn_rpn_qsort_box(proposals_ptr, 0, proposal_count - 1, pre_nms_topn);
		} else {
			vx_nn_rpn_qsort_box(proposals_ptr, 0, proposal_count, pre_nms_topn);
		}
		rpn_nms_cpu(pre_nms_topn, proposals_ptr, VIP_NULL, &real_roi, 0, nms_thresh, post_nms_topn);
	} else if (proposal_data_format == VIP_BUFFER_FORMAT_FP16) {
		/*hack hw bug to save float32 as float16*/
		proposals_ptr = (vip_float_t_ptr)proposals_data;
		proposal_count = proposal_count / 2;
		if (proposal_count > 2) {
			vx_nn_rpn_qsort_box(proposals_ptr, 0, proposal_count - 1, pre_nms_topn);
		} else {
			vx_nn_rpn_qsort_box(proposals_ptr, 0, proposal_count, pre_nms_topn);
		}
		rpn_nms_cpu(pre_nms_topn, proposals_ptr, VIP_NULL, &real_roi, 0, nms_thresh, post_nms_topn);
	} else {
		/* only surpported F32 and F16 data type. todo..... */
		status = VIP_ERROR_FAILURE;
		gcvip_error("SW RPN sort and nms operation not support format %d", proposal_data_format);
	}

	for (i = 0; i < real_roi; i++) {
		vip_int32_t index = 5 * i;
		vip_float_t *ptr = proposals_ptr + index;
		save_dataext(roi_output_format, out_roi_quant_format, index + 0,      0,
					 roi_output_data, roi_output_fp, out_roi_zp, out_roi_scale, roi_output_rMode);
		save_dataext(roi_output_format, out_roi_quant_format, index + 1, ptr[0],
					 roi_output_data, roi_output_fp, out_roi_zp, out_roi_scale, roi_output_rMode);
		save_dataext(roi_output_format, out_roi_quant_format, index + 2, ptr[1],
					 roi_output_data, roi_output_fp, out_roi_zp, out_roi_scale, roi_output_rMode);
		save_dataext(roi_output_format, out_roi_quant_format, index + 3, ptr[2],
					 roi_output_data, roi_output_fp, out_roi_zp, out_roi_scale, roi_output_rMode);
		save_dataext(roi_output_format, out_roi_quant_format, index + 4, ptr[3],
					 roi_output_data, roi_output_fp, out_roi_zp, out_roi_scale, roi_output_rMode);

		if (score_output_data) {
			save_dataext(out_score_format, out_score_quant_format, i, ptr[4],
						 score_output_data, out_score_fp, out_score_zp, out_score_scale, out_score_rMode);
		}
	}

	return status;
}

/*********************CPU function implement end*****************************************/

static void *gcvip_get_sw_operation_ptr_by_index(
	vip_network_t *network,
	gcvip_bin_sw_operation_info_t *sw_ptr,
	vip_int32_t index
)
{
	void *ptr_io = VIP_NULL;
	vip_uint32_t size = 0;

	size = sizeof(gcvip_bin_sw_operation_info_t) - sizeof(vip_int8_t) * MAX_SW_LAYER_NAME_LENGTH;

	if (network->fixed.header.version >= 0x00010009) {
		ptr_io = (void *)(sw_ptr + index);
	} else {
		ptr_io = (void *)((vip_int8_t *)sw_ptr + index * size);
	}

	return ptr_io;
}

static vip_status_e paser_swlayer_parameter(
	vip_network_t *network,
	gcvip_bin_layer_parameter_t *layer_param,
	gcvip_layer_buffer_t *layer_buffer
)
{
	vip_status_e status = VIP_SUCCESS;
	vip_uint32_t i = 0;

	switch (layer_param->source_type) {
	case GCVIP_SOURCE_INPUT: {
		vip_int32_t in_index = layer_param->index;
		gcvip_io_patch_info_t *input = &network->network_inputs[in_index];

		input->sw_op_buffer = &layer_buffer->buffer;
	}
	break;

	case GCVIP_SOURCE_OUTPUT: {
		vip_int32_t out_index = layer_param->index;
		gcvip_io_patch_info_t *output = &network->network_outputs[out_index];

		output->sw_op_buffer = &layer_buffer->buffer;
	}
	break;

	case GCVIP_SOURCE_MEMORY_POOL: {
		layer_buffer->buffer = network->pool.logical + layer_param->address_offset;
	}
	break;

	case GCVIP_SOURCE_MISC_DYNA_GENERIC:
	case GCVIP_SOURCE_MISC_DYNA_INPUT:
	case GCVIP_SOURCE_MISC_DYNA_OUTPUT: {
		vip_uint32_t index = layer_param->index;
		layer_buffer->buffer = network->LCD.logical + network->LCDT[index].offset +
							   layer_param->address_offset;
	}
	break;

	default: {
		gcvip_info("not support this source type: %d\n", layer_param->source_type);
	}
	break;
	}

	layer_buffer->dim_count = layer_param->dim_count;
	layer_buffer->data_format = layer_param->data_format;
	layer_buffer->data_type = layer_param->data_type;
	layer_buffer->quant_format = layer_param->quant_format;
	layer_buffer->fixpoint_zeropoint = layer_param->fixpoint_zeropoint;
	layer_buffer->tfscale = layer_param->tfscale;

	for (i = 0; i < layer_param->dim_count; i++) {
		layer_buffer->dims[i] = layer_param->dims[i];
	}

	return status;
}

/* NBG format version is small than 0x0001000B, used this old API */
static vip_status_e paser_swlayer_parameter_old(
	vip_network_t *network,
	void *param,
	gcvip_layer_buffer_t *layer_buffer
)
{
	typedef struct _gcvip_bin_layer_parameter_entry_old {
		vip_char_t      param_name[16];
		vip_uint32_t    dim_count;
		vip_uint32_t    dims[OLD_NBG_MAX_DIMS];
		vip_uint32_t    data_format;
		vip_uint32_t    data_type;
		vip_uint32_t    quant_format;
		vip_uint32_t    fixpoint_zeropoint;
		vip_float_t     tfscale;
		vip_int32_t     index;
		vip_uint32_t    address_offset;
		vip_uint32_t    source_type;
	} gcvip_bin_layer_parameter_old_t;
	vip_status_e status = VIP_SUCCESS;
	vip_uint32_t i = 0;
	gcvip_bin_layer_parameter_old_t *layer_param = (gcvip_bin_layer_parameter_old_t *)param;

	switch (layer_param->source_type) {
	case GCVIP_SOURCE_INPUT: {
		vip_int32_t in_index = layer_param->index;
		gcvip_io_patch_info_t *input = &network->network_inputs[in_index];

		input->sw_op_buffer = &layer_buffer->buffer;
	}
	break;

	case GCVIP_SOURCE_OUTPUT: {
		vip_int32_t out_index = layer_param->index;
		gcvip_io_patch_info_t *output = &network->network_outputs[out_index];

		output->sw_op_buffer = &layer_buffer->buffer;
	}
	break;

	case GCVIP_SOURCE_MEMORY_POOL: {
		layer_buffer->buffer = network->pool.logical + layer_param->address_offset;
	}
	break;

	case GCVIP_SOURCE_MISC_DYNA_GENERIC:
	case GCVIP_SOURCE_MISC_DYNA_INPUT:
	case GCVIP_SOURCE_MISC_DYNA_OUTPUT: {
		vip_uint32_t index = layer_param->index;
		layer_buffer->buffer = network->LCD.logical + network->LCDT[index].offset +
							   layer_param->address_offset;
	}
	break;

	default: {
		gcvip_info("not support this source type: %d\n", layer_param->source_type);
	}
	break;
	}

	layer_buffer->dim_count = layer_param->dim_count;
	layer_buffer->data_format = layer_param->data_format;
	layer_buffer->data_type = layer_param->data_type;
	layer_buffer->quant_format = layer_param->quant_format;
	layer_buffer->fixpoint_zeropoint = layer_param->fixpoint_zeropoint;
	layer_buffer->tfscale = layer_param->tfscale;

	for (i = 0; i < layer_param->dim_count; i++) {
		layer_buffer->dims[i] = layer_param->dims[i];
	}

	return status;
}

static vip_status_e patch_sw_rpn(
	gcvip_bin_operation_t *operation,
	gcvip_bin_sw_operation_info_t *sw_op,
	vip_network_t *network,
	gcvip_lite_segment_t *segment
)
{
	vip_status_e status = VIP_SUCCESS;
	vip_uint32_t i = 0;
	gcvip_bin_layer_parameter_t *layer_param = VIP_NULL;
	gcvip_sw_layer_rpn_t *rpn_layer = VIP_NULL;

	gcvip_user_allocate_memory(sizeof(gcvip_sw_layer_rpn_t), (void **)&rpn_layer);

	if (network->fixed.header.version >= 0x0001000B) {
		for (i = 0; i < operation->patch_count; i++) {
			layer_param = &network->lp_entries[operation->patch_index + i];

			if (gcvip_os_strcmp(layer_param->param_name, "score") == 0) {
				paser_swlayer_parameter(network, layer_param, &rpn_layer->score);
			} else if (gcvip_os_strcmp(layer_param->param_name, "bbox") == 0) {
				paser_swlayer_parameter(network, layer_param, &rpn_layer->bbox);
			} else if (gcvip_os_strcmp(layer_param->param_name, "anchor") == 0) {
				paser_swlayer_parameter(network, layer_param, &rpn_layer->anchor);
			} else if (gcvip_os_strcmp(layer_param->param_name, "img_info") == 0) {
				paser_swlayer_parameter(network, layer_param, &rpn_layer->img_info);
			} else if (gcvip_os_strcmp(layer_param->param_name, "roi_output") == 0) {
				paser_swlayer_parameter(network, layer_param, &rpn_layer->roi_output);
			} else if (gcvip_os_strcmp(layer_param->param_name, "score_output") == 0) {
				paser_swlayer_parameter(network, layer_param, &rpn_layer->score_output);
			} else if (gcvip_os_strcmp(layer_param->param_name, "feature_stride") == 0) {
				paser_swlayer_parameter(network, layer_param, &rpn_layer->feature_stride);
			} else if (gcvip_os_strcmp(layer_param->param_name, "min_size") == 0) {
				paser_swlayer_parameter(network, layer_param, &rpn_layer->min_size);
			} else if (gcvip_os_strcmp(layer_param->param_name, "pre_nms_topn") == 0) {
				paser_swlayer_parameter(network, layer_param, &rpn_layer->pre_nms_topn);
			} else if (gcvip_os_strcmp(layer_param->param_name, "post_nms_topn") == 0) {
				paser_swlayer_parameter(network, layer_param, &rpn_layer->post_nms_topn);
			} else if (gcvip_os_strcmp(layer_param->param_name, "nms_thresh") == 0) {
				paser_swlayer_parameter(network, layer_param, &rpn_layer->nms_thresh);
			} else {
				gcvip_info("can't match layer parameter in rpn layer\n");
			}
		}
	} else {
		for (i = 0; i < operation->patch_count; i++) {
			vip_uint32_t size = sizeof(gcvip_bin_layer_parameter_t) -
								sizeof(vip_uint32_t) * (MAX_NUM_DIMS - OLD_NBG_MAX_DIMS);
			layer_param = (gcvip_bin_layer_parameter_t *)((vip_uint8_t *)network->lp_entries + i * size);

			if (gcvip_os_strcmp(layer_param->param_name, "score") == 0) {
				paser_swlayer_parameter_old(network, layer_param, &rpn_layer->score);
			} else if (gcvip_os_strcmp(layer_param->param_name, "bbox") == 0) {
				paser_swlayer_parameter_old(network, layer_param, &rpn_layer->bbox);
			} else if (gcvip_os_strcmp(layer_param->param_name, "anchor") == 0) {
				paser_swlayer_parameter_old(network, layer_param, &rpn_layer->anchor);
			} else if (gcvip_os_strcmp(layer_param->param_name, "img_info") == 0) {
				paser_swlayer_parameter_old(network, layer_param, &rpn_layer->img_info);
			} else if (gcvip_os_strcmp(layer_param->param_name, "roi_output") == 0) {
				paser_swlayer_parameter_old(network, layer_param, &rpn_layer->roi_output);
			} else if (gcvip_os_strcmp(layer_param->param_name, "score_output") == 0) {
				paser_swlayer_parameter_old(network, layer_param, &rpn_layer->score_output);
			} else if (gcvip_os_strcmp(layer_param->param_name, "feature_stride") == 0) {
				paser_swlayer_parameter_old(network, layer_param, &rpn_layer->feature_stride);
			} else if (gcvip_os_strcmp(layer_param->param_name, "min_size") == 0) {
				paser_swlayer_parameter_old(network, layer_param, &rpn_layer->min_size);
			} else if (gcvip_os_strcmp(layer_param->param_name, "pre_nms_topn") == 0) {
				paser_swlayer_parameter_old(network, layer_param, &rpn_layer->pre_nms_topn);
			} else if (gcvip_os_strcmp(layer_param->param_name, "post_nms_topn") == 0) {
				paser_swlayer_parameter_old(network, layer_param, &rpn_layer->post_nms_topn);
			} else if (gcvip_os_strcmp(layer_param->param_name, "nms_thresh") == 0) {
				paser_swlayer_parameter_old(network, layer_param, &rpn_layer->nms_thresh);
			} else {
				gcvip_info("can't match layer parameter in rpn layer\n");
			}
		}
	}

	rpn_layer->base.segment_type = sw_op->sw_peration_type;
	rpn_layer->base.name = sw_op->name;
	segment->base = &rpn_layer->base;

	return status;
}

static vip_status_e patch_sw_rpn_sort_nms(
	gcvip_bin_operation_t *operation,
	gcvip_bin_sw_operation_info_t *sw_op,
	vip_network_t *network,
	gcvip_lite_segment_t *segment
)
{
	vip_status_e status = VIP_SUCCESS;
	vip_uint32_t i = 0;
	gcvip_bin_layer_parameter_t *layer_param = VIP_NULL;
	gcvip_sw_layer_rpn_sort_nms_t *rpn_sortnms_layer = VIP_NULL;

	gcvip_user_allocate_memory(sizeof(gcvip_sw_layer_rpn_sort_nms_t), (void **)&rpn_sortnms_layer);

	for (i = 0; i < operation->patch_count; i++) {
		layer_param = &network->lp_entries[operation->patch_index + i];

		if (gcvip_os_strcmp(layer_param->param_name, "proposal") == 0) {
			paser_swlayer_parameter(network, layer_param, &rpn_sortnms_layer->proposal);
		} else if (gcvip_os_strcmp(layer_param->param_name, "roi_output") == 0) {
			paser_swlayer_parameter(network, layer_param, &rpn_sortnms_layer->roi_output);
		} else if (gcvip_os_strcmp(layer_param->param_name, "score_output") == 0) {
			paser_swlayer_parameter(network, layer_param, &rpn_sortnms_layer->score_output);
		} else if (gcvip_os_strcmp(layer_param->param_name, "pre_nms_topn") == 0) {
			paser_swlayer_parameter(network, layer_param, &rpn_sortnms_layer->pre_nms_topn);
		} else if (gcvip_os_strcmp(layer_param->param_name, "post_nms_topn") == 0) {
			paser_swlayer_parameter(network, layer_param, &rpn_sortnms_layer->post_nms_topn);
		} else if (gcvip_os_strcmp(layer_param->param_name, "nms_thresh") == 0) {
			paser_swlayer_parameter(network, layer_param, &rpn_sortnms_layer->nms_thresh);
		} else {
			gcvip_info("can't match layer parameter in rpn sort and nms layer\n");
		}
	}

	rpn_sortnms_layer->base.segment_type = sw_op->sw_peration_type;
	rpn_sortnms_layer->base.name = sw_op->name;
	segment->base = &rpn_sortnms_layer->base;

	return status;
}

/*
@brief Parser software operation which create by user.(not build in OpenVX)
@param operation The operation info in NBG. see NBG format Operations[n].
@param sw_op The software operation info in NBG. see NBG format Enumerations [8].
@param network The network object.
@param segment The segment object.
*/
static vip_status_e patch_sw_user(
	gcvip_bin_operation_t *operation,
	gcvip_bin_sw_operation_info_t *sw_op,
	vip_network_t *network,
	gcvip_lite_segment_t *segment
)
{
	vip_status_e status = VIP_SUCCESS;
	vip_uint32_t i = 0;
	gcvip_bin_layer_parameter_t *layer_param = VIP_NULL;
	gcvip_sw_layer_user_t *user_layer = VIP_NULL;

	gcOnError(gcvip_user_allocate_memory(sizeof(gcvip_sw_layer_user_t), (void **)&user_layer));
	gcOnError(gcvip_user_allocate_memory(operation->patch_count * sizeof(gcvip_layer_buffer_t),
										 (void **)&user_layer->buffers));

	for (i = 0; i < operation->patch_count; i++) {
		layer_param = &network->lp_entries[operation->patch_index + i];
		paser_swlayer_parameter(network, layer_param, &user_layer->buffers[i]);
	}

	user_layer->buffer_num = operation->patch_count;
	user_layer->base.segment_type = sw_op->sw_peration_type;
	user_layer->base.name = sw_op->name;
	segment->base = &user_layer->base;

	return status;

onError:
	if (user_layer != VIP_NULL) {
		gcvip_user_free_memory(user_layer);
		user_layer = VIP_NULL;
	}
	return status;
}

/*
@brief Parser software layers in NBG file.
@param operation The operation info in NBG. see NBG format Operations[n].
@param sw_op The software operation info in NBG. see NBG format Enumerations [8].
@param network The network object.
@param segment The segment object.
*/
static vip_status_e patch_sw(
	gcvip_bin_operation_t *operation,
	gcvip_bin_sw_operation_info_t *sw_op,
	vip_network_t *network,
	gcvip_lite_segment_t *segment
)
{
	vip_status_e status = VIP_SUCCESS;

	switch (sw_op->sw_peration_type) {
	case GCVIP_SW_OPERATION_RPN: {
		gcOnError(patch_sw_rpn(operation, sw_op, network, segment));
	}
	break;

	case GCVIP_SW_OPERATION_RPN_SORT_NMS: {
		gcOnError(patch_sw_rpn_sort_nms(operation, sw_op, network, segment));
	}
	break;

	case GCVIP_SW_OPEARTION_USER_CPU: {
		gcOnError(patch_sw_user(operation, sw_op, network, segment));
	}
	break;

	default:
		gcvip_error("invalid sw operation\n");
		gcOnError(VIP_ERROR_FAILURE);
		break;
	}

onError:
	return status;
}

/*
@brief Rlease resouce create in patch_sw function flow.
@param segment The segment object.
*/
vip_status_e gcvip_sw_release_resource(
	gcvip_lite_segment_t *segment
)
{
	vip_status_e status = VIP_SUCCESS;

	if ((segment == VIP_NULL) || (segment->base == VIP_NULL)) {
		return status;
	}

	if (GCVIP_SW_OPEARTION_USER_CPU == segment->base->segment_type) {
		gcvip_sw_layer_user_t *user_layer = (gcvip_sw_layer_user_t *)segment->base;
		if (user_layer->buffers != VIP_NULL) {
			gcvip_user_free_memory(user_layer->buffers);
			user_layer->buffers = VIP_NULL;
		}
	}

	gcvip_user_free_memory(segment->base);
	segment->base = VIP_NULL;

	return status;
}

/*
@brief Parser NBG file to prepare software layer.
@param network The network object.
@param segment The segment object.
*/
vip_status_e gcvip_sw_prepare_layer(
	vip_network_t *network,
	gcvip_lite_segment_t *segment
)
{
	gcvip_bin_operation_t *operation = VIP_NULL;
	gcvip_bin_sw_operation_info_t *sw_op = VIP_NULL;
	vip_uint32_t i = 0;
	vip_status_e status = VIP_SUCCESS;

	for (i = 0; i < network->n_operations; i++) {
		operation = &network->operations[i];

		if (i != segment->segm_start_id) {
			continue;
		}

		if (operation->type == GCVIP_OPERATION_TYPE_SW) {
			sw_op = (gcvip_bin_sw_operation_info_t *)gcvip_get_sw_operation_ptr_by_index(network,
					network->sw_ops,
					operation->index);
			status = patch_sw(operation, sw_op, network, segment);
			if (status != VIP_SUCCESS) {
				gcvip_error("patch sw failed\n");
				gcGoOnError(VIP_ERROR_NOT_SUPPORTED);
			} else {
				gcvip_info("patch sw opeation name=%s successfully\n", segment->name);
				break;
			}
		}
	}

onError:
	return status;
}

/*
@brief Run software layer.
@param network The network object.
@param segment The segment object.
*/
vip_status_e gcvip_sw_do_layer(
	vip_network_t *network,
	gcvip_lite_segment_t *segment
)
{
	vip_status_e status = VIP_SUCCESS;

#if vpmdENABLE_CNN_PROFILING
	segment->start_time = gcvip_os_get_time();
#endif

	switch (segment->base->segment_type) {
	case GCVIP_SW_OPERATION_RPN: {
		gcOnError(do_rpn_layer(network, segment));
	}
	break;

	case GCVIP_SW_OPERATION_RPN_SORT_NMS: {
		gcOnError(do_rpn_sort_nms_layer(network, segment));
	}
	break;

	/* Verisilicon no longer recommends using this way to support
	   customer software operation now. May instead by TFLite-Micro
	*/
	case GCVIP_SW_OPEARTION_USER_CPU: {
		gcOnError(gcvip_do_user_layer(network, segment));
	}
	break;

	default:
		gcvip_error("do sw layer, invalid sw operation, type: %d\n",
					segment->base->segment_type);
		break;
	}

#if vpmdENABLE_CNN_PROFILING
	segment->end_time = gcvip_os_get_time();
	if (segment->end_time > segment->start_time) {
		network->total_time += segment->end_time - segment->start_time;
	} else {
		gcvip_error("failed to get sw layer time, start %ld, end %ld\n",
					segment->start_time, segment->end_time);
	}
#endif

onError:
	return status;
}

#endif
