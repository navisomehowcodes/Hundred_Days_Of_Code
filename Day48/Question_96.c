/*
Question 96
Reverse each word in a sentence without changing the word order.
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
    size_t i = 0;
    while (text[i] != '\0') {
        if (isspace((unsigned char)text[i])) {
            putchar((unsigned char)text[i++]);
        } else {
            size_t start = i;
            while (text[i] != '\0' && !isspace((unsigned char)text[i])) ++i;
            for (size_t end = i; end > start; --end) {
                putchar((unsigned char)text[end - 1]);
            }
        }
    }
    putchar('\n');
    return 0;
}
