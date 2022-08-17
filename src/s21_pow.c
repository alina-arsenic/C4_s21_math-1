// by workerwa
#include "s21_math.h"
#include <math.h>

long double s21_pow(double base, double exp) {
    return pow(base, exp);
}

/*  workerwa's ver

long double s21_pow(double base, double exp) {
    long double res = base;
    if (exp != 0) {
        for (int i = exp > 0 ? exp : exp * -1; i > 1; i--) {
            res *= base;
        }
    } else {
        res = 1;
    }
    return exp < 0 ? 1 / res : res;
}
*/

/* weaveryu's try to improve

long double s21_pow(double base, double exp) {
    long double result;
    if ((s21_isinf(base) || s21_isinf(exp) || s21_isnan(base) || s21_isnan(exp)) && exp != 0) {
        result = S21_NAN;
    } else {
        long double res = base;
        if (exp != 0) {
            for (int i = exp > 0 ? exp : exp * -1; i > 1; i--) {
                res *= base;
            }
        } else {
            res = 1;
        }
        result = exp < 0 ? 1 / res : res;
    }
    return result;
}*/
