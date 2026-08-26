/*
Question 66
Insert an element in a sorted array at the appropriate position.
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
    int numbers[CAPACITY + 1], count, value;
    if (!read_array(numbers, &count) || scanf("%d", &value) != 1) {
        return 1;
    }
    int position = count;
    while (position > 0 && numbers[position - 1] > value) {
        numbers[position] = numbers[position - 1];
        --position;
    }
    numbers[position] = value;
    print_array(numbers, count + 1);
    return 0;
}
