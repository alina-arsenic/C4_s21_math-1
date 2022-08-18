// by teresecl
#include "s21_math.h"

long double s21_exp(double x) {
    long double res = 0;
    if (s21_isnan(x)) {
        res = S21_NAN;
    } else if (x <= -100) {
        res = 0;
    } else if (x >= 710) {
        res = S21_INFINITY;
    } else {
        int indic = x < 0;
        if (indic) x *= -1;
        long double result = 1;
        double tmp = x;
        unsigned flag = 1;
        while ((s21_fabs(tmp) > S21_EPS)) {
            result += tmp;
            tmp = (tmp * x) / ++flag;
            if (x > 707 && flag > 650)
                break;
        }
        res = indic ? (1 / result) : result;
    }
    return res;
}
