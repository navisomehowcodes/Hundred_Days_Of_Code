/*
Question 114
Write a program to take a string s as input. The task is to find the length of the longest substring without repeating characters. Print the length as output.
*/

#include <stdio.h>
#include <string.h>
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

/* Point into the next quoted string, terminating it at its closing quote. */
static char *next_quoted(char **cursor)
{
    char *opening = strchr(*cursor, '"');
    if (!opening) return NULL;
    char *end = strchr(opening + 1, '"');
    if (!end) return NULL;
    *end = '\0';
    *cursor = end + 1;
    return opening + 1;
}

int main(void)
{
    char text[TEXT_CAPACITY + 1];
    if (!read_line(text, sizeof text)) {
        return 1;
    }
    char *s = text;
    if (strchr(text, '"')) {
        char *cursor = text;
        s = next_quoted(&cursor);
        if (!s) return 1;
    }
    int last_plus_one[UCHAR_MAX + 1] = {0};
    int start = 0, longest = 0;
    for (int i = 0; s[i] != '\0'; ++i) {
        unsigned char ch = (unsigned char)s[i];
        if (last_plus_one[ch] > start) start = last_plus_one[ch];
        int length = i - start + 1;
        if (length > longest) longest = length;
        last_plus_one[ch] = i + 1;
    }
    printf("%d\n", longest);
    return 0;
}
