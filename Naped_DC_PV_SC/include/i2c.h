#ifndef I2C_H
#define I2C_H

void i2c_begin_slave(int);
void i2c_begin_master();
char readFromMaster();
void sendToMaster(int);
void i2c_listen_and_send(int);
int i2cReadFromSlave();
void i2cSendToSlave(char);

#endif