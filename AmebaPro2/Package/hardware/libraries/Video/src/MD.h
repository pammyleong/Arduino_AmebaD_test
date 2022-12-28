#ifndef __MD_H__
#define __MD_H__

#ifdef __cplusplus
extern "C" {
#endif

#include "md_drv.h"

#ifdef __cplusplus
}
#endif

#include "VideoStream.h"

class MD:public MMFModule {
    public:
        MD(void);
        ~MD(void);
        void getOSDParams(int ch, VideoSetting& config);
        void configVideo(int ch, VideoSetting& config);
        void begin(void);
        void OSDDraw(void);
    private:
};

#endif
