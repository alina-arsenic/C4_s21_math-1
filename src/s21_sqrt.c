#include "s21_math.h"


long double s21_sqrt(double x) {
    double result = 0;
    double right = x;
    double root = 0;
    if (x != x || x < 0) {
        result = S21_NAN;
    } else if (x == 0) {
        result = x;
    } else {
        if (x < 1)
            right = 1;
        while (right - result > 1e-7) {
            root = (right + result)/2;
            if (root * root  > x) {
                right = root;
            } else {
                result = root;
            }
        }
    }
    return result;
}
