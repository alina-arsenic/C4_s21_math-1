/*
релизация ceil
Copyright 2022

nidorina@student.21-school.ru
*/
#include "s21_math.h"

long double s21_ceil(double x) {
    long double answer = 0.0;
    if (s21_isinf(x))
        answer = x < 0 ? -S21_INFINITY : S21_INFINITY;
    else if (s21_isnan(x))
        answer = S21_NAN;
    else
        answer = (long double)(int)x + (x > 0 ? ((int)x == x ? 0 : 1) : 0);
    return answer;
}
