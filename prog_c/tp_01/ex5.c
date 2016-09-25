#include <stdlib.h>
#include <stdio.h>

/* On suppose que le tableau valeurs est de taille n et contient les
 * valeurs de la ligne n-1 */
void pascal_ligne(int n, int valeurs[]) {
  int u = valeurs[0];
  int v;

  for (int i = 1 ; i < n-1 ; i++) {
    v = valeurs[i];
    valeurs[i] = u + v;
    u = v;
  }

  valeurs[n-1] = 1;
}


void affiche_ligne(int n, int valeurs[]) {
  for (int i = 0 ; i < n ; i++)
    printf("%d ", valeurs[i]);
  printf("\n");
}


void affiche_pascal(int n) {
  int t[n];
  t[0] = 1;

  for (int i = 1 ; i < n ; i++) {
    affiche_ligne(i, t);
    pascal_ligne(i + 1, t);
  }
}


int main(int argc, char *argv[]) {
  affiche_pascal(10);

  return EXIT_SUCCESS;
}
