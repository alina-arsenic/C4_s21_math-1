// by yoghurtb
#include "s21_math.h"

long double s21_log(double x) {
    long double result;
    if (x == 0.0) {
        result = -S21_INFINITY;
    } else if (x != x && x == -S21_INFINITY) {
        result = S21_NAN;
    } else if (x < 0.0) {
        result = S21_NAN;
    } else if (x == 1) {
        result = 0;
    } else if (x == S21_INFINITY) {
        result = S21_INFINITY;
    } else if (x == S21_M_E) {
        result = 1;
    } else {
        int a = 0;
        while (x >= 2.0) {
            a++;
            x /= S21_M_E;
        }
        double t = x - 1;
        double u = t;
        double lnabsx = u;
        int n = 1;
        while (u > S21_EPS || u < -S21_EPS) {
            n++;
            u *= -((n - 1) * t) / n;
            lnabsx += u;
        }
        result = a + lnabsx;
    }
    return result;
}
