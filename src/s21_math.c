#include "s21_math.h"
#include <math.h>

long double s21_acos(double x) {
	long double result = 0;
	if (x > 1.0 || x < -1.0)
		result = S21_NAN;
	else if (x == 1)
		result = 0.0;
	else if (x == -1)
		result = S21_PI;
	else
		result = S21_PI / 2 - asin(x);
	return result;
}

long double s21_exp(double x) {
    long double res = 0;
    if (x < 0) {
        res = 1 / s21_exp((-1) * x);
    } else {
        for (int k = 0; k < 2000; ++k) {
            double current = 1;
            for (int j = 1; j <= k; ++j) {
                current *= x;
                current /= j;
            }
            res += current;
        }
    }
    return res;
}

long double s21_sin(double x) {
    x = fmod(x, 2 * S21_PI);
    long double result = 0;
    long double temp = x;
    unsigned flag = 1;
    while (flag < 1000) {
        result += temp;
        flag += 2;
        temp *= -(x * x) / ((flag - 1) * flag);
    }
    return result;
}
