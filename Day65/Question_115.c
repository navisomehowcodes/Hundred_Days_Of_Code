/*
Question 115
Write a program to take two strings s and t as inputs (assume all characters are lowercase). The task is to determine if s and t are valid anagrams, meaning they contain the same characters with the same frequencies. Print "Anagram" if they are, otherwise "Not Anagram".
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
    char line[TEXT_CAPACITY + 1], second_line[TEXT_CAPACITY + 1];
    if (!read_line(line, sizeof line)) return 1;
    char *first = line, *second = second_line;
    if (strchr(line, '"')) {
        char *cursor = line;
        first = next_quoted(&cursor);
        second = next_quoted(&cursor);
        if (!first || !second) return 1;
    } else if (!read_line(second_line, sizeof second_line)) {
        return 1;
    }
    int balance[26] = {0};
    for (size_t i = 0; first[i] != '\0'; ++i) {
        if (first[i] < 'a' || first[i] > 'z') return 1;
        ++balance[first[i] - 'a'];
    }
    for (size_t i = 0; second[i] != '\0'; ++i) {
        if (second[i] < 'a' || second[i] > 'z') return 1;
        --balance[second[i] - 'a'];
    }
    for (int i = 0; i < 26; ++i) {
        if (balance[i] != 0) {
            puts("Not Anagram");
            return 0;
        }
    }
    puts("Anagram");
    return 0;
}
