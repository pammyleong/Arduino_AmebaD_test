//---------------------------------------------------------
// Face Detection and Landmark - CenterFace
//---------------------------------------------------------
#include <math.h>
#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "img_process/img_process.h"
#include "nn_utils/iou.h"
#include "nn_utils/nms.h"
#include "nn_utils/quantize.h"
#include "nn_utils/tensor.h"
#include "mmf2_module.h"
#include "module_vipnn.h"
#include "fwfs.h"
#include "hal_cache.h"
#include "pre_process.h"

#define DBG_LEVEL	LOG_ERR

#define LOG_OFF		4
#define LOG_ERR		3
#define LOG_MSG		2
#define LOG_INF		1
#define LOG_ALL		0

#define dprintf(level, ...) if(level >= DBG_LEVEL) printf(__VA_ARGS__)

#define max(a,b) \
   ({ __typeof__ (a) _a = (a); \
       __typeof__ (b) _b = (b); \
     _a > _b ? _a : _b; })

#define min(a,b) \
   ({ __typeof__ (a) _a = (a); \
       __typeof__ (b) _b = (b); \
     _a < _b ? _a : _b; })

#define MAX_FACE_CNT MAX_DETECT_OBJ_NUM
static box_t face_box[MAX_FACE_CNT];
static box_t *p_face_box[MAX_FACE_CNT];
static int face_cnt = 0;

static int id_pair[MAX_FACE_CNT][2];
static int id_pair_cnt = 0;

void *centerface_get_network_filename(void)
{
	return (void *)"NN_MDL/centerface_uint8.nb";	// fix name for NN model binary
}

//--------PRE PROCESS-------------------------------------------

static int face_in_width, face_in_height;
int centerface_preprocess(void *data_in, nn_data_param_t *data_param, void *tensor_in, nn_tensor_param_t *tensor_param)
{
	void **tensor = (void **)tensor_in;
	rect_t *roi = (rect_t *)&data_param->img.roi;

	img_t img_in, img_out;

	img_in.width  = data_param->img.width;
	img_in.height = data_param->img.height;
	img_out.width  = tensor_param->dim[0].size[0];
	img_out.height = tensor_param->dim[0].size[1];
	face_in_width  = tensor_param->dim[0].size[0];
	face_in_height = tensor_param->dim[0].size[1];

	img_in.data = (uint8_t *)data_in;
	img_out.data = (uint8_t *)tensor[0];
	dprintf(LOG_INF, "[nn preprocess]src %d %d, dst %d %d\n\r", img_in.width, img_in.height, img_out.width, img_out.height);
	dprintf(LOG_INF, "[nn preprocess]roi %d %d %d %d \n\r", roi->xmin, roi->ymin, roi->xmax, roi->ymax);

	// resize src ROI area to dst
	if (img_in.width == img_out.width && img_in.height == img_out.height) {
		dprintf(LOG_INF, "[nn preprocess]same size, just copy!\n\r");
		//memcpy(img_out.data, img_in.data, img_out.width * img_out.height * 3);
		img_dma_copy(img_out.data, img_in.data, img_out.width * img_out.height * 3);
	} else {
		dprintf(LOG_INF, "[nn preprocess]resize to NN input size!\n\r");
		//img_resize_planar(&img_in, roi, &img_out);
		img_scaled_into_letterbox(&img_in, &img_out);
	}

	dcache_clean_by_addr((uint32_t *)img_out.data, img_out.width * img_out.height * 3);

	return 0;
}

static float get_heatmap_data(void *heatmap, nn_tensor_param_t *param, int idx)
{
	return get_tensor_value(heatmap, idx, &param->format[0]);
}

static float get_scale_data(void *scale, nn_tensor_param_t *param, int idx)
{
	return get_tensor_value(scale, idx, &param->format[1]);
}

static float get_offset_data(void *offset, nn_tensor_param_t *param, int idx)
{
	return get_tensor_value(offset, idx, &param->format[2]);
}

