/*
Question 144
Write a function that accepts a structure as parameter and prints its members.
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
    if (strcmp(student.name, "Student:") == 0 && scanf(" %99s", student.name) != 1) return 1;
    if (scanf("%d%lf", &student.roll_no, &student.marks) != 2) return 1;
    print_student(student);
    return 0;
}
