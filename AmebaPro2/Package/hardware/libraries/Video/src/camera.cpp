#include "camera.h"
#include <Arduino.h>

#include "camera_drv.h"

#define V1_CHANNEL 0
#define	VIDEO_FHD   6

#define V1_RESOLUTION VIDEO_FHD
#define V1_FPS 30
#define V1_GOP 30

#define V1_BPS 2*1024*1024
#define V1_RCMODE 2 // 1: CBR, 2: VBR

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

// define video resolution
#if V1_RESOLUTION == VIDEO_FHD
#define V1_WIDTH	1920
#define V1_HEIGHT	1080
#endif


Camera::Camera(){};
Camera::~Camera(){};

/**
  * @brief  none
  * @param  none
  * @retval  none
  */
void Camera::Init(void) {
    cameraPresetting(1, V1_WIDTH, V1_HEIGHT, V1_BPS, 0);
}

/**
  * @brief  none
  * @param  none
  * @retval  none
  */
void Camera::DeInit(void) {

}

/**
  * @brief  none
  * @param  none
  * @retval  none
  */
void Camera::Open(long long t) {

}


/**
  * @brief  none
  */
void Camera::Close(int s) {

}

