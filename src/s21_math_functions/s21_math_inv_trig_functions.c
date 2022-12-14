#include "../s21_math.h"

// long double s21_atan(double x) {
//   x = fmodl(x, S21_PI_4);
//   long double result = 0;
//   for (int i = 37; i >= 1; i -= 2) {
//     result += (((i - 1) % 4 == 0) ? 1 : -1) * s21_pow_int(x, i) / i;
//   }
//   return result;
// }