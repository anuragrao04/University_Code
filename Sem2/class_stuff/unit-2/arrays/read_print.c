#include <stdio.h>

void printArray(int arr[], int size) {
  printf("The contents of the array are: \n");
  for (int i = 0; i < size; i++) {
    printf("%d\n", arr[i]);
  }
}
void makeArray(int *arr, int size) {
  for (int i = 0; i < size; i++) {
    printf("Enter the integer element at index %d: ", i);
    int element;
    scanf("%d", &element);
    arr[i] = element;
  }
}

int main(int argc, char *argv[]) {
  int arr[5];
  makeArray(arr, 5);
  printArray(arr, 5);
  return 0;
}
