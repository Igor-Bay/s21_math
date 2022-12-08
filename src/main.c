#include <math.h>
#include <stdio.h>
#include <string.h>

#include "s21_math.h"

void test_s21_log(double x) {
  printf("\t\t%.20f\n", x);
  printf("math:\t\t%.20f\n", log(x));
  printf("s21:\t\t%.20Lf\n\n", s21_log(x));
}

void test_s22_pow(double x, double exp) {
  printf("\t\t%.20f\n", x);
  printf("math:\t\t%.20f\n", pow(x, exp));
  printf("s21:\t\t%.20Lf\n\n", s22_pow(x, exp));
}

void test_s21_sqrt(double x) {
  printf("\t\t%.20f\n", x);
  printf("math:\t\t%.20f\n", sqrt(x));
  printf("s21:\t\t%.20Lf\n\n", s21_sqrt(x));
}

int main(void) {
  // test_s21_sqrt(INFINITY);
  // test_s21_sqrt(-INFINITY);
  // test_s21_sqrt(NAN);
  // test_s21_sqrt(2);
  // test_s21_sqrt(-2);
  // test_s21_sqrt(4.23532523);
  // test_s21_sqrt(0.214);
  // test_s21_sqrt(2.324892737958);
  // test_s21_sqrt(2357983275987238957893279857328976893479867439867.32423894);
  // test_s21_sqrt(235798327598723898976893479867439867.32423894);
  // test_s21_sqrt(23578957893279857328976893479867439867.32423894);
  // test_s21_sqrt(-0.0);

  test_s22_pow(2, 2);
  test_s22_pow(-2, 3);
  test_s22_pow(-2, 3.234);
  test_s22_pow(-2, 0.123);
  test_s22_pow(-2, 1);
  test_s22_pow(-2, 0);
  test_s22_pow(-INFINITY, 0);
  test_s22_pow(INFINITY, 0);
  test_s22_pow(6, 4.23532523);
  test_s22_pow(0.214, 43.214124);
  test_s22_pow(2.324892737958, 43.214124);
  test_s22_pow(2.324892737958, 555);

  // test_s21_log(INFINITY);
  // test_s21_log(-INFINITY);
  // test_s21_log(0.0);
  // test_s21_log(325.234);
  // test_s21_log(8712498782197487129874.732587238);
  // test_s21_log(871249878327598723958782386594837649572197487129874.732587238);
  // test_s21_log(871249878327598723958782386537258732986593265325943694837649572197487129874.732587238);
  // test_s21_log(0.0000623476324);
  // test_s21_log(2);
  // test_s21_log(2.45);
  // test_s21_log(87124994382975897329857892306984509685490769053947893475987348957894375987435874398758437598473895789434758934759873489578934878327598723958782386594837649572197487129874.732587238);
  // test_s21_log(0.732587238);
  // test_s21_log(0.000000000000000000623476324);
  // test_s21_log(2);
  // test_s21_log(2.00000001);
  // test_s21_log(0.5);
  // test_s21_log(0.5 + EPS);
  // test_s21_log(0.5 - EPS);
  // for (double x = -2 * S21_PI; x <= S21_PI * 2; x += S21_PI / 16)
  //   printf("% .15Lf\n", s21_sin(x) - sin(x));

  // for (double x = -15.; x <= 15.; x += 0.5)
  //   printf("% .15Lf\t\t% .15f\n", s21_exp(x), exp(x));

  return 0;
}