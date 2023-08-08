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
  for (int i = 0; i <= my_strlen(str2); i++) {
    str1[i] = str2[i];
  }
}

int my_strcmp(char str1[], char str2[]) {
  for (int i = 0; i < my_strlen(str2); i++) {
    if (str1[i] != str2[i]) {
      return str1[i] - str2[i];
    }
  }
  return 0;
}

char *my_strchr(char str[], char ch) {
  while (*str != '\0') {
    if (*str == ch) {
      return str;
    }
    str++;
  }
  return NULL;
}

char *my_strcat(char str1[], char str2[]) {
  int len = my_strlen(str1);
  int len2 = my_strlen(str2);
  int counter;
  for (int i = len; i <= len + len2; i++) {
    str1[i] = str2[counter];
    counter++;
  }
  return str1;
}

int main(int argc, char *argv[]) {
  char str1[] = "hello\n";
  char str2[] = "world\n";
  printf("%d", my_strcmp(str1, str2));
}
