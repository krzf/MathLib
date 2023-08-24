#include "../Mymath.h"
long double Mypow(double base, double exp) {
  if (!exp) {
    return 1;
  }
  if (base == NEG_INF && exp == NEG_INF) {
    return 0;
  }
  if (base == NEG_INF && exp == POS_INF) {
    return POS_INF;
  }
  if (base < 0 && exp != (long long int)exp) {
    return MyNAN;
  }
  long double res = 0;
  int sign;
  if (base < 0) {
    sign = -1;
  } else {
    sign = 1;
  }

  res = Myexp(exp * Mylog(base * sign));
  if (Myfmod(exp, 2)) {
    res *= sign;
    return res;
  }
  return res;
}