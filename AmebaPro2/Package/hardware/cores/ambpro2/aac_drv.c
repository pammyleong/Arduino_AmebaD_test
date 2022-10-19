#include "aac_drv.h"
#include "module_aac.h"
#include "mmf2_link.h"
//#include <stdlib.h>


//#include "mmf2_module.h"
//#include "mmf2_siso.h"
//#include "sensor.h"
//#include "rtsp/rtsp_api.h"
//#include "module_rtsp2.h"
//#include "queue.h"

#define DEBUG 0

#if DEBUG
#define CAMDBG(fmt, args...) \
    do {printf("\r\nFunc-[%s]@Line-%d: \r\n"fmt"\r\n", __func__, __LINE__, ## args); } while (0);
#else
#define CAMDBG(fmt, args...)
#endif

//-------------------------------------------------------------------------------//

static aac_params_t aac_params = {	
	.sample_rate = 0,
	.channel = 0,
	.bit_length = 0,
	.output_format = 0,
	.mpeg_version = 0,
	.mem_total_size = 0,
	.mem_block_size = 0,
	.mem_frame_size = 0
};

//-------------------------------------------------------------------------------//

mm_context_t* AAC_Init (void) { 
    return mm_module_open(&aac_module);
}

//-------------------------------------------------------------------------------//


// check the return datatype and if any values needed to return for all the below functions
// and input params after cpp is created
int AAC_Set_Params (void *p, uint32_t sample_rate, uint32_t channel, uint32_t bit_length, uint32_t output_format, uint32_t mpeg_version, uint32_t mem_total_size, uint32_t mem_block_size, uint32_t mem_frame_size){
	// try change to aac_ctrl afterwards
	aac_params.sample_rate = sample_rate;
	aac_params.channel = channel;
	aac_params.bit_length = bit_length;
	aac_params.output_format = output_format;
	aac_params.mpeg_version = mpeg_version;
	aac_params.mem_total_size = mem_total_size;
	aac_params.mem_block_size = mem_block_size;
	aac_params.mem_frame_size = mem_frame_size;
	
	return mm_module_ctrl(p, CMD_AAC_SET_PARAMS, (int)&aac_params);
}

//-------------------------------------------------------------------------------//


int AAC_Set_Queue_Length (void *p){
	
	return mm_module_ctrl(p, MM_CMD_SET_QUEUE_LEN, 6);
}

//-------------------------------------------------------------------------------//

int AAC_Init_Queue_Items (void *p){
	
	return mm_module_ctrl(p, MM_CMD_INIT_QUEUE_ITEMS, MMQI_FLAG_DYNAMIC);
}

//-------------------------------------------------------------------------------//


int AAC_Init_Mem_Pool (void *p){
	// try change to aac_ctrl afterwards
	return mm_module_ctrl(p, CMD_AAC_INIT_MEM_POOL, 0);
}

//-------------------------------------------------------------------------------//


int AAC_Apply (void *p){
	// try change to aac_ctrl afterwards
	return mm_module_ctrl(p, CMD_AAC_APPLY, 0);
}

//-------------------------------------------------------------------------------//

mm_context_t* AAC_DeInit(void *p) {
	return mm_module_close (p);
}

//-------------------------------------------------------------------------------//

