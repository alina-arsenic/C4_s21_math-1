#include "s21_math.h"
#include <math.h>

long double s21_acos(double x) {
    long double result = 0.0;
    if (x == 1.0) {
        return 0;
    } else if (x == -1.0) {
        return S21_PI;
    } else if (x == 0) {
        return S21_CONST_1;
    } else if (x == S21_CONST_SQ) {
        return S21_CONST_2;
    } else if (x == -S21_CONST_SQ) {
        return 3 * S21_CONST_2;
    }

    if (0.0 < x && x < 1.0) {
        result = atan(sqrt(1 - x * x) / x);
    } else if (-1. < x && x < 0.) {
        result = S21_PI + atan(sqrt(1 - x * x) / x);
    } else {
        result = S21_NAN;
    }

    return result;
}

long double s21_exp(double x) {
  if (S21_isnan(x)) return S21_NAN;
  if (S21_isinf(x)) return x < 0 ? 0 : S21_INF;
  int indic = x < 0;
  if (indic) x *= -1;
  long double result = 1;
  double tmp = x;
  unsigned flag = 1;
  while (fabs(tmp) >= S21_EPS) {
    result += tmp;
    tmp = (tmp * x) / ++flag;
  }
  return indic ? (1 / result) : result;
}

long double s21_sin(double x) {
    x = fmod(x, 2 * S21_PI);
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
