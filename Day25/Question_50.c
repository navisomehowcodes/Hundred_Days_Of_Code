/*
Question 50
Write a program to print the following pattern:
*****
 ****
  ***
   **
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
    for (int row = 0; row < 5; ++row) {
        for (int space = 0; space < row; ++space) {
            putchar(' ');
        }
        print_stars(5 - row);
        putchar('\n');
    }
    return 0;
}
