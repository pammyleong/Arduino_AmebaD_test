#include "Arduboy.h"
#include "audio.h"
#include "pwmout_api.h"

const byte PROGMEM tune_pin_to_timer_PGM[] = { 3, 1 };
volatile byte *_tunes_timer1_pin_port;
volatile byte _tunes_timer1_pin_mask;
volatile int32_t timer1_toggle_count;
volatile byte *_tunes_timer3_pin_port;
volatile byte _tunes_timer3_pin_mask;
byte _tune_pins[AVAILABLE_TIMERS];
byte _tune_num_chans = 0;
volatile boolean tune_playing; // is the score still playing?
volatile unsigned wait_timer_frequency2;       /* its current frequency */
volatile boolean wait_timer_playing = false;   /* is it currently playing a note? */
volatile boolean tonePlaying = false;
volatile unsigned long wait_toggle_count;      /* countdown score waits */

// pointers to your musical score and your position in said score
volatile const byte *score_start = 0;
volatile const byte *score_cursor = 0;

TaskHandle_t score_task;

// Table of midi note frequencies * 2
//   They are times 2 for greater accuracy, yet still fits in a word.
//   Generated from Excel by =ROUND(2*440/32*(2^((x-9)/12)),0) for 0<x<128
// The lowest notes might not work, depending on the Arduino clock frequency
// Ref: http://www.phy.mtu.edu/~suits/notefreqs.html
const uint8_t PROGMEM _midi_byte_note_frequencies[48] = {
16,17,18,19,21,22,23,24,26,28,29,31,33,35,37,39,41,44,46,49,52,55,58,62,65,
69,73,78,82,87,92,98,104,110,117,123,131,139,147,156,165,175,185,196,208,220,
233,247
};
const unsigned int PROGMEM _midi_word_note_frequencies[80] = {
262,277,294,311,330,349,370,392,415,440,466,494,523,554,587,622,659,
698,740,784,831,880,932,988,1047,1109,1175,1245,1319,1397,1480,1568,1661,1760,
1865,1976,2093,2217,2349,2489,2637,2794,2960,3136,3322,3520,3729,3951,4186,
4435,4699,4978,5274,5588,5920,6272,6645,7040,7459,7902,8372,8870,9397,9956,
10548,11175,11840,12544,13290,14080,14917,15804,16744,17740,18795,19912,21096,
22351,23680,25088 };

/* AUDIO */

bool ArduboyAudio::audio_enabled = false;

void ArduboyAudio::on()
{
  audio_enabled = true;
}

bool ArduboyAudio::enabled()
{
  return audio_enabled;
}

void ArduboyAudio::off()
{
  audio_enabled = false;
}

void ArduboyAudio::saveOnOff()
{
  EEPROM.write(EEPROM_AUDIO_ON_OFF, audio_enabled);
}

void ArduboyAudio::begin()
{
  tune_playing = false;
  //if (EEPROM.read(EEPROM_AUDIO_ON_OFF))  // default to on and ignore EEPROM value
    on();
}

/* TUNES */

extern void *gpio_pin_struct[];
void ArduboyTunes::initChannel(byte pin)
{
  // we are out of timers
  if (_tune_num_chans == AVAILABLE_TIMERS)
    return;

  _tune_pins[_tune_num_chans] = pin;
  _tune_num_chans++;

  if ((g_APinDescription[pin].ulPinAttribute & PIO_PWM) != PIO_PWM) {
    return;
  }

  if (g_APinDescription[pin].ulPinType != PIO_PWM) {
    if ((g_APinDescription[pin].ulPinType == PIO_GPIO) || (g_APinDescription[pin].ulPinType == PIO_GPIO_IRQ)) {
      pinRemoveMode(pin);
    }
    gpio_pin_struct[pin] = malloc(sizeof(pwmout_t));
    pwmout_t *obj = (pwmout_t *)gpio_pin_struct[pin];
    pwmout_init(obj, (PinName)g_APinDescription[pin].pinname);
    pwmout_period(obj, 1.0);
    pwmout_pulsewidth_us(obj, 0);
    g_APinDescription[pin].ulPinType = PIO_PWM;
    g_APinDescription[pin].ulPinMode = PWM_MODE_ENABLED;
  }
}

