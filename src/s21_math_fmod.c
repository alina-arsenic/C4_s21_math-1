#include <stdio.h>
#include <math.h>

long double s21_fmod(double x, double y);

int main () {
    double x = 5323.5323;
    double y = 71.61323;
    printf("%Lf\n", s21_fmod(x, y));
    printf("%f\n", fmod(x, y));
    return 0;
}

long double s21_fmod(double x, double y) {
    int div = x / y;
    return x - div * y;
}
