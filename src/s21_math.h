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

/*  Even though these might be more useful as long doubles, POSIX requires
  that they be double-precision literals.                                   */
#define S21_E 2.71828182845904523536028747135266250        /* e              */
#define S21_LOG2E 1.44269504088896340735992468100189214    /* log2(e)        */
#define S21_LOG10E 0.434294481903251827651128918916605082  /* log10(e)       */
#define S21_LN2 0.693147180559945309417232121458176568     /* loge(2)        */
#define S21_LN10 2.30258509299404568401799145468436421     /* loge(10)       */
#define S21_PI 3.14159265358979323846264338327950288       /* pi             */
#define S21_PI_2 1.57079632679489661923132169163975144     /* pi/2           */
#define S21_PI_4 0.785398163397448309615660845819875721    /* pi/4           */
#define S21_1_PI 0.318309886183790671537767526745028724    /* 1/pi           */
#define S21_2_PI 0.636619772367581343075535053490057448    /* 2/pi           */
#define S21_2_SQRTPI 1.12837916709551257389615890312154517 /* 2/sqrt(pi) */
#define S21_SQRT2 1.41421356237309504880168872420969808    /* sqrt(2)        */
#define S21_SQRT1_2 0.707106781186547524400844362104849039 /* 1/sqrt(2) */

// #define S21_MAXFLOAT 0x1.fffffep+127f
#define EPS 10e-16

typedef union {
  double d;
  struct {
    uint64_t mnt : 52;
    uint64_t exp : 11;
    uint64_t sgn : 1;
  } parts;
} double_cast;

// basic functions
long double s21_fabs(double x);
long double s21_pow(double base, int exp);
long double s21_fact(int n);
long double s21_trunc(double x);
long double s21_floor(double x);
long double s21_ceil(double x);
long double s21_round(double x);
long double s21_fmod(double x, double y);

// power functions
long double s21_exp(double x);

// trigonometric functions
long double s21_sin(double x);
long double s21_cos(double x);
long double s21_tan(double x);

// inverse trigonometric functions
// long double s21_atan(double x);

// tail call functions
long double s21_pow_rec(double base, int exp, long double acc);
long double s21_fact_rec(int n, long double acc);

#endif  // SRC_S21_STRING_H_