#include <stdio.h>
#include <string.h>
#define EXIT_SUCCESS 0;

int main(int argc, char *argv[]) {
  char str1[100], str2[100];
  printf("Enter string1: ");
  scanf("%s", str1);

  printf("Enter string2: ");
  scanf("%s", str2);

  if (!strcmp(str1, str2)) {
    printf("\nEqual\n");
  } else {
    printf("\nNot Equal\n");
  }

  return EXIT_SUCCESS;
}
