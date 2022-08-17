#include "s21_tests.h"

START_TEST(test_s21_fmod_1) {
    ck_assert_ldouble_nan(s21_fmod(0, 0));
} END_TEST

START_TEST(test_s21_fmod_2) {
    ck_assert_ldouble_eq_tol(s21_fmod(99999999, 12345678.123456), fmod(99999999, 12345678.123456), 1e-6);
} END_TEST

START_TEST(test_s21_fmod_3) {
    ck_assert_ldouble_eq_tol(s21_fmod(-99999999, 12345678.123456), fmod(-99999999, 12345678.123456), 1e-6);
} END_TEST

START_TEST(test_s21_fmod_4) {
    ck_assert_ldouble_eq_tol(s21_fmod(-99999999, -12345678.123456), fmod(-99999999, -12345678.123456), 1e-6);
} END_TEST

START_TEST(test_s21_fmod_5) {
    ck_assert_ldouble_eq_tol(s21_fmod(S21_M_PI, 1), fmod(S21_M_PI, 1), 1e-6);
} END_TEST

START_TEST(test_s21_fmod_6) {
    ck_assert_ldouble_nan(s21_fmod(S21_INFINITY, 0));
} END_TEST

START_TEST(test_s21_fmod_7) {
    ck_assert_ldouble_nan(s21_fmod(S21_NAN, S21_INFINITY));
} END_TEST

START_TEST(test_s21_fmod_8) {
    ck_assert_ldouble_nan(s21_fmod(S21_INFINITY, -S21_INFINITY));
} END_TEST

START_TEST(test_s21_fmod_9) {
    ck_assert_ldouble_nan(s21_fmod(S21_NAN, S21_NAN));
} END_TEST

START_TEST(test_s21_fmod_10) {
    ck_assert_ldouble_nan(s21_fmod(-1, 0));
} END_TEST

Suite *s21_fmod_suite(void) {
    Suite *fmod = suite_create("s21_fmod");
    TCase *tc_fmod;
    tc_fmod = tcase_create("test_fmod");
    tcase_add_test(tc_fmod, test_s21_fmod_1);
    tcase_add_test(tc_fmod, test_s21_fmod_2);
    tcase_add_test(tc_fmod, test_s21_fmod_3);
    tcase_add_test(tc_fmod, test_s21_fmod_4);
    tcase_add_test(tc_fmod, test_s21_fmod_5);
    tcase_add_test(tc_fmod, test_s21_fmod_6);
    tcase_add_test(tc_fmod, test_s21_fmod_7);
    tcase_add_test(tc_fmod, test_s21_fmod_8);
    tcase_add_test(tc_fmod, test_s21_fmod_9);
    tcase_add_test(tc_fmod, test_s21_fmod_10);
    suite_add_tcase(fmod, tc_fmod);
    return fmod;
}
