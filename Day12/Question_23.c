/*
Question 23
Write a program to calculate library fine based on late days as follows: 
First 5 days late: ₹2/day 
Next 5 days late: ₹4/day 
Next 20 days days late: ₹6/day 
More than 30 days: Membership Cancelled.
*/

#include <stdio.h>

int main(void)
{
    int n;
    if (scanf("%d", &n) != 1 || n < 0) {
        return 1;
    }
    if (n > 30) {
        puts("Membership Cancelled");
    } else {
        int fine;
        if (n <= 5) {
            fine = 2 * n;
        } else if (n <= 10) {
            fine = 10 + 4 * (n - 5);
        } else {
            fine = 30 + 6 * (n - 10);
        }
        printf("Fine ₹%d\n", fine);
    }
    return 0;
}
