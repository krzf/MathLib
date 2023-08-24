#include <check.h>
#include <math.h>
#include <stdlib.h>

#include "../Mymath.h"

START_TEST(test_Mymath_ceil_usual) {
  double testValue1 = -5.7;
  double testValue2 = -0.1;
  double testValue3 = 12.4;
  ck_assert_ldouble_eq_tol(Myceil(testValue1), ceil(testValue1), 1e-6);
  ck_assert_ldouble_eq_tol(Myceil(testValue2), ceil(testValue2), 1e-6);
  ck_assert_ldouble_eq_tol(Myceil(testValue3), ceil(testValue3), 1e-6);
  for (double i = -1.01; i <= 1.01; i += 0.01) {
    ck_assert_ldouble_eq_tol(Myceil(i), ceil(i), 1e-6);
  }
}
END_TEST

START_TEST(test_Mymath_ceil_unusual) {
  double testValue1 = POS_INF;
  double testValue2 = NEG_INF;
  double testValue3 = MyNAN;
  ck_assert_double_infinite(Myceil(testValue1));
  ck_assert_double_infinite(Myceil(testValue2));
  ck_assert_double_nan(Myceil(testValue3));
}
END_TEST

Suite *Mymath_ceil_suite() {
  Suite *s;
  TCase *tc_ceil_usual, *tc_ceil_unusual;

  s = suite_create("Myceil");

  tc_ceil_usual = tcase_create("Myceil_usual");
  tcase_add_test(tc_ceil_usual, test_Mymath_ceil_usual);
  suite_add_tcase(s, tc_ceil_usual);

  tc_ceil_unusual = tcase_create("Myceil_unusual");
  tcase_add_test(tc_ceil_unusual, test_Mymath_ceil_unusual);
  suite_add_tcase(s, tc_ceil_unusual);

  return s;
}

int main() {
  Suite *s;
  int failed = 0;
  SRunner *runner;

  s = Mymath_ceil_suite();
  runner = srunner_create(s);

  srunner_run_all(runner, CK_NORMAL);
  failed = srunner_ntests_failed(runner);
  srunner_free(runner);
  return (failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}