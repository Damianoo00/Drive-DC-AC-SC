#ifndef ENCODER_H
#define ENCODER_H

#include <RotaryEncoder.h>

class MyEncoder : private RotaryEncoder
{
    MyEncoder(int pin1, int pin2, LatchMode mode = LatchMode::TWO03) : RotaryEncoder(pin1, pin2, mode){};
};

int get_speed_from_encoder(RotaryEncoder *, int);
void enable_encoder(int, int);

#endif