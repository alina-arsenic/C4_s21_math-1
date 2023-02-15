// by teresecl
#include "s21_math.h"

long double s21_acos(double x) {
    long double result = 0.0;
    if (x == 1.0) {
        return 0;
    } else if (x == -1.0) {
        return S21_M_PI;
    } else if (x == 0) {
        return S21_M_PI_2;
    } else if (x == S21_M_SQRT1_2) {
        return S21_M_PI_4;
    } else if (x == -S21_M_SQRT1_2) {
        return 3 * S21_M_PI_2;
    }

    if (0.0 < x && x < 1.0) {
        result = s21_atan(s21_sqrt(1 - x * x) / x);
    } else if (-1. < x && x < 0.) {
        result = S21_M_PI + s21_atan(s21_sqrt(1 - x * x) / x);
    } else {
        result = S21_NAN;
    }

    return result;
}
