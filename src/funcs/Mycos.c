#include "../Mymath.h"

long double Mycos(double x) {
  while (x > MyPI) {
    x -= 2 * MyPI;
  }
  while (x < -MyPI) {
    x += 2 * MyPI;
  }

  double result = 1.0;
  double term = 1.0;
  double power = x * x;
  int n = 2;
  int sign = -1;

  while (term > 1e-10) {
    term *= power / (n * (n - 1));
    result += sign * term;
    n += 2;
    sign *= -1;
  }

  return result;
}