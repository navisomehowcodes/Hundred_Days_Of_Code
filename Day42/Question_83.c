/*
Question 83
Count vowels and consonants in a string.
*/

#include <stdio.h>
#include <ctype.h>

static int is_vowel(int ch)
{
    return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
}

int main(void)
{
    size_t vowels = 0, consonants = 0;
    int ch;
    while ((ch = getchar()) != EOF && ch != '\n') {
        if (isalpha(ch)) {
            if (is_vowel(tolower(ch))) {
                ++vowels;
            } else {
                ++consonants;
            }
        }
    }
    printf("Vowels=%zu, Consonants=%zu\n", vowels, consonants);
    return 0;
}
