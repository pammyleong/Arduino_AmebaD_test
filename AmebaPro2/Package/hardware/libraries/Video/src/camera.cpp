#include <Arduino.h>
#include "camera.h"

#ifdef __cplusplus
extern "C" {
#endif

#include "camera_drv.h"

#ifdef __cplusplus
}
#endif

Camera::Camera(){
    video_data = NULL;
};

Camera::~Camera(){};

/**
  * @brief  initialization for the camera sensor
  * @param  none
  * @retval  none
  */
void *Camera::Init(){
    int w = 1920;
    int h = 1080;
    int bps = 2*1024*1024;
    
    return Init(w, h, bps);
}

/**
  * @brief  initialization for the camera sensor
  * @param  w       : width
            h       : height
            bps     : bit rate in bits per second
  * @retval  none
  */
void *Camera::Init(int w, int h, int bps){
    int enable = 1;
    int snapshot = 0;
    
    return Init(enable, w, h, bps, snapshot);
}

/**
  * @brief  initialization for the camera sensor
  * @param  enable  : sensor enable status
            w       : width
            h       : height
            bps     : bit rate in bits per second
            snapshot: eanble or disable snapshot function
  * @retval  none
  */
void *Camera::Init(int enable, int w, int h, int bps, int snapshot) {
    int heapSize = cameraConfig(enable, w, h, bps, snapshot);
    
    printf("[%s] VOE heap size is: %d\r\n", __FUNCTION__, heapSize);

    video_data = cameraInit();
    
    return (void *)video_data;

}

/**
  * @brief  deinitialization for the camera sensor
  * @param  none
  * @retval  none
  */
void Camera::DeInit() {
    if (cameraDeInit(video_data) == NULL) {
        printf("RTSP DeInit.\r\n");
    }
    else {
        printf("RTSP need to be DeInit.\r\n");
    }

}

/**
  * @brief  open camera with default value setting
  * @param  none
  * @retval  none
  */
void Camera::Open() {
    int stream_id = V1_CHANNEL;
    int type =VIDEO_TYPE; 
    int res =V1_RESOLUTION; 
    int w=V1_WIDTH;
    int h=V1_HEIGHT;
    int bps=V1_BPS;
    int fps=V1_FPS;
    int gop=V1_GOP;
    int rc_mode=V1_RCMODE;
    Open(video_data, video_data->priv, stream_id, type, res, w, h, bps, fps, gop, rc_mode);
}

void Camera::Open(mm_context_t *p){
    int stream_id = V1_CHANNEL;
    int type =VIDEO_TYPE; 
    int res =V1_RESOLUTION; 
    int w=V1_WIDTH;
    int h=V1_HEIGHT;
    int bps=V1_BPS;
    int fps=V1_FPS;
    int gop=V1_GOP;
    int rc_mode=V1_RCMODE;
    cameraOpen(p, p->priv, stream_id, type, res, w, h, bps, fps, gop, rc_mode);
}

/**
  * @brief  open camera with default value setting
  * @param  stream_id: 
            type     : video or audio type 
            res      : video resolution
            w        : width
            h        : hight
            bps      : bit rate in bits per second
            fps      : frame rate in frames per second
            gop      ： group of pictures
            rc_mode  : enable or disable constant rate mode
  * @retval  none
  */
void Camera::Open(mm_context_t *p, void *p_priv, int stream_id, int type, int res, int w, int h, int bps, int fps, int gop, int rc_mode) {
    cameraOpen(p, p_priv, stream_id, type, res, w, h, bps, fps, gop, rc_mode);
}

/**
  * @brief  start camera upon camera settings were defined
  * @param  none
  * @retval  none
  */
void Camera::Start(){
//    cameraStart(video_data->priv, V1_CHANNEL);
    cameraStart(video_data->priv, V1_CHANNEL);
}

/**
  * @brief  close camera while transmision is finished
  * @param  none
  * @retval  none
  */
void Camera::Close() {
    cameraStopVideoStream(video_data->priv, V1_CHANNEL);
}

