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


int compte_occurences(char *str, char c) {
  int res = 0;
 
  for (int i = 0 ; str[i] != '\0' ; ++i) {
    if (str[i] == c)
      res++;
  }

  return res;
}


/* On suppose que le tableau t est assez grand pour contenir tous les nombres 
 * i represente l'avancement dans le tableau
 * j represente l'avancement dans la chaine de caracteres */
void my_atoi_tab(char *str, char d, int t[]) {
  for (int i = 0, j = 0 ; str[j] != '\0' ; i++) {
    /* my_atoi : on lit le nombre */
    int res = 0;

    while (str[j] != '\0' && str[j] != d) {
      res = res * 10 + str[j] - '0';
      j++;
    }
    
    j++;    
    t[i] = res;
  }
}


int main(int argc, char *argv[]) {
  if (argc != 3)
    usage("usage: ./ex5 chaine_entiers delimiter");

  char delimiter = argv[2][0];
  int size = compte_occurences(argv[1], delimiter) + 1;
  int t[size];

  my_atoi_tab(argv[1], delimiter, t);
  printf("my_atoi_tab(\"%s\", \"%c\", t) (effet de bord)\n", argv[1], delimiter);
  printf("t : ");
  display_array(t, size);

  return EXIT_SUCCESS;
}

    
    
 
