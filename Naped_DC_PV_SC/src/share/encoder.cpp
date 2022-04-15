#include <Arduino.h>
#include <RotaryEncoder.h>
#include <stdint.h>
#include "../include/encoder.h"

int get_speed_from_encoder(RotaryEncoder *encoder, int sampling_time)
{
    static int d_pos;
    static int pos_1 = 0;
    static int time = millis();
    static int pos = 0;
    static int newPos;

    encoder->tick();
    newPos = encoder->getPosition();

    if (pos != newPos)
    {
        pos = newPos;
    }

    if ((millis() - time) > sampling_time)
    {
        d_pos = pos - pos_1;
        pos_1 = pos;
        time = millis();
        return d_pos * (1000 / sampling_time) / 2500;
    }
}
