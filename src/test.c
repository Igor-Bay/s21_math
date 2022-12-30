/*
 * DO NOT EDIT THIS FILE. Generated by checkmk.
 * Edit the original source file "check_test.check" instead.
 */

#include <check.h>

#line 1 "check_test.check"
#include <check.h>
#include <locale.h>
#include <math.h>
#include <stdio.h>

#include "s21_math.h"

#define CHK_EPS 1e-6

START_TEST(fabs_basic) {
#line 15

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
    ck_assert_ldouble_eq_tol(s21_fabs(testcases[i]), fabs(testcases[i]),
                             CHK_EPS);
}
END_TEST

START_TEST(fabs_inf) {
#line 38

  double testcases[] = {S21_INF, -S21_INF};
  size_t n = sizeof(testcases) / sizeof(testcases[0]);

  for (size_t i = 0; i < n; ++i)
    ck_assert_ldouble_infinite(s21_fabs(testcases[i]));
}
END_TEST

START_TEST(fabs_nan) {
#line 46

  ck_assert_ldouble_nan(s21_fabs(S21_NAN));
}
END_TEST

START_TEST(fact_test) {
#line 52

  int testcases[] = {1, 2, 5, 10};
  int result[] = {1, 2, 120, 3628800};
  size_t n = sizeof(testcases) / sizeof(testcases[0]);

  for (size_t i = 0; i < n; ++i)
    ck_assert_int_eq(s21_fact(testcases[i]), result[i]);
}
END_TEST

