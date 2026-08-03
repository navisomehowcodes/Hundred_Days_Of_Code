/*
Question 31
Write a program to take a number as input and print its equivalent binary representation.
*/

#include <stdio.h>

int main(void)
{
    int n;
    if (scanf("%d", &n) != 1) {
        return 1;
    }
    long long magnitude = n < 0 ? -(long long)n : n;
    if (n < 0) {
        putchar('-');
    }
    long long place = 1;
    while (place <= magnitude / 2) {
        place *= 2;
    }
    while (place > 0) {
        putchar('0' + (int)(magnitude / place));
        magnitude %= place;
        place /= 2;
    }
    putchar('\n');
    return 0;
}
