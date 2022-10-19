#include "aac_drv.h"
#include "module_audio.h"

#include "module_aac.h"

//#include <stdlib.h>
//#include "mmf2_link.h"
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

static audio_params_t audio_params = {
    .sample_rate = 0,
	.word_length = 0,
	.mic_gain    = 0,
	.dmic_l_gain    = 0,
	.dmic_r_gain    = 0,
	.use_mic_type   = 0,
	.channel     = 0,
	.enable_aec  = 0
//	.sample_rate = ASR_8KHZ,
//	.word_length = WL_16BIT,
//	.mic_gain    = MIC_0DB,
//	.dmic_l_gain    = DMIC_BOOST_24DB,
//	.dmic_r_gain    = DMIC_BOOST_24DB,
//	.use_mic_type   = USE_AUDIO_AMIC,
//	.channel     = 1,
//	.enable_aec  = 0
};

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

mm_context_t* audio_Init(void) { 
    return mm_module_open(&audio_module);
}

void audioOpen(mm_context_t *p, int sample_rate, int word_length, int mic_gain, int dmic_l_gain, int dmic_r_gain, int use_mic_type, int channel, int enable_aec){
    audio_params.sample_rate = sample_rate;
	audio_params.word_length = word_length;
	audio_params.mic_gain    = mic_gain;
	audio_params.dmic_l_gain    = dmic_l_gain;
	audio_params.dmic_r_gain    = dmic_r_gain;
	audio_params.use_mic_type   = use_mic_type;
	audio_params.channel     = channel;
	audio_params.enable_aec  = enable_aec;
    

    if (p) {
        mm_module_ctrl(p, CMD_AUDIO_SET_PARAMS, (int)&audio_params);
        mm_module_ctrl(p, MM_CMD_SET_QUEUE_LEN, 6);
        mm_module_ctrl(p, MM_CMD_INIT_QUEUE_ITEMS, MMQI_FLAG_STATIC);
        mm_module_ctrl(p, CMD_AUDIO_APPLY, 0);

        CAMDBG("audio opened");
    } else {
		CAMDBG("audio open fail");
	}
}

