/**
 * @file Arduboy2Core.cpp
 * \brief
 * The Arduboy2Core class for Arduboy hardware initilization and control.
 */

#include "Arduboy2Core.h"

//========================================
//========== class Arduboy2Core ==========
//========================================

// Commands sent to the OLED display to initialize it
const PROGMEM uint8_t Arduboy2Core::lcdBootProgram[] = {
  // boot defaults are commented out but left here in case they
  // might prove useful for reference
  //
  // Further reading: https://www.adafruit.com/datasheets/SSD1306.pdf
  //
  // Display Off
  // 0xAE,

  // Set Display Clock Divisor v = 0xF0
  // default is 0x80
  0xD5, 0xF0,

  // Set Multiplex Ratio v = 0x3F
  // 0xA8, 0x3F,

  // Set Display Offset v = 0
  // 0xD3, 0x00,

  // Set Start Line (0)
  // 0x40,

  // Charge Pump Setting v = enable (0x14)
  // default is disabled
  0x8D, 0x14,

  // Set Segment Re-map (A0) | (b0001)
  // default is (b0000)
  0xA1,

  // Set COM Output Scan Direction
  0xC8,

  // Set COM Pins v
  // 0xDA, 0x12,

  // Set Contrast v = 0xCF
  0x81, 0xCF,

  // Set Precharge = 0xF1
  0xD9, 0xF1,

  // Set VCom Detect
  // 0xDB, 0x40,

  // Entire Display ON
  // 0xA4,

  // Set normal/inverse display
  // 0xA6,

  // Display On
  0xAF,

  // set display mode = horizontal addressing mode (0x00)
  0x20, 0x00,

  // set col address range
  // 0x21, 0x00, COLUMN_ADDRESS_END,

  // set page address range
  // 0x22, 0x00, PAGE_ADDRESS_END
};

void Arduboy2Core::boot()
{
  bootPins();
  bootSPI();
  bootOLED();
  bootPowerSaving();
}

void Arduboy2Core::setCPUSpeed8MHz()
{
}

// Pins are set to the proper modes and levels for the specific hardware.
// This routine must be modified if any pins are moved to a different port
void Arduboy2Core::bootPins()
{
    pinMode(PIN_LEFT_BUTTON, INPUT_PULLDOWN);
    pinMode(PIN_RIGHT_BUTTON, INPUT_PULLDOWN);
    pinMode(PIN_UP_BUTTON, INPUT_PULLDOWN);
    pinMode(PIN_DOWN_BUTTON, INPUT_PULLDOWN);
    pinMode(PIN_A_BUTTON, INPUT_PULLDOWN);
    pinMode(PIN_B_BUTTON, INPUT_PULLDOWN);

    pinMode(PIN_DC, OUTPUT);
    pinMode(PIN_CS, OUTPUT);
    pinMode(PIN_RST, OUTPUT);

    pinMode(RED_LED, OUTPUT);
    pinMode(GREEN_LED, OUTPUT);
    pinMode(BLUE_LED, OUTPUT);
    digitalWrite(RED_LED, RGB_OFF);
    digitalWrite(GREEN_LED, RGB_OFF);
    digitalWrite(BLUE_LED, RGB_OFF);
}

void Arduboy2Core::bootOLED()
{
  // reset the display
  digitalWrite(PIN_RST, HIGH);
  delayShort(1);           // VDD (3.3V) goes high at start, lets just chill for a ms
  digitalWrite(PIN_RST, LOW);   // bring reset low
  delayShort(10);          // wait 10ms
  digitalWrite(PIN_RST, HIGH);  // bring out of reset

  // run our customized boot-up command sequence against the
  // OLED to initialize it properly for Arduboy
  LCDCommandMode();
  for (uint8_t i = 0; i < sizeof(lcdBootProgram); i++) {
    SPItransfer(pgm_read_byte(lcdBootProgram + i));
  }
  LCDDataMode();
}

void Arduboy2Core::LCDDataMode()
{
  digitalWrite(PIN_DC, HIGH);
}

void Arduboy2Core::LCDCommandMode()
{
  digitalWrite(PIN_DC, LOW);
}

// Initialize the SPI interface for the display
void Arduboy2Core::bootSPI()
{
  SPI.setDefaultFrequency(8000000);
  SPI.begin();
}

// Write to the SPI bus (MOSI pin)
void Arduboy2Core::SPItransfer(uint8_t data)
{
  SPI.transfer(data);
}

// Write to and read from the SPI bus (out to MOSI pin, in from MISO pin)
uint8_t Arduboy2Core::SPItransferAndRead(uint8_t data)
{
  SPItransfer(data);
  return 0;
}

void Arduboy2Core::safeMode()
{
  if (buttonsState() == UP_BUTTON)
  {
    digitalWriteRGB(RED_LED, RGB_ON);
    while (true) { }
  }
}


/* Power Management */

void Arduboy2Core::idle()
{
}

void Arduboy2Core::bootPowerSaving()
{
}

// Shut down the display
void Arduboy2Core::displayOff()
{
  LCDCommandMode();
  SPItransfer(0xAE); // display off
  SPItransfer(0x8D); // charge pump:
  SPItransfer(0x10); //   disable
  delayShort(250);
  digitalWrite(PIN_RST, LOW);   // bring reset low
}

