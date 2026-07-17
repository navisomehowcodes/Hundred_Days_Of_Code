/*
Question 9
Write a program to calculate simple and compound interest for given principal, rate, and time.
*/

#include <stdio.h>
#include <math.h>
#include <string.h>

/* Monetary results are rounded to cents, with superfluous zeros removed. */
static void print_amount(double amount)
{
    char formatted[384];
    snprintf(formatted, sizeof formatted, "%.2f", round(amount * 100) / 100);
    size_t end = strlen(formatted);
    while (end > 0 && formatted[end - 1] == '0') {
        --end;
    }
    if (end > 0 && formatted[end - 1] == '.') {
        --end;
    }
    formatted[end] = '\0';
    fputs(formatted, stdout);
}

int main(void)
{
    double principal, rate, years;
    if (scanf("%lf%lf%lf", &principal, &rate, &years) != 3 ||
        principal < 0 || years < 0) {
        return 1;
    }
    double simple = principal * rate * years / 100;
    double compound = principal * (pow(1 + rate / 100, years) - 1);
    if (!isfinite(simple) || !isfinite(compound) || fabs(simple) > 1e300 || fabs(compound) > 1e300) {
        return 1;
    }
    fputs("Simple Interest=", stdout);
    print_amount(simple);
    fputs(", Compound Interest=", stdout);
    print_amount(compound);
    putchar('\n');
    return 0;
}
