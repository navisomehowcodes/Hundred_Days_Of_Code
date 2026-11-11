/*
Question 138
Print all enum names and integer values using a loop.
*/

#include <stdio.h>

typedef enum { RED, YELLOW, GREEN } Light;

int main(void)
{
    const char *names[] = {"RED", "YELLOW", "GREEN"};
    for (Light light = RED; light <= GREEN; ++light) {
        printf("%s=%d\n", names[light], (int)light);
    }
    return 0;
}
