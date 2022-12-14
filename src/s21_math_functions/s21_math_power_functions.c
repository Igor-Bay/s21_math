#include "../s21_math.h"

long double s21_pow_rec(long double base, int exp, long double acc) {
  return (exp == 0)       ? acc
         : (exp % 2 == 1) ? s21_pow_rec(base, exp - 1, acc * base)
                          : s21_pow_rec(base * base, exp / 2, acc);
}

long double s21_pow_int(double base, int exp) {
  return s21_pow_rec(base, exp, 1.0L);
}

long double s21_exp(double x) {
  long double result = 0;
  long double tmp = 1;
  if (x >= -20.)
    for (int i = 1; i <= 5000; ++i) {
      result += tmp;
      tmp *= x / i;
    }
  return result;
}

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

  while (d <= 0.5L) {
    d *= S21_E;
    t--;
  }

  long double result = 0.0L;

  if (d > 1.8L - EPS) {
    d /= S21_SQRTE;
    result += 0.5L;
  }

  long double tmp = d - 1.0L;
  for (int i = 1; i < 2500; ++i) {
    result += (i % 2 == 1 ? 1 : -1) * tmp / i;
    tmp *= d - 1.0L;
  }

  return result + t;
}

long double s21_pow(double base, double exp) {
  return s21_exp(s21_log(base) * exp);
}

long double s21_sqrt(double x) {
  if (isnan(x) || x < -EPS) {
    return NAN;
  }
  return s21_pow(x, 0.5);
}
