#ifndef I2C_H
#define I2C_H

void i2c_begin_master();
int i2c_get_value_from_slave(int, int);
void i2c_begin_slave(int);
void update_message(int);
void requestEvent();

#endif