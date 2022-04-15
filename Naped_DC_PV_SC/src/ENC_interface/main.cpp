#include "../include/uart.h"
#include "../include/encoder.h"
#include <RotaryEncoder.h>
#include <stdint.h>

#define ENC_PIN1 7
#define ENC_PIN2 8

RotaryEncoder encoder(ENC_PIN1, ENC_PIN2, RotaryEncoder::LatchMode::TWO03);
int16_t speed;

void setup()
{
  uart_begin(9600);
  speed = 0;
}

void loop()
{
  speed = get_speed_from_encoder(encoder);
  //  uart_transmit(speed);
  uart_transmit_as_string(speed);
}