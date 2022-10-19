#ifndef rtsp_drv_h
#define rtsp_drv_h
#include <stdint.h>
#include <FreeRTOS.h>
#include <semphr.h>
#include <diag.h>
#include "mmf2_module.h"

// In faaccfg.h, cannot be found in Arduino env
/* Input Formats */
#define FAAC_INPUT_NULL    0
#define FAAC_INPUT_16BIT   1
#define FAAC_INPUT_24BIT   2
#define FAAC_INPUT_32BIT   3
#define FAAC_INPUT_FLOAT   4

/* MPEG ID's */
#define MPEG2 1
#define MPEG4 0

mm_context_t* AAC_Init (void);
int AAC_Set_Params (void *p, uint32_t sample_rate, uint32_t channel, uint32_t bit_length, uint32_t output_format, uint32_t mpeg_version, uint32_t mem_total_size, uint32_t mem_block_size, uint32_t mem_frame_size);
int AAC_Set_Queue_Length (void *p);
int AAC_Init_Queue_Items (void *p);
int AAC_Init_Mem_Pool (void *p);
int AAC_Apply (void *p);
mm_context_t* AAC_DeInit(void *p);



// extern function
extern int aac_control(void *p, int cmd, int arg);
extern void *aac_destroy(void *p);
extern void *aac_create(void *parent);


#endif