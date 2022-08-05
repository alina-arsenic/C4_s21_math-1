/*
релизация функций abs asin ceil
Copyright 2022

nidorina@student.21-school.ru
*/

#include "./s21_math.h"

int s21_abs(int i) { return i >= 0 ? i : -i; }

long double s21_ceil(double x) {
    long double answer = 0.0;
    if (s21_IS_INF(x))
        answer = x < 0 ? s21_MINUSINF : s21_INF;
    else if (s21_isnan(x))
        answer = s21_NAN;
    else
        answer = (long double)(int)x + (x > 0 ? ((int)x == x ? 0 : 1) : 0);
    return answer;
}

int s21_isnan(long double number) {
    return (number >= 0 || number < 0) ? 0 : 1;
}
