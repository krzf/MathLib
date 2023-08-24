#include "../Mymath.h"

long double Myceil(double x) {
  int int_x = (int)x;

  if (x < 0 && Myfabs(x - int_x) < 0.00001) {
    int_x -= 1;
  }

  if (x > int_x) {
    int_x += 1;
  }
  if (x == POS_INF) {
    return POS_INF;
  }
  if (x == NEG_INF) {
    return NEG_INF;
  }
  if (x != x) {
    return MyNAN;
  }
  return int_x;
}