#include <stdio.h>
#include <math.h>

long double s21_pow(double base, double exp);

int main () {
    double x = 2;
    double y = 512;
    printf("%Lf\n", s21_pow(x, y));
    printf("%f\n", pow(x, y));
    return 0;
}

long double s21_pow(double base, double exp) {
    double res = base;
    if (exp != 0) {
        for (double i = exp > 0 ? exp : exp * -1; i > 1; i--) {
            res *= base;
        }
    } else {
        res = 1;
    }
    return exp < 0 ? 1 / res : res;
}