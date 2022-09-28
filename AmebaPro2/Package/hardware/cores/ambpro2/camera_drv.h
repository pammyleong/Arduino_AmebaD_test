#ifndef camera_drv_h
#define camera_drv_h

#include <stdint.h>
#include <FreeRTOS.h>
#include <semphr.h>
#include <diag.h>

#define FW_VOE_SIZE        600*1024


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
data_content_t *cameraInit(void);

// Functions externed from module_video
extern void *video_create(void *parent);

extern void *video_destroy(void *p);

#endif
