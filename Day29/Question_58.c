/*
Question 58
Find the maximum and minimum element in an array.
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
    if (count == 0) {
        puts("Empty array");
        return 0;
    }
    int maximum = numbers[0], minimum = numbers[0];
    for (int i = 1; i < count; ++i) {
        if (numbers[i] > maximum) maximum = numbers[i];
        if (numbers[i] < minimum) minimum = numbers[i];
    }
    printf("Max=%d, Min=%d\n", maximum, minimum);
    return 0;
}
