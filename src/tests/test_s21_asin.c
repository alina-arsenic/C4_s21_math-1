/*
checking asin
Copyright 2022

nidorina@student.21-school.ru
*/
#include "s21_tests.h"

START_TEST(test_s21_asin) {
    srand((unsigned int)time(NULL));
    long double x = 0;
    ck_assert_ldouble_eq(s21_asin(x), asin(x));
    x = -1;
    ck_assert_ldouble_eq(s21_asin(x), asin(x));
    x = 1;
    ck_assert_ldouble_eq(s21_asin(x), asin(x));
    x = 1.1;
    ck_assert_ldouble_nan(s21_asin(x));
    x = 0.9998234;
    ck_assert_ldouble_lt(fabsl(s21_asin(x) - asin(x)), 1e-5);
}
END_TEST

Suite *s21_asin_suite(void) {
    Suite *asin = suite_create("s21_asin");
    TCase *tc_asin;
    tc_asin = tcase_create("test_asin");
    tcase_add_test(tc_asin, test_s21_asin);
    suite_add_tcase(asin, tc_asin);
    return asin;
}
