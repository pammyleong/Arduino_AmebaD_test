/**
 *  This function describes how to use the Realtek Camera API. 
*/

/*****************************************************************************
* ISP channel : 0
* Video type  : H264/HEVC
* Sensor      : SENSOR_JXF37
*****************************************************************************/
#include "camera.h"

#define V1_ENABLE   1
#define V1_DISABLE   0

#define V1_SNAPSHOT_ENABLE 1
#define V1_SNAPSHOT_DISABLE 0
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

/* Create an camera object */
Camera cam;

void setup() {
    Serial.begin(115200);
    cam.Init(V1_ENABLE, V1_WIDTH, V1_HEIGHT, V1_BPS, V1_SNAPSHOT_DISABLE);
}

void loop() {

}
