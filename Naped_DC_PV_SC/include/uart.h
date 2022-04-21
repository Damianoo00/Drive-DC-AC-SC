#ifndef UART_H
#define UART_H

class Uart
{
};

void uart_begin(int);
int uart_recive();
void uart_transmit(int);
void uart_transmit_as_string(int, unsigned int);
void uart_recive_curr_n_speed(int *, int *);
void uart_transmit_string(char *);

#endif