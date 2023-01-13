#include "nn_facedet_drv.h"
#include "module_video.h"
#include "module_vipnn.h"
#include "roi_delta_qp/roi_delta_qp.h"
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

uint32_t RTSPWidth = 0;
uint32_t RTSPHeight = 0;
uint32_t NNWidth = 0;
uint32_t NNHeight = 0;
int RTSPChannel = 0;

static nn_data_param_t roi_nn = {
	.img = {
		.width = 0,
		.height = 0,
		.rgb = 0, // set to 1 if want RGB->BGR or BGR->RGB
		.roi = {
			.xmin = 0,
			.ymin = 0,
			.xmax = 0,
			.ymax = 0,
		}
	}
};

#define LIMIT(x, lower, upper) if(x<lower) x=lower; else if(x>upper) x=upper;

static void faceDrawObj(void *p, void *img_param) {
    int i = 0;
    facedetect_res_t *face_res = (facedetect_res_t *)p;
    nn_data_param_t *im = (nn_data_param_t *)img_param;

    if (!p || !img_param)	{
    	return;
    }

    int im_h = RTSPHeight;
    int im_w = RTSPWidth;

    //crop
    float ratio_w = (float)im_w / (float)im->img.width;
    float ratio_h = (float)im_h / (float)im->img.height;
    float ratio = ratio_h < ratio_w ? ratio_h : ratio_w;
    int roi_w = (int)((im->img.roi.xmax - im->img.roi.xmin) * ratio);
    int roi_h = (int)((im->img.roi.ymax - im->img.roi.ymin) * ratio);
    int roi_x = (int)(im->img.roi.xmin * ratio + (im_w - roi_w) / 2);
    int roi_y = (int)(im->img.roi.ymin * ratio + (im_h - roi_h) / 2);

    roi_delta_qp_set_param(RTSPChannel, 0, 0, RTSPWidth, RTSPHeight, ROI_DELTA_QP_MAX);

    printf("object num = %d\r\n", face_res->obj_num);
    canvas_clean_all(RTSPChannel, 0);
    if (face_res->obj_num > 0) {
        for (i = 0; i < face_res->obj_num; i++) {
            int obj_class = (int)face_res->result[6 * i ];
            int class_id = obj_class;
            if (class_id != -1) {
                int xmin = (int)(face_res->result[6 * i + 2] * roi_w) + roi_x;
                int ymin = (int)(face_res->result[6 * i + 3] * roi_h) + roi_y;
                int xmax = (int)(face_res->result[6 * i + 4] * roi_w) + roi_x;
                int ymax = (int)(face_res->result[6 * i + 5] * roi_h) + roi_y;
                LIMIT(xmin, 0, im_w)
                LIMIT(xmax, 0, im_w)
                LIMIT(ymin, 0, im_h)
                LIMIT(ymax, 0, im_h)
                printf("%d,c%d:%d %d %d %d\n\r", i, class_id, xmin, ymin, xmax, ymax);
                canvas_set_rect(RTSPChannel, 0, xmin, ymin, xmax, ymax, 3, COLOR_WHITE);
                char text_str[20];
                snprintf(text_str, sizeof(text_str), "%s %d", "face", (int)(face_res->result[6 * i + 1 ] * 100));
                canvas_set_text(RTSPChannel, 0, xmin, ymin - 32, text_str, COLOR_CYAN);

                roi_delta_qp_set_param(RTSPChannel, xmin, ymin, (xmax - xmin), (ymax - ymin), ROI_DELTA_QP_DEFAULT);

                for (int j = 0; j < 5; j++) {
                    int x = (int)(face_res->landmark[i].pos[j].x * roi_w) + roi_x;
                    int y = (int)(face_res->landmark[i].pos[j].y * roi_h) + roi_y;
                    canvas_set_point(RTSPChannel, 0, x, y, 8, COLOR_RED);
                }
            }
        }
    }
    canvas_update(RTSPChannel, 0);
}

// get settings from RTSP module
void configFDOSD(int ch, uint16_t width, uint16_t height) { 
    RTSPWidth = width;
    RTSPHeight = height;
    RTSPChannel = ch;
}

void configFD(uint16_t NN_width, uint16_t NN_height) {
    roi_nn.img.width = NN_width;
    roi_nn.img.height = NN_height;
    roi_nn.img.roi.xmax = NN_width;
    roi_nn.img.roi.ymax = NN_height;
}

mm_context_t* nnFDInit(void) {
    return mm_module_open(&vipnn_module);
}

// setup NN model: Facedet
void nnSetFDModel(void *p) {
    vipnn_control(p, CMD_VIPNN_SET_MODEL, (int)&scrfd_fwfs);
}

// setup NN model: Facenet
void nnSetFNModel(void *p) {
    vipnn_control(p, CMD_VIPNN_SET_MODEL, (int)&mbfacenet_fwfs);
}

// setup NN input parameters
void nnSetFDInputParam(void *p) {
    vipnn_control(p, CMD_VIPNN_SET_IN_PARAMS, (int)&roi_nn);
}

// setup NN object
void nnSetFDDisppost(void *p) {
    vipnn_control(p, CMD_VIPNN_SET_DISPPOST, (int)faceDrawObj);
}

// apply NN face detection object
void nnFDSetApply(void *p) {
    vipnn_control(p, CMD_VIPNN_APPLY, 0);
}

// set NN module as output of a linker module
void nnSetFDOutput(void *p) {
    vipnn_control(p, CMD_VIPNN_SET_OUTPUT, 1);
}

// set NN module as data group input or output
void nnSetFDDatagroup(mm_context_t *ctx, int status) {
    mm_module_ctrl(ctx, MM_CMD_SET_DATAGROUP, status);
}

// set NN model to cascade mode
void nnSetFDCascade(void *p) {
    vipnn_control(p, CMD_VIPNN_SET_CASCADE, 2);
}
