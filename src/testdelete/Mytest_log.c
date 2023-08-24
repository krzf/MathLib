#include <check.h>
#include <math.h>
#include <stdlib.h>

#include "../Mymath.h"

START_TEST(test_Mymath_log_usual) {
  double testValue1 = MyEXP;
  double testValue2 = 10;
  double testValue3 = 3;
  ck_assert_ldouble_eq_tol(Mylog(testValue1), log(testValue1), 1e-6);
  ck_assert_ldouble_eq_tol(Mylog(testValue2), log(testValue2), 1e-6);
  ck_assert_ldouble_eq_tol(Mylog(testValue3), log(testValue3), 1e-6);
  // for (double i = 0.1; i < 100.0; i += 0.1) {
  //   ck_assert_ldouble_eq_tol(Mylog(i), log(i), 1e-6);
  // }
}
END_TEST

START_TEST(test_Mymath_log_unusual) {
  double testValue1 = -1;
  double testValue2 = 0;
  ck_assert_double_nan(Mylog(testValue1));
  ck_assert_ldouble_infinite(Mylog(testValue2));
  ck_assert_double_nan(Mylog(NAN));
  ck_assert_double_nan(Mylog(MyNAN));
  ck_assert_double_nan(Mylog(-MyNAN));
  ck_assert_ldouble_infinite(Mylog(POS_INF));
  ck_assert_ldouble_nan(Mylog(NEG_INF));
}
END_TEST

Suite *Mymath_log_suite() {
  Suite *s;
  TCase *tc_log_usual, *tc_log_unusual;

  s = suite_create("Mylog");

  tc_log_usual = tcase_create("Mylog_usual");
  tcase_add_test(tc_log_usual, test_Mymath_log_usual);
  suite_add_tcase(s, tc_log_usual);

  tc_log_unusual = tcase_create("Mylog_unusual");
  tcase_add_test(tc_log_unusual, test_Mymath_log_unusual);
  suite_add_tcase(s, tc_log_unusual);

  return s;
}

int main() {
  Suite *s;
  int failed = 0;
  SRunner *runner;

  s = Mymath_log_suite();
  runner = srunner_create(s);

  srunner_run_all(runner, CK_NORMAL);
  failed = srunner_ntests_failed(runner);
  srunner_free(runner);
  return (failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}