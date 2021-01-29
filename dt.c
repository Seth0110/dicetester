/*
 * Dice Tester - Counter tool to display statistics about the randomness of dice 
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <gsl/gsl_cdf.h>

#define SIDES 6

double
chiSquared(double *observed, double *expected, int sides) {
  double sum = 0.0;
  for (int i = 0; i < sides; i++)
    sum += pow((observed[i] - expected[i]), 2) / expected[i];
  return sum;
}

int
main(int argc, char **argv)
{
  char input[8];
  int num, total;
  double observed[SIDES], expected[SIDES];

  total = 0;
  memset(observed, 0, sizeof observed);
  memset(input, 0, sizeof input);

  /* Load observed data */
  while (scanf("%s", input) != EOF) {
    num = atoi(input);
    if (num >= 1 && num <= SIDES) {
      printf("%d\n", num);
      observed[num-1] += 1;
      total += 1;
    }
    getchar();
  }

  /* Random = flat distribution */
  for (int i = 0; i < SIDES; i++)
    expected[i] = (double) total / SIDES;

  double chi2 = chiSquared(observed, expected, SIDES);
  double pval = 1-gsl_cdf_chisq_P(chi2, SIDES-1);

  fputs("\n########## RESULTS ##########\n", stderr);
  fputs("Num:\tExp:\tObs:\tPer:\t\n", stderr);
  for (int i = 0; i < SIDES; i++)
    fprintf(stderr, "%d:\t %2.0f\t %2.0f\t %3.0f%%\n", i+1, expected[i], observed[i], (observed[i] / total)*100);
  if (pval >= 0.1)
    fputs("\nDie is fair :)\n", stderr);
  else if (pval > 0.05)
    fputs("\nDie is probably fair\n", stderr);
  else
    fputs("\nDie not fair :(\n", stderr);
  
  return 0;
}
