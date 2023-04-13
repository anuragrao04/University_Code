#include <stdio.h>
void printSize(int arr[]) { printf("printSize: %lu\n", sizeof(arr)); }

void printPointerSize(int *arr) {
  printf("printPointerSize: %lu\n", sizeof(arr));
  printf("*arr and sizeof(*arr): %d %lu\n", *arr, sizeof(*arr));
}
int main(int argc, char *argv[]) {
  int arr[] = {1, 2, 3, 4, 5};
  printSize(arr);
  printPointerSize(arr);

  return 0;
}
