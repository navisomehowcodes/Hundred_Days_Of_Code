/*
Question 133
Create an enum for months and print how many days each month has.
*/

#include <stdio.h>
#include <string.h>

int main(void)
{
    enum Month { JAN, FEB, MAR, APR, MAY, JUN, JUL, AUG, SEP, OCT, NOV, DEC };
    const char *names[] = {"JAN", "FEB", "MAR", "APR", "MAY", "JUN", "JUL", "AUG", "SEP", "OCT", "NOV", "DEC"};
    char name[16];
    if (scanf("%15s", name) != 1) return 1;
    enum Month month = JAN;
    while (month <= DEC && strcmp(name, names[month]) != 0) ++month;
    switch (month) {
    case FEB: puts("28 or 29 days"); break;
    case APR: case JUN: case SEP: case NOV: puts("30 days"); break;
    case JAN: case MAR: case MAY: case JUL: case AUG: case OCT: case DEC: puts("31 days"); break;
    default: puts("Unknown month"); break;
    }
    return 0;
}
