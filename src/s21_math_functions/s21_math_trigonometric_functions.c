#include "../s21_math.h"

long double s21_sin(double x) {
  x = s21_fmod(x, 2. * S21_PI);
  long double result = 0;

  for (int i = 37; i >= 1; i -= 2)
    result += (((i - 1) % 4 == 0) ? 1 : -1) * s21_pow_int(x, i) / s21_fact(i);

  return result;
}

long double s21_cos(double x) {
  x = s21_fmod(x, 2. * S21_PI);
  long double result = 0;

  for (int i = 36; i >= 0; i -= 2)
    result += ((i % 4 == 0) ? 1 : -1) * s21_pow_int(x, i) / s21_fact(i);

  return result;
}

long double s21_tan(double x) {
  x = s21_fmod(x, 2. * S21_PI_2);
  long double result = S21_NAN;

  if (!S21_IS_NAN(x) && !S21_IS_INF(x)) {
    if (s21_fabs(s21_cos(x)) < 1e-16)
      result = s21_sin(x) * S21_INF;
    else
      result = s21_sin(x) / s21_cos(x);
  }

  return result;
}