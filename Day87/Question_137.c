/*
Question 137
Create an enum for user roles (ADMIN, USER, GUEST) and display messages based on role.
*/

#include <stdio.h>
#include <string.h>

int main(void)
{
    enum Role { ADMIN, USER, GUEST };
    const char *names[] = {"ADMIN", "USER", "GUEST"};
    const char *greetings[] = {"Welcome Admin!", "Welcome User!", "Welcome Guest!"};
    char name[20];
    if (scanf("%19s", name) != 1) return 1;
    for (enum Role role = ADMIN; role <= GUEST; ++role) {
        if (strcmp(name, names[role]) == 0) {
            puts(greetings[role]);
            return 0;
        }
    }
    puts("Unknown role");
    return 0;
}
