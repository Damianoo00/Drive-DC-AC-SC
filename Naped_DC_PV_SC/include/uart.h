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