#ifndef SRC_S21_MATH_H_
#define SRC_S21_MATH_H_

#include <stdio.h>

#define S21_NAN 0.0 / 0.0
#define S21_INFINITY 1.0 / 0.0
#define S21_NEG_INFINITY -1.0 / 0.0
#define S21_E 2.71828182845904523536

long double s21_fabs(double x);
long double s21_log(double x);
long double s21_sqrt(double x);

#endif  // SRC_S21_MATH_H_
