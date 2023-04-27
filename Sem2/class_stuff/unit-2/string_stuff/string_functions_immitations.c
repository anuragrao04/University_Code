#include <stdio.h>
#include <string.h>

int my_strlen(char str[]) {
  int counter = 0;
  while (str[counter] != '\0') {
    counter++;
  }
  return counter;
}

void my_strcpy(char str1[], char str2[]) {
  for (int i = 0; i < my_strlen(str2); i++) {
    str1[i] = str2[i];
  }
  str1[strlen(str2)] = '\0';
}

int my_strcmp(char str1[], char str2[]) {
  int counter = 0;
  for (int i = 0; i < my_strlen(str2); i++) {
    counter += str1[i] - str2[i];
  }
  return counter;
}

char *my_strchr(char str[], char ch) {
  for (int i = 0; i < my_strlen(str); i++) {
    if (*str == ch) {
      return str;
    }
    str++;
  }
  return NULL;
}

char *my_strcat(char str1[], char str2[]) {
  int len = my_strlen(str1);
  int index = len;
  for (int i = 0; i < my_strlen(str2); i++) {
    str1[index] = str2[i];
    index++;
  }
  str1[index] = '\0';
  return str1;
}

int main(int argc, char *argv[]) {
  char str1[] = "hello\n";
  char str2[] = "world\n";
  printf("%d", my_strcmp(str1, str2));
}
