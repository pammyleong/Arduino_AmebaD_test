//---------------------------------------------------------
// Face Recognition - NK
//---------------------------------------------------------
#include <math.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include "img_process/img_process.h"
#include "mmf2_module.h"
#include "module_vipnn.h"
#include "fwfs.h"
#include "hal_cache.h"
#include "pre_process.h"
#include "face_alignment/face_alignment.h"

#define DBG_LEVEL	LOG_MSG

#define LOG_OFF		4
#define LOG_ERR		3
#define LOG_MSG		2
#define LOG_INF		1
#define LOG_ALL		0

#define dprintf(level, ...) if(level >= DBG_LEVEL) printf(__VA_ARGS__)


typedef struct data_format_s {
	nn_tensor_format_t *format;
	nn_tensor_dim_t *dim;
} data_format_t;

static float u8_to_f(uint8_t val, uint8_t zero_p, float scale)
{
	return  scale * ((float)val - (float)zero_p);
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
	switch (fmt->type) {
	case VIP_BUFFER_QUANTIZE_DYNAMIC_FIXED_POINT:
		// s16
		return s16_to_f(*(int16_t *)val, fmt->fix_point_pos);
	case VIP_BUFFER_QUANTIZE_TF_ASYMM:
		// u8
		return u8_to_f(*(uint8_t *)val, fmt->zero_point, fmt->scale);
	default:
		// bf16
		return bf16_to_f(*(__fp16 *)val);
	}
}

void *mbfacenet_nk_get_network_filename(void)
{
	return (void *)"NN_MDL/mobilefacenet_nk_int16.nb";	// fix name for NN model binary
}

//--------PRE PROCESS-------------------------------------------

static int16_t f_to_s16(float val, int q)
{
	return (int16_t)(val * (1 << q));
}

static lm_t ref = {{
		{38.29459953, 51.69630051 },
		{73.53179932, 51.50139999 },
		{56.02519989, 71.73660278 },
		{41.54930115, 92.3655014  },
		{70.72990036, 92.20410156 },
	}
};

static int face_in_width, face_in_height;
int mbfacenet_nk_preprocess(void *data_in, nn_data_param_t *data_param, void *tensor_in, nn_tensor_param_t *tensor_param)
{
	void **tensor = (void **)tensor_in;
	rect_t *roi = (rect_t *)&data_param->img.roi;

	landmarki_t *landmark = &data_param->img.landmark;

	img_t img_in, img_rotate, img_out;

	img_in.width  = data_param->img.width;
	img_in.height = data_param->img.height;
	img_out.width  = tensor_param->dim[0].size[0];
	img_out.height = tensor_param->dim[0].size[1];
	face_in_width  = tensor_param->dim[0].size[0];
	face_in_height = tensor_param->dim[0].size[1];

	img_in.data = (uint8_t *)data_in;
	img_out.data = (uint8_t *)tensor[0];
	dprintf(LOG_INF, "[nn preprocess]src %d %d, dst %d %d\n\r", img_in.width, img_in.height, img_out.width, img_out.height);

	// resize src ROI area to dst
	if (landmark->pos[0].x == 0 && landmark->pos[0].y == 0) {
		if (img_in.width == img_out.width && img_in.height == img_out.height) {
			dprintf(LOG_INF, "[nn preprocess]same size, just copy!\n\r");
			//memcpy(img_out.data, img_in.data, img_out.width * img_out.height * 3);
			img_dma_copy(img_out.data, img_in.data, img_out.width * img_out.height * 3);
		} else {
			dprintf(LOG_INF, "[nn preprocess]resize to NN input size!\n\r");
			img_resize_planar(&img_in, roi, &img_out);
		}
	} else {
		lm_t lm;
		for (int i = 0; i < 5; i++) {
			lm.pos[i].x = (float)landmark->pos[i].x;
			lm.pos[i].y = (float)landmark->pos[i].y;
		}
		face_alignment(lm, ref, img_in.data, img_in.width, img_in.height, img_out.data, img_out.width, img_out.height);
	}

// NK pre-process
#if 1
	float mean[3] = {0.485, 0.456, 0.406};
	float std[3]  = {0.229, 0.224, 0.225};
	data_format_t fmt;
	fmt.format = &tensor_param->format[0];
	fmt.dim = &tensor_param->dim[0];
	float_t tmp;
	uint32_t data_in_size = img_out.width * img_out.height * 3 * sizeof(int16_t);
	int16_t *mfnin_int16 = (int16_t *) malloc(data_in_size);
	for (int i = 0; i < img_out.width * img_out.height; i++) {
		tmp = ((float) img_out.data[i]) / 255.0;
		tmp -= mean[0];
		tmp /= std[0];
		mfnin_int16[i] = f_to_s16(tmp, fmt.format->fix_point_pos);
		tmp = ((float) img_out.data[i + img_out.width * img_out.height]) / 255.0;
		tmp -= mean[1];
		tmp /= std[1];
		mfnin_int16[i + img_out.width * img_out.height] = f_to_s16(tmp, fmt.format->fix_point_pos);
		tmp = ((float) img_out.data[i + img_out.width * img_out.height * 2]) / 255.0;
		tmp -= mean[2];
		tmp /= std[2];
		mfnin_int16[i + img_out.width * img_out.height * 2] = f_to_s16(tmp, fmt.format->fix_point_pos);
	}
	//memcpy(img_out.data, mfnin_int16, data_in_size);
	img_dma_copy(img_out.data, mfnin_int16, data_in_size);
	if (mfnin_int16) {
		free(mfnin_int16);
	}
#endif

	dcache_clean_by_addr((uint32_t *)img_out.data, img_out.width * img_out.height * 3);


	return 0;
}

