#include "s21_tests.h"

START_TEST(test_s21_cos_1) {
    ck_assert_ldouble_eq_tol(s21_cos(S21_M_PI), cos(S21_M_PI), 1e-6);
} END_TEST

START_TEST(test_s21_cos_2) {
    ck_assert_ldouble_eq_tol(s21_cos(0), cos(0), 1e-6);
} END_TEST

START_TEST(test_s21_cos_3) {
    ck_assert_ldouble_eq_tol(s21_cos(-1), cos(-1), 1e-6);
} END_TEST

START_TEST(test_s21_cos_4) {
    ck_assert_ldouble_eq_tol(s21_cos(99999999), cos(99999999), 1e-6);
} END_TEST

START_TEST(test_s21_cos_5) {
    ck_assert_ldouble_eq_tol(s21_cos(-1.111111), cos(-1.111111), 1e-6);
} END_TEST

START_TEST(test_s21_cos_6) {
    ck_assert_ldouble_nan(s21_cos(-S21_INFINITY));
} END_TEST

START_TEST(test_s21_cos_7) {
    ck_assert_ldouble_nan(s21_cos(S21_INFINITY));
} END_TEST

START_TEST(test_s21_cos_8) {
    ck_assert_ldouble_nan(s21_cos(S21_NAN));
} END_TEST

START_TEST(test_s21_cos_9) {
    ck_assert_ldouble_eq_tol(s21_cos(12345678.123456), cos(12345678.123456), 1e-6);
} END_TEST

START_TEST(test_s21_cos_10) {
    ck_assert_ldouble_eq_tol(s21_cos(-12345678.123456), cos(-12345678.123456), 1e-6);
} END_TEST

Suite *s21_cos_suite(void) {
    Suite *cos = suite_create("s21_cos");
    TCase *tc_cos;
    tc_cos = tcase_create("test_cos");
    tcase_add_test(tc_cos, test_s21_cos_1);
    tcase_add_test(tc_cos, test_s21_cos_2);
    tcase_add_test(tc_cos, test_s21_cos_3);
    tcase_add_test(tc_cos, test_s21_cos_4);
    tcase_add_test(tc_cos, test_s21_cos_5);
    tcase_add_test(tc_cos, test_s21_cos_6);
    tcase_add_test(tc_cos, test_s21_cos_7);
    tcase_add_test(tc_cos, test_s21_cos_8);
    tcase_add_test(tc_cos, test_s21_cos_9);
    tcase_add_test(tc_cos, test_s21_cos_10);
    suite_add_tcase(cos, tc_cos);
    return cos;
}
