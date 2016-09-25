#include <stdlib.h>
#include <stdio.h>

#define ARRAY_SIZE 10

void display_array(int t[], int n) {
  int i = 0;

  printf("[");

  while (i < n-1) {
    printf("%d, ", t[i]);
    i++;
  }

  /* Ne pas avoir de virgule a la fin */
  printf("%d]\n", t[i]);
}


void fill_array_even(int t[], int n) {
  int i = 0;

  while (i < n) {
    t[i] = 2*i;
    i++;
  }
}
 

int main(int argc, char *argv[]) {
  int t[ARRAY_SIZE];
  fill_array_even(t, ARRAY_SIZE);
  display_array(t, ARRAY_SIZE);

  return EXIT_SUCCESS;
}
