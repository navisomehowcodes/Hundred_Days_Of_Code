/*
Question 29
Write a program to calculate the factorial of a number.
*/

#include <stdio.h>
#include <limits.h>

int main(void)
{
    int n;
    if (scanf("%d", &n) != 1 || n < 0) {
        return 1;
    }
    unsigned long long factorial = 1;
    for (int factor = 2; factor <= n; ++factor) {
        if (factorial > ULLONG_MAX / (unsigned)factor) {
            puts("Overflow");
            return 0;
        }
        factorial *= (unsigned)factor;
    }
    printf("%llu\n", factorial);
    return 0;
}
