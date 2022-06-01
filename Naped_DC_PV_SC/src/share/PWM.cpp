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

constexpr int PWM_pin = 9;
constexpr int Inwert_PWM_pin = 10;
constexpr int DeadTime = 2;

/**
 * @brief Init PWM on 10 and 9 (inwerted) device analog ports
 */
void PWM_begin()
{
    TCCR1A = (TCCR1A & 0x0F) | 0xB0;
    pinMode(PWM_pin, OUTPUT);
    pinMode(Inwert_PWM_pin, OUTPUT);
}

/**
 * @brief Genarate PWM on analog ports 10 and 9 with setted deadtime

 * @param duty duty of PWM signal in % (0-100)
 *
 */
void PWM_write(int duty)
{
    static int AnalogDuty = CalcDAC(duty);
    analogWrite(PWM_pin, AnalogDuty);
    analogWrite(Inwert_PWM_pin, AnalogDuty + DeadTime);
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