#include <stdio.h>
#include <stdlib.h>

typedef struct node {
  char data;
  struct node *left;
  struct node *right;
} node_t;

void construct_tree(node_t **tree, char *expression);
int eval(node_t *tree);

int is_operand(char operand) {
  return (operand == '*' || operand == '/' || operand == '+' || operand == '-');
}

void push(node_t *stack[], int *top, node_t *node) { stack[++(*top)] = node; }
node_t *pop(node_t *stack[], int *top) { return stack[(*top)--]; }
node_t *get_node(char data) {
  node_t *new_node = (node_t *)malloc(sizeof(node_t));
  new_node->data = data;
  new_node->left = NULL;
  new_node->right = NULL;
  return new_node;
}

int main(int argc, char *argv[]) {
  char expression[64];
  printf("Enter postfix expression without spaces: ");
  scanf("%s", expression);
  node_t *tree;
  construct_tree(&tree, expression);
  printf("The result is : %d\n", eval(tree));
  return EXIT_SUCCESS;
}

void construct_tree(node_t **tree, char *expression) {
  node_t *stack[64];
  int top = -1;
  while (*expression != '\0') {
    node_t *new_node = get_node(*expression);
    if (is_operand(*expression)) {
      node_t *op1 = pop(stack, &top);
      node_t *op2 = pop(stack, &top);
      new_node->right = op1;
      new_node->left = op2;
      push(stack, &top, new_node);
    } else {
      push(stack, &top, new_node);
    }
    expression++;
  }
  *tree = pop(stack, &top);
}

int eval(node_t *tree) {
  if (is_operand(tree->data)) {
    switch (tree->data) {
    case '*':
      return eval(tree->left) * eval(tree->right);
    case '/':
      return eval(tree->left) / eval(tree->right);
    case '+':
      return eval(tree->left) + eval(tree->right);
    case '-':
      return eval(tree->left) - eval(tree->right);
    default:
      return eval(tree->left) +
             eval(tree->right); // default case is to just add. My LSP was
                                // complaining that the function has to return
                                // on all control paths
    }
  } else {
    int value;
    printf("Enter the value of %c: ", tree->data);
    scanf("%d", &value);
    return value;
  }
}
