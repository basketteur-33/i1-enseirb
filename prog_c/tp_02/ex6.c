#include <stdlib.h>
#include <stdio.h>
#include <string.h>


void usage(char *s) {
  perror(s);
  exit(1);
}

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


/* Echange la position des elements aux indices i et j dans le tableau t */
void echange(int t[], int i, int j) {
  int tmp = t[i];
  t[i] = t[j];
  t[j] = tmp;
}


/* Retourne l'indice de l'element minimum du tableau 
 * On suppose que le tableau est deja trie jusqu'a l'indice inf exclus */
int trouve_indice_minimum(int t[], int n, int inf) {
  int i_min = inf;

  for (int i = inf ; i < n ; ++i) {
    if (t[i] < t[i_min])
      i_min = i;
  }

  return i_min;
}
    

void tri_selection(int t[], int n) {
  for (int i = 0 ; i < n ; ++i) {
    int i_min = trouve_indice_minimum(t, n, i);
    echange(t, i, i_min);
  }
}    
  

int main(int argc, char *argv[]) {
  if (argc != 1)
    usage("usage: ./ex6");

  int t[] = { 539, 5, 15, 42, 74, 1, 174, 3, 9 };
  int n = 9;
  
  printf("t non trié : ");
  display_array(t, n);

  printf("tri_selection(t, n)\n");
  tri_selection(t, n);
  printf("t trié : ");
  display_array(t, n);   
 
  return EXIT_SUCCESS;
}
