#include "../Mymath.h"
// #include "Myabs.c"

long double Mysin(double x) {
  while (Myfabs(x) - 2 * MyPI > 0) {
    x += 2 * MyPI * x / Myfabs(x) * -1;
  }
  long double result = 0;
  int sign = 1;
  double xx = x * x;
  double pw = x;
  double fact = 1.0;
  for (int i = 1; i < 200; i += 2) {
    fact *= i;
    result += sign * pw / fact;
    fact *= (i + 1);
    sign = -sign;
    pw *= xx;
  }
  return result;
}