void ArduboyTunes::playNote(byte chan, byte note)
{
  unsigned int frequency2; // frequency times 2

  // we can't play on a channel that does not exist
  if (chan >= _tune_num_chans)
    return;

  // we only have frequencies for 128 notes
  if (note > 127) {
    return;
  }

  if (note < 48) {
    frequency2 = pgm_read_byte(_midi_byte_note_frequencies + note);
  } else {
    frequency2 = pgm_read_word(_midi_word_note_frequencies + note - 48);
  }

  byte pin = _tune_pins[chan];
  pwmout_t *obj = (pwmout_t *)gpio_pin_struct[pin];
  pwmout_period(obj, 1.0/frequency2);
  pwmout_write(obj, 0.2);
}

void ArduboyTunes::stopNote(byte chan)
{
  if (chan >= _tune_num_chans)
    return;

  byte pin = _tune_pins[chan];
  pwmout_t *obj = (pwmout_t *)gpio_pin_struct[pin];
  pwmout_write(obj, 0);
}

void ArduboyTunes::playScore(const byte *score)
{
  score_start = score;
  score_cursor = score_start;
  tune_playing = true;
  xTaskCreate(step, "playScore Task", 512, NULL, tskIDLE_PRIORITY + 3, &score_task);
}

void ArduboyTunes::stopScore (void)
{
  for (uint8_t i = 0; i < _tune_num_chans; i++)
    stopNote(i);
  tune_playing = false;
  vTaskDelete(score_task);
}

bool ArduboyTunes::playing()
{
  return tune_playing;
}

// Do score commands until a "wait" is found, or the score is stopped.
// if CMD < 0x80, then the other 7 bits and the next byte are a 15-bit big-endian number of msec to wait
void ArduboyTunes::step(void* pvParameters)
{
  (void)pvParameters;
  byte command, opcode, chan;
  unsigned duration;

  while (1) {   // process commands repeatedly until a stop or delay command is received
    command = pgm_read_byte(score_cursor++);
    opcode = command & 0xf0;
    chan = command & 0x0f;
    if (opcode == TUNE_OP_STOPNOTE) { // stop note
      stopNote(chan);
    }
    else if (opcode == TUNE_OP_PLAYNOTE) { // play note
      playNote(chan, pgm_read_byte(score_cursor++));
    }
    else if (opcode == TUNE_OP_RESTART) { // restart score
      score_cursor = score_start;
    }
    else if (opcode == TUNE_OP_STOP) { // stop score
      tune_playing = false;
      vTaskDelete(NULL);
      break;
    }
    else if (opcode < 0x80) { // wait count in msec.
      duration = ((unsigned)command << 8) | (pgm_read_byte(score_cursor++));
      vTaskDelay(duration / portTICK_PERIOD_MS);
    }
  }
}

void ArduboyTunes::closeChannels(void)
{
  for (uint8_t chan=0; chan < _tune_num_chans; chan++) {
    byte pin = _tune_pins[chan];
    stopNote(chan);
    pinRemoveMode(pin);
    digitalWrite(pin, 0);
  }
  _tune_num_chans = 0;
  tune_playing = false;
}

void ArduboyTunes::soundOutput()
{
}

#ifdef __cplusplus
extern "C" {
extern void _tone(uint32_t ulPin, unsigned int frequency, unsigned long duration);
}
#endif

void ArduboyTunes::tone(unsigned int frequency, unsigned long duration)
{
  byte pin = _tune_pins[0];
  _tone(pin, frequency, duration);
}
