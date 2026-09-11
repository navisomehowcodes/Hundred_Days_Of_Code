/*
Question 90
Toggle case of each character in a string.
*/

#include <stdio.h>
#include <ctype.h>

int main(void)
{
    int ch;
    while ((ch = getchar()) != EOF && ch != '\n') {
        putchar(isupper(ch) ? tolower(ch) : toupper(ch));
    }
    putchar('\n');
    return 0;
}
