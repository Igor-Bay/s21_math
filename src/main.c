#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// #include "./s21_math_functions/s21_math_basic_functions.c"
#include "./s21_math_functions/s21_math_fmod.c"
#include "s21_math.h"

void bin(uint64_t n, uint64_t bytes) {
  uint64_t i = 0LLU;
  for (i = (uint64_t)1 << (bytes - 1); i > 0; i /= 2)
    (n & i) ? printf("1") : printf("0");
  printf("\n");
}

void print_cast(double d) {
  double_cast dc = {.d = d};

  printf("%+.16f\n", dc.d);
  // printf("%03x\t\t %u\t\t\t", dc.parts.exp, dc.parts.exp);
  // bin(dc.parts.exp, 11);
  // printf("\n");
  // printf("%016llx %llu\t", dc.parts.mnt, dc.parts.mnt);
  // bin(dc.parts.mnt, 52);
  // printf("\n");
}

int main(void) {
  srand(time(NULL));

  double d1 = 0.5;
  double d2 = 1.;
  printf("%.6Lf\t%.6f\t%.6Lf\n", s21_fmod(d1, d2), fmod(d1, d2),
         s21_fmod(d1, d2) - fmod(d1, d2));

  // double testcases[] = {1e-10, -1e-10, 0.5, -0.5, 1., -1., 1e-4, 1e4, -1e-4,
  // -1e4, S21_MAX_DOUBLE, -S21_MAX_DOUBLE}; size_t n = sizeof(testcases) /
  // sizeof(testcases[0]);

  // for (size_t i = 0; i < n; ++i)
  //   for (size_t j = 0; j < n; ++j)
  //     printf("%f\t%f\t%.6Lf\n", testcases[i], testcases[j],
  //     s21_fmod(testcases[i],  testcases[j]) - fmod(testcases[i],
  //     testcases[j]));

  // for (int i = 0; i < 100000; ++i) {
  //   // (-10^[1-2])^([0-100]^[-1,1]) * [-1,1]
  //   d1 = pow(pow(-10, (rand() % 2) + 1), rand() % 100 * pow(-1, rand() % 2))
  //   *
  //        pow(-1, rand() % 2);
  //   d2 = pow(pow(-10, (rand() % 2) + 1), rand() % 100 * pow(-1, rand() % 2))
  //   *
  //        pow(-1, rand() % 2);
  //   // printf("%.16f\n", d1);
  //   // printf("%.16f\n", d2);
  //   // printf("%Lf\n%f\n", s21_fmod(d1, d2), fmod(d1, d2));
  //   printf("%e\t%e\t%.6Lf\n", d1, d2, s21_fmod(d1, d2) - fmod(d1, d2));
  // }

  // for (int i = -1000; i < 1000; ++i) {
  //   // (-10^[1-2])^([0-100]^[-1,1]) * [-1,1]
  //   d1 = (double)i;
  //   // printf("%.16f\n", d1);
  //   // printf("%.16f\n", d2);
  //   // printf("%Lf\n%f\n", s21_fmod(d1, d2), fmod(d1, d2));
  //   printf("%.6Lf\n", s21_sin(d1) - sin(d1));
  //   printf("%.6Lf\n", s21_cos(d1) - cos(d1));
  //   printf("%.6Lf\n", s21_tan(d1) - tan(d1));
  // }

  return 0;
}
