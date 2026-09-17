/*
Question 97
Print the initials of a name.
*/

#include <stdio.h>
#include <ctype.h>

int main(void)
{
    int ch, at_start = 1;
    while ((ch = getchar()) != EOF && ch != '\n') {
        if (isspace(ch)) {
            at_start = 1;
        } else if (at_start) {
            printf("%c.", toupper(ch));
            at_start = 0;
        }
    }
    putchar('\n');
    return 0;
}
