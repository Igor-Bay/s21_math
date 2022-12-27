#include <check.h>
#include <locale.h>
#include <math.h>
#include <stdio.h>

#include "s21_math.h"

#define CHK_EPS 1e-6

#suite math_basic_functions_suite

#tcase s21_fabs_test

#test fabs_basic

double testcases[] = {-S21_MAX_DOUBLE,
                      -1e20,
                      -7.4143526437e3,
                      -3144.51e-4,
                      0.43,
                      -1e-10,
                      1e-4,
                      -4.2356e-2,
                      0.5,
                      -1.,
                      1.5,
                      -100.,
                      9.123123e6,
                      -1e4,
                      1e10,
                      S21_MAX_DOUBLE};
size_t n = sizeof(testcases) / sizeof(testcases[0]);

for (size_t i = 0; i < n; ++i)
  ck_assert_ldouble_eq_tol(s21_fabs(testcases[i]), fabs(testcases[i]), CHK_EPS);

#test fabs_inf

double testcases[] = {S21_INF, -S21_INF};
size_t n = sizeof(testcases) / sizeof(testcases[0]);

for (size_t i = 0; i < n; ++i)
  ck_assert_ldouble_infinite(s21_fabs(testcases[i]));

#test fabs_nan

ck_assert_ldouble_nan(s21_fabs(S21_NAN));

#tcase s21_fact_test

#test fact_test

int testcases[] = {1, 2, 5, 10};
int result[] = {1, 2, 120, 3628800};
size_t n = sizeof(testcases) / sizeof(testcases[0]);

for (size_t i = 0; i < n; ++i)
  ck_assert_int_eq(s21_fact(testcases[i]), result[i]);

#suite math_fmod_suite

#tcase s21_fmod_test

#test fmod_basic

double testcases[] = {-S21_MAX_DOUBLE,
                      -1e20,
                      -7.4143526437e3,
                      -3144.51e-4,
                      0.43,
                      1e-10,
                      1e-4,
                      4.2356e-2,
                      0.5,
                      1.,
                      1.5,
                      100.,
                      9.123123e6,
                      1e4,
                      1e10,
                      S21_MAX_DOUBLE};
size_t n = sizeof(testcases) / sizeof(testcases[0]);

for (size_t i = 0; i < n; ++i)
  for (size_t j = 0; j < n; ++j)
    ck_assert_ldouble_eq_tol(s21_fmod(testcases[i], testcases[j]),
                             fmod(testcases[i], testcases[j]), CHK_EPS);

#test fmod_inf

double testcases[] = {-S21_MAX_DOUBLE,
                      -1e20,
                      -7.4143526437e3,
                      -3144.51e-4,
                      0.,
                      0.43,
                      1e-10,
                      1e-4,
                      4.2356e-2,
                      0.5,
                      1.,
                      1.5,
                      100.,
                      9.123123e6,
                      1e4,
                      1e10,
                      S21_MAX_DOUBLE};
size_t n = sizeof(testcases) / sizeof(testcases[0]);

for (size_t i = 0; i < n; ++i)
  ck_assert_ldouble_eq_tol(s21_fmod(testcases[i], S21_INF),
                           fmod(testcases[i], S21_INF), CHK_EPS);

#test fmod_nan

double testcases[] = {-S21_MAX_DOUBLE,
                      -1e20,
                      -7.4143526437e3,
                      -3144.51e-4,
                      0.,
                      0.43,
                      1e-10,
                      1e-4,
                      4.2356e-2,
                      0.5,
                      1.,
                      1.5,
                      100.,
                      9.123123e6,
                      1e4,
                      1e10,
                      S21_MAX_DOUBLE};
size_t n = sizeof(testcases) / sizeof(testcases[0]);

for (size_t i = 0; i < n; ++i) {
  ck_assert_ldouble_nan(s21_fmod(testcases[i], 0));
  ck_assert_ldouble_nan(fmod(testcases[i], 0));
  ck_assert_ldouble_nan(s21_fmod(S21_NAN, testcases[i]));
  ck_assert_ldouble_nan(fmod(S21_NAN, testcases[i]));
}

#suite math_power_suite

#tcase s21_exp_test

#test exp_basic

double testcases[] = {1e-10, -1e-10, -19, 0.5,   -0.5, 1.,
                      -1.,   1e-4,   3e2, -1e-4, -1e4, -S21_MAX_DOUBLE};
size_t n = sizeof(testcases) / sizeof(testcases[0]);

