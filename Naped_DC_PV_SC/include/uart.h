/**
 * @file uart.h
 * @author Damian Płaskowicki (damian.plaskowicki.stud@pw.edu.pl)
 * @brief uart functions prototypes
 * @version 0.1
 * @date 2022-05-31
 *
 * @copyright Copyright (c) 2022
 *
 */
#ifndef UART_H
#define UART_H

class Uart
{
};

void uart_begin(long, int);
int uart_recive();
void uart_recive_2_params(int *, int *);
void uart_transmit(int);
void log_uart(String, const long *, const int);

#endif