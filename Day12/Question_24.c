/*
Question 24
Write a program to calculate electricity bill based on units consumed with these rates: 
First 100 units at ₹5/unit 
Next 100 units at ₹7/unit 
Next 100 units at ₹10/unit 
Above at ₹12/unit
*/

#include <stdio.h>

int main(void)
{
    int n;
    if (scanf("%d", &n) != 1 || n < 0) {
        return 1;
    }
    long long bill;
    if (n <= 100) {
        bill = 5 * n;
    } else if (n <= 200) {
        bill = 500 + 7 * (n - 100);
    } else if (n <= 300) {
        bill = 1200 + 10 * (n - 200);
    } else {
        bill = 2200 + 12LL * (n - 300);
    }
    printf("Bill: ₹%lld\n", bill);
    return 0;
}
