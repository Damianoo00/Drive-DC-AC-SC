#ifndef SENSORS_H
#define SENSORS_H

#include <RotaryEncoder.h>

long read_current(int, int);
int get_speed(RotaryEncoder *);
int get_voltage(int);
long get_current(int, int);

#endif