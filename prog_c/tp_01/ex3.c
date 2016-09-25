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


int sum_array(int t[], int n) {
  int s = 0;
  int i = 0;

  while (i < n) {
    s += t[i++];
  }

  return s;
}


/* Note
 * i++ revient a faire i = i + 1 apres l'execution de la ligne
 * ++i revient a faire i = i + 1 avant l'execution de la ligne
 */


/* On suppose que t1 et t2 sont de même longueur n */
int scalar_produt_array(int t1[], int t2[], int n) {
  int s = 0;
  int i = 0;

  while (i < n) {
    s = s + (t1[i] * t2[i]);
    i++;
  }

  return s;
}


/* On passe en parametre le tableau vide res qui servira a stocker le resultat */
/* On suppose que res, t1 et t2 sont de même longueur n */
void sum_tabs(int res[], int t1[], int t2[], int n) {
  int i = 0;
  
  while (i < n) {
    res[i] = t1[i] + t2[i];
    i++;
  }
}   


int main(int argc, char *argv[]) {
  int n = 2;
  int t1[2] = { 3, 2 };
  int t2[2] = { 4, 2 };
  int res[2];

  printf("t1 : ");
  display_array(t1, n);

  printf("t2 : ");
  display_array(t2, n);

  printf("sum_array(t1, n) : %d\n", sum_array(t1, n));
  printf("scalar_produt_array(t1, t2, n) : %d\n", scalar_produt_array(t1, t2, n));

  sum_tabs(res, t1, t2, n);
  printf("sum_tabs(res, t1, t2, n) (effet de bord sur res)\n");
  printf("res : ");
  display_array(res, n);

  return EXIT_SUCCESS;
}
