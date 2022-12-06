//------------------------------------------------------
// Yolov5
//------------------------------------------------------
#include <math.h>
#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "img_process/img_process.h"
#include "mmf2_module.h"
#include "module_vipnn.h"
#include "hal_cache.h"

static float yolov5_confidence_thresh = 0.25;    // default
static float yolov5_nms_thresh = 0.3;      // default

static float u8_to_f(uint8_t val, uint8_t zero_p, float scale)
{
	return  scale * ((float)val - (float)zero_p);
}

static float s8_to_f(int8_t val, int q)
{
	return (float)val / (float)(1 << q);
}

static float s16_to_f(int16_t val, int q)
{
	return (float)val / (float)(1 << q);
}

static float bf16_to_f(__fp16 val)
{
	return (float)val;
}

static float q2f(void *val, nn_tensor_format_t *fmt)
{
	switch (fmt->buf_type) {
	case VIP_BUFFER_FORMAT_INT16:
		// s16
		return s16_to_f(*(int16_t *)val, fmt->fix_point_pos);
	case VIP_BUFFER_FORMAT_INT8:
		// s8
		return s8_to_f(*(int8_t *)val, fmt->fix_point_pos);
	case VIP_BUFFER_FORMAT_UINT8:
		// u8
		return u8_to_f(*(uint8_t *)val, fmt->zero_point, fmt->scale);
	case VIP_BUFFER_FORMAT_FP16:
		// bf16
		return bf16_to_f(*(__fp16 *)val);
	default:
		// fp32
		return *(float *)val;
	}
}

static uint8_t f_to_u8(float val, uint8_t zero_p, float scale)
{
	return (uint8_t)(val / scale) + zero_p;
}

static int8_t f_to_s8(float val, int q)
{
	return (int8_t)(val * (1 << q));
}

static int16_t f_to_s16(float val, int q)
{
	return (int16_t)(val * (1 << q));
}

static __fp16 f_to_bf16(float val)
{
	return (__fp16)val;
}

static float inv_sigmoid(float x)
{
	return -log((1 - x) / x);
}

void *yolov5_get_network_filename(void)
{
	return (void *)"NN_MDL/yolov5n_int16.nb";	// fix name for NN model binary
}

static int yolo_in_width, yolo_in_height;

int yolov5_preprocess(void *data_in, nn_data_param_t *data_param, void *tensor_in, nn_tensor_param_t *tensor_param)
{
	void **tensor = (void **)tensor_in;
	rect_t *roi = &data_param->img.roi;

	img_t img_in, img_out;

	img_in.width  = data_param->img.width;
	img_in.height = data_param->img.height;
	img_out.width  = tensor_param->dim[0].size[0];
	img_out.height = tensor_param->dim[0].size[1];
	yolo_in_width  = tensor_param->dim[0].size[0];
	yolo_in_height = tensor_param->dim[0].size[1];

	img_in.data   = (unsigned char *)data_in;
	img_out.data   = (unsigned char *)tensor[0];
	//printf("src %d %d, dst %d %d\n\r", img_in.width, img_in.height, img_out.width, img_out.height);
	//printf("roi %d %d %d %d \n\r", roi->xmin, roi->ymin, roi->xmax, roi->ymax);

	// resize src ROI area to dst
	if (img_in.width == img_out.width && img_in.height == img_out.height) {
		//memcpy(img_out.data, img_in.data, img_out.width * img_out.height * 3);
		img_dma_copy(img_out.data, img_in.data, img_out.width * img_out.height * 3);
	} else {
		img_resize_planar(&img_in, roi, &img_out);
	}

	dcache_clean_by_addr((uint32_t *)img_out.data, img_out.width * img_out.height * 3);

	return 0;
}

typedef struct data_format_s {
	nn_tensor_format_t *format;
	nn_tensor_dim_t *dim;
} data_format_t;

static int yolo_get_element_size(data_format_t *fmt)
{
	int es = 1;
	switch (fmt->format->buf_type) {
	case VIP_BUFFER_FORMAT_INT16:
	case VIP_BUFFER_FORMAT_FP16:
		es = 2;
		break;
	case VIP_BUFFER_FORMAT_FP32:
		es = 4;
		break;
	default:
		break;
	}

	return es;
}

