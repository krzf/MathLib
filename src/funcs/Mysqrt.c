#include "../Mymath.h"
long double Mysqrt(double x) {
  if (x < 0) {
    return MyNAN;
  }

  double i;
  double precision = 0.000001;
  for (i = 1; i * i <= x; i++)
    ;
  for (--i; i * i < x; i = i + precision)
    ;
  return i;
}
