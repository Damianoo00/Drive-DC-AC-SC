#include "../include/PWM.h"
#include <Arduino.h>

void PWM_begin(int pin)
/* Set pin in OUTPUT mode */
{
    pinMode(pin, OUTPUT);
}

void PWM_write(int pin, float duty)
/* Genarate PWM with set duty (0 - 1) and output it on pin */
{
    static int AnalogDuty = duty * 255;
    analogWrite(pin, AnalogDuty);
}