static int yolo_get_offset(data_format_t *fmt, int idx)
{
	int es = 1;
	switch (fmt->format->buf_type) {
	case VIP_BUFFER_FORMAT_INT16:
	case VIP_BUFFER_FORMAT_FP16:
		es = 2;
		break;
	case VIP_BUFFER_FORMAT_FP32:
		es = 4;
		break;
	default:
		break;
	}

	return idx * es;
}

static void *yolo_get_data_addr(void *data, data_format_t *fmt, int idx)
{
	int offset = yolo_get_offset(fmt, idx);
	uint8_t *data8 = (uint8_t *)data;

	return (void *)&data8[offset];
}

static float yolo_get_data(void *data, data_format_t *fmt, int idx)
{
	void *datax = (void *)yolo_get_data_addr(data, fmt, idx);
	return q2f(datax, fmt->format);
}

static int yolo_filter_class(void *data, data_format_t *fmt, int *class_idx, float threshold, int class_num)
{
	int count = 0;
	switch (fmt->format->buf_type) {
	case VIP_BUFFER_FORMAT_INT16: {
		int16_t th16 = f_to_s16(threshold, fmt->format->fix_point_pos);
		for (int x = 0; x < class_num; x++) {
			int16_t tmp = *(int16_t *)yolo_get_data_addr(data, fmt, 5 + x);
			if (tmp > th16) {
				class_idx[count] = x;
				count++;
			}
		}
		break;
	}
	case VIP_BUFFER_FORMAT_INT8: {
		int8_t th8 = f_to_s8(threshold, fmt->format->fix_point_pos);
		for (int x = 0; x < class_num; x++) {
			int8_t tmp = *(int8_t *)yolo_get_data_addr(data, fmt, 5 + x);
			if (tmp > th8) {
				class_idx[count] = x;
				count++;
			}
		}
		break;
	}
	case VIP_BUFFER_FORMAT_UINT8: {
		uint8_t th8 = f_to_u8(threshold, fmt->format->zero_point, fmt->format->scale);
		for (int x = 0; x < class_num; x++) {
			uint8_t tmp = *(uint8_t *)yolo_get_data_addr(data, fmt, 5 + x);
			if (tmp > th8) {
				class_idx[count] = x;
				count++;
			}
		}
		break;
	}
	case VIP_BUFFER_FORMAT_FP16: {
		__fp16 th16f = f_to_bf16(threshold);
		for (int x = 0; x < class_num; x++) {
			__fp16 tmp = *(__fp16 *)yolo_get_data_addr(data, fmt, 5 + x);
			if (tmp > th16f) {
				class_idx[count] = x;
				count++;
			}
		}
		break;
	}
	default: {
		float th32f = threshold;
		for (int x = 0; x < class_num; x++) {
			float tmp = *(float *)yolo_get_data_addr(data, fmt, 5 + x);
			if (tmp > th32f) {
				class_idx[count] = x;
				count++;
			}
		}
		break;
	}
	}

	return count;
}

typedef struct box_s {
	float prob;
	int invalid;
	float objectness;
	float class_prob;
	int class_idx;
	float x, y;
	float w, h;
} box_t;

#define MAX_BOX_CNT 64
static box_t res_box[MAX_BOX_CNT];
static box_t *p_res_box[MAX_BOX_CNT];
static int box_idx;

//-----------------------------IOU-----------------------------

#define max(a,b) \
   ({ __typeof__ (a) _a = (a); \
       __typeof__ (b) _b = (b); \
     _a > _b ? _a : _b; })

#define min(a,b) \
   ({ __typeof__ (a) _a = (a); \
       __typeof__ (b) _b = (b); \
     _a < _b ? _a : _b; })

typedef enum {
	IOU,
	DIOU,
} iou_t;

static float overlap(float x1, float w1, float x2, float w2)
{
	float l1 = x1 - w1 / 2;
	float l2 = x2 - w2 / 2;
	float left = max(l1, l2);
	float r1 = x1 + w1 / 2;
	float r2 = x2 + w2 / 2;
	float right = min(r1, r2);
	return right - left;
}

static float box_intersection(box_t *a, box_t *b)
{
	float w = overlap(a->x, a->w, b->x, b->w);
	float h = overlap(a->y, a->h, b->y, b->h);
	if (w < 0 || h < 0) {
		return 0;
	}
	float area = w * h;
	return area;
}

