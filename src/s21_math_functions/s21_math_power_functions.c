#include "../s21_math.h"

long double s21_pow_rec(long double base, int exp, long double acc) {
  return (exp == 0)       ? acc
         : (exp % 2 == 1) ? s21_pow_rec(base, exp - 1, acc * base)
                          : s21_pow_rec(base * base, exp / 2, acc);
}

long double s21_pow(double base, int exp) {
  return s21_pow_rec(base, exp, 1.0L);
}

long double s21_exp(double x) {
  long double result = 0;
  if (x >= -10.)
    for (int i = 36; i >= 0; --i) result += s21_pow(x, i) / s21_fact(i);

  return result;
}

#include <math.h>
long double s21_log(double x) {
  if (x < -EPS)
    return NAN;
  else if (x < EPS)
    return -INFINITY;
  else if (x > __DBL_MAX__)
    return INFINITY;

  int t = 0;
  long double d = x;
  while (d >= S21_E) {
    d /= S21_E;
    t++;
  }

  long double result = t;

  if (d > 2.0L - EPS) {
    d /= sqrt(S21_E);
    result += 0.5L;
  }

  for (int i = 1000; i > 0; --i)
    result += (i % 2 == 1 ? 1 : -1) * s21_pow(d - 1.0L, i) / i;

  return result;
}
