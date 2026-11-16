/*
Question 141
Define a structure Student with name, roll_no, and marks, then read and print one student's data.
*/

#include <stdio.h>
#include <string.h>

typedef struct {
    char name[100];
    int roll_no;
    double marks;
} Student;

static void print_student(Student student)
{
    printf("Name: %s | Roll: %d | Marks: %.12g\n", student.name, student.roll_no, student.marks);
}

int main(void)
{
    Student student;
    if (scanf(" %99s", student.name) != 1) return 1;
    if (strcmp(student.name, "Name:") == 0) {
        if (scanf(" %99[^\n] Roll: %d Marks: %lf",
                  student.name, &student.roll_no, &student.marks) != 3) return 1;
    } else if (scanf("%d%lf", &student.roll_no, &student.marks) != 2) {
        return 1;
    }
    print_student(student);
    return 0;
}
