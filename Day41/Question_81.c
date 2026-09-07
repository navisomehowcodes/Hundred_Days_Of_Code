/*
Question 81
Count characters in a string without using built-in length functions.
*/

#include <stdio.h>

int main(void)
{
    size_t length = 0;
    int ch;
    while ((ch = getchar()) != EOF && ch != '\n') {
        ++length;
    }
    printf("%zu\n", length);
    return 0;
}
