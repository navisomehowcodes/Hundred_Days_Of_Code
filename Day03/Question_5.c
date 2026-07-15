/*
Question 5
Write a program to convert temperature from Celsius to Fahrenheit.
*/

#include <stdio.h>

int main(void)
{
    double celsius;
    if (scanf("%lf", &celsius) != 1) {
        return 1;
    }
    printf("Fahrenheit=%.12g\n", celsius * 9.0 / 5.0 + 32);
    return 0;
}
