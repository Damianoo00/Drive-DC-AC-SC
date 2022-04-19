#ifndef ENCODER_H
#define ENCODER_H

#include <RotaryEncoder.h>

class MyEncoder : public RotaryEncoder
{
public:
    MyEncoder(int pin1, int pin2, int resolution, int sample_time, LatchMode mode);
    int get_speed();

private:
    using RotaryEncoder::RotaryEncoder;
    int _resolution;
    int _sample_time;
};

int get_speed_from_encoder(RotaryEncoder *, int);
void enable_encoder(int, int);

#endif