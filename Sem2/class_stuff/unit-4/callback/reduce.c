#include <stdio.h>
#include <stdlib.h>

int func(int a, int b) { return a * b; }

int reduce(int arr[], int size, int (*f)(int a, int b));

int main(int argc, char *argv[]) {

  int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  int size = 10;
  for (int i = 0; i < size; i++) {
    printf("%d ", arr[i]);
  }

  printf("\n");

  printf("%d\n", reduce(arr, size, func));

  return EXIT_SUCCESS;
}

int reduce(int arr[], int size, int (*f)(int a, int b)) {
  int result = arr[0];
  for (int j = 1; j < size; j++) {
    result = f(result, arr[j]);
  }
  return result;
}
