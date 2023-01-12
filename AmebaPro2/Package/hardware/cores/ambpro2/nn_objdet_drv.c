#include "nn_objdet_drv.h"
#include "module_video.h"
#include "module_vipnn.h"

#include "img_sample/input_image_640x360x3.h"
//#include "input_image_640x360x3.h"
#include "nn_utils/class_name.h"
#include "model_yolo.h"

// others (see if needed)
#include "osd_render.h"
#include "avcodec.h"
#include "hal_video.h"
#include "hal_isp.h"

#define DEBUG           0

#if DEBUG
#define CAMDBG(fmt, args...) \
    do {printf("\r\nFunc-[%s]@Line-%d: \r\n" fmt "\r\n", __func__, __LINE__, ## args); } while (0);
#else
#define CAMDBG(fmt, args...)
#endif

uint16_t OSDWidthOD = 0;
uint16_t OSDHeightOD = 0;
int OSDChannel = 0;

// YOLO
#define NN_MODEL_OBJ    yolov4_tiny
#define NN_WIDTH        576
#define NN_HEIGHT       320

static float nn_confidence_thresh = 0;
static float nn_nms_thresh = 0;
static int desired_class_list[] = {0, 2, 5, 7};

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

//void configODModel(float confidence_thres, float nms_thres) {
//    nn_confidence_thresh = confidence_thres;
//    nn_nms_thresh = nms_thres;
//}

void configODModel(float confidence_thres, float nms_thres, uint16_t nn_width, uint16_t nn_height) {
    nn_confidence_thresh = confidence_thres;
    nn_nms_thresh = nms_thres;

    roi_nn.img.width = nn_width;
    roi_nn.img.height = nn_height;
    roi_nn.img.roi.xmax = nn_width;
    roi_nn.img.roi.ymax = nn_height;
}

// Get settings from streaming channel
void configODOSD(int ch, uint16_t width, uint16_t height) {
    OSDChannel = ch;
    OSDWidthOD = width;
    OSDHeightOD = height;
}

// check whether the selected object item number is in the list
static int checkList(int class_indx) {
    for (int i = 0; i < (sizeof(desired_class_list) / sizeof(int)); i++) {
        if (class_indx == desired_class_list[i]) {
            return class_indx;
        }
    }
    return -1;
}

// callback function to to be called to draw rect
static void ODDrawObj(void *p, void *img_param) {
    int i = 0;
    objdetect_res_t *res = (objdetect_res_t *)p;
    nn_data_param_t *im = (nn_data_param_t *)img_param;

    if (!p || !img_param)	{
        return;
    }

    int im_h = OSDHeightOD;
    int im_w = OSDWidthOD;

    float ratio_w = (float)im_w / (float)im->img.width;
    float ratio_h = (float)im_h / (float)im->img.height;
    int roi_h, roi_w, roi_x, roi_y;

// if (video_params_v4.use_roi == 1) { //resize
    roi_w = (int)((im->img.roi.xmax - im->img.roi.xmin) * ratio_w);
    roi_h = (int)((im->img.roi.ymax - im->img.roi.ymin) * ratio_h);
    roi_x = (int)(im->img.roi.xmin * ratio_w);
    roi_y = (int)(im->img.roi.ymin * ratio_h);
//	} else {  //crop
//		float ratio = ratio_h < ratio_w ? ratio_h : ratio_w;
//		roi_w = (int)((im->img.roi.xmax - im->img.roi.xmin) * ratio);
//		roi_h = (int)((im->img.roi.ymax - im->img.roi.ymin) * ratio);
//		roi_x = (int)(im->img.roi.xmin * ratio + (im_w - roi_w) / 2);
//		roi_y = (int)(im->img.roi.ymin * ratio + (im_h - roi_h) / 2);
//	}

    printf("object num = %d\r\n", res->obj_num);
    canvas_clean_all(OSDChannel, 0);
    if (res->obj_num > 0) {
        for (i = 0; i < res->obj_num; i++) {
            int obj_class = (int)res->result[6 * i ];
            int class_id = checkList(obj_class); //show class in desired_class_list
            //int class_id = obj_class; //coco label
            if (class_id != -1) {
                int xmin = (int)(res->result[6 * i + 2] * roi_w) + roi_x;
                int ymin = (int)(res->result[6 * i + 3] * roi_h) + roi_y;
                int xmax = (int)(res->result[6 * i + 4] * roi_w) + roi_x;
                int ymax = (int)(res->result[6 * i + 5] * roi_h) + roi_y;
                LIMIT(xmin, 0, im_w)
                LIMIT(xmax, 0, im_w)
                LIMIT(ymin, 0, im_h)
                LIMIT(ymax, 0, im_h)
                printf("%d,c%d:%d %d %d %d\n\r", i, class_id, xmin, ymin, xmax, ymax);
                canvas_set_rect(OSDChannel, 0, xmin, ymin, xmax, ymax, 3, COLOR_WHITE);
                char text_str[20];
                snprintf(text_str, sizeof(text_str), "%s %d", coco_name_get_by_id(class_id), (int)(res->result[6 * i + 1 ] * 100));
                canvas_set_text(OSDChannel, 0, xmin, ymin - 32, text_str, COLOR_CYAN);
            }
        }
    }
    canvas_update(OSDChannel, 0);
}

mm_context_t* nnODInit(void) {
    return mm_module_open(&vipnn_module);
}

// setup NN model
void nnSetODModel(void *p) {
    vipnn_control(p, CMD_VIPNN_SET_MODEL, (int)&NN_MODEL_OBJ);
}

// setup NN input parameters
void nnSetInputODParams(void *p) {
    vipnn_control(p, CMD_VIPNN_SET_IN_PARAMS, (int)&roi_nn);
}

// setup NN object
void nnSetODDisppost(void *p) {
    vipnn_control(p, CMD_VIPNN_SET_DISPPOST, (int)ODDrawObj);
}

// set NN confidence threshold
void nnSetODConfThres(void *p) {
    vipnn_control(p, CMD_VIPNN_SET_CONFIDENCE_THRES, (int)&nn_confidence_thresh);
}

// set Non-maximum Suppresion (NMS) threshold
void nnODNMSThres(void *p) {
    vipnn_control(p, CMD_VIPNN_SET_NMS_THRES, (int)&nn_nms_thresh);
}

// apply NN object detection object
void nnODSetApply(void *p) {
    vipnn_control(p, CMD_VIPNN_APPLY, 0);
}

void ODOSD(void) {
    int ch_enable[3] = {1, 0, 0};
    int char_resize_w[3] = {16, 0, 0}, char_resize_h[3] = {32, 0, 0};
    int ch_width[3] = {OSDWidthOD, 0, 0}, ch_height[3] = {OSDHeightOD, 0, 0};

    osd_render_dev_init(ch_enable, char_resize_w, char_resize_h);
    osd_render_task_start(ch_enable, ch_width, ch_height);
}
