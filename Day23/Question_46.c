/*
Question 46
Write a program to print the following pattern:
*****
*****
*****
*****
*****
*/

#include <stdio.h>

static void print_stars(int count)
{
    for (int column = 0; column < count; ++column) {
        putchar('*');
    }
}

int main(void)
{
    for (int row = 0; row < 5; ++row) {
        print_stars(5);
        putchar('\n');
    }
    return 0;
}
