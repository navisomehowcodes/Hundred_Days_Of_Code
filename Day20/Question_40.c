/*
Question 40
Write a program to find the 1’s complement of a binary number and print it.
*/

#include <stdio.h>
#include <ctype.h>

int main(void)
{
    int ch;
    do {
        ch = getchar();
    } while (ch != EOF && isspace(ch));
    if (ch != '0' && ch != '1') {
        return 1;
    }
    do {
        putchar(ch == '0' ? '1' : '0');
        ch = getchar();
    } while (ch == '0' || ch == '1');
    if (ch != EOF && !isspace(ch)) {
        return 1;
    }
    putchar('\n');
    return 0;
}
