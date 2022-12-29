#ifndef md_drv_h
#define md_drv_h

#include <stdint.h>
#include <FreeRTOS.h>
#include <semphr.h>
#include <diag.h>
#include "mmf2_module.h"

// void md_process(void *md_result);

void MDOSDConfig(int ch, uint32_t width, uint32_t height);

mm_context_t* MDInit(void);

void setMDParams(void *p, int img_width, int img_height);

void setMDThres(void *p);

void setMDMask(mm_context_t *p);

void setMDDisppost(void *p);

void setMDTrigBlock(void *p);

void MDDraw(void);

// Function externed from module_md
extern int md_control(void *p, int cmd, int arg);

#endif