for (size_t i = 0; i < n; ++i) {
  long double result = s21_exp(testcases[i]);
  double expected_result = exp(testcases[i]);
  if (result > 1e16) {
    int power = ceil(log10l(result));
    result *= powl(10, 16 - power);
    result = truncl(result);

    power = ceil(log10l(expected_result));
    expected_result *= pow(10, 16 - power);
    expected_result = trunc(expected_result);
  }
  ck_assert_ldouble_eq_tol(result, expected_result, CHK_EPS);
}

#test exp_inf

double testcases[] = {1e4, 1e10, S21_MAX_DOUBLE};
size_t n = sizeof(testcases) / sizeof(testcases[0]);

for (size_t i = 0; i < n; ++i) {
  ck_assert_ldouble_infinite(s21_exp(testcases[i]));
  ck_assert_ldouble_infinite(exp(testcases[i]));
}

#test exp_nan

ck_assert_ldouble_nan(s21_exp(S21_NAN));
ck_assert_ldouble_nan(exp(S21_NAN));

#tcase s21_log_test

#test log_basic

double testcases[] = {0.1, 0.43, 1e-10, 1e-4,          4.2356e-2,
                      0.5, 1.,   1.5,   100.,          9.123123e6,
                      1e4, 1e10, 1e20,  S21_MAX_DOUBLE};

size_t n = sizeof(testcases) / sizeof(testcases[0]);

for (size_t i = 0; i < n; ++i)
  ck_assert_ldouble_eq_tol(s21_log(testcases[i]), log(testcases[i]), CHK_EPS);

#test log_inf

double testcases[] = {0, S21_INF};
size_t n = sizeof(testcases) / sizeof(testcases[0]);

for (size_t i = 0; i < n; ++i) {
  ck_assert_ldouble_infinite(s21_log(testcases[i]));
  ck_assert_ldouble_infinite(log(testcases[i]));
}

#test log_nan

double testcases[] = {-S21_MAX_DOUBLE, -1e4, -1., S21_NAN};
size_t n = sizeof(testcases) / sizeof(testcases[0]);

for (size_t i = 0; i < n; ++i) {
  ck_assert_ldouble_nan(s21_log(testcases[i]));
  ck_assert_ldouble_nan(log(testcases[i]));
}

#tcase s21_pow_test

#test pow_basic

double testcases[] = {1., 2., 3., 4., 5., 10., 1e-10, 1e-5, 0.5, 0.1, 24.536};
size_t n = sizeof(testcases) / sizeof(testcases[0]);

for (size_t i = 0; i < n; ++i)
  for (size_t j = 0; j < n; ++j)
    for (int sgn = 1; sgn <= 1; sgn += 2) {
      // printf("%.16lf\t%.16lf\t%d\n", testcases[i], testcases[j], sgn);

      long double result = s21_pow(testcases[i], testcases[j] * sgn);
      double expected_result = pow(testcases[i], testcases[j] * sgn);
      if (result > 1e10) {
        int power = ceil(log10l(result));
        result *= powl(10, 10 - power);
        result = truncl(result);

        power = ceil(log10l(expected_result));
        expected_result *= pow(10, 10 - power);
        expected_result = trunc(expected_result);
      }
      // printf("%.6Lf\n%.6lf\n", result, expected_result);
      ck_assert_ldouble_eq_tol(result, expected_result, CHK_EPS);
    }

#test pow_inf

#test pow_nan

