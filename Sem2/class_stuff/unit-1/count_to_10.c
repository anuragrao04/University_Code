#include <stdio.h>

int function_something() { return 0; }
int main(int argc, char const *argv[]) {
  // while
  int n = 0, count = 0;
  while (n <= 10) {
    count += n;
    n++;
  }
  printf("count is: %d\n", count);

  // do while
  n = 0, count = 0;
  do {
    count += n;
    n++;
  } while (n <= 10);
  printf("count is: %d\n", count);

  // for
  n = 0, count = 0;
  for (n = 0; n <= 10; n++) {
    count += n;
  }
  printf("count is: %d\n", count);
  printf("something function returned: %d", function_something());
  return 0;
}
