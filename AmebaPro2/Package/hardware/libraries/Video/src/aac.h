#ifndef __RTSP_H__
#define __RTSP_H__

#ifdef __cplusplus
extern "C" {
#endif

#include "aac_drv.h"
#include "avcodec.h"

#ifdef __cplusplus
}
#endif

class AACClass {
    public:
        AACClass(void);
        ~AACClass(void);

        void init(void);
        void deInit(void);
        mm_context_t *getIO(void);
        
    private:
        mm_context_t *AACData;

};



#endif



