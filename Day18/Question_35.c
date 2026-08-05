/*
Question 35
Write a program to print all factors of a given number.
*/

#include <stdio.h>

int main(void)
{
    int n;
    if (scanf("%d", &n) != 1) {
        return 1;
    }
    long long magnitude = n < 0 ? -(long long)n : n;
    if (magnitude == 0) {
        puts("Infinitely many factors");
        return 0;
    }
    long long divisor = 1;
    while (divisor <= magnitude / divisor) {
        if (magnitude % divisor == 0) {
            printf("%s%lld", divisor == 1 ? "" : " ", divisor);
        }
        ++divisor;
    }
    /* Visit complementary factors in ascending order, printing a square root only once. */
    while (--divisor >= 1) {
        if (magnitude % divisor == 0 && divisor != magnitude / divisor) {
            printf(" %lld", magnitude / divisor);
        }
    }
    putchar('\n');
    return 0;
}
