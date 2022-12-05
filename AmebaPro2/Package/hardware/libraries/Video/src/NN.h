#ifndef __NN_H__
#define __NN_H__

#ifdef __cplusplus
extern "C" {
#endif

#include "nn_drv.h"

#ifdef __cplusplus
}
#endif

#include "Video.h"

class NNSetting {
    friend class Video;

    public:

    private:
};

class NNModelSetting {
    friend class NNSetting;

    public:

    private:
};

class VIPNN:public MMFModule {
    public:
        VIPNN(void);
        ~VIPNN(void);
        
        void configVideo(VideoSetting& config);
    private:
};

class FaceRecg:public MMFModule {
     public:
        FaceRecg(void);
        ~FaceRecg(void);
    private:
};

#endif