static float box_union(box_t *a, box_t *b)
{
	float i = box_intersection(a, b);
	float u = a->w * a->h + b->w * b->h - i;
	return u;
}

static float box_iou(box_t *a, box_t *b)
{
	return box_intersection(a, b) / box_union(a, b);
}

// return a smallest box contain a and b
static box_t box_box(box_t *a, box_t *b)
{
	box_t c;
	float c_topx = min(a->x, b->x);
	float c_topy = min(a->y, b->y);
	float c_botx = max(a->x + a->w, b->x + b->w);
	float c_boty = max(a->y + a->h, b->y + b->h);
	c.x = c_topx;
	c.y = c_topy;
	c.w = c_botx - c_topx;
	c.h = c_boty - c_topy;
	return c;
}

static float box_diou(box_t *a, box_t *b)
{
	float a_cx = a->x + (a->w / 2);
	float a_cy = a->y + (a->h / 2);
	float b_cx = b->x + (b->w / 2);
	float b_cy = b->y + (b->h / 2);
	box_t ab = box_box(a, b);
	float c = ab.w * ab.w + ab.h * ab.h;
	float d = (a_cx - b_cx) * (a_cx - b_cx) + (a_cy - b_cy) * (a_cy - b_cy);
	float u = pow(d / c, 0.6);
	return box_iou(a, b) - u;
}

static float box_nms_iou(box_t *a, box_t *b, iou_t iou_type)
{
	switch (iou_type) {
	case IOU:
		return box_iou(a, b);
	case DIOU:
		return box_diou(a, b);
	}
	return 0.0;
}

//-----------------------------NMS-----------------------------

static int nms_comparator(const void *pa, const void *pb)
{
	box_t *a = *(box_t **)pa;
	box_t *b = *(box_t **)pb;
	float diff = a->prob - b->prob;
	if (diff < 0) {
		return 1;
	} else if (diff > 0) {
		return -1;
	}
	return 0;
}

static int setup_class_box(int class, int total)
{
	int class_cnt = 0;
	for (int i = 0; i < total; i++) {
		if (res_box[i].class_idx == class) {
			p_res_box[class_cnt] = &res_box[i];
			class_cnt++;
		}
	}
	return class_cnt;
}

static void do_nms(int classes, int total, float threshold)
{
	int class_cnt;
	box_t *a, *b;
	for (int c = 0; c < classes; c++) {
		class_cnt = setup_class_box(c, total);
		qsort(p_res_box, class_cnt, sizeof(box_t *), nms_comparator);
		for (int i = 0; i < class_cnt; i++) {
			a = p_res_box[i];
			for (int j = i + 1; j < class_cnt; j++) {
				b = p_res_box[j];
				if (box_nms_iou(a, b, DIOU) > threshold) {
					b->invalid = 1;
				}
			}
		}
	}
}

static int __decode_yolov5(data_format_t *fmt, void *out)
{
	int max_i = 0;
	float cp = 0;
	int class_idx[80];
	int class_cnt = 0;
	int pass_cnt = 0;

	float p = yolo_get_data(out, fmt, 4);
	if (p < yolov5_confidence_thresh) {
		return 0;
	}

	int classes = fmt->dim->size[0] - 5;
	class_cnt = yolo_filter_class(out, fmt, class_idx, inv_sigmoid(0.5), classes);
	//printf("[yolov5_postprocess]yolo_filter_class class_cnt=%d\r\n", class_cnt);

	for (int ci = 0; ci < class_cnt; ci++) {
		max_i = class_idx[ci];
		cp = yolo_get_data(out, fmt, 5 + max_i);

		if (cp * p >= yolov5_confidence_thresh && box_idx < MAX_BOX_CNT) {

			float cx = yolo_get_data(out, fmt, 0) / yolo_in_width;
			float cy = yolo_get_data(out, fmt, 1) / yolo_in_height;
			float w = yolo_get_data(out, fmt, 2) / yolo_in_width;
			float h = yolo_get_data(out, fmt, 3) / yolo_in_height;

			float x = cx - w / 2;
			float y = cy - h / 2;
			x = max(x, 0);
			x = min(x, 1);
			y = max(y, 0);
			y = min(y, 1);

			//printf("x y w h = %f %f %f %f\n\r", x, y, w, h);
			//printf("x y w h = %3.0f %3.0f %3.0f %3.0f\n\r", x*yolo_in_width, y*yolo_in_height, w*yolo_in_width, h*yolo_in_height);

			res_box[box_idx].objectness = p;
			res_box[box_idx].class_prob = cp;
			res_box[box_idx].class_idx = max_i;
			res_box[box_idx].prob = cp * p;
			res_box[box_idx].x = x;
			res_box[box_idx].y = y;
			res_box[box_idx].w = w;
			res_box[box_idx].h = h;
			box_idx++;
			pass_cnt++;
		}
	}

	return pass_cnt;
}

