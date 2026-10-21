/*
Question 123
Read a text file and count the total number of characters, words, and lines. A word is defined as a sequence of non-space characters separated by spaces or newlines.
*/

#include <stdio.h>
#include <ctype.h>

int main(int argc, char *argv[])
{
    const char *path = argc > 1 ? argv[1] : "sample.txt";
    FILE *input = fopen(path, "r");
    if (input == NULL) {
        perror(path);
        return 1;
    }
    unsigned long long characters = 0, words = 0, lines = 0;
    int ch, previous = '\n', in_word = 0;
    while ((ch = fgetc(input)) != EOF) {
        ++characters;
        if (ch == '\n') ++lines;
        if (isspace(ch)) {
            in_word = 0;
        } else if (!in_word) {
            ++words;
            in_word = 1;
        }
        previous = ch;
    }
    if (previous != '\n') ++lines;
    int failed = ferror(input);
    if (fclose(input) != 0 || failed) return 1;
    printf("Characters: %llu\nWords: %llu\nLines: %llu\n", characters, words, lines);
    return 0;
}
