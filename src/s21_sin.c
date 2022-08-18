// by teresecl
#include "s21_math.h"

long double s21_sin(double x) {
    x = s21_fmod(x, 2 * S21_M_PI);
    long double result = 0;
    long double tmp = x;
    unsigned flag = 1;
    while (flag < 1000) {
        result += tmp;
        flag += 2;
        tmp *= -(x * x) / ((flag - 1) * flag);
    }
    return result;
}
