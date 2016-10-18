#include <stdlib.h>
#include <stdio.h>
#include <limits.h>

#define UNUSED LONG_MIN
#define POOL_SIZE 4096


/* Variable globale (portee du fichier) */
long pool[POOL_SIZE];


void usage(char *s) {
  perror(s);
  exit(EXIT_FAILURE);
}


void release(long *ptr, size_t length, long motif) {
  while (length--)
    *ptr++ = motif;
}


void initialize_pool() {
  release(pool, POOL_SIZE, UNUSED);
}


long *allocate(size_t length) {
  int s = 0;
  int i;

  for (i = 0 ; i < POOL_SIZE && s < length ; i++) {
    if (pool[i] == UNUSED)
      s++;
    else
      s = 0;
  }
  
  if (s == length) {
    release(pool + i - length, length, 0);
    return pool + i - length;
  }

  return NULL;
}


/* On suppose que matrix est deja alloue de taille n */
int lower_triangular_matrix(int n, int m, long *matrix[]) {
  for (int i = 0 ; i < n ; i++ ) {
    int size = i + 1;
    long *line;

    if (size < m)
      line = allocate(size);
    else
      line = allocate(m);    

    if (line == NULL) {
      perror("Allocation non reussie");
      exit(EXIT_FAILURE);
    }

    matrix[i] = line;
  }

  return EXIT_SUCCESS;
}


void print_line(int size, long *tab) {
  for (int j = 0 ; j < size ; j++)
    printf("%ld ", tab[j]);
  printf("\n");
}
  

void print_lower_triangular_matrix(int n, int m, long *matrix[]) {
  for (int i = 0 ; i < n ; i++) {
    int size = i + 1;
    if (size < m)
      print_line(size, matrix[i]);
    else
      print_line(m, matrix[i]);
  }
}  

    
int main(int argc, char *argv[]) {
  if (argc != 1)
    usage("usage: /ex6");
 
  /* On initialise notre espace memoire global */
  initialize_pool();

  long *matrix[30];
  lower_triangular_matrix(30, 35, matrix);
  print_lower_triangular_matrix(30, 35, matrix);
   
  return EXIT_SUCCESS;
}

