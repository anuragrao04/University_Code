#include <stdio.h>
#include <stdlib.h>

typedef struct node {
  int data;
  struct node *link;
} node_t;

typedef struct box {
  struct node *head;
} box_t;

void insert_front(box_t *box, int data);
void insert_back(box_t *box, int data);
void delete_front(box_t *box);
void delete_back(box_t *box);
void insert_at_position(box_t *box, int data, int position);
void delete_at_position(box_t *box, int position);
void delete_with_key(box_t *box, int data);
void display(node_t *head);
void free_list(node_t *head);

int main(int argc, char *argv[]) {
  node_t *head = NULL; // No list exists yet
  box_t box = {head};
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
      insert_front(&box, data);
      display(head);
      break;

    case 2:
      printf("Enter data: ");
      scanf("%d", &data);
      insert_back(&box, data);
      display(head);
      break;

    case 3:
      delete_front(&box);
      display(head);
      break;

    case 4:
      delete_back(&box);
      display(head);
      break;

    case 5:
      printf("Enter data: ");
      scanf("%d", &data);
      printf("Enter position (0 indexed): ");
      scanf("%d", &position);
      insert_at_position(&box, data, position);
      display(head);
      break;

    case 6:
      printf("Enter position (0 indexed): ");
      scanf("%d", &position);
      delete_at_position(&box, position);
      display(head);
      break;

    case 7:
      printf("Enter element you want to remove: ");
      scanf("%d", &data);
      delete_with_key(&box, data);
      display(box.head);
      break;

    case 0:
      free_list(box.head);
      printf("Freed List. Exiting\n");
      return EXIT_SUCCESS;
    }
  }

  return EXIT_SUCCESS;
}

void insert_front(box_t *box, int data) {
  node_t *new_node = malloc(sizeof(node_t));
  new_node->data = data;
  new_node->link = box->head;
  box->head = new_node;
}

void delete_front(box_t *box) {
  if (box->head == NULL) {
    printf("List only isn't there pa\n");
    return;
  }
  node_t *temp = box->head->link;
  free(box->head);
  box->head = temp;
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

void insert_back(box_t *box, int data) {
  node_t *new_node = malloc(sizeof(node_t));
  new_node->data = data;

  if (box->head == NULL) {
    box->head = new_node;
    new_node->link = NULL;
    return;
  } else {
    node_t *ohead = box->head;
    while (box->head->link != NULL) {
      box->head = box->head->link;
    }
    box->head->link = new_node;
    new_node->link = NULL;
    box->head = ohead;
  }
}

void delete_back(box_t *box) {
  if (box->head == NULL) {
    printf("List only isn't there pa\n");
    return;
  } else if (box->head->link == NULL) {
    free(box->head);
    box->head = NULL;
  } else {
    node_t *ohead = box->head;
    while (box->head->link->link != NULL) {
      box->head = box->head->link;
    }
    free(box->head->link);
    box->head->link = NULL;
    box->head = ohead;
  }
}

void insert_at_position(box_t *box, int data, int position) {
  node_t *new_node = malloc(sizeof(node_t));
  new_node->data = data;

  if (box->head == NULL) {
    box->head = new_node;
    new_node->link = NULL;
    return;
  }

  if (position == 0) {
    new_node->link = box->head;
    box->head = new_node;
    return;
  }

  node_t *ohead = box->head;

  for (int i = 1; i < position && box->head->link != NULL; i++) {
    box->head = box->head->link;
  }
  new_node->link = box->head->link;
  box->head->link = new_node;
  box->head = ohead;
}

void delete_at_position(box_t *box, int position) {
  if (box->head == NULL) {
    printf("list only isn't there pa\n");
    return;
  }

  if (position == 0) {
    node_t *temp = box->head;
    box->head = box->head->link;
    free(temp);
    temp = NULL;
    return;
  }

  if (box->head->link == NULL) {
    free(box->head);
    box->head = NULL;
  }

  node_t *ohead = box->head;
  for (int i = 1; i < position && box->head->link->link != NULL; i++) {
    box->head = box->head->link;
  }
  node_t *temp = box->head->link;
  box->head->link = box->head->link->link;
  free(temp);
  box->head = ohead;
}

void delete_with_key(box_t *box, int key) {
  if (box->head == NULL) {
    printf("No list pa\n");
    return;
  }
  if (box->head->data == key) {
    delete_front(box);
    return;
  }

  node_t *ohead = box->head;

  node_t *prev = box->head;
  box->head = box->head->link;

  while (box->head != NULL) {
    if (box->head->data == key) {
      prev->link = box->head->link;
      free(box->head);
      box->head = ohead;
      return;
    }
    prev = box->head;
    box->head = box->head->link;
  }
  printf("Element doesn't exist\n");
  box->head = ohead;
  return;
}

void free_list(node_t *head) {
  while (head != NULL) {
    node_t *next = head->link;
    free(head);
    head = next;
  }
}
