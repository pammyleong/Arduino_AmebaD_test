#ifndef __NNFACEDETCTION_H__
#define __NNFACEDETCTION_H__

#ifdef __cplusplus
extern "C" {
#endif

#include "nn_facedet_drv.h"

#ifdef __cplusplus
}
#endif

#include "VideoStream.h"

//class NNModelSetting {
//    friend class NNSetting;
//
//    public:
//
//    private:
//};

class NNFaceDetection:public MMFModule {
    public:
        NNFaceDetection(void);
        ~NNFaceDetection(void);
        
        void configVideo(VideoSetting& config, int faceRecogFlag = 0);
        void configModel(VideoSetting& config);
        void configOSD(int ch, VideoSetting& config);
        void beginOSD(void);
    private:
};

//class FaceRecg:public MMFModule {
//     public:
//        FaceRecg(void);
//        ~FaceRecg(void);
//    private:
//};

#endif
