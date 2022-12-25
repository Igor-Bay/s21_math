/* ==========================================================================*/
/* Copyright 2022 © Moscow, Russian Federaion
 *
 * This file contains Original Code created by
 * Mikhail aka sarellad,
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

#include <math.h>
#include <stdint.h>
#include <stdio.h>

/*  Even though these might be more useful as long doubles, POSIX requires
  that they be double-precision literals. */
#define S21_E 2.718281828459045235360287471352662500L      /* e              */
#define S21_LOG2E 1.442695040888963407359924681001892140L  /* log2(e)        */
#define S21_LOG10E 0.434294481903251827651128918916605082L /* log10(e) */
#define S21_LN2 0.693147180559945309417232121458176568L    /* loge(2)        */
#define S21_LN10 2.302585092994045684017991454684364210L   /* loge(10)       */
#define S21_PI 3.141592653589793238462643383279502880L     /* pi             */
#define S21_PI_2 1.570796326794896619231321691639751440L   /* pi/2           */
#define S21_PI_4 0.785398163397448309615660845819875721L   /* pi/4           */
#define S21_1_PI 0.318309886183790671537767526745028724L   /* 1/pi           */
#define S21_2_PI 0.636619772367581343075535053490057448L   /* 2/pi           */
#define S21_2_SQRTPI 1.128379167095512573896158903121545170L /* 2/sqrt(pi) */
#define S21_SQRT2 1.414213562373095048801688724209698080L    /* sqrt(2)       */
#define S21_SQRT1_2 0.707106781186547524400844362104849039L  /* 1/sqrt(2)  */
#define S21_SQRTE 1.648721270700128102982932876141575206L    /* sqrt(e)       */

#define EPS 1e-32
#define S21_NAN (0.f / 0.f)
#define S21_INF (1.f / 0.f)
#define S21_IS_NAN(X) ((X) != (X))
#define S21_IS_INF(X) ((X) == S21_INF || (X) == -S21_INF)
#define S21_IS_NULL(X) ((X) < EPS && (X) > -EPS)
#define S21_IS_NEG(X) (*(long*)&(X) & 0x8000000000000000)
#define S21_MAX_DOUBLE 1.7976931348623157E+308

typedef union {
  double d;
  // uint64_t u;
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

// power functions
long double s21_exp(double x);
long double s21_log(double x);
long double s21_pow(double base, double exp);
long double s21_sqrt(double x);

// trigonometric functions
long double s21_sin(double x);
long double s21_cos(double x);
long double s21_tan(double x);

// inverse trigonometric functions
// long double s21_atan(double x);

// round functions
long double s21_trunc(double x);
long double s21_floor(double x);
long double s21_ceil(double x);
long double s21_round(double x);

// fmod
long double s21_fmod(double x, double y);
double s21_fmod_apple(double x, double y);

// tail call functions
long double s21_pow_rec(long double base, int exp, long double acc);
long double s21_fact_rec(int n, long double acc);

#endif  // SRC_S21_STRING_H_