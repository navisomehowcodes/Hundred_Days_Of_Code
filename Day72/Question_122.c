/*
Question 122
Write a C program that opens an existing file (e.g., info.txt) and reads its contents using fgets(). The program should print all the lines to the console until EOF (end of file) is reached.
*/

#include <stdio.h>

int main(int argc, char *argv[])
{
    const char *path = argc > 1 ? argv[1] : "info.txt";
    FILE *input = fopen(path, "r");
    if (input == NULL) {
        perror(path);
        return 1;
    }
    char line[256];
    while (fgets(line, sizeof line, input)) {
        fputs(line, stdout);
    }
    int failed = ferror(input);
    if (fclose(input) != 0 || failed) return 1;
    return 0;
}
