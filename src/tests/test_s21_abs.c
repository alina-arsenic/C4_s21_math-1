/*
checking abs
Copyright 2022

nidorina@student.21-school.ru
*/
#include "s21_tests.h"

START_TEST(test_s21_abs) {
    int arr[] = {
        INT8_MAX, INT16_MAX, INT32_MAX, INT8_MIN, INT16_MIN, INT32_MIN, 0,
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

Suite *s21_abs_suite(void) {
    Suite *abs = suite_create("s21_abs");
    TCase *tc_abs;
    tc_abs = tcase_create("test_abs");
    tcase_add_test(tc_abs, test_s21_abs);
    suite_add_tcase(abs, tc_abs);
    return abs;
}
