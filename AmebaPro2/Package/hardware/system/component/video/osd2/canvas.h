﻿#ifndef CANVAS_H_
#define CANVAS_H_

#include <stdio.h>

#define TXT_STR_MAX_LEN 20
#define CHAR_MAX_W 36
#define CHAR_MAX_H 72

typedef struct argb_s {
	uint8_t a, r, g, b;
} argb_t;

typedef union {
	uint32_t argb_u32;	// u32 [a, b, g, r]
	argb_t argb;
} canvas_color_t;

#define ARGB(a, r, g, b) ((((b)&0xff) << 24) | (((g)&0xff) << 16) | (((r)&0xff) << 8) | ((a)&0xff))

#define COLOR_RED 		ARGB(0xff,0xff,0x00,0x00)
#define COLOR_BLUE 		ARGB(0xff,0x00,0x00,0xff)
#define COLOR_GREEN 	ARGB(0xff,0x00,0xff,0x00)
#define COLOR_PURPLE 	ARGB(0xff,0xff,0x00,0xff)
#define COLOR_YELLOW 	ARGB(0xff,0xff,0xff,0x00)
#define COLOR_CYAN      ARGB(0xff,0x00,0xff,0xff)
#define COLOR_WHITE 	ARGB(0xff,0xff,0xff,0xff)
#define COLOR_BLACK 	ARGB(0xff,0x00,0x00,0x00)
#define COLOR_GRAY 		ARGB(0xff,0x7f,0x7f,0x7f)
#define COLOR_HORANGE	ARGB(0xff,0xf3,0x70,0x21)
#define COLOR_TBLUE		ARGB(0xff,0x0a,0xba,0xb5)
#define COLOR_BGREEN	ARGB(0xff,0x00,0x92,0x5b)
#define COLOR_CRED		ARGB(0xff,0xfe,0x00,0x1a)

typedef struct canvas_pt_s {
	unsigned char pt_width;
	int x, y;
} canvas_pt_t;

typedef struct canvas_text_s {
	char text_str[TXT_STR_MAX_LEN];
	int left;
	int top;
	canvas_pt_t start_point;
	canvas_color_t color;
} canvas_text_t;

typedef struct canvas_rect_s {
	int line_width;	// filled: -1
	canvas_pt_t start_point, end_point;
} canvas_rect_t;

typedef union {
	canvas_text_t text;
	canvas_rect_t rect;
	canvas_pt_t point;
} canvas_draw_data_t;

typedef struct canvas_msg_s {
	int ch;
	int idx;
	int msg_type;
	canvas_draw_data_t draw_data;
	canvas_color_t color;
} canvas_msg_t;

void draw_point_on_bitmap(uint8_t *bitmap, int width, int height, canvas_pt_t *pt, canvas_color_t *color);
void draw_line_on_bitmap(uint8_t *bitmap, int width, int height, canvas_pt_t *pt1, canvas_pt_t *pt2, canvas_color_t *color);
void draw_rect_on_bitmap(uint8_t *bitmap, int width, int height, canvas_rect_t *rect, canvas_color_t *color);
void draw_text_on_bitmap(uint8_t *bitmap, int width, int height, int font_idx, canvas_text_t *text, canvas_color_t *color);

#endif //CANVAS_H_