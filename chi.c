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

/* double */
/* chiSquaredPDF(int x, int k, int n) { */
/*   return (pow(2, ((1-n)/2)) * */
/* 	  pow(x, (n-1)) * */
/* 	  pow(M_E, (0-(pow(x,2)/2)))) / */
/*     lgamma(n/2); */
/* } */