static int get_element_size(data_format_t *fmt)
{
	int es = 2;	// bf16, int16
	if (fmt->format->type == VIP_BUFFER_QUANTIZE_TF_ASYMM) {
		es = 1; // u8
	}
	return es;
}

static float inner_product(float *a, float *b, int len)
{
	float sum = 0;
	for (int i = 0; i < len; i++) {
		sum += a[i] * b[i];
	}
	return sum;
}

static void face_feature_dump(int log_level, float *pfeature, int num)
{
	if (log_level >= DBG_LEVEL) {
		printf("--------------------------------------------------\r\n");
		printf("face feature dump\r\n");
		printf("--------------------------------------------------\r\n");
		for (int i = 0; i < num; i++) {
			printf("%6.2f ", pfeature[i]);
			if ((i + 1) % 16 == 0) {
				printf("\r\n");
			}
		}
		printf("--------------------------------------------------\r\n");
	}
}

//--------POST PROCESS-------------------------------------------

static vipnn_res_t mbfacenet_nk_res;
void *mbfacenet_nk_postprocess(void *tensor_out, nn_tensor_param_t *param)
{
	void **tensor = (void **)tensor_out;

	// decode
	uint8_t *tt0 = (uint8_t *)tensor[0];
	data_format_t fmt;
	fmt.format = &param->format[0];
	fmt.dim = &param->dim[0];
	int face_feature_dim = fmt.dim->size[0];
	dprintf(LOG_INF, "face feature dim: %d\r\n", face_feature_dim);

	float face_feature[face_feature_dim * sizeof(float)];
	int es = get_element_size(&fmt);
	for (int i = 0; i < face_feature_dim; i++) {
		face_feature[i] = q2f(tt0 + i * es, fmt.format);
	}

	// normalize
	float l2_norm = sqrtf(inner_product(face_feature, face_feature, face_feature_dim));
	for (int i = 0; i < face_feature_dim; i++) {
		face_feature[i] = face_feature[i] / l2_norm;
	}

	// dump result
	face_feature_dump(LOG_INF, face_feature, face_feature_dim);

	memcpy(mbfacenet_nk_res.frec_res.result, face_feature, face_feature_dim * sizeof(float));

	return &mbfacenet_nk_res;
}

nnmodel_t mbfacenet_nk_fwfs = {
	.nb 			= mbfacenet_nk_get_network_filename,
	.preprocess 	= mbfacenet_nk_preprocess,
	.postprocess 	= mbfacenet_nk_postprocess,
	.model_src 		= MODEL_SRC_FILE,

	.name = "MBFACENET_NK"
};