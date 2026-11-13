/*
Question 140
Define a struct with enum Gender and print person's gender.
*/

#include <stdio.h>
#include <string.h>

int main(void)
{
    enum Gender { MALE, FEMALE, OTHER };
    struct Person {
        enum Gender gender;
    };
    const char *names[] = {"MALE", "FEMALE", "OTHER"};
    const char *labels[] = {"Male", "Female", "Other"};
    char input[32];
    if (scanf("%31s", input) != 1) return 1;
    const char *value = strncmp(input, "Gender=", 7) == 0 ? input + 7 : input;
    struct Person person;
    for (person.gender = MALE; person.gender <= OTHER; ++person.gender) {
        if (strcmp(names[person.gender], value) == 0) {
            puts(labels[person.gender]);
            return 0;
        }
    }
    puts("Unknown gender");
    return 0;
}
