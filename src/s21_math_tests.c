/*
checking abs asin ceil
Copyright 2022

nidorina@student.21-school.ru
*/

#include <check.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

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

START_TEST(s21_abs_test) { ck_assert_int_eq(s21_abs(1), abs(1)); }
END_TEST

Suite *s21_suite() {
    Suite *s;
    s = suite_create("math_Suite");

    TCase *tc_core = tcase_create("math");
    tcase_add_test(tc_core, s21_abs_test);
    suite_add_tcase(s, tc_core);

    return s;
}
