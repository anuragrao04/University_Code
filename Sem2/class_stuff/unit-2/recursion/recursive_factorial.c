#include <stdio.h>
int get_factorial(int n) {
  if (n == 0) {
    return 1;
  } else {
    return n * get_factorial(n - 1);
  }
}

int main(void) {
  int n = 0;
  printf("Enter the number: ");
  scanf("%d", &n);
  printf("Factorial of %d is %d\n", n, get_factorial(n));
  return 0;
}
