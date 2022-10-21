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

//video output
static rtsp2_params_t rtsp_params = {
    .type = AVMEDIA_TYPE_VIDEO,
    .u = {
        .v = {
            .codec_id = 0,
            .fps      = 0,
            .bps      = 0
        }
    }
};

//audio output
static rtsp2_params_t rtsp_param_audio = {
	.type = AVMEDIA_TYPE_AUDIO,
	.u = {
		.a = {
			.codec_id   = 0,
			.channel    = 0,
			.samplerate = 0
		}
	}
};

// RTSP init
mm_context_t* RTSP_Init (void) { 
    return mm_module_open(&rtsp2_module);
}


// Select channel index 0 (video) or 1 (audio) etc
int RTSP_Select_Stream (void *p, int channel_idx) {
    //return rtsp2_control(p, CMD_RTSP2_SELECT_STREAM, channel_idx);
	return rtsp2_control(p, CMD_RTSP2_SELECT_STREAM, channel_idx);
}


// Apply parameters set
int RTSP_Set_Apply (void *p) {
	return rtsp2_control(p, CMD_RTSP2_SET_APPLY, 0);
}


// Decide to on or off streaming
void RTSP_Set_Streaming (void *p, int arg) { 
    CAMDBG("Set Streaming");
    mm_module_ctrl((mm_context_t *)p, CMD_RTSP2_SET_STREAMMING, arg);	
}


// Set parameters for RTSP Video
int RTSP_Set_Params_Video (void *p, uint32_t rtsp_fps, uint32_t rtsp_bps, uint32_t AV_codec) {
    rtsp_params.u.v.fps = rtsp_fps;
    rtsp_params.u.v.bps = rtsp_bps;
    rtsp_params.u.v.codec_id = AV_codec;

	return rtsp2_control(p, CMD_RTSP2_SET_PARAMS, (int)&rtsp_params);
}


// Set parameters for RTSP Audio
int RTSP_Set_Params_Audio (void *p, uint32_t channel, uint32_t sample_rate, uint32_t AV_codec) {
    rtsp_param_audio.u.a.channel = channel;
	rtsp_param_audio.u.a.samplerate = sample_rate;
    rtsp_param_audio.u.a.codec_id = AV_codec;

	return rtsp2_control(p, CMD_RTSP2_SET_PARAMS, (int)&rtsp_param_audio);
}


// deinit and release all resources for RTSP
mm_context_t* RTSP_DeInit (void *p){
	return mm_module_close(p);
}


// FOR TESTING/DEBUGGING
//-------------------------------------------------------------------------------//

void RTSP_TEST(mm_context_t *p, uint32_t rtsp_fps, uint32_t rtsp_bps, uint32_t V_codec, uint32_t channel, uint32_t sample_rate, uint32_t A_codec){
  	RTSP_Select_Stream(p->priv,0);
	RTSP_Set_Params_Video(p->priv,rtsp_fps,rtsp_bps,V_codec); //p: mm_module_ctrl   p->priv: rtsp2_control
	RTSP_Set_Apply(p->priv);
	
//	rtsp_params.u.v.fps = rtsp_fps;
//	rtsp_params.u.v.bps = rtsp_bps;  
//	rtsp_params.u.v.codec_id = V_codec;
//	mm_module_ctrl(p, CMD_RTSP2_SELECT_STREAM, 0);
//	mm_module_ctrl(p, CMD_RTSP2_SET_PARAMS, (int)&rtsp_params);
	
//	mm_module_ctrl(p, CMD_RTSP2_SET_APPLY, 0);


	RTSP_Select_Stream(p->priv,1);
	RTSP_Set_Params_Audio(p->priv,channel,sample_rate,A_codec); //p: mm_module_ctrl   p->priv: rtsp2_control
	RTSP_Set_Apply(p->priv);
	
//	rtsp_param_audio.u.a.channel = channel;
//	rtsp_param_audio.u.a.samplerate = sample_rate;
//    rtsp_param_audio.u.a.codec_id = A_codec;
//	mm_module_ctrl(p, CMD_RTSP2_SELECT_STREAM, 1);
//	mm_module_ctrl(p, CMD_RTSP2_SET_PARAMS, (int)&rtsp_param_audio);
	
//	mm_module_ctrl(p, CMD_RTSP2_SET_APPLY, 0);

	RTSP_Set_Streaming(p, ON);
//	mm_module_ctrl(p, CMD_RTSP2_SET_STREAMMING, ON);
}

//-------------------------------------------------------------------------------//

