#include <stdio.h>

int main(int argc, char const *argv[]) {
  // Multiplication By 2
  int a = 2;
  printf("2 * 2 is: %d\n", a << 1);

  // Division By 2
  int b = 4;
  printf("4 / 2 is %d\n", b >> 1);

  // Even Or Odd
  int c = 3;
  (c & 1) == 0 ? printf("even\n") : printf("odd\n");
  // the only way a number can be odd is if the LSB of the binary representation
  // is 1
  //  for example
  //  100 = 4
  //  101 = 5
  //  110 = 6
  //  111 = 7
  //  and so on
  //  so when we use the bitwise & operator on the integer comparing it to 1,
  //  we are essentially checking if the LSB is also 1 => Which means the
  //  integer is odd
}
