#include <Wire.h>
#include "../../include/i2c.h"

volatile int SEND_VAL = 5;

void i2c_begin_slave(int slave_id)
{
    Wire.begin(slave_id);
    Wire.onRequest(requestEvent);
}

void i2c_begin_master()
{
    Wire.begin();
}

void update_message(int new_val)
{
    SEND_VAL = new_val;
}

int i2c_get_value_from_slave(int slave_id, int num_of_bytes)
{
    Wire.requestFrom(slave_id, num_of_bytes);

    String mess = "";
    while (Wire.available())
    {
        char c = Wire.read();
        mess += c;
    }
    return mess.toInt();
}

void requestEvent()
{
    Wire.println(SEND_VAL);
}