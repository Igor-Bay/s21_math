
#include <math.h>
#include <stdlib.h>

#include "s21_math.h"

#define CHK_EPS 1e-6

void abs_basic() {
  int testcases[] = {-2147483648, -422112, -3458, -2,     -1,        -0,
                     0,           1,       2,     481516, 2147483647};
  size_t n = sizeof(testcases) / sizeof(testcases[0]);

  for (size_t i = 0; i < n; ++i) s21_abs(testcases[i]);
}

void fabs_basic() {
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

  for (size_t i = 0; i < n; ++i) s21_fabs(testcases[i]);
}

void fabs_inf() {
  double testcases[] = {S21_INF, -S21_INF};
  size_t n = sizeof(testcases) / sizeof(testcases[0]);

  for (size_t i = 0; i < n; ++i) s21_fabs(testcases[i]);
}

void fabs_nan() { (s21_fabs(S21_NAN)); }

void fact_test() {
  int testcases[] = {1, 2, 5, 10};
  size_t n = sizeof(testcases) / sizeof(testcases[0]);

  for (size_t i = 0; i < n; ++i) s21_fact(testcases[i]);
}

void fmod_basic() {
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
    for (size_t j = 0; j < n; ++j) s21_fmod(testcases[i], testcases[j]);
}

void fmod_inf() {
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

  for (size_t i = 0; i < n; ++i) s21_fmod(testcases[i], S21_INF);
}

void fmod_nan() {
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
    s21_fmod(testcases[i], 0);
    s21_fmod(S21_NAN, testcases[i]);
  }
}

void exp_basic() {
  double testcases[] = {1e-10, -1e-10, -19, 0.5,   -0.5, 1.,
                        -1.,   1e-4,   3e2, -1e-4, -1e4, -S21_MAX_DOUBLE};
  size_t n = sizeof(testcases) / sizeof(testcases[0]);

  for (size_t i = 0; i < n; ++i) {
    long double result = s21_exp(testcases[i]);

    if (result > 1e16) {
      int power = ceil(log10l(result));
      result *= powl(10, 16 - power);
      result = truncl(result);
    }
  }
}

void exp_inf() {
  double testcases[] = {1e4, 1e10, S21_MAX_DOUBLE};
  size_t n = sizeof(testcases) / sizeof(testcases[0]);

  for (size_t i = 0; i < n; ++i) {
    s21_exp(testcases[i]);
  }
}

void exp_nan() { s21_exp(S21_NAN); }

void log_basic() {
  double testcases[] = {0.001,      1e-10,    1e-4, 4.2356e-2,     0.43,
                        0.5,        0.999999, 1.,   1.0000001,     1.001,
                        1.008888,   1.01,     1.1,  1.5,           100.,
                        9.123123e6, 1e4,      1e10, S21_MAX_DOUBLE};

  size_t n = sizeof(testcases) / sizeof(testcases[0]);

  for (size_t i = 0; i < n; ++i) s21_log(testcases[i]);
}

void log_inf() {
  double testcases[] = {0, S21_INF};
  size_t n = sizeof(testcases) / sizeof(testcases[0]);

  for (size_t i = 0; i < n; ++i) {
    s21_log(testcases[i]);
  }
}

void log_nan() {
  double testcases[] = {-S21_MAX_DOUBLE, -1e4, -1., S21_NAN};
  size_t n = sizeof(testcases) / sizeof(testcases[0]);

  for (size_t i = 0; i < n; ++i) {
    s21_log(testcases[i]);
  }
}

void pow_basic_1() {
  double testcases[] = {1., 2., 3., 4., 5., 10., 9.75, 24.536};
  size_t n = sizeof(testcases) / sizeof(testcases[0]);

  for (int sgn = -1; sgn <= 1; sgn += 2)
    for (size_t i = 0; i < n; ++i)
      for (size_t j = 0; j < n; ++j) {
        long double result = s21_pow(testcases[i], testcases[j] * sgn);

        if (result > 1e10) {
          int power = ceil(log10l(result));
          result *= powl(10, 10 - power);
          result = truncl(result);
        }
      }
}

void pow_basic_2() {
  double testcases[] = {0., 1., 2., 3., 4., 5., 10., 9.75, 24.536};
  size_t n = sizeof(testcases) / sizeof(testcases[0]);

  for (size_t i = 0; i < n; ++i)
    for (size_t j = 0; j < n; ++j) {
      long double result = s21_pow(testcases[i], testcases[j]);

      if (result > 1e10) {
        int power = ceil(log10l(result));
        result *= powl(10, 10 - power);
        result = truncl(result);
      }
    }
}

