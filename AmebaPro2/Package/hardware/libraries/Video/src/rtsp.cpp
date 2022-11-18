#include <Arduino.h>
#include "rtsp.h"

#define ON  1
#define OFF 0
#define DEBUG 1

#define VID_CH_IDX 0
#define RTSP_VIDEO_TYPE AVMEDIA_TYPE_VIDEO
#define RTSP_BPS CAM_BPS

#define AUDIO_CH_IDX 1
#define RTSP_AUDIO_TYPE AVMEDIA_TYPE_AUDIO
#define AUDIO_SAMPLE_RATE 8000
#define AUDIO_CODEC_ID AV_CODEC_ID_MP4A_LATM

static int AUDIO_EN = 0;

#if DEBUG
#define CAMDBG(fmt, args...) \
    do {printf("\r\nFunc-[%s]@Line-%d: \r\n" fmt "\r\n", __func__, __LINE__, ## args); } while (0);
#else
#define CAMDBG(fmt, args...)
#endif

RTSP::RTSP(void) {

};

/**
  * @brief  Initialization for RTSP module by setting up RTSP paramters. 
  * @param  obj  : object pointer to Camera Settings
  * @retval none
  */
void RTSP::init(VideoSetting& obj) {
    if (_p_mmf_context == NULL) {
        _p_mmf_context = RTSPInit();
    }
    CAMDBG("RTSP_Init done\r\n");

    uint32_t RTSP_fps;
    uint32_t AV_Codec_ID;
    uint32_t RTSP_bps = CAM_BPS;

    RTSP_fps = obj._fps;
    AV_Codec_ID = obj._encoder;
    RTSP_bps = obj._bps;

    if (AV_Codec_ID == VIDEO_H264) {
        AV_Codec_ID = AV_CODEC_ID_H264;
    } else if (AV_Codec_ID == VIDEO_JPEG) {
        AV_Codec_ID = AV_CODEC_ID_MJPEG;
        RTSP_bps = 0; 
    }
    CAMDBG("%d   %d   %d", RTSP_fps, RTSP_bps, AV_Codec_ID);
    CAMDBG("AUDIO_EN Status: %d", AUDIO_EN);
    RTSPSelectStream(_p_mmf_context->priv, VID_CH_IDX);
    RTSPSetParamsVideo(_p_mmf_context->priv, RTSP_fps, RTSP_bps, AV_Codec_ID);
    RTSPSetApply(_p_mmf_context->priv);
    if (AUDIO_EN == 1) {
        RTSPSelectStream(_p_mmf_context->priv,AUDIO_CH_IDX);
        RTSPSetParamsAudio(_p_mmf_context->priv,AUDIO_CH_IDX, AUDIO_SAMPLE_RATE, AUDIO_CODEC_ID);
        RTSPSetApply(_p_mmf_context->priv);
    }
}

/**
  * @brief  deinit and release all the resources set for RTSP 
  * @param  none
  * @retval none
  */
void RTSP::deinit(void) {
    if (_p_mmf_context == NULL) {
        return;
    }
    if (RTSPDeinit(_p_mmf_context) == NULL) {
        _p_mmf_context = NULL;
    } else {
        CAMDBG("RTSP deinit failed\r\n");
    }
}

/**
  * @brief  Start RTSP streaming
  * @param  none
  * @retval none
  */
void RTSP::open (void) {
    if (_p_mmf_context == NULL) {
        printf("Need RTSP init first\r\n");
    } else {
        RTSPSetStreaming((void *)_p_mmf_context, ON);
        CAMDBG("Start Streaming\r\n");
    }
}

/**
  * @brief  Stop RTSP streaming
  * @param  none
  * @retval none
  */
void RTSP::close(void) {
    if (_p_mmf_context == NULL) {
        printf("Need RTSP init first\r\n");
    }
    RTSPSetStreaming((void *)_p_mmf_context, OFF);
}

/**
  * @brief  Enable RTSP settings for Audio Video streaming
  * @param  none
  * @retval AUDIO_EN status as a integer
  */
int RTSP::enableAudio(void) {
    AUDIO_EN = 1;
    return AUDIO_EN;
}

/**
  * @brief  Get RTSP port value for RTSP address
  * @param  none
  * @retval port value as a integer
  */
int RTSP::getPort(void) {
    if (_p_mmf_context == NULL) {
        printf("Need RTSP init first\r\n");
    }
    int port_val;
    port_val = RTSPGetPort(_p_mmf_context->priv);
    return port_val;
}
