#include <check.h>
#include <math.h>
#include <stdlib.h>

#include "../Mymath.h"

START_TEST(test_Mymath_sqrt_usual) {
  double testValue1 = 256;
  // double testValue2 = 25;
  double testValue3 = 0;
  ck_assert_ldouble_eq_tol(Mysqrt(testValue1), sqrt(testValue1), 1e-6);
  ck_assert_ldouble_eq_tol(Mysqrt(25), sqrt(25), 1e-6);
  ck_assert_ldouble_eq_tol(Mysqrt(testValue3), sqrt(testValue3), 1e-6);
}
END_TEST

START_TEST(test_Mymath_sqrt_unusual) {
  double testValue1 = -1;
  double testValue2 = 1e10;
  double testValue3 = 0.01;
  ck_assert_double_nan(Mysqrt(testValue1));
  ck_assert_ldouble_eq_tol(Mysqrt(testValue2), sqrt(testValue2), 1e-6);
  ck_assert_ldouble_eq_tol(Mysqrt(testValue3), sqrt(testValue3), 1e-6);
}
END_TEST

Suite *Mymath_sqrt_suite() {
  Suite *s;
  TCase *tc_sqrt_usual, *tc_sqrt_unusual;

  s = suite_create("Mysqrt");

  tc_sqrt_usual = tcase_create("Mysqrt_usual");
  tcase_add_test(tc_sqrt_usual, test_Mymath_sqrt_usual);
  suite_add_tcase(s, tc_sqrt_usual);

  tc_sqrt_unusual = tcase_create("Mysqrt_unusual");
  tcase_add_test(tc_sqrt_unusual, test_Mymath_sqrt_unusual);
  suite_add_tcase(s, tc_sqrt_unusual);

  return s;
}

int main() {
  Suite *s;
  int failed = 0;
  SRunner *runner;

  s = Mymath_sqrt_suite();
  runner = srunner_create(s);

  srunner_run_all(runner, CK_NORMAL);
  failed = srunner_ntests_failed(runner);
  srunner_free(runner);
  return (failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}