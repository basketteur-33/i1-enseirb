#include <stdlib.h>
#include <stdio.h>


int fibo_rec(int n) {
  if (n < 2)
    return n;

  return fibo_rec(n-1) + fibo_rec(n-2);
}


int fibo_iter(int n) {
  int size = n + 1;
  int t[size];
  t[0] = 0;
  t[1] = 1;

  for (int i = 2 ; i < size ; i++)
    t[i] = t[i-1] + t[i-2];

  return t[n];
}


int fibo_iter_bis(int n) {
  int u = 0;
  int v = 1;
  int w;
  int i = 0;
  
  while (i < n) {
    w = u + v;
    u = v;
    v = w;
    i++;
  }

  return u;
}
  

int main(int argc, char *argv[]) {
  for (int i = 0 ; i < 10 ; i++)
    printf("fibo_rec(%d) : %d\n", i, fibo_rec(i));

  printf("_____________________________\n\n");

  for (int i = 0 ; i < 10 ; i++)
    printf("fibo_iter(%d) : %d\n", i, fibo_iter(i));

  printf("_____________________________\n\n");

  for (int i = 0 ; i < 10 ; i++)
    printf("fibo_iter_bis(%d) : %d\n", i, fibo_iter_bis(i));

  return EXIT_SUCCESS;
}
