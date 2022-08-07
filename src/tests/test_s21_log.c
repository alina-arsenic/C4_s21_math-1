#include "s21_tests.h"


START_TEST(test_s21_log1) {
    long double s21_result = s21_log(S21_E);
    long double result = log(S21_E);
    ck_assert_ldouble_eq(s21_result, result);
} END_TEST

START_TEST(test_s21_log2) {
    long double s21_result = s21_log(0.0);
    long double result = log(0.0);
    ck_assert_ldouble_eq(s21_result, result);
} END_TEST

START_TEST(test_s21_log3) {
    long double s21_result = s21_log(1.0);
    long double result = log(1.0);
    ck_assert_ldouble_eq(s21_result, result);
} END_TEST

START_TEST(test_s21_log4) {
    long double s21_result = s21_log(123456789123456789123456789.123456789123456789);
    long double result = log(123456789123456789123456789.123456789123456789);
    ck_assert_ldouble_eq_tol(s21_result, result, 1e-6);
} END_TEST

START_TEST(test_s21_log5) {
    ck_assert(s21_log(S21_NAN));
} END_TEST

START_TEST(test_s21_log6) {
    long double s21_result = s21_log(S21_INFINITY);
    long double result = log(INFINITY);
    ck_assert_ldouble_eq(s21_result, result);
} END_TEST

START_TEST(test_s21_log7) {
    long double s21_result = s21_log(-S21_INFINITY);
    ck_assert_ldouble_nan(s21_result);
} END_TEST

START_TEST(test_s21_log8) {
    long double s21_result = s21_log(0.3);
    long double result = log(0.3);
    ck_assert_ldouble_eq_tol(s21_result, result, 1e-6);
} END_TEST

START_TEST(test_s21_log9) {
    long double s21_result = s21_log(S21_E*5);
    long double result = log(S21_E*5);
    ck_assert_ldouble_eq_tol(s21_result, result, 1e-6);
} END_TEST

START_TEST(test_s21_log10) {
    long double s21_result = s21_log(123456789);
    long double result = log(123456789);
    ck_assert_ldouble_eq_tol(s21_result, result, 1e-6);
} END_TEST

Suite *s21_log_suite(void) {
    Suite *s = suite_create("s21_log");
    TCase *tc_log;
    tc_log = tcase_create("test_log");
    tcase_add_test(tc_log, test_s21_log1);
    tcase_add_test(tc_log, test_s21_log2);
    tcase_add_test(tc_log, test_s21_log3);
    tcase_add_test(tc_log, test_s21_log4);
    tcase_add_test(tc_log, test_s21_log5);
    tcase_add_test(tc_log, test_s21_log6);
    tcase_add_test(tc_log, test_s21_log7);
    tcase_add_test(tc_log, test_s21_log8);
    tcase_add_test(tc_log, test_s21_log9);
    tcase_add_test(tc_log, test_s21_log10);
    suite_add_tcase(s, tc_log);
    return s;
}
