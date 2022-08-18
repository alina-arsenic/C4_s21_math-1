#ifndef SRC_S21_MATH_H_
#define SRC_S21_MATH_H_

#include <float.h>

#define S21_M_E         2.71828182845904523536028747135266250   // e
#define S21_M_LOG2E     1.44269504088896340735992468100189214   // log2(e)
#define S21_M_LOG10E    0.434294481903251827651128918916605082  // log10(e)
#define S21_M_LN2       0.693147180559945309417232121458176568  // loge(2)
#define S21_M_LN10      2.30258509299404568401799145468436421   // loge(10)
#define S21_M_PI        3.14159265358979323846264338327950288   // pi
#define S21_M_PI_2      1.57079632679489661923132169163975144   // pi/2
#define S21_M_PI_4      0.785398163397448309615660845819875721  // pi/4
#define S21_M_1_PI      0.318309886183790671537767526745028724  // 1/pi
#define S21_M_2_PI      0.636619772367581343075535053490057448  // 2/pi
#define S21_M_2_SQRTPI  1.12837916709551257389615890312154517   // 2/sqrt(pi)
#define S21_M_SQRT2     1.41421356237309504880168872420969808   // sqrt(2)
#define S21_M_SQRT1_2   0.707106781186547524400844362104849039  // 1/sqrt(2)

#define S21_EPS 1e-8
#define S21_ACCUR 1e-13
#define S21_NAN 0.0 / 0.0
#define S21_INFINITY 1.0 / 0.0

#define s21_isnormal(x) __builtin_isnormal((double)(x))

#define s21_isinf(x) __builtin_isinf((double)(x))

#define s21_isnan(x) __builtin_isnan((double)(x))

#define is_finite(x) __builtin_isfinite(x)

int s21_abs(int x);  // вычисляет абсолютное значение целого числа
long double s21_acos(double x);   // вычисляет арккосинус
long double s21_asin(double x);   // вычисляет арксинус
long double s21_atan(double x);   // вычисляет арктангенс
long double s21_ceil(double x);   // возвращает ближайшее целое число, не меньшее заданного значения
long double s21_cos(double x);    // вычисляет косинус
long double s21_exp(double x);    // возвращает значение e, возведенное в заданную степень
long double s21_fabs(double x);   // вычисляет абсолютное значение числа с плавающей точкой
long double s21_floor(double x);  // возвращает ближайшее целое число, не превышающее заданное значение
long double s21_fmod(double x, double y);  // остаток операции деления с плавающей точкой
long double s21_log(double x);    // вычисляет натуральный логарифм
long double s21_pow(double base, double exp);  // возводит число в заданную степень
long double s21_sin(double x);    // вычисляет синус
long double s21_sqrt(double x);   // вычисляет квадратный корень
long double s21_tan(double x);    // вычисляет тангенс

#endif  // SRC_S21_MATH_H_
