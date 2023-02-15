// by weaveryu
#include "s21_math.h"

long double s21_tan(double x) {
    long double result;
    x = s21_fmod(x, S21_M_PI);
    if (s21_fabs(x) == S21_M_PI_2) {
        result = S21_INFINITY;
    } else {
        result = s21_sin(x)/s21_cos(x);
    }
    return result;
}
