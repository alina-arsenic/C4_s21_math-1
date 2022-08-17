#ifndef SRC_TESTS_S21_TESTS_H_
#define SRC_TESTS_S21_TESTS_H_

#include <stdio.h>
#include <check.h>
#include <math.h>
#include <time.h>
#include <stdlib.h>
#include "../s21_math.h"

Suite *s21_fabs_suite(void);
Suite *s21_log_suite(void);
Suite *s21_sqrt_suite(void);
Suite *s21_ceil_suite(void);
Suite *s21_abs_suite(void);
Suite *s21_asin_suite(void);
Suite *s21_sin_suite(void);
Suite *s21_exp_suite(void);
Suite *s21_acos_suite(void);
Suite *s21_cos_suite(void);
Suite *s21_tan_suite(void);
Suite *s21_atan_suite(void);
Suite *s21_pow_suite(void);
Suite *s21_floor_suite(void);
Suite *s21_fmod_suite(void);

#endif  // SRC_TESTS_S21_TESTS_H_
