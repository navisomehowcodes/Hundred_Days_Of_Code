/*
Question 102
Write a Program to take a sorted array arr[] and an integer x as input, find the index (0-based) of the smallest element in arr[] that is greater than or equal to x and print it. This element is called the ceil of x. If such an element does not exist, print -1. Note: In case of multiple occurrences of ceil of x, return the index of the first occurrence.
*/

/* Source note
Follow-up(optional): Can you do it in O(log n) Time Complexity?
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <limits.h>
#include <errno.h>

enum { CAPACITY = 4096, INPUT_SIZE = 65536 };

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

static int read_integer(char **cursor, int *value)
{
    char *end;
    errno = 0;
    long parsed = strtol(*cursor, &end, 10);
    if (end == *cursor || errno == ERANGE || parsed < INT_MIN || parsed > INT_MAX) {
        return 0;
    }
    *value = (int)parsed;
    *cursor = end;
    return 1;
}

static char *skip_spaces(char *s)
{
    while (isspace((unsigned char)*s)) ++s;
    return s;
}

/* Extract a bracketed list, skipping the optional empty brackets in "arr[] = [...]". */
static int read_list(char **cursor, int values[], int *count)
{
    char *open = strchr(*cursor, '[');
    if (!open) return 0;
    char *s = skip_spaces(open + 1);
    if (*s == ']') {
        char *rest = skip_spaces(s + 1);
        if (*rest == '=' && *skip_spaces(rest + 1) == '[') {
            s = skip_spaces(skip_spaces(rest + 1) + 1);
        }
    }
    *count = 0;
    if (*s != ']') {
        for (;;) {
            if (*count >= CAPACITY || !read_integer(&s, &values[*count])) return 0;
            ++*count;
            s = skip_spaces(s);
            if (*s != ',') break;
            ++s;
        }
    }
    if (*s != ']') return 0;
    *cursor = s + 1;
    return 1;
}

static int read_parameter(char *s, int *value)
{
    char *equals = strrchr(s, '=');
    if (equals) s = equals + 1;
    if (!read_integer(&s, value)) return 0;
    while (isspace((unsigned char)*s)) ++s;
    return *s == '\0';
}

int main(void)
{
    char line[INPUT_SIZE], *cursor = line;
    int numbers[CAPACITY], count;
    if (!read_line(line, sizeof line) || !read_list(&cursor, numbers, &count)) {
        return 1;
    }
    int target;
    if (!read_parameter(cursor, &target)) {
        return 1;
    }
    int left = 0, right = count;
    while (left < right) {
        int middle = left + (right - left) / 2;
        if (numbers[middle] < target) {
            left = middle + 1;
        } else {
            right = middle;
        }
    }
    printf("%d\n", left == count ? -1 : left);
    return 0;
}
