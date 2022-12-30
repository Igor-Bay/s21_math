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
  long double tmp_big = 1;
  if (S21_IS_NAN(x))
    result = x;
  else if (x >= 1e4)
    result = S21_INF;
  else if (x >= -20.) {
    while (x > 10) {
      tmp_big *= S21_E;
      --x;
    }
    for (int i = 1; i <= 5000; ++i) {
      result += tmp;
      tmp *= x / i;
    }
  }
  return result * tmp_big;
}

long double s21_log(double x) {
  long double result = 0.0L;

  if (x < -EPS)
    result = S21_NAN;
  else if (x < EPS)
    result = -S21_INF;
  else if (S21_IS_INF(x))
    result = S21_INF;
  else {
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

    if (d > 1.8L - EPS) {
      d /= S21_SQRTE;
      result += 0.5L;
    }

    long double tmp = d - 1.0L;
    for (int i = 1; i < 2500; ++i) {
      result += (i % 2 == 1 ? 1 : -1) * tmp / i;
      tmp *= d - 1.0L;
    }
    result += t;
  }
  return result;
}

long double s21_pow(double base, double exp) {
  long double result = 0;

  if (S21_IS_NULL(base - 1)) {
    result = 1;
  } else if (S21_IS_NAN(exp)) {
    result = S21_NAN;
  } else if (S21_IS_NULL(exp)) {
    result = 1;
  } else if (S21_IS_NAN(base)) {
    result = S21_NAN;
  } else if (exp == S21_INF) {
    result = (S21_IS_NULL(s21_fabs(base) - 1)
                  ? 1
                  : ((s21_fabs(base) < 1 + EPS) ? 0 : S21_INF));
  } else if (exp == -S21_INF) {
    result = (S21_IS_NULL(s21_fabs(base) - 1)
                  ? 1
                  : ((s21_fabs(base) < 1 + EPS) ? S21_INF : 0));
  } else if (S21_IS_NEG(base)) {
    if (S21_IS_NULL(exp - s21_trunc(exp))) {
      result = s21_pow(-base, exp);
      result *= S21_IS_NULL(s21_fmod(exp, 2)) ? 1 : -1;
    } else
      result = S21_NAN;
  } else {
    long double power = s21_log(base) * exp;
    long double left_bound = s21_exp(power - 1);
    long double right_bound = s21_exp(power + 1);
    if (S21_IS_INF(left_bound)) {
      result = left_bound;
    } else {
      if (S21_IS_INF(right_bound)) {
        right_bound = S21_MAX_DOUBLE;
      }

      long double mid = left_bound / 2. + right_bound / 2.;
      long double func_diff = s21_log(mid) - power;
      int counter = 0;

      while (s21_fabs(func_diff) >= 1e-16 &&
             left_bound + 2.0L * 1e-16L <= right_bound && counter < 14) {
        long double log_diff = s21_log(right_bound) - s21_log(left_bound);
        if (s21_fabs(log_diff) > EPS) {
          right_bound -= s21_fabs((right_bound - left_bound) *
                                  (s21_log(right_bound) - power) / (log_diff));
        }
        left_bound -= (s21_log(left_bound) - power) * left_bound;
        mid = left_bound / 2. + right_bound / 2.;
        func_diff = s21_log(mid) - power;
        counter++;
      }
      result = mid;
    }
  }
  return result;
}

long double s21_sqrt(double x) {
  long double result = 0;

  if (S21_IS_NAN(x) || x < -EPS) {
    result = S21_NAN;
  } else if (S21_IS_NEG(x)) {
    result = -0.;
  } else {
    result = s21_pow(x, 0.5);
  }
  return result;
}
