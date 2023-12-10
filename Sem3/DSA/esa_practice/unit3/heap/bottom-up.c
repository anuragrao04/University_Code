#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}

void heapify_helper(int arr[], int size, int i) {
  int largest = i;
  int left = 2 * i + 1;
  int right = 2 * i + 2;
  if (left < size && arr[largest] < arr[left]) {
    largest = left;
  }
  if (right < size && arr[largest] < arr[right]) {
    largest = right;
  }
  if (largest != i) {
    swap(&arr[largest], &arr[i]);
    heapify_helper(arr, size, largest);
  }
}

void heapify(int arr[], int size) {
  for (int i = size / 2 - 1; i >= 0; i--) {
    heapify_helper(arr, size, i);
  }
}

int main(int argc, char *argv[]) {
  int n;
  printf("Enter the number of elements: ");
  scanf("%d", &n);
  int arr[n];

  printf("Enter the elements: ");
  for (int i = 0; i < n; i++) {
    scanf("%d", &arr[i]);
  }
  heapify(arr, n);
  printf("The heap is: ");
  for (int i = 0; i < n; i++) {
    printf("%d ", arr[i]);
  }
  return EXIT_SUCCESS;
}
