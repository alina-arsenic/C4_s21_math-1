/*
релизация asin
Copyright 2022

nidorina@student.21-school.ru
*/
#include "s21_math.h"

long double tailor_row_asin(long double x);

long double s21_asin(double x) {
    long double answer = x;
    long double fabs_x = s21_fabs(x);
    // printf("\nincome x=%.7f\n", x);
    if (fabs_x > 1) {
        answer = s21_fabs(S21_NAN);
        // printf("%.7Lf\n", answer);
    } else if (fabs_x == 1) {
        answer = x * S21_M_PI / 2;
        // printf("%.7Lf\n", answer);
    } else if (fabs_x == 0) {
        answer = 0;
    } else if (fabs_x > 0 && fabs_x <= 0.5) {
        answer = tailor_row_asin(x);
    } else if (fabs_x > 0.5 && fabs_x < 1) {
        x = s21_sqrt(((1 - x) / 2));
        answer = tailor_row_asin(x);
        answer = (S21_M_PI / 2) - (2 * answer);
    }
    // printf("asnwer=%.17Lf\n", answer);
    return answer;
}

long double tailor_row_asin(long double x) {
    long double answer = x;
    long double tailor_n2 = x;
    for (int n = 1; s21_fabs(tailor_n2) > S21_EPS; n++) {
        tailor_n2 *= (2 * n - 1) * (2 * n - 1) * x * x;
        tailor_n2 /= 2 * n * (2 * n + 1);
        answer += tailor_n2;
    }
    return answer;
}
