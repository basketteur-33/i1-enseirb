#include <stdlib.h>
#include <stdio.h>
#include <string.h>


void usage(char *s) {
  perror(s);
  exit(1);
}


/* Cette fonction sert a echanger la position des elements aux indices
 * i et j dans la chaine de caractere str */
void echange(char *str, int i, int j) {
  char tmp;

  tmp = str[i];
  str[i] = str[j];
  str[j] = tmp;
}
  


void chaine_miroir(char *str) {
  int i = 0;
  int j = strlen(str) - 1;

  while (i < j) {
    echange(str, i, j);
    i++;
    j--;
  }
}    


/* On suppose que dest est assez grand pour recevoir src */
void chaine_miroir_bis(char *dest, char *src) {
  dest = strcpy(dest, src);
  chaine_miroir(dest);
}
  

int main(int argc, char *argv[]) {
  if (argc != 2)
    usage("usage: ./ex3 chaine");

  /* Sale car on ecrase directement sur la pile... 
  printf("chaine_miroir(%s)\n", argv[1]);
  chaine_miroir(argv[1]);
  printf("argv[1] : %s \n", argv[1]);*/

  size_t n = strlen(argv[1]);
  char dest[n];

  printf("chaine_miroir_bis(dest, %s)\n", argv[1]);
  chaine_miroir_bis(dest, argv[1]);  
  printf("argv[1] : %s\n", argv[1]);
  printf("dest : %s\n", dest);

  return EXIT_SUCCESS;
}
