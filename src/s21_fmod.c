// by workerwa
#include "s21_math.h"

long double s21_fmod(double x, double y) {
    long double result;
    if (s21_isinf(x) || s21_isinf(y) || s21_isnan(x) || s21_isnan(y) || y == 0) {
        result = S21_NAN;
    } else {
        long double l_x = x;
        long double l_y = y;
        long long div = x / y;
        result = l_x - div * l_y;
    }
    return result;
}