static float get_landmarks_data(void *landmarks, nn_tensor_param_t *param, int idx)
{
	return get_tensor_value(landmarks, idx, &param->format[3]);
}

static void get_id_pair_from_heatmap(void *heatmap, nn_tensor_param_t *param, int w, int h, float thresh)
{
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			//dprintf(LOG_INF, "%6.2f ", heatmap[i * w + j]);
			if (get_heatmap_data(heatmap, param, i * w + j) > thresh) {
				if (id_pair_cnt < MAX_FACE_CNT) {
					id_pair[id_pair_cnt][0] = j;  // h_x
					id_pair[id_pair_cnt][1] = i;  // h_y
					id_pair_cnt++;
					dprintf(LOG_INF, "[heatmap] (i,j,cnt):%d,%d,%f\r\n", i, j, get_heatmap_data(heatmap, param, i * w + j));
				}
			}
		}
	}
}

static void facebox_dump(int log_level)
{
	if (log_level >= DBG_LEVEL) {
		printf("--------------------------------------------------\r\n");
		printf("facebox dump\r\n");
		printf("--------------------------------------------------\r\n");
		for (int i = 0; i < face_cnt; i++) {
			printf("x,y,w,h:%6.2f %6.2f %6.2f %6.2f %6.2f\r\n", face_box[i].x, face_box[i].y, face_box[i].w, face_box[i].h, face_box[i].score);
		}
		printf("--------------------------------------------------\r\n");
	}
}

//--------POST PROCESS-------------------------------------------

static float score_thres = 0.5;
static float nms_thres = 0.3;

static vipnn_res_t centerface_res;

