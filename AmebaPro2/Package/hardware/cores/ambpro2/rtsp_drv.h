#ifndef rtsp_drv_h
#define rtsp_drv_h
#include <stdint.h>
#include <FreeRTOS.h>
#include <semphr.h>
#include <diag.h>
#include "mmf2_module.h"

mm_context_t* RTSP_Init (void);

int RTSP_Select_Stream (void *p, int arg);

int RTSP_Set_Apply (void *p);

void RTSP_Set_Streaming (void *p, int arg);

int RTSP_Set_Params_Video (void *p, uint32_t rtsp_fps, uint32_t rtsp_bps, uint32_t AV_codec);

int RTSP_Set_Params_Audio (void *p, uint32_t channel, uint32_t sample_rate, uint32_t AV_codec);

mm_context_t* RTSP_DeInit (void *p);

// extern function 
extern void *rtsp2_create (void *parent);
extern void *rtsp2_destroy(void *p);
extern int rtsp2_control(void *p, int cmd, int arg);
extern int rtsp2_handle(void *p, void *input, void *output);

// For Testing and Debugging
//-------------------------------------------------------------------------------//
void RTSP_TEST(mm_context_t *p, uint32_t rtsp_fps, uint32_t rtsp_bps, uint32_t V_codec, uint32_t channel, uint32_t sample_rate, uint32_t A_codec);

#endif
