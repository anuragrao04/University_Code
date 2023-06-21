#include <stdio.h>
#include <stdlib.h>

int mul_69(int n) { return 69 * n; }

void map(int arr[], int size, int (*p)(int n)) {
  int counter = 0;
  for (int i = 0; i < size; i++) {
    arr[i] = p(arr[i]);
    counter++;
  }
  return counter;
}

int main(int argc, char *argv[]) {

  int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  int size = 10;
  for (int i = 0; i < size; i++) {
    printf("%d ", arr[i]);
  }

  printf("\n");
  printf("After map: \n");

  map(arr, size, mul_69);

  for (int i = 0; i < size; i++) {
    printf("%d ", arr[i]);
  }

  printf("\n");

  return EXIT_SUCCESS;
}
