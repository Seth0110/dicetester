/*
 * Dice Tester - Counter tool to display statistics about the randomness of dice 
 */

#include <stdio.h>
#include <string.h>

#define SIDES 4
#define EXPECTED 5 // This is set per the Chi Squared test

int
main(int argc, char **argv)
{
  int counter[SIDES];
  int n;

  int total = SIDES * EXPECTED;

  memset(counter, 0, sizeof counter);

  for (int i = 0; i < total; i++) {
    scanf("%d", &n);
    printf("%d\n", n);
    if (n >= 1 && n <= SIDES)
      counter[n-1] += 1;
    else {
      printf("Invalid number, use 1 through %d.\n", SIDES);
      i--;
    }
    getchar();
  }

  fputs("##### RESULTS #####\n", stderr);
  fprintf(stderr, "TOTAL: %d\n", total);
  for (int i = 0; i < SIDES; i++)
    fprintf(stderr, "%d: %d %3.0f%%\n", i+1, counter[i], (counter[i] / (float) total)*100);
  
  return 0;
}
