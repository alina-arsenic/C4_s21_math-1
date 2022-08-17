// by weaveryu
#include "s21_math.h"

long double s21_tan(double x) {
    long double result;
    if (s21_fabs(x) == S21_M_PI_2) {
        result = S21_INFINITY;
    } else {
        double check = s21_fmod(x, S21_M_PI);
        int sign = (s21_fabs(check) > S21_M_PI_2) ? -1 : 1;
        if (x < 0) sign *= -1;
        result = sign * s21_sqrt((long double)1/(s21_pow(s21_cos(x), 2))-1);
    }
    return result;
}
