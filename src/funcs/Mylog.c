#include "../Mymath.h"
long double Mylog(double x) {
  long double res = 0.0;
  if (x == 0) {
    return res = NEG_INF;
  }
  if (x != x) {
    return MyNAN;
  }
  if (x < 0) {
    return MyNAN;
  }
  if (x == POS_INF) {
    return res = POS_INF;
  } else {
    int repeat = 0;
    for (; x >= MyEXP; repeat++) x /= MyEXP;
    for (int i = 0; i < 20; i++) {
      long double tmp = res;
      res = tmp + 2 * (x - Myexp(tmp)) / (x + Myexp(tmp));
    }
    res = res + repeat;
  }
  return res;
}