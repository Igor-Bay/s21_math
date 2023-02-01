/* ==========================================================================*/
/* Copyright 2022 © Moscow, Russian Federaion
 *
 * This file contains Original Code created by
 * Igor Baidikov aka lorenttr.
 *
 * The Original Code and all software developed in the process of
 * participation on learning by experimental programming educational method.
 * The whole methodology was developed and distributed by
 * Autonomous non-profit organization «School 21» (ANO «School 21»).
 *
 * Redistribution and use of this file, its parts, or entire project
 * are permitted by confirmation of its original creators.
 */
/* ==========================================================================*/

#ifndef SRC_S21_MATH_H_
#define SRC_S21_MATH_H_

#include <stdint.h>
#include <stdio.h>

/*  Even though these might be more useful as long doubles, POSIX requires
  that they be double-precision literals. */
#define S21_PI 3.141592653589793238462643383279502880L     /* pi             */
#define S21_PI_2 1.570796326794896619231321691639751440L   /* pi/2           */

#define EPS 1e-32
#define S21_NAN (0.L / 0.L)
#define S21_INF (1.L / 0.L)
#define S21_IS_NAN(X) ((X) != (X))
#define S21_IS_INF(X) ((X) == S21_INF || (X) == -S21_INF)
#define S21_IS_NULL(X) ((X) < EPS && (X) > -EPS)
#define S21_IS_NEG(X) (*(long*)&(X)&0x8000000000000000)
#define S21_MAX_DOUBLE 1.7976931348623157E+308

typedef union {
  double d;
  struct {
    uint64_t mnt : 52;
    uint64_t exp : 11;
    uint64_t sgn : 1;
  } parts;
} double_cast;

// basic functions
int s21_abs(int x);
long double s21_fabs(double x);
long double s21_pow_int(double base, int exp);
long double s21_fact(int n);

// round functions
long double s21_trunc(double x);
long double s21_floor(double x);
long double s21_ceil(double x);
long double s21_round(double x);

// fmod
long double s21_fmod(double x, double y);

#endif  // SRC_S21_STRING_H_