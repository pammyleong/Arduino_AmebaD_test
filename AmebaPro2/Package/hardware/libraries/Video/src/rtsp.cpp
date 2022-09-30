#include <Arduino.h>
#include "rtsp.h"

#ifdef __cplusplus
extern "C" {
#endif

#include "rtsp_drv.h"

#ifdef __cplusplus
}
#endif

static data_content_t *rtspData = NULL;

#define ON  1
#define OFF 0


RTSP::RTSP(){};
RTSP::~RTSP(){};

/**
  * @brief  none
  * @param  none
  * @retval  none
  */
void RTSP::Init(int channel_idx, uint32_t rtsp_fps, uint32_t rtsp_bps, int video_codec) {
	RTSP_Config(rtsp_fps, rtsp_bps, video_codec);
	RTSP_Set_Apply();
	RTSP_Select_Stream (channel_idx);
	RTSP_Set_Params();

	rtspData = RTSP_Init(); 
}

void RTSP::RTSP_Open(void){
	RTSP_Set_Streaming(ON);
}

void RTSP::RTSP_Close(void){
	RTSP_Set_Streaming(OFF);
}

void RTSP::DeInit(void){
	//RTSP_DeInit();
}



