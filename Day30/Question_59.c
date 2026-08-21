/*
Question 59
Count even and odd numbers in an array.
*/

#include <stdio.h>

enum { CAPACITY = 4096 };

static int read_array(int values[], int *count)
{
    if (scanf("%d", count) != 1 || *count < 0 || *count > CAPACITY) {
        return 0;
    }
    for (int i = 0; i < *count; ++i) {
        if (scanf("%d", &values[i]) != 1) {
            return 0;
        }
    }
    return 1;
}

int main(void)
{
    int numbers[CAPACITY], count;
    if (!read_array(numbers, &count)) {
        return 1;
    }
    int even = 0;
    for (int i = 0; i < count; ++i) {
        if (numbers[i] % 2 == 0) {
            ++even;
        }
    }
    printf("Even=%d, Odd=%d\n", even, count - even);
    return 0;
}
