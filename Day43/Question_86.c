/*
Question 86
Check if a string is a palindrome.
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
    for (size_t i = 0; i < length / 2; ++i) {
        if (text[i] != text[length - 1 - i]) {
            puts("Not palindrome");
            return 0;
        }
    }
    puts("Palindrome");
    return 0;
}
