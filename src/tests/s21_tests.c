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
    SRunner *sr;

    fabs = s21_fabs_suite();
    log = s21_log_suite();
    sqrt = s21_sqrt_suite();
    abs = s21_abs_suite();
    ceil = s21_ceil_suite();
    asin = s21_asin_suite();

    sr = srunner_create(fabs);
    srunner_add_suite(sr, log);
    srunner_add_suite(sr, sqrt);
    srunner_add_suite(sr, abs);
    srunner_add_suite(sr, ceil);
    srunner_add_suite(sr, asin);
    srunner_run_all(sr, CK_ENV);
    number_failed = srunner_ntests_failed(sr);
    srunner_free(sr);
    return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
