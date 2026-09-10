/*
Question 87
Count spaces, digits, and special characters in a string.
*/

#include <stdio.h>
#include <ctype.h>

int main(void)
{
    size_t spaces = 0, digits = 0, special = 0;
    int ch;
    while ((ch = getchar()) != EOF && ch != '\n') {
        if (ch == ' ') {
            ++spaces;
        } else if (isdigit(ch)) {
            ++digits;
        } else if (!isalpha(ch)) {
            ++special;
        }
    }
    printf("Spaces=%zu, Digits=%zu, Special=%zu\n", spaces, digits, special);
    return 0;
}
