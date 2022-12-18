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

double s21_fmod_apple(double x, double y) {
  union {
    double d;
    uint64_t u;
  } ux = {x};
  union {
    double d;
    uint64_t u;
  } uy = {y};

  // взятие модуля чисел
  uint64_t absx = ux.u & ~0x8000000000000000ULL;
  uint64_t absy = uy.u & ~0x8000000000000000ULL;

  // число больше максимального aka Inf или NaN
  if (absx - 1ULL >= 0x7fefffffffffffffULL ||
      absy - 1ULL >= 0x7fefffffffffffffULL) {
    double fabsx = __builtin_fabs(x);
    double fabsy = __builtin_fabs(y);

    // deal with NaN
    if (x != x || y != y) return x + y;

    // x = Inf or y = 0, return Invalid per IEEE-754
    if (fabsx == __builtin_inf() || 0.0 == y) {
      return __builtin_nan("");
    }

    // handle trivial case
    if (fabsy == __builtin_inf() || 0.0 == x) {
      return x;
    }
  }

  if (absy >= absx) {
    if (absy == absx) {
      ux.u ^= absx;
      return ux.d;
    }
    return x;
  }

  int32_t expx = absx >> 52;
  int32_t expy = absy >> 52;
  int64_t sx = absx & 0x000fffffffffffff;
  int64_t sy = absy & 0x000fffffffffffff;

  // нормирование мантиссы
  if (0 == expx) {  // если экспонента == 0
    uint32_t shift = __builtin_clzll(absx) - (64 - 53);
    sx <<= shift;  // то сдвигаем мантиссу на все незначащие нули влево
    expx = 1 - shift;  // экспонента равна -сдвигу (aka научная нотация)
  }

  // нормирование мантиссы
  if (0 == expy) {
    uint32_t shift = __builtin_clzll(absy) - (64 - 53);
    sy <<= shift;
    expy = 1 - shift;
  }
  sx |= 0x0010000000000000ULL;  // приводим мантиссу к виду 1.***
  sy |= 0x0010000000000000ULL;

  int32_t idiff = expx - expy;  // разница экспонент
  int32_t shift = 0;
  int64_t mask;

  do {
    sx <<= shift;  //  сдвигаем мантиссу x на кол-во незначащих нулей
    idiff += ~shift;  //  разница экспонент + shift-1
    sx -= sy;  // вычитаем из мантиссы x мантиссу y
    mask = sx >> 63;  //  маска равна 1***1, если sx < 0, 0***0 если >= 0
    sx += sx;  //
    sx += sy & mask;  //  если sx был меньше нуля, прибавляем y
    shift = __builtin_clzll(sx) - (64 - 53);  // вычисляем кол-во незнач нулей
  } while (idiff >= shift && sx != 0LL);

  if (idiff < 0) {
    sx += sy & mask;
    sx >>= 1;
    idiff = 0;
  }

  sx <<= idiff;

  if (0 == sx) {
    ux.u &= 0x8000000000000000;
    return ux.d;
  }

  shift = __builtin_clzll(sx) - (64 - 53);
  sx <<= shift;
  expy -= shift;
  sx &= 0x000fffffffffffffULL;
  sx |= ux.u & 0x8000000000000000ULL;
  if (expy > 0) {
    ux.u = sx | ((int64_t)expy << 52);
    return ux.d;
  }

  expy += 1022;
  ux.u = sx | ((int64_t)expy << 52);
  return ux.d * 0x1.0p-1022;
}
