#include <Arduino.h>
#include <RotaryEncoder.h>
#include <stdint.h>
#include "../include/encoder.h"

MyEncoder::MyEncoder(int pin1, int pin2, int resolution, int sample_time, LatchMode mode = LatchMode ::TWO03) : RotaryEncoder(pin1, pin2, mode)
{
    _resolution = resolution;
    _sample_time = sample_time;
}

int MyEncoder::get_speed()
{
    static int d_pos;
    static int pos_1 = 0;
    static int time = millis();
    static int pos = 0;
    static int newPos;

    tick();
    newPos = getPosition();

    if (pos != newPos)
    {
        pos = newPos;
    }

    if ((millis() - time) > _sample_time)
    {
        d_pos = pos - pos_1;
        pos_1 = pos;
        time = millis();
        return d_pos * (60 * 1000 / _sample_time) / _resolution;
    }
}
