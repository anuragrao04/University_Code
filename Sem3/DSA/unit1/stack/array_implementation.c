#include <stdio.h>
#include <stdlib.h>
#define STACK_SIZE 50

typedef struct stack {
  int arr[STACK_SIZE];
  int top;
} stack;

void display(stack *stk);
void push(stack *stk, int data);
void pop(stack *stk);

int main(int argc, char const *argv[]) {
  stack stk;
  stk.top = -1;
  int choice;

  while (1) {
    printf("1. Push\n2. Pop\n3. Display\n0. Exit\n");
    scanf("%d", &choice);

    int data;
    switch (choice) {
    case 1:
      printf("Enter data: ");
      scanf("%d", &data);
      push(&stk, data);
      break;
    case 2:
      pop(&stk);
      break;

    case 3:
      display(&stk);
      break;
    case 0:
      return EXIT_SUCCESS;
      break;
    }
  }
  return EXIT_SUCCESS;
}

void display(stack *stk) {
  printf("\n\n");
  if (stk->top == -1) {
    printf("Stack Empty\n");
    printf("\n\n");
    return;
  }
  for (int i = (stk->top); i >= 0; i--) {
    printf("%d\n", stk->arr[i]);
  }
  printf("\n\n");
}

void push(stack *stk, int data) {
  if (stk->top == STACK_SIZE - 1) {
    printf("\n\n");
    printf("Can't insert. Stack will overflow\n");
    printf("\n\n");
    return;
  }
  stk->top += 1;
  stk->arr[stk->top] = data;
  display(stk);
}

void pop(stack *stk) {
  if (stk->top == -1) {
    printf("Can't pop. List is empty. It will underflow\n");
    return;
  }
  stk->top -= 1;
  display(stk);
}
