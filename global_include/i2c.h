#ifndef I2C_H
#define I2C_H

void send_int_by_I2C(int num_of_bits, int device_id);
int recive_int_by_I2C(int num_of_bits, int device_id);
void I2C_begin_master();
void I2C_begin_slave(int id);
void requestEvent();
void I2C_hearing();
#endif