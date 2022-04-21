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

const float Kr_v = 2.8e-5;
const float Tr_v = 1.5e-3;
const int8_t max_v = 126;
const int8_t min_v = -126;

struct PICTRL PIctrl_curr;
struct PICTRL PIctrl_speed;
static int curr_sensor = 0;
static int speed_sensor = 0;

/* REF speed value */
const int8_t speed_ref = 100;

void setup()
{
  uart_begin(BAUD);

  PWM_begin(PWM1_port);
  PWM_begin(PWM2_port);

  InitPIctrl(&PIctrl_curr, Ts, Kr_i, Tr_i, max_v, min_v);
  InitPIctrl(&PIctrl_speed, Ts, Kr_v, Tr_v, max_v, min_v);
}

void loop()
{
#ifdef WORK
  curr_sensor = read_current(CURR_PORT, 1);
  speed_sensor = uart_recive();
#endif

#ifdef TEST
  uart_recive_curr_n_speed(&curr_sensor, &speed_sensor);
#endif
  CalcPIctrl(&PIctrl_curr, speed_ref - speed_sensor);

  PWM_write(PWM1_port, PIctrl_curr.y);
  PWM_write(PWM2_port, -PIctrl_curr.y);

#ifdef TEST
  uart_transmit(PIctrl_curr.y);
#endif
}