#include <stdlib.h>
#include <stdio.h>

void usage(char *s) {
  perror(s);
  exit(1);
}


void swap(int *x, int *y) {
  int tmp = *x;
  *x = *y;
  *y = tmp;
}


/* Sorte de "tri a bulle" */
void order(int *x, int *y, int *z) {
  if (*x > *y) {
    swap(x, y);
  } 

  if (*y > *z) {
    swap(y, z);

    if (*x > *y) {
      swap(x, y);
    }
  }
}


int main(int argc, char *argv[]) {
  if (argc != 1)
    usage("usage: ./ex1");

  int x = 42;
  int y = 69;
  int z = 12;

  printf("x = %d, y = %d et z = %d\n", x, y, z);
  printf("On appelle la fonction swap(&x, &y)\n");

  swap(&x, &y);
  printf("x = %d et y = %d\n\n", x, y);

  printf("order(&x, &y, &z)\n");
  order(&x, &y, &z);
  printf("x = %d, y = %d et z = %d\n", x, y, z);

  return EXIT_SUCCESS;
}
