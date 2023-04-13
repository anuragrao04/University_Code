#include <stdio.h>

int main(int argc, char *argv[]) {
  int *p, x = 20;
  p = &x;
  printf("%d\n", p);
  printf("%d\n", ++p);
  printf("size of long double: %d", sizeof(long double));
  return 0;
}
