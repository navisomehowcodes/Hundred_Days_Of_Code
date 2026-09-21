/*
Question 101
Write a Program to take a sorted array(say nums[]) and an integer (say target) as inputs. The elements in the sorted array might be repeated. You need to print the first and last occurrence of the target and print the index of first and last occurrence. Print -1, -1 if the target is not present.
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

/* In a sorted array, find the first position >= target (or > target for upper). */
static int bound(const int numbers[], int count, int target, int upper)
{
    int left = 0, right = count;
    while (left < right) {
        int middle = left + (right - left) / 2;
        if (numbers[middle] < target || (upper && numbers[middle] == target)) {
            left = middle + 1;
        } else {
            right = middle;
        }
    }
    return left;
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
    int first = bound(numbers, count, target, 0);
    if (first == count || numbers[first] != target) {
        puts("-1,-1");
    } else {
        int last = bound(numbers, count, target, 1) - 1;
        printf("%d,%d\n", first, last);
    }
    return 0;
}
