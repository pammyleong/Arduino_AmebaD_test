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
  * @brief  initialization for camera sensor
  * @param  none
  * @retval  none
  */
//int enable, int w, int h, int bps, int snapshot
void Camera::Init(int enable, int w, int h, int bps, int snapshot) {
    int heapSize = cameraConfig(enable, w, h, bps, snapshot);
    printf("VOE heap size is: %d", heapSize);

    cameraData = cameraInit();
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
void Camera::Open(void) {

}


/**
  * @brief  none
  */
void Camera::Close(void) {

}

