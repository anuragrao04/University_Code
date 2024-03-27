#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
  int srn;
  char name[64];
  struct node *next;
} node_t;

typedef struct hashtable {
  node_t **arr;
  int size;
} hash_t;

int getHash(int srn) { return srn % 10; } // hash function

void insert(hash_t *hashTable, int srn, char *name) {
  int index = getHash(srn);
  node_t *new_node = (node_t *)malloc(sizeof(node_t));
  new_node->srn = srn;
  strcpy(new_node->name, name); // put name into the node
  new_node->next = hashTable->arr[index];
  hashTable->arr[index] = new_node;
}

int search(hash_t *hashTable, int srn, char *name) {
  int index = getHash(srn);
  node_t *current = hashTable->arr[index];
  while (current != NULL) { // traverse through the linked list
    if (current->srn == srn) {
      strcpy(name, current->name); // if found, you can't return a string, so
                                   // you copy it to the arg
      return 1;                    // 1 means that it was found
    }
    current = current->next;
  }
  return 0;
}

int delete(hash_t *hashTable, int srn) {
  // this is a lil similar to search.
  int index = getHash(srn);
  int found = 0;
  node_t *current = hashTable->arr[index]; // current and previ
  node_t *previ = NULL;
  while (current != NULL) {
    if (current->srn == srn) {
      found = 1;
      break;
    }
    previ = current;
    current = current->next;
  }
  if (found) {
    if (previ == NULL) {
      // this condition is true when you have to update head itself.
      // cases when you need to delete the first element
      node_t *temp = hashTable->arr[index]->next;
      free(hashTable->arr[index]);
      hashTable->arr[index] = temp;
      return 1;
    }
    // if previ is not null, aka previ has changed.
    previ->next = current->next;
    free(current);
    current = NULL;
    return 1;
  } else {
    // when you didn't find the element you want to delete
    return 0;
  }
}

void display(hash_t *hashTable) {
  for (int i = 0; i < hashTable->size; i++) {
    printf("%d ", i); // every index in the hashtable
    for (node_t *current = hashTable->arr[i]; current != NULL;
         current = current->next) {
      // traverse through the linked list using your fav for loop
      printf("->%d", current->srn);
    }
    printf("\n"); // new line for every new index
  }
} // this might come since I remember sir had done this function in class
// it just displays the hashtable and lists

int main(int argc, char *argv[]) {
  printf("Enter hash table size: ");
  int size;
  scanf("%d", &size);
  hash_t hashTable;
  hashTable.arr = (node_t **)malloc(sizeof(node_t *));
  for (int i = 0; i < size; i++) {
    hashTable.arr[i] = NULL;
  } // make sure to make all hashTable arr values as NULL. you might have this
    // in an init hashTable func
  hashTable.size = size;
  int choice;
  while (1) {
    printf("1. Insert\n2. Search\n3. Delete\n4. Display\n0. Exit\n");
    scanf("%d", &choice);
    switch (choice) {
    case 1:
      printf("Enter SRN: ");
      int srn;
      scanf("%d", &srn);
      printf("Enter name: ");
      char name[64];
      scanf("%s", name);
      insert(&hashTable, srn, name);
      break;
    case 2:
      printf("Enter SRN: ");
      scanf("%d", &srn);
      if (search(&hashTable, srn, name)) {
        // remember search returns if it was found or not
        printf("Found %s with srn %d\n", name, srn);
      } else {
        printf("Not found :(\n");
      }
      break;
    case 3:
      // similar to search
      printf("Enter SRN: ");
      scanf("%d", &srn);
      if (delete (&hashTable, srn)) {
        printf("Deleted srn %d\n", srn);
      } else {
        printf("Not found :(\n");
      }

      break;
    case 4:
      display(&hashTable);
      break;
    case 0:
      exit(0);
    }
  }
  return EXIT_SUCCESS;
}
int delete(hash_t *hashTable, int srn) {
  int index = getHash(srn);
  node_t *curr = hashTable->arr[index];
  node_t *prev = NULL;

  // imagine the element you want to delete is the first element. So your linked
  // list is like this:
  // -> 209 -> 29 -> 19. Delete 209.
  while (curr != NULL) {
    if (curr->srn == srn) { // prev will still be null.  you gotta point head to
                            // the next element.
      // but you named head as current
      if (prev == NULL) {
        node_t *temp = current;
        current =
            current
                ->ptr; // but now you lost the reference to current. have temp!
        free(temp);
        return 1; // because you're done deleting
      }

      prev->ptr =
          curr->ptr; // if you're deleting something like 29, prev will be 209,
      free(curr);    // 209 ka next should be 29 ka next, aka 19, and you free
                     // current. no probs here
      return 1;      // because you're done deleting
    }
    curr = curr->ptr;
  }
  // if you reach here, then you haven't found your shit
  return 0; // ashte over delete
}
