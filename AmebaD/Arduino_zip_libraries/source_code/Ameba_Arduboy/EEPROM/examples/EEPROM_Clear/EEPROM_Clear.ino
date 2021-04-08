/*
   EEPROM Clear
   Sets all of the bytes of the EEPROM to 0.
*/

#include <EEPROM.h>

void setup() {
  EEPROM.begin();
  // write a 0 to all bytes of the EEPROM
  for (int i = 0; i < EEPROM_DEFAULT_SIZE; i++) {
    EEPROM.write(i, 0);
  }

  EEPROM.end();
}

void loop() {
	//Do Nothing
	delay(1000);
}