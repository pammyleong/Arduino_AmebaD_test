#ifndef __NNFACERECOGNITION_H__
#define __NNFACERECOGNITION_H__

#ifdef __cplusplus
extern "C" {
#endif

#include "nn_facerecog_drv.h"

#ifdef __cplusplus
}
#endif

#include "VideoStream.h"

class NNFaceRecognition:public MMFModule {
    public:
        NNFaceRecognition(void);
        ~NNFaceRecognition(void);
        
        void configOSD(int ch, VideoSetting& config);
        void configVideo();
        void beginOSD(void);
    private:
};

//class NNFaceNet:public MMFModule {
//     public:
//        NNFaceNet(void);
//        ~NNFaceNet(void);
//    private:
//};

#endif
