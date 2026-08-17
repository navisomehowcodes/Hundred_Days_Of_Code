/*
Question 51
Write a program to print the following pattern:
    5
   45
  345
 2345
12345
*/

#include <stdio.h>

int main(void)
{
    for (int first = 5; first >= 1; --first) {
        for (int space = 1; space < first; ++space) {
            putchar(' ');
        }
        for (int digit = first; digit <= 5; ++digit) {
            printf("%d", digit);
        }
        putchar('\n');
    }
    return 0;
}
