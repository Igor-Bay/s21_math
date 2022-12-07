#include <math.h>
#include <stdio.h>

#include "s21_math.h"

void test_s21_log(double x) {
  printf("\t\t%f\n", x);
  printf("math:\t\t%f\n", log(x));
  printf("s21:\t\t%Lf\n\n", s21_log(x));
}

int main(void) {
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

  // for (double x = -2 * S21_PI; x <= S21_PI * 2; x += S21_PI / 16)
  //   printf("% .15Lf\n", s21_sin(x) - sin(x));

  // for (double x = -15.; x <= 15.; x += 0.5)
  //   printf("% .15Lf\t\t% .15f\n", s21_exp(x), exp(x));

  return 0;
}