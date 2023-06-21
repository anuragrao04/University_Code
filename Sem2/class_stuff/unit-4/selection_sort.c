#include <stdio.h>
#include <stdlib.h>

void display(int arr[], int n);
void swap(int arr[], int i, int j);

int main(int argc, char *argv[]) {
  int arr[] = {2, 8, 5, 3, 9, 4, 1};
  int n = 7;
  display(arr, n);

  // selection sort

  for (int i = 0; i < n - 1; i++) {
    int iMin = i;
    for (int j = i + 1; j < n; j++) {
      if (arr[j] < arr[iMin]) {
        iMin = j;
      }
    }

    if (iMin != i) {
      swap(arr, i, iMin);
    }
  }

  display(arr, n);
  return EXIT_SUCCESS;
}

void display(int arr[], int n) {
  for (int i = 0; i < n; i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");
}

void swap(int arr[], int i, int j) {
  int temp = arr[i];
  arr[i] = arr[j];
  arr[j] = temp;
}

// output
// 2 8 5 3 9 4 1
// 1 2 3 4 5 8 9
