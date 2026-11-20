/*
Question 145
Return a structure containing top student's details from a function.
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

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

static Student top_student(const Student students[], int count)
{
    int best = 0;
    for (int i = 1; i < count; ++i) {
        if (students[i].marks > students[best].marks) best = i;
    }
    return students[best];
}

int main(void)
{
    int count;
    if (scanf("%d", &count) != 1 || count < 0 || count > 4096) return 1;
    if (count == 0) {
        puts("No students");
        return 0;
    }
    Student *students = malloc((size_t)count * sizeof *students);
    if (!students) return 1;
    for (int i = 0; i < count; ++i) {
        if (!read_student(&students[i])) {
            free(students);
            return 1;
        }
    }
    Student best = top_student(students, count);
    free(students);
    printf("Top Student: %s | Roll: %d | Marks: %.12g\n", best.name, best.roll_no, best.marks);
    return 0;
}
