/*
Question 10
Write a program to input time in seconds and convert it to hours:minutes:seconds format.
*/

#include <stdio.h>

int main(void)
{
    int n;
    if (scanf("%d", &n) != 1 || n < 0) {
        return 1;
    }
    printf("%d:%d:%d\n", n / 3600, n / 60 % 60, n % 60);
    return 0;
}
