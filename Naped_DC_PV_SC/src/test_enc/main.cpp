#include "../include/encoder.h"
#include "../include/uart.h"
#include <Arduino.h>
#include <RotaryEncoder.h>

#define PIN_IN1 7
#define PIN_IN2 8

RotaryEncoder encoder(PIN_IN1, PIN_IN2, RotaryEncoder::LatchMode::TWO03);
void setup()
{
    uart_begin(9600);
}
void loop()
{
    static int speed = 0;
    speed = get_speed_from_encoder(&encoder, 250);
    uart_transmit_as_string(speed, 250);
}