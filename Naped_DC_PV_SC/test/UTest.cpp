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

void TestCalcVoltage()
{
    TEST_ASSERT_EQUAL_INT(0, CalcVoltage(0)); // min voltage
    TEST_ASSERT_EQUAL_INT(2441, CalcVoltage(500));
    TEST_ASSERT_EQUAL_INT(5000, CalcVoltage(1024)); // max voltage
}

void TestCalcCurrent()
{
    TEST_ASSERT_EQUAL_INT(0, CalcCurrent(0, 0));
    TEST_ASSERT_EQUAL_INT(19, CalcCurrent(190, 47));
    TEST_ASSERT_EQUAL_INT(106, CalcCurrent(1024, 47));
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

    RUN_TEST(TestCalcVoltage);
    RUN_TEST(TestCalcCurrent);
    RUN_TEST(TestGetCiukDuty);
    RUN_TEST(TestRpm2rads);
    RUN_TEST(TestCalcDac);

    UNITY_END();
}