#include "camera_drv.h"
#include "mmf2_link.h"
#include "mmf2_siso.h"
#include "base_type.h"
#include "hal_video.h"
#include "video_api.h"

#include "sensor.h"
#include "module_video.h"
#include "module_rtsp2.h"
#include "rtsp/rtsp_api.h"

#define OSD_ENABLE 1
#define MD_ENABLE  1
#define HDR_ENABLE 1

int sensor_id_value = 0;


void *cameraInit(void *parent){ //video_create()
    video_ctx_t *ctx = malloc(sizeof(video_ctx_t));
	int iq_addr, sensor_addr;
    
    if (!ctx) {
		return NULL;
	}
	memset(ctx, 0, sizeof(video_ctx_t));

	ctx->parent = parent;


	if (voe_boot_fsc_status()) {
		sensor_id_value = voe_boot_fsc_id();
		voe_get_sensor_info(sensor_id_value, &iq_addr, &sensor_addr);
	} 
    else {
#if MULTI_SENSOR
		int sensor_id = isp_get_id();
		printf("sensor_id %d\r\n", sensor_id);
		if (sensor_id != 0xff && sensor_id < isp_boot->p_fcs_ld_info.multi_fcs_cnt && sensor_id > 0) {
			sensor_id_value = sensor_id;
			voe_get_sensor_info(sensor_id_value, &iq_addr, &sensor_addr);
		} else {
			sensor_id_value = USE_SENSOR;
			voe_get_sensor_info(sensor_id_value, &iq_addr, &sensor_addr);
		}
#else
		if (!sensor_id_value) { //Use the default sensor, if the value equal to 0
			sensor_id_value = USE_SENSOR;
		}
		voe_get_sensor_info(sensor_id_value, &iq_addr, &sensor_addr);
#endif
	}
	printf("ID %x iq_addr %x sensor_addr %x\r\n", sensor_id_value, iq_addr, sensor_addr);
	ctx->v_adp = video_init(iq_addr, sensor_addr);
	printf("ctx->v_adp = 0x%X\r\n", (unsigned int)ctx->v_adp);

	return ctx;
}

int cameraPresetting(int enable, int w, int h, int bps, int snapshot){
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

#if OSD_ENABLE
	info.osd_enable = 1;
#endif

#if MD_ENABLE
	info.md_enable = 1;
#endif

#if HDR_ENABLE
	info.hdr_enable = 1;
#endif

	video_set_isp_info(&info);

	voe_heap_size =  video_buf_calc(enable, w, h, bps, snapshot,
        0,0,0,0,0,
        0,0,0,0,0,
        0,0,0);
    
	return voe_heap_size;
}



extern int __voe_code_start__[];




