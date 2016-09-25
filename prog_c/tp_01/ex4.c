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


int is_sort(int t[], int n) {
  int i = 1;

  while (i < n)
    if (t[i-1] > t[i++])
      return 0;

  return 1;
}


int is_inside(int t[], int n, int x) {
  int i = 1;

  while (i < n)
    if (t[i++] == x)
      return 1;

  return 0;
}


/* On suppose que le tableau t est trie */
int rech_dicho(int t[], int n, int x) {
  int debut = 0;
  int fin = n;
  int milieu;

  while (debut <= fin) {
    milieu = debut + (fin - debut) / 2;

    if (x == t[milieu])
      return 1;
    
    if (x < t[milieu])
      fin = milieu - 1;
    else
      debut = milieu + 1;
  }

  return 0;
}


int rech_dicho_rec_bis(int t[], int n, int x, int debut, int fin) {
  if (debut > fin)
    return 0;

  int milieu = debut + (fin - debut) / 2;
  
  if (x == t[milieu])
    return 1;
  
  if (x < t[milieu])
    return rech_dicho_rec_bis(t, n, x, debut, milieu - 1);
  return rech_dicho_rec_bis(t, n, x, milieu + 1, fin);
}


int rech_dicho_rec(int t[], int n, int x) {
  return rech_dicho_rec_bis(t, n, x, 0, n);
}


int main(int argc, char *argv[]) {
  int n = 5; 

  int t1[5] = { 1, 4, 43, 65, 94 };
  int t2[5] = { 1, 4, 42, 65, 94 };
  int t3[5] = { 1, 4, 43, 94, 65 };

  printf("t1 : ");
  display_array(t1, n);

  printf("t2 : ");
  display_array(t2, n);

  printf("t3 : ");
  display_array(t3, n);

  printf("is_sort(t1, n) : %d\n", is_sort(t1, n));
  printf("is_sort(t2, n) : %d\n", is_sort(t2, n));
  printf("is_sort(t3, n) : %d\n", is_sort(t3, n));

  printf("is_inside(t1, n, 42) : %d\n", is_inside(t1, n, 42));
  printf("is_inside(t2, n, 42) : %d\n", is_inside(t2, n, 42));

  printf("rech_dicho(t1, n, 42) : %d\n", rech_dicho(t1, n, 42));
  printf("rech_dicho(t2, n, 42) : %d\n", rech_dicho(t2, n, 42));

  printf("rech_dicho_rec(t1, n, 42) : %d\n", rech_dicho(t1, n, 42));
  printf("rech_dicho_rec(t2, n, 42) : %d\n", rech_dicho(t2, n, 42));

  return EXIT_SUCCESS;
}
