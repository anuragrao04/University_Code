#include <stdio.h>
#include <stdlib.h>

void reverse(char *str) {
  if (*str) {
    reverse(str + 1);
    printf("%c", *str);
  }
}

int main(int argc, char *argv[]) {
  char st[] = "abcdef";
  reverse(st);

  return EXIT_SUCCESS;
}
