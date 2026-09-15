/*
Question 94
Find the longest word in a sentence.
*/

#include <stdio.h>
#include <ctype.h>

enum { TEXT_CAPACITY = 4096 };

/* Read one complete line, preserving spaces and excluding the line ending. */
static int read_line(char text[], size_t size)
{
    size_t length = 0;
    int ch;
    while ((ch = getchar()) != EOF && ch != '\n') {
        if (length + 1 >= size) {
            return 0;
        }
        text[length++] = (char)ch;
    }
    text[length] = '\0';
    return !ferror(stdin) && (length > 0 || ch == '\n');
}

int main(void)
{
    char text[TEXT_CAPACITY + 1];
    if (!read_line(text, sizeof text)) {
        return 1;
    }
    size_t best_start = 0, best_length = 0, i = 0;
    while (text[i] != '\0') {
        while (isspace((unsigned char)text[i])) ++i;
        size_t start = i;
        while (text[i] != '\0' && !isspace((unsigned char)text[i])) ++i;
        if (i - start > best_length) {
            best_start = start;
            best_length = i - start;
        }
    }
    fwrite(text + best_start, 1, best_length, stdout);
    putchar('\n');
    return 0;
}
