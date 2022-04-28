#include "../include/Control.h"
#include "../include/PWM.h"
#include "../include/sensors.h"
#include "../include/uart.h"
#include "../include/i2c.h"
#include <Arduino.h>
#include <stdint.h>

#define LOG
#define SET_CURR

/***** POUT *****/
#define PWM1_port 11
#define PWM2_port 10
#define CURR_PORT A0

/*** UART params***/
#define BAUD 115200
#define TIMEOUT 10

/*** REG I params ***/
const float Ts = 10e3;
const float Kr_i = 3.2593;
const float Tr_i = 4.6136;
const int8_t max_i = 1;
const int8_t min_i = -1;

/*** REG V params ***/
const float Kr_v = 2.8e-5;
const float Tr_v = 1.5e-3;
const int8_t max_v = 126;
const int8_t min_v = -126;

struct PICTRL PIctrl_curr;
struct PICTRL PIctrl_speed;

static int curr_sensor = 0;
static int speed_sensor = 0;

/* REF speed value [rad/s] */
const int speed_ref = 300;

void setup()
{
  uart_begin(BAUD, TIMEOUT);
  i2c_begin_master();

  PWM_begin(PWM1_port);
  PWM_begin(PWM2_port);

  InitPIctrl(&PIctrl_curr, Ts, Kr_i, Tr_i, max_v, min_v);
  InitPIctrl(&PIctrl_speed, Ts, Kr_v, Tr_v, max_v, min_v);
  InitPIctrl(&PIctrl_curr, Ts, Kr_i, Tr_i, max_i, min_i);
}

void loop()
{

#ifdef WORK
  curr_sensor = read_current(CURR_PORT, 1);
  speed_sensor = i2cReadFromSlave();
#endif

#ifdef SET_CURR
  curr_sensor = uart_recive();
#endif
  CalcPIctrl(&PIctrl_speed, speed_ref - speed_sensor);
  CalcPIctrl(&PIctrl_curr, PIctrl_speed.y - speed_sensor);

  PWM_write(PWM1_port, PIctrl_curr.y);
  PWM_write(PWM2_port, -PIctrl_curr.y);

#ifdef LOG
  log_uart(millis(), speed_ref, speed_sensor, 0, curr_sensor, PIctrl_curr.y);
#endif
}