#include "rtsp_drv.h"
#include "mmf2_link.h"
#include "mmf2_siso.h"
#include "mmf2_module.h"
#include "sensor.h"
#include "rtsp/rtsp_api.h"
#include "module_rtsp2.h"
#include "queue.h"

#define DEBUG 0

#if DEBUG
#define CAMDBG(fmt, args...) \
    do {printf("\r\nFunc-[%s]@Line-%d: \r\n"fmt"\r\n", __func__, __LINE__, ## args); } while (0);
#else
#define CAMDBG(fmt, args...)
#endif

extern void rtp_stream_statistics_sync(struct stream_context *stream_ctx);

//-------------------------------------------------------------------------------//

//video output
static rtsp2_params_t rtsp_params = {
    .type = 0,
    .u = {
        .v = {
            .codec_id = 0,
            .fps      = 0,
            .bps      = 0
        }
    }
};

//audio output
//static rtsp2_params_t rtsp_param_audio = {
//	.type = AVMEDIA_TYPE_AUDIO,
//	.u = {
//		.a = {
//			.codec_id   = AV_CODEC_ID_MP4A_LATM,
//			.channel    = 1,
//			.samplerate = 8000
//		}
//	}
//};


//-------------------------------------------------------------------------------//

mm_context_t* RTSP_Init (void) { 
    return mm_module_open(&rtsp2_module);
}

//-------------------------------------------------------------------------------//

// Select channel index 0 or 1
int RTSP_Select_Stream (void *p, int channel_idx) {
    return rtsp2_control(p, CMD_RTSP2_SELECT_STREAM, channel_idx);
}

//-------------------------------------------------------------------------------//

// Apply parameters set
int RTSP_Set_Apply (void *p) {
    return rtsp2_control(p, CMD_RTSP2_SET_APPLY, 0);
}

//-------------------------------------------------------------------------------//

// Decide to on or off streaming
void RTSP_Set_Streaming (void *p, int arg) { 
    CAMDBG("Set Streaming");
    mm_module_ctrl((mm_context_t *)p, CMD_RTSP2_SET_STREAMMING, ON);
}

//-------------------------------------------------------------------------------//

// Set parameters for RTSP
int RTSP_Set_Params (void *p, uint32_t video_type, uint32_t rtsp_fps, uint32_t rtsp_bps, uint32_t AV_codec) {
    rtsp_params.type = video_type;
    rtsp_params.u.v.fps = rtsp_fps;
    rtsp_params.u.v.bps = rtsp_bps;
    rtsp_params.u.v.codec_id = AV_codec;

    return rtsp2_control(p, CMD_RTSP2_SET_PARAMS, (int)&rtsp_params);
}

//-------------------------------------------------------------------------------//

// deinit and release all resources for RTSP
mm_context_t* RTSP_DeInit (void *p){
	return mm_module_close(p);
}

//-------------------------------------------------------------------------------//

