/*
Question 99
Change the date format from dd/04/yyyy to dd-Apr-yyyy.
*/

#include <stdio.h>

int main(void)
{
    int day, month, year;
    if (scanf("%d/%d/%d", &day, &month, &year) != 3 || year < 1 || year > 9999 ||
        month < 1 || month > 12) {
        puts("Invalid date");
        return 0;
    }
    const char *names[] = {"Jan", "Feb", "Mar", "Apr", "May", "Jun",
                           "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};
    int lengths[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0)) {
        lengths[1] = 29;
    }
    if (day < 1 || day > lengths[month - 1]) {
        puts("Invalid date");
    } else {
        printf("%02d-%s-%04d\n", day, names[month - 1], year);
    }
    return 0;
}