START_TEST(fmod_basic) {
#line 65

  double testcases[] = {-S21_MAX_DOUBLE,
                        -1e20,
                        -7.4143526437e3,
                        -3144.51e-4,
                        1e-10,
                        1e-4,
                        4.2356e-2,
                        0.43,
                        0.5,
                        0.999999,
                        1.,
                        1.0000001,
                        1.001,
                        1.008888,
                        1.01,
                        1.1,
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
}
END_TEST

START_TEST(fmod_inf) {
#line 97

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
}
END_TEST

START_TEST(fmod_nan) {
#line 122

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
}
END_TEST

START_TEST(exp_basic) {
#line 154

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
}
END_TEST

START_TEST(exp_inf) {
#line 175

  double testcases[] = {1e4, 1e10, S21_MAX_DOUBLE};
  size_t n = sizeof(testcases) / sizeof(testcases[0]);

  for (size_t i = 0; i < n; ++i) {
    ck_assert_ldouble_infinite(s21_exp(testcases[i]));
    ck_assert_ldouble_infinite(exp(testcases[i]));
  }
}
END_TEST

START_TEST(exp_nan) {
#line 185

  ck_assert_ldouble_nan(s21_exp(S21_NAN));
  ck_assert_ldouble_nan(exp(S21_NAN));
}
END_TEST

START_TEST(log_basic) {
#line 192

  double testcases[] = {0.001,      1e-10,    1e-4, 4.2356e-2,     0.43,
                        0.5,        0.999999, 1.,   1.0000001,     1.001,
                        1.008888,   1.01,     1.1,  1.5,           100.,
                        9.123123e6, 1e4,      1e10, S21_MAX_DOUBLE};

  size_t n = sizeof(testcases) / sizeof(testcases[0]);

  for (size_t i = 0; i < n; ++i)
    ck_assert_ldouble_eq_tol(s21_log(testcases[i]), log(testcases[i]), CHK_EPS);
}
END_TEST

START_TEST(log_inf) {
#line 204

  double testcases[] = {0, S21_INF};
  size_t n = sizeof(testcases) / sizeof(testcases[0]);

  for (size_t i = 0; i < n; ++i) {
    ck_assert_ldouble_infinite(s21_log(testcases[i]));
    ck_assert_ldouble_infinite(log(testcases[i]));
  }
}
END_TEST

START_TEST(log_nan) {
#line 214

  double testcases[] = {-S21_MAX_DOUBLE, -1e4, -1., S21_NAN};
  size_t n = sizeof(testcases) / sizeof(testcases[0]);

  for (size_t i = 0; i < n; ++i) {
    ck_assert_ldouble_nan(s21_log(testcases[i]));
    ck_assert_ldouble_nan(log(testcases[i]));
  }
}
END_TEST

START_TEST(pow_basic_1) {
#line 226

  double testcases[] = {1., 2., 3., 4., 5., 10., 9.75, 24.536};
  size_t n = sizeof(testcases) / sizeof(testcases[0]);

  for (int sgn = -1; sgn <= 1; sgn += 2)
    for (size_t i = 0; i < n; ++i)
      for (size_t j = 0; j < n; ++j) {
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
}
END_TEST

START_TEST(pow_basic_2) {
#line 249

  double testcases[] = {0., 1., 2., 3., 4., 5., 10., 9.75, 24.536};
  size_t n = sizeof(testcases) / sizeof(testcases[0]);

  for (size_t i = 0; i < n; ++i)
    for (size_t j = 0; j < n; ++j) {
      long double result = s21_pow(testcases[i], testcases[j]);
      double expected_result = pow(testcases[i], testcases[j]);
      if (result > 1e10) {
        int power = ceil(log10l(result));
        result *= powl(10, 10 - power);
        result = truncl(result);

        power = ceil(log10l(expected_result));
        expected_result *= pow(10, 10 - power);
        expected_result = trunc(expected_result);
      }

      ck_assert_ldouble_eq_tol(result, expected_result, CHK_EPS);
    }
}
END_TEST

START_TEST(pow_basic_3) {
#line 271

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
  ck_assert_ldouble_eq(s21_pow(1., S21_NAN), pow(1., S21_NAN));
}
END_TEST

START_TEST(pow_nan_1) {
#line 291

  double testcases[] = {1.15,  2.623, 3.457, 4.08253,
                        5.457, 0.098, 9.75,  24.536};
  size_t n = sizeof(testcases) / sizeof(testcases[0]);

  for (size_t i = 0; i < n; ++i)
    for (size_t j = 0; j < n; ++j) {
      long double result = s21_pow(testcases[i] * -1., testcases[j]);
      double expected_result = pow(testcases[i] * -1., testcases[j]);

      ck_assert_ldouble_nan(result);
      ck_assert_ldouble_nan(expected_result);
    }
}
END_TEST

START_TEST(pow_nan_2) {
#line 305

  ck_assert_ldouble_nan(s21_pow(S21_NAN, 1.));
  ck_assert_ldouble_nan(s21_pow(S21_NAN, S21_NAN));
  ck_assert_ldouble_nan(pow(S21_NAN, 1.));
  ck_assert_ldouble_nan(pow(S21_NAN, S21_NAN));
}
END_TEST

START_TEST(pow_inf_1) {
#line 312

  ck_assert_ldouble_infinite(s21_pow(0., -1.));
  ck_assert_ldouble_infinite(s21_pow(0., -2.));
  ck_assert_ldouble_infinite(s21_pow(0., -3.));
  ck_assert_ldouble_infinite(pow(0., -1.));
  ck_assert_ldouble_infinite(pow(0., -2.));
  ck_assert_ldouble_infinite(pow(0., -3.));
}
END_TEST

START_TEST(pow_inf_2) {
#line 321

  double testcases[] = {24.536, 50., 100124.116131, -1245.15};
  size_t n = sizeof(testcases) / sizeof(testcases[0]);

  for (size_t i = 0; i < n; ++i) {
    long double result = s21_pow(testcases[i], 500);
    double expected_result = pow(testcases[i], 500);

    ck_assert_ldouble_infinite(result);
    ck_assert_ldouble_infinite(expected_result);
  }

  ck_assert_ldouble_nan(pow(-1.5, -2.5));
  ck_assert_ldouble_nan(s21_pow(-1.5, -2.5));
  ck_assert_ldouble_eq(s21_pow(-S21_INF, -3.), s21_pow(-S21_INF, -3.));
  ck_assert_ldouble_eq(s21_pow(-S21_INF, 3.), s21_pow(-S21_INF, 3.));
}
END_TEST

START_TEST(sqrt_basic) {
#line 341

  double testcases[] = {
      -0.,        1e-10, 1e-4,       4.2356e-2, 0.43,          0.5,
      0.999999,   1.,    1.0000001,  1.001,     1.008888,      1.01,
      1.1,        1.5,   11.67,      37.17,     49.000009,     100.,
      169.777777, 1e4,   9.123123e6, 1e10,      S21_MAX_DOUBLE};

  size_t n = sizeof(testcases) / sizeof(testcases[0]);

  for (size_t i = 0; i < n; ++i) {
    long double result = s21_sqrt(testcases[i]);
    double expected_result = sqrt(testcases[i]);
    if (result > 1e17) {
      int power = ceil(log10l(result));
      result *= powl(10, 17 - power);
      result = truncl(result);

      power = ceil(log10l(expected_result));
      expected_result *= pow(10, 17 - power);
      expected_result = trunc(expected_result);
    }
    ck_assert_ldouble_eq_tol(result, expected_result, CHK_EPS);
  }
}
END_TEST

START_TEST(sqrt_inf) {
#line 366

  ck_assert_ldouble_infinite(s21_sqrt(S21_INF));
  ck_assert_ldouble_infinite(sqrt(S21_INF));
}
END_TEST

START_TEST(sqrt_nan) {
#line 371

  double testcases[] = {-S21_MAX_DOUBLE, -1e4, -1., -0.1, S21_NAN};
  size_t n = sizeof(testcases) / sizeof(testcases[0]);

  for (size_t i = 0; i < n; ++i) {
    ck_assert_ldouble_nan(s21_sqrt(testcases[i]));
    ck_assert_ldouble_nan(sqrt(testcases[i]));
  }
}
END_TEST

START_TEST(sin_basic) {
#line 385

  for (double i = -4.; i <= 4.; i += 0.0625)
    ck_assert_ldouble_eq_tol(s21_sin(i * S21_PI), sin(i * S21_PI), CHK_EPS);
}
END_TEST

START_TEST(sin_nan) {
#line 390

  double testcases[] = {-S21_INF, S21_INF, S21_NAN};
  size_t n = sizeof(testcases) / sizeof(testcases[0]);

  for (size_t i = 0; i < n; ++i) {
    ck_assert_ldouble_nan(s21_sin(testcases[i]));
    ck_assert_ldouble_nan(sin(testcases[i]));
  }
}
END_TEST

START_TEST(cos_basic) {
#line 402

  for (double i = -4.; i <= 4.; i += 0.0625)
    ck_assert_ldouble_eq_tol(s21_cos(i * S21_PI), cos(i * S21_PI), CHK_EPS);
}
END_TEST

START_TEST(cos_nan) {
#line 407

  double testcases[] = {-S21_INF, S21_INF, S21_NAN};
  size_t n = sizeof(testcases) / sizeof(testcases[0]);

  for (size_t i = 0; i < n; ++i) {
    ck_assert_ldouble_nan(s21_cos(testcases[i]));
    ck_assert_ldouble_nan(cos(testcases[i]));
  }
}
END_TEST

START_TEST(tan_basic_inf) {
#line 419

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
}
END_TEST

START_TEST(tan_nan) {
#line 434

  double testcases[] = {-S21_INF, S21_INF, S21_NAN};
  size_t n = sizeof(testcases) / sizeof(testcases[0]);

  for (size_t i = 0; i < n; ++i) {
    ck_assert_ldouble_nan(s21_tan(testcases[i]));
    ck_assert_ldouble_nan(tan(testcases[i]));
  }
}
END_TEST

START_TEST(trunc_basic) {
#line 448

  double testcases[] = {-S21_MAX_DOUBLE,
                        -1e20,
                        -7.4143526437e3,
                        -3144.51e-4,
                        0.,
                        1e-10,
                        1e-4,
                        4.2356e-2,
                        0.43,
                        0.5,
                        0.999999,
                        1.,
                        1.0000001,
                        1.001,
                        1.008888,
                        1.01,
                        1.1,
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
}
END_TEST

START_TEST(trunc_inf) {
#line 480

  double testcases[] = {-S21_INF, S21_INF};
  size_t n = sizeof(testcases) / sizeof(testcases[0]);

  for (size_t i = 0; i < n; ++i) {
    ck_assert_ldouble_infinite(s21_trunc(testcases[i]));
    ck_assert_ldouble_infinite(trunc(testcases[i]));
  }
}
END_TEST

START_TEST(trunc_nan) {
#line 490

  ck_assert_ldouble_nan(s21_trunc(S21_NAN));
  ck_assert_ldouble_nan(trunc(S21_NAN));
}
END_TEST

START_TEST(floor_basic) {
#line 497

  double testcases[] = {-S21_MAX_DOUBLE,
                        -1e20,
                        -7.4143526437e3,
                        -3144.51e-4,
                        0.,
                        1e-10,
                        1e-4,
                        4.2356e-2,
                        0.43,
                        0.5,
                        0.999999,
                        1.,
                        1.0000001,
                        1.001,
                        1.008888,
                        1.01,
                        1.1,
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
}
END_TEST

START_TEST(floor_inf) {
#line 529

  double testcases[] = {-S21_INF, S21_INF};
  size_t n = sizeof(testcases) / sizeof(testcases[0]);

  for (size_t i = 0; i < n; ++i) {
    ck_assert_ldouble_infinite(s21_floor(testcases[i]));
    ck_assert_ldouble_infinite(floor(testcases[i]));
  }
}
END_TEST

START_TEST(floor_nan) {
#line 539

  ck_assert_ldouble_nan(s21_floor(S21_NAN));
  ck_assert_ldouble_nan(floor(S21_NAN));
}
END_TEST

START_TEST(ceil_basic) {
#line 546

  double testcases[] = {-S21_MAX_DOUBLE,
                        -1e20,
                        -7.4143526437e3,
                        -3144.51e-4,
                        0.,
                        1e-10,
                        1e-4,
                        4.2356e-2,
                        0.43,
                        0.5,
                        0.999999,
                        1.,
                        1.0000001,
                        1.001,
                        1.008888,
                        1.01,
                        1.1,
                        1.5,
                        100.,
                        9.123123e6,
                        1e4,
                        1e10,
                        S21_MAX_DOUBLE};

  size_t n = sizeof(testcases) / sizeof(testcases[0]);

  for (size_t i = 0; i < n; ++i)
    ck_assert_ldouble_eq_tol(s21_ceil(testcases[i]), ceil(testcases[i]),
                             CHK_EPS);
}
END_TEST

START_TEST(ceil_inf) {
#line 577

  double testcases[] = {-S21_INF, S21_INF};
  size_t n = sizeof(testcases) / sizeof(testcases[0]);

  for (size_t i = 0; i < n; ++i) {
    ck_assert_ldouble_infinite(s21_ceil(testcases[i]));
    ck_assert_ldouble_infinite(ceil(testcases[i]));
  }
}
END_TEST

START_TEST(ceil_nan) {
#line 587

  ck_assert_ldouble_nan(s21_ceil(S21_NAN));
  ck_assert_ldouble_nan(ceil(S21_NAN));
}
END_TEST

START_TEST(round_basic) {
#line 594

  double testcases[] = {-S21_MAX_DOUBLE,
                        -1e20,
                        -7.4143526437e3,
                        -3144.51e-4,
                        0.,
                        1e-10,
                        1e-4,
                        4.2356e-2,
                        0.43,
                        0.5,
                        0.999999,
                        1.,
                        1.0000001,
                        1.001,
                        1.008888,
                        1.01,
                        1.1,
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
}
END_TEST

START_TEST(round_inf) {
#line 626

  double testcases[] = {-S21_INF, S21_INF};
  size_t n = sizeof(testcases) / sizeof(testcases[0]);

  for (size_t i = 0; i < n; ++i) {
    ck_assert_ldouble_infinite(s21_round(testcases[i]));
    ck_assert_ldouble_infinite(round(testcases[i]));
  }
}
END_TEST

START_TEST(round_nan) {
#line 636

  ck_assert_ldouble_nan(s21_round(S21_NAN));
  ck_assert_ldouble_nan(round(S21_NAN));
}
END_TEST

START_TEST(asin_basic) {
#line 645

  double testcases[] = {-3144.51e-4, 0.,  1e-10,    1e-4, 4.2356e-2,
                        0.43,        0.5, 0.999999, 1.};

  size_t n = sizeof(testcases) / sizeof(testcases[0]);

  for (size_t i = 0; i < n; ++i)
    ck_assert_ldouble_eq_tol(s21_asin(testcases[i]), asin(testcases[i]),
                             CHK_EPS);
}
END_TEST

START_TEST(asin_nan) {
#line 655

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
}
END_TEST

START_TEST(acos_basic) {
#line 672

  double testcases[] = {-3144.51e-4, 0.,  1e-10,    1e-4, 4.2356e-2,
                        0.43,        0.5, 0.999999, 1.};

  size_t n = sizeof(testcases) / sizeof(testcases[0]);

  for (size_t i = 0; i < n; ++i)
    ck_assert_ldouble_eq_tol(s21_acos(testcases[i]), acos(testcases[i]),
                             CHK_EPS);
}
END_TEST

START_TEST(acos_nan) {
#line 682

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
}
END_TEST

START_TEST(atan_basic) {
#line 699

  double testcases[] = {-S21_INF,    -S21_MAX_DOUBLE,
                        -1e20,       -7.4143526437e3,
                        -3144.51e-4, 0.,
                        1e-10,       1e-4,
                        4.2356e-2,   0.43,
                        0.5,         0.999999,
                        1.,          1.0000001,
                        1.001,       1.008888,
                        1.01,        1.1,
                        1.5,         100.,
                        9.123123e6,  1e4,
                        1e10,        S21_MAX_DOUBLE,
                        S21_INF};

  size_t n = sizeof(testcases) / sizeof(testcases[0]);

  for (size_t i = 0; i < n; ++i)
    ck_assert_ldouble_eq_tol(s21_atan(testcases[i]), atan(testcases[i]),
                             CHK_EPS);
}
END_TEST

START_TEST(atan_nan) {
#line 720

  ck_assert_ldouble_nan(s21_atan(S21_NAN));
  ck_assert_ldouble_nan(atan(S21_NAN));
}
END_TEST

int main(void) {
  Suite *s1 = suite_create("math_basic_functions_suite");
  TCase *tc1_1 = tcase_create("s21_fabs_test");
  TCase *tc1_2 = tcase_create("s21_fact_test");
  Suite *s2 = suite_create("math_fmod_suite");
  TCase *tc2_1 = tcase_create("s21_fmod_test");
  Suite *s3 = suite_create("math_power_suite");
  TCase *tc3_1 = tcase_create("s21_exp_test");
  TCase *tc3_2 = tcase_create("s21_log_test");
  TCase *tc3_3 = tcase_create("s21_pow_test");
  TCase *tc3_4 = tcase_create("s21_sqrt_test");
  Suite *s4 = suite_create("math_trig_suite");
  TCase *tc4_1 = tcase_create("s21_sin_test");
  TCase *tc4_2 = tcase_create("s21_cos_test");
  TCase *tc4_3 = tcase_create("s21_tan_test");
  Suite *s5 = suite_create("math_round_suite");
  TCase *tc5_1 = tcase_create("s21_trunc_test");
  TCase *tc5_2 = tcase_create("s21_floor_test");
  TCase *tc5_3 = tcase_create("s21_ceil_test");
  TCase *tc5_4 = tcase_create("s21_round_test");
  Suite *s6 = suite_create("math_inv_trig_suite");
  TCase *tc6_1 = tcase_create("s21_asin_test");
  TCase *tc6_2 = tcase_create("s21_acos_test");
  TCase *tc6_3 = tcase_create("s21_atan_test");
  SRunner *sr = srunner_create(s1);
  int nf;

  suite_add_tcase(s1, tc1_1);
  tcase_add_test(tc1_1, fabs_basic);
  tcase_add_test(tc1_1, fabs_inf);
  tcase_add_test(tc1_1, fabs_nan);
  suite_add_tcase(s1, tc1_2);
  tcase_add_test(tc1_2, fact_test);
  suite_add_tcase(s2, tc2_1);
  tcase_add_test(tc2_1, fmod_basic);
  tcase_add_test(tc2_1, fmod_inf);
  tcase_add_test(tc2_1, fmod_nan);
  suite_add_tcase(s3, tc3_1);
  tcase_add_test(tc3_1, exp_basic);
  tcase_add_test(tc3_1, exp_inf);
  tcase_add_test(tc3_1, exp_nan);
  suite_add_tcase(s3, tc3_2);
  tcase_add_test(tc3_2, log_basic);
  tcase_add_test(tc3_2, log_inf);
  tcase_add_test(tc3_2, log_nan);
  suite_add_tcase(s3, tc3_3);
  tcase_add_test(tc3_3, pow_basic_1);
  tcase_add_test(tc3_3, pow_basic_2);
  tcase_add_test(tc3_3, pow_basic_3);
  tcase_add_test(tc3_3, pow_nan_1);
  tcase_add_test(tc3_3, pow_nan_2);
  tcase_add_test(tc3_3, pow_inf_1);
  tcase_add_test(tc3_3, pow_inf_2);
  suite_add_tcase(s3, tc3_4);
  tcase_add_test(tc3_4, sqrt_basic);
  tcase_add_test(tc3_4, sqrt_inf);
  tcase_add_test(tc3_4, sqrt_nan);
  suite_add_tcase(s4, tc4_1);
  tcase_add_test(tc4_1, sin_basic);
  tcase_add_test(tc4_1, sin_nan);
  suite_add_tcase(s4, tc4_2);
  tcase_add_test(tc4_2, cos_basic);
  tcase_add_test(tc4_2, cos_nan);
  suite_add_tcase(s4, tc4_3);
  tcase_add_test(tc4_3, tan_basic_inf);
  tcase_add_test(tc4_3, tan_nan);
  suite_add_tcase(s5, tc5_1);
  tcase_add_test(tc5_1, trunc_basic);
  tcase_add_test(tc5_1, trunc_inf);
  tcase_add_test(tc5_1, trunc_nan);
  suite_add_tcase(s5, tc5_2);
  tcase_add_test(tc5_2, floor_basic);
  tcase_add_test(tc5_2, floor_inf);
  tcase_add_test(tc5_2, floor_nan);
  suite_add_tcase(s5, tc5_3);
  tcase_add_test(tc5_3, ceil_basic);
  tcase_add_test(tc5_3, ceil_inf);
  tcase_add_test(tc5_3, ceil_nan);
  suite_add_tcase(s5, tc5_4);
  tcase_add_test(tc5_4, round_basic);
  tcase_add_test(tc5_4, round_inf);
  tcase_add_test(tc5_4, round_nan);
  suite_add_tcase(s6, tc6_1);
  tcase_add_test(tc6_1, asin_basic);
  tcase_add_test(tc6_1, asin_nan);
  suite_add_tcase(s6, tc6_2);
  tcase_add_test(tc6_2, acos_basic);
  tcase_add_test(tc6_2, acos_nan);
  suite_add_tcase(s6, tc6_3);
  tcase_add_test(tc6_3, atan_basic);
  tcase_add_test(tc6_3, atan_nan);

  srunner_add_suite(sr, s2);
  srunner_add_suite(sr, s3);
  srunner_add_suite(sr, s4);
  srunner_add_suite(sr, s5);
  srunner_add_suite(sr, s6);

  srunner_run_all(sr, CK_ENV);
  nf = srunner_ntests_failed(sr);
  srunner_free(sr);

  return nf == 0 ? 0 : 1;
}
