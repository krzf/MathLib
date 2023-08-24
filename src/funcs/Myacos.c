#include "../Mymath.h"
// #include "Myatan.c"
// #include "Mysqrt.c"

long double Myacos(double x) {
  long double res = MyNAN;

  if (x == 1) res = 0;

  if (x == -1) res = MyPI;

  if (x > -1 && x < 0) res = MyPI + Myatan(Mysqrt(1 - x * x) / x);

  if (x < 1 && x >= 0) res = Myatan(Mysqrt(1 - x * x) / x);

  return res;
}
