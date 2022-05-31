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

/**
 * @brief Init PWM on device output
 *
 * @param pin analog pin adress
 *
 */
void PWM_begin(int pin)
{
    pinMode(pin, OUTPUT);
}

/**
 * @brief Genarate PWM with set duty (0 - 100) and output it on analog pin
 *
 * @param pin analog pin adress
 * @param dupty duty of PWM signal in % (0-100)
 *
 */
void PWM_write(int pin, int duty)
{
    static int AnalogDuty = CalcDAC(duty);
    analogWrite(pin, AnalogDuty);
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