#include <stdio.h>

void swap_elements(int *arr, int size) {
  int temp = arr[size - 1];
  arr[size - 1] = arr[0];
  arr[0] = temp;
}

void printArray(int arr[], int size) {
  printf("\nThe contents of the array after swapping are: \n");
  for (int i = 0; i < size; i++) {
    printf("%d\n", arr[i]);
  }
}

int main(int argc, char *argv[]) {
  int arr[5] = {1, 2, 3, 4, 5};
  swap_elements(arr, 5);
  printArray(arr, 5);
  return 0;
}
