/*
Question 104
Write a Program to take a positive integer n as input, and find the pivot integer x such that the sum of all elements between 1 and x inclusively equals the sum of all elements between x and n inclusively. Print the pivot integer x. If no such integer exists, print -1. Assume that it is guaranteed that there will be at most one pivot integer for the given input.
*/

/* Source note
Follow-up 1 (optional): Can you do it in O(log n) Time Complexity? Follow-up 2 (optional): Can you do it in O(1) Time Complexity?
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <limits.h>
#include <errno.h>

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
    char line[128];
    int n;
    if (!read_line(line, sizeof line) || !read_parameter(line, &n) || n < 1) {
        return 1;
    }
    /* Adding the two sums through x and through x-1 gives x squared. */
    long long total = (long long)n * (n + 1LL) / 2;
    long long left = 1, right = n;
    while (left <= right) {
        long long middle = left + (right - left) / 2;
        long long square = middle * middle;
        if (square == total) {
            printf("%lld\n", middle);
            return 0;
        }
        if (square < total) {
            left = middle + 1;
        } else {
            right = middle - 1;
        }
    }
    puts("-1");
    return 0;
}
