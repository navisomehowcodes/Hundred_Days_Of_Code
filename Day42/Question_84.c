/*
Question 84
Convert a lowercase string to uppercase without using built-in functions.
*/

#include <stdio.h>

int main(void)
{
    int ch;
    while ((ch = getchar()) != EOF && ch != '\n') {
        if (ch >= 'a' && ch <= 'z') {
            ch = ch - 'a' + 'A';
        }
        putchar(ch);
    }
    putchar('\n');
    return 0;
}
