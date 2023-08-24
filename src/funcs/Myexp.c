#include "../Mymath.h"

long double Myexp(double x) {
  const int maxIterations = 100;
  long double res = 1;
  long double term = 1;
  if (x == NEG_INF || x < -14.5) {
    res = 0.0;
  } else if (x == POS_INF) {
    res = POS_INF;
  } else {
    for (int n = 1; n <= maxIterations; n++) {
      term *= x / n;
      res += term;
      if (res > MyMAX) {
        res = POS_INF;
      }
    }
  }
  return res;
}
