#include "../include/sensors.h"

float read_current(int analog_output, int prescaler)
{
    return analog_output * 3.3f / 255.0f * prescaler;
}