/*
Question 25
Write a program to implement a basic calculator using switch-case for +, -, *, /, %.
*/

#include <stdio.h>
#include <math.h>

int main(void)
{
    double left, right, result;
    char operation;
    if (scanf("%lf%lf %c", &left, &right, &operation) != 3) {
        return 1;
    }
    if ((operation == '/' || operation == '%') && right == 0) {
        puts("Division by zero");
        return 0;
    }
    switch (operation) {
    case '+': result = left + right; break;
    case '-': result = left - right; break;
    case '*': result = left * right; break;
    case '/': result = left / right; break;
    case '%': result = fmod(left, right); break;
    default: puts("Invalid operation"); return 0;
    }
    printf("%.12g\n", result);
    return 0;
}
