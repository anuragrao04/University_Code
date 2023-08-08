#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}

void selection_sort(int array[], int n) {
  for (int i = 0; i < n - 1; i++) {
    int iMin = i;
    for (int j = i; j < n; j++) {
      if (array[iMin] > array[j]) {
        iMin = j;
      }
    }

    if (iMin != i) {
      swap(&array[iMin], &array[i]);
    }
  }
}
int main(int argc, char *argv[]) {

  int n;
  printf("Enter array size: ");
  scanf("%d", &n);

  int array[n];

  printf("Enter the elements of the array separated by a space: ");
  for (int i = 0; i < n; i++) {
    scanf("%d", &array[i]);
  }

  printf("Elements before sort: ");
  for (int i = 0; i < n; i++) {
    printf("%d ", array[i]);
  }
  printf("\n");

  selection_sort(array, n);

  printf("Elements after sort: ");
  for (int i = 0; i < n; i++) {
    printf("%d ", array[i]);
  }
  printf("\n");

  return EXIT_SUCCESS;
}
