/*
Question 55
Write a program to print all the prime numbers from 1 to n.
*/

#include <stdio.h>

static int is_prime(int n)
{
    if (n < 2) {
        return 0;
    }
    for (int divisor = 2; divisor <= n / divisor; ++divisor) {
        if (n % divisor == 0) {
            return 0;
        }
    }
    return 1;
}

int main(void)
{
    int n;
    if (scanf("%d", &n) != 1) {
        return 1;
    }
    int first = 1;
    for (long long candidate = 2; candidate <= n; ++candidate) {
        if (is_prime((int)candidate)) {
            printf("%s%lld", first ? "" : " ", candidate);
            first = 0;
        }
    }
    putchar('\n');
    return 0;
}
