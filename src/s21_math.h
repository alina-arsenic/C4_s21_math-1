#ifndef SRC_S21_MATH_H_
#define SRC_S21_MATH_H_

# define S21_M_E        2.71828182845904523536   // e
# define S21_M_LOG2E    1.44269504088896340736   // log_2 e
# define S21_M_LOG10E   0.434294481903251827651  // log_10 e
# define S21_M_LN2      0.693147180559945309417  // log_e 2
# define S21_M_LN10     2.30258509299404568402   // log_e 10
# define S21_M_PI       3.14159265358979323846   // pi
# define S21_M_PI_2     1.57079632679489661923   // pi/2
# define S21_M_PI_4     0.785398163397448309616  // pi/4
# define S21_M_1_PI     0.318309886183790671538  // 1/pi
# define S21_M_2_PI     0.636619772367581343076  // 2/pi
# define S21_M_2_SQRTPI 1.12837916709551257390   // 2/sqrt(pi)
# define S21_M_SQRT2    1.41421356237309504880   // sqrt(2)
# define S21_M_SQRT1_2  0.707106781186547524401  // 1/sqrt(2)

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
