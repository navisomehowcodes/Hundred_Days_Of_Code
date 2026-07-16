/*
Question 8
Write a program to find and display the sum of the first n natural numbers.
*/

#include <stdio.h>

int main(void)
{
    int n;
    if (scanf("%d", &n) != 1 || n < 0) {
        return 1;
    }
    long long sum = (long long)n * (n + 1LL) / 2;
    printf("Sum=%lld\n", sum);
    return 0;
}
