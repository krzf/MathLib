#include <check.h>
#include <math.h>
#include <stdlib.h>

#include "../Mymath.h"

START_TEST(test_Mymath_sin_usual) {
  double step = 0.05;
  for (double i = -5 * MyPI; i <= 5 * MyPI; i += step) {
    ck_assert_ldouble_eq_tol(Mysin(i), sin(i), 1e-6);
  }
}
END_TEST

START_TEST(test_Mymath_sin_unusual) {
  int testValue1 = 100;
  int testValue2 = -3003;
  double testValue3 = 0.0005;
  double testValue4 = 0.98439849385;
  double testValue5 = MyPI;
  double testValue6 = -MyPI;
  double testValue7 = MyPI / 2;
  double testValue8 = -MyPI / 2;

  ck_assert_ldouble_eq_tol(Mysin(testValue1), sin(testValue1), 1e-6);
  ck_assert_ldouble_eq_tol(Mysin(testValue2), sin(testValue2), 1e-6);
  ck_assert_ldouble_eq_tol(Mysin(testValue3), sin(testValue3), 1e-6);
  ck_assert_ldouble_eq_tol(Mysin(testValue4), sin(testValue4), 1e-6);
  ck_assert_ldouble_eq_tol(Mysin(testValue5), sin(testValue5), 1e-6);
  ck_assert_ldouble_eq_tol(Mysin(testValue6), sin(testValue6), 1e-6);
  ck_assert_ldouble_eq_tol(Mysin(testValue7), sin(testValue7), 1e-6);
  ck_assert_ldouble_eq_tol(Mysin(testValue8), sin(testValue8), 1e-6);
}
END_TEST

Suite *Mymath_sin_suite() {
  Suite *s;
  TCase *tc_sin;

  s = suite_create("Mysin");

  tc_sin = tcase_create("Mysin");
  tcase_add_test(tc_sin, test_Mymath_sin_usual);
  tcase_add_test(tc_sin, test_Mymath_sin_unusual);
  suite_add_tcase(s, tc_sin);
  return s;
}

int main() {
  Suite *s;
  int failed = 0;
  SRunner *runner;

  s = Mymath_sin_suite();
  runner = srunner_create(s);

  srunner_run_all(runner, CK_NORMAL);
  failed = srunner_ntests_failed(runner);
  srunner_free(runner);
  return (failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
