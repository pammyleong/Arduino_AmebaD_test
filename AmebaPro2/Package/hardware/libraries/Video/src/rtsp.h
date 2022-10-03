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

class RTSP {
    public:
        RTSP(void);
        ~RTSP(void);
	
		void* Init(void);
	    void RTSP_Open(void);
		void RTSP_Close(void);
		void DeInit(void);
		
		uint32_t fps = 30;
		uint32_t bps = 2*1024*1024;
		int ch_idx = 0;
		int VC = AV_CODEC_ID_H264;
		
    private:
		mm_context_t rtspData;
		void* rtsp_ptr;
		
        
};

//extern RTSP rtsp;

#endif



