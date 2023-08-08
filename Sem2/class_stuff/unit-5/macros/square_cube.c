#include <stdio.h>
#include <stdlib.h>

#define ADD(x, y) (x + y + x)

int main(int argc, char *argv[]) {
  int a = 10;
  int b = 11;
  printf("%d\n", ADD(++a, ++b));
  return EXIT_SUCCESS;
}
