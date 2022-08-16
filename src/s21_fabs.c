// by yoghurtb
#include "s21_math.h"

long double s21_fabs(double x) {
    long double result;
    if (x != x) {
        result = S21_NAN;
    } else if (x == S21_INFINITY || x == -S21_INFINITY) {
        result = S21_INFINITY;
    } else {
        result = (x < 0) ? (long double)(x * -1) : (long double)x;
    }
    return result;
}
