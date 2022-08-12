#include <check.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "s21_math.h"

START_TEST(s21_acos_0001) {
    long double x = S21_CONST_SQ;
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
    long double x = -S21_CONST_SQ;
    long double res = acos(x), s21_res = s21_acos(x);

    ck_assert_ldouble_eq(res, s21_res);
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

START_TEST(s21_exp_0001) {
  double res1 = 22.1345;
  ck_assert_int_eq(s21_exp(res1), exp(res1));
}
END_TEST

START_TEST(s21_exp_0002) {
  long double step =  0.01, start = -10, stop = 10, x;
    x = start;
    int step_counter = 0;
    while (x < stop + 0.01) {
        long double s21_exp_x = s21_exp((double)x), max, diff, prescision;
        long double exp_x = (long double) exp((double)x);
        if (fabsl(exp_x) > fabsl(s21_exp_x)) {
            max = fabsl(exp_x);
        } else {
            max = fabsl(s21_exp_x);
        }
        diff = fabsl(exp_x - s21_exp_x);
        if (max > 1) {
            prescision = diff/max;
        } else {
            prescision = fabsl(s21_exp_x - exp_x);
        }
        if (prescision > 0.0000009) {
            ck_assert_double_lt(prescision, 0.00000009);
        }
        x = start + step * (long double) step_counter;
        step_counter++;
    }
}
END_TEST

START_TEST(s21_exp_0003) {
  double x = NAN;
    ck_assert_ldouble_nan(s21_exp(x));
}
END_TEST

START_TEST(s21_exp_0004) {
  double x = INFINITY;
    ck_assert_ldouble_eq(exp(x), s21_exp(x));
}
END_TEST

START_TEST(s21_exp_0005) {
  double x = -INFINITY;
    ck_assert_ldouble_eq_tol(exp(x), s21_exp(x), S21_EPS);
}
END_TEST

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
    ck_assert_double_eq_tol(s21_sin(S21_PI / 6), sin(S21_PI / 6), S21_EPS);
} END_TEST

START_TEST(s21_sin_0011) {
    ck_assert_double_eq_tol(s21_sin(S21_PI / 4), sin(S21_PI / 4), S21_EPS);
} END_TEST

START_TEST(s21_sin_0012) {
    ck_assert_double_eq_tol(s21_sin(S21_PI / 3), sin(S21_PI / 3), S21_EPS);
} END_TEST

START_TEST(s21_sin_0013) {
    ck_assert_double_eq_tol(s21_sin(S21_PI / 2), sin(S21_PI / 2), S21_EPS);
} END_TEST

START_TEST(s21_sin_0014) {
    ck_assert_double_eq_tol(s21_sin(3 * S21_PI / 2), sin(3 * S21_PI / 2), S21_EPS);
} END_TEST

START_TEST(s21_sin_0015) {
    ck_assert_double_eq_tol(s21_sin(2 * S21_PI), sin(2 * S21_PI), S21_EPS);;
} END_TEST

START_TEST(s21_sin_0016) {
    ck_assert_double_eq_tol(s21_sin(-2 * S21_PI), sin(-2 * S21_PI), S21_EPS);
} END_TEST

START_TEST(s21_sin_0017) {
     ck_assert_double_eq_tol(s21_sin(-3 * S21_PI), sin(-3 * S21_PI), S21_EPS);
} END_TEST

START_TEST(s21_sin_0018) {
    ck_assert_double_eq_tol(s21_sin(424.532925199433), sin(424.532925199433), S21_EPS);
} END_TEST

START_TEST(s21_sin_0019) {
    ck_assert_double_eq_tol(s21_sin(-222.532925199433), sin(-222.532925199433), S21_EPS);
} END_TEST

START_TEST(s21_sin_0020) {
    ck_assert_double_eq_tol(s21_sin(-S21_PI), sin(-S21_PI), S21_EPS);
} END_TEST

Suite *s21_math_suite(void) {
    Suite *s;
    TCase *tc_s21_acos, *tc_s21_exp, *tc_s21_sin;

    s = suite_create("s21_math");

    tc_s21_acos = tcase_create("s21_acos");
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

    tc_s21_exp = tcase_create("s21_exp");
    tcase_add_test(tc_s21_exp, s21_exp_0001);
    tcase_add_test(tc_s21_exp, s21_exp_0002);
    tcase_add_test(tc_s21_exp, s21_exp_0003);
    tcase_add_test(tc_s21_exp, s21_exp_0004);
    tcase_add_test(tc_s21_exp, s21_exp_0005);

    tc_s21_sin = tcase_create("s21_sin");
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

    suite_add_tcase(s, tc_s21_acos);
    suite_add_tcase(s, tc_s21_exp);
    suite_add_tcase(s, tc_s21_sin);

    return s;
}

int main(void) {
    int no_failed = 0;
    Suite *s;
    SRunner *runner;

    s = s21_math_suite();
    runner = srunner_create(s);
    srunner_set_fork_status(runner, CK_NOFORK);
    srunner_run_all(runner, CK_NORMAL);
    no_failed = srunner_ntests_failed(runner);
    srunner_free(runner);
    return (no_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
