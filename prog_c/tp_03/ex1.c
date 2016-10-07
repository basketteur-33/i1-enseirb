#include <stdlib.h>
#include <stdio.h>

void usage(char *s) {
  perror(s);
  exit(1);
}


int est_bissextile(int year) {
  return (year % 4 == 0 && year % 100) || (year % 400 == 0);
}


int nombre_jours(int month, int year) {
  switch (month) {
  case 2:
    if (est_bissextile(year))
      return 29;
    return 28;
    break;
  case 1:
  case 3:
  case 5:
  case 7:
  case 8:
  case 10:
  case 12:
    return 31;
    break;
  default:
    return 30;
    break;
  }
}
    

int main(int argc, char *argv[]) {
  if (argc != 2)
    usage("usage: ./ex1 annee");

  int year = atoi(argv[1]);
  printf("%d est-elle une annee bissextile ? %s\n", year, est_bissextile(year)?"OUI":"NON");

  printf("Il y a %d jours en août (8) et %d jours en septembre (9)\n", nombre_jours(8, 2016), nombre_jours(9, 2016));

  return EXIT_SUCCESS;
}
