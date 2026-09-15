/*
Question 93
Check if two strings are anagrams of each other.
*/

#include <stdio.h>
#include <limits.h>

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
    char first[TEXT_CAPACITY + 1], second[TEXT_CAPACITY + 1];
    if (!read_line(first, sizeof first) || !read_line(second, sizeof second)) {
        return 1;
    }
    int balance[UCHAR_MAX + 1] = {0};
    for (size_t i = 0; first[i] != '\0'; ++i) {
        ++balance[(unsigned char)first[i]];
    }
    for (size_t i = 0; second[i] != '\0'; ++i) {
        --balance[(unsigned char)second[i]];
    }
    for (int ch = 0; ch <= UCHAR_MAX; ++ch) {
        if (balance[ch] != 0) {
            puts("Not anagrams");
            return 0;
        }
    }
    puts("Anagrams");
    return 0;
}
