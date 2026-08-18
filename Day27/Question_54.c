/*
Question 54
Write a program to print the following pattern:

   *
  ***
 *****
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
    for (int row = 0; row < 7; ++row) {
        int level = row <= 3 ? row : 6 - row;
        for (int space = 0; space < 3 - level; ++space) {
            putchar(' ');
        }
        print_stars(2 * level + 1);
        putchar('\n');
    }
    return 0;
}
