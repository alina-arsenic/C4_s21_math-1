// by weaveryu
#include "s21_math.h"

long double s21_tan(double x) {
    int sign = 1;
    if (s21_fabs(s21_fmod(x, 2*S21_M_PI)) > S21_M_PI_2) {
        sign = -1;
    }
    long double result = sign * s21_sqrt((long double)1/(s21_pow(s21_cos(x), 2))-1);
    return result;
}
