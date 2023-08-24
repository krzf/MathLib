#ifndef MyMATH_H
#define MyMATH_H

#include <stdlib.h>

#define MyINF __builtin_huge_vall()
#define MyMIN_INF -__builtin_huge_vall()
#define MyEPS 1e-7

#define MyPI 3.1415926535897932384626433832795
#define MyNAN __builtin_nanf("0x7fc00000")
#define MyMAX 1e100

// #define INFINITY (-1.0 / 0.0)
#define POS_INF 1.0 / 0.0L
#define NEG_INF -1.0 / 0.0L

#define MyEXP 2.7182818284590452

// me
int Myabs(int x);
long double Myfabs(double x);

// trigonom
long double Mysin(double x);
long double Mycos(double x);
long double Mytan(double x);
long double Myatan(double x);
long double Myacos(double x);
long double Myasin(double x);

// ED
long double Mysqrt(double x);
long double Myfloor(double x);
long double Myfmod(double x, double y);
long double Myceil(double x);
long double Mypow(double base, double exp);
long double Myexp(double x);
long double Mylog(double x);

#endif