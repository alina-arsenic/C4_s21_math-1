/*
релизация функций abs asin ceil
Copyright 2022

nidorina@student.21-school.ru
*/
#include "./s21_math.h"

#include <math.h>
#include <stdio.h>

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
    return (number > 0 || number < 0 || number == 0) ? 0 : 1;
}

long double s21_fabs(double x) { return x >= 0 ? x : -x; }

long double s21_asin(double x) {
    long double answer = x;
    long double fabs_x = s21_fabs(x);
    // printf("\nincome x=%.7f\n", x);
    if (fabs_x > 1) {
        answer = s21_fabs(s21_NAN);
        // printf("%.7Lf\n", answer);
    } else if (fabs_x == 1) {
        answer = x * s21_PI / 2;
        // printf("%.7Lf\n", answer);
    } else if (fabs_x == 0) {
        answer = 0;
    } else if (fabs_x > 0 && fabs_x <= 0.5) {
        answer = tailor_row_asin(x);
    } else if (fabs_x > 0.5 && fabs_x < 1) {
        x = pow(((1 - x) / 2), 0.5);
        answer = tailor_row_asin(x);
        answer = (s21_PI / 2) - (2 * answer);
    }
    // printf("asnwer=%.17Lf\n", answer);
    return answer;
}

long double tailor_row_asin(long double x) {
    long double answer = x;
    long double tailor_n2 = x;
    int n = 1;
    for (; s21_fabs(tailor_n2) > s21_EPS; n++) {
        tailor_n2 *= (2 * n - 1) * (2 * n - 1) * x * x;
        tailor_n2 /= 2 * n * (2 * n + 1);
        answer += tailor_n2;
    }
    return answer;
}
