#include "../s21_math.h"
#include "s21_tests.h"

int main(void) {
    int number_failed;
    Suite *fabs;
    Suite *log;
    Suite *sqrt;
    Suite *abs;
    Suite *ceil;
    Suite *asin;
    Suite *sin;
    Suite *acos;
    Suite *exp;
    Suite *cos;
    Suite *tan;
    Suite *atan;
    Suite *pow;
    Suite *floor;
    Suite *fmod;
    SRunner *sr;

    fabs = s21_fabs_suite();
    log = s21_log_suite();
    sqrt = s21_sqrt_suite();
    abs = s21_abs_suite();
    ceil = s21_ceil_suite();
    asin = s21_asin_suite();
    sin = s21_sin_suite();
    acos = s21_acos_suite();
    exp = s21_exp_suite();
    cos = s21_cos_suite();
    tan = s21_tan_suite();
    atan = s21_atan_suite();
    pow = s21_pow_suite();
    floor = s21_floor_suite();
    fmod = s21_fmod_suite();

    sr = srunner_create(fabs);
    srunner_add_suite(sr, log);
    srunner_add_suite(sr, sqrt);
    srunner_add_suite(sr, abs);
    srunner_add_suite(sr, ceil);
    srunner_add_suite(sr, asin);
    srunner_add_suite(sr, sin);
    srunner_add_suite(sr, acos);
    srunner_add_suite(sr, exp);
    srunner_add_suite(sr, cos);
    srunner_add_suite(sr, tan);
    srunner_add_suite(sr, atan);
    srunner_add_suite(sr, pow);
    srunner_add_suite(sr, floor);
    srunner_add_suite(sr, fmod);
    srunner_run_all(sr, CK_ENV);
    number_failed = srunner_ntests_failed(sr);
    srunner_free(sr);
    return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
