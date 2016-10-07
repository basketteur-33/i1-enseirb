#include <stdlib.h>
#include <stdio.h>

void usage(char *s) {
  perror(s);
  exit(1);
}


/* Decalage du nombre */
int compte_bits(int n) {
  int s = 0;

  while (n > 0) {
    if (n & 1)
      s++;
    n = n >> 1;
  }

  return s;
}


/* Decalage du masque */
int compte_bits_bis(int n) {
  int s = 0;
  int m = 1;
  int n_bits = 8 * sizeof(n);
  
  for (int i = 0 ; i < n_bits ; i++) {
    if (n & m)
      s++;
    m = m << 1;
  }

  return s;
}


/* Parce qu'on aime le hack */
int hackers_deligth(int n) {
  int s = 0;

  while (n > 0) {
    /* DIRTY TRICK */
    int m = n & (~n + 1);
    n = n ^ m;
    s++;
  }

  return s;
}
    

int main(int argc, char *argv[]) {
  if (argc != 2)
    usage("usage: ./ex3 entier");
  
  int n = atoi(argv[1]);

  printf("compte_bits(%d) : %d\n", n, compte_bits(n));
  printf("compte_bits_bis(%d) : %d\n", n, compte_bits_bis(n));
  printf("hackers_deligth(%d) : %d\n", n, hackers_deligth(n));

  return EXIT_SUCCESS;
}
