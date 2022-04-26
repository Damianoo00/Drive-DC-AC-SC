#include "../include/sensors.h"
#include <Arduino.h>
int read_current(int pin, int resistance)
/* read current value [mA] "Shut method"
Args:
    pin - pin adress
    resistance - shunt resistance
 */
{
    int analog_output = analogRead(pin);

    const int AmperToMiliamper = 1000;
    const float AdcToVolt = 3.3f / 255.0f;

    return analog_output *
           AmperToMiliamper * AdcToVolt / resistance;
}