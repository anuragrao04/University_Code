#include <stdio.h>
#include <stdlib.h>

void heapify(int *arr, int i);

int main(int argc, char *argv[]) {

  int n;
  printf("Size: ");
  scanf("%d", &n);
  int arr[n];

  printf("Elements: ");
  for (int i = 0; i < n; i++) {
    scanf("%d", &arr[i]);
  }

  heapify(arr, n);

  printf("Arr after heapifying: ");
  for (int i = 0; i < n; i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");

  return EXIT_SUCCESS;
}

void swap(int *a, int *b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}

void heapify_slave(int *arr, int i) {
  int parent_index = (i - 1) / 2;
  if (arr[i] > arr[parent_index]) {
    swap(&arr[i], &arr[parent_index]);
    heapify_slave(arr, parent_index);
  }
}

void heapify(int *arr, int n) {
  for (int i = 0; i < n; i++) {
    heapify_slave(arr, i);
  }
}
