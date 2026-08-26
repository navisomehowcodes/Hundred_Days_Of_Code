/*
Question 65
Search in a sorted array using binary search.
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
    int left = 0, right = count;
    while (left < right) {
        int middle = left + (right - left) / 2;
        if (numbers[middle] < target) {
            left = middle + 1;
        } else {
            right = middle;
        }
    }
    if (left < count && numbers[left] == target) {
        printf("Found at index %d\n", left);
    } else {
        puts("-1");
    }
    return 0;
}
