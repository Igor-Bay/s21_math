#include "../s21_math.h"

long double s21_fabs(double x) {
  double_bits temp;
  temp.d = x;
  return temp.i & 0x7FFFffffFFFFffff;
}

long double s21_fact_rec(int n, long double acc) {
  return (n == 0.) ? acc : s21_fact_rec(n - 1, acc * n);
}

long double s21_fact(int n) { return s21_fact_rec(n, 1.); }