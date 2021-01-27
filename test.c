#include <stdio.h>
#include <math.h>

#include "chi.h"

#define k 5

int
main(void)
{
  /* Test data sourced from https://youtu.be/2QeDRsxSF9M */
  double observed[] = { 30, 14, 34, 45, 57, 20 };
  double expected[] = { 20, 20, 30, 40, 60, 30 };

  double chi = chiSquared(observed, expected, k+1);
  printf("chiSquared: %s\n", chi == 11.44 ? "Fail" : "Pass");

  return 0;
}
