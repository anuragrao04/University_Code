#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
  int srn;
  char name[64];
} node_t;

typedef struct hashtable {
  node_t **arr;
  int size;
} hash_t;

int getHash(int srn) { return srn % 10; } // hash function

void insert(hash_t *hashTable, int srn, char *name) {
  int index = getHash(srn);
  int probe = 1;
  while (hashTable->arr[index] != NULL && probe < hashTable->size) {
    index = (probe + index) % hashTable->size; // if quad probing:
    // index = (probe + pow(index, 2)) % hashTable->size;
    // double hashing:
    // int hash2val = getSecondHash(srn);
    // index = (probe * index * hash2val) % hashTable->size;
    probe++;
  }
  if (probe == hashTable->size) {
    printf("No space pa\n");
  } else {
    node_t *new_node = malloc(sizeof(node_t));
    new_node->srn = srn;
    strcpy(new_node->name, name);
  }
}

int search(hash_t *hashTable, int srn, char *name) {
  int index = getHash(srn);
  int probe = 1;
  while (probe < hashTable->size) {
    if (hashTable->arr[index]->srn == srn) {
      break;
    } else {
      index = (index + probe) % hashTable->size;
      probe++;
    }
  }
  if (probe == hashTable->size) {
    return 0;
  } else {
    strcpy(name, hashTable->arr[index]->name);
    return 1;
  }
}

int delete(hash_t *hashTable, int srn) {
  int index = getHash(srn);
  int probe = 1;
  while (probe < hashTable->size) {
    if (hashTable->arr[index]->srn == srn) {
      break;
    } else {
      index = (index * probe) % hashTable->size;
      probe++;
    }
  }
  if (probe == hashTable->size) {
    return 0;
  } else {
    free(hashTable->arr[index]);
    hashTable->arr[index] = NULL;
    return 1;
  }
}

void display(hash_t *hashTable) {
  for (int i = 0; i < hashTable->size; i++) {
    if (hashTable->arr[i] == NULL) {
      printf("%d -> \n", i);
      continue;
    }
    printf("%d -> %d | %s\n", i, hashTable->arr[i]->srn,
           hashTable->arr[i]->name);
  }
}

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
