/*
Question 139
Show that enums store integers by printing assigned values.
*/

#include <stdio.h>

typedef enum { SUCCESS, FAILURE, TIMEOUT } Status;

int main(void)
{
    printf("SUCCESS=%d, FAILURE=%d, TIMEOUT=%d\n", SUCCESS, FAILURE, TIMEOUT);
    return 0;
}
