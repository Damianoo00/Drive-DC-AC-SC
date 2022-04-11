#include "../include/i2c.h"
#include "../include/global_val.h"
#include <Arduino.h>
#include <RotaryEncoder.h>

#define PIN_IN1 2
#define PIN_IN2 3

RotaryEncoder encoder(PIN_IN1, PIN_IN2, RotaryEncoder::LatchMode::TWO03);
int time;
int dx, dt;

void setup()
{
  I2C_begin_slave(54);
  I2C_hearing();
}

void loop()
{
  static int pos = 0;
  encoder.tick();
  time = millis();
  int newPos = encoder.getPosition();
  if (pos != newPos)
  {
    dx = newPos - pos;
    dt = millis() - time;
    speed = dx / dt;
    pos = newPos;
  }
}