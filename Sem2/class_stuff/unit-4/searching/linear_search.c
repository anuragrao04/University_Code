#include <stdio.h>
#include <stdlib.h>

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

  // linear search
  int i;
  for (i = 0; i < array_size; i++) {
    if (arr[i] == search_element) {
      printf("\nElement found at index %d or position %d\n", i, i + 1);
      break;
    }
  }
  // if `i` reaches array size, it means that the entire array was traversed but
  // the element was not found
  if (i == array_size) {
    printf("\nElement not found :(\n");
  }

  return EXIT_SUCCESS;
}
