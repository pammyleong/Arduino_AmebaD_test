#ifndef camera_drv_h
#define camera_drv_h

#define FW_VOE_SIZE        600*1024


void videoLoadFirmware(unsigned int sensor_start_addr);

void videoInitPeripheral(void);

void videoLoadIQ(void);

void videoLoadSensor(void);

// Function 1: define parameters to initialize the ISP heap size for VOE
int videoVOEPresetting(int enable, int w, int h, int bps, int snapshot);

// Function 2: collect parameters

#endif
