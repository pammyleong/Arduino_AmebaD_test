#include "core.h"

// need to redeclare these here since we declare them static in .h
volatile uint8_t *ArduboyCore::mosiport, *ArduboyCore::csport, *ArduboyCore::dcport;
uint8_t ArduboyCore::mosipinmask, ArduboyCore::cspinmask, ArduboyCore::dcpinmask;

const uint8_t pinBootProgram[] = {
  // buttons
  PIN_LEFT_BUTTON, INPUT_PULLDOWN,
  PIN_RIGHT_BUTTON, INPUT_PULLDOWN,
  PIN_UP_BUTTON, INPUT_PULLDOWN,
  PIN_DOWN_BUTTON, INPUT_PULLDOWN,
  PIN_A_BUTTON, INPUT_PULLDOWN,
  PIN_B_BUTTON, INPUT_PULLDOWN,

  // OLED SPI
  DC, OUTPUT,
  RST, OUTPUT,
  CS, OUTPUT,
  0
};

const uint8_t lcdBootProgram[] = {
  // boot defaults are commented out but left here incase they
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


ArduboyCore::ArduboyCore() {}

void ArduboyCore::boot()
{
  SPI.setDefaultFrequency(8000000);
  SPI.begin();
  bootPins();
  bootLCD();

  saveMuchPower();
}

void ArduboyCore::bootPins()
{
  uint8_t pin, mode;
  uint8_t i = 0;

  while(true) {
    pin = pinBootProgram[i++];
    mode = pinBootProgram[i++];
    if (pin==0) break;
    pinMode(pin, mode);
  }

  digitalWrite(RST, HIGH);
  delay(1);           // VDD (3.3V) goes high at start, lets just chill for a ms
  digitalWrite(RST, LOW);   // bring reset low
  delay(10);          // wait 10ms
  digitalWrite(RST, HIGH);  // bring out of reset
}

void ArduboyCore::bootLCD()
{
  LCDCommandMode();
  // run our customized boot-up command sequence against the
  // OLED to initialize it properly for Arduboy
  for (uint8_t i=0; i < sizeof(lcdBootProgram); i++) {
    SPI.transfer(lcdBootProgram[i]);
  }
  LCDDataMode();
}

void ArduboyCore::LCDDataMode()
{
  digitalWrite(DC, HIGH);
  //digitalWrite(CS, LOW);
}

void ArduboyCore::LCDCommandMode()
{
  //digitalWrite(CS, HIGH);
  digitalWrite(DC, LOW);
  //digitalWrite(CS, LOW);
}

void ArduboyCore::safeMode()
{
  blank(); // to avoid random gibberish
  while (true) {
    asm volatile("nop \n");
  }
}

/* Power Management */

void ArduboyCore::idle()
{
  // Set to do nothing for RTL8722, TODO: add in sleep mode code support
  /*/
  set_sleep_mode(SLEEP_MODE_IDLE);
  sleep_mode();
  //*/
}

void ArduboyCore::saveMuchPower()
{
  // Set to do nothing for RTL8722, TODO: add in equivalent code support
  /*/
  power_adc_disable();
  power_usart0_disable();
  power_twi_disable();
  // timer 0 is for millis()
  // timers 1 and 3 are for music and sounds
  power_timer2_disable();
  power_usart1_disable();
  // we need USB, for now (to allow triggered reboots to reprogram)
  // power_usb_disable()
  //*/
}

uint8_t ArduboyCore::width() { return WIDTH; }

uint8_t ArduboyCore::height() { return HEIGHT; }


/* Drawing */

void ArduboyCore::paint8Pixels(uint8_t pixels)
{
  SPI.transfer(pixels);
}

void ArduboyCore::paintScreen(const unsigned char *image)
{
  for (int i = 0; i < (HEIGHT*WIDTH)/8; i++)
  {
    SPI.transfer((uint8_t)(image[i]));
  }
}

// paint from a memory buffer, this should be FAST as it's likely what
// will be used by any buffer based subclass
void ArduboyCore::paintScreen(unsigned char image[])
{
  for (int i = 0; i < (HEIGHT*WIDTH)/8; i++)
  {
    SPI.transfer((uint8_t)(image[i]));
  }
}

void ArduboyCore::blank()
{
  for (int i = 0; i < (HEIGHT*WIDTH)/8; i++)
    SPI.transfer(0x00);
}

void ArduboyCore::sendLCDCommand(uint8_t command)
{
  LCDCommandMode();
  SPI.transfer(command);
  LCDDataMode();
}

// invert the display or set to normal
// when inverted, a pixel set to 0 will be on
void ArduboyCore::invert(boolean inverse)
{
  sendLCDCommand(inverse ? OLED_PIXELS_INVERTED : OLED_PIXELS_NORMAL);
}

// turn all display pixels on, ignoring buffer contents
// or set to normal buffer display
void ArduboyCore::allPixelsOn(boolean on)
{
  sendLCDCommand(on ? OLED_ALL_PIXELS_ON : OLED_PIXELS_FROM_RAM);
}

// flip the display vertically or set to normal
void ArduboyCore::flipVertical(boolean flipped)
{
  sendLCDCommand(flipped ? OLED_VERTICAL_FLIPPED : OLED_VERTICAL_NORMAL);
}

#define OLED_HORIZ_FLIPPED 0xA0 // reversed segment re-map
#define OLED_HORIZ_NORMAL 0xA1 // normal segment re-map

// flip the display horizontally or set to normal
void ArduboyCore::flipHorizontal(boolean flipped)
{
  sendLCDCommand(flipped ? OLED_HORIZ_FLIPPED : OLED_HORIZ_NORMAL);
}

/* RGB LED */

void ArduboyCore::setRGBled(uint8_t red, uint8_t green, uint8_t blue)
{
  // inversion is necessary because these are common annode LEDs
  analogWrite(RED_LED, 255 - red);
  analogWrite(GREEN_LED, 255 - green);
  analogWrite(BLUE_LED, 255 - blue);
}

/* Buttons */

uint8_t ArduboyCore::getInput()
{
  return buttonsState();
}

uint8_t ArduboyCore::buttonsState()
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
