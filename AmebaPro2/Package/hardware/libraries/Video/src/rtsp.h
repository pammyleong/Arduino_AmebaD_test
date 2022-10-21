#ifndef __RTSP_H__
#define __RTSP_H__

#ifdef __cplusplus
extern "C" {
#endif

#include "rtsp_drv.h"
#include "avcodec.h"
#include "camera.h"


#ifdef __cplusplus
}
#endif


class RTSPClass : public CameraSetting 
{
    public:
        RTSPClass(void);
        ~RTSPClass(void);

        void init(CameraSetting *obj);
		void RTSP_Test(void);
        void open(void);
        void close(void);
        void deInit(void);
        mm_context_t *getIO(void);
		
    private:
        mm_context_t *rtspData;
		
};



#endif



