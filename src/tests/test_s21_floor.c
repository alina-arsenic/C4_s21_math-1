#include "s21_tests.h"

START_TEST(test_s21_floor_1) {
    ck_assert_ldouble_eq_tol(s21_floor(S21_M_PI), floor(S21_M_PI), 1e-6);
} END_TEST

START_TEST(test_s21_floor_2) {
    ck_assert_ldouble_eq_tol(s21_floor(0), floor(0), 1e-6);
} END_TEST

START_TEST(test_s21_floor_3) {
    ck_assert_ldouble_eq_tol(s21_floor(-1), floor(-1), 1e-6);
} END_TEST

START_TEST(test_s21_floor_4) {
    ck_assert_ldouble_eq_tol(s21_floor(99999999), floor(99999999), 1e-6);
} END_TEST

START_TEST(test_s21_floor_5) {
    ck_assert_ldouble_eq_tol(s21_floor(-1.111111), floor(-1.111111), 1e-6);
} END_TEST

START_TEST(test_s21_floor_6) {
    ck_assert_ldouble_infinite(s21_floor(-S21_INFINITY));
} END_TEST

START_TEST(test_s21_floor_7) {
    ck_assert_ldouble_infinite(s21_floor(S21_INFINITY));
} END_TEST

START_TEST(test_s21_floor_8) {
    ck_assert_ldouble_nan(s21_floor(S21_NAN));
} END_TEST

START_TEST(test_s21_floor_9) {
    ck_assert_ldouble_eq_tol(s21_floor(12345678.123456), floor(12345678.123456), 1e-6);
} END_TEST

START_TEST(test_s21_floor_10) {
    ck_assert_ldouble_eq_tol(s21_floor(-12345678.123456), floor(-12345678.123456), 1e-6);
} END_TEST

Suite *s21_floor_suite(void) {
    Suite *floor = suite_create("s21_floor");
    TCase *tc_floor;
    tc_floor = tcase_create("test_floor");
    tcase_add_test(tc_floor, test_s21_floor_1);
    tcase_add_test(tc_floor, test_s21_floor_2);
    tcase_add_test(tc_floor, test_s21_floor_3);
    tcase_add_test(tc_floor, test_s21_floor_4);
    tcase_add_test(tc_floor, test_s21_floor_5);
    tcase_add_test(tc_floor, test_s21_floor_6);
    tcase_add_test(tc_floor, test_s21_floor_7);
    tcase_add_test(tc_floor, test_s21_floor_8);
    tcase_add_test(tc_floor, test_s21_floor_9);
    tcase_add_test(tc_floor, test_s21_floor_10);
    suite_add_tcase(floor, tc_floor);
    return floor;
}
