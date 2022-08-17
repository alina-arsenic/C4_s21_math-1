#include "s21_tests.h"

START_TEST(test_s21_pow_1) {
    ck_assert_ldouble_eq_tol(s21_pow(0, 0), pow(0, 0), 1e-6);
} END_TEST

// START_TEST(test_s21_pow_2) {
//     ck_assert_ldouble_infinite(s21_pow(99999999, 12345678.123456));
// } END_TEST

// START_TEST(test_s21_pow_3) {
//     ck_assert_ldouble_eq_tol(s21_pow(999, 12.123456), pow(999, 12.123456), 1e-6);
// } END_TEST

START_TEST(test_s21_pow_4) {
    ck_assert_ldouble_nan(s21_pow(-99, -1.123456));
} END_TEST

START_TEST(test_s21_pow_5) {
    ck_assert_ldouble_eq_tol(s21_pow(S21_M_PI, 1), pow(S21_M_PI, 1), 1e-6);
} END_TEST

START_TEST(test_s21_pow_6) {
    ck_assert_ldouble_eq_tol(s21_pow(S21_INFINITY, 0), pow(S21_INFINITY, 0), 1e-6);
} END_TEST

START_TEST(test_s21_pow_7) {
    ck_assert_ldouble_eq_tol(s21_pow(0, 2), pow(0, 2), 1e-6);
} END_TEST

// START_TEST(test_s21_pow_8) {
//     ck_assert_ldouble_eq_tol(s21_pow(12.123, 123.123456), pow(12.123, 123.123456), 1e-6);
// } END_TEST

START_TEST(test_s21_pow_9) {
    ck_assert_ldouble_nan(s21_pow(S21_NAN, S21_NAN));
} END_TEST

START_TEST(test_s21_pow_10) {
    ck_assert_ldouble_eq_tol(s21_pow(-1, 0), pow(-1, 0), 1e-6);
} END_TEST

START_TEST(test_s21_pow_11) {
    ck_assert_ldouble_infinite(s21_pow(0, -2));
} END_TEST

START_TEST(test_s21_pow_12) {
    ck_assert_ldouble_eq_tol(s21_pow(S21_INFINITY, -1), pow(S21_INFINITY, -1), 1e-6);
} END_TEST

START_TEST(pow_test_001) {
    double base = +0;
    double exp = -0;
    ck_assert_ldouble_eq_tol(s21_pow(base, exp), powl(base, exp), S21_EPS);
}
END_TEST

START_TEST(pow_test_002) {
    double base = +0;
    double exp = 4;
    ck_assert_ldouble_eq_tol(s21_pow(base, exp), powl(base, exp), S21_EPS);
}
END_TEST

START_TEST(pow_test_011) {
    double base = -0;
    double exp = -1;
    ck_assert_ldouble_infinite(powl(base, exp));
    ck_assert_ldouble_infinite(s21_pow(base, exp));
}
END_TEST

START_TEST(pow_test_021) {
    double base = 1;
    double exp = 169;
    ck_assert_ldouble_eq_tol(s21_pow(base, exp), powl(base, exp), S21_EPS);
}
END_TEST

START_TEST(pow_test_031) {
    double base = -1;
    double exp = -169;
    ck_assert_ldouble_eq_tol(s21_pow(base, exp), powl(base, exp), S21_EPS);
}
END_TEST

START_TEST(pow_test_041) {
    double base = 169;
    double exp = 0.88;
    ck_assert_ldouble_eq_tol(s21_pow(base, exp), powl(base, exp), S21_EPS);
}
END_TEST

START_TEST(pow_test_051) {
    double base = -169;
    double exp = -8.77;
    ck_assert_ldouble_nan(powl(base, exp));
    ck_assert_ldouble_nan(s21_pow(base, exp));
}
END_TEST

START_TEST(pow_test_052) {
    double base = -169;
    double exp = 0;
    ck_assert_ldouble_eq_tol(s21_pow(base, exp), powl(base, exp), S21_EPS);
}
END_TEST

START_TEST(pow_test_061) {
    double base = NAN;
    double exp = NAN;
    ck_assert_ldouble_nan(powl(base, exp));
    ck_assert_ldouble_nan(s21_pow(base, exp));
}
END_TEST

START_TEST(pow_test_071) {
    double base = INFINITY;
    double exp = 1;
    ck_assert_ldouble_infinite(powl(base, exp));
    ck_assert_ldouble_infinite(s21_pow(base, exp));
}
END_TEST

START_TEST(pow_test_081) {
    double base = -INFINITY;
    double exp = -0.88;
    ck_assert_ldouble_eq_tol(s21_pow(base, exp), powl(base, exp), S21_EPS);
}
END_TEST

START_TEST(pow_test_091) {
    double base = -INFINITY;
    double exp = 1;
    ck_assert_ldouble_infinite(powl(base, exp));
    ck_assert_ldouble_infinite(s21_pow(base, exp));
}
END_TEST

START_TEST(pow_test_111) {
    long double base = -0.88;
    long double exp = 0.00000001;
    ck_assert_ldouble_nan(powl(base, exp));
    ck_assert_ldouble_nan(s21_pow(base, exp));
}
END_TEST

START_TEST(pow_test_121) {
    long double base = 9999999999999999;
    long double exp = 1;
    ck_assert_ldouble_eq_tol(s21_pow(base, exp), pow(base, exp), S21_EPS);
}
END_TEST

START_TEST(pow_test_132) {
    long double base = -0.1;
    long double exp = -DBL_MAX;
    ck_assert_ldouble_infinite(powl(base, exp));
    ck_assert_ldouble_infinite(s21_pow(base, exp));
}
END_TEST

Suite *s21_pow_suite(void) {
    Suite *pow = suite_create("s21_pow");
    TCase *tc_pow;
    tc_pow = tcase_create("test_pow");
    tcase_add_test(tc_pow, test_s21_pow_1);
    // tcase_add_test(tc_pow, test_s21_pow_2);
    // tcase_add_test(tc_pow, test_s21_pow_3);
    tcase_add_test(tc_pow, test_s21_pow_4);
    tcase_add_test(tc_pow, test_s21_pow_5);
    tcase_add_test(tc_pow, test_s21_pow_6);
    tcase_add_test(tc_pow, test_s21_pow_7);
    // tcase_add_test(tc_pow, test_s21_pow_8);
    tcase_add_test(tc_pow, test_s21_pow_9);
    tcase_add_test(tc_pow, test_s21_pow_10);
    tcase_add_test(tc_pow, test_s21_pow_11);
    tcase_add_test(tc_pow, test_s21_pow_12);
    tcase_add_test(tc_pow, pow_test_001);
    tcase_add_test(tc_pow, pow_test_002);
    tcase_add_test(tc_pow, pow_test_011);
    tcase_add_test(tc_pow, pow_test_021);
    tcase_add_test(tc_pow, pow_test_031);
    tcase_add_test(tc_pow, pow_test_041);
    tcase_add_test(tc_pow, pow_test_051);
    tcase_add_test(tc_pow, pow_test_052);
    tcase_add_test(tc_pow, pow_test_061);
    tcase_add_test(tc_pow, pow_test_071);
    tcase_add_test(tc_pow, pow_test_081);
    tcase_add_test(tc_pow, pow_test_091);
    tcase_add_test(tc_pow, pow_test_111);
    tcase_add_test(tc_pow, pow_test_121);
    tcase_add_test(tc_pow, pow_test_132);
    suite_add_tcase(pow, tc_pow);
    return pow;
}
