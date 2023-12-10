#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 100

void enqueue(int arr[], int *n, int key);
int dequeue(int arr[], int *n);
void swap(int *a, int *b);

int main(int argc, char *argv[]) {
  int choice;
  int arr[MAXSIZE];
  int n = 0;
  int key;

  while (1) {
    printf("1. Enqueue\n2. Dequeue\n3. Print Heap\n0. Exit\n");
    scanf("%d", &choice);
    switch (choice) {
    case 1:
      printf("Enter element to enqueue: ");
      scanf("%d", &key);
      enqueue(arr, &n, key);
      break;
    case 2:
      printf("Dequeued: %d\n", dequeue(arr, &n));
      break;
    case 3:
      printf("\nHeap: ");
      for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
      }
      printf("\n");
      break;
    case 0:
      return EXIT_SUCCESS;
    }
  }

  return EXIT_SUCCESS;
}

void swap(int *a, int *b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}

void enqueue(int arr[], int *n, int key) {
  (*n)++;
  int i = *n - 1;
  arr[i] = key;

  while (i && arr[i / 2] < arr[i]) {
    swap(&arr[i / 2], &arr[i]);
    i = i / 2;
  }
}

void heapify(int arr[], int n, int i) {
  int largest = i;
  int left = 2 * i + 1;
  int right = 2 * i + 2;
  if (left < n && arr[left] > arr[largest]) {
    largest = left;
  }
  if (right < n && arr[right] > arr[largest]) {
    largest = right;
  }

  if (largest != i) {
    swap(&arr[largest], &arr[i]);
    heapify(arr, n, largest);
  }
}

int dequeue(int arr[], int *n) {
  if (*n == 0) {
    printf("\n\nNothing to dequeue\n");
    return -1;
  }

  int ret = arr[0];
  arr[0] = arr[--(*n)];
  heapify(arr, *n, 0);
  return ret;
}
