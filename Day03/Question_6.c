/*
Question 6
Write a program to swap two numbers using a third variable.
*/

#include <stdio.h>

int main(void)
{
    int a, b;
    if (scanf("%d%d", &a, &b) != 2) {
        return 1;
    }
    int temporary = a;
    a = b;
    b = temporary;
    printf("After swap: %d %d\n", a, b);
    return 0;
}
