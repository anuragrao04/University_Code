#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}

void heapify_helper(int arr[], int size, int n) {
  int parent = (n - 1) / 2;
  if (arr[parent] < arr[n]) {
    swap(&arr[parent], &arr[n]);
    heapify_helper(arr, size, parent);
  }
}

void heapify(int arr[], int n) {
  for (int i = 0; i < n; i++) {
    heapify_helper(arr, n, i);
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
