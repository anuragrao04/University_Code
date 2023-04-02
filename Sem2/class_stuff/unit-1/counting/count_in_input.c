#include <stdio.h>

int main() {
    char c;
    int num_chars = 0, num_words = 0, num_lines = 0, in_word = 0;

    printf("Enter text. Press Ctrl-D (Unix) or Ctrl-Z (Windows) to finish.\n");

    while ((c = getchar()) != EOF) {
        num_chars++;

        if (c == ' ') {
            if (in_word) {
                num_words++;
                in_word = 0;
            }
            if (c == '\n') {
                num_lines++;
            }
        } else {
            in_word = 1;
        }
    }

    if (in_word) {
        num_words++;
    }
    if (num_chars > 0) {
        num_lines++;  // last line may not have a newline character
    }

    printf("\nNumber of characters: %d\n", num_chars);
    printf("Number of words: %d\n", num_words);
    printf("Number of lines: %d\n", num_lines);

    return 0;
}
