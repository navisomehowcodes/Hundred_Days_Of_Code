/*
Question 91
Remove all vowels from a string.
*/

#include <stdio.h>
#include <ctype.h>

static int is_vowel(int ch)
{
    return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
}

int main(void)
{
    int ch;
    while ((ch = getchar()) != EOF && ch != '\n') {
        if (!is_vowel(tolower(ch))) {
            putchar(ch);
        }
    }
    putchar('\n');
    return 0;
}
