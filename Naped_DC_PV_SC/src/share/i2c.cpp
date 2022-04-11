#include "../include/i2c.h"
#include "../include/global_val.h"
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

void I2C_begin_master()
{
    Wire.begin();
}

void I2C_begin_slave(int id)
{
    Wire.begin(id);
}

void I2C_hearing()
{
    Wire.onRequest(requestEvent);
}

void requestEvent()
{
    byte myArray[2];
    myArray[0] = (speed >> 8) & 0xFF;
    myArray[1] = speed & 0xFF;
    Wire.write(myArray, 2);
}
