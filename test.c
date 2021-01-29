#include <stdio.h>
#include <math.h>

#include "chi.h"

#define k 5

double
testfunc(double x, double y) {
  return 2*x + y;
}

int
main(void)
{
  /* Test data sourced from https://youtu.be/2QeDRsxSF9M */
  double observed[] = { 30, 14, 34, 45, 57, 20 };
  double expected[] = { 20, 20, 30, 40, 60, 30 };

  double chi = chiSquared(observed, expected, k+1);
  printf("chiSquared: %2.2f == 11.44\n", chi);

  /* Test integral of 0 to 3 of f(x,1)=2x+1 */
  double area = appxIntegral(0.0,3.0,testfunc,1.0);
  printf("Integral: %s\n", area-12 > 0.01 || area-12 < -0.01 ? "Fail" : "Pass");

  /* Test chisquaredpdf with https://www.mathsisfun.com/data/chi-square-table.html */
  double result = appxIntegral(0.0,23.685,chiSquaredPDF,14);
  printf("Chisquaredpdf: %2.2f ~= 0.50\n", result);

  return 0;
}
