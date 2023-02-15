// by workerwa
#include "s21_math.h"

long double s21_floor(double x) {
    long double result;
    if (s21_isinf(x)) {
        if (x < 0) {
            result = -S21_INFINITY;
        } else {
            result = S21_INFINITY;
        }
    } else if (s21_isnan(x)) {
        result = S21_NAN;
    } else {
        int y = (int) x;
        if (x < 0 && y - x > 0) {
            y -= 1;
        }
        result = (long double)y;
    }
    return result;
}