void pow_basic_3() {
  s21_pow(0.5, S21_INF);
  s21_pow(0.5, -S21_INF);
  s21_pow(S21_NAN, 0);
  s21_pow(S21_INF, 0);
  s21_pow(S21_INF, -1);
  s21_pow(0, S21_INF);
  s21_pow(-1, -S21_INF);
  s21_pow(1, -S21_INF);
  s21_pow(2, S21_INF);
  s21_pow(-2, S21_INF);
  s21_pow(2, -S21_INF);
  s21_pow(-2, -S21_INF);
  s21_pow(S21_INF, S21_INF);
  s21_pow(S21_INF, -S21_INF);
  s21_pow(-S21_INF, S21_INF);
  s21_pow(-S21_INF, -S21_INF);
  s21_pow(1., S21_NAN);
}

void pow_nan_1() {
  double testcases[] = {1.15,  2.623, 3.457, 4.08253,
                        5.457, 0.098, 9.75,  24.536};
  size_t n = sizeof(testcases) / sizeof(testcases[0]);

  for (size_t i = 0; i < n; ++i)
    for (size_t j = 0; j < n; ++j) {
      long double result = s21_pow(testcases[i] * -1., testcases[j]);
      s21_round(result);
    }
}

void pow_nan_2() {
  s21_pow(S21_NAN, 1.);
  s21_pow(S21_NAN, S21_NAN);
}

void pow_inf_1() {
  s21_pow(0., -1.);
  s21_pow(0., -2.);
  s21_pow(0., -3.);
}

void pow_inf_2() {
  double testcases[] = {24.536, 50., 100124.116131, -1245.15};
  size_t n = sizeof(testcases) / sizeof(testcases[0]);

  for (size_t i = 0; i < n; ++i) {
    long double result = s21_pow(testcases[i], 500);
    s21_round(result);
  }
}

void Sasha_pow() {
  s21_pow(-1.5, -2.5);
  s21_pow(-S21_INF, -3.);
  s21_pow(-S21_INF, 3.);
}

void sqrt_basic() {
  double testcases[] = {
      -0.,        1e-10, 1e-4,       4.2356e-2, 0.43,          0.5,
      0.999999,   1.,    1.0000001,  1.001,     1.008888,      1.01,
      1.1,        1.5,   11.67,      37.17,     49.000009,     100.,
      169.777777, 1e4,   9.123123e6, 1e10,      S21_MAX_DOUBLE};

  size_t n = sizeof(testcases) / sizeof(testcases[0]);

  for (size_t i = 0; i < n; ++i) {
    long double result = s21_sqrt(testcases[i]);
    s21_round(result);
  }
}

void sqrt_inf() { s21_sqrt(S21_INF); }

void sqrt_nan() {
  double testcases[] = {-S21_MAX_DOUBLE, -1e4, -1., -0.1, S21_NAN};
  size_t n = sizeof(testcases) / sizeof(testcases[0]);

  for (size_t i = 0; i < n; ++i) {
    s21_sqrt(testcases[i]);
  }
}

void sin_basic() {
  for (double i = -4.; i <= 4.; i += 0.0625) s21_sin(i * S21_PI);
}

void sin_nan() {
  double testcases[] = {-S21_INF, S21_INF, S21_NAN};
  size_t n = sizeof(testcases) / sizeof(testcases[0]);

  for (size_t i = 0; i < n; ++i) {
    s21_sin(testcases[i]);
  }
}

void cos_basic() {
  for (double i = -4.; i <= 4.; i += 0.0625) s21_cos(i * S21_PI);
}

void cos_nan() {
  double testcases[] = {-S21_INF, S21_INF, S21_NAN};
  size_t n = sizeof(testcases) / sizeof(testcases[0]);

  for (size_t i = 0; i < n; ++i) {
    s21_cos(testcases[i]);
  }
}

void tan_basic_inf() {
  for (double i = -4.; i <= 4.; i += 0.0625) {
    double x = i * S21_PI;
    s21_tan(x);
  }
}

void tan_nan() {
  double testcases[] = {-S21_INF, S21_INF, S21_NAN};
  size_t n = sizeof(testcases) / sizeof(testcases[0]);

  for (size_t i = 0; i < n; ++i) {
    s21_tan(testcases[i]);
  }
}

void trunc_basic() {
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

  for (size_t i = 0; i < n; ++i) s21_trunc(testcases[i]);
}

