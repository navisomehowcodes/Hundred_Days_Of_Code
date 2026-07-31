/*
Question 30
Write a program to reverse a given number.
*/

#include <stdio.h>

static long long reverse_digits(long long number)
{
    long long reversed = 0;
    while (number > 0) {
        reversed = 10 * reversed + number % 10;
        number /= 10;
    }
    return reversed;
}

int main(void)
{
    int n;
    if (scanf("%d", &n) != 1) {
        return 1;
    }
    long long magnitude = n < 0 ? -(long long)n : n;
    long long reversed = reverse_digits(magnitude);
    printf("%lld\n", n < 0 ? -reversed : reversed);
    return 0;
}
