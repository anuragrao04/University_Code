#include <stdio.h>
#include <stdlib.h>

typedef struct node {
  int data;
  struct node *link;
} node_t;

void display_list(node_t *head) {
  while (head != NULL) {
    printf("%d ", head->data);
    head = head->link;
  }
  printf("\n");
}

int main(int argc, char *argv[]) {
  node_t *head = malloc(sizeof(node_t));
  node_t *second_node = malloc(sizeof(node_t));

  head->data = 1;
  head->link = second_node;
  second_node->data = 2;
  second_node->link = NULL;
  display_list(head);
  return EXIT_SUCCESS;
}
