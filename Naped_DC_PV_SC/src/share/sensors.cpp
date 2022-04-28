#include "../include/sensors.h"
#include <Arduino.h>
int read_current(int pin, int resistance)
/* read current value [mA] "Shut method", resistance in mOhm
Args:
    pin - pin adress
    resistance - shunt resistance [mOhm]
 */
{
    int analog_output = analogRead(pin);

    const int AmperToMiliamper = 1000;
    const int AdcToMilivolt = 5000 / 255;

    return AmperToMiliamper * analog_output * AdcToMilivolt / resistance;
}