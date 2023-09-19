#include <stdio.h>
#include <stdlib.h>

typedef struct node {
  int data;
  struct node *link;
} node_t;

void insert_front(node_t **tail, int data);
void insert_back(node_t **tail, int data);
void delete_front(node_t **tail);
void delete_back(node_t **tail);
void insert_at_position(node_t **tail, int data, int position);
void delete_at_position(node_t **tail, int position);
void delete_with_key(node_t **tail, int data);
void display(node_t *tail);
void free_list(node_t *tail);

int main(int argc, char *argv[]) {
  node_t *tail = NULL; // No list exists yet
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
      insert_front(&tail, data);
      display(tail);
      break;

    case 2:
      printf("Enter data: ");
      scanf("%d", &data);
      insert_back(&tail, data);
      display(tail);
      break;

    case 3:
      delete_front(&tail);
      display(tail);
      break;

    case 4:
      delete_back(&tail);
      display(tail);
      break;

    case 5:
      printf("Enter data: ");
      scanf("%d", &data);
      printf("Enter position (0 indexed): ");
      scanf("%d", &position);
      insert_at_position(&tail, data, position);
      display(tail);
      break;

    case 6:
      printf("Enter position (0 indexed): ");
      scanf("%d", &position);
      delete_at_position(&tail, position);
      display(tail);
      break;

    case 7:
      printf("Enter element you want to remove: ");
      scanf("%d", &data);
      delete_with_key(&tail, data);
      display(tail);
      break;

    case 0:
      free_list(tail);
      printf("Freed List. Exiting\n");
      return EXIT_SUCCESS;
    }
  }

  return EXIT_SUCCESS;
}

void insert_front(node_t **tail, int data) {
  node_t *new_node = malloc(sizeof(node_t));
  new_node->data = data;
  if (*tail == NULL) {
    *tail = new_node;
    new_node->link = new_node;
    return;
  } else {
    new_node->link = (*tail)->link;
    (*tail)->link = new_node;
    return;
  }
}

void delete_front(node_t **tail) {
  if (*tail == NULL) {
    printf("List only isn't there pa\n");
    return;
  } else if ((*tail)->link == *tail) {
    free(*tail);
    *tail = NULL;
    return;
  }
  node_t *del_ref = (*tail)->link;
  (*tail)->link = (*tail)->link->link;
  free(del_ref);
}

void display(node_t *tail) {
  if (tail == NULL) {
    printf("List Empty\n");
    return;
  }
  node_t *head_ref = tail->link;
  tail = tail->link;
  do {
    printf("%d ", tail->data);
    tail = tail->link;
  } while (tail != head_ref);

  printf("\n");
}

void insert_back(node_t **tail, int data) {
  node_t *new_node = malloc(sizeof(node_t));
  new_node->data = data;
  if (*tail == NULL) {
    *tail = new_node;
    new_node->link = new_node;
    return;
  } else {
    new_node->link = (*tail)->link;
    (*tail)->link = new_node;
    (*tail) = (*tail)->link;
  }
}

void delete_back(node_t **tail) {
  if (*tail == NULL) {
    printf("List only isn't there pa\n");
    return;
  } else if ((*tail)->link == (*tail)) {
    free(*tail);
    *tail = NULL;
  } else {
    node_t *dtail = *tail;
    while (dtail->link != *tail) {
      dtail = dtail->link;
    }
    dtail->link = (*tail)->link;
    free(*tail);
    (*tail) = dtail;
  }
}

void insert_at_position(node_t **tail, int data, int position) {
  node_t *new_node = malloc(sizeof(node_t));
  new_node->data = data;

  if ((*tail) == NULL) {
    (*tail) = new_node;
    new_node->link = NULL;
    return;
  }

  if (position == 0) {
    new_node->link = (*tail);
    (*tail) = new_node;
    return;
  }

  node_t *otail = *tail;

  for (int i = 1; i < position && (*tail)->link != NULL; i++) {
    *tail = (*tail)->link;
  }
  new_node->link = (*tail)->link;
  (*tail)->link = new_node;
  *tail = otail;
}

void delete_at_position(node_t **tail, int position) {
  if ((*tail) == NULL) {
    printf("list only isn't there pa\n");
    return;
  }

  if (position == 0) {
    node_t *temp = *tail;
    *tail = (*tail)->link;
    free(temp);
    temp = NULL;
    return;
  }

  if ((*tail)->link == NULL) {
    free(*tail);
    *tail = NULL;
  }

  node_t *otail = *tail;
  for (int i = 1; i < position && (*tail)->link->link != NULL; i++) {
    *tail = (*tail)->link;
  }
  node_t *temp = (*tail)->link;
  (*tail)->link = (*tail)->link->link;
  free(temp);
  *tail = otail;
}

void delete_with_key(node_t **tail, int key) {
  if (*tail == NULL) {
    printf("No list pa\n");
    return;
  }
  if ((*tail)->data == key) {
    delete_front(tail);
    return;
  }

  node_t *otail = *tail;
  node_t *prev = *tail;
  *tail = (*tail)->link;

  while (*tail != NULL) {
    if ((*tail)->data == key) {
      prev->link = (*tail)->link;
      free(*tail);
      *tail = otail;
      return;
    }
    prev = *tail;
    *tail = (*tail)->link;
  }
  printf("Element doesn't exist\n");
  *tail = otail;
  return;
}

void free_list(node_t *tail) {
  if (tail == NULL) {
    return;
  } else {
    node_t *head_ref = tail->link;
    tail = tail->link;
    do {
      node_t *next = tail->link;
      free(tail);
      tail = next;
    } while (tail != head_ref);
  }
}
