#include <Arduino.h>
#include "rtsp.h"


#define ON  1
#define OFF 0
#define DEBUG 0

#define CH_IDX 0

#define RTSP_TYPE AVMEDIA_TYPE_VIDEO
#define AUDIO_TYPE AVMEDIA_TYPE_AUDIO
#define RTSP_BPS CAM_BPS //2*1024*1024

//#define VID_FPS 30
//#define AV_CODEC AV_CODEC_ID_H264

#if DEBUG
#define CAMDBG(fmt, args...) \
    do {printf("\r\nFunc-[%s]@Line-%d: \r\n"fmt"\r\n", __func__, __LINE__, ## args); } while (0);
#else
#define CAMDBG(fmt, args...)
#endif

RTSPClass::RTSPClass(void){
    rtspData = NULL;
	// ADD RTSPAudioData
};
RTSPClass::~RTSPClass(){};


//-------------------------------------------------------------------------------//

/**
  * @brief  Initialization for RTSP module by setting up RTSP paramters. 
  Default value: channel_idx : 0
                   video type: AVMEDIA_TYPE_VIDEO
                   fps: 30
                   bps: 2*1024*1024
                   video_codec: AV_CODEC_ID_H264
  * @param  obj
  * @retval none
  */
void RTSPClass::init(CameraSetting *obj) {
    rtspData = RTSP_Init();
	
	
    CAMDBG("RTSP_Init done\r\n");

	// to be improved
	uint32_t rtsp_ch_idx = CH_IDX;
	uint32_t rtsp_type = RTSP_TYPE;
	uint32_t rtsp_bps = RTSP_BPS;

	uint32_t rtsp_fps = obj->_fps;
	uint32_t av_codec_id = obj->_decoder;

	if (av_codec_id == VIDEO_H264){
		av_codec_id = AV_CODEC_ID_H264;
	}

	else if (av_codec_id == VIDEO_JPEG){
		av_codec_id = AV_CODEC_ID_MJPEG;
		rtsp_bps = NULL; 
	}
	printf("\r\nbps: %d\r\n", rtsp_bps);
	printf("\r\nfps: %d\r\n", rtsp_fps);
	printf("\r\nAV_codec_id: %d\r\n", av_codec_id);

	RTSP_Select_Stream(rtspData->priv, rtsp_ch_idx);
    CAMDBG("RTSP_Select_Stream done\r\n");
	
	RTSP_Set_Params(rtspData->priv, rtsp_type, rtsp_fps, rtsp_bps, av_codec_id);
    CAMDBG("RTSP_Set_Params done\r\n");

	RTSP_Set_Apply(rtspData->priv);
    CAMDBG("RTSP_Set_Apply done\r\n");
}


//-------------------------------------------------------------------------------//

/**
  * @brief  Start RTSP streaming
  * @param  void pointer to rtsp obj
  * @retval none
  */
void RTSPClass::open (){
    
    if (rtspData->priv == NULL) {
        printf("Streaming failed, RTSP not initialised yet.\r\n");
    }
	
    else {
        CAMDBG("Start Streaming\r\n");
        RTSP_Set_Streaming ((void *)rtspData, ON);
    }
}

//-------------------------------------------------------------------------------//


/**
  * @brief  Get RTSP data pointer
  * @param  none
  * @retval data pointer
  */
mm_context_t *RTSPClass::getIO(void) {
    // To check if rtsp init is done
	if (rtspData == NULL) {
		printf("Streaming failed, please init RTSP first.\r\n");	
		return NULL;
	}
	
	else {
		return rtspData;
	}
}

//-------------------------------------------------------------------------------//


/**
  * @brief  Stop RTSP streaming
  * @param  void pointer to rtsp obj
  * @retval none
  */
void RTSPClass::close(){
    RTSP_Set_Streaming(rtspData->priv, OFF);
}

//-------------------------------------------------------------------------------//

/**
  * @brief  Deinit and release all the resources set for RTSP 
  * @param  void pointer to rtsp obj
  * @retval none
  */
void RTSPClass::deInit(){
    if (RTSP_DeInit(rtspData->priv) == NULL) {
        CAMDBG("RTSP DeInit.\r\n");
    }
    else {
        CAMDBG("RTSP need to be DeInit.\r\n");
    }
}

//-------------------------------------------------------------------------------//

