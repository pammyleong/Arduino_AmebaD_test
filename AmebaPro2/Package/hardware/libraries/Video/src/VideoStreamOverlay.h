#ifndef __VIDEOSTREAMOVERLAY_H__
#define __VIDEOSTREAMOVERLAY_H__

#ifdef __cplusplus
extern "C" {
#endif

#include "osd_render.h"

#ifdef __cplusplus
}
#endif

#include "VideoStream.h"

class VideoStreamOverlay{
    public:
        void clearAll(int ch, int idx);
        void update(int ch, int idx);
        void setPoint(int ch, int idx, int xmin, int ymin, int point_width, uint32_t color);
        void drawRect(int ch, int idx, int xmin, int ymin, int xmax, int ymax, int line_width, uint32_t color);
        void setText(int ch, int idx, int xmin, int ymin, char *text_string, uint32_t color);
        void taskStop(void);
        void taskStart(int *ch_visible, int *ch_width, int *ch_height);
        void init(int *ch_enable, int *char_resize_w, int *char_resize_h);
        void deinit(int ch);
        void deinitAll();
        void config(int ch, VideoSetting& config, int resize_text_width, int resize_text_height);
        void begin(void);
    private:
        int ch_enable[3]={0};
        int char_resize_w[3] = {0};
        int char_resize_h[3] = {0};
        int ch_width[3] = {0};
        int ch_height[3] = {0};
};


extern VideoStreamOverlay OSD;

#endif