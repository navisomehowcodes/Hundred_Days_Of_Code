/*
Question 41
Write a program to swap the first and last digit of a number.
*/

#include <stdio.h>

int main(void)
{
    int n;
    if (scanf("%d", &n) != 1) {
        return 1;
    }
    long long magnitude = n < 0 ? -(long long)n : n;
    long long place = 1;
    while (place <= magnitude / 10) {
        place *= 10;
    }
    if (place > 1) {
        long long first = magnitude / place;
        long long last = magnitude % 10;
        long long middle = magnitude % place / 10;
        magnitude = last * place + middle * 10 + first;
    }
    printf("%lld\n", n < 0 ? -magnitude : magnitude);
    return 0;
}
