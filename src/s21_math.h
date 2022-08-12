#ifndef SRC_S21_MATH_H_
#define SRC_S21_MATH_H_

#include <stdio.h>
#include <stdlib.h>

#define S21_EPS 1e-6
#define S21_PI 3.14159265358979323846264338327950288
#define S21_CONST_1 1.570796326794896558
#define S21_CONST_2 0.785398163397448309
#define S21_CONST_SQ 0.7071067811865475244
#define S21_NAN 0.0 / 0.0
#define S21_INF 1.0 / 0.0
#define S21_isnan(x) (!(x >= 0) && !(x < 0))
#define S21_isinf(x) ((x == S21_INF) || (x == -S21_INF))

long double s21_acos(double x);
long double s21_exp(double x);
long double s21_sin(double x);

#endif  // SRC_S21_MATH_H_
