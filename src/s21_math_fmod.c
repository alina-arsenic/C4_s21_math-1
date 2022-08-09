#include <stdio.h>
#include <math.h>

long double s21_fmod(double x, double y);

int main () {
    double x = 5323.5323;
    double y = 71.61323;
    printf("%.16Lf\n", s21_fmod(x, y));
    printf("%.16f\n", fmod(x, y));
    return 0;
}

long double s21_fmod(double x, double y) {
    long double l_x = x;
    long double l_y = y;
    long long div = x / y;
    return l_x - div * l_y;
}
