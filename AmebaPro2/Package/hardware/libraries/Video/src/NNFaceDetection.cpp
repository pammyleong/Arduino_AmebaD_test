#include <Arduino.h>
#include "NNFaceDetection.h"

#ifdef __cplusplus
extern "C" {
#endif

#include "mmf2_module.h"
#include "module_vipnn.h"
#include "model_scrfd.h"
#include "roi_delta_qp/roi_delta_qp.h"
#include "osd_render.h"

extern int vipnn_control(void *p, int cmd, int arg);

#ifdef __cplusplus
}
#endif

#define DEBUG 0

#if DEBUG
#define CAMDBG(fmt, args...) \
    do {printf("\r\nFunc-[%s]@Line-%d: \r\n" fmt "\r\n", __func__, __LINE__, ## args); } while (0);
#else
#define CAMDBG(fmt, args...)
#endif

#define RTSP_CHANNEL 0
#define RTSP_HEIGHT 1080
#define RTSP_WIDTH 1920
#define LIMIT(x, lower, upper) if(x<lower) x=lower; else if(x>upper) x=upper;

void nnFaceDetectionCB(void *p, void *img_param) {
	int i = 0;
	facedetect_res_t *face_res = (facedetect_res_t *)p;
	nn_data_param_t *im = (nn_data_param_t *)img_param;

	if (!p || !img_param)	{
		return;
	}

	int im_h = RTSP_HEIGHT;
	int im_w = RTSP_WIDTH;

	//crop
	float ratio_w = (float)im_w / (float)im->img.width;
	float ratio_h = (float)im_h / (float)im->img.height;
	float ratio = ratio_h < ratio_w ? ratio_h : ratio_w;
	int roi_w = (int)((im->img.roi.xmax - im->img.roi.xmin) * ratio);
	int roi_h = (int)((im->img.roi.ymax - im->img.roi.ymin) * ratio);
	int roi_x = (int)(im->img.roi.xmin * ratio + (im_w - roi_w) / 2);
	int roi_y = (int)(im->img.roi.ymin * ratio + (im_h - roi_h) / 2);

	roi_delta_qp_set_param(RTSP_CHANNEL, 0, 0, RTSP_WIDTH, RTSP_HEIGHT, ROI_DELTA_QP_MAX);

	printf("object num = %d\r\n", face_res->obj_num);
	canvas_clean_all(RTSP_CHANNEL, 0);
	if (face_res->obj_num > 0) {
		for (i = 0; i < face_res->obj_num; i++) {
			int obj_class = (int)face_res->result[6 * i ];
			int class_id = obj_class;
			if (class_id != -1) {
				int xmin = (int)(face_res->result[6 * i + 2] * roi_w) + roi_x;
				int ymin = (int)(face_res->result[6 * i + 3] * roi_h) + roi_y;
				int xmax = (int)(face_res->result[6 * i + 4] * roi_w) + roi_x;
				int ymax = (int)(face_res->result[6 * i + 5] * roi_h) + roi_y;
				LIMIT(xmin, 0, im_w)
				LIMIT(xmax, 0, im_w)
				LIMIT(ymin, 0, im_h)
				LIMIT(ymax, 0, im_h)
				printf("%d,c%d:%d %d %d %d\n\r", i, class_id, xmin, ymin, xmax, ymax);
				canvas_set_rect(RTSP_CHANNEL, 0, xmin, ymin, xmax, ymax, 3, COLOR_WHITE);
				char text_str[20];
				snprintf(text_str, sizeof(text_str), "%s %d", "face", (int)(face_res->result[6 * i + 1 ] * 100));
				canvas_set_text(RTSP_CHANNEL, 0, xmin, ymin - 32, text_str, COLOR_CYAN);

				roi_delta_qp_set_param(RTSP_CHANNEL, xmin, ymin, (xmax - xmin), (ymax - ymin), ROI_DELTA_QP_DEFAULT);

				for (int j = 0; j < 5; j++) {
					int x = (int)(face_res->landmark[i].pos[j].x * roi_w) + roi_x;
					int y = (int)(face_res->landmark[i].pos[j].y * roi_h) + roi_y;
					canvas_set_point(RTSP_CHANNEL, 0, x, y, 8, COLOR_RED);
				}
			}
		}
	}
	canvas_update(RTSP_CHANNEL, 0);
}

void NNFaceDetection::configVideo(VideoSetting& config) {
    roi_nn.img.width = config._w;
    roi_nn.img.height = config._h;
    roi_nn.img.rgb = 0;
    roi_nn.img.roi.xmin = 0;
    roi_nn.img.roi.ymin = 0;
    roi_nn.img.roi.xmax = config._w;
    roi_nn.img.roi.ymax = config._h;
}

void NNFaceDetection::configFaceRecogCascadedMode(uint8_t enable) {
    cascaded_mode = enable;
}

void NNFaceDetection::begin(void) {
    if (_p_mmf_context == NULL) {
        _p_mmf_context = mm_module_open(&vipnn_module);
    }
    if (_p_mmf_context == NULL) {
        printf("NNFaceDetection init failed\r\n");
        return;
    }

    if((roi_nn.img.width == 0) || (roi_nn.img.height == 0)) {
        printf("ERROR: NNFaceDetection video not configured\r\n");
        return;
    }

    vipnn_control(_p_mmf_context->priv, CMD_VIPNN_SET_MODEL, (int)&scrfd_fwfs);
    vipnn_control(_p_mmf_context->priv, CMD_VIPNN_SET_IN_PARAMS, (int)&roi_nn);
    if (cascaded_mode) {
        mm_module_ctrl(_p_mmf_context, CMD_VIPNN_SET_OUTPUT, 1);
        mm_module_ctrl(_p_mmf_context, MM_CMD_SET_DATAGROUP, MM_GROUP_START);
        mm_module_ctrl(_p_mmf_context, MM_CMD_SET_QUEUE_LEN, 1);
        mm_module_ctrl(_p_mmf_context, MM_CMD_INIT_QUEUE_ITEMS, MMQI_FLAG_STATIC);
    } else {
        vipnn_control(_p_mmf_context->priv, CMD_VIPNN_SET_DISPPOST, (int)nnFaceDetectionCB);
    }
    vipnn_control(_p_mmf_context->priv, CMD_VIPNN_APPLY, 0);
}

void NNFaceDetection::end(void) {
    if (_p_mmf_context == NULL) {
        return;
    }
    vipnn_control(_p_mmf_context->priv, CMD_VIPNN_SET_DISPPOST, (int)NULL);
    if (mm_module_close(_p_mmf_context) == NULL) {
        _p_mmf_context = NULL;
    } else {
        CAMDBG("NNFaceDetection deinit failed\r\n");
    }
}

void NNFaceDetection::setResultCallback(void) {

}

void NNFaceDetection::getResult(void) {

}

