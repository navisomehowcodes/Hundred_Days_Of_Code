/*
Question 27
Write a program to print the sum of the first n odd numbers.
*/

#include <stdio.h>

int main(void)
{
    int n;
    if (scanf("%d", &n) != 1 || n < 0) {
        return 1;
    }
    long long sum = 0;
    for (int i = 0; i < n; ++i) {
        sum += 2LL * i + 1;
    }
    printf("%lld\n", sum);
    return 0;
}
