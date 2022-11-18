#ifndef __RTSP_H__
#define __RTSP_H__

#ifdef __cplusplus
extern "C" {
#endif

#include "rtsp_drv.h"
#include "avcodec.h"

#ifdef __cplusplus
}
#endif

#include "camera.h"

class RTSP:public MMFModule {
    public:
        RTSP(void);

        void init(VideoSetting& obj);
        void deinit(void);
        void open(void);
        void close(void);
        int enableAudio(void);
        int getPort(void);

    private:
};

#endif