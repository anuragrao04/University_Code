#include <stdio.h>
#include <stdlib.h>

typedef struct node {
  int data;
  struct node *link;
} node_t;

typedef struct list {
  node_t *head;
} list_t;

void init(list_t *listv);

int main(int argc, char *argv[]) {
  list_t listv;
  init(&listv);

  if (listv.head == NULL) {
    printf("List is empty");
  }

  return EXIT_SUCCESS;
}

void init(list_t *listv) { listv->head = NULL; }
