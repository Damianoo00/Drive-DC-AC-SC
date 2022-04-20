#include <Arduino.h>
#include <string.h>

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
    Serial.write('\n');
}

void uart_transmit_string(char *str)
{

    Serial.write(str);
    Serial.write('\n');
}

void uart_transmit_as_string(int value, int time_interval)
{
    static int time = 0;

    if ((millis() - time) > time_interval)
    {
        static char buffer[10];
        itoa(value, buffer, 10);
        Serial.write(buffer);
        Serial.write('\n');
        time = millis();
    }
}

void uart_recive_curr_n_speed(int *curr, int *speed)
{
    static char buffor[10];
    int i = 0;
    while (Serial.available())
    {
        buffor[i++] = Serial.read();
    }
    *curr = atoi(strtok(buffor, ","));
    *speed = atoi(strtok(NULL, ","));
}