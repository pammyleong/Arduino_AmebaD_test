#include "nn_objdet_drv.h"
#include "module_video.h"
#include "module_vipnn.h"

#include "input_image_640x360x3.h"
#include "model_yolov3t.h"
#include "osd_render.h"

#define DEBUG           0

#if DEBUG
#define CAMDBG(fmt, args...) \
    do {printf("\r\nFunc-[%s]@Line-%d: \r\n" fmt "\r\n", __func__, __LINE__, ## args); } while (0);
#else
#define CAMDBG(fmt, args...)
#endif

#define RTSP_HEIGHT 1920
#define RTSP_WIDTH 1080
#define RTSP_CHANNEL 0

#define LIMIT(x, lower, upper) if(x<lower) x=lower; else if(x>upper) x=upper;

// NN model selction //
#define YOLO_MODEL              1
#define USE_NN_MODEL            YOLO_MODEL

//#define NN_CHANNEL 4
////#define NN_RESOLUTION VIDEO_VGA //don't care for NN
//#define NN_FPS 10
//#define NN_GOP NN_FPS
//#define NN_BPS 1024*1024 //don't care for NN
//#define NN_TYPE VIDEO_RGB

#if (USE_NN_MODEL==YOLO_MODEL)
#define NN_MODEL_OBJ   yolov3_tiny_fwfs
#define NN_WIDTH	416
#define NN_HEIGHT	416
static float nn_confidence_thresh = 0.4;
static float nn_nms_thresh = 0.3;
static int desired_class_num = 4;
static int desired_class_list[] = {0, 2, 5, 7};
static const char *tag[80] = {"person", "bicycle", "car", "motorbike", "aeroplane", "bus", "train", "truck", "boat", "traffic light",
							  "fire hydrant", "stop sign", "parking meter", "bench", "bird", "cat", "dog", "horse", "sheep", "cow",
							  "elephant", "bear", "zebra", "giraffe", "backpack", "umbrella", "handbag", "tie", "suitcase", "frisbee",
							  "skis", "snowboard", "sports ball", "kite", "baseball bat", "baseball glove", "skateboard", "surfboard", "tennis racket", "bottle",
							  "wine glass", "cup", "fork", "knife", "spoon", "bowl", "banana", "apple", "sandwich", "orange",
							  "broccoli", "carrot", "hot dog", "pizza", "donut", "cake", "chair", "sofa", "pottedplant", "bed",
							  "diningtable", "toilet", "tvmonitor", "laptop", "mouse", "remote", "keyboard", "cell phone", "microwave", "oven",
							  "toaster", "sink", "refrigerator", "book", "clock", "vase", "scissors", "teddy bear", "hair drier", "toothbrush"
							 };
#else
#error Please set model correctly. (YOLO_MODEL)
#endif

//static video_params_t video_params_v4 = {
//	.stream_id 		= NN_CHANNEL,
//	.type 			= NN_TYPE,
//	.resolution	 	= NN_RESOLUTION,
//	.width 			= NN_WIDTH,
//	.height 		= NN_HEIGHT,
//	.bps 			= NN_BPS,
//	.fps 			= NN_FPS,
//	.gop 			= NN_GOP,
//	.direct_output 	= 0,
//	.use_static_addr = 1,
//	.use_roi = 1,
//	.roi = {
//		.xmin = 0,
//		.ymin = 0,
//		.xmax = SENSOR_MAX_WIDTH,
//		.ymax = SENSOR_MAX_HEIGHT,
//	}
//};

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

#define V1_ENA 1
#define V4_ENA 1
#define V4_SIM 0

static int check_in_list(int class_indx)
{
	for (int i = 0; i < desired_class_num; i++) {
		if (class_indx == desired_class_list[i]) {
			return class_indx;
		}
	}
	return -1;
}

static void nn_set_object(void *p, void *img_param)
{
	int i = 0;
	objdetect_res_t *res = (objdetect_res_t *)p;
	nn_data_param_t *im = (nn_data_param_t *)img_param;

	if (!p || !img_param)	{
		return;
	}

	int im_h = RTSP_HEIGHT;
	int im_w = RTSP_WIDTH;

	float ratio_w = (float)im_w / (float)im->img.width;
	float ratio_h = (float)im_h / (float)im->img.height;
	int roi_h, roi_w, roi_x, roi_y;
//	if (video_params_v4.use_roi == 1) { //resize
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
	canvas_clean_all(RTSP_CHANNEL, 0);
	if (res->obj_num > 0) {
		for (i = 0; i < res->obj_num; i++) {
			int obj_class = (int)res->result[6 * i ];
			int class_id = check_in_list(obj_class); //show class in desired_class_list
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
				canvas_set_rect(RTSP_CHANNEL, 0, xmin, ymin, xmax, ymax, 3, COLOR_WHITE);
				char text_str[20];
				snprintf(text_str, sizeof(text_str), "%s %d", tag[class_id], (int)(res->result[6 * i + 1 ] * 100));
				canvas_set_text(RTSP_CHANNEL, 0, xmin, ymin - 32, text_str, COLOR_CYAN);
			}
		}
	}
	canvas_update(RTSP_CHANNEL, 0);
}

mm_context_t* nnObjDetInit(void) {
    return mm_module_open(&vipnn_module);
}

// setup NN model
void nnSetObjDetModel(void *p) {
    vipnn_control(p, CMD_VIPNN_SET_MODEL, (int)&NN_MODEL_OBJ);
}

// setup NN input parameters
void nnSetInputObjDetParam(void *p) {
    vipnn_control(p, CMD_VIPNN_SET_IN_PARAMS, (int)&roi_nn);
}

// setup NN object
void nnSetObjDetDisppost(void *p) {
    vipnn_control(p, CMD_VIPNN_SET_DISPPOST, (int)nn_set_object);
}


void nnSetObjDetConfThres(void *p) {
    vipnn_control(p, CMD_VIPNN_SET_CONFIDENCE_THRES, (int)&nn_confidence_thresh);
}

void nnObjDetNMSThres(void *p) {
    vipnn_control(p, CMD_VIPNN_SET_NMS_THRES, (int)&nn_nms_thresh);
}

void nnObjDetSetApply(void *p) {
    vipnn_control(p, CMD_VIPNN_APPLY, 0);
}
