#include <Arduino.h>
#include <string.h>
#include <stdio.h>

volatile int IF_HEADER_SEND = 0;

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
void uart_recive_2_params(int *curr, int *speed)
/* wait for message and save 2 int variables  */
{
    while (!Serial.available())
    {
        /* waiting for mess */
    }
    *curr = Serial.readString().toInt();
    while (!Serial.available())
    {
        /* waiting for mess */
    }
    *speed = Serial.readString().toInt();
}

void uart_transmit(int val)
/* Transmit any data as String ended '\n' */
{

    Serial.println(val);
}

void log_uart(String header, const long *list_of_log_params, const int num_of_params)
/* log data from queue in csv format */
{
    if (IF_HEADER_SEND)
    {
        for (int i = 0; i < num_of_params; i++)
        {
            if (i > 0)
            {
                Serial.print(",");
            }

            Serial.print(list_of_log_params[i]);
        }
        Serial.print("\n");
    }
    else
    {
        if (Serial.available())
        {
            if (Serial.read() == '?')
            {
                Serial.print(header);
                Serial.print('/n');
                IF_HEADER_SEND = 1;
            }
        }
    }
}