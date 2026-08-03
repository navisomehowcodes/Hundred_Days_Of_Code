/*
Question 32
Write a program to check if a number is a palindrome.
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
    puts(n >= 0 && reverse_digits(n) == n ? "Palindrome" : "Not palindrome");
    return 0;
}
