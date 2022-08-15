#include "s21_math.h"


long double s21_log(double x) {
    const double eps = 1.0e-7;
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
    } else if (x == S21_E) {
        result = 1;
    } else {
        int a = 0;
        while (x >= 2.0) {
            a++;
            x /= S21_E;
        }
        double t = x - 1;
        double u = t;
        double lnabsx = u;
        int n = 1;
        while (u > eps || u < -eps) {
            n++;
            u *= -((n - 1) * t) / n;
            lnabsx += u;
        }
        result = a + lnabsx;
    }
    return result;
}
