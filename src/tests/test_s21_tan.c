#include "s21_tests.h"

START_TEST(test_s21_tan_1) {
    ck_assert_ldouble_infinite(s21_tan(S21_M_PI_2));
} END_TEST

START_TEST(test_s21_tan_2) {
    ck_assert_ldouble_eq_tol(s21_tan(0), tan(0), 1e-5);
} END_TEST

START_TEST(test_s21_tan_3) {
    ck_assert_ldouble_eq_tol(s21_tan(-1.1), tan(-1.1), 1e-5);
} END_TEST

START_TEST(test_s21_tan_4) {
    ck_assert_ldouble_eq_tol(s21_tan(99999999), tan(99999999), 1e-5);
} END_TEST

START_TEST(test_s21_tan_5) {
    ck_assert_ldouble_eq_tol(s21_tan(-1.111111), tan(-1.111111), 1e-5);
} END_TEST

START_TEST(test_s21_tan_6) {
    ck_assert_ldouble_nan(s21_tan(-S21_INFINITY));
} END_TEST

START_TEST(test_s21_tan_7) {
    ck_assert_ldouble_nan(s21_tan(S21_INFINITY));
} END_TEST

START_TEST(test_s21_tan_8) {
    ck_assert_ldouble_nan(s21_tan(S21_NAN));
} END_TEST

START_TEST(test_s21_tan_9) {
    ck_assert_ldouble_eq_tol(s21_tan(12345578.123455), tan(12345578.123455), 1e-5);
} END_TEST

START_TEST(test_s21_tan_10) {
    ck_assert_ldouble_eq_tol(s21_tan(-12345578.123455), tan(-12345578.123455), 1e-5);
} END_TEST

Suite *s21_tan_suite(void) {
    Suite *tan = suite_create("s21_tan");
    TCase *tc_tan;
    tc_tan = tcase_create("test_tan");
    tcase_add_test(tc_tan, test_s21_tan_1);
    tcase_add_test(tc_tan, test_s21_tan_2);
    tcase_add_test(tc_tan, test_s21_tan_3);
    tcase_add_test(tc_tan, test_s21_tan_4);
    tcase_add_test(tc_tan, test_s21_tan_5);
    tcase_add_test(tc_tan, test_s21_tan_6);
    tcase_add_test(tc_tan, test_s21_tan_7);
    tcase_add_test(tc_tan, test_s21_tan_8);
    tcase_add_test(tc_tan, test_s21_tan_9);
    tcase_add_test(tc_tan, test_s21_tan_10);
    suite_add_tcase(tan, tc_tan);
    return tan;
}
