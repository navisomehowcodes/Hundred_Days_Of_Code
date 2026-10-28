/*
Question 128
Read a text file and count how many vowels and consonants are in the file. Ignore digits and special characters.
*/

#include <stdio.h>
#include <ctype.h>

static int is_vowel(int ch)
{
    ch = tolower(ch);
    return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
}

int main(int argc, char *argv[])
{
    const char *path = argc > 1 ? argv[1] : "text.txt";
    FILE *input = fopen(path, "r");
    if (input == NULL) {
        perror(path);
        return 1;
    }
    unsigned long long vowels = 0, consonants = 0;
    int ch;
    while ((ch = fgetc(input)) != EOF) {
        if (isalpha(ch)) {
            if (is_vowel(ch)) {
                ++vowels;
            } else {
                ++consonants;
            }
        }
    }
    int failed = ferror(input);
    if (fclose(input) != 0 || failed) return 1;
    printf("Vowels: %llu\nConsonants: %llu\n", vowels, consonants);
    return 0;
}
