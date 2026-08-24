/*
Question 61
Search for an element in an array using linear search.
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
    int target;
    if (scanf("%d", &target) != 1) {
        return 1;
    }
    for (int i = 0; i < count; ++i) {
        if (numbers[i] == target) {
            printf("Found at index %d\n", i);
            return 0;
        }
    }
    puts("-1");
    return 0;
}
