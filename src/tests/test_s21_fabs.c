#include "s21_tests.h"


START_TEST(test_s21_fabs1) {
    long double s21_result = s21_fabs(-1.0);
    long double result = fabs(-1.0);
    ck_assert_ldouble_eq(s21_result, result);
} END_TEST

START_TEST(test_s21_fabs2) {
    long double s21_result = s21_fabs(0.0);
    long double result = fabs(0.0);
    ck_assert_ldouble_eq(s21_result, result);
} END_TEST

START_TEST(test_s21_fabs3) {
    long double s21_result = s21_fabs(1.0);
    long double result = fabs(1.0);
    ck_assert_ldouble_eq(s21_result, result);
} END_TEST

START_TEST(test_s21_fabs4) {
    long double s21_result = s21_fabs(123456789123456789123456789.123456789123456789);
    long double result = fabs(123456789123456789123456789.123456789123456789);
    ck_assert_ldouble_eq(s21_result, result);
} END_TEST

START_TEST(test_s21_fabs5) {
    ck_assert(s21_fabs(S21_NAN));
} END_TEST

START_TEST(test_s21_fabs6) {
    long double s21_result = s21_fabs(S21_INFINITY);
    long double result = fabs(INFINITY);
    ck_assert_ldouble_eq(s21_result, result);
} END_TEST

START_TEST(test_s21_fabs7) {
    long double s21_result = s21_fabs(-S21_INFINITY);
    long double result = fabs(-INFINITY);
    ck_assert_ldouble_eq(s21_result, result);
} END_TEST

START_TEST(test_s21_fabs8) {
    long double s21_result = s21_fabs(0.000000003);
    long double result = fabs(0.000000003);
    ck_assert_ldouble_eq(s21_result, result);
} END_TEST

START_TEST(test_s21_fabs9) {
    long double s21_result = s21_fabs(-0.000000003);
    long double result = fabs(-0.000000003);
    ck_assert_ldouble_eq(s21_result, result);
} END_TEST

START_TEST(test_s21_fabs10) {
    long double s21_result = s21_fabs(-2.22507e-308);
    long double result = fabs(-2.22507e-308);
    ck_assert_ldouble_eq(s21_result, result);
} END_TEST

START_TEST(test_s21_fabs11) {
    long double s21_result = s21_fabs(2.22507e-308);
    long double result = fabs(2.22507e-308);
    ck_assert_ldouble_eq(s21_result, result);
} END_TEST

Suite *s21_fabs_suite(void) {
    Suite *fabs = suite_create("s21_fabs");
    TCase *tc_fabs;
    tc_fabs = tcase_create("test_fabs");
    tcase_add_test(tc_fabs, test_s21_fabs1);
    tcase_add_test(tc_fabs, test_s21_fabs2);
    tcase_add_test(tc_fabs, test_s21_fabs3);
    tcase_add_test(tc_fabs, test_s21_fabs4);
    tcase_add_test(tc_fabs, test_s21_fabs5);
    tcase_add_test(tc_fabs, test_s21_fabs6);
    tcase_add_test(tc_fabs, test_s21_fabs7);
    tcase_add_test(tc_fabs, test_s21_fabs8);
    tcase_add_test(tc_fabs, test_s21_fabs9);
    tcase_add_test(tc_fabs, test_s21_fabs10);
    tcase_add_test(tc_fabs, test_s21_fabs11);
    suite_add_tcase(fabs, tc_fabs);
    return fabs;
}
