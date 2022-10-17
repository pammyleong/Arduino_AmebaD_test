#include <Arduino.h>
#include "camera.h"

#define DEBUG 0

#if DEBUG
#define CAMDBG(fmt, args...) \
    do {printf("\r\nFunc-[%s]@Line-%d: "fmt"", __func__, __LINE__, ## args); } while (0);
#else
#define CAMDBG(fmt, args...)
#endif

#ifdef __cplusplus
extern "C" {
#endif

#include "camera_drv.h"

#ifdef __cplusplus
}
#endif

CameraClass::CameraClass(){
    video_data = NULL;
};

CameraClass::~CameraClass(){};

/**
  * @brief  initialization for the camera sensor
  * @param  resolution : 4K, FHD, HD, or VGA
            fps        : frame rate (frame per second)
  * @retval  none
  */
void CameraClass::init(int version){
    int w   = 1920;
    int h   = 1080;
    int bps = 2*1024*1024;
    
    return init(w, h, bps, version);
}

/**
  * @brief  initialization for the camera sensor
  * @param  w       : width
            h       : height
            bps     : bit rate in bits per second
  * @retval  none
  */
void CameraClass::init(int w, int h, int bps, int version){
    int enable   = VIDEO_ENABLE;
    int snapshot = VIDEO_SNAPSHOT_DISABLE;

    return init(enable, w, h, bps, snapshot, version);
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
void CameraClass::init(int enable, int w, int h, int bps, int snapshot, int version) {
    int heapSize = cameraConfig(enable, w, h, bps, snapshot, version);
    printf("[%s] VOE heap size is: %d\r\n", __FUNCTION__, heapSize);
    video_data = cameraInit();
}

/**
  * @brief  deinitialization for the camera sensor
  * @param  void pointer to video obj
  * @retval  none
  */
void CameraClass::deInit(void){
    if (cameraDeInit(video_data) == NULL) {
        printf("Camera Sensor DeInit Done.\r\n");
    }
    else {
        printf("Camera Sensor DeInit Failed.\r\n");
    }
}

/**
  * @brief  open camera with default value setting
  * @param  void pointer to video obj
  * @retval  none
  */
void CameraClass::open(void){
    int stream_id = V1_CHANNEL;
    int type =VIDEO_TYPE; 
    int res =V1_RESOLUTION; 
    int w=V1_WIDTH;
    int h=V1_HEIGHT;
    int bps = CAM_BPS;
    int fps = CAM_FPS;
    int gop = CAM_GOP;
    int rc_mode = CAM_RCMODE;
    cameraOpen(video_data, video_data->priv, stream_id, type, res, w, h, bps, fps, gop, rc_mode);
}

/**
  * @brief  open camera with default value setting
  * @param  void pointer to video obj
  * @retval  none
  */
void CameraClass::open(int version){
    if (version == 1){
        int stream_id = V1_CHANNEL;
        int type = VIDEO_TYPE; 
        int res = V1_RESOLUTION; 
        int w = V1_WIDTH;
        int h = V1_HEIGHT;
        int bps = CAM_BPS;
        int fps = CAM_FPS;
        int gop = CAM_GOP;
        int rc_mode = CAM_RCMODE;
        cameraOpen(video_data, video_data->priv, stream_id, type, res, w, h, bps, fps, gop, rc_mode);
    }
    else if (version == 2){
        int stream_id = V2_CHANNEL;
        int type =VIDEO_TYPE; 
        int res =V2_RESOLUTION; 
        int w=V2_WIDTH;
        int h=V2_HEIGHT;
        int bps = CAM_BPS;
        int fps = CAM_FPS;
        int gop = CAM_GOP;
        int rc_mode = CAM_RCMODE;
        cameraOpen(video_data, video_data->priv, stream_id, type, res, w, h, bps, fps, gop, rc_mode);
    }
    else if (version == 3){
        int stream_id = V3_CHANNEL;
        int type =VIDEO_JPEG; 
        int res =V3_RESOLUTION; 
        int w=V3_WIDTH;
        int h=V3_HEIGHT;
        int fps = CAM_FPS;
        cameraOpenv3(video_data, video_data->priv, stream_id, type, res, w, h, fps);
    }
    else{

    }
    
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
void CameraClass::open(mm_context_t *p, void *p_priv, int stream_id, int type, int res, int w, int h, int bps, int fps, int gop, int rc_mode) {
    cameraOpen(p, p_priv, stream_id, type, res, w, h, bps, fps, gop, rc_mode);
}

/**
  * @brief  start camera upon camera settings were defined
  * @param  void pointer to video obj
  * @retval  none
  */
void CameraClass::start(int version){
    if (version == 1){
        cameraStart(video_data->priv, V1_CHANNEL);
    } 
    else if (version == 2){
        cameraStart(video_data->priv, V2_CHANNEL);
    }
    else if (version == 3){
        cameraStart(video_data->priv, V3_CHANNEL);
        cameraSnapshot(video_data->priv, V3_CHANNEL);
    }
	
}


/**
  * @brief  Get video data pointer
  * @param  none
  * @retval data pointer
  */
mm_context_t *CameraClass::getIO(void) {
    //To check if camera sensor init is done
	if (video_data == NULL){
		printf("\r\nPlease init camera sensor first.\r\n");
		return NULL;
	}
	
	else{
		 return video_data;
	}
}


/**
  * @brief  close camera while transmision is finished
  * @param  void pointer to video obj
  * @retval  none
  */
void CameraClass::close(){
    cameraStopVideoStream(video_data->priv, V1_CHANNEL);
}