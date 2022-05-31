/**
 * @file converters.cpp
 * @author Damian Płaskowicki (damian.plaskowicki.stud@pw.edu.pl)
 * @brief Functinons serviced converters
 * @version 0.1
 * @date 2022-05-31
 *
 * @copyright Copyright (c) 2022
 *
 */
#include "../../include/converters.h"

/**
 * @brief Calculate duty for Ćuk convereter in range 0-100 to achive Vo value
 *
 * @param Vo target value on the output voltage of converter
 * @param Vs supply voltage
 *
 * @return duty in % (0-100)
 */
int GetCukDuty(int Vo, int Vs)
{
    constexpr int ToProc = 100;
    return (long)ToProc * Vo / (Vs + Vo);
}