#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#include "./s21_math_functions/s21_math_trigonometric_functions.c"
// #include "./s21_math_functions/s21_math_fmod.c"
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
  // printf("%.16Lf\t%.16lf\n", s21_sin(S21_PI / 2), sin(S21_PI / 2));
  // printf("%.16Lf\t%.16lf\n", s21_cos(S21_PI / 2), cos(S21_PI / 2));
  // printf("%.6Lf\t%.6lf\n", s21_tan(S21_PI / 2), tan(S21_PI / 2));

  for(long double j = -2.; j <= 2.; j += 0.01) {
    long double i = S21_PI * j;
    printf("\n%Lf\n", i);
    if (s21_sin(i) - sin(i) > 1e-6) printf("%.6Lf\n", s21_sin(i) - sin(i));
    if (s21_cos(i) - cos(i) > 1e-6) printf("%.6Lf\n", s21_cos(i) - cos(i));
    if (s21_tan(i) - tan(i) > 1e-6) printf("%.6Lf\n", s21_tan(i) - tan(i));
  }

  return 0;
}
