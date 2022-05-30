#include <unity.h>
#include "../include/sensors.h"
#include "../include/control.h"
#include "../include/converters.h"

void TestGetVoltage()
{
    TEST_ASSERT_EQUAL_INT(0, get_voltage(0)); // min voltage
    TEST_ASSERT_EQUAL_INT(2441, get_voltage(500));
    TEST_ASSERT_EQUAL_INT(5000, get_voltage(1024)); // max voltage
}

void TestGetCurrent()
{
    TEST_ASSERT_EQUAL_INT(0, get_current(0, 0));
    TEST_ASSERT_EQUAL_INT(1945600, get_current(1024, 10));
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
    TEST_ASSERT_EQUAL_INT(0, get_Cuk_duty(0, 0));
    TEST_ASSERT_EQUAL_INT(28, get_Cuk_duty(2000, 5000));
    TEST_ASSERT_EQUAL_INT(50, get_Cuk_duty(5000, 5000));
}

int main(int argc, char **argv)
{
    UNITY_BEGIN();

    RUN_TEST(TestGetVoltage);
    RUN_TEST(TestGetCurrent);
    RUN_TEST(TestCalacPI);
    RUN_TEST(TestGetCiukDuty);

    UNITY_END();
}