#include <stdio.h>
#include <stdlib.h>

typedef struct node {
  int data;
  struct node *link;
} node_t;

void enque_front(node_t **front, node_t **rear, int data);
void enque_back(node_t **front, node_t **rear, int data);
void deque_front(node_t **front, node_t **rear);
void deque_back(node_t **front, node_t **rear);
void display(node_t *front);
void free_list(node_t *front);

int main(int argc, char *argv[]) {
  node_t *front = NULL; // No list exists yet
  node_t *rear = NULL;
  int choice;
  int position;
  while (1) {
    printf("1. Enque Front\n2. Enque Back\n3. Deque Front\n4. Deque "
           "Back\n0.Exit\n");
    scanf("%d", &choice);

    int data;
    switch (choice) {
    case 1:
      printf("Enter data: ");
      scanf("%d", &data);
      enque_front(&front, &rear, data);
      display(front);
      break;

    case 2:
      printf("Enter data: ");
      scanf("%d", &data);
      enque_back(&front, &rear, data);
      display(front);
      break;

    case 3:
      deque_front(&front, &rear);
      display(front);
      break;

    case 4:
      deque_back(&front, &rear);
      display(front);
      break;

    case 0:
      free_list(front);
      printf("Freed List. Exiting\n");
      return EXIT_SUCCESS;
    }
  }

  return EXIT_SUCCESS;
}

void enque_front(node_t **front, node_t **rear, int data) {
  node_t *new_node = malloc(sizeof(node_t));
  new_node->data = data;
  new_node->link = *front;
  *front = new_node;
  if (*rear == NULL) {
    *rear = new_node;
  }
}

void deque_front(node_t **front, node_t **rear) {
  if (front == NULL) {
    printf("List only isn't there pa\n");
    return;
  }
  if (*front == *rear && (*front)->link == NULL) {
    free(*front);
    *front = NULL;
    *rear = NULL;
    return;
  }
  node_t *temp = (*front)->link;
  free(*front);
  *front = temp;
}

void display(node_t *front) {
  if (front == NULL) {
    printf("List Empty\n");
    return;
  }
  while (front != NULL) {
    printf("%d ", front->data);
    front = front->link;
  }
  printf("\n");
}

void enque_back(node_t **front, node_t **rear, int data) {
  node_t *new_node = malloc(sizeof(node_t));
  new_node->data = data;
  if (*front == NULL) {
    *front = new_node;
    *rear = new_node;
  } else {
    (*rear)->link = new_node;
    new_node->link = NULL;
    *rear = new_node;
  }
}

void deque_back(node_t **front, node_t **rear) {
  if (*front == NULL || *rear == NULL) {
    printf("List only isn't there pa\n");
    return;
  } else if ((*front)->link == NULL) {
    free(*front);
    *front = NULL;
    *rear = NULL;
  } else {
    node_t *ofront = *front;
    while ((*front)->link->link != NULL) {
      *front = (*front)->link;
    }
    *rear = *front;
    free((*front)->link);
    (*rear)->link = NULL;
    *front = ofront;
  }
}

void free_list(node_t *front) {
  while (front != NULL) {
    node_t *next = front->link;
    free(front);
    front = next;
  }
}
