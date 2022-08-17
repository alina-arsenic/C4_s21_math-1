#include "s21_tests.h"

START_TEST(test_s21_atan_1) {
    ck_assert_ldouble_eq_tol(s21_atan(S21_M_PI), atan(S21_M_PI), 1e-6);
} END_TEST

START_TEST(test_s21_atan_2) {
    ck_assert_ldouble_eq_tol(s21_atan(0), atan(0), 1e-6);
} END_TEST

START_TEST(test_s21_atan_3) {
    ck_assert_ldouble_eq_tol(s21_atan(-1.2), atan(-1.2), 1e-6);
} END_TEST

START_TEST(test_s21_atan_4) {
    ck_assert_ldouble_eq_tol(s21_atan(99999999), atan(99999999), 1e-6);
} END_TEST

START_TEST(test_s21_atan_5) {
    ck_assert_ldouble_eq_tol(s21_atan(-1.111111), atan(-1.111111), 1e-6);
} END_TEST

START_TEST(test_s21_atan_6) {
    ck_assert_ldouble_eq_tol(s21_atan(-S21_INFINITY), atan(-S21_INFINITY), 1e-6);
} END_TEST

START_TEST(test_s21_atan_7) {
    ck_assert_ldouble_eq_tol(s21_atan(S21_INFINITY), atan(S21_INFINITY), 1e-6);
} END_TEST

START_TEST(test_s21_atan_8) {
    ck_assert_ldouble_nan(s21_atan(S21_NAN));
} END_TEST

START_TEST(test_s21_atan_9) {
    ck_assert_ldouble_eq_tol(s21_atan(12345678.123456), atan(12345678.123456), 1e-6);
} END_TEST

START_TEST(test_s21_atan_10) {
    ck_assert_ldouble_eq_tol(s21_atan(-12345678.123456), atan(-12345678.123456), 1e-6);
} END_TEST

Suite *s21_atan_suite(void) {
    Suite *atan = suite_create("s21_atan");
    TCase *tc_atan;
    tc_atan = tcase_create("test_atan");
    tcase_add_test(tc_atan, test_s21_atan_1);
    tcase_add_test(tc_atan, test_s21_atan_2);
    tcase_add_test(tc_atan, test_s21_atan_3);
    tcase_add_test(tc_atan, test_s21_atan_4);
    tcase_add_test(tc_atan, test_s21_atan_5);
    tcase_add_test(tc_atan, test_s21_atan_6);
    tcase_add_test(tc_atan, test_s21_atan_7);
    tcase_add_test(tc_atan, test_s21_atan_8);
    tcase_add_test(tc_atan, test_s21_atan_9);
    tcase_add_test(tc_atan, test_s21_atan_10);
    suite_add_tcase(atan, tc_atan);
    return atan;
}
