#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define NUM_SPACE 5

typedef struct node {
  int data;
  struct node *rchild;
  struct node *lchild;
} node_t;

node_t *get_node(int data);
void insert(node_t **root, int data);
void preorder(node_t *root);
void inorder(node_t *root);
void postorder(node_t *root);
void display(node_t *root, int space);
int count_nodes(node_t *root);
int count_leaves(node_t *root);
int get_height(node_t * root);
node_t *delete_node(node_t *root, int key);

int main(int argc, char *argv[]) {

  int choice;
  int data;
  node_t *root = NULL;

  do {
    printf("1. Insert\n");
    printf("2. Preorder\n");
    printf("3. Inorder\n");
    printf("4. Postorder\n");
    printf("5. Display\n");
    printf("6. Count nodes\n");
    printf("7. Count leaves\n");
    printf("8. Get height\n");
    printf("9. Delete\n");
    printf("0. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
    case 1:
      printf("Enter data: ");
      scanf("%d", &data);
      insert(&root, data);
      break;

    case 2:
      preorder(root);
      printf("\n");
      break;

    case 3:
      inorder(root);
      printf("\n");
      break;

    case 4:
      postorder(root);
      printf("\n");
      break;

    case 5:
      display(root, 0);
      break;

    case 6:
      printf("Number of nodes: %d\n", count_nodes(root));
      break;

    case 7:
      printf("Number of leaves: %d\n", count_leaves(root));
      break;

    case 8:
      printf("Height: %d\n", get_height(root));
      break;

    case 9:
      printf("Enter data: ");
      scanf("%d", &data);
      root = delete_node(root, data);
      break;

    case 0:
      printf("Exiting...\n");
      break;

    default:
      printf("Invalid choice\n");
      break;
    }

  } while (choice != 0);

  return EXIT_SUCCESS;
}

node_t *get_node(int data) {
  node_t *new_node = malloc(sizeof(node_t));
  new_node->data = data;
  new_node->lchild = NULL;
  new_node->rchild = NULL;
  return new_node;
}

void insert(node_t **root, int data) {
  node_t *new_node = get_node(data);
  if (*root == NULL) {
    *root = new_node;
    return;
  } else {
    node_t *prev = *root;
    node_t *current = *root;
    while (current != NULL) {
      prev = current;

      if (data < current->data) {
        current = current->lchild;
      } else {
        current = current->rchild;
      }
    }

    if (data < prev->data) {
      prev->lchild = new_node;
    } else {
      prev->rchild = new_node;
    }
  }
}

void preorder(node_t *root) {
  if (root == NULL) {
    return;
  }
  printf("%d ", root->data);
  preorder(root->lchild);
  preorder(root->rchild);
}

void inorder(node_t *root) {
  if (root == NULL) {
    return;
  }
  inorder(root->lchild);
  printf("%d ", root->data);
  inorder(root->rchild);
}

void postorder(node_t *root) {
  if (root == NULL) {
    return;
  }
  postorder(root->lchild);
  postorder(root->rchild);
  printf("%d ", root->data);
}

void display(node_t *root, int space) {
  if (root == NULL) {
    return;
  }

  space += NUM_SPACE;

  display(root->rchild, space);

  for (int i = NUM_SPACE; i < space; i++) {
    printf(" ");
  }
  printf("%d\n", root->data);

  display(root->lchild, space);
}

int count_nodes(node_t *root) {
  if (root == NULL) {
    return 0;
  }
  int n_left = count_nodes(root->lchild);
  int n_right = count_nodes(root->rchild);
  return n_left + n_right + 1;
}

int count_leaves(node_t *root) {
  if (root == NULL) {
    return 0;
  } else if (root->lchild == NULL && root->rchild == NULL) {
    return 1;
  } else {
    return count_leaves(root->lchild) + count_leaves(root->rchild);
  }
}



int get_height(node_t * root){
  if(root == NULL){
    return -1;
  }
  else if(root->lchild == NULL && root->rchild == NULL) {
    return 0;
  } else{
    return 1 + fmax(get_height(root->rchild), get_height(root->lchild));
  }
}


node_t* get_min_node(node_t* root){
  while(root->lchild != NULL && root != NULL){
    root = root->lchild;
  }
  return root;
}

node_t *delete_node(node_t *root, int key){
  if(root == NULL){
    printf("Element not found\n");
    return root;
  }
  if(key < root->data){
    root->lchild = delete_node(root->lchild, key);
  } else if(key > root->data){
    root->rchild = delete_node(root->rchild, key);
  } else{
    if (root->rchild == NULL){
      node_t* temp = root->lchild;
      free(root);
      return temp;
    } else if(root->lchild == NULL){
      node_t* temp = root->rchild;
      free(root);
      return temp;
    }
    node_t* temp = get_min_node(root->rchild);
    root->data = temp->data;
    root->rchild = delete_node(root->rchild, temp->data);

  }
  return root;
}
