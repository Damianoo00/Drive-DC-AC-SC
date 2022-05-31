/**
 * @file sensors.cpp
 * @author Damian Płaskowicki (damian.plaskowicki.stud@pw.edu.pl)
 * @brief Functions serviced using sensors in project
 * @version 0.1
 * @date 2022-05-31
 *
 * @copyright Copyright (c) 2022
 *
 */
#include "../include/sensors.h"
#include <Arduino.h>
#include <RotaryEncoder.h>

/**
 * @brief Read current value [mA] "Shut method", resistance in mOhm
 *
 * @param pin analog input adress
 * @param resistance shut resistor resistance in mOhm
 *
 * @return (long)return currenst value in mA
 *
 */
long GetCurrent(int pin, int resistance)
{
    int analog_output = analogRead(pin);
    return GetCurrent(analog_output, resistance);
}

/**
 * @brief Calculate current value from adc value
 *
 * @param raw_adc raw adc value (0-255)
 * @param resistance shut resistance (mOhm)
 * @return (long) current value in mA
 */
long CalcCurrent(int raw_adc, int resistance)
{
    const int AmperToMiliamper = 1000;
    const int AdcToMilivolt = 5000 / 255;

    return (int32_t)raw_adc * AmperToMiliamper * AdcToMilivolt / resistance;
}

/**
 * @brief Get the speed value from rotary encoder
 *
 * @param encoder pointer to Rotary Encoder object
 * @return (int) rotary speed in rad/s
 */
int GetSpeed(RotaryEncoder *encoder)
{
    encoder->tick();
    int speed_rad_s = encoder->getRPM() * 2 * 3.14f / 60;
    return speed_rad_s;
}

/**
 * @brief Calculate rad/s speed from RPM speed
 *
 * @param rpm_speed speed in RPM (rotates per minute)
 * @return (int) speed in rad/s
 */
int Rpm2Rads(int16_t rpm_speed)
{
    constexpr int prescaledPi = 314;
    constexpr int min2sec = 60;
    constexpr int represcale = 100;
    return (int32_t)rpm_speed * 2 * prescaledPi / min2sec / represcale;
}

/**
 * @brief Calculate voltage value in (mV)
 *
 * @param raw_adc raw adc value (0-1024)
 * @return (int) voltage value in (mV)
 */
int CalcVoltage(int raw_adc)
{
    constexpr int VoltToMilivolt = 1000;
    constexpr int MaxVolt = 5;
    constexpr int AdcResolution = 1024;

    return (int32_t)raw_adc * MaxVolt * VoltToMilivolt / AdcResolution;
}