#include "md_drv.h"
#include "module_video.h"
#include "module_md.h"
#include "osd_render.h"
#include "md_api.h" //(include?)
#include "hal_video.h"
#include "base_type.h"
#include "video_drv.h"
#include "sensor.h"

#define MD_DRAW 1

//from "md_api.h"
#define MD_COL 16
#define MD_ROW 16

uint32_t RTSPWidthMD;
uint32_t RTSPHeightMD;
int RTSPChannelMD;
int i;

static md_param_t md_param = {
    .image_width = 0,
    .image_height = 0,
    .md_row = MD_ROW,
    .md_col = MD_COL,
};

// get settings from RTSP module
void MDOSDConfig(int ch, uint32_t width, uint32_t height) { 
    RTSPWidthMD = width;
    RTSPHeightMD = height;
    RTSPChannelMD = ch;

//	printf ("RTSP Width = %d\r\n", RTSPWidthMD);
//	printf ("RTSP Height = %d\r\n", RTSPHeightMD);
//	printf ("RTSP CH = %d\r\n", RTSPChannelMD);
}

static void md_process(void *md_result) {
	char *md_res = (char *) md_result;

	//draw md rect
	int motion = 0, j, k;
	int jmin = MD_ROW - 1, jmax = 0;
	int kmin = MD_COL - 1, kmax = 0;
	for (int j = 0; j < MD_ROW; j++) {
		for (int k = 0; k < MD_COL; k++) {
			printf("%d ", md_res[j * MD_COL + k]);
			if (md_res[j * MD_COL + k]) {
				motion = 1;
				if (j < jmin) {
					jmin = j;
				}
				if (k < kmin) {
					kmin = k;
				}
				if (j > jmax) {
					jmax = j;
				}
				if (k > kmax) {
					kmax = k;
				}
			}
		}
		printf("\r\n");
	}
	printf("\r\n\r\n");
	//draw md region
	canvas_clean_all(RTSPChannelMD, 0);
	if (motion) {
		int xmin = (int)(kmin * RTSPWidthMD / MD_COL) + 1;
		int ymin = (int)(jmin * RTSPHeightMD / MD_ROW) + 1;
		int xmax = (int)((kmax + 1) * RTSPWidthMD / MD_COL) - 1;
		int ymax = (int)((jmax + 1) * RTSPHeightMD / MD_ROW) - 1;
		canvas_set_rect(RTSPChannelMD, 0, xmin, ymin, xmax, ymax, 3, COLOR_GREEN);
	}
	canvas_update(RTSPChannelMD, 0);
}

mm_context_t *MDInit(void) {
    return mm_module_open(&md_module);
}

void setMDParams(void *p, int img_width, int img_height) {
    md_param.image_width = img_width;
    md_param.image_height = img_height;
	printf("Image width = %d\r\n", md_param.image_width);
	printf("Image height = %d\r\n", md_param.image_height);
    md_control(p, CMD_MD_SET_PARAMS, (int)&md_param);
}

void setMDThres(void *p) {
	motion_detect_threshold_t md_thr = {
    .Tbase = 2,
    .Tlum = 3
	};
    md_control(p, CMD_MD_SET_MD_THRESHOLD, (int)&md_thr);
}

void setMDMask(mm_context_t *p) {
	char md_mask [MD_COL * MD_ROW] = {0};
	for (i = 0; i < (MD_COL * MD_ROW); i++) {
		md_mask[i] = 1;
	}
	mm_module_ctrl(p, CMD_MD_SET_MD_MASK, (int)&md_mask);
}

void setMDDisppost(void *p) {
    md_control(p, CMD_MD_SET_DISPPOST, (int)md_process);
}

void setMDTrigBlock(void *p) {
    md_control(p, CMD_MD_SET_TRIG_BLK, 3); //md triggered when at least 3 motion block triggered
}

void MDDraw(void) {
    int ch_enable[3] = {1, 0, 0};
	int char_resize_w[3] = {16, 0, 0}, char_resize_h[3] = {32, 0, 0};
	int ch_width[3] = {RTSPWidthMD, 0, 0}, ch_height[3] = {RTSPHeightMD, 0, 0};
	osd_render_dev_init(ch_enable, char_resize_w, char_resize_h);
	osd_render_task_start(ch_enable, ch_width, ch_height);
}