#include "canvas.h"
#include "hal_osd_util.h"

void draw_point_on_bitmap(uint8_t *bitmap, int width, int height, canvas_pt_t *pt, canvas_color_t *color)
{
	uint8_t draw_color = (color->argb.a >> 6) * 64 + (color->argb.b >> 6) * 16 + (color->argb.g >> 6) * 4 + (color->argb.r >> 6);
	int pt_w = pt->pt_width;
	int pt_xmin = pt->x - pt_w / 2 < 0 ? 0 : pt->x - pt_w / 2;
	int pt_xmax = pt->x + pt_w / 2 < width ? pt->x + pt_w / 2 : width;
	int pt_ymin = pt->y - pt_w / 2 < 0 ? 0 : pt->y - pt_w / 2;
	int pt_ymax = pt->y + pt_w / 2 < height ? pt->y + pt_w / 2 : height;
	for (int j = pt_ymin; j < pt_ymax; j++) {
		for (int k = pt_xmin; k < pt_xmax; k++) {
			bitmap[j * width + k] = draw_color;
		}
	}
}

void switch_point(canvas_pt_t *pt1, canvas_pt_t *pt2)
{
	canvas_pt_t pt = *pt1;
	*pt1 = *pt2;
	*pt2 = pt;
}

void draw_line_on_bitmap(uint8_t *bitmap, int width, int height, canvas_pt_t *pt1, canvas_pt_t *pt2, canvas_color_t *color)
{
	canvas_pt_t pt = *pt1;
	uint8_t draw_color = (color->argb.a >> 6) * 64 + (color->argb.b >> 6) * 16 + (color->argb.g >> 6) * 4 + (color->argb.r >> 6);

	if (pt2->y == pt1->y) { //horizontal line
		if (pt1->x > pt2->x) {
			switch_point(pt1, pt2);
		}
		for (int i = pt1->x; i < pt2->x; i++) {
			pt.y = pt1->y;
			pt.x = i;
			int pt_ymin = pt.y - pt.pt_width / 2 < 0 ? 0 : pt.y - pt.pt_width / 2;
			int pt_ymax = pt.y + pt.pt_width / 2 < height ? pt.y + pt.pt_width / 2 : height;
			for (int j = pt_ymin; j < pt_ymax; j++) {
				bitmap[j * width + i] = draw_color;
			}
		}
	} else if (pt1->x == pt2->x) { //vertical line
		if (pt1->y > pt2->y) {
			switch_point(pt1, pt2);
		}
		for (int i = pt1->y; i < pt2->y; i++) {
			pt.x = pt1->x;
			pt.y = i;
			int pt_xmin = pt.x - pt.pt_width / 2 < 0 ? 0 : pt.x - pt.pt_width / 2;
			int pt_xmax = pt.x + pt.pt_width / 2 < height ? pt.x + pt.pt_width / 2 : width;
			for (int j = pt_xmin; j < pt_xmax; j++) {
				bitmap[i * width + j] = draw_color;
			}
		}
	} else if (abs(pt2->y - pt1->y) > abs(pt2->x - pt1->x)) { //y step lager tha x step
		if (pt1->y > pt2->y) {
			switch_point(pt1, pt2);
		}
		for (int i = pt1->y; i < pt2->y; i++) {
			pt.x = (pt2->x - pt1->x) * (i - pt1->y) / (pt2->y - pt1->y) + pt1->x;
			pt.y = i;
			int pt_xmin = pt.x - pt.pt_width / 2 < 0 ? 0 : pt.x - pt.pt_width / 2;
			int pt_xmax = pt.x + pt.pt_width / 2 < height ? pt.x + pt.pt_width / 2 : width;
			for (int j = pt_xmin; j < pt_xmax; j++) {
				bitmap[i * width + j] = draw_color;
			}
		}
	} else { //x step lager tha y step
		if (pt1->x > pt2->x) {
			switch_point(pt1, pt2);
		}
		for (int i = pt1->x; i < pt2->x; i++) {
			pt.x = i;
			pt.y = (pt2->y - pt1->y) * (i - pt1->x) / (pt2->x - pt1->x) + pt1->y;
			int pt_ymin = pt.y - pt.pt_width / 2 < 0 ? 0 : pt.y - pt.pt_width / 2;
			int pt_ymax = pt.y + pt.pt_width / 2 < height ? pt.y + pt.pt_width / 2 : height;
			for (int j = pt_ymin; j < pt_ymax; j++) {
				bitmap[j * width + i] = draw_color;
			}
		}
	}

}

