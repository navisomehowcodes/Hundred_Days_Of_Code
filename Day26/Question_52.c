/*
Question 52
Write a program to print the following pattern:

*

*
*
*

*
*
*
*
*

*
*
*

*


*/

#include <stdio.h>

int main(void)
{
    /* The diagram puts each star on its own line, with blank lines between groups. */
    putchar('\n');
    for (int group = 0; group < 5; ++group) {
        int height = group <= 2 ? 2 * group + 1 : 2 * (4 - group) + 1;
        for (int star = 0; star < height; ++star) {
            puts("*");
        }
        putchar('\n');
    }
    return 0;
}
