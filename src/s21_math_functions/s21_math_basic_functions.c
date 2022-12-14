#include "../s21_math.h"

long double s21_fabs(double x) {
  double_cast dc = {.d = x};
  dc.parts.sgn = 0;
  return dc.d;
}

long double s21_fact_rec(int n, long double acc) {
  return (n == 0) ? acc : s21_fact_rec(n - 1, acc * n);
}

long double s21_fact(int n) { return s21_fact_rec(n, 1.); }

long double s21_trunc(double x) {
  double_cast dc = {.d = x};
  unsigned int sgn = dc.parts.sgn;
  if (dc.parts.exp > 1022 && dc.parts.exp < 1075) {
    uint64_t mask = ~((1LLU << (52LLU - (dc.parts.exp - 1023LLU))) - 1);
    dc.parts.mnt &= mask;
  } else if (dc.parts.exp <= 1022)
    dc.d = 0;
  dc.parts.sgn = sgn;
  return dc.d;
}

long double s21_floor(double x) {
  double_cast dc = {.d = x};
  double_cast dc_res = {.d = s21_trunc(x)};
  if (fabs(x) - fabs(dc_res.d) > EPS) dc_res.d += dc.parts.sgn ? -1. : 0;
  dc_res.parts.sgn = dc.parts.sgn;
  return dc_res.d;
}

long double s21_ceil(double x) {
  double_cast dc = {.d = x};
  double_cast dc_res = {.d = s21_trunc(x)};
  if (fabs(x) - fabs(dc_res.d) > EPS) dc_res.d += dc.parts.sgn ? 0. : 1.;
  dc_res.parts.sgn = dc.parts.sgn;
  return dc_res.d;
}

long double s21_round(double x) {
  double_cast dc = {.d = x};
  double x_trnc = x;
  if (dc.parts.exp < 1075) {
    x_trnc = s21_trunc(x);
    if (fabs(x) - fabs(x_trnc) >= 0.5) x_trnc += dc.parts.sgn ? -1. : 1.;
  }
  return x_trnc;
}

long double s21_fmod(double x, double y) { return x - trunc(x / y) * y; }
