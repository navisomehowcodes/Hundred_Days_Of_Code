/*
Question 136
Use enum to represent menu choices (ADD, SUBTRACT, MULTIPLY) and perform operations using switch.
*/

#include <stdio.h>
#include <string.h>

int main(void)
{
    enum Choice { ADD, SUBTRACT, MULTIPLY };
    enum Choice choice;
    char name[16];
    int a, b;
    if (scanf("%15s%d%d", name, &a, &b) != 3) return 1;
    if (strcmp(name, "ADD") == 0) choice = ADD;
    else if (strcmp(name, "SUBTRACT") == 0) choice = SUBTRACT;
    else if (strcmp(name, "MULTIPLY") == 0) choice = MULTIPLY;
    else {
        puts("Unknown operation");
        return 0;
    }
    switch (choice) {
    case ADD:      printf("%lld\n", (long long)a + b); break;
    case SUBTRACT: printf("%lld\n", (long long)a - b); break;
    case MULTIPLY: printf("%lld\n", (long long)a * b); break;
    }
    return 0;
}
