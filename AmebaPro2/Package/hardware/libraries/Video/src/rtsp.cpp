#include <Arduino.h>
#include "rtsp.h"

#define ON  1
#define OFF 0

RTSP::RTSP(){};
RTSP::~RTSP(){};

/**
  * @brief  Initialization for RTSP module by setting up RTSP paramters. 
  Default value: channel_idx : 0
  				 video type: AVMEDIA_TYPE_VIDEO
  				 fps: 30
  				 bps: 2*1024*1024
  				 video_codec: AV_CODEC_ID_H264
  * @param  none
  * @retval none
  */

void* RTSP::Init(void) {

	rtspData = RTSP_Init();
	RTSP_Select_Stream(rtspData->priv, ch_idx);
	RTSP_Set_Params(rtspData->priv, video_type, fps, bps, VC);
	RTSP_Set_Apply(rtspData->priv);

	return rtspData->priv;
}

/**
  * @brief  Start RTSP streaming
  * @param  none
  * @retval none
  */
void RTSP::Open(void){
		
	if (rtspData->priv == NULL) {
		printf("Streaming failed, RTSP not initialised yet.");
	}
	else {
		RTSP_Set_Streaming(rtspData->priv, ON);
	}
}

/**
  * @brief  Stop RTSP streaming
  * @param  none
  * @retval none
  */
void RTSP::Close(void){
	RTSP_Set_Streaming(rtspData->priv, OFF);
}

/**
  * @brief  Deinit and release all the resources set for RTSP 
  * @param  none
  * @retval none
  */
void RTSP::DeInit(void){
	if (RTSP_DeInit(rtspData->priv) == NULL) {
		printf("RTSP DeInit.");
	}
	else {
		printf("RTSP need to be DeInit.");
	}
}
