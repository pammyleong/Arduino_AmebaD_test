/**
 *  This function describes how to use the Realtek Camera API.
 *  ISP channel : 0
 *  Video type  : H264/HEVC
 *  Sensor      : SENSOR_JXF37
*/
#include "camera.h"

/* Create an camera object */
Camera cam;

void setup() {
    Serial.begin(115200);
    cam.Init();  // put inside CAMIO.register
}

void loop() {
    cam.Open();
    cam.Close();

    cam.DeInit(); // put inside CAMIO.deinit
}
