#include "../Mymath.h"

// тригонометрическое тождество
long double Myatan(double x) {
  double result = 0.0;

  if (x > -1 && x < 1) {
    double power = x;
    double term = x;
    int sign = 1;
    int n = 1;

    while (term != 0) {
      result += sign * term;
      power *= x * x;
      n += 2;
      term = power / n;
      sign *= -1;
    }
  } else if (x == 1) {
    result = MyPI / 4;
  } else if (x == -1) {
    result = -MyPI / 4;
  } else if (x < -1) {
    result = -MyPI / 2 - Myatan(1 / x);
  } else if (x > 1) {
    result = MyPI / 2 - Myatan(1 / x);
  }

  return result;
}