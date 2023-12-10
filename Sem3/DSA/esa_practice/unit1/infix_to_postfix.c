#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
typedef struct stack {
  int data;
  struct stack *next;
} stacki;

void push(stacki **stack, int data) {
  stacki *new_node = (stacki *)malloc(sizeof(stacki));
  new_node->data = data;
  new_node->next = *stack;
  *stack = new_node;
}

char pop(stacki **stack) {
  if (*stack == NULL) {
    return -1;
  } else {
    stacki *temp = *stack;
    *stack = (*stack)->next;
    char to_ret = temp->data;
    free(temp);
    return to_ret;
  }
}

int peek(stacki *stack) {
  if (stack == NULL) {
    return -1;
  }
  return stack->data;
}

int get_priority(char ch) {
  switch (ch) {
  case '(':
    return 1;
  case '-':
    return 2;
  case '+':
    return 3;
  case '*':
    return 4;
  case '/':
    return 5;
  case '#':
    return -1;
  default:
    return -1;
  }
}

char *get_postfix_expr(char *infix_expr) {
  char *postfix_expr = (char *)malloc(64 * sizeof(char));
  int counter = 0;
  char ch;
  stacki *stack = NULL;
  push(&stack, '#');
  while (*infix_expr != '\0') {
    if (isalpha(*infix_expr)) {
      postfix_expr[counter++] = *infix_expr;
    } else {
      // handle brackets
      if (*infix_expr == ')') {
        while ((ch = pop(&stack)) != '(') {
          postfix_expr[counter++] = ch;
        }
        infix_expr++;
        continue;
      }

      // if not a close bracket
      while (1) {
        ch = peek(stack);
        if (get_priority(ch) > get_priority(*infix_expr)) {
          postfix_expr[counter++] = pop(&stack);
        } else {
          break;
        }
      }

      push(&stack, *infix_expr);
    }
    infix_expr++;
  }

  // done iterating, now we empty the contents of the stack into the postfix
  // expr
  while ((ch = pop(&stack)) != '#') {
    postfix_expr[counter++] = ch;
  }
  postfix_expr[counter] = '\0';
  return postfix_expr;
}

int main(int argc, char *argv[]) {
  stacki *stack = NULL;
  char infix_expr[64];
  printf("Enter infix expression: ");
  scanf("%s", infix_expr);
  char *postfix_expr = get_postfix_expr(infix_expr);
  printf("Postfix Expression: %s\n", postfix_expr);
  return EXIT_SUCCESS;
}
