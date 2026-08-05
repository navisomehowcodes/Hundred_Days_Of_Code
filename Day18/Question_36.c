/*
Question 36
Write a program to find the HCF (GCD) of two numbers.
*/

#include <stdio.h>

static long long gcd(long long a, long long b)
{
    while (b != 0) {
        long long remainder = a % b;
        a = b;
        b = remainder;
    }
    return a;
}

int main(void)
{
    int a, b;
    if (scanf("%d%d", &a, &b) != 2) {
        return 1;
    }
    long long first = a < 0 ? -(long long)a : a;
    long long second = b < 0 ? -(long long)b : b;
    printf("%lld\n", gcd(first, second));
    return 0;
}
