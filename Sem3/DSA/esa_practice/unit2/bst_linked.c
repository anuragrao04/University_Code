#include <stdio.h>
#include <stdlib.h>

typedef struct node {
  int data;
  struct node *left;
  struct node *right;
} node_t;

void insert(node_t **tree, int data);
node_t *get_node(int data);
node_t *delete(node_t *tree, int data);
void inorder(node_t *tree);
void preorder(node_t *tree);
void postorder(node_t *tree);

int main(int argc, char *argv[]) {
  node_t *tree = NULL;
  int choice;
  int data;
  while (1) {
    system("clear");
    printf("\n1. Insert\n2. Delete\n3. Inorder\n4. Preorder\n5. Postorder\n"
           "0. Exit\n");
    scanf("%d", &choice);
    switch (choice) {
    case 1:
      printf("\nEnter data to insert: ");
      scanf("%d", &data);
      insert(&tree, data);
      break;
    case 2:
      printf("\nEnter data to delete: ");
      scanf("%d", &data);
      tree = delete (tree, data);
      break;
    case 3:
      inorder(tree);
      break;
    case 4:
      preorder(tree);
      break;
    case 5:
      postorder(tree);
      break;
    case 0:
      return EXIT_SUCCESS;
    default:
      printf("\nInvalid choice");
    }
  }
  return EXIT_SUCCESS;
}

void insert(node_t **tree, int data) {
  node_t *new_node = get_node(data);
  if (*tree == NULL) {
    *tree = new_node;
    return;
  } else {
    node_t *child = *tree;
    node_t *parent = NULL;
    while (child != NULL) {
      parent = child;
      if (data < child->data) {
        child = child->left;
      } else {
        child = child->right;
      }
    }
    if (data < parent->data) {
      parent->left = new_node;
    } else {
      parent->right = new_node;
    }
  }
}

node_t *get_node(int data) {
  node_t *new_node = (node_t *)malloc(sizeof(node_t));
  new_node->data = data;
  new_node->left = NULL;
  new_node->right = NULL;
  return new_node;
}

node_t *delete(node_t *tree, int data) {
  if (tree->data == data) {
    if (tree->left == NULL && tree->right == NULL) {
      free(tree);
      return NULL;
    } else {
      if (tree->left == NULL) {
        node_t *toRet = tree->right;
        free(tree);
        return toRet;
      } else if (tree->right == NULL) {
        node_t *toRet = tree->left;
        free(tree);
        return toRet;
      } else {
        node_t *inorder_successor = tree->right;
        while (inorder_successor->left != NULL) {
          inorder_successor = inorder_successor->left;
        }
        // now we are at the inorder successor
        tree->data = inorder_successor->data;
        tree->right = delete (tree->right, inorder_successor->data);
      }
    }
  } else {
    if (data < tree->data) {
      tree->left = delete (tree->left, data);
    } else {
      tree->right = delete (tree->right, data);
    }
  }
  return tree;
}

void inorder(node_t *tree) {
  if (tree == NULL) {
    return;
  }
  inorder(tree->left);
  printf("%d ", tree->data);
  inorder(tree->right);
}

void preorder(node_t *tree) {
  if (tree == NULL) {
    return;
  }
  printf("%d ", tree->data);
  preorder(tree->left);
  preorder(tree->right);
}
void postorder(node_t *tree) {
  if (tree == NULL) {
    return;
  }
  postorder(tree->left);
  postorder(tree->right);
  printf("%d ", tree->data);
}