#test Sasha_pow
ck_assert_ldouble_eq(s21_pow(0, 0), pow(0, 0));
ck_assert_ldouble_eq(s21_pow(0, -1), pow(0, -1));
ck_assert_ldouble_eq(s21_pow(0, 1), pow(0, 1));
ck_assert_ldouble_eq(s21_pow(1, 0), pow(1, 0));
ck_assert_ldouble_eq(s21_pow(-1, 1), pow(-1, 1));
ck_assert_ldouble_eq(s21_pow(-1, 2), pow(-1, 2));
ck_assert_ldouble_eq(s21_pow(0.5, S21_INF), pow(0.5, S21_INF));
ck_assert_ldouble_eq(s21_pow(0.5, -S21_INF), pow(0.5, -S21_INF));
ck_assert_ldouble_eq(s21_pow(S21_NAN, 0), pow(S21_NAN, 0));
ck_assert_ldouble_eq(s21_pow(S21_INF, 0), pow(S21_INF, 0));
ck_assert_ldouble_eq(s21_pow(S21_INF, -1), pow(S21_INF, -1));
ck_assert_ldouble_eq(s21_pow(0, S21_INF), pow(0, S21_INF));
ck_assert_ldouble_eq(s21_pow(-1, -S21_INF), pow(-1, -S21_INF));
ck_assert_ldouble_eq(s21_pow(1, -S21_INF), pow(1, -S21_INF));
ck_assert_ldouble_eq(s21_pow(2, S21_INF), pow(2, S21_INF));
ck_assert_ldouble_eq(s21_pow(-2, S21_INF), pow(-2, S21_INF));
ck_assert_ldouble_eq(s21_pow(2, -S21_INF), pow(2, -S21_INF));
ck_assert_ldouble_eq(s21_pow(-2, -S21_INF), pow(-2, -S21_INF));
ck_assert_ldouble_eq(s21_pow(S21_INF, S21_INF), pow(S21_INF, S21_INF));
ck_assert_ldouble_eq(s21_pow(S21_INF, -S21_INF), pow(S21_INF, -S21_INF));
ck_assert_ldouble_eq(s21_pow(-S21_INF, S21_INF), pow(-S21_INF, S21_INF));
ck_assert_ldouble_eq(s21_pow(-S21_INF, -S21_INF), pow(-S21_INF, -S21_INF));
ck_assert_ldouble_nan(pow(-1.5, -2.5));
ck_assert_ldouble_nan(s21_pow(-1.5, -2.5));
ck_assert_ldouble_eq(s21_pow(-S21_INF, -3.), s21_pow(-S21_INF, -3.));
ck_assert_ldouble_eq(s21_pow(-S21_INF, 3.), s21_pow(-S21_INF, 3.));
ck_assert_ldouble_eq(s21_pow(5., 3.), s21_pow(5., 3.));
ck_assert_ldouble_eq(s21_pow(5.5, -3.1), s21_pow(5.5, -3.1));

#tcase s21_sqrt_test

#test sqrt_basic

double testcases[] = {-0.,  0.43, 1e-10, 1e-4,          4.2356e-2,
                      0.5, 1.,   1.5,   100.,          9.123123e6,
                      1e4, 1e10, 1e20,  S21_MAX_DOUBLE};

size_t n = sizeof(testcases) / sizeof(testcases[0]);

for (size_t i = 0; i < n; ++i) {
  long double result = s21_sqrt(testcases[i]);
  double expected_result = sqrt(testcases[i]);
  if (result > 1e14) {
    int power = ceil(log10l(result));
    result *= powl(10, 14 - power);
    result = truncl(result);

    power = ceil(log10l(expected_result));
    expected_result *= pow(10, 14 - power);
    expected_result = trunc(expected_result);

    ck_assert_ldouble_eq_tol(result, expected_result, CHK_EPS);
  }
}

#test sqrt_inf

ck_assert_ldouble_infinite(s21_sqrt(S21_INF));
ck_assert_ldouble_infinite(sqrt(S21_INF));

#test sqrt_nan

double testcases[] = {-S21_MAX_DOUBLE, -1e4, -1., -0.1, S21_NAN};
size_t n = sizeof(testcases) / sizeof(testcases[0]);

for (size_t i = 0; i < n; ++i) {
  ck_assert_ldouble_nan(s21_sqrt(testcases[i]));
  ck_assert_ldouble_nan(sqrt(testcases[i]));
}

#suite math_trig_suite

#tcase s21_sin_test

#test sin_basic

for (double i = -4.; i <= 4.; i += 0.0625)
  ck_assert_ldouble_eq_tol(s21_sin(i* S21_PI), sin(i* S21_PI), CHK_EPS);

#test sin_nan

double testcases[] = {-S21_INF, S21_INF, S21_NAN};
size_t n = sizeof(testcases) / sizeof(testcases[0]);

for (size_t i = 0; i < n; ++i) {
  ck_assert_ldouble_nan(s21_sin(testcases[i]));
  ck_assert_ldouble_nan(sin(testcases[i]));
}

#tcase s21_cos_test

#test cos_basic

for (double i = -4.; i <= 4.; i += 0.0625)
  ck_assert_ldouble_eq_tol(s21_cos(i* S21_PI), cos(i* S21_PI), CHK_EPS);

#test cos_nan

double testcases[] = {-S21_INF, S21_INF, S21_NAN};
size_t n = sizeof(testcases) / sizeof(testcases[0]);

for (size_t i = 0; i < n; ++i) {
  ck_assert_ldouble_nan(s21_cos(testcases[i]));
  ck_assert_ldouble_nan(cos(testcases[i]));
}

