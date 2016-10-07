#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void usage(char *s) {
  perror(s);
  exit(1);
}


/* n correspond au nombre de caracteres par ligne */
void affiche_table_caracteres(int n, int min, int max) { 
  int j = 1;

  for (int i = min ; i < max ; ++i) {
    if (i < 32 || i > 126)
      printf("NA\t%d\t0x%x\t0%o\t", i, i, i);
    else
      printf("%c\t%d\t0x%x\t0%o\t", i, i, i, i);

    if (j % n == 0)
      printf("\n");
    else
      printf("  |  ");
    ++j;
  }
  printf("\n");
}
    


int main(int argc, char *argv[]) {
  if (argc == 1 || argc > 6)
    usage("usage: ./ex2 nombre_lignes --min nombre --max nombre");

  int n = atoi(argv[1]);
  int min = 0;
  int max = 255;

  /* Cas ou seule la borne min ou bien les deux options sont passees par l'utilisateur */
  if (argc > 2 && !strcmp(argv[2], "--min")) {
    min = atoi(argv[3]);
    if (argc > 4 && !strcmp(argv[4], "--max"))
      max = atoi(argv[5]);
  }

  /* Cas ou seulement la borne max est passe par l'utilisateur */
  if (argc > 2 && !strcmp(argv[2], "--max")) {
    max = atoi(argv[3]);  
  }
 
  affiche_table_caracteres(n, min, max);

  return EXIT_SUCCESS;
}
