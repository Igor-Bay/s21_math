#include "../s21_math.h"

long double s21_atan(double x) {
  long double result = 0L;
  long double temp = s21_fabs(x);
  if (S21_IS_NAN(x)) {
    result = x;
  } else if (S21_IS_INF(x)) {
    result = S21_PI_2;
  } else if (temp < 1.0L + 1e-2 && temp > 1.0 - 1e-2) {
    long double left_bound = S21_PI_4 - 0.2;
    long double right_bound = S21_PI_4 + 0.2;
    long double prev_mid = 0.0L;
    long double mid = (left_bound + right_bound) / 2;
    long double func_diff = s21_tan(mid) - temp;

    while (s21_fabs(func_diff) > 1e-7 && s21_fabs(mid - prev_mid) > 1e-10) {
      if (func_diff < -EPS) {
        left_bound = mid;
      } else {
        right_bound = mid;
      }
      prev_mid = mid;
      mid = (left_bound + right_bound) / 2;
      func_diff = s21_tan(mid) - temp;
    }

    result = mid;
  } else if (temp < 1.0L + 1e-10) {
    for (int i = 1; i < 2000; i += 2) {
      result += (((i - 1) % 4 == 0) ? 1 : -1) * temp / (long double)i;
      temp *= x * x;
    }
  } else {
    result = S21_PI_2;
    for (int i = 1; i < 10000; i += 2) {
      result += (((i - 1) % 4 == 0) ? -1 : 1) / temp / (long double)i;
      temp *= x * x;
    }
  }
  if (x < -EPS) {
    result = -result;
  }
  return result;
}

long double s21_asin(double x) {
  long double result = 0L;
  result = s21_atan(x / s21_sqrt(1 - x * x));
  return result;
}

long double s21_acos(double x) {
  long double result = 0L;
  if (s21_fabs(x) <= 1. + EPS) {
    long double left_bound = S21_PI;
    long double right_bound = 0;
    long double prev_mid = 0.0L;
    long double mid = (left_bound + right_bound) / 2;
    long double func_diff = s21_cos(mid) - x;

    while (s21_fabs(func_diff) > 1e-15 && s21_fabs(mid - prev_mid) > 1e-10) {
      if (func_diff < -EPS) {
        left_bound = mid;
      } else {
        right_bound = mid;
      }
      prev_mid = mid;
      mid = (left_bound + right_bound) / 2;
      func_diff = s21_cos(mid) - x;
    }

    if (s21_fabs(func_diff) > 1e-1) {
      result = S21_NAN;
    } else {
      result = mid;
    }
  } else
    result = S21_NAN;

  return result;
}
