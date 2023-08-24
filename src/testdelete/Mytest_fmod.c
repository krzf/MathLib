#include <check.h>
#include <math.h>
#include <stdlib.h>

#include "../Mymath.h"

START_TEST(test_Mymath_fmod_usual) {
  double testValueX1 = -8;
  double testValueY1 = 3;
  double testValueX2 = -10;
  double testValueY2 = 2;
  double testValueX3 = 164.2;
  double testValueY3 = 0.3;
  ck_assert_ldouble_eq_tol(Myfmod(testValueX1, testValueY1),
                           fmod(testValueX1, testValueY1), 1e-6);
  ck_assert_ldouble_eq_tol(Myfmod(testValueX2, testValueY2),
                           fmod(testValueX2, testValueY2), 1e-6);
  ck_assert_ldouble_eq_tol(Myfmod(testValueX3, testValueY3),
                           fmod(testValueX3, testValueY3), 1e-6);
}
END_TEST

START_TEST(test_Mymath_fmod_unusual) {
  double testValueX1 = 0;
  double testValueY1 = 0;
  double testValueX2 = 3;
  double testValueY2 = 0;
  double testValueX3 = 100;
  double testValueY3 = -5;
  double testValueX4 = POS_INF;
  double testValueY4 = -5;
  double testValueX5 = 4;
  double testValueY5 = MyNAN;
  ck_assert_double_nan(Myfmod(testValueX1, testValueY1));
  ck_assert_double_nan(Myfmod(testValueX2, testValueY2));
  ck_assert_ldouble_eq_tol(Myfmod(testValueX3, testValueY3),
                           fmod(testValueX3, testValueY3), 1e-6);
  ck_assert_double_nan(Myfmod(testValueX4, testValueY4));
  ck_assert_double_nan(Myfmod(testValueX5, testValueY5));
}
END_TEST

Suite *Mymath_fmod_suite() {
  Suite *s;
  TCase *tc_fmod_usual, *tc_fmod_unusual;

  s = suite_create("Myfmod");

  tc_fmod_usual = tcase_create("Myfmod_usual");
  tcase_add_test(tc_fmod_usual, test_Mymath_fmod_usual);
  suite_add_tcase(s, tc_fmod_usual);

  tc_fmod_unusual = tcase_create("Myfmod_unusual");
  tcase_add_test(tc_fmod_unusual, test_Mymath_fmod_unusual);
  suite_add_tcase(s, tc_fmod_unusual);

  return s;
}

int main() {
  Suite *s;
  int failed = 0;
  SRunner *runner;

  s = Mymath_fmod_suite();
  runner = srunner_create(s);

  srunner_run_all(runner, CK_NORMAL);
  failed = srunner_ntests_failed(runner);
  srunner_free(runner);
  return (failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}