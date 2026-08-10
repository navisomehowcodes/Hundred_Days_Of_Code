/*
Question 42
Write a program to check if a number is a perfect number.
*/

#include <stdio.h>

int main(void)
{
    int n;
    if (scanf("%d", &n) != 1) {
        return 1;
    }
    long long sum = n > 1 ? 1 : 0;
    for (int divisor = 2; divisor <= n / divisor; ++divisor) {
        if (n % divisor == 0) {
            sum += divisor;
            if (n / divisor != divisor) {
                sum += n / divisor;
            }
        }
    }
    puts(n > 1 && sum == n ? "Perfect number" : "Not perfect number");
    return 0;
}
