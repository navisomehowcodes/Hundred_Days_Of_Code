/*
Question 88
Replace spaces with hyphens in a string.
*/

#include <stdio.h>

int main(void)
{
    int ch;
    while ((ch = getchar()) != EOF && ch != '\n') {
        putchar(ch == ' ' ? '-' : ch);
    }
    putchar('\n');
    return 0;
}
