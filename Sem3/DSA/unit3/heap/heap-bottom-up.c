#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}

void heapify(int *arr, int n) {
  int k, largest, left, right;
  for (int i = n / 2 - 1; i >= 0; i--) {
    k = i;
    while (1) {
      largest = k;
      left = 2 * k + 1;
      right = 2 * k + 2;

      if (left < n && arr[left] > arr[largest]) {
        largest = left;
      }
      if (right < n && arr[right] > arr[largest]) {
        largest = right;
      }
      if (largest == k) {
        break;
      }
      swap(&arr[largest], &arr[k]);
      k = largest;
    }
  }
}

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
