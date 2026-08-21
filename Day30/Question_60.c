/*
Question 60
Count positive, negative, and zero elements in an array.
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
    int positive = 0, negative = 0;
    for (int i = 0; i < count; ++i) {
        if (numbers[i] > 0) {
            ++positive;
        } else if (numbers[i] < 0) {
            ++negative;
        }
    }
    printf("Positive=%d, Negative=%d, Zero=%d\n", positive, negative, count - positive - negative);
    return 0;
}
