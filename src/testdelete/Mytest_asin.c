#include <check.h>
#include <math.h>
#include <stdlib.h>

#include "../Mymath.h"

START_TEST(test_Mymath_asin_usual) {
  ck_assert_ldouble_eq_tol(Myasin(1.0), asin(1.0), 1e-6);
  ck_assert_ldouble_eq_tol(Myasin(-1.0), asin(-1.0), 1e-6);
  ck_assert_ldouble_eq_tol(Myasin(0.0), asin(0.0), 1e-6);

  ck_assert_ldouble_eq_tol(Myasin(0.23234), asin(0.23234), 1e-6);
  ck_assert_ldouble_eq_tol(Myasin(-0.23234), asin(-0.23234), 1e-6);
  ck_assert_ldouble_eq_tol(Myasin(0.0002), asin(0.0002), 1e-6);
  ck_assert_ldouble_eq_tol(Myasin(-0.0002), asin(-0.0002), 1e-6);
}
END_TEST

Suite *Mymath_asin_suite() {
  Suite *s;
  TCase *tc_asin_usual;

  s = suite_create("Myasin");

  tc_asin_usual = tcase_create("Myasin_usual");
  tcase_add_test(tc_asin_usual, test_Mymath_asin_usual);

  suite_add_tcase(s, tc_asin_usual);

  return s;
}

int main() {
  Suite *s;
  int failed = 0;
  SRunner *runner;

  s = Mymath_asin_suite();
  runner = srunner_create(s);

  srunner_run_all(runner, CK_NORMAL);
  failed = srunner_ntests_failed(runner);
  srunner_free(runner);
  return (failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}