void *centerface_postprocess(void *tensor_out, nn_tensor_param_t *param)
{
	void **tensor = (void **)tensor_out;

	uint8_t *heatmap = (uint8_t *)tensor[0];
	uint8_t *scale0 = (uint8_t *)tensor[1];
	uint8_t *offset0 = (uint8_t *)tensor[2];
	uint8_t *landmarks = (uint8_t *)tensor[3];

	int fea_w = param->dim[0].size[0];
	int fea_h = param->dim[0].size[1];
	int spacial_size = fea_w * fea_h;
	dprintf(LOG_INF, "[nn postprocess]fea_w,fea_h: %d,%d\r\n", fea_w, fea_h);

	// get id pair from heapmap
	id_pair_cnt = 0;
	get_id_pair_from_heatmap(heatmap, param, fea_w, fea_h, score_thres);
	if (id_pair_cnt == 0) {
		centerface_res.fd_res.obj_num  = 0;
		goto centerface_cleanup;
	}
	dprintf(LOG_INF, "[nn postprocess]get_id_pair_from_heatmap done.\r\n");

	// reset facebox
	face_cnt = 0;
	memset(face_box, 0, sizeof(face_box));
	dprintf(LOG_INF, "[nn postprocess](sizeof(face_box),sizeof(box_t)):%d,%d\r\n", sizeof(face_box), sizeof(box_t));

	// decode
	int d_w = face_in_width;
	int d_h = face_in_height;
	for (int i = 0; i < id_pair_cnt && face_cnt < MAX_FACE_CNT; i++) {
		int id_w = id_pair[i][0];  // h_x
		int id_h = id_pair[i][1];  // h_y
		int index = id_h * fea_w + id_w;
		dprintf(LOG_INF, "[nn postprocess][decode] (id_w,id_h,index):%d,%d,%d\r\n", id_w, id_h, index);

		float s0 = exp(get_scale_data(scale0, param, index)) * 4;
		float s1 = exp(get_scale_data(scale0, param, index + spacial_size)) * 4;
		float o0 = get_offset_data(offset0, param, index);
		float o1 = get_offset_data(offset0, param, index + spacial_size);

		float x1 = max(0., (id_w + o1 + 0.5) * 4 - s1 / 2);
		float y1 = max(0., (id_h + o0 + 0.5) * 4 - s0 / 2);
		float x2 = 0, y2 = 0;
		x1 = min(x1, (float)d_w);
		y1 = min(y1, (float)d_h);
		x2 = min(x1 + s1, (float)d_w);
		y2 = min(y1 + s0, (float)d_h);

		box_t *facebox_tmp = &face_box[face_cnt];
		facebox_tmp->x = x1 / d_w;
		facebox_tmp->y = y1 / d_h;
		facebox_tmp->w = (x2 - x1) / d_w;
		facebox_tmp->h = (y2 - y1) / d_h;
		facebox_tmp->score = get_heatmap_data(heatmap, param, index);
		facebox_tmp->invalid = 0;

		float box_w = x2 - x1;
		float box_h = y2 - y1;

		for (int j = 0; j < 5; j++) {
			facebox_tmp->landmarks[2 * j] = (x1 + get_landmarks_data(landmarks, param, (2 * j + 1) * spacial_size + index) * s1) / (float)d_w;
			facebox_tmp->landmarks[2 * j + 1] = (y1 + get_landmarks_data(landmarks, param, (2 * j) * spacial_size + index) * s0) / (float)d_h;
		}

		face_cnt++;
	}

	dprintf(LOG_INF, "[nn postprocess]decode done.\r\n");

	// dump facebox
	facebox_dump(LOG_INF);

	// NMS
	do_nms(1, face_cnt, nms_thres, face_box, p_face_box, IOU);

	// fill result
	centerface_res.fd_res.obj_num  = 0;
	for (int i = 0; i < face_cnt; i++) {
		box_t *b = &face_box[i];
		dprintf(LOG_INF, "p %2.6f, invalid %d\n\r", b->score, b->invalid);
		if (b->invalid == 0) {
			centerface_res.fd_res.result[centerface_res.fd_res.obj_num * 6 + 0] = 0;  // face only
			centerface_res.fd_res.result[centerface_res.fd_res.obj_num * 6 + 1] = b->score;
			centerface_res.fd_res.result[centerface_res.fd_res.obj_num * 6 + 2] = b->x;	// top_x
			centerface_res.fd_res.result[centerface_res.fd_res.obj_num * 6 + 3] = b->y;	// top_y
			centerface_res.fd_res.result[centerface_res.fd_res.obj_num * 6 + 4] = b->x + b->w; // bottom_x
			centerface_res.fd_res.result[centerface_res.fd_res.obj_num * 6 + 5] = b->y + b->h; // bottom_y

			for (int j = 0; j < 5; j++) {
				centerface_res.fd_res.landmark[centerface_res.fd_res.obj_num].pos[j].x = b->landmarks[2 * j];
				centerface_res.fd_res.landmark[centerface_res.fd_res.obj_num].pos[j].y = b->landmarks[2 * j + 1];
			}

			centerface_res.fd_res.obj_num++;
		}
	}

centerface_cleanup:

	return &centerface_res;
}

void centerface_set_confidence_thresh(void *confidence_thresh)
{
	score_thres = *(float *)confidence_thresh;
	printf("set centerface score thresh to %f\n\r", *(float *)confidence_thresh);
}

void centerface_set_nms_thresh(void *nms_thresh)
{
	nms_thres = *(float *)nms_thresh;
	printf("set centerface NMS thresh to %f\n\r", *(float *)nms_thresh);
}

nnmodel_t centerface_fwfs = {
	.nb 			= centerface_get_network_filename,
	.preprocess 	= centerface_preprocess,
	.postprocess 	= centerface_postprocess,
	.model_src 		= MODEL_SRC_FILE,
	.set_confidence_thresh  = centerface_set_confidence_thresh,
	.set_nms_thresh     = centerface_set_nms_thresh,

	.name = "CENTERFACE"
};