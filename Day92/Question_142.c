/*
Question 142
Store details of 5 students in an array of structures and print all.
*/

#include <stdio.h>

typedef struct {
    char name[100];
    int roll_no;
    double marks;
} Student;

static int read_student(Student *student)
{
    return scanf("%99s%d%lf", student->name, &student->roll_no, &student->marks) == 3;
}

int main(void)
{
    Student students[5];
    for (int i = 0; i < 5; ++i) {
        if (!read_student(&students[i])) return 1;
    }
    puts("Name\tRoll\tMarks");
    for (int i = 0; i < 5; ++i) {
        printf("%s\t%d\t%.12g\n", students[i].name, students[i].roll_no, students[i].marks);
    }
    return 0;
}
