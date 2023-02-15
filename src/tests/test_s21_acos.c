#include "s21_tests.h"

START_TEST(s21_acos_0001) {
    long double x = S21_M_SQRT1_2;
    long double res = acos(x), s21_res = s21_acos(x);

    ck_assert_ldouble_eq(res, s21_res);
} END_TEST

START_TEST(s21_acos_0002) {
    int ret = 0;
    double x = 1.3;
    long double res = acos(x), s21_res = s21_acos(x);

    if (isnan(res) == isnan(s21_res)) ret = 1;

    ck_assert_int_eq(1, ret);
} END_TEST

START_TEST(s21_acos_0003) {
    int ret = 0;
    double x = -1.8;
    long double res = acos(x), s21_res = s21_acos(x);

    if (isnan(res) == isnan(s21_res)) ret = 1;

    ck_assert_int_eq(1, ret);
} END_TEST

START_TEST(s21_acos_0004) {
    double x = -0.12;
    long double res = acos(x), s21_res = s21_acos(x);

    ck_assert_double_eq_tol(s21_res, res, S21_EPS);
} END_TEST

START_TEST(s21_acos_0005) {
    double x = 0.43;
    long double res = acos(x), s21_res = s21_acos(x);

    ck_assert_double_eq_tol(s21_res, res, S21_EPS);
} END_TEST

START_TEST(s21_acos_0006) {
    int ret = 0;
    long double x = 1.;
    long double res = acos(x), s21_res = s21_acos(x);

    if (isnan(res) == isnan(s21_res)) ret = 1;

    ck_assert_ldouble_eq(1, ret);
} END_TEST

START_TEST(s21_acos_0007) {
    int ret = 0;
    long double x = -1.;
    long double res = acos(x), s21_res = s21_acos(x);

    if (isnan(res) == isnan(s21_res)) ret = 1;

    ck_assert_ldouble_eq(1, ret);
} END_TEST

START_TEST(s21_acos_0008) {
    long double x = 0;
    long double res = acos(x), s21_res = s21_acos(x);

    ck_assert_ldouble_eq(res, s21_res);
} END_TEST

START_TEST(s21_acos_0009) {
    long double x = 0.999999;
    long double res = acos(x), s21_res = s21_acos(x);

    ck_assert_ldouble_lt(fabsl(res - s21_res), 1e-6);
} END_TEST

START_TEST(s21_acos_0010) {
    int ret = 0;
    long double x = 1.5;
    long double res = acos(x), s21_res = s21_acos(x);

    if (isnan(res) == isnan(s21_res)) ret = 1;

    ck_assert_ldouble_eq(1, ret);
} END_TEST

START_TEST(s21_acos_0011) {
    int ret = 0;
    long double x = -1.5;
    long double res = acos(x), s21_res = s21_acos(x);

    if (isnan(res) == isnan(s21_res)) ret = 1;

    ck_assert_ldouble_eq(1, ret);
} END_TEST

Suite *s21_acos_suite(void) {
    Suite *acos = suite_create("s21_acos");
    TCase *tc_s21_acos;
    tc_s21_acos = tcase_create("test_acos");
    tcase_add_test(tc_s21_acos, s21_acos_0001);
    tcase_add_test(tc_s21_acos, s21_acos_0002);
    tcase_add_test(tc_s21_acos, s21_acos_0003);
    tcase_add_test(tc_s21_acos, s21_acos_0004);
    tcase_add_test(tc_s21_acos, s21_acos_0005);
    tcase_add_test(tc_s21_acos, s21_acos_0006);
    tcase_add_test(tc_s21_acos, s21_acos_0007);
    tcase_add_test(tc_s21_acos, s21_acos_0008);
    tcase_add_test(tc_s21_acos, s21_acos_0009);
    tcase_add_test(tc_s21_acos, s21_acos_0010);
    tcase_add_test(tc_s21_acos, s21_acos_0011);
    suite_add_tcase(acos, tc_s21_acos);
    return acos;
}
