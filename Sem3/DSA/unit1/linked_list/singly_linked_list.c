#include <stdio.h>
#include <stdlib.h>

typedef struct node {
  int data;
  struct node *link;
} node_t;

void insert_front(node_t **head, int data);
void insert_back(node_t **head, int data);
void delete_front(node_t **head);
void delete_back(node_t **head);
void insert_at_position(node_t **head, int data, int position);
void delete_at_position(node_t **head, int position);
void delete_with_key(node_t **head, int data);
void display(node_t *head);
void free_list(node_t *head);

int main(int argc, char *argv[]) {
  node_t *head = NULL; // No list exists yet
  int choice;
  int position;
  while (1) {
    printf("1. Insert Front\n2. Insert Back\n3. Delete Front\n4. Delete "
           "Back\n5. Insert At "
           "Position\n6. Delete At Position\n7. Delete with key\n0. Exit\n");
    scanf("%d", &choice);

    int data;
    switch (choice) {
    case 1:
      printf("Enter data: ");
      scanf("%d", &data);
      insert_front(&head, data);
      display(head);
      break;

    case 2:
      printf("Enter data: ");
      scanf("%d", &data);
      insert_back(&head, data);
      display(head);
      break;

    case 3:
      delete_front(&head);
      display(head);
      break;

    case 4:
      delete_back(&head);
      display(head);
      break;

    case 5:
      printf("Enter data: ");
      scanf("%d", &data);
      printf("Enter position (0 indexed): ");
      scanf("%d", &position);
      insert_at_position(&head, data, position);
      display(head);
      break;

    case 6:
      printf("Enter position (0 indexed): ");
      scanf("%d", &position);
      delete_at_position(&head, position);
      display(head);
      break;

    case 7:
      printf("Enter element you want to remove: ");
      scanf("%d", &data);
      delete_with_key(&head, data);
      display(head);
      break;

    case 0:
      free_list(head);
      printf("Freed List. Exiting\n");
      return EXIT_SUCCESS;
    }
  }

  return EXIT_SUCCESS;
}

void insert_front(node_t **head, int data) {
  node_t *new_node = malloc(sizeof(node_t));
  new_node->data = data;
  new_node->link = *head;
  *head = new_node;
}

void delete_front(node_t **head) {
  if (head == NULL) {
    printf("List only isn't there pa\n");
    return;
  }
  node_t *temp = (*head)->link;
  free(*head);
  *head = temp;
}

void display(node_t *head) {
  if (head == NULL) {
    printf("List Empty\n");
    return;
  }
  while (head != NULL) {
    printf("%d ", head->data);
    head = head->link;
  }
  printf("\n");
}

void insert_back(node_t **head, int data) {
  node_t *new_node = malloc(sizeof(node_t));
  new_node->data = data;

  if (*head == NULL) {
    *head = new_node;
    new_node->link = NULL;
    return;
  } else {
    node_t *ohead = *head;
    while ((*head)->link != NULL) {
      *head = (*head)->link;
    }
    (*head)->link = new_node;
    new_node->link = NULL;
    *head = ohead;
  }
}

void delete_back(node_t **head) {
  if (head == NULL) {
    printf("List only isn't there pa\n");
    return;
  } else if ((*head)->link == NULL) {
    free(*head);
    *head = NULL;
  } else {
    node_t *ohead = *head;
    while ((*head)->link->link != NULL) {
      *head = (*head)->link;
    }
    free((*head)->link);
    (*head)->link = NULL;
    *head = ohead;
  }
}

void insert_at_position(node_t **head, int data, int position) {
  node_t *new_node = malloc(sizeof(node_t));
  new_node->data = data;

  if ((*head) == NULL) {
    (*head) = new_node;
    new_node->link = NULL;
    return;
  }

  if (position == 0) {
    new_node->link = (*head);
    (*head) = new_node;
    return;
  }

  node_t *ohead = *head;

  for (int i = 1; i < position && (*head)->link != NULL; i++) {
    *head = (*head)->link;
  }
  new_node->link = (*head)->link;
  (*head)->link = new_node;
  *head = ohead;
}

void delete_at_position(node_t **head, int position) {
  if ((*head) == NULL) {
    printf("list only isn't there pa\n");
    return;
  }

  if (position == 0) {
    node_t *temp = *head;
    *head = (*head)->link;
    free(temp);
    temp = NULL;
    return;
  }

  if ((*head)->link == NULL) {
    free(*head);
    *head = NULL;
  }

  node_t *ohead = *head;
  for (int i = 1; i < position && (*head)->link->link != NULL; i++) {
    *head = (*head)->link;
  }
  node_t *temp = (*head)->link;
  (*head)->link = (*head)->link->link;
  free(temp);
  *head = ohead;
}

void delete_with_key(node_t **head, int key) {
  if (*head == NULL) {
    printf("No list pa\n");
    return;
  }
  if ((*head)->data == key) {
    delete_front(head);
    return;
  }

  node_t *ohead = *head;

  node_t *prev = *head;
  *head = (*head)->link;

  while (*head != NULL) {
    if ((*head)->data == key) {
      prev->link = (*head)->link;
      free(*head);
      *head = ohead;
      return;
    }
    prev = *head;
    *head = (*head)->link;
  }
  printf("Element doesn't exist\n");
  *head = ohead;
  return;
}

void free_list(node_t *head) {
  while (head != NULL) {
    node_t *next = head->link;
    free(head);
    head = next;
  }
}