#tcase s21_tan_test

#test tan_basic_inf

for (double i = -4.; i <= 4.; i += 0.0625) {
  double x = i * S21_PI;
  double chk = fmod(fabs(x), 2. * S21_PI_2);
  int check_pi_2 = (chk >= S21_PI_2 - 1e-10) && (chk <= S21_PI_2 + 1e-10);
  int check_3_pi_2 =
      (chk >= 3 * S21_PI_2 - 1e-10) && (chk <= 3 * S21_PI_2 + 1e-10);

  if (!check_pi_2 && !check_3_pi_2) {
    ck_assert_ldouble_eq_tol(s21_tan(x), tan(x), CHK_EPS);
  } else
    ck_assert_double_infinite(s21_tan(x));
}

#test tan_nan

double testcases[] = {-S21_INF, S21_INF, S21_NAN};
size_t n = sizeof(testcases) / sizeof(testcases[0]);

for (size_t i = 0; i < n; ++i) {
  ck_assert_ldouble_nan(s21_tan(testcases[i]));
  ck_assert_ldouble_nan(tan(testcases[i]));
}

#suite math_round_suite

#tcase s21_trunc_test

#test trunc_basic

double testcases[] = {-S21_MAX_DOUBLE,
                      -1e20,
                      -7.4143526437e3,
                      -3144.51e-4,
                      0.,
                      0.43,
                      1e-10,
                      1e-4,
                      4.2356e-2,
                      0.5,
                      1.,
                      1.5,
                      100.,
                      9.123123e6,
                      1e4,
                      1e10,
                      S21_MAX_DOUBLE};
size_t n = sizeof(testcases) / sizeof(testcases[0]);

for (size_t i = 0; i < n; ++i)
  ck_assert_ldouble_eq_tol(s21_trunc(testcases[i]), trunc(testcases[i]),
                           CHK_EPS);

#test trunc_inf

double testcases[] = {-S21_INF, S21_INF};
size_t n = sizeof(testcases) / sizeof(testcases[0]);

for (size_t i = 0; i < n; ++i) {
  ck_assert_ldouble_infinite(s21_trunc(testcases[i]));
  ck_assert_ldouble_infinite(trunc(testcases[i]));
}

#test trunc_nan

ck_assert_ldouble_nan(s21_trunc(S21_NAN));
ck_assert_ldouble_nan(trunc(S21_NAN));

#tcase s21_floor_test

#test floor_basic

double testcases[] = {-S21_MAX_DOUBLE,
                      -1e20,
                      -7.4143526437e3,
                      -3144.51e-4,
                      0.,
                      0.43,
                      1e-10,
                      1e-4,
                      4.2356e-2,
                      0.5,
                      1.,
                      1.5,
                      100.,
                      9.123123e6,
                      1e4,
                      1e10,
                      S21_MAX_DOUBLE};
size_t n = sizeof(testcases) / sizeof(testcases[0]);

for (size_t i = 0; i < n; ++i)
  ck_assert_ldouble_eq_tol(s21_floor(testcases[i]), floor(testcases[i]),
                           CHK_EPS);

#test floor_inf

double testcases[] = {-S21_INF, S21_INF};
size_t n = sizeof(testcases) / sizeof(testcases[0]);

for (size_t i = 0; i < n; ++i) {
  ck_assert_ldouble_infinite(s21_floor(testcases[i]));
  ck_assert_ldouble_infinite(floor(testcases[i]));
}

#test floor_nan

ck_assert_ldouble_nan(s21_floor(S21_NAN));
ck_assert_ldouble_nan(floor(S21_NAN));

#tcase s21_ceil_test

#test ceil_basic

double testcases[] = {-S21_MAX_DOUBLE,
                      -1e20,
                      -7.4143526437e3,
                      -3144.51e-4,
                      0.,
                      0.43,
                      1e-10,
                      1e-4,
                      4.2356e-2,
                      0.5,
                      1.,
                      1.5,
                      100.,
                      9.123123e6,
                      1e4,
                      1e10,
                      S21_MAX_DOUBLE};
size_t n = sizeof(testcases) / sizeof(testcases[0]);

for (size_t i = 0; i < n; ++i)
  ck_assert_ldouble_eq_tol(s21_ceil(testcases[i]), ceil(testcases[i]), CHK_EPS);

#test ceil_inf

double testcases[] = {-S21_INF, S21_INF};
size_t n = sizeof(testcases) / sizeof(testcases[0]);

