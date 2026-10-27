/*
Question 127
Write a program that reads text from input.txt, converts all lowercase letters to uppercase, and writes the result to output.txt.
*/

#include <stdio.h>
#include <ctype.h>

int main(void)
{
    FILE *input = fopen("input.txt", "r");
    if (!input) {
        perror("input.txt");
        return 1;
    }
    FILE *output = fopen("output.txt", "w");
    if (!output) {
        perror("output.txt");
        fclose(input);
        return 1;
    }
    int ch, ok = 1;
    while ((ch = fgetc(input)) != EOF) {
        if (fputc(toupper(ch), output) == EOF) {
            ok = 0;
            break;
        }
    }
    if (ferror(input)) ok = 0;
    if (fclose(input) != 0) ok = 0;
    if (fclose(output) != 0 || !ok) return 1;
    return 0;
}
