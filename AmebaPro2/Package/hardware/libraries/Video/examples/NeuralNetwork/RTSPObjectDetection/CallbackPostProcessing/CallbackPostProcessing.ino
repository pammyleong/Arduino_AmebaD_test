// Demo for object detection
#include "WiFi.h"
#include "StreamIO.h"
#include "VideoStream.h"
#include "RTSP.h"
#include "NNObjectDetection.h"
#include "VideoStreamOverlay.h"
#include "ObjectClassList.h"

// Default preset configurations for each video channel:
// Channel 0 : 1920 x 1080 30FPS H264
// Channel 1 : 1280 x 720  30FPS H264
// Channel 2 : 1920 x 1080 30FPS MJPEG
#define CHANNEL 0
#define CHANNELNN 3 

// Set confidence threshold and NMS threshold here.
#define CONF_THRES 0.5
#define NMS_THRES 0.3

// Customised resolution for NN
#define NNWIDTH 576
#define NNHEIGHT 320

//OSD text size
#define OSDTEXTWIDTH 16
#define OSDTEXTHEIGHT 32

#define LIMIT(x, lower, upper) if(x<lower) x=lower; else if(x>upper) x=upper;

VideoSetting config(VIDEO_FHD, 30, VIDEO_H264, 0);
VideoSetting configNN(NNWIDTH, NNHEIGHT, 10, VIDEO_RGB, 0);
NNObjectDetection ObjDet;
RTSP rtsp;
StreamIO videoStreamer(1, 1);  // 1 Input Video -> 1 Output RTSP
StreamIO videoStreamerNN(1, 1);  // 1 Input Video RGB -> 1 Output NN

char ssid[] = "Aurical_5G";     //  your network SSID (name)
char pass[] = "wyy170592";  	// your network password
int status = WL_IDLE_STATUS;    // the Wifi radio's status

void setup() {
    Serial.begin(115200);
    
    // attempt to connect to Wifi network:
    while (status != WL_CONNECTED) {
        Serial.print("Attempting to connect to WPA SSID: ");
        Serial.println(ssid);
        // Connect to WPA/WPA2 network:
        status = WiFi.begin(ssid, pass);

        // wait 2 seconds for connection:
        delay(2000);
    }

    // Configure camera video channels with video format information
    Camera.configVideoChannel(CHANNEL, config);
    Camera.configVideoChannel(CHANNELNN, configNN);
    Camera.videoInit();

    // Configure RTSP with identical video format information
    rtsp.configVideo(config);
    rtsp.begin();

    // Configure video channel for NN with video format information 
    ObjDet.configVideo(configNN);
    ObjDet.configThreshold(CONF_THRES, NMS_THRES);
    ObjDet.setCallback(ODPostProcess);
    ObjDet.begin();
    
    // Configure StreamIO object to stream data from video channel to RTSP
    videoStreamer.registerInput(Camera.getStream(CHANNEL));
    videoStreamer.registerOutput(rtsp);
    if (videoStreamer.begin() != 0) {
        Serial.println("StreamIO link start failed");
    }

    // Start data stream from video channel
    Camera.channelBegin(CHANNEL); // Start CH0/1/2 for Streaming

    // Configure StreamIO object to stream data from RGB video channel to object detection
    videoStreamerNN.registerInput(Camera.getStream(CHANNELNN));
    videoStreamerNN.setStackSize();
    videoStreamerNN.setTaskPriority();
    videoStreamerNN.registerOutput(ObjDet);
    if (videoStreamerNN.begin() != 0) {
        Serial.println("StreamIO link start failed");
    }

    // Start video channel for NN
    Camera.channelBegin(CHANNELNN);

    // OSD
    // OSD is not supported on CH3.
    OSD.configVideo(CHANNEL, config);
    OSD.configTextSize(CHANNEL, OSDTEXTWIDTH, OSDTEXTHEIGHT);
    OSD.begin();
}

void loop() {
    // Do nothing
}

// UserCB Function
void ODPostProcess(objdetect_res_t *od_res) {
    int class_id;

    uint16_t im_h = config.height();
    uint16_t im_w = config.width();
    uint16_t nn_h = configNN.height();
    uint16_t nn_w = configNN.width();

    float ratio_w = (float)im_w / (float)nn_w;
    float ratio_h = (float)im_h / (float)nn_h;

    int roi_w = (int)((nn_w - 0) * ratio_w);
    int roi_h = (int)((nn_h - 0) * ratio_h);
    int roi_x = (int)(0 * ratio_w);
    int roi_y = (int)(0 * ratio_h);

    printf("Total number of obj detected = %d\r\n", od_res->obj_num);
    OSD.clearAll(CHANNEL, 0);

    if (od_res->obj_num > 0) {
        for (int i = 0; i < od_res->obj_num; i++) {
            int obj_class = (int)od_res->result[6 * i];
            if (obj_class == itemList[obj_class].index) {
                if (itemList[obj_class].filter == 1) {
                    class_id = itemList[obj_class].index;
                } else {
                    class_id = -1;
                }
            }
            if (class_id != -1) {
                int xmin = (int)(od_res->result[6 * i + 2] * roi_w) + roi_x;
                int ymin = (int)(od_res->result[6 * i + 3] * roi_h) + roi_y;
                int xmax = (int)(od_res->result[6 * i + 4] * roi_w) + roi_x;
                int ymax = (int)(od_res->result[6 * i + 5] * roi_h) + roi_y;

                LIMIT(xmin, 0, im_w)
                LIMIT(xmax, 0, im_w)
                LIMIT(ymin, 0, im_h)
                LIMIT(ymax, 0, im_h)

                printf("%d,c%d:%d %d %d %d\n\r", i, class_id, xmin, ymin, xmax, ymax);
                OSD.drawRect(CHANNEL, 0, xmin, ymin, xmax, ymax, 3, OSD_COLOR_WHITE);
                
                char text_str[20];
                snprintf(text_str, sizeof(text_str), "%s %d", itemList[class_id].objectName, (int)(od_res->result[6 * i + 1] * 100));
                OSD.drawText(CHANNEL, 0, xmin, ymin - 32, text_str, OSD_COLOR_CYAN);
            }
        }
    }
    OSD.update(CHANNEL, 0);
}
