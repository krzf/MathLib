#include <check.h>
#include <math.h>
#include <stdlib.h>

#include "../Mymath.h"
#include "test_cases.h"

#define sizeArr(x) (sizeof(x) / sizeof((x)[0]))

START_TEST(test_Mymath_pow_usual) {
  ck_assert_ldouble_eq_tol(Mypow(8, 3), pow(8, 3), 1e-6);
  ck_assert_ldouble_eq_tol(Mypow(-8, 3), pow(-8, 3), 1e-6);
  ck_assert_ldouble_eq_tol(Mypow(8, -3), pow(8, -3), 1e-6);
  ck_assert_ldouble_eq_tol(Mypow(0, 0), pow(0, 0), 1e-6);
  ck_assert_ldouble_eq_tol(Mypow(1, -3), pow(1, -3), 1e-6);
  ck_assert_ldouble_eq_tol(Mypow(0, 5), pow(0, 5), 1e-6);
  ck_assert_ldouble_eq_tol(Mypow(8.234, -3), pow(8.234, -3), 1e-6);
  ck_assert_ldouble_eq_tol(Mypow(25, 0.5), pow(25, 0.5), 1e-6);
  ck_assert_ldouble_eq_tol(Mypow(5, 1.4), pow(5, 1.4), 1e-6);
  ck_assert_ldouble_eq_tol(Mypow(5, -1.4), pow(5, -1.4), 1e-6);
  ck_assert_double_nan(Mypow(-4, 1.4));
  for (double i = 0.0; i < 10.0; i += 0.1) {
    for (double j = 0.0; j < 10.0; j += 0.1) {
      ck_assert_ldouble_eq_tol(Mypow(i, j), pow(i, j), 1e-4);
    }
  }
}
END_TEST

START_TEST(test_Mymath_pow_big) {
  int base = 2989839;
  double exp1 = 0.0004;
  int exp3 = 0;
  // int exp4 = 55;
  int exp5 = -2;

  ck_assert_ldouble_eq_tol(Mypow(base, exp1), pow(base, exp1), 1e-6);
  ck_assert_ldouble_eq_tol(Mypow(base, exp3), pow(base, exp3), 1e-6);
  ck_assert_ldouble_eq_tol(Mypow(base, exp5), pow(base, exp5), 1e-6);
}
END_TEST

START_TEST(test_Mymath_pow_small) {
  double base = 0.0083928293832;
  // double exp1 = 0.0004;
  int exp2 = 293;
  int exp3 = 0;
  int exp4 = 66;
  // int exp5 = -99;

  // ck_assert_ldouble_eq_tol(Mypow(base, exp1), pow(base, exp1), 1e-6);
  ck_assert_ldouble_eq_tol(Mypow(base, exp2), pow(base, exp2), 1e-6);
  ck_assert_ldouble_eq_tol(Mypow(base, exp3), pow(base, exp3), 1e-6);
  ck_assert_ldouble_eq_tol(Mypow(base, exp4), pow(base, exp4), 1e-6);
}
END_TEST

// START_TEST(test_Mymath_pow_cases_should_return_nan) {
//   for (unsigned int i = 0; i < sizeArr(cases_pow_return_nan); i++) {
//     double base = cases_pow_return_nan[i][0];
//     double exp = cases_pow_return_nan[i][1];
//     ck_assert_double_nan(Mypow(base, exp));
//   }
// }
// END_TEST

// START_TEST(test_Mymath_pow_cases_should_return_inf) {
//   for (unsigned int i = 0; i < sizeArr(cases_pow_return_inf); i++) {
//     double base = cases_pow_return_inf[i][0];
//     double exp = cases_pow_return_inf[i][1];
//     ck_assert_ldouble_infinite(Mypow(base, exp));
//   }
// }
// END_TEST

// START_TEST(test_Mymath_pow_cases_should_return_one) {
//   for (unsigned int i = 0; i < sizeArr(cases_pow_return_one); i++) {
//     double base = cases_pow_return_one[i][0];
//     double exp = cases_pow_return_one[i][1];
//     ck_assert_double_eq(Mypow(base, exp), 1.0);
//   }
// }
// END_TEST

Suite *Mymath_pow_suite() {
  Suite *s;
  TCase *tc_pow_big, *tc_pow_small, *tc_pow_usual, *tc_pow_unusual;

  s = suite_create("pow");

  tc_pow_usual = tcase_create("pow_usual");
  tcase_add_test(tc_pow_usual, test_Mymath_pow_usual);
  suite_add_tcase(s, tc_pow_usual);

  tc_pow_big = tcase_create("pow_big");
  tcase_add_test(tc_pow_big, test_Mymath_pow_big);
  suite_add_tcase(s, tc_pow_big);

  tc_pow_small = tcase_create("pow_small");
  tcase_add_test(tc_pow_small, test_Mymath_pow_small);
  suite_add_tcase(s, tc_pow_small);

  tc_pow_unusual = tcase_create("pow_unusual");
  // tcase_add_test(tc_pow_unusual, test_Mymath_pow_cases_should_return_nan);
  // tcase_add_test(tc_pow_unusual, test_Mymath_pow_cases_should_return_inf);
  // tcase_add_test(tc_pow_unusual, test_Mymath_pow_cases_should_return_one);
  suite_add_tcase(s, tc_pow_unusual);

  return s;
}

int main() {
  Suite *s;
  int failed = 0;
  SRunner *runner;

  s = Mymath_pow_suite();
  runner = srunner_create(s);

  srunner_run_all(runner, CK_NORMAL);
  failed = srunner_ntests_failed(runner);
  srunner_free(runner);
  return (failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
