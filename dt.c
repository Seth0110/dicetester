/*
 * Dice Tester - Counter tool to display statistics about the randomness of dice 
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "chi.h"

#define SIDES 20

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

  /* Print basic statistical data */
  fputs("##### RESULTS #####\n", stderr);
  fputs("Num:\tExp:\tObs:\tPer:\t\n", stderr);
  for (int i = 0; i < SIDES; i++)
    fprintf(stderr, "%d:\t %2.0f\t %2.0f\t %3.0f%%\n", i+1, expected[i], observed[i], (observed[i] / total)*100);

  /* Calculate and print Chi Squared test data*/
  double chi2 = chiSquared(observed, expected, SIDES);
  fprintf(stderr, "Chi Squared: %2.2f\n", chi2-1);
  
  return 0;
}
