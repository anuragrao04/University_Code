#include <stdio.h>

int globalVariable = 10;

void function() {
  globalVariable++;
  printf("Global Variable: %d\n", globalVariable);
}

int main() {
  function();
  printf("main: %d", globalVariable);
  return 0;
}
