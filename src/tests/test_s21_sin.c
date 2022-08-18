#include "s21_tests.h"

START_TEST(s21_sin_0001) {
    double x = 2.3;
    ck_assert_double_eq_tol(s21_sin(x), sin(x), 1e-6);
} END_TEST

START_TEST(s21_sin_0002) {
    ck_assert_double_eq_tol(s21_sin(0.0), sin(0), 1e-6);;
} END_TEST

START_TEST(s21_sin_0003) {
    ck_assert_double_eq_tol(s21_sin(1), sin(1), 1e-6);
} END_TEST

START_TEST(s21_sin_0004) {
    ck_assert_double_eq_tol(s21_sin(-1), sin(-1), 1e-6);
} END_TEST

START_TEST(s21_sin_0005) {
    ck_assert_double_eq_tol(s21_sin(0.234234123), sin(0.234234123), 1e-6);
} END_TEST

START_TEST(s21_sin_0006) {
    ck_assert_double_eq_tol(s21_sin(-0.99999), sin(-0.99999), 1e-6);
} END_TEST

START_TEST(s21_sin_0007) {
    ck_assert_ldouble_nan(s21_sin(NAN));
    ck_assert_ldouble_nan(sin(NAN));
} END_TEST

START_TEST(s21_sin_0008) {
    ck_assert_ldouble_nan(s21_sin(INFINITY));
    ck_assert_ldouble_nan(sin(INFINITY));
} END_TEST

START_TEST(s21_sin_0009) {
    ck_assert_ldouble_nan(s21_sin(-INFINITY));
    ck_assert_ldouble_nan(sin(-INFINITY));
} END_TEST

START_TEST(s21_sin_0010) {
    ck_assert_double_eq_tol(s21_sin(S21_M_PI / 6), sin(S21_M_PI / 6), S21_EPS);
} END_TEST

START_TEST(s21_sin_0011) {
    ck_assert_double_eq_tol(s21_sin(S21_M_PI / 4), sin(S21_M_PI / 4), S21_EPS);
} END_TEST

START_TEST(s21_sin_0012) {
    ck_assert_double_eq_tol(s21_sin(S21_M_PI / 3), sin(S21_M_PI / 3), S21_EPS);
} END_TEST

START_TEST(s21_sin_0013) {
    ck_assert_double_eq_tol(s21_sin(S21_M_PI / 2), sin(S21_M_PI / 2), S21_EPS);
} END_TEST

START_TEST(s21_sin_0014) {
    ck_assert_double_eq_tol(s21_sin(3 * S21_M_PI / 2), sin(3 * S21_M_PI / 2), S21_EPS);
} END_TEST

START_TEST(s21_sin_0015) {
    ck_assert_double_eq_tol(s21_sin(2 * S21_M_PI), sin(2 * S21_M_PI), S21_EPS);;
} END_TEST

START_TEST(s21_sin_0016) {
    ck_assert_double_eq_tol(s21_sin(-2 * S21_M_PI), sin(-2 * S21_M_PI), S21_EPS);
} END_TEST

START_TEST(s21_sin_0017) {
     ck_assert_double_eq_tol(s21_sin(-3 * S21_M_PI), sin(-3 * S21_M_PI), S21_EPS);
} END_TEST

START_TEST(s21_sin_0018) {
    ck_assert_double_eq_tol(s21_sin(424.532925199433), sin(424.532925199433), S21_EPS);
} END_TEST

START_TEST(s21_sin_0019) {
    ck_assert_double_eq_tol(s21_sin(-222.532925199433), sin(-222.532925199433), S21_EPS);
} END_TEST

START_TEST(s21_sin_0020) {
    ck_assert_double_eq_tol(s21_sin(-S21_M_PI), sin(-S21_M_PI), S21_EPS);
} END_TEST

Suite *s21_sin_suite(void) {
    Suite *sin = suite_create("s21_sin");
    TCase *tc_s21_sin;
    tc_s21_sin = tcase_create("test_sin");
    tcase_add_test(tc_s21_sin, s21_sin_0001);
    tcase_add_test(tc_s21_sin, s21_sin_0002);
    tcase_add_test(tc_s21_sin, s21_sin_0003);
    tcase_add_test(tc_s21_sin, s21_sin_0004);
    tcase_add_test(tc_s21_sin, s21_sin_0005);
    tcase_add_test(tc_s21_sin, s21_sin_0006);
    tcase_add_test(tc_s21_sin, s21_sin_0007);
    tcase_add_test(tc_s21_sin, s21_sin_0008);
    tcase_add_test(tc_s21_sin, s21_sin_0009);
    tcase_add_test(tc_s21_sin, s21_sin_0010);
    tcase_add_test(tc_s21_sin, s21_sin_0011);
    tcase_add_test(tc_s21_sin, s21_sin_0012);
    tcase_add_test(tc_s21_sin, s21_sin_0013);
    tcase_add_test(tc_s21_sin, s21_sin_0014);
    tcase_add_test(tc_s21_sin, s21_sin_0015);
    tcase_add_test(tc_s21_sin, s21_sin_0016);
    tcase_add_test(tc_s21_sin, s21_sin_0017);
    tcase_add_test(tc_s21_sin, s21_sin_0018);
    tcase_add_test(tc_s21_sin, s21_sin_0019);
    tcase_add_test(tc_s21_sin, s21_sin_0020);
    suite_add_tcase(sin, tc_s21_sin);
    return sin;
}
