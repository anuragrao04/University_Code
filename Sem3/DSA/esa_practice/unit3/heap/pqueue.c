#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 64
void swap(int *a, int *b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}

void enqueue(int arr[], int *n, int element) {
  (*n)++;
  int i = *n - 1;
  arr[i] = element;

  while (i && arr[i] > arr[i / 2]) {
    swap(&arr[i], &arr[i / 2]);
    i = i / 2;
  }
}

void heapify(int arr[], int size, int i) {
  int largest = i;
  int left = i * 2 + 1;
  int right = i * 2 + 2;
  if (left < size && arr[left] > arr[largest]) {
    largest = left;
  }
  if (right < size && arr[right] > arr[largest]) {
    largest = right;
  }
  if (largest != i) {
    swap(&arr[largest], &arr[i]);
    heapify(arr, size, largest);
  }
}

int dequeue(int arr[], int *n) {
  if (*n == 0) {
    printf("Nothing to dequeue\n");
    return -1;
  }
  (*n)--;
  int toRet = arr[0];
  arr[0] = arr[*n];
  heapify(arr, *n, 0);
  return toRet;
}

int main(int argc, char *argv[]) {
  int choice;
  int element;
  int arr[MAXSIZE];
  int n = 0;
  while (1) {
    printf("1. Enqueue\n2. Dequeue\n0. Exit\n");
    scanf("%d", &choice);
    switch (choice) {
    case 1:
      printf("Enter element to enqueue: ");
      scanf("%d", &element);
      enqueue(arr, &n, element);
      break;
    case 2:
      printf("Dequeued element: %d\n", dequeue(arr, &n));
      break;
    case 0:
      exit(0);
    default:
      printf("Invalid choice\n");
    }
  }
  return EXIT_SUCCESS;
}
