/**
 * @file i2c.h
 * @author Damian Płaskowicki (damian.plaskowicki.stud@pw.edu.pl)
 * @brief i2c functions prototypes
 * @version 0.1
 * @date 2022-05-31
 *
 * @copyright Copyright (c) 2022
 *
 */
#ifndef I2C_H
#define I2C_H

void i2c_begin_master();
int i2c_get_value_from_slave(int, int);
void i2c_begin_slave(int);
void update_message(int);
void requestEvent();

#endif