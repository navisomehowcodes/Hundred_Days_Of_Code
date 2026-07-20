/*
Question 12
Write a program to input an integer and check whether it is positive, negative or zero using nested if–else.
*/

#include <stdio.h>

int main(void)
{
    int n;
    if (scanf("%d", &n) != 1) {
        return 1;
    }
    if (n >= 0) {
        if (n == 0) {
            puts("Zero");
        } else {
            puts("Positive");
        }
    } else {
        puts("Negative");
    }
    return 0;
}
