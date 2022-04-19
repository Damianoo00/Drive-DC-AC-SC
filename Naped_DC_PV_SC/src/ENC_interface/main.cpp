#include "../include/encoder.h"
#include "../include/uart.h"

#define WORK

/******* PIN_IN *********/
#define ENC_A 7
#define ENC_B 8

/*** Encoder params ***/
#define ENC_res 2500
#define Ts 1 // ms

/**** UART params ****/
#define BAUND 9600

MyEncoder encoder(ENC_A, ENC_B, ENC_res, Ts, MyEncoder::LatchMode::TWO03);

void setup()
{
  uart_begin(BAUND);
}
void loop()
{

#ifdef WORK
  uart_transmit(encoder.get_speed());
#endif
#ifdef TEST
  uart_transmit_as_string(encoder.get_speed(), Ts);
#endif
}