/*
Question 14
Write a program to input a character and check whether it is a vowel or consonant using if–else.
*/

#include <stdio.h>
#include <ctype.h>

static int is_vowel(int ch)
{
    return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
}

int main(void)
{
    int ch = getchar();
    if (ch == EOF) {
        return 1;
    }
    if (!isalpha(ch)) {
        puts("Not an alphabet");
    } else if (is_vowel(tolower(ch))) {
        puts("Vowel");
    } else {
        puts("Consonant");
    }
    return 0;
}
