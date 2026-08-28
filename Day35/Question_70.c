/*
Question 70
Rotate an array to the right by k positions.
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
    int steps;
    if (scanf("%d", &steps) != 1) {
        return 1;
    }
    if (count > 0) {
        int shift = (steps % count + count) % count;
        for (int i = 0; i < count; ++i) {
            int source = (i + count - shift) % count;
            printf("%s%d", i == 0 ? "" : " ", numbers[source]);
        }
    }
    putchar('\n');
    return 0;
}
