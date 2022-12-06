//------------------------------------------------------
// yolox-tiny and yolox-nano
//------------------------------------------------------
#include <math.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "img_process/img_process.h"
#include "mmf2_module.h"
#include "module_vipnn.h"
#include "hal_cache.h"

static float yolox_confidence_thresh = 0.5;    // default
static float yolox_nms_thresh = 0.3;      // default

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

void *yolox_get_network_filename(void)
{
	return (void *)"NN_MDL/yolox_tiny.nb";	// fix name for NN model binary
}

static int yolo_in_width, yolo_in_height;

int yolox_preprocess(void *data_in, nn_data_param_t *data_param, void *tensor_in, nn_tensor_param_t *tensor_param)
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
	return idx * yolo_get_element_size(fmt);
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

typedef struct GridAndStride {
	int grid0;
	int grid1;
	int stride;
} GridAndStride_t;

GridAndStride_t *grid_strides = NULL;

static void generate_grids_and_stride(const int target_w, const int target_h, int *strides, int stride_size)
{
	int gridStrideCnt = 0;
	for (int i = 0; i < stride_size; i++) {
		int stride = strides[i];
		int num_grid_w = target_w / stride;
		int num_grid_h = target_h / stride;
		for (int g1 = 0; g1 < num_grid_h; g1++) {
			for (int g0 = 0; g0 < num_grid_w; g0++) {
				GridAndStride_t gs;
				gs.grid0 = g0;
				gs.grid1 = g1;
				gs.stride = stride;
				grid_strides[gridStrideCnt] = gs;
				gridStrideCnt++;
			}
		}
	}
}

void generate_yolox_proposals(data_format_t *fmt, void *out, int anchor_idx)
{
	float box_objectness = yolo_get_data(out, fmt, 4);
	if (box_objectness < yolox_confidence_thresh) {
		return;
	}

	const int grid0 = grid_strides[anchor_idx].grid0;
	const int grid1 = grid_strides[anchor_idx].grid1;
	const int stride = grid_strides[anchor_idx].stride;

	int class_num = fmt->dim->size[0] - 5;

	// yolox decode
	float x_center = (yolo_get_data(out, fmt, 0) + grid0) * stride;
	float y_center = (yolo_get_data(out, fmt, 1) + grid1) * stride;
	float w = exp(yolo_get_data(out, fmt, 2)) * stride;
	float h = exp(yolo_get_data(out, fmt, 3)) * stride;
	float x0 = x_center - w * 0.5f;
	float y0 = y_center - h * 0.5f;

	//printf("x0 y0 w h = %f %f %f %f\n\r", x0, y0, w, h);

	for (int class_idx = 0; class_idx < class_num; class_idx++) {
		float box_cls_score = yolo_get_data(out, fmt, 5 + class_idx);
		float box_prob = box_objectness * box_cls_score;
		if (box_prob > yolox_confidence_thresh) {
			res_box[box_idx].objectness = box_objectness;
			res_box[box_idx].class_prob = box_cls_score;
			res_box[box_idx].class_idx = class_idx;
			res_box[box_idx].prob = box_prob;
			res_box[box_idx].x = x0 / yolo_in_width;
			res_box[box_idx].y = y0 / yolo_in_height;
			res_box[box_idx].w = w / yolo_in_width;
			res_box[box_idx].h = h / yolo_in_height;
			box_idx++;

			//printf("x0 y0 w h = %f %f %f %f\n\r", x0, y0, w, h);
			//printf("x0 y0 w h = %3.0f %3.0f %3.0f %3.0f\n\r", x0*yolo_in_width, y0*yolo_in_height, w*yolo_in_width, h*yolo_in_height);
		}
	}
}

static vipnn_res_t yolo_res;
void *yolox_postprocess(void *tensor_out, nn_tensor_param_t *param)
{
	u32 t0 = xTaskGetTickCount();
	void **tensor = (void **)tensor_out;

	int classes = param->dim[0].size[0] - 5;
	//printf("[yolox_postprocess]classes=%d\r\n", classes);
	int output_count = param->count;

	int row = param->dim[0].size[1];
	int col = param->dim[0].size[0];
	//printf("[yolox_postprocess]row,col=%d,%d\r\n", row, col);

	// generate grids & stride
	if (!grid_strides) {
		grid_strides = (GridAndStride_t *)malloc(row * sizeof(GridAndStride_t));
		if (!grid_strides) {
			printf("fail to allocate memory for grid_strides\r\n");
			while (1);
		}
		int strides[3] = {8, 16, 32};
		generate_grids_and_stride(yolo_in_width, yolo_in_height, strides, sizeof(strides) / sizeof(int));
	}

	// reset box index
	box_idx = 0;
	memset(res_box, 0, sizeof(res_box));

	data_format_t fmt;
	fmt.format = &param->format[0];
	fmt.dim = &param->dim[0];
	uint8_t *bb0 = (uint8_t *)tensor[0];

	// yolox decode
	int es = yolo_get_element_size(&fmt);
	for (int anchor_idx = 0; anchor_idx < row; anchor_idx++) {
		generate_yolox_proposals(&fmt, bb0 + anchor_idx * col * es, anchor_idx);
	}

	// NMS
	do_nms(classes, box_idx, yolox_nms_thresh);

	// fill result
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

static void yolox_set_confidence_thresh(void *confidence_thresh)
{
	yolox_confidence_thresh = *(float *)confidence_thresh;
	printf("set yolox confidence thresh to %f\n\r", *(float *)confidence_thresh);
}

static void yolox_set_nms_thresh(void *nms_thresh)
{
	yolox_nms_thresh = *(float *)nms_thresh;
	printf("set yolox NMS thresh to %f\n\r", *(float *)nms_thresh);
}

nnmodel_t yolox_fwfs = {
	.nb 			= yolox_get_network_filename,
	.preprocess 	= yolox_preprocess,
	.postprocess 	= yolox_postprocess,
	.model_src 		= MODEL_SRC_FILE,
	.set_confidence_thresh   = yolox_set_confidence_thresh,
	.set_nms_thresh     = yolox_set_nms_thresh,

	.name = "YOLOX"
};