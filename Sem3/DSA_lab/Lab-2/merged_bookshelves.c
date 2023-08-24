#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct BookNode {
  char title[100];
  struct BookNode *next;
} BookNode;

BookNode *createBook(const char *bookTitle) {
  BookNode *newBook = (BookNode *)malloc(sizeof(BookNode));
  strcpy(newBook->title, bookTitle);
  newBook->next = NULL;
  return newBook;
}

BookNode *insertSorted(BookNode *node, BookNode *shelf) {
  if (strcmp(node->title, shelf->title) < 0) {
    node->next = shelf;
    shelf = node;
    return shelf;
  }
  BookNode *oshelf = shelf;
  while (shelf->next != NULL) {
    if (strcmp(shelf->next->title, node->title) > 0) {
      node->next = shelf->next;
      shelf->next = node;
      return oshelf;
    }
    shelf = shelf->next;
  }
  shelf->next = node;
  node->next = NULL;
  return oshelf;
}

BookNode *mergeBookshelves(BookNode *shelf1, BookNode *shelf2) {

  if (shelf1 == NULL) {
    return shelf2;
  }
  if (shelf2 == NULL) {
    return shelf1;
  }

  BookNode *dshelf1 = shelf1;

  int found = 0;
  while (shelf2 != NULL) {
    found = 0;
    while (dshelf1 != NULL) {
      if (strcmp(dshelf1->title, shelf2->title) == 0) {
        found = 1;
        break;
      }
      dshelf1 = dshelf1->next;
    }
    if (!found) {
      BookNode *newBook = createBook(shelf2->title);
      shelf1 = insertSorted(newBook, shelf1);
    }
    dshelf1 = shelf1;
    shelf2 = shelf2->next;
  }
  return shelf1;
}

void displayMergedBookshelf(BookNode *start) {
  BookNode *current = start;
  while (current) {
    printf("%s - ", current->title);
    current = current->next;
  }
}

// Driver code
int main() {
  int emmaCount, oliviaCount;
  scanf("%d %d", &emmaCount, &oliviaCount);
  BookNode *emmaShelf = NULL, *oliviaShelf = NULL, *temp = NULL;
  char bookTitle[100];

  if (emmaCount > 0) {
    scanf("%s", bookTitle);
    emmaShelf = createBook(bookTitle);
    temp = emmaShelf;
    for (int i = 1; i < emmaCount; i++) {
      scanf("%s", bookTitle);
      temp->next = createBook(bookTitle);
      temp = temp->next;
    }
  }
  if (oliviaCount > 0) {
    scanf("%s", bookTitle);
    oliviaShelf = createBook(bookTitle);
    temp = oliviaShelf;
    for (int i = 1; i < oliviaCount; i++) {
      scanf("%s", bookTitle);
      temp->next = createBook(bookTitle);
      temp = temp->next;
    }
  }

  BookNode *mergedBookshelf = mergeBookshelves(emmaShelf, oliviaShelf);
  displayMergedBookshelf(mergedBookshelf);
  return 0;
}
