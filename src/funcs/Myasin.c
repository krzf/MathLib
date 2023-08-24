#include "../Mymath.h"
// #include "Myacos.c"

long double Myasin(double x) {
  double res = MyNAN;
  if (x < -1 || x > 1) {
    return res;
  }

  if (x == -1 || x == 1) {
    res = MyPI / (2 * x);
  }
  if (x > -1 || x < 1) {
    res = MyPI / 2 - Myacos(x);
  }

  return res;
}