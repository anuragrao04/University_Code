#include <stdio.h>
#include <stdlib.h>

int iterative_bin_search(int arr[], int size, int target);
int recursive_bin_search(int arr[], int target, int low, int high);

int main(int argc, char *argv[]) {
  int array_size, search_element;
  printf("Enter array size: ");
  scanf("%d", &array_size);
  int arr[array_size];
  printf("\nEnter elements separated by a space: ");
  for (int i = 0; i < array_size; i++) {
    scanf("%d", &arr[i]);
  }

  printf("\nEnter element to search: ");
  scanf(" %d", &search_element);

  printf("\nIteratively: \n");

  int position = iterative_bin_search(arr, array_size, search_element);
  printf("\nFound at index: %d",
         position); // position -1 means that it wasn't found

  printf("\nRecursively: \n");

  position = recursive_bin_search(arr, search_element, 0, array_size - 1);
  printf("\nFound at index: %d",
         position); // position -1 means that it wasn't found

  return EXIT_SUCCESS;
}
int iterative_bin_search(int arr[], int size, int target) {
  int low = 0;
  int high = size - 1;
  while (low <= high) {
    int mid = (low + high) / 2;
    if (arr[mid] == target) {
      return mid;
    } else if (arr[mid] < target) {
      low = mid + 1;
    } else {
      high = mid - 1;
    }
  }
  return -1;
}

int recursive_bin_search(int arr[], int target, int low, int high) {
  if (low > high) {
    return -1;
  }

  int mid = (low + high) / 2;
  if (arr[mid] == target) {
    return mid;
  } else if (arr[mid] < target) {
    return recursive_bin_search(arr, target, mid + 1, high);
  } else {
    return recursive_bin_search(arr, target, low, mid - 1);
  }
}
