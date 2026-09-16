/*
Question 95
Check if one string is a rotation of another.
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
    char first[TEXT_CAPACITY + 1], second[TEXT_CAPACITY + 1];
    if (!read_line(first, sizeof first) || !read_line(second, sizeof second)) {
        return 1;
    }
    size_t length = strlen(first);
    if (length != strlen(second)) {
        puts("Not rotation");
        return 0;
    }
    /* A rotation crosses at most one boundary between two copies. */
    char doubled[2 * TEXT_CAPACITY + 1];
    memcpy(doubled, first, length);
    memcpy(doubled + length, first, length + 1);
    puts(strstr(doubled, second) ? "Rotation" : "Not rotation");
    return 0;
}
