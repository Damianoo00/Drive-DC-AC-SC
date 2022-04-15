#ifndef UART_H
#define UART_H

void uart_begin(int);
int uart_recive();
void uart_transmit(int);
void uart_transmit_as_string(int, int);

#endif