#include "nn_facerecog_drv.h"
#include "module_video.h"
#include "module_vipnn.h"

#include "osd_render.h"
#include "module_facerecog.h"
#include "model_mobilefacenet.h"
#include "model_scrfd.h"
#include "avcodec.h"

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

#define NN_CHANNEL 4
#define NN_RESOLUTION VIDEO_VGA //don't care for NN
#define NN_FPS 10
#define NN_GOP NN_FPS
#define NN_BPS 1024*1024 //don't care for NN
#define NN_TYPE VIDEO_RGB

#define NN_MODEL_OBJ   	scrfd_fwfs
#define NN_MODEL2_OBJ   mbfacenet_fwfs
#define NN_WIDTH	576
#define NN_HEIGHT	320

#define LIMIT(x, lower, upper) if(x<lower) x=lower; else if(x>upper) x=upper;

TimerHandle_t osd_cleanup_timer = NULL;
void osd_cleanup_callback(TimerHandle_t xTimer)
{
	(void)xTimer;
	canvas_clean_all(RTSP_CHANNEL, 0);
	canvas_update(RTSP_CHANNEL, 0);
}

static void nn_set_object(void *p, void *img_param)
{
	int i = 0;
	frc_draw_t *fdraw = (frc_draw_t *)p;

	if (!p)	{
		return;
	}

	int im_h = RTSP_HEIGHT;
	int im_w = RTSP_WIDTH;

	printf("object num = %d\r\n", fdraw->obj_cnt);
	canvas_clean_all(RTSP_CHANNEL, 0);
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
				canvas_set_rect(RTSP_CHANNEL, 0, xmin, ymin, xmax, ymax, 3, COLOR_RED);
				canvas_set_text(RTSP_CHANNEL, 0, xmin, ymin - 32, fdraw->obj_name[i], COLOR_RED);
			} else {
				canvas_set_rect(RTSP_CHANNEL, 0, xmin, ymin, xmax, ymax, 3, COLOR_GREEN);
				canvas_set_text(RTSP_CHANNEL, 0, xmin, ymin - 32, fdraw->obj_name[i], COLOR_GREEN);
			}
		}
		if (osd_cleanup_timer) {
			xTimerReset(osd_cleanup_timer, 10);
		}
	}
	canvas_update(RTSP_CHANNEL, 0);
}

void nnFacerecogSetThreshold(void *p) {
    vipnn_control(p, CMD_FRC_SET_THRES100, 99);
}

void nnFacerecogSetOSDDraw(void *p) {
    vipnn_control(p, CMD_FRC_SET_OSD_DRAW, (int)nn_set_object);
}

