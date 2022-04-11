#include "../include/PWM.h"
#include <Arduino.h>

void PWM_begin(int port)
{
    pinMode(port, OUTPUT);
}

void PWM_write(int port, int duty)
{
    analogWrite(port, duty);
}