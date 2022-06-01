/**
 * @file PWM.h
 * @author Damian Płaskowicki (damian.plaskowicki.stud@pw.edu.pl)
 * @brief PWM functions prototypes
 * @version 0.1
 * @date 2022-05-31
 *
 * @copyright Copyright (c) 2022
 *
 */
#ifndef PWM_LIB_H
#define PWM_LIB_H

void PWM_begin();
void PWM_write(int);
int CalcDAC(int);

#endif
