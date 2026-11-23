/*
Question 146
Create Employee structure with nested Date structure for joining date and print details.
*/

#include <stdio.h>
#include <string.h>

/* Read one complete line, preserving spaces and excluding the line ending. */
static int read_line(char text[], size_t size)
{
    size_t length = 0;
    int ch;
    while ((ch = getchar()) != EOF && ch != '\n') {
        if (length + 1 >= size) {
            return 0;
        }
        text[length++] = (char)ch;
    }
    text[length] = '\0';
    return !ferror(stdin) && (length > 0 || ch == '\n');
}

typedef struct {
    int day, month, year;
} Date;

typedef struct {
    char name[100];
    int id;
    Date joined;
} Employee;

static int valid_date(Date date)
{
    if (date.year < 1 || date.year > 9999 || date.month < 1 || date.month > 12) return 0;
    int days[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (date.year % 400 == 0 || (date.year % 4 == 0 && date.year % 100 != 0)) days[1] = 29;
    return date.day >= 1 && date.day <= days[date.month - 1];
}

int main(void)
{
    char line[256];
    Employee employee;
    if (!read_line(line, sizeof line)) return 1;
    if (strncmp(line, "Employee: ", 10) == 0) {
        if (sscanf(line, "Employee: %99[^|]| ID: %d | Joining Date: %d%d%d",
                   employee.name, &employee.id, &employee.joined.day, &employee.joined.month,
                   &employee.joined.year) != 5) return 1;
        size_t length = strlen(employee.name);
        while (length > 0 && employee.name[length - 1] == ' ') employee.name[--length] = '\0';
    } else {
        if (strlen(line) >= sizeof employee.name) return 1;
        strcpy(employee.name, line);
        if (scanf("%d%d%d%d", &employee.id, &employee.joined.day, &employee.joined.month,
                  &employee.joined.year) != 4) return 1;
    }
    if (employee.name[0] == '\0' || !valid_date(employee.joined)) {
        puts("Invalid employee record");
        return 0;
    }
    printf("Name: %s | ID: %d | Joining Date: %02d/%02d/%04d\n", employee.name,
           employee.id, employee.joined.day, employee.joined.month, employee.joined.year);
    return 0;
}
