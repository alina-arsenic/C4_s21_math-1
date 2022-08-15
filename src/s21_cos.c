// by weaveryu
#include "s21_math.h"

long double s21_cos(double x) {
    x = s21_fmod(x, S21_M_PI);
    long double result = 1;
    long double xx = x*x;
    long double fact = 2;
    long double fact_mul = 2;
    long double add = 1;
    int sign = -1;
    int i = 1;
    while (s21_fabs(add) > S21_EPS) {
        add = sign*(s21_pow(xx, i))/(fact);
        result += add;
        sign *= -1;
        fact *= ++fact_mul;
        fact *= ++fact_mul;
        i++;
    }
    return result;
}
