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

// Function 3: disable video streaming
void cameraStopVideoStream(void *p);

// Function 4: deinit parameters assigned to ISP and VOE
data_content_t *cameraDeInit(data_content_t *ctx);

// Functions externed from module_video
extern void *video_create(void *parent);

extern void *video_destroy(void *p);

extern int video_close(int ch);

extern void *video_del_item(void *p, void *d);

extern void *video_deinit(void);

#endif
