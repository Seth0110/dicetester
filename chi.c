#include <math.h>

#include "chi.h"

#ifndef M_E
#define M_E 2.71828
#endif

double
chiSquared(double *observed, double *expected, int k) {
  double sum = 0.0;
  for (int i = 0; i < k; i++)
    sum += pow((observed[i] - expected[i]), 2) / expected[i];
  return sum;
}

double
chiSquaredPDF(double x, double k) {
  return x <= 0 ? 0 :
    (pow(x,(k/2)-1) * pow(M_E,0-(x/2))) /
    (pow(2, (2/k)) * tgamma(k/2));
}

/* Integral from a to b of two-arg function fn given the second argument */
double
appxIntegral(double a, double b, double fn(double, double), double arg2) {
  double sum = 0.0;
  double interval = 0.00001;
  for (double i = a; i < b; i += interval)
    sum += fn(i, arg2) * interval;
  return sum;
}
