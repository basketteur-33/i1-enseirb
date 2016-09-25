#include <stdlib.h>
#include <stdio.h>


int pgcd_rec(int a, int b) {
  if (b == 0)
    return a;
  return pgcd_rec(b, a % b);
}


int pgcd_iter(int a, int b) {
  int c;

  while (b > 0) {
    c = a % b;
    a = b;
    b = c;
  }

  return a;
}


void affiche_pgcd(int a, int b) {
  int res_rec = pgcd_rec(a,b);
  int res_iter = pgcd_iter(a,b);

  if (res_rec != res_iter) {
    perror("Les deux methodes retournent un resultat different.\n");
    exit(1);
  }

  printf("pgcd(%d, %d) = %d\n", a, b, res_rec);
}
  
 
int main(int argc, char *argv[]) { 
  affiche_pgcd(10, 5);
  affiche_pgcd(24, 36);
  affiche_pgcd(95, 57);

  return EXIT_SUCCESS;
}
