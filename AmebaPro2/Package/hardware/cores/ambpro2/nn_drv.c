#include "nn_drv.h"
#include "module_video.h"
#include "module_vipnn.h"

#include "input_image_640x360x3.h"
#include "model_yolov3t.h"

#define DEBUG           0

#if DEBUG
#define CAMDBG(fmt, args...) \
    do {printf("\r\nFunc-[%s]@Line-%d: \r\n" fmt "\r\n", __func__, __LINE__, ## args); } while (0);
#else
#define CAMDBG(fmt, args...)
#endif

// NN model selction //
#define YOLO_MODEL              1
#define USE_NN_MODEL            YOLO_MODEL

#define NN_CHANNEL 4
#define NN_RESOLUTION VIDEO_VGA //don't care for NN
#define NN_FPS 10
#define NN_GOP NN_FPS
#define NN_BPS 1024*1024 //don't care for NN
#define NN_TYPE VIDEO_RGB

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

static void nn_set_object(void *p, void *img_param)
{
	// int i = 0;
	// objdetect_res_t *res = (objdetect_res_t *)p;
	// nn_data_param_t *im = (nn_data_param_t *)img_param;

	// if (!p || !img_param)	{
	// 	return;
	// }

	// int im_h = NN_WIDTH; // RTSP_HEIGHT;
	// int im_w = NN_WIDTH; // RTSP_WIDTH;

	// float ratio_h = (float)im_h / (float)im->img.height;
	// float ratio_w = (float)im_w / (float)im->img.width;
	// int roi_h = (int)((im->img.roi.ymax - im->img.roi.ymin) * ratio_h);
	// int roi_w = (int)((im->img.roi.xmax - im->img.roi.xmin) * ratio_w);
	// int roi_x = (int)(im->img.roi.xmin * ratio_w);
	// int roi_y = (int)(im->img.roi.ymin * ratio_h);

	// // float ratio_h = (float)im_h / (float)im->img.height;
	// // int roi_h = (int)((im->img.roi.ymax - im->img.roi.ymin) * ratio_h);
	// // int roi_w = (int)((im->img.roi.xmax - im->img.roi.xmin) * ratio_h);
	// // int roi_x = (int)(im->img.roi.xmin * ratio_h + (im_w - roi_w) / 2);
	// // int roi_y = (int)(im->img.roi.ymin * ratio_h);

	// printf("object num = %d\r\n", res->obj_num);
	// if (res->obj_num > 0) {
	// 	nn_object.obj_num = 0;
	// 	for (i = 0; i < res->obj_num; i++) {
	// 		int obj_class = (int)res->result[6 * i ];
	// 		if (nn_object.obj_num == OSD_OBJ_MAX_NUM) {
	// 			break;
	// 		}
	// 		//printf("obj_class = %d\r\n",obj_class);

	// 		int class_id = check_in_list(obj_class); //show class in desired_class_list
	// 		//int class_id = obj_class; //coco label
	// 		if (class_id != -1) {
	// 			int ind = nn_object.obj_num;
	// 			nn_object.rect[ind].ymin = (int)(res->result[6 * i + 3] * roi_h) + roi_y;
	// 			LIMIT(nn_object.rect[ind].ymin, 0, im_h - 1)

	// 			nn_object.rect[ind].xmin = (int)(res->result[6 * i + 2] * roi_w) + roi_x;
	// 			LIMIT(nn_object.rect[ind].xmin, 0, im_w - 1)

	// 			nn_object.rect[ind].ymax = (int)(res->result[6 * i + 5] * roi_h) + roi_y;
	// 			LIMIT(nn_object.rect[ind].ymax, 0, im_h - 1)

	// 			nn_object.rect[ind].xmax = (int)(res->result[6 * i + 4] * roi_w) + roi_x;
	// 			LIMIT(nn_object.rect[ind].xmax, 0, im_w - 1)

	// 			nn_object.class[ind] = class_id;
	// 			nn_object.score[ind] = (int)(res->result[6 * i + 1 ] * 100);
	// 			nn_object.obj_num++;
	// 			printf("%d,c%d:%d %d %d %d\n\r", i, nn_object.class[ind], nn_object.rect[ind].xmin, nn_object.rect[ind].ymin, nn_object.rect[ind].xmax,
	// 				   nn_object.rect[ind].ymax);
	// 		}
	// 	}
	// } else {
	// 	nn_object.obj_num = 0;
	// }

	// int nn_osd_ready2draw = nn_osd_get_status();
	// if (nn_osd_ready2draw == 1) {
	// 	for (i = 0; i < OSD_OBJ_MAX_NUM; i++) {
	// 		if (i < nn_object.obj_num) {
	// 			snprintf(osd_text.text_str, sizeof(osd_text.text_str), "%s %d", tag[nn_object.class[i]], nn_object.score[i]);
	// 			memcpy(&osd_rect.rect, &nn_object.rect[i], sizeof(nn_rect_t));
	// 			nn_osd_set_rect_with_text(i, RTSP_CHANNEL, &osd_text, &osd_rect);
	// 		} else {
	// 			nn_osd_clear_bitmap(i, RTSP_CHANNEL);
	// 		}
	// 		//printf("num=%d  %d, %d, %d, %d.\r\n", g_results.num, g_results.obj[i].left, g_results.obj[i].right, g_results.obj[i].top, g_results.obj[i].bottom);
	// 	}
	// 	nn_osd_update();
	// }

}

mm_context_t* NNInit(void) {
    return mm_module_open(&vipnn_module);
}

// setup NN model
void NNSetModel(void *p) {
    vipnn_control(p, CMD_VIPNN_SET_MODEL, (int)&NN_MODEL_OBJ);
}

// setup NN input parameters
void NNSetInputParam(void *p) {
    vipnn_control(p, CMD_VIPNN_SET_IN_PARAMS, (int)&roi_nn);
}

// setup NN object
void NNSetDisppost(void *p) {
    vipnn_control(p, CMD_VIPNN_SET_DISPPOST, (int)nn_set_object);
}

// 
void NNSetConfThres(void *p) {
    vipnn_control(p, CMD_VIPNN_SET_CONFIDENCE_THRES, (int)&nn_confidence_thresh);
}

void NNNMSThres(void *p) {
    vipnn_control(p, CMD_VIPNN_SET_NMS_THRES, (int)&nn_nms_thresh);
}

void NNSetApply(void *p) {
    vipnn_control(p, CMD_VIPNN_APPLY, 0);
}
