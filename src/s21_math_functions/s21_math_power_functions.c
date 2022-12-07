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