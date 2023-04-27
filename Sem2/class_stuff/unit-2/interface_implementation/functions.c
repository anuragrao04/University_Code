#include <stdio.h>
#include <stdlib.h>

int isPalindrome(int a) {
  int b = a;
  int sum = 0;
  while (b) {
    sum = sum * 10 + (b / 10);
    b /= 10;
  }
  return sum == a;
}
