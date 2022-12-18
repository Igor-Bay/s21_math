#include "../s21_math.h"

long double s21_fabs(double x) {
  double_cast dc = {x};
  dc.parts.sgn = 0;
  return dc.d;
}

long double s21_fact_rec(int n, long double acc) {
  return (n == 0) ? acc : s21_fact_rec(n - 1, acc * n);
}

long double s21_fact(int n) { return s21_fact_rec(n, 1.); }
