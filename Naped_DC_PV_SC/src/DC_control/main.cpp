#include "../include/Control.h"
#include "../include/PWM.h"
#include "../include/sensors.h"
#include "../include/uart.h"
#include <Arduino.h>
#include <stdint.h>

#define TEST

/***** POUT *****/
#define PWM1_port 11
#define PWM2_port 10
#define CURR_PORT A0

/*** UART params***/
#define BAUD 9600

/*** REG params ***/
const float Ts = 10e3;
const float Kr_i = 3.2593;
const float Tr_i = 4.6136;
const int8_t max_i = 1;
const int8_t min_i = -1;

struct PICTRL PIctrl_curr;
static int curr_sensor = 0;

/* REF speed value */
const int8_t current_ref = 10;

void setup()
{
  uart_begin(BAUD);

  PWM_begin(PWM1_port);
  PWM_begin(PWM2_port);

  InitPIctrl(&PIctrl_curr, Ts, Kr_i, Tr_i, max_i, min_i);
}

void loop()
{
#ifdef WORK
  curr_sensor = read_current(CURR_PORT, 1);
  speed_sensor = uart_recive();
#endif

#ifdef TEST
  curr_sensor = uart_recive();
#endif
  CalcPIctrl(&PIctrl_curr, current_ref - curr_sensor);

  PWM_write(PWM1_port, PIctrl_curr.y);
  PWM_write(PWM2_port, -PIctrl_curr.y);

#ifdef TEST
  uart_transmit(PIctrl_curr.y);
#endif
}