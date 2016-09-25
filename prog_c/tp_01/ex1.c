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
  /* Usage */
  if (argc != 3) {
    printf("Usage : ./ex1 a b");
    exit(1);
  }

  /* Tests */
  int a = atoi(argv[1]);
  int b = atoi(argv[2]);
  
  affiche_pgcd(a,b);

  return EXIT_SUCCESS;
}
