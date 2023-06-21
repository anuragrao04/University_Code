#include <stdio.h>
#include <stdlib.h>

typedef struct {
  int a;
  int b;
  int c;
} some_struct_t;

void display(some_struct_t *s[], int size);
void swap(some_struct_t **s1,
          some_struct_t **s2); // double pointer because we'd be passing an
                               // address of an address. why? because we gotta
                               // swap, so we need the address of the pointer in
                               // the array, which is also an address

int main(int argc, char *argv[]) {
  some_struct_t some_array[] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
  some_struct_t *array_of_ptr[3]; // this will contain the pointers
  for (int i = 0; i < 3; i++) {
    array_of_ptr[i] = &some_array[i]; // assigning the pointers
  }

  printf("Before swap: \n");
  display(array_of_ptr, 3);

  swap(&array_of_ptr[0], &array_of_ptr[2]); // swapping first and last

  printf("After swap: \n");
  display(array_of_ptr, 3);

  return EXIT_SUCCESS;
}

void display(some_struct_t *s[], int size) {
  for (int i = 0; i < size; i++) {
    printf("%d %d %d\n", s[i]->a, s[i]->b, s[i]->c);
  }
}

void swap(some_struct_t **s1, some_struct_t **s2) {
  some_struct_t *temp = *s1;
  *s1 = *s2;
  *s2 = temp;
}
