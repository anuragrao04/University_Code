#include <stdio.h>
#include <stdlib.h>

typedef struct node {
  int data;
  struct node *right;
  struct node *left;
  int rthread;
} node_t;

node_t *getNode(int data) {
  node_t *newNode = malloc(sizeof(node_t));
  newNode->data = data;
  newNode->left = NULL;
  newNode->right = NULL;
  newNode->rthread = 1;
  return newNode;
}

void setLeft(node_t *parent, node_t *node) {
  parent->left = node;
  node->right = parent;
}

void setRight(node_t *parent, node_t *node) {
  node->right = parent->right;
  parent->right = node;
  parent->rthread = 0;
}

void insert(node_t **root, int data) {
  node_t *newNode = getNode(data);
  if (*root == NULL) {
    *root = newNode;
    return;
  } else {
    node_t *current = *root;
    node_t *parent = NULL;
    while (current != NULL) {
      parent = current;
      if (data < current->data) {
        current = current->left;
      } else if (current->rthread) {
        break;
      } else {
        current = current->right;
      }
    }
    if (data < parent->data) {
      setLeft(parent, newNode);
    } else {
      setRight(parent, newNode);
    }
  }
}

node_t *getLeftMost(node_t *node) {
  if (node == NULL) {
    return node;
  } else {
    while (node->left != NULL) {
      node = node->left;
    }
    return node;
  }
}

void inorder(node_t *root) {
  node_t *current = getLeftMost(root);
  while (current != NULL) {
    printf("%d ", current->data);
    if (current->rthread) {
      current = current->right;
    } else {
      current = getLeftMost(current->right);
    }
  }
}

int main(int argc, char *argv[]) {
  node_t *tree = NULL;
  int n;
  printf("Enter number of elements: ");
  scanf("%d", &n);
  printf("Enter elements space separated: ");
  int element;
  for (int i = 0; i < n; i++) {
    scanf("%d", &element);
    insert(&tree, element);
  }

  // inorder traversal
  inorder(tree);

  return EXIT_SUCCESS;
}
