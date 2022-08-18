#include "s21_tests.h"

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

Suite *s21_exp_suite(void) {
    Suite *exp = suite_create("s21_exp");
    TCase *tc_s21_exp;
    tc_s21_exp = tcase_create("test_exp");
    tcase_add_test(tc_s21_exp, s21_exp_0001);
    tcase_add_test(tc_s21_exp, s21_exp_0002);
    tcase_add_test(tc_s21_exp, s21_exp_0003);
    tcase_add_test(tc_s21_exp, s21_exp_0004);
    tcase_add_test(tc_s21_exp, s21_exp_0005);
    suite_add_tcase(exp, tc_s21_exp);
    return exp;
}
