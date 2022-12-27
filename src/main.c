#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "./s21_math_functions/s21_math_trigonometric_functions.c"
#include "s21_math.h"

// void bin(uint64_t n, uint64_t bytes) {
//   uint64_t i = 0LLU;
//   for (i = (uint64_t)1 << (bytes - 1); i > 0; i /= 2)
//     (n & i) ? printf("1") : printf("0");
//   printf("\n");
// }

// void print_cast(double d) {
//   double_cast dc = {.d = d};

// printf("%+.16f\n", dc.d);
// printf("%03x\t\t %u\t\t\t", dc.parts.exp, dc.parts.exp);
// bin(dc.parts.exp, 11);
// printf("\n");
// printf("%016llx %llu\t", dc.parts.mnt, dc.parts.mnt);
// bin(dc.parts.mnt, 52);
// printf("\n");
// }

int main(void) {
  double i = 1e-6;
  printf("%.6Lf\t %.6lf\n", s21_round(i), round(i));

  // if (s21_sin(i) - sin(i) > 1e-6 || s21_sin(i) - sin(i) < -1e-6)
  //   printf("%.6Lf\n", s21_sin(i) - sin(i));
  // if (s21_cos(i) - cos(i) > 1e-6 || s21_cos(i) - cos(i) < -1e-6)
  //   printf("%.6Lf\n", s21_cos(i) - cos(i));
  // if (s21_round(i) - round(i) > 1e-6 || s21_round(i) - round(i) < -1e-6)
  //   printf("%.6Lf\n", s21_round(i) - round(i));

  return 0;
}
