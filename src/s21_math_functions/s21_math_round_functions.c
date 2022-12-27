#include "../s21_math.h"

long double s21_trunc(double x) {
  double_cast dc = {x};
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
  double_cast dc = {x};
  double res = s21_trunc(x);
  if (s21_fabs(x - res) > EPS) res += dc.parts.sgn ? -1. : 0;
  return res;
}

long double s21_ceil(double x) {
  double_cast dc = {x};
  double res = s21_trunc(x);
  if (s21_fabs(x - res) > EPS) res += dc.parts.sgn ? 0. : 1.;
  return res;
}

long double s21_round(double x) {
  double_cast dc = {x};
  double res = x;
  if (dc.parts.exp < 1075) {
    res = s21_trunc(x);
    if (s21_fabs(x - res) >= 0.5 - EPS) res += dc.parts.sgn ? -1. : 1.;
  }
  return res;
}