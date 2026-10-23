/*
Question 125
Open an existing file in append mode and allow the user to enter a new line of text. Append the text at the end without overwriting existing content.
*/

#include <stdio.h>

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
    const char *path = argc > 1 ? argv[1] : "data.txt";
    char text[TEXT_CAPACITY + 1];
    if (!read_line(text, sizeof text)) {
        return 1;
    }
    FILE *file = fopen(path, "a+b");
    if (!file) {
        perror(path);
        return 1;
    }
    int ok = fseek(file, 0, SEEK_END) == 0;
    long length = ok ? ftell(file) : -1;
    ok = length >= 0;
    if (ok && length > 0) {
        ok = fseek(file, -1, SEEK_END) == 0;
        int last = ok ? fgetc(file) : EOF;
        ok = last != EOF && fseek(file, 0, SEEK_END) == 0;
        if (ok && last != '\n') ok = fputc('\n', file) != EOF;
    }
    if (ok) ok = fprintf(file, "%s\n", text) >= 0;
    if (fclose(file) != 0 || !ok) return 1;
    puts("File updated successfully with appended text.");
    return 0;
}
