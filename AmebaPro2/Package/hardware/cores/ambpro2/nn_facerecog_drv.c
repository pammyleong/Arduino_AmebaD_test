#include "nn_facerecog_drv.h"
#include "module_video.h"
#include "module_vipnn.h"
#include "module_facerecog.h"

#include "model_mobilefacenet.h"
#include "model_scrfd.h"

#include "osd_render.h"
//#include "log_service.h"

//static void *g_frc_ctx = NULL;

#define DEBUG           0
#define MAX_ARGC        20

#if DEBUG
#define CAMDBG(fmt, args...) \
    do {printf("\r\nFunc-[%s]@Line-%d: \r\n" fmt "\r\n", __func__, __LINE__, ## args); } while (0);
#else
#define CAMDBG(fmt, args...)
#endif

uint32_t RTSPWidthFR = 0;
uint32_t RTSPHeightFR = 0;
int RTSPChannelFR = 0;

// SCRFD + FACENET
#define NN_MODEL_OBJ    scrfd_fwfs
#define NN_MODEL2_OBJ   mbfacenet_fwfs
//#define NN_WIDTH        576
//#define NN_HEIGHT       320

//static nn_data_param_t roi_nn = {
//    .img = {
//        .width = 0,
//        .height = 0,
//        .rgb = 0, // set to 1 if want RGB->BGR or BGR->RGB
//        .roi = {
//            .xmin = 0,
//            .ymin = 0,
//            .xmax = 0,
//            .ymax = 0,
//        }
//    }
//};

#define LIMIT(x, lower, upper) if(x<lower) x=lower; else if(x>upper) x=upper;

TimerHandle_t osd_cleanup_timer = NULL;

void configFROSD(int ch, uint32_t width, uint32_t height) {
    RTSPWidthFR = width;
    RTSPHeightFR = height;
    RTSPChannelFR = ch;
}

//void configFR (uint16_t NN_width, uint16_t NN_height) {
//    roi_nn.img.width = NN_width;
//    roi_nn.img.height = NN_height;
//    roi_nn.img.roi.xmax = NN_width;
//    roi_nn.img.roi.ymax = NN_height;
//}

// callback function to to be called to clean up rect
void osd_cleanup_callback(TimerHandle_t xTimer) {
    (void)xTimer;
    canvas_clean_all(RTSPChannelFR, 0);
    canvas_update(RTSPChannelFR, 0);
}

// ===========
// FACERECOG
// ===========
// callback function to to be called to draw rect
void faceDrawObj(void *p, void *img_param) {
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

// Initialize Face Recognition module
mm_context_t* nnFRInit(void) {
    return mm_module_open(&facerecog_module);
}

// set NN face recognition threshold value
void nnFRSetThreshold(void *p) {
    facerecog_control(p, CMD_FRC_SET_THRES100, 99); // 99/100 = 0.99 --> set a value to get lowest FP rate
}

// set NN face recognition OSD
void nnFRSetOSDDraw(void *p) {
   facerecog_control(p, CMD_FRC_SET_OSD_DRAW, (int)faceDrawObj);
}

void FROSD(void) {
    int ch_enable[3] = {1, 0, 0};
    int char_resize_w[3] = {16, 0, 0}, char_resize_h[3] = {32, 0, 0};
    int ch_width[3] = {RTSPWidthFR, 0, 0}, ch_height[3] = {RTSPHeightFR, 0, 0};

    osd_render_dev_init(ch_enable, char_resize_w, char_resize_h);
    osd_render_task_start(ch_enable, ch_width, ch_height);
    osd_cleanup_timer = xTimerCreate("OSD clean timer", 500 / portTICK_PERIOD_MS, pdTRUE, NULL, osd_cleanup_callback);
}


// Register faces
//-----------------------------------------------------------------------------------------------
//void faceRegInit(void *p) {
//    g_frc_ctx = p;
//}
//
//void faceRegister(void *arg) {
//    int argc = 0;
//    char *argv[MAX_ARGC] = {0};
//    argc = parse_param(arg, argv);
//    printf("enter register mode\n\r");
//    mm_module_ctrl(g_frc_ctx, CMD_FRC_REGISTER_MODE, (int)argv[1]);
//}
//
//void faceRecgMode(void *arg) {
//    if (!g_frc_ctx)	{
//        return;
//    }
//    printf("enter recognition mode\n\r");
//    mm_module_ctrl(g_frc_ctx, CMD_FRC_RECOGNITION_MODE, 0);
//}
//
//void faceRecgLoadFeature(void *arg) {
//    if (!g_frc_ctx) {
//        return;
//    }
//    printf("load feature\n\r");
//    mm_module_ctrl(g_frc_ctx, CMD_FRC_LOAD_FEATURES, 0);
//}
//
//void faceRecgSaveFeature(void *arg) {
//    if (!g_frc_ctx) {
//        return;
//    }
//    printf("save feature\n\r");
//    mm_module_ctrl(g_frc_ctx, CMD_FRC_SAVE_FEATURES, 0);
//}
//
//void faceRecgResetFeature(void *arg) {
//    if (!g_frc_ctx) {
//        return;
//    }
//    printf("reset feature\n\r");
//    mm_module_ctrl(g_frc_ctx, CMD_FRC_RESET_FEATURES, 0);
//}
//
//void faceSetScoreThres(void *p, void *arg) {
//    if (!g_frc_ctx) {
//        return;
//    }
//    int argc = 0;
//    char *argv[MAX_ARGC] = {0};
//    argc = parse_param(arg, argv);
//    (void)argc;
//
//    int score = strtol(argv[1], NULL, 0);
//    printf("set face recognition score threshold to %.2f\n\r", (float)score / 100.0);
//    mm_module_ctrl(p, CMD_FRC_SET_THRES100, score);
//}
//

