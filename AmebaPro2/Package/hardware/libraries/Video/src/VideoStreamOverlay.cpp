#include <Arduino.h>
#include "VideoStreamOverlay.h"

#define DEBUG 1

#if DEBUG
#define CAMDBG(fmt, args...) \
    do {printf("\r\nFunc-[%s]@Line-%d: \r\n" fmt "\r\n", __func__, __LINE__, ## args); } while (0);
#else
#define CAMDBG(fmt, args...)
#endif

VideoStreamOverlay OSD;

void VideoStreamOverlay::clearAll(int ch, int idx) {
    canvas_clean_all(ch, idx);
}

void VideoStreamOverlay::update(int ch, int idx) {
    canvas_update(ch, idx);
}

void VideoStreamOverlay::setPoint(int ch, int idx, int xmin, int ymin, int point_width, uint32_t color) {
    canvas_set_point(ch, idx, xmin, ymin, point_width, color);
}

void VideoStreamOverlay::drawRect(int ch, int idx, int xmin, int ymin, int xmax, int ymax, int line_width, uint32_t color) {
    canvas_set_rect(ch, idx, xmin, ymin, xmax, ymax, line_width, color);
}

void VideoStreamOverlay::setText(int ch, int idx, int xmin, int ymin, char *text_string, uint32_t color) {
    canvas_set_text(ch, idx, xmin, ymin, text_string, color);
}

void VideoStreamOverlay::taskStop(void) {
    osd_render_task_stop();    
}

void VideoStreamOverlay::taskStart(int *ch_visible, int *ch_width, int *ch_height) {
    osd_render_task_start(ch_visible, ch_width, ch_height);
}

void VideoStreamOverlay::init(int *ch_enable, int *char_resize_w, int *char_resize_h) {
    osd_render_dev_init(ch_enable, char_resize_w, char_resize_h);
}

void VideoStreamOverlay::deinit(int ch) {
    osd_render_dev_deinit(ch);
}

void VideoStreamOverlay::deinitAll() {
    osd_render_dev_deinit_all();
}

void VideoStreamOverlay::config(int ch, VideoSetting& config, int resize_text_width, int resize_text_height) {
    for (int i = 0; i <= 2; i++) {
        if (i == ch) {
            ch_enable[i] = 1;
            char_resize_w[i] = resize_text_width;
            char_resize_h[i] = resize_text_height;
            ch_width[i] = config._w;
            ch_height[i] = config._h;
        }
        CAMDBG("ch_enable %d  %d  %d\r\n", ch_enable[0], ch_enable[1], ch_enable[2]);
        CAMDBG("char_resize_w %d  %d  %d\r\n", char_resize_w[0], char_resize_w[1], char_resize_w[2]);
        CAMDBG("char_resize_h %d  %d  %d\r\n", char_resize_h[0], char_resize_h[1], char_resize_h[2]);
        CAMDBG("ch_width %d  %d  %d\r\n", ch_width[0], ch_width[1], ch_width[2]);
        CAMDBG("ch_height %d  %d  %d\r\n", ch_height[0], ch_height[1], ch_height[2]);
    }
}

void VideoStreamOverlay::begin(void) {
    init(ch_enable, char_resize_w, char_resize_h);
	taskStart(ch_enable, ch_width, ch_height);
}