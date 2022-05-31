/**
 * @file UTest.cpp
 * @author Damian Płaskowicki (damian.plaskowicki.stud@pw.edu.pl)
 * @brief Unit test of Calculations in projct
 * @version 0.1
 * @date 2022-05-31
 *
 * @copyright Copyright (c) 2022
 *
 */
#include <unity.h>
#include "../include/sensors.h"
#include "../include/control.h"
#include "../include/converters.h"
#include "../include/PWM.h"

void TestGetVoltage()
{
    TEST_ASSERT_EQUAL_INT(0, CalcVoltage(0)); // min voltage
    TEST_ASSERT_EQUAL_INT(2441, CalcVoltage(500));
    TEST_ASSERT_EQUAL_INT(5000, CalcVoltage(1024)); // max voltage
}

void TestGetCurrent()
{
    TEST_ASSERT_EQUAL_INT(0, CalcCurrent(0, 0));
    TEST_ASSERT_EQUAL_INT(1945600, CalcCurrent(1024, 10));
}

void TestCalacPI()
{
    /******** PI config *********/
    constexpr float Ts = 10e3;
    constexpr float Kr_i = 3.2593;
    constexpr float Tr_i = 4.6136;
    constexpr int8_t max_i = 1;
    constexpr int8_t min_i = -1;
    struct PICTRL PIctrl;
    InitPIctrl(&PIctrl, Ts, Kr_i, Tr_i, max_i, min_i);

    /********* TESTS ******************/
    CalcPIctrl(&PIctrl, 1);
    TEST_ASSERT_EQUAL_FLOAT(1, PIctrl.y);
    CalcPIctrl(&PIctrl, 0.0004);
    TEST_ASSERT_EQUAL_FLOAT(1, PIctrl.y);
}

void TestGetCiukDuty()
{
    TEST_ASSERT_EQUAL_INT(0, GetCukDuty(0, 0));
    TEST_ASSERT_EQUAL_INT(28, GetCukDuty(2000, 5000));
    TEST_ASSERT_EQUAL_INT(50, GetCukDuty(5000, 5000));
}

void TestRpm2rads()
{
    TEST_ASSERT_EQUAL_INT(0, Rpm2Rads(0));
    TEST_ASSERT_EQUAL_INT(10, Rpm2Rads(100));
    TEST_ASSERT_EQUAL_INT(209, Rpm2Rads(2000));
}

void TestCalcDac()
{
    TEST_ASSERT_EQUAL_INT(0, CalcDAC(0));
    TEST_ASSERT_EQUAL_INT(255, CalcDAC(100));
    TEST_ASSERT_EQUAL_INT(51, CalcDAC(20));
}

int main(int argc, char **argv)
{
    UNITY_BEGIN();

    RUN_TEST(TestGetVoltage);
    RUN_TEST(TestGetCurrent);
    RUN_TEST(TestCalacPI);
    RUN_TEST(TestGetCiukDuty);
    RUN_TEST(TestRpm2rads);
    RUN_TEST(TestCalcDac);

    UNITY_END();
}