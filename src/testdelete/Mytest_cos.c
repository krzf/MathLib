#include <check.h>
#include <math.h>
#include <stdlib.h>

#include "../Mymath.h"

START_TEST(test_Mymath_cos_unusual) {
  int testValue1 = 100;
  int testValue2 = -3003;
  double testValue3 = 0.0005;
  double testValue4 = 0.98439849385;
  double testValue5 = MyPI;
  double testValue6 = -MyPI;
  double testValue7 = MyPI / 2;
  double testValue8 = -MyPI / 2;

  ck_assert_ldouble_eq_tol(Mycos(testValue1), cos(testValue1), 1e-6);
  ck_assert_ldouble_eq_tol(Mycos(testValue2), cos(testValue2), 1e-6);
  ck_assert_ldouble_eq_tol(Mycos(testValue3), cos(testValue3), 1e-6);
  ck_assert_ldouble_eq_tol(Mycos(testValue4), cos(testValue4), 1e-6);
  ck_assert_ldouble_eq_tol(Mycos(testValue5), cos(testValue5), 1e-6);
  ck_assert_ldouble_eq_tol(Mycos(testValue6), cos(testValue6), 1e-6);
  ck_assert_ldouble_eq_tol(Mycos(testValue7), cos(testValue7), 1e-6);
  ck_assert_ldouble_eq_tol(Mycos(testValue8), cos(testValue8), 1e-6);
}

START_TEST(test_Mymath_cos_usual) {
  double step = 0.01;
  for (double i = -5 * MyPI; i <= 5 * MyPI; i += step) {
    ck_assert_ldouble_eq_tol(Mycos(i), cos(i), 1e-6);
  }
}
END_TEST

Suite *Mymath_cos_suite() {
  Suite *s;
  TCase *tc_cos;

  s = suite_create("Mycos");

  tc_cos = tcase_create("Mycos");
  tcase_add_test(tc_cos, test_Mymath_cos_unusual);
  tcase_add_test(tc_cos, test_Mymath_cos_usual);
  suite_add_tcase(s, tc_cos);
  return s;
}

int main() {
  Suite *s;
  int failed = 0;
  SRunner *runner;

  s = Mymath_cos_suite();
  runner = srunner_create(s);

  srunner_run_all(runner, CK_NORMAL);
  failed = srunner_ntests_failed(runner);
  srunner_free(runner);
  return (failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
