#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>


void usage(char *s) {
  perror(s);
  exit(1);
}


int est_palindrome(char *str) {
  int i = 0;
  int j = strlen(str) - 1;

  while (i < j) {
    if (str[i] != str[j])
      return 0;
    i++;
    j--;
  }

  return 1;
}


int my_isalpha(char c) {  
  return ((c >= 'A' && c <= 'Z') ||
	  (c >= 'a' && c <= 'z'));
}


int my_ismaj(char c) {
  return (c >= 'A' && c <= 'Z');
}


char my_tolower(char c) {
  int dist = 'a' - 'A';

  if (my_ismaj(c))
    return c + dist;

  return c;
}


void display_char() {
  for (int i = 0 ; i < 255 ; i++)
    printf("%d : %c\n", i, i);
}


/* Note : operateur ternaire
 * (cond)?val1:val2 est une expression ternaire qui a pour valeur
 * val1 si (cond) est vraie, val2 sinon */

int main(int argc, char *argv[]) {
  if (argc != 2)
    usage("usage: ./ex2 chaine");

  printf("--- PALINDROME ---\n");
  printf("est_palindrome(%s) : %s\n", argv[1], est_palindrome(argv[1])?"TRUE":"FALSE");

  printf("\n--- ALPHABET ---\n");
  printf("isalpha('a - 1') : %s\n", isalpha('a' - 1)?"TRUE":"FALSE");
  printf("isalpha('a') : %s\n", isalpha('a')?"TRUE":"FALSE");
  printf("isalpha('b') : %s\n", isalpha('b')?"TRUE":"FALSE");
  printf("isalpha('A') : %s\n", isalpha('A')?"TRUE":"FALSE");
  printf("isalpha('Z') : %s\n", isalpha('Z')?"TRUE":"FALSE");
  printf("isalpha('Z' + 1) : %s\n", isalpha('Z' + 1)?"TRUE":"FALSE");
  printf("isalpha('2') : %s\n", isalpha('2')?"TRUE":"FALSE");
  printf("isalpha('_') : %s\n", isalpha('_')?"TRUE":"FALSE");
  printf("my_isalpha('a') : %s\n", my_isalpha('a')?"TRUE":"FALSE");
  printf("my_isalpha('j') : %s\n", my_isalpha('j')?"TRUE":"FALSE");
  printf("my_isalpha('A') : %s\n", my_isalpha('A')?"TRUE":"FALSE");
  printf("my_isalpha('Z') : %s\n", my_isalpha('Z')?"TRUE":"FALSE");
  printf("my_isalpha('3') : %s\n", my_isalpha('3')?"TRUE":"FALSE");
  printf("my_isalpha('_') : %s\n", my_isalpha('_')?"TRUE":"FALSE");

  printf("\n--- MINUSCULE ---\n");
  printf("tolower(%c) : %c\n", 'A', tolower('A'));
  printf("tolower(%c) : %c\n", 'a', tolower('a'));
  printf("tolower(%c) : %c\n", 'G', tolower('G'));
  printf("my_tolower(%c) : %c\n", 'A', my_tolower('A'));
  printf("my_tolower(%c) : %c\n", 'a', my_tolower('a'));
  printf("my_tolower(%c) : %c\n", 'G', my_tolower('G'));

  return EXIT_SUCCESS;
}
