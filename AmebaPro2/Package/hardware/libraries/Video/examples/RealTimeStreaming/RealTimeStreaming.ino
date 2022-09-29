/**
 *  This function describes how to use the Realtek RTSP API. 
*/

#include "rtsp.h"
#include "avcodec.h"


// define video codec
#define USE_H265 0

#if USE_H265
#include "sample_h265.h"
#define VIDEO_TYPE VIDEO_HEVC
#define VIDEO_CODEC AV_CODEC_ID_H265
#else
#include "sample_h264.h"
#define VIDEO_TYPE VIDEO_H264
#define VIDEO_CODEC AV_CODEC_ID_H264
#endif

// define video frame rate
#define RTSP_FPS 30

// define video bit rate
#define RTSP_BPS 2*1024*1024

#define CH_IDX 0


/* Create a RTSP object */
RTSP rtsp;

void setup() {
    //Serial.begin(115200);
	rtsp.Init(CH_IDX, RTSP_FPS, RTSP_BPS, VIDEO_CODEC);
	rtsp.RTSP_Open();
}

void loop() {

}
