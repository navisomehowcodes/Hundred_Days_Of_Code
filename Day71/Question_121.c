/*
Question 121
Write a C program that creates a text file named info.txt in write mode. The program should take the user’s name and age as input, and write them to the file using fprintf(). After writing, display a message confirming that the data was successfully saved.
*/

#include <stdio.h>
#include <string.h>

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
    char line[256], name[200];
    int age;
    if (!read_line(line, sizeof line)) return 1;
    if (strncmp(line, "Name: ", 6) == 0) {
        if (sscanf(line, "Name: %199[^,], Age: %d", name, &age) != 2) return 1;
    } else {
        if (line[0] == '\0' || strlen(line) >= sizeof name || scanf("%d", &age) != 1) return 1;
        strcpy(name, line);
    }
    if (age < 0) return 1;
    FILE *file = fopen("info.txt", "w");
    if (!file) {
        perror("info.txt");
        return 1;
    }
    int written = fprintf(file, "Name: %s\nAge: %d\n", name, age);
    if (fclose(file) != 0 || written < 0) return 1;
    puts("File created successfully! Data written to info.txt");
    return 0;
}
