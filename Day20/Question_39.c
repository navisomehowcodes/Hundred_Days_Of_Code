/*
Question 39
Write a program to find the product of odd digits of a number.
*/

#include <stdio.h>

int main(void)
{
    int n;
    if (scanf("%d", &n) != 1) {
        return 1;
    }
    long long magnitude = n < 0 ? -(long long)n : n;
    long long product = 1;
    int count = 0;
    for (long long rest = magnitude; rest > 0; rest /= 10) {
        int digit = (int)(rest % 10);
        if (digit % 2 == 1) {
            product *= digit;
            ++count;
        }
    }
    if (count == 0) {
        puts("1 (no odd digits, assume 1)");
        return 0;
    }
    printf("%lld (", product);
    long long place = 1;
    while (place <= magnitude / 10) {
        place *= 10;
    }
    while (place > 0) {
        int digit = (int)(magnitude / place % 10);
        if (digit % 2 == 1) {
            printf("%d", digit);
            if (--count > 0) {
                putchar('*');
            }
        }
        place /= 10;
    }
    puts(")");
    return 0;
}
