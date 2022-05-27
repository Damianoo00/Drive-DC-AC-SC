#include "../include/sensors.h"
#include <Arduino.h>
#include <RotaryEncoder.h>

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

int get_speed(RotaryEncoder *encoder)
/* get speed value from encoder in rad/s */
{
    encoder->tick();
    int speed_rad_s = encoder->getRPM() * 2 * 3.14f / 60;
    return speed_rad_s;
}

int get_voltage(int raw_adc)
/* return voltage value [mV] */
{
    constexpr int VoltToMilivolt = 1000;
    constexpr int MaxVolt = 5;
    constexpr int AdcResolution = 1024;

    return raw_adc * MaxVolt * VoltToMilivolt / AdcResolution;
}