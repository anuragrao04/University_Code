#include <stdio.h>
int get_factorial(int n) {
  if (n == 0) {
    return 1;
  } else {
    return n * get_factorial(n - 1);
  }
}
int main(int argc, char *argv[]) {
  printf("Factorial of 4 is %d", get_factorial(4));
  return 0;
}
