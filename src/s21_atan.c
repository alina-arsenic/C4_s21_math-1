// by weaveryu
#include "s21_math.h"

long double s21_atan(double x) {
    double ax = s21_fabs(x);  // arctan(-x) = -arctan(x)
    double a = a = (ax > 1.0) ? 1.0/ax : ax;  // arctan(1/x) = pi/2 - arctan(x) if x > 0
    double k = 1;
    long double temp = 0, pred = 1;
    while (s21_fabs(pred-temp) > S21_EPS) {
        pred = temp;
        temp += s21_pow(a, k)/k - s21_pow(a, k+2)/(k+2);
        k += 4;
    }
    temp = s21_fmod(temp, S21_M_PI);
    long double result = (ax > 1.0) ? (S21_M_PI_2 - temp) : temp;
    int sign = (x < 0) ? -1 : 1;
    return sign*result;
}