// Restart the display after a displayOff()
void Arduboy2Core::displayOn()
{
  bootOLED();
}


/* Drawing */

void Arduboy2Core::paint8Pixels(uint8_t pixels)
{
  SPItransfer(pixels);
}

void Arduboy2Core::paintScreen(const uint8_t *image)
{
  for (int i = 0; i < (HEIGHT*WIDTH)/8; i++)
  {
    SPItransfer(pgm_read_byte(image + i));
  }
}

// paint from a memory buffer, this should be FAST as it's likely what
// will be used by any buffer based subclass
//
// The following assembly code runs "open loop". It relies on instruction
// execution times to allow time for each byte of data to be clocked out.
// It is specifically tuned for a 16MHz CPU clock and SPI clocking at 8MHz.
void Arduboy2Core::paintScreen(uint8_t image[], bool clear)
{
  for (int i = 0; i < (HEIGHT*WIDTH)/8; i++) {
    if (clear) {
        image[i] = 0;
        SPI.transfer(0);
    } else {
        SPI.transfer(image[i]);
    }
  }
}

void Arduboy2Core::blank()
{
  for (int i = 0; i < (HEIGHT*WIDTH)/8; i++)
    SPItransfer(0x00);
}

void Arduboy2Core::sendLCDCommand(uint8_t command)
{
  LCDCommandMode();
  SPItransfer(command);
  LCDDataMode();
}

// invert the display or set to normal
// when inverted, a pixel set to 0 will be on
void Arduboy2Core::invert(bool inverse)
{
  sendLCDCommand(inverse ? OLED_PIXELS_INVERTED : OLED_PIXELS_NORMAL);
}

// turn all display pixels on, ignoring buffer contents
// or set to normal buffer display
void Arduboy2Core::allPixelsOn(bool on)
{
  sendLCDCommand(on ? OLED_ALL_PIXELS_ON : OLED_PIXELS_FROM_RAM);
}

// flip the display vertically or set to normal
void Arduboy2Core::flipVertical(bool flipped)
{
  sendLCDCommand(flipped ? OLED_VERTICAL_FLIPPED : OLED_VERTICAL_NORMAL);
}

// flip the display horizontally or set to normal
void Arduboy2Core::flipHorizontal(bool flipped)
{
  sendLCDCommand(flipped ? OLED_HORIZ_FLIPPED : OLED_HORIZ_NORMAL);
}

/* RGB LED */

void Arduboy2Core::setRGBled(uint8_t red, uint8_t green, uint8_t blue)
{
  // inversion is necessary because these are common annode LEDs
  analogWrite(RED_LED, 255 - red);
  analogWrite(GREEN_LED, 255 - green);
  analogWrite(BLUE_LED, 255 - blue);
}

void Arduboy2Core::setRGBled(uint8_t color, uint8_t val)
{
  if (color == RED_LED)
  {
    analogWrite(RED_LED, 255 - val);
  }
  else if (color == GREEN_LED)
  {
    analogWrite(GREEN_LED, 255 - val);
  }
  else if (color == BLUE_LED)
  {
    analogWrite(BLUE_LED, 255 - val);
  }
}

void Arduboy2Core::freeRGBled()
{
}

void Arduboy2Core::digitalWriteRGB(uint8_t red, uint8_t green, uint8_t blue)
{
    digitalWrite(RED_LED, red);
    digitalWrite(GREEN_LED, green);
    digitalWrite(BLUE_LED, blue);
}

void Arduboy2Core::digitalWriteRGB(uint8_t color, uint8_t val)
{
  if (color == RED_LED)
  {
    digitalWrite(RED_LED, val);
  }
  else if (color == GREEN_LED)
  {
    digitalWrite(GREEN_LED, val);
  }
  else if (color == BLUE_LED)
  {
    digitalWrite(BLUE_LED, val);
  }
}

/* Buttons */

uint8_t Arduboy2Core::buttonsState()
{
  uint8_t buttons = 0;

  if (digitalRead(PIN_LEFT_BUTTON)==1) { buttons |= LEFT_BUTTON; }
  if (digitalRead(PIN_RIGHT_BUTTON)==1) { buttons |= RIGHT_BUTTON; }
  if (digitalRead(PIN_UP_BUTTON)==1) { buttons |= UP_BUTTON; }
  if (digitalRead(PIN_DOWN_BUTTON)==1) { buttons |= DOWN_BUTTON; }
  if (digitalRead(PIN_A_BUTTON)==1) { buttons |= A_BUTTON; }
  if (digitalRead(PIN_B_BUTTON)==1) { buttons |= B_BUTTON; }

  return buttons;
}

unsigned long Arduboy2Core::generateRandomSeed()
{
  unsigned long seed;

  seed = ((unsigned long)analogRead(RAND_SEED_IN) << 16) + micros();

  return seed;
}

// delay in ms with 16 bit duration
void Arduboy2Core::delayShort(uint16_t ms)
{
  delay((unsigned long) ms);
}

void Arduboy2Core::exitToBootloader()
{
}


//=========================================
//========== class Arduboy2NoUSB ==========
//=========================================

void Arduboy2NoUSB::mainNoUSB()
{
}

