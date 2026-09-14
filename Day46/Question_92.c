/*
Question 92
Find the first repeating lowercase alphabet in a string.
*/

#include <stdio.h>

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
    int frequency[26] = {0};
    for (size_t i = 0; text[i] != '\0'; ++i) {
        if (text[i] >= 'a' && text[i] <= 'z') {
            ++frequency[text[i] - 'a'];
        }
    }
    for (size_t i = 0; text[i] != '\0'; ++i) {
        if (text[i] >= 'a' && text[i] <= 'z' && frequency[text[i] - 'a'] > 1) {
            printf("%c\n", text[i]);
            return 0;
        }
    }
    puts("-1");
    return 0;
}
