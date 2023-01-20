#include <Arduino.h>
#include "NNFaceRecognition.h"

#ifdef __cplusplus
extern "C" {
#endif

#include "mmf2_module.h"
#include "module_vipnn.h"
#include "module_facerecog.h"
#include "model_mobilefacenet.h"
#include "osd_render.h"
#include "siso_drv.h"

extern int vipnn_control(void *p, int cmd, int arg);

#ifdef __cplusplus
}
#endif

#define DEBUG 0

#if DEBUG
#define CAMDBG(fmt, args...) \
    do {printf("\r\nFunc-[%s]@Line-%d: \r\n" fmt "\r\n", __func__, __LINE__, ## args); } while (0);
#else
#define CAMDBG(fmt, args...)
#endif

#define RTSP_CHANNEL 0
#define RTSP_HEIGHT 1080
#define RTSP_WIDTH 1920
#define LIMIT(x, lower, upper) if(x<lower) x=lower; else if(x>upper) x=upper;

void nnFaceRecogCB(void *p, void *img_param) {
    int i = 0;
        frc_draw_t *fdraw = (frc_draw_t *)p;
    
        if (!p) {
            return;
        }
    
        int im_h = RTSP_HEIGHT;
        int im_w = RTSP_WIDTH;
    
        printf("object num = %d\r\n", fdraw->obj_cnt);
        canvas_clean_all(RTSP_CHANNEL, 0);
        if (fdraw->obj_cnt > 0) {
            for (i = 0; i < fdraw->obj_cnt; i++) {
                nn_data_param_t *param = (nn_data_param_t *)fdraw->img_param[i];
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
                    canvas_set_rect(RTSP_CHANNEL, 0, xmin, ymin, xmax, ymax, 3, COLOR_RED);
                    canvas_set_text(RTSP_CHANNEL, 0, xmin, ymin - 32, fdraw->obj_name[i], COLOR_RED);
                } else {
                    canvas_set_rect(RTSP_CHANNEL, 0, xmin, ymin, xmax, ymax, 3, COLOR_GREEN);
                    canvas_set_text(RTSP_CHANNEL, 0, xmin, ymin - 32, fdraw->obj_name[i], COLOR_GREEN);
                }
            }
//            if (osd_cleanup_timer) {
//                xTimerReset(osd_cleanup_timer, 10);
//            }
        }
        canvas_update(RTSP_CHANNEL, 0);
}

void NNFaceRecognition::begin(void) {
    if (_p_mmf_context == NULL) {
        _p_mmf_context = mm_module_open(&vipnn_module);
    }
    if (_p_mmf_context == NULL) {
        printf("NNFaceRecognition init failed\r\n");
        return;
    }
    if (facerecog_ctx == NULL) {
        facerecog_ctx = mm_module_open(&facerecog_module);
    }
    if (facerecog_ctx == NULL) {
        printf("FaceRecognition module init failed\r\n");
        return;
    }
    if (facerecog_siso_ctx == NULL) {
        facerecog_siso_ctx = (void*)sisoCreate();
    }
    if (facerecog_siso_ctx == NULL) {
        printf("FaceRecognition SISO init failed\r\n");
        return;
    }

    // VIPNN MobileFaceNet configuration
    vipnn_control(_p_mmf_context->priv, CMD_VIPNN_SET_MODEL, (int)&mbfacenet_fwfs);
    vipnn_control(_p_mmf_context->priv, CMD_VIPNN_SET_CASCADE, 2);
    vipnn_control(_p_mmf_context->priv, CMD_VIPNN_SET_OUTPUT, 1);
    mm_module_ctrl(_p_mmf_context, MM_CMD_SET_DATAGROUP, MM_GROUP_END);
    mm_module_ctrl(_p_mmf_context, MM_CMD_SET_QUEUE_LEN, 1);
    mm_module_ctrl(_p_mmf_context, MM_CMD_INIT_QUEUE_ITEMS, MMQI_FLAG_STATIC);
    vipnn_control(_p_mmf_context->priv, CMD_VIPNN_APPLY, 0);

    // MMFv2 Face Recognition module configuration
    mm_module_ctrl(facerecog_ctx, CMD_FRC_SET_THRES100, 99);  // 99/100 = 0.99 --> set a value to get lowest FP rate
    mm_module_ctrl(facerecog_ctx, CMD_FRC_SET_OSD_DRAW, (int)nnFaceRecogCB);

    // SISO link VIPNN to FaceRecognition module
    sisoRegIn(facerecog_siso_ctx, _p_mmf_context);
    sisoRegOut(facerecog_siso_ctx, facerecog_ctx);
    sisoStart(facerecog_siso_ctx);
}

void NNFaceRecognition::end(void) {
    if (_p_mmf_context == NULL) {
        return;
    }
    if (mm_module_close(_p_mmf_context) == NULL) {
        _p_mmf_context = NULL;
    } else {
        CAMDBG("NNFaceRecognition deinit failed\r\n");
    }

    if (facerecog_ctx == NULL) {
        return;
    }
    if (mm_module_close(facerecog_ctx) == NULL) {
        facerecog_ctx = NULL;
    } else {
        CAMDBG("NNFaceRecognition deinit failed\r\n");
    }

    if (facerecog_siso_ctx == NULL) {
        return;
    }
    sisoDestroy(facerecog_siso_ctx);
    _p_mmf_context = NULL;
}

void NNFaceRecognition::getResult(void) {

}

void NNFaceRecognition::setResultCallback(void) {
    
}

void NNFaceRecognition::registerFace(const char* arg) {
    if (!facerecog_ctx) {
        return;
    }
    char *regName;
    regName = (char *)arg;
    mm_module_ctrl(facerecog_ctx, CMD_FRC_REGISTER_MODE, (int)regName);
}

void NNFaceRecognition::setRecognitionMode(void) {
    if (!facerecog_ctx) {
        return;
    }
    printf("enter recognition mode\n\r");
    mm_module_ctrl(facerecog_ctx, CMD_FRC_RECOGNITION_MODE, 0);
}

void NNFaceRecognition::loadRegisteredFace(void) {
    if (!facerecog_ctx) {
        return;
    }
    printf("load feature\n\r");
    mm_module_ctrl(facerecog_ctx, CMD_FRC_LOAD_FEATURES, 0);
}

void NNFaceRecognition::saveRegisteredFace(void) {
    if (!facerecog_ctx) {
        return;
    }
    printf("save feature\n\r");
    mm_module_ctrl(facerecog_ctx, CMD_FRC_SAVE_FEATURES, 0);
}

void NNFaceRecognition::resetRegisteredFace(void) {
    if (!facerecog_ctx) {
        return;
    }
    printf("reset feature\n\r");
    mm_module_ctrl(facerecog_ctx, CMD_FRC_RESET_FEATURES, 0);
}

void NNFaceRecognition::setThreshold(const char *score) {
    if (!facerecog_ctx) {
        return;
    }
    char *regThres;
    regThres = (char *)score;
    float threshold = atof(regThres);
    printf("set face recognition score threshold to %.2f\n\r", (float)threshold / 100.0);
    mm_module_ctrl(facerecog_ctx, CMD_FRC_SET_THRES100, threshold);
}