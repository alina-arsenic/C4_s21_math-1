// by weaveryu
#include "s21_math.h"

long double s21_tan(double x) {
    int sign = (s21_fabs(s21_fmod(x, 2*S21_M_PI)) > S21_M_PI_2) ? -1 : 1;
    return sign * s21_sqrt((long double)1/(s21_pow(s21_cos(x), 2))-1);
}
