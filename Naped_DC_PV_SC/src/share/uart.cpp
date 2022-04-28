#include <Arduino.h>
#include <string.h>
#include <stdio.h>

void uart_begin(long baundrate, int timeout)
/* set baudrate and timeout for UART */
{

    Serial.begin(baundrate);
    Serial.setTimeout(timeout);
}

int uart_recive()
/* wait for message and return (int) mess when recived '\n' */
{
    while (!Serial.available())
    {
        /* waiting for mess */
    }
    return Serial.readString().toInt();
}
void uart_recive_2_params(int *speed, int *curr)
/* wait for message and save 2 int variables  */
{
    /* TO DO */
}

void uart_transmit(int val)
/* Transmit any data as String ended '\n' */
{

    Serial.println(val);
}

void log_uart(unsigned long CLK, int speed_ref, int speed_sensor, int curr_ref, int curr_sensor, int ctr_sig)
/* log CLK,speed_ref,speed_sensor,curr_ref,curr_sensor,ctr_sig\n on UART */
{
    Serial.print(CLK);
    Serial.print(",");
    Serial.print(speed_ref);
    Serial.print(",");
    Serial.print(speed_sensor);
    Serial.print(",");
    Serial.print(curr_ref);
    Serial.print(",");
    Serial.print(curr_sensor);
    Serial.print(",");
    Serial.print(ctr_sig);
    Serial.print("\n");
}