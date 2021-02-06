/*
 * Dice Tester - Counter tool to display statistics about the randomness of dice 
 */

#include <gsl/gsl_cdf.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int
getSides(int argc, char **argv) {
  int sides = 6;
  if (argc >= 2 && atoi(argv[1]) > 0)
    sides = atoi(argv[1]);
  return sides;
}

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
  int num, total, sides, memSize;
  double *observed, *expected;
  
  total = 0;

  sides = getSides(argc, argv);
  memSize = sizeof(double) * sides;
  observed = malloc(memSize);
  expected = malloc(memSize);
  printf("HERE %d\n", sides);
  for (int i = 0; i < sides; i++)
    observed[i] = 0.0;
  
  printf("HERE %d\n", sides);
  printf("Obs: %f\n", observed[0]);
  /* Load observed data */
  while (scanf("%s", input) != EOF) {
    num = atoi(input);

    if (num >= 1 && num <= sides) {
      printf("%d\n", num);
      observed[num-1] += 1;
      total += 1;
    }
    getchar();
  }

  /* Random = flat distribution */
  for (int i = 0; i < sides; i++)
    expected[i] = (double) total / sides;

  double chi2 = chiSquared(observed, expected, sides);
  double pval = 1-gsl_cdf_chisq_P(chi2, sides-1);

  fputs("\n########## RESULTS ##########\n", stderr);
  fputs("Num:\tExp:\tObs:\tPer:\t\n", stderr);
  for (int i = 0; i < sides; i++)
    fprintf(stderr, "%d:\t %2.0f\t %2.0f\t %3.0f%%\n", i+1, expected[i], observed[i], (observed[i] / total)*100);
  if (pval >= 0.1)
    fputs("\nDie is fair :)\n", stderr);
  else if (pval > 0.05)
    fputs("\nDie is probably fair\n", stderr);
  else
    fputs("\nDie not fair :(\n", stderr);

  free(observed);
  free(expected);
  
  return 0;
}