static vipnn_res_t yolo_res;
void *yolov5_postprocess(void *tensor_out, nn_tensor_param_t *param)
{
	void **tensor = (void **)tensor_out;

	int classes = param->dim[0].size[0] - 5;
	printf("[yolov5_postprocess]classes=%d\r\n", classes);
	int output_count = param->count;

	int row = param->dim[0].size[1];
	int col = param->dim[0].size[0];
	printf("[yolov5_postprocess]row,col=%d,%d\r\n", row, col);

	// reset box index
	box_idx = 0;
	memset(res_box, 0, sizeof(res_box));

	data_format_t fmt;
	fmt.format = &param->format[0];
	fmt.dim = &param->dim[0];
	uint8_t *bb0 = (uint8_t *)tensor[0];

	// yolov5 decode
	int es = yolo_get_element_size(&fmt);
	printf("[yolov5_postprocess]es=%d\r\n", es);
	for (int i = 0; i < row; i++) {
		__decode_yolov5(&fmt, bb0 + i * col * es);
	}

	// NMS
	do_nms(classes, box_idx, yolov5_nms_thresh);

	// dump result
	/*
	for (int i = 0; i < box_idx; i++) {
		box_t *b = &res_box[i];
		printf("x y w h = %f %f %f %f\n\r", b->x, b->y, b->w, b->h);
		printf("x y w h = %3.0f %3.0f %3.0f %3.0f\n\r", b->x * yolo_in_width, b->y * yolo_in_height, b->w * yolo_in_width, b->h * yolo_in_height);
		printf("p %2.6f, obj %2.6f, cp %2.6f, class %d, invalid %d\n\r", b->prob, b->objectness, b->class_prob, b->class_idx, b->invalid);
	}
	*/
	yolo_res.od_res.obj_num  = 0;
	for (int i = 0; i < box_idx; i++) {
		box_t *b = &res_box[i];

		if (b->invalid == 0) {
			yolo_res.od_res.result[yolo_res.od_res.obj_num * 6 + 0] = b->class_idx;
			yolo_res.od_res.result[yolo_res.od_res.obj_num * 6 + 1] = b->prob;
			yolo_res.od_res.result[yolo_res.od_res.obj_num * 6 + 2] = b->x;	// top_x
			yolo_res.od_res.result[yolo_res.od_res.obj_num * 6 + 3] = b->y;	// top_y
			yolo_res.od_res.result[yolo_res.od_res.obj_num * 6 + 4] = b->x + b->w; // bottom_x
			yolo_res.od_res.result[yolo_res.od_res.obj_num * 6 + 5] = b->y + b->h; // bottom_y
			yolo_res.od_res.obj_num++;
		}
	}

	return &yolo_res;
}

static void yolov5_set_confidence_thresh(void *confidence_thresh)
{
	yolov5_confidence_thresh = *(float *)confidence_thresh;
	printf("set yolov5 confidence thresh to %f\n\r", *(float *)confidence_thresh);
}

static void yolov5_set_nms_thresh(void *nms_thresh)
{
	yolov5_nms_thresh = *(float *)nms_thresh;
	printf("set yolov5 NMS thresh to %f\n\r", *(float *)nms_thresh);
}

nnmodel_t yolov5 = {
	.nb 			= yolov5_get_network_filename,
	.preprocess 	= yolov5_preprocess,
	.postprocess 	= yolov5_postprocess,
	.model_src 		= MODEL_SRC_FILE,
	.set_confidence_thresh   = yolov5_set_confidence_thresh,
	.set_nms_thresh     = yolov5_set_nms_thresh,

	.name = "YOLOv5"
};