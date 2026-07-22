/*
Question 15
Write a program to input a character and check whether it is an uppercase alphabet, lowercase alphabet, digit, or special character.
*/

#include <stdio.h>
#include <ctype.h>

int main(void)
{
    int ch = getchar();
    if (ch == EOF) {
        return 1;
    }
    if (isupper(ch)) {
        puts("Uppercase alphabet");
    } else if (islower(ch)) {
        puts("Lowercase alphabet");
    } else if (isdigit(ch)) {
        puts("Digit");
    } else {
        puts("Special character");
    }
    return 0;
}
