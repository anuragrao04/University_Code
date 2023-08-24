#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

struct test {
  int test_ele;
};

int main(int argc, char *argv[]) {

  int x;
  int *pX;

  struct test test_var;

  test_var.test_ele = 20;
  struct test *p_test_var;

  p_test_var = &test_var;

  x = 10;
  pX = &x;

  printf("%d", *pX);
  printf("\n%d", p_test_var->test_ele);

  return EXIT_SUCCESS;
}
