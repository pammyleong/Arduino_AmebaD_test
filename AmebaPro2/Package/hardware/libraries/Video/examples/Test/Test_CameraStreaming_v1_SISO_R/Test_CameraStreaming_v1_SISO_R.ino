#include "StreamIO.h"
#include "WiFi.h"
#include "camera.h"
#include "rtsp.h"

// Connect to GPIO pin 8 if you want to do trigger video reset
CameraClass cam;
CameraSetting camset;
RTSP rtsp;
StreamIO streamIO(1, 1);  // Single Input Single Output

// Button setting
int buttonPin = 8;
int buttonState = 0;

char ssid[] = "Aurical_5G";   // your network SSID (name)
char pass[] = "wyy170592";    // your network password
int status = WL_IDLE_STATUS;  // the Wifi radio's status

void setup() {
    Serial.begin(115200);
    Serial.println("Just setup");

    if (WiFi.status() == WL_NO_SHIELD) {
        Serial.println("WiFi shield not present");
        // don't continue:
        while (true)
            ;
    }

    // attempt to connect to Wifi network:
    while (status != WL_CONNECTED) {
        Serial.print("Attempting to connect to WPA SSID: ");
        Serial.println(ssid);
        // Connect to WPA/WPA2 network:
        status = WiFi.begin(ssid, pass);

        // wait 2 seconds for connection:
        delay(2000);
    }

    // init camera
    cam.init(camset);
    cam.open(camset);

    // init rtsp
    rtsp.init(camset);
    rtsp.open();

    // create camera io linker
    streamIO.create();
    streamIO.registerInput(cam.getIO());
    streamIO.registerOutput(rtsp.getIO());

    if (streamIO.start() != 0) {
        Serial.println("camera io link start failed");
    }

    cam.start(camset);
    Serial.println("Cam start!");
    pinMode(buttonPin, INPUT);
}

void loop() {
    buttonState = digitalRead(buttonPin);
    if (buttonState == HIGH) {
        reset();
    }
}

void reset() {
    // deinit
    streamIO.pause();
    Serial.println("Streaming pause!");

    rtsp.close();
    Serial.println("rtsp close!");
    cam.close();
    Serial.println("Cam close!");

    streamIO.destroy();

    rtsp.deinit();
    Serial.println("rtsp deinit!");
    cam.deInit();
    Serial.println("cam deinit!");

    // reinit
    delay(4000);
    Serial.println("\n");
    Serial.println("Resetting......");
    delay(10000);

    // init camera
    cam.init(camset);
    Serial.println("init cam again!");
    cam.open(camset);
    Serial.println("init rtsp again!");

    // init rtsp
    rtsp.init(camset);
    rtsp.open();

    // create camera io linker
    streamIO.create();

    streamIO.registerInput(cam.getIO());
    streamIO.registerOutput(rtsp.getIO());

    if (streamIO.start() != 0) {
        Serial.println("camera io link start failed");
    }

    cam.start(camset);
    Serial.println("Cam start again!");
};
