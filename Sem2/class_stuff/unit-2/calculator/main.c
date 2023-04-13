#include <stdio.h>
#define EXIT_SUCCESS 0
#include "calculator.h"
int main(int argc, char *argv[]) {

  float x, y;
  printf("Enter first number: ");
  scanf("%f", &x);
  printf("Enter the second number: ");
  scanf("%f", &y);
  char operator;
  printf("Enter operator (+, -, /, *): ");
  scanf(" %c", &operator);

  switch (operator) {
  case '+':
    printf("The result is: %f\n", add(x, y));
    break;
  case '-':
    printf("The result is: %f\n", sub(x, y));
    break;
  case '*':
    printf("The result is: %f\n", mul(x, y));
    break;
  case '/':
    printf("The result is: %f\n", div(x, y));
    break;
  default:
    printf("Unrecognised Operator, exiting.\n");
  }
  return EXIT_SUCCESS;
}
