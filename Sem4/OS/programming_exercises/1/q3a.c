#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
  int a, b;
  printf("Enter num1: ");
  scanf("%d", &a);
  printf("Enter num2: ");
  scanf("%d", &b);
  char stra[10];
  sprintf(stra, "%d", a);
  char strb[10];
  sprintf(strb, "%d", b); // these will hold string versions of a and b
  char *child_argv[] = {"./q3b", stra, strb, NULL};
  execv(child_argv[0], child_argv);
  return EXIT_SUCCESS;
}