void draw_rect_on_bitmap(uint8_t *bitmap, int width, int height, canvas_rect_t *rect, canvas_color_t *color)
{
	uint8_t draw_color = (color->argb.a >> 6) * 64 + (color->argb.b >> 6) * 16 + (color->argb.g >> 6) * 4 + (color->argb.r >> 6);

	int start_x = rect->start_point.x < 0 ? 0 : rect->start_point.x;
	int start_y = rect->start_point.y < 0 ? 0 : rect->start_point.y;
	int end_x = rect->end_point.x > width ? width : rect->end_point.x;
	int end_y = rect->end_point.y > height ? height : rect->end_point.y;

	int line_width = rect->line_width;

	if (line_width > 0) {
		if (line_width * 2 > end_x - start_x) {
			line_width = (end_x - start_x) / 2;
		}
		if (line_width * 2 > end_y - start_y) {
			line_width = (end_y - start_y) / 2;
		}

		//top
		for (int i = start_x; i < end_x; i++) {
			for (int j = start_y; j < start_y + line_width; j++) {
				*(bitmap + i + j * width) = draw_color;
			}
		}
		//buttom
		for (int i = start_x; i < end_x; i++) {
			for (int j = end_y - line_width; j < end_y; j++) {
				*(bitmap + i + j * width) = draw_color;
			}
		}
		//left
		for (int i = start_y; i < end_y; i++) {
			for (int j = start_x; j < start_x + line_width; j++) {
				*(bitmap + j + i * width) = draw_color;
			}
		}
		//right
		for (int i = start_y; i < end_y; i++) {
			for (int j = end_x - line_width; j < end_x; j++) {
				*(bitmap + j + i * width) = draw_color;
			}
		}
	} else {
		for (int i = start_y; i < end_y; i++) {
			memset(&bitmap[i * width + start_x], draw_color, end_x - start_x);
		}
	}

}

void draw_text_on_bitmap(uint8_t *bitmap, int width, int height, int font_idx, canvas_text_t *text, canvas_color_t *color)
{
	uint8_t txt_color = (color->argb.a >> 6) * 64 + (color->argb.b >> 6) * 16 + (color->argb.g >> 6) * 4 + (color->argb.r >> 6);
	uint8_t txt_bnd_color = (color->argb.a >> 6) * 64 + (color->argb.b >> 7) * 16 + (color->argb.g >> 7) * 4 + (color->argb.r >> 7);

	BITMAP_S text_bmp;
	text_bmp.pData = malloc(((TXT_STR_MAX_LEN * CHAR_MAX_W + 7) / 8) * 8 * CHAR_MAX_H);
	if (text_bmp.pData) {
		//gen text bitmap
		osd_text2bmp(text->text_str, &text_bmp, font_idx, font_idx);
		int txt_w = text_bmp.u32Width;
		int txt_h = text_bmp.u32Height;
		uint8_t *txt_buf = (uint8_t *)text_bmp.pData;
		int offset_w = text->start_point.x;// pt1->x < 0 ? 0 : pt1->x;
		int offset_h = text->start_point.y;//pt1->y < 0 ? 0 : pt1->y;

		for (int i = 0; i < txt_h; i++) {
			for (int j = 0; j < txt_w; j++) {
				//if ((i + offset_h) < height && j + offset_w < width && (i + offset_h) >= 0 && j + offset_w >= 0) {
				if (((i + offset_h) < height) && ((j + offset_w) < width) && ((i + offset_h) >= 0) && ((j + offset_w) >= 0)) {
					if ((txt_buf[i * txt_w + j] & 0x3F) == 0x3F) { //turn white to collor
						bitmap[(i + offset_h) * width + (j + offset_w)] = (txt_buf[i * txt_w + j] & 0xC0) | txt_color;
					} else if ((txt_buf[i * txt_w + j] & 0x3F) == 0x00 && (txt_buf[i * txt_w + j] & 0xC0) != 0x00) { //turn black to bounder collor
						bitmap[(i + offset_h) * width + (j + offset_w)] = (txt_buf[i * txt_w + j] & 0xC0) | txt_bnd_color;
					} else if (txt_buf[i * txt_w + j] != 0) {
						bitmap[(i + offset_h) * width + (j + offset_w)] = txt_buf[i * txt_w + j];
					}
				}
			}
		}

		free(text_bmp.pData);
	}



}
