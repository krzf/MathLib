#include <check.h>
#include <math.h>
#include <stdlib.h>

#include "../Mymath.h"

START_TEST(test_Mymath_atan_usual) {
  ck_assert_ldouble_eq_tol(Myatan(1.0), atan(1.0), 1e-6);
  ck_assert_ldouble_eq_tol(Myatan(0.1), atan(0.1), 1e-6);
  ck_assert_ldouble_eq_tol(Myatan(-1.0), atan(-1.0), 1e-6);
  ck_assert_ldouble_eq_tol(Myatan(0.0), atan(0.0), 1e-6);
  ck_assert_ldouble_eq_tol(Myatan(1000.0), atan(1000.0), 1e-6);
  ck_assert_ldouble_eq_tol(Myatan(-1000.0), atan(-1000.0), 1e-6);
}
END_TEST

Suite *Mymath_atan_suite() {
  Suite *s;
  TCase *tc_atan_usual;

  s = suite_create("Myatan");

  tc_atan_usual = tcase_create("Myatan_usual");
  tcase_add_test(tc_atan_usual, test_Mymath_atan_usual);

  suite_add_tcase(s, tc_atan_usual);

  return s;
}

int main() {
  Suite *s;
  int failed = 0;
  SRunner *runner;

  s = Mymath_atan_suite();
  runner = srunner_create(s);

  srunner_run_all(runner, CK_NORMAL);
  failed = srunner_ntests_failed(runner);
  srunner_free(runner);
  return (failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}