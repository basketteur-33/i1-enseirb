#include <stdlib.h>
#include <stdio.h>

void usage(char *s) {
  perror(s);
  exit(EXIT_FAILURE);
}


void display_array(int t[], int n) {
  printf("[");

  for (int i = 0 ; i < n-1 ; ++i)
    printf("%d, ", t[i]);

  /* Ne pas avoir de virgule a la fin */
  printf("%d]\n", t[n-1]);
}


void min_max(int l, int t[], int *min, int *max) {
  int m = t[0];
  int M = t[0];

  for (int i = 0 ; i < l ; ++i) {
    if (t[i] < m)
      m = t[i];

    if (t[i] > M)
      M = t[i];
  }

  /* On s'assure qu'on ne pointe pas sur NULL */
  if (min != NULL)
    *min = m;

  if (max != NULL)
    *max = M;  
}


int main(int argc, char *argv[]) {
  if (argc != 1)
    usage("usage: ./ex2");

  int t[] = { 42, 55, 3, 6, 2, 9, 69, 14, 13 };
  int l = 9;
  int min;
  int max;

  display_array(t, l);
  printf("min_max(l, t, &min, &max)\n");
  min_max(l, t, &min, &max);

  printf("min : %d et max : %d\n", min, max);  

  return EXIT_SUCCESS;
}
