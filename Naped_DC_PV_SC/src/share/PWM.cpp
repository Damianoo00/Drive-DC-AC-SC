/**
 * @file PWM.cpp
 * @author Damian Płaskowicki (damian.plaskowicki.stud@pw.edu.pl)
 * @brief Functions serviced PWM functions
 * @version 0.1
 * @date 2022-05-31
 *
 * @copyright Copyright (c) 2022
 *
 */
#include "../include/PWM.h"
#include <Arduino.h>

volatile int PWM_pin;

/**
 * @brief Init PWM on 10 and 9 (inwerted) device analog ports
 *
 * @param pin adress od analog pin
 */
void PWM_begin(int pin)
{
    PWM_pin = pin;
    pinMode(pin, OUTPUT);
}
/**
 * @brief Convert PI Voltage output voltage to duty 0-100
 *
 * @param Voltage Output voltage V
 * @param maxVolt Max voltage V
 * @return int
 */
int VoltageToDuty(float Voltage, int maxVolt)
{
    constexpr int ToDuty = 100;
    return (int)(Voltage * ToDuty) / maxVolt;
}

/**
 * @brief Genarate PWM on analog ports 10 and 9 with setted deadtime
 * @param duty duty of PWM signal in % (0-100)
 *
 */
void PWM_write(int duty)
{
    int AnalogDuty = CalcDAC(duty);
    analogWrite(PWM_pin, AnalogDuty);
}

/**
 * @brief Calculate DAC value for any duty value
 *
 * @param duty duty of PWM signal in % (0-100)
 *
 */
int CalcDAC(int duty)
{
    constexpr int DacResolution = 255;
    constexpr int ProcToUnit = 100;
    return duty * DacResolution / ProcToUnit;
}