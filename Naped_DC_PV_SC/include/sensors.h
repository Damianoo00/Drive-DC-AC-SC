#ifndef SENSORS_H
#define SENSORS_H

#include <RotaryEncoder.h>

int read_current(int, int);
int get_speed(RotaryEncoder *);

#endif