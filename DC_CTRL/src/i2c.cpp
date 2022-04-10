#include "include/i2c.h"
#include <Wire.h>
#include <Arduino.h>
int recive_int_by_I2C(int num_of_bits, int device_id)
{
    byte a, b;
    int Num;
    Wire.requestFrom(num_of_bits, device_id);
    a = Wire.read();
    b = Wire.read();

    Num = a;
    Num = Num << 8 | b;
    return Num;
}

void I2C_begin()
{
    Wire.begin();
}
