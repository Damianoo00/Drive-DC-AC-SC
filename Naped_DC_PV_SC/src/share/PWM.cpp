#include "../include/PWM.h"
#include <Arduino.h>

void PWM_begin(int pin)
/* Set pin in OUTPUT mode */
{
    pinMode(pin, OUTPUT);
}

void PWM_write(int pin, int duty)
/* Genarate PWM with set duty and output it on pin */
{
    analogWrite(pin, duty);
}