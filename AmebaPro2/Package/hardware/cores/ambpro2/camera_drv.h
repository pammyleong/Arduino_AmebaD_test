#ifndef camera_drv_h
#define camera_drv_h

#define FW_VOE_SIZE        600*1024


// Function 1: define parameters to initialize the ISP heap size for VOE
int cameraPresetting(int enable, int w, int h, int bps, int snapshot);

// Function 2: collect parameters
void *cameraInit(void *parent);

// Functions externed from video_api
extern int voe_boot_fsc_status(void);

extern int voe_boot_fsc_id(void);

extern int voe_get_sensor_info(int id, int *iq_data, int *sensor_data);

// Functions externed from module_video
int isp_get_id(void);

#endif
