/*
Question 120
Write a program to take a string input. Change it to sentence case.
*/

#include <stdio.h>
#include <string.h>
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

int main(int argc, char *argv[])
{
    /* The examples capitalize every word. --sentence selects the statement's rule. */
    int sentence_mode = argc == 2 && strcmp(argv[1], "--sentence") == 0;
    if (argc > 1 && !sentence_mode) return 1;
    char text[TEXT_CAPACITY + 1];
    if (!read_line(text, sizeof text)) {
        return 1;
    }
    char *s = strncmp(text, "str = ", 6) == 0 ? text + 6 : text;
    int capitalize = 1;
    for (; *s != '\0'; ++s) {
        unsigned char ch = (unsigned char)*s;
        if (isalpha(ch)) {
            putchar(capitalize ? toupper(ch) : tolower(ch));
            capitalize = 0;
        } else {
            putchar(ch);
            if (sentence_mode) {
                if (ch == '.' || ch == '!' || ch == '?') capitalize = 1;
            } else if (isspace(ch)) {
                capitalize = 1;
            }
        }
    }
    putchar('\n');
    return 0;
}
