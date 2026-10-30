/*
Question 130
Store multiple student records (name, roll number, marks) into a file using fprintf(). Then read them using fscanf() and display each record.
*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

typedef struct {
    char name[100];
    int roll_no;
    double marks;
} Student;

static int read_student(Student *student)
{
    return scanf("%99s%d%lf", student->name, &student->roll_no, &student->marks) == 3;
}

enum { MAX_STUDENTS = 4096 };

static int next_nonspace(void)
{
    int ch;
    do {
        ch = getchar();
    } while (ch != EOF && isspace(ch));
    return ch;
}

static int read_records(Student students[], int *count)
{
    int ch = next_nonspace();
    if (ch == EOF || ungetc(ch, stdin) == EOF) return 0;
    if (ch != 'S') {
        if (scanf("%d", count) != 1 || *count < 0 || *count > MAX_STUDENTS) return 0;
        for (int i = 0; i < *count; ++i) {
            if (!read_student(&students[i])) return 0;
        }
        return 1;
    }
    /* Also accept the website's semicolon-separated, labelled student records. */
    *count = 0;
    do {
        if (*count == MAX_STUDENTS) return 0;
        Student *s = &students[*count];
        if (scanf(" Student %*d %*[^:] : %99[^ ,], Roll: %d, Marks: %lf",
                  s->name, &s->roll_no, &s->marks) != 3) return 0;
        ++*count;
        ch = next_nonspace();
    } while (ch == ';');
    return ch == EOF && !ferror(stdin);
}

int main(void)
{
    int count;
    Student *students = malloc(MAX_STUDENTS * sizeof *students);
    if (!students) return 1;
    if (!read_records(students, &count)) {
        free(students);
        return 1;
    }
    FILE *file = fopen("students.txt", "w");
    if (!file) {
        perror("students.txt");
        free(students);
        return 1;
    }
    int ok = 1;
    for (int i = 0; i < count && ok; ++i) {
        ok = fprintf(file, "%s %d %.17g\n", students[i].name,
                     students[i].roll_no, students[i].marks) >= 0;
    }
    free(students);
    if (fclose(file) != 0 || !ok) return 1;
    file = fopen("students.txt", "r");
    if (!file) return 1;
    Student student;
    for (int i = 0; i < count; ++i) {
        if (fscanf(file, "%99s%d%lf", student.name, &student.roll_no, &student.marks) != 3) {
            fclose(file);
            return 1;
        }
        printf("Name: %s | Roll: %d | Marks: %.12g\n", student.name, student.roll_no, student.marks);
    }
    if (fclose(file) != 0) return 1;
    return 0;
}
