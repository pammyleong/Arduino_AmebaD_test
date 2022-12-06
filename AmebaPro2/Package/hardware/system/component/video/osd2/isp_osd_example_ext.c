#include <platform_stdlib.h>
#include <platform_opts.h>
#include <build_info.h>
#include "log_service.h"
#include "atcmd_isp.h"
#include "main.h"
#include "flash_api.h"
#include "hal_osd_util.h"
#include "osd_custom.h"
#include "osd_pict_custom.h"
#include "osd_api.h"
#include "isp_osd_example_ext.h"


static osd_text_info_st s_txt_info_time;
static osd_text_info_st s_txt_info_date;
static osd_text_info_st s_txt_info_string;
static char teststring[] = "RTK-AmebaPro2";

#define SCALE_BASE 100
int rescale(int value, int a, int b)
{
	return (value * a) / b;
}

extern void rts_osd_task(void *arg);
osd_pict_st posd2_pic_0, posd2_pic_1, posd2_pic_2;
void example_isp_osd(int idx, int ch_id, int txt_w, int txt_h, int scale)
{
	int ch = ch_id;
	rt_font_st font;
	printf("Text/Logo OSD Test\r\n");

	if (scale < 20 || scale > 200) {
		return;
	}
	txt_w = rescale(txt_w, scale, SCALE_BASE);
	txt_h = txt_w * 2;
	if (idx == 0) {

		printf("[osd] Heap available:%d\r\n", xPortGetFreeHeapSize());
		rts_osd_init(ch_id, txt_w, txt_h, (int)(8.0f * 3600));

		font.bg_enable		= OSD_TEXT_FONT_BG_ENABLE;
		font.bg_color		= OSD_TEXT_FONT_BG_COLOR;
		font.ch_color		= OSD_TEXT_FONT_CH_COLOR;
		font.block_alpha	= OSD_TEXT_FONT_BLOCK_ALPHA;
		font.h_gap			= OSD_TEXT_FONT_H_GAP;
		font.v_gap			= OSD_TEXT_FONT_V_GAP;
		font.date_fmt		= osd_date_fmt_9;
		font.time_fmt		= osd_time_fmt_24;



		posd2_pic_0.chn_id = ch;

		posd2_pic_1.chn_id = ch;

		posd2_pic_2.chn_id = ch;

		if (ch == 0) {
			s_txt_info_time.font = font;
			s_txt_info_time.blk_idx = 0;
			s_txt_info_time.chn_id = ch;
			s_txt_info_time.rotate = OSD_TEXT_ROTATE;
			s_txt_info_time.start_x = rescale(10 + 320 + 50, scale, SCALE_BASE);
			s_txt_info_time.start_y = rescale(10, scale, SCALE_BASE);


			s_txt_info_date.font = font;
			s_txt_info_date.blk_idx = 1;
			s_txt_info_date.chn_id = ch;
			s_txt_info_date.rotate = OSD_TEXT_ROTATE;
			s_txt_info_date.start_x = rescale(10, scale, SCALE_BASE);
			s_txt_info_date.start_y = rescale(10, scale, SCALE_BASE);


			s_txt_info_string.str = teststring;
			s_txt_info_string.font = font;
			s_txt_info_string.blk_idx = 5;
			s_txt_info_string.chn_id = ch;
			s_txt_info_string.rotate = RT_ROTATE_90L;
			s_txt_info_string.start_x = rescale(10, scale, SCALE_BASE);
			s_txt_info_string.start_y = rescale(10 + 100, scale, SCALE_BASE);

			posd2_pic_0.osd2.blk_idx = 2;
			posd2_pic_0.osd2.start_x = rescale(150, scale, SCALE_BASE);
			posd2_pic_0.osd2.start_y = rescale(200, scale, SCALE_BASE);
			posd2_pic_0.osd2.end_x = posd2_pic_0.osd2.start_x + PICT0_WIDTH;
			posd2_pic_0.osd2.end_y = posd2_pic_0.osd2.start_y + PICT0_HEIGHT;
			posd2_pic_0.osd2.blk_fmt = PICT0_BLK_FMT;
			posd2_pic_0.osd2.buf = PICT0_NAME;
			posd2_pic_0.osd2.len = PICT0_SIZE;


			posd2_pic_1.osd2.blk_idx = 3;
			posd2_pic_1.osd2.start_x = rescale(150 + 50 + PICT0_WIDTH, scale, SCALE_BASE);
			posd2_pic_1.osd2.start_y = rescale(200, scale, SCALE_BASE);
			posd2_pic_1.osd2.end_x = posd2_pic_1.osd2.start_x + PICT1_WIDTH;
			posd2_pic_1.osd2.end_y = posd2_pic_1.osd2.start_y + PICT1_HEIGHT;
			posd2_pic_1.osd2.blk_fmt = PICT1_BLK_FMT;
			posd2_pic_1.osd2.buf = PICT1_NAME;
			posd2_pic_1.osd2.len = PICT1_SIZE;


			posd2_pic_2.osd2.blk_idx = 4;
			posd2_pic_2.osd2.start_x = rescale(150 + 50 + 50 + PICT0_WIDTH + PICT1_WIDTH, scale, SCALE_BASE);
			posd2_pic_2.osd2.start_y = rescale(200, scale, SCALE_BASE);
			posd2_pic_2.osd2.end_x = posd2_pic_2.osd2.start_x + PICT2_WIDTH;
			posd2_pic_2.osd2.end_y = posd2_pic_2.osd2.start_y + PICT2_HEIGHT;
			posd2_pic_2.osd2.blk_fmt = PICT2_BLK_FMT;
			posd2_pic_2.osd2.color_1bpp = 0x000000FF;//0xAABBGGRR
			posd2_pic_2.osd2.buf = PICT2_NAME;
			posd2_pic_2.osd2.len = PICT2_SIZE;
		} else if (ch == 1) {
			s_txt_info_time.font = font;
			s_txt_info_time.blk_idx = 0;
			s_txt_info_time.chn_id = ch;
			s_txt_info_time.rotate = OSD_TEXT_ROTATE;
			s_txt_info_time.start_x = rescale(10, scale, SCALE_BASE);
			s_txt_info_time.start_y = rescale(10, scale, SCALE_BASE);


			s_txt_info_date.font = font;
			s_txt_info_date.blk_idx = 1;
			s_txt_info_date.chn_id = ch;
			s_txt_info_date.rotate = OSD_TEXT_ROTATE;
			s_txt_info_date.start_x = rescale(10 + 320 + 50, scale, SCALE_BASE);
			s_txt_info_date.start_y = rescale(10, scale, SCALE_BASE);


			s_txt_info_string.str = teststring;
			s_txt_info_string.font = font;
			s_txt_info_string.blk_idx = 5;
			s_txt_info_string.chn_id = ch;
			s_txt_info_string.rotate = RT_ROTATE_90R;
			s_txt_info_string.start_x = rescale(10, scale, SCALE_BASE);
			s_txt_info_string.start_y = rescale(10 + 100, scale, SCALE_BASE);

			posd2_pic_0.osd2.blk_idx = 2;
			posd2_pic_0.osd2.start_x = rescale(150 + 50 + 50 + PICT0_WIDTH + PICT1_WIDTH, scale, SCALE_BASE);
			posd2_pic_0.osd2.start_y = rescale(200, scale, SCALE_BASE);
			posd2_pic_0.osd2.end_x = posd2_pic_0.osd2.start_x + PICT0_WIDTH;
			posd2_pic_0.osd2.end_y = posd2_pic_0.osd2.start_y + PICT0_HEIGHT;
			posd2_pic_0.osd2.blk_fmt = PICT0_BLK_FMT;
			posd2_pic_0.osd2.buf = PICT0_NAME;
			posd2_pic_0.osd2.len = PICT0_SIZE;


			posd2_pic_1.osd2.blk_idx = 3;
			posd2_pic_1.osd2.start_x = rescale(150, scale, SCALE_BASE);
			posd2_pic_1.osd2.start_y = rescale(300, scale, SCALE_BASE);
			posd2_pic_1.osd2.end_x = posd2_pic_1.osd2.start_x + PICT1_WIDTH;
			posd2_pic_1.osd2.end_y = posd2_pic_1.osd2.start_y + PICT1_HEIGHT;
			posd2_pic_1.osd2.blk_fmt = PICT1_BLK_FMT;
			posd2_pic_1.osd2.buf = PICT1_NAME;
			posd2_pic_1.osd2.len = PICT1_SIZE;


			posd2_pic_2.osd2.blk_idx = 4;
			posd2_pic_2.osd2.start_x = rescale(150 + PICT0_WIDTH + 50, scale, SCALE_BASE);
			posd2_pic_2.osd2.start_y = rescale(400, scale, SCALE_BASE);
			posd2_pic_2.osd2.end_x = posd2_pic_2.osd2.start_x + PICT2_WIDTH;
			posd2_pic_2.osd2.end_y = posd2_pic_2.osd2.start_y + PICT2_HEIGHT;
			posd2_pic_2.osd2.blk_fmt = PICT2_BLK_FMT;
			posd2_pic_2.osd2.color_1bpp = 0x000000FF;//0xAABBGGRR
			posd2_pic_2.osd2.buf = PICT2_NAME;
			posd2_pic_2.osd2.len = PICT2_SIZE;
		} else if (ch == 2) {
			s_txt_info_time.font = font;
			s_txt_info_time.blk_idx = 0;
			s_txt_info_time.chn_id = ch;
			s_txt_info_time.rotate = OSD_TEXT_ROTATE;
			s_txt_info_time.start_x = rescale(10, scale, SCALE_BASE);
			s_txt_info_time.start_y = rescale(10, scale, SCALE_BASE);


			s_txt_info_date.font = font;
			s_txt_info_date.blk_idx = 1;
			s_txt_info_date.chn_id = ch;
			s_txt_info_date.rotate = OSD_TEXT_ROTATE;
			s_txt_info_date.start_x = rescale(10, scale, SCALE_BASE);
			s_txt_info_date.start_y = rescale(10 + 70, scale, SCALE_BASE);


			s_txt_info_string.str = teststring;
			s_txt_info_string.font = font;
			s_txt_info_string.blk_idx = 5;
			s_txt_info_string.chn_id = ch;
			s_txt_info_string.rotate = RT_ROTATE_0;
			s_txt_info_string.start_x = rescale(10 + 320 + 50, scale, SCALE_BASE);
			s_txt_info_string.start_y = rescale(10, scale, SCALE_BASE);

			posd2_pic_0.osd2.blk_idx = 2;
			posd2_pic_0.osd2.start_x = rescale(150 + 50 + PICT0_WIDTH, scale, SCALE_BASE);
			posd2_pic_0.osd2.start_y = rescale(200, scale, SCALE_BASE);
			posd2_pic_0.osd2.end_x = posd2_pic_0.osd2.start_x + PICT0_WIDTH;
			posd2_pic_0.osd2.end_y = posd2_pic_0.osd2.start_y + PICT0_HEIGHT;
			posd2_pic_0.osd2.blk_fmt = PICT0_BLK_FMT;
			posd2_pic_0.osd2.buf = PICT0_NAME;
			posd2_pic_0.osd2.len = PICT0_SIZE;


			posd2_pic_1.osd2.blk_idx = 3;
			posd2_pic_1.osd2.start_x = rescale(150 + 50 + 50 + PICT0_WIDTH + PICT1_WIDTH, scale, SCALE_BASE);
			posd2_pic_1.osd2.start_y = rescale(350, scale, SCALE_BASE);
			posd2_pic_1.osd2.end_x = posd2_pic_1.osd2.start_x + PICT1_WIDTH;
			posd2_pic_1.osd2.end_y = posd2_pic_1.osd2.start_y + PICT1_HEIGHT;
			posd2_pic_1.osd2.blk_fmt = PICT1_BLK_FMT;
			posd2_pic_1.osd2.buf = PICT1_NAME;
			posd2_pic_1.osd2.len = PICT1_SIZE;


			posd2_pic_2.osd2.blk_idx = 4;
			posd2_pic_2.osd2.start_x = rescale(150, scale, SCALE_BASE);
			posd2_pic_2.osd2.start_y = rescale(450, scale, SCALE_BASE);
			posd2_pic_2.osd2.end_x = posd2_pic_2.osd2.start_x + PICT2_WIDTH;
			posd2_pic_2.osd2.end_y = posd2_pic_2.osd2.start_y + PICT2_HEIGHT;
			posd2_pic_2.osd2.blk_fmt = PICT2_BLK_FMT;
			posd2_pic_2.osd2.color_1bpp = 0x000000FF;//0xAABBGGRR
			posd2_pic_2.osd2.buf = PICT2_NAME;
			posd2_pic_2.osd2.len = PICT2_SIZE;
		}

		rts_osd_set_info(rts_osd2_type_date, &s_txt_info_date);
		rts_osd_set_info(rts_osd2_type_time, &s_txt_info_time);
		rts_osd_set_info(rts_osd2_type_pict, &posd2_pic_0);
		rts_osd_set_info(rts_osd2_type_pict, &posd2_pic_1);
		rts_osd_set_info(rts_osd2_type_pict, &posd2_pic_2);
		rts_osd_set_info(rts_osd2_type_text, &s_txt_info_string);

		printf("[osd] Heap available:%d\r\n", xPortGetFreeHeapSize());

		if (xTaskCreate(rts_osd_task, "OSD", 10 * 1024, NULL, tskIDLE_PRIORITY + 1, NULL) != pdPASS) {
			printf("\n\r%s xTaskCreate failed", __FUNCTION__);
		}
	}
}