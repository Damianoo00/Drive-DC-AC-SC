#include <unity.h>
#include "../include/sensors.h"

void TestGetVoltage()
{
    TEST_ASSERT_EQUAL_INT(0, get_voltage(0)); // min voltage
    TEST_ASSERT_EQUAL_INT(5000, get_voltage(1024)); // max voltage
}

int main(int argc, char **argv)
{
    UNITY_BEGIN();

    RUN_TEST(TestGetVoltage);

    UNITY_END();
}