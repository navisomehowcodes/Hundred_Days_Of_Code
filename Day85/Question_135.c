/*
Question 135
Assign explicit values starting from 10 and print them.
*/

#include <stdio.h>

int main(void)
{
    enum Letter { A = 10, B, C };
    printf("A=%d\nB=%d\nC=%d\n", A, B, C);
    return 0;
}
