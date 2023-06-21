#include <stdio.h>
#include <stdlib.h>

int is_69_420(int n) { return n == 69 || n == 420; }

int filter(int arr[], int size, int (*f)(int n)) {
  int counter = 0;
  for (int i = 0; i < size; i++) {
    if (f(arr[i])) {
      arr[counter] = arr[i];
      counter++;
    }
  }
  return counter;
}

int main(int argc, char *argv[]) {
  int arr[] = {1, 2, 69, 4, 420, 6, 7, 69, 9, 10};
  int size = 10;
  for (int i = 0; i < size; i++) {
    printf("%d ", arr[i]);
  }

  printf("\n");
  printf("After filter: \n");

  size = filter(arr, size, is_69_420);

  for (int i = 0; i < size; i++) {
    printf("%d ", arr[i]);
  }

  printf("\n");

  return EXIT_SUCCESS;
}
