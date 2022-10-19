#ifndef __RTSP_H__
#define __RTSP_H__

#ifdef __cplusplus
extern "C" {
#endif

#include "aac_drv.h"
#include "avcodec.h"

#ifdef __cplusplus
}
#endif

class AACClass {
    public:
        AACClass(void);
        ~AACClass(void);

        void init(void);
        void deInit(void);
        mm_context_t *getIO(void);

        int ch_idx = 0;

        uint32_t video_type = AVMEDIA_TYPE_VIDEO;
        uint32_t fps = 30;
        uint32_t bps = 2*1024*1024;
        uint32_t VC = AV_CODEC_ID_H264;

		// For aac
		uint32_t sample_rate = 8000;
		uint32_t channel = 1;
		uint32_t bit_length = FAAC_INPUT_16BIT;
		uint32_t output_format = 1;
		uint32_t mpeg_version = MPEG4;
		uint32_t mem_total_size = 10 * 1024;
		uint32_t mem_block_size = 128;
		uint32_t mem_frame_size = 1024;
        
    private:
        mm_context_t *AACData;

};



#endif



