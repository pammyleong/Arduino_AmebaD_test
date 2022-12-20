#include "nn_facerecog_drv.h"
#include "module_video.h"
#include "module_vipnn.h"
#include "module_facerecog.h"

#include "model_mobilefacenet.h"
#include "model_scrfd.h"

#include "osd_render.h"

#define DEBUG           0

#if DEBUG
#define CAMDBG(fmt, args...) \
    do {printf("\r\nFunc-[%s]@Line-%d: \r\n" fmt "\r\n", __func__, __LINE__, ## args); } while (0);
#else
#define CAMDBG(fmt, args...)
#endif

uint32_t RTSPWidthFR = 0;
uint32_t RTSPHeightFR = 0;
int RTSPChannelFR = 0;

// #define NN_CHANNEL 4
// #define NN_RESOLUTION VIDEO_VGA //don't care for NN
// #define NN_FPS 10
// #define NN_GOP NN_FPS
// #define NN_BPS 1024*1024 //don't care for NN
// #define NN_TYPE VIDEO_RGB

// SCRFD + FACENET
#define NN_MODEL_OBJ   	scrfd_fwfs
#define NN_MODEL2_OBJ   mbfacenet_fwfs
#define NN_WIDTH		576
#define NN_HEIGHT		320

static nn_data_param_t roi_nn = {
    .img = {
        .width = NN_WIDTH,
        .height = NN_HEIGHT,
        .rgb = 0, // set to 1 if want RGB->BGR or BGR->RGB
        .roi = {
            .xmin = 0,
            .ymin = 0,
            .xmax = NN_WIDTH,
            .ymax = NN_HEIGHT,
        }
    }
};

#define LIMIT(x, lower, upper) if(x<lower) x=lower; else if(x>upper) x=upper;

TimerHandle_t osd_cleanup_timer = NULL;

// get settings from RTSP module
// ======================================================
// change name to setOSDparam
// ch: given a fixed value as user input RTSP_CHANNEL
// ======================================================
void getRTSPFR (int ch, uint32_t width, uint32_t height) { 
    RTSPWidthFR = width;
    RTSPHeightFR = height;
    RTSPChannelFR = ch;
}

// callback function to to be called to clean up rect
void osd_cleanup_callback(TimerHandle_t xTimer) {
    (void)xTimer;
    canvas_clean_all(RTSPChannelFR, 0);
    canvas_update(RTSPChannelFR, 0);
}

// callback function to to be called to draw rect
void face_draw_object(void *p, void *img_param) {
    int i = 0;
    frc_draw_t *fdraw = (frc_draw_t *)p;

    if (!p)	{
        return;
    }

    int im_h = RTSPHeightFR;
    int im_w = RTSPWidthFR;

    printf("object num = %d\r\n", fdraw->obj_cnt);
    canvas_clean_all(RTSPChannelFR, 0);
    if (fdraw->obj_cnt > 0) {
        for (i = 0; i < fdraw->obj_cnt; i++) {
            nn_data_param_t *param = fdraw->img_param[i];
            int x_offset = 0, y_offset = 0;
            float ratio;
            if ((float)im_w / (float)im_h > (float)param->img.width / (float)param->img.height) {
                ratio = (float)im_h / (float)param->img.height;
                x_offset = (im_w - (float)param->img.width * ratio) / 2;
            } else {
                ratio = (float)im_w / (float)param->img.width;
                y_offset = (im_h - (float)param->img.height * ratio) / 2;
            }

            int xmin = (int)(param->img.roi.xmin * ratio) + x_offset;
            int ymin = (int)(param->img.roi.ymin * ratio) + y_offset;
            int xmax = (int)(param->img.roi.xmax * ratio) + x_offset;
            int ymax = (int)(param->img.roi.ymax * ratio) + y_offset;
            LIMIT(xmin, 0, im_w)
            LIMIT(xmax, 0, im_w)
            LIMIT(ymin, 0, im_h)
            LIMIT(ymax, 0, im_h)
            //printf("%d,c%s:%d %d %d %d\n\r", i, fdraw->obj_name[i], xmin, ymin, xmax, ymax);

            if (!strcmp(fdraw->obj_name[i], "unknown")) {
                canvas_set_rect(RTSPChannelFR, 0, xmin, ymin, xmax, ymax, 3, COLOR_RED);
                canvas_set_text(RTSPChannelFR, 0, xmin, ymin - 32, fdraw->obj_name[i], COLOR_RED);
            } else {
                canvas_set_rect(RTSPChannelFR, 0, xmin, ymin, xmax, ymax, 3, COLOR_GREEN);
                canvas_set_text(RTSPChannelFR, 0, xmin, ymin - 32, fdraw->obj_name[i], COLOR_GREEN);
            }
        }
        if (osd_cleanup_timer) {
            xTimerReset(osd_cleanup_timer, 10);
        }
    }
    canvas_update(RTSPChannelFR, 0);
}

// set NN face recognition threshold value
void nnFacerecogSetThreshold(void *p) {
    vipnn_control(p, CMD_FRC_SET_THRES100, 99); // 99/100 = 0.99 --> set a value to get lowest FP rate
}

// set NN face recognition OSD
void nnFacerecogSetOSDDraw(void *p) {
    vipnn_control(p, CMD_FRC_SET_OSD_DRAW, (int)face_draw_object);
}

// Initialize Face Recognition module 
mm_context_t* nnFaceRecgInit(void) {
    return mm_module_open(&vipnn_module);
}

// setup NN model: FD
void nnSetFaceRecgModel1(void *p) {
    vipnn_control(p, CMD_VIPNN_SET_MODEL, (int)&NN_MODEL_OBJ);
}

// setup NN model: FR
void nnSetFaceRecgModel2(void *p) {
    vipnn_control(p, CMD_VIPNN_SET_MODEL, (int)&NN_MODEL2_OBJ);
}

// set current NN model to cascade mode
void nnSetFaceRecgCascade(void *p) {
    vipnn_control(p, CMD_VIPNN_SET_CASCADE, 2);
}

// setup NN module input parameters
void nnSetFaceRecgInputParam(void *p) {
    vipnn_control(p, CMD_VIPNN_SET_IN_PARAMS, (int)&roi_nn);
}

// set NN module as output of a linker module
void nnSetFaceRecgOutput(void *p) {
    vipnn_control(p, CMD_VIPNN_SET_OUTPUT, 1);
}

// set NN module as data group input or output
void nnSetFaceRecgDatagroup(mm_context_t *ctx, int status) {
    mm_module_ctrl(ctx, MM_CMD_SET_DATAGROUP, status);
}

// apply NN face recognition object
void nnFaceRecgSetApply(void *p) {
    vipnn_control(p, CMD_VIPNN_APPLY, 0);
}