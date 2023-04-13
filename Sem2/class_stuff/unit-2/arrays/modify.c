#include <stdio.h>

void modifyArray(int *arr) {
  printf("Enter index to modify (0 <= index <= 5): ");
  int i = 0;
  scanf("%d", &i);
  printf("Enter new element at index %d: ", i);
  int element = 0;
  scanf("%d", &element);
  arr[i] = element;
  printf("\n Array modified");
}

void printArray(int arr[], int size) {
  printf("\nThe contents of the array are: \n");
  for (int i = 0; i < size; i++) {
    printf("%d\n", arr[i]);
  }
}

int main(int argc, char *argv[]) {
  int arr[] = {1, 2, 3, 4, 5};
  modifyArray(arr);
  printArray(arr, 5);
  return 0;
}
