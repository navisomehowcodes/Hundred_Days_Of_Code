/*
Question 43
Write a program to check if a number is a strong number.
*/

#include <stdio.h>

int main(void)
{
    int n;
    if (scanf("%d", &n) != 1) {
        return 1;
    }
    int value = n, sum = 0;
    do {
        int digit = value % 10, factorial = 1;
        for (int i = 2; i <= digit; ++i) {
            factorial *= i;
        }
        sum += factorial;
        value /= 10;
    } while (value > 0);
    puts(n >= 0 && sum == n ? "Strong number" : "Not strong number");
    return 0;
}
