/*
Question 53
Write a program to print the following pattern:
*
***
*****
*******
*********
*******
*****
***
*
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
    for (int row = 0; row < 9; ++row) {
        int level = row <= 4 ? row : 8 - row;
        print_stars(2 * level + 1);
        putchar('\n');
    }
    return 0;
}
