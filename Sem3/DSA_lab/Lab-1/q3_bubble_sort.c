#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}

// void bubble_sort(int array[], int n) {
//   for (int i = 1; i < n; i++) {
//     for (int j = 0; j < n - 1; j++) {
//       if (array[j] > array[j + 1]) {
//         swap(&array[j], &array[j + 1]);
//       }
//     }
//   }
// }

void bubble_sort(int array[], int n) {
  for (int i = 1; i < n; i++) {
    for (int j = 0; j < n - i; j++) {
      if (array[j] > array[j + 1]) {
        swap(&array[j], &array[j + 1]);
      }
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

  bubble_sort(array, n);

  printf("Elements after sort: ");
  for (int i = 0; i < n; i++) {
    printf("%d ", array[i]);
  }
  printf("\n");

  return EXIT_SUCCESS;
}
