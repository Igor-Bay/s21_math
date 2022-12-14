#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "s21_math.h"
// #include "./s21_math_functions/s21_math_basic_functions.c"

void bin(uint64_t n, uint64_t bytes) {
  uint64_t i = 0LLU;
  for (i = (uint64_t)1 << (bytes - 1); i > 0; i /= 2)
    (n & i) ? printf("1") : printf("0");
  printf("\n");
}

void print_cast(double_cast *dc) {
  printf("%+.16f\n", dc->d);
  // printf("%x\t%u\t", dc->parts.exp, dc->parts.exp);
  bin(dc->parts.exp, 11);
  // printf("%lx\t%lu\t", dc->parts.mnt, dc->parts.mnt);
  bin(dc->parts.mnt, 52);
  printf("\n");
}

int main(void) {
  for (double x = -30; x < 100; x += 1) {
    printf("%Lf\t%.7Lf\n", s21_exp(x), s21_exp(x) - (long double)exp(x));
    // printf("%lf\n%lf\n", round(s21_exp(x) * 1e16) / 1e16, exp(x));
    // printf("\n");
  }

  return 0;
}

/*
  srand(time(NULL));

  for (int i = 0; i < 300; ++i) {
    double d1 = 1e5 * rand() * i;
    double d2 = 1e1 * rand() * i;

    // printf("%.16f\n", d1);
    // printf("%.16f\n", d2);

    // printf("%Lf\n%Lf\n", s21_fmod(d1, d2), fmodl(d1, d2));
    printf("%.6Lf\n", s21_fmod(d1, d2) - (long double)fmod(d1, d2));
    printf("\n");
  }
*/