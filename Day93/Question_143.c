/*
Question 143
Find and print the student with the highest marks.
*/

#include <stdio.h>
#include <string.h>

typedef struct {
    char name[100];
    int roll_no;
    double marks;
} Student;

/* A record is name roll marks. The published lists also use a "students:" label and commas. */
static int read_student(Student *student)
{
    scanf(" %*1[,]");
    if (scanf(" %99s", student->name) != 1) return 0;
    if (strcmp(student->name, "students:") == 0) {
        if (scanf(" %99s", student->name) != 1) return 0;
    }
    return scanf("%d%lf", &student->roll_no, &student->marks) == 2;
}

int main(void)
{
    int count;
    if (scanf("%d", &count) != 1 || count < 0) return 1;
    if (count == 0) {
        puts("No students");
        return 0;
    }
    Student best;
    if (!read_student(&best)) return 1;
    for (int i = 1; i < count; ++i) {
        Student next;
        if (!read_student(&next)) return 1;
        if (next.marks > best.marks) best = next;
    }
    printf("Topper: %s (Marks: %.12g)\n", best.name, best.marks);
    return 0;
}
