#include "IRDevice.h"

uint8_t adr = 0;
uint8_t cmd = 0;

void setup() {
    IR.beginNEC(8, 9, IR_MODE_TX); // configure for NEC IR protocol
}

void loop() {
    if (cmd++ >=255) {
        adr++;
    }

    IR.sendNEC(adr, cmd);
    printf("Sent %2x%2x\r\n",adr,cmd);

    //IR.end();   // Call this method to stop IR device and free up the pins for other uses
}
