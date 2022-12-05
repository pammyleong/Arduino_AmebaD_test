#ifndef array_drv_h
#define array_drv_h

#include <stdint.h>
#include <FreeRTOS.h>
#include <semphr.h>
#include <diag.h>
#include "mmf2_module.h"

mm_context_t* arrayInit(void);

mm_context_t* arrayDeinit(mm_context_t *p);

void arraySetParams(void *p, uint32_t array_type, uint32_t array_encoder, uint32_t array_fps, uint32_t h264_nal_size);

void arraySetArray(void *p) ;

void arraySetQueue(mm_context_t *p);

void arraySetApply(void *p);

void arrayStart(mm_context_t *p);

void arrayStop(mm_context_t *p);

// extern function
extern int array_control(void *p, int cmd, int arg);

#endif