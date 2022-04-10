#include "include/Control_lib.h"
#include <Arduino.h>

#define Ts 10e3

#define Kr_i 3.2593
#define Tr_i 4.6136
#define max_i 1
#define min_i -1

#define Kr_v 2.8e-5
#define Tr_v 1.5e-3
#define max_v 126
#define min_v -126

void setup()
{
  struct PICTRL PIctrl_curr;
  struct PICTRL PIctrl_speed;

  InitPIctrl(&PIctrl_curr, Ts, Kr_i, Tr_i, max_v, min_v);
  InitPIctrl(&PIctrl_speed, Ts, Kr_v, Tr_v, max_v, min_v);
}

void loop()
{
}