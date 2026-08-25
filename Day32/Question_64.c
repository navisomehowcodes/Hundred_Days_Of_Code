/*
Question 64
Find the digit that occurs the most times in an integer number.
*/

#include <stdio.h>

int main(void)
{
    int n;
    if (scanf("%d", &n) != 1) {
        return 1;
    }
    long long magnitude = n < 0 ? -(long long)n : n;
    int frequency[10] = {0};
    do {
        ++frequency[magnitude % 10];
        magnitude /= 10;
    } while (magnitude > 0);
    int most_frequent = 0;
    for (int digit = 1; digit <= 9; ++digit) {
        if (frequency[digit] > frequency[most_frequent]) {
            most_frequent = digit;
        }
    }
    printf("%d\n", most_frequent);
    return 0;
}
