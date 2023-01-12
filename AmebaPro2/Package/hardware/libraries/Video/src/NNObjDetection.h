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
        void configOSD(int ch, VideoSetting& config);
        void configModel(float confidence_threshold, float nms_threshold, VideoSetting& config);
        void beginOSD(void);

    private:

};

#endif
