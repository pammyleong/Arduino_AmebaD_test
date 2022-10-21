#include <Arduino.h>
#include "rtsp.h"

#define ON  1
#define OFF 0
#define DEBUG 0

#define VID_CH_IDX 0
#define RTSP_VIDEO_TYPE AVMEDIA_TYPE_VIDEO
#define RTSP_BPS CAM_BPS

#define AUDIO_CH_IDX 1
#define RTSP_AUDIO_TYPE AVMEDIA_TYPE_AUDIO
#define AUDIO_SAMPLE_RATE 8000
#define AUDIO_CODEC_ID AV_CODEC_ID_MP4A_LATM

#if DEBUG
#define CAMDBG(fmt, args...) \
    do {printf("\r\nFunc-[%s]@Line-%d: \r\n" fmt "\r\n", __func__, __LINE__, ## args); } while (0);
#else
#define CAMDBG(fmt, args...)
#endif

RTSPClass::RTSPClass(void){
    rtspData = NULL;
};
RTSPClass::~RTSPClass(){};


/**
  * @brief  Initialization for RTSP module by setting up RTSP paramters. 
  * @param  obj
  * @retval none
  */
void RTSPClass::init(CameraSetting *obj) {
    rtspData = RTSP_Init();
    CAMDBG("RTSP_Init done\r\n");

	uint32_t rtsp_fps = obj->_fps;
	uint32_t av_codec_id = obj->_decoder;
	uint32_t rtsp_bps = RTSP_BPS;

	if (av_codec_id == VIDEO_H264){
		av_codec_id = AV_CODEC_ID_H264;
	}

	else if (av_codec_id == VIDEO_JPEG){
		av_codec_id = AV_CODEC_ID_MJPEG;
		rtsp_bps = 0; 
	}

	CAMDBG("\r\VID_CH_IDX: %d\r\n", VID_CH_IDX);
	CAMDBG("\r\nfps: %d\r\n", rtsp_fps);
	CAMDBG("\r\nbps: %d\r\n", rtsp_bps);
	CAMDBG("\r\nAV_codec_id: %d\r\n", av_codec_id);

	CAMDBG("\r\AUDIO_CH_IDX: %d\r\n", AUDIO_CH_IDX);
	CAMDBG("\r\AUDIO_SAMPLE_RATE: %d\r\n", AUDIO_SAMPLE_RATE);
	CAMDBG("\r\AUDIO_CODEC_ID: %d\r\n", AUDIO_CODEC_ID);
	
	RTSP_Select_Stream(rtspData->priv, VID_CH_IDX);
	CAMDBG("RTSP_Select_Stream 0 done\r\n");
	
	RTSP_Set_Params_Video(rtspData->priv,rtsp_fps,rtsp_bps,av_codec_id);
	CAMDBG("Video_RTSP_Set_Params done\r\n");
	
	RTSP_Set_Apply(rtspData->priv);
	CAMDBG("Video_RTSP_Set_Apply done\r\n");

	RTSP_Select_Stream(rtspData->priv,AUDIO_CH_IDX);
	CAMDBG("RTSP_Select_Stream 1 done\r\n");
	
	RTSP_Set_Params_Audio(rtspData->priv,AUDIO_CH_IDX,AUDIO_SAMPLE_RATE,AUDIO_CODEC_ID);
	CAMDBG("Audio_RTSP_Set_Params done\r\n");
	
	RTSP_Set_Apply(rtspData->priv);
	CAMDBG("Audio_RTSP_Set_Apply done\r\n");

}


/**
  * @brief  Start RTSP streaming
  * @param  void pointer to rtsp obj
  * @retval none
  */
void RTSPClass::open (void){
    if (rtspData == NULL) {
        printf("Streaming failed, RTSP not initialised yet.\r\n");
    }

    else {
        CAMDBG("Start Streaming\r\n");
		RTSP_Set_Streaming ((void *)rtspData, ON);
    }
}

/**
  * @brief  Stop RTSP streaming
  * @param  void pointer to rtsp obj
  * @retval none
  */
void RTSPClass::close(void){
    RTSP_Set_Streaming((void *)rtspData, OFF);
}


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

// FOR TESTING/DEBUGGING

//-------------------------------------------------------------------------------//

void RTSPClass:: RTSP_Test(void) {
	rtspData = RTSP_Init();
	mm_context_t *p = rtspData;
	
//	RTSP_TEST(rtspData);
	RTSP_TEST(rtspData, 30, 2*1024*1024, AV_CODEC_ID_H264, 1, 8000, AV_CODEC_ID_MP4A_LATM);

//	RTSP_Select_Stream(p->priv,0);
//	RTSP_Set_Params_Video(p->priv,30,RTSP_BPS,AV_CODEC_ID_H264);
//	RTSP_Set_Apply(p->priv);
//
//	RTSP_Select_Stream(p->priv,1);
//	RTSP_Set_Params_Audio(p->priv,AUDIO_CH_IDX,AUDIO_SAMPLE_RATE,AUDIO_CODEC_ID);
//	RTSP_Set_Apply(p->priv);
	
//	RTSP_Set_Streaming(p->priv,ON);

}

