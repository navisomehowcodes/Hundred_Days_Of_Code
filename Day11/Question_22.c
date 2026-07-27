/*
Question 22
Write a program to find profit or loss percentage given cost price and selling price.
*/

#include <stdio.h>

int main(void)
{
    double cost, selling;
    if (scanf("%lf%lf", &cost, &selling) != 2 || selling < 0 || cost <= 0) {
        return 1;
    }
    if (selling > cost) {
        printf("Profit %.12g%%\n", (selling - cost) / cost * 100);
    } else if (selling < cost) {
        printf("Loss %.12g%%\n", (cost - selling) / cost * 100);
    } else {
        puts("No Profit No Loss");
    }
    return 0;
}
