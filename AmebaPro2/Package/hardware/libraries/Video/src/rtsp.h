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

#ifndef AUDIO_ENABLE
#define AUDIO_EN 0
#endif

#ifdef AUDIO_ENABLE
#define AUDIO_EN 1
#endif

class RTSPClass : public CameraSetting {
    public:
        RTSPClass(void);
        ~RTSPClass(void);

        void init(CameraSetting *obj);
        void open(void);
        void close(void);
        void deInit(void);
        mm_context_t *getIO(void);
        
    private:
        mm_context_t *rtspData;
};

#endif
