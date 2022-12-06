#include "nn_facedet_drv.h"
#include "module_video.h"
#include "module_vipnn.h"

#include "input_image_640x360x3.h"
#include "model_yolov3t.h"
#include "osd_render.h"
#include "model_scrfd.h"


#define DEBUG           0

#if DEBUG
#define CAMDBG(fmt, args...) \
    do {printf("\r\nFunc-[%s]@Line-%d: \r\n" fmt "\r\n", __func__, __LINE__, ## args); } while (0);
#else
#define CAMDBG(fmt, args...)
#endif

#define RTSP_HEIGHT 1920
#define RTSP_WIDTH 1080
#define RTSP_CHANNEL 0

// NN model config //
#define NN_CHANNEL 4
#define NN_RESOLUTION VIDEO_VGA //don't care for NN
#define NN_FPS 10
#define NN_GOP NN_FPS
#define NN_BPS 1024*1024 //don't care for NN
#define NN_TYPE VIDEO_RGB

// SCRFD
#define NN_MODEL_OBJ   scrfd_fwfs
#define NN_WIDTH    576//640
#define NN_HEIGHT   320//640

static const char *tag[1] = {"face"};

#define LIMIT(x, lower, upper) if(x<lower) x=lower; else if(x>upper) x=upper;

static nn_data_param_t roi_nn = {
	.img = {
		.width = NN_WIDTH,
		.height = NN_HEIGHT,
		.rgb = 0, // set to 1 if want RGB->BGR or BGR->RGB
		.roi = {
			.xmin = 0,
			.ymin = 0,
			.xmax = NN_WIDTH,
			.ymax = NN_HEIGHT,
		}
	}
};

static void nn_set_object(void *p, void *img_param)
{
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
				snprintf(text_str, sizeof(text_str), "%s %d", tag[class_id], (int)(face_res->result[6 * i + 1 ] * 100));
				canvas_set_text(RTSP_CHANNEL, 0, xmin, ymin - 32, text_str, COLOR_CYAN);

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

mm_context_t* nnFacedetInit(void) {
    return mm_module_open(&vipnn_module);
}

// setup NN model
void nnSetFacedetModel(void *p) {
    vipnn_control(p, CMD_VIPNN_SET_MODEL, (int)&NN_MODEL_OBJ);
}

// setup NN input parameters
void nnSetFacedetInputParam(void *p) {
    vipnn_control(p, CMD_VIPNN_SET_IN_PARAMS, (int)&roi_nn);
}

// setup NN object
void nnSetFacedetDisppost(void *p) {
    vipnn_control(p, CMD_VIPNN_SET_DISPPOST, (int)nn_set_object);
}

void nnFacedetSetApply(void *p) {
    vipnn_control(p, CMD_VIPNN_APPLY, 0);
}
