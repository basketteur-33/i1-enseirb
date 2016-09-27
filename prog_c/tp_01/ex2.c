#include <stdlib.h>
#include <stdio.h>

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
  int size = 10;

  int t[size];
  fill_array_even(t, size);
  display_array(t, size);

  return EXIT_SUCCESS;
}
