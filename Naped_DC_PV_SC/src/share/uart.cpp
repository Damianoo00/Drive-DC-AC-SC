#include <Arduino.h>

void uart_begin(int baundrate)
{
    Serial.begin(baundrate);
}

int uart_recive()
{
    if (Serial.available())
    {
        return Serial.read();
    }
}
void uart_transmit(int value)
{
    Serial.write(value);
}
