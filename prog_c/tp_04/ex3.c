#include <stdlib.h>
#include <stdio.h>

void usage(char *s) {
  perror(s);
  exit(EXIT_FAILURE);
}


/* Version soft */
char *stpcpy(char *dst, const char *src) {
  int i = 0;

  while (src[i] != '\0') {
    dst[i] = src[i];
    i++;
  }

  dst[i] = '\0';
  return dst + i; // &dst[i]
}


/* Version hardcore */
char *stpcpy_hardcore(char *dst, const char *src) {
  while ((*dst++ = *src++))
    ;
  
  return dst - 1;
}


size_t strlen(const char *s) {
  const char *begin = s;

  while (*s)
    s++;

  return s - begin;
}


int strcmp(const char *s1, const char *s2) {
  while (*s1) {
    if (*s2 == '\0') // s2 se termine avant s1
      return -1;

    if (*s1 != *s2) // Les car sont differents
      return *s1 - *s2;

    ++s1;
    ++s2;
  }

  return *s2 != '\0';
}   


/* ATTENTION : s1 doit etre assez grand pour contenir
 * Les chaines concatenees... Cela veut dire que l'espace memoire
 * alloue doit etre plus grand que la taille proprement dite de la chaine s1
 * (en gros il doit y avoir de la place apres le '\0') */
char *strcat(char *s1, const char *s2) {
  char *p = s1 + strlen(s1);
  stpcpy(p, s2);
  return s1;
}   


int main(int argc, char *argv[]) {
  if (argc != 1)
    usage("usage: ./ex3");

  char str1[] = "Toto";
  char str2[] = "Tata";
  char str3[] = "Titi";
  char str4[10] = "Tutu";

  printf("str1 : %s\n", str1);
  printf("str2 : %s\n", str2);
  printf("str3 : %s\n\n", str3);
  printf("str4 : %s\n\n", str4);

  printf("stpcpy(str2, str1)\n");
  stpcpy(str2, str1);
  printf("str2 : %s\n\n", str2);

  printf("stpcpy_hardcore(str2, str1)\n");
  stpcpy_hardcore(str3, str1);
  printf("str3 : %s\n\n", str3);

  printf("strlen(%s) : %zu\n", str1, strlen(str1));
  printf("strcmp(str1, str2) : %d\n\n", strcmp(str1, str2));

  printf("strcat(str4, str1) : %s\n", strcat(str4, str1));

  return EXIT_SUCCESS;
}
