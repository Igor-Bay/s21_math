#include "../s21_math.h"

long double s21_fmod(double x, double y) {
  double_cast dx = {x}, dy = {y};
  long double result = 0.;

  if (S21_IS_NAN(x + y))
    result = x + y;
  else if (S21_IS_INF(x) || s21_fabs(y) < EPS)
    result = S21_NAN;
  else if (S21_IS_INF(y) || s21_fabs(x) < EPS)
    result = x;
  else if (s21_fabs(x) < s21_fabs(y) + EPS) {  // x <= y
    if (s21_fabs(x - y) < EPS)                 // x == y
      result = 0. * ((dx.parts.sgn - dy.parts.sgn) ? -1 : 1);
    else
      result = x;
  } else {
    int64_t sx = dx.parts.mnt | 0x0010000000000000ULL;
    int64_t sy = dy.parts.mnt | 0x0010000000000000ULL;
    int32_t expdiff = dx.parts.exp - dy.parts.exp;
    int32_t shift = 0;
    int64_t tmp = 0;
    do {
      sx <<= shift;
      expdiff += ~shift;
      tmp = sx - sy;
      sx = tmp * 2 + sy * (tmp < 0 ? 1 : 0);
      shift = __builtin_clzll(sx) - (64 - 53);
    } while (expdiff >= shift && sx != 0LL);

    if (expdiff < 0) {
      sx += sy * (tmp < 0 ? 1 : 0);
      sx >>= 1;
      expdiff = 0;
    }
    sx <<= expdiff;

    if (0 == sx) {
      dx.parts.mnt = dx.parts.exp = 0;
      result = dx.d;
    } else {
      shift = __builtin_clzll(sx) - (64 - 53);
      sx <<= shift;
      dx.parts.exp = dy.parts.exp - shift;
      sx &= 0x000fffffffffffffULL;
      dx.parts.mnt = sx;
      result = dx.d;
    }
  }
  return result;
}
