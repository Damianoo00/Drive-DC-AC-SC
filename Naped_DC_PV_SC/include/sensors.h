/**
 * @file sensors.h
 * @author Damian Płaskowicki (damian.plaskowicki.stud@pw.edu.pl)
 * @brief Sensors functions prototypes
 * @version 0.1
 * @date 2022-05-31
 *
 * @copyright Copyright (c) 2022
 *
 */
#ifndef SENSORS_H
#define SENSORS_H

#include <RotaryEncoder.h>

int GetCurrent(int, int);
int CalcCurrent(int, int);
int GetSpeed(RotaryEncoder *);
int GetVoltage(int);
int CalcVoltage(int);
int Rpm2Rads(int16_t);

#endif