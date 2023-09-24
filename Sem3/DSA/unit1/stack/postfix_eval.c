#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

typedef struct stack{
  int top;
  int arr[10];
} stk;


void push(stk* stack, int data){
  stack->top++;
  stack->arr[stack->top] = data;
}

int pop(stk* stack){
  stack->top--;
  return stack->arr[stack->top + 1];
}


int eval_with_op(int op1, int op2, char operator){
  switch(operator){
    case '+':
      return op1 + op2;
      break;
    case '-':
      return op2 - op1;
      break;
    case '*':
      return op1 * op2;
      break;
    case '/':
      return op1/op2;
      break;
  }
  return 0;
}


int eval_postfix(char *postfix_exp){
  stk stack = {.top = -1};

  while(postfix_exp[0] != '\0'){
    if(isdigit(postfix_exp[0])){
      push(&stack, postfix_exp[0] - '0');
    }else{
      int operand1 = pop(&stack);
      int operand2 = pop(&stack);
      int res = eval_with_op(operand1, operand2, postfix_exp[0]);
      push(&stack, res);
    }
    postfix_exp++;
  }
  return pop(&stack);
}

int main(int argc, char *argv[])
{
  char postfix_exp[32];
  printf("Enter postfix expression: ");
  scanf("%s", postfix_exp);
  int result = eval_postfix(postfix_exp);
  printf("The result is: %d\n", result);
  return EXIT_SUCCESS;
}
