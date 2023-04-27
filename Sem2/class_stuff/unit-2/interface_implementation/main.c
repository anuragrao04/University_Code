#include "functions.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  int x = 1212;
  isPalindrome(x) ? printf("It is palindromic")
                  : printf("It is not palindromic");
  return EXIT_SUCCESS;
}
