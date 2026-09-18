/*
Question 100
Print all sub-strings of a string.
*/

#include <stdio.h>
#include <string.h>

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
    size_t length = strlen(text);
    for (size_t start = 0; start < length; ++start) {
        for (size_t count = 1; count <= length - start; ++count) {
            if (start != 0 || count != 1) {
                putchar(',');
            }
            fwrite(text + start, 1, count, stdout);
        }
    }
    putchar('\n');
    return 0;
}
