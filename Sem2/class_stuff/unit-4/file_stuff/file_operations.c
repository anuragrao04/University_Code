// Q. Write a C program to perform the following operations:
// - Read the contents of the file and display the contents on stdout
// - Open a file in write mode and write contents into it from stdin
// - Read from an src file and write into destination file
// - Read the data in the form of integer using formatted input functions.
// Perform addition and write the result to a destination file
// - Open a file in read mode and display the index value using ftell() and
// appropriate character. Use fseek() to change to the 5th position and extract
// the character. Change the position again to the third character and display
// it. Finally, display the last character using fseek()

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  FILE *read_file = fopen("read_file.txt", "r");
  FILE *write_file = fopen("write_file.txt", "w");
  printf("Reading file read_file.txt...\n\n");
  char ch;

  // reading
  while ((ch = fgetc(read_file)) != EOF) {
    printf("%c", ch);
  }

  // writing
  char text_to_put[100];
  printf("\n\n reading done. Enter text to put in the write_file: ");
  fgets(text_to_put, 100, stdin);

  fprintf(write_file, "%s", text_to_put);
  printf("\n\nWritten to write_file. Moving to reading from src and pasting in "
         "dest\n");

  FILE *src_file = fopen("src_file.txt", "r");
  FILE *dest_file = fopen("dest_file.txt", "w");

  while ((ch = fgetc(src_file)) != EOF) {
    fprintf(dest_file, "%c", ch);
  }

  printf("\nPasting done\n");

  fclose(read_file);
  fclose(src_file);
  fclose(write_file);
  fclose(dest_file);
  return EXIT_SUCCESS;
}
