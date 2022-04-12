#ifndef ENCODER_H
#define ENCODER_H

#include <RotaryEncoder.h>

int get_speed_from_encoder(RotaryEncoder);
void enable_encoder(int, int);

#endif