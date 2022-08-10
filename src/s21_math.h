#ifndef SRC_S21_MATH_H_
#define SRC_S21_MATH_H_

#define s21_EPS 1e-17
#define s21_PI 3.1415926535897932

#define s21_NULL (void *)0
#define s21_INF 1.0 / 0.0
#define s21_MINUSINF -1.0 / 0.0
#define s21_NAN 0.0 / 0.0

#define s21_IS_INF(x) __builtin_isinf(x)

typedef long unsigned s21_size_t;

int s21_abs(int i);
long double s21_ceil(double x);
int s21_isnan(long double number);
long double s21_fabs(double x);
long double s21_asin(double x);
long double tailor_row_asin(long double x);

#endif  // SRC_S21_MATH_H_
