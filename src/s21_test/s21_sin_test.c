#include <check.h>
#include <math.h>
#include <stdlib.h>

#include "../s21_math.h"

START_TEST(test_s21_math_sin_usual) {
  double step = 0.05;
  for (double i = -5 * S21_M_PI; i <= 5 * S21_M_PI; i += step) {
    ck_assert_ldouble_eq_tol(s21_sin(i), sin(i), 1e-6);
  }
}
END_TEST

START_TEST(test_s21_math_sin_unusual) {
  int testValue1 = 1000;
  int testValue2 = -1000;
  double testValue3 = 0.0001;
  double testValue4 = 0.3284932423;
  double testValue5 = S21_M_PI;
  double testValue6 = -S21_M_PI;

  ck_assert_ldouble_eq_tol(s21_sin(testValue1), sin(testValue1), 1e-6);
  ck_assert_ldouble_eq_tol(s21_sin(testValue2), sin(testValue2), 1e-6);
  ck_assert_ldouble_eq_tol(s21_sin(testValue3), sin(testValue3), 1e-6);
  ck_assert_ldouble_eq_tol(s21_sin(testValue4), sin(testValue4), 1e-6);
  ck_assert_ldouble_eq_tol(s21_sin(testValue5), sin(testValue5), 1e-6);
  ck_assert_ldouble_eq_tol(s21_sin(testValue6), sin(testValue6), 1e-6);
}
END_TEST

Suite *s21_math_sin_suite() {
  Suite *s = suite_create("s21_sin");
  TCase *tc_sin = tcase_create("s21_sin");
  tcase_add_test(tc_sin, test_s21_math_sin_usual);
  tcase_add_test(tc_sin, test_s21_math_sin_unusual);
  suite_add_tcase(s, tc_sin);
  return s;
}

int main() {
  int fail_number = 0;
  Suite *s = s21_math_sin_suite();
  SRunner *runner = srunner_create(s);

  srunner_run_all(runner, CK_NORMAL);
  fail_number = srunner_ntests_failed(runner);
  srunner_free(runner);
  return (fail_number == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
