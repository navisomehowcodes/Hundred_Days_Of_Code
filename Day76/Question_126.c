/*
Question 126
Ask the user for a filename. Check if it exists by trying to open it in read mode. If the file pointer is NULL, print an error message; otherwise, read and display its content.
*/

#include <stdio.h>

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
    char path[512];
    if (!read_line(path, sizeof path)) return 1;
    FILE *input = fopen(path, "r");
    if (!input) {
        puts("Error: File does not exist!");
        return 0;
    }
    puts("File opened successfully.");
    int ch;
    while ((ch = fgetc(input)) != EOF) {
        putchar(ch);
    }
    int failed = ferror(input);
    if (fclose(input) != 0 || failed) return 1;
    return 0;
}
