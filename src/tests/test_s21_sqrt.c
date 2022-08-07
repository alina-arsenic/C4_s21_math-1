#include "s21_tests.h"


START_TEST(test_s21_sqrt1) {
    long double s21_result = s21_sqrt(-1.0);
    long double result = sqrt(-1.0);
    ck_assert_ldouble_nan(s21_result);
    ck_assert_ldouble_nan(result);
} END_TEST

START_TEST(test_s21_sqrt2) {
    long double s21_result = s21_sqrt(0.0);
    long double result = sqrt(0.0);
    ck_assert_ldouble_eq(s21_result, result);
} END_TEST

START_TEST(test_s21_sqrt3) {
    long double s21_result = s21_sqrt(1.0);
    long double result = sqrt(1.0);
    ck_assert_ldouble_eq_tol(s21_result, result, 1e-6);
} END_TEST

START_TEST(test_s21_sqrt4) {
    long double s21_result = s21_sqrt(12345678912345.1234567891);
    long double result = sqrt(12345678912345.1234567891);
    ck_assert_ldouble_eq_tol(s21_result, result, 1e-6);
} END_TEST

START_TEST(test_s21_sqrt5) {
    ck_assert(s21_sqrt(S21_NAN));
} END_TEST

START_TEST(test_s21_sqrt6) {
    long double s21_result = s21_sqrt(S21_INFINITY);
    long double result = sqrt(INFINITY);
    ck_assert_ldouble_eq(s21_result, result);
} END_TEST

START_TEST(test_s21_sqrt7) {
    long double s21_result = s21_sqrt(-S21_INFINITY);
    long double result = sqrt(-INFINITY);
    ck_assert_ldouble_nan(s21_result);
    ck_assert_ldouble_nan(result);
} END_TEST

START_TEST(test_s21_sqrt8) {
    long double s21_result = s21_sqrt(0.00003);
    long double result = sqrt(0.00003);
    ck_assert_ldouble_eq_tol(s21_result, result, 1e-6);
} END_TEST

START_TEST(test_s21_sqrt9) {
    long double s21_result = s21_sqrt(12345);
    long double result = sqrt(12345);
    ck_assert_ldouble_eq_tol(s21_result, result, 1e-6);
} END_TEST

START_TEST(test_s21_sqrt10) {
    long double s21_result = s21_sqrt(10000000000);
    long double result = sqrt(10000000000);
    ck_assert_ldouble_eq_tol(s21_result, result, 1e-6);
} END_TEST

START_TEST(test_s21_sqrt11) {
    long double s21_result = s21_sqrt(123123);
    long double result = sqrt(123123);
    ck_assert_ldouble_eq_tol(s21_result, result, 1e-6);
} END_TEST

START_TEST(test_s21_sqrt12) {
    long double s21_result = s21_sqrt(S21_E);
    long double result = sqrt(S21_E);
    ck_assert_ldouble_eq_tol(s21_result, result, 1e-6);
} END_TEST

START_TEST(test_s21_sqrt13) {
    long double s21_result = s21_sqrt(0.00123);
    long double result = sqrt(0.00123);
    ck_assert_ldouble_eq_tol(s21_result, result, 1e-6);
} END_TEST

START_TEST(test_s21_sqrt14) {
    long double s21_result = s21_sqrt(0.1);
    long double result = sqrt(0.1);
    ck_assert_ldouble_eq_tol(s21_result, result, 1e-6);
} END_TEST

Suite *s21_sqrt_suite(void) {
    Suite *s = suite_create("s21_sqrt");
    TCase *tc_sqrt;
    tc_sqrt = tcase_create("test_sqrt");
    tcase_add_test(tc_sqrt, test_s21_sqrt1);
    tcase_add_test(tc_sqrt, test_s21_sqrt2);
    tcase_add_test(tc_sqrt, test_s21_sqrt3);
    tcase_add_test(tc_sqrt, test_s21_sqrt4);
    tcase_add_test(tc_sqrt, test_s21_sqrt5);
    tcase_add_test(tc_sqrt, test_s21_sqrt6);
    tcase_add_test(tc_sqrt, test_s21_sqrt7);
    tcase_add_test(tc_sqrt, test_s21_sqrt8);
    tcase_add_test(tc_sqrt, test_s21_sqrt9);
    tcase_add_test(tc_sqrt, test_s21_sqrt10);
    tcase_add_test(tc_sqrt, test_s21_sqrt11);
    tcase_add_test(tc_sqrt, test_s21_sqrt12);
    tcase_add_test(tc_sqrt, test_s21_sqrt13);
    tcase_add_test(tc_sqrt, test_s21_sqrt14);
    suite_add_tcase(s, tc_sqrt);
    return s;
}
