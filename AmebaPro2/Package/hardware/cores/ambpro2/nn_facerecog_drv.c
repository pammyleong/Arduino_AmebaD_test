#include "nn_facerecog_drv.h"
#include "module_video.h"
#include "module_vipnn.h"
#include "module_facerecog.h"
#include "avcodec.h"

#include "model_mobilefacenet.h"
#include "model_scrfd.h"

#include "osd_render.h"

#define DEBUG           0

#if DEBUG
#define CAMDBG(fmt, args...) \
    do {printf("\r\nFunc-[%s]@Line-%d: \r\n" fmt "\r\n", __func__, __LINE__, ## args); } while (0);
#else
#define CAMDBG(fmt, args...)
#endif

uint32_t RTSPWidth4FR = 0;
uint32_t RTSPHeight4FR = 0;
int RTSPChannel4FR = 0;

// SCRFD
#define NN_MODEL_OBJ    scrfd_fwfs
#define NN_MODEL_OBJ2   mbfacenet_fwfs

#define NN_WIDTH    576//640
#define NN_HEIGHT   320//640

#define LIMIT(x, lower, upper) if(x<lower) x=lower; else if(x>upper) x=upper;

void getRTSPFR (int ch, uint32_t width, uint32_t height) { 
    RTSPWidth4FR = width;
    RTSPHeight4FR = height;
    RTSPChannel4FR = ch;
}

TimerHandle_t osd_cleanup_timer = NULL;
void osd_cleanup_callback(TimerHandle_t xTimer)
{
	(void)xTimer;
	canvas_clean_all(RTSPChannel4FR, 0);
	canvas_update(RTSPChannel4FR, 0);
}

// callback function to to be called to draw rect
static void nn_set_object_FR(void *p, void *img_param) {
	int i = 0;
	frc_draw_t *fdraw = (frc_draw_t *)p;

	if (!p)	{
		return;
	}

	int im_h = RTSPHeight4FR;
	int im_w = RTSPWidth4FR;

	printf("object num = %d\r\n", fdraw->obj_cnt);
	canvas_clean_all(RTSPChannel4FR, 0);
	if (fdraw->obj_cnt > 0) {
		for (i = 0; i < fdraw->obj_cnt; i++) {
			nn_data_param_t *param = fdraw->img_param[i];
			int x_offset = 0, y_offset = 0;
			float ratio;
			if ((float)im_w / (float)im_h > (float)param->img.width / (float)param->img.height) {
				ratio = (float)im_h / (float)param->img.height;
				x_offset = (im_w - (float)param->img.width * ratio) / 2;
			} else {
				ratio = (float)im_w / (float)param->img.width;
				y_offset = (im_h - (float)param->img.height * ratio) / 2;
			}

			int xmin = (int)(param->img.roi.xmin * ratio) + x_offset;
			int ymin = (int)(param->img.roi.ymin * ratio) + y_offset;
			int xmax = (int)(param->img.roi.xmax * ratio) + x_offset;
			int ymax = (int)(param->img.roi.ymax * ratio) + y_offset;
			LIMIT(xmin, 0, im_w)
			LIMIT(xmax, 0, im_w)
			LIMIT(ymin, 0, im_h)
			LIMIT(ymax, 0, im_h)
			//printf("%d,c%s:%d %d %d %d\n\r", i, fdraw->obj_name[i], xmin, ymin, xmax, ymax);

			if (!strcmp(fdraw->obj_name[i], "unknown")) {
				canvas_set_rect(RTSPChannel4FR, 0, xmin, ymin, xmax, ymax, 3, COLOR_RED);
				canvas_set_text(RTSPChannel4FR, 0, xmin, ymin - 32, fdraw->obj_name[i], COLOR_RED);
			} else {
				canvas_set_rect(RTSPChannel4FR, 0, xmin, ymin, xmax, ymax, 3, COLOR_GREEN);
				canvas_set_text(RTSPChannel4FR, 0, xmin, ymin - 32, fdraw->obj_name[i], COLOR_GREEN);
			}
		}
		if (osd_cleanup_timer) {
			xTimerReset(osd_cleanup_timer, 10);
		}
	}
	canvas_update(RTSPChannel4FR, 0);
}

mm_context_t* nnFaceRecogInit(void) {
    return mm_module_open(&facerecog_module);
}

// set face recog threshold
void nnFaceRecogSetThres(void *p) {
    vipnn_control(p, CMD_FRC_SET_THRES100, 99);
}

// OSD Draw
void nnFaceRecogOSDDraw(void *p) {
    vipnn_control(p,  CMD_FRC_SET_OSD_DRAW, (int)nn_set_object_FR);
}

void OSDBeginFR(void) {
    int ch_enable[3] = {1, 0, 0};
    int char_resize_w[3] = {16, 0, 0}, char_resize_h[3] = {32, 0, 0};
    int ch_width[3] = {RTSPWidth4FR, 0, 0}, ch_height[3] = {RTSPHeight4FR, 0, 0};

    osd_render_dev_init(ch_enable, char_resize_w, char_resize_h);
    osd_render_task_start(ch_enable, ch_width, ch_height);
}
