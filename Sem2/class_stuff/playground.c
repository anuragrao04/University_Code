#include <stdio.h>

int main(int argc, char *argv[]) {
  int a = 10;
  int b = 20;
  int *pA = &a;
  printf("%d", pA[0]);
  return 0;
}
