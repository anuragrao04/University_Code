#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) {
  char st[] = "py\0thon";
  printf("%s\n", st);
  printf("at index 2 is: %c\n", st[2]);
  printf("at index 3 is: %c\n", st[3]);

  return 0;
}
