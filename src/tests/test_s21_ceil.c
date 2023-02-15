/*
checking ceil
Copyright 2022

nidorina@student.21-school.ru
*/
#include "s21_tests.h"

START_TEST(test_s21_ceil) {
    srand((unsigned int)time(NULL));
    long double x = -S21_INFINITY;
    ck_assert_ldouble_eq(s21_ceil(x), ceil(x));
    x = S21_INFINITY;
    ck_assert_ldouble_eq(s21_ceil(x), ceil(x));
    x = S21_NAN;
    ck_assert_ldouble_nan(s21_ceil(x));
    for (int i = 0; i < 200; i++) {
        x = ((long double)rand() / (long double)(RAND_MAX)) * INT16_MAX;
        ck_assert_ldouble_eq(s21_ceil(x), ceil(x));
        x = -((long double)rand() / (long double)(RAND_MAX)) * INT16_MAX;
        ck_assert_ldouble_eq(s21_ceil(x), ceil(x));
        // printf("%.7Lf\n", x);
    }
}
END_TEST

Suite *s21_ceil_suite(void) {
    Suite *ceil = suite_create("s21_ceil");
    TCase *tc_ceil;
    tc_ceil = tcase_create("test_ceil");
    tcase_add_test(tc_ceil, test_s21_ceil);
    suite_add_tcase(ceil, tc_ceil);
    return ceil;
}
