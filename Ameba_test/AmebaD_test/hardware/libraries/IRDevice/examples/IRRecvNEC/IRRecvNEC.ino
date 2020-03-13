#include "IRDevice.h"

uint8_t adr = 0;
uint8_t cmd = 0;

void setup() {
    IR.beginNEC(8, 9, IR_MODE_RX); // configure for NEC IR protocol
}

void loop() {

    if (IR.recvNEC(adr, cmd, 1000)) {
        printf("Received %2x%2x\r\n",adr,cmd);
    } else {
        printf("Received nothing, timed out \r\n");
    }
    //IR.end();   // Call this method to stop IR device and free up the pins for other uses
}
