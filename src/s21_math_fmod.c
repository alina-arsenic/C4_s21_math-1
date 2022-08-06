#include <stdio.h>
#include <math.h>

long double s21_fmod(double x, double y);

int main () {
    double x = 53.5;
    double y = 7.61;
    printf("%Lf\n", s21_fmod(x, y));
    printf("%f\n", fmod(x, y));
    return 0;
}

long double s21_fmod(double x, double y) {
	int i_x = (int) x;
	int i_y = (int) y;
	return (long double)((i_x % i_y) + ((x - i_x) - (y - i_y)));
}
