/*
Question 112
Write a program to take an integer array arr as input. The task is to find the maximum sum of any contiguous subarray using Kadane's algorithm. Print the maximum sum as output. If all elements are negative, print the largest (least negative) element.
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

int main(void)
{
    char line[INPUT_SIZE], *cursor = line;
    int numbers[CAPACITY], count;
    if (!read_line(line, sizeof line) || !read_list(&cursor, numbers, &count)) {
        return 1;
    }
    if (count == 0) {
        puts("Empty array");
        return 0;
    }
    long long ending_here = numbers[0], best = ending_here;
    for (int i = 1; i < count; ++i) {
        /* Starting over beats extending a subarray whose sum is negative. */
        ending_here = (ending_here > 0 ? ending_here : 0) + numbers[i];
        if (ending_here > best) best = ending_here;
    }
    printf("%lld\n", best);
    return 0;
}