for (size_t i = 0; i < n; ++i) {
  ck_assert_ldouble_infinite(s21_ceil(testcases[i]));
  ck_assert_ldouble_infinite(ceil(testcases[i]));
}

#test ceil_nan

ck_assert_ldouble_nan(s21_ceil(S21_NAN));
ck_assert_ldouble_nan(ceil(S21_NAN));

#tcase s21_round_test

#test round_basic

double testcases[] = {-S21_MAX_DOUBLE,
                      -1e20,
                      -7.4143526437e3,
                      -3144.51e-4,
                      0.,
                      0.43,
                      1e-10,
                      1e-4,
                      4.2356e-2,
                      0.5,
                      1.,
                      1.5,
                      100.,
                      9.123123e6,
                      1e4,
                      1e10,
                      S21_MAX_DOUBLE};

size_t n = sizeof(testcases) / sizeof(testcases[0]);

for (size_t i = 0; i < n; ++i)
  ck_assert_ldouble_eq_tol(s21_round(testcases[i]), round(testcases[i]),
                           CHK_EPS);

#test round_inf

double testcases[] = {-S21_INF, S21_INF};
size_t n = sizeof(testcases) / sizeof(testcases[0]);

for (size_t i = 0; i < n; ++i) {
  ck_assert_ldouble_infinite(s21_round(testcases[i]));
  ck_assert_ldouble_infinite(round(testcases[i]));
}

#test round_nan

ck_assert_ldouble_nan(s21_round(S21_NAN));
ck_assert_ldouble_nan(round(S21_NAN));

#suite math_inv_trig_suite

#tcase s21_asin_test

#test asin_basic

double testcases[] = {-3144.51e-4, 0., 0.43, 1e-10, 1e-4, 4.2356e-2, 0.5, 1.};

size_t n = sizeof(testcases) / sizeof(testcases[0]);

for (size_t i = 0; i < n; ++i)
  ck_assert_ldouble_eq_tol(s21_asin(testcases[i]), asin(testcases[i]), CHK_EPS);

#test asin_nan

double testcases[] = {-S21_INF,   -S21_MAX_DOUBLE,
                      -1e20,      -7.4143526437e3,
                      1.5,        100.,
                      9.123123e6, 1e4,
                      1e10,       S21_MAX_DOUBLE,
                      S21_INF,    S21_NAN};
size_t n = sizeof(testcases) / sizeof(testcases[0]);

for (size_t i = 0; i < n; ++i) {
  ck_assert_ldouble_nan(s21_asin(testcases[i]));
  ck_assert_ldouble_nan(asin(testcases[i]));
}

#tcase s21_acos_test

#test acos_basic

double testcases[] = {-3144.51e-4, 0., 0.43, 1e-10, 1e-4, 4.2356e-2, 0.5, 1.};

size_t n = sizeof(testcases) / sizeof(testcases[0]);

for (size_t i = 0; i < n; ++i)
  ck_assert_ldouble_eq_tol(s21_acos(testcases[i]), acos(testcases[i]), CHK_EPS);

#test acos_nan

double testcases[] = {-S21_INF,   -S21_MAX_DOUBLE,
                      -1e20,      -7.4143526437e3,
                      1.5,        100.,
                      9.123123e6, 1e4,
                      1e10,       S21_MAX_DOUBLE,
                      S21_INF,    S21_NAN};
size_t n = sizeof(testcases) / sizeof(testcases[0]);

for (size_t i = 0; i < n; ++i) {
  ck_assert_ldouble_nan(s21_acos(testcases[i]));
  ck_assert_ldouble_nan(acos(testcases[i]));
}

#tcase s21_atan_test

#test atan_basic

double testcases[] = {-S21_INF,    -S21_MAX_DOUBLE,
                      -1e20,       -7.4143526437e3,
                      -3144.51e-4, 0.,
                      0.43,        1e-10,
                      1e-4,        4.2356e-2,
                      0.5,         1.,
                      1.5,         100.,
                      9.123123e6,  1e4,
                      1e10,        S21_MAX_DOUBLE,
                      S21_INF};

size_t n = sizeof(testcases) / sizeof(testcases[0]);

for (size_t i = 0; i < n; ++i)
  ck_assert_ldouble_eq_tol(s21_atan(testcases[i]), atan(testcases[i]), CHK_EPS);

#test atan_nan

ck_assert_ldouble_nan(s21_atan(S21_NAN));
ck_assert_ldouble_nan(atan(S21_NAN));