/*
Question 134
Define an enum with SUCCESS, FAILURE, and TIMEOUT, and print messages accordingly.
*/

#include <stdio.h>
#include <string.h>

typedef enum { SUCCESS, FAILURE, TIMEOUT } Status;

int main(void)
{
    const char *names[] = {"SUCCESS", "FAILURE", "TIMEOUT"};
    const char *messages[] = {"Operation successful", "Operation failed", "Operation timed out"};
    char name[20];
    if (scanf("%19s", name) != 1) return 1;
    for (Status status = SUCCESS; status <= TIMEOUT; ++status) {
        if (strcmp(name, names[status]) == 0) {
            puts(messages[status]);
            return 0;
        }
    }
    puts("Unknown status");
    return 0;
}
