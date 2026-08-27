/*
Question 67
Insert an element in an array at a given position.
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
    int numbers[CAPACITY + 1], count, position, value;
    if (!read_array(numbers, &count) || scanf("%d%d", &position, &value) != 2 ||
        position < 0 || position > count) {
        return 1;
    }
    for (int i = count; i > position; --i) {
        numbers[i] = numbers[i - 1];
    }
    numbers[position] = value;
    print_array(numbers, count + 1);
    return 0;
}
