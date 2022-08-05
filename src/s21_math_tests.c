/*
checking abs asin ceil
Copyright 2022

nidorina@student.21-school.ru
*/

#include <check.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "./s21_math.h"

Suite *s21_suite();

int main() {
    int number_failed = 0;
    Suite *s;
    SRunner *runner;

    s = s21_suite();
    runner = srunner_create(s);

    srunner_run_all(runner, CK_NORMAL);
    number_failed = srunner_ntests_failed(runner);
    srunner_free(runner);
    printf("\nFAILED TESTS: %d \n\n", number_failed);

    return 0;
}
/*
START_TEST(s21_cat_test) {
    секция подготовки

    секция действия

    секция проверки результата

    ck_assert_uint_eq(1, 1);
}
END_TEST*/

START_TEST(s21_abs_test) {
    int arr[] = {
        INT8_MAX, INT16_MAX, INT32_MAX, INT8_MIN, INT16_MIN, INT32_MIN,
    };
    int arr_length = sizeof(arr) / sizeof(arr[0]);
    ck_assert_int_eq(s21_abs(1), abs(1));
    ck_assert_int_eq(s21_abs(0), abs(0));
    for (; arr_length; arr_length--) {
        int tmp_i = arr[arr_length - 1];
        ck_assert_int_eq(s21_abs(tmp_i), abs(tmp_i));
        ck_assert_int_eq(s21_abs(-tmp_i), abs(-tmp_i));
        // printf(" %d i=%d\n", tmp_i, arr_length - 1);
        // printf("# %d\n", -tmp_i);
    }
}
END_TEST

START_TEST(s21_ceil_test) {
    srand((unsigned int)time(NULL));
    long double x = s21_MINUSINF;
    ck_assert_ldouble_eq(s21_ceil(x), ceil(x));
    x = s21_INF;
    ck_assert_ldouble_eq(s21_ceil(x), ceil(x));
    x = s21_NAN;
    ck_assert_ldouble_nan(s21_ceil(x));
    for (int i = 0; i < 200; i++) {
        x = ((long double)rand() / (long double)(RAND_MAX)) * INT16_MAX;
        ck_assert_ldouble_eq(s21_ceil(x), ceil(x));
        x = -((long double)rand() / (long double)(RAND_MAX)) * INT16_MAX;
        ck_assert_ldouble_eq(s21_ceil(x), ceil(x));
        // printf("%.7Lf\n", x);
    }
}
END_TEST

Suite *s21_suite() {
    Suite *s;
    s = suite_create("math_Suite");

    TCase *tc_core = tcase_create("math");
    tcase_add_test(tc_core, s21_abs_test);
    tcase_add_test(tc_core, s21_ceil_test);
    suite_add_tcase(s, tc_core);

    return s;
}
