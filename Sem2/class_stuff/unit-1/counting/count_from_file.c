#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    FILE *fp = fopen(argv[1], "r");
    if (fp == NULL) {
        printf("Error: cannot open file '%s'\n", argv[1]);
        return 1;
    }

    char c;
    int num_chars = 0, num_words = 0, num_lines = 0, in_word = 0;

    while ((c = fgetc(fp)) != EOF) {
        num_chars++;

        if (isspace(c)) {
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

    printf("Number of characters: %d\n", num_chars);
    printf("Number of words: %d\n", num_words);
    printf("Number of lines: %d\n", num_lines);

    fclose(fp);
    return 0;
}
