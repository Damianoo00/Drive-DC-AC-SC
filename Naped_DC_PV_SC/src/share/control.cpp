/**
 * @file control.cpp
 * @author Damian Płaskowicki (damian.plaskowicki.stud@pw.edu.pl)
 * @brief Discrete PI Controller function
 * @version 0.1
 * @date 2022-05-31
 *
 * @copyright Copyright (c) 2022
 *
 */
#include "../include/control.h"

/**
 * @brief Initialize struct of PI controller
 *
 * @param pictrl pointer to PICTRL struct
 * @param Ts sample time
 * @param Kr amplification of regulator
 * @param Ti Time constant of regulator
 * @param max max saturation limit
 * @param min min saturation limit
 */
void InitPIctrl(struct PICTRL *pictrl, int Ts, float Kr, float Ti, int max,
                int min)
{
  pictrl->x = 0.0;
  pictrl->y = 0.0;

  pictrl->a = 0.0;
  pictrl->b = 0.0;
  pictrl->c = 0.0;
  pictrl->c_1 = 0.0;
  pictrl->d = 0.0;
  pictrl->d_1 = 0.0;
  pictrl->e = 0.0;
  pictrl->f = 0.0;
  pictrl->f_1 = 0.0;

  pictrl->Ts = Ts;
  pictrl->Kr = Kr;
  pictrl->Ti = Ti;
  pictrl->max = max;
  pictrl->min = min;
}

/**
 * @brief Calculate output of PI controller and return on [struct].y
 *
 * @param input input of PI Controller
 */
void CalcPIctrl(struct PICTRL *pictrl, float input)
{
  pictrl->x = input;
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