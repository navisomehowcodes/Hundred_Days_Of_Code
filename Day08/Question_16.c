/*
Question 16
Write a program to input three numbers and find the largest among them using if–else.
*/

#include <stdio.h>

int main(void)
{
    double a, b, c, largest;
    if (scanf("%lf%lf%lf", &a, &b, &c) != 3) {
        return 1;
    }
    if (a >= b && a >= c) {
        largest = a;
    } else if (b >= c) {
        largest = b;
    } else {
        largest = c;
    }
    printf("Largest is %.12g\n", largest);
    return 0;
}
