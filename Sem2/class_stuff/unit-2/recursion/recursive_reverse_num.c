#include <stdio.h>
#include <stdlib.h>

int reverse(long int n, long int rev) {
  if (n == 0)
    return rev;
  return reverse(n / 10, rev * 10 + n % 10);
}

int main(int argc, char *argv[]) {
  int n = 1234;
  printf("%d", reverse(n, 0));
  return EXIT_SUCCESS;
}
