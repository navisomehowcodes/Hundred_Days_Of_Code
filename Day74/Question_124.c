/*
Question 124
Take two filenames from the user – a source file and a destination file. Copy all the content from the source file to the destination file using fgetc() and fputc().
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

static int copy_stream(FILE *source, FILE *destination)
{
    int ch;
    while ((ch = fgetc(source)) != EOF) {
        if (fputc(ch, destination) == EOF) return 0;
    }
    return !ferror(source);
}

int main(void)
{
    char source_name[512], destination_name[512];
    if (!read_line(source_name, sizeof source_name) ||
        !read_line(destination_name, sizeof destination_name)) return 1;
    FILE *source = fopen(source_name, "rb");
    if (!source) {
        perror(source_name);
        return 1;
    }
    /* Finish reading before opening the destination. This also handles two paths to the same file. */
    FILE *snapshot = tmpfile();
    if (!snapshot) {
        fclose(source);
        return 1;
    }
    int copied = copy_stream(source, snapshot);
    if (fclose(source) != 0 || !copied || fseek(snapshot, 0, SEEK_SET) != 0) {
        fclose(snapshot);
        return 1;
    }
    FILE *destination = fopen(destination_name, "wb");
    if (!destination) {
        perror(destination_name);
        fclose(snapshot);
        return 1;
    }
    copied = copy_stream(snapshot, destination);
    int closed = fclose(destination);
    fclose(snapshot);
    if (!copied || closed != 0) return 1;
    printf("File copied successfully to %s\n", destination_name);
    return 0;
}
