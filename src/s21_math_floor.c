#include <stdio.h>
#include <math.h>

long double s21_floor(double x);

int main () {
    double x = 12.9;
    printf("%Lf\n", s21_floor(x));
    printf("%f\n", floor(x));
    return 0;
}

long double s21_floor(double x) {
    int y = (int) x;
    if (x < 0) {
        y -= 1;
    }
    return (long double)y;
}