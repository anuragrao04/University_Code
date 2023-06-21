
#include <stdio.h>

int main() {
#ifdef __unix__
  printf("This code is being compiled on a Unix system.\n");
#else
  printf("This code is not being compiled on a Unix system.\n");
#endif
  return 0;
}
