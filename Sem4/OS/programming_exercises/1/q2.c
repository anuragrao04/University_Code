#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int compare_ints(const void *a, const void *b) {
  int int_a = *(int *)a;
  int int_b = *(int *)b;
  return int_a - int_b; // Ascending order
}

int main(int argc, char *argv[]) {
  int arr[] = {1, 6, 2, 4, 5, 8, 9, 0};

  pid_t child_pid = fork();

  if (child_pid == 0) {
    // child
    qsort(arr, 8, sizeof(int), compare_ints); // call qsort to sort
  } else {
    // parent process
    // displaying the array
    for (int i = 0; i < 8; i++) {
      printf("%d ", arr[i]);
    }
  }

  return EXIT_SUCCESS;
}
