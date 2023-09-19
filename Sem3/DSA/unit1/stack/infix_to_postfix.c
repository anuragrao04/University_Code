#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 100

// Stack implementation
struct Stack {
  int top;
  unsigned capacity;
  char *array;
};

struct Stack *createStack(unsigned capacity) {
  struct Stack *stack = (struct Stack *)malloc(sizeof(struct Stack));
  stack->capacity = capacity;
  stack->top = -1;
  stack->array = (char *)malloc(stack->capacity * sizeof(char));
  return stack;
}

int isEmpty(struct Stack *stack) { return stack->top == -1; }

char peek(struct Stack *stack) { return stack->array[stack->top]; }

char pop(struct Stack *stack) {
  if (!isEmpty(stack))
    return stack->array[stack->top--];
  return '$';
}

void push(struct Stack *stack, char op) { stack->array[++stack->top] = op; }

int isOperand(char ch) {
  return (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z');
}

int Prec(char ch) {
  switch (ch) {
  case '+':
  case '-':
    return 1;
  case '*':
  case '/':
    return 2;
  case '$':
    return 3;
  }
  return -1;
}

void infixToPostfix(char *exp) {
  int i, k;
  struct Stack *stack = createStack(strlen(exp));
  if (!stack)
    return;

  for (i = 0, k = -1; exp[i]; ++i) {
    if (isOperand(exp[i]))
      exp[++k] = exp[i];

    else if (exp[i] == '(')
      push(stack, exp[i]);

    else if (exp[i] == ')') {
      while (!isEmpty(stack) && peek(stack) != '(')
        exp[++k] = pop(stack);
      pop(stack);

    } else {
      while (!isEmpty(stack) && Prec(exp[i]) <= Prec(peek(stack)))
        exp[++k] = pop(stack);
      push(stack, exp[i]);
    }
  }

  while (!isEmpty(stack))
    exp[++k] = pop(stack);

  exp[++k] = '\0';
  printf("Postfix expression: %s\n", exp);
}

int main() {
  char exp[SIZE];
  printf("Enter the infix expression: ");
  fgets(exp, SIZE, stdin);
  infixToPostfix(exp);
  return 0;
}
