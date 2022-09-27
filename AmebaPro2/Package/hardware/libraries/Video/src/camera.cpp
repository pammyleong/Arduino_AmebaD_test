#include "camera.h"
#include <Arduino.h>


#ifdef __cplusplus
extern "C" {
#endif

#include "camera_drv.h"

#ifdef __cplusplus
}
#endif


// define video resolution
#define V1_RESOLUTION VIDEO_FHD
// define video frame rate
#define V1_FPS 30
// define video group of pictures
#define V1_GOP 30
// define video bit rate
#define V1_BPS 2*1024*1024
// define video rate control
#define V1_RCMODE 2 // 1: CBR, 2: VBR
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
// define video resolution
#if V1_RESOLUTION == VIDEO_FHD
#define V1_WIDTH	1920
#define V1_HEIGHT	1080
#endif

//static mm_context_t *video_v1_ctx			= NULL;

Camera::Camera(){};
Camera::~Camera(){};

/**
  * @brief  none
  * @param  none
  * @retval  none
  */
void Camera::Init(void) {
    int heapSize = cameraConfig(1, V1_WIDTH, V1_HEIGHT, V1_BPS, 0);
    printf("VOE heap size is: %d", heapSize);
    cameraInit();
//    return video_v1_ctx;
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

