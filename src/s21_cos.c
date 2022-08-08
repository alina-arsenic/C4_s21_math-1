// by weaveryu
#include "s21_math.h"

long double s21_cos(double x) {
    x = s21_fmod(x, 2 * S21_M_PI);
    long double result = 1;
    long double xx = x*x;
    long double fact = 2;
    long double fact_mul = 2;
    int sign = -1;
    for (int i = 1; i < 100; i++) {
        result += sign*(s21_pow(xx, i))/(fact);
        sign *= -1;
        fact *= ++fact_mul;
        fact *= ++fact_mul;
    }
    return result;
}
