#include "../include/control.h"

void InitPIctrl(struct PICTRL *pictrl, int Ts, float Kr, float Ti, int max,
                int min)
{
  /*
  Initialize struct of PI controller
  Args:
          Ts - Sample time
          Kr - amplification of regulator
          Ti - time constant of regulator
          max - max saturation limit
          min - min saturation limit
  */
  pictrl->x = 0;
  pictrl->y = 0;

  pictrl->a = 0;
  pictrl->b = 0;
  pictrl->c = 0;
  pictrl->c_1 = 0;
  pictrl->d = 0;
  pictrl->d_1 = 0;
  pictrl->e = 0;
  pictrl->f = 0;
  pictrl->f_1 = 0;

  pictrl->Ts = Ts;
  pictrl->Kr = Kr;
  pictrl->Ti = Ti;
  pictrl->max = max;
  pictrl->min = min;
}

void CalcPIctrl(struct PICTRL *pictrl, float x)
{
  /*
  Calc output of PI controller
  Args: x - input of PI controller block
   */
  pictrl->x = x;
  pictrl->a = pictrl->Kr * pictrl->x;

  if (pictrl->f_1 == 0)
    pictrl->b = pictrl->a;
  else
    pictrl->b = 0;

  pictrl->c = pictrl->b * 1 / pictrl->Ti;
  pictrl->d = pictrl->c * pictrl->Ts * 0.5 + pictrl->c_1 * 0.5 * pictrl->Ts +
              pictrl->d_1;
  pictrl->e = pictrl->a + pictrl->d;

  pictrl->y = pictrl->e;
  if (pictrl->e > pictrl->max)
    pictrl->y = pictrl->max;
  if (pictrl->y < pictrl->min)
    pictrl->y = pictrl->min;

  pictrl->f = pictrl->e - pictrl->y;
  pictrl->f_1 = pictrl->f;
  pictrl->c_1 = pictrl->c;
  pictrl->d_1 = pictrl->d;
}