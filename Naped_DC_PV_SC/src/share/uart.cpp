#include <Arduino.h>
#include <string.h>

void uart_begin(long baundrate, int timeout)
{
    Serial.begin(baundrate);
    Serial.setTimeout(timeout);
}

int uart_recive()
{
    while (!Serial.available())
    {
        /* waiting for mess */
    }
    return Serial.readString().toInt();
}

void uart_transmit(int val)
{

    Serial.println(val);
}

void log_uart(unsigned long CLK, int speed_ref, int speed_sensor, int curr_ref, int curr_sensor, int ctr_sig)
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