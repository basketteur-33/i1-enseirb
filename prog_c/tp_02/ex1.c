#include <stdlib.h>
#include <stdio.h>
#include <string.h>


void usage(char *s) {
  perror(s);
  exit(1);
}


int my_strlen(char *str) {
  int i = 0;

  while (str[i] != '\0')
    i++;

  return i;
}


int my_strcmp(char *str1, char *str2) {
  return my_strlen(str1) - my_strlen(str2);
}


int est_voyelle(char c) {
  return (c == 'a' || c == 'e' || c == 'i' ||
	  c == 'o' || c == 'u' || c == 'y');
}


int compte_voyelles(char *str) {
  int i = 0;
  int s = 0;

  while (str[i] != '\0') {
    if (est_voyelle(str[i]))
      s++;
    i++;
  }

  return s;
} 


int main(int argc, char *argv[]) {
  if (argc != 3)
    usage("usage: ./ex1 chaine1 chaine2");
  
  char *str1 = argv[1];
  char *str2 = argv[2];

  printf("--- AFFICHAGE ---\n");
  printf("str1 : \"%s\"\n", str1);
  printf("str2 : \"%s\"\n", str2);

  printf("\n--- LONGUEUR ---\n");
  printf("strlen(%s) : %zu\n", str1, strlen(str1));
  printf("my_strlen(%s) : %d\n", str1, my_strlen(str1));
  printf("strlen(%s) : %zu\n", str2, strlen(str2));
  printf("my_strlen(%s) : %d\n", str2, my_strlen(str2));

  printf("\n--- COMPARE ---\n");
  printf("strcmp(%s, %s) : %d\n", str1, str2, strcmp(str1, str2));
  printf("my_strcmp(%s, %s) : %d\n", str1, str2, my_strcmp(str1, str2));

  printf("\n--- VOYELLES ---\n");
  printf("compte_voyelles(%s) : %d\n", str1, compte_voyelles(str1));
  printf("compte_voyelles(%s) : %d\n", str2, compte_voyelles(str2));

  return EXIT_SUCCESS;
}

   
