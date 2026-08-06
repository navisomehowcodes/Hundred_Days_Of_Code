/*
Question 38
Write a program to find the sum of digits of a number.
*/

#include <stdio.h>

int main(void)
{
    int n;
    if (scanf("%d", &n) != 1) {
        return 1;
    }
    long long magnitude = n < 0 ? -(long long)n : n;
    int sum = 0;
    while (magnitude > 0) {
        sum += (int)(magnitude % 10);
        magnitude /= 10;
    }
    printf("%d\n", sum);
    return 0;
}
