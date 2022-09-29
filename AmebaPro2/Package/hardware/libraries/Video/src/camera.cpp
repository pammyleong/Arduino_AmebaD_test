#include "camera.h"
#include <Arduino.h>


#ifdef __cplusplus
extern "C" {
#endif

#include "camera_drv.h"

#ifdef __cplusplus
}
#endif

static data_content_t *cameraData = NULL;

Camera::Camera(){};
Camera::~Camera(){};

/**
  * @brief  initialization for the camera sensor
  * @param  none
  * @retval  none
  */
void Camera::Init(int enable, int w, int h, int bps, int snapshot) {
    int heapSize = cameraConfig(enable, w, h, bps, snapshot);
    printf("VOE heap size is: %d", heapSize);

    cameraData = cameraInit(); // pending to return pointer to structre or keep using cameraData
}

/**
  * @brief  none
  * @param  none
  * @retval  none
  */
void Camera::DeInit(void) {
    // cameraDeInit();
}

/**
  * @brief  none
  * @param  none
  * @retval  none
  */
void Camera::Open(int stream_id, int type, int res, int w, int h, int bps, int fps, int gop, int rc_mode) {
    cameraOpen(stream_id, type, res, w, h, bps, fps, gop, rc_mode);
}


/**
  * @brief  none
  * @param  none
  * @retval  none
  */
void Camera::Close(void) {
    // cameraStopVideoStream();
}

