// by workerwa
#include "s21_math.h"

long double s21_pow_calc(double base, double exp) {
    long double result;
    long double base_copy = base;

    if (base < 0) {
        base_copy = -base_copy;
        result = s21_exp(exp * s21_log(base_copy));
        if (s21_fmod(exp, 2) != 0) result = -result;
    } else {
        result = s21_exp(exp * s21_log(base));
    }

    if (exp == 1) result = base;

    if (exp == 0) result = 1;

    return result;
}

long double s21_pow(double base, double exp) {
    int base_is_fin = is_finite(base);
    int exp_is_fin = is_finite(exp);
    int exp_int = s21_fabs(exp - s21_floor(exp)) <= S21_ACCUR;

    // exp is DBL_MAX
    if (base < 0 && (exp == DBL_MAX || exp == -DBL_MAX))
        return -s21_pow_calc(base, exp);

    // base ±0 returns +0 for exp > 0 and even integer or non-integer
    if ((s21_fabs(base) < S21_ACCUR) && (exp > S21_ACCUR) &&
        (((exp_int && !((int)exp) % 2)) || (!exp_int)))
        return +0;

    // exp is ±0 returns 1 for any base, even when base is NaN
    if (s21_fabs(exp) < S21_ACCUR) return 1;

    // base = 1 or base = -1 and exp = +-INF
    if ((base == 1) ||
        ((base == -1) && ((exp == +S21_INFINITY) || (exp == -S21_INFINITY))))
        return 1;

    // base is finite and negative and exp is finite and non-integer
    if (base_is_fin && base < -S21_ACCUR && exp_is_fin && !exp_int &&
        s21_fabs(exp) > 0)
        return S21_NAN;

    // |base| < 1 and exp is -INF or |base| > 1 and exp is +INF
    if ((s21_fabs(base) - 1 < S21_ACCUR && exp == -S21_INFINITY) ||
        (s21_fabs(base) - 1 > S21_ACCUR && exp == +S21_INFINITY))
        return +S21_INFINITY;

    // |base| > 1 and exp is -INF or |base| < 1 and exp is +INF
    if ((s21_fabs(base) - 1 > S21_ACCUR && exp == -S21_INFINITY) ||
        (s21_fabs(base) - 1 < S21_ACCUR && exp == +S21_INFINITY))
        return +0;

    // base is -INF returns +INF if exp is a positive non-integer or positive
    // even integer
    if ((base == -S21_INFINITY) && (exp > S21_ACCUR) &&
        (((exp_int && !((int)exp) % 2)) || (!exp_int)))
        return +S21_INFINITY;

    // base is -INF returns +0 if exp is a negative non-integer or negative even
    // integer
    if ((base == -S21_INFINITY) && (exp < S21_ACCUR) &&
        (((exp_int && !((int)exp) % 2)) || (!exp_int)))
        return +0;

    return s21_pow_calc(base, exp);
}
