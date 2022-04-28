#include <Wire.h>
#include <Arduino.h>

#define TO_MASER_SIZE 2

byte messageToMaster[TO_MASER_SIZE];

void i2c_begin_slave(int slave_adress)
/* set address of slave i2c */
{
    Wire.begin(slave_adress);
}

void i2c_begin_master()
/* set master of i2c without address */
{
    Wire.begin();
}

char readFromMaster()
/* read one char from master i2c */
{
    return Wire.read();
}

void sendToMaster(int mess)
/* send int value to master i2c  */
{
    messageToMaster[0] = 1;
    messageToMaster[1] = (mess >> 8) & 0xff; // the top byte of x
    Wire.write(messageToMaster, TO_MASER_SIZE);
}

void i2c_listen_and_send(int mess)
/* listen for trigger from master to send him mess i2c */
{
    if (Wire.available())
    {
        if (readFromMaster() == '?')
        {
            sendToMaster(mess);
        }
    }
}

void i2cSendToSlave(char trigg)
/* send mess to trigger i2c slave to recive value from them */
{
    Wire.beginTransmission(1);
    Wire.write(trigg);
    Wire.endTransmission();
}

int i2cReadFromSlave()
/* read int value from slave by i2c */
{
    if (Wire.available() == TO_MASER_SIZE)
    {
        for (int i = 0; i < TO_MASER_SIZE; i++)
        {
            messageToMaster[i] = Wire.read();
        }
        return ((int)messageToMaster[1] << 8);
    }
    return 0;
}
