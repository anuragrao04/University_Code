#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct stack{
  char arr[100];
  int top;
} stack;

void push(stack *stk, char data)
{
  stk->arr[++stk->top] = data;
}

char pop(stack *stk){
  return stk->arr[stk->top--];
}

char peek(stack *stk){
  return stk->arr[stk->top];
}

int get_precedence(char operator){
  if(operator == '+' || operator == '-'){
    return 1;
  } else if(operator == '*' || operator == '/'){
    return 2;
  } else if(operator == '^'){
    return 3;
  } else if(operator == '('){
    return 0;
  } else {
    return -1;
  }
}

char *get_postfix(char* infix){
  char* postfix = malloc(sizeof(char) * 64);
  int counter = 0;
  stack stk;
  stk.top = -1;
  push(&stk, '#');


  while(*infix != '\0'){
    if(isalpha(infix[0])){
      postfix[counter++] = infix[0];
    } else{
      if(*infix == ')'){
        char ch = pop(&stk);
        while(ch != '('){
          postfix[counter++] = ch;
          ch = pop(&stk);
        }
        infix++;
        continue;
      }



      int prec = get_precedence(infix[0]);
      while(get_precedence(peek(&stk)) >= prec){
        postfix[counter++] = pop(&stk);
      }
      push(&stk, infix[0]);
    }
    infix++;
  }
  while(peek(&stk) != '#'){
    postfix[counter++] = pop(&stk);
  }
  postfix[counter] = '\0';
  return postfix;
}

int main(int argc, char *argv[])
{
  char infix[64];
  printf("Enter infix expression: ");
  scanf("%s", infix);
  printf("Postfix expression: %s\n", get_postfix(infix));
  return EXIT_SUCCESS;
}
