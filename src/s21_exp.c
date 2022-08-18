// by teresecl
#include "s21_math.h"

long double s21_exp(double x) {
    if (s21_isnan(x)) return S21_NAN;
    if (x == -S21_INFINITY) return 0;
    if (x == S21_INFINITY) return S21_INFINITY;
    int indic = x < 0;
    if (indic) x *= -1;
    long double result = 1;
    double tmp = x;
    unsigned flag = 1;
    while (s21_fabs(tmp) > S21_EPS) {
        result += tmp;
        tmp = (tmp * x) / ++flag;
    }
    return indic ? (1 / result) : result;
}
