#include "nn_objdet_drv.h"
#include "module_video.h"
#include "module_vipnn.h"

#include "input_image_640x360x3.h"
#include "model_yolo.h"
#include "osd_render.h"

#define DEBUG           0

#if DEBUG
#define CAMDBG(fmt, args...) \
    do {printf("\r\nFunc-[%s]@Line-%d: \r\n" fmt "\r\n", __func__, __LINE__, ## args); } while (0);
#else
#define CAMDBG(fmt, args...)
#endif

uint32_t RTSPWidthOD = 0;
uint32_t RTSPHeightOD = 0;
int RTSPChannelOD = 0;

// YOLO
#define NN_MODEL_OBJ    yolov4_tiny
#define NN_WIDTH        416
#define NN_HEIGHT       416

static const char *tag[80] = {"person", "bicycle", "car", "motorbike", "aeroplane", "bus", "train", "truck", "boat", "traffic light",
							  "fire hydrant", "stop sign", "parking meter", "bench", "bird", "cat", "dog", "horse", "sheep", "cow",
							  "elephant", "bear", "zebra", "giraffe", "backpack", "umbrella", "handbag", "tie", "suitcase", "frisbee",
							  "skis", "snowboard", "sports ball", "kite", "baseball bat", "baseball glove", "skateboard", "surfboard", "tennis racket", "bottle",
							  "wine glass", "cup", "fork", "knife", "spoon", "bowl", "banana", "apple", "sandwich", "orange",
							  "broccoli", "carrot", "hot dog", "pizza", "donut", "cake", "chair", "sofa", "pottedplant", "bed",
							  "diningtable", "toilet", "tvmonitor", "laptop", "mouse", "remote", "keyboard", "cell phone", "microwave", "oven",
							  "toaster", "sink", "refrigerator", "book", "clock", "vase", "scissors", "teddy bear", "hair drier", "toothbrush"
							 };
static float nn_confidence_thresh = 0.4;
static float nn_nms_thresh = 0.3;
static int desired_class_num = 4;
static int desired_class_list[] = {0, 2, 5, 7};

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

//#define NN_CHANNEL 4
////#define NN_RESOLUTION VIDEO_VGA //don't care for NN
//#define NN_FPS 10
//#define NN_GOP NN_FPS
//#define NN_BPS 1024*1024 //don't care for NN
//#define NN_TYPE VIDEO_RGB


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

// get settings from RTSP module
void getRTSPOD (int ch, uint32_t width, uint32_t height) { 
    RTSPWidthOD = width;
    RTSPHeightOD = height;
    RTSPChannelOD = ch;
}

// check whether the selected object item number is in the list
static int check_in_list(int class_indx)
{
	for (int i = 0; i < desired_class_num; i++) {
		if (class_indx == desired_class_list[i]) {
			return class_indx;
		}
	}
	return -1;
}

// callback function to to be called to draw rect
static void nn_set_object(void *p, void *img_param)
{
	int i = 0;
	objdetect_res_t *res = (objdetect_res_t *)p;
	nn_data_param_t *im = (nn_data_param_t *)img_param;

	if (!p || !img_param)	{
		return;
	}

	int im_h = RTSPHeightOD;
	int im_w = RTSPWidthOD;

	float ratio_w = (float)im_w / (float)im->img.width;
	float ratio_h = (float)im_h / (float)im->img.height;
	int roi_h, roi_w, roi_x, roi_y;
	// ============================================
	// check whether use_roi value will be always 1 
	// ============================================
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
	canvas_clean_all(RTSPChannelOD, 0);
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
				canvas_set_rect(RTSPChannelOD, 0, xmin, ymin, xmax, ymax, 3, COLOR_WHITE);
				char text_str[20];
				snprintf(text_str, sizeof(text_str), "%s %d", tag[class_id], (int)(res->result[6 * i + 1 ] * 100));
				canvas_set_text(RTSPChannelOD, 0, xmin, ymin - 32, text_str, COLOR_CYAN);
			}
		}
	}
	canvas_update(RTSPChannelOD, 0);
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

// set NN confidence threshold
void nnSetObjDetConfThres(void *p) {
    vipnn_control(p, CMD_VIPNN_SET_CONFIDENCE_THRES, (int)&nn_confidence_thresh);
}

// set Non-maximum Suppresion (NMS) threshold
void nnObjDetNMSThres(void *p) {
    vipnn_control(p, CMD_VIPNN_SET_NMS_THRES, (int)&nn_nms_thresh);
}

// apply NN object detection object
void nnObjDetSetApply(void *p) {
    vipnn_control(p, CMD_VIPNN_APPLY, 0);
}

void OSDBeginOD(void) {
    int ch_enable[3] = {1, 0, 0};
    int char_resize_w[3] = {16, 0, 0}, char_resize_h[3] = {32, 0, 0};
    int ch_width[3] = {RTSPWidthOD, 0, 0}, ch_height[3] = {RTSPHeightOD, 0, 0};

    osd_render_dev_init(ch_enable, char_resize_w, char_resize_h);
    osd_render_task_start(ch_enable, ch_width, ch_height);
}
