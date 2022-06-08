/**
 * @file uart.cpp
 * @author Damian Płaskowicki (damian.plaskowicki.stud@pw.edu.pl)
 * @brief Functions serviced UART comunication
 * @version 0.1
 * @date 2022-05-31
 *
 * @copyright Copyright (c) 2022
 *
 */
#include <Arduino.h>
#include <string.h>
#include <stdio.h>

/**
 * @brief Check if header of logs was send at begining of logging
 *
 */
volatile int IF_HEADER_SEND = 0;

/**
 * @brief Init UART communication
 *
 * @param baundrate set baundrate of UART comunication [Hz]
 * @param timeout set timeout of comunication [ms]
 */
void uart_begin(long baundrate, int timeout)
{
    Serial.begin(baundrate);
    Serial.setTimeout(timeout);
}

/**
 * @brief Wait for uart message and return as intiger when recived '\n'
 *
 * @return (int) recived message
 */
int uart_recive()
{
    while (!Serial.available())
    {
        /* waiting for mess */
    }
    return Serial.readString().toInt();
}

/**
 * @brief Whait for 2 messages and save as intiger values
 *
 * @param curr pointer to measured current value
 * @param speed pointer to measured speed value
 */
void uart_recive_2_params(long *curr, long *speed)
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

/**
 * @brief Transmit intiger as String ended '\n'
 *
 * @param val value to transmit via uart
 */
void uart_transmit(int val)
{

    Serial.println(val);
}

/**
 * @brief Log via UART params in cvs format
 *
 * @param header comas separated header of parameters
 * @param list_of_log_params list of parameters
 * @param num_of_params number of parameters in list
 */
void log_uart(String header, const long *list_of_log_params, const int num_of_params)
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
        while (!Serial.available())
        {
            // wait for message
        }
        if (Serial.read() == '?')
        {
            Serial.print(header);
            Serial.print('\n');
            IF_HEADER_SEND = 1;
        }
    }
}