#include "../include/PWM.h"
#include <Arduino.h>

void PWM_begin(int pin)
/* Set pin in OUTPUT mode */
{
    pinMode(pin, OUTPUT);
}

void PWM_write(int pin, int duty)
/* Genarate PWM with set duty (0 - 100) and output (0-5V) on pin */
{
    constexpr int DacResolution = 255;
    constexpr int ProcToPerUnit = 100;
    static int AnalogDuty = duty * DacResolution / ProcToPerUnit;
    analogWrite(pin, AnalogDuty);
}