/**
 * @file i2c.cpp
 * @author Damian Płaskowicki (damian.plaskowicki.stud@pw.edu.pl)
 * @brief i2c serviced functions
 * @version 0.1
 * @date 2022-05-31
 *
 * @copyright Copyright (c) 2022
 *
 */
#include <Wire.h>
#include "../../include/i2c.h"

/**
 * @brief (buffor) store data in SEND_VAL value and send it on request
 *
 */
volatile int SEND_VAL = 5;

/**
 * @brief Init i2c service and hearing for requests
 *
 * @param slave_id slave i2c id
 *
 */
void i2c_begin_slave(int slave_id)
{
    Wire.begin(slave_id);
    Wire.onRequest(requestEvent);
}

/**
 * @brief Init i2c service as master device
 *
 */
void i2c_begin_master()
{
    Wire.begin();
}

/**
 * @brief Update (buffor) value to send on request
 *
 * @param new_value updated (buffor) value to send on request
 */
void update_message(int new_val)
{
    SEND_VAL = new_val;
}

/**
 * @brief Send i2c request to slave device and pick up data
 *
 * @param slave_id i2c id of slave device
 * @param num_of_bytes number of bytes which you want to ick up
 *
 * @return Picked up value (int)
 *
 */
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

/**
 * @brief If picked up request, send stored (buffor) data
 *
 */
void requestEvent()
{
    Wire.println(SEND_VAL);
}