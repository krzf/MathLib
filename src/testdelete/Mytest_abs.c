#include <check.h>
#include <math.h>
#include <stdlib.h>

#include "../Mymath.h"

START_TEST(test_Mymath_abs_usual) {
  int testValue1 = -5;
  int testValue2 = 5;
  int testValue3 = 0;
  ck_assert_int_eq(Myabs(testValue1), abs(testValue1));
  ck_assert_int_eq(Myabs(testValue2), abs(testValue2));
  ck_assert_int_eq(Myabs(testValue3), abs(testValue3));
}
END_TEST

START_TEST(test_Mymath_abs_unusual) {
  int testValue1 = -10;
  int testValue2 = 10;
  int testValue3 = 0;
  ck_assert_int_eq(Myabs(testValue1), abs(testValue1));
  ck_assert_int_eq(Myabs(testValue2), abs(testValue2));
  ck_assert_int_eq(Myabs(testValue3), abs(testValue3));
}
END_TEST

Suite *Mymath_abs_suite() {
  Suite *s;
  TCase *tc_abs_usual, *tc_abs_unusual;

  s = suite_create("Myabs");

  tc_abs_usual = tcase_create("Myabs_usual");
  tcase_add_test(tc_abs_usual, test_Mymath_abs_usual);

  suite_add_tcase(s, tc_abs_usual);

  tc_abs_unusual = tcase_create("Myabs_unusual");
  tcase_add_test(tc_abs_unusual, test_Mymath_abs_unusual);
  suite_add_tcase(s, tc_abs_unusual);

  return s;
}

int main() {
  Suite *s;
  int failed = 0;
  SRunner *runner;

  s = Mymath_abs_suite();
  runner = srunner_create(s);

  srunner_run_all(runner, CK_NORMAL);
  failed = srunner_ntests_failed(runner);
  srunner_free(runner);
  return (failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}