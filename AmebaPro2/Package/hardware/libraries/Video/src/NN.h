#ifndef __NN_H__
#define __NN_H__

#ifdef __cplusplus
extern "C" {
#endif

#include "nn_objdet_drv.h"
#include "nn_facedet_drv.h"
#include "nn_facerecog_drv.h"

#ifdef __cplusplus
}
#endif

#include "VideoStream.h"

class NNObjectDetection:public MMFModule {
    public:
        void configVideo(VideoSetting& config);
        void configOSD(int ch, VideoSetting& config);
        void configModel(float confidence_threshold, float nms_threshold, VideoSetting& config);

    private:
};

class NNFaceDetection:public MMFModule {
    public:
        void configVideo(VideoSetting& config, int faceRecogFlag = 0);
        void configModel(VideoSetting& config);
        void configOSD(int ch, VideoSetting& config);
    private:
};

class NNFaceRecognition:public MMFModule {
    public:
        void configOSD(int ch, VideoSetting& config);
        void configVideo();
        void beginOSD(void);
    private:
};

#endif
