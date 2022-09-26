#include "camera_drv.h"
#include "mmf2_link.h"
#include "mmf2_siso.h"
#include "base_type.h"
#include "hal_video.h"
#include "video_api.h"
#include "sensor.h"


#define OSD_ENABLE 1
#define MD_ENABLE  1
#define HDR_ENABLE 1

int videoVOEPresetting(int enable, int w, int h, int bps, int snapshot){
    int voe_heap_size = 0;
	isp_info_t info;

	if (USE_SENSOR == SENSOR_GC4653) {
		info.sensor_width = 2560;
		info.sensor_height = 1440;
		info.sensor_fps = 15;
	} else {
		info.sensor_width = 1920;
		info.sensor_height = 1080;
		info.sensor_fps = 30;
	}

//#if OSD_ENABLE
//	info.osd_enable = 1;
//#endif
//
//#if MD_ENABLE
//	info.md_enable = 1;
//#endif
//
//#if HDR_ENABLE
//	info.hdr_enable = 1;
//#endif
//
//	video_set_isp_info(&info);
//
//	voe_heap_size =  video_buf_calc(enable, w, h, bps, snapshot);
//    
	return voe_heap_size;
}



extern int __voe_code_start__[];


void videoLoadFirmware(unsigned int sensor_start_addr){
    //int offset = 0;
	unsigned int fw_size = 0;
	//void *fp = NULL;

    fw_size = FW_VOE_SIZE; //Default voe fw size
    unsigned char *buf = malloc(fw_size);
    
    if (sensor_start_addr > 12) {
        printf("Analog read has a maximum resolution of 12 bits. \r\n");
    }
    sensor_start_addr = OK;
    //hal_video_load_fw((voe_cpy_t)hal_voe_cpy, buf, __voe_code_start__);
    hal_video_load_fw(sensor_start_addr, buf, __voe_code_start__);
    video_init(sensor_start_addr,sensor_start_addr);
    video_create(0);
}

mm_context_t *mm_module_open(mm_module_t *mm) //, int queue_num, int queue_size)
{
	mm_context_t *ctx = (mm_context_t *)rtw_malloc(sizeof(mm_context_t));
	if (!ctx) {
		return NULL;
	}
	memset(ctx, 0, sizeof(mm_context_t));

	ctx->queue_num = 1;		// default 1 queue, can set multiple queue by command MM_CMD_SET_QUEUE_NUM
	ctx->module = mm;
	ctx->priv = mm->create(ctx);

	if (!ctx->priv) {
		goto mm_open_fail;
	}

	//rt_printf("module open - free heap %d\n\r", xPortGetFreeHeapSize());
	return ctx;

mm_open_fail:

	mm_printf("fail------\n\r");

	if (ctx->priv) {
		mm->destroy(ctx->priv);
	}
	if (ctx) {
		free(ctx);
	}
	return NULL;
}


