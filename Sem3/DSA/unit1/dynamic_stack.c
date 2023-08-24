#include <stdio.h>
#include <stdlib.h>

void push(int stack[], int *stack_size, int *occupied);
void display(int stack[], int occupied);
int main(int argc, char *argv[]) {
  int occupied = 0;
  int stack_size = 1;
  int *stack = malloc(stack_size * sizeof(int));

  while (1) {
    push(stack, &stack_size, &occupied);
    display(stack, occupied);
  }

  free(stack);
  return EXIT_SUCCESS;
}

void push(int stack[], int *stack_size, int *occupied) {
  int element;
  printf("Enter element: ");
  scanf("%d", &element);

  *occupied += 1;

  if (occupied >= stack_size) {
    *stack_size = 2 * *stack_size * sizeof(int);
    stack = realloc(stack, *stack_size);
    printf("\nMemory doubled to %d\n", *stack_size);
  }
}

void display(int *stack, int occupied) {
  for (int i = 0; i < occupied; i++) {
    printf("%d ", stack[i]);
  }
  printf("\n");
}
