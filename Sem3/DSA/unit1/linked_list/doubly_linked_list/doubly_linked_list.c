#include <stdio.h>
#include <stdlib.h>

typedef struct node {
  struct node *l_link;
  int data;
  struct node *r_link;
} node_t;

node_t *get_node(int data) {
  node_t *new_node = (node_t *)malloc(sizeof(node_t));
  new_node->l_link = NULL;
  new_node->r_link = NULL;
  new_node->data = data;
  return new_node;
}

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
  node_t *head = NULL;
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

void display(node_t *head) {
  if (head == NULL) {
    printf("\n\nList Empty\n\n");
    return;
  }
  printf("\n\nList: ");
  while (head != NULL) {
    printf("%d ", head->data);
    head = head->r_link;
  }
  printf("\n\n");
}

void insert_front(node_t **head, int data) {
  node_t *new_node = get_node(data);
  if (*head == NULL) {
    new_node->r_link = NULL;
    (*head) = new_node;
    return;
  }
  new_node->r_link = (*head);
  (*head)->l_link = new_node;
  (*head) = new_node;
}

void insert_back(node_t **head, int data) {
  node_t *new_node = get_node(data);
  if ((*head) == NULL) {
    *head = new_node;
    return;
  } else {
    node_t *dhead = *head;
    while (dhead->r_link != NULL) {
      dhead = dhead->r_link;
    }

    dhead->r_link = new_node;
    new_node->l_link = dhead;
    return;
  }
}

void delete_front(node_t **head) {
  if ((*head) == NULL) {
    printf("List isn't there pa\n");
    return;
  } else if ((*head)->r_link == NULL) {
    free(*head);
    *head = NULL;
    return;
  } else {
    *head = (*head)->r_link;
    free((*head)->l_link);
    (*head)->l_link = NULL;
  }
}

void delete_back(node_t **head) {
  if (*head == NULL) {
    printf("Where list pa\n");
    return;
  } else if ((*head)->r_link == NULL) {
    free(*head);
    (*head) = NULL;
    return;
  } else {
    node_t *dhead = *head;
    while (dhead->r_link->r_link != NULL) {
      dhead = dhead->r_link;
    }
    free(dhead->r_link);
    dhead->r_link = NULL;
  }
}

void insert_at_position(node_t **head, int data, int position) {
  if (*head == NULL) {
    insert_front(head, data);
    return;
  } else if (position == 0) {
    insert_front(head, data);
    return;
  } else {
    node_t *dhead = (*head);
    for (int i = 1; i < position && dhead->r_link != NULL; i++) {
      dhead = dhead->r_link;
    }
    if (dhead->r_link != NULL) {
      node_t *new_node = get_node(data);
      new_node->r_link = dhead->r_link;
      dhead->r_link->l_link = new_node;
      dhead->r_link = new_node;
      new_node->l_link = dhead;
      return;
    } else {
      insert_back(head, data);
    }
  }
}
void delete_at_position(node_t **head, int position) {}
void delete_with_key(node_t **head, int data) {}

void free_list(node_t *head) {
  while (head != NULL) {
    node_t *temp = head;
    head = head->r_link;
    free(temp);
  }
}