void trunc_inf() {
  double testcases[] = {-S21_INF, S21_INF};
  size_t n = sizeof(testcases) / sizeof(testcases[0]);

  for (size_t i = 0; i < n; ++i) {
    s21_trunc(testcases[i]);
  }
}

void trunc_nan() { s21_trunc(S21_NAN); }

void floor_basic() {
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

  for (size_t i = 0; i < n; ++i) s21_floor(testcases[i]);
}

void floor_inf() {
  double testcases[] = {-S21_INF, S21_INF};
  size_t n = sizeof(testcases) / sizeof(testcases[0]);

  for (size_t i = 0; i < n; ++i) {
    s21_floor(testcases[i]);
  }
}

void floor_nan() { s21_floor(S21_NAN); }

void ceil_basic() {
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

  for (size_t i = 0; i < n; ++i) s21_ceil(testcases[i]);
}

void ceil_inf() {
  double testcases[] = {-S21_INF, S21_INF};
  size_t n = sizeof(testcases) / sizeof(testcases[0]);

  for (size_t i = 0; i < n; ++i) {
    s21_ceil(testcases[i]);
  }
}

void ceil_nan() { s21_ceil(S21_NAN); }

void round_basic() {
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

  for (size_t i = 0; i < n; ++i) s21_round(testcases[i]);
}

void round_inf() {
  double testcases[] = {-S21_INF, S21_INF};
  size_t n = sizeof(testcases) / sizeof(testcases[0]);

  for (size_t i = 0; i < n; ++i) {
    s21_round(testcases[i]);
  }
}

void round_nan() { s21_round(S21_NAN); }

void asin_basic() {
  double testcases[] = {-3144.51e-4, 0.,  1e-10,    1e-4, 4.2356e-2,
                        0.43,        0.5, 0.999999, 1.};

  size_t n = sizeof(testcases) / sizeof(testcases[0]);

  for (size_t i = 0; i < n; ++i) s21_asin(testcases[i]);
}

void asin_nan() {
  double testcases[] = {-S21_INF,   -S21_MAX_DOUBLE,
                        -1e20,      -7.4143526437e3,
                        1.5,        100.,
                        9.123123e6, 1e4,
                        1e10,       S21_MAX_DOUBLE,
                        S21_INF,    S21_NAN};
  size_t n = sizeof(testcases) / sizeof(testcases[0]);

  for (size_t i = 0; i < n; ++i) {
    s21_asin(testcases[i]);
  }
}

void acos_basic() {
  double testcases[] = {-3144.51e-4, 0.,  1e-10,    1e-4, 4.2356e-2,
                        0.43,        0.5, 0.999999, 1.};

  size_t n = sizeof(testcases) / sizeof(testcases[0]);

  for (size_t i = 0; i < n; ++i) s21_acos(testcases[i]);
}

void acos_nan() {
  double testcases[] = {-S21_INF,   -S21_MAX_DOUBLE,
                        -1e20,      -7.4143526437e3,
                        1.5,        100.,
                        9.123123e6, 1e4,
                        1e10,       S21_MAX_DOUBLE,
                        S21_INF,    S21_NAN};
  size_t n = sizeof(testcases) / sizeof(testcases[0]);

  for (size_t i = 0; i < n; ++i) {
    s21_acos(testcases[i]);
  }
}

void atan_basic() {
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

  for (size_t i = 0; i < n; ++i) s21_atan(testcases[i]);

  s21_atan(S21_NAN);
}

int main(void) {
  abs_basic();
  fabs_basic();
  fabs_inf();
  fabs_nan();
  fact_test();
  fmod_basic();
  fmod_inf();
  fmod_nan();
  exp_basic();
  exp_inf();
  exp_nan();
  log_basic();
  log_inf();
  log_nan();
  pow_basic_1();
  pow_basic_2();
  pow_basic_3();
  pow_nan_1();
  pow_nan_2();
  pow_inf_1();
  pow_inf_2();
  Sasha_pow();
  sqrt_basic();
  sqrt_inf();
  sqrt_nan();
  sin_basic();
  sin_nan();
  cos_basic();
  cos_nan();
  tan_basic_inf();
  tan_nan();
  trunc_basic();
  trunc_inf();
  trunc_nan();
  floor_basic();
  floor_inf();
  floor_nan();
  ceil_basic();
  ceil_inf();
  ceil_nan();
  round_basic();
  round_inf();
  round_nan();
  asin_basic();
  asin_nan();
  acos_basic();
  acos_nan();
  atan_basic();
  atan_basic();

  return 0;
}