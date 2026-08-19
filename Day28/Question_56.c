/*
Question 56
Read and print elements of a one-dimensional array.
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

static void print_array(const int values[], int count)
{
    for (int i = 0; i < count; ++i) {
        printf("%s%d", i == 0 ? "" : " ", values[i]);
    }
    putchar('\n');
}

int main(void)
{
    int numbers[CAPACITY], count;
    if (!read_array(numbers, &count)) {
        return 1;
    }
    print_array(numbers, count);
    return 0;
}
