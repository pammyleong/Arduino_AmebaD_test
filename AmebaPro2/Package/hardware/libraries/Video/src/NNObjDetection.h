#ifndef __NNOBJDETCTION_H__
#define __NNOBJDETCTION_H__

#ifdef __cplusplus
extern "C" {
#endif

#include "nn_objdet_drv.h"

#ifdef __cplusplus
}
#endif

#include "VideoStream.h"


class NNObjectDetection:public MMFModule {
    public:
        NNObjectDetection(void);
        ~NNObjectDetection(void);

        void configVideo(VideoSetting& config);
        void configObjDetOSD(int ch, VideoSetting& config);
        void configObjDetModel(float confidence_threshold, float nms_threshold);
        void beginObjDetOSD(void);
        //    void begin(void);
        //    void end(void);
    private:
        uint32_t width;
        uint32_t height;
        uint32_t RTSPwidth;
        uint32_t RTSPheight;
};

#endif
