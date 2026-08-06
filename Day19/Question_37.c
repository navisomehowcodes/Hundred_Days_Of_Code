/*
Question 37
Write a program to find the LCM of two numbers.
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
    long long lcm = 0;
    if (first != 0 && second != 0) {
        lcm = first / gcd(first, second) * second;
    }
    printf("%lld\n", lcm);
    return 0;
}
