#include <stdlib.h>
#include <stdio.h>

void usage(char *s) {
  perror(s);
  exit(EXIT_FAILURE);
}


/* Affiche un tableau de caracteres */
void display_array(char t[], int n) {
  printf("[");

  for (int i = 0 ; i < n-1 ; ++i)
    printf("%d, ", t[i]);

  /* Ne pas avoir de virgule a la fin */
  printf("%d]\n", t[n-1]);
}


void *memcpy(void *dst, const void *src, size_t len) {
  /* On caste vers un char car c'est la longuer d'un octet */
  const char *s = src;
  char *d = dst;

  while (len--)
    *d++ = *s++;

  return dst;    
}


int memcmp(void *src, void *dst, size_t len) {
  const unsigned char *s = src;
  unsigned char *d = dst;

  while (len--) {
    if (*s != *d)
      return *s - *d;
    s++;
    d++;
  }

  return 0;
}


void *memset(void *src, int c, size_t len) {
  unsigned char *s = src;
  unsigned char fill = (unsigned char) c;

  while (len--)
    *s++ = fill;

  return src;
}  


void swab(const void *src, void *dest, size_t nbytes) {
  /* On convertit en char car c'est la taille d'un octet (byte) */
  const char *s = src;
  char *d = dest;

  while (nbytes > 1) {
    *d = *(s + 1);
    *(d + 1) = *s;
    s += 2;
    d += 2;
    nbytes -= 2;
  }
 
  /* Nombre de bytes impair */
  if (nbytes)
    *d = *s;  
}


int main(int argc, char *argv[]) {
  if (argc != 1)
    usage("usage: ./ex5");

  int x = 42;
  int y = 34;

  printf("x = %d et y = %d\n", x, y);
  printf("On recopie &x dans &y sur 4 octets (taille d'un entier)\n");
  printf("memcpy(&y, &x, 4)\n");
  memcpy(&y, &x, 4);
  printf("x = %d et y = %d\n\n", x, y);

  char str1[] = "Toto";
  char str2[] = "Tata";

  printf("str1 : %s\n", str1);
  printf("str2 : %s\n", str2);
  printf("memcmp(str1, str2, 4) : %d\n", memcmp(str1, str2, 4));
  printf("memcmp(str1, str1, 4) : %d\n\n", memcmp(str1, str1, 4));

  char t[] = { 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h' };
  char l[] = { 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h' };
  char m[8];
  int n = 8;

  printf("Manipulation de tableaux de car (affichage sous forme d'entiers)\n");
  display_array(t, n);
  printf("On appelle memset(t, \'\\0\', n)\n");
  memset(t, '\0', n);
  display_array(t, n);

  printf("\nManipulation de tableaux de car (affichage sous forme d'entiers)\n");
  display_array(l, n);
  printf("On appelle swab(l, m, n)\n");
  swab(l, m, n);
  display_array(m, n);

  return EXIT_SUCCESS;
}
