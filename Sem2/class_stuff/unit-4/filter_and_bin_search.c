#include <stdio.h>
#include <stdlib.h>

void binary_search(int a[], int low, int high, int key);
int filter(int a[], int (*p)(int i));
int isEven(int i);
int isUnder22(int i);

int main(int argc, char *argv[]) {
  int a[] = {11, 13, 16, 18, 21, 24, 28, 34, 39, 64};
  int b[] = {11, 13, 16, 18, 21, 24, 28, 34, 39, 64};
  int s_a;
  int s_b;
  s_a = filter(a, isEven);
  s_b = filter(b, isUnder22);

  for (int i = 0; i < s_a; i++) {
    printf("%d ", a[i]);
  }
  printf("\n");
  for (int i = 0; i < s_b; i++) {
    printf("%d ", b[i]);
  }

  int search_a;
  int search_b;
  printf("\nEnter search for even numbers: ");
  scanf("%d", &search_a);
  binary_search(a, 0, s_a, search_a);
  printf("\nEnter search for numbers under 22: ");
  scanf("%d", &search_b);
  binary_search(b, 0, s_b, search_b);
  return EXIT_SUCCESS;
}

int isEven(int i) { return i % 2 == 0; }
int isUnder22(int i) { return i < 22; }

int filter(int a[], int (*p)(int i)) {
  int counter = 0;
  for (int j = 0; j < 10; j++) {
    if (p(a[j])) {
      a[counter] = a[j];
      counter++;
    }
  }
  return counter;
}

void binary_search(int a[], int low, int high, int key) {
  if (low <= high) {
    int mid = low + (high - low) / 2;
    if (a[mid] == key) {
      printf("Element found at index %d\n", mid);
    } else if (a[mid] < key) {
      binary_search(a, mid + 1, high, key);
    } else {
      binary_search(a, low, mid - 1, key);
    }
  } else {
    printf("\nElement not found\n");
  }
}
