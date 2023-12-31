#include <check.h>
#include <math.h>
#include <stdlib.h>

#include "../Mymath.h"

START_TEST(test_Mymath_acos_usual) {
  ck_assert_ldouble_eq_tol(Myacos(1.0), acos(1.0), 1e-6);
  ck_assert_ldouble_eq_tol(Myacos(-1.0), acos(-1.0), 1e-6);
  ck_assert_ldouble_eq_tol(Myacos(0.0), acos(0.0), 1e-6);

  ck_assert_ldouble_eq_tol(Myacos(0.23234), acos(0.23234), 1e-6);
  ck_assert_ldouble_eq_tol(Myacos(-0.23234), acos(-0.23234), 1e-6);
  ck_assert_ldouble_eq_tol(Myacos(0.0002), acos(0.0002), 1e-6);
  ck_assert_ldouble_eq_tol(Myacos(-0.0002), acos(-0.0002), 1e-6);
}
END_TEST

Suite *Mymath_acos_suite() {
  Suite *s;
  TCase *tc_acos_usual;

  s = suite_create("Myacos");

  tc_acos_usual = tcase_create("Myacos_usual");
  tcase_add_test(tc_acos_usual, test_Mymath_acos_usual);

  suite_add_tcase(s, tc_acos_usual);

  return s;
}

int main() {
  Suite *s;
  int failed = 0;
  SRunner *runner;

  s = Mymath_acos_suite();
  runner = srunner_create(s);

  srunner_run_all(runner, CK_NORMAL);
  failed = srunner_ntests_failed(runner);
  srunner_free(runner);
  return (failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}