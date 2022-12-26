#include "../s21_math.h"

long double s21_sin(double x) {
  x = s21_fmod(x, 2. * S21_PI);  //  ???
  long double result = 0;

  for (int i = 37; i >= 1; i -= 2)
    result += (((i - 1) % 4 == 0) ? 1 : -1) * s21_pow_int(x, i) / s21_fact(i);

  return result;
}

long double s21_cos(double x) {
  x = s21_fmod(x, 2. * S21_PI);  //  ???
  long double result = 0;

  for (int i = 36; i >= 0; i -= 2)
    result += ((i % 4 == 0) ? 1 : -1) * s21_pow_int(x, i) / s21_fact(i);

  return result;
}

long double s21_tan(double x) {
  x = s21_fmod(x, 2. * S21_PI_2);
  long double result = 0;

  int check_pi_2 = (s21_fabs(x) >= S21_PI_2 - 1e-16) && (s21_fabs(x) <= S21_PI_2 + 1e-16);
  int check_3_pi_2 = s21_fabs(x) >= (3 * S21_PI_2 - 1e-16) && (s21_fabs(x) <= 3 * S21_PI_2 + 1e-16);
  if (check_pi_2 || check_3_pi_2)
    result = S21_INF;
  else
    result = s21_sin(x) / s21_cos(x);
  return result;
}