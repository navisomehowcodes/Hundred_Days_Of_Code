/*
Question 33
Write a program to check if a number is an Armstrong number.
*/

#include <stdio.h>

int main(void)
{
    int n;
    if (scanf("%d", &n) != 1) {
        return 1;
    }
    int digits = 1;
    for (int value = n; value >= 10; value /= 10) {
        ++digits;
    }
    long long sum = 0;
    for (int value = n; value > 0; value /= 10) {
        int digit = value % 10;
        long long power = 1;
        for (int i = 0; i < digits; ++i) {
            power *= digit;
        }
        sum += power;
    }
    puts(n >= 0 && sum == n ? "Armstrong" : "Not Armstrong");
    return 0;
}
