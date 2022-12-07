#include "../s21_math.h"

long double s21_fabs(double x) { return x > EPS ? x : x < -EPS ? -x : 0; }

long double s21_fact_rec(int n, long double acc) {
  return (n == 0) ? acc : s21_fact_rec(n - 1, acc * n);
}

long double s21_fact(int n) { return s21_fact_rec(n, 1.0L); }