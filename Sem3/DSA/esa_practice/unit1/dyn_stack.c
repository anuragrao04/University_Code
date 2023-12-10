#include <stdio.h>
#include <stdlib.h>

typedef struct stack {
  int top;
  int capacity;
  int *arr;
} STACK;

int isFull(STACK *stk) { return stk->top == stk->capacity; }

void push(STACK *stk, int data) {
  stk->top++;
  if (isFull(stk)) {
    printf("\nNot enough space, doubling capacity of stack");
    stk->arr = realloc(stk->arr, 2 * stk->capacity * sizeof(int));
    stk->capacity *= 2;
    printf("\nNew capacity: %d", stk->capacity);
  }
  stk->arr[stk->top] = data;
}

int pop(STACK *stk) {
  if (stk->top == -1) {
    printf("Stack is empty");
    return -1;
  }
  return stk->arr[stk->top--];
}

void display(STACK *stk) {
  printf("\nStack: \n");
  for (int i = stk->top; i >= 0; i--) {
    printf("| %d |\n", stk->arr[i]);
  }
  printf("-----\n");
}

int main(int argc, char *argv[]) {
  STACK *stk = malloc(sizeof(STACK));
  stk->top = -1;
  stk->capacity = 1;
  stk->arr = malloc(stk->capacity * sizeof(int));

  int choice;
  int data;
  while (1) {
    system("clear");
    display(stk);
    printf("\n1. Push\n2. Pop\n3. Exit\n");
    scanf("%d", &choice);
    switch (choice) {
    case 1:
      printf("\nEnter data to push: ");
      scanf("%d", &data);
      push(stk, data);
      break;
    case 2:
      printf("\nPopped data: %d", pop(stk));
      break;
    case 3:
      exit(0);
    default:
      printf("\nInvalid choice");
    }
  }

  return EXIT_SUCCESS;
}
