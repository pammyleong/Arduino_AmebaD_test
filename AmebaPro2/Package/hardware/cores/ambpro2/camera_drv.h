#ifndef camera_drv_h
#define camera_drv_h

#include <stdint.h>
#include <FreeRTOS.h>
#include <semphr.h>
#include <diag.h>

typedef struct data_conveyor_s {
	xQueueHandle    output_ready;
	xQueueHandle    output_recycle;
	int32_t item_num;
} data_conveyor_t;

typedef struct data_content_s {
	union {
		struct {
			xQueueHandle    output_ready;
			xQueueHandle    output_recycle;
			int32_t item_num;
		};
		data_conveyor_t port[4];
	};

	//mm_module_t    *module;

	// private data structure for created instance
	void *priv;

	// module state
	uint32_t state;
	int32_t queue_num;			// number of queue
	int32_t curr_queue;
} data_content_t;

// Function 1: define parameters to initialize the ISP heap size for VOE
int cameraConfig(int enable, int w, int h, int bps, int snapshot);

// Function 2: collect parameters
void *cameraInit(void);

// Function 3: set video parameter, init queue and open camera
void cameraOpen(int stream_id, int type, int res, int w, int h, int bps, int fps, int gop, int rc_mode);

// Function 4: disable video streaming
void cameraStopVideoStream(void);

// Function 5: deinit parameters assigned to ISP and VOE
void *cameraDeInit(void);

// Functions externed from module_video
extern void *video_create(void *parent);
extern void *video_destroy(void *p);
extern int video_control(void *p, int cmd, int arg);
extern int video_close(int ch);
extern void *video_del_item(void *p, void *d);
extern void *video_deinit(void);

#endif
