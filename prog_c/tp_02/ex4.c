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


void my_itoa(char *str, int n) {
  int i = 0;
  int sign = n;

  /* Si le nombre est negatif, on se souvient du signe et on travaille sur
   * un nombre positif (reste > 0 pour modulo) */
  if (sign < 0)
    n = -n;

  /* On ecrit le nombre a l'envers
   * Le do ... while sert a rentrer une fois dans la boucle
   * dans le cas ou n vaut 0 */
  do {
    str[i++] = n % 10 + '0';
    n = n / 10;
  } while (n > 0);
  
  if (sign < 0)
    str[i++] = '-';

  /* On rajoute le caractere de fin de chaine et 
   * on inverse la chaine (car on a ecrit le nombre a l'envers) */
  str[i] = '\0';
  chaine_miroir(str);
}


int main(int argc, char *argv[]) {
  if (argc != 1)
    usage("usage: ./ex4");

  int a = 169;
  int b = -42;
  int c = 0;

  char stra[10];
  char strb[10];
  char strc[10];

  printf("a : %d\n", a);
  printf("my_itoa(stra, %d) (effet de bord)\n", a);
  my_itoa(stra, a);
  printf("stra : %s\n", stra);
  printf("strlen(%s) : %zu\n\n", stra, strlen(stra));

  printf("b : %d\n", b);
  printf("my_itoa(strb, %d) (effet de bord)\n", b);
  my_itoa(strb, b);
  printf("strb : %s\n", strb);
  printf("strlen(%s) : %zu\n\n", strb, strlen(strb));

  printf("c : %d\n", c);
  printf("my_itoa(strc, %d) (effet de bord)\n", c);
  my_itoa(strc, c);
  printf("strc : %s\n", strc);
  printf("strlen(%s) : %zu\n", strc, strlen(strc));

  return EXIT_SUCCESS;
}
