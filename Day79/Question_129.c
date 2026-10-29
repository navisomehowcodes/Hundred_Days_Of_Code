/*
Question 129
A file numbers.txt contains a list of integers separated by spaces. Read all integers, compute their sum and average, and print both.
*/

#include <stdio.h>
#include <limits.h>

int main(int argc, char *argv[])
{
    const char *path = argc > 1 ? argv[1] : "numbers.txt";
    FILE *input = fopen(path, "r");
    if (input == NULL) {
        perror(path);
        return 1;
    }
    long long sum = 0;
    unsigned long long count = 0;
    int number, status;
    while ((status = fscanf(input, "%d", &number)) == 1) {
        if ((number > 0 && sum > LLONG_MAX - number) ||
            (number < 0 && sum < LLONG_MIN - number)) {
            fclose(input);
            return 1;
        }
        sum += number;
        ++count;
    }
    int failed = ferror(input) || status != EOF;
    if (fclose(input) != 0 || failed) return 1;
    if (count == 0) {
        puts("No numbers");
    } else {
        printf("Sum = %lld\nAverage = %.2f\n", sum, (double)sum / (double)count);
    }
    return 0;
}
