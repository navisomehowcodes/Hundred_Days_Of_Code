/*
Question 69
Find the second largest element in an array.
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
        puts("No second largest");
        return 0;
    }
    int largest = numbers[0], second = 0, found_second = 0;
    for (int i = 1; i < count; ++i) {
        if (numbers[i] > largest) {
            second = largest;
            largest = numbers[i];
            found_second = 1;
        } else if (numbers[i] < largest && (!found_second || numbers[i] > second)) {
            second = numbers[i];
            found_second = 1;
        }
    }
    if (found_second) {
        printf("%d\n", second);
    } else {
        puts("No second largest");
    }
    return 0;
}
