/**
 * @file Arduboy2Beep.cpp
 * \brief
 * Classes to generate simple square wave tones on the Arduboy speaker pins.
 */

#include <Arduino.h>
#include "Arduboy2Beep.h"

#ifdef __cplusplus
extern "C" {
extern void _tone(uint32_t ulPin, unsigned int frequency, unsigned long duration);
extern void noTone(uint32_t ulPin);
}
#endif

// Speaker pin 1, Timer 3A, Port C bit 6, Arduino pin 5

uint8_t BeepPin1::duration = 0;

void BeepPin1::begin()
{
  digitalWrite(PIN_SPEAKER_1, 0);
}

void BeepPin1::tone(uint16_t count)
{
  tone(count, 0);
}

void BeepPin1::tone(uint16_t count, uint8_t dur)
{
  duration = dur;
  _tone(PIN_SPEAKER_1, count, 0);
}

void BeepPin1::timer()
{
  if (duration && (--duration == 0)) {
    ::noTone(PIN_SPEAKER_1);
  }
}

void BeepPin1::noTone()
{
  duration = 0;
  ::noTone(PIN_SPEAKER_1);
}


// Speaker pin 2, Timer 4A, Port C bit 7, Arduino pin 13

uint8_t BeepPin2::duration = 0;

void BeepPin2::begin()
{
  digitalWrite(PIN_SPEAKER_2, 0);
}

void BeepPin2::tone(uint16_t count)
{
  tone(count, 0);
}

void BeepPin2::tone(uint16_t count, uint8_t dur)
{
  duration = dur;
  _tone(PIN_SPEAKER_2, count, 0);
}

void BeepPin2::timer()
{
  if (duration && (--duration == 0)) {
    ::noTone(PIN_SPEAKER_2);
  }
}

void BeepPin2::noTone()
{
  duration = 0;
  ::noTone(PIN_SPEAKER_2);
}

