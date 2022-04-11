#include "../include/Control.h"
#include "../include/Reg_param.h"
#include "../../global_include/i2c.h"
#include "../../global_include/PWM.h"
#include "../../global_include/sensors.h"
#include <Arduino.h>
#include <Wire.h>

struct PICTRL PIctrl_curr;
struct PICTRL PIctrl_speed;
float curr_sensor = 0;
float speed_sensor = 0;
int PWM1_port = 11;
int PWM2_port = 10;

/* reference speed value */
const float speed_ref = 100;
/************************/

void setup()
{
  I2C_begin_master();

  PWM_begin(PWM1_port);
  PWM_begin(PWM2_port);

  InitPIctrl(&PIctrl_curr, Ts, Kr_i, Tr_i, max_v, min_v);
  InitPIctrl(&PIctrl_speed, Ts, Kr_v, Tr_v, max_v, min_v);
}

void loop()
{
  curr_sensor = read_current(A0, 1);
  speed_sensor = recive_int_by_I2C(54, 2);

  CalcPIctrl(&PIctrl_speed, speed_ref - speed_sensor);
  CalcPIctrl(&PIctrl_curr, PIctrl_speed.y - speed_sensor);

  PWM_write(PWM1_port, PIctrl_curr.y);
  PWM_write(PWM2_port, -PIctrl_curr.y);
}