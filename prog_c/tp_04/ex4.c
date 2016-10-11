#include <stdlib.h>
#include <stdio.h>

void usage(char *s) {
  perror(s);
  exit(EXIT_FAILURE);
}


void display_array(char t[], int n) {
  printf("[");

  for (int i = 0 ; i < n-1 ; ++i)
    printf("%d, ", t[i]);

  /* Ne pas avoir de virgule a la fin */
  printf("%d]\n", t[n-1]);
}


void array_zero(char *t, int n) {
  for (int i = 0 ; i < n ; i++)
    t[i] = 0;
}


int main(int argc, char *argv[]) {
  if (argc != 1)
    usage("usage: ./ex4");

  char t[] = { 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h' };
  int n = 8;

  printf("Manipulation de tableaux de car (affichage sous forme d'entiers)\n");
  display_array(t, n);
  printf("On appelle array_zero(t, n)\n");
  array_zero(t, n);
  display_array(t, n);

  return EXIT_SUCCESS;
}
