#ifndef NN_OSD_DRAW_H_
#define NN_OSD_DRAW_H_

#define OSD_OBJ_MAX_NUM 6 //fix value
#define OSD_TXT_MAX_NUM 20

#define DRAW_NOTHING   0
#define DRAW_RECT_ONLY 1
#define DRAW_TEXT_ONLY 2
#define DRAW_RECT_AND_TEXT 3

typedef struct osd_color_s {
	unsigned char r;
	unsigned char g;
	unsigned char b;
} osd_color_t;

typedef struct nn_rect_s {
	int xmin, ymin;
	int xmax, ymax;
} nn_rect_t;

typedef struct nn_osd_text_s {
	char text_str[OSD_TXT_MAX_NUM];
	int left;
	int top;
	osd_color_t color;
} nn_osd_text_t;

typedef struct nn_osd_rect_s {
	nn_rect_t rect;
	unsigned char line_width;
	osd_color_t color;
} nn_osd_rect_t;

typedef struct nn_osd_object_s {
	int idx;
	int draw_status;
	nn_osd_text_t text;
	nn_osd_rect_t rect;
} nn_osd_object_t;

typedef struct nn_osd_ctx_s {
	int nn_osd_ready2draw;
	int nn_osd_channel;
	int xmax, ymax;
	nn_osd_object_t obj[OSD_OBJ_MAX_NUM];
} nn_osd_ctx_t;

typedef struct nn_osd_draw_obj_s {
	int obj_num;
	nn_rect_t rect[OSD_OBJ_MAX_NUM];
	int score[OSD_OBJ_MAX_NUM];
	int class[OSD_OBJ_MAX_NUM];
	char name[OSD_OBJ_MAX_NUM][128];
} nn_osd_draw_obj_t;



void nn_osd_start(int ch, int txt_w, int txt_h, int xmax, int ymax);
int nn_osd_get_status(void);

//int nn_osd_set_text(int idx, nn_osd_text_t* text);
//int nn_osd_set_rect(int idx, nn_osd_rect_t* rect);
int nn_osd_set_rect_with_text(int idx, nn_osd_text_t *text, nn_osd_rect_t *rect);
int nn_osd_clear_bitmap(int idx);

//int nn_osd_set_object(osd_ctx_t nn_results);
int nn_osd_update();

#endif //NN_OSD_DRAW_H_