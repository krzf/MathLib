#include "../Mymath.h"
long double Myfmod(double x, double y) {
  long double res = 0.0;
  int sign = 1;
  if (x < 0) {
    sign = -1;
    x = Myfabs(x);
  }

  if (y < 0) {
    y = Myfabs(y);
  }
  if (y == 0) {
    res = MyNAN;
  } else if (x == y) {
    res = 0;
  } else if (x < y) {
    res = x;
  } else if (x == POS_INF) {
    res = MyNAN;
  } else {
    long long int mod = x / y;
    res = (long double)x - mod * (long double)y;
  }
  return res * sign;
}
