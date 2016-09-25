#include <stdlib.h>
#include <stdio.h>
#include <string.h>


void usage(char *s) {
  perror(s);
  exit(1);
}


void my_itoa(char *str, int n) {
  int i = 0;
  
  if (n < 0)
    str[i++] = '-';

  while 
}



int main(int argc, char *argv[]) {
  if (argc != 2)
    usage("usage: ./ex4 chaine");

  return EXIT_SUCCESS;
}
