#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "s21_math.h"

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
  srand(time(NULL));

  for (int i = 0; i < 100; ++i) {
    double_cast d1 = {.d = 1e-20 * rand() * s21_pow(rand(), 2) * i};
    // double_cast d2 = {.d = 1e10 * (double)rand()};
    // print_cast(&d1);
    printf("%.16f\n", d1.d);
    double_cast d3 = {.d = round(d1.d)};
    double_cast d4 = {.d = s21_round(d1.d)};
    // print_cast(&d2);
    // print_cast(&d3);
    // printf("%.6f\n", d3.d);
    // printf("%.6f\n", d4.d);
    // printf("%f\n", round(d3.d * 10e6) / 10e6 - round(d4.d * 10e6) / 10e6);
    printf("%f\n", d3.d - d4.d);
    printf("\n");
  }
  return 0;
}